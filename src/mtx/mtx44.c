#include "Dolphin/mtx.h"
#include "math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void MTXFrustum(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
	// just for float ordering
	f32 tmp;

	tmp     = 1 / (r - l);
	m[0][0] = (2 * n * tmp);
	m[0][1] = 0;
	m[0][2] = (tmp * (r + l));
	m[0][3] = 0;
	tmp     = 1 / (t - b);
	m[1][0] = 0;
	m[1][1] = (2 * n * tmp);
	m[1][2] = (tmp * (t + b));
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	tmp     = 1 / (f - n);
	m[2][2] = (-n * tmp);
	m[2][3] = (tmp * -(f * n));
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = -1;
	m[3][3] = 0;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FDF20
 * Size:	0000D0
 */
void MTXPerspective(Mtx m, f32 fovY, f32 aspect, f32 n, f32 f)
{
	f32 angle;
	f32 cot;
	f32 tmp;

	angle   = (0.5f * fovY);
	angle   = angle * 0.017453293f;
	cot     = 1.0f / tanf(angle);
	m[0][0] = (cot / aspect);
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = (cot);
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	tmp     = 1.0f / (f - n);
	m[2][2] = (-n * tmp);
	m[2][3] = (tmp * -(f * n));
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = -1.0f;
	m[3][3] = 0.0f;
}

/*
 * --INFO--
 * Address:	801FDFF0
 * Size:	000098
 */
void MTXOrtho(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
	f32 tmp;

	tmp     = 1.0f / (r - l);
	m[0][0] = 2.0f * tmp;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = (tmp * -(r + l));
	tmp     = 1.0f / (t - b);
	m[1][0] = 0.0f;
	m[1][1] = 2.0f * tmp;
	m[1][2] = 0.0f;
	m[1][3] = (tmp * -(t + b));
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	tmp     = 1.0f / (f - n);
	m[2][2] = (-1.0f * tmp);
	m[2][3] = (-f * tmp);
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}
