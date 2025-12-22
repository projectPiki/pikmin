#include "Dolphin/mtx.h"

#include "Dolphin/math.h"
#include "Dolphin/os.h"
#include "fdlibm.h"

static f32 Unit01[] = { 0.0f, 1.0f };
extern f32 sinf(f32);

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void C_MTXIdentity(Mtx mtx)
{
	mtx[0][0] = 1.0f;
	mtx[0][1] = 0.0f;
	mtx[0][2] = 0.0f;

	mtx[1][0] = 0.0f;
	mtx[1][1] = 1.0f;
	mtx[1][2] = 0.0f;

	mtx[2][0] = 0.0f;
	mtx[2][1] = 0.0f;
	mtx[2][2] = 1.0f;
}

/**
 * @TODO: Documentation
 */
void PSMTXIdentity(register Mtx m)
{
	register f32 zero_c = 0.0f;
	register f32 one_c  = 1.0f;
	register f32 c_01;
	register f32 c_10;

#ifdef __MWERKS__
	asm {
		psq_st      zero_c, 8(m),   0, 0
		ps_merge01  c_01, zero_c, one_c
		psq_st      zero_c, 24(m),  0, 0
		ps_merge10  c_10, one_c, zero_c
		psq_st      zero_c, 32(m),  0, 0
		psq_st      c_01,   16(m),  0, 0
		psq_st      c_10,   0(m),   0, 0
		psq_st      c_10,   40(m),  0, 0
	}
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void C_MTXCopy(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
ASM void PSMTXCopy(const register Mtx src, register Mtx dst)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	psq_l       fp0, 0(src),   0, 0
	psq_st      fp0, 0(dst),   0, 0
	psq_l       fp1, 8(src),   0, 0
	psq_st      fp1, 8(dst),   0, 0
	psq_l       fp2, 16(src),  0, 0
	psq_st      fp2, 16(dst),  0, 0
	psq_l       fp3, 24(src),  0, 0
	psq_st      fp3, 24(dst),  0, 0
	psq_l       fp4, 32(src),  0, 0
	psq_st      fp4, 32(dst),  0, 0
	psq_l       fp5, 40(src),  0, 0
	psq_st      fp5, 40(dst),  0, 0

	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0002A8
 */
void C_MTXConcat(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
ASM void PSMTXConcat(const register Mtx mA, // r3
                     const register Mtx mB, // r4
                     register Mtx mAB       // r5
)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

#define FP0 fp0
#define FP1 fp1
#define FP2 fp2
#define FP3 fp3
#define FP4 fp4
#define FP5 fp5
#define FP6 fp6
#define FP7 fp7
#define FP8 fp8
#define FP9 fp9
#define FP10 fp10
#define FP11 fp11
#define FP12 fp12
#define FP13 fp13
#define FP14 fp14
#define FP15 fp15
#define FP31 fp31
	stwu    r1, -64(r1)
	psq_l   FP0, 0(mA), 0, 0
	stfd    fp14, 8(r1)
	psq_l   FP6, 0(mB), 0, 0
	addis   r6, 0, Unit01@ha
	psq_l   FP7, 8(mB), 0, 0
	stfd    fp15, 16(r1)
	addi    r6, r6, Unit01@l
	stfd    fp31, 40(r1)
	psq_l   FP8, 16(mB), 0, 0
	ps_muls0 FP12, FP6, FP0
	psq_l   FP2, 16(mA), 0, 0
	ps_muls0 FP13, FP7, FP0
	psq_l   FP31, 0(r6), 0, 0
	ps_muls0 FP14, FP6, FP2
	psq_l   FP9, 24(mB), 0, 0
	ps_muls0 FP15, FP7, FP2
	psq_l   FP1, 8(mA), 0, 0
		ps_madds1 FP12, FP8, FP0, FP12
	psq_l   FP3, 24(mA), 0, 0
		ps_madds1 FP14, FP8, FP2, FP14
	psq_l   FP10, 32(mB), 0, 0
		ps_madds1 FP13, FP9, FP0, FP13
	psq_l   FP11, 40(mB), 0, 0
		ps_madds1 FP15, FP9, FP2, FP15
	psq_l   FP4, 32(mA), 0, 0
	psq_l   FP5, 40(mA), 0, 0
			ps_madds0 FP12, FP10, FP1, FP12
			ps_madds0 FP13, FP11, FP1, FP13
			ps_madds0 FP14, FP10, FP3, FP14
			ps_madds0 FP15, FP11, FP3, FP15
	psq_st  FP12, 0(mAB), 0, 0

	ps_muls0 FP2, FP6, FP4
				ps_madds1 FP13, FP31, FP1, FP13
	ps_muls0 FP0, FP7, FP4
	psq_st  FP14, 16(mAB), 0, 0
				ps_madds1 FP15, FP31, FP3, FP15

	psq_st  FP13, 8(mAB), 0, 0

		ps_madds1 FP2, FP8, FP4, FP2
		ps_madds1 FP0, FP9, FP4, FP0
			ps_madds0 FP2, FP10, FP5, FP2
	lfd    fp14, 8(r1)
	psq_st  FP15, 24(mAB), 0, 0
			ps_madds0 FP0, FP11, FP5, FP0
	psq_st  FP2, 32(mAB), 0, 0
				ps_madds1 FP0, FP31, FP5, FP0
	lfd    fp15, 16(r1)
	psq_st  FP0, 40(mAB), 0, 0

	lfd    fp31, 40(r1)
	addi   r1, r1, 64

	blr

#undef FP0
#undef FP1
#undef FP2
#undef FP3
#undef FP4
#undef FP5
#undef FP6
#undef FP7
#undef FP8
#undef FP9
#undef FP10
#undef FP11
#undef FP12
#undef FP13
#undef FP14
#undef FP15
#undef FP31
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
void C_MTXTranspose(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void PSMTXTranspose(const register Mtx src, register Mtx xPose)
{
	register f32 c_zero = 0.0f;
	register f32 row0a, row1a, row0b, row1b;
	register f32 trns0, trns1, trns2;

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
 * @note UNUSED Size: 0002AC
 */
void C_MTXInverse(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
ASM u32 PSMTXInverse(const register Mtx src, register Mtx inv)
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
	ps_mul      fp13, fp5, fp7
		ps_merge10  fp8, fp5, fp4
	ps_msub     fp11, fp1, fp7, fp11
	ps_mul      fp12, fp1, fp8
	ps_msub     fp13, fp3, fp8, fp13
		ps_mul      fp10, fp3, fp4
	ps_msub     fp12, fp5, fp6, fp12
		ps_mul      fp9,  fp0, fp5
		ps_mul      fp8,  fp1, fp2
	ps_sub      fp6, fp6, fp6
		ps_msub     fp10, fp2, fp5, fp10
	ps_mul      fp7, fp0, fp13
		ps_msub     fp9,  fp1, fp4, fp9
	ps_madd     fp7, fp2, fp12, fp7
		ps_msub     fp8,  fp0, fp3, fp8
	ps_madd     fp7, fp4, fp11, fp7
	ps_cmpo0    cr0, fp7, fp6
	bne         _regular
	addi        r3, 0, 0
	blr
  _regular:
	ps_res      f0, f7
	ps_add      f6, f0, f0
	ps_mul 		f5, f0, f0
	ps_nmsub 	f0, f7, f5, f6
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
 * @note UNUSED Size: 00021C
 */
void C_MTXInvXpose(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D4
 */
void PSMTXInvXpose(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
void MTXRotRad(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000104
 */
void MTXRotTrig(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000118
 */
void MTXRotAxisRad(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void MTXTrans(Mtx m, f32 xT, f32 yT, f32 zT)
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
 * @note UNUSED Size: 000078
 */
void MTXTransApply(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void MTXScale(Mtx m, f32 xS, f32 yS, f32 zS)
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
 * @note UNUSED Size: 000094
 */
void MTXScaleApply(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
void MTXQuat(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000100
 */
void MTXReflect(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00018C
 */
void MTXLookAt(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094
 */
void MTXLightFrustum(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
{
	// this is just here for the float ordering
	f32 tmp;

	tmp     = 1 / (r - l);
	m[0][0] = (scaleS * (n * tmp));
	m[0][1] = 0;
	m[0][2] = (scaleS * (tmp * (r + l))) - transS;
	m[0][3] = 0;
	tmp     = 1 / (t - b);
	m[1][0] = 0;
	m[1][1] = (scaleT * (n * tmp));
	m[1][2] = (scaleT * (tmp * (t + b))) - transT;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = -1;
	m[2][3] = 0;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
{
	f32 angle;
	f32 cot;

	ASSERTMSGLINE(2605, m, "MTXLightPerspective():  NULL MtxPtr 'm' ");
	ASSERTMSGLINE(2606, (fovY > 0.0) && (fovY < 180.0), "MTXLightPerspective():  'fovY' out of range ");
	ASSERTMSGLINE(2607, 0 != aspect, "MTXLightPerspective():  'aspect' is 0 ");

	angle   = 0.5f * fovY;
	angle   = MTXDegToRad(angle);
	cot     = 1.0f / tanf(angle);
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000088
 */
void MTXLightOrtho(void)
{
	// UNUSED FUNCTION
}
