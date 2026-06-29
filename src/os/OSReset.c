#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include <stddef.h>
#include <string.h>

static OSResetQueue ResetFunctionQueue;

/**
 * @TODO: Documentation
 */
void OSRegisterResetFunction(OSResetFunctionInfo* info)
{
	OSResetFunctionInfo* tmp;
	OSResetFunctionInfo* iter;

	for (iter = ResetFunctionQueue.head; iter && iter->priority <= info->priority; iter = iter->next) {
		;
	}

	if (iter == NULL) {
		tmp = ResetFunctionQueue.tail;
		if (tmp == NULL) {
			ResetFunctionQueue.head = info;
		} else {
			tmp->next = info;
		}
		info->prev              = tmp;
		info->next              = NULL;
		ResetFunctionQueue.tail = info;
		return;
	}

	info->next = iter;
	tmp        = iter->prev;
	iter->prev = info;
	info->prev = tmp;
	if (tmp == NULL) {
		ResetFunctionQueue.head = info;
		return;
	}
	tmp->next = info;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
void OSUnregisterResetFunction(OSResetFunctionInfo*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00008C (Matching by size)
 */
BOOL CallResetFunctions(BOOL final)
{
	OSResetFunctionInfo* iter;
	BOOL retCode = FALSE;

	for (iter = ResetFunctionQueue.head; (iter != NULL); iter = iter->next) {
		retCode |= !iter->func(final);
	}

	retCode |= !__OSSyncSram();

	if (retCode) {
		return FALSE;
	}
	return TRUE;
}

/**
 * @TODO: Documentation
 */
static void ASM Reset(register s32 resetCode)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	b       _jump1

_begin:
	mfspr   r8, SPR_HID0
	ori     r8, r8, HID0_ABE
	mtspr   SPR_HID0, r8
	isync
	sync
	nop
	b       _preloop

_jump1:
	b       _jump2

_preloop:
	mftb    r5
_loop:
	mftb    r6
	subf    r7, r5, r6
	cmplwi  r7, 0x1124
	blt     _loop
	nop
	b       _setPIReg

_jump2:
	b       _jump3

_setPIReg:
	lis     r8,     __PIRegs @h
	ori     r8, r8, __PIRegs @l
	li      r4, 3
	stw     r4, PI_RESETCODE * 4 (r8)
	stw     resetCode, PI_RESETCODE * 4 (r8)
	nop
	b       _noptrap

_jump3:
	b       _jump4

_noptrap:
	nop
	b       _noptrap

_jump4:
	b       _begin
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000068 (Matching by size)
 */
static void KillThreads(void)
{
	OSThread* thread;
	OSThread* next;

	for (thread = __OSActiveThreadQueue.head; thread; thread = next) {
		next = thread->linkActive.next;
		switch (thread->state) {
		case 1:
		case 4:
		{
			OSCancelThread(thread);
			break;
		}
		}
	}
}

/**
 * @TODO: Documentation
 */
void __OSDoHotReset(s32 code)
{
	OSDisableInterrupts();
	__VIRegs[VI_DISP_CONFIG] = 0;
	ICFlashInvalidate();
	Reset(code * 8);
}

/**
 * @TODO: Documentation
 */
void OSResetSystem(int reset, u32 resetCode, BOOL forceMenu)
{
	BOOL rc;
	BOOL disableRecalibration;
	BOOL enabled;
#if OS_BUILD_VERSION >= 20011002L
	STACK_PAD_VAR(2);
#endif
	OSDisableScheduler();
	__OSStopAudioSystem();

#if OS_BUILD_VERSION >= 20011112L
	if (reset == OS_RESET_SHUTDOWN) {
		disableRecalibration = __PADDisableRecalibration(TRUE);
	}
#endif

	while (!CallResetFunctions(FALSE)) {
		;
	}

#if OS_BUILD_VERSION >= 20011002L
	if (reset == OS_RESET_HOTRESET && forceMenu)
#else
	if (reset && forceMenu)
#endif
	{
		OSSram* sram;

		sram = __OSLockSram();
		sram->flags |= 0x40;
		__OSUnlockSram(TRUE);

		while (!__OSSyncSram()) {
			;
		}
	}

#if OS_BUILD_VERSION >= 20011112L
	OSDisableInterrupts();
#else
	enabled = OSDisableInterrupts();
#endif
	CallResetFunctions(TRUE);
#if OS_BUILD_VERSION >= 20011002L
	LCDisable();
#endif
	if (reset == OS_RESET_HOTRESET) {
		__OSDoHotReset(resetCode);
	}
#if OS_BUILD_VERSION >= 20011002L
	else if (reset == OS_RESET_RESTART)
#else
	else
#endif
	{
		KillThreads();
		OSEnableScheduler();
		__OSReboot(resetCode, forceMenu);
	}

#if OS_BUILD_VERSION >= 20011002L
	KillThreads();
	memset(OSPhysicalToCached(0x40), 0, 0xcc - 0x40);
	memset(OSPhysicalToCached(0xd4), 0, 0xe8 - 0xd4);
	memset(OSPhysicalToCached(0xf4), 0, 0xf8 - 0xf4);
	memset(OSPhysicalToCached(0x3000), 0, 0xc0);
	memset(OSPhysicalToCached(0x30c8), 0, 0xd4 - 0xc8);
	// memset(OSPhysicalToCached(0x30e2), 0, 1);

#if OS_BUILD_VERSION >= 20011112L
	__PADDisableRecalibration(disableRecalibration);
#endif

#else
	OSRestoreInterrupts(enabled);
	OSEnableScheduler();
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030 (Matching by size)
 */
u32 OSGetResetCode(void)
{
	if (OS_REBOOT_BOOL) {
		return 0x80000000;
	}
	return ((__PIRegs[PI_RESETCODE] & ~7) >> 3);
}
