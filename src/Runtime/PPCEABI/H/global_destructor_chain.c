

/*
 * --INFO--
 * Address:	80214964
 * Size:	000048
 */
void __destroy_global_chain(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  b         .loc_0x2C

	.loc_0x10:
	  lwz       r0, 0x0(r3)
	  li        r4, -0x1
	  stw       r0, 0x3470(r13)
	  lwz       r12, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r3, 0x3470(r13)
	  cmplwi    r3, 0
	  bne+      .loc_0x10
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802149AC
 * Size:	000018
 */
void __register_global_object(void)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x3470(r13)
	  stw       r0, 0x0(r5)
	  stw       r4, 0x4(r5)
	  stw       r3, 0x8(r5)
	  stw       r5, 0x3470(r13)
	  blr
	*/
}
