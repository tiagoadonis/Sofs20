#include "grp_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "devtools.h"
#include "bin_mksofs.h"

#include <string.h>
#include <inttypes.h>

namespace sofs20
{
    void grpResetFreeDataBlocks(uint32_t ntotal, uint32_t itotal, uint32_t dbtotal)
    {
        soProbe(607, "%s(%u, %u, %u)\n", __FUNCTION__, ntotal, itotal, dbtotal);

        /* replace the following line with your code */
        binResetFreeDataBlocks(ntotal, itotal, dbtotal);
    }
};

