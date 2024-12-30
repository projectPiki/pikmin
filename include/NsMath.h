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
void calcMtxBotIdent(Matrix4f&);
void calcMtxTrans(const Matrix4f&, int, Vector3f&);
void calcOuterPro(const Vector3f&, const Vector3f&, Vector3f&);
void calcVectorTrans(const Vector3f&, int, Matrix4f&);
} // namespace NsCalculation

// these exist in the DLL "map"
template <typename T>
struct NsLibMath {
	// these exist for int and float
	T abs(T);
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

// things to make according to the DLL:
inline f32 getRand(f32 val) { return System::getRand(1.0f) * (val * 0.99999899f); }

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
