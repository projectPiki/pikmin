#ifndef _ZEN_BALLOONPANE_H
#define _ZEN_BALLOONPANE_H

/**
 * .obj __vt__Q23zen11BalloonPane, global
 * .4byte __RTTI__Q23zen11BalloonPane
 * .4byte 0
 * .4byte invoke__Q23zen11BalloonPaneFP7P2DPane
 * .4byte draw__15P2DPaneCallBackFP7P2DPane
 */

struct P2DPaneCallBack {
	virtual void invoke(P2DPane*); // _08
	virtual void draw(P2DPane*);   // _0C (weak)
};

namespace zen {
/**
 * @brief TODO
 */
struct BalloonPane : public P2DPaneCallBack {
	virtual void invoke(P2DPane*); // _08
};
} // namespace zen

#endif
