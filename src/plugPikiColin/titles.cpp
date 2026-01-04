#include "TitlesSection.h"

#include "Camera.h"
#include "CinematicPlayer.h"
#include "Controller.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "Dolphin/card.h"
#include "Font.h"
#include "Graphics.h"
#include "Interface.h"
#include "Light.h"
#include "Menu.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/DrawHiScore.h"
#include "zen/ogStart.h"
#include "zen/ogTitle.h"

struct TitleSetupSection;

// Macros for packing and unpacking the section compression flag, to pass both section and subsection ID together.
// Realistically, the only section with a subsection ID is OnePlayerSection, so having a dedicated macro for it is easier.
// NB: this is actually the reverse of the MapSelectSection and CardSelectSection packing for whatever reason.

/// Packs next section ID to transit to, to be stored in a flag.
#define PACK_NEXT_SECTION(sectionID) (sectionID) << 16

/// Packs next OnePlayerSection subsection ID to transit to, to be stored in a flag.
#define PACK_NEXT_ONEPLAYER(onePlayerID) ((SECTION_OnePlayer) << 16) | (onePlayerID)

/// Unpacks next section ID from flag.
#define UNPACK_NEXT_SECTION(flag) (flag) >> 16

/// Unpacks next OnePlayerSection subsection ID from flag.
#define UNPACK_NEXT_ONEPLAYER(flag) (flag) & 0xFFFF

/// Main title menu, opened after pressing A or START. Contains submenus and transitions to game modes.
static zen::ogScrTitleMgr* titleWindow;

/// Whether the main title menu is open and visible.
static bool titleWindowOn;

/// Hiscore screen overlay, opened from Options >> High Scores.
static zen::DrawHiScore* totalWindow;

/// Whether hiscore screen overlay is open and visible.
static bool totalWindowOn;

/// The PRESS START text "menu". Pressing A or START will open the titleWindow and close this.
static zen::ogScrStartMgr* startWindow;

/// Whether the PRESS START text is "open" and visible.
static bool startWindowOn;

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Titles")

/**
 * @brief Commands to send via `TitleMovieInterface`, from cutscenes to title screen.
 *
 * In practice, only ever used to send one command.
 */
enum TitleMovieCommands {
	TITLECMD_ShowStartMenu = 0, ///< 0, make start menu visible.
};

/**
 * @brief Title-screen-specific message shuttle. Primarily used for shuttling messages into and out of cutscenes.
 *
 * This is never used explicitly in the codebase, but it is used by the entering-into-title cutscene to trigger when
 * the start menu options should be displayed (via event flags).
 *
 * @note Size: 0x8.
 */
struct TitlesMovieInterface : public GameInterface {

	/**
	 * @brief Construct a title message shuttle.
	 * @param section Parent setup section to attach to.
	 */
	TitlesMovieInterface(TitleSetupSection* section) { mSetupSection = section; }

	virtual void message(int cmd, int); // _08

	// _00 = VTBL
	TitleSetupSection* mSetupSection; ///< _04, parent setup/controlling section.
};

/**
 * @brief Inner control game section for the title screen, which does a lot more of the labour than its parent `TitlesSection`.
 *
 * The menus themselves are handled by zen::ogScrTitleMgr (with zen::DrawHiScore for the hiscore screen,
 * and zen::ogScrStartMgr for the PRESS START text).
 *
 * @note Size: 0xA4C.
 */
struct TitleSetupSection : public Node {

	/**
	 * @brief Display states the title screen can be in.
	 */
	enum State {
		STATE_Inactive    = -1, ///< -1, have exited and menu is now inactive.
		STATE_Active      = 0,  ///< 0, active and operational, no transitions pending.
		STATE_ExitPending = 1,  ///< 1, transition is pending and waiting to be resolved.
	};

