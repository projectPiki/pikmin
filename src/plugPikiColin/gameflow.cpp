#include "gameflow.h"

#include "BaseApp.h"
#include "Controller.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "Dolphin/os.h"
#include "GameCourseClearSection.h"
#include "Geometry.h"
#include "Graphics.h"
#include "LoadIdler.h"
#include "Menu.h"
#include "MovSampleSection.h"
#include "MoviePlayer.h"
#include "NinLogoSection.h"
#include "OnePlayerSection.h"
#include "PaniTestSection.h"
#include "RumbleMgr.h"
#include "Texture.h"
#include "TitlesSection.h"
#include "WorldClock.h"
#include "jaudio/piki_scene.h"
#include "sysNew.h"
#include "timers.h"
#include "zen/ogTest.h"

/// Global game state.
GameFlow gameflow;

/// Global game application.
BaseApp* app;

/// Unused load logo "spin" value.
static f32 llspin;

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameFlow");

static const char* timopts[] = { " [off]", "  [on]", "[full]" };

/**
 * @brief Draws the loading screen while game is idling, including level banner.
 *
 * @param gfx Graphics unit performing the drawing.
 */
void GameLoadIdler::draw(Graphics& gfx)
{
	gfx.mAmbientFogColour.set(48, 48, 48, 255); // very dark grey, but not perfect black
	gfx.setViewport(AREA_FULL_SCREEN(gfx));
	gfx.setScissor(AREA_FULL_SCREEN(gfx));
	gfx.setClearColour(COLOUR_TRANSPARENT);
	gfx.clearBuffer(3, false);

	// try and display level banner
	if (!gameflow.mLevelBannerTex) {
		return;
	}

	gameflow.mLevelBannerFadeValue += (1.0f / 300.0f);
	if (gameflow.mLevelBannerFadeValue > 1.0f) {
		gameflow.mLevelBannerFadeValue = 1.0f;
	}

	// draw level banner
	gameflow.drawLoadLogo(gfx, true, gameflow.mLevelBannerTex, gameflow.mLevelBannerFadeValue);
}

/**
 * @brief Draws a logo texture while on a loading screen.
 *
 * @param gfx Graphics unit performing the drawing.
 * @param force60FPSSpin Unused toggle for logo spin speed - either 60 FPS or the current frame rate.
 * @param logoTex Texture for the logo to display.
 * @param fadeInFactor Scaling factor to apply to the logo's colour alpha - 0 (no alpha) to 1 (full alpha).
 */
void GameFlow::drawLoadLogo(Graphics& gfx, bool force60FPSSpin, Texture* logoTex, f32 fadeInFactor)
{
	if (!logoTex) {
		return;
	}

	Matrix4f screenMtx;

	// this spin speed is unused. maybe the logos used to rotate?
	llspin += (force60FPSSpin) ? 1.0f / 60.0f : gsys->getFrameTime();

	gfx.setOrthogonal(screenMtx.mMtx, AREA_FULL_SCREEN(gfx));

	if (mIsNintendoLoadLogo) {
// red - this is just for the Nintendo logo on boot-up.
#if defined(VERSION_GPIJ01_01)
		gfx.setColour(Colour(0, 70, 255, fadeInFactor * 255.0f), true);
		gfx.setAuxColour(Colour(0, 70, 255, fadeInFactor * 255.0f));
#else
		gfx.setColour(Colour(220, 0, 0, fadeInFactor * 255.0f), true);
		gfx.setAuxColour(Colour(220, 0, 0, fadeInFactor * 255.0f));
#endif
	} else {
		// browny-red and gold.
		gfx.setColour(Colour(192, 64, 0, fadeInFactor * 255.0f), true);
		gfx.setAuxColour(Colour(255, 192, 0, fadeInFactor * 255.0f));
	}

	gfx.useTexture(logoTex, GX_TEXMAP0);

	// calc where to start drawing the logo so it's centered on the screen
	int left = gfx.mScreenWidth / 2 - logoTex->mWidth / 2;
	int top  = gfx.mScreenHeight / 2 - logoTex->mHeight / 2;

	// the Nintendo logo on boot-up isn't centered vertically for whatever reason
	if (mIsNintendoLoadLogo) {
		top -= 40;
	}

	gfx.drawRectangle(RectArea(left, top, left + logoTex->mWidth, top + logoTex->mHeight),
	                  RectArea(0, 0, logoTex->mWidth, logoTex->mHeight), nullptr);

	STACK_PAD_VAR(1);
}

