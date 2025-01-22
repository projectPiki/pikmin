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

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	DrawWMPause();

	void start();
	returnStatusFlag update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
