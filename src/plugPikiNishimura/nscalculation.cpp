#include "NsMath.h"

#include "Vector.h"
#include "Matrix3f.h"
#include "Matrix4f.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

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

	f32 adjSqr;
	f32 midBotSqr = SQUARE(middleToBottomDistance);
	f32 topMidSqr = SQUARE(topToMiddleDistance);

	botToTop.x = bottomPosition.x - topPosition.x;
	botToTop.y = bottomPosition.y - topPosition.y;
	botToTop.z = bottomPosition.z - topPosition.z;

	f32 topBotSqr = SQUARE(botToTop.x) + SQUARE(botToTop.y) + SQUARE(botToTop.z);
	if (!(topBotSqr < 0.000001f)) {
		f32 factor = (0.5f / topBotSqr) * (topMidSqr - midBotSqr + topBotSqr);
		adjTop.x   = factor * botToTop.x + topPosition.x;
		adjTop.y   = factor * botToTop.y + topPosition.y;
		adjTop.z   = factor * botToTop.z + topPosition.z;

		adjBotToTop.x = adjTop.x - topPosition.x;
		adjBotToTop.y = adjTop.y - topPosition.y;
		adjBotToTop.z = adjTop.z - topPosition.z;

		adjSqr = topMidSqr - SQUARE(adjBotToTop.x) - SQUARE(adjBotToTop.y) - SQUARE(adjBotToTop.z);
		(void)adjSqr;

		if (!(adjSqr <= 0.0f)) {
			NsCalculation::calcOuterPro(middleJointPos, botToTop, adjBotToTop);
			NsCalculation::calcOuterPro(botToTop, adjBotToTop, middleJointPos);
			f32 midJointSqr = SQUARE(middleJointPos.x) + SQUARE(middleJointPos.y) + SQUARE(middleJointPos.z);
			if (midJointSqr != 0.0f) {
				factor                = std::sqrtf(adjSqr / midJointSqr);
				bottomJointPosition.x = factor * middleJointPos.x + adjTop.x;
				bottomJointPosition.y = factor * middleJointPos.y + adjTop.y;
				bottomJointPosition.z = factor * middleJointPos.z + adjTop.z;
				return;
			}
		}
	}

	topToMiddleDistance    = std::sqrtf(topMidSqr);
	middleToBottomDistance = std::sqrtf(midBotSqr);

	f32 rootVal           = topToMiddleDistance / (topToMiddleDistance + middleToBottomDistance);
	bottomJointPosition.x = rootVal * botToTop.x + topPosition.x;
	bottomJointPosition.y = rootVal * botToTop.y + topPosition.y;
	bottomJointPosition.z = rootVal * botToTop.z + topPosition.z;
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