	/// Constructs a new control section for the title screen, also setting up the debug menu and some unused additional lighting.
	TitleSetupSection()
	{
		setName("Titles section");

#if defined(BUGFIX)
		// This section uses `SeSystem` without constructing it.
		seSystem = new SeSystem();
#endif

#if defined(VERSION_G98E01_PIKIDEMO)
		// if you spend 30 minutes on the demo title screen, the game reboots and freezes lol
		mIdleMovieTimer = 1800.0f;
#else
		// first how-to movie will start after spending 20s on the title screen (starts counting from when PRESS START shows up)
		mIdleMovieTimer = 20.0f;
#endif
		mCameraFocusPoint.set(0.0f, 20.0f, 0.0f);
		gameflow.mGameInterface = new TitlesMovieInterface(this);
		mController             = new Controller(1);
		mState                  = STATE_Active;

		titleWindow   = new zen::ogScrTitleMgr;
		titleWindowOn = false;

		mDayMgr = new DayMgr(nullptr, mController);

		// play camera pan-in to title screen (which will also trigger PRESS START to show up)
		gameflow.mDemoFlags = 0;
		mPlayer             = new CinematicPlayer("cinemas/opening.cin");
		mPlayer->mWorldMtx.makeIdentity();
		mPlayer->mIsPlaying = true;

		// load in lighting/time settings
		RandomAccessStream* data = gsys->openFile("cinemas/opening.ini", true, true);
		if (data) {
			CmdStream* stream = new CmdStream(data);
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
				if (stream->isToken("dayMgr")) {
					stream->getToken(true);
					mDayMgr->init(stream);
				}
			}
			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
			data->close();
		}

		mCameraZoom = 0.45f;
		_39C        = 1.0f; // unused

#if defined(WIN32) // DLL exclusive
		// set but never used
		PRINT("big font!\n");
		mFont = new Font();
		mFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
#endif

		// these title screen light pools are never enabled (and don't really look great, so fair)
		mEnableLightPool = FALSE;
		mLightPoolList.initCore("lightPools");

		// this loop never sets these up in retail. would've been between 1 and 3 in development i assume
		for (int i = 0; i < TERNARY_DEVELOP(3, 0); i++) {
			LightPool* light = new LightPool;
			light->mFlags    = 0;
			// all these light pools are a sickly yellow
			light->mColour.set(255, 255, 64, 64);
			light->mParticleTexture    = gsys->loadTexture("effects/halowhit.txe", true);
			light->mFocusRotationAngle = i * QUARTER_PI;

			switch (i) {
			case 0:
				light->mCamera.mPosition.set(500.0f, 300.0f, -25.0f);
				break;
			case 1:
				light->mCamera.mPosition.set(25.0f, 300.0f, -12.0f);
				break;
			case 2:
				light->mCamera.mPosition.set(500.0f, 300.0f, 500.0f);
				break;
			}
			light->mCamera.mFocus.set(0.0f, 0.0f, 0.0f);
			light->mCamera.mFocus.y = 10.0f;
			light->mCamera.mFocus.z += 0.00001f;
			light->mCamera.mFov          = 40.0f;
			light->mLight.mPosition      = light->mCamera.mPosition;
			light->mLight.mDiffuseColour = light->mColour;
			light->mLight.mLightFlag     = LIGHTFLAG_Unk100 | LIGHTFLAG_Unk200 | LIGHT_Spot;
			light->mLight.mSpotAngle     = light->mCamera.mFov / 2.0f;
			light->mLight.mSpotMode      = SPOT_Smooth;

			light->mLight.mDirection.set(0.0f, -1.0f, 0.0f);
			light->mLight.mDirection.normalise();

			gameflow.addGenNode("lightPool", light);
			mLightPoolList.add(light);
		}

		mActiveDebugMenu = nullptr;

#if defined(DEVELOP) || defined(WIN32)
		Menu* optionsMenu = new Menu(mController, gsys->mConsFont);

		optionsMenu->mCenterPoint.mMinX = glnWidth / 2;
		optionsMenu->mCenterPoint.mMinY = glnHeight / 2 + 40; // offset downwards from screen center
		optionsMenu->mGradBGTopColour.set(MENU_COLOUR_RED);
		optionsMenu->mGradBGBottomColour.set(MENU_COLOUR_DEFAULT_GREY);

		optionsMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(mDebugMenu, &Menu::menuCloseMenu));
		gameflow.addOptionsMenu(optionsMenu);
