#ifndef _PHPHASH
#define _PHPHASH

#include <stdio.h> //size_t constant
#include <inttypes.h>

#include "inline.h"    //INLINE constant



/*
* DJBX33A (Daniel J. Bernstein, Times 33 with Addition)
*/


static ALWAYS_INLINE uint64_t phphash(const char *str, size_t len)
{
    uint64_t hash = UINT64_C(5381);

    /* variant with the hash unrolled eight times */
    for (; len >= 8; len -= 8) {
        hash = ((hash << 5) + hash) + *str++;
        hash = ((hash << 5) + hash) + *str++;
        hash = ((hash << 5) + hash) + *str++;
        hash = ((hash << 5) + hash) + *str++;
        hash = ((hash << 5) + hash) + *str++;
        hash = ((hash << 5) + hash) + *str++;
        hash = ((hash << 5) + hash) + *str++;
        hash = ((hash << 5) + hash) + *str++;
    }
    switch (len) {
        case 7: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */
        case 6: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */
        case 5: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */
        case 4: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */
        case 3: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */
        case 2: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */
        case 1: hash = ((hash << 5) + hash) + *str++; break;
        case 0: break;
        default: __builtin_unreachable (); break;
    }

    /* Hash value can't be zero, so we always set the high bit */
    return hash | UINT64_C(0x8000000000000000);
}

#endif