/**
 * @brief Sets the speed of in-game time progression, relative to real-world time.
 *
 * @param minsPerGameDay Number of real-world minutes one full (24hr) in-game "day" should take.
 * @note UNUSED Size: 000020
 */
void WorldClock::setClockSpd(f32 minsPerGameDay)
{
	mRealSecsPerGameDay  = minsPerGameDay * 60.0f;
	mRealSecsPerGameHour = mRealSecsPerGameDay / mHoursInDay;
}

/**
 * @brief Sets the current time of day, along with relevant quick-access time parts.
 */
void WorldClock::setTime(f32 timeOfDay)
{
	// store just the hour component
	mCurrentGameHour = (int)timeOfDay;

	// calc how many real seconds have elapsed since the last game hour change
	mRealSecsIntoHour = mRealSecsPerGameHour * (timeOfDay - f32(int(timeOfDay)));

	// calc quick-access game-relevant values
	mCurrentGameMinute = (60.0f / mRealSecsPerGameHour) * mRealSecsIntoHour;
	mTimeOfDay         = f32(mCurrentGameHour) + (mRealSecsIntoHour / mRealSecsPerGameHour);
	mPrevTimeOfDay     = mTimeOfDay;
}

/**
 * @brief Resets the in-game time calculations, including the clock speed.
 *
 * @param minsPerGameDay Number of real-world minutes one full (24hr) in-game "day" should take.
 * @note UNUSED Size: 000044
 */
void WorldClock::reset(f32 minsPerGameDay)
{
	mRealSecsIntoHour  = 0.0f;
	mPrevTimeOfDay     = 0.0f;
	mCurrentDay        = 0;
	mCurrentGameHour   = 0;
	mCurrentGameMinute = 0;
	mHoursInDay        = HOURS_IN_DAY;
	setClockSpd(minsPerGameDay);
}

/**
 * @brief Calculates how many in-game days have passed since the supplied reference day/time.
 *
 * @param referenceDay In-game "day", counted from start of save file (e.g. halfway through Day 1 would be 0.5f).
 * @return How many days have passed between the supplied day and current time.
 * @note UNUSED Size: 00006C
 */
f32 WorldClock::age(f32 referenceDay)
{
	// calc number of game hours since start of save file
	f32 hours = f32(mCurrentDay) * mHoursInDay + f32(mCurrentGameHour);

	// convert to (fractional) game days, and calculate delta
	return (hours * mRealSecsPerGameHour + mRealSecsIntoHour) / mRealSecsPerGameDay - referenceDay;
}

/**
 * @brief Updates the in-game time and any derived quick-access amounts.
 *
 * @param playRate Speed - how many "frames" should be advanced this frame (only ever called with 1.0f).
 */
void WorldClock::update(f32 playRate)
{
	mRealSecsIntoHour += gsys->getFrameTime() * playRate;
	if (mRealSecsIntoHour >= mRealSecsPerGameHour) {
		mRealSecsIntoHour -= mRealSecsPerGameHour;
		mCurrentGameHour++;
		if (mCurrentGameHour >= HOURS_IN_DAY) {
			mCurrentGameHour -= HOURS_IN_DAY;
			mCurrentDay++;
		}
	}

	mCurrentGameMinute = int(60.0f / mRealSecsPerGameHour * mRealSecsIntoHour);
	mTimeOfDay         = mCurrentGameHour + mRealSecsIntoHour / mRealSecsPerGameHour;
	mDeltaTimeOfDay    = mTimeOfDay - mPrevTimeOfDay;
	if (mDeltaTimeOfDay < 0.0f) {
		mDeltaTimeOfDay += HOURS_IN_DAY;
	}

	mPrevTimeOfDay = mTimeOfDay;
}