#endif

		mDebugMenu = new Menu(mController, gsys->mConsFont);

		mDebugMenu->mCenterPoint.mMinX = glnWidth / 2;
		mDebugMenu->mCenterPoint.mMinY = glnHeight / 2 + 80; // offset downwards from screen center

		mDebugMenu->addKeyEvent(Menu::KeyEventType::OnConfirm, KBBTN_START | KBBTN_A,
		                        new Delegate1<TitleSetupSection, Menu&>(this, &menuSelectOption));
		mDebugMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(mDebugMenu, &Menu::menuCloseMenu));

#if defined(DEVELOP) || defined(WIN32)
		mDebugMenu->addOption(PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup), "Start GL Game", nullptr);
		mDebugMenu->addOption(PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup), "Challenge Mode",
		                      new Delegate1<TitleSetupSection, Menu&>(this, &menuChallengeOption));
		mDebugMenu->addOption(PACK_NEXT_SECTION(SECTION_MovSample), "Movie Sample", nullptr);
		mDebugMenu->addOption(PACK_NEXT_SECTION(SECTION_OgTest), "Rumble", nullptr);
		mDebugMenu->addOption(PACK_NEXT_SECTION(SECTION_PaniTest), "TestScreen", nullptr);

		mDebugMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		mDebugMenu->addMenu(mDayMgr->mMenu, 0, "Lighting");
		mDebugMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		mDebugMenu->addMenu(optionsMenu, 0, "Options");
