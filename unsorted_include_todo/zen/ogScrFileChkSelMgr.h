#ifndef _ZEN_OGSCRFILECHKSELMGR_H
#define _ZEN_OGSCRFILECHKSELMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrFileChkSelMgr {
	ogScrFileChkSelMgr();
	void start(bool);
	void startSave();
	void update(Controller*, CardQuickInfo&);
	void draw(Graphics&);
};
} // namespace zen

#endif
