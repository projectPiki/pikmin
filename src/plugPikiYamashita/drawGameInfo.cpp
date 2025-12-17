#include "zen/DrawGameInfo.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "NaviMgr.h"
#include "P2D/Graph.h"
#include "PUT/Geometry.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/Graphics.h"
#include "zen/Math.h"
#include "zen/Number.h"
#include "zen/ogSub.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(38)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("drawGameInfo")

namespace {

const char* pikiTexNametable[19] = {
	"screen/tex/piki0.bti",   "screen/tex/bp_l64.bti",  "screen/tex/bp_b64.bti",  "screen/tex/bp_f64.bti",  "screen/tex/bp_lb64.bti",
	"screen/tex/bp_bb64.bti", "screen/tex/bp_fb64.bti", "screen/tex/rp_l64.bti",  "screen/tex/rp_b64.bti",  "screen/tex/rp_f64.bti",
	"screen/tex/rp_lb64.bti", "screen/tex/rp_bb64.bti", "screen/tex/rp_fb64.bti", "screen/tex/yp_l64.bti",  "screen/tex/yp_b64.bti",
	"screen/tex/yp_f64.bti",  "screen/tex/yp_lb64.bti", "screen/tex/yp_bb64.bti", "screen/tex/yp_fb64.bti",
};

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct PikiIconCallBack : public P2DPaneCallBack {
	PikiIconCallBack(P2DPane* pane)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		mFrameTimer     = frameMax;
		for (int i = 0; i < 19; i++) {
			Texture* tex     = zen::loadTexExp(pikiTexNametable[i], true, true);
			mPikiTextures[i] = tex;
			if (!tex) {
				PRINT("Can't load texture [%s] \n", pikiTexNametable[i]);
				ERROR("Can't load texture [%s] \n", pikiTexNametable[i]);
			}
		}
		pic->setTexture(mPikiTextures[0], 0);
		pic->setOffset(pic->getWidth() >> 1, pic->getHeight() >> 1);
		mNextThrowType = 0;
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		mFrameTimer += gsys->getFrameTime();
		if (mFrameTimer > frameMax) {
			mFrameTimer = frameMax;
		}

		f32 t  = mFrameTimer / frameMax;
		f32 t2 = (1.0f - t) * 0.2f;
		pane->setScale(NMathF::cos(2.0f * TAU * t) * t2 + 1.0f);
		if (zen::pGameInfo->mEncodedNextThrowType < 0 || zen::pGameInfo->mEncodedNextThrowType >= 19) {
			zen::pGameInfo->mEncodedNextThrowType = 0;
		}

		static_cast<P2DPicture*>(pane)->setTexture(mPikiTextures[zen::pGameInfo->mEncodedNextThrowType], 0);
		if (mNextThrowType != zen::pGameInfo->mEncodedNextThrowType && zen::pGameInfo->mEncodedNextThrowType != 0) {
			mFrameTimer = 0.0f;
		}

		mNextThrowType = zen::pGameInfo->mEncodedNextThrowType;
		return true;
	}

	static const f32 frameMax;

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	f32 mFrameTimer;            // _04
	Texture* mPikiTextures[19]; // _08
	int mNextThrowType;         // _54
};

const f32 PikiIconCallBack::frameMax = 0.5f;

/**
 * @brief TODO
 */
struct DateCallBack : public P2DPaneCallBack, public zen::NumberTex {
	DateCallBack(P2DPane* cPane, P2DPane* lPane, P2DPane* rPane, P2DPane* scPane, P2DPane* slPane, P2DPane* srPane)
	    : P2DPaneCallBack(nullptr, PANETYPE_Pane)
	{
		checkPaneType(cPane, PANETYPE_Picture);
		checkPaneType(lPane, PANETYPE_Picture);
		checkPaneType(rPane, PANETYPE_Picture);
		checkPaneType(scPane, PANETYPE_Picture);
		checkPaneType(slPane, PANETYPE_Picture);
		checkPaneType(srPane, PANETYPE_Picture);

		mCentreDigit       = (P2DPicture*)cPane;
		mLeftDigit         = (P2DPicture*)lPane;
		mRightDigit        = (P2DPicture*)rPane;
		mCentreDigitShadow = (P2DPicture*)scPane;
		mLeftDigitShadow   = (P2DPicture*)slPane;
		mRightDigitShadow  = (P2DPicture*)srPane;

		setTex();
	}

