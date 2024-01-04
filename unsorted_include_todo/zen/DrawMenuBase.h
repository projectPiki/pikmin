#ifndef _ZEN_DRAWMENUBASE_H
#define _ZEN_DRAWMENUBASE_H

/**
 * .obj __vt__Q23zen12DrawMenuBase, global
 * .4byte __RTTI__Q23zen12DrawMenuBase
 * .4byte 0
 * .4byte update__Q23zen10DrawScreenFv
 * .4byte draw__Q23zen10DrawScreenFv
 * .4byte draw__Q23zen12DrawMenuBaseFR8Graphics
 * .4byte update__Q23zen12DrawMenuBaseFP10Controller
 * .4byte start__Q23zen12DrawMenuBaseFv
 * .4byte modeDefault__Q23zen12DrawMenuBaseFP10Controller
 * .4byte modeSleep__Q23zen12DrawMenuBaseFP10Controller
 * .4byte modeOperation__Q23zen12DrawMenuBaseFP10Controller
 * .4byte setModeFunc__Q23zen12DrawMenuBaseFi
 */

namespace zen {
struct DrawScreen {
	virtual void update(); // _08
	virtual void draw();   // _0C
};
} // namespace zen

namespace zen {
/**
 * @brief TODO
 */
struct DrawMenuBase : public DrawScreen {
	virtual void draw(Graphics&);            // _10
	virtual void update(Controller*);        // _14
	virtual void start();                    // _18
	virtual void modeDefault(Controller*);   // _1C
	virtual void modeSleep(Controller*);     // _20
	virtual void modeOperation(Controller*); // _24
	virtual void setModeFunc(int);           // _28

	DrawMenuBase(char*, bool, bool);
	void init(int);
};
} // namespace zen

#endif
