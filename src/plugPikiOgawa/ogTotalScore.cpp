#include "zen/ogTotalScore.h"
#include "DebugLog.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "sysNew.h"
#include "zen/ZenController.h"
#include "zen/DrawCommon.h"
#include "zen/ogMessage.h"
#include "zen/ogSub.h"
#include "zen/EffectMgr2D.h"
#include "zen/DrawCM.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgTotalScoreSection") // probably

/*
 * --INFO--
 * Address:	80194204
 * Size:	000A0C
 */
zen::ogScrTotalScoreMgr::ogScrTotalScoreMgr(zen::TotalScoreType* scores)
{
	mScores = scores;
	if (!mScores) {
		mDummyScores = new TotalScoreType();
		mDummyScores->setDummy();
		mScores = mDummyScores;
	}
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/f_result.blo", true, true, true);
	P2DScreen* screen = mScreen;

	mBest = new DrawCMbest();
	mBest->init(mScreen);
	mEfxMgr2D = new EffectMgr2D(16, 0x400, 0x400);

	mPartsEffectPane     = screen->search('win1', true);
	mDaysEffectPane      = screen->search('win2', true);
	mBornEffectPane      = screen->search('win3', true);
	mDeadEffectPane      = screen->search('win4', true);
	mPartsDigitsTens     = (P2DPicture*)screen->search('pa_l', true);
	mPartsDigitsOnes     = (P2DPicture*)screen->search('pa_r', true);
	mDaysDigitsTens      = (P2DPicture*)screen->search('da_l', true);
	mDaysDigitsOnes      = (P2DPicture*)screen->search('da_r', true);
	mBornDigitsThousands = (P2DPicture*)screen->search('lp_4', true);
	mBornDigitsHundreds  = (P2DPicture*)screen->search('lp_3', true);
	mBornDigitsTens      = (P2DPicture*)screen->search('lp_2', true);
	mBornDigitsOnes      = (P2DPicture*)screen->search('lp_1', true);
	mDeadDigitsThousands = (P2DPicture*)screen->search('dp_4', true);
	mDeadDigitsHundreds  = (P2DPicture*)screen->search('dp_3', true);
	mDeadDigitsTens      = (P2DPicture*)screen->search('dp_2', true);
	mDeadDigitsOnes      = (P2DPicture*)screen->search('dp_1', true);
	mPartsDaysSlash      = (P2DPicture*)screen->search('pd_s', true);
	mPartsHeading        = (P2DTextBox*)screen->search('pa_k', true);
	mDaysHeading         = (P2DTextBox*)screen->search('pa_d', true);
	mBornHeading         = (P2DTextBox*)screen->search('lp_h', true);
	mDeadHeading         = (P2DTextBox*)screen->search('dp_h', true);

	setSpecialNumber(1, mScores->mRecordNumParts[0]);
	setSpecialNumber(2, mScores->mRecordNumDays[0]);
	setSpecialNumber(3, mScores->mRecordNumParts[1]);
	setSpecialNumber(4, mScores->mRecordNumDays[1]);
	setSpecialNumber(5, mScores->mRecordNumParts[2]);
	setSpecialNumber(6, mScores->mRecordNumDays[2]);
	setSpecialNumber(7, mScores->mRecordNumParts[3]);
	setSpecialNumber(8, mScores->mRecordNumDays[3]);
	setSpecialNumber(9, mScores->mRecordNumParts[4]);
	setSpecialNumber(10, mScores->mRecordNumDays[4]);
	setSpecialNumber(11, mScores->mRecordNumBorn[0]);
	setSpecialNumber(12, mScores->mRecordNumBorn[1]);
	setSpecialNumber(13, mScores->mRecordNumBorn[2]);
	setSpecialNumber(14, mScores->mRecordNumBorn[3]);
	setSpecialNumber(15, mScores->mRecordNumBorn[4]);
	setSpecialNumber(16, mScores->mRecordNumDead[0]);
	setSpecialNumber(17, mScores->mRecordNumDead[1]);
	setSpecialNumber(18, mScores->mRecordNumDead[2]);
	setSpecialNumber(19, mScores->mRecordNumDead[3]);
	setSpecialNumber(20, mScores->mRecordNumDead[4]);

	mNewRecordDefaultPane = (P2DPicture*)screen->search('newd', true);

	char buf[8];
	for (int i = 0; i < 5; i++) {
		sprintf(buf, "pd%02d", i + 1);
		mPartDayRecordTexts[i] = (P2DTextBox*)screen->search(P2DPaneLibrary::makeTag(buf), true);
		char* str              = mPartsDaysRecordStrings[i];
		strcpy(str, mPartDayRecordTexts[i]->getString());
		cnvSpecialNumber(str);
		mPartDayRecordTexts[i]->setString(str);
	}

	for (int i = 0; i < 5; i++) {
		sprintf(buf, "lp%02d", i + 1);
		mBornRecordTexts[i] = (P2DTextBox*)screen->search(P2DPaneLibrary::makeTag(buf), true);
		char* str           = mBornRecordStrings[i];
		strcpy(str, mBornRecordTexts[i]->getString());
		cnvSpecialNumber(str);
		mBornRecordTexts[i]->setString(str);
	}

	for (int i = 0; i < 5; i++) {
		sprintf(buf, "dp%02d", i + 1);
		mDeadRecordTexts[i] = (P2DTextBox*)screen->search(P2DPaneLibrary::makeTag(buf), true);
		char* str           = mDeadRecordStrings[i];
		strcpy(str, mDeadRecordTexts[i]->getString());
		cnvSpecialNumber(str);
		mDeadRecordTexts[i]->setString(str);
	}

	setNumberTag(screen, 'pa_l', &mScores->mParts, 10);
	setNumberTag(screen, 'pa_r', &mScores->mParts, 1);
	setNumberTag(screen, 'da_l', &mScores->mDay, 10);
	setNumberTag(screen, 'da_r', &mScores->mDay, 1);
	setNumberTag(screen, 'lp_4', &mScores->mPikis, 1000);
	setNumberTag(screen, 'lp_3', &mScores->mPikis, 100);
	setNumberTag(screen, 'lp_2', &mScores->mPikis, 10);
	setNumberTag(screen, 'lp_1', &mScores->mPikis, 1);
	setNumberTag(screen, 'dp_4', &mScores->mDeadPikis, 1000);
	setNumberTag(screen, 'dp_3', &mScores->mDeadPikis, 100);
	setNumberTag(screen, 'dp_2', &mScores->mDeadPikis, 10);
	setNumberTag(screen, 'dp_1', &mScores->mDeadPikis, 1);
	setNumberTag(screen, 'tp_8', &mScores->mTotalPikis, 10000000);
	setNumberTag(screen, 'tp_7', &mScores->mTotalPikis, 1000000);
	setNumberTag(screen, 'tp_6', &mScores->mTotalPikis, 100000);
	setNumberTag(screen, 'tp_5', &mScores->mTotalPikis, 10000);
	setNumberTag(screen, 'tp_4', &mScores->mTotalPikis, 1000);
	setNumberTag(screen, 'tp_3', &mScores->mTotalPikis, 100);
	setNumberTag(screen, 'tp_2', &mScores->mTotalPikis, 10);
	setNumberTag(screen, 'tp_1', &mScores->mTotalPikis, 1);

	mFrameTimer = 0.0f;
	mState      = TOTALSCORE_Sleep;

	mDeadRecordTexts ? "fake" : "fake";
	mDeadRecordTexts ? "fake" : "fake";
	mDeadRecordTexts ? "fake" : "fake";
}

