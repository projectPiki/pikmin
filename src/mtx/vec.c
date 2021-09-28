

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void C_VECAdd(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PSVECAdd(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void C_VECSubtract(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PSVECSubtract(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void C_VECScale(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PSVECScale(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void C_VECNormalize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void PSVECNormalize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void C_VECSquareMag(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FE088
 * Size:	00001C
 */
void PSVECSquareMag(void)
{
/*
.loc_0x0:
  psq_l     f2,0x0(r3),0,0
  ps_mul    f3, f2, f2
  lfs       f4, 0x8(r3)
  ps_madd   f5, f4, f4, f3
  ps_sum0   f1, f5, f3, f3
  blr       
  blr
*/
}

/*
 * --INFO--
 * Address:	801FE0A4
 * Size:	000088
 */
void VECMag(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  bl        -0x28
  lfs       f0, -0x3CF8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x78
  fsqrte    f2, f1
  lfd       f4, -0x3CF0(r2)
  lfd       f3, -0x3CE8(r2)
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f0, f2, f0
  fmul      f0, f1, f0
  frsp      f0, f0
  stfs      f0, 0xC(r1)
  lfs       f1, 0xC(r1)
  b         .loc_0x78

.loc_0x78:
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void C_VECDotProduct(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PSVECDotProduct(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void C_VECCrossProduct(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void PSVECCrossProduct(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void VECHalfAngle(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void VECReflect(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void C_VECSquareDistance(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void PSVECSquareDistance(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void VECDistance(void)
{
	// UNUSED FUNCTION
}