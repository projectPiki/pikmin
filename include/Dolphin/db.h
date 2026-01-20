#ifndef _DOLPHIN_DB_H
#define _DOLPHIN_DB_H

#include "Dolphin/AmcExi2.h"
#include "Dolphin/os.h"
#include "types.h"

#define ExceptionHookDestination 0x80000048
#define IsDebuggerPresent        0x80000040

typedef void (*MTRCallbackType)(int);

typedef struct DBInterface {
	u8 filler0[4];
	u32 unk4;
} DBInterface;

extern DBInterface* __DBInterface;
extern BOOL DBVerbose;

void DBInit(void);
void DBInitComm(vu8**, MTRCallbackType);
void DBInitInterrupts(void);

int DBQueryData(void);
BOOL DBRead(void*, int);
BOOL DBWrite(const void*, int);
void DBOpen(void);
void DBClose(void);

void __DBExceptionDestination(void);
int __DBIsExceptionMarked(u8);
void DBPrintf(const char* format, ...);

#endif
