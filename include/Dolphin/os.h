#ifndef _DOLPHIN_OS_H
#define _DOLPHIN_OS_H

#include "types.h"

#include "Dolphin/OS/OSAlarm.h"
#include "Dolphin/OS/OSAlloc.h"
#include "Dolphin/OS/OSBootInfo.h"
#include "Dolphin/OS/OSCache.h"
#include "Dolphin/OS/OSContext.h"
#include "Dolphin/OS/OSError.h"
#include "Dolphin/OS/OSException.h"
#include "Dolphin/OS/OSExi.h"
#include "Dolphin/OS/OSExpansion.h"
#include "Dolphin/OS/OSFont.h"
#include "Dolphin/OS/OSInterrupt.h"
#include "Dolphin/OS/OSMemory.h"
#include "Dolphin/OS/OSMessage.h"
#include "Dolphin/OS/OSModule.h"
#include "Dolphin/OS/OSMutex.h"
#include "Dolphin/OS/OSReset.h"
#include "Dolphin/OS/OSRtc.h"
#include "Dolphin/OS/OSSerial.h"
#include "Dolphin/OS/OSThread.h"
#include "Dolphin/OS/OSTime.h"
#include "Dolphin/OS/OSUtil.h"

// #include "Dolphin/OS/OSFastCast.h" // Is intentionally omitted for jaudio bc paired single asm instructions mess with proc 750

BEGIN_SCOPE_EXTERN_C

///////// OS FUNCTIONS ///////////
// Initialisers.
extern void __OSPSInit();
extern void __OSFPRInit();
extern void __OSCacheInit();
extern void __OSContextInit();
extern void __OSInterruptInit();
extern void __OSInitSystemCall();
extern void __OSModuleInit();
extern void __OSInitAudioSystem();
extern void __OSStopAudioSystem();
extern void __OSInitMemoryProtection();

void OSInit();

// Other OS functions.
#define OS_CONSOLE_RETAIL4     0x00000004
#define OS_CONSOLE_RETAIL3     0x00000003
#define OS_CONSOLE_RETAIL2     0x00000002
#define OS_CONSOLE_RETAIL1     0x00000001
#define OS_CONSOLE_RETAIL      0x00000000
#define OS_CONSOLE_DEVHW4      0x10000007
#define OS_CONSOLE_DEVHW3      0x10000006
#define OS_CONSOLE_DEVHW2      0x10000005
#define OS_CONSOLE_DEVHW1      0x10000004
#define OS_CONSOLE_MINNOW      0x10000003
#define OS_CONSOLE_ARTHUR      0x10000002
#define OS_CONSOLE_PC_EMULATOR 0x10000001
#define OS_CONSOLE_EMULATOR    0x10000000
#define OS_CONSOLE_DEVELOPMENT 0x10000000
#define OS_CONSOLE_DEVKIT      0x10000000
#define OS_CONSOLE_TDEVKIT     0x20000000

u32 OSGetConsoleType();

// Arena functions.
void* OSGetArenaHi(void);
void* OSGetArenaLo(void);
void OSSetArenaHi(void* addr);
void OSSetArenaLo(void* addr);

#define OS_SYS_CALL_HANDLER  ((void*)0x80000C00)
#define OS_HANDLER_SLOT_SIZE (0x100)

void __OSSystemCallVectorStart();
void __OSSystemCallVectorEnd();

u8 GameChoice AT_ADDRESS(OS_BASE_CACHED | 0x30E3);

volatile int __OSTVMode AT_ADDRESS(OS_BASE_CACHED | 0xCC);

//////////////////////////////////

// extern things.
extern OSThreadQueue __DVDThreadQueue;
extern u8 _stack_addr[];
extern u8 _stack_end[];

extern BOOL __OSInIPL;
extern OSTime __OSStartTime;

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
