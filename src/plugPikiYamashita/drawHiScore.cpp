#include "zen/DrawHiScore.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "VersionGroups.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(14)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("drawHiScore")

/*
 * --INFO--
 * Address:	801F0A80
 * Size:	0003D8
 */
zen::DrawHiScore::DrawHiScore()
{
	mMode             = MODE_Sleep;
	mScreen           = new DrawScreen("screen/blo/cha_hi.blo", nullptr, true, true);
	P2DScreen* screen = mScreen->getScreenPtr();
	mTotalsPane       = screen->search('ttal', true);
	mCMRecordsPane    = screen->search('char', true);
	mBest.init(screen);
	mBest.hide();

	int stageCount = 0;
	char buf[8];
	for (int i = 0; i < 5; i++) {
		// parts / days
		sprintf(buf, "p_%02d", i);
		rewriteNumber(screen, P2DPaneLibrary::makeTag(buf), gameflow.mGamePrefs.mHiscores.mMinDayRecords[i].mNumParts, 2, true);
		sprintf(buf, "d_%02d", i);
		rewriteNumber(screen, P2DPaneLibrary::makeTag(buf), gameflow.mGamePrefs.mHiscores.mMinDayRecords[i].mNumDays, 2, true);

		// living pikmin
		sprintf(buf, "lp%02d", i);
		rewriteNumber(screen, P2DPaneLibrary::makeTag(buf), gameflow.mGamePrefs.mHiscores.mBornPikminRecords[i].mNumBorn, 4, true);

		// dead pikmin
		sprintf(buf, "dp%02d", i);
		int dead = gameflow.mGamePrefs.mHiscores.mDeadPikminRecords[i].mNumDead;
		if (dead == 9999) {
			dead = -1;
		}
		rewriteNumber(screen, P2DPaneLibrary::makeTag(buf), dead, 4, true);

		if (!gameflow.mGamePrefs.isStageOpen(i)) {
			sprintf(buf, "pm_%d", i);
			P2DPane* pane = screen->search(P2DPaneLibrary::makeTag(buf), true);
			pane->hide();
		} else {
			stageCount++;
		}

		for (int j = 0; j < 5; j++) {
			GameChalQuickInfo info;
			info.mCourseID = j;
			gameflow.mGamePrefs.getChallengeScores(info);
			sprintf(buf, "%d_%02d", j, i);
			rewriteNumber(screen, P2DPaneLibrary::makeTag(buf), info.mCourseScores[i], 3, true);
		}
	}

	// if we haven't unlocked any challenge modes, hide the challenge mode records?
	if (stageCount == 0) {
		mTotalsPane->move(27, 130);
		mCMRecordsPane->hide();
	}
}

/*
 * --INFO--
 * Address:	801F0E58
 * Size:	00012C
 */
bool zen::DrawHiScore::update(Controller* controller)
{
	bool res = false;
	mScreen->update();
	mBest.update();
	mAlphaWipe.update();
	switch (mMode) {
	case MODE_FadeIn:
		if (mAlphaWipe.isSleep()) {
			mMode = MODE_Operation;
		}
		break;

	case MODE_Operation:
		if (controller->keyClick(KBBTN_B)) {
			SeSystem::playSysSe(SYSSE_CANCEL);
			mMode = MODE_FadeOut;
			mAlphaWipe.setColour(Colour(0, 0, 0, 255), Colour(0, 0, 0, 255));
			mAlphaWipe.start(0.5f, 0.25f, AlphaWipe::TYPE_Normal);
		}
		break;

	case MODE_FadeOut:
		if (mAlphaWipe.isSleep()) {
			mMode = MODE_Sleep;
			res   = true;
		}
		break;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801F0F84
 * Size:	0001B0
 */
void zen::DrawHiScore::draw(Graphics& gfx)
{
	bool check = false;
	switch (mMode) {
	case MODE_FadeIn:
		if (mAlphaWipe.isDec()) {
			check = true;
		}
		break;

	case MODE_Operation:
		check = true;
		break;

	case MODE_FadeOut:
		if (mAlphaWipe.isInc()) {
			check = true;
		}
		break;
	}

	if (check) {
		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setColour(Colour(0, 0, 0, 255), true);
		gfx.setAuxColour(Colour(0, 0, 64, 255));
		gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		mScreen->draw();
	}

	mAlphaWipe.draw(gfx);
}

/*
 * --INFO--
 * Address:	801F1134
 * Size:	000084
 */
void zen::DrawHiScore::start()
{
	mMode = MODE_FadeIn;
	mBest.wait();
	mAlphaWipe.setColour(Colour(0, 0, 0, 255), Colour(0, 0, 0, 255));
	mAlphaWipe.start(0.5f, 0.25, AlphaWipe::TYPE_Reverse);
}

/*
 * --INFO--
 * Address:	801F11B8
 * Size:	00033C
 */
void zen::DrawHiScore::rewriteNumber(P2DScreen* screen, u32 tag, int value, int digits, bool p5)
{
	P2DPane* pane = screen->search(tag, true);
	if (pane->getTypeID() == PANETYPE_TextBox) {
		int i;
		char* text = new char[digits + 1];
		if (p5 && value < 0) {
			for (i = 0; i < digits; i++) {
#if defined(VERSION_PIKIDEMO)
				text[i] = '-';
#else
				text[i] = '*';
#endif
			}
			text[digits] = 0;
		} else {
			int place = 1;
			for (i = 0; i < digits; i++) {
				text[digits - i - 1] = value / place % 10 + '0';
				place *= 10;
			}
			text[digits] = 0;
		}

		static_cast<P2DTextBox*>(pane)->setString(text);
	} else {
		PRINT("tag <%c%c%c%c> is not TextBox Pane. \n", ((u32*)&tag)[0], ((u32*)&tag)[1], ((u32*)&tag)[2], ((u32*)&tag)[3]);
		ERROR("tag <%c%c%c%c> is not TextBox Pane. \n", ((u32*)&tag)[0], ((u32*)&tag)[1], ((u32*)&tag)[2], ((u32*)&tag)[3]);
	}
}
