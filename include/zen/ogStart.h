#ifndef _ZEN_OGSTART_H
#define _ZEN_OGSTART_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrStartMgr {
	ogScrStartMgr();

	void start();
	void stop();
	void update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
