#include "MapSelect.h"

#include "Camera.h"
#include "Controller.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "Demo.h"
#include "FlowController.h"
#include "Font.h"
#include "Graphics.h"
#include "Menu.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/piki_scene.h"
#include "sysNew.h"
#include "system.h"
#include "zen/DrawCM.h"
#include "zen/DrawWorldMap.h"

/// Size of the message heap (102 kb).
#define MESSAGE_HEAP_SIZE (0x19800)

// Macros for packing and unpacking the section compression flag.
// (this packing is a holdover from TitlesSection where there's also section transitions, not just OnePlayerSection).

/// Packs next OnePlayerSection subsection ID to transit to, to be stored in a flag.
#define PACK_NEXT_ONEPLAYER(onePlayerID) (onePlayerID) << 16

/// Unpacks next OnePlayerSection subsection ID from flag.
#define UNPACK_NEXT_ONEPLAYER(flag) (flag) >> 16

/// Challenge mode map select screen.
static zen::DrawCMcourseSelect* selectWindow;

/// Story mode world map screen.
static zen::DrawWorldMap* mapWindow;

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("MapSelect")

/**
 * @brief Initialising object for both the Challenge Mode map select and story mode world map screens.
 *
 * Localised to just the source file, so effectively private.
 * (Lives in the source file because it has file-specific PRINT statements.)
 *
 * @note Size: 0x384.
 */
struct MapSelectSetupSection : public Node {

	/**
	 * @brief States that the section can be in, to control transitions and actions.
	 */
	enum State {
		Inactive = -1, ///< no longer active.
		Active   = 0,  ///< normal/active state.
		Exit     = 1,  ///< fading out/exiting/entering an area.
	};

	// fun fact: these need to be ahead of the ctor for function pointer nonsense

	/**
	 * @brief Callback function to open all story mode maps on the map debug menu.
	 *
	 * @param parent Parent debug menu.
	 */
	void openAllMaps(Menu& parent)
	{
		PRINT("opening all maps !!\n");
		for (int i = 0; i < STAGE_COUNT_INCLUDING_TESTMAPS; i++) {
			gameflow.mPlayState.openStage(i);
		}

		makeMapsMenu();

		parent.mPreviousMenu = mMapListMenu;
		STACK_PAD_TERNARY(parent.mPreviousMenu, 1);
	}

	/**
	 * @brief Callback function to open all challenge mode maps on the map debug menu.
	 *
	 * @param parent Parent debug menu.
	 */
	void openAllChMaps(Menu& parent)
	{
		PRINT("opening all challenge maps !!\n");
		for (int i = 0; i < CHALSTAGE_COUNT; i++) {
			gameflow.mGamePrefs.openStage(i);
		}

		makeMapsMenu();

		parent.mPreviousMenu = mMapListMenu;
		STACK_PAD_TERNARY(parent.mPreviousMenu, 1);
	}

	/// Constructs map select debug menu, adding any stages that are open (and marked visible in their .ini files).
	void makeMapsMenu()
	{
		mMapListMenu                     = new Menu(mController, mConsFont);
		mMapListMenu->mAnchorPoint.mMinX = glnWidth / 2;
		mMapListMenu->mAnchorPoint.mMinY = glnHeight / 2 + 30;

		// select with A or START
		mMapListMenu->addKeyEvent(Menu::KeyEventType::Navigate, KBBTN_START | KBBTN_A,
		                          new Delegate1<MapSelectSetupSection, Menu&>(this, &menuSelectOption));

		// exit menu/submenu with B
		mMapListMenu->addKeyEvent(Menu::KeyEventType::SpecialRelease, KBBTN_B,
		                          new Delegate1<Menu, Menu&>(mMapListMenu, &Menu::menuCloseMenu));

		// load in all stages, both challenge mode and story mode
		for (StageInfo* inf = (StageInfo*)flowCont.mStageList.mChild; inf; inf = (StageInfo*)inf->mNext) {
			if (gameflow.mIsChallengeMode) {
				PRINT("checking map in challenge mode!\n");
				bool valid = gameflow.mGamePrefs.isStageOpen(inf->mChalStageID);
				// must be both open and marked visible in its .ini
				if (inf->mIsVisible && valid) {
					mMapListMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr);
				}
			} else {
				bool valid = gameflow.mPlayState.isStageOpen(inf->mStageID);
				// must be open, marked visible in its .ini, and also *not* a challenge mode stage (to avoid dupes)
				if (inf->mIsVisible && valid && inf->mChalStageID == CHALSTAGE_NOT) {
					mMapListMenu->addOption((int)inf, StdSystem::stringDup(inf->mStageName), nullptr);
				}
			}
		}

