#ifndef _ZEN_ZENCONTROLLER_H
#define _ZEN_ZENCONTROLLER_H

#include "types.h"

struct Controller;

namespace zen {

/**
 * @brief TODO
 */
struct KeyRepeat {
	KeyRepeat(u32 button)
	{
		mButton = button;
		_04     = 0.0f;
		_08     = repeatTime;
		_0C     = 0;
	}

	bool update(Controller*);

	static f32 repeatTime;

	u32 mButton; // _00
	f32 _04;     // _04
	f32 _08;     // _08
	u8 _0C;      // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x6C.
 */
struct ZenController {
	ZenController(Controller*);

	void update();

	bool keyRepeat(u32 button) { return mRepeatInput & button; }
	void setContPtr(Controller* controller) { mController = controller; }

	// DLL inline to do:
	void setRepeatTime(f32 time) { KeyRepeat::repeatTime = time; }

	Controller* mController;    // _00
	u32 mRepeatInput;           // _04, probably some form of input
	KeyRepeat* mKeyRepeats[25]; // _08
};

} // namespace zen

#endif
