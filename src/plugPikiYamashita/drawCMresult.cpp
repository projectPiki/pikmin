#include "DebugLog.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "nlib/Math.h"
#include "zen/DrawCM.h"
#include "zen/DrawSave.h"
#include "zen/EffectMgr2D.h"
#include "zen/Number.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(14)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("drawCMresult")

/**
 * @todo: Documentation
 */
zen::DrawCMresult::DrawCMresult()
{
	mEffectMgr2D  = new EffectMgr2D(8, 0x80, 0x80);
	mResultScreen = new DrawScreen("screen/blo/cha_re.blo", nullptr, true, true);
	mScoreScreen  = new DrawScreen("screen/blo/cha_rank.blo", nullptr, true, true);
	mBestScreen   = new DrawScreen("screen/blo/cha_best.blo", nullptr, true, true);

	P2DScreen* titleScreen = mResultScreen->getScreenPtr();
	P2DScreen* scoreScreen = mScoreScreen->getScreenPtr();
	P2DScreen* bestScreen  = mBestScreen->getScreenPtr();

	mOptionSave = new DrawOptionSave();
	scoreScreen->search('rank', true)->move(338, 102);
	bestScreen->search('best', true)->move(433, 44);

	mTitleObj.init(titleScreen);
	mScoreMgr.init(scoreScreen);
	mBest.init(bestScreen);

	_94 = 0.0f;
	_84 = 0;
	_88 = 0;
	_8C = -1;

	P2DPane* pane = titleScreen->search('bigl', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &_88, 100, false));

	pane = titleScreen->search('bigc', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &_88, 10, false));

	pane = titleScreen->search('bigr', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &_88, 1, false));

	pane = titleScreen->search('sbil', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &_88, 100, true));

	pane = titleScreen->search('sbic', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &_88, 10, true));

	pane = titleScreen->search('sbir', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &_88, 1, true));

	mResultGraph = new DrawCMresultGraph(titleScreen);

	setMode(MODE_Sleep);
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMresult::update(Controller* controller)
{
	bool res = false;
	if ((this->*mModeFunction)(controller)) {
		res = true;
	}
	if (mMode != MODE_Save) {
		mResultScreen->update();
		mScoreScreen->update();
		mBestScreen->update();
		mTitleObj.update();
		mScoreMgr.update();
		mBest.update();
		mEffectMgr2D->update();
		mResultGraph->update();
	}
	return res;
}

/**
 * @todo: Documentation
 */
void zen::DrawCMresult::draw(Graphics& gfx)
{
	mResultScreen->draw();
	mScoreScreen->draw();
	mBestScreen->draw();
	mResultGraph->draw();
	mEffectMgr2D->draw(gfx);
	mOptionSave->draw(gfx);
}

/**
 * @todo: Documentation
 */
void zen::DrawCMresult::start(const GameChalQuickInfo& chalInfo)
{
	mEffectMgr2D->killAll(true);
	mTitleObj.wait(0.0f);
	mBest.hide();
	mScoreMgr.sleep();
	u32 i;
	for (i = 0; i < 5; i++) {
		mScoreMgr.setScore(i, chalInfo.mCourseScores[i]);
	}

	_84 = chalInfo.mScore;
	_88 = 0;
	_8C = chalInfo.mRank;

	setMode(MODE_WaitAppear);

	char buf[8];
	for (i = 0; i < 5; i++) {
		sprintf(buf, "p_m%d", i);
		P2DPane* pane = mResultScreen->getScreenPtr()->search(P2DPaneLibrary::makeTag(buf), true);
		if (i == chalInfo.mStageID) {
			pane->show();
		} else {
			pane->hide();
		}
	}

	mOptionSave->init();
	makeResident();
	mResultGraph->init();
}

/**
 * @todo: Documentation
 */
void zen::DrawCMresult::makeResident()
{
	mResultScreen->makeResident();
	mScoreScreen->makeResident();
	mBestScreen->makeResident();
	NumberTex::makeResident();
}

/**
 * @todo: Documentation
 */
