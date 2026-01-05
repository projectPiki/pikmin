#include "IntroGameSection.h"

#include "Camera.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "MemStat.h"
#include "MoviePlayer.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "sysNew.h"
#include "system.h"
#include "timers.h"

//////////////////////////////////////////////////////
//////////////// FORWARD DECLARATIONS ////////////////
//////////////////////////////////////////////////////

struct IntroGameSetupSection;

//////////////////////////////////////////////////////
///////////////// MACROS AND DEFINES /////////////////
//////////////////////////////////////////////////////

/// Size for the asteroid/crash landing intro cutscene heap, in bytes.
#define INTRO_MOVIE_HEAP_SIZE (0x500000)

//////////////////////////////////////////////////////
////////////////// STATIC INSTANCES //////////////////
//////////////////////////////////////////////////////

/// Intro cutscene setup instance.
static IntroGameSetupSection* igss;

//////////////////////////////////////////////////////
//////////////// PRINT/ERROR DEFINES /////////////////
//////////////////////////////////////////////////////

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("introGame");

//////////////////////////////////////////////////////
////////////////// INTRO MODE STATES /////////////////
//////////////////////////////////////////////////////

/**
 * @brief State for handling quitting out of the intro movie, to transit to gameplay.
 *
 * @note Size: 0x8.
 */
struct QuittingModeState : public ModeState {

	/**
	 * @brief Constructs a quitter state.
	 * @param parent Parent setup/control section (`IntroGameSetupSection` in this case).
	 */
	QuittingModeState(BaseGameSection* parent)
	    : ModeState(parent)
	{
	}

	/**
	 * @brief Updates quitter - keeps update flag at none, no transits out.
	 * @details Actual transit out of this state is handled by `postUpdate`.
	 * @param result Output update flag, to pass to other game flow machinery - see `ModeUpdateFlags` enum.
	 * @return Pointer to active state for next frame - always `this`.
	 */
	virtual ModeState* update(u32& result) // _08
	{
		PRINT("quitter updating!\n");
		result = UPDATE_NONE;
		return this;
	}

	/**
	 * @brief Force transits to a new game section, based on what we have queued up.
	 */
	virtual void postUpdate() // _10
	{
		// force transit to next section (if we're not already)
		if (!gsys->resetPending()) {
			PRINT("sending softreset!\n");

			memStat->reset();
			// next section is always entering gameplay
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			Jac_SceneExit(SCENE_Exit, 0);
			gsys->softReset();
		}
	}

	// _00     = VTBL
	// _00-_08 = ModeState
};

/**
 * @brief Basic listener-like state to detect when the intro cutscene has finished.
 *
 * @note Size: 0xC.
 */
struct IntroModeState : public ModeState {

	/**
	 * @brief Constructs an intro listener state.
	 * @param parent Parent setup/control section (`IntroGameSetupSection` in this case).
	 */
	IntroModeState(BaseGameSection* parent)
	    : ModeState(parent)
	{
		mController = parent->mController;
	}

	/**
	 * @brief Updates intro listener - keeps update flag for AI so cutscene can animate.
	 * @details Transits to the quitter when the cutscene is finished.
	 * @param result Output update flag, to pass to other game flow machinery - see `ModeUpdateFlags` enum.
	 * @return Pointer to active state for next frame - either `this` to stay in this state, or `QuittingModeState` to exit.
	 */
	virtual ModeState* update(u32& result) // _08
	{
		result = UPDATE_AI;

		// when cutscene is finished, exit to gameplay
		if (!gameflow.mMoviePlayer->mIsActive) {
			PRINT("quitting!\n");
			return new QuittingModeState(mParentSection);
		}

		return this;
	}

	/// No overlays to draw.
	virtual void postRender(Graphics&) { } // _0C

	// _00     = VTBL
	// _00-_08 = ModeState
	Controller* mController; ///< _08, active player controller.
};

//////////////////////////////////////////////////////
//////////////////// SETUP SECTION ///////////////////
//////////////////////////////////////////////////////

/**
 * @brief Inner control section for the intro cutscene, which does a lot more of the labour than its parent `IntroGameSection`.
 *
 * @note Size: 0x3A8 (0x3AC in PAL).
 */
struct IntroGameSetupSection : public BaseGameSection {

	/// Constructs a new control section for the intro cutscene and starts it.
	IntroGameSetupSection()
	{
		// start our cutscene listener state
		mCurrentModeState = new IntroModeState(this);

		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));

		mIsInitialSetup          = true;
		gameflow.mIsDayEndActive = FALSE;
		_44                      = 0; // unused

#if defined(VERSION_GPIP01_00)
		mDrawCounter = 0;
