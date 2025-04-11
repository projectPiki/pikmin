#ifndef _NLIB_MATH_H
#define _NLIB_MATH_H

#include "types.h"
#include "Vector.h"
#include "Dolphin/mtx.h"
#include <system.h>
#include "nlib/System.h"

template <typename T>
struct NMath {
	static void copyArray44(Mtx44 output, Mtx44 input)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				output[i][j] = input[i][j];
			}
		}
	}

	static T absolute(T val)
	{
		if (val > 0) {
			return val;
		}
		return -val;
	}

	static T clampMinMax(T val, T lower, T upper)
	{
		if (val < lower) {
			return lower;
		}
		if (val > upper) {
			return upper;
		}
		return val;
	}

	// inlines to make, per the DLL:
	static f32 maxValue(f32, f32);
	static T minValue(T x, T y) { return (x < y) ? x : y; }
};

typedef NMath<f32> NMathf;

struct NMathF {

	static f32 error;
	static f32 const pi;
	static f32 const degreePerRadian;
	static f32 const radianPerDegree;

	static f32 cos(f32 x) { return cosf(x); }
	static f32 sin(f32 x) { return sinf(x); }
	static f32 tan(f32 x) { return tanf(x); }

	static f32 atan2(f32, f32);
	static f32 remainder(f32, f32);

	// NB: don't use this - it gets stripped in nlibgeometry
	// so shouldn't show up elsewhere in anything non-stripped
	static inline f32 roundAngle(f32 angle)
	{
		f32 tau = 2.0f * NMathF::pi;
		if (angle < 0.0f) {
			return angle + tau;
		}
		if (angle >= tau) {
			return angle - tau;
		}
		return angle;
	}

	static inline f32 interpolate(f32 x, f32 y, f32 t) { return x * (1.0f - t) + y * t; }
	static inline f32 length(f32 x, f32 y) { return std::sqrtf(x * x + y * y); }

	static inline bool equals(f32 x, f32 y) { return NMathF::isZero(x - y); }
	static inline bool isPositive(f32 x) { return x >= error; }
	static inline bool isZero(f32 value) { return NMathf::absolute(value) <= error; }

	static inline f32 d2r(f32 degrees) { return degrees * radianPerDegree; }
	static inline f32 r2d(f32 radians) { return radians * degreePerRadian; }

	static inline f32 calcNearerDirection(f32 target, f32 angle)
	{
		f32 tau = 2.0f * pi;
		if (angle >= target) {
			f32 diff = angle - target;
			if (tau - diff < diff) {
				angle -= tau;
			}
		} else {
			f32 diff = target - angle;
			if (tau - diff < diff) {
				angle += tau;
			}
		}
		return angle;
	}

	static inline f32 angleDifference(f32 angleA, f32 angleB)
	{
		f32 tau = 2.0f * pi;
		if (angleA >= angleB) {
			f32 mainDiff = angleA - angleB;
			f32 compDiff = tau - mainDiff;
			if (mainDiff < compDiff) {
				return mainDiff;
			}

			return compDiff;
		}
		f32 mainDiff = angleB - angleA;
		f32 compDiff = tau - mainDiff;
		if (mainDiff < compDiff) {
			return mainDiff;
		}

		return compDiff;
	}

	static inline f32 rangeRandom(f32 min, f32 max) { return (max - min) * NSystem::random() + min; }
	static inline bool occurred(f32 chance) { return NSystem::random() < chance; }
	static inline f32 rateRandom(f32 min, f32 range) { return min * (2.0f * (NSystem::random() - 0.5f)) * range + min; }
	static inline f32 sqrt(f32 x) { return std::sqrtf(x); }

	// inlines from DLL, to be created:
	static inline f32 acos(f32);
	static inline int quotient(f32, f32);
};

struct NMathI {
	static int rangeRandom(int min, int max) { return min + NSystem::randomInt(max - min); }
	static bool checkBit(int flag, int bit) { return (flag & bit); }
};

extern u16 atan(f32 x, f32 y);

extern u16 AtanTable[1025];

#endif
