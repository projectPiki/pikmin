#include "zen/DrawContainer.h"
#include "DebugLog.h"
#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/Window.h"
#include "zen/Math.h"
#include "zen/Number.h"
#include "zen/TexAnim.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(26)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("DrawContainer")

Texture* zen::StickCallBack::pTexTable[21];
Texture* zen::ArrowCenterCallBack::pUpTex;
Texture* zen::ArrowCenterCallBack::pDownTex;

const f32 zen::WindowPaneMgr::weightPosLength  = 50.0f;
const f32 zen::WindowPaneMgr::weightPosGravity = 9.8f;

/**
 * @TODO: Documentation
 */
zen::DrawContainer::DrawContainer()
    : mZenController(nullptr)
{
	mTransferDelta         = 0;
	mDeltaPikiNum          = 0;
	mIsActive              = false;
	mColor                 = COLOR_Red;
	mInitialContainerCount = 0;
	mContainerCapacity     = 0;
	mInitialSquadCount     = 0;
	mSquadCapacity         = 0;
	mSquadTotalCount       = 0;
	mSquadTotalLimit       = 0;
	mTransferSpeed         = 0.0f;
	mFrameTimer            = 0.0f;
	mContainerPikiNum      = 0;
	mSquadPikiNum          = 0;
	mDeltaPikiNum          = 0;
	mController            = new Controller(1);
	mZenController.setContPtr(mController);

	mPerspGraph = new P2DPerspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
#if defined(VERSION_GPIP01_00)
	mScreen.set("screen/blo/conmix.blo", true);
#else
	mScreen.set("screen/blo/con01.blo", true);
#endif
	mMessageMgr    = new MessageMgr(mScreen);
	mWindowPaneMgr = new WindowPaneMgr(mScreen.search('pall', true));
	mMarkerPicture = (P2DPicture*)mScreen.search('maru', true);
	mMarkerPicture->show();
	mMarkerPicture->setAlpha(0);
	mMarkerPicture->setScale(3.0f);
	mMarkerBasePosition.x = mMarkerPicture->getPosH();
	mMarkerBasePosition.y = mMarkerPicture->getPosV();
	mMarkerPicture->setOffset(mMarkerPicture->getWidth() >> 1, mMarkerPicture->getHeight() >> 1);

	P2DPane* pane = mScreen.search('cu_l', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mContainerPikiNum, 100, false));
	pane = mScreen.search('cu_c', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mContainerPikiNum, 10, false));
	pane = mScreen.search('cu_r', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mContainerPikiNum, 1, false));
	pane = mScreen.search('cusl', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mContainerPikiNum, 100, true));
	pane = mScreen.search('cusc', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mContainerPikiNum, 10, true));
	pane = mScreen.search('cusr', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mContainerPikiNum, 1, true));

	pane = mScreen.search('cl_l', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mSquadPikiNum, 100, false));
	pane = mScreen.search('cl_c', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mSquadPikiNum, 10, false));
	pane = mScreen.search('cl_r', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mSquadPikiNum, 1, false));
	pane = mScreen.search('clsl', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mSquadPikiNum, 100, true));
	pane = mScreen.search('clsc', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mSquadPikiNum, 10, true));
	pane = mScreen.search('clsr', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mSquadPikiNum, 1, true));

	pane = mScreen.search('cc_l', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mDeltaPikiNum, 100, false));
	pane = mScreen.search('cc_c', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mDeltaPikiNum, 10, false));
	pane = mScreen.search('cc_r', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mDeltaPikiNum, 1, false));
	pane = mScreen.search('ccsl', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mDeltaPikiNum, 100, true));
	pane = mScreen.search('ccsc', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mDeltaPikiNum, 10, true));
	pane = mScreen.search('ccsr', true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, &mDeltaPikiNum, 1, true));

	pane = mScreen.search('y_c_', true);
	pane->setCallBack(new ArrowCenterCallBack(pane, this, 10.0f * PI / 180.0f));
	pane = mScreen.search('y_l_', true);
	pane->setCallBack(new ArrowLRCallBack(pane, this, 10.0f * PI / 180.0f));
	pane = mScreen.search('y_r_', true);
	pane->setCallBack(new ArrowLRCallBack(pane, this, -10.0f * PI / 180.0f));

	pane = mScreen.search('ysc_', true);
	pane->setCallBack(new ArrowCenterCallBack(pane, this, 10.0f * PI / 180.0f));
	pane = mScreen.search('ysl_', true);
	pane->setCallBack(new ArrowLRCallBack(pane, this, 10.0f * PI / 180.0f));
	pane = mScreen.search('ysr_', true);
	pane->setCallBack(new ArrowLRCallBack(pane, this, -10.0f * PI / 180.0f));

	pane = mScreen.search('cont', true);
	pane->setCallBack(new StickCallBack(pane, this));

	mPikminTextures[0]    = loadTexExp("screen/tex/p2b_64.bti", true, true);
	mPikminTextures[1]    = loadTexExp("screen/tex/p2r_64.bti", true, true);
	mPikminTextures[2]    = loadTexExp("screen/tex/p2y_64.bti", true, true);
	mWindowTextures[0]    = loadTexExp("screen/tex/ws08_160.bti", true, true);
	mWindowTextures[1]    = loadTexExp("screen/tex/ws08_red.bti", true, true);
	mWindowTextures[2]    = loadTexExp("screen/tex/ws08_yel.bti", true, true);
	mContainerTextures[0] = loadTexExp("screen/tex/p2b_c_4.bti", true, true);
	mContainerTextures[1] = loadTexExp("screen/tex/p2b_c_r.bti", true, true);
	mContainerTextures[2] = loadTexExp("screen/tex/p2b_c_y.bti", true, true);
}

