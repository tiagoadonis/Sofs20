/*
 *  \author António Rui Borges - 2012-2015
 *  \authur Artur Pereira - 2009-2020
 */

#include "freedatablocks.h"

#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

#include "core.h"
#include "devtools.h"
#include "daal.h"

namespace sofs20
{
    uint32_t grpAllocDataBlock()
    {
        soProbe(441, "%s()\n", __FUNCTION__);

        /* replace the following line with your code */
        return binAllocDataBlock();
    }
};

