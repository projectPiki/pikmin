#ifndef _JAUDIO_DEBUG_H
#define _JAUDIO_DEBUG_H

#include "Dolphin/OS/OSError.h"

/*
 * This is intentionally an object-like macro. In retail builds, removing only
 * the callee leaves the parenthesized arguments as a comma expression.
 */
#if defined(DEBUG)
#define JAUDIO_PRINT OSReport
#else
#define JAUDIO_PRINT
#endif

#endif