/**
 * @TODO: Documentation
 */
void zen::DrawContainer::start(zen::DrawContainer::containerType color, int p2, int p3, int p4, int p5, int p6, int p7)
{
	if (!mIsActive) {
		P2DPaneLibrary::makeResident(&mScreen);
		ArrowCenterCallBack unused0;
		StickCallBack unused1;
		NumberTex unused2;

		unused0.makeResident();
		unused1.makeResident();
		NumberTex::makeResident();

		if (color > COLOR_Yellow) {
			PRINT("unknown container type %d \n", color);
			ERROR("unknown container type %d \n", color);
		}

		mIsActive              = true;
		mState                 = STATE_Wait;
		mColor                 = color;
		mInitialContainerCount = p2;
		mContainerCapacity     = p3;
		mTransferDelta         = 0;
		mDeltaPikiNum          = 0;
		mInitialSquadCount     = p4;
		mSquadCapacity         = p5;
		mSquadTotalCount       = p6;
		mSquadTotalLimit       = p7;
		mFrameTimer            = 0.0f;

		setDispParam();
		mWindowPaneMgr->init();
		mMessageMgr->init(mColor);

		P2DWindow* pane = (P2DWindow*)mScreen.search('p264', true);
		pane->setTexture(mPikminTextures[mColor]);
		P2DPicture* pic = (P2DPicture*)mScreen.search('ws8c', true);
		pic->setTexture(mWindowTextures[mColor], 0);
		pic = (P2DPicture*)mScreen.search('p2c4', true);
		pic->setTexture(mContainerTextures[mColor], 0);
		pic = (P2DPicture*)mScreen.search('ws8u', true);
		pic->setTexture(mWindowTextures[mColor], 0);
		pic = (P2DPicture*)mScreen.search('ws8l', true);
		pic->setTexture(mWindowTextures[mColor], 0);
		SeSystem::playSysSe(SYSSE_CMENU_ON);
	}
}

/**
 * @TODO: Documentation
 */
