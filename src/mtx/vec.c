#include "Dolphin/vec.h"
#include <math.h>

#pragma - fp_contract off

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void C_VECAdd(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void PSVECAdd(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void C_VECSubtract(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void PSVECSubtract(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void C_VECScale(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
void PSVECScale(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000C8
 */
void C_VECNormalize(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000048
 */
void PSVECNormalize(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void C_VECSquareMag(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
ASM f32 PSVECSquareMag(register Vec* v) {
#ifdef __MWERKS__ // clang-format off
    psq_l f2, Vec.x(v), 0, 0
    ps_mul f3, f2, f2
    lfs f4, Vec.z(v)
    ps_madd f5, f4, f4, f3
    ps_sum0 f1, f5, f3, f3 // return square mag in f1
    blr //! whoops! an extra blr is added by the compiler since 1 is added automatically.
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
f32 VECMag(Vec* v)
{
	return sqrtf(PSVECSquareMag(v));
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void C_VECDotProduct(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
void PSVECDotProduct(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void C_VECCrossProduct(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void PSVECCrossProduct(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D8
 */
void VECHalfAngle(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D4
 */
void VECReflect(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void C_VECSquareDistance(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void PSVECSquareDistance(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000088
 */
void VECDistance(void)
{
	// UNUSED FUNCTION
}

#pragma - fp_contract reset
