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
	u8 _00[0x38];
};

} // namespace zen

#endif