	virtual bool invoke(P2DPane*) // _08
	{
		setTex();
		return true;
	}

	void setTex()
	{
		int day = gameflow.mWorldClock.mCurrentDay;
		if (gameflow.mWorldClock.mCurrentDay > 9) {
			// need to use left/right digits, since more than 1
			mCentreDigit->hide();
			mLeftDigit->show();
			mLeftDigit->setTexture(texTable[day / 10], 0);
			mRightDigit->show();
			mRightDigit->setTexture(texTable[day % 10], 0);
			mCentreDigitShadow->hide();
			mLeftDigitShadow->show();
			mLeftDigitShadow->setTexture(shadowTexTable[day / 10], 0);
			mRightDigitShadow->show();
			mRightDigitShadow->setTexture(shadowTexTable[day % 10], 0);

		} else {
			// single digit, just use centre
			mCentreDigit->show();
			mCentreDigit->setTexture(texTable[day], 0);
			mLeftDigit->hide();
			mRightDigit->hide();
			mCentreDigitShadow->show();
			mCentreDigitShadow->setTexture(shadowTexTable[day], 0);
			mLeftDigitShadow->hide();
			mRightDigitShadow->hide();
		}
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04     = zen::NumberTex (empty)
	P2DPicture* mCentreDigit;       // _04
	P2DPicture* mLeftDigit;         // _08
	P2DPicture* mRightDigit;        // _0C
	P2DPicture* mCentreDigitShadow; // _10
	P2DPicture* mLeftDigitShadow;   // _14
	P2DPicture* mRightDigitShadow;  // _18
};

/**
 * @brief TODO
 */
struct LifePinchCallBack : public P2DPaneCallBack {
	LifePinchCallBack(P2DPane* pane)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		_04 = _08 = 0.0f;
		_10       = false;
		_0C       = 0;
		pic->setAlpha(0);
		pic->setOffset(pic->getWidth() >> 1, pic->getHeight() >> 1);
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		Navi* navi      = nullptr;
		f32 healthRatio = 0.0f;
		if (naviMgr) {
			navi        = naviMgr->getNavi(0);
			healthRatio = navi->mHealth / C_NAVI_PROP(navi).mHealth();
		}

		if (healthRatio > 0.0f && healthRatio < 0.5f) {
			if (_04 < 250.0f) {
				_04 += 5.0f;
			} else {
				_04 = 255.0f;
			}

			_08 += ((0.5f - healthRatio) * 30.0f * PI + 15.0f) / 180.0f;
			if (navi->orimaDamaged()) {
				_0C = 3;
			}
		} else {
			_0C = 0;
			if (!_10 && navi && navi->mHealth > 0.0f && navi->orimaDamaged()) {
				_10 = true;
				_04 = 255.0f;
				_08 = 0.0f;
			}
			if (_04 > 5.0) { // forgot an f, yamashita
				_04 -= 5.0f;
			} else {
				_04 = 0.0f;
				_10 = false;
			}
			_08 += 15.0f * PI / 180.0f;
		}

		if (_08 > TAU) {
			_08 -= TAU;
			_10 = false;
			if (_0C > 0) {
				SeSystem::playSysSe(SYSSE_ORIMA_LIFEDIM);
			}
		}

