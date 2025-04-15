#ifndef _ZEN_ALPHAWIPE_H
#define _ZEN_ALPHAWIPE_H

#include "types.h"
#include "Colour.h"

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
		TYPE_Normal  = 0,
		TYPE_Reverse = 1,
	};

	/**
	 * @brief TODO
	 */
	enum statusFlag {
		STATE_Inactive = 0,
		STATE_Active   = 1,
	};

	/**
	 * @brief TODO
	 */
	enum directionFlag {
		DIR_Increasing = 1 << 0, // 0x1
		DIR_Decreasing = 1 << 1, // 0x2
	};

	AlphaWipe();

	void update();
	void draw(Graphics&);
	void start(f32, f32, typeFlag);

	// DLL inlines to do:
	void setColour(Colour&, Colour&);
	bool isInc();
	bool isDec();
	bool isSleep();

	statusFlag mState;   // _00
	u32 mFlags;          // _04, see directionFlag enum
	typeFlag mWipeType;  // _08
	f32 mStartWipeTimer; // _0C
	f32 mWipeDuration;   // _10
	f32 mEndWipeTimer;   // _14
	f32 _18;             // _18
	f32 mDelayPeriod;    // _1C
	Colour mStartColor;  // _20
	Colour mEndColor;    // _24
};

} // namespace zen

#endif
