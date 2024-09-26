#ifndef _ZEN_MENUPANELMGR_H
#define _ZEN_MENUPANELMGR_H

#include "types.h"
#include "zen/DrawCommon.h"

struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct MenuPanel : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08 (weak)

	void update(P2DPane*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct MenuPanelMgr {

	void setCallBack(P2DScreen*, P2DPane*);
	void update();
	void checkFinish();

	// unused/inlined:
	void operation();

	// TODO: members
};

} // namespace zen

#endif
