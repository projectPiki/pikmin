#include "types.h"

// This is a fabricated header with fabricated macros in order to support multiple revisions of the SDK.
// TODO: There are revisional differences in vi.c that cannot be explained by the build date and time.

/////////////// OS BUILD INFO /////////////////////////////////////////////////////////////////////

#if defined(VERSION_GPIJ01) || defined(VERSION_GPIE01)
#define OS_BUILD_VERSION 20010719L
#elif defined(VERSION_DPIJ01_PIKIDEMO)
#define OS_BUILD_VERSION 20011002L
#elif defined(VERSION_G98E01_PIKIDEMO)
#define OS_BUILD_VERSION 20011112L
#else // VERSION_G98P01_PIKIDEMO, VERSION_GPIP01
#define OS_BUILD_VERSION 20011217L
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////
