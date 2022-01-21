

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void GXAdjustForOverscan(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80210F00
 * Size:	0000C0
 */
void GXSetDispCopySrc(void)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x2A68(r13)
	  li        r8, 0
	  rlwinm    r4,r4,10,6,21
	  stw       r8, 0x1E0(r7)
	  rlwinm    r7,r5,0,16,31
	  rlwinm    r5,r6,0,16,31
	  lwz       r6, 0x2A68(r13)
	  subi      r0, r5, 0x1
	  rlwinm    r5,r3,0,16,31
	  addi      r9, r6, 0x1E0
	  lwz       r6, 0x1E0(r6)
	  subi      r3, r7, 0x1
	  rlwinm    r6,r6,0,0,21
	  or        r5, r6, r5
	  stw       r5, 0x0(r9)
	  rlwinm    r0,r0,10,0,21
	  lwz       r5, 0x2A68(r13)
	  addi      r6, r5, 0x1E0
	  lwz       r5, 0x1E0(r5)
	  rlwinm    r5,r5,0,22,11
	  or        r4, r5, r4
	  stw       r4, 0x0(r6)
	  lwz       r4, 0x2A68(r13)
	  addi      r5, r4, 0x1E0
	  lwz       r4, 0x1E0(r4)
	  rlwinm    r4,r4,0,8,31
	  oris      r4, r4, 0x4900
	  stw       r4, 0x0(r5)
	  lwz       r4, 0x2A68(r13)
	  stw       r8, 0x1E4(r4)
	  lwz       r4, 0x2A68(r13)
	  addi      r5, r4, 0x1E4
	  lwz       r4, 0x1E4(r4)
	  rlwinm    r4,r4,0,0,21
	  or        r3, r4, r3
	  stw       r3, 0x0(r5)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1E4
	  lwz       r3, 0x1E4(r3)
	  rlwinm    r3,r3,0,22,11
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1E4(r3)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x4A00
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210FC0
 * Size:	0000C0
 */
void GXSetTexCopySrc(void)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x2A68(r13)
	  li        r8, 0
	  rlwinm    r4,r4,10,6,21
	  stw       r8, 0x1F0(r7)
	  rlwinm    r7,r5,0,16,31
	  rlwinm    r5,r6,0,16,31
	  lwz       r6, 0x2A68(r13)
	  subi      r0, r5, 0x1
	  rlwinm    r5,r3,0,16,31
	  addi      r9, r6, 0x1F0
	  lwz       r6, 0x1F0(r6)
	  subi      r3, r7, 0x1
	  rlwinm    r6,r6,0,0,21
	  or        r5, r6, r5
	  stw       r5, 0x0(r9)
	  rlwinm    r0,r0,10,0,21
	  lwz       r5, 0x2A68(r13)
	  addi      r6, r5, 0x1F0
	  lwz       r5, 0x1F0(r5)
	  rlwinm    r5,r5,0,22,11
	  or        r4, r5, r4
	  stw       r4, 0x0(r6)
	  lwz       r4, 0x2A68(r13)
	  addi      r5, r4, 0x1F0
	  lwz       r4, 0x1F0(r4)
	  rlwinm    r4,r4,0,8,31
	  oris      r4, r4, 0x4900
	  stw       r4, 0x0(r5)
	  lwz       r4, 0x2A68(r13)
	  stw       r8, 0x1F4(r4)
	  lwz       r4, 0x2A68(r13)
	  addi      r5, r4, 0x1F4
	  lwz       r4, 0x1F4(r4)
	  rlwinm    r4,r4,0,0,21
	  or        r3, r4, r3
	  stw       r3, 0x0(r5)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1F4
	  lwz       r3, 0x1F4(r3)
	  rlwinm    r3,r3,0,22,11
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1F4(r3)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x4A00
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211080
 * Size:	000044
 */
void GXSetDispCopyDst(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  li        r0, 0
	  stw       r0, 0x1E8(r4)
	  rlwinm    r0,r3,1,16,30
	  srawi     r0, r0, 0x5
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1E8
	  lwz       r3, 0x1E8(r3)
	  rlwinm    r3,r3,0,0,21
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1E8(r3)
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0x4D00
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802110C4
 * Size:	000170
 */
void GXSetTexCopyDst(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r5, 0x13
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  addi      r8, r3, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  rlwinm    r31,r5,0,28,31
	  stw       r30, 0x28(r1)
	  addi      r30, r6, 0
	  lwz       r7, 0x2A68(r13)
	  stb       r0, 0x200(r7)
	  addi      r7, r4, 0
	  bne-      .loc_0x3C
	  li        r31, 0xB

	.loc_0x3C:
	  cmpwi     r5, 0x26
	  beq-      .loc_0x5C
	  bge-      .loc_0x78
	  cmpwi     r5, 0x4
	  bge-      .loc_0x78
	  cmpwi     r5, 0
	  bge-      .loc_0x5C
	  b         .loc_0x78

	.loc_0x5C:
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1FC(r3)
	  rlwinm    r0,r0,0,17,14
	  oris      r0, r0, 0x1
	  ori       r0, r0, 0x8000
	  stw       r0, 0x0(r3)
	  b         .loc_0x8C

	.loc_0x78:
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1FC(r3)
	  rlwinm    r0,r0,0,17,14
	  oris      r0, r0, 0x1
	  stw       r0, 0x0(r3)

	.loc_0x8C:
	  rlwinm    r4,r5,0,27,27
	  lwz       r3, 0x2A68(r13)
	  subi      r0, r4, 0x10
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  stb       r0, 0x200(r3)
	  addi      r3, r5, 0
	  addi      r5, r7, 0
	  lwz       r4, 0x2A68(r13)
	  addi      r7, r1, 0x1C
	  lwz       r0, 0x1FC(r4)
	  addi      r6, r4, 0x1FC
	  addi      r4, r8, 0
	  rlwinm    r0,r0,0,29,27
	  rlwimi    r0,r31,0,28,28
	  stw       r0, 0x0(r6)
	  rlwinm    r31,r31,0,29,31
	  addi      r6, r1, 0x20
	  addi      r8, r1, 0x18
	  bl        0xF68
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0
	  stw       r0, 0x1F8(r3)
	  rlwinm    r3,r30,9,15,22
	  rlwinm    r0,r31,4,0,27
	  lwz       r5, 0x20(r1)
	  lwz       r4, 0x18(r1)
	  lwz       r6, 0x2A68(r13)
	  mullw     r4, r5, r4
	  lwzu      r5, 0x1F8(r6)
	  rlwinm    r5,r5,0,0,21
	  or        r4, r5, r4
	  stw       r4, 0x0(r6)
	  lwz       r4, 0x2A68(r13)
	  addi      r5, r4, 0x1F8
	  lwz       r4, 0x1F8(r4)
	  rlwinm    r4,r4,0,8,31
	  oris      r4, r4, 0x4D00
	  stw       r4, 0x0(r5)
	  lwz       r4, 0x2A68(r13)
	  addi      r5, r4, 0x1FC
	  lwz       r4, 0x1FC(r4)
	  rlwinm    r4,r4,0,23,21
	  or        r3, r4, r3
	  stw       r3, 0x0(r5)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1FC
	  lwz       r3, 0x1FC(r3)
	  rlwinm    r3,r3,0,28,24
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  mtlr      r0
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211234
 * Size:	00002C
 */
void GXSetDispCopyFrame2Field(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,12,0,19
	  lwzu      r3, 0x1EC(r4)
	  rlwinm    r3,r3,0,20,17
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1FC(r3)
	  rlwinm    r0,r0,0,20,17
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211260
 * Size:	00007C
 */
void GXSetCopyClamp(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r4,r3,0,31,31
	  subi      r0, r4, 0x1
	  lwz       r4, 0x1EC(r5)
	  addi      r6, r5, 0x1EC
	  cntlzw    r0, r0
	  rlwinm    r5,r4,0,0,30
	  rlwinm    r4,r0,27,24,31
	  or        r0, r5, r4
	  stw       r0, 0x0(r6)
	  rlwinm    r3,r3,0,30,30
	  subi      r0, r3, 0x2
	  lwz       r3, 0x2A68(r13)
	  cntlzw    r0, r0
	  rlwinm    r6,r0,28,23,30
	  addi      r5, r3, 0x1EC
	  lwz       r3, 0x1EC(r3)
	  rlwinm    r0,r3,0,31,29
	  or        r0, r0, r6
	  stw       r0, 0x0(r5)
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1FC(r3)
	  rlwinm    r0,r0,0,0,30
	  or        r0, r0, r4
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x1FC(r3)
	  rlwinm    r0,r0,0,31,29
	  or        r0, r0, r6
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802112DC
 * Size:	0000BC
 */
void GXSetDispCopyYScale(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  lfs       f0, -0x3CB0(r2)
	  fdivs     f1, f0, f1
	  bl        0x3AD8
	  li        r0, 0x61
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r3,r3,0,23,31
	  lis       r6, 0xCC01
	  stw       r3, 0x1C(r1)
	  oris      r7, r3, 0x4E00
	  stb       r0, -0x8000(r6)
	  li        r5, 0x1
	  subfic    r3, r3, 0x100
	  stw       r7, -0x8000(r6)
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  sth       r5, 0x2(r4)
	  lis       r0, 0x4330
	  rlwinm    r3,r3,10,14,21
	  lwz       r4, 0x2A68(r13)
	  stw       r0, 0x18(r1)
	  addi      r5, r4, 0x1EC
	  lwz       r4, 0x1EC(r4)
	  lfd       f0, 0x18(r1)
	  rlwinm    r4,r4,0,22,20
	  or        r3, r4, r3
	  stw       r3, 0x0(r5)
	  lfd       f2, -0x3CA8(r2)
	  lfs       f1, -0x3CB0(r2)
	  fsubs     f0, f0, f2
	  lwz       r3, 0x2A68(r13)
	  lwz       r3, 0x1E4(r3)
	  fdivs     f0, f1, f0
	  rlwinm    r3,r3,22,22,31
	  addi      r3, r3, 0x1
	  stw       r3, 0x24(r1)
	  stw       r0, 0x20(r1)
	  lfd       f1, 0x20(r1)
	  fsubs     f1, f1, f2
	  fmuls     f1, f1, f0
	  bl        0x3A44
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211398
 * Size:	000068
 */
void GXSetCopyClear(void)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,8,31
	  lbz       r4, 0x3(r3)
	  lbz       r5, 0x0(r3)
	  li        r6, 0x61
	  rlwinm    r7,r4,8,0,23
	  lwz       r4, 0x2A68(r13)
	  rlwimi    r7,r5,0,24,31
	  lis       r5, 0xCC01
	  rlwinm    r7,r7,0,8,31
	  stb       r6, -0x8000(r5)
	  oris      r7, r7, 0x4F00
	  stw       r7, -0x8000(r5)
	  oris      r7, r0, 0x5100
	  li        r0, 0x1
	  lbz       r8, 0x2(r3)
	  lbz       r3, 0x1(r3)
	  rlwinm    r3,r3,8,0,23
	  stb       r6, -0x8000(r5)
	  rlwimi    r3,r8,0,24,31
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x5000
	  stw       r3, -0x8000(r5)
	  stb       r6, -0x8000(r5)
	  stw       r7, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211400
 * Size:	000228
 */
void GXSetCopyFilter(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x50(r1)
	  rlwinm.   r0,r3,0,24,31
	  stmw      r23, 0x2C(r1)
	  beq-      .loc_0x134
	  lbz       r0, 0x1(r4)
	  lbz       r3, 0x7(r4)
	  rlwinm    r30,r0,4,0,27
	  lbz       r8, 0x0(r4)
	  lbz       r0, 0x13(r4)
	  rlwinm    r25,r3,4,0,27
	  lbz       r10, 0x6(r4)
	  rlwimi    r30,r8,0,28,31
	  lbz       r11, 0x2(r4)
	  lbz       r7, 0xD(r4)
	  rlwimi    r25,r10,0,28,31
	  rlwinm    r27,r11,8,0,23
	  lbz       r9, 0x8(r4)
	  lbz       r3, 0xE(r4)
	  rlwinm    r26,r9,8,0,23
	  lbz       r28, 0x3(r4)
	  rlwimi    r27,r30,0,24,31
	  lbz       r9, 0x10(r4)
	  rlwinm    r23,r7,4,0,27
	  lbz       r12, 0xC(r4)
	  lbz       r7, 0x15(r4)
	  rlwinm    r24,r3,8,0,23
	  rlwimi    r23,r12,0,28,31
	  lbz       r29, 0x12(r4)
	  rlwinm    r0,r0,4,0,27
	  rlwimi    r0,r29,0,28,31
	  lbz       r8, 0x14(r4)
	  rlwinm    r28,r28,12,0,19
	  lbz       r31, 0x9(r4)
	  rlwimi    r28,r27,0,20,31
	  lbz       r29, 0x4(r4)
	  rlwimi    r24,r23,0,24,31
	  lbz       r10, 0xF(r4)
	  rlwinm    r23,r8,8,0,23
	  lbz       r12, 0xA(r4)
	  rlwimi    r26,r25,0,24,31
	  lbz       r3, 0x16(r4)
	  rlwinm    r25,r10,12,0,19
	  lbz       r30, 0x5(r4)
	  rlwimi    r23,r0,0,24,31
	  lbz       r0, 0x17(r4)
	  rlwinm    r27,r31,12,0,19
	  lbz       r11, 0xB(r4)
	  lbz       r8, 0x11(r4)
	  rlwinm    r4,r29,16,0,15
	  rlwinm    r7,r7,12,0,19
	  rlwinm    r10,r12,16,0,15
	  rlwimi    r27,r26,0,20,31
	  rlwinm    r12,r3,16,0,15
	  rlwimi    r7,r23,0,20,31
	  rlwimi    r4,r28,0,16,31
	  rlwinm    r3,r30,20,0,11
	  rlwimi    r25,r24,0,20,31
	  rlwinm    r9,r9,16,0,15
	  rlwimi    r10,r27,0,16,31
	  rlwimi    r3,r4,0,12,31
	  rlwimi    r12,r7,0,16,31
	  rlwinm    r7,r3,0,8,31
	  rlwinm    r3,r11,20,0,11
	  rlwimi    r3,r10,0,12,31
	  rlwinm    r4,r3,0,8,31
	  rlwinm    r3,r8,20,0,11
	  rlwimi    r9,r25,0,16,31
	  rlwimi    r3,r9,0,12,31
	  rlwinm    r0,r0,20,0,11
	  rlwimi    r0,r12,0,12,31
	  rlwinm    r3,r3,0,8,31
	  rlwinm    r0,r0,0,8,31
	  oris      r8, r7, 0x100
	  oris      r7, r4, 0x200
	  oris      r9, r3, 0x300
	  oris      r10, r0, 0x400
	  b         .loc_0x154

	.loc_0x134:
	  lis       r8, 0x166
	  lis       r7, 0x266
	  lis       r4, 0x366
	  lis       r3, 0x466
	  addi      r8, r8, 0x6666
	  addi      r7, r7, 0x6666
	  addi      r9, r4, 0x6666
	  addi      r10, r3, 0x6666

	.loc_0x154:
	  li        r4, 0x61
	  lis       r3, 0xCC01
	  stb       r4, -0x8000(r3)
	  rlwinm.   r0,r5,0,24,31
	  stw       r8, -0x8000(r3)
	  stb       r4, -0x8000(r3)
	  stw       r7, -0x8000(r3)
	  stb       r4, -0x8000(r3)
	  stw       r9, -0x8000(r3)
	  stb       r4, -0x8000(r3)
	  stw       r10, -0x8000(r3)
	  beq-      .loc_0x1E8
	  lbz       r0, 0x0(r6)
	  lbz       r3, 0x1(r6)
	  oris      r5, r0, 0x5300
	  lbz       r0, 0x4(r6)
	  lbz       r4, 0x2(r6)
	  rlwinm    r7,r5,0,26,19
	  rlwinm    r5,r3,6,0,25
	  lbz       r3, 0x5(r6)
	  or        r7, r7, r5
	  oris      r8, r0, 0x5400
	  lbz       r5, 0x3(r6)
	  lbz       r0, 0x6(r6)
	  rlwinm    r6,r7,0,20,13
	  rlwinm    r4,r4,12,0,19
	  or        r6, r6, r4
	  rlwinm    r4,r8,0,26,19
	  rlwinm    r3,r3,6,0,25
	  or        r3, r4, r3
	  rlwinm    r6,r6,0,14,7
	  rlwinm    r4,r5,18,0,13
	  rlwinm    r3,r3,0,20,13
	  rlwinm    r0,r0,12,0,19
	  or        r6, r6, r4
	  or        r7, r3, r0
	  b         .loc_0x1F8

	.loc_0x1E8:
	  lis       r4, 0x5359
	  lis       r3, 0x5400
	  addi      r6, r4, 0x5000
	  addi      r7, r3, 0x15

	.loc_0x1F8:
	  li        r5, 0x61
	  lwz       r3, 0x2A68(r13)
	  lis       r4, 0xCC01
	  stb       r5, -0x8000(r4)
	  li        r0, 0x1
	  stw       r6, -0x8000(r4)
	  stb       r5, -0x8000(r4)
	  stw       r7, -0x8000(r4)
	  sth       r0, 0x2(r3)
	  lmw       r23, 0x2C(r1)
	  addi      r1, r1, 0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211628
 * Size:	00001C
 */
void GXSetDispCopyGamma(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,7,0,24
	  lwzu      r3, 0x1EC(r4)
	  rlwinm    r3,r3,0,25,22
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211644
 * Size:	000170
 */
void GXCopyDisp(void)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x40
	  lwz       r7, 0x2A68(r13)
	  li        r0, 0x61
	  lis       r5, 0xCC01
	  lwz       r6, 0x1D8(r7)
	  rlwinm    r6,r6,0,0,30
	  stb       r0, -0x8000(r5)
	  ori       r6, r6, 0x1
	  rlwinm    r6,r6,0,31,27
	  ori       r6, r6, 0xE
	  stw       r6, -0x8000(r5)
	  lwz       r6, 0x1D0(r7)
	  stb       r0, -0x8000(r5)
	  rlwinm    r0,r6,0,0,29
	  stw       r0, -0x8000(r5)

	.loc_0x40:
	  rlwinm.   r0,r4,0,24,31
	  li        r0, 0
	  bne-      .loc_0x60
	  lwz       r5, 0x2A68(r13)
	  lwz       r5, 0x1DC(r5)
	  rlwinm    r5,r5,0,29,31
	  cmplwi    r5, 0x3
	  bne-      .loc_0x8C

	.loc_0x60:
	  lwz       r5, 0x2A68(r13)
	  lwz       r7, 0x1DC(r5)
	  rlwinm    r5,r7,26,31,31
	  cmplwi    r5, 0x1
	  bne-      .loc_0x8C
	  li        r0, 0x61
	  lis       r6, 0xCC01
	  stb       r0, -0x8000(r6)
	  rlwinm    r5,r7,0,26,24
	  li        r0, 0x1
	  stw       r5, -0x8000(r6)

	.loc_0x8C:
	  li        r9, 0x61
	  lwz       r7, 0x2A68(r13)
	  lis       r8, 0xCC01
	  stb       r9, -0x8000(r8)
	  rlwinm    r3,r3,27,8,31
	  oris      r10, r3, 0x4B00
	  lwz       r6, 0x1E0(r7)
	  rlwinm.   r5,r4,0,24,31
	  rlwinm    r3,r4,11,13,20
	  stw       r6, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  lwz       r4, 0x1E4(r7)
	  stw       r4, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  lwz       r4, 0x1E8(r7)
	  stw       r4, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  stw       r10, -0x8000(r8)
	  lwz       r4, 0x1EC(r7)
	  rlwinm    r4,r4,0,21,19
	  or        r3, r4, r3
	  stw       r3, 0x1EC(r7)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1EC
	  lwz       r3, 0x1EC(r3)
	  rlwinm    r3,r3,0,18,16
	  ori       r3, r3, 0x4000
	  stw       r3, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1EC
	  lwz       r3, 0x1EC(r3)
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x5200
	  stw       r3, 0x0(r4)
	  stb       r9, -0x8000(r8)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1EC(r4)
	  stw       r3, -0x8000(r8)
	  beq-      .loc_0x140
	  stb       r9, -0x8000(r8)
	  lwz       r3, 0x1D8(r4)
	  stw       r3, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  lwz       r3, 0x1D0(r4)
	  stw       r3, -0x8000(r8)

	.loc_0x140:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x160
	  li        r0, 0x61
	  lwz       r3, 0x2A68(r13)
	  lis       r4, 0xCC01
	  stb       r0, -0x8000(r4)
	  lwz       r0, 0x1DC(r3)
	  stw       r0, -0x8000(r4)

	.loc_0x160:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0x1
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802117B4
 * Size:	000190
 */
void GXCopyTex(void)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x40
	  lwz       r7, 0x2A68(r13)
	  li        r0, 0x61
	  lis       r5, 0xCC01
	  lwz       r6, 0x1D8(r7)
	  rlwinm    r6,r6,0,0,30
	  stb       r0, -0x8000(r5)
	  ori       r6, r6, 0x1
	  rlwinm    r6,r6,0,31,27
	  ori       r6, r6, 0xE
	  stw       r6, -0x8000(r5)
	  lwz       r6, 0x1D0(r7)
	  stb       r0, -0x8000(r5)
	  rlwinm    r0,r6,0,0,29
	  stw       r0, -0x8000(r5)

	.loc_0x40:
	  lwz       r6, 0x2A68(r13)
	  li        r0, 0
	  lbz       r5, 0x200(r6)
	  lwz       r7, 0x1DC(r6)
	  cmplwi    r5, 0
	  beq-      .loc_0x70
	  rlwinm    r5,r7,0,29,31
	  cmplwi    r5, 0x3
	  beq-      .loc_0x70
	  rlwinm    r0,r7,0,0,28
	  ori       r7, r0, 0x3
	  li        r0, 0x1

	.loc_0x70:
	  rlwinm.   r5,r4,0,24,31
	  bne-      .loc_0x84
	  rlwinm    r5,r7,0,29,31
	  cmplwi    r5, 0x3
	  bne-      .loc_0x98

	.loc_0x84:
	  rlwinm    r5,r7,26,31,31
	  cmplwi    r5, 0x1
	  bne-      .loc_0x98
	  li        r0, 0x1
	  rlwinm    r7,r7,0,26,24

	.loc_0x98:
	  rlwinm.   r5,r0,0,24,31
	  beq-      .loc_0xB0
	  li        r6, 0x61
	  lis       r5, 0xCC01
	  stb       r6, -0x8000(r5)
	  stw       r7, -0x8000(r5)

	.loc_0xB0:
	  li        r9, 0x61
	  lwz       r7, 0x2A68(r13)
	  lis       r8, 0xCC01
	  stb       r9, -0x8000(r8)
	  rlwinm    r3,r3,27,8,31
	  oris      r10, r3, 0x4B00
	  lwz       r6, 0x1F0(r7)
	  rlwinm.   r5,r4,0,24,31
	  rlwinm    r3,r4,11,13,20
	  stw       r6, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  lwz       r4, 0x1F4(r7)
	  stw       r4, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  lwz       r4, 0x1F8(r7)
	  stw       r4, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  stw       r10, -0x8000(r8)
	  lwz       r4, 0x1FC(r7)
	  rlwinm    r4,r4,0,21,19
	  or        r3, r4, r3
	  stw       r3, 0x1FC(r7)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1FC
	  lwz       r3, 0x1FC(r3)
	  rlwinm    r3,r3,0,18,16
	  stw       r3, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x1FC
	  lwz       r3, 0x1FC(r3)
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x5200
	  stw       r3, 0x0(r4)
	  stb       r9, -0x8000(r8)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1FC(r4)
	  stw       r3, -0x8000(r8)
	  beq-      .loc_0x160
	  stb       r9, -0x8000(r8)
	  lwz       r3, 0x1D8(r4)
	  stw       r3, -0x8000(r8)
	  stb       r9, -0x8000(r8)
	  lwz       r3, 0x1D0(r4)
	  stw       r3, -0x8000(r8)

	.loc_0x160:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x180
	  li        r0, 0x61
	  lwz       r3, 0x2A68(r13)
	  lis       r4, 0xCC01
	  stb       r0, -0x8000(r4)
	  lwz       r0, 0x1DC(r3)
	  stw       r0, -0x8000(r4)

	.loc_0x180:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0x1
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211944
 * Size:	000038
 */
void GXClearBoundingBox(void)
{
	/*
	.loc_0x0:
	  li        r6, 0x61
	  lwz       r3, 0x2A68(r13)
	  lis       r5, 0xCC01
	  lis       r4, 0x5500
	  stb       r6, -0x8000(r5)
	  addi      r0, r4, 0x3FF
	  stw       r0, -0x8000(r5)
	  lis       r4, 0x5600
	  addi      r4, r4, 0x3FF
	  stb       r6, -0x8000(r5)
	  li        r0, 0x1
	  stw       r4, -0x8000(r5)
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GXReadBoundingBox(void)
{
	// UNUSED FUNCTION
}
