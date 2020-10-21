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
#include <sys/stat.h>
#include <string.h>

#include <iostream>

#include "core.h"
#include "devtools.h"
#include "daal.h"

namespace sofs20
{
    uint16_t grpAllocInode(uint32_t mode)
    {
        soProbe(401, "%s(0x%x)\n", __FUNCTION__, mode);

        /* replace the following line with your code */
        return binAllocInode(mode);
    }
};

