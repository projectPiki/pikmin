

/*
 * --INFO--
 * Address:	8001D9A0
 * Size:	0000E0
 */
void Bank_Setup(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  mr        r27, r3
	  bl        -0x11834
	  mr        r3, r27
	  bl        -0x15B3C
	  bl        -0x18240
	  addi      r0, r3, 0
	  addi      r3, r27, 0
	  mr        r27, r0
	  addi      r4, r27, 0
	  bl        -0x15AD4
	  bl        -0x11458
	  lwz       r0, 0x0(r27)
	  li        r28, 0
	  lwz       r30, 0x4(r27)
	  li        r31, 0
	  add       r29, r27, r0
	  b         .loc_0x7C

	.loc_0x54:
	  add       r3, r29, r31
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lwz       r0, 0x0(r3)
	  addi      r4, r28, 0
	  add       r3, r27, r0
	  bl        -0x11530

	.loc_0x74:
	  addi      r28, r28, 0x1
	  addi      r31, r31, 0x8

	.loc_0x7C:
	  cmplw     r28, r30
	  blt+      .loc_0x54
	  lwz       r0, 0x8(r27)
	  li        r28, 0
	  lwz       r30, 0xC(r27)
	  li        r31, 0
	  add       r29, r27, r0
	  b         .loc_0xC4

	.loc_0x9C:
	  add       r3, r29, r31
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xBC
	  lwz       r0, 0x0(r3)
	  addi      r4, r28, 0
	  add       r3, r27, r0
	  bl        -0x11918

	.loc_0xBC:
	  addi      r28, r28, 0x1
	  addi      r31, r31, 0x8

	.loc_0xC4:
	  cmplw     r28, r30
	  blt+      .loc_0x9C
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
