#include "types.h"
#include "V3D.h"

/*
 * --INFO--
 * Address:	8001BB60
 * Size:	000034
 */
// nonmatch by reason of epilogue lr restore scheduling
#ifdef NON_MATCHING
float V3D_GetAngle__FP9Vector3D_(struct Vector3D_* input_vec) { return (atanf2__Fff(input_vec->x, input_vec->y) + 3.141592); }
#else
asm float V3D_GetAngle__FP9Vector3D_(struct Vector3D_*)
{
	// clang-format off
	nofralloc
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f1, 0x0(r3)
	  lfs       f2, 0x4(r3)
	  bl        atanf2__Fff
	  lfd       f0, 3.141592
	  lwz       r0, 0xC(r1)
	  fadd      f1, f0, f1
	  frsp      f1, f1
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
}
#endif
// clang-format on
/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void V3D_Zero(Vector3D_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void V3D_Minus(Vector3D_*, Vector3D_*, Vector3D_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001BBA0
 * Size:	000040
 */
double V3D_Abs__FP9Vector3D_(struct Vector3D_* input_vec)
{
	return (sqrtf2__Ff((input_vec->x * input_vec->x) + (input_vec->y * input_vec->y) + (input_vec->z * input_vec->z)));
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void V3D_Norm(Vector3D_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void V3D_Resize(Vector3D_*, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void V3D_Copy(Vector3D_*, Vector3D_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void V3D_InitObj(Object3D_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E4
 */
void V3D_UpdateObj(Object3D_*, Vector3D_*, Vector3D_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void V3D_TMove(TVector3D_*, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void V3D_TimeUpdateObj(Object3D_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void V3D_Filter_Set(Filter_*, float*, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void V3D_Filter_Mix(Filter_*, Filter_*, Filter_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void V3D_Filter_MixD(Filter_*, float*, float*, unsigned long, unsigned long)
{
	// UNUSED FUNCTION
}