		STACK_PAD_VAR(2);
	}

	/**
	 * @brief Callback function to select the hovered option.
	 *
	 * @param parent Parent debug menu.
	 */
	void menuSelectOption(Menu& parent)
	{
		// for this menu, the payload data is a pointer to the map's StageInfo
		StageInfo* info = reinterpret_cast<StageInfo*>(parent.mCurrentItem->mData);

		// prepare to enter gameplay for the selected course
		enterCourse(info);
		mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_NewPikiGame);
		parent.close();
		gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());

		// start fade-out
		mSectionState = Exit;
		gsys->setFade(0.0f, 3.0f);
	}

	/// Constructs a map select helper object; also sets up the relevant selection screen (story mode or challenge mode) and the debug menu.
	MapSelectSetupSection()
	{
		setName("MapSelect section");

		// This section uses `SeSystem` without constructing it. Bad!
#if defined(BUGFIX)
		seSystem = new SeSystem();
#endif

		mController   = new Controller(1);
		mSectionState = Active;
		// need console font for debug menus, and big font for regular gameplay-visible text.
		mConsFont = new Font;
		mConsFont->setTexture(gsys->loadTexture("consFont.bti", true), 16, 8);
		mBigFont = new Font;
		mBigFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);

		// make debug menu
		makeMapsMenu();
		mMapListMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);
		mMapListMenu->addOption(0, "Open All Maps",
		                        !gameflow.mIsChallengeMode ? new Delegate1<MapSelectSetupSection, Menu&>(this, &openAllMaps)
		                                                   : new Delegate1<MapSelectSetupSection, Menu&>(this, &openAllChMaps));
		mActiveOverlayMenu = nullptr;

		// decide if we need to set up a world map screen or challenge mode map select screen
		mapWindow    = nullptr;
		selectWindow = nullptr;
		if (!gameflow.mIsChallengeMode) {
			// story mode = world map
			mapWindow = new zen::DrawWorldMap;

			bool old = gsys->mTogglePrint != FALSE;
			// you wanna hear this, I promise - Colin, probably.
			gsys->mTogglePrint = TRUE;
#if defined(VERSION_PIKIDEMO)
			_Print("opening map window with %d : %d\n", gameflow.mPendingStageUnlockID, gameflow.mCurrentStageID);
#else
			(gameflow.mCurrentStageID != 0); // huh?
			PRINT("opening map window with %d : %d\n", gameflow.mPendingStageUnlockID, gameflow.mCurrentStageID);
#endif
			gsys->mTogglePrint = old;

			// start world map screen, including the right cursor location and any unlock animations
			// (default is Impact Site with no animations)
			mapWindow->start(zen::DrawWorldMap::startModeFlag(gameflow.mPendingStageUnlockID == -1 ? zen::DrawWorldMap::None
			                                                                                       : gameflow.mPendingStageUnlockID),
			                 zen::DrawWorldMap::startPlaceFlag(gameflow.mCurrentStageID == -1 ? zen::DrawWorldMap::ImpactSite
			                                                                                  : gameflow.mCurrentStageID));
		} else {
			// challenge mode! always day 1.
			gameflow.mWorldClock.mCurrentDay = 1;
			selectWindow                     = new zen::DrawCMcourseSelect;
			selectWindow->start();
		}
		gsys->setFade(1.0f, 3.0f);
		// default target is to exit back to title unless we positively confirm otherwise
		mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_GameExit);
	}

	/// Updates the screen each frame and alters the state.
	virtual void update() // _10 (weak)
	{
		mController->update();

#if defined(DEVELOP) || defined(WIN32)
		// press R to increase the day by 1 (can't go above 30)
		if (mController->keyClick(KBBTN_R)) {
			if (++gameflow.mWorldClock.mCurrentDay > MAX_DAYS) {
				gameflow.mWorldClock.mCurrentDay = MAX_DAYS;
			}
		}
		// press L to decrease the day by 1 (can't go below 1)
		if (mController->keyClick(KBBTN_L)) {
			if (--gameflow.mWorldClock.mCurrentDay < 1) {
				gameflow.mWorldClock.mCurrentDay = 1;
			}
		}
#endif

		// update debug menu if we have it
		if (mActiveOverlayMenu) {
			mActiveOverlayMenu = mActiveOverlayMenu->doUpdate(false);

		} else if (mSectionState == Active) {

#if defined(DEVELOP) || defined(WIN32)
			// press Z in the DEVELOP build to open the debug menu!
			if (!mActiveOverlayMenu && mController->keyClick(KBBTN_Z)) {
				// Identical to the implementation of `NewPikiGameSetupSection::openMenu`.
				mActiveOverlayMenu = mMapListMenu;
				mActiveOverlayMenu->open(false);
				mActiveOverlayMenu->mIsMenuChanging = true;
			} else
#endif
			{
				// process challenge mode if we've made a decision
				if (selectWindow && selectWindow->update(mController)) {
					zen::DrawCMcourseSelect::returnStatusFlag chalStatus = selectWindow->getReturnStatusFlag();
					if (chalStatus == zen::DrawCMcourseSelect::Exit) {
						// exit back to previous screen (in this case title)
						mSectionState = Exit;
						gsys->setFade(0.0f, 3.0f);

					} else {
						// we made a positive selection
						for (StageInfo* stage = (StageInfo*)flowCont.mStageList.mChild; stage; stage = (StageInfo*)stage->mNext) {
							// if positive selection matches a course ID, prepare to enter that course
							if (stage->mChalStageID == chalStatus) {
								enterCourse(stage);
								mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_NewPikiGame);

								gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
								mSectionState = Exit;
								gsys->setFade(0.0f, 3.0f);
								break;
							}
						}
					}
				}

				// handle story mode world map screen if we've made a decision
				if (mapWindow && mapWindow->update(mController)) {
					zen::DrawWorldMap::returnStatusFlag returnStatus = mapWindow->getReturnStatusFlag();
					if (returnStatus == zen::DrawWorldMap::RET_ReturnToTitle) {
						// player wants to exit, so exit
						mSectionState = Exit;
						gsys->setFade(0.0f, 3.0f);
					} else {
						// player made a positive selection
						for (StageInfo* stage = (StageInfo*)flowCont.mStageList.mChild; stage; stage = (StageInfo*)stage->mNext) {
							if (stage->mStageID == returnStatus) {
								// prepare to enter selected map
								enterCourse(stage);
								mNextSectionsFlag = PACK_NEXT_ONEPLAYER(ONEPLAYER_NewPikiGame);

								gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
								mSectionState = Exit;
								gsys->setFade(0.0f, 3.0f);
								break;
							}
						}
					}
				}
			}
		}

		// we want to exit (and the debug menu isn't active), so force a transition
		if (mSectionState == Exit && !mActiveOverlayMenu && gsys->getFade() == 0.0f) {
			mSectionState                    = Inactive;
			gameflow.mNextOnePlayerSectionID = UNPACK_NEXT_ONEPLAYER(mNextSectionsFlag);
			Jac_SceneExit(SCENE_Exit, 0);
			gsys->softReset();
		}
	}

	/**
	 * @brief Renders the screen and adjusts the render based on screen status.
	 * @param gfx Graphics context for rendering.
	 */
	virtual void draw(Graphics& gfx) // _14 (weak)
	{
		// full-screen
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);
		Matrix4f orthoMtx;
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setColour(COLOUR_BLACK, true);
		gfx.setAuxColour(Colour(0, 0, 64, 255));
		gfx.fillRectangle(AREA_FULL_SCREEN(gfx));

		// draw challenge mode select
		if (selectWindow) {
			selectWindow->draw(gfx);
		}

		// draw story mode world map
		if (mapWindow) {
			mapWindow->draw(gfx);
		}

		// draw debug menu over the top
		Matrix4f orthoMtxDebug;
		gfx.setOrthogonal(orthoMtxDebug.mMtx, AREA_FULL_SCREEN(gfx));

		if (mActiveOverlayMenu) {
			mActiveOverlayMenu->draw(gfx, 1.0f);
		}
	}

	/**
	 * @brief Passes information about the selected course to the game flow handler.
	 *
	 * If we have challenge mode unlocked (and we're entering a story mode course),
	 * this will unlock the selected course in challenge mode if it isn't already.
	 *
	 * @param info Info for the stage to enter.
	 */
	void enterCourse(StageInfo* info)
	{
		flowCont.mCurrentStage = info;
		sprintf(flowCont.mCurrStageFilePath, "%s", info->mFileName);
		sprintf(flowCont.mDoorStageFilePath, "%s", info->mFileName);
		if (gameflow.mGamePrefs.isChallengeOpen()) {
			gameflow.mGamePrefs.openStage(info->mStageID);
		}
	}

	// _00     = VTBL
	// _00-_20 = Node
	u32 mSectionState;        ///< _20, whether screen is inactive, active, or exiting - see `State` enum.
	u32 mNextSectionsFlag;    ///< _24, flag that stores the next OnePlayerSection and Section - see `ONEPLAYER` macros.
	Menu* mMapListMenu;       ///< _28, debug menu for selecting (and unlocking) maps.
	Menu* mActiveOverlayMenu; ///< _2C, active pop-up/overlay menu - only ever used for the debug menu.
	Controller* mController;  ///< _30, active controller.
	Font* mConsFont;          ///< _34, console font (for debug menu).
	Font* mBigFont;           ///< _38, big font (for regular text).
	Camera mCamera;           ///< _3C, dedicated camera - seemingly unused.
};

