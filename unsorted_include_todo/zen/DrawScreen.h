#ifndef _ZEN_DRAWSCREEN_H
#define _ZEN_DRAWSCREEN_H

/**
 * .obj __vt__Q23zen10DrawScreen, global
 * .4byte __RTTI__Q23zen10DrawScreen
 * .4byte 0
 * .4byte update__Q23zen10DrawScreenFv
 * .4byte draw__Q23zen10DrawScreenFv
 */

namespace zen {
/**
 * @brief TODO
 */
struct DrawScreen {
	virtual void update(); // _08
	virtual void draw();   // _0C

	DrawScreen(char*, P2DGrafContext*, bool, bool);
};
} // namespace zen

#endif
