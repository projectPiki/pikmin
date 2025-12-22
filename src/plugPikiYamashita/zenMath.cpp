#include "DebugLog.h"
#include "Matrix3f.h"
#include "Vector.h"
#include "zen/Math.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D8
 */
void zen::ZenQuat::GetMatrix(const Quat&, Matrix3f& outMtx)
{
	outMtx.mMtx[0][0] = 1.0f; // just for sdata2's sake
	                          // UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000100
 */
void zen::ZenQuat::GetMatrix(const Quat&, Matrix4f&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000238
 */
void zen::ZenQuat::GetRotate(const Quat&, Vector3f&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
f32 zen::getDistPointAndLine(Vector3f point, Vector3f lineStartPt, Vector3f lineEndPt, f32& t)
{
	Vector3f dirStart;
	Vector3f dirEnd;
	Vector3f lineDir;

	dirStart.set(lineStartPt - point);
	dirEnd.set(lineEndPt - point);
	lineDir.set(dirEnd - dirStart);

	f32 dist;
	if (lineDir.x != 0.0f || lineDir.y != 0.0f || lineDir.z != 0.0f) {
		Vector3f startToNearest;
		t = -dirStart.DP(lineDir) / (lineDir.x * lineDir.x + lineDir.y * lineDir.y + lineDir.z * lineDir.z);
		startToNearest.set(lineDir.x * t + dirStart.x, lineDir.y * t + dirStart.y, lineDir.z * t + dirStart.z);
		dist = startToNearest.length();
	} else {
		t    = 1.0f;
		dist = dirStart.length();
	}

	return dist;
}

/**
 * @TODO: Documentation
 */
void zen::makeRotMatrix(immut Vector3f& axis, Matrix3f& rotMtx)
{
	Vector3f xVec;
	Vector3f zVec;

	xVec.set(1.0f, 0.0f, 0.0f);
	zVec.cross(xVec, axis);
	if (zVec.x == 0.0f && zVec.x == 0.0f && zVec.x == 0.0f) { // nice work.
		zVec.set(0.0f, 0.0f, 1.0f);
	}
	zVec.normalize();
	xVec.cross(axis, zVec);
	xVec.normalize();

	rotMtx.mMtx[0][0] = xVec.x;
	rotMtx.mMtx[1][0] = xVec.y;
	rotMtx.mMtx[2][0] = xVec.z;

	rotMtx.mMtx[0][1] = axis.x;
	rotMtx.mMtx[1][1] = axis.y;
	rotMtx.mMtx[2][1] = axis.z;

	rotMtx.mMtx[0][2] = zVec.x;
	rotMtx.mMtx[1][2] = zVec.y;
	rotMtx.mMtx[2][2] = zVec.z;
}
