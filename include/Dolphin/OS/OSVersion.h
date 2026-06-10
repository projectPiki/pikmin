#ifndef _DOLPHIN_OS_OSVERSION_H
#define _DOLPHIN_OS_OSVERSION_H

#include "types.h"

// This is a fabricated header with fabricated macros in order to support multiple revisions of the SDK.
// `OS_BUILD_REVISION` is not granular enough because there are differences between the Oct. and Nov.
// versions of Dolphin SDK Revision 47, so prefer `OS_BUILD_VERSION` for conditionally compiled code.
// TODO: There are revisional differences in vi.c that cannot be explained by the build date and time.

/////////////// OS BUILD INFO /////////////////////////////////////////////////////////////////////

#if defined(VERSION_GPIJ01) || defined(VERSION_GPIE01)
#define OS_BUILD_REVISION 37
#define OS_BUILD_DATE     "Jul 19 2001"
#define OS_BUILD_TIME     "05:43:42"
#define OS_BUILD_VERSION  20010719L
#elif defined(VERSION_DPIJ01_PIKIDEMO)
#define OS_BUILD_REVISION 47
#define OS_BUILD_DATE     "Oct  2 2001"
#define OS_BUILD_TIME     "11:02:22"
#define OS_BUILD_VERSION  20011002L
#elif defined(VERSION_G98E01_PIKIDEMO)
#define OS_BUILD_REVISION 47
#define OS_BUILD_DATE     "Nov 12 2001"
#define OS_BUILD_TIME     "01:46:17"
#define OS_BUILD_VERSION  20011112L
#else // VERSION_G98P01_PIKIDEMO, VERSION_GPIP01
#define OS_BUILD_REVISION 49
#define OS_BUILD_DATE     "Dec 17 2001"
#define OS_BUILD_TIME     "18:46:45"
#define OS_BUILD_VERSION  20011217L
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif
