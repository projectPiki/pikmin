#include "NsMath.h"

#include "DebugLog.h"
#include "Matrix3f.h"
#include "Matrix4f.h"
#include "Vector.h"
#include "sysMath.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * Aside from arg order and defines, identical to Pikmin 2's NsMathExp::calcLagrange
 */
void NsCalculation::calcLagrange(f32 t, const Vector3f* controlPts, Vector3f& outPoint)
{
	outPoint.x = (t - 2.0f) * (controlPts[0].x * 0.5f * (t - 1.0f)) - ((t - 2.0f) * (controlPts[1].x * t))
	           + (t - 1.0f) * (controlPts[2].x * 0.5f * t);
	outPoint.y = (t - 2.0f) * (controlPts[0].y * 0.5f * (t - 1.0f)) - ((t - 2.0f) * (controlPts[1].y * t))
	           + (t - 1.0f) * (controlPts[2].y * 0.5f * t);
	outPoint.z = (t - 2.0f) * (controlPts[0].z * 0.5f * (t - 1.0f)) - ((t - 2.0f) * (controlPts[1].z * t))
	           + (t - 1.0f) * (controlPts[2].z * 0.5f * t);
}

/**
 * @todo: Documentation
 */
void NsCalculation::calcMatrix(const Vector3f& xVec, const Vector3f& yVec, const Vector3f& zVec, const Vector3f& transVec, Matrix4f& mtx)
{
	Vector3f inXVec, inYVec, inZVec;

	calcMtxTrans(mtx, 0, inXVec);
	calcMtxTrans(mtx, 1, inYVec);
	calcMtxTrans(mtx, 2, inZVec);

	calcVectorTrans(xVec, 0, mtx);
	calcVectorTrans(yVec, 1, mtx);
	calcVectorTrans(zVec, 2, mtx);

	mtx.scale(Vector3f(inXVec.length(), inYVec.length(), inZVec.length()));

	calcVectorTrans(transVec, 3, mtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size)
 */
void NsCalculation::calcMatrix3f(const Vector3f& vec1, const Vector3f& vec2, const Vector3f& vec3, Matrix3f& mtx)
{
	mtx.mMtx[0][0] = vec1.x;
	mtx.mMtx[0][3] = vec1.y;
	mtx.mMtx[1][2] = vec1.z;
	mtx.mMtx[0][1] = vec2.x;
	mtx.mMtx[1][0] = vec2.y;
	mtx.mMtx[1][3] = vec2.z;
	mtx.mMtx[0][2] = vec3.x;
	mtx.mMtx[1][1] = vec3.y;
	mtx.mMtx[2][0] = vec3.z;
}

/**
 * @todo: Documentation
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
void NsCalculation::calcJointPos(const Vector3f& topPosition, const Vector3f& bottomPosition, f32 topToMiddleDistance,
                                 f32 middleToBottomDistance, Vector3f& middleJointPos, Vector3f& bottomJointPosition)
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
			calcOuterPro(middleJointPos, botToTop, adjBotToTop);
			calcOuterPro(botToTop, adjBotToTop, middleJointPos);
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001E8 (Matching by size)
 */
int NsCalculation::calcMtxDirect(const Matrix4f& param_1, const Matrix4f& param_2)
{
	Vector3f local_28[3];

	Vector3f local_34;
	Vector3f local_40;
	Vector3f local_4c;

	float maxInnerRatio = 0.0f;

	int i; // Nishimura, why?
	for (i = 0; i < 3; i++) {
		calcMtxTrans(param_1, i, local_28[i]);
		local_28[i].normalise();
	}
	calcMtxTrans(param_1, 3, local_34);
	calcMtxTrans(param_2, 3, local_40);
	local_4c.x = local_40.x - local_34.x;
	local_4c.y = local_40.y - local_34.y;
	local_4c.z = local_40.z - local_34.z;
	local_4c.normalise();

	int maxIdx;
	for (i = 0; i < 3; i++) {
		float innerRatio = calcInnerRatio(local_28[i], local_4c);
		if (maxInnerRatio < innerRatio) {
			maxIdx        = i;
			maxInnerRatio = innerRatio;
		}
	}
	return maxIdx;
}

/**
 * @todo: Documentation
 */
void NsCalculation::calcMat4toMat3(const Matrix4f& inMtx, Matrix3f& outMtx)
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size)
 */
void NsCalculation::calcMat3toMat4(const Matrix3f& inMtx, Matrix4f& outMtx)
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
