#ifndef _ZEN_ALPHAWIPE_H
#define _ZEN_ALPHAWIPE_H

#include "types.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct AlphaWipe {

	/**
	 * @brief TODO
	 */
	enum typeFlag {
		// TODO: this
	};

	AlphaWipe();

	void update();
	void draw(Graphics&);
	void start(f32, f32, typeFlag);

	// TODO: members
};

} // namespace zen

#endif
