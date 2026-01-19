#include "Dolphin/OS/OSError.h"
#include "Dolphin/mtx.h"
#include <math.h>

// Technically not required, but "mtx.c" needs this pragma so I feel it belongs here too.
#pragma dont_inline on

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C (Matching by size)
 */
void C_MTXFrustum(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
	f32 tmp;

	OSAssertMsgLine(105, m, "MTXFrustum():  NULL Mtx44Ptr 'm' ");
	OSAssertMsgLine(106, t != b, "MTXFrustum():  't' and 'b' clipping planes are equal ");
	OSAssertMsgLine(107, l != r, "MTXFrustum():  'l' and 'r' clipping planes are equal ");
	OSAssertMsgLine(108, n != f, "MTXFrustum():  'n' and 'f' clipping planes are equal ");

	tmp       = 1.0f / (r - l);
	m[0][0]   = (2 * n) * tmp;
	m[0][1]   = 0.0f;
	m[0][2]   = (r + l) * tmp;
	m[0][3]   = 0.0f;

	tmp       = 1.0f / (t - b);
	m[1][0]   = 0.0f;
	m[1][1]   = (2 * n) * tmp;
	m[1][2]   = (t + b) * tmp;
	m[1][3]   = 0.0f;

	tmp       = 1.0f / (f - n);
	m[2][0]   = 0.0f;
	m[2][1]   = 0.0f;
	m[2][2]   = -(1 * n) * tmp;
	m[2][3]   = -(f * n) * tmp;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = -1.0f;
	m[3][3] = 0.0f;
}

/**
 * @TODO: Documentation
 */
void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f)
{
	f32 angle;
	f32 cot;
	f32 tmp;

	OSAssertMsgLine(179, m, "MTXPerspective():  NULL Mtx44Ptr 'm' ");
	OSAssertMsgLine(180, (fovY > 0.0) && (fovY < 180.0), "MTXPerspective():  'fovY' out of range ");
	OSAssertMsgLine(181, 0.0f != aspect, "MTXPerspective():  'aspect' is 0 ");

	angle = (0.5f * fovY);
	angle = MTXDegToRad(angle);
	cot   = 1.0f / tanf(angle);

	m[0][0] = (cot / aspect);
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = (cot);
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	tmp       = 1.0f / (f - n);
	m[2][0]   = 0.0f;
	m[2][1]   = 0.0f;
	m[2][2]   = -(1 * n) * tmp;
	m[2][3]   = -(f * n) * tmp;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = -1.0f;
	m[3][3] = 0.0f;
}

/**
 * @TODO: Documentation
 */
void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
	f32 tmp;

	OSAssertMsgLine(254, m, "MTXOrtho():  NULL Mtx44Ptr 'm' ");
	OSAssertMsgLine(255, t != b, "MTXOrtho():  't' and 'b' clipping planes are equal ");
	OSAssertMsgLine(256, l != r, "MTXOrtho():  'l' and 'r' clipping planes are equal ");
	OSAssertMsgLine(257, n != f, "MTXOrtho():  'n' and 'f' clipping planes are equal ");

	tmp       = 1.0f / (r - l);
	m[0][0]   = 2.0f * tmp;
	m[0][1]   = 0.0f;
	m[0][2]   = 0.0f;
	m[0][3]   = (tmp * -(r + l));

	tmp       = 1.0f / (t - b);
	m[1][0]   = 0.0f;
	m[1][1]   = 2.0f * tmp;
	m[1][2]   = 0.0f;
	m[1][3]   = -(t + b) * tmp;

	tmp       = 1.0f / (f - n);
	m[2][0]   = 0.0f;
	m[2][1]   = 0.0f;
	m[2][2]   = (-1.0f * tmp);
	m[2][3]   = (-f * tmp);

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00004c (Matching by size)
 */
