#ifndef _DEBUGLOG_H
#define _DEBUGLOG_H

#include "Dolphin/OS/OSError.h"
#include "Stream.h"
#include "system.h"
#include "types.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define DEFINE_PRINT(_NAME)                        \
	static void _Print(immut char* fmt, ...)       \
	{                                              \
		va_list args;                              \
		va_start(args, fmt);                       \
		char dest[1024];                           \
                                                   \
		if (sysCon) {                              \
			if (_NAME)                             \
				sysCon->print("%s: ", _NAME);      \
                                                   \
			vsprintf(dest, fmt, args);             \
			if (strlen(dest)) {                    \
				sysCon->write(dest, strlen(dest)); \
			}                                      \
		}                                          \
		va_end(args);                              \
	}

// Size - 0x9C
#define DEFINE_ERROR(line)                    \
	static void _Error(immut char* fmt, ...)  \
	{                                         \
		va_list args;                         \
		va_start(args, fmt);                  \
		char buffer[2048];                    \
		vsprintf(buffer, fmt, args);          \
		System::halt(__FILE__, line, buffer); \
		va_end(args);                         \
	}

// DO NOT define these as variadic macros (when matching).  MSVC 6.0 does not support variadic macros, meaning that cannot be how
// these macros were originally implemented.  It has been confirmed by a small snippet of the original source code (leaked by the
// file "sysBootup.opt") that the `PRINT` macro we have created was originally spelled and used in exactly the same way as we have
// spelled and used it for decompilation.  Additionally, many places in the codebase have been shown to require the parenthesized,
// comma-separated arguments to be left in stead of an actual call to the `_Print` or `_Error` functions for matching.  This was
// previously done by expanding the (formerly variadic) macros to `(__VA_ARGS__)` when matching the GCN versions of Pikmin 1, but
// again merely defining a variadic macro when compiling under MSVC 6.0 is a compilation error.  These clues all lead to one
// conclusion.  The `PRINT` and `ERROR` macros never accepted variadic arguments to begin with, and that's how what were formerly
// their arguments ended up affecting the compiled code: they got left behind when the `PRINT` and `ERROR` macros (accepting zero
// arguments) expanded to nothing!
#if defined(WIN32) || defined(DEVELOP)
#define PRINT _Print
#define ERROR _Error
#elif defined(VERSION_DPIJ01_PIKIDEMO) or defined(VERSION_GPIJ01)
#define PRINT
#define ERROR _Error
#else
#define PRINT
#define ERROR
#endif

// In the DLL, there are five global BOOLs (only three are actually used) consistently used to control `PRINT` statements belonging
// to a specific plugPiki library (e.g. plugPikiKando).  These BOOLs go UNUSED in the DOL, but were known to exist in gameflow.cpp.
extern BOOL _nsPrint; // Nishimura's PRINT flag
extern BOOL _cPrint;  // Colin's PRINT flag
extern BOOL _kPrint;  // Kando's PRINT flag
extern BOOL _nPrint;  // Nakata's PRINT flag
extern BOOL _yPrint;  // Yamashita's PRINT flag

// These macros should expand to nothing when matching the GCN versions of Pikmin 1 for the same reasons as the basic `PRINT` macro.
#if defined(WIN32) || defined(DEVELOP)
// clang-format off
#define PRINT_NISHI if (_nsPrint) PRINT
#define PRINT_COLIN if (_cPrint) PRINT
#define PRINT_KANDO if (_kPrint) PRINT
#define PRINT_NAKATA if (_nPrint) PRINT
#define PRINT_YAMASH if (_yPrint) PRINT
// clang-format on
#else
#define PRINT_NISHI
#define PRINT_COLIN
#define PRINT_KANDO
#define PRINT_NAKATA
#define PRINT_YAMASH
#endif

// TODO: Confirm if newlines are necessary or even just desirable for `ERROR`s.   Given the samples we have, it seems the
// devs were mixed on whether one should be used or not.  We'll have to wait until JPN Demo's error handler is understood.
#define MISSING_NEWLINE TERNARY_BUGFIX("\n", "")

#endif // _DEBUGLOG_H
