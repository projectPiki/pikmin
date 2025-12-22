#include "Dolphin/db.h"

#include "Dolphin/os.h"

BOOL DBVerbose;
DBInterface* __DBInterface;

void DBInit(void)
{
	__DBInterface                   = (void*)IsDebuggerPresent;
	*(u32*)ExceptionHookDestination = (u32)__DBExceptionDestination - OS_BASE_CACHED;
	DBVerbose                       = TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void DBIsDebuggerPresent(void)
{
	// UNUSED FUNCTION
}

void __DBExceptionDestinationAux(void)
{
	u8 dummy[8];
	OSContext* ctx = (void*)(OS_BASE_CACHED + *(u32*)0xC0); // WTF??
	OSReport("DBExceptionDestination\n");
	OSDumpContext(ctx);
	PPCHalt();
}

#ifdef __MWERKS__ // clang-format off
ASM void __DBExceptionDestination(void)
{
	nofralloc
	mfmsr r3
	ori r3, r3, 0x30
	mtmsr r3
	b __DBExceptionDestinationAux
}
#else // clang-format on
void __DBExceptionDestination(void)
{
	asm("mfmsr %r3\n"
	    "ori %r3, %r3, 0x30\n"
	    "mtmsr %r3\n"
	    "b __DBExceptionDestinationAux\n");
}
#endif

int __DBIsExceptionMarked(u8 a)
{
	return __DBInterface->unk4 & (1 << a);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void __DBMarkException(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void __DBSetPresent(void)
{
	// UNUSED FUNCTION
}

void DBPrintf(const char*, ...)
{
}
