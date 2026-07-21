#include "zen/ogNitaku.h"
#include "DebugLog.h"
#include "P2D/Screen.h"
#include "SoundMgr.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/TextColorCallBack.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("OgNitakuSection")

/**
 * @todo: Documentation
 */
zen::ogNitakuMgr::ogNitakuMgr(P2DScreen* screen, P2DTextBox* text1, P2DTextBox* text2, P2DTextBox* text3, bool startYes, bool canCancel)
{
	mScreen = screen;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
#else
	mTextBoxA = text1;
	mTextBoxB = text2;
#endif
	P2DPane* pane_l0 = mScreen->search('i00l', true);
	P2DPane* pane_r0 = mScreen->search('i00r', true);
	P2DPane* pane_l1 = mScreen->search('i01l', true);
	P2DPane* pane_r1 = mScreen->search('i01r', true);
	pane_l0->hide();
	pane_r0->hide();
	pane_l1->hide();
	pane_r1->hide();
	mYesLeftCursorX  = pane_l0->getPosH();
	mYesLeftCursorY  = pane_l0->getPosV();
	mNoLeftCursorX   = pane_l1->getPosH();
	mNoLeftCursorY   = pane_l1->getPosV();
	mYesRightCursorX = pane_r0->getPosH();
	mYesRightCursorY = pane_r0->getPosV();
	mNoRightCursorX  = pane_r1->getPosH();
	mNoRightCursorY  = pane_r1->getPosV();
	mRootPane = mScreen->search('root', true);
	PRINT("Yes(%f, %f)  No(%f,%f)\n", mNoLeftCursorX, mNoLeftCursorY, mNoRightCursorX, mNoRightCursorY);
	mLeftCursorMgr.init(mScreen, mRootPane, 'z00l', mNoLeftCursorX, mNoLeftCursorY);
	mRightCursorMgr.init(mScreen, mRootPane, 'z00r', mNoRightCursorX, mNoRightCursorY);
	cursorDisable(0.001f);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	mMesgColorA = new TextColorCallBack(text1);
	text1->setCallBack(mMesgColorA);
	mMesgColorB = new TextColorCallBack(text2);
	text2->setCallBack(mMesgColorB);
	mSelectedTextCharColor = text3->getCharColor();
	mSelectedTextGradColor = text3->getGradColor();
	mUnselectedTextCharColor = text1->getCharColor();
	mUnselectedTextGradColor = text1->getGradColor();
#else
	mMesgColorA = new TextColorCallBack(mTextBoxA);
	mTextBoxA->setCallBack(mMesgColorA);
	mMesgColorB = new TextColorCallBack(mTextBoxB);
	mTextBoxB->setCallBack(mMesgColorB);
	mSelectedTextCharColor = text3->getCharColor();
	mSelectedTextGradColor = text3->getGradColor();
	mUnselectedTextCharColor = mTextBoxA->getCharColor();
	mUnselectedTextGradColor = mTextBoxA->getGradColor();
#endif
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000088
 */
void zen::ogNitakuMgr::MoveCursorYes(f32 rate)
{
	mMesgColorA->setTargetColor(mSelectedTextCharColor, mSelectedTextGradColor, rate);
	mMesgColorB->setTargetColor(mUnselectedTextCharColor, mUnselectedTextGradColor, rate);
	mLeftCursorMgr.move(mYesLeftCursorX, mYesLeftCursorY, rate);
	mRightCursorMgr.move(mYesRightCursorX, mYesRightCursorY, rate);
	mIsYes = true;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000088
 */
void zen::ogNitakuMgr::MoveCursorNo(f32 rate)
{
	mMesgColorA->setTargetColor(mUnselectedTextCharColor, mUnselectedTextGradColor, rate);
	mMesgColorB->setTargetColor(mSelectedTextCharColor, mSelectedTextGradColor, rate);
	mLeftCursorMgr.move(mNoLeftCursorX, mNoLeftCursorY, rate);
	mRightCursorMgr.move(mNoRightCursorX, mNoRightCursorY, rate);
	mIsYes = false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000150
 */
void zen::ogNitakuMgr::InitCursor()
{
	if (mDoStartYes) {
		mIsYes = true;
		MoveCursorYes(0.001f);
		mLeftCursorMgr.initPos(mYesLeftCursorX, mYesLeftCursorY);
		mRightCursorMgr.initPos(mYesRightCursorX, mYesRightCursorY);
	} else {
		mIsYes = false;
		MoveCursorNo(0.001f);
		mLeftCursorMgr.initPos(mNoLeftCursorX, mNoLeftCursorY);
		mRightCursorMgr.initPos(mNoRightCursorX, mNoRightCursorY);
	}
	mLeftCursorMgr.initScale(0.0f);
	mRightCursorMgr.initScale(0.0f);
}

/**
 * @todo: Documentation
 */
void zen::ogNitakuMgr::start()
{
	mStatus    = Status_1;
	mWaitTimer = 0.0f;
	InitCursor();
	cursorEnable(0.2f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000154
 */
void zen::ogNitakuMgr::stop()
{
	mStatus = Status_0;
	InitCursor();
}

/**
 * @todo: Documentation
 */
void zen::ogNitakuMgr::cursorEnable(f32 rate)
{
	mLeftCursorMgr.scale(1.0f, rate);
	mRightCursorMgr.scale(1.0f, rate);
}

/**
 * @todo: Documentation
 */
void zen::ogNitakuMgr::cursorDisable(f32 rate)
{
	mLeftCursorMgr.scale(0.0f, rate);
	mRightCursorMgr.scale(0.0f, rate);
}

/**
 * @todo: Documentation
 */
zen::ogNitakuMgr::NitakuStatus zen::ogNitakuMgr::update(Controller* input)
{
	if (mStatus == 0) {
		return mStatus;
	}

	switch (mStatus) {
	case Status_1:
	{
		mWaitTimer += gsys->getFrameTime();
		if (mWaitTimer >= 0.2f) {
			mStatus = Status_3;
		}
		break;
	}
	case Exiting:
	{
		mWaitTimer += gsys->getFrameTime();
		if (mWaitTimer >= 0.2f) {
			mStatus = mStatus2;
		}
		break;
	}
	case Status_3:
	{
		if (input->keyClick(KBBTN_MSTICK_UP)) {
			if (mIsYes) {
				MoveCursorNo(0.25f);
			} else {
				MoveCursorYes(0.25f);
			}
			seSystem->playSysSe(ogEnumFix(SYSSE_MOVE1, JACSYS_Move1));
		} else if (input->keyClick(KBBTN_MSTICK_DOWN)) {
			if (mIsYes) {
				MoveCursorNo(0.25f);
			} else {
				MoveCursorYes(0.25f);
			}
			seSystem->playSysSe(ogEnumFix(SYSSE_MOVE1, JACSYS_Move1));
		} else if (input->keyClick(KBBTN_START | KBBTN_A)) {
			if (mIsYes) {
				mStatus2 = ExitSuccess;
			} else {
				mStatus2 = ExitFailure;
			}

			mWaitTimer = 0.0f;
			mStatus    = Exiting;
			cursorDisable(0.2f);
			seSystem->playSysSe(ogEnumFix(SYSSE_DECIDE1, JACSYS_Decide1));
		} else if (mCanCancel && input->keyClick(KBBTN_B)) {
			mStatus2   = Status_4;
			mWaitTimer = 0.0f;
			mStatus    = Exiting;
			cursorDisable(0.2f);
		}
		break;
	}
	}

	if (mStatus >= Status_4) {
		return mStatus;
	}

	mLeftCursorMgr.update();
	mRightCursorMgr.update();
	return mStatus;
}
