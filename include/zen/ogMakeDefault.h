#ifndef _ZEN_OGMAKEDEFAULT_H
#define _ZEN_OGMAKEDEFAULT_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrMakeDefaultMgr {
	ogScrMakeDefaultMgr();

	void start();
	void update(Controller*);
	void draw(Graphics&);
	void checkTypingAll();

	// unused/inlined:

	// TODO: members
};

} // namespace zen

#endif