/**
 * @brief Toggles the debug timer display and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuToggleTimers(Menu& menu)
{
	gsys->mTimerState = (gsys->mTimerState + 1) % 3;
	gsys->mTimer->reset();
	sprintf(menu.mCurrentItem->mName, "Toggle Timers %s", timopts[gsys->mTimerState]);
}

/**
 * @brief Toggles the debug print display and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuTogglePrint(Menu& menu)
{
	gsys->mTogglePrint ^= TRUE;
	sprintf(menu.mCurrentItem->mName, "Toggle Print %s", (gsys->mTogglePrint) ? " [on]" : "[off]");
}

/**
 * @brief Toggles the debug info display and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuToggleDInfo(Menu& menu)
{
	gsys->mToggleDebugInfo ^= TRUE;
	sprintf(menu.mCurrentItem->mName, "Toggle DInfo %s", (gsys->mToggleDebugInfo) ? " [on]" : "[off]");
}

/**
 * @brief Toggles the debug extra info display and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuToggleDExtra(Menu& menu)
{
	gsys->mToggleDebugExtra ^= TRUE;
	sprintf(menu.mCurrentItem->mName, "Toggle DExtra %s", (gsys->mToggleDebugExtra) ? " [on]" : "[off]");
}

/**
 * @brief Toggles the debug blur display and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuToggleBlur(Menu& menu)
{
	gsys->mToggleBlur ^= TRUE;
	sprintf(menu.mCurrentItem->mName, "Toggle Blur %s", (gsys->mToggleBlur) ? " [on]" : "[off]");
}

/**
 * @brief Toggles the debug file info display and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuToggleInfo(Menu& menu)
{
	gsys->mToggleFileInfo ^= TRUE;
	sprintf(menu.mCurrentItem->mName, "Toggle FileInfo %s", (gsys->mToggleFileInfo) ? " [on]" : "[off]");
}

/**
 * @brief Toggles the debug collision display and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuToggleColls(Menu& menu)
{
	gsys->mToggleColls ^= TRUE;
	sprintf(menu.mCurrentItem->mName, "Toggle Colls %s", (gsys->mToggleColls) ? " [on]" : "[off]");
}

/**
 * @brief Sets up the game flow debug options menu, along with all toggles and callbacks.
 *
 * @param parent Parent menu.
 * @note UNUSED Size: 0004DC
 */
void GameFlow::addOptionsMenu(Menu* parent)
{
	char* timerBuf = new char[0x40];
	sprintf(timerBuf, "Toggle Timers %s", timopts[gsys->mTimerState]);
	parent->addOption(0, timerBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleTimers));

	char* printBuf = new char[0x40];
	sprintf(printBuf, "Toggle Print %s", (gsys->mTogglePrint) ? " [on]" : "[off]");
	parent->addOption(0, printBuf, new Delegate1<GameFlow, Menu&>(this, &menuTogglePrint));

	char* debugInfoBuf = new char[0x40];
	sprintf(debugInfoBuf, "Toggle DInfo %s", (gsys->mToggleDebugInfo) ? " [on]" : "[off]");
	parent->addOption(0, debugInfoBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleDInfo));

	char* debugExtraBuf = new char[0x40];
	sprintf(debugExtraBuf, "Toggle DExtra %s", (gsys->mToggleDebugExtra) ? " [on]" : "[off]");
	parent->addOption(0, debugExtraBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleDExtra));

	char* blurBuf = new char[0x40];
	sprintf(blurBuf, "Toggle Blur %s", (gsys->mToggleBlur) ? " [on]" : "[off]");
	parent->addOption(0, blurBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleBlur));

	char* fileInfoBuf = new char[0x40];
	sprintf(fileInfoBuf, "Toggle FileInfo %s", (gsys->mToggleFileInfo) ? " [on]" : "[off]");
	parent->addOption(0, fileInfoBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleInfo));

	char* collsBuf = new char[0x40];
	sprintf(collsBuf, "Toggle Colls %s", (gsys->mToggleColls) ? " [on]" : "[off]");
	parent->addOption(0, collsBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleColls));
}

