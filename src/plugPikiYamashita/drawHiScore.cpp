#include "zen/DrawHiScore.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(14)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("drawHiScore")

/**
 * @todo: Documentation
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
	for (int i = 0; i < MAX_HI_SCORES; i++) {
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

		for (int j = 0; j < STAGE_COUNT; j++) {
			GameChalQuickInfo info;
			info.mStageID = j;
			gameflow.mGamePrefs.getChallengeScores(info);
			sprintf(buf, "%d_%02d", j, i);
			rewriteNumber(screen, P2DPaneLibrary::makeTag(buf), info.mCourseScores[i], 3, true);
		}
	}

	// If we haven't unlocked any challenge modes, hide the challenge mode records.
	if (stageCount == 0) {
		mTotalsPane->move(27, 130);
		mCMRecordsPane->hide();
	}
}

/**
 * @todo: Documentation
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
			mAlphaWipe.setColour(COLOUR_BLACK, COLOUR_BLACK);
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

/**
 * @todo: Documentation
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
		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setColour(COLOUR_BLACK, true);
		gfx.setAuxColour(Colour(0, 0, 64, 255));
		gfx.fillRectangle(AREA_FULL_SCREEN(gfx));
		mScreen->draw();
	}

	mAlphaWipe.draw(gfx);
}

/**
 * @todo: Documentation
 */
void zen::DrawHiScore::start()
{
	mMode = MODE_FadeIn;
	mBest.wait();
	mAlphaWipe.setColour(COLOUR_BLACK, COLOUR_BLACK);
	mAlphaWipe.start(0.5f, 0.25, AlphaWipe::TYPE_Reverse);
}

/**
 * @todo: Documentation
 */
void zen::DrawHiScore::rewriteNumber(P2DScreen* screen, u32 tag, int value, int digits, bool p5)
{
	P2DPane* pane = screen->search(tag, true);
	if (pane->getTypeID() == PANETYPE_TextBox) {
		int i;
		char* text = new char[digits + 1];
		if (p5 && value < 0) {
			for (i = 0; i < digits; i++) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
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
		const char* s = reinterpret_cast<char*>(&tag);
		PRINT("tag <%c%c%c%c> is not TextBox Pane. \n", s[0], s[1], s[2], s[3]);
		ERROR("tag <%c%c%c%c> is not TextBox Pane. \n", s[0], s[1], s[2], s[3]);
	}
}
