#ifndef _ZEN_OGRESULT_H
#define _ZEN_OGRESULT_H

#include "types.h"

struct P2DPane;
struct Controller;
struct P2DPicture;
struct Graphics;
struct P2DScreen;
struct P2DTextBox;

namespace zen {

struct DrawCMbest;
struct ogSaveMgr;
struct ogScrMessageMgr;
struct ogGraphMgr;
struct PikaAlphaMgr;

/**
 * @brief TODO
 */
enum EnumResult {

};

/**
 *
 * @note Size: 0x55C.
 */
struct ogScrResultMgr {
public:
	enum returnStatusFlag {
		Status_NULL = -1,
		Status_0    = 0,
		Status_3    = 3,
		Status_4    = 4,
		Status_5    = 5,
		Status_6    = 6,
		Status_7    = 7,
		Status_8    = 8,
		// TODO: this
	};

	ogScrResultMgr();
	ogScrResultMgr(EnumResult*);

	returnStatusFlag update(Controller*);
	void start();
	void draw(Graphics&);

private:
	void ogScrResultMgrSub();
	void check1000(int, P2DPane*, P2DPane*, int);
	void setEnumResultTable(EnumResult*);
	void StartRESULT();

	int _00;                         // _00
	returnStatusFlag mStatus;        // _04
	returnStatusFlag mStatus2;       // _08
	P2DScreen* mMainScreen;          // _0C
	int _10;                         // _10
	ogScrMessageMgr* mMesgScreen;    // _14
	PikaAlphaMgr* mAlphaMgr;         // _18
	int _1C;                         // _1C
	P2DPane* mPaneRoot;              // _20
	ogSaveMgr* mSaveMgr;             // _24
	ogGraphMgr* mGraphMgr;           // _28
	DrawCMbest* mCMBestData;         // _2C
	P2DScreen* mBlackScreen;         // _30
	P2DPicture* mBlackPane;          // _34
	P2DPane* _38;                    // _38
	P2DPane* _3C;                    // _3C
	P2DPane* _40;                    // _40
	P2DPane* _44;                    // _44
	P2DPane* _48;                    // _48
	P2DPane* _4C;                    // _4C
	P2DPane* mPaneRedPikis;          // _50
	P2DPane* mPaneBluePikis;         // _54
	P2DPane* mPaneYellowPikis;       // _58
	P2DPane* _5C;                    // _5C
	P2DPane* mPaneDaysL;             // _60
	P2DPane* mPaneDaysC;             // _64
	P2DPane* mPaneDaysR;             // _67
	P2DPane* mPaneDaysLeftL;         // _6C
	P2DPane* mPaneDaysLeftC;         // _70
	P2DPane* mPaneDaysLeftR;         // _74
	P2DPane* mPanePartsLeftL;        // _78
	P2DPane* mPanePartsLeftC;        // _7C
	P2DPane* mPanePartsLeftR;        // _80
	P2DPane* mPaneData;              // _84
	P2DPane* mPaneFileNum1;          // _88
	P2DPane* mPaneFileNum2;          // _8C
	P2DPane* mPaneFileNum3;          // _90
	P2DTextBox* _94;                 // _94
	P2DPane* _98;                    // _98
	P2DPane* _9C;                    // _9C
	P2DPane* _A0;                    // _A0
	P2DPane* _A4;                    // _A4
	P2DPane* _A8;                    // _A8
	P2DPane* _AC;                    // _AC
	P2DPane* _B0;                    // _B0
	P2DPane* _B4;                    // _B4
	P2DPane* _B8;                    // _B8
	P2DPane* _BC;                    // _BC
	P2DPane* _C0;                    // _C0
	P2DPane* _C4;                    // _C4
	P2DPane* _C8;                    // _C8
	P2DPane* _CC;                    // _CC
	P2DPane* _D0;                    // _D0
	P2DPane* _D4;                    // _D4
	P2DPane* _D8;                    // _D8
	P2DPane* _DC;                    // _DC
	f32 mWaitTimer;                  // _E0
	f32 mSaveWaitTimer;              // _E4
	s16 mBgAlpha;                    // _E8
	s16 mGraphAlpha;                 // _EA
	int mRedPikis;                   // _EC
	int mBluePikis;                  // _F0
	int mYellowsPikis;               // _F4
	int mTotalPikis;                 // _F8
	int mBornPikis;                  // _FC
	int mDeadPikis;                  // _100
	int mVictimPikis;                // _104
	int mSproutedPikis;              // _108
	int mPikisLostToBattle;          // _10C
	int mLeftBehindPikis;            // _110
	int _114;                        // _114
	int _118;                        // _118
	int mCurrentParts;               // _11C
	int mCurrentDay;                 // _120
	int mRemainingParts;             // _124
	int mRemainingDays;              // _128
	int mTotalParts;                 // _12C
	int mTotalDays;                  // _130
	int mPowerupNum;                 // _134
	s16 mStartWaitDelay;             // _138
	bool mHasBlue;                   // _13A
	bool mHasRed;                    // _13B
	bool mHasYellow;                 // _13C
	char _13D[16];                   // _13D
	immut char* mDiaryPathList[256]; // _150
	immut char** mPageInfoPtr;       // _550
	int _554;                        // _554
	int mSaveStatus;                 // _558
};

extern immut char* bloFile_Res_Table[];

} // namespace zen

#endif