#endif

		// default next section is back to the loading logo
		mNextSectionsFlag = PACK_NEXT_SECTION(SECTION_NinLogo);

		gameflow.mFrameCacher = new AnimFrameCacher(8000);

		_3B4.set(200.0f, 200.0f, 50.0f); // unused

		// test a null/worst-possible hiscore to get updated score info
		// (is this to make sure there's an entry in the scoreboard? or just to prep the system? unsure.)
		GameQuickInfo info;
		info.mDay       = MAX_DAYS;
		info.mBornPikis = 0;
		info.mDeadPikis = 0;
		info.mParts     = 0;
		gameflow.mGamePrefs.checkIsHiscore(info);

		// set up hiscore window for if we open that menu
		totalWindow   = new zen::DrawHiScore;
		totalWindowOn = false;

		// set up start menu
		startWindow   = new zen::ogScrStartMgr;
		startWindowOn = false;

		gsys->setFade(1.0f);
	}

	/// Updates the current title screen state, handling menu and submenu transitions, and triggering overall game section
	virtual void update() // _10
	{
		mController->update();

		// handle PRESS START
		if (mState == STATE_Active && startWindowOn) {
			// NB: this timer is cumulative and doesn't get reset on activity on the title screen, only by re-transitioning from another
			// section (tutorial movie, game section, etc)
			mIdleMovieTimer -= gsys->getFrameTime();

			// play pre-rendered tutorial movie
			if (mIdleMovieTimer < 0.0f) {
				mIdleMovieTimer = 0.0f;
#if defined(VERSION_G98E01_PIKIDEMO)
				// demo takes 30 minutes to trigger this, but no movies - hard reset and freeze
				gsys->forceHardReset();
				while (true) { }
#endif
				// set up the next idle movie to play, and queue up the next
				gameflow.mCurrIntroMovieID = gameflow.mNextIntroMovieID;
				gameflow.mNextIntroMovieID = (gameflow.mNextIntroMovieID + 1) & MOV_INTRO_CYCLE_MASK; // basically mod(4)

				mNextSectionsFlag = PACK_NEXT_SECTION(SECTION_MovSample);
				mState            = STATE_ExitPending;
				gsys->setFade(0.0f);
				return;
			}
		}

		// time technically advances on the title screen - this was probably for some unused lighting handling
		if (!mActiveDebugMenu) {
			gameflow.mWorldClock.update(1.0f);
		}

		if (!mActiveDebugMenu) {
			// if there wasn't a cutscene always playing in the background, this would move the title camera around
			f32 stickX = mController->mMainStickX * 1.25f;
			f32 stickY = mController->mMainStickY * 1.25f;

			Vector3f xVec(mCamera.mViewXAxis.x * stickX, 0.0f, mCamera.mViewXAxis.z * stickX);
			xVec.project(Vector3f(0.0f, 1.0f, 0.0f));
			Vector3f yVec(mCamera.mViewZAxis.x * stickY, 0.0f, mCamera.mViewZAxis.z * stickY);
			yVec.project(Vector3f(0.0f, 1.0f, 0.0f));
			mCameraFocusPoint.add(xVec);
			mCameraFocusPoint.add(yVec);

			if (mController->keyDown(KBBTN_L)) {
				mCameraZoom += gsys->getFrameTime() * 1.0f;
			} else if (mController->keyDown(KBBTN_R)) {
				mCameraZoom -= gsys->getFrameTime() * 1.0f;
			}

			if (mController->keyDown(KBBTN_CSTICK_RIGHT)) {
				mCamera.mRotation.x += gsys->getFrameTime() * 1.0f;
			} else if (mController->keyDown(KBBTN_CSTICK_LEFT)) {
				mCamera.mRotation.x -= gsys->getFrameTime() * 1.0f;
			}
		}

		// this camera is never actually used, since there's always technically a cutscene playing,
		// so these functions don't do anything in retail
		Vector3f camPos;
		camPos.x          = sinf(mCamera.mRotation.x) * (1500.0f * mCameraZoom) + mCameraFocusPoint.x;
		camPos.y          = sinf(mCamera.mRotation.y) + mCameraFocusPoint.y + (2.0f * mCameraZoom) * 450.0f;
		camPos.z          = cosf(mCamera.mRotation.x) * (1500.0f * mCameraZoom) + mCameraFocusPoint.z;
		mCamera.mPosition = camPos;
		mCamera.calcLookAt(camPos, mCameraFocusPoint, nullptr);

		if (mActiveDebugMenu) {
			// update any open debug menus
			mActiveDebugMenu = mActiveDebugMenu->doUpdate(false);
			// update background cutscene
			mPlayer->mPlaybackSpeed = 30.0f;
			mPlayer->update();
		} else {
			// update background cutscene
			mPlayer->mPlaybackSpeed = 30.0f;
			mPlayer->update();

			if (mState == STATE_Active) {
				// handle hiscore window closing
				if (totalWindow && totalWindow->update(mController)) {
					// go from hiscore window back to PRESS START
					totalWindowOn = false;
					startWindow->start();
					startWindowOn = true;
				}

				if (!totalWindowOn) {

					// handle pressing A or START on PRESS START screen
					if (startWindowOn && !titleWindowOn && mController->keyClick(KBBTN_START | KBBTN_A)) {
#if defined(VERSION_G98E01_PIKIDEMO)
						// demo doesn't use the title menu, jump straight into Forest of Hope challenge mode
						mNextSectionsFlag                = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						gameflow.mGamePrefs.mHasSaveGame = false;
						gameflow.mIsChallengeMode        = true;
						Jac_SceneExit(SCENE_Exit, 0);
						mState = STATE_ExitPending;
						gsys->setFade(0.0f);
#else
						// swap from PRESS START to the main title menu
						startWindow->stop();
						startWindowOn = false;
						// only display Challenge Mode option if we've unlocked it
						titleWindow->start(gameflow.mGamePrefs.isChallengeOpen());
						titleWindowOn = true;
#endif
					}

					startWindow->update(mController);

					// handle main title menu exit status
					zen::ogScrTitleMgr::TitleStatus titleState = titleWindow->update(mController);
					if (titleState == zen::ogScrTitleMgr::STATUS_ExitToChallengeMode) {
						PRINT("going to CHALLENGE MODE SETUP!\n");
						// set up transit to challenge mode
						mNextSectionsFlag                = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						gameflow.mGamePrefs.mHasSaveGame = false;
						gameflow.mIsChallengeMode        = TRUE;
						Jac_SceneExit(SCENE_Exit, 0);
						mState = STATE_ExitPending;
						gsys->setFade(0.0f);

					} else if (titleState == zen::ogScrTitleMgr::STATUS_ExitToHiScore) {
						titleWindowOn = false;
						// show hiscore overlay
						totalWindowOn = true;
						totalWindow->start();

					} else if (titleState == zen::ogScrTitleMgr::STATUS_ExitToStoryMode) {
						// set up transit to story mode
						// the illusion of choice
						if (gameflow.mGamePrefs.mHasSaveGame) {
							PRINT("going to SETUP!\n");
							mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						} else {
							PRINT("going to SETUP!\n");
							mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						}
						Jac_SceneExit(SCENE_Exit, 0);
						mState = STATE_ExitPending;
						gsys->setFade(0.0f);

					} else if (titleState == zen::ogScrTitleMgr::STATUS_Unk5 || titleState == zen::ogScrTitleMgr::STATUS_ExitToStart) {
						// cancel out of menu back to PRESS START, save all preferences and check if language restart required
#if defined(VERSION_G98E01_PIKIDEMO)
						STACK_PAD_VAR(1);
						if (gameflow.mGamePrefs.mChangesPending)
							gameflow.mMemoryCard.saveOptions();

						int oldLang = gameflow.mLanguageIndex;
						if (!gameflow.mGamePrefs.getChildMode()) {
							gameflow.mLanguageIndex = LANG_Adult;
						} else {
							gameflow.mLanguageIndex = LANG_Child;
						}
						if (gameflow.mLanguageIndex != oldLang) {
							// language update required, need to re-initialise title to re-do preLoadLanguage
							gameflow.mLanguageIndex = LANG_FORCE_CHANGE;
							mState                  = STATE_ExitPending;
							gsys->setFade(0.0f);
						} else {
							startWindow->start();
							startWindowOn = true;
							titleWindowOn = false;
						}
#else
#if defined(VERSION_GPIP01_00)
						int lang = gameflow.mGamePrefs.getChildMode();
						STACK_PAD_VAR(1);
						PRINT("got language index %d\n", lang);
#else
						bool lang = gameflow.mGamePrefs.getChildMode();
#endif
						if (gameflow.mGamePrefs.mChangesPending) {
							bool vibe   = gameflow.mGamePrefs.getVibeMode();
							bool stereo = gameflow.mGamePrefs.getStereoMode();
#if defined(VERSION_GPIP01_00)
							int lang = gameflow.mGamePrefs.getChildMode();
#else
							bool lang = gameflow.mGamePrefs.getChildMode();
#endif
							u8 bgmVol = gameflow.mGamePrefs.getBgmVol();
							u8 sfxVol = gameflow.mGamePrefs.getSfxVol();

							if (gameflow.mMemoryCard.getMemoryCardState(true) == 0 && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
								gameflow.mMemoryCard.loadOptions();
							}

							gameflow.mGamePrefs.setVibeMode(vibe);
							gameflow.mGamePrefs.setStereoMode(stereo);
							gameflow.mGamePrefs.setChildMode(lang);
							gameflow.mGamePrefs.setBgmVol(bgmVol);
							gameflow.mGamePrefs.setSfxVol(sfxVol);
							gameflow.mGamePrefs.mChangesPending = false;
							gameflow.mMemoryCard.saveOptions();
						}
						if (gameflow.mLanguageIndex != lang) {
							// language update required, need to re-initialise title to re-do preLoadLanguage
							gameflow.mLanguageIndex = LANG_FORCE_CHANGE;
							mState                  = STATE_ExitPending;
							gsys->setFade(0.0f);
						} else {
							startWindow->start();
							startWindowOn = true;
							titleWindowOn = false;
						}
#endif
					}
				}

#if defined(DEVELOP) || defined(WIN32)
				if (mController->keyUnClick(KBBTN_Z)) {
					// open debug menu with Z
					mActiveDebugMenu = mDebugMenu;
					mActiveDebugMenu->open(false);
					mActiveDebugMenu->mIsMenuChanging = true;
				}
#endif

				// force update any children (we don't have any but that's fine)
				Node::update();
			}
		}

		if (mState == STATE_ExitPending && !mActiveDebugMenu && gsys->getFade() == 0.0f) {
			// TRANSIT STATE
			mState                           = STATE_Inactive;
			gameflow.mNextGameSectionID      = UNPACK_NEXT_SECTION(mNextSectionsFlag);
			gameflow.mNextOnePlayerSectionID = UNPACK_NEXT_ONEPLAYER(mNextSectionsFlag);
			gsys->softReset();
		}
	}

	/**
	 * @brief Renders the current frame of the title screen, handling background cutscene and which menus to display.
	 * @param gfx Graphics context for rendering.
	 */
	virtual void draw(Graphics& gfx) // _14
	{
		if (mPlayer->mCurrentData) {
			// current cutscene playing, use its camera
			// in reality, this is always the case - the background is a cutscene
			gfx.setCamera(&mPlayer->mCurrentData->mCameraData->mCamera);
		} else {
			// use our custom title screen camera
			// (this never actually happens)
			gfx.setCamera(&mCamera);
			mCamera.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), mCamera.mFov, 100.0f, 15000.0f);
		}

		// this is always false, but if it weren't - set up our light pools
		if (mEnableLightPool) {
			FOREACH_NODE(LightPool, mLightPoolList.mChild, lightPool)
			{
				LightCamera& cam = lightPool->mCamera;
				lightPool->mFocusRotationAngle += gsys->getFrameTime() * 0.0175f;
				cam.mFocus.set(sinf(lightPool->mFocusRotationAngle) * 20.0f + cam.mPosition.x, cam.mFocus.y,
				               cosf(lightPool->mFocusRotationAngle) * 20.0f + cam.mPosition.z);
				cam.mLightMap = nullptr;
				cam.calcVectors(cam.mPosition, cam.mFocus);
				cam.calcProjection(gfx, true, nullptr);
				lightPool->mLight.mPosition  = cam.mPosition;
				lightPool->mLight.mDirection = cam.mFocus - cam.mPosition;
				lightPool->mLight.mDirection.normalise();
				lightPool->mLight.update();
				gfx.addLight(&lightPool->mLight);
			}
		}

		Matrix4f orthoMtx;
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);
		gfx.mAmbientFogColour.set(48, 48, 48, 255);

		// (this is a wacky way of resetting the graphics context's last model matrix to the identity)
		Matrix4f tmpViewMtx1;
		gfx.calcViewMatrix(Matrix4f::ident, tmpViewMtx1);
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
		                   gfx.mCamera->mFar, 1.0f);
		gfx.setLighting(false, nullptr);
		gfx.setFog(false);

		// (this is a wacky way of resetting the graphics context's last model matrix to the identity)
		Matrix4f tmpViewMtx2;
		gfx.calcViewMatrix(Matrix4f::ident, tmpViewMtx2);

		gfx.useMatrix(Matrix4f::ident, 0);

		STACK_PAD_VAR(1);

		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
			// use special Movie time setting (lighting)
			mDayMgr->refresh(gfx, 25.0f, 8);
			mDayMgr->setFog(gfx, nullptr);
		} else {
			mPlayer->addLights(gfx);
		}

		gfx.calcLighting(1.0f);

		// unused!
		static f32 spin = 0.0f;
		spin += gsys->getFrameTime() * 0.5f;

		// also completely unused
		static int chas = 15;
		static int cmax = 20;

		if (mController->keyClick(KBBTN_X)) {
			chas++;
		} else if (mController->keyClick(KBBTN_Y)) {
			chas--;
		}

		mPlayer->refresh(gfx);

		// unused!
		static f32 rspin = 0.0f;
		rspin += gsys->getFrameTime() * 5.0f;

		// what is this cursed bit of code? what happened here colin.
		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.useMatrix(Matrix4f::ident, 0);

		f32 unused = mController->mTriggerR / 170.0f * 4.0f + 3.0f;
		gfx.useMatrix(Matrix4f::ident, 0);

		// draw our light pools if they're enabled (they never are)
		if (mEnableLightPool) {
			FOREACH_NODE(LightPool, mLightPoolList.mChild, lightPool)
			{
				lightPool->draw(gfx);
			}
		}

		// draw any children we have (we have none)
		Node::draw(gfx);

		// clear some graphics to get ready for menu/overlay drawing
		gfx.flushCachedShapes();
		gsys->flushLFlares(gfx);

		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.useMatrix(Matrix4f::ident, 0); // colin i think it's been set mate

		// this is just for fading the debug menu
		static f32 mfade = 0.0f;

		if (mActiveDebugMenu) {
			mfade -= gsys->getFrameTime() * 400.0f;
			if (mfade < 0.0f) {
				mfade = 0.0f;
			}
		} else {
			mfade += gsys->getFrameTime() * 400.0f;
			if (mfade > 255.0f) {
				mfade = 255.0f;
			}
		}

		if (mfade > 0.0f) {
			gfx.setColour(Colour(255, 255, 64, (int)mfade), true);
			gfx.setAuxColour(Colour(255, 0, 64, (int)(mfade * 0.5f)));
		}

		gfx.setCBlending(BLEND_Alpha);

		STACK_PAD_TERNARY(mActiveDebugMenu, 2);
		if (mActiveDebugMenu) {
			// draw the debug menu if it's open
			drawMenu(gfx, mActiveDebugMenu, 1.0f);
		} else {
			// draw PRESS START, main title menu, or hiscore menus as required
			startWindow->draw(gfx);
			titleWindow->draw(gfx);
			if (totalWindow) {
				// hiscore menu is a full-screen overlay
				gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
				totalWindow->draw(gfx);
			}
		}

		// i do not know what load banner we'd have here but draw it just in case
		if (gameflow.mLevelBannerFadeValue > 0.0f) {
			gameflow.mLevelBannerFadeValue -= gsys->getFrameTime();
			if (gameflow.mLevelBannerFadeValue < 0.0f) {
				gameflow.mLevelBannerFadeValue = 0.0f;
				gameflow.mIsNintendoLoadLogo   = FALSE;
			} else {
				gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTex, gameflow.mLevelBannerFadeValue);
			}
		}
	}

	/**
	 * @brief Debug menu callback for selecting an item, therefore causing a section transit.
	 * @param parent Parent debug menu.
	 */
	void menuSelectOption(Menu& parent)
	{
		mNextSectionsFlag         = parent.mCurrentItem->mData;
		gameflow.mIsChallengeMode = FALSE;
		Jac_SceneExit(SCENE_Exit, 0);
		parent.close();
		mState = STATE_ExitPending;
		gsys->setFade(0.0f);
	}

	/**
	 * @brief Debug menu callback for selecting the Challenge Mode item, therefore causing a section transit.
	 * @param parent Parent debug menu.
	 */
	void menuChallengeOption(Menu& parent)
	{
		mNextSectionsFlag = parent.mCurrentItem->mData;
		gameflow.mGamePrefs.Initialise();
		gameflow.mIsChallengeMode = TRUE;
		Jac_SceneExit(SCENE_Exit, 0); // Just an educated guess, as this function is DLL-exclusive.
		parent.close();
		mState = STATE_ExitPending;
		gsys->setFade(0.0f);
	}

	/**
	 * @brief Renders the given debug menu, handling any pop-out submenu overlay alphas.
	 * @param gfx Graphics context for rendering.
	 * @param menu Menu to render.
	 * @param fadeFactor Factor to apply to menu alpha (0-1, 0=no alpha, 1=full alpha).
	 */
	void drawMenu(Graphics& gfx, Menu* menu, f32 fadeFactor)
	{
		if (menu->mAlignToParentItem) {
			// create pop-out submenu effect - have parent menu at half alpha behind this menu
			drawMenu(gfx, menu->mParentMenu, fadeFactor * 0.5f);
		}

		menu->draw(gfx, fadeFactor);
	}