void zen::DrawContainer::setDispParam()
{
	mContainerPikiNum = mInitialContainerCount + mTransferDelta;
	mSquadPikiNum     = mInitialSquadCount - mTransferDelta;
	mDeltaPikiNum     = Abs(mTransferDelta);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
bool zen::DrawContainer::waitStatus()
{
	mFrameTimer += gsys->getFrameTime();
	if (mFrameTimer > 0.1f) {
		mFrameTimer = 0.0f;
		mState      = STATE_Start;
	}
	return false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000404
 */
bool zen::DrawContainer::startStatus()
{
	mFrameTimer += gsys->getFrameTime();
	f32 a = mFrameTimer / 0.5f;
	if (a > 1.0f) {
		a = 1.0f;
	}
	a         = -NMathF::cos(PI * a);
	f32 t     = (1.0f + a) * 0.5f;
	f32 tComp = 1.0f - t;
	mWindowPaneMgr->update(WindowPaneMgr::MODE_SlideIn, t, tComp);
	mMarkerPicture->setAlpha((200.0f * t));
	mMarkerPicture->setScale((1.0f - NMathF::cos(PI * tComp)) * 1.0f + 1.0f);
	mMarkerPicture->move(RoundOff(mMarkerBasePosition.x), RoundOff(mMarkerBasePosition.y));
	if (t == 1.0f) {
		mFrameTimer = 0.0f;
		mState      = STATE_Operation;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
bool zen::DrawContainer::operationStatus()
{
	mFrameTimer += gsys->getFrameTime() * 0.2f;
	if (mFrameTimer > TAU) {
		mFrameTimer -= TAU;
	}

	mWindowPaneMgr->update(WindowPaneMgr::MODE_Hold, 0.0f, 0.0f);
	mMarkerPicture->move(RoundOff(NMathF::sin(mFrameTimer) * 50.0f + mMarkerBasePosition.x),
	                     RoundOff(NMathF::sin(2.0f * mFrameTimer) * 30.0f + mMarkerBasePosition.y));
	if (mZenController.keyRepeat(KBBTN_MSTICK_UP) || mController->keyClick(KBBTN_MSTICK_UP)) {
		if (mController->keyClick(KBBTN_MSTICK_UP)) {
			mTransferSpeed = 1.0f;
		} else {
			if (++mTransferSpeed > 1.0f) {
				mTransferSpeed = 1.0f;
			}
		}
	} else if (mZenController.keyRepeat(KBBTN_MSTICK_DOWN) || mController->keyClick(KBBTN_MSTICK_DOWN)) {
		if (mController->keyClick(KBBTN_MSTICK_DOWN)) {
			mTransferSpeed = -1.0f;
		} else {
			if (--mTransferSpeed < -1.0f) {
				mTransferSpeed = -1.0f;
			}
		}
	} else {
		mTransferSpeed = 0.0f;
	}

	mTransferDelta += RoundOff(mTransferSpeed);

	if (mInitialSquadCount == 0 && mInitialContainerCount == 0) {
		if (mTransferDelta) {
			mMessageMgr->setMessage(MessageMgr::MSG_NothingToTransfer, 2.0f);
			mTransferDelta = 0;
			mTransferSpeed = 0.0f;
		}
	} else if (mTransferDelta > 0) {
		if (mInitialSquadCount < mTransferDelta) {
			mTransferDelta = mInitialSquadCount;
			mTransferSpeed = 0.0f;
			mMessageMgr->setMessage(MessageMgr::MSG_NotEnoughInSquad, 2.0f);
		} else if (mInitialContainerCount + mTransferDelta > mContainerCapacity) {
			mTransferDelta = mContainerCapacity - mInitialContainerCount;
			mTransferSpeed = 0.0f;
			mMessageMgr->setMessage(MessageMgr::MSG_ContainerFull, 2.0f);
		}
	} else if (mInitialContainerCount + mTransferDelta < 0) {
		mTransferDelta = -mInitialContainerCount;
		mTransferSpeed = 0.0f;
		mMessageMgr->setMessage(MessageMgr::MSG_ContainerEmpty, 2.0f);
	} else if (mInitialSquadCount - mTransferDelta > mSquadCapacity) {
		mTransferDelta = -(mSquadCapacity - mInitialSquadCount);
		mTransferSpeed = 0.0f;
		mMessageMgr->setMessage(MessageMgr::MSG_SquadCapacityFull, 2.0f);
	} else if (mSquadTotalCount - mTransferDelta > mSquadTotalLimit) {
		mTransferDelta = -(mSquadTotalLimit - mSquadTotalCount);
		mTransferSpeed = 0.0f;
		mMessageMgr->setMessage(MessageMgr::MSG_SquadTotalFull, 2.0f);
	}

	if (Abs(mTransferDelta) != mDeltaPikiNum) {
		SeSystem::playSysSe(SYSSE_CMENU_SELECT);
	}

	setDispParam();

	if (mController->keyClick(KBBTN_START | KBBTN_A)) {
		mFrameTimer = 0.0f;
		mState      = STATE_End;
		SeSystem::playSysSe(SYSSE_CMENU_OFF);
	}

	if (mController->keyClick(KBBTN_B)) {
		mFrameTimer    = 0.0f;
		mState         = STATE_End;
		mTransferDelta = 0;
		SeSystem::playSysSe(SYSSE_CMENU_OFF);
	}

	STACK_PAD_VAR(2);
	return false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000384
 */
bool zen::DrawContainer::endStatus()
{
	bool res = false;
	mFrameTimer += gsys->getFrameTime();
	f32 a = mFrameTimer / 0.5f;
	if (a > 1.0f) {
		a = 1.0f;
	}

	a         = -NMathF::cos(PI * a);
	f32 t     = (1.0f + a) * 0.5f;
	f32 tComp = 1.0f - t;
	mWindowPaneMgr->update(WindowPaneMgr::MODE_SlideOut, t, tComp);
	mMarkerPicture->setAlpha(200.0f * tComp);
	mMarkerPicture->setScale(2.0f * t + 1.0f);
	if (t == 1.0f) {
		mIsActive = false;
		res       = true;
	}
	return res;
}

/**
 * @TODO: Documentation
 */
bool zen::DrawContainer::update(int& delta)
{
	bool res = false;
	if (mIsActive) {
		mController->update();
		mZenController.update();
		switch (mState) {
		case STATE_Wait:
			res = waitStatus();
			break;

		case STATE_Start:
			res = startStatus();
			break;

		case STATE_Operation:
			res = operationStatus();
			break;

		case STATE_End:
			res = endStatus();
			break;
		}
		delta = mTransferDelta;
		mMessageMgr->update(mController, mContainerPikiNum, mSquadPikiNum);
		mScreen.update();
	} else {
		res = true;
	}

	return res;
}

/**
 * @TODO: Documentation
 */
void zen::DrawContainer::draw(Graphics& gfx)
{
	if (mIsActive) {
		mPerspGraph->setPort();
		mScreen.draw(0, 0, mPerspGraph);
	}
}
