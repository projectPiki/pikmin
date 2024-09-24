#ifndef _ZEN_OGMAP_H
#define _ZEN_OGMAP_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrMapMgr {
	ogScrMapMgr();

	void start(s16);
	void update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
