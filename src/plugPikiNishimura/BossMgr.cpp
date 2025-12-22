#include "Boss.h"
#include "CoreNucleus.h"
#include "DebugLog.h"
#include "Generator.h"
#include "King.h"
#include "Kogane.h"
#include "MemStat.h"
#include "Mizu.h"
#include "Nucleus.h"
#include "Pellet.h"
#include "PlayerState.h"
#include "Pom.h"
#include "RadarInfo.h"
#include "Slime.h"
#include "Snake.h"
#include "Spider.h"
#include "gameflow.h"
#include "sysNew.h"
#include "timers.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("BossMgr");

BossMgr* bossMgr;

Creature* BossMgr::getCreature(int bossID)
{
	int i, count = 0;

	for (i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
		BossNode* node = static_cast<BossNode*>(mActiveNodes[i].mChild);
		while (node) {
			if (count == bossID) {
				return node->mBoss;
			}

			node = static_cast<BossNode*>(node->mNext);
			count++;
		}
	}
	return nullptr;
}

int BossMgr::getFirst()
{
	return 0;
}

int BossMgr::getNext(int idx)
{
	return idx + 1;
}

bool BossMgr::isDone(int idx)
{
	if (idx >= getSize()) {
		return true;
	}

	return false;
}

int BossMgr::getSize()
{
	int i, count = 0;
	for (i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
		count += mActiveBossCounts[i];
	}

	return count;
}

int BossMgr::getMax()
{
	int i, max = 0;

	for (i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
		max += mInitialisedBossCounts[i];
	}
	return max;
}

BossMgr::BossMgr()
{
	mActiveBossCounts      = new int[BOSS_IDCOUNT];
	mInitialisedBossCounts = new int[BOSS_IDCOUNT];
	mActiveNodes           = new BossNode[BOSS_IDCOUNT];
	mFreeNodes             = new BossNode[BOSS_IDCOUNT];
	mAnimMgr               = new BossAnimationManager(this);
	mMotionTable           = PaniTekiAnimator::createMotionTable();
	mShapeObjects          = new BossShapeObject*[BOSS_IDCOUNT];
	mBossProps             = new BossProp*[BOSS_IDCOUNT];
	mUseCounts             = new int[BOSS_IDCOUNT];
	mSlimeCreatureCount    = 4;
	mForceUpdate           = true;

	for (int i = 0; i < BOSS_IDCOUNT; i++) {
		mActiveBossCounts[i]      = 0;
		mInitialisedBossCounts[i] = 0;
		mShapeObjects[i]          = nullptr;
		mBossProps[i]             = nullptr;
		mUseCounts[i]             = 0;
	}
}

