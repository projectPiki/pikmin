#include "BaseInf.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "FlowController.h"
#include "GameSetupSection.h"
#include "Generator.h"
#include "GlobalShape.h"
#include "KIO.h"
#include "Kontroller.h"
#include "MemStat.h"
#include "PlayerState.h"
#include "Shape.h"
#include "gameflow.h"
#include "sysNew.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameSetup");

static immut char* shapeList[10][2] = {
	{ "objects/pellets/white1.mod", "objects/pellets/white1.anm" },
	{ "objects/pellets/white2.mod", "objects/pellets/white2.anm" },
	{ "objects/pellets/white3.mod", "objects/pellets/white3.anm" },
	{ "objects/pellets/white4.mod", "objects/pellets/white4.anm" },
	{ "pikis/bluModel.mod", "pikis/bluModel.anm" },
	{ "pikis/redModel.mod", nullptr },
	{ "pikis/yelModel.mod", nullptr },
	{ "pikis/kinModel.mod", nullptr },
	{ "pikis/nv3Model.mod", nullptr },
	{ nullptr, nullptr },
};

static immut char* shapeList2[18][2] = {
	{ "objects/ufo/ufo0705.mod", "objects/ufo/ufo0705.anm" },
	{ "objects/ufoparts/soto1.mod", "objects/ufoparts/soto1.anm" },
	{ "objects/ufoparts/soto2.mod", "objects/ufoparts/soto2.anm" },
	{ "objects/ufoparts/soto3.mod", "objects/ufoparts/soto3.anm" },
	{ "objects/ufoparts/soto4.mod", "objects/ufoparts/soto4.anm" },
	{ "objects/ufoparts/soto5.mod", "objects/ufoparts/soto5.anm" },
	{ "objects/ufoparts/fuzoku1.mod", "objects/ufoparts/fuzoku1.anm" },
	{ "objects/ufoparts/fuzoku2.mod", "objects/ufoparts/fuzoku2.anm" },
	{ "objects/ufoparts/fuzoku3.mod", "objects/ufoparts/fuzoku3.anm" },
	{ "objects/ufoparts/fuzoku4.mod", "objects/ufoparts/fuzoku4.anm" },
	{ "objects/ufoparts/fuzoku5.mod", "objects/ufoparts/fuzoku5.anm" },
	{ "objects/ufoparts/fuzoku6.mod", "objects/ufoparts/fuzoku6.anm" },
	{ "objects/ufoparts/fuzoku7.mod", "objects/ufoparts/fuzoku7.anm" },
	{ "objects/ufoparts/fuzoku8.mod", "objects/ufoparts/fuzoku8.anm" },
	{ "objects/ufoparts/fuzoku9.mod", "objects/ufoparts/fuzoku9.anm" },
	{ "objects/ufoparts/fuzoku10.mod", "objects/ufoparts/fuzoku10.anm" },
	{ "objects/ufoparts/fuzoku11.mod", "objects/ufoparts/fuzoku11.anm" },
	{ nullptr, nullptr },
};

static immut char* arambundleList[][2] = {
	{ "archives/tekis.dir", "dataDir/archives/tekis.arc" },
	{ "archives/bosses.dir", "dataDir/archives/bosses.arc" },
	{ "archives/tekipara.dir", "dataDir/archives/tekipara.arc" },
	{ "archives/tekikey.dir", "dataDir/archives/tekikey.arc" },
	{ "archives/plants.dir", "dataDir/archives/plants.arc" },
	{ "archives/ufopartsbin.dir", "dataDir/archives/ufopartsbin.arc" },
	{ "archives/bridges.dir", "dataDir/archives/bridges.arc" },
	{ "archives/gates.dir", "dataDir/archives/gates.arc" },
	{ "archives/bomb.dir", "dataDir/archives/bomb.arc" },
	{ "archives/rope.dir", "dataDir/archives/rope.arc" },
	{ "archives/water.dir", "dataDir/archives/water.arc" },
	{ "archives/fl_water.dir", "dataDir/archives/fl_water.arc" },
	{ "archives/pelletsbin.dir", "dataDir/archives/pelletsbin.arc" },
	{ "archives/pikihead.dir", "dataDir/archives/pikihead.arc" },
	{ "archives/effshapes.dir", "dataDir/archives/effshapes.arc" },
	{ "archives/weeds.dir", "dataDir/archives/weeds.arc" },
#if defined(VERSION_G98E01_PIKIDEMO)
#else
	{ "archives/goal.dir", "dataDir/archives/goal.arc" },
#endif
	{ nullptr, nullptr },
};

