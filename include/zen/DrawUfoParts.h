#ifndef _ZEN_DRAWUFOPARTS_H
#define _ZEN_DRAWUFOPARTS_H

#include "types.h"

struct Graphics;
struct Controller;

namespace zen {

/**
 * @brief TODO
 */
struct DrawUfoParts {
	DrawUfoParts();

	bool update(Controller*);
	void draw(Graphics&);
	void sleep();
	void start();
	void operation();
	void dataSet();

	// TODO: members
};

} // namespace zen

#endif
