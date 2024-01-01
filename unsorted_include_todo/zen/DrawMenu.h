#ifndef _ZEN_DRAWMENU_H
#define _ZEN_DRAWMENU_H

/**
 * .obj __vt__Q23zen8DrawMenu, weak
 * .4byte __RTTI__Q23zen8DrawMenu
 * .4byte 0
 * .4byte update__Q23zen10DrawScreenFv
 * .4byte draw__Q23zen10DrawScreenFv
*/

namespace zen {
struct DrawScreen {
	virtual void update();  // _08
	virtual void draw();    // _0C
};
} // namespace zen

namespace zen {
/**
 * @brief TODO
 */
struct DrawMenu : public DrawScreen {

};
} // namespace zen

#endif
