#include "Dolphin/db.h"

#include "Dolphin/PPCArch.h"
#include "Dolphin/os.h"

BOOL DBVerbose;
DBInterface* __DBInterface;

/**
 * @TODO: Documentation
 */
void DBInit(void)
{
	__DBInterface                   = (void*)IsDebuggerPresent;
	*(u32*)ExceptionHookDestination = (u32)__DBExceptionDestination - OS_BASE_CACHED;
	DBVerbose                       = TRUE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
void DBIsDebuggerPresent(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void __DBExceptionDestinationAux(void)
{
	u8 dummy[8];
	OSContext* ctx = (void*)(OS_BASE_CACHED + *(u32*)0xC0); // WTF??
	OSReport("DBExceptionDestination\n");
	OSDumpContext(ctx);
	PPCHalt();
}

/**
 * @TODO: Documentation
 */
ASM void __DBExceptionDestination(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mfmsr  r3
	ori    r3, r3, 0x30
	mtmsr  r3
	b      __DBExceptionDestinationAux
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
int __DBIsExceptionMarked(u8 a)
{
	return __DBInterface->unk4 & (1 << a);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void __DBMarkException(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void __DBSetPresent(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void DBPrintf(const char*, ...)
{
}