/*
 * --INFO--
 * Address:	80194C10
 * Size:	00003C
 */
void zen::ogScrTotalScoreMgr::start()
{
	setRankInColor();
	mState = TOTALSCORE_FadeIn;
	mBest->appear();
}

/*
 * --INFO--
 * Address:	80194C4C
 * Size:	000190
 */
zen::ogScrTotalScoreMgr::TotalScoreStatus zen::ogScrTotalScoreMgr::update(Controller* input)
{
	if (mState == TOTALSCORE_Sleep) {
		return mState;
	}

	mScreen->update();
	mEfxMgr2D->update();
	mBest->update();
	mFrameTimer += gsys->getFrameTime();
	if (mState == TOTALSCORE_FadeIn) {
		if (mFrameTimer < 1.0f) {
			P2DPaneLibrary::setFamilyAlpha(mScreen, u8(255.0f * mFrameTimer));
		} else {
			P2DPaneLibrary::setFamilyAlpha(mScreen, 255);
			mState      = TOTALSCORE_Operation;
			mFrameTimer = 0.0f;
			setRankInEffect();
		}
		return mState;
	} else if (mState == TOTALSCORE_FadeOut) {
		if (mFrameTimer < 1.0f) {
			P2DPaneLibrary::setFamilyAlpha(mScreen, 255 - u8(255.0f * mFrameTimer));
		} else {
			P2DPaneLibrary::setFamilyAlpha(mScreen, 0);
			mState      = TOTALSCORE_End;
			mFrameTimer = 0.0f;
		}
		return mState;

	} else if (mState == TOTALSCORE_End) {
		mState = TOTALSCORE_Sleep;
		return mState;

	} else {
		setRankInColor();
		if (mState == TOTALSCORE_Operation && input->keyClick(KBBTN_ANY)) {
			mState      = TOTALSCORE_FadeOut;
			mFrameTimer = 0.0f;
			mEfxMgr2D->killAll(true);
		}
		return mState;
	}
}

