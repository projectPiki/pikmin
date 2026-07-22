#ifndef _DOLPHIN_OS_OSERROR_H
#define _DOLPHIN_OS_OSERROR_H

#include "Dolphin/OS/OSContext.h"
#include "Dolphin/OS/OSException.h"
#include "Dolphin/OS/OSUtil.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

/////////// ERROR TYPES //////////
// Useful typedef for errors.
typedef u16 OSError;

// Error handler function type.
typedef void (*OSErrorHandler)(OSError error, OSContext* context, ...);

// Error functions.
OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler);
void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar);

// OS logging and reporting.
void OSReport(const char* message, ...);
void OSPanic(const char* file, int line, const char* message, ...);

#if defined(_MSC_VER) && _MSC_VER < 1400

// For Pikmin 1: plugPiki.dll undeniably used Dolphin OS in some capacity, as
// the symbol `void __cdecl OSf32tos16(float *,__int16 *)` can be found in its
// ILK.  Conflictingly, plugPiki.dll was built using MSVC 6.0 (released 1998),
// which predates variadic macros (a feature of C99).  Defining a macro with
// variadic arguments is a compile-time error, so we need some kind of fallback.

#define OSErrorLine(line, message) OSPanic(__FILE__, line, message)
#define OSError(message)           OSErrorLine(__LINE__, message)

#define OSAssertMsgLine(line, cond, message) ((void)((cond) || (OSErrorLine(line, __VA_ARGS__), 0)))
#define OSAssertMsg(cond, message)           OSAssertMsgLine(__LINE__, cond, message)

#else

#define OSErrorLine(line, ...) OSPanic(__FILE__, line, __VA_ARGS__)
#define OSError(...)           OSErrorLine(__LINE__, __VA_ARGS__)

#ifdef DEBUG // Currently necessary for dsp_cardunlock.c
#define OSAssertMsgLine(line, cond, ...) ((void)((cond) || (OSErrorLine(line, __VA_ARGS__), 0)))
#else
#define OSAssertMsgLine(line, cond, ...) ((void)(0))
#endif

#define OSAssertMsg(cond, ...)   OSAssertMsgLine(__LINE__, cond, __VA_ARGS__)

#endif

#define OSAssertLine(line, cond) OSAssertMsgLine(line, cond, "Failed assertion " #cond)
#define OSAssert(cond)           OSAssertLine(__LINE__, cond)

// Error defines.
#define OS_ERROR_SYSTEM_RESET       (0)
#define OS_ERROR_MACHINE_CHECK      (1)
#define OS_ERROR_DSI                (2)
#define OS_ERROR_ISI                (3)
#define OS_ERROR_EXTERNAL_INTERRUPT (4)
#define OS_ERROR_ALIGNMENT          (5)
#define OS_ERROR_PROGRAM            (6)
#define OS_ERROR_FLOATING_POINT     (7)
#define OS_ERROR_DECREMENTER        (8)
#define OS_ERROR_SYSTEM_CALL        (9)
#define OS_ERROR_TRACE              (10)
#define OS_ERROR_PERFORMACE_MONITOR (11)
#define OS_ERROR_BREAKPOINT         (12)
#define OS_ERROR_SYSTEM_INTERRUPT   (13)
#define OS_ERROR_THERMAL_INTERRUPT  (14)
#define OS_ERROR_PROTECTION         (15)
#define OS_ERROR_MAX                (OS_ERROR_PROTECTION + 1)

// Error table.
extern OSErrorHandler __OSErrorTable[OS_ERROR_MAX];

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
