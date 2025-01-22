#ifndef _ZEN_GRAPHICS_H
#define _ZEN_GRAPHICS_H

#include "types.h"

struct Vector3f;
struct Colour;

namespace zen {
/**
 * @brief TODO
 */
struct DrawLifeCircle {
	void drawLifeCircle(f32);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawNaviLifeCircle {
	void drawLifeCircle();

	// TODO: members
};
} // namespace zen

namespace zenGraphics {
static void drawOneTri(Vector3f*, Colour&);
static void setTevFillPolygon();
} // namespace zenGraphics

#endif
