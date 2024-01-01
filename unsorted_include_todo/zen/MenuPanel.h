#ifndef _ZEN_MENUPANEL_H
#define _ZEN_MENUPANEL_H

/**
 * .obj __vt__Q23zen9MenuPanel, weak
 * .4byte __RTTI__Q23zen9MenuPanel
 * .4byte 0
 * .4byte invoke__Q23zen9MenuPanelFP7P2DPane
 * .4byte draw__15P2DPaneCallBackFP7P2DPane
*/

struct P2DPaneCallBack {
	virtual void invoke(P2DPane *);  // _08 (weak)
	virtual void draw(P2DPane *);    // _0C (weak)
};

namespace zen {
/**
 * @brief TODO
 */
struct MenuPanel : public P2DPaneCallBack {
	virtual void invoke(P2DPane *);  // _08 (weak)

	void update(P2DPane *);
};
} // namespace zen

#endif
