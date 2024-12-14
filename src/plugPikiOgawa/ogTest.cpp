#include "zen/ogTest.h"
#include "sysNew.h"
#include "Font.h"
#include "Controller.h"
#include "MemoryCard.h"
#include "zen/ZenController.h"
#include "zen/ogSub.h"
#include "zen/ogMemChk.h"
#include "zen/ogPause.h"
#include "zen/ogResult.h"
#include "zen/ogTitle.h"
#include "zen/ogTutorial.h"
#include "zen/ogMap.h"
#include "zen/ogDiary.h"
#include "zen/ogFileChkSel.h"
#include "zen/ogTotalScore.h"
#include "zen/ogStart.h"
#include "zen/ogMessage.h"
#include "FlowController.h"
#include "Dolphin/os.h"
#include "Geometry.h"
#include "Graphics.h"
#include "stl/stdio.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "OgTestSection");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017D744
 * Size:	0002EC
 */
zen::OgTestScreen::OgTestScreen()
{
	u32 badCompiler[10];

	setName("OgTestScreen");
	mController      = new Controller();
	_20              = 0;
	mActiveMode      = TESTMODE_INACTIVE;
	mTutorialMode    = 0;
	mDiaryMode       = 0;
	mMemChkMode      = 0;
	mMapMode         = 0;
	mSaveMode        = 0;
	_38A             = 0;
	mPauseMode       = false;
	mFileChkSelMode  = false;
	mSelectedMode    = TESTMODE_Title;
	Texture* fontTex = gsys->loadTexture("bigFont.bti", true);
	mFont            = new Font();
	mFont->setTexture(fontTex, 21, 42);
	gsys->setFade(1.0f, 3.0f);

	for (int i = 0; i < 100; i++) {
		setSpecialNumber(i, -123);
	}

	gsys->getHeap(gsys->mActiveHeapIdx);

	mMemChkMgr = new ogScrMemChkMgr();

	gsys->getHeap(gsys->mActiveHeapIdx);

	mPauseMgr             = new ogScrPauseMgr();
	mResultMgr            = new ogScrResultMgr();
	mTitleMgr             = new ogScrTitleMgr();
	mTutorialMgr          = new ogScrTutorialMgr();
	mMapMgr               = new ogScrMapMgr();
	mDrawSelectDiary      = new ogDrawSelectDiary();
	mFileChkSelMgr        = new ogScrFileChkSelMgr();
	mTotalScoreMgr        = new ogScrTotalScoreMgr(nullptr);
	mStartMgr             = new ogScrStartMgr();
	mZenController        = new ZenController(nullptr);
	KeyRepeat::repeatTime = 0.5f;
}

/*
 * --INFO--
 * Address:	8017DA30
 * Size:	0004DC
 */
void zen::OgTestScreen::modeSelectSub()
{
	if (mController->isPressed(KBBTN_MSTICK_UP) && mSelectedMode > TESTMODE_MIN) {
		mSelectedMode--;
	}

	if (mController->isPressed(KBBTN_MSTICK_DOWN) && mSelectedMode < TESTMODE_MAX) {
		mSelectedMode++;
	}

	if (mSelectedMode == TESTMODE_Tutorial) {
		if (mZenController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mTutorialMode < 152) {
			mTutorialMode++;
		}

		if (mZenController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mTutorialMode > 0) {
			mTutorialMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Diary) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mDiaryMode < 30) {
			mDiaryMode++;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mDiaryMode > 0) {
			mDiaryMode--;
		}
	}

	if (mSelectedMode == TESTMODE_MemChk) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mMemChkMode < 9) {
			mMemChkMode++;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mMemChkMode > 0) {
			mMemChkMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Map) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mMapMode < 1) {
			mMapMode++;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mMapMode > 0) {
			mMapMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Save) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && mSaveMode < 7) {
			mSaveMode++;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && mSaveMode > 0) {
			mSaveMode--;
		}
	}

	if (mSelectedMode == TESTMODE_Pause) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT)) {
			mPauseMode = true;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT)) {
			mPauseMode = false;
		}
	}

	if (mSelectedMode == TESTMODE_FileChkSel) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT)) {
			mFileChkSelMode = true;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT)) {
			mFileChkSelMode = false;
		}
	}

	if (mSelectedMode == TESTMODE_Title) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT)) {
			mTitleMode = true;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT)) {
			mTitleMode = false;
		}
	}

	if (mSelectedMode == 12) {
		if (mController->isPressed(KBBTN_MSTICK_RIGHT | KBBTN_CSTICK_RIGHT) && _38A < 5) {
			_38A++;
		}

		if (mController->isPressed(KBBTN_MSTICK_LEFT | KBBTN_CSTICK_LEFT) && _38A > 0) {
			_38A--;
		}
	}

	if (!mController->isPressed(KBBTN_A)) {
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
		mPauseMgr->start(mPauseMode);
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

/*
 * --INFO--
 * Address:	8017DF0C
 * Size:	000188
 */
void zen::OgTestScreen::update()
{
	u32 badCompiler[8];

	mController->update();
	mZenController->setController(mController);
	mZenController->update();

	if (mActiveMode == TESTMODE_INACTIVE) {
		modeSelectSub();
	}

	if (mResultMgr->update(mController) >= 7) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mTitleMgr->update(mController) >= 3) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mPauseMgr->update(mController) >= 5) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mMapMgr->update(mController) >= 4) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mTutorialMgr->update(mController) >= 4) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mMemChkMgr->update(mController) >= 19) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mDrawSelectDiary->update(mController) >= 4) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mTotalScoreMgr->update(mController) >= 3) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mStartMgr->update(mController) >= 3) {
		mActiveMode = TESTMODE_INACTIVE;
	}

	if (mFileChkSelMgr->update(mController, CardQuickInfo()) >= 1) {
		mActiveMode = TESTMODE_INACTIVE;
	}
}

