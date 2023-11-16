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

class MockingjayReplPolicy: public ReplPolicy {
    private:
        uint32_t numLines;
        uint32_t ways;
        std::map<uint32_t, uint8_t> set_timestamps;
        //std::set<int> sampled_sets;
        struct SampledEntry {
            bool valid;
            Address address;
            Address pc;
            uint8_t timestamp;

        };
        std::map<uint32_t, SampledEntry*> sampled_cache;
        std::map<Address, uint8_t> rdp;
        uint32_t* etr_counters;

        void update_sampled_cache(uint32_t id, const MemReq* req) {
            HashFamily* hf = new IdHashFamily;
            uint32_t set = hf->hash(0, req->lineAddr) & ((numLines / ways) - 1);
            //if(sampled_sets.find(set) != sampled_sets.end()) {
            set_timestamps[set]++;
            SampledEntry* s = sampled_cache[set];
            set = req->lineAddr & 0x0F;
            uint32_t tag = req->lineAddr & 0x3FF8;
            bool sampleMiss = true;
            uint8_t pred;
            for(uint32_t i = set * 16; i < set * 16 + 5; i++)
            {
                if(s[i].valid && (s[i].address & 0x3FF8) == tag)
                {
                    sampleMiss = false;
                    pred = set_timestamps[set] - s[i].timestamp;
                    s[i].timestamp = set_timestamps[set];
                    update_rdp(id, req->pc, pred, sampleMiss);
                }
                else if(!s[i].valid)
                {
                    s[i].valid = true;
                    s[i].address = req->lineAddr;
                    s[i].pc = req->pc;
                    s[i].timestamp = set_timestamps[set];
                }
            }
            if(sampleMiss)
                sampled_cache_replacement(id, req, set);
        }

        void sampled_cache_replacement(uint32_t id, const MemReq* req, uint32_t set) {
            uint32_t bestCand = -1;
            uint32_t bestScore = UINT32_MAX;
            for(uint32_t i = set * 16; i < set * 16 + 5; i++)
            {
                if(!sampled_cache[set][i].valid)
                {
                    sampled_cache[set][i].valid = true;
                    sampled_cache[set][i].address = req->lineAddr;
                    sampled_cache[set][i].pc = req->pc;
                    sampled_cache[set][i].timestamp = set_timestamps[set];
                    return;
                }
                else
                {
                    uint32_t s = sampled_cache[set][i].timestamp;
                    bestCand = (s < bestScore) ? i : bestCand;
                    bestScore = MIN(s, bestScore);
                }
            } 
            update_rdp(id, sampled_cache[set][bestCand].pc, uint32_t(127), true);
            sampled_cache[set][bestCand].address = req->lineAddr;
            sampled_cache[set][bestCand].pc = req->pc;
            sampled_cache[set][bestCand].timestamp = set_timestamps[set];
        }

        void update_rdp(uint32_t id, Address pc, uint8_t pred, bool miss) {
            if(miss)
                rdp[pc] = pred;
            else
            {
                if(rdp.count(pc) == 0)
                    rdp[pc] = pred;
                else {
                    uint8_t old_pred = rdp[pc];
                    int diff = abs(old_pred - pred);
                    float_t w = MIN(1, diff/6);
                    w = w > 1 ? ceil(w) : floor(w);
                    uint8_t new_pred = (pred > old_pred) ? pred + w : pred - w;
                    rdp[pc] = new_pred;
                }
            }
            etr_counters[id] = rdp[pc];
        }

    public:
        MockingjayReplPolicy(uint32_t _numLines, uint32_t _ways): numLines(_numLines), ways(_ways) {
            etr_counters = gm_calloc<uint32_t>(numLines);
            for(uint32_t i = 0; i < numLines; i++)
            {
                etr_counters[i] = 127;
            }
            uint32_t numSets = numLines / ways;
            for(uint32_t i = 0; i < numSets; i++)
            {
                set_timestamps[i] = 0;
                SampledEntry* s = new SampledEntry[80];
                for(int j = 0; j < 80; i++)
                   s[j] = {false, 0, 0, 0};
                sampled_cache[i] = s;

            } 
        }

        ~MockingjayReplPolicy(){
            gm_free(etr_counters);
        }

        void update(uint32_t id, const MemReq* req) {
            printf("PC value: %lu\n", req->lineAddr);
            HashFamily* hf = new IdHashFamily;
            uint32_t set = hf->hash(0, req->lineAddr) & ((numLines / ways) - 1);
            for(uint32_t i = set * ways; i < set * ways + ways; i++)
            {
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
                if(abs(etr_counters[i]) > bestScore)
                {
                    bestCand = i;
                    bestScore = abs(etr_counters[i]);
                }
                else if(abs(etr_counters[i] == bestScore))
                {
                    if(etr_counters[i] < 0)
                        bestCand = i;
                }
            }
            printf("Prediction: %x\n", bestCand);
            return bestCand;
            return rand() % numLines + 1;
        }
        DECL_RANK_BINDINGS
};

#endif
