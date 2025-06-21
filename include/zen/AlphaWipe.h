#ifndef _ZEN_ALPHAWIPE_H
#define _ZEN_ALPHAWIPE_H

#include "types.h"
#include "Colour.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x28.
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

	void setColour(Colour& start, Colour& end)
	{
		mStartColor = start;
		mEndColor   = end;
	}

	bool isSleep() { return mState == STATE_Inactive; }
	bool isInc() { return (mFlags & DIR_Increasing) ? TRUE : FALSE; }
	bool isDec() { return (mFlags & DIR_Decreasing) ? TRUE : FALSE; }

	statusFlag mState;   // _00
	u32 mFlags;          // _04, see directionFlag enum
	typeFlag mWipeType;  // _08
	f32 mStartWipeTimer; // _0C
	f32 mWipeDuration;   // _10
	f32 mEndWipeTimer;   // _14
	f32 mTotalDuration;  // _18
	f32 mDelayPeriod;    // _1C
	Colour mStartColor;  // _20
	Colour mEndColor;    // _24
};

} // namespace zen

#endif
