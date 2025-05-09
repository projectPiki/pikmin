#ifndef _ZEN_BBOARDCOLOURANIM_H
#define _ZEN_BBOARDCOLOURANIM_H

#include "types.h"

struct Colour;

namespace zen {

/*
 * @brief TODO
 */
struct bBoardColourAnimData {
	bBoardColourAnimData()
	{
		mBlendMode       = 0;
		mDuration        = 0;
		mFlags.all       = 0;
		mMaxFrame        = 0;
		mFrameThresholds = 0;
		mPrimColors      = 0;
		mEnvColors       = 0;
	}

	void set(u8*);

	// unused/inlined:
	~bBoardColourAnimData() { }

	u8 mBlendMode; // _00
	u8 mDuration;  // _01
	union {
		struct {
			u8 _m0 : 1;
			u8 _m1 : 3;
			u8 _m4 : 1;
			u8 _m5 : 1;
			u8 _m6 : 1;
			u8 _m7 : 1;
		} bits;
		u8 all;
	} mFlags;              // _02
	u8 mMaxFrame;          // _03
	f32* mFrameThresholds; // _04
	Colour* mPrimColors;   // _08
	Colour* mEnvColors;    // _0C
};

/**
 * @brief TODO
 */
struct bBoardColourAnim {
	void update(f32, Colour*, Colour*);
	void init(zen::bBoardColourAnimData* data, s16 lifeTime)
	{
		mProgress     = 0.0f;
		mCurrentFrame = 0;
		mAnimData     = data;
		if (mAnimData) {
			if (mAnimData->mFlags.all) {
				mDuration = lifeTime;
			} else {
				mDuration = mAnimData->mDuration;
			}
		} else {
			mDuration = lifeTime;
		}
	}

	f32 mProgress;                   // _00
	u8 mCurrentFrame;                // _04
	s16 mDuration;                   // _06
	bBoardColourAnimData* mAnimData; // _08
};

} // namespace zen

#endif
