

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void setbuf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void setvbuf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80215CB0
 * Size:	0000CC
 */
void __flush_buffer(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r3, 0x18(r3)
	  lwz       r0, 0x20(r31)
	  sub.      r0, r0, r3
	  beq-      .loc_0x80
	  stw       r0, 0x24(r31)
	  lbz       r0, 0x5(r31)
	  rlwinm.   r0,r0,29,31,31
	  lwz       r12, 0x3C(r31)
	  addi      r5, r31, 0x24
	  lwz       r3, 0x0(r31)
	  mtlr      r12
	  lwz       r4, 0x18(r31)
	  lwz       r6, 0x44(r31)
	  blrl
	  cmplwi    r30, 0
	  beq-      .loc_0x64
	  lwz       r0, 0x24(r31)
	  stw       r0, 0x0(r30)

	.loc_0x64:
	  cmpwi     r3, 0
	  beq-      .loc_0x70
	  b         .loc_0xB4

	.loc_0x70:
	  lwz       r3, 0x14(r31)
	  lwz       r0, 0x24(r31)
	  add       r0, r3, r0
	  stw       r0, 0x14(r31)

	.loc_0x80:
	  lwz       r0, 0x18(r31)
	  li        r3, 0
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x1C(r31)
	  stw       r0, 0x24(r31)
	  lwz       r5, 0x14(r31)
	  lwz       r4, 0x28(r31)
	  lwz       r0, 0x24(r31)
	  and       r4, r5, r4
	  sub       r0, r0, r4
	  stw       r0, 0x24(r31)
	  lwz       r0, 0x14(r31)
	  stw       r0, 0x30(r31)

	.loc_0xB4:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  mtlr      r0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void __load_buffer(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80215D7C
 * Size:	000034
 */
void __prep_buffer(void)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x18(r3)
	  stw       r0, 0x20(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r0, 0x24(r3)
	  lwz       r5, 0x14(r3)
	  lwz       r4, 0x28(r3)
	  lwz       r0, 0x24(r3)
	  and       r4, r5, r4
	  sub       r0, r0, r4
	  stw       r0, 0x24(r3)
	  lwz       r0, 0x14(r3)
	  stw       r0, 0x30(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void __convert_to_newlines(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void __convert_from_newlines(void)
{
	// UNUSED FUNCTION
}
