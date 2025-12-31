#include "GameSetupSection.h"

#include "BaseInf.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "FlowController.h"
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

/// Size of controller input recording buffer.
#define CONTROLLER_INPUT_BUFFER_SIZE (12 * 3000)

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameSetup");

/**
 * @brief First set of model-animation file pairs to index in system lists - Pikmin and pellets.
 *
 * Pikmin models all share the same (blue Pikmin) animation set once loaded.
 * No idea what the pellets are used for.
 */
static immut char* shapeList[10][2] = {
	{ "objects/pellets/white1.mod", "objects/pellets/white1.anm" }, ///< white1 pellet?
	{ "objects/pellets/white2.mod", "objects/pellets/white2.anm" }, ///< white2 pellet?
	{ "objects/pellets/white3.mod", "objects/pellets/white3.anm" }, ///< white3 pellet?
	{ "objects/pellets/white4.mod", "objects/pellets/white4.anm" }, ///< white4 pellet?
	{ "pikis/bluModel.mod", "pikis/bluModel.anm" },                 ///< blue Pikmin model and animation.
	{ "pikis/redModel.mod", nullptr },                              ///< red Pikmin model (reuses blue animation).
	{ "pikis/yelModel.mod", nullptr },                              ///< yellow Pikmin model (reuses blue animation).
	{ "pikis/kinModel.mod", nullptr },                              ///< puffmin model (reuses blue animation).
	{ "pikis/nv3Model.mod", nullptr },                              ///< olimar model.
	{ nullptr, nullptr },
};

/**
 * @brief Second set of model-animation file pairs to index in system lists - ship parts with animations.
 *
 * These models and animations are used for attaching ship parts to the Dolphin when collected.
 * "Soto" models are "outside" - they affect the actual hull of the ship.
 * "Fuzoku" models are "close friends" - they make external changes to the ship.
 * "Naka" parts don't affect the ship's appearance/have attaching animations, so don't get loaded here.
 */
static immut char* shapeList2[18][2] = {
	{ "objects/ufo/ufo0705.mod", "objects/ufo/ufo0705.anm" },             ///< base Dolphin model and animation set.
	{ "objects/ufoparts/soto1.mod", "objects/ufoparts/soto1.anm" },       ///< Bowsprit ("outside 1").
	{ "objects/ufoparts/soto2.mod", "objects/ufoparts/soto2.anm" },       ///< Gluon Drive ("outside 2").
	{ "objects/ufoparts/soto3.mod", "objects/ufoparts/soto3.anm" },       ///< Anti-Dioxin Filter ("outside 3").
	{ "objects/ufoparts/soto4.mod", "objects/ufoparts/soto4.anm" },       ///< Eternal Fuel Dynamo ("outside 4").
	{ "objects/ufoparts/soto5.mod", "objects/ufoparts/soto5.anm" },       ///< Main Engine ("outside 5").
	{ "objects/ufoparts/fuzoku1.mod", "objects/ufoparts/fuzoku1.anm" },   ///< Whimsical Radar ("close friend 1").
	{ "objects/ufoparts/fuzoku2.mod", "objects/ufoparts/fuzoku2.anm" },   ///< Interstellar Radio ("close friend 2").
	{ "objects/ufoparts/fuzoku3.mod", "objects/ufoparts/fuzoku3.anm" },   ///< Guard Satellite ("close friend 3").
	{ "objects/ufoparts/fuzoku4.mod", "objects/ufoparts/fuzoku4.anm" },   ///< Chronos Reactor ("close friend 4").
	{ "objects/ufoparts/fuzoku5.mod", "objects/ufoparts/fuzoku5.anm" },   ///< Radiation Canopy ("close friend 5").
	{ "objects/ufoparts/fuzoku6.mod", "objects/ufoparts/fuzoku6.anm" },   ///< Geiger Counter ("close friend 6").
	{ "objects/ufoparts/fuzoku7.mod", "objects/ufoparts/fuzoku7.anm" },   ///< Sagittarius ("close friend 7").
	{ "objects/ufoparts/fuzoku8.mod", "objects/ufoparts/fuzoku8.anm" },   ///< Libra ("close friend 8").
	{ "objects/ufoparts/fuzoku9.mod", "objects/ufoparts/fuzoku9.anm" },   ///< Omega Stabilizer ("close friend 9").
	{ "objects/ufoparts/fuzoku10.mod", "objects/ufoparts/fuzoku10.anm" }, ///< Ionium Jet #1 ("close friend 10").
	{ "objects/ufoparts/fuzoku11.mod", "objects/ufoparts/fuzoku11.anm" }, ///< Ionium Jet #2 ("close friend 11").
	{ nullptr, nullptr },
};

