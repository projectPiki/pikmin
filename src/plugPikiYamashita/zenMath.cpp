#include "DebugLog.h"
#include "Matrix3f.h"
#include "Vector.h"
#include "nlib/Math.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D8 (Matching by size)
 */
void zen::ZenQuat::GetMatrix(const Quat& quat, Matrix3f& outMtx)
{
	f32 quatScale = 2.0f / (SQUARE(quat.v.x) + SQUARE(quat.v.y) + SQUARE(quat.v.z) + SQUARE(quat.s));

	f32 scaledX = quatScale * quat.v.x;
	f32 scaledY = quatScale * quat.v.y;
	f32 scaledZ = quatScale * quat.v.z;

	f32 scaledXw = scaledX * quat.s;
	f32 scaledYw = scaledY * quat.s;
	f32 scaledZw = scaledZ * quat.s;

	f32 scaledXx = scaledX * quat.v.x;
	f32 scaledYx = scaledY * quat.v.x;
	f32 scaledZx = scaledZ * quat.v.x;

	f32 scaledYy = scaledY * quat.v.y;
	f32 scaledZy = scaledZ * quat.v.y;
	f32 scaledZz = scaledZ * quat.v.z;

	outMtx.mMtx[0][0] = 1.0f - (scaledYy + scaledZz);
	outMtx.mMtx[0][1] = scaledYx - scaledZw;
	outMtx.mMtx[0][2] = scaledZx + scaledYw;

	outMtx.mMtx[1][0] = scaledYx + scaledZw;
	outMtx.mMtx[1][1] = 1.0f - (scaledXx + scaledZz);
	outMtx.mMtx[1][2] = scaledZy - scaledXw;

	outMtx.mMtx[2][0] = scaledZx - scaledYw;
	outMtx.mMtx[2][1] = scaledZy + scaledXw;
	outMtx.mMtx[2][2] = 1.0f - (scaledXx + scaledYy);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000100 (Matching by size)
 */
void zen::ZenQuat::GetMatrix(const Quat& quat, Matrix4f& outMtx)
{
	f32 quatScale = 2.0f / (SQUARE(quat.v.x) + SQUARE(quat.v.y) + SQUARE(quat.v.z) + SQUARE(quat.s));

	f32 scaledX = quatScale * quat.v.x;
	f32 scaledY = quatScale * quat.v.y;
	f32 scaledZ = quatScale * quat.v.z;

	f32 scaledXw = scaledX * quat.s;
	f32 scaledYw = scaledY * quat.s;
	f32 scaledZw = scaledZ * quat.s;

	f32 scaledXx = scaledX * quat.v.x;
	f32 scaledYx = scaledY * quat.v.x;
	f32 scaledZx = scaledZ * quat.v.x;

	f32 scaledYy = scaledY * quat.v.y;
	f32 scaledZy = scaledZ * quat.v.y;
	f32 scaledZz = scaledZ * quat.v.z;

	outMtx.mMtx[0][0] = 1.0f - (scaledYy + scaledZz);
	outMtx.mMtx[0][1] = scaledYx - scaledZw;
	outMtx.mMtx[0][2] = scaledZx + scaledYw;
	outMtx.mMtx[0][3] = 0.0f;

	outMtx.mMtx[1][0] = scaledYx + scaledZw;
	outMtx.mMtx[1][1] = 1.0f - (scaledXx + scaledZz);
	outMtx.mMtx[1][2] = scaledZy - scaledXw;
	outMtx.mMtx[1][3] = 0.0f;

	outMtx.mMtx[2][0] = scaledZx - scaledYw;
	outMtx.mMtx[2][1] = scaledZy + scaledXw;
	outMtx.mMtx[2][2] = 1.0f - (scaledXx + scaledYy);
	outMtx.mMtx[2][3] = 0.0f;

	outMtx.mMtx[3][0] = 0.0f;
	outMtx.mMtx[3][1] = 0.0f;
	outMtx.mMtx[3][2] = 0.0f;
	outMtx.mMtx[3][3] = 1.0f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000238 (Nonmatching by size)
 */
void zen::ZenQuat::GetRotate(const Quat& quat, Vector3f& outVec)
{
	f32 cosv, sinv;
	Matrix3f mtx;
	GetMatrix(quat, mtx);

	if (mtx.mMtx[0][2] == 1.0f) {
		outVec.x = 0.0;
		outVec.y = -HALF_PI;
		outVec.z = NMathF::atan2(-mtx.mMtx[1][0], -mtx.mMtx[2][0]);
		return;
	}
	if (mtx.mMtx[0][2] == -1.0f) {
		outVec.x = 0.0;
		outVec.y = HALF_PI;
		outVec.z = NMathF::atan2(mtx.mMtx[2][1], mtx.mMtx[1][1]);
		return;
	}

	if (mtx.mMtx[0][0] < 0.0f) {
		outVec.x = NMathF::atan2(-mtx.mMtx[1][2], -mtx.mMtx[2][2]);
		outVec.z = NMathF::atan2(-mtx.mMtx[0][1], -mtx.mMtx[0][0]);
		cosv     = cosf(outVec.x);
	} else {
		outVec.x = NMathF::atan2(mtx.mMtx[1][2], mtx.mMtx[2][2]);
		outVec.z = NMathF::atan2(mtx.mMtx[0][1], mtx.mMtx[0][0]);
		cosv     = cosf(outVec.x);
	}
	if (zen::Abs(cosv) > 0.000001f) {
		sinv = sinf(outVec.x);
		if (sinv > 0.0f) {
			outVec.y = NMathF::atan2(-mtx.mMtx[0][2] * sinv, mtx.mMtx[1][2]);
		} else {
			outVec.y = NMathF::atan2(mtx.mMtx[0][2] * sinv, -mtx.mMtx[1][2]);
		}
	} else if (cosv > 0.0f) {
		outVec.y = NMathF::atan2(-mtx.mMtx[0][2] * cosv, mtx.mMtx[2][2]);
	} else if (cosv < 0.0f) {
		outVec.y = NMathF::atan2(mtx.mMtx[0][2] * cosv, -mtx.mMtx[2][2]);
	}
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
