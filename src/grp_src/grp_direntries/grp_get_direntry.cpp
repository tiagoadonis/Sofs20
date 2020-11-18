#include "direntries.h"

#include "core.h"
#include "devtools.h"
#include "daal.h"
#include "fileblocks.h"
#include "bin_direntries.h"

#include <errno.h>
#include <string.h>
#include <sys/stat.h>

namespace sofs20
{
    uint16_t grpGetDirentry(int pih, const char *name)
    {
        soProbe(201, "%s(%d, %s)\n", __FUNCTION__, pih, name);

        /* replace the following line with your code */
        //return binGetDirentry(pih, name);

        SOInode* pointer = soGetInodePointer(pih);

        for(unsigned i=0; i<pointer->size/BlockSize; i++){
            SODirentry entries[DPB]; //array de entries
            soReadFileBlock(pih, i, entries);
            for(unsigned j=0; j<DPB; j++){
                if(strcmp(entries[j].name, name) == 0){
                    return entries[j].in; //retorna o numero do inode associado a essa entrie
                }else{
                    return BlockNullReference; //se nao encontrar nenhum com o mesmo nome retorna null
                }
            }
        }
    return 0;

    }
};

