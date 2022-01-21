

/*
 * --INFO--
 * Address:	80016900
 * Size:	000020
 */
void Jac_OutputMode(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x10A8C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80016920
 * Size:	000010
 */
void Jac_SetBGMVolume(void)
{
	/*
	.loc_0x0:
	  li        r0, 0x1
	  stb       r3, -0x7FB0(r13)
	  stw       r0, 0x2C48(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80016940
 * Size:	000010
 */
void Jac_SetSEVolume(void)
{
	/*
	.loc_0x0:
	  li        r0, 0x1
	  stb       r3, -0x7FAF(r13)
	  stw       r0, 0x2C48(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80016960
 * Size:	000048
 */
void Jac_Gsync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2C48(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x2C
	  li        r0, 0
	  lbz       r3, -0x7FB0(r13)
	  stw       r0, 0x2C48(r13)
	  lbz       r4, -0x7FAF(r13)
	  bl        0x2A98

	.loc_0x2C:
	  bl        0x3794
	  bl        0x190
	  bl        0xE0C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Jac_DebugCall(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void __print_thread(char*, OSThread*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800169C0
 * Size:	00008C
 */
void Jac_SetProcessStatus(void)
{
	/*
	.loc_0x0:
	  lwz       r6, -0x7FAC(r13)
	  cmpwi     r6, -0x1
	  beq-      .loc_0x84
	  rlwinm    r0,r3,0,31,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x58
	  subi      r0, r3, 0x1
	  cmplw     r6, r0
	  bne-      .loc_0x84
	  lwz       r4, 0x2C4C(r13)
	  cmpwi     r4, 0
	  beq-      .loc_0x84
	  subi      r0, r4, 0x1
	  lis       r3, 0x8036
	  stw       r0, 0x2C4C(r13)
	  addi      r0, r3, 0x36E0
	  lwz       r3, 0x2C4C(r13)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  stw       r0, -0x7FAC(r13)
	  blr

	.loc_0x58:
	  rlwinm.   r0,r6,0,31,31
	  bne-      .loc_0x84
	  lwz       r5, 0x2C4C(r13)
	  lis       r4, 0x8036
	  addi      r0, r4, 0x36E0
	  rlwinm    r4,r5,2,0,29
	  add       r4, r0, r4
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x2C4C(r13)
	  addi      r0, r4, 0x1
	  stw       r0, 0x2C4C(r13)

	.loc_0x84:
	  stw       r3, -0x7FAC(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Jac_CheckStreamBufferEmpty(void)
{
	// UNUSED FUNCTION
}
