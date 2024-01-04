#ifndef _ZEN_STICKCALLBACK_H
#define _ZEN_STICKCALLBACK_H

/**
 * .obj __vt__Q23zen13StickCallBack, weak
 * .4byte __RTTI__Q23zen13StickCallBack
 * .4byte 0
 * .4byte invoke__Q23zen13StickCallBackFP7P2DPane
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
struct StickCallBack : public P2DPaneCallBack {
	virtual void invoke(P2DPane*); // _08
};
} // namespace zen

#endif
