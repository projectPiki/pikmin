

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void C_MTXIdentity(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDB94
 * Size:	00002C
 */
void PSMTXIdentity(void)
{
/*
.loc_0x0:
  lfs       f0, -0x3D24(r2)
  lfs       f1, -0x3D28(r2)
  psq_st    f0,0x8(r3),0,0
  ps_merge01f2, f0, f1
  psq_st    f0,0x18(r3),0,0
  ps_merge10f1, f1, f0
  psq_st    f0,0x20(r3),0,0
  psq_st    f2,0x10(r3),0,0
  psq_st    f1,0x0(r3),0,0
  psq_st    f1,0x28(r3),0,0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void C_MTXCopy(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void PSMTXCopy(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002A8
 */
void C_MTXConcat(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDBC0
 * Size:	0000CC
 */
void PSMTXConcat(void)
{
/*
.loc_0x0:
  stwu      r1, -0x40(r1)
  psq_l     f0,0x0(r3),0,0
  stfd      f14, 0x8(r1)
  psq_l     f6,0x0(r4),0,0
  lis       r6, 0x803E
  psq_l     f7,0x8(r4),0,0
  stfd      f15, 0x10(r1)
  addi      r6, r6, 0x7720
  stfd      f31, 0x28(r1)
  psq_l     f8,0x10(r4),0,0
  ps_muls0  f12, f6, f0
  psq_l     f2,0x10(r3),0,0
  ps_muls0  f13, f7, f0
  psq_l     f31,0x0(r6),0,0
  ps_muls0  f14, f6, f2
  psq_l     f9,0x18(r4),0,0
  ps_muls0  f15, f7, f2
  psq_l     f1,0x8(r3),0,0
  ps_madds1 f12, f8, f0, f12
  psq_l     f3,0x18(r3),0,0
  ps_madds1 f14, f8, f2, f14
  psq_l     f10,0x20(r4),0,0
  ps_madds1 f13, f9, f0, f13
  psq_l     f11,0x28(r4),0,0
  ps_madds1 f15, f9, f2, f15
  psq_l     f4,0x20(r3),0,0
  psq_l     f5,0x28(r3),0,0
  ps_madds0 f12, f10, f1, f12
  ps_madds0 f13, f11, f1, f13
  ps_madds0 f14, f10, f3, f14
  ps_madds0 f15, f11, f3, f15
  psq_st    f12,0x0(r5),0,0
  ps_muls0  f2, f6, f4
  ps_madds1 f13, f31, f1, f13
  ps_muls0  f0, f7, f4
  psq_st    f14,0x10(r5),0,0
  ps_madds1 f15, f31, f3, f15
  psq_st    f13,0x8(r5),0,0
  ps_madds1 f2, f8, f4, f2
  ps_madds1 f0, f9, f4, f0
  ps_madds0 f2, f10, f5, f2
  lfd       f14, 0x8(r1)
  psq_st    f15,0x18(r5),0,0
  ps_madds0 f0, f11, f5, f0
  psq_st    f2,0x20(r5),0,0
  ps_madds1 f0, f31, f5, f0
  lfd       f15, 0x10(r1)
  psq_st    f0,0x28(r5),0,0
  lfd       f31, 0x28(r1)
  addi      r1, r1, 0x40
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void C_MTXTranspose(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDC8C
 * Size:	000050
 */
void PSMTXTranspose(void)
{
/*
.loc_0x0:
  lfs       f0, -0x3D24(r2)
  psq_l     f1,0x0(r3),0,0
  stfs      f0, 0x2C(r4)
  psq_l     f2,0x10(r3),0,0
  ps_merge00f4, f1, f2
  psq_l     f3,0x8(r3),0x1,0
  ps_merge11f5, f1, f2
  psq_l     f2,0x18(r3),0x1,0
  psq_st    f4,0x0(r4),0,0
  psq_l     f1,0x20(r3),0,0
  ps_merge00f2, f3, f2
  psq_st    f5,0x10(r4),0,0
  ps_merge00f4, f1, f0
  psq_st    f2,0x20(r4),0,0
  ps_merge10f5, f1, f0
  psq_st    f4,0x8(r4),0,0
  lfs       f3, 0x28(r3)
  psq_st    f5,0x18(r4),0,0
  stfs      f3, 0x28(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002AC
 */
void C_MTXInverse(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDCDC
 * Size:	000104
 */
void PSMTXInverse(void)
{
/*
.loc_0x0:
  psq_l     f0,0x0(r3),0x1,0
  psq_l     f1,0x4(r3),0,0
  psq_l     f2,0x10(r3),0x1,0
  ps_merge10f6, f1, f0
  psq_l     f3,0x14(r3),0,0
  psq_l     f4,0x20(r3),0x1,0
  ps_merge10f7, f3, f2
  psq_l     f5,0x24(r3),0,0
  ps_mul    f11, f3, f6
  ps_mul    f13, f5, f7
  ps_merge10f8, f5, f4
  ps_msub   f11, f1, f7, f11
  ps_mul    f12, f1, f8
  ps_msub   f13, f3, f8, f13
  ps_mul    f10, f3, f4
  ps_msub   f12, f5, f6, f12
  ps_mul    f9, f0, f5
  ps_mul    f8, f1, f2
  ps_sub    f6, f6, f6
  ps_msub   f10, f2, f5, f10
  ps_mul    f7, f0, f13
  ps_msub   f9, f1, f4, f9
  ps_madd   f7, f2, f12, f7
  ps_msub   f8, f0, f3, f8
  ps_madd   f7, f4, f11, f7
  ps_cmpo0  f0, f7, f6
  bne-      .loc_0x74
  li        r3, 0
  blr       

.loc_0x74:
  .long     0x10003830
  ps_add    f6, f0, f0
  ps_mul    f5, f0, f0
  ps_nmadd  f0, f7, f5, f6
  ps_add    f6, f0, f0
  ps_mul    f5, f0, f0
  ps_nmadd  f0, f7, f5, f6
  lfs       f1, 0xC(r3)
  ps_muls0  f13, f13, f0
  lfs       f2, 0x1C(r3)
  ps_muls0  f12, f12, f0
  lfs       f3, 0x2C(r3)
  ps_muls0  f11, f11, f0
  ps_merge00f5, f13, f12
  ps_muls0  f10, f10, f0
  ps_merge11f4, f13, f12
  ps_muls0  f9, f9, f0
  psq_st    f5,0x0(r4),0,0
  ps_mul    f6, f13, f1
  psq_st    f4,0x10(r4),0,0
  ps_muls0  f8, f8, f0
  ps_madd   f6, f12, f2, f6
  psq_st    f10,0x20(r4),0x1,0
  ps_nmsub  f6, f11, f3, f6
  psq_st    f9,0x24(r4),0x1,0
  ps_mul    f7, f10, f1
  ps_merge00f5, f11, f6
  psq_st    f8,0x28(r4),0x1,0
  ps_merge11f4, f11, f6
  psq_st    f5,0x8(r4),0,0
  ps_madd   f7, f9, f2, f7
  psq_st    f4,0x18(r4),0,0
  ps_nmsub  f7, f8, f3, f7
  li        r3, 0x1
  psq_st    f7,0x2C(r4),0x1,0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00021C
 */
void C_MTXInvXpose(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void PSMTXInvXpose(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void MTXRotRad(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void MTXRotTrig(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void MTXRotAxisRad(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDDE0
 * Size:	00003C
 */
void MTXTrans(void)
{
/*
.loc_0x0:
  lfs       f4, -0x3D28(r2)
  stfs      f4, 0x0(r3)
  lfs       f0, -0x3D24(r2)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x8(r3)
  stfs      f1, 0xC(r3)
  stfs      f0, 0x10(r3)
  stfs      f4, 0x14(r3)
  stfs      f0, 0x18(r3)
  stfs      f2, 0x1C(r3)
  stfs      f0, 0x20(r3)
  stfs      f0, 0x24(r3)
  stfs      f4, 0x28(r3)
  stfs      f3, 0x2C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void MTXTransApply(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDE1C
 * Size:	000038
 */
void MTXScale(void)
{
/*
.loc_0x0:
  stfs      f1, 0x0(r3)
  lfs       f0, -0x3D24(r2)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x8(r3)
  stfs      f0, 0xC(r3)
  stfs      f0, 0x10(r3)
  stfs      f2, 0x14(r3)
  stfs      f0, 0x18(r3)
  stfs      f0, 0x1C(r3)
  stfs      f0, 0x20(r3)
  stfs      f0, 0x24(r3)
  stfs      f3, 0x28(r3)
  stfs      f0, 0x2C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void MTXScaleApply(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void MTXQuat(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void MTXReflect(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00018C
 */
void MTXLookAt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void MTXLightFrustum(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDE54
 * Size:	0000CC
 */
void MTXLightPerspective(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  stfd      f30, 0x48(r1)
  stfd      f29, 0x40(r1)
  stfd      f28, 0x38(r1)
  stfd      f27, 0x30(r1)
  stw       r31, 0x2C(r1)
  fmr       f27, f2
  mr        r31, r3
  fmr       f28, f3
  fmr       f29, f4
  fmr       f30, f5
  fmr       f31, f6
  lfs       f2, -0x3D1C(r2)
  lfs       f0, -0x3D18(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f0, f1
  bl        0x1DC30
  lfs       f3, -0x3D28(r2)
  fneg      f2, f30
  fneg      f0, f31
  fdivs     f4, f3, f1
  fdivs     f1, f4, f27
  fmuls     f3, f28, f1
  fmuls     f1, f4, f29
  stfs      f3, 0x0(r31)
  lfs       f3, -0x3D24(r2)
  stfs      f3, 0x4(r31)
  stfs      f2, 0x8(r31)
  stfs      f3, 0xC(r31)
  stfs      f3, 0x10(r31)
  stfs      f1, 0x14(r31)
  stfs      f0, 0x18(r31)
  stfs      f3, 0x1C(r31)
  stfs      f3, 0x20(r31)
  stfs      f3, 0x24(r31)
  lfs       f0, -0x3D20(r2)
  stfs      f0, 0x28(r31)
  stfs      f3, 0x2C(r31)
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lfd       f30, 0x48(r1)
  mtlr      r0
  lfd       f29, 0x40(r1)
  lfd       f28, 0x38(r1)
  lfd       f27, 0x30(r1)
  lwz       r31, 0x2C(r1)
  addi      r1, r1, 0x58
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void MTXLightOrtho(void)
{
	// UNUSED FUNCTION
}