/**
 * @todo: Documentation
 */
void GameSetupSection::preCacheShapes()
{
	// what on earth is this even doing.
	// this isn't in the DLL, so this is as close to a fake match as I can get.
	// still refuses to addi the _310 and _31C stuff, but w/e
	AramAllocator* list1 = &gsys->mBaseAramAllocator;
	AramAllocator* list2 = &gsys->mAramAllocator;
	gsys->initAramAllocator(list1, list2, gsys->mAramAllocator.mCurrentOffset, gsys->mAramAllocator.mCurrentOffset);
	gsys->initCurrentAllocator();

	gsys->mAramRoot.initCore("");
	gsys->mFileList = (DirEntry*)&gsys->mAramRoot;

	immut char** bundlePair;
	for (bundlePair = arambundleList[0]; bundlePair[0]; bundlePair += 2) {
		gsys->parseArchiveDirectory(bundlePair[0], bundlePair[1]);
	}

	BOOL print         = gsys->mTogglePrint;
	gsys->mTogglePrint = TRUE;
#if defined(VERSION_G98E01_PIKIDEMO)
	_Print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	_Print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	_Print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	AramAllocator* alloc = &gsys->mBaseAramAllocator;
	_Print("!!!!!!!!!!!!!!!!! %d bytes still in aramHeap\n", alloc->mBaseAddress + alloc->mSize - alloc->mCurrentOffset);
	_Print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	_Print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	_Print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	_Print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
#endif
	gsys->mTogglePrint = print;

	for (bundlePair = shapeList[0]; bundlePair[0]; bundlePair += 2) {
		Shape* shape = gameflow.loadShape(bundlePair[0], true);
		if (bundlePair[1]) {
			gsys->mCurrentShape = shape;
			gsys->loadBundle(bundlePair[1], false);
		}
	}

	for (bundlePair = shapeList2[0]; bundlePair[0]; bundlePair += 2) {
		Shape* shape = gameflow.loadShape(bundlePair[0], true);
		if (bundlePair[1]) {
			gsys->mCurrentShape = shape;
			gsys->loadBundle(bundlePair[1], false);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802A
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x73C8
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0x69A8
	  li        r3, 0
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  addi      r29, r31, 0x9D4
	  lwz       r6, 0x2DEC(r13)
	  addi      r5, r6, 0x31C
	  lwz       r4, 0x320(r6)
	  lwz       r7, 0x320(r6)
	  addi      r8, r6, 0x310
	  lwz       r6, 0x31C(r6)
	  lwz       r5, 0x8(r5)
	  add       r5, r6, r5
	  stw       r4, 0x0(r8)
	  sub       r4, r5, r7
	  stw       r4, 0x8(r8)
	  lwz       r4, 0x0(r8)
	  stw       r4, 0x4(r8)
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r5, 0x310
	  stw       r4, 0x328(r5)
	  lwz       r4, 0x2DEC(r13)
	  addi      r4, r4, 0x214
	  stw       r3, 0x10(r4)
	  stw       r3, 0xC(r4)
	  stw       r3, 0x8(r4)
	  stw       r0, 0x4(r4)
	  lwz       r3, 0x2DEC(r13)
	  addi      r0, r3, 0x214
	  stw       r0, 0x228(r3)
	  b         .loc_0xB0

	.loc_0x94:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r5, 0x4(r29)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x8

	.loc_0xB0:
	  lwz       r4, 0x0(r29)
	  cmplwi    r4, 0
	  bne+      .loc_0x94
	  lwz       r4, 0x2DEC(r13)
	  lis       r3, 0x803A
	  lwzu      r5, 0x1C(r4)
	  li        r0, 0x1
	  subi      r30, r3, 0x2848
	  stw       r0, 0x0(r4)
	  addi      r29, r31, 0x174
	  lwz       r3, 0x2DEC(r13)
	  stw       r5, 0x1C(r3)
	  b         .loc_0x118

	.loc_0xE4:
	  addi      r3, r30, 0
	  li        r5, 0x1
	  bl        -0x1F10
	  lwz       r0, 0x4(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x114
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0
	  stw       r3, 0x1FC(r4)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4(r29)
	  bl        -0x14E70

	.loc_0x114:
	  addi      r29, r29, 0x8

	.loc_0x118:
	  lwz       r4, 0x0(r29)
	  cmplwi    r4, 0
	  bne+      .loc_0xE4
	  lis       r3, 0x803A
	  addi      r30, r31, 0x5CC
	  subi      r31, r3, 0x2848
	  b         .loc_0x168

	.loc_0x134:
	  addi      r3, r31, 0
	  li        r5, 0x1
	  bl        -0x1F60
	  lwz       r0, 0x4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0
	  stw       r3, 0x1FC(r4)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4(r30)
	  bl        -0x14EC0

	.loc_0x164:
	  addi      r30, r30, 0x8

	.loc_0x168:
	  lwz       r4, 0x0(r30)
	  cmplwi    r4, 0
	  bne+      .loc_0x134
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/**
 * @todo: Documentation
 */
GameSetupSection::GameSetupSection()
{
	Node::init("<GameSetupSection>");
	AyuHeap* heap = gsys->getHeap(SYSHEAP_App);
	int allocType = heap->setAllocType(AYU_STACK_GROW_DOWN);

	memStat = new MemStat();

	memStat->start("setup");

	gameflow.mPlayState.Initialise();
	gameflow.mWorldClock.mCurrentDay = 1;
	flowCont._248                    = 0;
	flowCont._254                    = 0;
	flowCont._258                    = 0;
	flowCont._24C                    = 0;
	flowCont._250                    = 0;
	flowCont.readMapList("stages/stages.ini");
	flowCont._244 = 0;
	preCacheShapes();

	memStat->start("genCache");
	generatorCache = new GeneratorCache();
	generatorCache->initGame();
	memStat->end("genCache");

	memStat->start("playerInfo");
	playerState = new PlayerState();
	playerState->initGame();
	memStat->end("playerInfo");

	kio = new KIO();
	kio->initialise();
	int saveSize     = Kontroller::getSaveSize(3000);
	void* saveBuffer = new (0x20) u8[saveSize];
	controllerBuffer = new RamStream(saveBuffer, saveSize);

	GlobalShape::init();

	memStat->end("setup");
	heap->setAllocType(allocType);
	pikiInfMgr.clear();
	gameflow.mPlayState.Initialise();
}

/**
 * @todo: Documentation
 */
void GameSetupSection::update()
{
#if defined(VERSION_G98E01_PIKIDEMO)
	flowCont.mCurrentStage = 0;
	playerState->initGame();
	generatorCache->initGame();
	pikiInfMgr.initGame();

	StageInfo* stage = flowCont.mRootInfo.getChild();
	while (stage) {
		stage->mHasInitialised = 0;
		stage->mStageInf.initGame();
		stage = (StageInfo*)stage->mNext;
	}

	gameflow.mGamePrefs.mMemCardSaveIndex = 0;
	gameflow.mGamePrefs.mHasSaveGame      = 0;
	playerState->setChallengeMode();

	stage = flowCont.mRootInfo.getChild();
	while (stage) {
		if ((int)stage->mChalStageID == 1) {
			flowCont.mCurrentStage = stage;
			sprintf(flowCont.mStagePath1, "%s", stage->mFileName);
			sprintf(flowCont.mStagePath2, "%s", stage->mFileName);
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			break;
		}
		stage = (StageInfo*)stage->mNext;
	}
	gsys->softReset();
#else
	PRINT("reset!\n");
	gameflow.mNextOnePlayerSectionID = ONEPLAYER_CardSelect;
	gsys->softReset();
#endif
}
