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
void calcNearerDirection(f32, f32);

// things to make according to the DLL:
inline f32 getRand(f32 val)
{
	f32 boundedVal = val * 0.99999899f;
	return System::getRand(1.0f) * boundedVal;
}

inline f32 roundAngle(f32);
} // namespace NsMathF

namespace NsMathI {
inline int getRand(int val)
{
	f32 fVal = val * 0.99999899f;
	return System::getRand(1.0f) * fVal;
}
inline int intLoop(int, int, int);
} // namespace NsMathI

#endif
