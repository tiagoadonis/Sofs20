#include "grp_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "devtools.h"
#include "bin_mksofs.h"

#include <inttypes.h>
#include <string.h>

namespace sofs20
{
    void grpFillReferenceTable(uint32_t ntotal, uint32_t itotal, uint32_t dbtotal)
    {
        soProbe(605, "%s(%u, %u, %u)\n", __FUNCTION__, ntotal, itotal, dbtotal);

        /* replace the following line with your code */
        binFillReferenceTable(ntotal, itotal, dbtotal);
    }
};

