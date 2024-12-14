#ifndef _ZEN_OGTEST_H
#define _ZEN_OGTEST_H

#include "types.h"
#include "Section.h"
#include "Camera.h"

struct Font;

namespace zen {

struct ogDrawSelectDiary;
struct ogScrFileChkSelMgr;
struct ogScrMapMgr;
struct ogScrMemChkMgr;
struct ogScrPauseMgr;
struct ogScrResultMgr;
struct ogScrStartMgr;
struct ogScrTitleMgr;
struct ogScrTotalScoreMgr;
struct ogScrTutorialMgr;
struct ZenController;

/**
 * @brief TODO
 */
enum TestMode {
	TESTMODE_Title      = 0,
	TESTMODE_Tutorial   = 1,
	TESTMODE_Save       = 2,
	TESTMODE_Map        = 3,
	TESTMODE_MemChk     = 4,
	TESTMODE_FileChkSel = 5,
	TESTMODE_Diary      = 6,
	TESTMODE_Result     = 7,
	TESTMODE_Pause      = 8,
	TESTMODE_TotalScore = 9,
	TESTMODE_Start      = 10,

	TESTMODE_Unused11 = 11,
	TESTMODE_Unk12    = 12,
	TESTMODE_INACTIVE = 14,

	TESTMODE_MIN = TESTMODE_Title,
	TESTMODE_MAX = TESTMODE_Start, // idk why this is the max
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C0.
 */
struct OgTestScreen : public Node {
	OgTestScreen();

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	void modeSelectSub();

	// _00     = VTBL
	// _00-_20 = Node
	u32 _20;                             // _20, unknown
	u32 mActiveMode;                     // _24, active mode, see TestMode enum
	Controller* mController;             // _28
	ZenController* mZenController;       // _2C
	Font* mFont;                         // _30
	Camera mTestCamera;                  // _34
	s16 mSelectedMode;                   // _37C, mode setting cursor is on, see TestMode enum
	s16 mTutorialMode;                   // _37E
	s16 mDiaryMode;                      // _380
	u8 _382[0x2];                        // _382, unknown
	s16 mMemChkMode;                     // _384
	s16 mMapMode;                        // _386
	s16 mSaveMode;                       // _388
	s16 _38A;                            // _38A
	bool mPauseMode;                     // _38C
	bool mFileChkSelMode;                // _38D
	bool mTitleMode;                     // _38E
	ogScrResultMgr* mResultMgr;          // _390
	ogScrTitleMgr* mTitleMgr;            // _394
	ogScrTutorialMgr* mTutorialMgr;      // _398
	ogScrPauseMgr* mPauseMgr;            // _39C
	ogScrMapMgr* mMapMgr;                // _3A0
	ogScrMemChkMgr* mMemChkMgr;          // _3A4
	ogScrFileChkSelMgr* mFileChkSelMgr;  // _3A8
	ogScrTotalScoreMgr* mTotalScoreMgr;  // _3AC
	ogScrStartMgr* mStartMgr;            // _3B0
	ogDrawSelectDiary* mDrawSelectDiary; // _3B4
	u8 _3B8[0x8];                        // _3B8, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct OgTestSection : public Section {
	OgTestSection();

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

} // namespace zen

#endif
