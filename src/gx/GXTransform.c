

/*
 * --INFO--
 * Address:	........
 * Size:	000174
 */
void GXProject(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802142F4
 * Size:	0000D4
 */
void GXSetProjection(void)
{
/*
.loc_0x0:
  lwz       r5, 0x2A68(r13)
  cmpwi     r4, 0x1
  stw       r4, 0x420(r5)
  lfs       f0, 0x0(r3)
  lwz       r4, 0x2A68(r13)
  stfs      f0, 0x424(r4)
  lfs       f0, 0x14(r3)
  lwz       r4, 0x2A68(r13)
  stfs      f0, 0x42C(r4)
  lfs       f0, 0x28(r3)
  lwz       r4, 0x2A68(r13)
  stfs      f0, 0x434(r4)
  lfs       f0, 0x2C(r3)
  lwz       r4, 0x2A68(r13)
  stfs      f0, 0x438(r4)
  bne-      .loc_0x5C
  lfs       f0, 0xC(r3)
  lwz       r4, 0x2A68(r13)
  stfs      f0, 0x428(r4)
  lfs       f0, 0x1C(r3)
  lwz       r3, 0x2A68(r13)
  stfs      f0, 0x430(r3)
  b         .loc_0x74

.loc_0x5C:
  lfs       f0, 0x8(r3)
  lwz       r4, 0x2A68(r13)
  stfs      f0, 0x428(r4)
  lfs       f0, 0x18(r3)
  lwz       r3, 0x2A68(r13)
  stfs      f0, 0x430(r3)

.loc_0x74:
  li        r0, 0x10
  lwz       r4, 0x2A68(r13)
  lis       r5, 0xCC01
  lis       r3, 0x6
  stb       r0, -0x8000(r5)
  addi      r0, r3, 0x1020
  stw       r0, -0x8000(r5)
  li        r0, 0
  lfs       f0, 0x424(r4)
  stfs      f0, -0x8000(r5)
  lfs       f0, 0x428(r4)
  stfs      f0, -0x8000(r5)
  lfs       f0, 0x42C(r4)
  stfs      f0, -0x8000(r5)
  lfs       f0, 0x430(r4)
  stfs      f0, -0x8000(r5)
  lfs       f0, 0x434(r4)
  stfs      f0, -0x8000(r5)
  lfs       f0, 0x438(r4)
  stfs      f0, -0x8000(r5)
  lwz       r3, 0x420(r4)
  stw       r3, -0x8000(r5)
  sth       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void GXSetProjectionv(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void GXGetProjectionv(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802143C8
 * Size:	000034
 */
void WriteMTXPS4x3(void)
{
/*
.loc_0x0:
  psq_l     f0,0x0(r3),0,0
  psq_l     f1,0x8(r3),0,0
  psq_l     f2,0x10(r3),0,0
  psq_l     f3,0x18(r3),0,0
  psq_l     f4,0x20(r3),0,0
  psq_l     f5,0x28(r3),0,0
  psq_st    f0,0x0(r4),0,0
  psq_st    f1,0x0(r4),0,0
  psq_st    f2,0x0(r4),0,0
  psq_st    f3,0x0(r4),0,0
  psq_st    f4,0x0(r4),0,0
  psq_st    f5,0x0(r4),0,0
  blr
*/
}

/*
 * --INFO--
 * Address:	802143FC
 * Size:	000034
 */
void WriteMTXPS3x3from3x4(void)
{
/*
.loc_0x0:
  psq_l     f0,0x0(r3),0,0
  lfs       f1, 0x8(r3)
  psq_l     f2,0x10(r3),0,0
  lfs       f3, 0x18(r3)
  psq_l     f4,0x20(r3),0,0
  lfs       f5, 0x28(r3)
  psq_st    f0,0x0(r4),0,0
  stfs      f1, 0x0(r4)
  psq_st    f2,0x0(r4),0,0
  stfs      f3, 0x0(r4)
  psq_st    f4,0x0(r4),0,0
  stfs      f5, 0x0(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void WriteMTXPS3x3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80214430
 * Size:	000024
 */
void WriteMTXPS4x2(void)
{
/*
.loc_0x0:
  psq_l     f0,0x0(r3),0,0
  psq_l     f1,0x8(r3),0,0
  psq_l     f2,0x10(r3),0,0
  psq_l     f3,0x18(r3),0,0
  psq_st    f0,0x0(r4),0,0
  psq_st    f1,0x0(r4),0,0
  psq_st    f2,0x0(r4),0,0
  psq_st    f3,0x0(r4),0,0
  blr
*/
}

/*
 * --INFO--
 * Address:	80214454
 * Size:	00003C
 */
void GXLoadPosMtxImm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  li        r6, 0x10
  lis       r5, 0xCC01
  rlwinm    r0,r4,2,0,29
  stb       r6, -0x8000(r5)
  oris      r0, r0, 0xB
  stw       r0, -0x8000(r5)
  subi      r4, r5, 0x8000
  bl        -0xB4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void GXLoadPosMtxIndx(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80214490
 * Size:	000040
 */
void GXLoadNrmMtxImm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  mulli     r4, r4, 0x3
  addi      r0, r4, 0x400
  lis       r5, 0xCC01
  li        r6, 0x10
  stb       r6, -0x8000(r5)
  oris      r0, r0, 0x8
  subi      r4, r5, 0x8000
  stw       r0, -0x8000(r5)
  bl        -0xC0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void GXLoadNrmMtxImm3x3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GXLoadNrmMtxIndx3x3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802144D0
 * Size:	00003C
 */
void GXSetCurrentMtx(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r4, 0x2A68(r13)
  addi      r4, r4, 0x80
  lwz       r0, 0x0(r4)
  rlwinm    r0,r0,0,0,25
  or        r0, r0, r3
  stw       r0, 0x0(r4)
  li        r3, 0
  bl        0x2F4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021450C
 * Size:	000084
 */
void GXLoadTexMtxImm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  cmplwi    r4, 0x40
  blt-      .loc_0x24
  subi      r0, r4, 0x40
  rlwinm    r4,r0,2,0,29
  addi      r7, r4, 0x500
  b         .loc_0x28

.loc_0x24:
  rlwinm    r7,r4,2,0,29

.loc_0x28:
  cmpwi     r5, 0x1
  bne-      .loc_0x38
  li        r4, 0x8
  b         .loc_0x3C

.loc_0x38:
  li        r4, 0xC

.loc_0x3C:
  subi      r0, r4, 0x1
  rlwinm    r0,r0,16,0,15
  li        r6, 0x10
  lis       r4, 0xCC01
  stb       r6, -0x8000(r4)
  or        r0, r7, r0
  cmpwi     r5, 0
  stw       r0, -0x8000(r4)
  bne-      .loc_0x6C
  subi      r4, r4, 0x8000
  bl        -0x1A8
  b         .loc_0x74

.loc_0x6C:
  subi      r4, r4, 0x8000
  bl        -0x14C

.loc_0x74:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void GXLoadTexMtxIndx(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80214590
 * Size:	00011C
 */
void GXSetViewportJitter(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  stfd      f30, 0x50(r1)
  stfd      f29, 0x48(r1)
  stfd      f28, 0x40(r1)
  stfd      f27, 0x38(r1)
  stfd      f26, 0x30(r1)
  cmplwi    r3, 0
  bne-      .loc_0x34
  lfs       f0, -0x3C28(r2)
  fsubs     f2, f2, f0

.loc_0x34:
  lfs       f11, -0x3C28(r2)
  fneg      f10, f4
  lfs       f0, -0x3C20(r2)
  lfs       f9, -0x3C24(r2)
  fmuls     f31, f3, f11
  lwz       r3, 0x2A68(r13)
  fmuls     f7, f4, f11
  stfs      f1, 0x43C(r3)
  fadds     f8, f1, f31
  fmuls     f30, f0, f6
  lwz       r3, 0x2A68(r13)
  fadds     f1, f2, f7
  stfs      f2, 0x440(r3)
  fmuls     f0, f0, f5
  fmuls     f29, f10, f11
  lwz       r3, 0x2A68(r13)
  fadds     f27, f9, f8
  stfs      f3, 0x444(r3)
  fadds     f26, f9, f1
  fsubs     f28, f30, f0
  lwz       r3, 0x2A68(r13)
  stfs      f4, 0x448(r3)
  lwz       r3, 0x2A68(r13)
  stfs      f5, 0x44C(r3)
  lwz       r3, 0x2A68(r13)
  stfs      f6, 0x450(r3)
  lwz       r3, 0x2A68(r13)
  lbz       r0, 0x454(r3)
  cmplwi    r0, 0
  beq-      .loc_0xB8
  fmr       f1, f5
  lfs       f2, 0x458(r3)
  bl        -0x560

.loc_0xB8:
  li        r0, 0x10
  lwz       r3, 0x2A68(r13)
  lis       r5, 0xCC01
  lis       r4, 0x5
  stb       r0, -0x8000(r5)
  addi      r0, r4, 0x101A
  stw       r0, -0x8000(r5)
  li        r0, 0
  stfs      f31, -0x8000(r5)
  stfs      f29, -0x8000(r5)
  stfs      f28, -0x8000(r5)
  stfs      f27, -0x8000(r5)
  stfs      f26, -0x8000(r5)
  stfs      f30, -0x8000(r5)
  sth       r0, 0x2(r3)
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  lfd       f30, 0x50(r1)
  mtlr      r0
  lfd       f29, 0x48(r1)
  lfd       f28, 0x40(r1)
  lfd       f27, 0x38(r1)
  lfd       f26, 0x30(r1)
  addi      r1, r1, 0x60
  blr
*/
}

/*
 * --INFO--
 * Address:	802146AC
 * Size:	000024
 */
void GXSetViewport(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  li        r3, 0x1
  bl        -0x12C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void GXGetViewportv(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802146D0
 * Size:	0000B0
 */
void GXSetScissor(void)
{
/*
.loc_0x0:
  lwz       r7, 0x2A68(r13)
  addi      r8, r3, 0x154
  subi      r0, r5, 0x1
  addi      r5, r7, 0xF8
  lwz       r3, 0x0(r5)
  add       r0, r8, r0
  addi      r4, r4, 0x154
  rlwinm    r3,r3,0,0,20
  or        r3, r3, r4
  stw       r3, 0x0(r5)
  subi      r3, r6, 0x1
  rlwinm    r7,r8,12,0,19
  lwz       r5, 0x2A68(r13)
  add       r4, r4, r3
  rlwinm    r3,r0,12,0,19
  addi      r8, r5, 0xF8
  lwz       r0, 0x0(r8)
  li        r6, 0x61
  lis       r5, 0xCC01
  rlwinm    r0,r0,0,20,8
  or        r0, r0, r7
  stw       r0, 0x0(r8)
  li        r0, 0x1
  lwz       r7, 0x2A68(r13)
  addi      r8, r7, 0xFC
  lwz       r7, 0x0(r8)
  rlwinm    r7,r7,0,0,20
  or        r4, r7, r4
  stw       r4, 0x0(r8)
  lwz       r4, 0x2A68(r13)
  addi      r7, r4, 0xFC
  lwz       r4, 0x0(r7)
  rlwinm    r4,r4,0,20,8
  or        r3, r4, r3
  stw       r3, 0x0(r7)
  stb       r6, -0x8000(r5)
  lwz       r4, 0x2A68(r13)
  lwz       r3, 0xF8(r4)
  stw       r3, -0x8000(r5)
  stb       r6, -0x8000(r5)
  lwz       r3, 0xFC(r4)
  stw       r3, -0x8000(r5)
  sth       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void GXGetScissor(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80214780
 * Size:	000044
 */
void GXSetScissorBoxOffset(void)
{
/*
.loc_0x0:
  addi      r5, r3, 0x154
  lwz       r3, 0x2A68(r13)
  addi      r0, r4, 0x154
  rlwinm    r4,r5,31,1,31
  rlwinm    r0,r0,31,1,31
  rlwinm    r4,r4,0,22,11
  rlwinm    r0,r0,10,0,21
  or        r0, r4, r0
  rlwinm    r5,r0,0,8,31
  li        r0, 0x61
  lis       r4, 0xCC01
  stb       r0, -0x8000(r4)
  oris      r5, r5, 0x5900
  li        r0, 0x1
  stw       r5, -0x8000(r4)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	802147C4
 * Size:	000028
 */
void GXSetClipMode(void)
{
/*
.loc_0x0:
  li        r0, 0x10
  lwz       r4, 0x2A68(r13)
  lis       r6, 0xCC01
  stb       r0, -0x8000(r6)
  li        r5, 0x1005
  li        r0, 0
  stw       r5, -0x8000(r6)
  stw       r3, -0x8000(r6)
  sth       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	802147EC
 * Size:	000084
 */
void __GXSetMatrixIndex(void)
{
/*
.loc_0x0:
  cmpwi     r3, 0x5
  bge-      .loc_0x40
  li        r0, 0x8
  lwz       r4, 0x2A68(r13)
  lis       r5, 0xCC01
  stb       r0, -0x8000(r5)
  li        r0, 0x30
  li        r3, 0x10
  stb       r0, -0x8000(r5)
  li        r0, 0x1018
  lwz       r4, 0x80(r4)
  stw       r4, -0x8000(r5)
  stb       r3, -0x8000(r5)
  stw       r0, -0x8000(r5)
  stw       r4, -0x8000(r5)
  b         .loc_0x74

.loc_0x40:
  li        r0, 0x8
  lwz       r4, 0x2A68(r13)
  lis       r5, 0xCC01
  stb       r0, -0x8000(r5)
  li        r0, 0x40
  li        r3, 0x10
  stb       r0, -0x8000(r5)
  li        r0, 0x1019
  lwz       r4, 0x84(r4)
  stw       r4, -0x8000(r5)
  stb       r3, -0x8000(r5)
  stw       r0, -0x8000(r5)
  stw       r4, -0x8000(r5)

.loc_0x74:
  lwz       r3, 0x2A68(r13)
  li        r0, 0
  sth       r0, 0x2(r3)
  blr
*/
}
