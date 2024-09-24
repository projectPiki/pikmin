#ifndef _ZEN_OGFILECHKSEL_H
#define _ZEN_OGFILECHKSEL_H

#include "types.h"

struct Controller;
struct CardQuickInfo;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrFileChkSelMgr {
	ogScrFileChkSelMgr();

	void start(bool);
	void startSave();
	void update(Controller*, CardQuickInfo&);
	void draw(Graphics&);

	// unused/inlined:
	void init();
	void startSub();

	// TODO: members
};

} // namespace zen

#endif
