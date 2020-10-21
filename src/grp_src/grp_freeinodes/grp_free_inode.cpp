/*
 *  \author António Rui Borges - 2012-2015
 *  \authur Artur Pereira - 2016-2020
 */

#include "freeinodes.h"

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
    void grpFreeInode(uint16_t in)
    {
        soProbe(402, "%s(%u)\n", __FUNCTION__, in);

        /* replace the following line with your code */
        binFreeInode(in);
    }
};

