#include "Creature.h"
#include "DebugLog.h"
#include "Demo.h"
#include "Interface.h"
#include "KMath.h"
#include "MoviePlayer.h"
#include "PlayerState.h"
#include "gameflow.h"
#include "sysNew.h"
#include "zen/ogTutorial.h"

DemoParms* demoParms;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(12)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("demoFlag")

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A4
 */
DemoParms::DemoParms()
{
	load("parms/", "demo.bin", true);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000120
 */
DemoParms::Parms::Parms()
    : mOnionBootTriggerRadius(this, 150.0f, 0.0f, 1000.0f, "p00", "コンテナ接近距離")
    , mSeedDemoTriggerRadius(this, 100.0f, 0.0f, 1000.0f, "p01", "芽ピキ接近距離")
    , mSeedDemoWaitTime(this, 6.0f, 0.0f, 500.0f, "p02", "芽ピキ抜かずタイムアウト")
    , _30(this, 30.0f, 0.0f, 500.0f, "p03", "ペレット草バトルタイムアウト")
    , mDemoTriggerRadius(this, 150.0f, 0.0f, 1000.0f, "p04", "エンジン接近距離")
{
}

/**
 * @todo: Documentation
 */
DemoFlags::DemoFlags()
{
	demoParms         = new DemoParms;
	mFlagCount        = 32;
	mFlagDataNum      = mFlagCount << 3;
	mCurrentDataIndex = 0;
	mStoredFlags      = new u8[mFlagCount];
	mFlagDataList     = new DemoFlag*[mFlagDataNum];

	int i = 0;
	for (i = 0; i < mFlagCount; i++) {
		mStoredFlags[i] = 0;
	}
	for (i = 0; i < mFlagDataNum; i++) {
		mFlagDataList[i] = 0;
	}
	mCurrentDemoIndex = DEMOFLAG_NULL;
	mWaitTimer        = 0.0f;

	registerDemoFlag(DEMOFLAG_DiscoverRedOnyon, "赤コンテナに初めて接近", 4, 0, 0); // "Approaching the red container for the first time"
	registerDemoFlag(DEMOFLAG_DiscoverYellowOnyon, "黄コンテナに初めて接近", 5, 0,
	                 0); // "Approaching the yellow container for the first time"
	registerDemoFlag(DEMOFLAG_DiscoverBlueOnyon, "青コンテナに初めて接近", 6, 0, 0); // "Approaching the blue container for the first time"
	registerDemoFlag(DEMOFLAG_ApproachSeed, "芽ピキに初めて接近", 7, 0, 0);        // "Approaching Mepiki for the first time" (pikmin seed)
	registerDemoFlag(DEMOFLAG_PluckRedPikmin, "赤ピキ抜いた", 9, 0, 0);            // "I pulled out the red piki"
	registerDemoFlag(DEMOFLAG_PluckYellowPikmin, "黄ピキ抜いた", 10, 0, 0);        // "I pulled out the yellow piki"
	registerDemoFlag(DEMOFLAG_PluckBluePikmin, "青ピキ抜いた", 11, 0, 0);          // "I pulled out the blue piki"
	registerDemoFlag(DEMOFLAG_NoPikminTimeout, "ピキ抜かずタイムアウト", 8, 0, 0); // "Timeout without piki"
	registerDemoFlag(DEMOFLAG_CameraInfo, "カメラ説明", 0, 0, 0);                  // "camera description"
	registerDemoFlag(DEMOFLAG_Unk9, "ペレット草バトルタイムアウト", 13, 0, 0);     // "pellet grass battle timeout"
	registerDemoFlag(DEMOFLAG_CollectFirstPellet, "最初のペレットイン", 14, 0, 0); // "first pellet in"
	registerDemoFlag(DEMOFLAG_FirstSluiceDown, "初めて水門を開けた", 0, 0, 0);     // "opened the floodgates for the first time"
	registerDemoFlag(DEMOFLAG_ApproachEngine, "初めてエンジンに接近", 16, 0, 0);   // "Approaching the engine for the first time"
	registerDemoFlag(DEMOFLAG_CollectEngine, "エンジンを吸い込み", 20, 0, 0);      // "suck the engine"
	registerDemoFlag(DEMOFLAG_StartBoxPush, "岩を押し始めた", 15, 0, 0);           // "started pushing the rock"
	registerDemoFlag(DEMOFLAG_FinishBoxPush, "岩を押し切った", -1, 0, 0);          // "pushed through the rock"
	registerDemoFlag(DEMOFLAG_OnyonMenuInfo, "コンテナ出し入れ説明", 44, 0, 1);    // "Explanation of container loading and unloading"
	registerDemoFlag(DEMOFLAG_PostExtinctionSeed, "ピキ全滅で１匹まく説明", 60, 0,
	                 1); // "Explanation of how to sow one piki when all of them are wiped out"
	registerDemoFlag(DEMOFLAG_GrabFirstBomb, "ボム持ち帰り", 68, 0, 0); // "Take home the bomb"
	registerDemoFlag(DEMOFLAG_FirstHurryUp, "First HurryUp", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_FirstBombExplode, "First Bomb Explode", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_PikminLimitTutorial, "Exceed 100 pikis Tutorial", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_PikminLimitForest, "Exceed 100 pikis Forest", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_PikminLimitCave, "Exceed 100 pikis Cave", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_PikminLimitYakushima, "Exceed 100 pikis Yakushima", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_PikminLimitLast, "Exceed 100 pikis Last", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_FirstNectar, "First Honey Dew", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_FirstBombDeath, "First Bomb Dead", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_CarryPathBlocked, "GURU GURU", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_OlimarLowHealth, "ORIMA DAMAGED", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_Pluck15thPikmin, "15 NUKI", 12, 0, 0);
	registerDemoFlag(DEMOFLAG_FirstNoon, "FIRST NOON", 12, 0, 0);

	for (int i = 0; i < MAX_UFO_PARTS; i++) {
		registerDemoFlag(i + DEMOFLAG_UfoPartDiscoveryOffset, "UFO PARTS", 12, i, 0);
	}

	// Set main engine discovery text as seen
	setFlagOnly(DEMOFLAG_UfoPartDiscoveryOffset + 4);
}

/**
 * @todo: Documentation
 */
void DemoFlags::initGame()
{
	for (int i = 0; i < mFlagCount; i++) {
		mStoredFlags[i] = 0;
	}

	mCurrentDemoIndex = DEMOFLAG_NULL;
	mWaitTimer        = 0.0f;

	// Set main engine discovery text as seen
	setFlagOnly(DEMOFLAG_UfoPartDiscoveryOffset + 4);
}

/**
 * @todo: Documentation
 */
void DemoFlags::initCourse()
{
	mCurrentDemoIndex = DEMOFLAG_NULL;
	mWaitTimer        = 0.0f;
}

/**
 * @todo: Documentation
 */
void DemoFlags::update()
{
	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	if (mCurrentDemoIndex == DEMOFLAG_NULL) {
		return;
	}

	if (isFlag(mCurrentDemoIndex)) {
		resetTimer();
		PRINT("リセットシマシタ！\n"); // "Reset!"
		return;
	}

	mWaitTimer -= gsys->getFrameTime();
	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	if (!(mWaitTimer <= 0.0f)) {
		return;
	}

	if (mCurrentDemoIndex == DEMOFLAG_FirstBombExplode) {
		gameflow.mGameInterface->message(MOVIECMD_TextDemo, zen::ogScrTutorialMgr::TUT_BombInfo);
		PRINT("*** BOMB TIME OUT * OG_BOMBINFO!\n");
		setFlagOnly(mCurrentDemoIndex);
	} else {
		setFlag(mCurrentDemoIndex, mTargetCreature);
	}
}

/**
 * @todo: Documentation
 */
void DemoFlags::saveCard(RandomAccessStream& data)
{
	for (int i = 0; i < mFlagCount; i++) {
		data.writeByte(mStoredFlags[i]);
	}
}

/**
 * @todo: Documentation
 */
void DemoFlags::loadCard(RandomAccessStream& data)
{
	for (int i = 0; i < mFlagCount; i++) {
		mStoredFlags[i] = data.readByte();
	}
}

/**
 * @todo: Documentation
 */
void DemoFlags::registerDemoFlag(int index, immut char* name, u16 movieIndex, u16 a2, bool a3)
{
	if (mCurrentDataIndex != index) {
		PRINT("<%s> curr=%d idx=%d\n", name, mCurrentDataIndex, index);
		ERROR("登録は順序よく!\n"); // "Registration is in order"
	}
	if (mCurrentDataIndex >= mFlagDataNum) {
		ERROR("超えた！"); // "Exceeded!"
	}

	DemoFlag* flag    = new DemoFlag;
	flag->mName       = name;
	flag->mMovieIndex = movieIndex;
	flag->_08         = a2;
	flag->mIndex      = index;
	flag->_0A         = a3;

	mFlagDataList[mCurrentDataIndex] = flag;
	mCurrentDataIndex++;
}

/**
 * @todo: Documentation
 */
bool DemoFlags::isFlag(int index)
{
	return (1 << index - (index >> 3) * 8 & mStoredFlags[index >> 3]) != false;
}

/**
 * @todo: Documentation
 */
void DemoFlags::resetFlag(int index)
{
	int id = index >> 3;
	mStoredFlags[id] &= ~(1 << index - (id * 8));
}

/**
 * @todo: Documentation
 */
void DemoFlags::setFlag(int index, Creature* obj)
{
	int id = index >> 3;
	if (isFlag(index)) {
		return;
	}

	PRINT("FLAG <%s> SET\n", getDemoFlag(index)->mName);
	mStoredFlags[id] |= 1 << index - id * 8;
	PRINT("MOVIE INDEX = %d\n", getDemoFlag(index)->mIndex);

	int test = 0;
	if (getDemoFlag(index)->_0A) {
		test = playerState->mPartsCollectedByDay[10]; // I dont think this is right but its optimized out from GCN anyway
	}

	if (getDemoFlag(index)->mMovieIndex == 0) {
		return;
	}

	STACK_PAD_VAR(3);

	if (index == DEMOFLAG_PluckRedPikmin) {
		Vector3f objPosition = obj->mSRT.t;
		f32 yRotation        = HALF_PI;
		Vector3f rotation(0.0f, yRotation, 0.0f);
		gameflow.mGameInterface->movie(getDemoFlag(index)->mMovieIndex, 0, obj, obj ? &obj->mSRT.t : nullptr, &rotation, CAF_AllVisibleMask,
		                               true);

	} else {
		if (obj && obj->mObjType != OBJTYPE_Goal) {
			Vector3f objPosition = obj->mSRT.t;
			Vector3f rotation(0.0f, getCameraSafeAngle(objPosition, 200.0f, 10.0f), 0.0f);
			gameflow.mGameInterface->movie(getDemoFlag(index)->mMovieIndex, 0, obj, obj ? &obj->mSRT.t : nullptr, &rotation,
			                               CAF_AllVisibleMask, true);
		} else {
			gameflow.mGameInterface->movie(getDemoFlag(index)->mMovieIndex, 0, obj, obj ? &obj->mSRT.t : nullptr,
			                               obj ? &obj->mSRT.r : nullptr, CAF_AllVisibleMask, true);
		}
	}

	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
void DemoFlags::setFlagOnly(int index)
{
	if (isFlag(index)) {
		return;
	}

	int id = index >> 3;
	mStoredFlags[id] |= 1 << index - id * 8;
}

/**
 * @todo: Documentation
 */
void DemoFlags::setTimer(f32 time, int index, Creature* target)
{
	mWaitTimer        = time;
	mCurrentDemoIndex = index;
	PRINT("TIMER SET (%f seconds) <%s>\n", mWaitTimer, getDemoFlag(index)->mName);
	mTargetCreature = target;
}

/**
 * @todo: Documentation
 */
void DemoFlags::resetTimer()
{
	mTargetCreature   = nullptr;
	mWaitTimer        = 0.0f;
	mCurrentDemoIndex = DEMOFLAG_NULL;
}

/**
 * @todo: Documentation
 */
DemoFlag* DemoFlags::getDemoFlag(int index)
{
	return mFlagDataList[index];
}
