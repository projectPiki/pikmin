#include "zen/ogTest.h"
#include "Camera.h"
#include "Controller.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "FlowController.h"
#include "Font.h"
#include "Geometry.h"
#include "Graphics.h"
#include "MemoryCard.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "zen/ZenController.h"
#include "zen/ogDiary.h"
#include "zen/ogFileChkSel.h"
#include "zen/ogMap.h"
#include "zen/ogMemChk.h"
#include "zen/ogMessage.h"
#include "zen/ogPause.h"
#include "zen/ogResult.h"
#include "zen/ogStart.h"
#include "zen/ogSub.h"
#include "zen/ogTitle.h"
#include "zen/ogTotalScore.h"
#include "zen/ogTutorial.h"
#include <stdio.h>

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("OgTestSection")

namespace zen {

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
 * @note Size: 0x3C0 (0x3BC in USA demo).
 */
struct OgTestScreen : public Node {
public:
	OgTestScreen();

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

private:
	void modeSelectSub();

	// _00     = VTBL
	// _00-_20 = Node
	u32 _20;                 // _20, unknown
	u32 mActiveMode;         // _24, active mode, see TestMode enum
	Controller* mController; // _28
#if defined(VERSION_PIKIDEMO)
#else
	ZenController* mZenController; // _2C
#endif
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
	bool mChallengeModePause;            // _38C
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
 * @todo: Documentation
 */
OgTestScreen::OgTestScreen()
{
	setName("OgTestScreen");

	// This section uses `SeSystem` without constructing it.
#if defined(BUGFIX)
	seSystem = new SeSystem();
#endif

	mController         = new Controller();
	_20                 = 0;
	mActiveMode         = TESTMODE_INACTIVE;
	mTutorialMode       = 0;
	mDiaryMode          = 0;
	mMemChkMode         = 0;
	mMapMode            = 0;
	mSaveMode           = 0;
	_38A                = 0;
	mChallengeModePause = false;
	mFileChkSelMode     = false;
	mSelectedMode       = TESTMODE_Title;
	Texture* fontTex    = gsys->loadTexture("bigFont.bti", true);
	mFont               = new Font();
	mFont->setTexture(fontTex, 21, 42);
	gsys->setFade(1.0f, 3.0f);

	for (int i = 0; i < 100; i++) {
		setSpecialNumber(i, -123);
	}

	int before = gsys->getHeap(gsys->mActiveHeapIdx)->getFree();
	mMemChkMgr = new ogScrMemChkMgr();
	int size   = before - gsys->getHeap(gsys->mActiveHeapIdx)->getFree();

	PRINT("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	PRINT("Target Mgr. MemSize = %d\n", size);
	PRINT("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

	mPauseMgr        = new ogScrPauseMgr();
	mResultMgr       = new ogScrResultMgr();
	mTitleMgr        = new ogScrTitleMgr();
	mTutorialMgr     = new ogScrTutorialMgr();
	mMapMgr          = new ogScrMapMgr();
	mDrawSelectDiary = new ogDrawSelectDiary();
	mFileChkSelMgr   = new ogScrFileChkSelMgr();
	mTotalScoreMgr   = new ogScrTotalScoreMgr(nullptr);
	mStartMgr        = new ogScrStartMgr();
#if defined(VERSION_PIKIDEMO)
#else
	mZenController        = new ZenController(nullptr);
	KeyRepeat::repeatTime = 0.5f;
#endif

	PRINT("**********************************************\n");
	PRINT("**\tTEST CONST FINISHED !!\t    \t\t   **\n");
	PRINT("**********************************************\n");
}

/**
 * @todo: Documentation
 */
void OgTestScreen::modeSelectSub()
{
	if (mController->keyClick(KBBTN_MSTICK_UP) && mSelectedMode > TESTMODE_MIN) {
		mSelectedMode--;
	}

	if (mController->keyClick(KBBTN_MSTICK_DOWN) && mSelectedMode < TESTMODE_MAX) {
		mSelectedMode++;
	}

	if (mSelectedMode == TESTMODE_Tutorial) {
#if defined(VERSION_PIKIDEMO)
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mTutorialMode < 152) {
#else
		if (mZenController->keyRepeat(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mTutorialMode < 152) {
#endif
			mTutorialMode++;
		}

#if defined(VERSION_PIKIDEMO)
		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mTutorialMode > 0) {
#else
		if (mZenController->keyRepeat(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mTutorialMode > 0) {
#endif
			mTutorialMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Diary) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mDiaryMode < 30) {
			mDiaryMode++;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mDiaryMode > 0) {
			mDiaryMode--;
		}
	}

	if (mSelectedMode == TESTMODE_MemChk) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mMemChkMode < 9) {
			mMemChkMode++;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mMemChkMode > 0) {
			mMemChkMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Map) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mMapMode < 1) {
			mMapMode++;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mMapMode > 0) {
			mMapMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Save) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mSaveMode < 7) {
			mSaveMode++;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mSaveMode > 0) {
			mSaveMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Pause) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT)) {
			mChallengeModePause = true;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT)) {
			mChallengeModePause = false;
		}
	}

	if (mSelectedMode == TESTMODE_FileChkSel) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT)) {
			mFileChkSelMode = true;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT)) {
			mFileChkSelMode = false;
		}
	}

	if (mSelectedMode == TESTMODE_Title) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT)) {
			mTitleMode = true;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT)) {
			mTitleMode = false;
		}
	}

	if (mSelectedMode == 12) {
		if (mController->keyClick(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && _38A < 5) {
			_38A++;
		}

		if (mController->keyClick(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && _38A > 0) {
			_38A--;
		}
	}

	if (!mController->keyClick(KBBTN_A)) {
		return;
	}

	switch (mSelectedMode) {
	case TESTMODE_Title:
		mTitleMgr->start(mTitleMode);
		mActiveMode = TESTMODE_Title;
		break;

	case TESTMODE_Tutorial:
		mTutorialMgr->start((ogScrTutorialMgr::EnumTutorial)mTutorialMode);
		mActiveMode = TESTMODE_Tutorial;
		break;

	case TESTMODE_Diary:
		mDrawSelectDiary->start();
		mActiveMode = TESTMODE_Diary;
		break;

	case 8:
		mPauseMgr->start(mChallengeModePause);
		mActiveMode = 8;
		break;

	case TESTMODE_Map:
		mMapMgr->start(mMapMode);
		mActiveMode = TESTMODE_Map;
		break;

	case TESTMODE_Result:
		mResultMgr->start();
		mActiveMode = TESTMODE_Result;
		break;

	case TESTMODE_MemChk:
		mMemChkMgr->DebugStart(mMemChkMode);
		mActiveMode = TESTMODE_MemChk;
		break;

	case TESTMODE_FileChkSel:
		mFileChkSelMgr->start(mFileChkSelMode);
		mActiveMode = TESTMODE_FileChkSel;
		break;

	case TESTMODE_Save:
		mFileChkSelMgr->startSave();
		mActiveMode = TESTMODE_Save;
		break;

	case TESTMODE_TotalScore:
		mTotalScoreMgr->start();
		mActiveMode = TESTMODE_TotalScore;
		break;

	case TESTMODE_Unused11:
		mActiveMode = TESTMODE_Unused11;
		break;

	case TESTMODE_Start:
		mStartMgr->start();
		mActiveMode = TESTMODE_Start;
		break;
	}
}

/**
 * @todo: Documentation
 */
void OgTestScreen::update()
{
	mController->update();
#if defined(VERSION_PIKIDEMO)
#else
	mZenController->setContPtr(mController);
	mZenController->update();
#endif

	if (mActiveMode == TESTMODE_INACTIVE) {
		modeSelectSub();
	}

	int resRes = mResultMgr->update(mController);
	if (resRes >= 7) {
		mActiveMode = TESTMODE_INACTIVE;
		PRINT("Result status = (%d)\n", resRes);
	}

	int titleRes = mTitleMgr->update(mController);
	if (titleRes >= 3) {
		mActiveMode = TESTMODE_INACTIVE;
		PRINT("Title Status (%d)\n", titleRes);
	}

	if (mPauseMgr->update(mController) >= 5) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mMapMgr->update(mController) >= ogScrMapMgr::Finished) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mTutorialMgr->update(mController) >= 4) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mMemChkMgr->update(mController) >= ogScrMemChkMgr::ExitFailure) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mDrawSelectDiary->update(mController) >= 4) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mTotalScoreMgr->update(mController) >= 3) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mStartMgr->update(mController) >= ogScrStartMgr::START_Exit) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	CardQuickInfo info;
	int fileCheckRes = mFileChkSelMgr->update(mController, info);
	if (fileCheckRes >= ogScrFileChkSelMgr::FILECHKSEL_Exit) {
		mActiveMode = TESTMODE_INACTIVE;
		PRINT("File Check & Select (%d)\n", fileCheckRes);
	}
}

