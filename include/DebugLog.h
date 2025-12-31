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

#if defined(DEVELOP)
#define PRINT(...)        _Print(__VA_ARGS__)
#define ERROR(...)        _Error(__VA_ARGS__)
#define PRINT_GLOBAL(...) OSReport(__VA_ARGS__)
#elif defined(VERSION_DPIJ01_PIKIDEMO) or defined(VERSION_GPIJ01_01)
#define PRINT(...)        (__VA_ARGS__)
#define ERROR(...)        _Error(__VA_ARGS__)
#define PRINT_GLOBAL(...) (__VA_ARGS__)
#else
#define PRINT(...)        (__VA_ARGS__)
#define ERROR(...)        (__VA_ARGS__)
#define PRINT_GLOBAL(...) (__VA_ARGS__)
#endif

// This macro exists to abstract the user PRINTs seen below.  mapMgr.cpp seems to have used this macro as well.
#define PRINT_IF(cond, ...) \
	if (cond) {             \
		PRINT(__VA_ARGS__); \
	}

// In the DLL, there are five global BOOLs (only three are actually used) consistently used to control `PRINT_IF` statements belonging
// to a specific plugPiki library (e.g. plugPikiKando).  However, these BOOLs seemingly only exist in the DLL.  I'm not even sure what
// translation unit they belong to.  For now, this stubbed configuration doesn't break matching.

extern BOOL _nsPrint; // Nishimura's PRINT flag
extern BOOL _cPrint;  // Colin's PRINT flag
extern BOOL _kPrint;  // Kando's PRINT flag
extern BOOL _nPrint;  // Nakata's PRINT flag
extern BOOL _yPrint;  // Yamashita's PRINT flag

#ifdef WIN32
#define PRINT_NISHI(...)  PRINT_IF(_nsPrint, __VA_ARGS__)
#define PRINT_COLIN(...)  PRINT_IF(_cPrint, __VA_ARGS__)
#define PRINT_KANDO(...)  PRINT_IF(_kPrint, __VA_ARGS__)
#define PRINT_NAKATA(...) PRINT_IF(_nPrint, __VA_ARGS__)
#define PRINT_YAMASH(...) PRINT_IF(_yPrint, __VA_ARGS__)
#else
#define PRINT_NISHI(...)  PRINT_IF(true, __VA_ARGS__)
#define PRINT_COLIN(...)  PRINT_IF(true, __VA_ARGS__)
#define PRINT_KANDO(...)  PRINT_IF(true, __VA_ARGS__)
#define PRINT_NAKATA(...) PRINT_IF(true, __VA_ARGS__)
#define PRINT_YAMASH(...) PRINT_IF(true, __VA_ARGS__)
#endif

// TODO: Confirm if newlines are necessary or even just desirable for `ERROR`s.   Given the samples we have, it seems the
// devs were mixed on whether one should be used or not.  We'll have to wait until JPN Demo's error handler is understood.
#define MISSING_NEWLINE TERNARY_BUGFIX("\n", "")

#endif // _DEBUGLOG_H
