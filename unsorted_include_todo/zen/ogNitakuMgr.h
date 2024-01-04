#ifndef _ZEN_OGNITAKUMGR_H
#define _ZEN_OGNITAKUMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogNitakuMgr {
	ogNitakuMgr(P2DScreen*, P2DTextBox*, P2DTextBox*, P2DTextBox*, bool, bool);
	void start();
	void cursorEnable(float);
	void cursorDisable(float);
	void update(Controller*);
};
} // namespace zen

#endif
