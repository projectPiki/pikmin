#include "zen/DrawHurryUp.h"
#include "DebugLog.h"
#include "Interface.h"
#include "MoviePlayer.h"
#include "PlayerState.h"
#include "gameflow.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/Math.h"

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
DEFINE_PRINT("drawHurryUp")

/*
 * --INFO--
 * Address:	801C049C
 * Size:	000308
 */
zen::DrawHurryUp::DrawHurryUp()
{
	mMode      = MODE_Start;
	mIsVisible = false;
	mScreen.set("screen/blo/sund.blo", true);
	mPerspGraph = new P2DPerspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);

	mModeTimer         = 0.0f;
	mModeDuration      = 1.0f;
	mRootScale         = 0.75f;
	_10C               = 1;
	mRootPane          = mScreen.search('root', true);
	mMovingHurryUpPane = (P2DPicture*)mScreen.search('hurr', true);
	mMovingSundownPane = (P2DPicture*)mScreen.search('sund', true);
	mFixedHurryUpPane  = (P2DPicture*)mScreen.search('hur2', true);
	mFixedSundownPane  = (P2DPicture*)mScreen.search('sun2', true);
	mMsgHaloPane       = (P2DPicture*)mScreen.search('sunl', true);
	mMsgFillPane       = (P2DPicture*)mScreen.search('sunw', true);

	mHurryUpDefaultPos.set(mMovingHurryUpPane->getPosH(), mMovingHurryUpPane->getPosV(), 0.0f);
	mSundownDefaultPos.set(mMovingSundownPane->getPosH(), mMovingSundownPane->getPosV(), 0.0f);
	mHaloDefaultPos.set(mMsgHaloPane->getPosH(), mMsgHaloPane->getPosV(), 0.0f);
	initPanes();
}

/*
 * --INFO--
 * Address:	801C07A4
 * Size:	000110
 */
void zen::DrawHurryUp::initPanes()
{
	mRootPane->setOffset(mRootPane->getWidth() >> 1, mRootPane->getHeight() >> 1);
	mRootPane->setScale(mRootScale);
	mFixedHurryUpPane->setAlpha(0);
	mFixedSundownPane->setAlpha(0);

	mMovingHurryUpPane->move(mMovingHurryUpPane->getPosH() - 700, mMovingHurryUpPane->getPosV()); // start offscreen left
	mMovingHurryUpPane->setAlpha(100);
	mMovingSundownPane->move(mMovingSundownPane->getPosH() + 700, mMovingSundownPane->getPosV()); // start offscreen right
	mMovingSundownPane->setAlpha(100);

	mMsgHaloPane->setAlpha(0);
	mMsgHaloPane->move(mHaloDefaultPos);

	mMsgFillPane->setAlpha(0);
}

/*
 * --INFO--
 * Address:	801C08B4
 * Size:	00012C
 */
void zen::DrawHurryUp::start(zen::DrawHurryUp::messageTypeFlag)
{
	mIsVisible    = true;
	mMode         = MODE_Start;
	mModeTimer    = 0.0f;
	mModeDuration = 0.5f;
	initPanes();
}

/*
 * --INFO--
 * Address:	801C09E0
 * Size:	0001AC
 */