static const char* filterNames[] = {
	"custom",
	"DF off",
};

/**
 * @brief Toggles the vertical filter type and updates the debug menu text.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuChangeFilter(Menu& menu)
{
	mFilterType ^= 1;
	sprintf(menu.mCurrentItem->mName, "type = %s", filterNames[mFilterType]);
	gsys->mDGXGfx->setVerticalFilter(mVFilters[mFilterType]);
	gsys->mDGXGfx->videoReset();
}

/**
 * @brief Increases the currently selected vertical filter value.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuIncreaseFilter(Menu& menu)
{
	if (mVFilters[0][menu.mCurrentItem->mData] < 128) {
		mVFilters[0][menu.mCurrentItem->mData]++;
	}

	sprintf(menu.mCurrentItem->mName, "Filter setting %d", mVFilters[0][menu.mCurrentItem->mData]);
	if (mFilterType == FILTER_Custom) {
		gsys->mDGXGfx->setVerticalFilter(mVFilters[0]);
		gsys->mDGXGfx->videoReset();
	}
}

/**
 * @brief Decreases the currently selected vertical filter value.
 *
 * @param menu Caller debug menu.
 */
void GameFlow::menuDecreaseFilter(Menu& menu)
{
	if (mVFilters[0][menu.mCurrentItem->mData] != 0) {
		mVFilters[0][menu.mCurrentItem->mData]--;
	}

	sprintf(menu.mCurrentItem->mName, "Filter setting %d", mVFilters[0][menu.mCurrentItem->mData]);
	if (mFilterType == FILTER_Custom) {
		gsys->mDGXGfx->setVerticalFilter(mVFilters[0]);
		gsys->mDGXGfx->videoReset();
	}
}

/**
 * @brief Sets up the vertical filter debug menu, along with all ranges and callbacks.
 *
 * @param parent Parent menu.
 * @note UNUSED Size: 000214
 */
void GameFlow::addFilterMenu(Menu* parent)
{
	char* changeBuf = new char[0x40];
	sprintf(changeBuf, "type = %s", filterNames[mFilterType]);
	parent->addOption(0, changeBuf, new Delegate1<GameFlow, Menu&>(this, &menuChangeFilter));
	parent->addOption(MENU_FAKE_OPTION_FOR_GAP);
	for (int i = 0; i < 7; i++) {
		char* buf = new char[0x40];
		sprintf(buf, "Filter setting %d", mVFilters[i]);
		parent->addOption(i, buf, nullptr);
		parent->addKeyEvent(Menu::KeyEventType::Release, KBBTN_Y, new Delegate1<GameFlow, Menu&>(this, &menuDecreaseFilter));
		parent->addKeyEvent(Menu::KeyEventType::Release, KBBTN_X, new Delegate1<GameFlow, Menu&>(this, &menuIncreaseFilter));
	}
}

/**
 * @brief Reads in game flow parameters from stream (.bin file).
 *
 * @param input Stream to read data from.
 */
void GameFlow::read(RandomAccessStream& input)
{
	mParameters->read(input);
}

/**
 * @brief Loads language-specific resources and sets up required paths.
 *
 * This is stubbed in the DLL, which makes decompiling some of the unused code tricky.
 *
 * @warning NON-MATCHING! Functionally equivalent.
 */
