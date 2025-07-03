#include "zen/DrawFinalResult.h"
#include "zen/ogSub.h"
#include "zen/EffectMgr2D.h"
#include "nlib/Math.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "DebugLog.h"

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
DEFINE_PRINT("drawFinalResult")

/*
 * --INFO--
 * Address:	801F3A38
 * Size:	000AC0
 */
zen::DrawTotalScore::DrawTotalScore(zen::TotalScoreRecord* record)
{
	mTotalScoreRecord = record;
	if (!mTotalScoreRecord) {
		mTotalScoreRecord = new TotalScoreRecord();
		mTotalScoreRecord->setDummy();
	}

	mResultScreen     = new DrawScreen("f_result.blo", nullptr, true, true);
	P2DScreen* screen = mResultScreen->getScreenPtr();
	screen->setOffset(screen->getWidth() >> 1, RoundOff(screen->getHeight() * 0.8f));
	char buf[8];
	int i;
	for (i = 0; i < 4; i++) {
		sprintf(buf, "win%d", i + 1);
		_14[i] = screen->search(P2DPaneLibrary::makeTag(buf), true);
	}

	mPartsNumLeft         = (P2DPicture*)screen->search('pa_l', true);
	mPartsNumRight        = (P2DPicture*)screen->search('pa_r', true);
	mDaysNumLeft          = (P2DPicture*)screen->search('da_l', true);
	mDaysNumRight         = (P2DPicture*)screen->search('da_r', true);
	mLivingPikisThousands = (P2DPicture*)screen->search('lp_4', true);
	mLivingPikisHundreds  = (P2DPicture*)screen->search('lp_3', true);
	mLivingPikisTens      = (P2DPicture*)screen->search('lp_2', true);
	mLivingPikisOnes      = (P2DPicture*)screen->search('lp_1', true);
	mDeadPikisThousands   = (P2DPicture*)screen->search('dp_4', true);
	mDeadPikisHundreds    = (P2DPicture*)screen->search('dp_3', true);
	mDeadPikisTens        = (P2DPicture*)screen->search('dp_2', true);
	mDeadPikisOnes        = (P2DPicture*)screen->search('dp_1', true);
	_B0                   = (P2DPicture*)screen->search('pd_s', true);
	_B4                   = (P2DTextBox*)screen->search('pa_k', true);
	_B8                   = (P2DTextBox*)screen->search('pa_d', true);
	_BC                   = (P2DTextBox*)screen->search('lp_h', true);
	_C0                   = (P2DTextBox*)screen->search('dp_h', true);

	setSpecialNumber(1, mTotalScoreRecord->mRecordNumParts[0]);
	setSpecialNumber(2, mTotalScoreRecord->mRecordNumDays[0]);
	setSpecialNumber(3, mTotalScoreRecord->mRecordNumParts[1]);
	setSpecialNumber(4, mTotalScoreRecord->mRecordNumDays[1]);
	setSpecialNumber(5, mTotalScoreRecord->mRecordNumParts[2]);
	setSpecialNumber(6, mTotalScoreRecord->mRecordNumDays[2]);
	setSpecialNumber(7, mTotalScoreRecord->mRecordNumParts[3]);
	setSpecialNumber(8, mTotalScoreRecord->mRecordNumDays[3]);
	setSpecialNumber(9, mTotalScoreRecord->mRecordNumParts[4]);
	setSpecialNumber(10, mTotalScoreRecord->mRecordNumDays[4]);
	setSpecialNumber(11, mTotalScoreRecord->mRecordNumBorn[0]);
	setSpecialNumber(12, mTotalScoreRecord->mRecordNumBorn[1]);
	setSpecialNumber(13, mTotalScoreRecord->mRecordNumBorn[2]);
	setSpecialNumber(14, mTotalScoreRecord->mRecordNumBorn[3]);
	setSpecialNumber(15, mTotalScoreRecord->mRecordNumBorn[4]);
	setSpecialNumber(16, mTotalScoreRecord->mRecordNumDead[0]);
	setSpecialNumber(17, mTotalScoreRecord->mRecordNumDead[1]);
	setSpecialNumber(18, mTotalScoreRecord->mRecordNumDead[2]);
	setSpecialNumber(19, mTotalScoreRecord->mRecordNumDead[3]);
	setSpecialNumber(20, mTotalScoreRecord->mRecordNumDead[4]);

	for (i = 0; i < 5; i++) {
		sprintf(buf, "pd%02d", i + 1);
		mPartsDaysRecordPanes[i] = (P2DTextBox*)screen->search(P2DPaneLibrary::makeTag(buf), true);
		char* str                = mPartsDaysRecordTexts[i];
		strcpy(str, mPartsDaysRecordPanes[i]->getString());
		cnvSpecialNumberHyphen(str);
		mPartsDaysRecordPanes[i]->setString(str);
	}
	for (i = 0; i < 5; i++) {
		sprintf(buf, "lp%02d", i + 1);
		mLivingPikiRecordPanes[i] = (P2DTextBox*)screen->search(P2DPaneLibrary::makeTag(buf), true);
		char* str                 = mLivingPikiRecordTexts[i];
		strcpy(str, mLivingPikiRecordPanes[i]->getString());
		cnvSpecialNumberHyphen(str);
		mLivingPikiRecordPanes[i]->setString(str);
	}
	for (i = 0; i < 5; i++) {
		sprintf(buf, "dp%02d", i + 1);
		mDeadPikiRecordPanes[i] = (P2DTextBox*)screen->search(P2DPaneLibrary::makeTag(buf), true);
		char* str               = mDeadPikiRecordTexts[i];
		strcpy(str, mDeadPikiRecordPanes[i]->getString());
		cnvSpecialNumberHyphen(str);
		mDeadPikiRecordPanes[i]->setString(str);
	}

	setNumberTag(screen, 'pa_l', &mTotalScoreRecord->mParts, 10);
	setNumberTag(screen, 'pa_r', &mTotalScoreRecord->mParts, 1);
	setNumberTag(screen, 'da_l', &mTotalScoreRecord->mDay, 10);
	setNumberTag(screen, 'da_r', &mTotalScoreRecord->mDay, 1);
	setNumberTag(screen, 'lp_4', &mTotalScoreRecord->mPikis, 1000);
	setNumberTag(screen, 'lp_3', &mTotalScoreRecord->mPikis, 100);
	setNumberTag(screen, 'lp_2', &mTotalScoreRecord->mPikis, 10);
	setNumberTag(screen, 'lp_1', &mTotalScoreRecord->mPikis, 1);
	setNumberTag(screen, 'dp_4', &mTotalScoreRecord->mDeadPikis, 1000);
	setNumberTag(screen, 'dp_3', &mTotalScoreRecord->mDeadPikis, 100);
	setNumberTag(screen, 'dp_2', &mTotalScoreRecord->mDeadPikis, 10);
	setNumberTag(screen, 'dp_1', &mTotalScoreRecord->mDeadPikis, 1);
	setNumberTag(screen, 'tp_8', &mTotalScoreRecord->mTotalPikis, 10000000);
	setNumberTag(screen, 'tp_7', &mTotalScoreRecord->mTotalPikis, 1000000);
	setNumberTag(screen, 'tp_6', &mTotalScoreRecord->mTotalPikis, 100000);
	setNumberTag(screen, 'tp_5', &mTotalScoreRecord->mTotalPikis, 10000);
	setNumberTag(screen, 'tp_4', &mTotalScoreRecord->mTotalPikis, 1000);
	setNumberTag(screen, 'tp_3', &mTotalScoreRecord->mTotalPikis, 100);
	setNumberTag(screen, 'tp_2', &mTotalScoreRecord->mTotalPikis, 10);
	setNumberTag(screen, 'tp_1', &mTotalScoreRecord->mTotalPikis, 1);

	_7C          = (P2DPicture*)screen->search('newd', true);
	mEffectMgr2D = new EffectMgr2D(0x10, 0x40, 0x40);
	mBest.init(screen);
	mBest.sleep();
	setMode(MODE_Sleep);

	STACK_PAD_VAR(4);
}

