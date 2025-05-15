#include "zen/ogNitaku.h"
#include "zen/TextColorCallBack.h"
#include "P2D/Screen.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
// DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	80196864
 * Size:	0003E4
 */
zen::ogNitakuMgr::ogNitakuMgr(P2DScreen* screen, P2DTextBox* text1, P2DTextBox* text2, P2DTextBox* text3, bool startYes, bool canCancel)
{
	mScreen          = screen;
	mTextBoxA        = text1;
	mTextBoxB        = text2;
	P2DPane* pane_l0 = mScreen->search('i00l', true);
	P2DPane* pane_r0 = mScreen->search('i00r', true);
	P2DPane* pane_l1 = mScreen->search('i01l', true);
	P2DPane* pane_r1 = mScreen->search('i01r', true);
	pane_l0->hide();
	pane_r0->hide();
	pane_l1->hide();
	pane_r1->hide();
	_40       = pane_l0->getPosH();
	_44       = pane_l0->getPosV();
	_48       = pane_l1->getPosH();
	_4C       = pane_l1->getPosV();
	_80       = pane_r0->getPosH();
	_84       = pane_r0->getPosV();
	_88       = pane_r1->getPosH();
	_8C       = pane_r1->getPosV();
	mRootPane = mScreen->search('root', true);
	PRINT("Yes(%f, %f)  No(%f,%f)\n", _48, _4C, _88, _8C);
	mLeftCursorMgr.init(mScreen, mRootPane, 'z00l', _48, _4C);
	mRightCursorMgr.init(mScreen, mRootPane, 'z00r', _88, _8C);
	cursorDisable(0.001f);
	mMesgColorA = new TextColorCallBack(mTextBoxA);
	mTextBoxA->setCallBack(mMesgColorA);
	mMesgColorB = new TextColorCallBack(mTextBoxB);
	mTextBoxB->setCallBack(mMesgColorB);
	_A4         = text3->getCharColor();
	_A8         = text3->getGradColor();
	_AC         = mTextBoxA->getCharColor();
	_B0         = mTextBoxA->getGradColor();
	mDoStartYes = startYes;
	mCanCancel  = canCancel;
	mStatus     = Status_0;
	mStatus2    = Status_0;

	if (mDoStartYes) {
		mIsYes = true;
	} else {
		mIsYes = false;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void zen::ogNitakuMgr::MoveCursorYes(f32 rate)
{
	mMesgColorA->setTargetColor(_A4, _A8, rate);
	mMesgColorB->setTargetColor(_AC, _B0, rate);
	mLeftCursorMgr.move(_40, _44, rate);
	mRightCursorMgr.move(_80, _84, rate);
	mIsYes = true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void zen::ogNitakuMgr::MoveCursorNo(f32 rate)
{
	mMesgColorA->setTargetColor(_AC, _B0, rate);
	mMesgColorB->setTargetColor(_A4, _A8, rate);
	mLeftCursorMgr.move(_48, _4C, rate);
	mRightCursorMgr.move(_88, _8C, rate);
	mIsYes = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
void zen::ogNitakuMgr::InitCursor()
{
	if (mDoStartYes) {
		mIsYes = true;
		MoveCursorYes(0.001f);
		mLeftCursorMgr.initPos(_40, _44);
		mRightCursorMgr.initPos(_80, _84);
	} else {
		mIsYes = false;
		MoveCursorNo(0.001f);
		mLeftCursorMgr.initPos(_48, _4C);
		mRightCursorMgr.initPos(_88, _8C);
	}
	mLeftCursorMgr.initScale(0.0f);
	mRightCursorMgr.initScale(0.0f);
}

/*
 * --INFO--
 * Address:	80196C48
 * Size:	000168
 */
void zen::ogNitakuMgr::start()
{
	mStatus    = Status_1;
	mWaitTimer = 0.0f;
	InitCursor();
	cursorEnable(0.2f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void zen::ogNitakuMgr::stop()
{
	mStatus = Status_0;
	InitCursor();
}

/*
 * --INFO--
 * Address:	80196DB0
 * Size:	000054
 */
void zen::ogNitakuMgr::cursorEnable(f32 rate)
{
	mLeftCursorMgr.scale(1.0f, rate);
	mRightCursorMgr.scale(1.0f, rate);
}

/*
 * --INFO--
 * Address:	80196E04
 * Size:	000054
 */
void zen::ogNitakuMgr::cursorDisable(f32 rate)
{
	mLeftCursorMgr.scale(0.0f, rate);
	mRightCursorMgr.scale(0.0f, rate);
}

/*
 * --INFO--
 * Address:	80196E58
 * Size:	000344
 */
zen::ogNitakuMgr::NitakuStatus zen::ogNitakuMgr::update(Controller* input)
{
	if (mStatus == 0) {
		return mStatus;
	}

	switch (mStatus) {
	case Status_1:
		mWaitTimer += gsys->getFrameTime();
		if (mWaitTimer >= 0.2f) {
			mStatus = Status_3;
		}
		break;
	case Exiting:
		mWaitTimer += gsys->getFrameTime();
		if (mWaitTimer >= 0.2f) {
			mStatus = mStatus2;
		}
		break;
	case Status_3:
		if (input->keyClick(KBBTN_MSTICK_UP)) {
			if (mIsYes) {
				MoveCursorNo(0.25f);
			} else {
				MoveCursorYes(0.25f);
			}
			seSystem->playSysSe(SYSSE_MOVE1);
		} else if (input->keyClick(KBBTN_MSTICK_DOWN)) {
			if (mIsYes) {
				MoveCursorNo(0.25f);
			} else {
				MoveCursorYes(0.25f);
			}
			seSystem->playSysSe(SYSSE_MOVE1);
		} else if (input->keyClick(KBBTN_START | KBBTN_A)) {
			if (mIsYes) {
				mStatus2 = ExitSuccess;
			} else {
				mStatus2 = ExitFailure;
			}

			mWaitTimer = 0.0f;
			mStatus    = Exiting;
			cursorDisable(0.2f);
			seSystem->playSysSe(SYSSE_DECIDE1);
		} else if (mCanCancel && input->keyClick(KBBTN_B)) {
			mStatus2   = Status_4;
			mWaitTimer = 0.0f;
			mStatus    = Exiting;
			cursorDisable(0.2f);
		}
		break;
	}

	if (mStatus >= Status_4) {
		return mStatus;
	}

	mLeftCursorMgr.update();
	mRightCursorMgr.update();
	return mStatus;
}
