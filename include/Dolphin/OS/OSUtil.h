#ifndef _DOLPHIN_OS_OSUTIL_H
#define _DOLPHIN_OS_OSUTIL_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

///// USEFUL MACROS/DEFINES //////

// Defines for cached and uncached memory.
#define OS_BASE_CACHED   (0x80000000)
#define OS_BASE_UNCACHED (0xC0000000)

// Necessary for inline asm functions.
#define OS_CACHED_REGION_PREFIX   (0x8000)
#define OS_UNCACHED_REGION_PREFIX (0xC000)
#define OS_PHYSICAL_MASK          (0x3FFF)

//////////////////////////////////

// Macros for rounding to 32-alignment.
#define OSRoundUp32B(x)   (((u32)(x) + 0x1F) & ~(0x1F))
#define OSRoundDown32B(x) (((u32)(x)) & ~(0x1F))

// Address conversions.
#define OSPhysicalToCached(paddr)    ((void*)((u32)(paddr) + OS_BASE_CACHED))
#define OSPhysicalToUncached(paddr)  ((void*)((u32)(paddr) + OS_BASE_UNCACHED))
#define OSCachedToPhysical(caddr)    ((u32)((u8*)(caddr) - OS_BASE_CACHED))
#define OSUncachedToPhysical(ucaddr) ((u32)((u8*)(ucaddr) - OS_BASE_UNCACHED))
#define OSCachedToUncached(caddr)    ((void*)((u8*)(caddr) + (OS_BASE_UNCACHED - OS_BASE_CACHED)))
#define OSUncachedToCached(ucaddr)   ((void*)((u8*)(ucaddr) - (OS_BASE_UNCACHED - OS_BASE_CACHED)))

// Other useful addresses.
vu16 __OSDeviceCode AT_ADDRESS(OS_BASE_CACHED | 0x30E6);

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
