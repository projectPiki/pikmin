#ifndef _ZEN_DRAWCMCSMENU_H
#define _ZEN_DRAWCMCSMENU_H

/**
 * .obj __vt__Q23zen12DrawCMCSmenu, weak
 * .4byte __RTTI__Q23zen12DrawCMCSmenu
 * .4byte 0
 * .4byte update__Q23zen10DrawScreenFv
 * .4byte draw__Q23zen10DrawScreenFv
 * .4byte draw__Q23zen12DrawMenuBaseFR8Graphics
 * .4byte update__Q23zen12DrawCMCSmenuFP10Controller
 * .4byte start__Q23zen12DrawCMCSmenuFv
 * .4byte modeDefault__Q23zen12DrawMenuBaseFP10Controller
 * .4byte modeSleep__Q23zen12DrawMenuBaseFP10Controller
 * .4byte modeOperation__Q23zen12DrawMenuBaseFP10Controller
 * .4byte setModeFunc__Q23zen12DrawCMCSmenuFi
*/

namespace zen {
struct DrawScreen {
	virtual void update();  // _08
	virtual void draw();    // _0C
};
} // namespace zen

namespace zen {
struct DrawMenuBase {
	virtual void _08() = 0;                    // _08
	virtual void _0C() = 0;                    // _0C
	virtual void draw(Graphics &);             // _10
	virtual void update(Controller *);         // _14
	virtual void start();                      // _18
	virtual void modeDefault(Controller *);    // _1C
	virtual void modeSleep(Controller *);      // _20
	virtual void modeOperation(Controller *);  // _24
};
} // namespace zen

namespace zen {
/**
 * @brief TODO
 */
struct DrawCMCSmenu : public DrawScreen, public DrawMenuBase {
	virtual void update(Controller *);  // _14
	virtual void start();               // _18
	virtual void setModeFunc(int);      // _28

	void modeAppear(Controller *);
};
} // namespace zen

#endif