		pic->setAlpha(zen::RoundOff((1.0f - NMathF::cos(_08)) * _04 * 0.5f));
		pic->setScale((1.0f - NMathF::cos(_08 * 0.5f)) * 0.15f + 1.0f);
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	f32 _04; // _04
	f32 _08; // _08
	int _0C; // _0C
	bool _10; // _10
};

/**
 * @brief TODO
 */
struct LifeIconCallBack : public P2DPaneCallBack {
	LifeIconCallBack(P2DPane* pane)
	    : P2DPaneCallBack(pane, PANETYPE_Pane)
	{
		mLifeCircle = new zen::DrawNaviLifeCircle(0, Vector3f(pane->getWidth() >> 1, pane->getHeight() >> 1, 0.0f), pane->getWidth() >> 1);
	}

	virtual bool invoke(P2DPane*) { return true; } // _08
	virtual bool draw(P2DPane*)                    // _0C
	{
		mLifeCircle->drawLifeCircle();
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	zen::DrawNaviLifeCircle* mLifeCircle; // _04
};

/**
 * @brief TODO
 */
struct NaviTexCallBack : public P2DPaneCallBack {
	NaviTexCallBack(P2DPane* pane)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	{
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		if (naviMgr) {
			Navi* navi = naviMgr->getNavi(0);
			if (navi->mHealth == 0.0f) {
				u8 alpha = pic->getAlpha();
				if (alpha > 3) {
					alpha -= 3;
				} else {
					alpha = 0;
				}

				pic->setAlpha(alpha);
			}
		}
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
};

/**
 * @brief TODO
 */
struct NaviIconCallBack : public P2DPaneCallBack {
	NaviIconCallBack(P2DPane* pane)
	    : P2DPaneCallBack(nullptr, PANETYPE_Pane)
	{
		_04        = 0.0f;
		mIsDamaged = false;
		pane->setOffset(pane->getWidth() >> 1, pane->getHeight() >> 1);
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		Navi* navi = nullptr;
		if (naviMgr) {
			navi = naviMgr->getNavi(0);
		}
		if (mIsDamaged) {
			f32 a = _04 += (PI / 3.0f);
			if (a > 3.0f * TAU) {
				mIsDamaged = false;
				pane->setScale(1.0f);
				_04 = 0.0f;
			}
			f32 t = NMathF::sin(_04) * ((1.0f - _04 / (3.0f * TAU)) * 0.2f);
			pane->setScale(1.0f - t, 1.0f + t, 1.0f);

		} else if (navi && navi->mHealth > 0.0f && navi->orimaDamaged()) {
			mIsDamaged = true;
		}

		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	f32 _04;         // _04
	bool mIsDamaged; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct SunMove {
	SunMove(P2DPane* startPane, P2DPane* goalPane)
	{
		PUTRect startBounds = startPane->getBounds();
		PUTRect goalBounds  = goalPane->getBounds();

		mStartX = f32((startBounds.mMinX + startBounds.mMaxX) >> 1);
		mStartY = f32((startBounds.mMinY + startBounds.mMaxY) >> 1);
		mGoalX  = f32((goalBounds.mMinX + goalBounds.mMaxX) >> 1);
		mGoalY  = f32((goalBounds.mMinY + goalBounds.mMaxY) >> 1);
	}

	// DLL inlines to do:
	void move(P2DPane* pane)
	{
		f32 tGoal, tStart;
		if (gameflow.mWorldClock.mTimeOfDay >= 7.0f && gameflow.mWorldClock.mTimeOfDay <= 19.0f) {
			// normal gameplay between 7am (day start) and 7pm (day end)
			tGoal  = (gameflow.mWorldClock.mTimeOfDay - 7.0f) / 12.0f;
			tStart = 1.0f - tGoal;
		} else {
			f32 tod = gameflow.mWorldClock.mTimeOfDay;
			if (gameflow.mWorldClock.mTimeOfDay < 7.0f) {
				tod += 5.0f; // 5 to 12 for midnight to 7am
			} else {
				tod -= 19.0f; // 0 to 5 for 7pm to midnight
			}
			// start and goal are flipped for nighttime?
			tStart = tod / 12.0f;
			tGoal  = 1.0f - tStart;
		}

		pane->move(zen::RoundOff(mStartX * tStart + mGoalX * tGoal) - (pane->getWidth() >> 1),
		           zen::RoundOff(mStartY * tStart + mGoalY * tGoal) - (pane->getWidth() >> 1));
	}

	f32 mStartX; // _00
	f32 mStartY; // _04
	f32 mGoalX;  // _08
	f32 mGoalY;  // _0C
};

/**
 * @brief TODO
 */
struct MoonIconCallBack : public P2DPaneCallBack, public SunMove {
	MoonIconCallBack(P2DPane* pane, P2DPane* startPane, P2DPane* goalPane)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , SunMove(startPane, goalPane)
	{
		_14 = 0.0f;
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		if (gameflow.mWorldClock.mTimeOfDay >= 7.0f && gameflow.mWorldClock.mTimeOfDay <= 19.0f) {
			pic->hide();
		} else {
			f32 alpha = 255.0f;
			pic->show();
			move(pane);
			f32 angle = _14 += 2.0f * PI / 180.0f;
			if (angle > TAU) {
				_14 -= TAU;
			}

			pic->rotateZ(pane->getWidth() >> 1, pane->getHeight() >> 1, NMathF::sin(_14) * (20.0f * PI / 180.0f) - (5.0f * PI / 180.0f));

			if (gameflow.mWorldClock.mTimeOfDay > 6.5f && gameflow.mWorldClock.mTimeOfDay <= 7.0f) {
				alpha *= (7.0f - gameflow.mWorldClock.mTimeOfDay) / 0.5f;
			} else if (gameflow.mWorldClock.mTimeOfDay > 19.0f && gameflow.mWorldClock.mTimeOfDay <= 19.5f) {
				alpha *= (gameflow.mWorldClock.mTimeOfDay - 19.0f) / 0.5f;
			}

			pic->setAlpha(zen::RoundOff(alpha));
		}
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04-_14 = SunMove
	f32 _14; // _14
};

/**
 * @brief TODO
 */
struct SunAnim {
	SunAnim(P2DPane* pane, f32 startAngle, f32 incAngle)
	{
		pane->rotate(pane->getWidth() >> 1, pane->getHeight() >> 1, P2DROTATE_Unk2, startAngle);
		mIncrementAngle = incAngle;
	}

	// DLL inlines to do:
	void anim(P2DPane* pane)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		if (gameflow.mWorldClock.mTimeOfDay >= 7.0f && gameflow.mWorldClock.mTimeOfDay <= 19.0f) {
			pic->show();
			if (!gameflow.mIsUiOverlayActive) {
				f32 t = NMathF::sin(2.0f * pane->getRotate());
				pic->rotate(pane->getWidth() >> 1, pane->getHeight() >> 1, P2DROTATE_Unk2, pane->getRotate() + mIncrementAngle);
				pic->setScale(0.1f * t + 0.9f);
				t = 64.0f * t + 191.0f;
				if (gameflow.mWorldClock.mTimeOfDay < 7.5f) {
					t *= (gameflow.mWorldClock.mTimeOfDay - 7.0f) / 0.5f;
				} else if (gameflow.mWorldClock.mTimeOfDay > 18.5f) {
					t *= (19.0f - gameflow.mWorldClock.mTimeOfDay) / 0.5f;
				}

				pic->setAlpha(zen::RoundOff(t));
			}
		} else {
			pic->hide();
		}
	}

	f32 mIncrementAngle; // _00
};

/**
 * @brief TODO
 */
struct SunIcon2CallBack : public P2DPaneCallBack, public SunMove, public SunAnim {
	SunIcon2CallBack(P2DPane* pane, P2DPane* startPane, P2DPane* goalPane, f32 startAngle, f32 incAngle)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , SunMove(startPane, goalPane)
	    , SunAnim(pane, startAngle, incAngle)
	{
	}

	virtual bool invoke(P2DPane* pane)
	{
		move(pane);
		anim(pane);
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04-_14 = SunMove
	// _14-_18 = SunAnim
};

/**
 * @brief TODO
 */
struct SunIcon1CallBack : public P2DPaneCallBack, public SunAnim {
	SunIcon1CallBack(P2DPane* pane, f32 startAngle, f32 incAngle)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , SunAnim(pane, startAngle, incAngle)
	{
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		anim(pane);
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04-_08 = SunAnim
	u8 _08[0x4]; // _08, unknown
};

/**
 * @brief TODO
 */
struct SunCapsuleCallBack : public P2DPaneCallBack {
	SunCapsuleCallBack(P2DPane* pane)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	{
		_04 = 0;
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		_04 += 2047;
		pic->setAlpha(zen::RoundOff(sinShort(_04) * 27.5f + 227.5f));
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	u16 _04; // _04
};

/**
 * @brief TODO
 */
struct SunBaseCallBack : public SunMove, public P2DPaneCallBack {
	SunBaseCallBack(P2DPane*, P2DPane* pane2, P2DPane* pane3)
	    : SunMove(pane2, pane3)
	    , P2DPaneCallBack(nullptr, PANETYPE_Pane)
	{
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		move(pane);
		return true;
	}

	// _10     = VTBL
	// _00-_10 = SunMove
	// _10-_14 = P2DPaneCallBack
	u8 _14[0x10]; // _14, unknown
};

/**
 * @brief TODO
 */
struct MapPikminWindowCallBack : public P2DPaneCallBack {
	MapPikminWindowCallBack(P2DPane* pane)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	{
		_04 = 0.0f;
		_08 = 0.0f;
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		_08 += gsys->getFrameTime();
		if (_08 > 2.0f) {
			_08 -= 2.0f;
		}

		if (zen::pGameInfo->mMapPikiNum == MAX_PIKI_ON_FIELD) {
			_04 += gsys->getFrameTime();
			if (_04 > 1.0f) {
				_04 = 1.0f;
			}
		} else {
			_04 -= gsys->getFrameTime();
			if (_04 < 0.0f) {
				_04 = 0.0f;
			}
		}

		f32 t     = (NMathF::sin(_08 / 2.0f * TAU) + 1.0f) * 0.5f * _04;
		f32 tComp = 1.0f - t;
		pic->setWhite(Colour(255, zen::RoundOff(50.0f * t + 255.0f * tComp), zen::RoundOff(50.0f * t + 255.0f * tComp), 255));
		return true;
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	f32 _04; // _04
	f32 _08; // _08
};

} // namespace

zen::GameInfo* zen::pGameInfo;

/*
 * --INFO--
 * Address:	801B6338
 * Size:	001FCC
 */
zen::DrawGameInfo::DrawGameInfo(zen::DrawGameInfo::playModeFlag playMode)
{
	mUpperScreenMgr = new DGIScreenMgr("screen/blo/play09.blo");
	mLowerScreenMgr = new DGIScreenMgr("screen/blo/play10.blo");

	switch (playMode) {
	case MODE_Story:
		mModeScreenMgr = new DGIScreenMgr("screen/blo/play_day.blo");
		break;

	case MODE_Challenge:
#if defined(VERSION_PIKIDEMO)
		mModeScreenMgr = new DGIScreenMgr("screen/blo/ot_play.blo");
#else
		mModeScreenMgr = new DGIScreenMgr("screen/blo/play_cha.blo");
#endif
		break;

	default:
		PRINT("ERROR! unknown play mode %d \n", playMode);
		ERROR("ERROR! unknown play mode %d \n", playMode);
		break;
	}

	pGameInfo = &mInfo;

	PRINT("PEACE\n"); // lol

	P2DPane* pane;
	if (pane = mModeScreenMgr->search('piki', true)) {
		pane->setCallBack(new PikiIconCallBack(pane));
	}

	pane = mModeScreenMgr->search('w_00', true);
	if (pane->getTypeID() == PANETYPE_Picture) {
		static_cast<P2DPicture*>(pane)->setBlack(Colour(0, 0, 0, 0));
		static_cast<P2DPicture*>(pane)->setWhite(Colour(153, 255, 153, 255));
	}

	pane = mModeScreenMgr->search('x_00', true);
	if (pane->getTypeID() == PANETYPE_Picture) {
		static_cast<P2DPicture*>(pane)->setBlack(Colour(0, 0, 0, 0));
		static_cast<P2DPicture*>(pane)->setWhite(Colour(153, 255, 153, 255));
	}

	pane = mModeScreenMgr->search('w_01', true);
	pane->setCallBack(new MapPikminWindowCallBack(pane));

	pane = mModeScreenMgr->search('c_ml', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mFormationPikiNum, 100, false));

	pane = mModeScreenMgr->search('c_mc', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mFormationPikiNum, 10, false));

	pane = mModeScreenMgr->search('c_mr', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mFormationPikiNum, 1, false));

	pane = mModeScreenMgr->search('c_ll', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mMapPikiNum, 100, false));

	pane = mModeScreenMgr->search('c_lc', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mMapPikiNum, 10, false));