/**
 * @todo: Documentation
 */
void OgTestScreen::draw(Graphics& gfx)
{
	gfx.setViewport(AREA_FULL_SCREEN(gfx));
	gfx.setScissor(AREA_FULL_SCREEN(gfx));
	gfx.setClearColour(COLOUR_BLACK);
	gfx.clearBuffer(3, false);

	Camera cam;
	Matrix4f viewMat;
	Vector3f vec1(0.0f, 0.0f, 250.0f);
	Vector3f vec2(0.0f, 0.0f, 0.0f);
	cam.calcVectors(vec1, vec2);
	cam.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), 60.0f, 1.0f, 5000.0f);
	gfx.setCamera(&cam);

	gfx.calcViewMatrix(Matrix4f::ident, viewMat);

	gfx.setPerspective(cam.mPerspectiveMatrix.mMtx, cam.mFov, cam.mAspectRatio, cam.mNear, cam.mFar, 1.0f);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

	mResultMgr->draw(gfx);
	mTitleMgr->draw(gfx);
	mPauseMgr->draw(gfx);
	mMapMgr->draw(gfx);
	mTutorialMgr->draw(gfx);
	mDrawSelectDiary->draw(gfx);
	mFileChkSelMgr->draw(gfx);
	mTotalScoreMgr->draw(gfx);
	mStartMgr->draw(gfx);

	if (mActiveMode == TESTMODE_INACTIVE) {
		Matrix4f ortho;
		gfx.setOrthogonal(ortho.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setColour(COLOUR_WHITE, true);
		gfx.setAuxColour(Colour(255, 255, 0, 255));

		char scrnSelectorText[PATH_MAX];
#if defined(VERSION_GPIP01_00)
		sprintf(scrnSelectorText, "２Ｄ Screen checker"); // '2D screen selector'
#else
		sprintf(scrnSelectorText, "２Ｄスクリーン・セレクター"); // '2D screen selector'
#endif
		gfx.texturePrintf(mFont, 320 - mFont->stringWidth(scrnSelectorText) / 2, 20, scrnSelectorText);

		gfx.setColour(Colour(200, 255, 255, 255), true);
		gfx.setAuxColour(Colour(50, 50, 255, 255));

		char optionsTexts[11][PATH_MAX];

#if defined(VERSION_GPIP01_00)
		sprintf(optionsTexts[0], "title (%d)", mTitleMode);              // 'Title (%d)'
		sprintf(optionsTexts[1], "tutorial (%d)", mTutorialMode);        // 'Tutorial (%d)'
		sprintf(optionsTexts[2], "save select (%d)", mSaveMode);         // 'Save Select (%d)'
		sprintf(optionsTexts[3], "test (%d)", mMapMode);                 // 'Test (%d)'
		sprintf(optionsTexts[4], "memory check(%d)", mMemChkMode);       // 'Memory check(%d)'
		sprintf(optionsTexts[5], "check & select(%d)", mFileChkSelMode); // 'Check  and Select (%d)'
		sprintf(optionsTexts[6], "diary (%d)", mDiaryMode);              // 'Diary (%d)'
		sprintf(optionsTexts[7], "result");                              // 'Results'
		sprintf(optionsTexts[8], "pause (%d)", mChallengeModePause);     // 'Pause (%d)'
		sprintf(optionsTexts[9], "total");                               // 'Total Score'
		sprintf(optionsTexts[10], "start");                              // 'Start'
#else
		sprintf(optionsTexts[0], "タイトル (%d)", mTitleMode);               // 'Title (%d)'
		sprintf(optionsTexts[1], "チュートリアル (%d)", mTutorialMode);      // 'Tutorial (%d)'
		sprintf(optionsTexts[2], "セーブセレクト (%d)", mSaveMode);          // 'Save Select (%d)'
		sprintf(optionsTexts[3], "テスト (%d)", mMapMode);                   // 'Test (%d)'
		sprintf(optionsTexts[4], "メモリーチェック(%d)", mMemChkMode);       // 'Memory check(%d)'
		sprintf(optionsTexts[5], "チェック＆セレクト(%d)", mFileChkSelMode); // 'Check  and Select (%d)'
		sprintf(optionsTexts[6], "日記 (%d)", mDiaryMode);                   // 'Diary (%d)'
		sprintf(optionsTexts[7], "リザルト");                                // 'Results'
		sprintf(optionsTexts[8], "ポーズ (%d)", mChallengeModePause);        // 'Pause (%d)'
		sprintf(optionsTexts[9], "トータル成績");                            // 'Total Score'
		sprintf(optionsTexts[10], "スタート");                               // 'Start'
#endif

		for (int i = 0; i < 11; i++) {
			gfx.texturePrintf(mFont, 200, 30 * i + 60, optionsTexts[i]);
		}

		gfx.setColour(COLOUR_WHITE, true);
		gfx.setAuxColour(COLOUR_WHITE);

		char arrowText[256];
		sprintf(arrowText, "＞");
		gfx.texturePrintf(mFont, 170, 30 * mSelectedMode + 60, arrowText);
	}

	if (mActiveMode == TESTMODE_Tutorial) {
		Matrix4f ortho;
		gfx.setOrthogonal(ortho.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setColour(COLOUR_WHITE, true);
		gfx.setAuxColour(Colour(255, 255, 150, 255));

		ogScrMessageMgr* msgMgr = mTutorialMgr->getScrMsgMgr();
		char tutorialText[PATH_MAX];
#if defined(VERSION_GPIP01_00)
		sprintf(tutorialText, "<<< tutorial >>> tx(%d)", msgMgr->getTxtLineMax()); // '<<< Tutorial >>> Number of tx?? (%d)'
#else
		sprintf(tutorialText, "<<< チュ−トリアル >>> tx??の数(%d個)", msgMgr->getTxtLineMax()); // '<<< Tutorial >>> Number of tx?? (%d)'
#endif
		gfx.texturePrintf(mFont, 30, 20, tutorialText);
		gfx.texturePrintf(mFont, 30, 40, msgMgr->getPageInfo()->mScreenResourcePath);
	}

	mMemChkMgr->draw(gfx);
	gfx.setLighting(false, nullptr);
}

/**
 * @todo: Documentation
 */
OgTestSection::OgTestSection()
{
	Node::init("<OgTestSection>");
	gsys->setFrameClamp(1);
	flowCont._24C = 0;
	flowCont._250 = 0;
}

/**
 * @todo: Documentation
 */
void OgTestSection::init()
{
	int msgHeapSize = 0x19800;
	gsys->mHeaps[SYSHEAP_Message].init("message", AYU_STACK_GROW_UP, new u8[msgHeapSize], msgHeapSize);
	OgTestScreen* screen = new OgTestScreen();
	add(screen);
}

} // namespace zen