/*
 * --INFO--
 * Address:	80194DDC
 * Size:	0000A4
 */
void zen::ogScrTotalScoreMgr::draw(Graphics& gfx)
{
	if (mState == TOTALSCORE_Sleep) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();
	mScreen->draw(0, 0, &perspGraph);
	mEfxMgr2D->draw(gfx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void zen::ogScrTotalScoreMgr::setEffect(P2DPane* pane, int effID)
{
	int x, y;
	P2DPaneLibrary::getWorldPos(pane, &x, &y);
	int width  = pane->getWidth();
	int height = pane->getHeight();
	x += width / 2;
	y += height / 2;
	y = 480 - y;
	Vector3f pos;
	pos.set(x, y, 0.0f);
	mEfxMgr2D->create(effID, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	80194E80
 * Size:	0006EC
 */
void zen::ogScrTotalScoreMgr::setRankInEffect()
{
	if (mScores->mPartsDaysRank >= 0 && mScores->mPartsDaysRank < 5) {
		setEffect(mPartsEffectPane, 2);
		setEffect(mPartsEffectPane, 3);
		setEffect(mDaysEffectPane, 2);
		setEffect(mDaysEffectPane, 3);
	}
	if (mScores->mBornPikisRank >= 0 && mScores->mBornPikisRank < 5) {
		setEffect(mBornEffectPane, 0);
		setEffect(mBornEffectPane, 1);
	}

	if (mScores->mDeadPikisRank >= 0 && mScores->mDeadPikisRank < 5) {
		setEffect(mDeadEffectPane, 0);
		setEffect(mDeadEffectPane, 1);
	}
}

/*
 * --INFO--
 * Address:	8019556C
 * Size:	0001D4
 */
void zen::ogScrTotalScoreMgr::setRankInColor()
{
	Colour colour;
	colour = mNewRecordDefaultPane->getWhite();

	s16 pdRank = mScores->mPartsDaysRank;
	if (pdRank >= 0 && pdRank < 5) {
		mPartDayRecordTexts[pdRank]->setCharColor(colour);
		mPartDayRecordTexts[pdRank]->setGradColor(colour);
		mPartsDigitsTens->setWhite(colour);
		mPartsDigitsOnes->setWhite(colour);
		mDaysDigitsTens->setWhite(colour);
		mDaysDigitsOnes->setWhite(colour);
		mPartsDaysSlash->setWhite(colour);
		mPartsHeading->setCharColor(colour);
		mPartsHeading->setGradColor(colour);
		mDaysHeading->setCharColor(colour);
		mDaysHeading->setGradColor(colour);
	}

	s16 bornRank = mScores->mBornPikisRank;
	if (bornRank >= 0 && bornRank < 5) {
		mBornRecordTexts[bornRank]->setCharColor(colour);
		mBornRecordTexts[bornRank]->setGradColor(colour);
		mBornDigitsThousands->setWhite(colour);
		mBornDigitsHundreds->setWhite(colour);
		mBornDigitsTens->setWhite(colour);
		mBornDigitsOnes->setWhite(colour);
		mBornHeading->setCharColor(colour);
		mBornHeading->setGradColor(colour);
	}

	s16 deadRank = mScores->mDeadPikisRank;
	if (deadRank >= 0 && deadRank < 5) {
		mDeadRecordTexts[deadRank]->setCharColor(colour);
		mDeadRecordTexts[deadRank]->setGradColor(colour);
		mDeadDigitsThousands->setWhite(colour);
		mDeadDigitsHundreds->setWhite(colour);
		mDeadDigitsTens->setWhite(colour);
		mDeadDigitsOnes->setWhite(colour);
		mDeadHeading->setCharColor(colour);
		mDeadHeading->setGradColor(colour);
	}
}
