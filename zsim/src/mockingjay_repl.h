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
        uint32_t numOverflows;
        std::set<uint32_t> sampled_sets;
        bool clock_overflow;
        struct SampledEntry {
            bool valid;
            uint16_t address_tag;
            uint16_t pc_signature;
            uint8_t timestamp;
            uint8_t overflow;
        };
        std::map<uint32_t, SampledEntry*> sampled_cache;
        std::map<uint16_t, uint8_t> rdp;
        std::map<uint16_t, uint32_t> pc_map;
        uint8_t* etr_counters;
        uint8_t* set_timestamps;
        uint8_t current_timestamp;

        void update_sampled_cache(uint32_t id, const MemReq* req, uint32_t set) {
            if(sampled_sets.find(set) == sampled_sets.end()) {
                SampledEntry* s = new SampledEntry[80];
                for(int i = 0; i < 80; i++) {
                    s[i] = {false, 0, 0, 0, 0};
                }
                sampled_cache[set] = s;
                sampled_sets.insert(set);
            }
            if(current_timestamp == UINT8_MAX) {
                clock_overflow = true;
                numOverflows++;
            }
            else   
                clock_overflow = false;
            set_timestamps[set] = current_timestamp++;
            //set_clock[set]++;
            /*
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
                    samped_set.erase(least_recent_set);
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
            uint32_t sampled_set = req->lineAddr & 0x0F;
            uint16_t tag = (req->lineAddr & 0x03FF0) >> 4;
            bool sampleMiss = true;
            uint8_t pred;
            std::cout << "LLC Set #: " << set << std::endl;
            //std::cout << "LLC Set: " << set << " " << "Sampled Cache Set: " << sampled_set << " " << "Address Tag: " << tag << " " << "Set timestamp: " << +set_timestamps[set] << std::endl;
            for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; i++) {
                //std::cout << "Tag: " << sampled_cache[set][i].address_tag << " " << std::boolalpha << sampled_cache[set][i].valid << " " << "Last access timestamp: " << +sampled_cache[set][i].timestamp << std::endl;
                if(sampled_cache[set][i].valid && sampled_cache[set][i].address_tag == tag) {
                    sampleMiss = false;
                    if(clock_overflow)
                        sampled_cache[set][i].overflow++;
                    /*
                    if(set_timestamps[set] < sampled_cache[set][i].timestamp) {
                        uint16_t overflow = (1 << 8) + set_timestamps[set];
                        pred = (overflow - sampled_cache[set][i].timestamp) > 104 ? 127 : set_timestamps[set] - sampled_cache[set][i].timestamp;
                    }
                    else
                        pred = (set_timestamps[set] - sampled_cache[set][i].timestamp) > 104 ? 127 : set_timestamps[set] - sampled_cache[set][i].timestamp;
                    */
                    uint16_t temp = (1 << 8) * numOverflows + set_timestamps[set] - (numOverflows - sampled_cache[set][i].overflow) * sampled_cache[set][i].timestamp;
                    pred = temp > 104 ? 127 : set_timestamps[set] - sampled_cache[set][i].timestamp;
                    sampled_cache[set][i].timestamp = set_timestamps[set];
                    sampled_cache[set][i].pc_signature = req->pc & 0x07FF;
                    pc_map[sampled_cache[set][i].pc_signature] = id;
                    update_rdp(sampled_cache[set][i].pc_signature, pred, sampleMiss);
                }
            }
            if(sampleMiss) {
                bool foundOverflow = false;
                for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; i++) {
                    if(!sampled_cache[set][i].valid) {
                        sampled_cache[set][i].valid = true;
                        sampled_cache[set][i].address_tag = (req->lineAddr & 0x03FF0) >> 4;
                        sampled_cache[set][i].pc_signature = req->pc & 0x07FF;
                        sampled_cache[set][i].timestamp = set_timestamps[set];
                        pc_map[sampled_cache[set][i].pc_signature] = id;
                        return;
                    }
                    else {
                        if(sampled_cache[set][i].timestamp  > set_timestamps[set])
                            foundOverflow = true;
                    }
                }
                uint32_t bestCand = -1;
                uint32_t bestScore = UINT32_MAX;
                if(foundOverflow) {
                    uint16_t overflow_timestamps[5];
                    for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; i++) {
                        //std::cout << "Timestamp: " << +s << std::endl;
                        uint32_t j = i % 5;
                        overflow_timestamps[j] = ((1 << 8) * (numOverflows - sampled_cache[set][i].overflow)) + sampled_cache[set][i].timestamp;
                        bestCand = (overflow_timestamps[j] < bestScore) ? i : bestCand;
                        bestScore = MIN(overflow_timestamps[j], bestScore);
                    }
                }
                else {
                    for(uint32_t i = sampled_set * 5; i < sampled_set * 5 + 5; i++) {
                        //std::cout << "Timestamp: " << +s << std::endl;
                        bestCand = (sampled_cache[set][i].timestamp < bestScore) ? i : bestCand;
                        bestScore = MIN(sampled_cache[set][i].timestamp, bestScore);
                    }
                }
                //std::cout << "Made it here" << std::endl;
                pred = 127;
                update_rdp(sampled_cache[set][bestCand].pc_signature, pred, sampleMiss);
                sampled_cache[set][bestCand].address_tag = (req->lineAddr & 0x03FF0) >> 4;
                sampled_cache[set][bestCand].pc_signature = req->pc & 0x07FF;
                sampled_cache[set][bestCand].timestamp = set_timestamps[set];
                pc_map[sampled_cache[set][bestCand].pc_signature] = id;
            }
            //}
        }

        void update_rdp(uint16_t pc_signature, uint8_t pred, bool miss) {
            //for (std::map<uint16_t, uint8_t>::iterator it=rdp.begin(); it!=rdp.end(); ++it)
                //std::cout << it->first << " => " << +it->second << std::endl;
            //std::cout << '\n';
            //for (std::map<uint16_t, uint32_t>::iterator it=pc_map.begin(); it!=pc_map.end(); ++it)
                //std::cout << it->first << " => " << it->second << std::endl;
            //std::cout << '\n';
            uint32_t id = pc_map[pc_signature];
            if(miss) {
                pc_signature <<= 1;
                rdp[pc_signature] = pred;
            }
            else {
                pc_signature <<= 1;
                pc_signature += 1;
                if(!rdp.count(pc_signature))
                    rdp[pc_signature] = pred;
                else {
                    uint8_t old_pred = rdp[pc_signature];
                    int diff = abs(old_pred - pred);
                    float_t w = MIN(1, diff/6);
                    uint8_t new_pred = (pred > old_pred) ? pred + w : pred - w;
                    rdp[pc_signature] = new_pred > 104 ? 127 : new_pred;
                }
            }
            etr_counters[id] = rdp[pc_signature];
        }

    public:
        MockingjayReplPolicy(uint32_t _numLines, uint32_t _ways): numLines(_numLines), ways(_ways) {
            etr_counters = gm_malloc<uint8_t>(numLines);
            for(uint32_t i = 0; i < numLines; i++) {
                etr_counters[i] = UINT8_MAX;
            }
            uint32_t numSets = numLines / ways;
            //set_clock = gm_calloc<uint8_t>(numSets);
            set_timestamps = gm_calloc<uint8_t>(numSets);
            clock_overflow = false;
            /*
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
            */
        }

        ~MockingjayReplPolicy(){
            gm_free(etr_counters);
        }

        void update(uint32_t id, const MemReq* req) {
            uint32_t set = req->lineAddr & ((numLines / ways) - 1);
            //if(set_clock[set] == 8) {
                //set_clock[set] = 0;
            for(uint32_t i = set * ways; i < set * ways + ways; i++) {
                if(etr_counters[i] < 127)
                    etr_counters[i]--;
            }
            //}
            update_sampled_cache(id, req, set);
            
        }

        void replaced(uint32_t id) {
            etr_counters[id] = 127;
        }

        template <typename C> uint32_t rank(const MemReq* req, C cands) {
            uint32_t bestCand = *cands.begin();
            uint32_t bestScore = abs(etr_counters[bestCand]);
            //uint32_t set = req->lineAddr & ((numLines/ways) - 1);
            //std::cout << "LLC Set #: " << set << std::endl;
            for (auto ci = cands.begin(); ci != cands.end(); ci.inc()) {
                uint32_t i = *ci;
                //std::cout << "LLC Line #: " << *ci << " " << "ETR value: " << abs(etr_counters[i]) << std::endl;
                if(abs(etr_counters[i]) > bestScore) {
                    bestCand = i;
                    bestScore = abs(etr_counters[i]);
                }
                else if(abs(etr_counters[i]) == bestScore && abs(etr_counters[i]) < 0) {
                    bestCand = i;
                }
            }
            //std::cout << '\n';
            return bestCand;
        }
        DECL_RANK_BINDINGS
};

#endif
