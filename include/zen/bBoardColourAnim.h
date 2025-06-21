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
			u8 _m0 : 1;                // Unused
			u8 mRotationType : 3;      // Sets rotation axis: 0=Y, 1=X, 2=Z, 3=XY, 4=XZ, 5=YZ, 6=XYZ
			u8 _m4 : 1;                // Unused
			u8 mOrientationSource : 1; // 0 = use velocity vector, 1 = use position vector for particle orientation
			u8 mIsDoubleSided : 1;     // 0 = single-sided (4 vertices), 1 = render particles double-sided (8 vertices)
			u8 _m7 : 1;                // Unused
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