void preloadLanguage()
{
	int unused; // for r30
	int heapIdx;
	int lang;

	gsys->mCacher->purgeAll();
	heapIdx = gsys->getHeapNum();

	// use the language heap for this action
	gsys->setHeap(SYSHEAP_Lang);
	gsys->resetHeap(SYSHEAP_Lang, AYU_STACK_GROW_UP);
	gsys->getHeap(gsys->getHeapNum())->getFree();

	gsys->mBaseAramAllocator.reset();
	gsys->mDvdRoot.initCore("");
	gsys->mFileList = (DirEntry*)&gsys->mDvdRoot;
	gsys->setActiveAramAllocator(&gsys->mBaseAramAllocator);

	// set and load language-specific file
	gsys->parseArchiveDirectory(gameflow.mLangModes[gameflow.mLanguageIndex].mDirPath,
	                            gameflow.mLangModes[gameflow.mLanguageIndex].mArcPath);
	gsys->loadBundle(gameflow.mLangModes[gameflow.mLanguageIndex].mBunPath, true);
	gsys->set2DRoot(gameflow.mLangModes[gameflow.mLanguageIndex].mBloPath, gameflow.mLangModes[gameflow.mLanguageIndex].mTexPath);

	gsys->getHeap(gsys->getHeapNum())->getFree();

	// restore the previous heap
	gsys->setHeap(heapIdx);

	!(unused++);
}

/**
 * @brief Loads the loading screen banner texture from file and attaches it.
 *
 * @param texPath Path to banner texture to load.
 * @return Pointer to newly set banner texture.
 */
Texture* GameFlow::setLoadBanner(immut char* texPath)
{
	int heapIdx = gsys->mActiveHeapIdx;

	// use the loading heap for this action
	gsys->resetHeap(SYSHEAP_Load, AYU_STACK_GROW_UP);
	gsys->setHeap(SYSHEAP_Load);

	// try and load texture
	gameflow.mLastLoadedBannerTex = gsys->loadTexture(texPath, true);
	if (gameflow.mLastLoadedBannerTex) {
		gameflow.mLastLoadedBannerTex->attach();
	}

	// restore previous heap
	gsys->setHeap(heapIdx);

	return gameflow.mLastLoadedBannerTex;
}

/**
 * @brief Peforms a full reset of game state, memory, and resources, for fresh boot-up ("hard" reset).
 *
 * @param baseApp Pointer to game application, to be set as the global game context.
 */