/// Archive-Directory pairs for various object types, to load into the system file list.
static immut char* arambundleList[][2] = {
	{ "archives/tekis.dir", "dataDir/archives/tekis.arc" },
	{ "archives/bosses.dir", "dataDir/archives/bosses.arc" },
	{ "archives/tekipara.dir", "dataDir/archives/tekipara.arc" },
	{ "archives/tekikey.dir", "dataDir/archives/tekikey.arc" },
#if defined(VERSION_GPIP01_00)
#else
	{ "archives/plants.dir", "dataDir/archives/plants.arc" },
#endif
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
 * @brief Loads arc/dir file pairs and model/animation pairs to populate the system file lists.
 *
 * @warning NON-MATCHING! Functionally equivalent.
 */
void GameSetupSection::preCacheShapes()
{
	// this isn't in the DLL, so this is as close to a fake match as I can get.
	// still refuses to addi the _310 and _31C stuff, but w/e
	AramAllocator* list1 = &gsys->mBaseAramAllocator;
	AramAllocator* list2 = &gsys->mAramAllocator;
	gsys->initAramAllocator(list1, list2, gsys->mAramAllocator.mCurrentOffset, gsys->mAramAllocator.mCurrentOffset);
	gsys->initCurrentAllocator();

	gsys->mAramRoot.initCore("");
	gsys->mFileList = (DirEntry*)&gsys->mAramRoot;

	// load in all the arc/dir file pairs to cache in the file list.
	immut char** bundlePair;
	for (bundlePair = arambundleList[0]; bundlePair[0]; bundlePair += 2) {
		gsys->parseArchiveDirectory(bundlePair[0], bundlePair[1]);
	}

	// Colin: "lemme yell at you real quick"
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
	gsys->mTogglePrint = print; // "back to regularly scheduled programming"

	// load in pikmin models/anims (and some seemingly unused pellet ones)
	for (bundlePair = shapeList[0]; bundlePair[0]; bundlePair += 2) {
		Shape* shape = gameflow.loadShape(bundlePair[0], true);
		if (bundlePair[1]) {
			gsys->mCurrentShape = shape;
			gsys->loadBundle(bundlePair[1], false); // don't load as cache texture
		}
	}

	// load in model/anim pairs for ship (and ship parts that modify they ship)
	for (bundlePair = shapeList2[0]; bundlePair[0]; bundlePair += 2) {
		Shape* shape = gameflow.loadShape(bundlePair[0], true);
		if (bundlePair[1]) {
			gsys->mCurrentShape = shape;
			gsys->loadBundle(bundlePair[1], false); // don't load as cache texture
		}
	}
}

/**
 * @brief Constructs the single-player setup section to initialise before gameplay.
 */
GameSetupSection::GameSetupSection()
{
	Node::init("<GameSetupSection>");

	// set heap to grow down
	AyuHeap* heap = gsys->getHeap(SYSHEAP_App);
	int allocType = heap->setAllocType(AYU_STACK_GROW_DOWN);

	// set up memory monitor before anything else
	memStat = new MemStat();

	memStat->start("setup");

	// initialise basic game flow parameters
	gameflow.mPlayState.Initialise();
	gameflow.mWorldClock.mCurrentDay = 1;
	flowCont.mClearStatePikiCount    = 0; // basically unused
	flowCont._254                    = 0; // unused
	flowCont._258                    = 0; // unused
	flowCont.mNaviSeedCount          = 0; // basically unused
	flowCont._250                    = 0; // unused

	// load all stages
	flowCont.readMapList("stages/stages.ini");
	flowCont.mEndingType = ENDING_None;

	// cache info on some important arc/dir and model/anim pairs
	preCacheShapes();

	// set up the generator cache, to store generator info between days
	memStat->start("genCache");
	generatorCache = new GeneratorCache();
	generatorCache->initGame();
	memStat->end("genCache");

	// set up player info, to track player-induced changes
	memStat->start("playerInfo");
	playerState = new PlayerState();
	playerState->initGame();
	memStat->end("playerInfo");

	// set up input recording (!!)
	kio = new KIO();
	kio->initialise();
	int saveSize     = Kontroller::getSaveSize(CONTROLLER_INPUT_BUFFER_SIZE / 12);
	void* saveBuffer = new (0x20) u8[saveSize];
	controllerBuffer = new RamStream(saveBuffer, saveSize);

	// load pikmin head and whistle models
	GlobalShape::init();

	memStat->end("setup");
	heap->setAllocType(allocType);

	// remove any buffered pikmin information
	pikiInfMgr.clear();

	// initialise the play state (to then load/save from/to memory card)
	gameflow.mPlayState.Initialise();
}

/**
 * @brief Performs any frame-by-frame required setup of single-player game state, then transits to card select.
 *
 * Demo version uses this to force setup of Forest of Hope challenge mode stage, other versions just transit straight to card select.
 */
void GameSetupSection::update()
{
#if defined(VERSION_G98E01_PIKIDEMO)
	// the only thing the demo will load into is the Forest of Hope challenge mode

	STACK_PAD_VAR(1);
	flowCont.mCurrentStage = nullptr;
	playerState->initGame();
	generatorCache->initGame();
	pikiInfMgr.initGame();

	// reset all our story mode stages to be re-initialised
	StageInfo* stage = (StageInfo*)flowCont.mStageList.mChild;
	while (stage) {
		stage->mHasInitialised = FALSE;
		stage->mStageInf.initGame();
		stage = (StageInfo*)stage->mNext;
	}

	gameflow.mGamePrefs.mMemCardSaveIndex = 0;
	gameflow.mGamePrefs.mHasSaveGame      = false;

	// put us in challenge mode
	playerState->setChallengeMode();

	stage = (StageInfo*)flowCont.mStageList.mChild;
	while (stage) {
		if ((int)stage->mChalStageID == STAGE_ChalForest) {
			// if we have it, load into Forest of Hope challenge mode!
			flowCont.mCurrentStage = stage;
			sprintf(flowCont.mCurrStageFilePath, "%s", stage->mFileName);
			sprintf(flowCont.mDoorStageFilePath, "%s", stage->mFileName);
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			break;
		}
		stage = (StageInfo*)stage->mNext;
	}

	// force transit to new subsection
	gsys->softReset();
#else
	PRINT("reset!\n");
	// queue up card select as the next section (either for story mode or challenge mode, doesn't matter)
	gameflow.mNextOnePlayerSectionID = ONEPLAYER_CardSelect;

	// force transit to new subsection
	gsys->softReset();
#endif
}
