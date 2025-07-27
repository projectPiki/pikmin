#ifndef _ZEN_SPECTRUMCURSORMGR_H
#define _ZEN_SPECTRUMCURSORMGR_H

#include "types.h"

struct P2DPane;
struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct SpectrumCursorMgr {
public:
	SpectrumCursorMgr()
	{
		mPaneCount = 0;
		mPanes     = nullptr;
		mMoveTimer = mMoveDuration = 1.0f;
		mStartPosX = mStartPosY = mTargetPosX = mTargetPosY = 0.0f;
		mScaleTimer = mScaleDuration = 1.0f;
		mStartScale = mTargetScale = 1.0f;
	}

	void update();
	void move(f32, f32, f32);
	void scale(f32, f32);
	void init(P2DScreen*, P2DPane*, u32, f32, f32);
	void initPos(f32, f32);
	void initScale(f32);

	bool checkFinish() { return mMoveTimer >= mMoveDuration && mScaleTimer >= mScaleDuration; }

protected:
	void setMirror(P2DPane*);
	u32 makeTag(u32, int);

	int mPaneCount;     // _00
	P2DPane** mPanes;   // _04
	f32 mMoveTimer;     // _08
	f32 mMoveDuration;  // _0C
	f32 mStartPosX;     // _10
	f32 mStartPosY;     // _14
	f32 mTargetPosX;    // _18
	f32 mTargetPosY;    // _1C
	f32 mScaleTimer;    // _20
	f32 mScaleDuration; // _24
	f32 mStartScale;    // _28
	f32 mTargetScale;   // _2C
};

} // namespace zen

#endif
