#include "types.h"
#include "Vector.h"
#include "Matrix3f.h"
#include "Matrix4f.h"
#include "NsMath.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

namespace NsCalculation {
/*
 * --INFO--
 * Address:	8017C2C8
 * Size:	0000C0
 * Aside from arg order and defines, identical to Pikmin 2's NsMathExp::calcLagrange
 */
void calcLagrange(f32 t, const Vector3f* controlPts, Vector3f& outPoint)
{
	outPoint.x = (t - 2.0f) * (controlPts[0].x * 0.5f * (t - 1.0f)) - ((t - 2.0f) * (controlPts[1].x * t))
	           + (t - 1.0f) * (controlPts[2].x * 0.5f * t);
	outPoint.y = (t - 2.0f) * (controlPts[0].y * 0.5f * (t - 1.0f)) - ((t - 2.0f) * (controlPts[1].y * t))
	           + (t - 1.0f) * (controlPts[2].y * 0.5f * t);
	outPoint.z = (t - 2.0f) * (controlPts[0].z * 0.5f * (t - 1.0f)) - ((t - 2.0f) * (controlPts[1].z * t))
	           + (t - 1.0f) * (controlPts[2].z * 0.5f * t);
}

/*
 * --INFO--
 * Address:	8017C388
 * Size:	00019C
 */
void calcMatrix(const Vector3f& xVec, const Vector3f& yVec, const Vector3f& zVec, const Vector3f& transVec, Matrix4f& mtx)
{
	Vector3f inXVec, inYVec, inZVec;

	mtx.getColumn(0, inXVec);
	mtx.getColumn(1, inYVec);
	mtx.getColumn(2, inZVec);

	mtx.setColumn(0, xVec);
	mtx.setColumn(1, yVec);
	mtx.setColumn(2, zVec);

	mtx.scale(Vector3f(inXVec.length(), inYVec.length(), inZVec.length()));

	mtx.setTranslation(transVec);
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
	Vector3f botToTop;
	Vector3f adjBotToTop;
	Vector3f adjTop;

	f32 topMidSqr = SQUARE(topToMiddleDistance);
	f32 midBotSqr = SQUARE(middleToBottomDistance);

	botToTop.x = bottomPosition.x - topPosition.x;
	botToTop.y = bottomPosition.y - topPosition.y;
	botToTop.z = bottomPosition.z - topPosition.z;

	f32 topBotSqr = botToTop.x * botToTop.x + botToTop.y * botToTop.y + botToTop.z * botToTop.z;
	if (!(topBotSqr < 0.000001f)) {
		f32 factor = (0.5f / topBotSqr) * (topMidSqr - midBotSqr + topBotSqr);
		adjTop.x   = factor * botToTop.x + topPosition.x;
		adjTop.y   = factor * botToTop.y + topPosition.y;
		adjTop.z   = factor * botToTop.z + topPosition.z;

		adjBotToTop.x = adjTop.x - topPosition.x;
		adjBotToTop.y = adjTop.y - topPosition.y;
		adjBotToTop.z = adjTop.z - topPosition.z;

		f32 adjSqr = topMidSqr - SQUARE(adjBotToTop.x) - SQUARE(adjBotToTop.y) - SQUARE(adjBotToTop.z);
		if (!(adjSqr <= 0.0f)) {
			NsCalculation::calcOuterPro(middleJointPos, botToTop, adjBotToTop);
			NsCalculation::calcOuterPro(botToTop, adjBotToTop, middleJointPos);
			f32 midJointSqr
			    = middleJointPos.x * middleJointPos.x + middleJointPos.y * middleJointPos.y + middleJointPos.z * middleJointPos.z;
			if (midJointSqr != 0.0f) {
				f32 rootVal           = std::sqrtf(adjSqr / midJointSqr);
				bottomJointPosition.x = rootVal * middleJointPos.x + adjTop.x;
				bottomJointPosition.y = rootVal * middleJointPos.y + adjTop.y;
				bottomJointPosition.z = rootVal * middleJointPos.z + adjTop.z;
				return;
			}
		}
	}

	f32 topMid2 = std::sqrtf(SQUARE(topToMiddleDistance));
	f32 midBot2 = std::sqrtf(midBotSqr);

	f32 rootVal           = topMid2 / (topMid2 + midBot2);
	bottomJointPosition.x = rootVal * botToTop.x + topPosition.x;
	bottomJointPosition.y = rootVal * botToTop.y + topPosition.y;
	bottomJointPosition.z = rootVal * botToTop.z + topPosition.z;

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
int calcMtxDirect(const Matrix4f&, const Matrix4f&)
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
	outMtx.mMtx[0][0] = inMtx.mMtx[0][0];
	outMtx.mMtx[1][0] = inMtx.mMtx[1][0];
	outMtx.mMtx[2][0] = inMtx.mMtx[2][0];

	outMtx.mMtx[0][1] = inMtx.mMtx[0][1];
	outMtx.mMtx[1][1] = inMtx.mMtx[1][1];
	outMtx.mMtx[2][1] = inMtx.mMtx[2][1];

	outMtx.mMtx[0][2] = inMtx.mMtx[0][2];
	outMtx.mMtx[1][2] = inMtx.mMtx[1][2];
	outMtx.mMtx[2][2] = inMtx.mMtx[2][2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void calcMat3toMat4(const Matrix3f& inMtx, Matrix4f& outMtx)
{
	// UNUSED FUNCTION
}
} // namespace NsCalculation