void GameFlow::hardReset(BaseApp* baseApp)
{
	app  = baseApp;
	_1D4 = 0; // never used again
	PRINT("Doing HardReset!!\n");
	mFilterType = FILTER_Custom;

	// set values for no deflicker/no custom vertical filter (i.e. a 3-tap filter)
	mVFilters[FILTER_DFOff][0] = 0;
	mVFilters[FILTER_DFOff][1] = 0;
	mVFilters[FILTER_DFOff][2] = 21;
	mVFilters[FILTER_DFOff][3] = 22;
	mVFilters[FILTER_DFOff][4] = 21;
	mVFilters[FILTER_DFOff][5] = 0;
	mVFilters[FILTER_DFOff][6] = 0;

	mCurrGameSectionID      = -1;
	mNextGameSectionID      = SECTION_NinLogo;
	mNextOnePlayerSectionID = ONEPLAYER_GameSetup;
	_200                    = 0;            // never used again
	mNextIntroMovieID       = MOV_GrowDemo; // title screen idling movie demo to queue up first

	// Different versions handle language differently (duh) but a lot of the mechanics are hold-overs from JP.
	// The original japanese version has two modes: an adult text mode (otona), and a child text mode (kodomo).
	// - The adult mode has more kanji and more complicated exposition
	// - The child mode has mostly hiragana and katakana and simplified exposition
	// (This is why the setting for this is called "child mode").
	// The USA demo version kept the two versions separate, but the retail release made both point to the same (eng) files.
	// PAL repurposes this setting to hold which language is selected instead (English, French, German, Spanish, Italian).

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	mLanguageIndex = LANG_Adult;
	mLangModes[LANG_Adult].set("archives/blo_otona.dir", "dataDir/archives/blo_otona.arc", "screen/otona_tex/screen.bun",
	                           "screen/otona_blo/", "screen/otona_tex/");
	mLangModes[LANG_Child].set("archives/blo_kodomo.dir", "dataDir/archives/blo_kodomo.arc", "screen/kodomo_tex/screen.bun",
	                           "screen/kodomo_blo/", "screen/kodomo_tex/");
	gsys->set2DRoot("screen/sys_blo/", "screen/otona_tex/");

#elif defined(VERSION_GPIE01_00) || defined(VERSION_GPIE01_01)
	// in the US retail releases, there's no difference between these two settings - just a holdover from demo/jp
	mLanguageIndex = LANG_Adult;
	mLangModes[LANG_Adult].set("archives/blo_eng.dir", "dataDir/archives/blo_eng.arc", "screen/eng_tex/screen.bun", "screen/eng_blo/",
	                           "screen/eng_tex/");
	mLangModes[LANG_Child].set("archives/blo_eng.dir", "dataDir/archives/blo_eng.arc", "screen/eng_tex/screen.bun", "screen/eng_blo/",
	                           "screen/eng_tex/");
	gsys->set2DRoot("screen/sys_blo/", "screen/otona_tex/");

#elif defined(VERSION_GPIP01_00)
	mLanguageIndex = LANG_English;
	mLangModes[LANG_English].set("archives/blo__eng.dir", "dataDir/archives/blo__eng.arc", "screen/eng_tex/screen.bun", "screen/eng_blo/",
	                             "screen/eng_tex/");
	mLangModes[LANG_French].set("archives/blo__fre.dir", "dataDir/archives/blo__fre.arc", "screen/fre_tex/screen.bun", "screen/fre_blo/",
	                            "screen/fre_tex/");
	mLangModes[LANG_German].set("archives/blo__ger.dir", "dataDir/archives/blo__ger.arc", "screen/ger_tex/screen.bun", "screen/ger_blo/",
	                            "screen/ger_tex/");
	mLangModes[LANG_Spanish].set("archives/blo__spa.dir", "dataDir/archives/blo__spa.arc", "screen/spa_tex/screen.bun", "screen/spa_blo/",
	                             "screen/spa_tex/");
	mLangModes[LANG_Italian].set("archives/blo__ita.dir", "dataDir/archives/blo__ita.arc", "screen/ita_tex/screen.bun", "screen/ita_blo/",
	                             "screen/ita_tex/");
	gsys->set2DRoot("screen/sys_blo/", "screen/eng_tex/");

#endif

	mParameters = new Parms();

	// loading heap is 0x8000 bytes in size (32 kb)
	int loadHeapSize = 0x8000;

	// set time-related factors
	mWorldClock.reset(mParameters->mRealMinutesPerGameDay());
	mTimeMultiplier         = 1.0f;
	mGenFlowUpdateTickCount = 0;

	mMemoryCard.init();

	// set up load heap
	PRINT("load heap\n");
	gsys->mHeaps[SYSHEAP_Load].init("load", AYU_STACK_GROW_UP, new u8[loadHeapSize], loadHeapSize);

	// prepare nintendo logo to appear
	mLastLoadedBannerTex  = nullptr;
	mLevelBannerTex       = setLoadBanner("intro/nintendo.bti");
	mLevelBannerFadeValue = 1.0f;
	Jac_SceneSetup(SCENE_BootUp, 0);
	mIsNintendoLoadLogo = TRUE;

	PRINT("starting loading\n");
	gsys->startLoading(&mGameLoadIdler, true, 0);
	PRINT("done starting loading\n");

	mEffectDurationTimer = 0.0f;
	mTargetEffectAlpha   = 0.0f;
	mCurrentEffectAlpha  = 0.0f;
	mAppTickCounter      = 2;

	PRINT("reading parms\n");
	PRINT("load params\n");
	load("parms/", "gamePrms.bin", 1);

	// reset movie player and movie flags
	mDemoFlags   = GFDEMO_None;
	mMoviePlayer = new MoviePlayer();

	// set up controller rumble manager
	rumbleMgr = new RumbleMgr(true, false, false, false);
	rumbleMgr->reset();
	rumbleMgr->rumbleOption(true);

	mGamePrefs.Initialise();

	mFlowManager = new GameGenFlow("GameGenFlow");

	// load effects
	gsys->loadBundle("effects/pcr/effects.bun", false);
	gsys->loadBundle("effects/tex/effects.bun", false);
}

