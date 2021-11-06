

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void GXSetMisc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80210770
 * Size:	000068
 */
void GXFlush(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x4F0(r3)
  cmplwi    r0, 0
  beq-      .loc_0x20
  bl        0x3BC

.loc_0x20:
  li        r0, 0x4
  mtctr     r0
  li        r0, 0
  lis       r3, 0xCC01

.loc_0x30:
  stb       r0, -0x8000(r3)
  stb       r0, -0x8000(r3)
  stb       r0, -0x8000(r3)
  stb       r0, -0x8000(r3)
  stb       r0, -0x8000(r3)
  stb       r0, -0x8000(r3)
  stb       r0, -0x8000(r3)
  stb       r0, -0x8000(r3)
  bdnz+     .loc_0x30
  bl        -0x1AE50
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GXResetWriteGatherPipe(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void GXAbortFrame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void GXSetDrawSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXReadDrawSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void GXSetDrawDone(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void GXWaitDrawDone(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802107D8
 * Size:	000080
 */
void GXDrawDone(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  bl        -0x1786C
  li        r0, 0x61
  lis       r5, 0xCC01
  lis       r4, 0x4500
  stb       r0, -0x8000(r5)
  addi      r0, r4, 0x2
  stw       r0, -0x8000(r5)
  mr        r31, r3
  bl        -0x98
  li        r0, 0
  stb       r0, 0x3458(r13)
  mr        r3, r31
  bl        -0x17874
  bl        -0x178A0
  mr        r31, r3
  b         .loc_0x58

.loc_0x50:
  addi      r3, r13, 0x345C
  bl        -0x13E70

.loc_0x58:
  lbz       r0, 0x3458(r13)
  cmplwi    r0, 0
  beq+      .loc_0x50
  mr        r3, r31
  bl        -0x1789C
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80210858
 * Size:	000024
 */
void GXPixModeSync(void)
{
/*
.loc_0x0:
  li        r0, 0x61
  lwz       r4, 0x2A68(r13)
  lis       r5, 0xCC01
  stb       r0, -0x8000(r5)
  li        r0, 0x1
  lwz       r3, 0x1DC(r4)
  stw       r3, -0x8000(r5)
  sth       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXTexModeSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021087C
 * Size:	000014
 */
void GXPokeAlphaMode(void)
{
/*
.loc_0x0:
  lwz       r5, 0x3428(r13)
  rlwinm    r0,r4,0,24,31
  rlwimi    r0,r3,8,0,23
  sth       r0, 0x6(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	80210890
 * Size:	000014
 */
void GXPokeAlphaRead(void)
{
/*
.loc_0x0:
  rlwinm    r0,r3,0,30,28
  lwz       r3, 0x3428(r13)
  ori       r0, r0, 0x4
  sth       r0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	802108A4
 * Size:	00001C
 */
void GXPokeAlphaUpdate(void)
{
/*
.loc_0x0:
  lwz       r4, 0x3428(r13)
  rlwinm    r0,r3,4,20,27
  lhzu      r3, 0x2(r4)
  rlwinm    r3,r3,0,28,26
  or        r0, r3, r0
  sth       r0, 0x0(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	802108C0
 * Size:	000088
 */
void GXPokeBlendMode(void)
{
/*
.loc_0x0:
  lwz       r7, 0x3428(r13)
  cmpwi     r3, 0x1
  li        r9, 0x1
  addi      r10, r7, 0x2
  lhz       r7, 0x2(r7)
  beq-      .loc_0x24
  cmpwi     r3, 0x3
  beq-      .loc_0x24
  li        r9, 0

.loc_0x24:
  rlwinm    r8,r7,0,0,30
  subfic    r0, r3, 0x3
  cntlzw    r7, r0
  subfic    r0, r3, 0x2
  or        r8, r8, r9
  cntlzw    r0, r0
  rlwinm    r8,r8,0,21,19
  rlwinm    r3,r7,6,0,20
  or        r3, r8, r3
  rlwinm    r3,r3,0,31,29
  rlwinm    r0,r0,28,4,30
  or        r0, r3, r0
  rlwinm    r3,r0,0,20,15
  rlwinm    r0,r6,12,0,19
  or        r0, r3, r0
  rlwinm    r3,r0,0,24,20
  rlwinm    r0,r4,8,0,23
  or        r0, r3, r0
  rlwinm    r3,r0,0,27,23
  rlwinm    r0,r5,5,0,26
  or        r0, r3, r0
  rlwinm    r0,r0,0,8,31
  oris      r0, r0, 0x4100
  sth       r0, 0x0(r10)
  blr
*/
}

/*
 * --INFO--
 * Address:	80210948
 * Size:	00001C
 */
void GXPokeColorUpdate(void)
{
/*
.loc_0x0:
  lwz       r4, 0x3428(r13)
  rlwinm    r0,r3,3,21,28
  lhzu      r3, 0x2(r4)
  rlwinm    r3,r3,0,29,27
  or        r0, r3, r0
  sth       r0, 0x0(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	80210964
 * Size:	000014
 */
void GXPokeDstAlpha(void)
{
/*
.loc_0x0:
  lwz       r5, 0x3428(r13)
  rlwinm    r0,r3,8,16,23
  rlwimi    r0,r4,0,24,31
  sth       r0, 0x4(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	80210978
 * Size:	00001C
 */
void GXPokeDither(void)
{
/*
.loc_0x0:
  lwz       r4, 0x3428(r13)
  rlwinm    r0,r3,2,22,29
  lhzu      r3, 0x2(r4)
  rlwinm    r3,r3,0,30,28
  or        r0, r3, r0
  sth       r0, 0x0(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	80210994
 * Size:	000028
 */
void GXPokeZMode(void)
{
/*
.loc_0x0:
  rlwinm    r0,r3,0,24,31
  lwz       r3, 0x3428(r13)
  rlwinm    r6,r0,0,31,27
  rlwinm    r0,r4,1,0,30
  or        r0, r6, r0
  rlwinm    r4,r0,0,28,26
  rlwinm    r0,r5,4,20,27
  or        r0, r4, r0
  sth       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXPeekARGB(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GXPokeARGB(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void GXPeekZ(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXPokeZ(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void GXSetDrawSyncCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802109BC
 * Size:	000088
 */
void GXTokenInterruptHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x2E0(r1)
  stw       r31, 0x2DC(r1)
  stw       r30, 0x2D8(r1)
  mr        r30, r4
  lwz       r0, 0x3450(r13)
  lwz       r3, 0x3428(r13)
  cmplwi    r0, 0
  lhz       r31, 0xE(r3)
  beq-      .loc_0x5C
  addi      r3, r1, 0x10
  bl        -0x195B0
  addi      r3, r1, 0x10
  bl        -0x19780
  lwz       r12, 0x3450(r13)
  addi      r3, r31, 0
  mtlr      r12
  blrl      
  addi      r3, r1, 0x10
  bl        -0x195D0
  mr        r3, r30
  bl        -0x197A0

.loc_0x5C:
  lwz       r3, 0x3428(r13)
  lhzu      r0, 0xA(r3)
  rlwinm    r0,r0,0,30,28
  ori       r0, r0, 0x4
  sth       r0, 0x0(r3)
  lwz       r0, 0x2E4(r1)
  lwz       r31, 0x2DC(r1)
  lwz       r30, 0x2D8(r1)
  mtlr      r0
  addi      r1, r1, 0x2E0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void GXSetDrawDoneCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80210A44
 * Size:	000084
 */
void GXFinishInterruptHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x2E0(r1)
  stw       r31, 0x2DC(r1)
  addi      r31, r4, 0
  lwz       r5, 0x3428(r13)
  lhz       r0, 0xA(r5)
  rlwinm    r0,r0,0,29,27
  ori       r0, r0, 0x8
  sth       r0, 0xA(r5)
  lwz       r0, 0x3454(r13)
  stb       r3, 0x3458(r13)
  cmplwi    r0, 0
  beq-      .loc_0x68
  addi      r3, r1, 0x10
  bl        -0x19648
  addi      r3, r1, 0x10
  bl        -0x19818
  lwz       r12, 0x3454(r13)
  mtlr      r12
  blrl      
  addi      r3, r1, 0x10
  bl        -0x19664
  mr        r3, r31
  bl        -0x19834

.loc_0x68:
  addi      r3, r13, 0x345C
  bl        -0x14008
  lwz       r0, 0x2E4(r1)
  lwz       r31, 0x2DC(r1)
  addi      r1, r1, 0x2E0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80210AC8
 * Size:	000080
 */
void __GXPEInit(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8021
  stw       r0, 0x4(r1)
  addi      r4, r3, 0x9BC
  li        r3, 0x12
  stwu      r1, -0x8(r1)
  bl        -0x17B18
  lis       r3, 0x8021
  addi      r4, r3, 0xA44
  li        r3, 0x13
  bl        -0x17B28
  addi      r3, r13, 0x345C
  bl        -0x15024
  li        r3, 0x2000
  bl        -0x1775C
  li        r3, 0x1000
  bl        -0x17764
  lwz       r3, 0x3428(r13)
  lhzu      r0, 0xA(r3)
  rlwinm    r0,r0,0,30,28
  ori       r0, r0, 0x4
  rlwinm    r0,r0,0,29,27
  ori       r0, r0, 0x8
  rlwinm    r0,r0,0,0,30
  ori       r0, r0, 0x1
  rlwinm    r0,r0,0,31,29
  ori       r0, r0, 0x2
  sth       r0, 0x0(r3)
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void GXCompressZ16(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void GXDecompressZ16(void)
{
	// UNUSED FUNCTION
}
