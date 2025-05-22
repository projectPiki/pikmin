#include "PlayerState.h"
#include "Generator.h"
#include "FlowController.h"
#include "gameflow.h"
#include "UtEffect.h"
#include "OnePlayerSection.h"
#include "Pellet.h"
#include "sysNew.h"
#include "GameStat.h"
#include "UfoItem.h"
#include "NaviMgr.h"
#include "Shape.h"
#include "Graphics.h"
#include "Interface.h"
#include "AIConstant.h"
#include "Piki.h"
#include "AIPerf.h"
#include "DebugLog.h"

int PlayerState::totalUfoParts = MAX_UFO_PARTS;

bool preloadUFO = false;
PlayerState* playerState;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("PlayerState")

UfoPartsInfo partsInfo[5] = {
	{ 'ust1', 1 }, { 'ust2', 1 }, { 'ust3', 1 }, { 'ust4', 1 }, { 'ust5', 1 },
};

char unusedStr[] = { "ペレットマネージャ" };

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
TimeGraph::TimeGraph()
{
	_04 = nullptr;
	_02 = 0;
	_00 = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void TimeGraph::create(u16 a, u16 b)
{
	int size = b - a + 1;
	_00      = a;
	_02      = b;
	_04      = new PikiNum[size];
	init();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void TimeGraph::init()
{
	for (int i = 0; i < _02 - _00 + 1; i++) {
		_04[i].set(-1, -1);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void TimeGraph::set(u16 time, int b, int c)
{
	int t = time - _00;
	if (t < 0 || (_02 - _00 + 1) < t) {
		ERROR("illegal time int %d\n", time);
	}
	_04[t].set(b, c);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
int TimeGraph::get(u16 time, int color)
{
	if (time - _00 < 0 || (_02 - _00 + 1) < time - _00) {
		ERROR("illegal time int %d\n", time);
	}
	return _04[time - _00].get(color);
}

/*
 * --INFO--
 * Address:	8007F3B8
 * Size:	000058
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

/*
 * --INFO--
 * Address:	8007F410
 * Size:	00019C
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

/*
 * --INFO--
 * Address:	8007F5AC
 * Size:	0001CC
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
	mIsChallengeMode      = 0;
	mLeftBehindPikis      = 0;
	mLostBattlePikis      = 0;
	mSproutedNum          = 0;
	_0C                   = 0;
	_1A0                  = 0;
	_1A4                  = 0;
	mDisplayPikiFlag      = 0;
	mShipEffectPartFlag   = 8;
	mTotalRegisteredParts = 0;
	mTotalParts           = totalUfoParts;
	_180                  = 0;
	mCurrParts            = 0;
	_14                   = 0;
	mContainerFlag        = 0;
	setContainer(1);
	setDisplayPikiCount(1);
	mTotalRegisteredParts = 0;

	for (i = 0; i < mTotalParts; i++) {
		mUfoParts[i]._DC = 0;
	}

	mIsTutorialMode = true;
	for (i = 0; i < 5; i++) {
		_187[i] = false;
	}

	StageInfo* node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (i = 0; i < 5; i++) {
		if (node->mFileInfoList.getChildCount() > 0) {
			mCourseFlags[i]->reset();
		}
		node = (StageInfo*)node->mNext;
	}

	mShipUpgradeLevel = 0;
}

/*
 * --INFO--
 * Address:	8007F778
 * Size:	000330
 */
PlayerState::PlayerState()
{
	int i;
	for (i = 0; i < MAX_DAYS; i++) {
		mPartsCollectedByDay[i] = 0;
		mPartsToNextByDay[i]    = 0;
	}

	mIsChallengeMode      = 0;
	mLeftBehindPikis      = 0;
	mLostBattlePikis      = 0;
	mSproutedNum          = 0;
	_0C                   = 0;
	_1A0                  = 0;
	_1A4                  = 0;
	mDisplayPikiFlag      = 0;
	mShipEffectPartFlag   = 8;
	mTotalRegisteredParts = 0;
	mTotalParts           = totalUfoParts;

	mUfoParts      = new UfoParts[mTotalParts];
	_180           = 0;
	mCurrParts     = 0;
	_14            = 0;
	mContainerFlag = 0;
	setContainer(1);
	setDisplayPikiCount(1);
	mTotalRegisteredParts = 0;

	for (i = 0; i < mTotalParts; i++) {
		mUfoParts[i]._DC = 0;
	}
	_18C.create(getStartHour(), getEndHour());
	_198.create(0, getTotalDays());
	mIsTutorialMode = true;
	for (i = 0; i < 5; i++) {
		_187[i] = false;
	}
	mCourseFlags = new BitFlags*[5];

	StageInfo* node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (i = 0; i < 5; i++) {
		int size = node->mFileInfoList.getChildCount();
		if (size > 0) {
			mCourseFlags[i] = new BitFlags;
			mCourseFlags[i]->create(size, nullptr);
			mCourseFlags[i]->reset();
		}
		node = (StageInfo*)node->mNext;
	}

	mShipUpgradeLevel = 0;
}

/*
 * --INFO--
 * Address:	8007FB44
 * Size:	000040
 */
bool PlayerState::courseOpen(int courseID)
{
	if (courseID >= STAGE_START && courseID <= STAGE_END) {
		return (gameflow.mPlayState.mCourseOpenFlags & (1 << courseID)) != 0;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8007FB84
 * Size:	00001C
 */
bool PlayerState::happyEndable()
{
	return _180 >= 25;
}

/*
 * --INFO--
 * Address:	8007FBA0
 * Size:	000074
 */
void PlayerState::setChallengeMode()
{
	mIsChallengeMode = 1;

	// set EVERY demo flag. no cutscenes!!
	for (int i = 0; i < DEMOFLAG_COUNT; i++) {
		mDemoFlags.setFlagOnly(i);
	}

	mIsTutorialMode     = 0;
	mContainerFlag      = 255;
	_186                = 0;
	mDisplayPikiFlag    = 0xFF;
	mShipEffectPartFlag = 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PlayerState::setDebugMode()
{
	setChallengeMode();
	mIsChallengeMode = false;
}

/*
 * --INFO--
 * Address:	8007FC14
 * Size:	00000C
 */
int PlayerState::getPartsGetCount(int index)
{
	if (index < 0 || index > 4) {
		ERROR("yamsi3 !\n");
	}
	return _187[index];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
int PlayerState::getCardPikiCount(int color)
{
	if (color < 0 || color > 2) {
		ERROR("NANDEYANEN-colr %d\n", color);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007FC20
 * Size:	000008
 */
int PlayerState::getCardUfoPartsCount()
{
	return mCurrParts;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
int PlayerState::getUfoPercentage()
{
	return getTotalParts() / (MAX_UFO_PARTS) * 100.0f;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007FC28
 * Size:	000084
 */
int PlayerState::getTotalPikiCount(int color)
{
	int total = pikiInfMgr.getColorTotal(color);

	int test        = 0;
	StageInfo* node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (int i = 0; i < 5; i++) {
		test += node->mStageInf.mBPikiInfMgr.getPikiCount(color);
		node = (StageInfo*)node->mNext;
	}

	return total;
}

/*
 * --INFO--
 * Address:	8007FCAC
 * Size:	0003FC
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
	StageInfo* node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (i = 0; i < 5; i++) {
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
		data.writeByte(mUfoParts[i]._DC);
	}
	PRINT("**** SAVING @ %d (%d,%d,%d)\n", data.getPosition());
	data.writeInt(mSproutedNum);
	data.writeInt(mLostBattlePikis);
	data.writeInt(mLeftBehindPikis);
	data.writeInt(_0C);
	data.writeInt(mCurrParts);
	data.writeInt(_180);
	data.writeByte(mContainerFlag);
	data.writeByte(mIsTutorialMode);
	data.writeByte(_186);
	data.writeByte(mShipEffectPartFlag);
	data.writeByte(mDisplayPikiFlag);

	for (i = 0; i < 5; i++) {
		data.writeByte(_187[i]);
	}
	data.writeInt(_1A0);
	data.writeInt(_1A4);

	id.setID('limg');
	id.write(data);

	node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (i = 0; i < 5; i++) {
		if (node->mFileInfoList.getChildCount() > 0) {
			mCourseFlags[i]->saveCard(data);
		}
		node = (StageInfo*)node->mNext;
	}

	id.setID('visf');
	id.write(data);

	node = (StageInfo*)flowCont.mRootInfo.mChild;
	PRINT("SAVE VISIT FLAGS FROM %d\n", data.getPosition());
	for (i = 0; i < 5; i++) {
		PRINT("\t++++ STAGE %d as %s\n", i, node->mHasInitialised ? "VISITED" : "NEVER VISITED");
		data.writeByte(node->mHasInitialised);
		node = (StageInfo*)node->mNext;
	}

	for (i = 0; i < MAX_DAYS; i++) {
		data.writeByte(mPartsCollectedByDay[i]);
		data.writeByte(mPartsToNextByDay[i]);
	}
}

/*
 * --INFO--
 * Address:	800800A8
 * Size:	0003CC
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
	StageInfo* node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (i = 0; i < 5; i++) {
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
		mUfoParts[i]._DC = data.readByte();
	}
	PRINT("**** LOADING @ %d\n", data.getPosition());

	mSproutedNum        = data.readInt();
	mLostBattlePikis    = data.readInt();
	mLeftBehindPikis    = data.readInt();
	_0C                 = data.readInt();
	mCurrParts          = data.readInt();
	_180                = data.readInt();
	mContainerFlag      = data.readByte();
	mIsTutorialMode     = data.readByte();
	_186                = data.readByte();
	mShipEffectPartFlag = data.readByte();
	mDisplayPikiFlag    = data.readByte();
	for (i = 0; i < 5; i++) {
		_187[i] = data.readByte();
	}
	_1A0 = data.readInt();
	_1A4 = data.readInt();
	PRINT("*** loaded : %d %d %d\n", mCurrParts, mContainerFlag, mIsTutorialMode);
	PRINT("| ufo level %d ufo parts %d container flag %d tutorialmode %s\n", mShipUpgradeLevel, mCurrParts, mContainerFlag,
	      mIsTutorialMode ? "yes" : "no");
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);

	node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (i = 0; i < 5; i++) {
		if (node->mFileInfoList.getChildCount() > 0) {
			mCourseFlags[i]->loadCard(data);
		}
		node = (StageInfo*)node->mNext;
	}

	PRINT("LOAD VISIT FLAGS FROM %d\n", data.getPosition());
	id.read(data);
	PRINT("___ CARD * <%s> BLOCK ___\n", id.mStringID);
	node = (StageInfo*)flowCont.mRootInfo.mChild;
	for (i = 0; i < 5; i++) {
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

/*
 * --INFO--
 * Address:	80080474
 * Size:	000044
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

/*
 * --INFO--
 * Address:	800804B8
 * Size:	00002C
 */
bool PlayerState::isGameCourse()
{
	int val = flowCont.mCurrentStage->mStageIndex;
	return (val >= 0 && val < 5);
}

/*
 * --INFO--
 * Address:	800804E4
 * Size:	000068
 */
bool PlayerState::checkLimitGenFlag(int id)
{
	if (!isGameCourse()) {
		return true;
	}
	return mCourseFlags[flowCont.mCurrentStage->mStageIndex]->isFlag(id);
}

/*
 * --INFO--
 * Address:	8008054C
 * Size:	000080
 */
void PlayerState::setLimitGenFlag(int id)
{
	if (isGameCourse()) {
		int course = flowCont.mCurrentStage->mStageIndex;
		mCourseFlags[course]->setFlag(id);
		mCourseFlags[course]->dump();
	}

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800805CC
 * Size:	000020
 */
bool PlayerState::displayPikiCount(int color)
{
	bool res = ((1 << color) & mDisplayPikiFlag) != 0;
	if ((1 << color) & mDisplayPikiFlag) {
		PRINT("color %d : %x is on\n", color, mDisplayPikiFlag);
	}
	return res;
}

/*
 * --INFO--
 * Address:	800805EC
 * Size:	000018
 */
void PlayerState::setDisplayPikiCount(int color)
{
	mDisplayPikiFlag |= 1 << color;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void PlayerState::init()
{
	pelletMgr = new PelletMgr(nullptr);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80080604
 * Size:	00005C
 */
bool PlayerState::hasUfoParts(u32 idx)
{
	for (int i = 0; i < mTotalParts; i++) {
		if (idx == mUfoParts[i].mModelID) {
			return mUfoParts[i]._DC != 0;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	80080660
 * Size:	0000E4
 */
void PlayerState::update()
{

	u32 badCompiler[2];

	bool isCM = isChallengeMode();
	if (!isCM) {
		mDemoFlags.update();
	}

	if (isCM || !mIsTutorialMode) {
		int time = gameflow.mWorldClock.mCurrentTime;
		if (time != _194) {
			GameStat::update();
			_194 = time;

			// When I'm in a WTF competition and my opponent is this
			int* b = (int*)(&GameStat::allPikis) + Blue;
			int* r = (int*)(&GameStat::allPikis) + Red;
			int* y = (int*)(&GameStat::allPikis) + Yellow;

			_18C.set(_194, Blue, *b);
			_18C.set(_194, Red, *r);
			_18C.set(_194, Yellow, *y);
			PRINT("record (%d %d %d) = %d\n", GameStat::allPikis, GameStat::allPikis[0], GameStat::allPikis[1], GameStat::allPikis[2]);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  lbz       r30, 0x1B6(r3)
	  cmplwi    r30, 0
	  bne-      .loc_0x2C
	  addi      r3, r31, 0x54
	  bl        0x1BE8

	.loc_0x2C:
	  cmplwi    r30, 0
	  bne-      .loc_0x40
	  lbz       r0, 0x185(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC

	.loc_0x40:
	  lis       r3, 0x803A
	  lhz       r0, 0x194(r31)
	  subi      r3, r3, 0x2848
	  lwz       r30, 0x2F8(r3)
	  cmpw      r30, r0
	  beq-      .loc_0xCC
	  bl        0x91EA8
	  sth       r30, 0x194(r31)
	  lis       r3, 0x803D
	  addi      r4, r3, 0x1ED0
	  lhz       r3, 0x18C(r31)
	  addi      r5, r4, 0x4
	  lhz       r0, 0x194(r31)
	  addi      r6, r4, 0x8
	  lwz       r4, 0x0(r4)
	  sub       r0, r0, r3
	  lwz       r3, 0x190(r31)
	  mulli     r0, r0, 0xC
	  stwx      r4, r3, r0
	  lhz       r3, 0x18C(r31)
	  lhz       r0, 0x194(r31)
	  lwz       r5, 0x0(r5)
	  sub       r0, r0, r3
	  lwz       r4, 0x190(r31)
	  mulli     r3, r0, 0xC
	  addi      r0, r3, 0x4
	  stwx      r5, r4, r0
	  lhz       r3, 0x18C(r31)
	  lhz       r0, 0x194(r31)
	  lwz       r5, 0x0(r6)
	  sub       r0, r0, r3
	  lwz       r4, 0x190(r31)
	  mulli     r3, r0, 0xC
	  addi      r0, r3, 0x8
	  stwx      r5, r4, r0

	.loc_0xCC:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80080744
 * Size:	0001B0
 */
void PlayerState::initCourse()
{
	for (int i = 0; i < 10; i++) {
		PRINT("***************************** PLAYER STAT INIT COURSE!\n");
	}
	_18C.init();
	setNavi(false);
	setDayEnd(false);
	_BC  = 0;
	_1B8 = new PermanentEffect;
	_1BC = new PermanentEffect;
	_1B8->changeEffect(EffectMgr::EFF_Navi_Light);
	_1BC->changeEffect(EffectMgr::EFF_Navi_LightGlow);
	_1B8->stop();
	_1BC->stop();
	_1C0.set(0.0f, 0.0f, 0.0f);
	mResultFlags.dump();
	int id = flowCont.mCurrentStage->mStageIndex;
	_194   = -1;
	if (id != 0) {
		mIsTutorialMode = false;
	}
	_C0 = naviMgr->mNaviShapeObject[0];
	mPikiAnimMgr.init(_C0->mAnimMgr, &_C0->mAnimatorB, &_C0->mAnimatorA, naviMgr->mMotionTable);
	mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Noru), PaniMotionInfo(PIKIANIM_Noru));
	mDemoFlags.initCourse();
}

/*
 * --INFO--
 * Address:	800808F4
 * Size:	0000D0
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

/*
 * --INFO--
 * Address:	800809C4
 * Size:	000094
 */
void PlayerState::setNavi(bool p1)
{
	if (!p1) {
		_1B4 = 0;
		return;
	}

	if (_1B4 == 0) {
		_1B8->restart();
		_1BC->restart();
		_1B4 = 1;
		mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Noru), PaniMotionInfo(PIKIANIM_Noru));
	}
}

/*
 * --INFO--
 * Address:	80080A58
 * Size:	000008
 */
int PlayerState::getFinalDeadPikis()
{
	return _1A0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
int PlayerState::getFinalBornPikis()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80080A60
 * Size:	000150
 */
void PlayerState::updateFinalResult()
{
	_1A0 += GameStat::deadPikis;
	_1A4 += GameStat::bornPikis;
	_1A8 = 0;
	for (int i = 0; i < 3; i++) {
		_1A8 += getTotalPikiCount(i);
	}
	_1A8 += GameStat::mapPikis;
	PRINT("lastPikmins ===== %d _______________________________\n", _1A8);
	gameflow.mGamePrefs.addBornPikis(GameStat::bornPikis);
}

/*
 * --INFO--
 * Address:	80080BB0
 * Size:	000014
 */
int PlayerState::getCurrDay()
{
	return gameflow.mWorldClock.mCurrentDay - 1;
}

/*
 * --INFO--
 * Address:	80080BC4
 * Size:	000008
 */
int PlayerState::getTotalDays()
{
	return MAX_DAYS;
}

/*
 * --INFO--
 * Address:	80080BCC
 * Size:	000028
 */
int PlayerState::getStartHour()
{
	return gameflow.mParameters->mStartHour();
}

/*
 * --INFO--
 * Address:	80080BF4
 * Size:	000028
 */
int PlayerState::getEndHour()
{
	return gameflow.mParameters->mEndHour();
}

/*
 * --INFO--
 * Address:	80080C1C
 * Size:	00004C
 */
int PlayerState::getPikiHourCount(int time, int color)
{
	return _18C.get(time, color);
}

/*
 * --INFO--
 * Address:	80080C68
 * Size:	000008
 */
int PlayerState::getTotalParts()
{
	return mTotalParts;
}

/*
 * --INFO--
 * Address:	80080C70
 * Size:	000008
 */
int PlayerState::getCurrParts()
{
	return mCurrParts;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
int PlayerState::getRestParts()
{
	return mTotalParts - mCurrParts;
}

/*
 * --INFO--
 * Address:	80080C78
 * Size:	000050
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

/*
 * --INFO--
 * Address:	80080CC8
 * Size:	0000C4
 */
void PlayerState::registerUfoParts(int p1, u32 modelID, u32 pelletId)
{
	pelletMgr->mUfoMotionTable = PaniPelletAnimator::createMotionTable();
	if (mTotalRegisteredParts >= mTotalParts) {
		ID32 id1(modelID);
		ID32 id2(pelletId);
	}

	UfoParts* part           = &mUfoParts[mTotalRegisteredParts];
	part->mPartIndex         = p1;
	part->mPelletId          = pelletId;
	part->mModelID           = modelID;
	PelletShapeObject* shape = pelletMgr->getShapeObject(modelID);
	part->initAnim(shape);

	if (shape) {
		shape->mShape->makeInstance(part->mAnimatedMaterials, 0);
	}

	mTotalRegisteredParts++;
}

/*
 * --INFO--
 * Address:	80080D8C
 * Size:	000074
 */
void PlayerState::UfoParts::initAnim(PelletShapeObject* shape)
{
	mPelletShape = shape;
	if (!shape) {
		return;
	}

	mAnimator.init(&mPelletShape->mAnimatorA, &mPelletShape->mAnimatorB, mPelletShape->mAnimMgr, pelletMgr->mUfoMotionTable);
	_D8 = 0.0f;
	mAnimator.startMotion(PaniMotionInfo(0));
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void PlayerState::UfoParts::startMotion(int id)
{
	if (mPelletShape) {
		mAnimator.startMotion(PaniMotionInfo(id, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PlayerState::UfoParts::startMotion(int id1, int id2)
{
	if (mPelletShape) {
		mAnimator.startMotion(PaniMotionInfo(id1, this), PaniMotionInfo(id2));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PlayerState::UfoParts::stopMotion()
{
	_D8 = 30.0f;
}

/*
 * --INFO--
 * Address:	80080E00
 * Size:	0001F0
 */
void PlayerState::UfoParts::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	int anim     = mAnimator.mLowerAnimator.mMotionIdx;
	UfoItem* ufo = itemMgr->getUfo();

	switch (event.mEventType) {
	case KEY_LoopEnd:
		if (anim == 3) {
			switch (mModelID) {
			case 'uf01':
				ufo->playEventSound(ufo, SE_UFO_ANTENNA);
				break;
			case 'uf03':
				ufo->playEventSound(ufo, SE_UFO_SATELLITE);
				break;
			case 'ust1':
				break;
			}
		} else {
			ID32(mModelID).mStringID;
			switch (mModelID) {
			case 'ust5':
				ufo->playEventSound(ufo, SE_UFO_ENGINE);
			case 'uf01':
				ufo->playEventSound(ufo, SE_UFO_RADER);
				break;
			}
		}
		break;

	case KEY_Finished:
		startMotion(2, 2);
		_D8 = 30.0f;
		PRINT("*** AFTER MOTION START * (%s)\n", ID32(mModelID).mStringID);
		break;

	case KEY_PlayEffect:
		if (anim == 1) {
			PRINT("UFO PARTS * GOT EFFECT KEY : index=%d\n", event.mValue);
			switch (event.mValue) {
			case 0:
				effectMgr->create(EffectMgr::EFF_UfoPart_ASN01, _B8, nullptr, nullptr);
				PRINT("assign effect 01\n");
				break;
			case 1:
				effectMgr->create(EffectMgr::EFF_UfoPart_ASN02, _B8, nullptr, nullptr);
				PRINT("assign effect 02\n");
				break;
			}
		}
	}

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	80080FF0
 * Size:	0000D0
 */
void PlayerState::ufoAssignStart()
{
	UfoParts* parts = _14;
	if (!parts) {
		PRINT("after motion を再生すべき ?\n");
		return;
	}

	if (parts->mPelletShape->isMotionFlag(2)) {
		parts->startMotion(1, 3);
		parts->setMotionSpeed(30.0f);
	} else {
		parts->startMotion(1);
		parts->setMotionSpeed(30.0f);
	}
	_14 = nullptr;
}

/*
 * --INFO--
 * Address:	800810C0
 * Size:	000084
 */
void PlayerState::startSpecialMotions()
{
	startUfoPartsMotion('ust1', 4, false);
	startUfoPartsMotion('uf01', 4, false);
	startUfoPartsMotion('uf02', 4, false);
	startUfoPartsMotion('uf03', 4, false);
}

/*
 * --INFO--
 * Address:	80081144
 * Size:	0000C8
 */
void PlayerState::startAfterMotions()
{
	for (int i = 0; i < mTotalRegisteredParts; i++) {
		UfoParts* part = &mUfoParts[i];
		if (part && part->_DC && part->mPelletShape) {
			ID32 id(part->mModelID);
			PRINT("(%s) : AFTER motion \n", id.mStringID);
			part->startMotion(2, 2);
			part->setMotionSpeed(30.0f);
		}
	}
}

/*
 * --INFO--
 * Address:	8008120C
 * Size:	00010C
 */
void PlayerState::startUfoPartsMotion(u32 id, int anim, bool flag)
{
	UfoParts* parts = findUfoParts(id);
	if (parts) {
		if (parts->mPelletShape->isMotionFlag(2)) {
			if (flag) {
				parts->startMotion(anim, 3);
			} else {
				parts->startMotion(anim, anim);
			}
			parts->setMotionSpeed(30.0f);
		} else {
			parts->startMotion(anim);
			parts->setMotionSpeed(30.0f);
		}
	}
}

/*
 * --INFO--
 * Address:	80081318
 * Size:	000458
 */
void PlayerState::getUfoParts(u32 partID, bool flag)
{
	UfoParts* parts = findUfoParts(partID);
	if (!parts && !flag) {
		ID32 id(partID);
		u32 badCompiler;
		PRINT("parts %s is not registered !\n", id.mStringID);
		ERROR("sorry\n");
	}

	// check required part count
	if (partID != 'un04' && partID != 'un09' && partID != 'un10' && partID != 'un11' && partID != 'un14') {
		_180++;
	}

	switch (partID) {
	case 'uf01':
		mShipEffectPartFlag |= 1;
		for (int i = 0; i < 10; i++) {
			PRINT("U GOT RADAR !\n");
		}
		if (!hasRadar()) {
			ERROR("sonna!");
		}
		break;

	case 'uf10':
		mShipEffectPartFlag |= 2;
		for (int i = 0; i < 10; i++) {
			PRINT("U GOT LEFT HORN !\n");
		}
		if (!hasUfoLeftControl()) {
			ERROR("sonna!");
		}
		break;

	case 'uf11':
		mShipEffectPartFlag |= 4;
		for (int i = 0; i < 10; i++) {
			PRINT("U GOT RIGHT HORN !\n");
		}
		if (!hasUfoRightControl()) {
			ERROR("sonna!");
		}
		break;
	}

	_187[flowCont.mCurrentStage->mStageID]++;
	if (!flag) {
		parts->_DC = 1;
	} else {
		parts->_DC = 2;
	}
	mCurrParts++;
	PRINT("ufo parts %d/%d", _180, mCurrParts);
	for (int i = 0; i < 33; i++) {
		PRINT("ufoPartsCount = %d\n", mCurrParts);
	}

	if (mCurrParts >= AIConstant::_instance->mConstants._184()) {
		mShipUpgradeLevel = 5;
	} else if (mCurrParts >= AIConstant::_instance->mConstants._174()) {
		gameflow.mPlayState.openStage(4);
		playerState->mResultFlags.setSeen(RESFLAG_Collect15Parts);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 4 ***\n");
		}
		mShipUpgradeLevel = 4;
	} else if (mCurrParts >= AIConstant::_instance->mConstants._164()) {
		gameflow.mPlayState.openStage(3);
		playerState->mResultFlags.setOn(RESFLAG_UnlockYakushima);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 3 ***\n");
		}
		mShipUpgradeLevel = 3;
	} else if (mCurrParts >= AIConstant::_instance->mConstants._154()) {
		playerState->mResultFlags.setOn(RESFLAG_UnlockCave);
		gameflow.mPlayState.openStage(2);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 2 ***\n");
		}
		mShipUpgradeLevel = 2;
	} else if (mCurrParts >= 1) {
		gameflow.mPlayState.openStage(1);
		for (int i = 0; i < 10; i++) {
			PRINT("OPEN STAGE 1 ***\n");
		}
		mShipUpgradeLevel = 1;
	}

	if (flag) {
		_14 = nullptr;
	} else {
		_14 = parts;
	}

	if (mCurrParts >= 15) {
		playerState->mResultFlags.setOn(RESFLAG_Collect15Parts);
	}

	if (mCurrParts >= 11 && gameflow.mWorldClock.mCurrentDay - 1 >= 9) {
		playerState->mResultFlags.setOn(RESFLAG_Collect10Parts);
	}

	if (!flag) {
		if (parts->mPelletShape->isMotionFlag(2)) {
			parts->startMotion(1, 3);
			parts->setMotionSpeed(0.0f);
		} else {
			parts->startMotion(1);
			parts->setMotionSpeed(0.0f);
		}
	}

	if (mCurrParts == 29) {
		playerState->mResultFlags.setOn(RESFLAG_Collect29Parts);
		playerState->mResultFlags.setSeen(RESFLAG_Collect25Parts);
		playerState->mResultFlags.setSeen(RESFLAG_Collect15Parts);
	} else if (mCurrParts == 25) {
		playerState->mResultFlags.setOn(RESFLAG_Collect25Parts);
		playerState->mResultFlags.setSeen(RESFLAG_Collect15Parts);
	}

	PRINT("fake", mCurrParts ? "fake" : "fake");
}

/*
 * --INFO--
 * Address:	80081770
 * Size:	000058
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

/*
 * --INFO--
 * Address:	800817C8
 * Size:	000100
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

	int movies[5] = { 17, 18, 19, 25, 26 };
	if (level != mShipUpgradeLevel) {
		gameflow.mGameInterface->movie(movies[level - 1], 0, nullptr, nullptr, nullptr, -1, true);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void PlayerState::lostUfoParts(u32 partID)
{
	UfoParts* part = findUfoParts(partID);
	if (!part) {
		ID32 id(partID);
		PRINT("parts %s is not registered !\n", id.mStringID);
		ERROR("sorry\n");
	}
	part->_DC = 1;
}

/*
 * --INFO--
 * Address:	800818C8
 * Size:	00004C
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

/*
 * --INFO--
 * Address:	80081914
 * Size:	0002FC
 */
void PlayerState::renderParts(Graphics& gfx, Shape* shape)
{
	for (int i = 0; i < mTotalRegisteredParts; i++) {
		UfoParts* parts = &mUfoParts[i];
		if (parts->_DC == 1 && parts->mPartIndex != -1) {
			if (parts->mPelletShape == nullptr) {
				ID32 id(parts->mModelID);
				PRINT("++++ shapeObject for ufo parts %d is null (%s)\n", i, id.mStringID);
				ERROR("sorry\n");
			}

			if (AIPerf::kandoOnly) {
				char* names[] = { "carry", "assign", "after", "piston", "special", "6" };
				u32 badCompiler;
				ID32 id(parts->mModelID);
				PRINT("* parts(%s) : motion(%s) : (%.1f|%.1f) frame\n", names[parts->_DC], id.mStringID);
			}
			u32 badCompiler;
			parts->mAnimator.updateAnimation(parts->_D8, 30.0f);
			parts->mAnimator.updateContext();
			Matrix4f& temp = shape->getAnimMatrix(parts->mPartIndex);
			parts->_B8.set(0.0f, 0.0f, 0.0f);
			shape->calcJointWorldPos(gfx, parts->mPartIndex, parts->_B8);
			Matrix4f mtx = temp;
			parts->mPelletShape->mShape->updateAnim(gfx, mtx, nullptr);
			parts->mAnimatedMaterials.animate(nullptr);
			parts->mPelletShape->mShape->drawshape(gfx, *gfx.mCamera, &parts->mAnimatedMaterials);
		}
	}

	if (_1B4) {
		mPikiAnimMgr.updateAnimation(30.0f);
		mPikiAnimMgr.updateContext();
		Matrix4f& mtx = shape->getAnimMatrix(11);
		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, PI, 0.0f), Vector3f(0.0f, -10.0f, 0.0f));
		Matrix4f mtx3;
		mtx.multiplyTo(mtx2, mtx3);
		_C0->mShape->updateAnim(gfx, mtx3, nullptr);
		_C0->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
		_1C0.set(2.0f, 0.0f, 0.0f);
		_C0->mShape->calcJointWorldPos(gfx, 6, _1C0);
		_1B8->updatePos(_1C0);
		_1BC->updatePos(_1C0);
	}

	PRINT("fake", _1B4 ? "fake" : "fake");
	PRINT("fake", _1B4 ? "fake" : "fake");
	PRINT("fake", _1B4 ? "fake" : "fake");
}
