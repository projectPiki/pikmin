#include "zen/DrawContainer.h"
#include "zen/TexAnim.h"
#include "zen/Math.h"
#include "zen/Number.h"
#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/Window.h"
#include "DebugLog.h"

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
DEFINE_PRINT("DrawContainer")

Texture* zen::StickCallBack::pTexTable[21];
Texture* zen::ArrowCenterCallBack::pUpTex;
Texture* zen::ArrowCenterCallBack::pDownTex;

const f32 zen::WindowPaneMgr::weightPosLength  = 50.0f;
const f32 zen::WindowPaneMgr::weightPosGravity = 9.8f;

/*
 * --INFO--
 * Address:	801BA600
 * Size:	002CAC
 */
zen::DrawContainer::DrawContainer()
    : mZenController(nullptr)
{
	_194              = 0;
	mDeltaPikiNum     = 0;
	_1DC              = 0;
	mColor            = COLOR_Red;
	_178              = 0;
	_17C              = 0;
	_180              = 0;
	_184              = 0;
	_188              = 0;
	_18C              = 0;
	_190              = 0.0f;
	_170              = 0.0f;
	mContainerPikiNum = 0;
	mSquadPikiNum     = 0;
	mDeltaPikiNum     = 0;
	mController       = new Controller(1);
	mZenController.setContPtr(mController);

	mPerspGraph = new P2DPerspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	mScreen.set("screen/blo/con01.blo", true);
	mMessageMgr    = new MessageMgr(mScreen);
	mWindowPaneMgr = new WindowPaneMgr(mScreen.search('pall', true));
	_1A8           = (P2DPicture*)mScreen.search('maru', true);
	_1A8->show();
	_1A8->setAlpha(0);
	_1A8->setScale(3.0f);
	_1AC.x = _1A8->getPosH();
	_1AC.y = _1A8->getPosV();
	_1A8->setOffset(_1A8->getWidth() >> 1, _1A8->getHeight() >> 1);

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

	_1B8[0] = loadTexExp("screen/tex/p2b_64.bti", true, true);
	_1B8[1] = loadTexExp("screen/tex/p2r_64.bti", true, true);
	_1B8[2] = loadTexExp("screen/tex/p2y_64.bti", true, true);
	_1C4[0] = loadTexExp("screen/tex/ws08_160.bti", true, true);
	_1C4[1] = loadTexExp("screen/tex/ws08_red.bti", true, true);
	_1C4[2] = loadTexExp("screen/tex/ws08_yel.bti", true, true);
	_1D0[0] = loadTexExp("screen/tex/p2b_c_4.bti", true, true);
	_1D0[1] = loadTexExp("screen/tex/p2b_c_r.bti", true, true);
	_1D0[2] = loadTexExp("screen/tex/p2b_c_y.bti", true, true);
}

/*
 * --INFO--
 * Address:	801BD5D4
 * Size:	0004B8
 */
void zen::DrawContainer::start(zen::DrawContainer::containerType color, int p2, int p3, int p4, int p5, int p6, int p7)
{
	if (!_1DC) {
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

		_1DC          = 1;
		mState        = STATE_Wait;
		mColor        = color;
		_178          = p2;
		_17C          = p3;
		_194          = 0;
		mDeltaPikiNum = 0;
		_180          = p4;
		_184          = p5;
		_188          = p6;
		_18C          = p7;
		_170          = 0.0f;

		setDispParam();
		mWindowPaneMgr->init();
		mMessageMgr->init(mColor);

		P2DWindow* pane = (P2DWindow*)mScreen.search('p264', true);
		pane->setTexture(_1B8[mColor]);
		P2DPicture* pic = (P2DPicture*)mScreen.search('ws8c', true);
		pic->setTexture(_1C4[mColor], 0);
		pic = (P2DPicture*)mScreen.search('p2c4', true);
		pic->setTexture(_1D0[mColor], 0);
		pic = (P2DPicture*)mScreen.search('ws8u', true);
		pic->setTexture(_1C4[mColor], 0);
		pic = (P2DPicture*)mScreen.search('ws8l', true);
		pic->setTexture(_1C4[mColor], 0);
		SeSystem::playSysSe(SYSSE_CMENU_ON);
	}
}

/*
 * --INFO--
 * Address:	801BDBF0
 * Size:	000038
 */
