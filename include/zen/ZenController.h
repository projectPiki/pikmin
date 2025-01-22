#ifndef _ZEN_ZENCONTROLLER_H
#define _ZEN_ZENCONTROLLER_H

#include "types.h"

struct Controller;

namespace zen {

/**
 * @brief TODO
 */
struct KeyRepeat {
	bool update(Controller*);

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

	/* Inlined:
	    void setRepeatTime(f32);
	*/

	inline BOOL keyRepeat(u32 button) { return mRepeatInput & button; }
	inline void setContPtr(Controller* controller) { mController = controller; }

	Controller* mController; // _00
	u32 mRepeatInput;        // _04, probably some form of input
	u8 _08[0x6C - 0x8];      // _08, unknown
};

} // namespace zen

#endif
