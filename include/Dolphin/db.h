#ifndef _DOLPHIN_DB_H
#define _DOLPHIN_DB_H

#include "Dolphin/AmcExi2.h"
#include "Dolphin/os.h"
#include "types.h"

#define ExceptionHookDestination 0x80000048
#define IsDebuggerPresent        0x80000040

typedef struct DBInterface {
	u8 filler0[4];
	u32 unk4;
} DBInterface;

extern DBInterface* __DBInterface;
extern int DBVerbose;

void DBInit(void);
int DBInitComm(void*, AmcEXICallback); // possibly not this type, but some similar construction
int DBInitInterrupts();

int DBQueryData();
BOOL DBRead(u8*, int);
BOOL DBWrite(const u8*, int);
BOOL DBOpen();
BOOL DBClose();

void __DBExceptionDestination(void);
void DBPrintf(const char* format, ...);

#endif
