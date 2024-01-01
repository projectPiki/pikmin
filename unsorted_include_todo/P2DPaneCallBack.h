#ifndef _P2DPANECALLBACK_H
#define _P2DPANECALLBACK_H

/**
 * .obj __vt__15P2DPaneCallBack, weak
 * .4byte __RTTI__15P2DPaneCallBack
 * .4byte 0
 * .4byte 0
 * .4byte draw__15P2DPaneCallBackFP7P2DPane
*/

/**
 * @brief TODO
 */
struct P2DPaneCallBack {
	virtual void _08() = 0;        // _08
	virtual void draw(P2DPane *);  // _0C (weak)

};

#endif
