#include "Dolphin/mtx.h"

#include "Dolphin/os.h"
#include "fdlibm.h"
#include <math.h>
#include <stddef.h>

#pragma dont_inline on

static f32 Unit01[] = { 0.0f, 1.0f };

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C (Matching by size)
 */
void C_MTXIdentity(Mtx m)
{
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
}

/**
 * @TODO: Documentation
 */
void PSMTXIdentity(register Mtx m)
{
	register f32 c_zero;
	register f32 c_one;
	register f32 c_01;
	register f32 c_10;

	c_zero = 0.0f;
	c_one  = 1.0f;

#ifdef __MWERKS__
	asm {
		psq_st      c_zero, 0x0008 (m), 0, 0
		ps_merge01  c_01, c_zero, c_one
		psq_st      c_zero, 0x0018 (m), 0, 0
		ps_merge10  c_10, c_one, c_zero
		psq_st      c_zero, 0x0020 (m), 0, 0
		psq_st      c_01,   0x0010 (m), 0, 0
		psq_st      c_10,   0x0000 (m), 0, 0
		psq_st      c_10,   0x0028 (m), 0, 0
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C (Matching by size)
 */
void C_MTXCopy(const Mtx src, Mtx dst)
{
	if (src == dst) {
		return;
	}

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
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void PSMTXCopy(register const Mtx src, register Mtx dst)
{
#ifdef __MWERKS__
	asm {
		psq_l   fp0, 0x0000 (src), 0, 0
		psq_st  fp0, 0x0000 (dst), 0, 0
		psq_l   fp1, 0x0008 (src), 0, 0
		psq_st  fp1, 0x0008 (dst), 0, 0
		psq_l   fp2, 0x0010 (src), 0, 0
		psq_st  fp2, 0x0010 (dst), 0, 0
		psq_l   fp3, 0x0018 (src), 0, 0
		psq_st  fp3, 0x0018 (dst), 0, 0
		psq_l   fp4, 0x0020 (src), 0, 0
		psq_st  fp4, 0x0020 (dst), 0, 0
		psq_l   fp5, 0x0028 (src), 0, 0
		psq_st  fp5, 0x0028 (dst), 0, 0
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0002A8 (Matching by size)
 */
void C_MTXConcat(const Mtx a, const Mtx b, Mtx dst)
{
	Mtx tmp;
	MtxPtr m;

	if (dst == a || dst == b) {
		m = tmp;
	} else {
		m = dst;
	}

	m[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
	m[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
	m[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2];
	m[0][3] = a[0][0] * b[0][3] + a[0][1] * b[1][3] + a[0][2] * b[2][3] + a[0][3];

	m[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
	m[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];
	m[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2];
	m[1][3] = a[1][0] * b[0][3] + a[1][1] * b[1][3] + a[1][2] * b[2][3] + a[1][3];

	m[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0];
	m[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1];
	m[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2];
	m[2][3] = a[2][0] * b[0][3] + a[2][1] * b[1][3] + a[2][2] * b[2][3] + a[2][3];

	if (m == tmp) {
		C_MTXCopy(tmp, dst);
	}
}

/**
 * @TODO: Documentation
 */
ASM void PSMTXConcat(register const Mtx a, register const Mtx b, register Mtx dst)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	stwu       r1, -64(r1)
	psq_l      fp0, 0(a), 0, 0
	stfd       fp14, 8(r1)
	psq_l      fp6, 0(b), 0, 0
	addis      r6, 0, Unit01@ha
	psq_l      fp7, 8(b), 0, 0
	stfd       fp15, 16(r1)
	addi       r6, r6, Unit01@l
	stfd       fp31, 40(r1)
	psq_l      fp8, 16(b), 0, 0
	ps_muls0   fp12, fp6, fp0
	psq_l      fp2, 16(a), 0, 0
	ps_muls0   fp13, fp7, fp0
	psq_l      fp31, 0(r6), 0, 0
	ps_muls0   fp14, fp6, fp2
	psq_l      fp9, 24(b), 0, 0
	ps_muls0   fp15, fp7, fp2
	psq_l      fp1, 8(a), 0, 0
	ps_madds1  fp12, fp8, fp0, fp12
	psq_l      fp3, 24(a), 0, 0
	ps_madds1  fp14, fp8, fp2, fp14
	psq_l      fp10, 32(b), 0, 0
	ps_madds1  fp13, fp9, fp0, fp13
	psq_l      fp11, 40(b), 0, 0
	ps_madds1  fp15, fp9, fp2, fp15
	psq_l      fp4, 32(a), 0, 0
	psq_l      fp5, 40(a), 0, 0
	ps_madds0  fp12, fp10, fp1, fp12
	ps_madds0  fp13, fp11, fp1, fp13
	ps_madds0  fp14, fp10, fp3, fp14
	ps_madds0  fp15, fp11, fp3, fp15
	psq_st     fp12, 0(dst), 0, 0

	ps_muls0   fp2, fp6, fp4
	ps_madds1  fp13, fp31, fp1, fp13
	ps_muls0   fp0, fp7, fp4
	psq_st     fp14, 16(dst), 0, 0
	ps_madds1  fp15, fp31, fp3, fp15

	psq_st     fp13, 8(dst), 0, 0

	ps_madds1  fp2, fp8, fp4, fp2
	ps_madds1  fp0, fp9, fp4, fp0
	ps_madds0  fp2, fp10, fp5, fp2
	lfd        fp14, 8(r1)
	psq_st     fp15, 24(dst), 0, 0
	ps_madds0  fp0, fp11, fp5, fp0
	psq_st     fp2, 32(dst), 0, 0
	ps_madds1  fp0, fp31, fp5, fp0
	lfd        fp15, 16(r1)
	psq_st     fp0, 40(dst), 0, 0

	lfd        fp31, 40(r1)
	addi       r1, r1, 64

	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C (Matching by size)
 */
void C_MTXTranspose(const Mtx src, Mtx xPose)
{
	Mtx tmp;
	MtxPtr m;

	if (src == xPose) {
		m = tmp;
	} else {
		m = xPose;
	}

	m[0][0] = src[0][0];
	m[0][1] = src[1][0];
	m[0][2] = src[2][0];
	m[0][3] = 0.0f;

	m[1][0] = src[0][1];
	m[1][1] = src[1][1];
	m[1][2] = src[2][1];
	m[1][3] = 0.0f;

	m[2][0] = src[0][2];
	m[2][1] = src[1][2];
	m[2][2] = src[2][2];
	m[2][3] = 0.0f;

	if (m == tmp) {
		C_MTXCopy(tmp, xPose);
	}
}

/**
 * @TODO: Documentation
 */
void PSMTXTranspose(register const Mtx src, register Mtx xPose)
{
	register f32 c_zero;
	register f32 row0a, row1a, row0b, row1b;
	register f32 trns0, trns1, trns2;

	c_zero = 0.0f;

#ifdef __MWERKS__
	asm {
		psq_l       row0a, 0(src),  0, 0
		stfs        c_zero, 44(xPose)
		psq_l       row1a, 16(src), 0, 0
		ps_merge00  trns0, row0a, row1a
		psq_l       row0b, 8(src),  1, 0
		ps_merge11  trns1, row0a, row1a
		psq_l       row1b, 24(src), 1, 0
		psq_st      trns0, 0(xPose),  0, 0
		psq_l       row0a, 32(src), 0, 0
		ps_merge00  trns2, row0b, row1b
		psq_st      trns1, 16(xPose), 0, 0
		ps_merge00  trns0, row0a, c_zero
		psq_st      trns2, 32(xPose), 0, 0
		ps_merge10  trns1, row0a, c_zero
		psq_st      trns0, 8(xPose),  0, 0
		lfs         row0b, 40(src)
		psq_st      trns1, 24(xPose), 0, 0
		stfs        row0b, 40(xPose)
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0002AC (Matching by size)
 */
u32 C_MTXInverse(const Mtx src, Mtx inv)
{
	Mtx tmp;
	MtxPtr m;
	f32 det;

	if (src == inv) {
		m = tmp;
	} else {
		m = inv;
	}

	det = src[0][0] * src[1][1] * src[2][2] + src[0][1] * src[1][2] * src[2][0] + src[0][2] * src[1][0] * src[2][1]
	    - src[2][0] * src[1][1] * src[0][2] - src[1][0] * src[0][1] * src[2][2] - src[0][0] * src[2][1] * src[1][2];

	if (det == 0.0f) {
		return FALSE;
	}

	det = 1.0f / det;

	m[0][0] = (src[1][1] * src[2][2] - src[2][1] * src[1][2]) * det;
	m[0][1] = -(src[0][1] * src[2][2] - src[2][1] * src[0][2]) * det;
	m[0][2] = (src[0][1] * src[1][2] - src[1][1] * src[0][2]) * det;

	m[1][0] = -(src[1][0] * src[2][2] - src[2][0] * src[1][2]) * det;
	m[1][1] = (src[0][0] * src[2][2] - src[2][0] * src[0][2]) * det;
	m[1][2] = -(src[0][0] * src[1][2] - src[1][0] * src[0][2]) * det;

	m[2][0] = (src[1][0] * src[2][1] - src[2][0] * src[1][1]) * det;
	m[2][1] = -(src[0][0] * src[2][1] - src[2][0] * src[0][1]) * det;
	m[2][2] = (src[0][0] * src[1][1] - src[1][0] * src[0][1]) * det;

	m[0][3] = -m[0][0] * src[0][3] - m[0][1] * src[1][3] - m[0][2] * src[2][3];
	m[1][3] = -m[1][0] * src[0][3] - m[1][1] * src[1][3] - m[1][2] * src[2][3];
	m[2][3] = -m[2][0] * src[0][3] - m[2][1] * src[1][3] - m[2][2] * src[2][3];

	if (m == tmp) {
		C_MTXCopy(tmp, inv);
	}

	return TRUE;
}

/**
 * @TODO: Documentation
 */
ASM u32 PSMTXInverse(register const Mtx src, register Mtx inv) {
#ifdef __MWERKS__ // clang-format off
	nofralloc

	psq_l       fp0,   0 (src), 1, 0
	psq_l       fp1,   4 (src), 0, 0
	psq_l       fp2,  16 (src), 1, 0
	ps_merge10  fp6,  fp1, fp0
	psq_l       fp3,  20 (src), 0, 0
	psq_l       fp4,  32 (src), 1, 0
	ps_merge10  fp7,  fp3, fp2
	psq_l       fp5,  36 (src), 0, 0
	ps_mul      fp11, fp3, fp6
	ps_mul      fp13, fp5, fp7
	ps_merge10  fp8,  fp5, fp4
	ps_msub     fp11, fp1, fp7,  fp11
	ps_mul      fp12, fp1, fp8
	ps_msub     fp13, fp3, fp8,  fp13
	ps_mul      fp10, fp3, fp4
	ps_msub     fp12, fp5, fp6,  fp12
	ps_mul      fp9,  fp0, fp5
	ps_mul      fp8,  fp1, fp2
	ps_sub      fp6,  fp6, fp6
	ps_msub     fp10, fp2, fp5,  fp10
	ps_mul      fp7,  fp0, fp13
	ps_msub     fp9,  fp1, fp4,  fp9
	ps_madd     fp7,  fp2, fp12, fp7
	ps_msub     fp8,  fp0, fp3,  fp8
	ps_madd     fp7,  fp4, fp11, fp7
	ps_cmpo0    cr0,  fp7, fp6
	bne         _regular
	addi        r3, 0, 0
	blr

_regular:
#if defined(BUILD_MATCHING) && (defined(VERSION_GPIJ01) || defined(VERSION_GPIE01))
	ps_res      fp0, fp7
	ps_add      fp6, fp0, fp0
	ps_mul      fp5, fp0, fp0
	ps_nmsub    fp0, fp7, fp5, fp6
#else // VERSION_PIKIDEMO, VERSION_GPIP01, Non-Matching builds
	fres        fp0, fp7
#endif
	ps_add      fp6, fp0, fp0
	ps_mul      fp5, fp0, fp0
	ps_nmsub    fp0, fp7, fp5, fp6
	lfs         fp1, 12(src)
	ps_muls0    fp13, fp13, fp0
	lfs         fp2, 28(src)
	ps_muls0    fp12, fp12, fp0
	lfs         fp3, 44(src)
	ps_muls0    fp11, fp11, fp0
	ps_merge00  fp5, fp13, fp12
	ps_muls0    fp10, fp10, fp0
	ps_merge11  fp4, fp13, fp12
	ps_muls0    fp9,  fp9,  fp0
	psq_st      fp5,  0(inv), 0, 0
	ps_mul      fp6, fp13, fp1
	psq_st      fp4,  16(inv), 0, 0
	ps_muls0    fp8,  fp8,  fp0
	ps_madd     fp6, fp12, fp2, fp6
	psq_st      fp10, 32(inv), 1, 0
	ps_nmadd    fp6, fp11, fp3, fp6
	psq_st      fp9,  36(inv), 1, 0
	ps_mul      fp7, fp10, fp1
	ps_merge00  fp5, fp11, fp6
	psq_st      fp8,  40(inv), 1, 0
	ps_merge11  fp4, fp11, fp6
	psq_st      fp5,  8(inv), 0, 0
	ps_madd     fp7, fp9,  fp2, fp7
	psq_st      fp4,  24(inv), 0, 0
	ps_nmadd    fp7, fp8,  fp3, fp7
	addi        r3, 0, 1
	psq_st      fp7,  44(inv), 1, 0
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00021C (Matching by size)
 */
u32 C_MTXInvXpose(const Mtx src, Mtx inv)
{
	Mtx tmp;
	MtxPtr m;
	f32 det;

	if (src == inv) {
		m = tmp;
	} else {
		m = inv;
	}

	det = src[0][0] * src[1][1] * src[2][2] + src[0][1] * src[1][2] * src[2][0] + src[0][2] * src[1][0] * src[2][1]
	    - src[2][0] * src[1][1] * src[0][2] - src[1][0] * src[0][1] * src[2][2] - src[0][0] * src[2][1] * src[1][2];

	if (det == 0.0f) {
		return FALSE;
	}

	det = 1.0f / det;

	m[0][0] = (src[1][1] * src[2][2] - src[2][1] * src[1][2]) * det;
	m[0][1] = -(src[1][0] * src[2][2] - src[2][0] * src[1][2]) * det;
	m[0][2] = (src[1][0] * src[2][1] - src[2][0] * src[1][1]) * det;

	m[1][0] = -(src[0][1] * src[2][2] - src[2][1] * src[0][2]) * det;
	m[1][1] = (src[0][0] * src[2][2] - src[2][0] * src[0][2]) * det;
	m[1][2] = -(src[0][0] * src[2][1] - src[2][0] * src[0][1]) * det;

	m[2][0] = (src[0][1] * src[1][2] - src[1][1] * src[0][2]) * det;
	m[2][1] = -(src[0][0] * src[1][2] - src[1][0] * src[0][2]) * det;
	m[2][2] = (src[0][0] * src[1][1] - src[1][0] * src[0][1]) * det;

	m[0][3] = 0.0f;
	m[1][3] = 0.0f;
	m[2][3] = 0.0f;

	if (m == tmp) {
		C_MTXCopy(tmp, inv);
	}

	return TRUE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D4 (Matching by size)
 */
ASM u32 PSMTXInvXpose(register const Mtx src, register Mtx inv)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	psq_l       fp0, 0(src), 1, 0
	psq_l       fp1, 4(src), 0, 0
	psq_l       fp2, 16(src), 1, 0
	ps_merge10  fp6, fp1, fp0
	psq_l       fp3, 20(src), 0, 0
	psq_l       fp4, 32(src), 1, 0
	ps_merge10  fp7, fp3, fp2
	psq_l       fp5, 36(src), 0, 0
	ps_mul      fp11, fp3, fp6
	ps_merge10  fp8, fp5, fp4
	ps_mul      fp13, fp5, fp7
	ps_msub     fp11, fp1, fp7, fp11
	ps_mul      fp12, fp1, fp8
	ps_msub     fp13, fp3, fp8, fp13
	ps_msub     fp12, fp5, fp6, fp12
	ps_mul      fp10, fp3, fp4
	ps_mul      fp9,  fp0, fp5
	ps_mul      fp8,  fp1, fp2
	ps_msub     fp10, fp2, fp5, fp10
	ps_msub     fp9,  fp1, fp4, fp9
	ps_msub     fp8,  fp0, fp3, fp8
	ps_mul      fp7, fp0, fp13
	ps_sub      fp1, fp1, fp1
	ps_madd     fp7, fp2, fp12, fp7
	ps_madd     fp7, fp4, fp11, fp7
	ps_cmpo0    cr0, fp7, fp1
	bne         _regular
	addi        r3, 0, 0
	blr

_regular:
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01)
	fres        fp0, fp7
#else// VERSION_PIKIDEMO, VERSION_GPIP01, Non-Matching builds
	ps_res      f0, f7
	ps_add      f6, f0, f0
	ps_mul      f5, f0, f0
	ps_nmsub    f0, f7, f5, f6
#endif
	psq_st      fp1,  12(inv), 1, 0
	ps_add      fp6, fp0, fp0
	ps_mul      fp5, fp0, fp0
	psq_st      fp1,  28(inv), 1, 0
	ps_nmsub    fp0, fp7, fp5, fp6
	psq_st      fp1,  44(inv), 1, 0
	ps_muls0    fp13, fp13, fp0
	ps_muls0    fp12, fp12, fp0
	ps_muls0    fp11, fp11, fp0
	psq_st      fp13,  0(inv), 0, 0
	psq_st      fp12,  16(inv), 0, 0
	ps_muls0    fp10, fp10, fp0
	ps_muls0    fp9,  fp9,  fp0
	psq_st      fp11,  32(inv), 0, 0
	psq_st      fp10,  8(inv), 1, 0
	ps_muls0    fp8,  fp8,  fp0
	addi        r3, 0, 1
	psq_st      fp9,   24(inv), 1, 0
	psq_st      fp8,   40(inv), 1, 0
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070 (Matching by size)
 */
void C_MTXRotRad(Mtx m, char axis, f32 rad)
{
	f32 sinA, cosA;
	sinA = sinf(rad);
	cosA = cosf(rad);
	C_MTXRotTrig(m, axis, sinA, cosA);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070 (Matching by size)
 */
void PSMTXRotRad(Mtx m, char axis, f32 rad)
{
	f32 sinA, cosA;
	sinA = sinf(rad);
	cosA = cosf(rad);
	PSMTXRotTrig(m, axis, sinA, cosA);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000104 (Matching by size)
 */
void C_MTXRotTrig(Mtx m, char axis, f32 sinA, f32 cosA)
{
	switch (axis) {
	case 'x':
	case 'X':
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
		break;
	}
	case 'y':
	case 'Y':
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
		break;
	}
	case 'z':
	case 'Z':
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
		break;
	}
	default:
	{
		OSAssertMsg(FALSE, "MTXRotTrig():  invalid 'axis' value ");
		break;
	}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000a8 (Matching by size)
 */
void PSMTXRotTrig(register Mtx m, register char axis, register f32 sinA, register f32 cosA)
{
	register f32 fc0, fc1, nsinA;
	register f32 fw0, fw1, fw2, fw3;

	fc0 = 0.0f;
	fc1 = 1.0f;

#ifdef __MWERKS__
	asm {
		ori         axis, axis, 0x20
		ps_neg      nsinA, sinA
		cmplwi      axis, 'x'
		beq         _case_x
		cmplwi      axis, 'y'
		beq         _case_y
		cmplwi      axis, 'z'
		beq         _case_z
		b           _end

	_case_x:
		psq_st      fc1,  0(m), 1, 0
		psq_st      fc0,  4(m), 0, 0
		ps_merge00  fw0, sinA, cosA
		psq_st      fc0, 12(m), 0, 0
		ps_merge00  fw1, cosA, nsinA
		psq_st      fc0, 28(m), 0, 0
		psq_st      fc0, 44(m), 1, 0
		psq_st      fw0, 36(m), 0, 0
		psq_st      fw1, 20(m), 0, 0
		b           _end;

	_case_y:
		ps_merge00  fw0, cosA, fc0
		ps_merge00  fw1, fc0, fc1
		psq_st      fc0, 24(m), 0, 0
		psq_st      fw0,  0(m), 0, 0
		ps_merge00  fw2, nsinA, fc0
		ps_merge00  fw3, sinA, fc0
		psq_st      fw0, 40(m), 0, 0;
		psq_st      fw1, 16(m), 0, 0;
		psq_st      fw3,  8(m), 0, 0;
		psq_st      fw2, 32(m), 0, 0;
		b           _end;

	_case_z:
		psq_st      fc0,  8(m), 0, 0
		ps_merge00  fw0, sinA, cosA
		ps_merge00  fw2, cosA, nsinA
		psq_st      fc0, 24(m), 0, 0
		psq_st      fc0, 32(m), 0, 0
		ps_merge00  fw1, fc1, fc0
		psq_st      fw0, 16(m), 0, 0
		psq_st      fw2,  0(m), 0, 0
		psq_st      fw1, 40(m), 0, 0

	_end:
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000118 (Matching by size)
 */
void C_MTXRotAxisRad(Mtx m, const Vec* axis, f32 rad)
{
	Vec vec;
	f32 sinA, cosA;
	f32 t;
	f32 x, y, z;
	f32 squareX, squareY, squareZ;

	sinA = sinf(rad);
	cosA = cosf(rad);
	t    = 1.0f - cosA;

	C_VECNormalize(axis, &vec);

	x = vec.x;
	y = vec.y;
	z = vec.z;

	squareX = x * x;
	squareY = y * y;
	squareZ = z * z;

	m[0][0] = (t * squareX) + (cosA);
	m[0][1] = (t * x * y) - (sinA * z);
	m[0][2] = (t * x * z) + (sinA * y);
	m[0][3] = 0.0f;

	m[1][0] = (t * x * y) + (sinA * z);
	m[1][1] = (t * squareY) + (cosA);
	m[1][2] = (t * y * z) - (sinA * x);
	m[1][3] = 0.0f;

	m[2][0] = (t * x * z) - (sinA * y);
	m[2][1] = (t * y * z) + (sinA * x);
	m[2][2] = (t * squareZ) + (cosA);
	m[2][3] = 0.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000104 (Matching by size)
 */
void PSMTXRotAxisRad(register Mtx m, const Vec* axis, register f32 rad)
{
	register f32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9;

	register f32 sinA, cosA, t;
	register f32 c_zero;
	Vec vec;
	register Vec* vecPtr;

	c_zero = 0.0f;
	vecPtr = &vec;
	sinA   = sinf(rad);
	cosA   = cosf(rad);
	t      = 1.0f - cosA;

	PSVECNormalize(axis, vecPtr);

#ifdef __MWERKS__
	asm {
		psq_l       rad,  0 (vecPtr), 0, 0
		lfs         tmp1, 8 (vecPtr)
		ps_merge00  tmp0, cosA, cosA
		ps_muls0    tmp4, rad, t
		ps_muls0    tmp5, tmp1, t
		ps_muls1    tmp3, tmp4, rad
		ps_muls0    tmp2, tmp4, rad
		ps_muls0    rad, rad, sinA
		ps_muls0    tmp4, tmp4, tmp1
		fnmsubs     tmp6, tmp1, sinA, tmp3
		fmadds      tmp7, tmp1, sinA, tmp3
		ps_neg      tmp9, rad
		ps_sum0     tmp8, tmp4, c_zero, rad
		ps_sum0     tmp2, tmp2, tmp6, tmp0
		ps_sum1     tmp3, tmp0, tmp7, tmp3
		ps_sum0     tmp6, tmp9, c_zero, tmp4
		ps_sum0     tmp9, tmp4, tmp4, tmp9
		psq_st      tmp8, 0x8(m), 0, 0
		ps_muls0    tmp5, tmp5, tmp1
		psq_st      tmp2, 0x0(m), 0, 0
		ps_sum1     tmp4, rad, tmp9, tmp4
		psq_st      tmp3, 0x10(m), 0, 0
		ps_sum0     tmp5, tmp5, c_zero, tmp0
		psq_st      tmp6, 0x18(m), 0, 0
		psq_st      tmp4, 0x20(m), 0, 0
		psq_st      tmp5, 0x28(m), 0, 0
	}
#endif
}

/**
 * @TODO: Documentation
 */
void C_MTXTrans(Mtx m, f32 xT, f32 yT, f32 zT)
{
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
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void PSMTXTrans(register Mtx m, register f32 xT, register f32 yT, register f32 zT)
{
	register f32 c0;
	register f32 c1;

	c0 = 0.0f;
	c1 = 1.0f;

#ifdef __MWERKS__
	asm {
		stfs    xT, 12(m)
		stfs    yT, 28(m)
		psq_st  c0,  4(m), 0, 0
		psq_st  c0, 32(m), 0, 0
		stfs    c0, 16(m)
		stfs    c1, 20(m)
		stfs    c0, 24(m)
		stfs    c1, 40(m)
		stfs    zT, 44(m)
		stfs    c1,  0(m)
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000078 (Matching by size)
 */
void C_MTXTransApply(const Mtx src, Mtx dst, f32 xT, f32 yT, f32 zT)
{
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
	}

	dst[0][3] = src[0][3] + xT;
	dst[1][3] = src[1][3] + yT;
	dst[2][3] = src[2][3] + zT;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040 (Matching by size)
 */
ASM void PSMTXTransApply(register const Mtx src, register Mtx dst, register f32 xT, register f32 yT, register f32 zT)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	psq_l    fp4,  0 (src), 0, 0
	psq_l    fp5,  8 (src), 0, 0
	psq_l    fp7, 24 (src), 0, 0
	psq_l    fp8, 40 (src), 0, 0
	psq_st   fp4,  0 (dst), 0, 0
	ps_sum1  fp5, xT, fp5, fp5
	psq_l    fp6, 16 (src), 0, 0   
	psq_st   fp5,  8 (dst), 0, 0
	ps_sum1  fp7, yT, fp7, fp7
	psq_l    fp9, 32 (src), 0, 0
	psq_st   fp6, 16 (dst), 0, 0
	ps_sum1  fp8, zT, fp8, fp8
	psq_st   fp7, 24 (dst), 0, 0
	psq_st   fp9, 32 (dst), 0, 0
	psq_st   fp8, 40 (dst), 0, 0
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
void C_MTXScale(Mtx m, f32 xS, f32 yS, f32 zS)
{
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
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028 (Matching by size)
 */
void PSMTXScale(register Mtx m, register f32 xS, register f32 yS, register f32 zS)
{
	register f32 c0;

	c0 = 0.0f;

#ifdef __MWERKS__
	asm {
		stfs    xS,  0 (m)
		psq_st  c0,  4 (m), 0, 0
		psq_st  c0, 12 (m), 0, 0
		stfs    yS, 20 (m)
		psq_st  c0, 24 (m), 0, 0
		psq_st  c0, 32 (m), 0, 0
		stfs    zS, 40 (m)
		stfs    c0, 44 (m)
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094 (Matching by size)
 */
void C_MTXScaleApply(const Mtx src, Mtx dst, f32 xS, f32 yS, f32 zS)
{
	dst[0][0] = src[0][0] * xS;
	dst[0][1] = src[0][1] * xS;
	dst[0][2] = src[0][2] * xS;
	dst[0][3] = src[0][3] * xS;

	dst[1][0] = src[1][0] * yS;
	dst[1][1] = src[1][1] * yS;
	dst[1][2] = src[1][2] * yS;
	dst[1][3] = src[1][3] * yS;

	dst[2][0] = src[2][0] * zS;
	dst[2][1] = src[2][1] * zS;
	dst[2][2] = src[2][2] * zS;
	dst[2][3] = src[2][3] * zS;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004c (Matching by size)
 */
ASM void PSMTXScaleApply(register const Mtx src, register Mtx dst, register f32 xS, register f32 yS, register f32 zS)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	psq_l     fp4,  0 (src), 0, 0
	psq_l     fp5,  8 (src), 0, 0
	ps_muls0  fp4, fp4, xS
	psq_l     fp6, 16 (src), 0, 0
	ps_muls0  fp5, fp5, xS
	psq_l     fp7, 24 (src), 0, 0
	ps_muls0  fp6, fp6, yS
	psq_l     fp8, 32 (src), 0, 0
	psq_st    fp4,  0 (dst), 0, 0
	ps_muls0  fp7, fp7, yS
	psq_l     fp2, 40 (src), 0, 0
	psq_st    fp5,  8 (dst), 0, 0
	ps_muls0  fp8, fp8, zS
	psq_st    fp6, 16 (dst), 0, 0
	ps_muls0  fp2, fp2, zS
	psq_st    fp7, 24 (dst), 0, 0
	psq_st    fp8, 32 (dst), 0, 0
	psq_st    fp2, 40(dst), 0, 0
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0 (Matching by size)
 */
void C_MTXQuat(Mtx m, const Quaternion* quat)
{
	f32 s, xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;

	s = 2.0f / ((quat->x * quat->x) + (quat->y * quat->y) + (quat->z * quat->z) + (quat->w * quat->w));

	xs = quat->x * s;
	ys = quat->y * s;
	zs = quat->z * s;
	wx = quat->w * xs;
	wy = quat->w * ys;
	wz = quat->w * zs;
	xx = quat->x * xs;
	xy = quat->x * ys;
	xz = quat->x * zs;
	yy = quat->y * ys;
	yz = quat->y * zs;
	zz = quat->z * zs;

	m[0][0] = 1.0f - (yy + zz);
	m[0][1] = xy - wz;
	m[0][2] = xz + wy;
	m[0][3] = 0.0f;

	m[1][0] = xy + wz;
	m[1][1] = 1.0f - (xx + zz);
	m[1][2] = yz - wx;
	m[1][3] = 0.0f;

	m[2][0] = xz - wy;
	m[2][1] = yz + wx;
	m[2][2] = 1.0f - (xx + yy);
	m[2][3] = 0.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000a4 (Matching by size)
 */
void PSMTXQuat(register Mtx m, register const Quaternion* quat)
{
	register f32 c_zero, c_one, c_two, scale;
	register f32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9;

	c_one = 1.0f;

#ifdef __MWERKS__
	asm {
		psq_l       tmp0,  0 (quat), 0, 0
		psq_l       tmp1,  8 (quat), 0, 0
		fsubs       c_zero, c_one, c_one
		fadds       c_two, c_one, c_one
		ps_mul      tmp2, tmp0, tmp0
		ps_merge10  tmp5, tmp0, tmp0
		ps_madd     tmp4, tmp1, tmp1, tmp2
		ps_mul      tmp3, tmp1, tmp1
		ps_sum0     scale, tmp4, tmp4, tmp4
		ps_muls1    tmp7, tmp5, tmp1
		fres        tmp9, scale
		ps_sum1     tmp4, tmp3, tmp4, tmp2
		ps_nmsub    scale, scale, tmp9, c_two
		ps_muls1    tmp6, tmp1, tmp1
		ps_mul      scale, tmp9, scale
		ps_sum0     tmp2, tmp2, tmp2, tmp2
		fmuls       scale, scale, c_two
		ps_madd     tmp8, tmp0, tmp5, tmp6
		ps_msub     tmp6, tmp0, tmp5, tmp6
		psq_st      c_zero, 12 (m), 1, 0
		ps_nmsub    tmp2, tmp2, scale, c_one
		ps_nmsub    tmp4, tmp4, scale, c_one
		psq_st      c_zero, 44 (m), 1, 0
		ps_mul      tmp8, tmp8, scale
		ps_mul      tmp6, tmp6, scale
		psq_st      tmp2, 40 (m), 1, 0
		ps_madds0   tmp5, tmp0, tmp1, tmp7
		ps_merge00  tmp1, tmp8, tmp4
		ps_nmsub    tmp7, tmp7, c_two, tmp5
		ps_merge10  tmp0, tmp4, tmp6
		psq_st      tmp1, 16 (m), 0, 0
		ps_mul      tmp5, tmp5, scale
		ps_mul      tmp7, tmp7, scale
		psq_st      tmp0,  0 (m), 0, 0
		psq_st      tmp5,  8 (m), 1, 0
		ps_merge10  tmp3, tmp7, c_zero
		ps_merge01  tmp9, tmp7, tmp5
		psq_st      tmp3, 24 (m), 0, 0
		psq_st      tmp9, 32 (m), 0, 0
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000100 (Nonmatching)
 */
void C_MTXReflect(Mtx m, const Vec* p, const Vec* n)
{
	f32 vxy, vxz, vyz, pdotn;

	vxy   = -2.0f * n->x * n->y;
	vxz   = -2.0f * n->x * n->z;
	vyz   = -2.0f * n->y * n->z;
	pdotn = 2.0f * C_VECDotProduct(p, n);

	m[0][0] = 1.0f - 2.0f * n->x * n->x;
	m[0][1] = vxy;
	m[0][2] = vxz;
	m[0][3] = pdotn * n->x;

	m[1][0] = vxy;
	m[1][1] = 1.0f - 2.0f * n->y * n->y;
	m[1][2] = vyz;
	m[1][3] = pdotn * n->y;

	m[2][0] = vxz;
	m[2][1] = vyz;
	m[2][2] = 1.0f - 2.0f * n->z * n->z;
	m[2][3] = pdotn * n->z;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070 (Matching by size)
 */
void PSMTXReflect(register Mtx m, const register Vec* p, const register Vec* n)
{
	register f32 c_one;
	register f32 vn_xy, vn_z1, n2vn_xy, n2vn_z1, pdotn;
	register f32 tmp0, tmp1, tmp2, tmp3;
	register f32 tmp4, tmp5, tmp6, tmp7;

	c_one = 1.0f;

#ifdef __MWERKS__
	asm {
		psq_l       vn_z1, 0x0008 (n), 1, 0
		psq_l       vn_xy, 0x0000 (n), 0, 0
		psq_l       tmp0,  0x0000 (p), 0, 0
		ps_nmadd    n2vn_z1, vn_z1, c_one, vn_z1
		psq_l       tmp1,  0x0008 (p), 1, 0
		ps_nmadd    n2vn_xy, vn_xy, c_one, vn_xy
		ps_muls0    tmp4, vn_xy, n2vn_z1
		ps_mul      pdotn, n2vn_xy, tmp0
		ps_muls0    tmp2, vn_xy, n2vn_xy
		ps_sum0     pdotn, pdotn, pdotn, pdotn
		ps_muls1    tmp3, vn_xy, n2vn_xy
		psq_st      tmp4, 0x0020 (m), 0, 0
		ps_sum0     tmp2, tmp2, tmp2, c_one
		ps_nmadd    pdotn, n2vn_z1, tmp1, pdotn
		ps_sum1     tmp3, c_one, tmp3, tmp3
		psq_st      tmp2, 0x0000 (m), 0, 0
		ps_muls0    tmp5, vn_xy, pdotn
		ps_merge00  tmp6, n2vn_z1, pdotn
		psq_st      tmp3, 0x0010 (m), 0, 0
		ps_merge00  tmp7, tmp4, tmp5
		ps_muls0    tmp6, tmp6, vn_z1
		ps_merge11  tmp5, tmp4, tmp5
		psq_st      tmp7, 0x0008 (m), 0, 0
		ps_sum0     tmp6, tmp6, tmp6, c_one
		psq_st      tmp5, 0x0018 (m), 0, 0
		psq_st      tmp6, 0x0028 (m), 0, 0
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00018C (Matching by size)
 */
void C_MTXLookAt(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target)
{
	Vec vLook, vRight, vUp;

	vLook.x = camPos->x - target->x;
	vLook.y = camPos->y - target->y;
	vLook.z = camPos->z - target->z;
	C_VECNormalize(&vLook, &vLook);
	C_VECCrossProduct(camUp, &vLook, &vRight);
	C_VECNormalize(&vRight, &vRight);
	VECCrossProduct(&vLook, &vRight, &vUp);

	m[0][0] = vRight.x;
	m[0][1] = vRight.y;
	m[0][2] = vRight.z;
	m[0][3] = -(camPos->x * vRight.x + camPos->y * vRight.y + camPos->z * vRight.z);

	m[1][0] = vUp.x;
	m[1][1] = vUp.y;
	m[1][2] = vUp.z;
	m[1][3] = -(camPos->x * vUp.x + camPos->y * vUp.y + camPos->z * vUp.z);

	m[2][0] = vLook.x;
	m[2][1] = vLook.y;
	m[2][2] = vLook.z;
	m[2][3] = -(camPos->x * vLook.x + camPos->y * vLook.y + camPos->z * vLook.z);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094 (Matching by size)
 */
void C_MTXLightFrustum(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
{
	f32 tmp;

	tmp       = 1.0f / (r - l);
	m[0][0]   = (2 * n) * tmp * scaleS;
	m[0][1]   = 0.0f;
	m[0][2]   = (r + l) * tmp * scaleS - transS;
	m[0][3]   = 0.0f;

	tmp       = 1.0f / (t - b);
	m[1][0]   = 0.0f;
	m[1][1]   = (2 * n) * tmp * scaleT;
	m[1][2]   = (t + b) * tmp * scaleT - transT;
	m[1][3]   = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = -1.0f;
	m[2][3] = 0.0f;
}

/**
 * @TODO: Documentation
 */
void C_MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
{
	f32 angle;
	f32 cot;

	OSAssertMsgLine(2605, m, "MTXLightPerspective():  NULL MtxPtr 'm' ");
	OSAssertMsgLine(2606, (fovY > 0.0) && (fovY < 180.0), "MTXLightPerspective():  'fovY' out of range ");
	OSAssertMsgLine(2607, 0 != aspect, "MTXLightPerspective():  'aspect' is 0 ");

	angle = 0.5f * fovY;
	angle = MTXDegToRad(angle);
	cot   = 1.0f / tanf(angle);

	m[0][0] = scaleS * (cot / aspect);
	m[0][1] = 0.0f;
	m[0][2] = -transS;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = cot * scaleT;
	m[1][2] = -transT;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = -1.0f;
	m[2][3] = 0.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000088
 */
void C_MTXLightOrtho(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
{
	f32 tmp;

	tmp       = 1.0f / (r - l);
	m[0][0]   = 2 * tmp * scaleS;
	m[0][1]   = 0.0f;
	m[0][2]   = 0.0f;
	m[0][3]   = -(r + l) * tmp * scaleS + transS;

	tmp       = 1.0f / (t - b);
	m[1][0]   = 0.0f;
	m[1][1]   = 2 * tmp * scaleT;
	m[1][2]   = 0.0f;
	m[1][3]   = -(t + b) * tmp * scaleT + transT;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 0.0f;
	m[2][3] = 1.0f;
}

#pragma dont_inline reset
