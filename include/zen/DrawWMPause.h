#ifndef _ZEN_DRAWWMPAUSE_H
#define _ZEN_DRAWWMPAUSE_H

#include "types.h"

struct Graphics;
struct Controller;

namespace zen {

/**
 * @brief TODO
 */
struct DrawWMPause {
	DrawWMPause();

	void start();
	void update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
