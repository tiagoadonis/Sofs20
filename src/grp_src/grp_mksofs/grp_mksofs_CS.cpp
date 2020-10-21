#include "grp_mksofs.h"

#include "core.h"
#include "devtools.h"
#include "bin_mksofs.h"

#include <inttypes.h>
#include <iostream>

namespace sofs20
{
    void grpComputeStructure(uint32_t ntotal, uint32_t & itotal, uint32_t & dbtotal)
    {
        soProbe(601, "%s(%u, %u, ...)\n", __FUNCTION__, ntotal, itotal);

        /* replace the following line with your code */
        binComputeStructure(ntotal, itotal, dbtotal);
    }
};

