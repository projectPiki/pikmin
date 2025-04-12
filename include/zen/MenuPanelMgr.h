#ifndef _ZEN_MENUPANELMGR_H
#define _ZEN_MENUPANELMGR_H

#include "types.h"
#include "zen/DrawCommon.h"

struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct MenuPanelMgr {

	void setCallBack(P2DScreen*, P2DPane*);
	bool update();
	bool checkFinish();

	// unused/inlined:
	void operation();

	// TODO: members
};

/**
 * @brief TODO
 */
struct MenuPanel : public P2DPaneCallBack {
	MenuPanel(P2DPane*, P2DPane*, MenuPanelMgr*); // DLL, to do

	virtual bool invoke(P2DPane*); // _08 (weak)

	void update(P2DPane*);

	// TODO: members
};

} // namespace zen

#endif
