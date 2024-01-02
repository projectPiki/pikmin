#ifndef _ZEN_TEXTCOLORCALLBACK_H
#define _ZEN_TEXTCOLORCALLBACK_H

/**
 * .obj __vt__Q23zen17TextColorCallBack, global
 * .4byte __RTTI__Q23zen17TextColorCallBack
 * .4byte 0
 * .4byte invoke__Q23zen17TextColorCallBackFP7P2DPane
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
struct TextColorCallBack : public P2DPaneCallBack {
	virtual void invoke(P2DPane *);  // _08

	TextColorCallBack(P2DPane *);
	void setTargetColor(Colour &, Colour &, f32);
};
} // namespace zen

#endif
