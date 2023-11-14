#ifndef RRIP_REPL_H_
#define RRIP_REPL_H_

#include "repl_policies.h"

// Static RRIP
class SRRIPReplPolicy : public ReplPolicy {
    protected:
        // add class member variables here
         uint32_t* array;
         uint32_t numLines;
         uint32_t rpvMax;

    public:
        // add member methods here, refer to repl_policies.h
        SRRIPReplPolicy(uint32_t _numLines, uint32_t _rpvMax): numLines(_numLines), rpvMax(_rpvMax) {
            array = gm_calloc<uint32_t>(numLines);
            for(uint32_t i = 0; i < numLines; i++)  {
                array[i] = rpvMax;
            }
        }

        ~SRRIPReplPolicy() {
            gm_free(array);
        }

        void update(uint32_t id, const MemReq* req) {
	    //printf("Index: %d, RPV Pre-Update: %d\n", id, array[id]);
            if(array[id] == rpvMax + 1)
                array[id] = rpvMax - 1;
            else
                array[id] = 0;
            //printf("Index: %d, RPV Post-Update: %d\n", id, array[id]);
        }

        void replaced(uint32_t id) {
            array[id] = rpvMax + 1;
        }

        template <typename C> uint32_t rank(const MemReq* req, C cands) {
            uint32_t bestCand = -1;
            bool foundRpvMax = false;
            do {
                for (auto ci = cands.begin(); ci != cands.end(); ci.inc()) {
                    uint32_t i = *ci;
		    //printf("Index: %d RPV: %d\n", i, array[i]);
                    if(array[i] == rpvMax) {
                        foundRpvMax = true;
                        bestCand = i;
 			break;
                    }
                }
                if(!foundRpvMax) {
                    for(auto ci = cands.begin(); ci != cands.end(); ci.inc()) {
			            uint32_t i = *ci;
                        array[i]++;
                    }
                }
            } while (!foundRpvMax);
	    //printf("Best candidate: %d RPV: %d\n", bestCand, array[bestCand]);
            return bestCand;
        }
        DECL_RANK_BINDINGS;
};
#endif // RRIP_REPL_H_
