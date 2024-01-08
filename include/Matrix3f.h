#ifndef _MATRIX3F_H
#define _MATRIX3F_H

#include "types.h"
#include "Dolphin/mtx.h"

struct Matrix3f {
	Matrix3f() { } // probably

	void identity();

	Mtx33 mMtx; // _00-_24
};

#endif
