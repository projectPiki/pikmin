#ifndef _MATRIX3F_H
#define _MATRIX3F_H

#include "types.h"
#include "Dolphin/mtx.h"

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct Matrix3f {
	Matrix3f() { identity(); }

	void identity()
	{
		for (int i = 0; i < 9; i++) {
			mMtx[i] = 0.0f;
		}

		mMtx[0] = mMtx[4] = mMtx[8] = 1.0f;
	}

	f32 mMtx[9]; // _00
};

#endif
