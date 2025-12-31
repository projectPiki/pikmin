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
	RESFLAG_NULL                    = -1,
	RESFLAG_DOC_END                 = 0,
	RESFLAG_EndFirstDay             = 1,
	RESFLAG_FirstVisitForest        = 3,
	RESFLAG_UnlockCave              = 5,
	RESFLAG_FirstVisitCave          = 6,
	RESFLAG_UnlockYakushima         = 7,
	RESFLAG_FirstVisitYakushima     = 8,
	RESFLAG_FinalDay                = 10,
	RESFLAG_Collect25Parts          = 11,
	RESFLAG_Collect29Parts          = 12,
	RESFLAG_OlimarDown              = 13,
	RESFLAG_PikminExtinction        = 14,
	RESFLAG_CollectAllParts         = 15, // unused
	RESFLAG_YellowWithBomb          = 17,
	RESFLAG_MeetBluePikmin          = 18,
	RESFLAG_PikminRouting           = 19,
	RESFLAG_OlimarDaydream          = 20,
	RESFLAG_Collect15Parts          = 21,
	RESFLAG_PikminLeftBehind        = 23,
	RESFLAG_PikminBombDeath         = 24,
	RESFLAG_Collect10Parts          = 26,
	RESFLAG_UnusedControls1         = 27,
	RESFLAG_UnusedControls2         = 29,
	RESFLAG_UnusedControls3         = 31,
	RESFLAG_BrokenBridge            = 32,
	RESFLAG_PikminSeeds             = 33,
	RESFLAG_PikminSeedStageUp       = 35,
	RESFLAG_Onyons                  = 36,
	RESFLAG_MeetYellowPikminNoBomb  = 37,
	RESFLAG_BluePikminWaterImmunity = 38, // unused
	RESFLAG_PikminOnFire            = 39,
	RESFLAG_Dororo                  = 40, // Smoky Progg
	RESFLAG_Swallow                 = 41, // Bulborb
	RESFLAG_Kinoko                  = 42, // Puffstool
	RESFLAG_Kogane                  = 43, // Flint Beetle
	RESFLAG_Mizinko                 = 44, // Honeywisp
	RESFLAG_Pom                     = 45, // Candypop Bud
	RESFLAG_Spider                  = 46, // Beady Long Legs
	RESFLAG_Beatle                  = 47, // Armored Cannon Beetle
	RESFLAG_Snake                   = 48, // Burrowing Snagret
	RESFLAG_King                    = 49, // Emperor Bulblax
	RESFLAG_Slime                   = 50, // Goolix
	RESFLAG_Miurin                  = 51, // Mamuta
	RESFLAG_Kabekui                 = 52, // Sheargrub
	RESFLAG_Tank                    = 53, // Fiery Blowhog
	RESFLAG_Shell                   = 54, // Pearly Clamclamp
	RESFLAG_Collec                  = 55, // Breadbug
	RESFLAG_Mar                     = 56, // Puffy Blowhog
	RESFLAG_Otimoti                 = 57, // Wollywog
	RESFLAG_Misc1                   = 58,
	RESFLAG_Misc2                   = 59,
	RESFLAG_Misc3                   = 60,
	RESFLAG_Misc4                   = 61,
	RESFLAG_Misc5                   = 62,
	RESFLAG_Misc6                   = 63,
	RESFLAG_Misc7                   = 64,
	RESFLAG_Misc8                   = 65,
	RESFLAG_Misc9                   = 66,
	RESFLAG_Misc10                  = 67,
	RESFLAG_Misc11                  = 68,
	RESFLAG_Misc12                  = 69,
	RESFLAG_Misc13                  = 70,
	RESFLAG_Misc14                  = 71,
	RESFLAG_Misc15                  = 72,
	RESFLAG_Misc16                  = 73,
	RESFLAG_Misc17                  = 74,
	RESFLAG_Misc18                  = 75,
	RESFLAG_Misc19                  = 76,
	RESFLAG_Misc20                  = 77,
	RESFLAG_Misc21                  = 78,
	RESFLAG_Misc22                  = 79,
	RESFLAG_Misc23                  = 80,
	RESFLAG_Misc24                  = 81,
	RESFLAG_Misc25                  = 82,
	RESFLAG_Misc26                  = 83,
	RESFLAG_Misc27                  = 84,
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
