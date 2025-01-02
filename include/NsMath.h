#ifndef _NSMATH_H
#define _NSMATH_H

#include "types.h"
#include "Vector.h"
#include "system.h"

namespace NsCalculation {
void calcLagrange(f32, const Vector3f*, Vector3f&);
void calcMatrix(const Vector3f&, const Vector3f&, const Vector3f&, const Vector3f&, Matrix4f&);
void calcJointPos(const Vector3f&, const Vector3f&, Vector3f&, Vector3f&);
void calcMat4toMat3(const Matrix4f&, Matrix3f&);

// unused/inlined:
void calcMatrix3f(const Vector3f&, const Vector3f&, const Vector3f&, Matrix3f&);
int calcMtxDirect(const Matrix4f&, const Matrix4f&);
void calcMat3toMat4(const Matrix3f&, Matrix4f&);

// other existing (inline) functions according to the DLL:
f32 calcInnerRatio(const Vector3f&, const Vector3f&);
void calcMtxTrans(const Matrix4f&, int, Vector3f&);
void calcVectorTrans(const Vector3f&, int, Matrix4f&);

static void calcOuterPro(const Vector3f& vec1, const Vector3f& vec2, Vector3f& outVec)
{
	outVec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	outVec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	outVec.z = vec1.x * vec2.y - vec1.y * vec2.x;
}

static inline void calcMtxBotIdent(Matrix4f& mtx)
{
	mtx.mMtx[3][0] = 0.0f;
	mtx.mMtx[3][1] = 0.0f;
	mtx.mMtx[3][2] = 0.0f;
	mtx.mMtx[3][3] = 1.0f;
}
} // namespace NsCalculation

// these exist in the DLL "map"
template <typename T>
struct NsLibMath {
	// these exist for int and float
	static inline T abs(T val) { return (val > 0) ? val : -val; }

	T revice(T, T, T);

	// these just exist for float
	T lagrange3(const T*, T);
	T toGoal(T, T, T);
};

namespace NsMathF {
inline f32 calcNearerDirection(f32 from, f32 to)
{
	if (to >= from) {
		f32 diff = to - from;
		if (TAU - diff < diff) {
			to -= TAU;
		}
	} else {
		f32 diff = from - to;
		if (TAU - diff < diff) {
			to += TAU;
		}
	}

	return to;
}

// i cannot get these two to both work in every case they need to be in. stack seems better with the getRand1
// but dies when trying to pass something straight from a Parm<f32>::operator() call.
inline f32 getRand(f32 val) { return System::getRand(1.0f) * (val * 0.99999899f); }

inline f32 getRand1(f32 val)
{
	f32 fval = val * 0.99999899f;
	return System::getRand(1.0f) * fval;
}

inline f32 roundAngle(f32 angle)
{
	if (angle < 0.0f) {
		return angle + TAU;
	}

	if (angle >= TAU) {
		return angle - TAU;
	}

	return angle;
}
} // namespace NsMathF

namespace NsMathI {
// this isn't correct according to the DLL, but this matches the best for stack in Boss and PomAi
inline int getRand(int val) { return NsMathF::getRand(val); }
inline int intLoop(int, int, int);
} // namespace NsMathI

#endif
