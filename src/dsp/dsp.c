#include "Dolphin/dsp.h"

#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

/**
 * @TODO: Documentation
 */
u32 DSPCheckMailToDSP()
{
	return __DSPRegs[DSP_MAILBOX_IN_HI] >> 0xF & 1;
}

/**
 * @TODO: Documentation
 */
u32 DSPCheckMailFromDSP(void)
{
	return __DSPRegs[DSP_MAILBOX_OUT_HI] >> 0xF & 1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void DSPReadCPUToDSPMbox(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
u32 DSPReadMailFromDSP()
{
	return (__DSPRegs[DSP_MAILBOX_OUT_HI] << 0x10) | __DSPRegs[DSP_MAILBOX_OUT_LO];
}

/**
 * @TODO: Documentation
 */
void DSPSendMailToDSP(u32 mail)
{
	__DSPRegs[DSP_MAILBOX_IN_HI] = mail >> 0x10;
	__DSPRegs[DSP_MAILBOX_IN_LO] = mail;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void DSPAssertInt(void)
{
	u32 tmp;
	BOOL interrupts               = OSDisableInterrupts();
	tmp                           = __DSPRegs[DSP_CONTROL_STATUS];
	__DSPRegs[DSP_CONTROL_STATUS] = (tmp & ~0xA8) | 2;
	OSRestoreInterrupts(interrupts);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void DSPCheckInit(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000048
 */
void DSPReset(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void DSPHalt(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void DSPUnhalt(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void DSPGetDMAStatus(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void DSPCancelTask(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000C8
 */
void DSPAssertTask(void)
{
	// UNUSED FUNCTION
}

#if defined(VERSION_GPIP01_00)

static int __DSP_init_flag;

void DSPInit(void)
{
	BOOL old;
	u16 tmp;

	__DSP_debug_printf("DSPInit(): Build Date: %s %s\n", "Dec 17 2001", "18:25:00");

	if (__DSP_init_flag == 1)
		return;

	old = OSDisableInterrupts();
	__OSSetInterruptHandler(7, __DSPHandler);
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_DSP_DSP);

	tmp          = __DSPRegs[5];
	tmp          = (tmp & ~0xA8) | 0x800;
	__DSPRegs[5] = tmp;

	tmp          = __DSPRegs[5];
	__DSPRegs[5] = tmp = tmp & ~0xAC;

	__DSP_first_task = __DSP_last_task = __DSP_curr_task = __DSP_tmp_task = NULL;
	__DSP_init_flag                                                       = 1;

	OSRestoreInterrupts(old);
}

#endif
