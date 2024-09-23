#ifndef _ZEN_OGPAUSE_H
#define _ZEN_OGPAUSE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrPauseMgr {
	ogScrPauseMgr();

	void start(bool);
	void update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
