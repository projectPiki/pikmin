#ifndef _ZEN_OGFILECHKSEL_H
#define _ZEN_OGFILECHKSEL_H

#include "types.h"

struct Controller;
struct CardQuickInfo;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct ogScrFileChkSelMgr {
	ogScrFileChkSelMgr();

	void start(bool);
	void startSave();
	int update(Controller*, CardQuickInfo&);
	void draw(Graphics&);

	// unused/inlined:
	void init();
	void startSub();

	u8 _00[0x18]; // _00, unknown
};

} // namespace zen

#endif
