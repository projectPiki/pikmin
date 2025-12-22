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

GameFlow gameflow;
BaseApp* app;
static f32 llspin;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameFlow");

static const char* timopts[] = { " [off]", "  [on]", "[full]" };

/**
 * @TODO: Documentation
 */
void GameLoadIdler::draw(Graphics& gfx)
{
	gfx.mAmbientFogColour.set(48, 48, 48, 255);
	gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setClearColour(Colour(0, 0, 0, 0));
	gfx.clearBuffer(3, false);

	if (!gameflow.mLevelBannerTexture) {
		return;
	}

	gameflow.mLevelBannerFadeValue += (1.0f / 300.0f);
	if (gameflow.mLevelBannerFadeValue > 1.0f) {
		gameflow.mLevelBannerFadeValue = 1.0f;
	}

	gameflow.drawLoadLogo(gfx, true, gameflow.mLevelBannerTexture, gameflow.mLevelBannerFadeValue);
}

/**
 * @TODO: Documentation
 */
void GameFlow::drawLoadLogo(Graphics& gfx, bool p2, Texture* p3, f32 p4)
{
	if (!p3) {
		return;
	}

	Matrix4f mtx;
	llspin += (p2) ? 1.0f / 60.0f : gsys->getFrameTime();
	gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	if (mRedLoadLogo) {
		gfx.setColour(Colour(220, 0, 0, p4 * 255.0f), true);
		gfx.setAuxColour(Colour(220, 0, 0, p4 * 255.0f));
	} else {
		gfx.setColour(Colour(192, 64, 0, p4 * 255.0f), true);
		gfx.setAuxColour(Colour(255, 192, 0, p4 * 255.0f));
	}

	gfx.useTexture(p3, GX_TEXMAP0);
	int width  = gfx.mScreenWidth / 2 - p3->mWidth / 2;
	int height = gfx.mScreenHeight / 2 - p3->mHeight / 2;
	if (mRedLoadLogo) {
		height -= 40;
	}

	gfx.drawRectangle(RectArea(width, height, width + p3->mWidth, height + p3->mHeight), RectArea(0, 0, p3->mWidth, p3->mHeight), nullptr);

	STACK_PAD_VAR(1);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
void WorldClock::setClockSpd(f32 speed)
{
	mTicksPerHour = speed * 60.0f;
	mTimeScale    = mTicksPerHour / mHoursInDay;
}

/**
 * @TODO: Documentation
 */
void WorldClock::setTime(f32 time)
{
	mCurrentTime      = time;
	mFractionalTime   = mTimeScale * (time - f32(int(time)));
	mMinutes          = (60.0f / mTimeScale) * mFractionalTime;
	mTimeOfDay        = f32(mCurrentTime) + (mFractionalTime / mTimeScale);
	mLastRecordedTime = mTimeOfDay;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void WorldClock::reset(f32 speed)
{
	mFractionalTime   = 0.0f;
	mLastRecordedTime = 0.0f;
	mCurrentDay       = 0;
	mCurrentTime      = 0;
	mMinutes          = 0;
	mHoursInDay       = 24.0f;
	setClockSpd(speed);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
f32 WorldClock::age(f32 p1)
{
	f32 hours = f32(mCurrentDay) * mHoursInDay + f32(mCurrentTime);
	return (hours * mTimeScale + mFractionalTime) / mTicksPerHour - p1;
}

/**
 * @TODO: Documentation
 */
void WorldClock::update(f32 timeStep)
{
	mFractionalTime += gsys->getFrameTime() * timeStep;
	if (mFractionalTime >= mTimeScale) {
		mFractionalTime -= mTimeScale;
		mCurrentTime++;
		if (mCurrentTime >= 24) {
			mCurrentTime -= 24;
			mCurrentDay++;
		}
	}

	mMinutes   = int(60.0f / mTimeScale * mFractionalTime);
	mTimeOfDay = mCurrentTime + mFractionalTime / mTimeScale;
	_1C        = mTimeOfDay - mLastRecordedTime;
	if (_1C < 0.0f) {
		_1C += 24.0f;
	}

	mLastRecordedTime = mTimeOfDay;
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuToggleTimers(Menu& menu)
{
	gsys->mTimerState = (gsys->mTimerState + 1) % 3;
	gsys->mTimer->reset();
	sprintf(menu.mCurrentItem->mName, "Toggle Timers %s", timopts[gsys->mTimerState]);
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuTogglePrint(Menu& menu)
{
	gsys->mTogglePrint ^= TRUE;
	sprintf(menu.mCurrentItem->mName, "Toggle Print %s", (gsys->mTogglePrint) ? " [on]" : "[off]");
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuToggleDInfo(Menu& menu)
{
	gsys->mToggleDebugInfo ^= 1;
	sprintf(menu.mCurrentItem->mName, "Toggle DInfo %s", (gsys->mToggleDebugInfo) ? " [on]" : "[off]");
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuToggleDExtra(Menu& menu)
{
	gsys->mToggleDebugExtra ^= 1;
	sprintf(menu.mCurrentItem->mName, "Toggle DExtra %s", (gsys->mToggleDebugExtra) ? " [on]" : "[off]");
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuToggleBlur(Menu& menu)
{
	gsys->mToggleBlur ^= true;
	sprintf(menu.mCurrentItem->mName, "Toggle Blur %s", (gsys->mToggleBlur) ? " [on]" : "[off]");
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuToggleInfo(Menu& menu)
{
	gsys->mToggleFileInfo ^= 1;
	sprintf(menu.mCurrentItem->mName, "Toggle FileInfo %s", (gsys->mToggleFileInfo) ? " [on]" : "[off]");
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuToggleColls(Menu& menu)
{
	gsys->mToggleColls ^= 1;
	sprintf(menu.mCurrentItem->mName, "Toggle Colls %s", (gsys->mToggleColls) ? " [on]" : "[off]");
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0004DC
 */
void GameFlow::addOptionsMenu(Menu* parent)
{
	char* timerBuf = new char[0x40];
	sprintf(timerBuf, "Toggle Timers %s", timopts[gsys->mTimerState]);
	parent->addOption(0, timerBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleTimers), true);

	char* printBuf = new char[0x40];
	sprintf(printBuf, "Toggle Print %s", (gsys->mTogglePrint) ? " [on]" : "[off]");
	parent->addOption(0, printBuf, new Delegate1<GameFlow, Menu&>(this, &menuTogglePrint), true);

	char* debugInfoBuf = new char[0x40];
	sprintf(debugInfoBuf, "Toggle DInfo %s", (gsys->mToggleDebugInfo) ? " [on]" : "[off]");
	parent->addOption(0, debugInfoBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleDInfo), true);

	char* debugExtraBuf = new char[0x40];
	sprintf(debugExtraBuf, "Toggle DExtra %s", (gsys->mToggleDebugExtra) ? " [on]" : "[off]");
	parent->addOption(0, debugExtraBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleDExtra), true);

	char* blurBuf = new char[0x40];
	sprintf(blurBuf, "Toggle Blur %s", (gsys->mToggleBlur) ? " [on]" : "[off]");
	parent->addOption(0, blurBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleBlur), true);

	char* fileInfoBuf = new char[0x40];
	sprintf(fileInfoBuf, "Toggle FileInfo %s", (gsys->mToggleFileInfo) ? " [on]" : "[off]");
	parent->addOption(0, fileInfoBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleInfo), true);

	char* collsBuf = new char[0x40];
	sprintf(collsBuf, "Toggle Colls %s", (gsys->mToggleColls) ? " [on]" : "[off]");
	parent->addOption(0, collsBuf, new Delegate1<GameFlow, Menu&>(this, &menuToggleColls), true);
}

static const char* filterNames[] = {
	"custom",
	"DF off",
};

/**
 * @TODO: Documentation
 */
void GameFlow::menuChangeFilter(Menu& menu)
{
	mFilterType ^= 1;
	sprintf(menu.mCurrentItem->mName, "type = %s", filterNames[mFilterType]);
	gsys->mDGXGfx->setVerticalFilter(&mFilters[mFilterType * 8]);
	gsys->mDGXGfx->videoReset();
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuIncreaseFilter(Menu& menu)
{
	if (mFilters[menu.mCurrentItem->mFilterIndex] < 128) {
		mFilters[menu.mCurrentItem->mFilterIndex]++;
	}

	sprintf(menu.mCurrentItem->mName, "Filter setting %d", mFilters[menu.mCurrentItem->mFilterIndex]);
	if (mFilterType == FILTER_Custom) {
		gsys->mDGXGfx->setVerticalFilter(mFilters);
		gsys->mDGXGfx->videoReset();
	}
}

/**
 * @TODO: Documentation
 */
void GameFlow::menuDecreaseFilter(Menu& menu)
{
	if (mFilters[menu.mCurrentItem->mFilterIndex] != 0) {
		mFilters[menu.mCurrentItem->mFilterIndex]--;
	}

	sprintf(menu.mCurrentItem->mName, "Filter setting %d", mFilters[menu.mCurrentItem->mFilterIndex]);
	if (mFilterType == FILTER_Custom) {
		gsys->mDGXGfx->setVerticalFilter(mFilters);
		gsys->mDGXGfx->videoReset();
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000214
 */
void GameFlow::addFilterMenu(Menu* parent)
{
	char* changeBuf = new char[0x40];
	sprintf(changeBuf, "type = %s", filterNames[mFilterType]);
	parent->addOption(0, changeBuf, new Delegate1<GameFlow, Menu&>(this, &menuChangeFilter), true);
	parent->addOption(0, nullptr, nullptr, true);
	for (int i = 0; i < 7; i++) {
		char* buf = new char[0x40];
		sprintf(buf, "Filter setting %d", mFilters[i]);
		parent->addOption(i, buf, nullptr, true);
		parent->addKeyEvent(Menu::KeyEventType::Release, KBBTN_Y, new Delegate1<GameFlow, Menu&>(this, &menuDecreaseFilter));
		parent->addKeyEvent(Menu::KeyEventType::Release, KBBTN_X, new Delegate1<GameFlow, Menu&>(this, &menuIncreaseFilter));
	}
}

/**
 * @TODO: Documentation
 */
void GameFlow::read(RandomAccessStream& input)
{
	mParameters->read(input);
}

/**
 * @TODO: Documentation
 */
void preloadLanguage()
{
	int unused; // for r30
	int heapIdx;
	int lang;

	gsys->mCacher->purgeAll();
	heapIdx = gsys->getHeapNum();
	gsys->setHeap(SYSHEAP_Lang);
	gsys->resetHeap(SYSHEAP_Lang, 2);
	gsys->getHeap(gsys->getHeapNum())->getFree();
	gsys->mAramAllocator.init();
	gsys->mDvdRoot.initCore("");
	gsys->mFileList         = (DirEntry*)&gsys->mDvdRoot;
	gsys->mCurrentAllocator = &gsys->mAramAllocator;
	gsys->parseArchiveDirectory(gameflow.mLangModes[gameflow.mLanguageIndex].mDirPath,
	                            gameflow.mLangModes[gameflow.mLanguageIndex].mArcPath);
	gsys->loadBundle(gameflow.mLangModes[gameflow.mLanguageIndex].mBunPath, true);
	gsys->set2DRoot(gameflow.mLangModes[gameflow.mLanguageIndex].mBloPath, gameflow.mLangModes[gameflow.mLanguageIndex].mTexPath);
	gsys->getHeap(gsys->getHeapNum())->getFree();
	gsys->setHeap(heapIdx);

	!(unused++);

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  subi      r31, r4, 0x2848
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r3, 0x38(r3)
	  bl        -0x11AF0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x7
	  lwz       r28, 0x194(r3)
	  bl        -0x12E7C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x7
	  li        r5, 0x2
	  bl        -0x12EC0
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x12EE0
	  lwz       r5, 0x2DEC(r13)
	  li        r4, 0
	  subi      r0, r13, 0x7570
	  addi      r7, r5, 0x31C
	  lwz       r3, 0x0(r7)
	  addi      r29, r31, 0x2A8
	  stw       r3, 0x4(r7)
	  lwz       r3, 0x2DEC(r13)
	  addi      r3, r3, 0x200
	  stw       r4, 0x10(r3)
	  stw       r4, 0xC(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x2DEC(r13)
	  addi      r0, r3, 0x200
	  stw       r0, 0x228(r3)
	  lwz       r3, 0x2DEC(r13)
	  addi      r0, r3, 0x31C
	  stw       r0, 0x328(r3)
	  lwz       r0, 0x2A8(r31)
	  lwz       r3, 0x2DEC(r13)
	  mulli     r0, r0, 0x14
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x24(r12)
	  add       r5, r31, r0
	  lwz       r4, 0x208(r5)
	  mtlr      r12
	  lwz       r5, 0x20C(r5)
	  blrl
	  lwz       r0, 0x0(r29)
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  mulli     r0, r0, 0x14
	  add       r4, r31, r0
	  lwz       r4, 0x210(r4)
	  bl        -0x121BC
	  lwz       r0, 0x0(r29)
	  lwz       r5, 0x2DEC(r13)
	  mulli     r0, r0, 0x14
	  add       r3, r31, r0
	  lwz       r4, 0x218(r3)
	  lwz       r0, 0x214(r3)
	  stw       r0, 0x44(r5)
	  stw       r4, 0x48(r5)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x194(r3)
	  bl        -0x12F9C
	  mr        r4, r28
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x12F60
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/**
 * @TODO: Documentation
 */
Texture* GameFlow::setLoadBanner(immut char* texPath)
{
	int heapIdx = gsys->mActiveHeapIdx;
	gsys->resetHeap(SYSHEAP_Load, 2);
	gsys->setHeap(SYSHEAP_Load);
	gameflow.mLoadBannerTexture = gsys->loadTexture(texPath, true);
	if (gameflow.mLoadBannerTexture) {
		gameflow.mLoadBannerTexture->attach();
	}

	gsys->setHeap(heapIdx);
	return gameflow.mLoadBannerTexture;
}

/**
 * @TODO: Documentation
 */
void GameFlow::hardReset(BaseApp* baseApp)
{
	app  = baseApp;
	_1D4 = 0;
	PRINT("Doing HardReset!!\n");
	mFilterType             = FILTER_Custom;
	_35C                    = 0;
	_35D                    = 0;
	_35E                    = 21;
	_35F                    = 22;
	_360                    = 21;
	_361                    = 0;
	_362                    = 0;
	mNextSectionID          = -1;
	mGameSectionID          = SECTION_NinLogo;
	mNextOnePlayerSectionID = ONEPLAYER_GameSetup;
	_200                    = 0;
	mIntroMovieIdCycle      = 0;
	mLanguageIndex          = 0;

	mLangModes[0].set("archives/blo_eng.dir", "dataDir/archives/blo_eng.arc", "screen/eng_tex/screen.bun", "screen/eng_blo/",
	                  "screen/eng_tex/");
	mLangModes[1].set("archives/blo_eng.dir", "dataDir/archives/blo_eng.arc", "screen/eng_tex/screen.bun", "screen/eng_blo/",
	                  "screen/eng_tex/");

	gsys->set2DRoot("screen/sys_blo/", "screen/otona_tex/");

	mParameters = new Parms();
	int size    = 0x8000;
	mWorldClock.reset(mParameters->mDaySpeedFactor());
	mTimeMultiplier  = 1.0f;
	mUpdateTickCount = 0;

	mMemoryCard.init();

	PRINT("load heap\n");
	gsys->mHeaps[SYSHEAP_Load].init("load", AYU_STACK_GROW_UP, new u8[size], size);
	mLoadBannerTexture    = nullptr;
	mLevelBannerTexture   = setLoadBanner("intro/nintendo.bti");
	mLevelBannerFadeValue = 1.0f;
	Jac_SceneSetup(0, 0);
	mRedLoadLogo = TRUE;

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
	mDemoFlags = 0;

	mMoviePlayer = new MoviePlayer();
	rumbleMgr    = new RumbleMgr(true, false, false, false);
	rumbleMgr->reset();
	rumbleMgr->rumbleOption(true);

	mGamePrefs.Initialise();

	mGenFlow = new GameGenFlow();

	gsys->loadBundle("effects/pcr/effects.bun", false);
	gsys->loadBundle("effects/tex/effects.bun", false);
}

/**
 * @TODO: Documentation
 */
void GameFlow::softReset()
{
	BOOL togglePrint   = gsys->mTogglePrint;
	gsys->mTogglePrint = FALSE;

	if (mGameSectionID != mNextSectionID) {
		gsys->resetHeap(1, 2);
		gsys->getHeap(SYSHEAP_Ovl)->setAllocType(AYU_STACK_GROW_UP);
		app->useHeap(1);
		PRINT("*------------------------------------------- section change\n");
		AyuHeap* heap = gsys->getHeap(SYSHEAP_Ovl);
		int max       = heap->getMaxFree();
		int type      = heap->setAllocType(AYU_STACK_GROW_UP);
		u8* buf       = new u8[heap->getMaxFree()];
		heap->setAllocType(type);
		gsys->mHeaps[SYSHEAP_App].init("app", AYU_STACK_GROW_UP, buf, max);
		app->useHeap(2);
		gsys->getHeap(gsys->getHeapNum())->setAllocType(AYU_STACK_GROW_DOWN);

		switch (mGameSectionID) {
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

	gsys->resetHeap(2, 2);

	gsys->getHeap(SYSHEAP_App)->setAllocType(AYU_STACK_GROW_UP);
	app->useHeap(2);
	PRINT("*------------------------------------------- softReset %.2fk free\n", gsys->getHeap(SYSHEAP_App)->getFree() / 1024.0f);
	mGenFlow->init("GameFlow");
	app->add(mGenFlow);
	mFrameCacher          = nullptr;
	gsys->mFlareGroupList = new LFlareGroup();
	gsys->initLFlares(256);
	mMoviePlayer->resetMovieList();
	f32 time            = gsys->getTime();
	gsys->mDvdOpenFiles = 0;
	gsys->mDvdBytesRead = 0;

	if (mGameSectionID != SECTION_OnePlayer && mGameSectionID != SECTION_Titles && mGameSectionID != SECTION_NinLogo) {
		PRINT("doing start load!\n");
		gsys->startLoading(nullptr, true, 60);
	}
	gsys->_250     = 0;
	mGameInterface = nullptr;
	gsys->getHeap(SYSHEAP_Message)->inactivate();
	mGameSection->init();

	if (mGameSectionID != SECTION_OnePlayer && mGameSectionID != SECTION_Titles) {
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
	gsys->mTogglePrint   = TRUE;
	PRINT("*--------------- %.2fk free : %d files, %.1fk took %.1f secs : %.1f mb/sec\n",
	      (u32)gsys->getHeap(SYSHEAP_App)->getFree() / 1024.0f, gsys->mDvdOpenFiles, gsys->mDvdBytesRead / 1024.0f, mLoadTimeSeconds,
	      gsys->mDvdBytesRead / (1024.0f * 1024.0f) / mLoadTimeSeconds);
	gsys->mTogglePrint = togglePrint;
	mGenFlow->add(mGameSection);
	_33C                    = FALSE;
	mIsUiOverlayActive      = FALSE;
	_348                    = 0;
	_34C                    = 0;
	mIsGameplayInputEnabled = TRUE;
	mNextSectionID          = mGameSectionID;

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 */
Shape* GameFlow::loadShape(immut char* filename, bool p2)
{
	return gsys->loadShape(filename, p2);
}

/**
 * @TODO: Documentation
 */
void GameFlow::update()
{
	if (rumbleMgr) {
		rumbleMgr->update();
	}
}

/**
 * @TODO: Documentation
 */
void GameFlow::addGenNode(immut char* name, CoreNode* node)
{
	mGenFlow->add(new GameGenNode((name) ? name : node->mName, node));
}
