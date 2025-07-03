#include "Demo.h"
#include "sysNew.h"
#include "gameflow.h"
#include "Interface.h"
#include "MoviePlayer.h"
#include "PlayerState.h"
#include "KMath.h"
#include "Creature.h"
#include "DebugLog.h"

DemoParms* demoParms;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(12)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("demoFlag")

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
DemoParms::DemoParms()
{
	load("parms/", "demo.bin", true);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
DemoParms::Parms::Parms()
    : mOnionBootTriggerRadius(this, 150.0f, 0.0f, 1000.0f, "p00", "コンテナ接近距離")
    , mSeedDemoTriggerRadius(this, 100.0f, 0.0f, 1000.0f, "p01", "芽ピキ接近距離")
    , mSeedDemoWaitTime(this, 6.0f, 0.0f, 500.0f, "p02", "芽ピキ抜かずタイムアウト")
    , _30(this, 30.0f, 0.0f, 500.0f, "p03", "ペレット草バトルタイムアウト")
    , mDemoTriggerRadius(this, 150.0f, 0.0f, 1000.0f, "p04", "エンジン接近距離")
{
}

/*
 * --INFO--
 * Address:	80081C10
 * Size:	0005F4
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

/*
 * --INFO--
 * Address:	80082204
 * Size:	000058
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

/*
 * --INFO--
 * Address:	8008225C
 * Size:	000014
 */
void DemoFlags::initCourse()
{
	mCurrentDemoIndex = DEMOFLAG_NULL;
	mWaitTimer        = 0.0f;
}

/*
 * --INFO--
 * Address:	80082270
 * Size:	0000F8
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
		gameflow.mGameInterface->message(0, 20);
		PRINT("*** BOMB TIME OUT * OG_BOMBINFO!\n");
		setFlagOnly(mCurrentDemoIndex);
	} else {
		setFlag(mCurrentDemoIndex, mTargetCreature);
	}
}

/*
 * --INFO--
 * Address:	80082368
 * Size:	000070
 */
void DemoFlags::saveCard(RandomAccessStream& data)
{
	for (int i = 0; i < mFlagCount; i++) {
		data.writeByte(mStoredFlags[i]);
	}
}

/*
 * --INFO--
 * Address:	800823D8
 * Size:	000070
 */
void DemoFlags::loadCard(RandomAccessStream& data)
{
	for (int i = 0; i < mFlagCount; i++) {
		mStoredFlags[i] = data.readByte();
	}
}

/*
 * --INFO--
 * Address:	80082448
 * Size:	00007C
 */
void DemoFlags::registerDemoFlag(int index, char* name, u16 movieIndex, u16 a2, bool a3)
{
	if (mCurrentDataIndex != index) {
		PRINT("<%s> curr=%d idx=%d\n", name, mCurrentDataIndex, index);
		ERROR("登録は順序よく!\n"); // "Registration is in order"
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

/*
 * --INFO--
 * Address:	800824C4
 * Size:	000030
 */
bool DemoFlags::isFlag(int index)
{
	return (1 << index - (index >> 3) * 8 & mStoredFlags[index >> 3]) != false;
}

/*
 * --INFO--
 * Address:	800824F4
 * Size:	000028
 */
void DemoFlags::resetFlag(int index)
{
	int id = index >> 3;
	mStoredFlags[id] &= ~(1 << index - (id * 8));
}

/*
 * --INFO--
 * Address:	8008251C
 * Size:	000234
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

	if (index == 4) {
		Vector3f objPosition = obj->mPosition;
		f32 yRotation        = HALF_PI;
		Vector3f rotation(0.0f, yRotation, 0.0f);
		gameflow.mGameInterface->movie(getDemoFlag(index)->mMovieIndex, 0, obj, obj ? &obj->mPosition : nullptr, &rotation, -1, true);
	} else {
		if (obj && obj->mObjType != OBJTYPE_Goal) {
			Vector3f objPosition = obj->mPosition;
			Vector3f rotation(0.0f, getCameraSafeAngle(objPosition, 200.0f, 10.0f), 0.0f);
			gameflow.mGameInterface->movie(getDemoFlag(index)->mMovieIndex, 0, obj, obj ? &obj->mPosition : nullptr, &rotation, -1, true);
		} else {
			gameflow.mGameInterface->movie(getDemoFlag(index)->mMovieIndex, 0, obj, obj ? &obj->mPosition : nullptr,
			                               obj ? &obj->mRotation : nullptr, -1, true);
		}
	}

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	80082750
 * Size:	000030
 */
void DemoFlags::setFlagOnly(int index)
{
	if (isFlag(index)) {
		return;
	}

	int id = index >> 3;
	mStoredFlags[id] |= 1 << index - id * 8;
}

/*
 * --INFO--
 * Address:	80082780
 * Size:	000048
 */
void DemoFlags::setTimer(f32 time, int index, Creature* target)
{
	mWaitTimer        = time;
	mCurrentDemoIndex = index;
	PRINT("TIMER SET (%f seconds) <%s>\n", mWaitTimer, getDemoFlag(index)->mName);
	mTargetCreature = target;
}

/*
 * --INFO--
 * Address:	800827C8
 * Size:	00001C
 */
void DemoFlags::resetTimer()
{
	mTargetCreature   = nullptr;
	mWaitTimer        = 0.0f;
	mCurrentDemoIndex = DEMOFLAG_NULL;
}

/*
 * --INFO--
 * Address:	800827E4
 * Size:	000010
 */
DemoFlag* DemoFlags::getDemoFlag(int index)
{
	return mFlagDataList[index];
}