#endif

		mNextModeState = nullptr;
		Jac_SceneSetup(SCENE_Intro, 0);

		// set up effect and lighting managers
		EffectMgr* mgr = new EffectMgr;
		mgr->cullingOff();
		mDayManager = new DayMgr(nullptr, mController);

		// set up movie heap and start playing the asteroid movie!
		int size = INTRO_MOVIE_HEAP_SIZE;
		gsys->mHeaps[SYSHEAP_Movie].init("movie", AYU_STACK_GROW_UP, new u8[size], size);
		gameflow.mMoviePlayer->startMovie(DEMOID_OpeningIntroPt1, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		gameflow.mMoviePlayer->startMovie(DEMOID_OpeningIntroPt2, 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
		gsys->setFade(1.0f);
		STACK_PAD_TERNARY(size, 1);
	}

	/**
	 * @brief Performs more detailed rendering actions for a single frame, mainly around lighting and cutscene rendering.
	 * @param gfx Graphics context for rendering.
	 */
	void mainRender(Graphics& gfx)
	{
		// set up space environment for cutscene and keep movie playing
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

	/**
	 * @brief Performs more detailed 2D rendering actions for overlays on a frame.
	 * @details In practice, this really does a whole lot of nothing, since no mode states have any 2D screens to render.
	 * @param gfx Graphics context for rendering.
	 */
	void postRender(Graphics& gfx)
	{
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, 60.0f, gfx.mCamera->mAspectRatio, 1.0f, gfx.mCamera->mFar, 1.0f);

		Matrix4f unused;
		unused.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, -5.0f));

		Matrix4f orthoMtx;
		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		mCurrentModeState->postRender(gfx);
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
	}

	/// Updates controller each frame (even though our inputs make no difference in retail).
	virtual void update() // _10
	{
		mController->update();
	}

	/**
	 * @brief Renders a single frame and conducts any associated updating.
	 * @param gfx Graphics context for rendering.
	 */
	virtual void draw(Graphics& gfx) // _14
	{
		Matrix4f orthoMtx;

#if defined(VERSION_GPIP01_00)
		// this does nothing but loop. never referenced.
		mDrawCounter++;
		if (mDrawCounter == 5) {
			mDrawCounter = 0;
		}
#endif

		// update the cutscene
		gameflow.mMoviePlayer->update();
		if (!gameflow.mMoviePlayer->setCamera(gfx)) {
			gfx.setCamera(&mIntroCamera);
			f32 w = gfx.mScreenWidth;
			f32 h = gfx.mScreenHeight;
			mIntroCamera.update(w / h, mIntroCamera.mFov, 100.0f, mCameraFarClip);
		}

		// main rendering - lighting and movie drawing
		gsys->mTimer->start("mainRender", true);
		mainRender(gfx);
		gsys->mTimer->stop("mainRender");

		// update our effects
		if (effectMgr) {
			if (gameflow.mPauseAll == FALSE && !gameflow.mIsUIOverlayActive) {
				gsys->mTimer->start("effect", true);
				bool isDVDNormal = true;
				if (gsys->mDvdErrorCode >= DvdError::ReadingDisc) {
					isDVDNormal = false;
				}
				if (isDVDNormal) {
					effectMgr->update();
				}
				gsys->mTimer->stop("effect");
			}
			// fun fact! this empty (in retail) timer function is necessary to fix this instruction ordering :')
			gsys->mTimer->start("eff draw", true);
			effectMgr->draw(gfx);
			gsys->mTimer->stop("eff draw");
		}

		// do any 2D overlay rendering - we never have any, so this is a bit pointless
		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
			gsys->mTimer->start("postRender", true);
			gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
			postRender(gfx);
			gsys->mTimer->stop("postRender");
		}

		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));

		// handle fade-ins and fade-outs
		BaseGameSection::draw(gfx);

		// no updating or transiting on the first frame please
		if (!mIsInitialSetup) {
			if (!gsys->resetPending() && (!mActiveMenu || gameflow.mMoviePlayer->mIsActive)) {
				if (mNextModeState) {
					mCurrentModeState = mNextModeState;
					mNextModeState    = nullptr;
				}
				mCurrentModeState = mCurrentModeState->update(mUpdateFlags);
			}
		} else {
			mIsInitialSetup = false;
		}

		// force transit mode state if we have one queued up
		if (mNextModeState) {
			PRINT("FORCING MODE !!!!\n");
			mCurrentModeState = mNextModeState;
			mNextModeState    = nullptr;
		}
	}

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	u32 _44;              ///< _044, unused/unknown.
	u8 _48[0x50 - 0x48];  ///< _048, unused/unknown.
	Camera mIntroCamera;  ///< _050, camera for intro cutscene.
	f32 mCameraFarClip;   ///< _398, max render distance from the camera.
	DayMgr* mDayManager;  ///< _39C, lighting manager, since we have no map.
	Colour _3A0;          ///< _3A0, unused/unknown.
	bool mIsInitialSetup; ///< _3A4, are we still in the initial setup phase? Cannot do certain actions til we're done.

#if defined(VERSION_GPIP01_00)
	int mDrawCounter; ///< _3A8, looping 5-frame draw counter - tracked but never referenced.
#endif
};

//////////////////////////////////////////////////////
//////////////////// GAME SECTION ////////////////////
//////////////////////////////////////////////////////

/**
 * @brief Constructs intro cutscene subsection for story mode.
 *
 * Most of the hard work gets farmed out to `IntroGameSetupSection` above and any mode states, including transiting to actual gameplay.
 */
IntroGameSection::IntroGameSection()
{
	Node::init("<IntroGameSection>");
	// run intro movie at 30 fps
	gsys->setFrameClamp(2);

	// no map to manage yet!
	mapMgr = nullptr;
	igss   = nullptr;

	gsys->startLoading(0, true, 60);
	// the actual workhorse of this section
	IntroGameSetupSection* intro = new IntroGameSetupSection();
	add(intro);
	gsys->endLoading();
}

//////////////////////////////////////////////////////
