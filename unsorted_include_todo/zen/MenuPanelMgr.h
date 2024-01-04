#ifndef _ZEN_MENUPANELMGR_H
#define _ZEN_MENUPANELMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct MenuPanelMgr {
	void setCallBack(P2DScreen*, P2DPane*);
	void update();
	void checkFinish();
};
} // namespace zen

#endif
