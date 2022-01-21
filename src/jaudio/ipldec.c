

/*
 * --INFO--
 * Address:	80008A00
 * Size:	000070
 */
void WriteTask(unsigned char, unsigned long, void*, void (*)(void*))
{
	/*
	.loc_0x0:
	  lbz       r0, 0x2BCA(r13)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lbz       r8, 0x2BC9(r13)
	  lis       r7, 0x803E
	  subi      r0, r7, 0x50E0
	  rlwinm    r7,r8,4,0,27
	  add       r7, r0, r7
	  stb       r3, 0x0(r7)
	  stw       r4, 0x4(r7)
	  stw       r5, 0x8(r7)
	  stw       r6, 0xC(r7)
	  lbz       r3, 0x2BC9(r13)
	  addi      r0, r3, 0x1
	  stb       r0, 0x2BC9(r13)
	  lbz       r0, 0x2BC9(r13)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x58
	  li        r0, 0
	  stb       r0, 0x2BC9(r13)

	.loc_0x58:
	  lbz       r4, 0x2BCA(r13)
	  lis       r3, 0x803E
	  subi      r3, r3, 0x50E0
	  addi      r0, r4, 0x1
	  stb       r0, 0x2BCA(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008A80
 * Size:	0000C0
 */
void DoTask()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803E
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r29, 0x14(r1)
	  subi      r31, r3, 0x50E0
	  b         .loc_0xA0

	.loc_0x1C:
	  lbz       r0, 0x2BC8(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r31, r0
	  lbz       r0, 0x0(r4)
	  lwz       r30, 0x8(r4)
	  cmpwi     r0, 0x1
	  lwz       r3, 0x4(r4)
	  lwz       r29, 0xC(r4)
	  beq-      .loc_0x58
	  bge-      .loc_0x5C
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  b         .loc_0x5C

	.loc_0x50:
	  bl        -0x150
	  b         .loc_0x5C

	.loc_0x58:
	  bl        -0x118

	.loc_0x5C:
	  cmplwi    r29, 0
	  beq-      .loc_0x74
	  addi      r12, r29, 0
	  addi      r3, r30, 0
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lbz       r3, 0x2BC8(r13)
	  addi      r0, r3, 0x1
	  stb       r0, 0x2BC8(r13)
	  lbz       r0, 0x2BC8(r13)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x94
	  li        r0, 0
	  stb       r0, 0x2BC8(r13)

	.loc_0x94:
	  lbz       r3, 0x2BCA(r13)
	  subi      r0, r3, 0x1
	  stb       r0, 0x2BCA(r13)

	.loc_0xA0:
	  lbz       r0, 0x2BCA(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0x1C
	  lmw       r29, 0x14(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008B40
 * Size:	000024
 */
void DspExtraTaskCheck()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xCC
	  li        r3, 0x1
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void Jac_IPLDspSec(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80008B80
 * Size:	00004C
 */
void Jac_DSPcardDecodeAsync(void*, void*, void (*)(void*))
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

	.loc_0x1C:
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  addi      r6, r31, 0
	  li        r3, 0
	  bl        -0x1AC
	  cmplwi    r3, 0
	  beq+      .loc_0x1C
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Jac_DSPagbDecodeAsync(void*, void*, void (*)(void*))
{
	// UNUSED FUNCTION
}
