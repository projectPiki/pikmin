#ifndef _NLIB_MATH_H
#define _NLIB_MATH_H

#include "types.h"
#include "Vector.h"
#include "Dolphin/mtx.h"
#include "system.h"

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
	static f32 minValue(f32, f32);
};

typedef NMath<f32> NMathf;

struct NMathF {

	static f32 error;
	static f32 const pi;
	static f32 const degreePerRadian;
	static f32 const radianPerDegree;

	static f32 cos(f32 x) { return cosf(x); }
	static f32 sin(f32 x) { return sinf(x); }

	static f32 atan2(f32, f32);
	static f32 remainder(f32, f32);

	// unused/inlined:
	static f32 roundAngle(f32);

	// inlines from DLL, to be created:
	static f32 angleDifference(f32, f32);
	static f32 calcNearerDirection(f32, f32);
	static f32 d2r(f32);
	static f32 interpolate(f32, f32, f32);
	static f32 length(f32, f32);
	static f32 r2d(f32);
	static f32 rangeRandom(f32, f32);
	static f32 rateRandom(f32, f32);
	static f32 sqrt(f32);
	static f32 tan(f32);
	static int quotient(f32, f32);
	static bool equals(f32, f32);
	static bool isPositive(f32);
	static bool isZero(f32 value) { return NMathf::absolute(value) <= error; }
	static bool occurred(f32);

	// this is fake.
	static inline f32 atan2Vec(Vector3f vec) { return atan2(vec.x, vec.z); }

	// this is fake or needs renaming
	static inline f32 getRandomAngle() { return 2.0f * StdSystem::getRand(1.0f) * pi; }
};

struct NMathI {
	static int rangeRandom(int, int);
	static bool checkBit(int, int);
};

#endif
