#ifndef _ZEN_ARROWLRCALLBACK_H
#define _ZEN_ARROWLRCALLBACK_H

/**
 * .obj __vt__Q23zen15ArrowLRCallBack, weak
 * .4byte __RTTI__Q23zen15ArrowLRCallBack
 * .4byte 0
 * .4byte invoke__Q23zen15ArrowLRCallBackFP7P2DPane
 * .4byte draw__15P2DPaneCallBackFP7P2DPane
*/

struct P2DPaneCallBack {
	virtual void invoke(P2DPane *);  // _08
	virtual void draw(P2DPane *);    // _0C (weak)
};

namespace zen {
/**
 * @brief TODO
 */
struct ArrowLRCallBack : public P2DPaneCallBack {
	virtual void invoke(P2DPane *);  // _08

};
} // namespace zen

#endif
