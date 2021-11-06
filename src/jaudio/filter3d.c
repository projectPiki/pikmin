

/*
 * --INFO--
 * Address:	8001BB60
 * Size:	000034
 */
void V3D_GetAngle(Vector3D_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lfs       f1, 0x0(r3)
  lfs       f2, 0x4(r3)
  bl        -0xDEB4
  lfd       f0, -0x7E00(r2)
  lwz       r0, 0xC(r1)
  fadd      f1, f0, f1
  frsp      f1, f1
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void V3D_Zero(Vector3D_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void V3D_Minus(Vector3D_ *, Vector3D_ *, Vector3D_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001BBA0
 * Size:	000040
 */
void V3D_Abs(Vector3D_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lfs       f1, 0x0(r3)
  lfs       f0, 0x4(r3)
  fmuls     f1, f1, f1
  lfs       f2, 0x8(r3)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0xDFAC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void V3D_Norm(Vector3D_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void V3D_Resize(Vector3D_ *, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void V3D_Copy(Vector3D_ *, Vector3D_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void V3D_InitObj(Object3D_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E4
 */
void V3D_UpdateObj(Object3D_ *, Vector3D_ *, Vector3D_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void V3D_TMove(TVector3D_ *, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void V3D_TimeUpdateObj(Object3D_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void V3D_Filter_Set(Filter_ *, float *, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void V3D_Filter_Mix(Filter_ *, Filter_ *, Filter_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void V3D_Filter_MixD(Filter_ *, float *, float *, unsigned long, unsigned long)
{
	// UNUSED FUNCTION
}
