#include "ModeState.h"
#include "IntroGameSection.h"
#include "system.h"
#include "MoviePlayer.h"
#include "timers.h"
#include "MemStat.h"
#include "MapMgr.h"
#include "gameflow.h"
#include "Graphics.h"
#include "jaudio/PikiScene.h"
#include "sysNew.h"
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
DEFINE_PRINT("introGame");

/**
 * @brief TODO
 */
struct QuittingModeState : public ModeState {
	QuittingModeState(BaseGameSection* c)
	    : ModeState(c)
	{
	}

	virtual ModeState* update(u32& p1) // _08
	{
		PRINT("quitter updating!\n");
		p1 = 0;
	}
	virtual void postUpdate() // _10
	{
		if (!gsys->getPending()) {
			PRINT("sending softreset!\n");

			memStat->reset();
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			Jac_SceneExit(13, 0);
			gsys->softReset();
		}
	}

	// _00     = VTBL?
	// _00-_04 = ModeState?
};

/**
 * @brief TODO
 */
struct IntroModeState : public ModeState {
	IntroModeState(BaseGameSection* c)
	    : ModeState(c)
	{
		mController = c->mController;
	}

	virtual ModeState* update(u32& p1) // _08
	{
		p1 = 1;
		if (!gameflow.mMoviePlayer->mIsActive) {
			PRINT("quitting!\n");
			return new QuittingModeState(mSection);
		}
		return this;
	}
	virtual void postRender(Graphics&) { } // _0C

	// _00     = VTBL
	// _00-_04 = ModeState
	Controller* mController; // _08
};

/**
 * @brief TODO
 *
 * @note In introGame.cpp because IntroModeState needs to be there.
 */
struct IntroGameSetupSection : public BaseGameSection {
	IntroGameSetupSection()
	{
		_34 = new IntroModeState(this);

		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));

		_3A4          = true;
		gameflow._1E4 = 0;
		_44           = 0;
		_38           = 0;
		Jac_SceneSetup(11, 0);
		EffectMgr* mgr = new EffectMgr;
		mgr->cullingOff();
		_39C = new DayMgr(nullptr, mController);

		int size        = 0x500000;
		int badCompiler = size;
		gsys->mHeaps[SYSHEAP_Movie].init("movie", 2, new u8[size], size);
		gameflow.mMoviePlayer->startMovie(1, 0, nullptr, nullptr, nullptr, -1, true);
		gameflow.mMoviePlayer->startMovie(2, 0, nullptr, nullptr, nullptr, -1, true);
		gsys->setFade(1.0f, 3.0f);
	}

	void mainRender(Graphics& gfx)
	{
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, 0);
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
		                   gfx.mCamera->mFar, 1.0f);
		gfx.useMatrix(Matrix4f::ident, 0);
		_39C->refresh(gfx, 25.0f, 8);
		_39C->setFog(gfx, nullptr);
		gfx.calcLighting(1.0f);
		gameflow.mMoviePlayer->refresh(gfx);
		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.flushCachedShapes();
	}

	void postRender(Graphics& gfx)
	{
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, 60.0f, gfx.mCamera->mAspectRatio, 1.0f, gfx.mCamera->mFar, 1.0f);

		Matrix4f mtx;
		mtx.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, -5.0f));
		Matrix4f mtx2;
		gfx.mRenderState = 0x700;
		_34->postRender(gfx);
		gfx.setOrthogonal(mtx2.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	}

	virtual void update() // _10
	{
		mController->update();
	}
	virtual void draw(Graphics& gfx) // _14
	{
		Matrix4f mtx;

		gameflow.mMoviePlayer->update();
		if (!gameflow.mMoviePlayer->setCamera(gfx)) {
			gfx.setCamera(&_50);
			f32 w = gfx.mScreenWidth;
			f32 h = gfx.mScreenHeight;
			_50.update(w / h, _50.mFov, 100.0f, _398);
		}

		gsys->mTimer->start("mainRender", true);
		mainRender(gfx);
		gsys->mTimer->stop("mainRender");

		if (effectMgr) {
			if (gameflow._33C == 0 && gameflow._338 == 0) {
				bool check = true;
				if (gsys->_258 >= 0) {
					check = false;
				}
				if (check) {
					gsys->mTimer->start("effect", true);
					effectMgr->update();
					gsys->mTimer->stop("effect");
				}
			}
			// fun fact! this empty timer function is necessary to fix this instruction ordering :')
			gsys->mTimer->start("eff draw", true);
			effectMgr->draw(gfx);
			gsys->mTimer->stop("eff draw");
		}

		if (!(gameflow.mDemoFlags & 0x80)) {
			gsys->mTimer->start("postRender", true);
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			postRender(gfx);
			gsys->mTimer->stop("postRender");
		}

		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		BaseGameSection::draw(gfx);

		if (!_3A4) {
			if (!gsys->getPending() && (!_20 || gameflow.mMoviePlayer->mIsActive)) {
				if (_38) {
					_34 = _38;
					_38 = nullptr;
				}
				_34 = _34->update(_3C);
			}
		} else {
			_3A4 = false;
		}

		if (_38) {
			PRINT("FORCING MODE !!!!\n");
			_34 = _38;
			_38 = nullptr;
		}
	}

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	u32 _44;      // _44
	u32 _48;      // _48
	u32 _4C;      // _4C
	Camera _50;   // _50
	f32 _398;     // _398
	DayMgr* _39C; // _39C
	Colour _3A0;  // _3A0
	u8 _3A4;      // _3A4
};

static IntroGameSetupSection* igss;

/*
 * --INFO--
 * Address:	8005AE1C
 * Size:	000298
 */
IntroGameSection::IntroGameSection()
{
	Node::init("<IntroGameSection>");
	gsys->setFrameClamp(2);

	mapMgr = nullptr;
	igss   = nullptr;

	gsys->startLoading(0, true, 60);
	IntroGameSetupSection* intro = new IntroGameSetupSection();
	add(intro);
	gsys->endLoading();
}