/**
 * @brief Performs a partial reset, reinitialising sections and resources.
 *
 * This is used between basically any transition of game section.
 */
void GameFlow::softReset()
{
	// make sure we don't debug-print all this while soft-resetting.
	BOOL togglePrint   = gsys->mTogglePrint;
	gsys->mTogglePrint = FALSE;

	if (mNextGameSectionID != mCurrGameSectionID) {
		// use the overlap heap for section change
		gsys->resetHeap(SYSHEAP_Ovl, AYU_STACK_GROW_UP);
		gsys->getHeap(SYSHEAP_Ovl)->setAllocType(AYU_STACK_GROW_UP);
		app->useHeap(SYSHEAP_Ovl);
		PRINT("*------------------------------------------- section change\n");
		AyuHeap* heap = gsys->getHeap(SYSHEAP_Ovl);

		// set up the application heap stack to the max size we can
		int max      = heap->getMaxFree();
		int type     = heap->setAllocType(AYU_STACK_GROW_UP);
		u8* appStack = new u8[heap->getMaxFree()];
		heap->setAllocType(type);
		gsys->mHeaps[SYSHEAP_App].init("app", AYU_STACK_GROW_UP, appStack, max);
		app->useHeap(SYSHEAP_App);
		gsys->getHeap(gsys->getHeapNum())->setAllocType(AYU_STACK_GROW_DOWN);

		switch (mNextGameSectionID) {
		case SECTION_NinLogo:
			mGameSection = new NinLogoSection();
			break;

		case SECTION_Titles:
			mGameSection = new TitlesSection();
			break;

		case SECTION_MovSample:
			mGameSection = new MovSampleSection();
			break;

		case SECTION_OnePlayer:
			mGameSection = new OnePlayerSection();
			break;

		case SECTION_PaniTest:
#if defined(VERSION_GPIP01_00)
			mGameSection = new GameCourseClearSection();
#else
			mGameSection = new PaniTestSection();
#endif
			break;

		case SECTION_OgTest:
			mGameSection = new zen::OgTestSection();
			break;
		}

		gsys->getHeap(gsys->getHeapNum())->setAllocType(AYU_STACK_GROW_UP);
	}

	gsys->resetHeap(SYSHEAP_App, AYU_STACK_GROW_UP);

	gsys->getHeap(SYSHEAP_App)->setAllocType(AYU_STACK_GROW_UP);
	app->useHeap(SYSHEAP_App);
	PRINT("*------------------------------------------- softReset %.2fk free\n", gsys->getHeap(SYSHEAP_App)->getFree() / 1024.0f);

	// initialise the flow manager
	mFlowManager->init("GameFlow");
	app->add(mFlowManager);

	mFrameCacher = nullptr;

	// set up light flares
	gsys->mFlareGroupList = new LFlareGroup();
	gsys->initLFlares(256);

	mMoviePlayer->resetMovieList();

	// timer for how long the loading took, to report for debugging
	f32 time            = gsys->getTime();
	gsys->mDvdOpenFiles = 0;
	gsys->mDvdBytesRead = 0;

	// load and intialise the new section!
	if (mNextGameSectionID != SECTION_OnePlayer && mNextGameSectionID != SECTION_Titles && mNextGameSectionID != SECTION_NinLogo) {
		// all other sections need loading
		PRINT("doing start load!\n");
		gsys->startLoading(nullptr, true, 60);
	}
	gsys->_250     = 0;
	mGameInterface = nullptr;
	gsys->getHeap(SYSHEAP_Message)->inactivate();
	mGameSection->init();

	if (mNextGameSectionID != SECTION_OnePlayer && mNextGameSectionID != SECTION_Titles) {
		PRINT("!!!!!!!!!!!!!!!!!!!!!!! END LOADING !!!!!!!!!!!!!!!!!!!!!!!!\n");
		gsys->endLoading();
	}

	f32 diff = gsys->getTime() - time;
	if (mAppTickCounter > 1 || diff / 1000.0f >= 0.02f) {
		mLoadTimeSeconds = diff / 1000.0f;
	}

	mEffectDurationTimer = 15.0f;
	mTargetEffectAlpha   = 255.0f;
	mAppTickCounter      = 0;

	// always print load time reporting
	gsys->mTogglePrint = TRUE;

#if defined(VERSION_GPIP01_00)
	int size  = (u32)gsys->getHeap(SYSHEAP_App)->getFree();
	int size2 = size - 0x1800000;
	if (size2 < 0) {
		size2 = 0;
	}
	PRINT("*--------------- %.2fk (%.2fk) free : %d files, %.1fk took %.1f secs : %.1f mb/sec\n", size / 1024.0f, size2 / 1024.0f,
	      gsys->mDvdOpenFiles, gsys->mDvdBytesRead / 1024.0f, mLoadTimeSeconds,
	      gsys->mDvdBytesRead / (1024.0f * 1024.0f) / mLoadTimeSeconds);
#else
	u32 size = (u32)gsys->getHeap(SYSHEAP_App)->getFree();
	PRINT("*--------------- %.2fk free : %d files, %.1fk took %.1f secs : %.1f mb/sec\n", size / 1024.0f, gsys->mDvdOpenFiles,
	      gsys->mDvdBytesRead / 1024.0f, mLoadTimeSeconds, gsys->mDvdBytesRead / (1024.0f * 1024.0f) / mLoadTimeSeconds);
#endif

	// restore the user's debug print setting
	gsys->mTogglePrint = togglePrint;
	mFlowManager->add(mGameSection);
	mPauseAll          = FALSE;
	mIsUIOverlayActive = FALSE;
	_348               = 0; // unused
	_34C               = 0; // unused
	mIsPauseAllowed    = TRUE;

	// all set, we can forget where we came from now
	mCurrGameSectionID = mNextGameSectionID;
}

/**
 * @brief Wrapper for loading a shape (model) from file.
 *
 * @param modelPath File path to model file to load.
 * @param checkCache Whether to check the cache for an existing instance first.
 * @return Pointer to newly loaded (or cached) model.
 */
Shape* GameFlow::loadShape(immut char* modelPath, bool checkCache)
{
	return gsys->loadShape(modelPath, checkCache);
}

/**
 * @brief Updates game flow state - in reality, just updates the controller rumble.
 */
void GameFlow::update()
{
	if (rumbleMgr) {
		rumbleMgr->update();
	}
}

/**
 * @brief Adds a generic node (list of something) to the flow manager.
 *
 * This *should* hook it up so it gets updated every frame by the game app,
 * but the wrapped node actually never gets interacted with lol.
 *
 * @param name Name of the GameGenNode to add.
 * @param node Generic node to add.
 */
void GameFlow::addGenNode(immut char* name, CoreNode* node)
{
	mFlowManager->add(new GameGenNode((name) ? name : node->mName, node));
}
