#include "grp_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "devtools.h"
#include "bin_mksofs.h"

#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <inttypes.h>

namespace sofs20
{
    void grpFillInodeTable(uint32_t itotal, bool date)
    {
        soProbe(604, "%s(%u)\n", __FUNCTION__, itotal);

        /* replace the following line with your code */
        binFillInodeTable(itotal, date);
    }
};

