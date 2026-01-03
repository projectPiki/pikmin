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
#include "TitlesSection.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/DrawHiScore.h"
#include "zen/ogStart.h"
#include "zen/ogTitle.h"

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

struct TitleSetupSection;

static zen::ogScrTitleMgr* titleWindow;
static bool titleWindowOn;
static zen::DrawHiScore* totalWindow;
static bool totalWindowOn;
static zen::ogScrStartMgr* startWindow;
static bool startWindowOn;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Titles")

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct TitlesMovieInterface : public GameInterface {
	TitlesMovieInterface(TitleSetupSection* section) { mSection = section; }

	virtual void message(int, int); // _08

	// _00 = VTBL
	TitleSetupSection* mSection; // _04
};

/**
 * @brief TODO
 */
struct TitleSetupSection : public Node {
	TitleSetupSection()
	{
		setName("Titles section");

		// This section uses `SeSystem` without constructing it.
#if defined(BUGFIX)
		seSystem = new SeSystem();
#endif

#if defined(VERSION_G98E01_PIKIDEMO)
		mStartTransitionTimer = 1800.0f;
#else
		mStartTransitionTimer = 20.0f;
#endif
		mCameraFocusPoint.set(0.0f, 20.0f, 0.0f);
		gameflow.mGameInterface = new TitlesMovieInterface(this);
		mController             = new Controller(1);
		mState                  = 0;
		titleWindow             = new zen::ogScrTitleMgr;
		titleWindowOn           = false;
		mDayMgr                 = new DayMgr(nullptr, mController);
		gameflow.mDemoFlags     = 0;
		mPlayer                 = new CinematicPlayer("cinemas/opening.cin");
		mPlayer->mWorldMtx.makeIdentity();
		mPlayer->mIsPlaying = true;

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
		mCameraDistanceScale = 0.45f;
		_UNUSED39C           = 1.0f;

#if defined(WIN32) // DLL exclusive
		PRINT("big font!\n");
		mFont = new Font();
		mFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
#endif

		mEnableLightPool = 0;
		mLightPool.initCore("lightPools");

		// i love code that never runs.
		for (int i = 0; i < 0; i++) {
			LightPool* light = new LightPool;
			light->mFlags    = 0;
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
			light->mLight.mLightType     = 771;
			light->mLight.mSpotAngle     = light->mCamera.mFov / 2.0f;
			light->mLight.mSpotMode      = 2;

			light->mLight.mDirection.set(0.0f, -1.0f, 0.0f);
			light->mLight.mDirection.normalise();

			gameflow.addGenNode("lightPool", light);
			mLightPool.add(light);
		}

		mCurrentMenu = nullptr;

#if defined(DEVELOP) || defined(WIN32)
		Menu* optionsMenu = new Menu(mController, gsys->mConsFont);

		optionsMenu->mCenterPoint.mMinX = glnWidth / 2;
		optionsMenu->mCenterPoint.mMinY = glnHeight / 2 + 40;
		optionsMenu->mGradBGTopColour.set(MENU_COLOUR_RED);
		optionsMenu->mGradBGBottomColour.set(MENU_COLOUR_DEFAULT_GREY);

		optionsMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(mMenu, &Menu::menuCloseMenu));
		gameflow.addOptionsMenu(optionsMenu);
#endif

		mMenu = new Menu(mController, gsys->mConsFont);

		mMenu->mCenterPoint.mMinX = glnWidth / 2;
		mMenu->mCenterPoint.mMinY = glnHeight / 2 + 80;

		mMenu->addKeyEvent(Menu::KeyEventType::OnConfirm, KBBTN_START | KBBTN_A,
		                   new Delegate1<TitleSetupSection, Menu&>(this, &menuSelectOption));
		mMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(mMenu, &Menu::menuCloseMenu));

#if defined(DEVELOP) || defined(WIN32)
		mMenu->addOption(PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup), "Start GL Game", nullptr);
		mMenu->addOption(PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup), "Challenge Mode",
		                 new Delegate1<TitleSetupSection, Menu&>(this, &menuChallengeOption));
		mMenu->addOption(PACK_NEXT_SECTION(SECTION_MovSample), "Movie Sample", nullptr);
		mMenu->addOption(PACK_NEXT_SECTION(SECTION_OgTest), "Rumble", nullptr);
		mMenu->addOption(PACK_NEXT_SECTION(SECTION_PaniTest), "TestScreen", nullptr);

		mMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		mMenu->addMenu(mDayMgr->mMenu, 0, "Lighting");
		mMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		mMenu->addMenu(optionsMenu, 0, "Options");
