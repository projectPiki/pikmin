#ifndef _ZEN_ZENCONTROLLER_H
#define _ZEN_ZENCONTROLLER_H

#include "types.h"

struct Controller;

namespace zen {

/**
 * @brief TODO
 */
struct KeyRepeat {
	void update(Controller*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct ZenController {
	ZenController(Controller*);

	void update();

	// TODO: members
};

} // namespace zen

#endif