void zen::DrawContainer::setDispParam()
{
	mContainerPikiNum = _178 + _194;
	mSquadPikiNum     = _180 - _194;
	mDeltaPikiNum     = Abs(_194);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
bool zen::DrawContainer::waitStatus()
{
	_170 += gsys->getFrameTime();
	if (_170 > 0.1f) {
		_170   = 0.0f;
		mState = STATE_Start;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000404
 */
bool zen::DrawContainer::startStatus()
{
	_170 += gsys->getFrameTime();
	f32 a = _170 / 0.5f;
	if (a > 1.0f) {
		a = 1.0f;
	}
	a         = -NMathF::cos(PI * a);
	f32 t     = (1.0f + a) * 0.5f;
	f32 tComp = 1.0f - t;
	mWindowPaneMgr->update(WindowPaneMgr::MODE_Unk1, t, tComp);
	_1A8->setAlpha((200.0f * t));
	_1A8->setScale((1.0f - NMathF::cos(PI * tComp)) * 1.0f + 1.0f);
	_1A8->move(RoundOff(_1AC.x), RoundOff(_1AC.y));
	if (t == 1.0f) {
		_170   = 0.0f;
		mState = STATE_Unk2;
	}
	return false;
}

/*
 * --INFO--
 * Address:	801BDC28
 * Size:	000C20
 */
bool zen::DrawContainer::operationStatus()
{
	_170 += gsys->getFrameTime() * 0.2f;
	if (_170 > TAU) {
		_170 -= TAU;
	}

	mWindowPaneMgr->update(WindowPaneMgr::MODE_Unk2, 0.0f, 0.0f);
	_1A8->move(RoundOff(NMathF::sin(_170) * 50.0f + _1AC.x), RoundOff(NMathF::sin(2.0f * _170) * 30.0f + _1AC.y));
	if (mZenController.keyRepeat(KBBTN_MSTICK_UP) || mController->keyClick(KBBTN_MSTICK_UP)) {
		if (mController->keyClick(KBBTN_MSTICK_UP)) {
			_190 = 1.0f;
		} else {
			if (++_190 > 1.0f) {
				_190 = 1.0f;
			}
		}
	} else if (mZenController.keyRepeat(KBBTN_MSTICK_DOWN) || mController->keyClick(KBBTN_MSTICK_DOWN)) {
		if (mController->keyClick(KBBTN_MSTICK_DOWN)) {
			_190 = -1.0f;
		} else {
			if (--_190 < -1.0f) {
				_190 = -1.0f;
			}
		}
	} else {
		_190 = 0.0f;
	}

	_194 += RoundOff(_190);

	if (_180 == 0 && _178 == 0) {
		if (_194) {
			mMessageMgr->setMessage(MessageMgr::MSG_Unk9, 2.0f);
			_194 = 0;
			_190 = 0.0f;
		}
	} else if (_194 > 0) {
		if (_180 < _194) {
			_194 = _180;
			_190 = 0.0f;
			mMessageMgr->setMessage(MessageMgr::MSG_Unk7, 2.0f);
		} else if (_178 + _194 > _17C) {
			_194 = _17C - _178;
			_190 = 0.0f;
			mMessageMgr->setMessage(MessageMgr::MSG_Unk4, 2.0f);
		}
	} else if (_178 + _194 < 0) {
		_194 = -_178;
		_190 = 0.0f;
		mMessageMgr->setMessage(MessageMgr::MSG_Unk8, 2.0f);
	} else if (_180 - _194 > _184) {
		_194 = -(_184 - _180);
		_190 = 0.0f;
		mMessageMgr->setMessage(MessageMgr::MSG_Unk5, 2.0f);
	} else if (_188 - _194 > _18C) {
		_194 = -(_18C - _188);
		_190 = 0.0f;
		mMessageMgr->setMessage(MessageMgr::MSG_Unk6, 2.0f);
	}

	if (Abs(_194) != mDeltaPikiNum) {
		SeSystem::playSysSe(SYSSE_CMENU_SELECT);
	}

	setDispParam();

	if (mController->keyClick(KBBTN_START | KBBTN_A)) {
		_170   = 0.0f;
		mState = STATE_Unk3;
		SeSystem::playSysSe(SYSSE_CMENU_OFF);
	}

	if (mController->keyClick(KBBTN_B)) {
		_170   = 0.0f;
		mState = STATE_Unk3;
		_194   = 0;
		SeSystem::playSysSe(SYSSE_CMENU_OFF);
	}

	STACK_PAD_VAR(2);
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000384
 */
bool zen::DrawContainer::endStatus()
{
	bool res = false;
	_170 += gsys->getFrameTime();
	f32 a = _170 / 0.5f;
	if (a > 1.0f) {
		a = 1.0f;
	}

	a         = -NMathF::cos(PI * a);
	f32 t     = (1.0f + a) * 0.5f;
	f32 tComp = 1.0f - t;
	mWindowPaneMgr->update(WindowPaneMgr::MODE_Unk3, t, tComp);
	_1A8->setAlpha(200.0f * tComp);
	_1A8->setScale(2.0f * t + 1.0f);
	if (t == 1.0f) {
		_1DC = 0;
		res  = true;
	}
	return res;
}

/*
 * --INFO--
 * Address:	801BE848
 * Size:	00052C
 */
bool zen::DrawContainer::update(int& p1)
{
	bool res = false;
	if (_1DC) {
		mController->update();
		mZenController.update();
		switch (mState) {
		case STATE_Wait:
			res = waitStatus();
			break;

		case STATE_Start:
			res = startStatus();
			break;

		case STATE_Unk2:
			res = operationStatus();
			break;

		case STATE_Unk3:
			res = endStatus();
			break;
		}
		p1 = _194;
		mMessageMgr->update(mController, mContainerPikiNum, mSquadPikiNum);
		mScreen.update();
	} else {
		res = true;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801BF138
 * Size:	00005C
 */
void zen::DrawContainer::draw(Graphics& gfx)
{
	if (_1DC) {
		mPerspGraph->setPort();
		mScreen.draw(0, 0, mPerspGraph);
	}
}