#if defined(WIN32)
	void genAge(AgeServer& server) { mPlayer->genAge(server); }
#endif

	// _00     = VTBL
	// _00-_20 = Node
	u32 mState;                 ///< _20, display state the title screen is in - see `State` enum.
	u32 mNextSectionsFlag;      ///< _24, flag that stores the next `OnePlayerSection` and `Section` IDs - see `PACK`/`UNPACK` macros.
	Menu* mDebugMenu;           ///< _28, debug menu exclusive to the DEVELOP build - opened with Z.
	Menu* mActiveDebugMenu;     ///< _2C, pointer to active (open) debug menu, if there is one; `nullptr` means none are open.
	Controller* mController;    ///< _30, active player controller.
	Font* mFont;                ///< _34, unused BigFont font.
	u8 _38[0x10];               ///< _38, unknown/unused.
	f32 mIdleMovieTimer;        ///< _48, idle timer, counting down until tutorial/helper movies start.
	f32 mCameraZoom;            ///< _4C, zoom for unused title screen camera.
	CinematicPlayer* mPlayer;   ///< _50, active cutscene player, handling the camera pan-in and background of title screen.
	Camera mCamera;             ///< _54, unused camera for this section, active when any cutscenes are not, which is never.
	f32 _39C;                   ///< _39C, unknown/unused - set to 1.0f and then never referenced.
	u8 _3A0[0x3B4 - 0x3A0];     ///< _3A0, unknown/unused.
	Vector3f _3B4;              ///< _3B4, unknown/unused - set in constructor then never referenced.
	u8 _3C0[0x4];               ///< _3C0, unknown/unused.
	LightPool mLightPoolList;   ///< _3C4, list of (unused) light pool effects.
	BOOL mEnableLightPool;      ///< _A34, whether to use the (uninitialised) light pool effects above - this option is always FALSE.
	u8 _A38[0x4];               ///< _A38, unknown/unused.
	DayMgr* mDayMgr;            ///< _A3C, lighting manager for the title screen.
	Vector3f mCameraFocusPoint; ///< _A40, target/watch position for unused title screen camera.
