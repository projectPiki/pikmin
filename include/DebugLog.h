#ifndef _DEBUGLOG_H
#define _DEBUGLOG_H

#include "Dolphin/OS/OSError.h"
#include "Stream.h"
#include "stl/stdarg.h"
#include "stl/stdio.h"
#include "stl/string.h"
#include "system.h"
#include "types.h"

#define DEFINE_PRINT(_NAME)                        \
	static void _Print(char* fmt, ...)             \
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
	static void _Error(char* fmt, ...)        \
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
#elif defined(VERSION_DPIJ01_PIKIDEMO)
#define PRINT(...)        (__VA_ARGS__)
#define ERROR(...)        _Error(__VA_ARGS__)
#define PRINT_GLOBAL(...) (__VA_ARGS__)
#else
#define PRINT(...)        (__VA_ARGS__)
#define ERROR(...)        (__VA_ARGS__)
#define PRINT_GLOBAL(...) (__VA_ARGS__)
#endif

// TODO: Confirm if newlines are necessary or even just desirable for `ERROR`s.   Given the samples we have, it seems the
// devs were mixed on whether one should be used or not.  We'll have to wait until JPN Demo's error handler is understood.
#if defined(BUGFIX)
#define MISSING_NEWLINE "\n"
#else
#define MISSING_NEWLINE
#endif

#endif // _DEBUGLOG_H
