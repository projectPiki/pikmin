#ifndef _QUAT_H
#define _QUAT_H

#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct Quat {
	Quat();

	void fromMat3f(struct Matrix3f&);
	void rotate(struct Vector3f&, f32);
	void multiply(Quat&);
	void normalise();
	void genVectorX(Vector3f&);
	void genVectorY(Vector3f&);
	void genVectorZ(Vector3f&);
	void slerp(Quat&, f32, int);
	void fromEuler(Vector3f&);

	// unused/inlined:
	void multiplyTo(Quat&, Quat&);

	f32 x, y, z, w; // _00-_10 - might be Vector3f, f32?
};

#endif
