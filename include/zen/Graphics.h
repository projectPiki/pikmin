#ifndef _ZEN_GRAPHICS_H
#define _ZEN_GRAPHICS_H

#include "types.h"
#include "Vector.h"

struct Colour;

namespace zen {
/**
 * @brief TODO
 */
struct DrawLifeCircle {
	DrawLifeCircle(Vector3f& p1, f32 p2)
	{
		_08 = p1;
		_14 = p2;
		_00 = int(TRI_NUM) - 1;
		_04 = 0.0f;
	}

	void drawLifeCircle(f32 healthRatio);

	static const f32 TRI_NUM;

	int _00;      // _00
	f32 _04;      // _04
	Vector3f _08; // _08
	f32 _14;      // _14
};

/**
 * @brief TODO
 */
struct DrawNaviLifeCircle : public DrawLifeCircle {
	DrawNaviLifeCircle(int p1, Vector3f& p2, f32 p3)
	    : DrawLifeCircle(p2, p3)
	{
		mNaviIndex = p1;
	}

	void drawLifeCircle();

	// _00-_18 = DrawLifeCircle
	int mNaviIndex; // _18, navi index? should be 0
};
namespace zenGraphics {
extern void drawOneTri(Vector3f*, Colour&);
extern void setTevFillPolygon();
} // namespace zenGraphics
} // namespace zen

#endif
