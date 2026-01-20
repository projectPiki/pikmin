#include "Dolphin/os.h"
#include <string.h>

#define OS_SYS_CALL_HANDLER  ((void*)0x80000C00)
#define OS_HANDLER_SLOT_SIZE (0x100)

void __OSSystemCallVectorStart();
void __OSSystemCallVectorEnd();

/**
 * @TODO: Documentation
 */
static ASM void SystemCallVector(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	entry __OSSystemCallVectorStart
	mfspr r9, DBSR
	ori r10, r9, 8
	mtspr DBSR, r10
	isync
	sync
	mtspr DBSR, r9
	rfi

	entry __OSSystemCallVectorEnd
	nop
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
void __OSInitSystemCall(void)
{
	void* handler = OS_SYS_CALL_HANDLER;
	memcpy(handler, __OSSystemCallVectorStart, (u32)__OSSystemCallVectorEnd - (u32)__OSSystemCallVectorStart);

	DCFlushRangeNoSync(handler, OS_HANDLER_SLOT_SIZE);
	__mwerks_sync();
	ICInvalidateRange(handler, OS_HANDLER_SLOT_SIZE);
}
