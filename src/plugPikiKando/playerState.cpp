#include "PlayerState.h"
#include "AIConstant.h"
#include "AIPerf.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "GameStat.h"
#include "Generator.h"
#include "Graphics.h"
#include "Interface.h"
#include "MoviePlayer.h"
#include "NaviMgr.h"
#include "OnePlayerSection.h"
#include "Pellet.h"
#include "Piki.h"
#include "Shape.h"
#include "UfoItem.h"
#include "UtEffect.h"
#include "gameflow.h"
#include "sysNew.h"

int PlayerState::totalUfoParts = MAX_UFO_PARTS;

bool preloadUFO = false;
PlayerState* playerState;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(20)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("PlayerState")

UfoPartsInfo partsInfo[5] = {
	{ UFOID_Bowsprit, true },          { UFOID_GluonDrive, true }, { UFOID_AntiDioxinFilter, true },
	{ UFOID_EternalFuelDynamo, true }, { UFOID_MainEngine, true },
};

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
TimeGraph::TimeGraph()
{
	mEntries   = nullptr;
	mEndTime   = 0;
	mStartTime = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
void TimeGraph::create(u16 startTime, u16 endTime)
{
	int entryCount = endTime - startTime + 1;
	mStartTime     = startTime;
	mEndTime       = endTime;
	mEntries       = new PikiNum[entryCount];
	init();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void TimeGraph::init()
{
	for (int i = 0; i < mEndTime - mStartTime + 1; i++) {
		mEntries[i].set(-1, -1); // set all counts to -1
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
void TimeGraph::set(u16 time, int color, int num)
{
	int entryIdx = time - mStartTime;
	if (entryIdx < 0 || entryIdx >= (mEndTime - mStartTime + 1)) {
		ERROR("illegal time int %d\n", time);
	}
	mEntries[entryIdx].set(color, num);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
int TimeGraph::get(u16 time, int color)
{
	if (time - mStartTime < 0 || time - mStartTime >= (mEndTime - mStartTime + 1)) {
		ERROR("illegal time int %d\n", time);
	}
	return mEntries[time - mStartTime].get(color);
}

/**
 * @todo: Documentation
 */

bool PlayerState::isEnding()
{
	if (getCurrDay() >= (MAX_DAYS - 1)) {
		// we've hit our 30-day limit
		return true;

	} else if (getCurrParts() >= MAX_UFO_PARTS) {
		// we've collected every part
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool PlayerState::existUfoParts(u32 id)
{
	if (hasUfoParts(id)) {
		return true;
	}

	if (generatorCache && generatorCache->hasUfoParts(flowCont.mCurrentStage->mStageID, id)) {
		return true;
	}

	if (pelletMgr) {
		Iterator it(pelletMgr);
		CI_LOOP(it)
		{
			Pellet* obj = (Pellet*)*it;
			if (obj->isAlive() && obj->mConfig->mModelId.mId == id) {
				return true;
			}
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
void PlayerState::initGame()
{
	int i;
	for (i = 0; i < MAX_DAYS; i++) {
		mPartsCollectedByDay[i] = 0;
		mPartsToNextByDay[i]    = 0;
	}
	mResultFlags.initGame();
	mDemoFlags.initGame();
	mIsChallengeMode       = false;
	mLeftBehindPikis       = 0;
	mLostBattlePikis       = 0;
	mSproutedNum           = 0;
	mTotalPluckedPikiCount = 0;
	mTotalDeadPikiNum      = 0;
	mTotalBornPikiNum      = 0;
	mDisplayPikiFlag       = 0;
	mShipEffectPartFlag    = 8;
	mTotalRegisteredParts  = 0;
	mTotalParts            = totalUfoParts;
	mRequiredUfoPartCount  = 0;
	mCurrParts             = 0;
	mCurrentRepairingPart  = nullptr;
	mContainerFlag         = 0;
	setContainer(Red);
	setDisplayPikiCount(Red);
	mTotalRegisteredParts = 0;

	for (i = 0; i < mTotalParts; i++) {
		mUfoParts[i].mPartVisType = PARTVIS_Uncollected;
	}

	mIsTutorialMode = true;
	for (i = 0; i < STAGE_COUNT; i++) {
		mStagePartsCollected[i] = 0;
	}

	StageInfo* node = (StageInfo*)flowCont.mStageList.mChild;
	for (i = 0; i < STAGE_COUNT; i++) {
		if (node->mGenFileList.getChildCount() > 0) {
			mCourseFlags[i]->reset();
		}
		node = (StageInfo*)node->mNext;
	}

	mShipUpgradeLevel = 0;
}

/**
 * @todo: Documentation
 */
PlayerState::PlayerState()
{
	int i;
	for (i = 0; i < MAX_DAYS; i++) {
		mPartsCollectedByDay[i] = 0;
		mPartsToNextByDay[i]    = 0;
	}

	mIsChallengeMode       = false;
	mLeftBehindPikis       = 0;
	mLostBattlePikis       = 0;
	mSproutedNum           = 0;
	mTotalPluckedPikiCount = 0;
	mTotalDeadPikiNum      = 0;
	mTotalBornPikiNum      = 0;
	mDisplayPikiFlag       = 0;
	mShipEffectPartFlag    = 8;
	mTotalRegisteredParts  = 0;
	mTotalParts            = totalUfoParts;

	mUfoParts             = new UfoParts[mTotalParts];
	mRequiredUfoPartCount = 0;
	mCurrParts            = 0;
	mCurrentRepairingPart = nullptr;
	mContainerFlag        = 0;
	setContainer(Red);
	setDisplayPikiCount(Red);
	mTotalRegisteredParts = 0;

	for (i = 0; i < mTotalParts; i++) {
		mUfoParts[i].mPartVisType = PARTVIS_Uncollected;
	}
	mPerHourGraph.create(getStartHour(), getEndHour());
	mPerDayGraph.create(0, getTotalDays());
	mIsTutorialMode = true;
	for (i = 0; i < STAGE_COUNT; i++) {
		mStagePartsCollected[i] = 0;
	}
	mCourseFlags = new BitFlags*[STAGE_COUNT];

	StageInfo* node = (StageInfo*)flowCont.mStageList.mChild;
	for (i = 0; i < STAGE_COUNT; i++) {
		int size = node->mGenFileList.getChildCount();
		if (size > 0) {
			mCourseFlags[i] = new BitFlags;
			mCourseFlags[i]->create(size, nullptr);
			mCourseFlags[i]->reset();
		}
		node = (StageInfo*)node->mNext;
	}

	mShipUpgradeLevel = 0;
}

/**
 * @todo: Documentation
 */
bool PlayerState::courseOpen(int courseID)
{
	if (courseID >= STAGE_START && courseID <= STAGE_TESTMAP) {
		return IS_STAGE_OPEN(gameflow.mPlayState.mCourseOpenFlags, courseID) != 0;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool PlayerState::happyEndable()
{
	return mRequiredUfoPartCount >= MIN_HAPPY_END_PARTS;
}

/**
 * @todo: Documentation
 */
void PlayerState::setChallengeMode()
{
	mIsChallengeMode = true;

	// set EVERY demo flag. no cutscenes!!
	for (int i = 0; i < DEMOFLAG_COUNT; i++) {
		mDemoFlags.setFlagOnly(i);
	}

	mIsTutorialMode     = false;
	mContainerFlag      = 0xFF; // ALL flags set.
	_186                = 0;
	mDisplayPikiFlag    = 0xFF; // ALL flags set.
	mShipEffectPartFlag = 1;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void PlayerState::setDebugMode()
{
	setChallengeMode();
	mIsChallengeMode = false;
}

/**
 * @todo: Documentation
 */
int PlayerState::getPartsGetCount(int stageID)
{
	if (stageID < STAGE_START || stageID >= STAGE_COUNT) {
		ERROR("yamsi3 !\n");
	}
	return mStagePartsCollected[stageID];
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
int PlayerState::getCardPikiCount(int color)
{
	if (color >= PikiMinColor && color <= PikiMaxColor) {
		return GameStat::allPikis[color];
	}
	ERROR("NANDEYANEN-colr %d\n", color);
	return GameStat::allPikis;
}

char unusedStr[] = { "ペレットマネージャ" };

/**
 * @todo: Documentation
 */
int PlayerState::getCardUfoPartsCount()
{
	return mCurrParts;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
int PlayerState::getUfoPercentage()
{
	return getTotalParts() / (MAX_UFO_PARTS) * 100.0f;
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
int PlayerState::getTotalPikiCount(int color)
{
	int total = pikiInfMgr.getColorTotal(color);

	int test        = 0;
	StageInfo* node = (StageInfo*)flowCont.mStageList.mChild;
	for (int i = 0; i < STAGE_COUNT; i++) {
		test += node->mStageInf.mBPikiInfMgr.getPikiCount(color);
		node = (StageInfo*)node->mNext;
	}

	return total;
}

/**
 * @todo: Documentation
 */
void PlayerState::saveCard(RandomAccessStream& data)
{
	int i;
	mIsTutorialMode = false;

	ID32 id;

	id.setID('cont');
	id.write(data);
	pikiInfMgr.saveCard(data);

	id.setID('cach');
	id.write(data);
	generatorCache->saveCard(data);

	id.setID('meck');
	id.write(data);
	StageInfo* node = (StageInfo*)flowCont.mStageList.mChild;
	for (i = 0; i < STAGE_COUNT; i++) {
		node->mStageInf.saveCard(data);
		node = (StageInfo*)node->mNext;
	}

	id.setID('ufop');
	id.write(data);
	data.writeByte(mShipUpgradeLevel);

	mDemoFlags.saveCard(data);
	mResultFlags.saveCard(data);
	data.writeInt(mTotalRegisteredParts);

	for (i = 0; i < mTotalRegisteredParts; i++) {
		data.writeByte(mUfoParts[i].mPartVisType);
	}
	PRINT("**** SAVING @ %d (%d,%d,%d)\n", data.getPosition());
	data.writeInt(mSproutedNum);
	data.writeInt(mLostBattlePikis);
	data.writeInt(mLeftBehindPikis);
	data.writeInt(mTotalPluckedPikiCount);
	data.writeInt(mCurrParts);
	data.writeInt(mRequiredUfoPartCount);
	data.writeByte(mContainerFlag);
	data.writeByte(mIsTutorialMode);
	data.writeByte(_186);
	data.writeByte(mShipEffectPartFlag);
	data.writeByte(mDisplayPikiFlag);

	for (i = 0; i < STAGE_COUNT; i++) {
		data.writeByte(mStagePartsCollected[i]);
	}
	data.writeInt(mTotalDeadPikiNum);
	data.writeInt(mTotalBornPikiNum);

	id.setID('limg');
	id.write(data);

	node = (StageInfo*)flowCont.mStageList.mChild;
	for (i = 0; i < STAGE_COUNT; i++) {
		if (node->mGenFileList.getChildCount() > 0) {
			mCourseFlags[i]->saveCard(data);
		}
		node = (StageInfo*)node->mNext;
	}

	id.setID('visf');
	id.write(data);

	node = (StageInfo*)flowCont.mStageList.mChild;
	PRINT("SAVE VISIT FLAGS FROM %d\n", data.getPosition());
	for (i = 0; i < STAGE_COUNT; i++) {
		PRINT("\t++++ STAGE %d as %s\n", i, node->mHasInitialised ? "VISITED" : "NEVER VISITED");
		data.writeByte(node->mHasInitialised);
		node = (StageInfo*)node->mNext;
	}

	for (i = 0; i < MAX_DAYS; i++) {
		data.writeByte(mPartsCollectedByDay[i]);
		data.writeByte(mPartsToNextByDay[i]);
	}
}

/**
 * @todo: Documentation
 */
void PlayerState::loadCard(RandomAccessStream& data)
{
	int i;
	ID32 id;
	PRINT("**************** LOAD CARD (%s) ****************\n", "Container Piki");
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);
	pikiInfMgr.loadCard(data);

	PRINT("**************** LOAD CARD (%s) ****************\n", "Generator Cache");
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);
	generatorCache->loadCard(data);

	PRINT("**************** LOAD CARD (%s) ****************\n", "Piki Head");
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);
	StageInfo* node = (StageInfo*)flowCont.mStageList.mChild;
	for (i = 0; i < STAGE_COUNT; i++) {
		node->mStageInf.loadCard(data);
		node = (StageInfo*)node->mNext;
	}

	PRINT("**************** LOAD CARD (%s) ****************\n", "Player State");
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);
	mShipUpgradeLevel = data.readByte();

	mDemoFlags.loadCard(data);
	mResultFlags.loadCard(data);

	int parts = data.readInt();
	PRINT("**** BEFORE UFO PARTS :: %d \n", data.getPosition());
	for (i = 0; i < parts; i++) {
		mUfoParts[i].mPartVisType = data.readByte();
	}
	PRINT("**** LOADING @ %d\n", data.getPosition());

	mSproutedNum           = data.readInt();
	mLostBattlePikis       = data.readInt();
	mLeftBehindPikis       = data.readInt();
	mTotalPluckedPikiCount = data.readInt();
	mCurrParts             = data.readInt();
	mRequiredUfoPartCount  = data.readInt();
	mContainerFlag         = data.readByte();
	mIsTutorialMode        = data.readByte();
	_186                   = data.readByte();
	mShipEffectPartFlag    = data.readByte();
	mDisplayPikiFlag       = data.readByte();
	for (i = 0; i < STAGE_COUNT; i++) {
		mStagePartsCollected[i] = data.readByte();
	}
	mTotalDeadPikiNum = data.readInt();
	mTotalBornPikiNum = data.readInt();
	PRINT("*** loaded : %d %d %d\n", mCurrParts, mContainerFlag, mIsTutorialMode);
	PRINT("| ufo level %d ufo parts %d container flag %d tutorialmode %s\n", mShipUpgradeLevel, mCurrParts, mContainerFlag,
	      mIsTutorialMode ? "yes" : "no");
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);

	node = (StageInfo*)flowCont.mStageList.mChild;
	for (i = 0; i < STAGE_COUNT; i++) {
		if (node->mGenFileList.getChildCount() > 0) {
			mCourseFlags[i]->loadCard(data);
		}
		node = (StageInfo*)node->mNext;
	}

	PRINT("LOAD VISIT FLAGS FROM %d\n", data.getPosition());
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);
	node = (StageInfo*)flowCont.mStageList.mChild;
	for (i = 0; i < STAGE_COUNT; i++) {
		node->mHasInitialised = data.readByte();
		PRINT("\t+++++++++ STAGE %d : %s\n", i, node->mHasInitialised ? "VISITED BEFORE" : "NEVER BEFORE");
		node = (StageInfo*)node->mNext;
	}
	PRINT("*******************************************************************************\n");
	generatorCache->dump();

	for (i = 0; i < MAX_DAYS; i++) {
		mPartsCollectedByDay[i] = data.readByte();
		mPartsToNextByDay[i]    = data.readByte();
	}
}

/**
 * @todo: Documentation
 */
bool PlayerState::isTutorial()
{
	if (flowCont.mCurrentStage && flowCont.mCurrentStage->mStageID != STAGE_Practice) {
		return false;
	}

	if (mIsChallengeMode) {
		return false;
	}

	return mIsTutorialMode;
}

/**
 * @todo: Documentation
 */
bool PlayerState::isGameCourse()
{
	int val = flowCont.mCurrentStage->mStageIndex;
	return (val >= STAGE_START && val < STAGE_COUNT);
}

/**
 * @todo: Documentation
 */
bool PlayerState::checkLimitGenFlag(int id)
{
	if (!isGameCourse()) {
		return true;
	}
	return mCourseFlags[flowCont.mCurrentStage->mStageIndex]->isFlag(id);
}

/**
 * @todo: Documentation
 */
void PlayerState::setLimitGenFlag(int id)
{
	if (isGameCourse()) {
		int course = flowCont.mCurrentStage->mStageIndex;
		mCourseFlags[course]->setFlag(id);
		mCourseFlags[course]->dump();
	}

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
bool PlayerState::displayPikiCount(int color)
{
	bool res = ((1 << color) & mDisplayPikiFlag) != 0;
	if ((1 << color) & mDisplayPikiFlag) {
		PRINT("color %d : %x is on\n", color, mDisplayPikiFlag);
	}
	return res;
}

/**
 * @todo: Documentation
 */
void PlayerState::setDisplayPikiCount(int color)
{
	mDisplayPikiFlag |= 1 << color;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
void PlayerState::init()
{
	pelletMgr = new PelletMgr(nullptr);
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
bool PlayerState::hasUfoParts(u32 idx)
{
	for (int i = 0; i < mTotalParts; i++) {
		if (idx == mUfoParts[i].mModelID) {
			return mUfoParts[i].mPartVisType != PARTVIS_Uncollected;
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
void PlayerState::update()
{

	STACK_PAD_VAR(2);

	bool isCM = isChallengeMode();
	if (!isCM) {
		mDemoFlags.update();
	}

	if (isCM || !mIsTutorialMode) {
		int time = gameflow.mWorldClock.mCurrentGameHour;
		if (time != mLastUpdatedTime) {
			GameStat::update();
			mLastUpdatedTime = time;

			// When I'm in a WTF competition and my opponent is this
			int* b = (int*)(&GameStat::allPikis) + Blue;
			int* r = (int*)(&GameStat::allPikis) + Red;
			int* y = (int*)(&GameStat::allPikis) + Yellow;

			mPerHourGraph.set(mLastUpdatedTime, Blue, *b);
			mPerHourGraph.set(mLastUpdatedTime, Red, *r);
			mPerHourGraph.set(mLastUpdatedTime, Yellow, *y);
			PRINT("record (%d %d %d) = %d\n", GameStat::allPikis, GameStat::allPikis[0], GameStat::allPikis[1], GameStat::allPikis[2]);
		}
	}
}

/**
 * @todo: Documentation
 */
void PlayerState::initCourse()
{
	for (int i = 0; i < 10; i++) {
		PRINT("***************************** PLAYER STAT INIT COURSE!\n");
	}
	mPerHourGraph.init();
	setNavi(false);
	setDayEnd(false);
	mHasExtinctionDemoPlayed = false;
	mNaviLightEfx            = new PermanentEffect;
	mNaviLightGlowEfx        = new PermanentEffect;
	mNaviLightEfx->changeEffect(EffectMgr::EFF_Navi_Light);
	mNaviLightGlowEfx->changeEffect(EffectMgr::EFF_Navi_LightGlow);
	mNaviLightEfx->stop();
	mNaviLightGlowEfx->stop();
	mNaviLightEfxPos.set(0.0f, 0.0f, 0.0f);
	mResultFlags.dump();
	int id           = flowCont.mCurrentStage->mStageIndex;
	mLastUpdatedTime = -1;
	if (id != 0) {
		mIsTutorialMode = false;
	}
	mOlimarShapeObj = naviMgr->mNaviShapeObject[0];
	mOlimarAnimMgr.init(mOlimarShapeObj->mAnimMgr, &mOlimarShapeObj->mAnimatorB, &mOlimarShapeObj->mAnimatorA, naviMgr->mMotionTable);
	mOlimarAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Noru), PaniMotionInfo(PIKIANIM_Noru));
	mDemoFlags.initCourse();
}

/**
 * @todo: Documentation
 */
void PlayerState::exitCourse()
{
	for (int i = 0; i < mTotalRegisteredParts; i++) {
		mUfoParts[i].mPelletShape = nullptr;
	}
	mTotalRegisteredParts = 0;

	int counts[3];
	for (int hour = getStartHour(); hour <= getEndHour(); hour++) {
		for (int color = 0; color < 3; color++) {
			counts[color] = getPikiHourCount(hour, color);
		}
		PRINT("*** HOUR %d : (%3d %3d %3d)\n", hour, counts[0], counts[1], counts[2]);
	}
	mIsTutorialMode = false;
}

/**
 * @todo: Documentation
 */
void PlayerState::setNavi(bool doSet)
{
	if (!doSet) {
		mIsNaviPilot = false;
		return;
	}

	if (mIsNaviPilot == false) {
		mNaviLightEfx->restart();
		mNaviLightGlowEfx->restart();
		mIsNaviPilot = true;
		mOlimarAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Noru), PaniMotionInfo(PIKIANIM_Noru));
	}
}

/**
 * @todo: Documentation
 */
int PlayerState::getFinalDeadPikis()
{
	return mTotalDeadPikiNum;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
int PlayerState::getFinalBornPikis()
{
	// UNUSED FUNCTION (Matching by size)
	return mTotalBornPikiNum;
}

/**
 * @todo: Documentation
 */
void PlayerState::updateFinalResult()
{
	mTotalDeadPikiNum += GameStat::deadPikis;
	mTotalBornPikiNum += GameStat::bornPikis;
	mLivingPikiNum = 0;
	for (int i = 0; i < 3; i++) {
		mLivingPikiNum += getTotalPikiCount(i);
	}
	mLivingPikiNum += GameStat::mapPikis;
	PRINT("lastPikmins ===== %d _______________________________\n", mLivingPikiNum);
	gameflow.mGamePrefs.addBornPikis(GameStat::bornPikis);
}

/**
 * @todo: Documentation
 */
int PlayerState::getCurrDay()
{
	return gameflow.mWorldClock.mCurrentDay - 1;
}

/**
 * @todo: Documentation
 */
int PlayerState::getTotalDays()
{
	return MAX_DAYS;
}

/**
 * @todo: Documentation
 */
int PlayerState::getStartHour()
{
	return gameflow.mParameters->mStartHour();
}

/**
 * @todo: Documentation
 */
int PlayerState::getEndHour()
{
	return gameflow.mParameters->mEndHour();
}

/**
 * @todo: Documentation
 */
int PlayerState::getPikiHourCount(int time, int color)
{
	return mPerHourGraph.get(time, color);
}

/**
 * @todo: Documentation
 */
int PlayerState::getTotalParts()
{
	return mTotalParts;
}

/**
 * @todo: Documentation
 */
int PlayerState::getCurrParts()
{
	return mCurrParts;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
int PlayerState::getRestParts()
{
	return mTotalParts - mCurrParts;
}

/**
 * @todo: Documentation
 */
bool PlayerState::isUfoBroken()
{
	if (mIsChallengeMode) {
		return false;
	}

	if (mCurrParts > 0) {
		return false;
	}

	if (flowCont.mCurrentStage->mStageID == STAGE_Practice) {
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void PlayerState::registerUfoParts(int repairAnimJointIndex, u32 modelID, u32 pelletID)
{
	pelletMgr->mUfoMotionTable = PaniPelletAnimator::createMotionTable();
	if (mTotalRegisteredParts >= mTotalParts) {
		PRINT("failed to register (%d,%s,%s)\n", repairAnimJointIndex, ID32(modelID).mStringID, ID32(pelletID).mStringID);
		ERROR("sorry\n");
	}

	UfoParts* part              = &mUfoParts[mTotalRegisteredParts];
	part->mRepairAnimJointIndex = repairAnimJointIndex;
	part->mPelletID             = pelletID;
	part->mModelID              = modelID;
	PelletShapeObject* shape    = pelletMgr->getShapeObject(modelID);
	part->initAnim(shape);

	if (shape) {
		shape->mShape->makeInstance(part->mAnimatedMaterials, 0);
	}

	mTotalRegisteredParts++;
}

/**
 * @todo: Documentation
 */
void PlayerState::UfoParts::initAnim(PelletShapeObject* shape)
{
	mPelletShape = shape;
	if (!shape) {
		return;
	}

	mAnimator.init(&mPelletShape->mAnimatorA, &mPelletShape->mAnimatorB, mPelletShape->mAnimMgr, pelletMgr->mUfoMotionTable);
	mMotionSpeed = 0.0f;
	mAnimator.startMotion(PaniMotionInfo(PelletMotion::Carry));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void PlayerState::UfoParts::startMotion(int id)
{
	if (mPelletShape) {
		mAnimator.startMotion(PaniMotionInfo(id, this));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void PlayerState::UfoParts::startMotion(int id1, int id2)
{
	if (mPelletShape) {
		mAnimator.startMotion(PaniMotionInfo(id1, this), PaniMotionInfo(id2));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
void PlayerState::UfoParts::stopMotion()
{
	mMotionSpeed = 30.0f;
}

/**
 * @todo: Documentation
 */
void PlayerState::UfoParts::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	int anim     = mAnimator.mLowerAnimator.mMotionIdx;
	UfoItem* ufo = itemMgr->getUfo();

	switch (event.mEventType) {
	case KEY_LoopEnd:
		if (anim == 3) {
			switch (mModelID) {
			case UFOID_WhimsicalRadar:
				ufo->playEventSound(ufo, SE_UFO_ANTENNA);
				break;
			case UFOID_GuardSatellite:
				ufo->playEventSound(ufo, SE_UFO_SATELLITE);
				break;
			case UFOID_Bowsprit:
				break;
			}
		} else {
			ID32(mModelID).mStringID;
			switch (mModelID) {
			case UFOID_MainEngine:
				ufo->playEventSound(ufo, SE_UFO_ENGINE);
			case UFOID_WhimsicalRadar:
				ufo->playEventSound(ufo, SE_UFO_RADER);
				break;
			}
		}
		break;

	case KEY_Finished:
		startMotion(PelletMotion::After, PelletMotion::After);
		mMotionSpeed = 30.0f;
		PRINT("*** AFTER MOTION START * (%s)\n", ID32(mModelID).mStringID);
		break;

	case KEY_PlayEffect:
		if (anim == 1) {
			PRINT("UFO PARTS * GOT EFFECT KEY : index=%d\n", event.mValue);
			switch (event.mValue) {
			case 0:
				effectMgr->create(EffectMgr::EFF_UfoPart_ASN01, mRepairEffectPosition, nullptr, nullptr);
				PRINT("assign effect 01\n");
				break;
			case 1:
				effectMgr->create(EffectMgr::EFF_UfoPart_ASN02, mRepairEffectPosition, nullptr, nullptr);
				PRINT("assign effect 02\n");
				break;
			}
		}
	}

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void PlayerState::ufoAssignStart()
{
	UfoParts* parts = mCurrentRepairingPart;
	if (!parts) {
		PRINT("after motion を再生すべき ?\n"); // Should I play after motion?
		return;
	}

	if (parts->mPelletShape->isMotionFlag(PelletMotionFlags::UsePiston)) {
		parts->startMotion(PelletMotion::Appear, PelletMotion::Piston);
		parts->setMotionSpeed(30.0f);
	} else {
		parts->startMotion(PelletMotion::Appear);
		parts->setMotionSpeed(30.0f);
	}
	mCurrentRepairingPart = nullptr;
}

/**
 * @todo: Documentation
 */
void PlayerState::startSpecialMotions()
{
	startUfoPartsMotion(UFOID_Bowsprit, PelletMotion::Special, false);
	startUfoPartsMotion(UFOID_WhimsicalRadar, PelletMotion::Special, false);
	startUfoPartsMotion(UFOID_InterstellarRadio, PelletMotion::Special, false);
	startUfoPartsMotion(UFOID_GuardSatellite, PelletMotion::Special, false);
}

/**
 * @todo: Documentation
 */
void PlayerState::startAfterMotions()
{
	for (int i = 0; i < mTotalRegisteredParts; i++) {
		UfoParts* part = &mUfoParts[i];
		if (part && part->mPartVisType != PARTVIS_Uncollected && part->mPelletShape) {
			PRINT("(%s) : AFTER motion \n", ID32(part->mModelID).mStringID);
			part->startMotion(PelletMotion::After, PelletMotion::After);
			part->setMotionSpeed(30.0f);
		}
	}
}

/**
 * @todo: Documentation
 */
void PlayerState::startUfoPartsMotion(u32 id, int anim, bool wantPassiveMotion)
{
	UfoParts* part = findUfoParts(id);
	if (part) {
		if (part->mPelletShape->isMotionFlag(PelletMotionFlags::UsePiston)) {
			if (wantPassiveMotion) {
				part->startMotion(anim, PelletMotion::Piston);
			} else {
				part->startMotion(anim, anim);
			}
			part->setMotionSpeed(30.0f);
		} else {
			part->startMotion(anim);
			part->setMotionSpeed(30.0f);
		}
	}
}

/**
 * @todo: Documentation
 */
void PlayerState::getUfoParts(u32 partID, bool isInvisiblePart)
{
	UfoParts* parts = findUfoParts(partID);
	if (!parts && !isInvisiblePart) {
		STACK_PAD_INLINE(1);
		PRINT("parts %s is not registered !\n", ID32(partID).mStringID);
		ERROR("sorry\n");
	}

	// check required part count
	if (partID != UFOID_NovaBlaster && partID != UFOID_SpaceFloat && partID != UFOID_MassageMachine && partID != UFOID_SecretSafe
	    && partID != UFOID_UVLamp) {
		mRequiredUfoPartCount++;
	}

	switch (partID) {
	case UFOID_WhimsicalRadar:
		mShipEffectPartFlag |= 1;
		for (int i = 0; i < 10; i++) {
			PRINT("U GOT RADAR !\n");
		}
		if (!hasRadar()) {
			ERROR("sonna!");
		}
		break;

	case UFOID_IoniumJet1:
		mShipEffectPartFlag |= 2;
		for (int i = 0; i < 10; i++) {
			PRINT("U GOT LEFT HORN !\n");
		}
		if (!hasUfoLeftControl()) {
			ERROR("sonna!\n");
		}
		break;

	case UFOID_IoniumJet2:
		mShipEffectPartFlag |= 4;
		for (int i = 0; i < 10; i++) {
			PRINT("U GOT RIGHT HORN !\n");
		}
		if (!hasUfoRightControl()) {
			ERROR("sonna!\n");
		}
		break;
	}

	mStagePartsCollected[flowCont.mCurrentStage->mStageID]++;
	if (!isInvisiblePart) {
		parts->mPartVisType = PARTVIS_Visible;
	} else {
		parts->mPartVisType = PARTVIS_Invisible;
	}
	mCurrParts++;
	PRINT_GLOBAL("ufo parts %d/%d", mRequiredUfoPartCount, mCurrParts);
	for (int i = 0; i < 33; i++) {
		PRINT("ufoPartsCount = %d\n", mCurrParts);
	}

	if (mCurrParts >= AIConstant::_instance->mConstants._184()) {
		PRINT("PERFECT !\n");
		mShipUpgradeLevel = 5;
		PRINT_GLOBAL("--- perfect 5");
	} else if (mCurrParts >= AIConstant::_instance->mConstants._174()) {
		gameflow.mPlayState.openStage(STAGE_Last);
		playerState->mResultFlags.setSeen(zen::RESFLAG_Collect15Parts);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 4 ***\n");
		}
		mShipUpgradeLevel = 4;
		PRINT_GLOBAL("--- level 4");
	} else if (mCurrParts >= AIConstant::_instance->mConstants._164()) {
		gameflow.mPlayState.openStage(STAGE_Yakushima);
		playerState->mResultFlags.setOn(zen::RESFLAG_UnlockYakushima);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 3 ***\n");
		}
		mShipUpgradeLevel = 3;
		PRINT_GLOBAL("--- level 3");
	} else if (mCurrParts >= AIConstant::_instance->mConstants._154()) {
		playerState->mResultFlags.setOn(zen::RESFLAG_UnlockCave);
		gameflow.mPlayState.openStage(STAGE_Cave);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 2 ***\n");
		}
		mShipUpgradeLevel = 2;
		PRINT_GLOBAL("--- level 2");
	} else if (mCurrParts >= 1) {
		gameflow.mPlayState.openStage(STAGE_Forest);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 1 ***\n");
		}
		PRINT_GLOBAL("--- level 1"); // Yes, it's before the value assignment here.
		mShipUpgradeLevel = 1;
	}

	if (isInvisiblePart) {
		mCurrentRepairingPart = nullptr;
	} else {
		mCurrentRepairingPart = parts;
	}

	if (mCurrParts >= 15) {
		playerState->mResultFlags.setOn(zen::RESFLAG_Collect15Parts);
	}

	if (mCurrParts >= 11 && gameflow.mWorldClock.mCurrentDay - 1 >= 9) {
		playerState->mResultFlags.setOn(zen::RESFLAG_Collect10Parts);
	}

	if (!isInvisiblePart) {
		if (parts->mPelletShape->isMotionFlag(PelletMotionFlags::UsePiston)) {
			parts->startMotion(PelletMotion::Appear, PelletMotion::Piston);
			parts->setMotionSpeed(0.0f);
		} else {
			parts->startMotion(PelletMotion::Appear);
			parts->setMotionSpeed(0.0f);
		}
	}

	if (mCurrParts == 29) {
		playerState->mResultFlags.setOn(zen::RESFLAG_Collect29Parts);
		playerState->mResultFlags.setSeen(zen::RESFLAG_Collect25Parts);
		playerState->mResultFlags.setSeen(zen::RESFLAG_Collect15Parts);
	} else if (mCurrParts == 25) {
		playerState->mResultFlags.setOn(zen::RESFLAG_Collect25Parts);
		playerState->mResultFlags.setSeen(zen::RESFLAG_Collect15Parts);
	}

	STACK_PAD_TERNARY(mCurrParts, 1);
}

/**
 * @todo: Documentation
 */
int PlayerState::getNextPowerupNumber()
{
	int counts[6];
	counts[0] = 1;
	counts[1] = AIConstant::_instance->mConstants._154();
	counts[2] = AIConstant::_instance->mConstants._164();
	counts[3] = AIConstant::_instance->mConstants._174();
	counts[4] = AIConstant::_instance->mConstants._184();
	counts[5] = MAX_UFO_PARTS;
	return counts[mShipUpgradeLevel] - mCurrParts;
}

/**
 * @todo: Documentation
 */
void PlayerState::preloadHenkaMovie()
{
	int level = mShipUpgradeLevel;
	int parts = mCurrParts + 1;
	if (parts == 1) {
		level = 1;
	} else if (AIConstant::_instance->mConstants._154() == parts) {
		level = 2;
	} else if (AIConstant::_instance->mConstants._164() == parts) {
		level = 3;
	} else if (AIConstant::_instance->mConstants._174() == parts) {
		level = 4;
	} else if (MAX_UFO_PARTS == parts) {
		level = 5;
	}

	int movies[5] = { DEMOID_ShipUpgradePractice, DEMOID_ShipUpgradeForest, DEMOID_ShipUpgradeCave, DEMOID_ShipUpgradeYakushima,
		              DEMOID_ShipUpgradeLast };
	if (level != mShipUpgradeLevel) {
		gameflow.mGameInterface->movie(movies[level - 1], 0, nullptr, nullptr, nullptr, CAF_AllVisibleMask, true);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050
 */
void PlayerState::lostUfoParts(u32 partID)
{
	UfoParts* part = findUfoParts(partID);
	if (!part) {
		ID32 id(partID);
		PRINT("parts %s is not registered !\n", id.mStringID);
		ERROR("sorry\n");
	}
	part->mPartVisType = PARTVIS_Visible;
}

/**
 * @todo: Documentation
 */
PlayerState::UfoParts* PlayerState::findUfoParts(u32 partID)
{
	for (int i = 0; i < mTotalRegisteredParts; i++) {
		if (mUfoParts[i].mModelID == partID) {
			return &mUfoParts[i];
		}
	}
	return nullptr;
}

/**
 * @todo: Documentation
 */
void PlayerState::renderParts(Graphics& gfx, Shape* shape)
{
	for (int i = 0; i < mTotalRegisteredParts; i++) {
		UfoParts* parts = &mUfoParts[i];
		if (parts->mPartVisType == PARTVIS_Visible && parts->mRepairAnimJointIndex != -1) {
			if (parts->mPelletShape == nullptr) {
				ID32 id(parts->mModelID);
				PRINT("++++ shapeObject for ufo parts %d is null (%s)\n", i, id.mStringID);
				ERROR("sorry\n");
			}

			if (AIPerf::kandoOnly) {
				// This is the extent to which I'm willing to document this bug (size is off-by-one but animation "7" is unused).
				const char* names[PelletMotion::COUNT - 1] = { "carry", "assign", "after", "piston", "special", "6" };
				STACK_PAD_VAR(1);
				ID32 id(parts->mModelID);
				PRINT("* parts(%s) : motion(%s) : (%.1f|%.1f) frame\n", names[parts->mPartVisType], id.mStringID);
			}
			STACK_PAD_VAR(1);
			parts->mAnimator.updateAnimation(parts->mMotionSpeed, 30.0f);
			parts->mAnimator.updateContext();
			immut Matrix4f& temp = shape->getAnimMatrix(parts->mRepairAnimJointIndex);
			parts->mRepairEffectPosition.set(0.0f, 0.0f, 0.0f);
			shape->calcJointWorldPos(gfx, parts->mRepairAnimJointIndex, parts->mRepairEffectPosition);
			Matrix4f mtx = temp;
			parts->mPelletShape->mShape->updateAnim(gfx, mtx, nullptr);
			parts->mAnimatedMaterials.animate(nullptr);
			parts->mPelletShape->mShape->drawshape(gfx, *gfx.mCamera, &parts->mAnimatedMaterials);
		}
	}

	if (mIsNaviPilot) {
		mOlimarAnimMgr.updateAnimation(30.0f);
		mOlimarAnimMgr.updateContext();
		immut Matrix4f& mtx = shape->getAnimMatrix(11);
		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, PI, 0.0f), Vector3f(0.0f, -10.0f, 0.0f));
		Matrix4f mtx3;
		mtx.multiplyTo(mtx2, mtx3);
		mOlimarShapeObj->mShape->updateAnim(gfx, mtx3, nullptr);
		mOlimarShapeObj->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
		mNaviLightEfxPos.set(2.0f, 0.0f, 0.0f);
		mOlimarShapeObj->mShape->calcJointWorldPos(gfx, 6, mNaviLightEfxPos);
		mNaviLightEfx->updatePos(mNaviLightEfxPos);
		mNaviLightGlowEfx->updatePos(mNaviLightEfxPos);
	}

	STACK_PAD_TERNARY(mIsNaviPilot, 3);
}