	pane = mModeScreenMgr->search('c_lr', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mMapPikiNum, 1, false));

	pane = mModeScreenMgr->search('c_sl', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mTotalPikiNum, 1000, false));

	pane = mModeScreenMgr->search('c_sc', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mTotalPikiNum, 100, false));

	pane = mModeScreenMgr->search('c_sr', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mTotalPikiNum, 10, false));

	pane = mModeScreenMgr->search('c_s1', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &pGameInfo->mTotalPikiNum, 1, false));

	P2DPane* startSunPane = mUpperScreenMgr->search('stat', true);
	P2DPane* goalSunPane  = mUpperScreenMgr->search('goal', true);
	pane                  = mUpperScreenMgr->search('suni', true);

	if (pane && startSunPane && goalSunPane) {
		pane->setCallBack(new SunBaseCallBack(pane, startSunPane, goalSunPane));
	}

	if (pane = mUpperScreenMgr->search('sunc', true)) {
		pane->setCallBack(new SunCapsuleCallBack(pane));
	}

	pane = mUpperScreenMgr->search('sun1', true);
	if (pane) {
		pane->setCallBack(new SunIcon1CallBack(pane, PI, PI / 180.0f));
	}

	if (startSunPane && goalSunPane) {
		pane = mUpperScreenMgr->search('sun2', true);
		if (pane) {
			pane->setCallBack(new SunIcon2CallBack(pane, startSunPane, goalSunPane, 0.0f, -PI / 180.0f));
		}
	}

	if (startSunPane && goalSunPane) {
		if (pane = mUpperScreenMgr->search('moon', true)) {
			pane->setCallBack(new MoonIconCallBack(pane, startSunPane, goalSunPane));
		}
	}

	pane = mLowerScreenMgr->search('li_i', true);
	pane->setCallBack(new NaviIconCallBack(pane));

	pane = mLowerScreenMgr->search('na_i', true);
	pane->setCallBack(new NaviIconCallBack(pane));

	pane = mLowerScreenMgr->search('navi', true);
	pane->setCallBack(new NaviTexCallBack(pane));

	pane = mLowerScreenMgr->search('life', true);
	pane->setCallBack(new LifeIconCallBack(pane));

	pane = mLowerScreenMgr->search('pin1', true);
	pane->setCallBack(new LifePinchCallBack(pane));

	pane = mLowerScreenMgr->search('pin2', true);
	pane->setCallBack(new LifePinchCallBack(pane));

	if (playMode == MODE_Story) {
		pane            = mModeScreenMgr->search('dc_c', true);
		P2DPane* lPane  = mModeScreenMgr->search('dc_l', true);
		P2DPane* rPane  = mModeScreenMgr->search('dc_r', true);
		P2DPane* scPane = mModeScreenMgr->search('dcsc', true);
		P2DPane* slPane = mModeScreenMgr->search('dcsl', true);
		P2DPane* srPane = mModeScreenMgr->search('dcsr', true);

		pane->setCallBack(new DateCallBack(pane, lPane, rPane, scPane, slPane, srPane));
	}
}

