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
#include <map>
#include <set>

class MockingjayReplPolicy: public ReplPolicy {
    protected:
        uint32_t numLines;
        uint32_t ways;
        HashFamily* hf;
        std::set<uint32_t> sampled_sets;
        bool cache_miss;
        struct SampledEntry {
            bool valid;
            uint16_t address_tag;
            uint16_t pc_signature;
            uint8_t timestamp;
        };
        std::map<uint32_t, SampledEntry*> sampled_cache;
        std::map<uint16_t, uint8_t> rdp;
        //std::map<uint64_t, int> pc_count;
        int8_t* etr_counters;
        uint8_t* set_timestamps;
        //uint8_t* set_clocks;
        void update_sampled_cache(uint32_t id, const MemReq* req, uint32_t set) {
            if(sampled_sets.find(set) == sampled_sets.end()) {
                SampledEntry* s = new SampledEntry[80];
                for(int i = 0; i < 80; i++) {
                    s[i] = {false, 0, 0, 0};
                }
                sampled_cache[set] = s;
                sampled_sets.insert(set);
            }
            //pc_count[req->pc]++;
            //std::cout << "PC: " << req->pc << " Count: " << pc_count[req->pc] << std::endl;
            uint16_t pc_hit = (((req->pc & 0x07FF) << 1) + 1);
            uint16_t pc_miss = ((req->pc & 0x07FF) << 1);
            std::cout << "PC hit: " << pc_hit << " PC miss: " << pc_miss << std::endl;
            std::cout << '\n';
            //set_clocks[set]++;
            /*
            std::cout << '\n';
            if(sampled_sets.find(set) == sampled_sets.end()) {
                uint8_t least_recent_timestamp = set_timestamps[0];
                uint32_t least_recent_set = 0;
                for(int i = 0; i < sizeof(set_timestamps)/sizeof(uint8_t); i++) {
                    if(set_timestamps[i] < least_recent_timestamp && sampled_sets.find(i) != sampled_sets.end()) {
                        least_recent_timestamp = set_timestamps[i];
                        least_recent_set = i;
                    }
                }
                if(least_recent_timestamp < set_timestamps[set]) {
                    delete sampled_sets[least_recent_set];
                    sampled_cache.erase(least_recent_set);
                    sampled_set.erase(least_recent_set);
                    SampledEntry* s = new SampledEntry[128];
                    for(int i = 0; i < 128; i++) {
                        s[i].valid = false;
                    }
                    sampled_cache[set] = s;
                    sampled_sets.insert(set);
                }
                set_timestamps[set]++;
            }
            */
            //if(sampled_sets.find(set) != sampled_sets.end()) {
                //set_timestamps[set]++;
            uint16_t numShift = log2(numLines / ways);
            uint32_t sampled_set = (req->lineAddr >> numShift) & 0x0F;
            uint16_t tag = ((req->lineAddr >> numShift) & 0x03FF0) >> 4;
            uint16_t new_pc_signature = cache_miss ? ((req->pc & 0x07FF) << 1): (((req->pc & 0x07FF) << 1) + 1);
            bool sampleMiss = true;
            bool invalidEntries = false;
            uint8_t pred;
            std::cout << "Id: " << id << " " << "LLC Set: " << set << " " << "Sampled Cache Set: " << sampled_set << " " << "Address: " << req->lineAddr << " " << "PC: " << req->pc << " " << "Set timestamp: " << +set_timestamps[set] << std::endl;
            for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; i++) {
                std::cout << "Tag: " << sampled_cache[set][i].address_tag << " " << std::boolalpha << sampled_cache[set][i].valid << " " << "Last access timestamp: " << +sampled_cache[set][i].timestamp << std::endl;
                if(sampled_cache[set][i].valid) {
                    if(set_timestamps[set] < sampled_cache[set][i].timestamp) {
                        uint16_t overflow = (1 << 8) + set_timestamps[set];
                        pred = overflow - sampled_cache[set][i].timestamp;
                    }
                    else
                        pred = set_timestamps[set] - sampled_cache[set][i].timestamp;
                    if(pred > INT8_MAX) {
                        update_rdp(id, sampled_cache[set][i].pc_signature, pred, false);
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
            std::cout << '\n';
            if(sampleMiss) {
                uint32_t bestCand = -1;
                uint32_t bestScore = UINT32_MAX;
                for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; i++) {
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
                    std::cout << "Made it here" << std::endl;
                }
            }
            set_timestamps[set]++;
            if(rdp.count(new_pc_signature)) 
                etr_counters[id] = rdp[new_pc_signature];
            else
                etr_counters[id] = 0;
            //}
        }

        void update_rdp(uint32_t id, uint16_t last_pc_signature, uint8_t pred, bool sampleMiss) { 
            if(sampleMiss) 
                rdp[last_pc_signature] = pred;
            
            else {
                if(rdp.count(last_pc_signature)) {
                    if(pred > INT8_MAX) 
                        rdp[last_pc_signature] = INT8_MAX;
                    else {
                        uint8_t old_pred = rdp[last_pc_signature];
                        int diff = abs(old_pred - pred);
                        float_t w = MIN(1, diff/6);
                        uint8_t new_pred;
                        if (pred > old_pred) {
                            diff = round(old_pred + w);
                            new_pred = diff > INT8_MAX ? INT8_MAX : diff;
                            rdp[last_pc_signature] = new_pred;
                        }
                        else if(pred < old_pred) {
                            diff = round(old_pred + w);
                            new_pred = diff < 0 ? 0 : diff;
                            rdp[last_pc_signature] = new_pred;
                        }
                    }  
                }
                else
                    rdp[last_pc_signature] = pred;
            }
            std::cout << "Id: " << id << " PC: " << last_pc_signature << " RDP: " << +rdp[last_pc_signature] << std::endl;
            std::cout << '\n';
        }

    public:
        MockingjayReplPolicy(uint32_t _numLines, uint32_t _ways, HashFamily* _hf): numLines(_numLines), ways(_ways), hf(_hf) {
            etr_counters = gm_calloc<int8_t>(numLines);
            for(uint32_t i = 0; i < numLines; i++) {
                etr_counters[i] = INT8_MIN;
            }
            uint32_t numSets = numLines / ways;
            //set_clocks = gm_calloc<uint8_t>(numSets);
            set_timestamps = gm_calloc<uint8_t>(numSets);
            cache_miss = false;
            std::vector<uint32_t> v;
            for(uint32_t i = 0; i < numSets; i++) {
                v.push_back(i);
            }
            std::random_shuffle(v.begin(), v.end());
            v.resize(32);
            for(std::vector<uint32_t>::iterator it = v.begin(); it != v.end(); ++it) {
                sampled_sets.insert(*it);
            }
            for(std::set<uint32_t>::iterator it = sampled_sets.begin(); it != sampled_sets.end(); ++it) {
                sampled_cache[*it] = new SampledEntry[128];
                for(int i = 0; i < 128; i++) {
                    sampled_cache[*it][i].valid = false;
                }
            }
            v = std::vector<uint32_t>();
        }

        ~MockingjayReplPolicy(){
            gm_free(etr_counters);
        }
        void update(uint32_t id, const MemReq* req) {
            uint32_t set = hf->hash(0, req->lineAddr) & ((numLines / ways) - 1);
            //if(set_clocks[set] == 8) {
                //set_clocks[set] = 0;
                for(uint32_t i = set * ways; i < set * ways + ways; i++) {
                    if(etr_counters[i] < INT8_MAX && etr_counters[i] > INT8_MIN && i != id)
                        etr_counters[i]--;
                }
            //}
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
            uint32_t set = hf->hash(0, req->lineAddr) & ((numLines/ways) - 1);
            std::cout << "LLC Set #: " << set << std::endl;
            for (auto ci = cands.begin(); ci != cands.end(); ci.inc()) {
                uint32_t i = *ci;
                std::cout << "LLC Line #: " << *ci << " " << "ETR value: " << +etr_counters[i] << std::endl;
                if(abs(etr_counters[i]) > bestScore) {
                    bestCand = i;
                    bestScore = abs(etr_counters[i]);
                }
                else if(abs(etr_counters[i]) == bestScore && abs(etr_counters[i]) < 0)
                    bestCand = i;
            }
            std::cout << '\n';
            return bestCand;
        }
        DECL_RANK_BINDINGS
};

#endif
