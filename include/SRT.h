#ifndef _SRT_H
#define _SRT_H

#include "types.h"
#include "Vector.h"

struct SRT {
	Vector3f mScale;       // _00
	Vector3f mRotation;    // _0C
	Vector3f mTranslation; // _18, aka position
};

#endif
