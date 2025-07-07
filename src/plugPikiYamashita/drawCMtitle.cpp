#include "DebugLog.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/DrawCM.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("drawCMtitle")

/*
 * --INFO--
 * Address:	801ED480
 * Size:	000158
 */
void zen::DrawCMtitleObj::init(P2DScreen* screen)
{
	mTitlePane = screen->search('titl', true);
	mTitlePane->setOffset(mTitlePane->getWidth() >> 1, mTitlePane->getHeight() >> 1);
	mPosition.set(mTitlePane->getPosH(), mTitlePane->getPosV(), 0.0f);
	mModeFunction = &modeSleep;
	P2DPane* mark = screen->search('mark', true);
	mark->setCallBack(new BalloonPane(mark, 3.0f));
	mEventFlag = 2;
}

/*
 * --INFO--
 * Address:	801ED5D8
 * Size:	000030
 */
void zen::DrawCMtitleObj::update()
{
	mEventFlag = 2;
	(this->*mModeFunction)();
}

/*
 * --INFO--
 * Address:	801ED608
 * Size:	00004C
 */
void zen::DrawCMtitleObj::wait(f32 p1)
{
	_20           = 0.0f;
	_24           = p1;
	_10           = 1;
	mModeFunction = &modeWait;
	mTitlePane->setScale(1.0f);
}

/*
 * --INFO--
 * Address:	801ED654
 * Size:	00004C
 */
void zen::DrawCMtitleObj::appear(f32 p1)
{
	_20           = 0.0f;
	_24           = p1;
	_10           = 0;
	mModeFunction = &modeAppear;
	mTitlePane->setScale(2.0f);
}

/*
 * --INFO--
 * Address:	801ED6A0
 * Size:	000008
 */
bool zen::DrawCMtitleObj::modeSleep()
{
	return false;
}

/*
 * --INFO--
 * Address:	801ED6A8
 * Size:	000120
 */
bool zen::DrawCMtitleObj::modeAppear()
{
	bool res = false;
	_20 += gsys->getFrameTime();
	f32 t, tComp;
	if (_20 > _24) {
		_20   = _24;
		t     = 1.0f;
		tComp = 0.0f;
		wait(0.5f);
		mEventFlag |= 0x1;
		res = true;
	} else {
		t     = _20 / _24;
		tComp = 1.0f - t;
	}

	mTitlePane->move(RoundOff(-1920.0f * t + 2560.0f * tComp), 240);
	return res;
}

/*
 * --INFO--
 * Address:	801ED7C8
 * Size:	0000E4
 */
bool zen::DrawCMtitleObj::modeWait()
{
	_20 += gsys->getFrameTime();
	f32 t, tComp;
	if (_20 > _24) {
		_20   = _24;
		t     = 1.0f;
		tComp = 0.0f;
	} else {
		t     = NMathF::sin(HALF_PI * _20 / _24);
		tComp = 1.0f - t;
	}

	mTitlePane->move((s16)mPosition.x, RoundOff(-480.0f * tComp + mPosition.y * t));
	return false;
}
