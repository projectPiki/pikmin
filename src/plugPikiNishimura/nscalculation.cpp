#include "types.h"
#include "Vector.h"
#include "Matrix3f.h"
#include "Matrix4f.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

namespace NsCalculation {
/*
 * --INFO--
 * Address:	8017C2C8
 * Size:	0000C0
 * Aside from arg order and defines, identical to Pikmin 2's NsMathExp::calcLagrange
 */
void calcLagrange(f32 p2, const Vector3f* p_vec, Vector3f& new_vec)
// calculates Lagrange, stores in new_vec
{
#define p2_sub1 (p2 - 1.0f)
#define p2_sub2 (p2 - 2.0f)
	new_vec.x = p2_sub1 * (p_vec[2].x * 0.5f * p2) + (p2_sub2 * (p_vec[0].x * 0.5f * p2_sub1) - (p2_sub2 * (p_vec[1].x * p2)));
	new_vec.y = p2_sub1 * (p_vec[2].y * 0.5f * p2) + (p2_sub2 * (p_vec[0].y * 0.5f * p2_sub1) - (p2_sub2 * (p_vec[1].y * p2)));
	new_vec.z = p2_sub1 * (p_vec[2].z * 0.5f * p2) + (p2_sub2 * (p_vec[0].z * 0.5f * p2_sub1) - (p2_sub2 * (p_vec[1].z * p2)));
}

/*
 * --INFO--
 * Address:	8017C388
 * Size:	00019C
 */
void calcMatrix(const Vector3f&, const Vector3f&, const Vector3f&, const Vector3f&, Matrix4f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stfd      f29, 0x78(r1)
	  stfd      f28, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r7
	  stw       r30, 0x68(r1)
	  mr        r30, r6
	  lfs       f2, 0x8(r7)
	  lfs       f0, 0x18(r7)
	  fmuls     f3, f2, f2
	  lfs       f1, 0x28(r7)
	  fmuls     f0, f0, f0
	  lfs       f5, 0x0(r3)
	  fmuls     f4, f1, f1
	  fadds     f3, f3, f0
	  lfs       f29, 0x0(r7)
	  lfs       f30, 0x10(r7)
	  lfs       f31, 0x20(r7)
	  lfs       f2, 0x4(r7)
	  lfs       f1, 0x14(r7)
	  fadds     f28, f4, f3
	  lfs       f0, 0x24(r7)
	  stfs      f5, 0x0(r7)
	  lfs       f3, 0x4(r3)
	  stfs      f3, 0x10(r7)
	  lfs       f3, 0x8(r3)
	  stfs      f3, 0x20(r7)
	  lfs       f3, 0x0(r4)
	  stfs      f3, 0x4(r7)
	  lfs       f3, 0x4(r4)
	  stfs      f3, 0x14(r7)
	  lfs       f3, 0x8(r4)
	  stfs      f3, 0x24(r7)
	  lfs       f3, 0x0(r5)
	  stfs      f3, 0x8(r7)
	  lfs       f3, 0x4(r5)
	  stfs      f3, 0x18(r7)
	  lfs       f3, 0x8(r5)
	  stfs      f3, 0x28(r7)
	  lfs       f3, -0x513C(r2)
	  fcmpo     cr0, f28, f3
	  ble-      .loc_0x110
	  fsqrte    f4, f28
	  lfd       f6, -0x5138(r2)
	  lfd       f5, -0x5130(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f28, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f28, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f28, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f28, f3
	  frsp      f3, f3
	  stfs      f3, 0x28(r1)
	  lfs       f28, 0x28(r1)

	.loc_0x110:
	  fmuls     f2, f2, f2
	  fmuls     f1, f1, f1
	  fmuls     f3, f0, f0
	  fadds     f0, f2, f1
	  fadds     f1, f3, f0
	  bl        -0x16E86C
	  fmuls     f2, f29, f29
	  fmuls     f0, f30, f30
	  fmuls     f3, f31, f31
	  fmr       f29, f1
	  fadds     f0, f2, f0
	  fadds     f1, f3, f0
	  bl        -0x16E888
	  stfs      f1, 0x38(r1)
	  addi      r4, r1, 0x38
	  addi      r3, r31, 0
	  stfs      f29, 0x3C(r1)
	  stfs      f28, 0x40(r1)
	  bl        -0x13DD24
	  lfs       f0, 0x0(r30)
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x2C(r31)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  lfd       f29, 0x78(r1)
	  lfd       f28, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void calcMatrix3f(const Vector3f&, const Vector3f&, const Vector3f&, Matrix3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017C524
 * Size:	0002F8
 */
/**
 * Calculates the position of the middle joint and bottom joint based on the given parameters.
 *
 * @param topPosition The position of the top joint.
 * @param bottomPosition The position of the bottom joint.
 * @param topToMiddleDistance The distance between the top joint and the middle joint.
 * @param middleToBottomDistance The distance between the middle joint and the bottom joint.
 * @param middleJointPos [out] The calculated position of the middle joint.
 * @param bottomJointPosition [out] The calculated position of the bottom joint.
 */
void calcJointPos(const Vector3f& topPosition, const Vector3f& bottomPosition, f32 topToMiddleDistance, f32 middleToBottomDistance,
                  Vector3f& middleJointPos, Vector3f& bottomJointPosition)
{
	f32 distanceTopMiddle    = SQUARE(topToMiddleDistance);
	f32 distanceMiddleBottom = SQUARE(middleToBottomDistance);

	Vector3f targetXyz         = bottomPosition;
	Vector3f topToTargetVector = bottomPosition - topPosition;

	f32 distanceTopToTarget = topToTargetVector.squaredLength();
	if (!(distanceTopToTarget < 0.000001f)) {
		f32 factor = (0.5f / distanceTopToTarget) * (distanceTopToTarget + (distanceTopMiddle - distanceMiddleBottom));

		Vector3f scaledTopToTarget(factor * topToTargetVector.x + topPosition.x, factor * topToTargetVector.y + topPosition.y,
		                           factor * topToTargetVector.z + topPosition.z);

		Vector3f offsetFromTop = scaledTopToTarget - topPosition;

		f32 distanceAdjustment = distanceTopMiddle - SQUARE(offsetFromTop.x) - SQUARE(offsetFromTop.y) - SQUARE(offsetFromTop.z);

		if (!(distanceAdjustment <= 0.0f)) {
			Vector3f cross1 = cross(middleJointPos, topToTargetVector);
			middleJointPos  = cross(cross1, topToTargetVector);

			f32 outSqr = middleJointPos.squaredLength();
			if (outSqr != 0.0f) {
				f32 len               = sqrtf(distanceAdjustment / outSqr);
				bottomJointPosition.x = len * middleJointPos.x + cross1.x;
				bottomJointPosition.y = len * middleJointPos.y + cross1.y;
				bottomJointPosition.z = len * middleJointPos.z + cross1.z;
				return;
			}
		}
	}

	f32 dtm           = sqrtf(distanceTopMiddle);
	f32 dmb           = sqrtf(distanceMiddleBottom);
	f32 distanceRatio = dtm / (dtm + dmb);

	bottomJointPosition = Vector3f(distanceRatio * targetXyz.x + topPosition.x, distanceRatio * targetXyz.y + topPosition.y,
	                               distanceRatio * targetXyz.z + topPosition.z);
	/*
	.loc_0x0:
	  stwu      r1, -0x68(r1)
	  fmuls     f8, f1, f1
	  fmuls     f7, f2, f2
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  stfd      f29, 0x50(r1)
	  lfs       f0, 0x0(r4)
	  lfs       f9, 0x0(r3)
	  lfs       f1, 0x4(r4)
	  fsubs     f2, f0, f9
	  lfs       f11, 0x4(r3)
	  lfs       f0, 0x8(r4)
	  fsubs     f1, f1, f11
	  lfs       f12, 0x8(r3)
	  fsubs     f0, f0, f12
	  lfs       f3, -0x5128(r2)
	  fmuls     f5, f2, f2
	  fmuls     f4, f1, f1
	  fmuls     f6, f0, f0
	  fadds     f4, f5, f4
	  fadds     f5, f6, f4
	  fcmpo     cr0, f5, f3
	  blt-      .loc_0x1DC
	  lfs       f4, -0x5144(r2)
	  fsubs     f3, f8, f7
	  lfs       f31, -0x513C(r2)
	  fdivs     f4, f4, f5
	  fadds     f3, f5, f3
	  fmuls     f5, f4, f3
	  fmuls     f3, f5, f2
	  fmuls     f4, f5, f1
	  fmuls     f5, f5, f0
	  fadds     f3, f9, f3
	  fadds     f4, f11, f4
	  fadds     f5, f12, f5
	  fsubs     f10, f3, f9
	  fsubs     f9, f4, f11
	  fsubs     f6, f5, f12
	  fmuls     f10, f10, f10
	  fmuls     f9, f9, f9
	  fmuls     f6, f6, f6
	  fsubs     f10, f8, f10
	  fsubs     f9, f10, f9
	  fsubs     f6, f9, f6
	  fcmpo     cr0, f6, f31
	  cror      2, 0, 0x2
	  beq-      .loc_0x1DC
	  lfs       f13, 0x4(r5)
	  lfs       f30, 0x8(r5)
	  lfs       f10, 0x0(r5)
	  fmuls     f9, f13, f2
	  fmuls     f12, f30, f2
	  fmuls     f11, f10, f0
	  fmuls     f10, f10, f1
	  fmuls     f13, f13, f0
	  fsubs     f29, f12, f11
	  fsubs     f12, f10, f9
	  fmuls     f11, f30, f1
	  fmuls     f9, f0, f29
	  fmuls     f10, f1, f12
	  fsubs     f30, f13, f11
	  fmuls     f11, f2, f12
	  fsubs     f13, f10, f9
	  fmuls     f12, f0, f30
	  fmuls     f10, f2, f29
	  fmuls     f9, f1, f30
	  stfs      f13, 0x0(r5)
	  fsubs     f11, f12, f11
	  fsubs     f9, f10, f9
	  stfs      f11, 0x4(r5)
	  stfs      f9, 0x8(r5)
	  lfs       f10, 0x0(r5)
	  lfs       f9, 0x4(r5)
	  lfs       f11, 0x8(r5)
	  fmuls     f10, f10, f10
	  fmuls     f9, f9, f9
	  fmuls     f11, f11, f11
	  fadds     f9, f10, f9
	  fadds     f9, f11, f9
	  fcmpu     cr0, f31, f9
	  beq-      .loc_0x1DC
	  fdivs     f7, f6, f9
	  fcmpo     cr0, f7, f31
	  ble-      .loc_0x1A8
	  fsqrte    f1, f7
	  lfd       f6, -0x5138(r2)
	  lfd       f2, -0x5130(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f6, f1
	  fmul      f0, f7, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f6, f1
	  fmul      f0, f7, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f6, f1
	  fmul      f0, f7, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f7, f0
	  frsp      f0, f0
	  stfs      f0, 0x28(r1)
	  lfs       f7, 0x28(r1)

	.loc_0x1A8:
	  lfs       f0, 0x0(r5)
	  fmuls     f0, f7, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x0(r6)
	  lfs       f0, 0x4(r5)
	  fmuls     f0, f7, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0x4(r6)
	  lfs       f0, 0x8(r5)
	  fmuls     f0, f7, f0
	  fadds     f0, f5, f0
	  stfs      f0, 0x8(r6)
	  b         .loc_0x2E4

	.loc_0x1DC:
	  lfs       f3, -0x513C(r2)
	  fcmpo     cr0, f8, f3
	  ble-      .loc_0x240
	  fsqrte    f4, f8
	  lfd       f6, -0x5138(r2)
	  lfd       f5, -0x5130(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f8, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f8, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f8, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f8, f3
	  frsp      f3, f3
	  stfs      f3, 0x24(r1)
	  lfs       f8, 0x24(r1)

	.loc_0x240:
	  lfs       f3, -0x513C(r2)
	  fcmpo     cr0, f7, f3
	  ble-      .loc_0x2A8
	  fsqrte    f4, f7
	  lfd       f6, -0x5138(r2)
	  lfd       f5, -0x5130(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f7, f3
	  frsp      f3, f3
	  stfs      f3, 0x20(r1)
	  lfs       f3, 0x20(r1)
	  b         .loc_0x2AC

	.loc_0x2A8:
	  fmr       f3, f7

	.loc_0x2AC:
	  fadds     f4, f8, f3
	  lfs       f3, 0x0(r3)
	  fdivs     f4, f8, f4
	  fmuls     f2, f4, f2
	  fmuls     f1, f4, f1
	  fmuls     f0, f4, f0
	  fadds     f2, f3, f2
	  stfs      f2, 0x0(r6)
	  lfs       f2, 0x4(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x4(r6)
	  lfs       f1, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r6)

	.loc_0x2E4:
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  lfd       f29, 0x50(r1)
	  addi      r1, r1, 0x68
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E8
 */
void calcMtxDirect(const Matrix4f&, const Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017C81C
 * Size:	00004C
 */
void calcMat4toMat3(const Matrix4f& inMtx, Matrix3f& outMtx)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			outMtx.mMtx[j][i] = inMtx.mMtx[j][i];
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void calcMat3toMat4(const Matrix3f& inMtx, Matrix4f& outMtx)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			outMtx.mMtx[j][i] = inMtx.mMtx[j][i];
		}
	}
}
} // namespace NsCalculation