void zen::DrawCMresult::setMode(zen::DrawCMresult::modeFlag mode)
{
	mMode = mode;
	switch (mMode) {
	case MODE_Sleep:
		mModeFunction = &modeSleep;
		break;

	case MODE_WaitAppear:
		_94           = 0.0f;
		mModeFunction = &modeWaitAppear;
		mResultScreen->getScreenPtr()->move(0, -480);
		break;

	case MODE_Appear:
		_94           = 0.0f;
		mModeFunction = &modeAppear;
		break;

	case MODE_Operation:
		if (_84 == 0) {
			mScoreMgr.appear(1.0f);
		}
		mModeFunction = &modeOperation;
		break;

	case MODE_Save:
		mOptionSave->start();
		mModeFunction = &modeSave;
		break;

	case MODE_Unk5:
		mMode         = MODE_Operation;
		mModeFunction = &modeOperation;
		break;
	}
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMresult::modeSleep(Controller*)
{
	return false;
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMresult::modeWaitAppear(Controller*)
{
	_94 += gsys->getFrameTime();
	if (_94 > 0.1f) {
		setMode(MODE_Appear);
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMresult::modeAppear(Controller*)
{
	_94 += gsys->getFrameTime();
	f32 vertPosFactor;
	f32 limit = 1.0f;
	if (_94 > limit) {
		_94           = limit;
		vertPosFactor = 0.0f;
		setMode(MODE_Operation);
	} else {
		vertPosFactor = 1.0f - NMathF::sin(_94 / limit * HALF_PI);
	}
	mResultScreen->getScreenPtr()->move(0, RoundOff(-480.0f * vertPosFactor));
	return false;
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMresult::modeOperation(Controller* controller)
{
	if (_88 < _84) {
		if (controller->keyClick(KBBTN_START | KBBTN_A)) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
			_88 = _84;
			mScoreMgr.appear(1.0f);
		} else {
			_88++;
			if (_88 == _84) {
				mScoreMgr.appear(1.0f);
			}
		}

		SeSystem::playSysSe(SYSSE_CMENU_SELECT);
	} else if (mScoreMgr.getEventFlag() & 0x2) {
		if (controller->keyClick(KBBTN_START | KBBTN_A)) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
#if defined(VERSION_PIKIDEMO)
			gsys->forceHardReset();
#else
			setMode(MODE_Save);
#endif
		}
	} else if (mScoreMgr.getEventFlag() & 0x1) {
		mBest.appear();
		mResultGraph->appear();
		createRankInEffect();
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMresult::modeSave(Controller* controller)
{
	bool res = false;
	if (mOptionSave->update(controller)) {
		switch (mOptionSave->getModeFlag()) {
		case DrawOptionSave::MODE_Unk6:
			res = true;
			break;

		case DrawOptionSave::MODE_Unk7:
			setMode(MODE_Save);
			break;

		case DrawOptionSave::MODE_Unk8:
			setMode(MODE_Unk5);
			break;

		case DrawOptionSave::MODE_Unk9:
			res = true;
			break;

		default:
			PRINT("Illegal mode:%d \n", mOptionSave->getModeFlag());
			ERROR("Illegal mode:%d \n", mOptionSave->getModeFlag());
			break;
		}
	}

	return res;
}

/**
 * @todo: Documentation
 */
void zen::DrawCMresult::createRankInEffect()
{
	if (_8C >= 0) {
		P2DPane* pane = mResultScreen->getScreenPtr()->search('bi_w', true);
		mEffectMgr2D->create(EFF2D_Unk14,
		                     Vector3f(pane->getPosH() + (pane->getWidth() >> 1), 480 - (pane->getPosV() + (pane->getHeight() >> 1)), 0.0f),
		                     nullptr, nullptr);
		mEffectMgr2D->create(EFF2D_Unk13,
		                     Vector3f(pane->getPosH() + (pane->getWidth() >> 1), 480 - (pane->getPosV() + (pane->getHeight() >> 1)), 0.0f),
		                     nullptr, nullptr);
		mEffectMgr2D->create(EFF2D_Unk12,
		                     Vector3f(pane->getPosH() + (pane->getWidth() >> 1), 480 - (pane->getPosV() + (pane->getHeight() >> 1)), 0.0f),
		                     nullptr, nullptr);

		int x, y;
		char buf[8];
		sprintf(buf, "m%d_w", _8C + 1);
		pane = mScoreScreen->getScreenPtr()->search(P2DPaneLibrary::makeTag(buf), true);
		P2DPaneLibrary::getWorldPos(pane, &x, &y);
		x += pane->getWidth() >> 1;
		y += pane->getHeight() >> 1;

		mEffectMgr2D->create(EFF2D_Unk16, Vector3f(x, 480 - y, 0.0f), nullptr, nullptr);
		mEffectMgr2D->create(EFF2D_Unk15, Vector3f(x, 480 - y, 0.0f), nullptr, nullptr);

		SeSystem::playSysSe(SYSSE_CHG_HISCORE);
	}
}
