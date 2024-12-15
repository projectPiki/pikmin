#ifndef _DEBUGLOG_H
#define _DEBUGLOG_H

#include "types.h"
#include "stl/stdarg.h"
#include "stl/string.h"
#include "stl/stdio.h"
#include "Stream.h"

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
	}

#ifndef __MWERKS__
#define PANIC(dest, name) (OSError(dest, name))
#else
#include "system.h"
#define PANIC(dest, name) ()
#endif

// Size - 0x9C
#define DEFINE_ERROR()                            \
	static void _Error(const char* fmt, ...)      \
	{                                             \
		char buffer[2048];                        \
		va_list args;                             \
		va_start(args, fmt);                      \
		vsprintf(buffer, fmt, args);              \
		va_end(args);                             \
		System::halt(__FILE__, __LINE__, buffer); \
	}

#ifndef _DEBUG
#define PRINT(...)
#define ERROR(...)
#else
#define PRINT(fmt, ...) _Print(fmt, __VA_ARGS__)
#define ERROR(fmt, ...) _Error(fmt, __VA_ARGS__)
#endif

#endif // _DEBUGLOG_H