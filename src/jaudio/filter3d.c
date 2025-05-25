#include "jaudio/filter3d.h"

#include "jaudio/ja_calc.h"

/*
 * --INFO--
 * Address:	8001BB60
 * Size:	000034
 */
f32 V3D_GetAngle(Vector3D_* input_vec)
{
	f32 retval = (atanf2(input_vec->x, input_vec->y) + 3.141592);
	return retval;
}

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
f64 V3D_Abs(Vector3D_* input_vec)
{
	return (sqrtf2((input_vec->x * input_vec->x) + (input_vec->y * input_vec->y) + (input_vec->z * input_vec->z)));
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
void V3D_Resize(Vector3D_*, f32)
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
void V3D_TMove(TVector3D_*, f32)
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
void V3D_Filter_Set(Filter_*, f32*, u32)
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
void V3D_Filter_MixD(Filter_*, f32*, f32*, u32, u32)
{
	// UNUSED FUNCTION
}
