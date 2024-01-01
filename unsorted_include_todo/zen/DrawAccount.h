#ifndef _ZEN_DRAWACCOUNT_H
#define _ZEN_DRAWACCOUNT_H

/**
 * .obj __vt__Q23zen11DrawAccount, global
 * .4byte __RTTI__Q23zen11DrawAccount
 * .4byte 0
 * .4byte update__Q23zen11DrawAccountFv
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
struct DrawAccount : public DrawScreen {
	virtual void update();  // _08

	DrawAccount();
	void draw(Graphics &);
	void start(zen::AccountData &);
};
} // namespace zen

#endif