void BossMgr::addUseCount(int bossID, int count)
{
	mUseCounts[bossID] += count;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
bool BossMgr::useBoss(int bossID)
{
	return mUseCounts[bossID] > 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
int BossMgr::getUseCount(int bossID)
{
	return mUseCounts[bossID];
}

void BossMgr::constructBoss()
{
	mForceUpdate = true;

	// SPIDER (Beady Long Legs)
	if (useBoss(BOSS_Spider)) {
		memStat->start("spider shape");
		Shape* shape = gameflow.loadShape("bosses/kumo/kumo.mod", true);
		memStat->end("spider shape");

		memStat->start("spider anim");
		mShapeObjects[BOSS_Spider] = new BossShapeObject(shape, "kumo");
		memStat->end("spider anim");

		memStat->start("spider rest");
		mBossProps[BOSS_Spider] = new SpiderProp();
		static_cast<SpiderProp*>(mBossProps[BOSS_Spider])->load("bosses/kumo/", "parms.bin", 1);
		init(BOSS_Spider, getUseCount(BOSS_Spider));
		memStat->end("spider rest");
	}

	// SNAKE (Snagret)
	if (useBoss(BOSS_Snake) || useBoss(BOSS_BoxSnake)) {
		memStat->start("snake shape");
		Shape* shape = gameflow.loadShape("bosses/snake/snake.mod", true);
		memStat->end("snake shape");

		memStat->start("snake anim");
		mShapeObjects[BOSS_Snake] = new BossShapeObject(shape, "snake");
		memStat->end("snake anim");

		memStat->start("snake rest");
		mBossProps[BOSS_Snake] = new SnakeProp();
		static_cast<SnakeProp*>(mBossProps[BOSS_Snake])->load("bosses/snake/", "parms.bin", 1);

		mShapeObjects[BOSS_BoxSnake] = mShapeObjects[BOSS_Snake];
		mBossProps[BOSS_BoxSnake]    = mBossProps[BOSS_Snake];

		if (useBoss(BOSS_Snake)) {
			init(BOSS_Snake, getUseCount(BOSS_Snake));
		}
		if (useBoss(BOSS_BoxSnake)) {
			init(BOSS_BoxSnake, getUseCount(BOSS_BoxSnake));
		}
		memStat->end("snake rest");
	}

	// SLIME (Goolix)
	if (useBoss(BOSS_Slime)) {
		// WHOLE SLIME
		memStat->start("slime shape");
		Shape* slimeShape = gameflow.loadShape("bosses/slime/slime.mod", true);
		memStat->end("slime shape");

		memStat->start("slime anim");
		mShapeObjects[BOSS_Slime] = new BossShapeObject(slimeShape, "slime");
		memStat->end("slime anim");

		memStat->start("slime rest");
		mBossProps[BOSS_Slime] = new SlimeProp();
		static_cast<SlimeProp*>(mBossProps[BOSS_Slime])->load("bosses/slime/", "parms.bin", 1);
		memStat->end("slime rest");

		// NUCLEUS
		memStat->start("nucleus shape");
		Shape* nucleusShape = gameflow.loadShape("bosses/nucleus/nucleus.mod", true);
		memStat->end("nucleus shape");

		memStat->start("nucleus anim");
		mShapeObjects[BOSS_Nucleus] = new BossShapeObject(nucleusShape, "nucleus");
		memStat->end("nucleus anim");

		memStat->start("nucleus rest");
		mBossProps[BOSS_Nucleus] = new NucleusProp();
		static_cast<NucleusProp*>(mBossProps[BOSS_Nucleus])->load("bosses/nucleus/", "parms.bin", 1);
		memStat->end("nucleus rest");

		// CORE NUCLEUS
		memStat->start("core nucleus shape");
		Shape* coreShape = gameflow.loadShape("bosses/core/core.mod", true);
		memStat->end("core nucleus shape");

		memStat->start("core nucleus anim");
		mShapeObjects[BOSS_CoreNucleus] = new BossShapeObject(coreShape, "core");
		memStat->end("core nucleus anim");

		memStat->start("core nucleus rest");
		mBossProps[BOSS_CoreNucleus] = new CoreNucleusProp();
		static_cast<CoreNucleusProp*>(mBossProps[BOSS_CoreNucleus])->load("bosses/core/", "parms.bin", 1);
		memStat->end("core nucleus rest");

		// This is not really a bug, but it is a baffling decision that causes unexpected behavior.  The Goolix has issues
		// drawing correctly when more than one exists at a time (see `SlimeBody::setSpherePosition`), so that's probably
		// why it is restricted to just one here.  Still, you could also just not spawn more than one Goolix.  Silly devs...
		init(BOSS_Slime, TERNARY_BUGFIX(getUseCount(BOSS_Slime), 1));
	}

	// KING (Emperor Bulblax)
	if (useBoss(BOSS_King)) {
		memStat->start("king shape");
		Shape* shape = gameflow.loadShape("bosses/king/king.mod", true);
		memStat->end("king shape");

		memStat->start("king anim");
		mShapeObjects[BOSS_King] = new BossShapeObject(shape, "king");
		memStat->end("king anim");

		memStat->start("king rest");
		mBossProps[BOSS_King] = new KingProp();
		static_cast<KingProp*>(mBossProps[BOSS_King])->load("bosses/king/", "parms.bin", 1);
		init(BOSS_King, getUseCount(BOSS_King));
		memStat->end("king rest");
	}

	// KOGANE (Iridescent Flint Beetle)
	if (useBoss(BOSS_Kogane)) {
		memStat->start("kogane shape");
		Shape* shape = gameflow.loadShape("bosses/kogane/kogane.mod", true);
		memStat->end("kogane shape");

		memStat->start("kogane anim");
		mShapeObjects[BOSS_Kogane] = new BossShapeObject(shape, "kogane");
		memStat->end("kogane anim");

		memStat->start("kogane rest");
		mBossProps[BOSS_Kogane] = new KoganeProp();
		static_cast<KoganeProp*>(mBossProps[BOSS_Kogane])->load("bosses/kogane/", "parms.bin", 1);
		init(BOSS_Kogane, getUseCount(BOSS_Kogane));
		memStat->end("kogane rest");
	}

	// POM (Candypop Bud)
	if (useBoss(BOSS_Pom)) {
		memStat->start("pom shape");
		Shape* shape = gameflow.loadShape("bosses/pom/pom.mod", true);
		memStat->end("pom shape");

		memStat->start("pom anim");
		mShapeObjects[BOSS_Pom] = new BossShapeObject(shape, "pom");
		memStat->end("pom anim");

		memStat->start("pom rest");
		mBossProps[BOSS_Pom] = new PomProp();
		static_cast<PomProp*>(mBossProps[BOSS_Pom])->load("bosses/pom/", "parms.bin", 1);
		init(BOSS_Pom, getUseCount(BOSS_Pom));
		memStat->end("pom rest");
	}

	// KINGBACK (unused)
	if (useBoss(BOSS_KingBack)) {
		memStat->start("king back shape");
		Shape* shape = gameflow.loadShape("bosses/kingback/kingback.mod", true);
		memStat->end("king back shape");

		memStat->start("king back anim");
		mShapeObjects[BOSS_KingBack] = new BossShapeObject(shape, "kingback");
		memStat->end("king back anim");

		memStat->start("king back rest");
		mBossProps[BOSS_KingBack] = new KingBackProp();
		static_cast<KingBackProp*>(mBossProps[BOSS_KingBack])->load("bosses/kingback/", "parms.bin", 1);
		init(BOSS_KingBack, getUseCount(BOSS_KingBack));
		memStat->end("king back rest");
	}

	// MIZU (Water Geyzer)
	if (useBoss(BOSS_Mizu) || useBoss(BOSS_Geyzer)) {
		memStat->start("mizu shape");
		Shape* shape = gameflow.loadShape("bosses/mizu/mizu.mod", true);
		memStat->end("mizu shape");

		memStat->start("mizu anim");
		mShapeObjects[BOSS_Mizu] = new BossShapeObject(shape, "mizu");
		memStat->end("mizu anim");

		memStat->start("mizu rest");
		mBossProps[BOSS_Mizu] = new MizuProp();
		static_cast<MizuProp*>(mBossProps[BOSS_Mizu])->load("bosses/mizu/", "parms.bin", 1);

		mShapeObjects[BOSS_Geyzer] = mShapeObjects[BOSS_Mizu];
		mBossProps[BOSS_Geyzer]    = mBossProps[BOSS_Mizu];

		if (useBoss(BOSS_Mizu)) {
			init(BOSS_Mizu, getUseCount(BOSS_Mizu));
		}
		if (useBoss(BOSS_Geyzer)) {
			init(BOSS_Geyzer, getUseCount(BOSS_Geyzer));
		}
		memStat->end("mizu rest");
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void BossMgr::animatorInit(Boss* boss)
{
	if (boss->mShapeObject) {
		boss->mAnimator.init(&boss->mShapeObject->mAnimContext, boss->mShapeObject->mAnimMgr, mMotionTable);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void BossMgr::initSpider(int count)
{
	for (int i = 0; i < count; i++) {
		Spider* spider = new Spider(mBossProps[BOSS_Spider]);
		BossNode* node = new BossNode(spider);
		mFreeNodes[BOSS_Spider].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initSnake(int count)
{
	for (int i = 0; i < count; i++) {
		Snake* snake   = new Snake(mBossProps[BOSS_Snake]);
		BossNode* node = new BossNode(snake);
		mFreeNodes[BOSS_Snake].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initBoxSnake(int count)
{
	for (int i = 0; i < count; i++) {
		Snake* snake   = new Snake(mBossProps[BOSS_BoxSnake]);
		BossNode* node = new BossNode(snake);
		mFreeNodes[BOSS_BoxSnake].add(node);
	}
}

void BossMgr::initSlime(int count)
{
	for (int i = 0; i < count; i++) {
		Slime* slime        = new Slime(mBossProps[BOSS_Slime], getBossShapeObject(BOSS_Slime));
		BossNode* slimeNode = new BossNode(slime);
		mFreeNodes[BOSS_Slime].add(slimeNode);

		Nucleus* nucleus      = new Nucleus(mBossProps[BOSS_Nucleus]);
		BossNode* nucleusNode = new BossNode(nucleus);
		mFreeNodes[BOSS_Nucleus].add(nucleusNode);

		CoreNucleus* core  = new CoreNucleus(mBossProps[BOSS_CoreNucleus]);
		BossNode* coreNode = new BossNode(core);
		mFreeNodes[BOSS_CoreNucleus].add(coreNode);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initKing(int count)
{
	for (int i = 0; i < count; i++) {
		King* king     = new King(mBossProps[BOSS_King]);
		BossNode* node = new BossNode(king);
		mFreeNodes[BOSS_King].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initKogane(int count)
{
	for (int i = 0; i < count; i++) {
		Kogane* kogane = new Kogane(mBossProps[BOSS_Kogane]);
		BossNode* node = new BossNode(kogane);
		mFreeNodes[BOSS_Kogane].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initPom(int count)
{
	for (int i = 0; i < count; i++) {
		Pom* pom       = new Pom(mBossProps[BOSS_Pom]);
		BossNode* node = new BossNode(pom);
		mFreeNodes[BOSS_Pom].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initKingBack(int count)
{
	for (int i = 0; i < count; i++) {
		KingBack* kingBack = new KingBack(mBossProps[BOSS_KingBack]);
		BossNode* node     = new BossNode(kingBack);
		mFreeNodes[BOSS_KingBack].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initMizu(int count)
{
	for (int i = 0; i < count; i++) {
		Mizu* mizu     = new Mizu(mBossProps[BOSS_Mizu]);
		BossNode* node = new BossNode(mizu);
		mFreeNodes[BOSS_Mizu].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initGeyzer(int count)
{
	for (int i = 0; i < count; i++) {
		Mizu* geyzer   = new Mizu(mBossProps[BOSS_Geyzer]);
		BossNode* node = new BossNode(geyzer);
		mFreeNodes[BOSS_Geyzer].add(node);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void BossMgr::setBossParam(Boss* boss, GenObjectBoss* genBoss)
{
	boss->setItemCount(genBoss->mItemCount);
	boss->setItemIndex(genBoss->mItemIndex);
	boss->setItemColour(genBoss->mItemColour);

	PelletConfig* config = pelletMgr->getConfigFromIdx(genBoss->mPelletConfigIdx);
	if (config) {
		boss->mPelletID.mId = config->mModelId.mId;
	} else {
		boss->mPelletID.mId = 'none';
	}

	if (Pellet::isUfoPartsID(boss->mPelletID.mId)) {
		radarInfo->attachParts(boss);
		pelletMgr->addUseList(boss->mPelletID.mId);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
Boss* BossMgr::createBoss(int bossID)
{
	BossNode* node = static_cast<BossNode*>(mFreeNodes[bossID].mChild);
	if (!node) {
		return nullptr;
	}

	mActiveBossCounts[bossID]++;
	node->del();
	mActiveNodes[bossID].add(node);
	Boss* boss         = node->mBoss;
	boss->mShapeObject = getBossShapeObject(bossID);
	animatorInit(boss);
	boss->mCollInfo->initInfo(boss->mShapeObject->mShape, nullptr, nullptr);
	return boss;
}

void BossMgr::init(int bossID, int count)
{
	if (bossID >= BOSS_IDCOUNT || bossID < BOSS_IDSTART || count <= 0) {
		return;
	}

	switch (bossID) {
	case BOSS_Spider:
		initSpider(count);
		break;
	case BOSS_Snake:
		initSnake(count);
		break;
	case BOSS_BoxSnake:
		initBoxSnake(count);
		break;
	case BOSS_Slime:
		initSlime(count);
		break;
	case BOSS_King:
		initKing(count);
		break;
	case BOSS_Kogane:
		initKogane(count);
		break;
	case BOSS_Pom:
		initPom(count);
		break;
	case BOSS_KingBack:
		initKingBack(count);
		break;
	case BOSS_Mizu:
		initMizu(count);
		break;
	case BOSS_Geyzer:
		initGeyzer(count);
		break;
	}

	mInitialisedBossCounts[bossID] = count;
}

Creature* BossMgr::create(int genBossID, BirthInfo& birthInfo, GenObjectBoss* genBoss)
{
	Boss* boss = nullptr;
	switch (genBossID) {
	case GENBOSS_Spider:
		boss = createBoss(BOSS_Spider);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_Spider);
			boss->init(birthInfo.mPosition);
			setBossParam(boss, genBoss);
		}
		break;

	case GENBOSS_Snake:
		boss = createBoss(BOSS_Snake);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_Snake);
			boss->init(birthInfo.mPosition);
			setBossParam(boss, genBoss);
		}
		break;

	case GENBOSS_BoxSnake:
		boss = createBoss(BOSS_BoxSnake);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_Snake);
			boss->init(birthInfo.mPosition);
			setBossParam(boss, genBoss);
			static_cast<Snake*>(boss)->setBossType(false);
		}
		break;

	case GENBOSS_Slime:
		boss = createBoss(BOSS_Slime);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_Slime);
			boss->init(birthInfo.mPosition);
			setBossParam(boss, genBoss);

			// also make the nuclei
			Boss* nucleus = createBoss(BOSS_Nucleus);
			nucleus->initBoss(birthInfo, OBJTYPE_Nucleus);
			nucleus->init(birthInfo.mPosition);
			static_cast<Slime*>(boss)->mNucleus    = static_cast<Nucleus*>(nucleus);
			static_cast<Nucleus*>(nucleus)->mSlime = static_cast<Slime*>(boss);

			nucleus = createBoss(BOSS_CoreNucleus);
			nucleus->initBoss(birthInfo, OBJTYPE_Nucleus);
			nucleus->init(birthInfo.mPosition);
			static_cast<Slime*>(boss)->mCore           = static_cast<CoreNucleus*>(nucleus);
			static_cast<CoreNucleus*>(nucleus)->mSlime = static_cast<Slime*>(boss);
		}
		break;

	case GENBOSS_King:
		boss = createBoss(BOSS_King);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_King);
			boss->init(birthInfo.mPosition);
			setBossParam(boss, genBoss);
		}
		break;

	case GENBOSS_Kogane:
		boss = createBoss(BOSS_Kogane);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_Kogane);
			boss->init(birthInfo.mPosition);
			setBossParam(boss, genBoss);
		}
		break;

	case GENBOSS_Pom:
		if (playerState->hasContainer(genBoss->mItemColour)) {
			boss = createBoss(BOSS_Pom);
			if (boss) {
				boss->initBoss(birthInfo, OBJTYPE_Pom);
				boss->init(birthInfo.mPosition);
				setBossParam(boss, genBoss);
				static_cast<Pom*>(boss)->setColor(genBoss->mItemColour);
			}
		}
		break;

	case GENBOSS_KingBack:
		boss = createBoss(BOSS_KingBack);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_KingBack);
			boss->init(birthInfo.mPosition);
			setBossParam(boss, genBoss);
		}
		break;

	case GENBOSS_Mizu:
		boss = createBoss(BOSS_Mizu);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_Mizu);
			static_cast<Mizu*>(boss)->initMizu(birthInfo.mPosition);
			setBossParam(boss, genBoss);
		}
		break;
	case GENBOSS_Geyzer:
		boss = createBoss(BOSS_Geyzer);
		if (boss) {
			boss->initBoss(birthInfo, OBJTYPE_Mizu);
			static_cast<Mizu*>(boss)->initGeyzer(birthInfo.mPosition);
			setBossParam(boss, genBoss);
		}
		break;
	}

	return boss;
}

void BossMgr::kill(Creature* target)
{
	for (int i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
		FOREACH_NODE(CoreNode, mActiveNodes[i].mChild, node)
		{
			BossNode* bNode = static_cast<BossNode*>(node);
			if (target == bNode->mBoss) {
				mActiveBossCounts[i]--;
				bNode->del();
				mFreeNodes[i].add(bNode);
				bNode->mBoss->kill(false);
				return;
			}
		}
	}
}

void BossMgr::killAll()
{
	CoreNode* node;
	CoreNode* next;

	for (int i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {

		node = mActiveNodes[i].mChild;
		while (node) {
			BossNode* bNode = static_cast<BossNode*>(node);
			next            = node->mNext;

			mActiveBossCounts[i]--;
			bNode->del();
			mFreeNodes[i].add(bNode);
			bNode->mBoss->kill(true);
			bNode->mBoss->exitCourse();
			node = next;
		}
	}
}

void BossMgr::update()
{
	gsys->mTimer->start("boss updt", true);
	if (mForceUpdate) {
		for (int i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
			FOREACH_NODE(BossNode, mActiveNodes[i].mChild, node)
			{
				node->mBoss->updateBoss();
				node->mBoss->update();
			}
		}

	} else {
		BossNode* next;
		int i;
		BossNode* node;
		for (i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
			node = static_cast<BossNode*>(mActiveNodes[i].mChild);
			while (node) {
				next = static_cast<BossNode*>(node->mNext);

				node->mBoss->updateBoss();
				if (C_BOSS_PROP(node->mBoss)._1DC() == 0 || !node->mBoss->mGrid.aiCulling() || node->mBoss->aiCullable()) {
					node->mBoss->update();
				}

				node = next;
			}
		}
	}
	gsys->mTimer->stop("boss updt");
}

void BossMgr::refresh(Graphics& gfx)
{
	gsys->mTimer->start("boss draw", true);
	if (mForceUpdate) {
		for (int i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
			FOREACH_NODE(BossNode, mActiveNodes[i].mChild, node)
			{
				node->mBoss->refresh(gfx);
				node->mBoss->drawShape(gfx);
			}
		}

		mForceUpdate = false;

	} else {
		for (int i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
			FOREACH_NODE(BossNode, mActiveNodes[i].mChild, node)
			{
				node->mBoss->refreshViewCulling(gfx);
				if (C_BOSS_PROP(node->mBoss)._1DC() == 0 || !node->mBoss->mGrid.aiCulling() || node->mBoss->aiCullable()) {
					node->mBoss->refresh(gfx);
				}

				if (node->mBoss->aiCullable()) {
					node->mBoss->drawShape(gfx);
				}
			}
		}
	}
	gsys->mTimer->stop("boss draw");
}

void BossMgr::refresh2d(Graphics& gfx)
{
	for (int i = BOSS_IDSTART; i < BOSS_IDCOUNT; i++) {
		FOREACH_NODE(BossNode, mActiveNodes[i].mChild, node)
		{
			if (node->mBoss->aiCullable()) {
				node->mBoss->refresh2d(gfx);
			}
		}
	}
}

void BossMgr::finalSetup()
{
	mForceUpdate = true;
}

BossShapeObject* BossMgr::getBossShapeObject(int bossID)
{
	return mShapeObjects[bossID];
}