/*
 * --INFO--
 * Address:	801B8580
 * Size:	000454
 */
void zen::DrawGameInfo::update()
{
	mUpperScreenMgr->update();
	mLowerScreenMgr->update();
	mModeScreenMgr->update();
	mDamageEffect.update();

	STACK_PAD_VAR(6);
}

/*
 * --INFO--
 * Address:	801B89D4
 * Size:	0000F0
 */
void zen::DrawGameInfo::draw(Graphics& gfx)
{
	mDamageEffect.draw(gfx);
	gfx.setFog(false);
	GXSetZMode(GX_FALSE, GX_ALWAYS, GX_FALSE);

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();
	mUpperScreenMgr->draw(&perspGraph);
	mLowerScreenMgr->draw(&perspGraph);
	mModeScreenMgr->draw(&perspGraph);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void zen::DrawGameInfo::upperDisplayOn()
{
	mUpperScreenMgr->makeResident();
	mUpperScreenMgr->displayOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void zen::DrawGameInfo::upperDisplayOff()
{
	mUpperScreenMgr->displayOff();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void zen::DrawGameInfo::lowerDisplayOn()
{
	mLowerScreenMgr->makeResident();
	mLowerScreenMgr->displayOn();
	mModeScreenMgr->makeResident();
	mModeScreenMgr->displayOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void zen::DrawGameInfo::lowerDisplayOff()
{
	mLowerScreenMgr->displayOff();
	mModeScreenMgr->displayOff();
}

/*
 * --INFO--
 * Address:	801B8AC4
 * Size:	00007C
 */
void zen::DrawGameInfo::upperFrameIn(f32 p1, bool p2)
{
	if (p2) {
		mUpperScreenMgr->makeResident();
	}
	mUpperScreenMgr->frameIn(p1);
}

/*
 * --INFO--
 * Address:	801B8B40
 * Size:	000080
 */
void zen::DrawGameInfo::upperFrameOut(f32 p1, bool p2)
{
	if (p2) {
		mUpperScreenMgr->makeResident();
	}
	mUpperScreenMgr->frameOut(p1);
}

/*
 * --INFO--
 * Address:	801B8BC0
 * Size:	0000B0
 */
void zen::DrawGameInfo::lowerFrameIn(f32 p1, bool p2)
{
	if (p2) {
		mLowerScreenMgr->makeResident();
		mModeScreenMgr->makeResident();
	}

	mLowerScreenMgr->frameIn(p1);
	mModeScreenMgr->frameIn(p1);
}

/*
 * --INFO--
 * Address:	801B8C70
 * Size:	0000B4
 */
void zen::DrawGameInfo::lowerFrameOut(f32 p1, bool p2)
{
	if (p2) {
		mLowerScreenMgr->makeResident();
		mModeScreenMgr->makeResident();
	}

	mLowerScreenMgr->frameOut(p1);
	mModeScreenMgr->frameOut(p1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
bool zen::DrawGameInfo::isUpperFrameIn()
{
	return mUpperScreenMgr->isFrameIn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
bool zen::DrawGameInfo::isUpperFrameOut()
{
	return mUpperScreenMgr->isFrameOut();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
bool zen::DrawGameInfo::isLowerFrameIn()
{
	return mLowerScreenMgr->isFrameIn() && mModeScreenMgr->isFrameIn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
bool zen::DrawGameInfo::isLowerFrameOut()
{
	return mLowerScreenMgr->isFrameOut() && mModeScreenMgr->isFrameOut();
}
