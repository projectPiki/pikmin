#ifndef _ZEN_DRAWACCOUNT_H
#define _ZEN_DRAWACCOUNT_H

#include "types.h"
#include "zen/DrawCommon.h"

class Graphics;

namespace zen {

/**
 * @brief TODO
 */
class AccountData {
public:
	AccountData()
	{
		mMinPikiNum  = 0;
		mMaxPikiNum  = 0;
		mDeadPikiNum = 0;
		mDeadTekiNum = 0;
		mPelletNum   = 0;
	}
	AccountData(s16 minPiki, s16 maxPiki, s16 deadPiki, s16 deadTeki, s16 pellets)
	{
		mMinPikiNum  = minPiki;
		mMaxPikiNum  = maxPiki;
		mDeadPikiNum = deadPiki;
		mDeadTekiNum = deadTeki;
		mPelletNum   = pellets;
	}

	short mMinPikiNum;  // _00
	short mMaxPikiNum;  // _02
	short mDeadPikiNum; // _04
	short mDeadTekiNum; // _06
	short mPelletNum;   // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x120.
 */
class DrawAccount : public DrawScreen {
public:
	DrawAccount();

	virtual void update(); // _08

	void start(AccountData&);
	void draw(Graphics&);

protected:
	// _00-_100 = DrawScreen
	f32 mAppearTimer;    // _100
	f32 mAppearDuration; // _104
	AccountData mData;   // _108
	P2DPane* mRootPane;  // _114
	P2DPane* mBlakPane;  // _118
	bool mIsVisible;     // _11C
};

} // namespace zen

extern zen::DrawAccount* accountWindow;

#endif
