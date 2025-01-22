#ifndef _ZEN_OGPAUSE_H
#define _ZEN_OGPAUSE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct ogScrPauseMgr {

	/**
	 * @brief TODO
	 */
	enum PauseStatus {
		// TODO: this
	};

	ogScrPauseMgr();

	void start(bool);
	PauseStatus update(Controller*);
	void draw(Graphics&);

	u8 _00[0x58]; // _00, unknown
};

} // namespace zen

#endif
