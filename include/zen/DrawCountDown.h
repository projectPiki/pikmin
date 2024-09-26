#ifndef _ZEN_DRAWCOUNTDOWN_H
#define _ZEN_DRAWCOUNTDOWN_H

#include "types.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct DrawCountDown {
	DrawCountDown();

	void setRate(f32, f32, f32);
	void init(f32, f32, f32*);
	void update();
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
