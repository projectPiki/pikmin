#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

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
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00008C
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
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
static ASM Reset(register s32 resetCode)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	b _jump1

_begin:
	mfspr r8, HID0
	ori r8, r8, 8
	mtspr HID0, r8
	isync
	sync
	nop
	b _preloop

_jump1:
	b _jump2

_preloop:
	mftb r5, 268
_loop:
	mftb r6, 268
	subf r7, r5, r6
	cmplwi r7, 0x1124
	blt _loop
	nop
	b _setPIReg

_jump2:
	b _jump3

_setPIReg:
	lis r8, 0xCC003000@h
	ori r8, r8, 0xCC003000@l
	li r4, 3
	stw r4, 0x24(r8)
	stw r3, 0x24(r8)
	nop
	b _noptrap

_jump3:
	b _jump4

_noptrap:
	nop
	b _noptrap

_jump4:
	b _begin
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000068
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
			OSCancelThread(thread);
			break;
		}
	}
	// UNUSED FUNCTION
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

	OSDisableScheduler();
	__OSStopAudioSystem();

	while (!CallResetFunctions(FALSE)) {
		;
	}

	if (reset && forceMenu) {
		OSSram* sram;

		sram = __OSLockSram();
		sram->flags |= 0x40;
		__OSUnlockSram(TRUE);

		while (!__OSSyncSram()) {
			;
		}
	}

	enabled = OSDisableInterrupts();
	CallResetFunctions(TRUE);
	if (reset == OS_RESET_HOTRESET) {
		__OSDoHotReset(resetCode);
	} else {
		KillThreads();
		OSEnableScheduler();
		__OSReboot(resetCode, forceMenu);
	}

	OSRestoreInterrupts(enabled);
	OSEnableScheduler();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
u32 OSGetResetCode(void)
{
	// UNUSED FUNCTION
}
