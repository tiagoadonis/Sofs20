#include "grp_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "devtools.h"
#include "bin_mksofs.h"

#include <string.h>
#include <inttypes.h>

namespace sofs20
{
    void grpFillSuperblock(const char *name, uint32_t ntotal, uint32_t itotal, uint32_t dbtotal)
    {
        soProbe(602, "%s(%s, %u, %u, %u)\n", __FUNCTION__, name, ntotal, itotal, dbtotal);
    
        SOSuperblock sb;
        strncpy(sb.name, name, PARTITION_NAME_LEN);

        sb.magic = MAGIC_NUMBER;
        sb.version = VERSION_NUMBER;

        sb.mntstat = 0;
        sb.ntotal = ntotal;
        sb.itotal = itotal;

        sb.dbp_start = (itotal/IPB) + 1;
        sb.dbtotal = dbtotal;
        sb.dbfree= sb.dbtotal-1;

        sb.ifree  =  itotal - 1;
        sb.iidx = 0;

        sb.reftable.ref_idx=0;  //Index of first cell, within first block, with references
        sb.insertion_cache.idx=0;   //index of the first empty insertion cache position

        sb.rt_start = (itotal/IPB) + dbtotal + 1; // por causa do 0---> First block of the reference table
        sb.rt_size = ntotal - (itotal/IPB) - dbtotal - 1; // n de blocos da ref table
        
        if(ntotal>=73){//1 sb +68(ref cache) + 4(inode table)
            sb.reftable.count =dbtotal- REF_CACHE_SIZE-1;
        }else{
            sb.reftable.count=0;
        }
            
        

        
        sb.retrieval_cache.idx= REF_CACHE_SIZE-1;
        int valores = sb.rt_start;
        int cache_count=ntotal-4;






        for(int i =REF_CACHE_SIZE-1; i>=0; i--){
            if(valores> REF_CACHE_SIZE+4){
                 sb.retrieval_cache.ref[i] = i+1;
                 sb.retrieval_cache.idx=0;   //Index of the first occupied retrieval cache position
            }else{
                if(i>=REF_CACHE_SIZE-(ntotal-4)){//para o caso da cache content não ser nil
                    sb.retrieval_cache.ref[i]= cache_count;
                    cache_count--;
                }else{
                    sb.retrieval_cache.ref[i]= BlockNullReference;
                }
                sb.retrieval_cache.idx=REF_CACHE_SIZE-(ntotal-4);
            }
        }
        //inode allocation bitmap
        for(int i=0; i< MAX_INODES/32; i++){
            if(i==0){
                sb.ibitmap[i]=1;
            }
            else{
                sb.ibitmap[i]=0;
            }
        }

        for(int i=0; i<REF_CACHE_SIZE; i++){
            sb.insertion_cache.ref[i] = BlockNullReference;
        }   

        soWriteRawBlock(0,&sb);

        /* replace the following line with your code */
       // binFillSuperblock(name, ntotal, itotal, dbtotal);
    }   
};