/*
 * --INFO--
 * Address:	801F44F8
 * Size:	0001D4
 */
bool zen::DrawTotalScore::update(Controller* controller)
{
	bool res = false;
	switch (mMode) {
	case MODE_Start:
		_04 += gsys->getFrameTime();
		if (_04 > _08) {
			setMode(MODE_Appear);
		} else {
			f32 t = 1.0f - NMathF::sin(_04 / _08 * HALF_PI);
			mResultScreen->getScreenPtr()->move(0, RoundOff(-960.0f * t));
			mResultScreen->getScreenPtr()->setScale(t + 1.0f);
			mResultScreen->getScreenPtr()->rotateX(PI * t);
			if (mResultScreen->getScreenPtr()->getRotate() > HALF_PI) {
				mResultScreen->getScreenPtr()->hide();
			} else {
				mResultScreen->getScreenPtr()->show();
			}
		}
		break;

	case MODE_Appear:
		_04 += gsys->getFrameTime();
		if (_04 > _08) {
			setMode(MODE_Operation);
		}
		break;

	case MODE_Operation:
		res = true;
		break;
	}
	mResultScreen->update();
	mEffectMgr2D->update();
	mBest.update();
	return res;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void zen::DrawTotalScore::draw(Graphics& gfx)
{
	mResultScreen->draw();
	mEffectMgr2D->draw(gfx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void zen::DrawTotalScore::sleep()
{
	mEffectMgr2D->killAll(true);
	setMode(MODE_Sleep);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void zen::DrawTotalScore::start()
{
	mEffectMgr2D->killAll(true);
	setMode(MODE_Start);
}

/*
 * --INFO--
 * Address:	801F46CC
 * Size:	000138
 */
void zen::DrawTotalScore::setMode(zen::DrawTotalScore::modeFlag mode)
{
	mMode = mode;
	switch (mMode) {
	case MODE_Sleep:
		_08 = 0.0f;
		_04 = 0.0f;
		mBest.sleep();
		mResultScreen->getScreenPtr()->hide();
		break;

	case MODE_Start:
		_04 = 0.0f;
		_08 = 2.0f;
		mBest.sleep();
		mResultScreen->makeResident();
		mResultScreen->getScreenPtr()->show();
		mResultScreen->getScreenPtr()->move(0, -960);
		break;

	case MODE_Appear:
		_04 = 0.0f;
		_08 = 2.0f;
		mBest.appear();
		setRankInEffect();
		setRankInColor();
		playRankInFanfare();
		mResultScreen->getScreenPtr()->show();
		break;

	case MODE_Operation:
		mResultScreen->getScreenPtr()->show();
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void zen::DrawTotalScore::setEffect(P2DPane* pane, int effID)
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
	mEffectMgr2D->create(effID, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	801F4804
 * Size:	000004
 */
void zen::DrawTotalScore::playRankInFanfare()
{
}

/*
 * --INFO--
 * Address:	801F4808
 * Size:	0006EC
 */
void zen::DrawTotalScore::setRankInEffect()
{
	if (mTotalScoreRecord->mPartsDaysRank >= 0 && mTotalScoreRecord->mPartsDaysRank < 5) {
		setEffect(_14[0], 2);
		setEffect(_14[0], 3);
		setEffect(_14[1], 2);
		setEffect(_14[1], 3);
	}
	if (mTotalScoreRecord->mBornPikisRank >= 0 && mTotalScoreRecord->mBornPikisRank < 5) {
		setEffect(_14[2], 0);
		setEffect(_14[2], 1);
	}

	if (mTotalScoreRecord->mDeadPikisRank >= 0 && mTotalScoreRecord->mDeadPikisRank < 5) {
		setEffect(_14[3], 0);
		setEffect(_14[3], 1);
	}
}

/*
 * --INFO--
 * Address:	801F4EF4
 * Size:	0001D4
 */
void zen::DrawTotalScore::setRankInColor()
{
	Colour color;
	color = _7C->getWhite();
	s16 a = mTotalScoreRecord->mPartsDaysRank;
	if (a >= 0 && a < 5) {
		mPartsDaysRecordPanes[a]->setCharColor(color);
		mPartsDaysRecordPanes[a]->setGradColor(color);
		mPartsNumLeft->setWhite(color);
		mPartsNumRight->setWhite(color);
		mDaysNumLeft->setWhite(color);
		mDaysNumRight->setWhite(color);
		_B0->setWhite(color);
		_B4->setCharColor(color);
		_B4->setGradColor(color);
		_B8->setCharColor(color);
		_B8->setGradColor(color);
	}
	s16 b = mTotalScoreRecord->mBornPikisRank;
	if (b >= 0 && b < 5) {
		mLivingPikiRecordPanes[b]->setCharColor(color);
		mLivingPikiRecordPanes[b]->setGradColor(color);
		mLivingPikisThousands->setWhite(color);
		mLivingPikisHundreds->setWhite(color);
		mLivingPikisTens->setWhite(color);
		mLivingPikisOnes->setWhite(color);
		_BC->setCharColor(color);
		_BC->setGradColor(color);
	}
	s16 c = mTotalScoreRecord->mDeadPikisRank;
	if (c >= 0 && c < 5) {
		mDeadPikiRecordPanes[c]->setCharColor(color);
		mDeadPikiRecordPanes[c]->setGradColor(color);
		mDeadPikisThousands->setWhite(color);
		mDeadPikisHundreds->setWhite(color);
		mDeadPikisTens->setWhite(color);
		mDeadPikisOnes->setWhite(color);
		_C0->setCharColor(color);
		_C0->setGradColor(color);
	}
}

/*
 * --INFO--
 * Address:	801F50C8
 * Size:	000070
 */
zen::DrawFinalResult::DrawFinalResult(zen::TotalScoreRecord* record)
{
	mScoreScreen = new DrawTotalScore(record);
}

/*
 * --INFO--
 * Address:	801F5138
 * Size:	0001A4
 */
bool zen::DrawFinalResult::update(Controller* controller)
{
	bool res = false;
	switch (mMode) {
	case MODE_Sleep:
		mScoreScreen->sleep();
		break;

	case MODE_Start:
		if (mScoreScreen->update(controller)) {
			setMode(MODE_Scores);
		}
		break;

	case MODE_Scores:
		if (controller->keyClick(KBBTN_START | KBBTN_A)) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
			setMode(MODE_Parts);
		} else {
			mScoreScreen->update(controller);
		}
		break;

	case MODE_Parts:
		if (mUfoPartsScreen.update(controller)) {
			switch (mUfoPartsScreen.getReturnStatusFlag()) {
			case DrawUfoParts::RETSTATE_Unk1:
				setMode(MODE_Scores);
				break;

			case DrawUfoParts::RETSTATE_Unk2:
				setMode(MODE_SaveStart);
				break;
			}
		}
		break;

	case MODE_SaveStart:
		if (mSaveScreen.update(controller)) {
			switch (mSaveScreen.getModeFlag()) {
			case DrawOptionSave::MODE_Unk6:
				setMode(MODE_SaveSuccess);
				break;

			case DrawOptionSave::MODE_Unk7:
				setMode(MODE_SaveStart);
				break;

			case DrawOptionSave::MODE_Unk8:
				setMode(MODE_PartsFromSave);
				break;

			case DrawOptionSave::MODE_Unk9:
				setMode(MODE_SaveSuccess);
				break;

			default:
				PRINT("ERR! Illegal mode: %d \n", mSaveScreen.getModeFlag());
				ERROR("ERR! Illegal mode: %d \n", mSaveScreen.getModeFlag());
				break;
			}
		}
		break;

	case MODE_SaveSuccess:
		res = true;
		break;

	case MODE_PartsFromSave:
		break;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801F52DC
 * Size:	000138
 */
void zen::DrawFinalResult::draw(Graphics& gfx)
{
	switch (mMode) {
	case MODE_Start:
		mSaveScreen.init();
		mScoreScreen->draw(gfx);
		break;

	case MODE_Scores:
		mScoreScreen->draw(gfx);
		break;

	case MODE_Parts:
		if (mUfoPartsScreen.getModeFlag() != DrawUfoParts::MODE_FadeOut
		    || mUfoPartsScreen.getReturnStatusFlag() == DrawUfoParts::RETSTATE_Unk1) {
			mScoreScreen->draw(gfx);
		}
		mUfoPartsScreen.draw(gfx);
		break;

	case MODE_SaveStart:
		mUfoPartsScreen.draw(gfx);
		mSaveScreen.draw(gfx);
		break;

	case MODE_SaveSuccess:
		mUfoPartsScreen.draw(gfx);
		mSaveScreen.draw(gfx);
		break;

	case MODE_Sleep:
	case MODE_PartsFromSave:
		break;
	}
}

/*
 * --INFO--
 * Address:	801F5414
 * Size:	000024
 */
void zen::DrawFinalResult::start()
{
	setMode(MODE_Start);
}

/*
 * --INFO--
 * Address:	801F5438
 * Size:	0000C8
 */
void zen::DrawFinalResult::setMode(zen::DrawFinalResult::modeFlag mode)
{
	mMode = mode;
	switch (mMode) {
	case MODE_Sleep:
		mScoreScreen->sleep();
		mUfoPartsScreen.sleep();
		break;

	case MODE_Start:
		mScoreScreen->start();
		break;

	case MODE_Parts:
		mUfoPartsScreen.start();
		break;

	case MODE_SaveStart:
		mSaveScreen.start();
		break;

	case MODE_PartsFromSave:
		mUfoPartsScreen.operation();
		mMode = MODE_Parts;
		break;

	case MODE_Scores:
	case MODE_SaveSuccess:
		break;
	}
}