void zen::DrawHurryUp::startStatus()
{
	mModeTimer += gsys->getFrameTime();
	f32 t = mModeTimer / mModeDuration; // duration 0.5s
	if (t > 1.0f) {
		t = 1.0f;
	}
	f32 tComp = 1.0f - t;
	mMovingHurryUpPane->move((mHurryUpDefaultPos.x - 700.0f) * t + (mHurryUpDefaultPos.x + 700.0f) * tComp, RoundOff(mHurryUpDefaultPos.y));
	mMovingSundownPane->move((mSundownDefaultPos.x + 700.0f) * t + (mSundownDefaultPos.x - 700.0f) * tComp, RoundOff(mSundownDefaultPos.y));

	if (t > 0.5f) {
		u8 alpha = (t - 0.5f) * 510.0f; // max 255 when t = 1
		mFixedHurryUpPane->setAlpha(alpha);
		mFixedSundownPane->setAlpha(alpha);
	}
	if (t == 1.0f) {
		mModeTimer    = 0.0f;
		mModeDuration = 0.1f;
		mMode         = MODE_Enlarge;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void zen::DrawHurryUp::enlargeStatus()
{
	mModeTimer += gsys->getFrameTime();
	f32 t = mModeTimer / mModeDuration; // duration 0.1s
	if (t > 1.0f) {
		t = 1.0f;
	}
	f32 tmp = -NMathF::cos(PI * t);
	mRootPane->setScale((1.0f - mRootScale) * ((1.0f + tmp) * 0.5f) + mRootScale);
	if (t == 1.0f) {
		mModeTimer    = 0.0f;
		mModeDuration = 0.5f;
		mMode         = MODE_BrightShot;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void zen::DrawHurryUp::brightShotStatus()
{
	mModeTimer += gsys->getFrameTime();
	f32 t = mModeTimer / mModeDuration; // duration 0.5s
	if (t > 1.0f) {
		t = 1.0f;
	}
	f32 tmp = -NMathF::cos(PI * t);
	mMsgHaloPane->setAlpha((1.0f - NMathF::cos(TAU * ((1.0f + tmp) * 0.5f))) * 50.0f);
	mMsgHaloPane->moveZ(-200.f * t);
	if (t == 1.0f) {
		mModeTimer    = 0.0f;
		mModeDuration = 2.5f;
		mMode         = MODE_Bright;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::DrawHurryUp::brightStatus()
{
	mModeTimer += gsys->getFrameTime();
	f32 t = mModeTimer / mModeDuration; // duration 2.5s
	if (t > 1.0f) {
		t = 1.0f;
	}
	f32 tmp  = -NMathF::cos(PI * t);
	u8 alpha = (1.0f - NMathF::cos(PI * ((1.0f + tmp) * 0.5f))) * 127.5f;
	mMsgHaloPane->moveZ(0.0f);
	mMsgHaloPane->setAlpha(alpha);
	mMsgFillPane->setAlpha(alpha);
	if (t == 1.0f) {
		mModeTimer    = 0.0f;
		mModeDuration = 0.5f;
		mMode         = MODE_End;
	}
}

/*
 * --INFO--
 * Address:	801C0B8C
 * Size:	0001F8
 */
bool zen::DrawHurryUp::endStatus()
{
	bool res = false;
	mModeTimer += gsys->getFrameTime();
	f32 t = mModeTimer / mModeDuration;
	if (t > 1.0f) {
		t = 1.0f;
	}
	f32 tmp   = -NMathF::cos(PI * t);
	f32 tComp = (1.0f + tmp) * 0.5f;
	u8 alpha  = (1.0f + NMathF::cos(PI * tComp)) * 127.5f;
	mMsgHaloPane->setAlpha(alpha);
	mMsgHaloPane->move(mHaloDefaultPos.x, RoundOff(mHaloDefaultPos.y * (1.0f - t) + (mHaloDefaultPos.y + 20.0f) * t), -1000.0f * t);
	mMsgFillPane->setAlpha(alpha);
	mFixedHurryUpPane->setAlpha(alpha);
	mFixedSundownPane->setAlpha(alpha);
	if (t == 1.0f) {
		mIsVisible = false;
		res        = true;
		if (playerState && !gameflow.mMoviePlayer->mIsActive && !playerState->mDemoFlags.isFlag(DEMOFLAG_FirstHurryUp)
		    && !playerState->mDemoFlags.isFlag(DEMOFLAG_FirstHurryUp)) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_FirstHurryUp);
			gameflow.mGameInterface->message(0, 19);
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	801C0D84
 * Size:	0002C0
 */
bool zen::DrawHurryUp::update()
{
	bool res = false;
	if (mIsVisible) {
		switch (mMode) {
		case MODE_Start:
			startStatus();
			break;

		case MODE_Enlarge:
			enlargeStatus();
			break;

		case MODE_BrightShot:
			brightShotStatus();
			break;

		case MODE_Bright:
			brightStatus();
			break;

		case MODE_End:
			res = endStatus();
			break;
		}
		mScreen.update();
	}

	return res;
}

/*
 * --INFO--
 * Address:	801C1044
 * Size:	00005C
 */
void zen::DrawHurryUp::draw(Graphics&)
{
	if (mIsVisible) {
		mPerspGraph->setPort();
		mScreen.draw(0, 0, mPerspGraph);
	}
}
