#ifndef _ZEN_OGTOTALSCORE_H
#define _ZEN_OGTOTALSCORE_H

#include "types.h"
#include "zen/DrawCM.h"
#include "zen/DrawFinalResult.h"

struct Controller;
struct Graphics;
struct P2DPane;
struct P2DScreen;

namespace zen {

struct EffectMgr2D;
struct ZenController;
struct DrawCMbest;
struct TotalScoreRecord;

/**
 * @brief TODO
 *
 * @note Why make a whole new identical type when TotalScoreRecord exists.
 */
struct TotalScoreType {
	TotalScoreType() { }

	void setDummy()
	{
		mParts         = 11;
		mDay           = 22;
		mPikis         = 333;
		mDeadPikis     = 4444;
		mTotalPikis    = 5555555;
		mPartsDaysRank = 1;
		mBornPikisRank = 1;
		mDeadPikisRank = 1;
		for (int i = 0; i < 5; i++) {
			mRecordNumParts[i] = i + 1;
			mRecordNumDays[i]  = i + 10;
			mRecordNumBorn[i]  = 5000 - i;
			mRecordNumDead[i]  = 10 * i;
		}
	}

	int mParts;             // _00
	int mDay;               // _04
	int mPikis;             // _08
	int mDeadPikis;         // _0C
	int mTotalPikis;        // _10
	s16 mPartsDaysRank;     // _14
	s16 mBornPikisRank;     // _16
	s16 mDeadPikisRank;     // _18
	s16 mRecordNumParts[5]; // _1A
	s16 mRecordNumDays[5];  // _24
	s16 mRecordNumBorn[5];  // _2E
	s16 mRecordNumDead[5];  // _38
};

/**
 * @brief TODO
 *
 * @note Size: 0x830.
 */
struct ogScrTotalScoreMgr {
public:
	/**
	 * @brief TODO
	 */
	enum TotalScoreStatus {
		TOTALSCORE_Sleep     = -1,
		TOTALSCORE_Operation = 0,
		TOTALSCORE_FadeIn    = 1,
		TOTALSCORE_FadeOut   = 2,
		TOTALSCORE_End       = 3,
	};

	ogScrTotalScoreMgr(TotalScoreType*);

	void start();
	TotalScoreStatus update(Controller*);
	void draw(Graphics&);

private:
	void setEffect(P2DPane*, int);
	void setRankInEffect();
	void setRankInColor();

	TotalScoreStatus mState;              // _00
	P2DScreen* mScreen;                   // _04
	f32 mFrameTimer;                      // _08
	P2DTextBox* mPartDayRecordTexts[5];   // _0C
	P2DTextBox* mBornRecordTexts[5];      // _20
	P2DTextBox* mDeadRecordTexts[5];      // _34
	P2DPicture* mNewRecordDefaultPane;    // _48
	P2DPicture* mPartsDigitsTens;         // _4C
	P2DPicture* mPartsDigitsOnes;         // _50
	P2DPicture* mDaysDigitsTens;          // _54
	P2DPicture* mDaysDigitsOnes;          // _58
	P2DPicture* mBornDigitsThousands;     // _5C
	P2DPicture* mBornDigitsHundreds;      // _60
	P2DPicture* mBornDigitsTens;          // _64
	P2DPicture* mBornDigitsOnes;          // _68
	P2DPicture* mDeadDigitsThousands;     // _6C
	P2DPicture* mDeadDigitsHundreds;      // _70
	P2DPicture* mDeadDigitsTens;          // _74
	P2DPicture* mDeadDigitsOnes;          // _78
	P2DPicture* mPartsDaysSlash;          // _7C
	P2DPane* mPartsEffectPane;            // _80
	P2DPane* mDaysEffectPane;             // _84
	P2DPane* mBornEffectPane;             // _88
	P2DPane* mDeadEffectPane;             // _8C
	P2DTextBox* mPartsHeading;            // _90
	P2DTextBox* mDaysHeading;             // _94
	P2DTextBox* mBornHeading;             // _98
	P2DTextBox* mDeadHeading;             // _9C
	char mPartsDaysRecordStrings[5][128]; // _A0
	char mBornRecordStrings[5][128];      // _320
	char mDeadRecordStrings[5][128];      // _5A0
	TotalScoreType* mScores;              // _820
	TotalScoreType* mDummyScores;         // _824
	EffectMgr2D* mEfxMgr2D;               // _828
	DrawCMbest* mBest;                    // _82C
};

} // namespace zen

#endif
