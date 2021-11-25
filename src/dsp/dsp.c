#include "dsp.h"
/*
 * --INFO--
 * Address:	80207E14
 * Size:	000010
 */


u32 DSPCheckMailToDSP(void)
{
	return (HW_REG(0xCC005000, u16) >> 15) & 1;
}

/*
 * --INFO--
 * Address:	80207E24
 * Size:	000010
 */
u32 DSPCheckMailFromDSP(void)
{
	return (HW_REG(0xCC005004, u16) >> 15) & 1;;
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
u32 DSPReadMailFromDSP(void)
{
	return (__DSPRegs[2] << 16) | __DSPRegs[3];
}

/*
 * --INFO--
 * Address:	80207E4C
 * Size:	000014
 */
void DSPSendMailToDSP(u32 mail)
{
	__DSPRegs[0] = (u16)((mail >> 16) & 0xffff);
	__DSPRegs[1] = (u16)(mail & 0xffff);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DSPAssertInt(void)
{
	// UNUSED FUNCTION
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
 * Size:	000070
 */
void DSPAddTask(void)
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
