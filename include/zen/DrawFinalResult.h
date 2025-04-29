#ifndef _ZEN_DRAWFINALRESULT_H
#define _ZEN_DRAWFINALRESULT_H

#include "types.h"
#include "zen/DrawCM.h"
#include "zen/DrawUfoParts.h"
#include "zen/DrawSave.h"

struct Graphics;
struct Controller;
struct P2DPane;

namespace zen {

/**
 * @brief TODO
 */
struct TotalScoreRecord {
	TotalScoreRecord() { }

	// DLL inlines to do:
	void setDummy()
	{
		mParts      = 11;
		mDay        = 22;
		mPikis      = 333;
		mDeadPikis  = 4444;
		mTotalPikis = 12345678;
		_14         = 3;
		_16         = 1;
		_18         = -1;
		for (int i = 0; i < 5; i++) {
			if (i < 3) {
				mRecordNumParts[i] = i + 1;
				mRecordNumDays[i]  = i + 10;
				mRecordNumBorn[i]  = 5000 - i;
				mRecordNumDead[i]  = 10 * i;
			} else {
				mRecordNumParts[i] = -1;
				mRecordNumDays[i]  = -1;
				mRecordNumBorn[i]  = -1;
				mRecordNumDead[i]  = -1;
			}
		}
	}

	int mParts;             // _00
	int mDay;               // _04
	int mPikis;             // _08
	int mDeadPikis;         // _0C
	int mTotalPikis;        // _10
	s16 _14;                // _14
	s16 _16;                // _16
	s16 _18;                // _18
	s16 mRecordNumParts[5]; // _1A
	s16 mRecordNumDays[5];  // _24
	s16 mRecordNumBorn[5];  // _2E
	s16 mRecordNumDead[5];  // _38
};

/**
 * @brief TODO
 *
 * @note Size: 0x848.
 */
struct DrawTotalScore {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Sleep     = 0,
		MODE_Start     = 1,
		MODE_Appear    = 2,
		MODE_Operation = 3,
	};

	DrawTotalScore(TotalScoreRecord*);

	bool update(Controller*);
	void setMode(modeFlag);
	void playRankInFanfare();
	void setRankInEffect();
	void setRankInColor();

	// unused/inlined:
	void draw(Graphics&);
	void sleep();
	void start();
	void setEffect(P2DPane*, int);

	modeFlag mMode;                        // _00
	f32 _04;                               // _04
	f32 _08;                               // _08
	DrawScreen* mResultScreen;             // _0C
	EffectMgr2D* mEffectMgr2D;             // _10
	P2DPane* _14[4];                       // _10
	DrawCMbest mBest;                      // _24
	P2DTextBox* mPartsDaysRecordPanes[5];  // _40
	P2DTextBox* mLivingPikiRecordPanes[5]; // _54
	P2DTextBox* mDeadPikiRecordPanes[5];   // _68
	P2DPicture* _7C;                       // _7C
	P2DPicture* mPartsNumLeft;             // _80 - 'Parts' tens
	P2DPicture* mPartsNumRight;            // _84 - 'Parts' ones
	P2DPicture* mDaysNumLeft;              // _88 - 'Days' tens
	P2DPicture* mDaysNumRight;             // _8C - 'Days' ones
	P2DPicture* mLivingPikisThousands;     // _90 - 'Surviving Pikmin'
	P2DPicture* mLivingPikisHundreds;      // _94 - 'Surviving Pikmin'
	P2DPicture* mLivingPikisTens;          // _98 - 'Surviving Pikmin'
	P2DPicture* mLivingPikisOnes;          // _9C - 'Surviving Pikmin'
	P2DPicture* mDeadPikisThousands;       // _A0 - 'Total Pikmin Lost'
	P2DPicture* mDeadPikisHundreds;        // _A4 - 'Total Pikmin Lost'
	P2DPicture* mDeadPikisTens;            // _A8 - 'Total Pikmin Lost'
	P2DPicture* mDeadPikisOnes;            // _AC - 'Total Pikmin Lost'
	P2DPicture* _B0;                       // _B0
	P2DTextBox* _B4;                       // _B4
	P2DTextBox* _B8;                       // _B8
	P2DTextBox* _BC;                       // _BC
	P2DTextBox* _C0;                       // _C0
	char mPartsDaysRecordTexts[5][0x80];   // _C4
	char mLivingPikiRecordTexts[5][0x80];  // _344
	char mDeadPikiRecordTexts[5][0x80];    // _5CC
	TotalScoreRecord* mTotalScoreRecord;   // _844
};

/**
 * @brief TODO
 *
 * @note Size: 0x1B4.
 */
struct DrawFinalResult {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Sleep         = 0,
		MODE_Start         = 1,
		MODE_Scores        = 2,
		MODE_Parts         = 3,
		MODE_SaveStart     = 4,
		MODE_PartsFromSave = 5,
		MODE_SaveSuccess   = 6,
	};

	DrawFinalResult(TotalScoreRecord* rec = nullptr);

	bool update(Controller*);
	void draw(Graphics&);
	void start();
	void setMode(modeFlag);

	modeFlag mMode;               // _00
	DrawTotalScore* mScoreScreen; // _04
	DrawUfoParts mUfoPartsScreen; // _08
	DrawOptionSave mSaveScreen;   // _58
};

} // namespace zen

#endif
