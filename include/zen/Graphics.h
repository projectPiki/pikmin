#ifndef _ZEN_GRAPHICS_H
#define _ZEN_GRAPHICS_H

#include "Vector.h"
#include "types.h"

struct Colour;

namespace zen {
/**
 * @brief TODO
 */
struct DrawLifeCircle {
public:
	DrawLifeCircle(immut Vector3f& p1, f32 p2)
	{
		_08                = p1;
		mRadius            = p2;
		mDisplayedTriCount = int(TRI_NUM) - 1;
		mUpdateTimer       = 0.0f;
	}

	void drawLifeCircle(f32 healthRatio);

protected:
	static const f32 TRI_NUM;

	int mDisplayedTriCount; // _00
	f32 mUpdateTimer;       // _04
	Vector3f _08;           // _08
	f32 mRadius;            // _14
};

/**
 * @brief TODO
 */
struct DrawNaviLifeCircle : public DrawLifeCircle {
public:
	DrawNaviLifeCircle(int p1, immut Vector3f& p2, f32 p3)
	    : DrawLifeCircle(p2, p3)
	{
		mNaviIndex = p1;
	}

	void drawLifeCircle();

protected:
	// _00-_18 = DrawLifeCircle
	int mNaviIndex; // _18, navi index? should be 0
};

struct zenGraphics {
	static void drawOneTri(immut Vector3f*, Colour&);
	static void setTevFillPolygon();
};
} // namespace zen

#endif