/*
 * --INFO--
 * Address:	8017E094
 * Size:	0006A8
 */
void zen::OgTestScreen::draw(Graphics& gfx)
{
	gfx.setViewport(RectArea(0, 0, gfx._30C, gfx._310));
	gfx.setScissor(RectArea(0, 0, gfx._30C, gfx._310));
	gfx.setClearColour(Colour(0, 0, 0, 255));
	gfx.clearBuffer(3, false);

	Camera cam;
	Matrix4f viewMat;
	Vector3f vec1(0.0f, 0.0f, 250.0f);
	Vector3f vec2(0.0f, 0.0f, 0.0f);
	cam.calcVectors(vec1, vec2);
	cam.update(f32(gfx._30C) / f32(gfx._310), 60.0f, 1.0f, 5000.0f);
	gfx.setCamera(&cam);

	gfx.calcViewMatrix(Matrix4f::ident, viewMat);

	gfx.setPerspective(cam._260.mMtx, cam._1CC, cam._1C4, cam._1D0, cam._1D4, 1.0f);
	gfx.useMatrix(gfx._2E4->_1E0, 0);

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
		gfx.setOrthogonal(ortho.mMtx, RectArea(0, 0, gfx._30C, gfx._310));
		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 0, 255));

		char scrnSelectorText[128];
		sprintf(scrnSelectorText, "２Ｄスクリーン・セレクター"); // '2D screen selector'
		gfx.texturePrintf(mFont, 320 - mFont->stringWidth(scrnSelectorText) / 2, 20, scrnSelectorText);

		gfx.setColour(Colour(200, 255, 255, 255), true);
		gfx.setAuxColour(Colour(50, 50, 255, 255));

		char optionsTexts[11][256];

		sprintf(optionsTexts[0], "タイトル (%d)", mTitleMode);               // 'Title (%d)'
		sprintf(optionsTexts[1], "チュートリアル (%d)", mTutorialMode);      // 'Tutorial (%d)'
		sprintf(optionsTexts[2], "セーブセレクト (%d)", mSaveMode);          // 'Save Select (%d)'
		sprintf(optionsTexts[3], "テスト (%d)", mMapMode);                   // 'Test (%d)'
		sprintf(optionsTexts[4], "メモリーチェック(%d)", mMemChkMode);       // 'Memory check(%d)'
		sprintf(optionsTexts[5], "チェック＆セレクト(%d)", mFileChkSelMode); // 'Check  and Select (%d)'
		sprintf(optionsTexts[6], "日記 (%d)", mDiaryMode);                   // 'Diary (%d)'
		sprintf(optionsTexts[7], "リザルト");                                // 'Results'
		sprintf(optionsTexts[8], "ポーズ (%d)", mPauseMode);                 // 'Pause (%d)'
		sprintf(optionsTexts[9], "トータル成績");                            // 'Total Score'
		sprintf(optionsTexts[10], "スタート");                               // 'Start'

		for (int i = 0; i < 11; i++) {
			gfx.texturePrintf(mFont, 200, 30 * i + 60, optionsTexts[i]);
		}

		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 255, 255));

		char arrowText[256];
		sprintf(arrowText, "＞");
		gfx.texturePrintf(mFont, 170, 30 * mSelectedMode + 60, arrowText);
	}

	if (mActiveMode == TESTMODE_Tutorial) {
		Matrix4f ortho;
		gfx.setOrthogonal(ortho.mMtx, RectArea(0, 0, gfx._30C, gfx._310));
		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 150, 255));

		ogScrMessageMgr* msgMgr = mTutorialMgr->mMessageMgr;
		char tutorialText[256];
		sprintf(tutorialText, "<<< チュ−トリアル >>> tx??の数(%d個)", msgMgr->_A59C); // '<<< Tutorial >>> Number of tx?? (%d)'
		gfx.texturePrintf(mFont, 30, 20, tutorialText);
		gfx.texturePrintf(mFont, 30, 40, *msgMgr->_1C[msgMgr->_4D0]);
	}

	mMemChkMgr->draw(gfx);
	gfx.setLighting(false, nullptr);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x12C8(r1)
	  stmw      r26, 0x12B0(r1)
	  li        r27, 0
	  mr        r31, r4
	  mr        r30, r3
	  addi      r3, r31, 0
	  addi      r29, r5, 0x2468
	  lwz       r6, 0x310(r4)
	  lwz       r0, 0x30C(r4)
	  addi      r4, r1, 0x6C
	  stw       r27, 0x6C(r1)
	  stw       r27, 0x70(r1)
	  stw       r0, 0x74(r1)
	  stw       r6, 0x78(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x5C
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r27, 0x5C(r1)
	  stw       r27, 0x60(r1)
	  stw       r0, 0x64(r1)
	  stw       r5, 0x68(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stb       r27, 0x58(r1)
	  li        r28, 0xFF
	  addi      r4, r1, 0x58
	  stb       r27, 0x59(r1)
	  mr        r3, r31
	  stb       r27, 0x5A(r1)
	  stb       r28, 0x5B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0xF58
	  bl        -0x13AFA0
	  lfs       f1, 0x8E8(r13)
	  addi      r3, r1, 0xF58
	  lfs       f0, 0x8F4(r13)
	  addi      r4, r1, 0xF0C
	  stfs      f1, 0xF0C(r1)
	  lfs       f1, 0x8EC(r13)
	  addi      r5, r1, 0xF00
	  stfs      f0, 0xF00(r1)
	  lfs       f0, 0x8F8(r13)
	  stfs      f1, 0xF10(r1)
	  lfs       f1, 0x8F0(r13)
	  stfs      f0, 0xF04(r1)
	  lfs       f0, 0x8FC(r13)
	  stfs      f1, 0xF14(r1)
	  stfs      f0, 0xF08(r1)
	  bl        -0x13B400
	  lwz       r5, 0x30C(r31)
	  lis       r4, 0x4330
	  lwz       r0, 0x310(r31)
	  addi      r3, r1, 0xF58
	  xoris     r5, r5, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x12AC(r1)
	  lfd       f5, -0x50F0(r2)
	  stw       r0, 0x12A4(r1)
	  lfs       f2, -0x50FC(r2)
	  stw       r4, 0x12A8(r1)
	  lfs       f3, -0x5108(r2)
	  stw       r4, 0x12A0(r1)
	  lfd       f1, 0x12A8(r1)
	  lfd       f0, 0x12A0(r1)
	  fsubs     f1, f1, f5
	  lfs       f4, -0x50F8(r2)
	  fsubs     f0, f0, f5
	  fdivs     f1, f1, f0
	  bl        -0x13B5A0
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0xF58
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x70(r12)
	  subi      r4, r4, 0x77C0
	  addi      r5, r1, 0xF18
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x1124(r1)
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x11B8
	  lfs       f2, 0x111C(r1)
	  lwz       r12, 0x3C(r12)
	  lfs       f3, 0x1128(r1)
	  mtlr      r12
	  lfs       f4, 0x112C(r1)
	  lfs       f5, -0x5108(r2)
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x390(r30)
	  mr        r4, r31
	  bl        0x6D18
	  lwz       r3, 0x394(r30)
	  mr        r4, r31
	  bl        0x3D84
	  lwz       r3, 0x39C(r30)
	  mr        r4, r31
	  bl        0x47EC
	  lwz       r3, 0x3A0(r30)
	  mr        r4, r31
	  bl        0x50D4
	  lwz       r3, 0x398(r30)
	  mr        r4, r31
	  bl        0x4A1C
	  lwz       r3, 0x3B4(r30)
	  mr        r4, r31
	  bl        0x12EE4
	  lwz       r3, 0x3A8(r30)
	  mr        r4, r31
	  bl        0x15614
	  lwz       r3, 0x3AC(r30)
	  mr        r4, r31
	  bl        0x16B04
	  lwz       r3, 0x3B0(r30)
	  mr        r4, r31
	  bl        0x1A9BC
	  lwz       r0, 0x24(r30)
	  cmplwi    r0, 0xE
	  bne-      .loc_0x54C
	  lwz       r6, 0x310(r31)
	  addi      r5, r1, 0x48
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  addi      r4, r1, 0xEC0
	  stw       r27, 0x48(r1)
	  stw       r27, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  stw       r6, 0x54(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x44(r1)
	  addi      r4, r1, 0x44
	  addi      r3, r31, 0
	  stb       r28, 0x45(r1)
	  li        r5, 0x1
	  stb       r28, 0x46(r1)
	  stb       r28, 0x47(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x40(r1)
	  addi      r4, r1, 0x40
	  addi      r3, r31, 0
	  stb       r28, 0x41(r1)
	  stb       r27, 0x42(r1)
	  stb       r28, 0x43(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0xDC0
	  crclr     6, 0x6
	  addi      r4, r29, 0x78
	  bl        0x98210
	  lwz       r3, 0x30(r30)
	  addi      r4, r1, 0xDC0
	  bl        -0x156260
	  lwz       r12, 0x3B4(r31)
	  srawi     r0, r3, 0x1
	  addze     r0, r0
	  lwz       r4, 0x30(r30)
	  lwz       r12, 0xEC(r12)
	  addi      r3, r31, 0
	  crclr     6, 0x6
	  mtlr      r12
	  subfic    r5, r0, 0x140
	  addi      r7, r1, 0xDC0
	  li        r6, 0x14
	  blrl
	  li        r0, 0xC8
	  stb       r0, 0x3C(r1)
	  addi      r4, r1, 0x3C
	  addi      r3, r31, 0
	  stb       r28, 0x3D(r1)
	  li        r5, 0x1
	  stb       r28, 0x3E(r1)
	  stb       r28, 0x3F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x32
	  stb       r0, 0x38(r1)
	  addi      r4, r1, 0x38
	  addi      r3, r31, 0
	  stb       r0, 0x39(r1)
	  stb       r28, 0x3A(r1)
	  stb       r28, 0x3B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lbz       r5, 0x38E(r30)
	  addi      r3, r1, 0x2C0
	  addi      r4, r29, 0x94
	  crclr     6, 0x6
	  bl        0x98164
	  lha       r5, 0x37E(r30)
	  addi      r3, r1, 0x3C0
	  addi      r4, r29, 0xA4
	  crclr     6, 0x6
	  bl        0x98150
	  lha       r5, 0x388(r30)
	  addi      r3, r1, 0x4C0
	  addi      r4, r29, 0xB8
	  crclr     6, 0x6
	  bl        0x9813C
	  lha       r5, 0x386(r30)
	  addi      r3, r1, 0x5C0
	  addi      r4, r29, 0xCC
	  crclr     6, 0x6
	  bl        0x98128
	  lha       r5, 0x384(r30)
	  addi      r3, r1, 0x6C0
	  addi      r4, r29, 0xD8
	  crclr     6, 0x6
	  bl        0x98114
	  lbz       r5, 0x38D(r30)
	  addi      r3, r1, 0x7C0
	  addi      r4, r29, 0xF0
	  crclr     6, 0x6
	  bl        0x98100
	  lha       r5, 0x380(r30)
	  addi      r3, r1, 0x8C0
	  addi      r4, r29, 0x108
	  crclr     6, 0x6
	  bl        0x980EC
	  addi      r3, r1, 0x9C0
	  crclr     6, 0x6
	  addi      r4, r29, 0x114
	  bl        0x980DC
	  lbz       r5, 0x38C(r30)
	  addi      r3, r1, 0xAC0
	  addi      r4, r29, 0x120
	  crclr     6, 0x6
	  bl        0x980C8
	  addi      r3, r1, 0xBC0
	  crclr     6, 0x6
	  addi      r4, r29, 0x12C
	  bl        0x980B8
	  addi      r3, r1, 0xCC0
	  crclr     6, 0x6
	  addi      r4, r29, 0x13C
	  bl        0x980A8
	  li        r26, 0
	  mulli     r3, r26, 0x1E
	  rlwinm    r0,r26,8,0,23
	  addi      r27, r1, 0x2C0
	  add       r27, r27, r0
	  addi      r28, r3, 0x3C

	.loc_0x478:
	  mr        r3, r31
	  lwz       r4, 0x30(r30)
	  lwz       r12, 0x3B4(r31)
	  addi      r6, r28, 0
	  addi      r7, r27, 0
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  li        r5, 0xC8
	  mtlr      r12
	  blrl
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0xB
	  addi      r27, r27, 0x100
	  addi      r28, r28, 0x1E
	  blt+      .loc_0x478
	  li        r27, 0xFF
	  stb       r27, 0x34(r1)
	  addi      r4, r1, 0x34
	  addi      r3, r31, 0
	  stb       r27, 0x35(r1)
	  li        r5, 0x1
	  stb       r27, 0x36(r1)
	  stb       r27, 0x37(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r27, 0x30(r1)
	  addi      r4, r1, 0x30
	  addi      r3, r31, 0
	  stb       r27, 0x31(r1)
	  stb       r27, 0x32(r1)
	  stb       r27, 0x33(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x1C0
	  crclr     6, 0x6
	  addi      r4, r13, 0x900
	  bl        0x97FEC
	  mr        r3, r31
	  lha       r0, 0x37C(r30)
	  lwz       r12, 0x3B4(r31)
	  addi      r7, r1, 0x1C0
	  mulli     r5, r0, 0x1E
	  lwz       r4, 0x30(r30)
	  lwz       r12, 0xEC(r12)
	  crclr     6, 0x6
	  mtlr      r12
	  addi      r6, r5, 0x3C
	  li        r5, 0xAA
	  blrl

	.loc_0x54C:
	  lwz       r0, 0x24(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x66C
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x20
	  addi      r3, r31, 0
	  stw       r0, 0x20(r1)
	  addi      r4, r1, 0x180
	  stw       r0, 0x24(r1)
	  stw       r6, 0x28(r1)
	  stw       r7, 0x2C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  li        r27, 0xFF
	  stb       r27, 0x1C(r1)
	  addi      r4, r1, 0x1C
	  addi      r3, r31, 0
	  stb       r27, 0x1D(r1)
	  li        r5, 0x1
	  stb       r27, 0x1E(r1)
	  stb       r27, 0x1F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r27, 0x18(r1)
	  li        r0, 0x96
	  addi      r4, r1, 0x18
	  stb       r27, 0x19(r1)
	  mr        r3, r31
	  stb       r0, 0x1A(r1)
	  stb       r27, 0x1B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x398(r30)
	  addi      r3, r1, 0x7C
	  addi      r4, r29, 0x148
	  crclr     6, 0x6
	  lwz       r27, 0x0(r5)
	  addis     r5, r27, 0x1
	  lha       r5, -0x5A64(r5)
	  bl        0x97EFC
	  mr        r3, r31
	  lwz       r4, 0x30(r30)
	  lwz       r12, 0x3B4(r31)
	  addi      r7, r1, 0x7C
	  crclr     6, 0x6
	  li        r5, 0x1E
	  lwz       r12, 0xEC(r12)
	  li        r6, 0x14
	  mtlr      r12
	  blrl
	  lha       r0, 0x4D0(r27)
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  crclr     6, 0x6
	  rlwinm    r0,r0,2,0,29
	  add       r4, r27, r0
	  lwz       r12, 0xEC(r12)
	  lwz       r6, 0x1C(r4)
	  li        r5, 0x1E
	  mtlr      r12
	  lwz       r4, 0x30(r30)
	  lwz       r7, 0x0(r6)
	  li        r6, 0x28
	  blrl

	.loc_0x66C:
	  lwz       r3, 0x3A4(r30)
	  mr        r4, r31
	  bl        0x10898
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lmw       r26, 0x12B0(r1)
	  lwz       r0, 0x12CC(r1)
	  addi      r1, r1, 0x12C8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017E73C
 * Size:	000094
 */
zen::OgTestSection::OgTestSection()
{
	Node::init("<OgTestSection>");
	gsys->mFrameRate = 1;
	flowCont._24C    = 0;
	flowCont._250    = 0;
}

/*
 * --INFO--
 * Address:	8017E7D0
 * Size:	000080
 */
void zen::OgTestSection::init()
{
	int msgHeapSize = 0x19800;
	gsys->mHeaps[SYSHEAP_Message].init("message", 2, new u8[msgHeapSize], msgHeapSize);
	OgTestScreen* screen = new OgTestScreen();
	add(screen);
}
