#include "Dolphin/dsp.h"

#include "Dolphin/os.h"
#include "Dolphin/hw_regs.h"

/*
 * --INFO--
 * Address:	80207E14
 * Size:	000010
 */
u32 DSPCheckMailToDSP()
{
	return __DSPRegs[DSP_MAILBOX_IN_HI] >> 0xF & 1;
}

/*
 * --INFO--
 * Address:	80207E24
 * Size:	000010
 */
u32 DSPCheckMailFromDSP(void)
{
	return __DSPRegs[DSP_MAILBOX_OUT_HI] >> 0xF & 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void DSPReadCPUToDSPMbox(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80207E34
 * Size:	000018
 */
u32 DSPReadMailFromDSP()
{
	return (__DSPRegs[DSP_MAILBOX_OUT_HI] << 0x10) | __DSPRegs[DSP_MAILBOX_OUT_LO];
}

/*
 * --INFO--
 * Address:	80207E4C
 * Size:	000014
 */
void DSPSendMailToDSP(u32 mail)
{
	__DSPRegs[DSP_MAILBOX_IN_HI] = mail >> 0x10;
	__DSPRegs[DSP_MAILBOX_IN_LO] = mail;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DSPAssertInt(void)
{
	u32 tmp;
	BOOL interrupts               = OSDisableInterrupts();
	tmp                           = __DSPRegs[DSP_CONTROL_STATUS];
	__DSPRegs[DSP_CONTROL_STATUS] = (tmp & ~0xA8) | 2;
	OSRestoreInterrupts(interrupts);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DSPCheckInit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void DSPReset(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DSPHalt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void DSPUnhalt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void DSPGetDMAStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DSPCancelTask(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void DSPAssertTask(void)
{
	// UNUSED FUNCTION
}
