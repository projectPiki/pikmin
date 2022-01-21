

/*
 * --INFO--
 * Address:	8021C310
 * Size:	0000D4
 */
void TRKInitializeNub(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  bl        0x10C
	  mr.       r30, r3
	  bne-      .loc_0x24
	  bl        0xBAC

	.loc_0x24:
	  cmpwi     r30, 0
	  bne-      .loc_0x34
	  bl        -0x288
	  mr        r30, r3

	.loc_0x34:
	  cmpwi     r30, 0
	  bne-      .loc_0x44
	  bl        0x188
	  mr        r30, r3

	.loc_0x44:
	  cmpwi     r30, 0
	  bne-      .loc_0x54
	  bl        0xB84
	  mr        r30, r3

	.loc_0x54:
	  cmpwi     r30, 0
	  bne-      .loc_0x98
	  lis       r3, 0x803D
	  addi      r31, r3, 0x5CE4
	  lis       r3, 0x1
	  addi      r6, r31, 0
	  subi      r3, r3, 0x1F00
	  li        r4, 0x1
	  li        r5, 0
	  bl        0x4284
	  mr        r0, r3
	  lwz       r3, 0x0(r31)
	  mr        r31, r0
	  bl        0x3AB8
	  cmpwi     r31, 0
	  beq-      .loc_0x98
	  mr        r30, r31

	.loc_0x98:
	  cmpwi     r30, 0
	  bne-      .loc_0xA8
	  bl        0xB00
	  mr        r30, r3

	.loc_0xA8:
	  cmpwi     r30, 0
	  bne-      .loc_0xB8
	  bl        0x3C90
	  mr        r30, r3

	.loc_0xB8:
	  mr        r3, r30
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C3E4
 * Size:	000024
 */
void TRKTerminateNub(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0xAE4
	  li        r3, 0
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C408
 * Size:	000028
 */
void TRKNubWelcome(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r3, r3, 0x2D50
	  stwu      r1, -0x8(r1)
	  bl        0x4378
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C430
 * Size:	000074
 */
void TRKInitializeEndian(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x803D
	  stwu      r1, -0x10(r1)
	  addi      r5, r3, 0x4318
	  li        r6, 0x1
	  stw       r6, 0x0(r5)
	  li        r0, 0x12
	  li        r3, 0x34
	  stb       r0, 0x8(r1)
	  li        r4, 0x56
	  li        r0, 0x78
	  stb       r3, 0x9(r1)
	  li        r3, 0
	  stb       r4, 0xA(r1)
	  stb       r0, 0xB(r1)
	  lwz       r4, 0x8(r1)
	  subis     r0, r4, 0x1234
	  cmplwi    r0, 0x5678
	  bne-      .loc_0x50
	  stw       r6, 0x0(r5)
	  b         .loc_0x6C

	.loc_0x50:
	  subis     r0, r4, 0x7856
	  cmplwi    r0, 0x3412
	  bne-      .loc_0x68
	  li        r0, 0
	  stw       r0, 0x0(r5)
	  b         .loc_0x6C

	.loc_0x68:
	  li        r3, 0x1

	.loc_0x6C:
	  addi      r1, r1, 0x10
	  blr
	*/
}
