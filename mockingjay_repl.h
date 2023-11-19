#ifndef MOCKINGJAY_REPL_H_
#define MOCKINGJAY_REPL_H_

#include "repl_policies.h"
#include "bithacks.h"
#include "math.h"
#include "limits.h"
#include "stdlib.h"
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

class MockingjayReplPolicy: public ReplPolicy {
    private:
        uint32_t numLines;
        uint32_t ways;
        std::map<uint32_t, uint8_t> set_timestamps;
        std::set<int> sampled_sets;
        struct SampledEntry {
            bool valid;
            uint16_t hashed_address;
            uint16_t hashed_pc;
            uint8_t timestamp;

        };
        std::map<uint32_t, SampledEntry*> sampled_cache;
        std::map<uint16_t, uint8_t> rdp;
        uint8_t* etr_counters;

        void update_sampled_cache(uint32_t id, const MemReq* req) {
            uint32_t set = req->lineAddr & ((numLines / ways) - 1);
            if(sampled_sets.find(set) != sampled_sets.end()) {
                set_timestamps[set]++;
                SampledEntry* s = sampled_cache[set];
                uint32_t sampled_set = req->lineAddr & 0x0F;
                uint64_t tag = req->lineAddr & 0x3FF8;
                uint16_t hashed_tag = hash(tag);
                bool sampleMiss = true;
                uint8_t pred;
                for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; i++) {
                    if(s[i].valid && s[i].hashed_address == hashed_tag) {
                        sampleMiss = false;
                        if(set_timestamps[set] < s[i].timestamp)
                        {
                            uint16_t overflow = (1 << 8) + set_timestamps[set];
                            pred = overflow - s[i].timestamp;
                        }
                        else
                            pred = set_timestamps[set] - s[i].timestamp;
                        s[i].timestamp = set_timestamps[set];
                        update_rdp(id, hash(req->pc), pred, sampleMiss);
                    }
                    else if(!s[i].valid) {
                        s[i].valid = true;
                        s[i].hashed_address = hash(req->lineAddr);
                        s[i].hashed_pc = hash(req->pc);
                        s[i].timestamp = set_timestamps[set];
                    }
                }
                if(sampleMiss)
                    sampled_cache_replacement(id, req, sampled_set);
            }
        }

        void sampled_cache_replacement(uint32_t id, const MemReq* req, uint32_t set) {
            uint32_t bestCand = -1;
            uint32_t bestScore = UINT32_MAX;
            for(uint32_t i = set * 5; i < set * 5 + 5; i++) {
                if(!sampled_cache[set][i].valid) {
                    sampled_cache[set][i].valid = true;
                    sampled_cache[set][i].hashed_address = hash(req->lineAddr);
                    sampled_cache[set][i].hashed_pc = hash(req->pc);
                    sampled_cache[set][i].timestamp = set_timestamps[set];
                    return;
                }
                else {
                    uint8_t s = sampled_cache[set][i].timestamp;
                    bestCand = (s < bestScore) ? i : bestCand;
                    bestScore = MIN(s, bestScore);
                }
            } 
            update_rdp(id, hash(sampled_cache[set][bestCand].hashed_pc), uint8_t(127), true);
            sampled_cache[set][bestCand].hashed_address = hash(req->lineAddr);
            sampled_cache[set][bestCand].hashed_pc = hash(req->pc);
            sampled_cache[set][bestCand].timestamp = set_timestamps[set];
        }

        void update_rdp(uint32_t id, uint16_t hashed_pc, uint8_t pred, bool miss) {
            if(miss)
                rdp[hashed_pc] = pred;
            else {
                if(rdp.count(hashed_pc) == 0)
                    rdp[hashed_pc] = pred;
                else {
                    uint8_t old_pred = rdp[hashed_pc];
                    int diff = abs(old_pred - pred);
                    float_t w = MIN(1, diff/6);
                    w = w > 1 ? ceil(w) : floor(w);
                    uint8_t new_pred = (pred > old_pred) ? pred + w : pred - w;
                    rdp[hashed_pc] = new_pred;
                }
            }
            etr_counters[id] = rdp[hashed_pc];
        }

        uint16_t hash(uint64_t val) {
            return (uint16_t)(val & 0xFFFF) ^ (uint16_t)(val >> 16 & 0xFFFF) ^ (uint16_t)(val >> 32 & 0xFFFF) ^ (uint16_t)(val >> 48 & 0xFFFF);
        }

    public:
        MockingjayReplPolicy(uint32_t _numLines, uint32_t _ways): numLines(_numLines), ways(_ways) {
            etr_counters = gm_calloc<uint8_t>(numLines);
            for(uint32_t i = 0; i < numLines; i++) 
                etr_counters[i] = 127;
            uint32_t numSets = numLines / ways;
            uint32_t sample = numSets / 32;
            for(uint32_t i = 0; i < numSets; i++) {
                if(i % sample == 0) {
                    sampled_sets.insert(i);
                    set_timestamps[i] = 0;
                    sampled_cache[i] = new SampledEntry[80];
                    for(int j = 0; j < 80; j++)
                    sampled_cache[i][j] = {false, 0, 0, 0};
                }
            } 
        }

        ~MockingjayReplPolicy(){
            gm_free(etr_counters);
            for(std::map<uint32_t, SampledEntry*>::iterator it = sampled_cache.begin(); it != sampled_cache.end(); it++)
                delete it->second;
            sampled_cache.clear();
        }

        void update(uint32_t id, const MemReq* req) {
            uint32_t set = req->lineAddr & ((numLines / ways) - 1);
            for(uint32_t i = set * ways; i < set * ways + ways; i++) {
                if(i != id)
                    etr_counters[i]--;
            }
            update_sampled_cache(id, req);
            
        }

        void replaced(uint32_t id) {
            etr_counters[id] = 127;
        }

        template <typename C> uint32_t rank(const MemReq* req, C cands) {
            uint32_t bestCand = -1;
            uint32_t bestScore = 0;
            for (auto ci = cands.begin(); ci != cands.end(); ci.inc()) {
                uint32_t i = *ci;
                if(abs(etr_counters[i]) > bestScore) {
                    bestCand = i;
                    bestScore = abs(etr_counters[i]);
                }
                else if(abs(etr_counters[i] == bestScore)) {
                    if(etr_counters[i] < 0)
                        bestCand = i;
                }
            }
            return bestCand;
            return rand() % numLines + 1;
        }
        DECL_RANK_BINDINGS
};

#endif
