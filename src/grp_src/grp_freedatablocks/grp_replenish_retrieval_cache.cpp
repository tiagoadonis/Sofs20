/*
 *  \author António Rui Borges - 2012-2015
 *  \authur Artur Pereira - 2016-2020
 */

#include "freedatablocks.h"

#include <string.h>
#include <errno.h>
#include <iostream>

#include "core.h"
#include "devtools.h"
#include "daal.h"

namespace sofs20
{
    void grpReplenishRetrievalCache(void)
    {
        soProbe(443, "%s()\n", __FUNCTION__);

        /* replace the following line with your code */
        binReplenishRetrievalCache();


        SOSuperblock* sb = soGetSuperblockPointer();

        if(sb->retrieval_cache.idx  == REF_CACHE_SIZE - 1) {
            return ;
        }  

        // Uses the reference table
        if(sb->reftable.count != 0) {
            uint32_t* rfdb = soGetReferenceBlockPointer(sb->reftable.blk_idx);
        
            while(sb->reftable.ref_idx < REF_CACHE_SIZE) {
                sb->retrieval_cache.ref[sb->retrieval_cache.idx;--] = rfdb[sb->reftable.ref_idx];
                rfdb[sb->reftable.ref_idx++] = BlockNullReference;
            }
            soSaveReferenceBlock();

            sb->rt_size--;
            sb->reftable.count--;
        }

        // Uses the Insertion Cache
        else {

            if(sb->insertion_cache.idx == 0) {
                    throw SOException(ENOSPC, __FUNCTION__); 
            }

            // Gets all 64 references from de Insertion cache
            while(sb->insertion_cache.idx > 0 and sb->retrieval_cache.idx > 0) {
                    sb->retrieval_cache.ref[--sb->retrieval_cache.idx] = sb->insertion_cache.ref[--sb->insertion_cache.idx];
                    sb->insertion_cache.ref[sb->insertion_cache.idx] == BlockNullReference;
            }
        }

        soSaveSuperblock();
    }
};

