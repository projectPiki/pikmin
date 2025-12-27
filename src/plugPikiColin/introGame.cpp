#include "Camera.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "IntroGameSection.h"
#include "MapMgr.h"
#include "MemStat.h"
#include "ModeState.h"
#include "MoviePlayer.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "sysNew.h"
#include "system.h"
#include "timers.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
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

	virtual ModeState* update(u32& result) // _08
	{
		PRINT("quitter updating!\n");
		result = UPDATE_NONE;
		return this;
	}

	virtual void postUpdate() // _10
	{
		if (!gsys->resetPending()) {
			PRINT("sending softreset!\n");

			memStat->reset();
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			Jac_SceneExit(SCENE_Unk13, 0);
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

	virtual ModeState* update(u32& result) // _08
	{
		result = UPDATE_AI;

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
 */
struct IntroGameSetupSection : public BaseGameSection {
	IntroGameSetupSection()
	{
		mCurrentModeState = new IntroModeState(this);

		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));

		mIsFirstFrame            = true;
		gameflow.mIsDayEndActive = FALSE;
		_44                      = 0;
#if defined(VERSION_GPIP01_00)
		_3A8 = 0;
#endif
		mNextModeState = 0;
		Jac_SceneSetup(SCENE_Unk11, 0);
		EffectMgr* mgr = new EffectMgr;
		mgr->cullingOff();
		mDayManager = new DayMgr(nullptr, mController);

		int size = 0x500000;
		gsys->mHeaps[SYSHEAP_Movie].init("movie", AYU_STACK_GROW_UP, new u8[size], size);
		gameflow.mMoviePlayer->startMovie(DEMOID_OpeningIntroPt1, 0, nullptr, nullptr, nullptr, -1, true);
		gameflow.mMoviePlayer->startMovie(DEMOID_OpeningIntroPt2, 0, nullptr, nullptr, nullptr, -1, true);
		gsys->setFade(1.0f, 3.0f);
		STACK_PAD_TERNARY(size, 1);
	}

	void mainRender(Graphics& gfx)
	{
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
		                   gfx.mCamera->mFar, 1.0f);
		gfx.useMatrix(Matrix4f::ident, 0);
		mDayManager->refresh(gfx, 25.0f, 8);
		mDayManager->setFog(gfx, nullptr);
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
		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		mCurrentModeState->postRender(gfx);
		gfx.setOrthogonal(mtx2.mMtx, AREA_FULL_SCREEN(gfx));
	}

	virtual void update() // _10
	{
		mController->update();
	}
	virtual void draw(Graphics& gfx) // _14
	{
		Matrix4f mtx;

#if defined(VERSION_GPIP01_00)
		_3A8++;
		if (_3A8 == 5) {
			_3A8 = 0;
		}
#endif

		gameflow.mMoviePlayer->update();
		if (!gameflow.mMoviePlayer->setCamera(gfx)) {
			gfx.setCamera(&mLocalCamera);
			f32 w = gfx.mScreenWidth;
			f32 h = gfx.mScreenHeight;
			mLocalCamera.update(w / h, mLocalCamera.mFov, 100.0f, mLocalCameraFar);
		}

		gsys->mTimer->start("mainRender", true);
		mainRender(gfx);
		gsys->mTimer->stop("mainRender");

		if (effectMgr) {
			if (gameflow.mPauseAll == FALSE && !gameflow.mIsUIOverlayActive) {
				gsys->mTimer->start("effect", true);
				bool check = true;
				if (gsys->mDvdErrorCode >= DvdError::ReadingDisc) {
					check = false;
				}
				if (check) {
					effectMgr->update();
				}
				gsys->mTimer->stop("effect");
			}
			// fun fact! this empty (in retail) timer function is necessary to fix this instruction ordering :')
			gsys->mTimer->start("eff draw", true);
			effectMgr->draw(gfx);
			gsys->mTimer->stop("eff draw");
		}

		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
			gsys->mTimer->start("postRender", true);
			gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
			postRender(gfx);
			gsys->mTimer->stop("postRender");
		}

		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));

		BaseGameSection::draw(gfx);

		if (!mIsFirstFrame) {
			if (!gsys->resetPending() && (!mActiveMenu || gameflow.mMoviePlayer->mIsActive)) {
				if (mNextModeState) {
					mCurrentModeState = mNextModeState;
					mNextModeState    = nullptr;
				}
				mCurrentModeState = mCurrentModeState->update(mUpdateFlags);
			}
		} else {
			mIsFirstFrame = false;
		}

		if (mNextModeState) {
			PRINT("FORCING MODE !!!!\n");
			mCurrentModeState = mNextModeState;
			mNextModeState    = nullptr;
		}
	}

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	u32 _44;             // _44
	u32 _48;             // _48
	u32 _4C;             // _4C
	Camera mLocalCamera; // _50
	f32 mLocalCameraFar; // _398
	DayMgr* mDayManager; // _39C
	Colour _3A0;         // _3A0
	u8 mIsFirstFrame;    // _3A4

#if defined(VERSION_GPIP01_00)
	int _3A8;
#endif
};

static IntroGameSetupSection* igss;

/**
 * @todo: Documentation
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
