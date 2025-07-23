#ifndef _NSMATH_H
#define _NSMATH_H

#include "Vector.h"
#include "system.h"
#include "types.h"

struct NsCalculation {
	static void calcLagrange(f32, const Vector3f*, Vector3f&);
	static void calcMatrix(const Vector3f&, const Vector3f&, const Vector3f&, const Vector3f&, Matrix4f&);
	static void calcJointPos(const Vector3f&, const Vector3f&, f32, f32, Vector3f&, Vector3f&);
	static void calcMat4toMat3(const Matrix4f&, Matrix3f&);

	// unused/inlined:
	static void calcMatrix3f(const Vector3f&, const Vector3f&, const Vector3f&, Matrix3f&);
	static int calcMtxDirect(const Matrix4f&, const Matrix4f&);
	static void calcMat3toMat4(const Matrix3f&, Matrix4f&);

	// other existing (inline) functions according to the DLL:
	static f32 calcInnerRatio(const Vector3f&, const Vector3f&);
	static void calcMtxTrans(const Matrix4f&, int, Vector3f&);
	static void calcVectorTrans(const Vector3f&, int, Matrix4f&);

	// Calculates the cross product
	static void calcOuterPro(const Vector3f& a, const Vector3f& b, Vector3f& result)
	{
		result.x = a.y * b.z - a.z * b.y;
		result.y = a.z * b.x - a.x * b.z;
		result.z = a.x * b.y - a.y * b.x;
	}

	static void calcMtxBotIdent(Matrix4f& mtx)
	{
		mtx.mMtx[3][0] = 0.0f;
		mtx.mMtx[3][1] = 0.0f;
		mtx.mMtx[3][2] = 0.0f;
		mtx.mMtx[3][3] = 1.0f;
	}
};

// these exist in the DLL "map"
template <typename T>
struct NsLibMath {
	// these exist for int and f32
	static inline T abs(T val) { return (val > 0) ? val : -val; }

	static T revice(T value, T min, T max) { return (value < min) ? min : (value > max) ? max : value; }

	// these just exist for f32
	static T lagrange3(const T* points, T val)
	{
		return points[0] * 0.5f * (val - 1.0f) * (val - 2.0f) - points[1] * val * (val - 2.0f) + points[2] * 0.5f * val * (val - 1.0f);
	}

	static T toGoal(T start, T goal, T step)
	{
		T res;
		T a = NsLibMath::abs(start - goal);
		if (a < step) {
			res = goal;
		} else {
			res = (start < goal) ? start + step : start - step;
		}
		return res;
	}
};

struct NsMathF {
	static f32 calcNearerDirection(f32 from, f32 to)
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

	static f32 getRand(f32 val) { return gsys->getRand(1.0f) * (val * 0.99999899f); }

	static f32 roundAngle(f32 angle)
	{
		if (angle < 0.0f) {
			return angle + TAU;
		}

		if (angle >= TAU) {
			return angle - TAU;
		}

		return angle;
	}
};

struct NsMathI {
	static int getRand(int val) { return gsys->getRand(1.0f) * (val * 0.99999899f); }

	// this COULD be revice instead, but i haven't seen a f32 version yet. TBD.
	// just bounds value in [min,max]
	static int intLoop(int value, int min, int max)
	{
		return (value < min) ? max + value - min + 1 : (value > max) ? min + value - max - 1 : value;
	}
};

#endif
