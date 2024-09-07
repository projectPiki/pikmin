#ifndef _KMATH_H
#define _KMATH_H

#include "types.h"
#include "Vector.h"

/**
 * @brief TODO
 */
struct KTri {
	KTri();

	void set(Vector3f&, Vector3f&, Vector3f&);

	Vector3f _00; // _00
	Vector3f _0C; // _0C
	Vector3f _18; // _18
};

/**
 * @brief TODO
 */
struct KRect {
	void inside(Vector3f&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct KSegment {
	// unused/inlined:
	KSegment();

	// TODO: members
};

#endif
