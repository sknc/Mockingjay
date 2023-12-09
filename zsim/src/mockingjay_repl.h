#ifndef MOCKINGJAY_REPL_H_
#define MOCKINGJAY_REPL_H_

#include "repl_policies.h"
#include "bithacks.h"
#include "math.h"
#include "limits.h"
#include "stdlib.h"
#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <set>

class MockingjayReplPolicy: public ReplPolicy {
    protected:
        uint32_t numLines;
        uint32_t ways;
        HashFamily* hf;
        bool cache_miss;
        struct SampledEntry {
            bool valid;
            uint16_t address_tag;
            uint16_t pc_signature;
            uint8_t timestamp;
        };
        std::unordered_map<uint32_t, SampledEntry*> sampled_cache;
        std::unordered_map<uint16_t, uint8_t> rdp;
        int8_t* etr_counters;
        uint8_t* set_timestamps;
        void update_sampled_cache(uint32_t id, const MemReq* req, uint32_t set) {
            uint16_t new_pc_signature = cache_miss ? ((req->pc & 0x7FF) << 1): (((req->pc & 0x7FF) << 1) + 1);
            if((set & 0x3F) == ((set >> 5) & 0x3F)) {
                uint16_t numShift = log2(numLines / ways);
                uint32_t sampled_set = (req->lineAddr >> numShift) & 0xF;
                uint64_t tag = ((req->lineAddr >> numShift) & 0x3FF0) >> 4;
                bool sampleMiss = true;
                bool invalidEntries = false;
                uint8_t pred;
                for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; ++i) {
                    if(sampled_cache[set][i].valid) {
                        pred = (set_timestamps[set] < sampled_cache[set][i].timestamp) ? (((1 << 8) + set_timestamps[set]) - sampled_cache[set][i].timestamp) : (set_timestamps[set] - sampled_cache[set][i].timestamp);
                        if(pred > INT8_MAX) {
                            pred = INT8_MAX;
                            update_rdp(id, sampled_cache[set][i].pc_signature, pred, true);
                            sampled_cache[set][i].valid = false;
                        }
                        else {
                            if(sampled_cache[set][i].address_tag == tag) {
                                sampleMiss = false;
                                update_rdp(id, sampled_cache[set][i].pc_signature, pred, sampleMiss);
                                sampled_cache[set][i].timestamp = set_timestamps[set];
                                sampled_cache[set][i].pc_signature = new_pc_signature;
                            }
                        }
                    }
                }
                if(sampleMiss) {
                    uint32_t bestCand = -1;
                    uint32_t bestScore = UINT32_MAX;
                    for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; ++i) {
                        if(!sampled_cache[set][i].valid) {
                            sampled_cache[set][i].valid = true;
                            sampled_cache[set][i].address_tag = tag;
                            sampled_cache[set][i].pc_signature = new_pc_signature;
                            sampled_cache[set][i].timestamp = set_timestamps[set];
                            invalidEntries = true;
                            break;
                        }
                        else {
                            bestCand = (sampled_cache[set][i].timestamp < bestScore) ? i : bestCand;
                            bestScore = MIN(sampled_cache[set][i].timestamp, bestScore);
                        }
                    }
                    if(!invalidEntries) {
                        pred = INT8_MAX;
                        update_rdp(id, sampled_cache[set][bestCand].pc_signature, pred, sampleMiss);
                        sampled_cache[set][bestCand].address_tag = tag;
                        sampled_cache[set][bestCand].pc_signature = new_pc_signature;
                        sampled_cache[set][bestCand].timestamp = set_timestamps[set];
                    }
                }
                set_timestamps[set]++;
            }
            if(rdp.count(new_pc_signature)) 
                etr_counters[id] = rdp[new_pc_signature] > 104 ? INT8_MAX : rdp[new_pc_signature];
        }

        void update_rdp(uint32_t id, uint16_t last_pc_signature, uint8_t pred, bool sampleMiss) { 
            if(sampleMiss || !rdp.count(last_pc_signature)) 
                rdp[last_pc_signature] = pred;
            else {
                if(rdp.count(last_pc_signature)) {
                    int diff = abs(rdp[last_pc_signature] - pred);
                    float_t w = MIN(1, diff/6);
                    rdp[last_pc_signature] = (pred > rdp[last_pc_signature]) ? round(rdp[last_pc_signature] + w) : round(rdp[last_pc_signature] - w);
                }
            }
        }

    public:
        MockingjayReplPolicy(uint32_t _numLines, uint32_t _ways, HashFamily* _hf): numLines(_numLines), ways(_ways), hf(_hf) {
            etr_counters = gm_malloc<int8_t>(numLines);
            for(uint32_t i = 0; i < numLines; ++i) {
                etr_counters[i] = INT8_MIN;
            }
            uint32_t numSets = numLines / ways;
            set_timestamps = gm_calloc<uint8_t>(numSets);
            cache_miss = false;
            for(uint32_t i = 0; i < numSets; ++i) {
                if((i & 0x3F) == ((i >> 5) & 0x3F)) {
                    sampled_cache[i] = new SampledEntry[80];
                    for(uint32_t j = 0; j < 80; ++j) {
                        sampled_cache[i][j].valid = false;
                    }
                }
            }
        }

        ~MockingjayReplPolicy(){
            gm_free(etr_counters);
            gm_free(set_timestamps);
            for(std::unordered_map<uint32_t, SampledEntry*>::iterator it = sampled_cache.begin(); it != sampled_cache.end(); ++it) {
                delete it->second;
            }
        }
        void update(uint32_t id, const MemReq* req) {
            uint32_t set = hf->hash(0, req->lineAddr) & ((numLines / ways) - 1);
            for(uint32_t i = set * ways; i < set * ways + ways; ++i) {
                if(etr_counters[i] < INT8_MAX && etr_counters[i] > INT8_MIN && i != id)
                    etr_counters[i]--;
            }
            update_sampled_cache(id, req, set);
            if(cache_miss)
                cache_miss = false;
        }

        void replaced(uint32_t id) {
            cache_miss = true;
            etr_counters[id] = 0;
        }

        template <typename C> uint32_t rank(const MemReq* req, C cands) {
            uint32_t bestCand = *cands.begin();
            uint32_t bestScore = abs(etr_counters[bestCand]);
            for (auto ci = cands.begin(); ci != cands.end(); ci.inc()) {
                uint32_t i = *ci;
                if(abs(etr_counters[i]) > bestScore) {
                    bestCand = i;
                    bestScore = abs(etr_counters[i]);
                }
                else if(abs(etr_counters[i]) == bestScore && abs(etr_counters[i]) < 0)
                    bestCand = i;
            }
            return bestCand;
        }
        DECL_RANK_BINDINGS
};

#endif