#endif

		mNextSectionsFlag = PACK_NEXT_SECTION(SECTION_NinLogo);

		gameflow.mFrameCacher = new AnimFrameCacher(8000);

		_UNUSED3B4.set(200.0f, 200.0f, 50.0f);
		GameQuickInfo info;
		info.mDay       = MAX_DAYS;
		info.mBornPikis = 0;
		info.mDeadPikis = 0;
		info.mParts     = 0;
		gameflow.mGamePrefs.checkIsHiscore(info);

		totalWindow   = new zen::DrawHiScore;
		totalWindowOn = false;
		startWindow   = new zen::ogScrStartMgr;
		startWindowOn = false;

		gsys->setFade(1.0f, 3.0f);
	}

	virtual void update() // _10
	{
		mController->update();
		if (!mState && startWindowOn) {
			mStartTransitionTimer -= gsys->getFrameTime();
			if (mStartTransitionTimer < 0.0f) {
				mStartTransitionTimer = 0.0f;
#if defined(VERSION_G98E01_PIKIDEMO)
				gsys->forceHardReset();
				while (true) { }
#endif
				// set up the next idle movie to play, and queue up the next
				gameflow.mCurrIntroMovieID = gameflow.mNextIntroMovieID;
				gameflow.mNextIntroMovieID = (gameflow.mNextIntroMovieID + 1) & MOV_INTRO_CYCLE_MASK; // basically mod(4)

				mNextSectionsFlag = PACK_NEXT_SECTION(SECTION_MovSample);
				mState            = 1;
				gsys->setFade(0.0f, 3.0f);
				return;
			}
		}

		if (!mCurrentMenu) {
			gameflow.mWorldClock.update(1.0f);
		}

		if (!mCurrentMenu) {
			f32 stickX = mController->mMainStickX * 1.25f;
			f32 stickY = mController->mMainStickY * 1.25f;

			Vector3f xVec(mCamera.mViewXAxis.x * stickX, 0.0f, mCamera.mViewXAxis.z * stickX);
			xVec.project(Vector3f(0.0f, 1.0f, 0.0f));
			Vector3f yVec(mCamera.mViewZAxis.x * stickY, 0.0f, mCamera.mViewZAxis.z * stickY);
			yVec.project(Vector3f(0.0f, 1.0f, 0.0f));
			mCameraFocusPoint.add(xVec);
			mCameraFocusPoint.add(yVec);

			if (mController->keyDown(KBBTN_L)) {
				mCameraDistanceScale += gsys->getFrameTime() * 1.0f;
			} else if (mController->keyDown(KBBTN_R)) {
				mCameraDistanceScale -= gsys->getFrameTime() * 1.0f;
			}

			if (mController->keyDown(KBBTN_CSTICK_RIGHT)) {
				mCamera.mRotation.x += gsys->getFrameTime() * 1.0f;
			} else if (mController->keyDown(KBBTN_CSTICK_LEFT)) {
				mCamera.mRotation.x -= gsys->getFrameTime() * 1.0f;
			}
		}

		Vector3f camPos;
		camPos.x          = sinf(mCamera.mRotation.x) * (1500.0f * mCameraDistanceScale) + mCameraFocusPoint.x;
		camPos.y          = sinf(mCamera.mRotation.y) + mCameraFocusPoint.y + (2.0f * mCameraDistanceScale) * 450.0f;
		camPos.z          = cosf(mCamera.mRotation.x) * (1500.0f * mCameraDistanceScale) + mCameraFocusPoint.z;
		mCamera.mPosition = camPos;
		mCamera.calcLookAt(camPos, mCameraFocusPoint, nullptr);

		if (mCurrentMenu) {
			mCurrentMenu            = mCurrentMenu->doUpdate(false);
			mPlayer->mPlaybackSpeed = 30.0f;
			mPlayer->update();
		} else {
			mPlayer->mPlaybackSpeed = 30.0f;
			mPlayer->update();

			if (mState == 0) {
				if (totalWindow && totalWindow->update(mController)) {
					totalWindowOn = false;
					startWindow->start();
					startWindowOn = true;
				}

				if (!totalWindowOn) {
					if (startWindowOn && !titleWindowOn && mController->keyClick(KBBTN_START | KBBTN_A)) {
#if defined(VERSION_G98E01_PIKIDEMO)
						mNextSectionsFlag                = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						gameflow.mGamePrefs.mHasSaveGame = false;
						gameflow.mIsChallengeMode        = true;
						Jac_SceneExit(SCENE_Exit, 0);
						mState = 1;
						gsys->setFade(0.0f, 3.0f);
#else
						startWindow->stop();
						startWindowOn = false;
						titleWindow->start(gameflow.mGamePrefs.isChallengeOpen());
						titleWindowOn = true;
#endif
					}

					startWindow->update(mController);

					zen::ogScrTitleMgr::TitleStatus titleState = titleWindow->update(mController);
					if (titleState == zen::ogScrTitleMgr::Status_6) {
						PRINT("going to CHALLENGE MODE SETUP!\n");
						mNextSectionsFlag                = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						gameflow.mGamePrefs.mHasSaveGame = false;
						gameflow.mIsChallengeMode        = TRUE;
						Jac_SceneExit(SCENE_Exit, 0);
						mState = 1;
						gsys->setFade(0.0f, 3.0f);

					} else if (titleState == zen::ogScrTitleMgr::Status_7) {
						titleWindowOn = false;
						totalWindowOn = true;
						totalWindow->start();

					} else if (titleState == zen::ogScrTitleMgr::Status_4) {
						if (gameflow.mGamePrefs.mHasSaveGame) {
							PRINT("going to SETUP!\n");
							mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						} else {
							PRINT("going to SETUP!\n");
							mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameSetup);
						}
						Jac_SceneExit(SCENE_Exit, 0);
						mState = 1;
						gsys->setFade(0.0f, 3.0f);
					} else if (titleState == zen::ogScrTitleMgr::Status_5 || titleState == zen::ogScrTitleMgr::Status_3) {
#if defined(VERSION_G98E01_PIKIDEMO)
						STACK_PAD_VAR(1);
						if (gameflow.mGamePrefs.mChangesPending)
							gameflow.mMemoryCard.saveOptions();

						int old = gameflow.mLanguageIndex;
						if (!gameflow.mGamePrefs.getChildMode()) {
							gameflow.mLanguageIndex = 0;
						} else {
							gameflow.mLanguageIndex = 1;
						}
						if (gameflow.mLanguageIndex != old) {
							gameflow.mLanguageIndex = -1;
							mState                  = 1;
							gsys->setFade(0.0f, 3.0f);
						} else {
							startWindow->start();
							startWindowOn = true;
							titleWindowOn = false;
						}
#else
#if defined(VERSION_GPIP01_00)
						int child = gameflow.mGamePrefs.getChildMode();
						STACK_PAD_VAR(1);
						PRINT("got language index %d\n", child);
#else
						bool child = gameflow.mGamePrefs.getChildMode();
#endif
						if (gameflow.mGamePrefs.mChangesPending) {
							bool vibe   = gameflow.mGamePrefs.getVibeMode();
							bool stereo = gameflow.mGamePrefs.getStereoMode();
#if defined(VERSION_GPIP01_00)
							int child = gameflow.mGamePrefs.getChildMode();
#else
							bool child = gameflow.mGamePrefs.getChildMode();
#endif
							u8 bgmVol = gameflow.mGamePrefs.getBgmVol();
							u8 sfxVol = gameflow.mGamePrefs.getSfxVol();

							if (gameflow.mMemoryCard.getMemoryCardState(true) == 0 && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
								gameflow.mMemoryCard.loadOptions();
							}

							gameflow.mGamePrefs.setVibeMode(vibe);
							gameflow.mGamePrefs.setStereoMode(stereo);
							gameflow.mGamePrefs.setChildMode(child);
							gameflow.mGamePrefs.setBgmVol(bgmVol);
							gameflow.mGamePrefs.setSfxVol(sfxVol);
							gameflow.mGamePrefs.mChangesPending = false;
							gameflow.mMemoryCard.saveOptions();
						}
						if (gameflow.mLanguageIndex != child) {
							gameflow.mLanguageIndex = -1;
							mState                  = 1;
							gsys->setFade(0.0f, 3.0f);
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
					mCurrentMenu = mMenu;
					mCurrentMenu->open(false);
					mCurrentMenu->mIsMenuChanging = true;
				}
#endif

				Node::update();
			}
		}

		if (mState == 1 && !mCurrentMenu && gsys->getFade() == 0.0f) {
			mState                           = -1;
			gameflow.mNextGameSectionID      = UNPACK_NEXT_SECTION(mNextSectionsFlag);
			gameflow.mNextOnePlayerSectionID = UNPACK_NEXT_ONEPLAYER(mNextSectionsFlag);
			gsys->softReset();
		}
	}
	virtual void draw(Graphics& gfx) // _14
	{
		if (mPlayer->mCurrentData) {
			gfx.setCamera(&mPlayer->mCurrentData->mCameraData->mCamera);
		} else {
			gfx.setCamera(&mCamera);
			mCamera.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), mCamera.mFov, 100.0f, 15000.0f);
		}

		if (mEnableLightPool) {
			FOREACH_NODE(LightPool, mLightPool.mChild, lightPool)
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

		Matrix4f mtx1;
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);
		gfx.mAmbientFogColour.set(48, 48, 48, 255);
		Matrix4f mtx2;
		gfx.calcViewMatrix(Matrix4f::ident, mtx2);
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
		                   gfx.mCamera->mFar, 1.0f);
		gfx.setLighting(false, nullptr);
		gfx.setFog(false);

		Matrix4f mtx3;
		gfx.calcViewMatrix(Matrix4f::ident, mtx3);
		gfx.useMatrix(Matrix4f::ident, 0);

		STACK_PAD_VAR(1);

		if (!(gameflow.mDemoFlags & GFDEMO_InMenu)) {
			mDayMgr->refresh(gfx, 25.0f, 8);
			mDayMgr->setFog(gfx, nullptr);
		} else {
			mPlayer->addLights(gfx);
		}

		gfx.calcLighting(1.0f);

		static f32 spin = 0.0f;
		spin += gsys->getFrameTime() * 0.5f;

		static int chas = 15;
		static int cmax = 20;

		if (mController->keyClick(KBBTN_X)) {
			chas++;
		} else if (mController->keyClick(KBBTN_Y)) {
			chas--;
		}

		mPlayer->refresh(gfx);

		static f32 rspin = 0.0f;
		rspin += gsys->getFrameTime() * 5.0f;

		// what is this cursed bit of code? what happened here colin.
		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.useMatrix(Matrix4f::ident, 0);

		f32 unused = mController->mTriggerR / 170.0f * 4.0f + 3.0f;
		gfx.useMatrix(Matrix4f::ident, 0);

		if (mEnableLightPool) {
			FOREACH_NODE(LightPool, mLightPool.mChild, lightPool)
			{
				lightPool->draw(gfx);
			}
		}

		Node::draw(gfx);
		gfx.flushCachedShapes();
		gsys->flushLFlares(gfx);

		gfx.setOrthogonal(mtx1.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.useMatrix(Matrix4f::ident, 0); // colin i think it's been set mate

		static f32 mfade = 0.0f;

		if (mCurrentMenu) {
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

		STACK_PAD_TERNARY(mCurrentMenu, 2);
		if (mCurrentMenu) {
			drawMenu(gfx, mCurrentMenu, 1.0f);
		} else {
			startWindow->draw(gfx);
			titleWindow->draw(gfx);
			if (totalWindow) {
				gfx.setOrthogonal(mtx1.mMtx, AREA_FULL_SCREEN(gfx));
				totalWindow->draw(gfx);
			}
		}

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

	void menuSelectOption(Menu& parent)
	{
		mNextSectionsFlag         = parent.mCurrentItem->mData;
		gameflow.mIsChallengeMode = FALSE;
		Jac_SceneExit(SCENE_Exit, 0);
		parent.close();
		mState = 1;
		gsys->setFade(0.0f, 3.0f);
	}

	void menuChallengeOption(Menu& parent)
	{
		mNextSectionsFlag = parent.mCurrentItem->mData;
		gameflow.mGamePrefs.Initialise();
		gameflow.mIsChallengeMode = TRUE;
		Jac_SceneExit(SCENE_Exit, 0); // Just an educated guess, as this function is DLL-exclusive.
		parent.close();
		mState = 1;
		gsys->setFade(0.0f, 3.0f);
	}

	void drawMenu(Graphics& gfx, Menu* menu, f32 p3)
	{
		if (menu->mAlignToParentItem) {
			drawMenu(gfx, menu->mParentMenu, p3 * 0.5f);
		}

		menu->draw(gfx, p3);
	}

	// _00     = VTBL
	// _00-_20 = Node
	u32 mState;                   // _20
	u32 mNextSectionsFlag;        // _24, flag that stores the next OnePlayerSection and Section - see defines in Section.h.
	Menu* mMenu;                  // _28
	Menu* mCurrentMenu;           // _2C
	Controller* mController;      // _30
	Font* mFont;                  // _34
	u8 _UNUSED38[0x10];           // _38
	f32 mStartTransitionTimer;    // _48
	f32 mCameraDistanceScale;     // _4C
	CinematicPlayer* mPlayer;     // _50
	Camera mCamera;               // _54
	f32 _UNUSED39C;               // _39C
	u8 _UNUSED3A0[0x3B4 - 0x3A0]; // _3A0
	Vector3f _UNUSED3B4;          // _3B4
	u8 _UNUSED3C0[0x4];           // _3C0
	LightPool mLightPool;         // _3C4
	int mEnableLightPool;         // _A34
	u8 _UNUSEDA38[0x4];           // _A38
	DayMgr* mDayMgr;              // _A3C
	Vector3f mCameraFocusPoint;   // _A40
	                              // this has two extra CoreNodes at the end in the DLL, but not in the DOL
};

/**
 * @todo: Documentation
 */
void TitlesMovieInterface::message(int a1, int)
{
	switch (a1) {
	case 0:
		startWindow->start();
		startWindowOn = true;
		break;
	}
}

/**
 * @todo: Documentation
 */
void TitlesSection::init()
{
	Node::init("<TitlesSection>");
	Jac_BackDVDBuffer();
	gsys->mTimerState = TS_Off;

	// run title screen at 60 fps
	gsys->setFrameClamp(1);

	gsys->setDataRoot("dataDir/");
	gameflow.mLevelBannerTex         = nullptr;
	gameflow.mLevelBannerFadeValue   = 1.0f;
	gameflow.mGamePrefs.mHasSaveGame = true;
#if defined(VERSION_G98E01_PIKIDEMO)
#else
	if (gameflow.mMemoryCard.getMemoryCardState(true) == CARD_RESULT_READY && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
		gameflow.mMemoryCard.loadOptions();
	}
#endif
	gameflow.mGamePrefs.fixSoundMode();
	gsys->startLoading(&gameflow.mGameLoadIdler, true, gameflow.mIsNintendoLoadLogo ? 0 : 60);

	int beforeLang = gameflow.mLanguageIndex;
#if defined(VERSION_GPIP01_00)
	gameflow.mLanguageIndex = gameflow.mGamePrefs.getChildMode();
	if (gameflow.mLanguageIndex < 0 || gameflow.mLanguageIndex > 4) {
		PRINT("trying to load language %d\n", gameflow.mLanguageIndex);
		gameflow.mLanguageIndex = 0;
	}
#else
	if (!gameflow.mGamePrefs.getChildMode()) {
		gameflow.mLanguageIndex = 0;
	} else {
		gameflow.mLanguageIndex = 1;
	}
#endif

	if (gameflow.mLanguageIndex != beforeLang) {
		preloadLanguage();
	}
	gameflow.mIsChallengeMode  = FALSE;
	gameflow._2B8              = 0;
	gameflow.mCurrIntroMovieID = MOV_GrowDemo;

	switch (gameflow.mNextOnePlayerSectionID) {
	case ONEPLAYER_GameSetup:
		add(new TitleSetupSection);
		break;
	}
	PRINT("ending loading!\n");
	gsys->endLoading();
	PRINT("done!\n");
	Jac_SceneSetup(SCENE_Title, 0);
}