void C_MTX44Identity(Mtx44 m)
{
	OSAssertMsgLine(324, m, "MTX44Identity():  NULL Mtx44 'm' ");

	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void PSMTX44Identity(register Mtx44 m)
{
	register f32 c1;
	register f32 c0;

	c1 = 1.0f;
	c0 = 0.0f;

#ifdef __MWERKS__
	asm {
		stfs    c1, 0x0000 (m)
		psq_st  c0, 0x0004 (m), 0, 0
		psq_st  c0, 0x000c (m), 0, 0
		stfs    c1, 0x0014 (m)
		psq_st  c0, 0x0018 (m), 0, 0
		psq_st  c0, 0x0020 (m), 0, 0
		stfs    c1, 0x0028 (m)
		psq_st  c0, 0x002c (m), 0, 0
		psq_st  c0, 0x0034 (m), 0, 0
		stfs    c1, 0x003c (m)
	}
#endif
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00008c (Matching by size)
 */
void C_MTX44Copy(const Mtx44 src, Mtx44 dst)
{
	OSAssertMsgLine(382, src, "MTX44Copy():  NULL Mtx44Ptr 'src' ");
	OSAssertMsgLine(383, dst, "MTX44Copy():  NULL Mtx44Ptr 'dst' ");

	if (src != dst) {
		dst[0][0] = src[0][0];
		dst[0][1] = src[0][1];
		dst[0][2] = src[0][2];
		dst[0][3] = src[0][3];

		dst[1][0] = src[1][0];
		dst[1][1] = src[1][1];
		dst[1][2] = src[1][2];
		dst[1][3] = src[1][3];

		dst[2][0] = src[2][0];
		dst[2][1] = src[2][1];
		dst[2][2] = src[2][2];
		dst[2][3] = src[2][3];

		dst[3][0] = src[3][0];
		dst[3][1] = src[3][1];
		dst[3][2] = src[3][2];
		dst[3][3] = src[3][3];
	}
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000044 (Matching by size)
 */
void PSMTX44Copy(register const Mtx44 src, register Mtx44 dst)
{
#ifdef __MWERKS__
	asm {
		psq_l   f1, 0x0000 (src), 0, 0
		psq_st  f1, 0x0000 (dst), 0, 0
		psq_l   f1, 0x0008 (src), 0, 0
		psq_st  f1, 0x0008 (dst), 0, 0
		psq_l   f1, 0x0010 (src), 0, 0
		psq_st  f1, 0x0010 (dst), 0, 0
		psq_l   f1, 0x0018 (src), 0, 0
		psq_st  f1, 0x0018 (dst), 0, 0
		psq_l   f1, 0x0020 (src), 0, 0
		psq_st  f1, 0x0020 (dst), 0, 0
		psq_l   f1, 0x0028 (src), 0, 0
		psq_st  f1, 0x0028 (dst), 0, 0
		psq_l   f1, 0x0030 (src), 0, 0
		psq_st  f1, 0x0030 (dst), 0, 0
		psq_l   f1, 0x0038 (src), 0, 0
		psq_st  f1, 0x0038 (dst), 0, 0
	}
#endif
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000450 (Matching by size)
 */
void C_MTX44Concat(const Mtx44 a, const Mtx44 b, Mtx44 ab)
{
	Mtx44 tmp;
	Mtx44Ptr m;

	OSAssertMsgLine(454, a, "MTX44Concat():  NULL Mtx44Ptr 'a'  ");
	OSAssertMsgLine(455, b, "MTX44Concat():  NULL Mtx44Ptr 'b'  ");
	OSAssertMsgLine(456, ab, "MTX44Concat():  NULL Mtx44Ptr 'ab' ");

	if (ab == a || ab == b) {
		m = tmp;
	} else {
		m = ab;
	}

	m[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0]) + (a[0][2] * b[2][0]) + (a[0][3] * b[3][0]);
	m[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1]) + (a[0][2] * b[2][1]) + (a[0][3] * b[3][1]);
	m[0][2] = (a[0][0] * b[0][2]) + (a[0][1] * b[1][2]) + (a[0][2] * b[2][2]) + (a[0][3] * b[3][2]);
	m[0][3] = (a[0][0] * b[0][3]) + (a[0][1] * b[1][3]) + (a[0][2] * b[2][3]) + (a[0][3] * b[3][3]);

	m[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0]) + (a[1][2] * b[2][0]) + (a[1][3] * b[3][0]);
	m[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1]) + (a[1][2] * b[2][1]) + (a[1][3] * b[3][1]);
	m[1][2] = (a[1][0] * b[0][2]) + (a[1][1] * b[1][2]) + (a[1][2] * b[2][2]) + (a[1][3] * b[3][2]);
	m[1][3] = (a[1][0] * b[0][3]) + (a[1][1] * b[1][3]) + (a[1][2] * b[2][3]) + (a[1][3] * b[3][3]);

	m[2][0] = (a[2][0] * b[0][0]) + (a[2][1] * b[1][0]) + (a[2][2] * b[2][0]) + (a[2][3] * b[3][0]);
	m[2][1] = (a[2][0] * b[0][1]) + (a[2][1] * b[1][1]) + (a[2][2] * b[2][1]) + (a[2][3] * b[3][1]);
	m[2][2] = (a[2][0] * b[0][2]) + (a[2][1] * b[1][2]) + (a[2][2] * b[2][2]) + (a[2][3] * b[3][2]);
	m[2][3] = (a[2][0] * b[0][3]) + (a[2][1] * b[1][3]) + (a[2][2] * b[2][3]) + (a[2][3] * b[3][3]);

	m[3][0] = (a[3][0] * b[0][0]) + (a[3][1] * b[1][0]) + (a[3][2] * b[2][0]) + (a[3][3] * b[3][0]);
	m[3][1] = (a[3][0] * b[0][1]) + (a[3][1] * b[1][1]) + (a[3][2] * b[2][1]) + (a[3][3] * b[3][1]);
	m[3][2] = (a[3][0] * b[0][2]) + (a[3][1] * b[1][2]) + (a[3][2] * b[2][2]) + (a[3][3] * b[3][2]);
	m[3][3] = (a[3][0] * b[0][3]) + (a[3][1] * b[1][3]) + (a[3][2] * b[2][3]) + (a[3][3] * b[3][3]);

	if (m == tmp) {
		C_MTX44Copy(tmp, ab);
	}
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000104 (Matching by size)
 */
ASM void PSMTX44Concat(register const Mtx44 a, register const Mtx44 b, register Mtx44 ab)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	psq_l      f0, 0x0(a), 0, 0
	psq_l      f2, 0x0(b), 0, 0
	ps_muls0   f6, f2, f0
	psq_l      f3, 0x10(b), 0, 0
	psq_l      f4, 0x20(b), 0, 0
	ps_madds1  f6, f3, f0, f6
	psq_l      f1, 0x8(a), 0, 0
	psq_l      f5, 0x30(b), 0, 0
	ps_madds0  f6, f4, f1, f6
	psq_l      f0, 0x10(a), 0, 0
	ps_madds1  f6, f5, f1, f6
	psq_l      f1, 0x18(a), 0, 0
	ps_muls0   f8, f2, f0
	ps_madds1  f8, f3, f0, f8
	psq_l      f0, 0x20(a), 0, 0
	ps_madds0  f8, f4, f1, f8
	ps_madds1  f8, f5, f1, f8
	psq_l      f1, 0x28(a), 0, 0
	ps_muls0   f10, f2, f0
	ps_madds1  f10, f3, f0, f10
	psq_l      f0, 0x30(a), 0, 0
	ps_madds0  f10, f4, f1, f10
	ps_madds1  f10, f5, f1, f10
	psq_l      f1, 0x38(a), 0, 0
	ps_muls0   f12, f2, f0
	psq_l      f2, 0x8(b), 0, 0
	ps_madds1  f12, f3, f0, f12
	psq_l      f0, 0x0(a), 0, 0
	ps_madds0  f12, f4, f1, f12
	psq_l      f3, 0x18(b), 0, 0
	ps_madds1  f12, f5, f1, f12
	psq_l      f1, 0x8(a), 0, 0
	ps_muls0   f7, f2, f0
	psq_l      f4, 0x28(b), 0, 0
	ps_madds1  f7, f3, f0, f7
	psq_l      f5, 0x38(b), 0, 0
	ps_madds0  f7, f4, f1, f7
	psq_l      f0, 0x10(a), 0, 0
	ps_madds1  f7, f5, f1, f7
	psq_l      f1, 0x18(a), 0, 0
	ps_muls0   f9, f2, f0
	psq_st     f6, 0x0(ab), 0, 0
	ps_madds1  f9, f3, f0, f9
	psq_l      f0, 0x20(a), 0, 0
	ps_madds0  f9, f4, f1, f9
	psq_st     f8, 0x10(ab), 0, 0
	ps_madds1  f9, f5, f1, f9
	psq_l      f1, 0x28(a), 0, 0
	ps_muls0   f11, f2, f0
	psq_st     f10, 0x20(ab), 0, 0
	ps_madds1  f11, f3, f0, f11
	psq_l      f0, 0x30(a), 0, 0
	ps_madds0  f11, f4, f1, f11
	psq_st     f12, 0x30(ab), 0, 0
	ps_madds1  f11, f5, f1, f11
	psq_l      f1, 0x38(a), 0, 0
	ps_muls0   f13, f2, f0
	psq_st     f7, 0x8(ab), 0, 0
	ps_madds1  f13, f3, f0, f13
	psq_st     f9, 0x18(ab), 0, 0
	ps_madds0  f13, f4, f1, f13
	psq_st     f11, 0x28(ab), 0, 0
	ps_madds1  f13, f5, f1, f13
	psq_st     f13, 0x38(ab), 0, 0
	blr
#endif // clang-format on
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0000c4 (Matching by size)
 */
void C_MTX44Transpose(const Mtx44 src, Mtx44 xPose)
{
	Mtx44 tmp;
	Mtx44Ptr m;

	OSAssertMsgLine(637, src, "MTX44Transpose():  NULL Mtx44Ptr 'src' ");
	OSAssertMsgLine(638, xPose, "MTX44Transpose():  NULL Mtx44Ptr 'xPose' ");

	if (src == xPose) {
		m = tmp;
	} else {
		m = xPose;
	}

	m[0][0] = src[0][0];
	m[0][1] = src[1][0];
	m[0][2] = src[2][0];
	m[0][3] = src[3][0];

	m[1][0] = src[0][1];
	m[1][1] = src[1][1];
	m[1][2] = src[2][1];
	m[1][3] = src[3][1];

	m[2][0] = src[0][2];
	m[2][1] = src[1][2];
	m[2][2] = src[2][2];
	m[2][3] = src[3][2];

	m[3][0] = src[0][3];
	m[3][1] = src[1][3];
	m[3][2] = src[2][3];
	m[3][3] = src[3][3];

	if (m == tmp) {
		C_MTX44Copy(tmp, xPose);
	}
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000064 (Matching by size)
 */
ASM void PSMTX44Transpose(register const Mtx44 src, register Mtx44 xPose) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	psq_l       f0, 0x0(src), 0, 0
	psq_l       f1, 0x10(src), 0, 0
	ps_merge00  f4, f0, f1
	psq_l       f2, 0x8(src), 0, 0
	psq_st      f4, 0x0(xPose), 0, 0
	ps_merge11  f5, f0, f1
	psq_l       f3, 0x18(src), 0, 0
	psq_st      f5, 0x10(xPose), 0, 0
	ps_merge00  f4, f2, f3
	psq_l       f0, 0x20(src), 0, 0
	psq_st      f4, 0x20(xPose), 0, 0
	ps_merge11  f5, f2, f3
	psq_l       f1, 0x30(src), 0, 0
	psq_st      f5, 0x30(xPose), 0, 0
	ps_merge00  f4, f0, f1
	psq_l       f2, 0x28(src), 0, 0
	psq_st      f4, 0x8(xPose), 0, 0
	ps_merge11  f5, f0, f1
	psq_l       f3, 0x38(src), 0, 0
	psq_st      f5, 0x18(xPose), 0, 0
	ps_merge00  f4, f2, f3
	psq_st      f4, 0x28(xPose), 0, 0
	ps_merge11  f5, f2, f3
	psq_st      f5, 0x38(xPose), 0, 0
	blr
#endif // clang-format on
}

#define SWAP(a, b) \
	{              \
		f32 tmp;   \
		tmp = a;   \
		a   = b;   \
		b   = tmp; \
	}

/**
 * @todo Documentation
 * @note UNUSED Size: 0003f0 (Nonmatching)
 */
u32 C_MTX44Inverse(const Mtx44 src, Mtx44 inv)
{
	Mtx44 gjm;
	s32 i;
	s32 j;
	s32 k;
	f32 w;
	f32 max;
	s32 swp;
	f32 ftmp;

	OSAssertMsgLine(734, src, "MTX44Inverse():  NULL Mtx44Ptr 'src' ");
	OSAssertMsgLine(735, inv, "MTX44Inverse():  NULL Mtx44Ptr 'inv' ");

	C_MTX44Copy(src, gjm);
	C_MTX44Identity(inv);

	for (i = 0; i < 4; i++) {
		max = 0.0f;
		swp = i;

		for (k = i; k < 4; k++) {
			ftmp = fabsf(gjm[k][i]);
			if (ftmp > max) {
				max = ftmp;
				swp = k;
			}
		}

		if (max == 0.0f) {
			return FALSE;
		}

		if (swp != i) {
			for (k = 0; k < 4; k++) {
				SWAP(gjm[i][k], gjm[swp][k]);
				SWAP(inv[i][k], inv[swp][k]);
			}
		}

		w = 1.0f / gjm[i][i];
		for (j = 0; j < 4; j++) {
			gjm[i][j] *= w;
			inv[i][j] *= w;
		}

		for (k = 0; k < 4; k++) {
			if (k != i) {
				w = gjm[k][i];
				for (j = 0; j < 4; j++) {
					gjm[k][j] -= gjm[i][j] * w;
					inv[k][j] -= inv[i][j] * w;
				}
			}
		}
	}

	return TRUE;
}

#undef SWAP

/**
 * @todo Documentation
 * @note UNUSED Size: 00004c (Matching by size)
 */
void C_MTX44Trans(Mtx44 m, f32 xT, f32 yT, f32 zT)
{
	OSAssertMsgLine(835, m, "MTX44Trans():  NULL Mtx44Ptr 'm' ");

	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = xT;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = yT;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = zT;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00003c (Matching by size)
 */
void PSMTX44Trans(register Mtx44 m, register f32 xT, register f32 yT, register f32 zT)
{
	register f32 c_zero;
	register f32 c_one;
	register f32 c_01;

	c_zero = 0.0f;
	c_one  = 1.0f;

#ifdef __MWERKS__
	asm {
		stfs        xT, 0xc(m)
		stfs        yT, 0x1c(m)
		ps_merge00  c_01, c_zero, c_one
		stfs        zT, 0x2c(m)
		psq_st      c_one, 0x0(m), 1, 0
		psq_st      c_zero, 0x4(m), 0, 0
		psq_st      c_01, 0x10(m), 0, 0
		psq_st      c_zero, 0x18(m), 1, 0
		psq_st      c_zero, 0x20(m), 0, 0
		psq_st      c_one, 0x28(m), 1, 0
		psq_st      c_zero, 0x30(m), 0, 0
		psq_st      c_01, 0x38(m), 0, 0
	}
#endif
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000098 (Matching by size)
 */
void C_MTX44TransApply(const Mtx44 src, Mtx44 dst, f32 xT, f32 yT, f32 zT)
{
	OSAssertMsgLine(899, src, "MTX44TransApply(): NULL Mtx44Ptr 'src' ");
	OSAssertMsgLine(900, dst, "MTX44TransApply(): NULL Mtx44Ptr 'dst' ");

	if (src != dst) {
		dst[0][0] = src[0][0];
		dst[0][1] = src[0][1];
		dst[0][2] = src[0][2];

		dst[1][0] = src[1][0];
		dst[1][1] = src[1][1];
		dst[1][2] = src[1][2];

		dst[2][0] = src[2][0];
		dst[2][1] = src[2][1];
		dst[2][2] = src[2][2];

		dst[3][0] = src[3][0];
		dst[3][1] = src[3][1];
		dst[3][2] = src[3][2];

		dst[3][3] = src[3][3];
	}

	dst[0][3] = (src[0][3] + xT);
	dst[1][3] = (src[1][3] + yT);
	dst[2][3] = (src[2][3] + zT);
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00005c (Matching by size)
 */
ASM void PSMTX44TransApply(register const Mtx44 src, register Mtx44 dst, register f32 xT, register f32 yT, register f32 zT)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	psq_l    f4, 0x0(src), 0, 0
	frsp     xT, xT
	psq_l    f5, 0x8(src), 0, 0
	frsp     yT, yT
	psq_l    f6, 0x10(src), 0, 0
	frsp     zT, zT
	psq_l    f7, 0x18(src), 0, 0
	psq_st   f4, 0x0(dst), 0, 0
	ps_sum1  f5, xT, f5, f5
	psq_l    f4, 0x28(src), 0, 0
	psq_st   f6, 0x10(dst), 0, 0
	ps_sum1  f7, yT, f7, f7
	psq_l    f8, 0x20(src), 0, 0
	psq_st   f5, 0x8(dst), 0, 0
	ps_sum1  f4, zT, f4, f4
	psq_st   f7, 0x18(dst), 0, 0
	psq_st   f8, 0x20(dst), 0, 0
	psq_l    f5, 0x30(src), 0, 0
	psq_l    f6, 0x38(src), 0, 0
	psq_st   f4, 0x28(dst), 0, 0
	psq_st   f5, 0x30(dst), 0, 0
	psq_st   f6, 0x38(dst), 0, 0
	blr
#endif // clang-format on
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00004c (Matching by size)
 */
void C_MTX44Scale(Mtx44 m, f32 xS, f32 yS, f32 zS)
{
	OSAssertMsgLine(976, m, "MTX44Scale():  NULL Mtx44Ptr 'm' ");

	m[0][0] = xS;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = yS;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = zS;
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void PSMTX44Scale(register Mtx44 m, register f32 xS, register f32 yS, register f32 zS)
{
	register f32 c_zero;
	register f32 c_one;

	c_zero = 0.0f;
	c_one  = 1.0f;

#ifdef __MWERKS__
	asm {
		stfs    xS, 0x0(m)
		psq_st  c_zero, 0x4(m), 0, 0
		psq_st  c_zero, 0xc(m), 0, 0
		stfs    yS, 0x14(m)
		psq_st  c_zero, 0x18(m), 0, 0
		psq_st  c_zero, 0x20(m), 0, 0
		stfs    zS, 0x28(m)
		psq_st  c_zero, 0x2c(m), 0, 0
		psq_st  c_zero, 0x34(m), 0, 0
		stfs    c_one, 0x3c(m)
	}
#endif
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0000b4 (Matching by size)
 */
void C_MTX44ScaleApply(const Mtx44 src, Mtx44 dst, f32 xS, f32 yS, f32 zS)
{
	OSAssertMsgLine(1036, src, "MTX44ScaleApply(): NULL Mtx44Ptr 'src' ");
	OSAssertMsgLine(1037, dst, "MTX44ScaleApply(): NULL Mtx44Ptr 'dst' ");

	dst[0][0] = (src[0][0] * xS);
	dst[0][1] = (src[0][1] * xS);
	dst[0][2] = (src[0][2] * xS);
	dst[0][3] = (src[0][3] * xS);

	dst[1][0] = (src[1][0] * yS);
	dst[1][1] = (src[1][1] * yS);
	dst[1][2] = (src[1][2] * yS);
	dst[1][3] = (src[1][3] * yS);

	dst[2][0] = (src[2][0] * zS);
	dst[2][1] = (src[2][1] * zS);
	dst[2][2] = (src[2][2] * zS);
	dst[2][3] = (src[2][3] * zS);

	dst[3][0] = src[3][0];
	dst[3][1] = src[3][1];
	dst[3][2] = src[3][2];
	dst[3][3] = src[3][3];
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00005c (Matching by size)
 */
ASM void PSMTX44ScaleApply(register const Mtx44 src, register Mtx44 dst, register f32 xS, register f32 yS, register f32 zS)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	psq_l     f4, 0x0(src), 0, 0
	psq_l     f5, 0x8(src), 0, 0
	psq_l     f6, 0x10(src), 0, 0
	ps_muls0  f4, f4, xS
	psq_l     f7, 0x18(src), 0, 0
	ps_muls0  f5, f5, xS
	psq_l     f8, 0x20(src), 0, 0
	psq_st    f4, 0x0(dst), 0, 0
	ps_muls0  f6, f6, yS
	psq_l     f9, 0x28(src), 0, 0
	psq_st    f5, 0x8(dst), 0, 0
	ps_muls0  f7, f7, yS
	psq_l     f10, 0x30(src), 0, 0
	psq_st    f6, 0x10(dst), 0, 0
	ps_muls0  f8, f8, zS
	psq_l     f11, 0x38(src), 0, 0
	psq_st    f7, 0x18(dst), 0, 0
	ps_muls0  f9, f9, zS
	psq_st    f8, 0x20(dst), 0, 0
	psq_st    f9, 0x28(dst), 0, 0
	psq_st    f10, 0x30(dst), 0, 0
	psq_st    f11, 0x38(dst), 0, 0
	blr
#endif // clang-format on
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000070 (Matching by size)
 */
void C_MTX44RotRad(Mtx44 m, char axis, f32 rad)
{
	f32 sinA;
	f32 cosA;

	OSAssertMsgLine(1118, m, "MTX44RotRad():  NULL Mtx44Ptr 'm' ");
	sinA = sinf(rad);
	cosA = cosf(rad);
	C_MTX44RotTrig(m, axis, sinA, cosA);
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000070 (Matching by size)
 */
void PSMTX44RotRad(Mtx44 m, char axis, f32 rad)
{
	f32 sinA;
	f32 cosA;

	sinA = sinf(rad);
	cosA = cosf(rad);
	PSMTX44RotTrig(m, axis, sinA, cosA);
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00011c (Matching by size)
 */
void C_MTX44RotTrig(Mtx44 m, char axis, f32 sinA, f32 cosA)
{
	OSAssertMsgLine(1163, m, "MTX44RotTrig():  NULL Mtx44Ptr 'm' ");

	axis |= 0x20;
	switch (axis) {
	case 'x':
	{
		m[0][0] = 1.0f;
		m[0][1] = 0.0f;
		m[0][2] = 0.0f;
		m[0][3] = 0.0f;

		m[1][0] = 0.0f;
		m[1][1] = cosA;
		m[1][2] = -sinA;
		m[1][3] = 0.0f;

		m[2][0] = 0.0f;
		m[2][1] = sinA;
		m[2][2] = cosA;
		m[2][3] = 0.0f;

		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 0.0f;
		m[3][3] = 1.0f;
		break;
	}
	case 'y':
	{
		m[0][0] = cosA;
		m[0][1] = 0.0f;
		m[0][2] = sinA;
		m[0][3] = 0.0f;

		m[1][0] = 0.0f;
		m[1][1] = 1.0f;
		m[1][2] = 0.0f;
		m[1][3] = 0.0f;

		m[2][0] = -sinA;
		m[2][1] = 0.0f;
		m[2][2] = cosA;
		m[2][3] = 0.0f;

		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 0.0f;
		m[3][3] = 1.0f;
		break;
	}
	case 'z':
	{
		m[0][0] = cosA;
		m[0][1] = -sinA;
		m[0][2] = 0.0f;
		m[0][3] = 0.0f;

		m[1][0] = sinA;
		m[1][1] = cosA;
		m[1][2] = 0.0f;
		m[1][3] = 0.0f;

		m[2][0] = 0.0f;
		m[2][1] = 0.0f;
		m[2][2] = 1.0f;
		m[2][3] = 0.0f;

		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 0.0f;
		m[3][3] = 1.0f;
		break;
	}
	default:
	{
		OSAssertMsgLine(1191, FALSE, "MTX44RotTrig():  invalid 'axis' value ");
		break;
	}
	}
}

/**
 * @todo Documentation
 * @note UNUSED Size: 0000cc (Matching by size)
 */
void PSMTX44RotTrig(register Mtx44 m, register char axis, register f32 sinA, register f32 cosA)
{
	register f32 ftmp0;
	register f32 ftmp1;
	register f32 ftmp2;
	register f32 ftmp3;
	register f32 ftmp4;

	register f32 c_zero;
	register f32 c_one;

	c_zero = 0.0f;
	c_one  = 1.0f;

#ifdef __MWERKS__
	asm {
		ori         axis, axis, 0x20
		cmplwi      axis, 'x'
		beq         _case_x
		cmplwi      axis, 'y'
		beq         _case_y
		cmplwi      axis, 'z'
		beq         _case_z
		b           _end

	_case_x:
		psq_st      c_one, 0x0(m), 1, 0
		psq_st      c_zero, 0x4(m), 0, 0
		ps_neg      ftmp0, sinA
		psq_st      c_zero, 0xc(m), 0, 0
		ps_merge00  ftmp1, sinA, cosA
		psq_st      c_zero, 0x1c(m), 0, 0
		ps_merge00  ftmp0, cosA, ftmp0
		psq_st      c_zero, 0x2c(m), 0, 0
		psq_st      c_zero, 0x34(m), 0, 0
		psq_st      ftmp1, 0x24(m), 0, 0
		psq_st      ftmp0, 0x14(m), 0, 0
		psq_st      c_one, 0x3c(m), 1, 0
		b           _end

	_case_y:
		ps_merge00  ftmp1, cosA, c_zero
		psq_st      c_zero, 0x30(m), 0, 0
		ps_neg      ftmp0, sinA
		psq_st      c_zero, 0x18(m), 0, 0
		ps_merge00  ftmp3, c_zero, c_one
		psq_st      ftmp1, 0x0(m), 0, 0
		ps_merge00  ftmp4, ftmp0, c_zero
		ps_merge00  ftmp2, sinA, c_zero
		psq_st      ftmp3, 0x10(m), 0, 0
		psq_st      ftmp2, 0x8(m), 0, 0
		psq_st      ftmp4, 0x20(m), 0, 0
		psq_st      ftmp1, 0x28(m), 0, 0
		psq_st      ftmp3, 0x38(m), 0, 0
		b           _end

	_case_z:
		psq_st      c_zero, 0x8(m), 0, 0
		ps_neg      ftmp0, sinA
		psq_st      c_zero, 0x18(m), 0, 0
		ps_merge00  ftmp1, sinA, cosA
		psq_st      c_zero, 0x20(m), 0, 0
		ps_merge00  ftmp2, c_one, c_zero
		psq_st      c_zero, 0x30(m), 0, 0
		ps_merge00  ftmp3, c_zero, c_one
		psq_st      ftmp1, 0x10(m), 0, 0
		ps_merge00  ftmp4, cosA, ftmp0
		psq_st      ftmp2, 0x28(m), 0, 0
		psq_st      ftmp3, 0x38(m), 0, 0
		psq_st      ftmp4, 0x0(m), 0, 0

	_end:
	}
#endif
}

/**
 * @todo Documentation
 * @note UNUSED Size: 00012c (Matching by size)
 */
void C_MTX44RotAxisRad(Mtx44 m, const Vec* axis, f32 rad)
{
	Vec vN;
	f32 sinA;
	f32 cosA;
	f32 t;
	f32 x;
	f32 y;
	f32 z;
	f32 xSq;
	f32 ySq;
	f32 zSq;

	OSAssertMsgLine(1300, m, "MTX44RotAxisRad():  NULL Mtx44Ptr 'm' ");
	OSAssertMsgLine(1301, axis, "MTX44RotAxisRad():  NULL VecPtr 'axis' ");

	sinA = sinf(rad);
	cosA = cosf(rad);
	t    = 1.0f - cosA;

	C_VECNormalize(axis, &vN);

	x = vN.x;
	y = vN.y;
	z = vN.z;

	xSq = (x * x);
	ySq = (y * y);
	zSq = (z * z);

	m[0][0] = (cosA + (t * xSq));
	m[0][1] = (y * (t * x)) - (sinA * z);
	m[0][2] = (z * (t * x)) + (sinA * y);
	m[0][3] = 0.0f;

	m[1][0] = ((y * (t * x)) + (sinA * z));
	m[1][1] = (cosA + (t * ySq));
	m[1][2] = ((z * (t * y)) - (sinA * x));
	m[1][3] = 0.0f;

	m[2][0] = ((z * (t * x)) - (sinA * y));
	m[2][1] = ((z * (t * y)) + (sinA * x));
	m[2][2] = (cosA + (t * zSq));
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

/**
 * @todo Documentation
 * @note UNUSED Size: 000128 (Nonmatching)
 */
void PSMTX44RotAxisRad(register Mtx44 m, register const Vec* axis, register f32 rad)
{
	register f32 sinA;
	register f32 cosA;
	register f32 t;
	register f32 fc0;
	register f32 tmp0;
	register f32 tmp1;
	register f32 tmp2;
	register f32 tmp3;
	register f32 tmp4;
	register f32 tmp5;
	register f32 tmp6;
	register f32 tmp7;
	register f32 tmp8;
	register f32 tmp9;

	sinA = sinf(rad);
	cosA = cosf(rad);

	tmp9 = 0.5f;
	tmp8 = 3.0f;

#ifdef __MWERKS__
	asm {
        frsp        cosA, cosA
        psq_l       tmp0, 0x0(axis), 0, 0
        frsp        sinA, sinA
        lfs         tmp1, 0x8(axis)
        ps_mul      tmp2, tmp0, tmp0
        fadds       tmp7, tmp9, tmp9
        ps_madd     tmp3, tmp1, tmp1, tmp2
        fsubs       fc0, tmp9, tmp9
        ps_sum0     tmp4, tmp3, tmp1, tmp2
        fsubs       t, tmp7, cosA
        frsqrte     tmp5, tmp4
        ps_merge00  tmp7, fc0, tmp7
        fmuls       tmp2, tmp5, tmp5
        fmuls       tmp3, tmp5, tmp9
        psq_st      fc0, 0x30(m), 0, 0
        fnmsubs     tmp2, tmp2, tmp4, tmp8
        fmuls       tmp5, tmp2, tmp3
        psq_st      tmp7, 0x38(m), 0, 0
        ps_merge00  cosA, cosA, cosA
        ps_muls0    tmp0, tmp0, tmp5
        ps_muls0    tmp1, tmp1, tmp5
        ps_muls0    tmp4, tmp0, t
        ps_muls0    tmp9, tmp0, sinA
        ps_muls0    tmp5, tmp1, t
        ps_muls1    tmp3, tmp4, tmp0
        ps_muls0    tmp2, tmp4, tmp0
        ps_muls0    tmp4, tmp4, tmp1
        fnmsubs     tmp6, tmp1, sinA, tmp3
        fmadds      tmp7, tmp1, sinA, tmp3
        ps_neg      tmp0, tmp9
        ps_sum0     tmp8, tmp4, fc0, tmp9
        ps_sum0     tmp2, tmp2, tmp6, cosA
        ps_sum1     tmp3, cosA, tmp7, tmp3
        ps_sum0     tmp6, tmp0, fc0, tmp4
        psq_st      tmp8, 0x8(m), 0, 0
        ps_sum0     tmp0, tmp4, tmp4, tmp0
        psq_st      tmp2, 0x0(m), 0, 0
        ps_muls0    tmp5, tmp5, tmp1
        psq_st      tmp3, 0x10(m), 0, 0
        ps_sum1     tmp4, tmp9, tmp0, tmp4
        psq_st      tmp6, 0x18(m), 0, 0
        ps_sum0     tmp5, tmp5, fc0, cosA
        psq_st      tmp4, 0x20(m), 0, 0
        psq_st      tmp5, 0x28(m), 0, 0
	}
#endif
}

#pragma dont_inline reset
