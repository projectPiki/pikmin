

/*
 * --INFO--
 * Address:	80207E14
 * Size:	000010
 */
void DSPCheckMailToDSP(void)
{
/*
.loc_0x0:
  lis       r3, 0xCC00
  lhz       r0, 0x5000(r3)
  rlwinm    r3,r0,17,31,31
  blr
*/
}

/*
 * --INFO--
 * Address:	80207E24
 * Size:	000010
 */
void DSPCheckMailFromDSP(void)
{
/*
.loc_0x0:
  lis       r3, 0xCC00
  lhz       r0, 0x5004(r3)
  rlwinm    r3,r0,17,31,31
  blr
*/
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
void DSPReadMailFromDSP(void)
{
/*
.loc_0x0:
  lis       r3, 0xCC00
  addi      r3, r3, 0x5000
  lhz       r0, 0x4(r3)
  lhz       r3, 0x6(r3)
  rlwimi    r3,r0,16,0,15
  blr
*/
}

/*
 * --INFO--
 * Address:	80207E4C
 * Size:	000014
 */
void DSPSendMailToDSP(void)
{
/*
.loc_0x0:
  lis       r4, 0xCC00
  rlwinm    r0,r3,16,16,31
  sth       r0, 0x5000(r4)
  sth       r3, 0x5002(r4)
  blr
*/
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
