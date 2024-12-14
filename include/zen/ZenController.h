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

	static f32 repeatTime;

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x6C.
 */
struct ZenController {
	ZenController(Controller*);

	void update();

	inline bool isPressed(u32 button) { return _04 & button; }
	inline void setController(Controller* controller) { mController = controller; }

	Controller* mController; // _00
	u32 _04;                 // _04, probably some form of input
	u8 _08[0x6C - 0x8];      // _08, unknown
};

} // namespace zen

#endif