#if defined(WIN32)              //
	CoreNode _A4C;              ///< _A4C, DLL-exclusive but unused.
	CoreNode _A60;              ///< _A60, DLL-exclusive but unused.
#endif
};

/**
 * @brief Sends a command from a cutscene to the title screen manager.
 *
 * In practice, this is only used to make the start menu visible after camera pan-in.
 *
 * @param cmd Command to send - see `TitleMessageCommands` enum.
 */
void TitlesMovieInterface::message(int cmd, int)
{
	switch (cmd) {
	case TITLECMD_ShowStartMenu:
		startWindow->start();
		startWindowOn = true;
		break;
	}
}

/**
 * @brief Initialises title screen game section.
 *
 * Most of the hard work gets farmed out to `TitleSetupSection` above, including transiting to a new subsection.
 */
void TitlesSection::init()
{
	Node::init("<TitlesSection>");
	Jac_BackDVDBuffer();

	// make sure debug timer display is off for players
	gsys->mTimerState = TS_Off;

	// run title screen at 60 fps
	gsys->setFrameClamp(1);

	// all "relative" directories will assume they're from here
	gsys->setDataRoot("dataDir/");
	gameflow.mLevelBannerTex         = nullptr;
	gameflow.mLevelBannerFadeValue   = 1.0f;
	gameflow.mGamePrefs.mHasSaveGame = true;
#if defined(VERSION_G98E01_PIKIDEMO)
	// no save games/memory card for demo
#else
	if (gameflow.mMemoryCard.getMemoryCardState(true) == CARD_RESULT_READY && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
		gameflow.mMemoryCard.loadOptions();
	}
#endif

	// sync stereo/mono with OS settings
	gameflow.mGamePrefs.fixSoundMode();
	gsys->startLoading(&gameflow.mGameLoadIdler, true, gameflow.mIsNintendoLoadLogo ? 0 : 60);

	// check if we need to reload the language, in case the preference has changed since last load
	int beforeLang = gameflow.mLanguageIndex;
#if defined(VERSION_GPIP01_00)
	gameflow.mLanguageIndex = gameflow.mGamePrefs.getChildMode();
	if (gameflow.mLanguageIndex < LANG_MIN || gameflow.mLanguageIndex > LANG_MAX) {
		PRINT("trying to load language %d\n", gameflow.mLanguageIndex);
		gameflow.mLanguageIndex = LANG_English;
	}
#else
	if (!gameflow.mGamePrefs.getChildMode()) {
		gameflow.mLanguageIndex = LANG_Adult;
	} else {
		gameflow.mLanguageIndex = LANG_Child;
	}
#endif

	if (gameflow.mLanguageIndex != beforeLang) {
		preloadLanguage();
	}

	gameflow.mIsChallengeMode  = FALSE;
	gameflow._2B8              = 0;            // unused
	gameflow.mCurrIntroMovieID = MOV_GrowDemo; // intro demos always play in the same order

	switch (gameflow.mNextOnePlayerSectionID) {
	case ONEPLAYER_GameSetup:
		// do the actual setup and control handling
		add(new TitleSetupSection);
		break;
	}

	PRINT("ending loading!\n");
	gsys->endLoading();
	PRINT("done!\n");

	Jac_SceneSetup(SCENE_Title, 0);
}
