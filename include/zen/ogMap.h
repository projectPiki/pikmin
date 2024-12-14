#ifndef _ZEN_OGMAP_H
#define _ZEN_OGMAP_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ogScrMapMgr {
	ogScrMapMgr();

	void start(s16);
	int update(Controller*);
	void draw(Graphics&);

	u8 _00[0x30]; // _00, unknown
};

} // namespace zen

#endif