/**
 * @brief Constructs map select subsection - either challenge mode map select, or story mode world map.
 *
 * Most of the hard work gets farmed out to `MapSelectSetupSection` above, including transiting to a new subsection.
 */
MapSelectSection::MapSelectSection()
{
	Node::init("<MapSelectSection>");
	// run map select at 60 fps
	gsys->setFrameClamp(1);

	// these are all unused
	flowCont._254           = 0;
	flowCont._258           = 0;
	flowCont.mNaviSeedCount = 0;
	flowCont._250           = 0;

	// set up the message heap, to show "tutorial" text etc
	int size = MESSAGE_HEAP_SIZE;
	gsys->mHeaps[SYSHEAP_Message].init("message", AYU_STACK_GROW_UP, System::alloc(size), size);

	gsys->startLoading(nullptr, true, 60);

	// do the actual bulk of the work
	add(new MapSelectSetupSection);
	gsys->endLoading();

	if (gameflow.mIsChallengeMode) {
		// play challenge mode select music
		Jac_SceneSetup(SCENE_ChalSelect, 0);
	} else {
		// play world map music
		Jac_SceneSetup(SCENE_WorldMap, 0);
	}

	// also set up cutscene parms? idk why we would do this here and not NewPikiGameSection.
	demoParms->initCore("");
	gameflow.addGenNode("DemoFlag Parms", demoParms);
}
