#ifndef _NLIB_GRAPHICS_H
#define _NLIB_GRAPHICS_H

#include "types.h"

struct Camera;

/**
 * @brief TODO
 */
struct NCamera {
	NCamera(Camera*);

	void makeMatrix();
	void makeCamera();

	// TODO: members
};

#endif
