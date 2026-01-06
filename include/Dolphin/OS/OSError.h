#ifndef _DOLPHIN_OS_OSERROR_H
#define _DOLPHIN_OS_OSERROR_H

#include "Dolphin/OS/OSContext.h"
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

// OS logging and reporting.
void OSReport(const char* message, ...);
void OSPanic(const char* file, int line, const char* message, ...);

#define OSError(...)           OSPanic(__FILE__, __LINE__, __VA_ARGS__)
#define OSErrorLine(line, ...) OSPanic(__FILE__, line, __VA_ARGS__)

#ifdef DEBUG // Currently necessary for dsp_cardunlock.c
#define ASSERTMSGLINE(line, cond, ...) ((void)((cond) || (OSErrorLine(line, __VA_ARGS__), 0)))
#else
#define ASSERTMSGLINE(line, cond, ...) ((void)(0))
#endif

#define ASSERTMSGLINEV(line, cond, ...) ASSERTMSGLINE(line, cond, __VA_ARG__)
#define ASSERTMSG(cond, ...)            ASSERTMSGLINE(__LINE__, cond, __VA_ARGS__)
#define ASSERTLINE(line, cond)          ASSERTMSGLINE(line, cond, "Failed assertion " #cond)
#define ASSERT(cond)                    ASSERTLINE(__LINE__, cond)

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
extern OSErrorHandler __OSErrorTable[16];

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
