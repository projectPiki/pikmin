

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void Jac_Pause(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80017460
 * Size:	000070
 */
void Jac_StreamMovieInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  addi      r31, r5, 0
	  bl        0x23C4
	  cmplwi    r3, 0x1
	  bne-      .loc_0x48
	  lwz       r0, 0x2C78(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x48
	  li        r3, 0x1
	  li        r4, 0x32
	  bl        0x2064
	  li        r0, 0x1
	  stw       r0, 0x2C78(r13)

	.loc_0x48:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        0x6B6C
	  bl        0x2948
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800174E0
 * Size:	00004C
 */
void Jac_StreamMovieStop(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x72F4
	  bl        0x2350
	  cmplwi    r3, 0x1
	  bne-      .loc_0x3C
	  lwz       r0, 0x2C78(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x3C
	  li        r3, 0
	  li        r4, 0x64
	  bl        0x1FF0
	  li        r0, 0
	  stw       r0, 0x2C78(r13)

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017540
 * Size:	000020
 */
void Jac_StreamMovieUpdate(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x6EF4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017560
 * Size:	000064
 */
void Jac_StreamMovieGetPicture(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  bl        0x72F0
	  addi      r31, r3, 0
	  cmpwi     r31, -0x1
	  bne-      .loc_0x4C
	  bl        0x22C0
	  cmplwi    r3, 0x1
	  bne-      .loc_0x4C
	  lwz       r0, 0x2C78(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x4C
	  li        r3, 0
	  li        r4, 0x64
	  bl        0x1F60
	  li        r0, 0
	  stw       r0, 0x2C78(r13)

	.loc_0x4C:
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
