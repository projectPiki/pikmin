#include "ItemMgr.h"
#include "gameflow.h"
#include "Shape.h"
#include "BuildingItem.h"
#include "Interactions.h"
#include "PikiHeadItem.h"
#include "GoalItem.h"
#include "UfoItem.h"
#include "KusaItem.h"
#include "FishItem.h"
#include "ItemObject.h"
#include "BombItem.h"
#include "MizuItem.h"
#include "SeedItem.h"
#include "KeyItem.h"
#include "GemItem.h"
#include "DoorItem.h"
#include "MemStat.h"
#include "BaseInf.h"
#include "RopeCreature.h"
#include "GameCoreSection.h"
#include "ItemAI.h"
#include "WeedsItem.h"
#include "AIConstant.h"
#include "sysNew.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "RumbleMgr.h"
#include "GameStat.h"
#include "Pcam/CameraManager.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(45)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("itemMgr")

bool PikiHeadMgr::buryMode;
ItemMgr* itemMgr;

/*
 * --INFO--
 * Address:	800F2978
 * Size:	000040
 */
bool BuildingItem::insideSafeArea(Vector3f& pos)
{
	f32 z = pos.z - mPosition.z;
	f32 x = pos.x - mPosition.x;
	if (SQUARE(x) + SQUARE(z) < 10000.0f) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800F29B8
 * Size:	00013C
 */
GoalItem* ItemMgr::getContainer(int color)
{
	if (!mMeltingPotMgr) {
		return nullptr;
	}
	Iterator iter(mMeltingPotMgr);
	CI_LOOP(iter)
	{
		Creature* creature = *iter;
		if (creature->mObjType == OBJTYPE_Goal) {
			GoalItem* goal = static_cast<GoalItem*>(creature);
			if (goal->mOnionColour == color) {
				return goal;
			}
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800F2AF4
 * Size:	000144
 */
GoalItem* ItemMgr::getNearestContainer(Vector3f& pos, f32 radius)
{
	MeltingPotMgr* mgr = mMeltingPotMgr;

	f32 minDist    = radius;
	GoalItem* goal = nullptr;
	Iterator iter(mgr);
	CI_LOOP(iter)
	{
		Creature* creature = *iter;
		if (creature->mObjType == OBJTYPE_Goal) {
			GoalItem* newGoal = static_cast<GoalItem*>(creature);
			f32 dist          = qdist2(creature->mPosition.x, creature->mPosition.z, pos.x, pos.z);
			if (dist < minDist) {
				minDist = dist;
				goal    = newGoal;
			}
		}
	}

	return goal;
}

/*
 * --INFO--
 * Address:	800F2C38
 * Size:	000114
 */
UfoItem* ItemMgr::getUfo()
{
	Iterator iter(getMeltingPotMgr());
	CI_LOOP(iter)
	{
		Creature* creature = *iter;
		if (creature->mObjType == OBJTYPE_Ufo) {
			return static_cast<UfoItem*>(creature);
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
ItemShapeObject::ItemShapeObject(Shape* shape, char* objName, char* file)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;
	char buf[128];
	if (objName) {
		sprintf(buf, "objects/%s/%s", objName, file);
		mAnimMgr        = new AnimMgr(shape, buf, ANIMMGR_LOAD_BUNDLE, nullptr);
		mAnimMgr->mName = objName;
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, ANIMMGR_LOAD_NOSKIP, nullptr);
	}
	mShape->overrideAnim(0, &mAnimContext);
}

/*
 * --INFO--
 * Address:	800F2D4C
 * Size:	0003C0
 */
MeltingPotMgr::MeltingPotMgr(ItemMgr* mgr)
{
	mItemMgr   = mgr;
	mGoalProps = new GoalItemProp();
	mGoalAI    = new GoalAI();
	mUfoProps  = new UfoItemProp();

	mSluiceAI    = nullptr;
	mBouShape    = nullptr;
	mKusaProps   = nullptr;
	mBuildProps  = nullptr;
	mBoBaseShape = nullptr;
}

/*
 * --INFO--
 * Address:	800F310C
 * Size:	000160
 */
void MeltingPotMgr::finalSetup()
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		Creature* creature = *iter;
		if (creature->isSluice()) {
			BuildingItem* goal = static_cast<BuildingItem*>(creature);
			goal->finalSetup();
		}
	}
}

/*
 * --INFO--
 * Address:	800F326C
 * Size:	000374
 */
void MeltingPotMgr::prepare(int objType)
{
	switch (objType) {
	case OBJTYPE_SluiceSoft:
	case OBJTYPE_SluiceHard:
	case OBJTYPE_SluiceBomb:
	case OBJTYPE_SluiceBombHard:
		if (!mSluiceAI) {
			mSluiceAI = new SluiceAI();
		}
		if (!mBuildProps) {
			mBuildProps = new BuildingItemProp();
		}
		break;
	case OBJTYPE_Kusa:
		if (!mBouShape) {
			mBouShape = static_cast<Shape*>(gameflow.loadShape("objects/rope/bou.mod", true));
		}
		if (!mBoBaseShape) {
			mBoBaseShape = static_cast<Shape*>(gameflow.loadShape("objects/rope/bobase.mod", true));
		}
		if (!mKusaProps) {
			mKusaProps = new KusaItemProp();
		}
		break;
	case OBJTYPE_Rocket:
	case OBJTYPE_SunsetStart:
	case OBJTYPE_SunsetGoal:
		break;
	}
}

/*
 * --INFO--
 * Address:	800F35E0
 * Size:	0002BC
 */
Creature* MeltingPotMgr::birth(int objType)
{
	Creature* creature = nullptr;
	switch (objType) {
	case OBJTYPE_Fish:
		creature = new FishGenerator();
		break;
	case OBJTYPE_Goal:
		creature = new GoalItem(mGoalProps, mItemMgr->mItemShapes[7], mItemMgr->mItemShapes[7], mItemMgr->mItemShapes[7], mGoalAI);
		break;
	case OBJTYPE_Ufo:
		creature = new UfoItem(mUfoProps, mItemMgr->mUfoShape);
		break;
	case OBJTYPE_Kusa:
		creature = new KusaItem(mKusaProps, mBouShape);
		break;
	case OBJTYPE_BoBase:
		creature = new BoBaseItem(mKusaProps, mBoBaseShape);
		break;
	case OBJTYPE_SluiceSoft:
		creature = new BuildingItem(objType, mBuildProps, mItemMgr->mItemShapes[8], mSluiceAI);
		break;
	case OBJTYPE_SluiceHard:
		creature = new BuildingItem(objType, mBuildProps, mItemMgr->mItemShapes[8], mSluiceAI);
		break;
	case OBJTYPE_SluiceBomb:
		creature = new BuildingItem(objType, mBuildProps, mItemMgr->mItemShapes[9], mSluiceAI);
		break;
	case OBJTYPE_SluiceBombHard:
		creature = new BuildingItem(objType, mBuildProps, mItemMgr->mItemShapes[9], mSluiceAI);
		break;
	case OBJTYPE_RockGen:
		creature = new RockGen(nullptr, nullptr);
		break;
	case OBJTYPE_GrassGen:
		creature = new GrassGen(nullptr, nullptr);
		break;
	}

	CreatureNode* node = new CreatureNode();
	node->mCreature    = creature;
	mRootNode.add(node);
	return creature;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
ObjectMgr* ItemMgr::getMgr(int)
{

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
int ItemMgr::getPikiNum()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
bool ItemMgr::useObjType(int type)
{
	FOREACH_NODE(UseNode, mRootUseNode.mChild, node)
	{
		if (node->mType == type) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	800F389C
 * Size:	0000F4
 */
void ItemMgr::addUseList(int type)
{
	if (!useObjType(type)) {
		UseNode* newNode = new UseNode();
		newNode->mType   = type;
		mRootUseNode.add(newNode);
	}
}

/*
 * --INFO--
 * Address:	800F3990
 * Size:	0009D8
 */
ItemMgr::ItemMgr()
    : PolyObjectMgr(30)
{
	PikiHeadMgr::buryMode = false;
	gameflow.addGenNode("itemMgr", this);
	mItemMotionTable = PaniItemAnimator::createMotionTable();
	mItemShapes      = new ItemShapeObject*[11];
	mUfoMotionTable  = PaniUfoAnimator::createMotionTable();

	for (int i = 0; i < 11; i++) {
		mItemShapes[i] = nullptr;
	}

	create(96);

	addUseList(OBJTYPE_Goal);
	addUseList(OBJTYPE_Ufo);
	addUseList(OBJTYPE_Pikihead);
	addUseList(OBJTYPE_Bomb);
	addUseList(OBJTYPE_Water);
	addUseList(OBJTYPE_FallWater);
	addUseList(OBJTYPE_Rope);
	addUseList(OBJTYPE_Fulcrum);
	addUseList(OBJTYPE_Seed);
	addUseList(OBJTYPE_Key);
	addUseList(OBJTYPE_Door);
	addUseList(OBJTYPE_Gate);
	addUseList(OBJTYPE_BombGen);

	mUfoShape = new UfoShapeObject(gameflow.loadShape("objects/ufo/ufo0705.mod", true));

	mPebbleShapeList[0] = gameflow.loadShape("objects/weeds/stone1.mod", true);
	mPebbleShapeList[1] = gameflow.loadShape("objects/weeds/stone2.mod", true);
	mPebbleShapeList[2] = gameflow.loadShape("objects/weeds/stone3.mod", true);
	mGrassShapeList[0]  = gameflow.loadShape("objects/weeds/weed1.mod", true);
	mGrassShapeList[1]  = gameflow.loadShape("objects/weeds/weed1.mod", true);
	mGrassShapeList[2]  = gameflow.loadShape("objects/weeds/weed1.mod", true);

	mMeltingPotMgr = nullptr;
	mPikiHeadMgr   = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ItemMgr::showInfo()
{
	PRINT("%s * size is %d\n", "NaviDemoSunsetStart", sizeof(NaviDemoSunsetStart));
	PRINT("%s * size is %d\n", "NaviDemoSunsetGoal", sizeof(NaviDemoSunsetGoal));
	PRINT("%s * size is %d\n", "PikiHeadItem", sizeof(PikiHeadItem));
	PRINT("%s * size is %d\n", "BombItem", sizeof(BombItem));
	PRINT("%s * size is %d\n", "MizuItem", sizeof(MizuItem));
	PRINT("%s * size is %d\n", "RopeItem", sizeof(RopeItem));
	PRINT("%s * size is %d\n", "Fulcrum", sizeof(Fulcrum));
	PRINT("%s * size is %d\n", "SeedItem", sizeof(SeedItem));
	PRINT("%s * size is %d\n", "KeyItem", sizeof(KeyItem));
	PRINT("%s * size is %d\n", "DoorItem", sizeof(DoorItem));
	PRINT("%s * size is %d\n", "UfoItem", sizeof(UfoItem));
	PRINT("%s * size is %d\n", "KusaItem", sizeof(KusaItem));
	PRINT("%s * size is %d\n", "BuildingItem", sizeof(BuildingItem));
	PRINT("%s * size is %d\n", "GoalItem", sizeof(GoalItem));
}

/*
 * --INFO--
 * Address:	800F4368
 * Size:	000008
 */
ItemShapeObject* ItemMgr::getPelletShapeObject(int, int)
{
	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
Shape* ItemMgr::getUfoShape()
{
	if (mUfoShape) {
		return mUfoShape->mShape;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800F4370
 * Size:	00153C
 */
void ItemMgr::initialise()
{
	mMeltingPotMgr = new MeltingPotMgr(this);

	beginRegister();

	registerClass(OBJTYPE_SunsetStart, new NaviDemoSunsetStart(), sizeof(NaviDemoSunsetStart));
	registerClass(OBJTYPE_SunsetGoal, new NaviDemoSunsetGoal(), sizeof(NaviDemoSunsetGoal));

	mItemShapes[3] = new ItemShapeObject(gameflow.loadShape("objects/pikihead/pikihead.mod", true), "pikihead", "anims.bin");

	mItemShapes[2] = new ItemShapeObject(gameflow.loadShape("objects/bomb/bomb.mod", true), "bomb", "anims.bin");
	registerClass(OBJTYPE_Bomb, new BombItem(new BombItemProp(), mItemShapes[2], new BombAI()), sizeof(BombItem));

	MizuItemProp* mizuProp = new MizuItemProp();
	WaterAI* mizuAI        = new WaterAI();
	mItemShapes[0]         = new ItemShapeObject(gameflow.loadShape("objects/water/water.mod", true), "water", "anims.bin");
	registerClass(OBJTYPE_Water, new MizuItem(OBJTYPE_Water, mizuProp, mItemShapes[0], mizuAI), sizeof(MizuItem));

	FallWaterAI* fwAI = new FallWaterAI();
	mItemShapes[1]    = new ItemShapeObject(gameflow.loadShape("objects/fl_water/fl_water.mod", true), "fl_water", "anims.bin");
	registerClass(OBJTYPE_FallWater, new MizuItem(OBJTYPE_FallWater, mizuProp, mItemShapes[1], fwAI), sizeof(MizuItem));

	// seems like these got initialised, but then their definitions got commented out? they're still used
	Shape* gateShape;
	Shape* doorShape;
	Shape* keyShape;
#if 0
	gateShape = loadShape("objects/door.mod", true);
	doorShape = loadShape("objects/door.mod", true);
	keyShape  = loadShape("objects/key.mod", true);
#endif

	Shape* seedShapes[2];
	seedShapes[0] = gameflow.loadShape("pikis/happas/leaf.mod", true);
	seedShapes[1] = gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
#if 0 // DLL only:
	gameflow.loadShape("shapes/arrow.mod", true);
	gameflow.loadShape("shapes/oldMarkr.mod", true);
#endif

	registerClass(OBJTYPE_Rope, new RopeItem(new RopeProp(), nullptr), sizeof(RopeItem));

	registerClass(OBJTYPE_Fulcrum, new Fulcrum(), sizeof(Fulcrum));

	registerClass(OBJTYPE_Seed, new SeedItem(new SeedProp(), seedShapes), sizeof(SeedItem));

	registerClass(OBJTYPE_Key, new KeyItem(new KeyProp(), keyShape), sizeof(KeyItem));

	registerClass(OBJTYPE_Door, new DoorItem(OBJTYPE_Door, new DoorProp(), doorShape), sizeof(DoorItem));
	registerClass(OBJTYPE_Gate, new DoorItem(OBJTYPE_Gate, new DoorProp(), gateShape), sizeof(DoorItem));
	registerClass(OBJTYPE_BombGen, new BombGenItem(nullptr), sizeof(BombGenItem));

	if (useObjType(OBJTYPE_Kusa)) {
		registerClass(OBJTYPE_Kusa, nullptr, 0);
		mMeltingPotMgr->prepare(OBJTYPE_Kusa);
	} else {
		registerClass(OBJTYPE_Kusa, nullptr, 0);
	}

	registerClass(OBJTYPE_BoBase, nullptr, 0);
	registerClass(OBJTYPE_RockGen, nullptr, 0);
	registerClass(OBJTYPE_GrassGen, nullptr, 0);

	memStat->start("sluice shape");

	if (useObjType(OBJTYPE_SluiceSoft)) {
		mItemShapes[8] = new ItemShapeObject(gameflow.loadShape("objects/gate/gt_soft.mod", true), "gate", "gate.bin");
		registerClass(OBJTYPE_SluiceSoft, nullptr, 0);
		mMeltingPotMgr->prepare(OBJTYPE_SluiceSoft);
	} else {
		registerClass(OBJTYPE_SluiceSoft, nullptr, 0);
	}

	if (useObjType(OBJTYPE_SluiceHard)) {
		mMeltingPotMgr->prepare(OBJTYPE_SluiceHard);
		registerClass(OBJTYPE_SluiceHard, nullptr, 0);
	} else {
		registerClass(OBJTYPE_SluiceHard, nullptr, 0);
	}

	if (useObjType(OBJTYPE_SluiceBomb)) {
		mItemShapes[9] = new ItemShapeObject(gameflow.loadShape("objects/gate/gt_hard.mod", true), "gate", "gate.bin");
		mMeltingPotMgr->prepare(OBJTYPE_SluiceBomb);
		registerClass(OBJTYPE_SluiceBomb, nullptr, 0);
	} else {
		registerClass(OBJTYPE_SluiceBomb, nullptr, 0);
	}

	if (useObjType(OBJTYPE_SluiceBombHard)) {
		mMeltingPotMgr->prepare(OBJTYPE_SluiceBombHard);
		registerClass(OBJTYPE_SluiceBombHard, nullptr, 0);
	} else {
		registerClass(OBJTYPE_SluiceBombHard, nullptr, 0);
	}

	memStat->end("sluice shape");

	registerClass(OBJTYPE_Fish, nullptr, 0);

	memStat->start("ufo shape");

	if (useObjType(OBJTYPE_Ufo)) {
		registerClass(OBJTYPE_Ufo, nullptr, 0);
	}

	memStat->end("ufo shape");

	memStat->start("goal shape");

	if (useObjType(OBJTYPE_Goal)) {
		mItemShapes[7] = new ItemShapeObject(gameflow.loadShape("objects/goal/goal.mod", true), "goal", "anims.bin");
		registerClass(OBJTYPE_Goal, nullptr, 0);
	}

	memStat->end("goal shape");

	memStat->start("register");
	endRegister();
	memStat->end("register");

	mPikiHeadMgr = new PikiHeadMgr(this);

	STACK_PAD_VAR(3);
	STACK_PAD_TERNARY(mPikiHeadMgr, 1);
}

/*
 * --INFO--
 * Address:	800F58AC
 * Size:	0000C8
 */
ItemCreature::ItemCreature(int objType, CreatureProp* props, Shape* shape)
    : AICreature(props)
{
	mItemShape = shape;
	_68        = 4;
	resetCreatureFlag(CF_Unk10);
	setCreatureFlag(CF_Unk1);
	mSearchBuffer.init(mItemSearchData, 8);
	mObjType         = (EObjType)objType;
	mItemShapeObject = nullptr;
	mStateMachine    = nullptr;
}

/*
 * --INFO--
 * Address:	800F5974
 * Size:	000070
 */
void ItemCreature::init(Vector3f& pos)
{
	Creature::init(pos);
	mSearchBuffer.init(mItemSearchData, 3);
	mMotionSpeed = 30.0f;
	if (mItemShapeObject) {
		mItemAnimator.init(&mItemShapeObject->mAnimContext, mItemShapeObject->mAnimMgr, itemMgr->mItemMotionTable);
	}
	_3C4 = 1;
}

/*
 * --INFO--
 * Address:	800F59E4
 * Size:	000008
 */
void ItemCreature::setMotionSpeed(f32 speed)
{
	mMotionSpeed = speed;
}

/*
 * --INFO--
 * Address:	800F59EC
 * Size:	000008
 */
f32 ItemCreature::getMotionSpeed()
{
	return mMotionSpeed;
}

/*
 * --INFO--
 * Address:	800F59F4
 * Size:	00000C
 */
void ItemCreature::stopMotion()
{
	mMotionSpeed = 0.0f;
}

/*
 * --INFO--
 * Address:	800F5A00
 * Size:	000008
 */
f32 ItemCreature::getCurrentMotionCounter()
{
	return mItemAnimator.mAnimationCounter;
}

/*
 * --INFO--
 * Address:	800F5A08
 * Size:	00002C
 */
char* ItemCreature::getCurrentMotionName()
{
	return mItemAnimator.getCurrentMotionName();
}

/*
 * --INFO--
 * Address:	800F5A34
 * Size:	000048
 */
void ItemCreature::startMotion(int motionID)
{
	mItemAnimator.startMotion(PaniMotionInfo(motionID, this));
}

/*
 * --INFO--
 * Address:	800F5A7C
 * Size:	00004C
 */
void ItemCreature::finishMotion()
{
	mItemAnimator.finishMotion(PaniMotionInfo(-1, this));
}

/*
 * --INFO--
 * Address:	800F5AC8
 * Size:	000058
 */
void ItemCreature::startMotion(int motionID, f32 frame)
{
	mItemAnimator.startMotion(PaniMotionInfo(motionID, this));
	mItemAnimator.mAnimationCounter = frame;
}

/*
 * --INFO--
 * Address:	800F5B20
 * Size:	00005C
 */
void ItemCreature::finishMotion(f32 frame)
{
	mItemAnimator.finishMotion(PaniMotionInfo(-1, this));
	mItemAnimator.mAnimationCounter = frame;
}

/*
 * --INFO--
 * Address:	800F5B7C
 * Size:	000034
 */
void ItemCreature::doKill()
{
	itemMgr->kill(this);
}

/*
 * --INFO--
 * Address:	800F5BB0
 * Size:	000044
 */
void ItemCreature::doAnimation()
{
	if (mItemShapeObject) {
		mItemAnimator.animate(mMotionSpeed);
	}
}

/*
 * --INFO--
 * Address:	800F5BF4
 * Size:	00003C
 */
void ItemCreature::update()
{
	if (mObjType == OBJTYPE_Ufo || (mObjType != OBJTYPE_Ufo && !GameCoreSection::inPause())) {
		Creature::update();
	}
}

/*
 * --INFO--
 * Address:	800F5C30
 * Size:	000048
 */
void ItemCreature::doAI()
{
	if (mStateMachine && !isCreatureFlag(CF_IsAiDisabled)) {
		mStateMachine->exec(this);
	}
}

/*
 * --INFO--
 * Address:	800F5C78
 * Size:	000220
 */
void ItemCreature::refresh(Graphics& gfx)
{
	bool isOffCamera = false;

	if (!gfx.mCamera->isPointVisible(mPosition, getBoundingSphereRadius())) {
		enableAICulling();
		isOffCamera = true;
	} else {
		disableAICulling();
	}

	if (mItemShapeObject) {
		_3C4 = 0;
		Matrix4f mtx;
		mWorldMtx.makeSRT(mScale, mRotation, mPosition);
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
		mItemAnimator.updateContext();
		mItemShapeObject->mShape->updateAnim(gfx, mtx, nullptr);

		if (!isOffCamera) {
			gfx.useMatrix(Matrix4f::ident, 0);
			mItemShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
		}
		return;
	}

	if (mItemShape && !isOffCamera) {
		PRINT("refreshing : %s\n", ObjType::getName(mObjType));
		mWorldMtx.makeSRT(mScale, mRotation, mPosition);
		Matrix4f mtx;
		gfx.calcViewMatrix(mWorldMtx, mtx);
		gfx.mHasTexGen = 1;
		gfx.useMatrix(mtx, 0);
		gfx.mCamera->setBoundOffset(&mPosition);
		mItemShape->drawshape(gfx, *gfx.mCamera, nullptr);
		gfx.mCamera->setBoundOffset(nullptr);
	}
}

/*
 * --INFO--
 * Address:	800F5E98
 * Size:	000074
 */
bool ItemCreature::stimulate(Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actItem(this);
	}

	return false;
}

/*
 * --INFO--
 * Address:	800F5F0C
 * Size:	000040
 */
bool InteractBuild::actItem(ItemCreature* item)
{
	if (item->isObjType(OBJTYPE_BoBase)) {
		return static_cast<BoBaseItem*>(item)->interactBuild(*this);
	}

	return false;
}

/*
 * --INFO--
 * Address:	800F5F4C
 * Size:	000040
 */
bool InteractBikkuri::actItem(ItemCreature* item)
{
	if (item->isObjType(OBJTYPE_Pikihead)) {
		return static_cast<PikiHeadItem*>(item)->interactBikkuri(*this);
	}
	return false;
}

/*
 * --INFO--
 * Address:	800F5F8C
 * Size:	000034
 */
bool InteractFlick::actItem(ItemCreature* item)
{
	if (item->isObjType(OBJTYPE_GemItem)) {
		static_cast<GemItem*>(item)->split();
	}

	return true;
}

/*
 * --INFO--
 * Address:	800F5FC0
 * Size:	000040
 */
bool InteractSwallow::actItem(ItemCreature* item)
{
	// why not use the inline????????????
	if (item->mObjType == OBJTYPE_Pikihead) {
		return static_cast<PikiHeadItem*>(item)->interactSwallow(*this);
	}
	return false;
}

/*
 * --INFO--
 * Address:	800F6000
 * Size:	000040
 */
bool InteractPullout::actItem(ItemCreature* item)
{
	// why not use the inline????????????
	if (item->mObjType == OBJTYPE_Weed) {
		return static_cast<Weed*>(item)->interactPullout(mOwner);
	}

	return false;
}

/*
 * --INFO--
 * Address:	800F6040
 * Size:	0002D4
 */
bool InteractBomb::actItem(ItemCreature* item)
{
	if (item->isSluice()) {
		BuildingItem* wall = static_cast<BuildingItem*>(item);
		if (wall->mCurrStage >= wall->mNumStages) {
			return false;
		}

		PRINT(" GOT BOMB!!!!\n");
		PRINT("sluice got bomb by %x\n", mOwner);
		switch (item->mObjType) {
		case OBJTYPE_SluiceSoft:
			item->playEventSound(item, SEB_SOFTWALL_HIT);
			break;
		case OBJTYPE_SluiceHard:
			item->playEventSound(item, SEB_HARDWALL_HIT);
			break;
		}

		item->mHealth -= mDamage;
		PRINT("BOMB : damage=%.1f life=%.1f currStage=%d\n", mDamage, item->mHealth, wall->mCurrStage);
		f32 healthThreshold = item->mMaxHealth - (wall->mCurrStage + 1) * (item->mMaxHealth / wall->mNumStages);
		if (healthThreshold >= item->mHealth) {
			bool check = false;
			while (healthThreshold >= item->mHealth && !check) {
				MsgUser msg(0);
				PRINT("currStage = %d threshold=%.1f currLife=%.1f\n", wall->mCurrStage, healthThreshold, item->mHealth);
				C_SAI(item)->procMsg(item, &msg);
				wall->mCurrStage++;
				if (wall->mCurrStage >= wall->mNumStages) {
					item->mHealth = 0.0f;
					SeSystem::playSysSe(SYSSE_WORK_FINISH);
					check = true;
				}

				healthThreshold = item->mMaxHealth - (wall->mCurrStage + 1) * (item->mMaxHealth / wall->mNumStages);
			}
		} else {
			MsgUser msg(1);
			C_SAI(item)->procMsg(item, &msg);
		}
		return true;
	}

	if (item->mObjType == OBJTYPE_Bomb) {
		BombItem* bomb = static_cast<BombItem*>(item);
		int state      = item->mStateMachine->getCurrID(item);
		PRINT("bomb got bomb interaction!\n");
		if (state != BombAI::BOMB_Bomb && state != BombAI::BOMB_Mizu && state != BombAI::BOMB_Die) {
			MsgUser msg(1);
			PRINT("bomb renbaku!\n");
			item->mCurrAnimId = 1;
			C_SAI(item)->procMsg(item, &msg);
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	800F6314
 * Size:	000060
 */
void BuildingItem::playEffect(int id)
{
	switch (id) {
	case 0:
		if (mCurrStage >= mNumStages) {
			cameraMgr->startVibrationEvent(4, mPosition);
		} else {
			cameraMgr->startVibrationEvent(2, mPosition);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	800F6374
 * Size:	000270
 */
bool InteractAttack::actItem(ItemCreature* item)
{
	if (item->mObjType == OBJTYPE_SluiceBomb || item->mObjType == OBJTYPE_SluiceBombHard) {
		item->playEventSound(item, SEB_HARDESTWALL_HIT);
		return false;
	}

	if (item->isSluice()) {
		BuildingItem* wall = static_cast<BuildingItem*>(item);
		if (wall->mCurrStage >= wall->mNumStages) {
			PRINT("zannen : %d >= %d\n", wall->mCurrStage, wall->mNumStages);
			return false;
		}

		if (item->mObjType == OBJTYPE_SluiceSoft) {
			item->playEventSound(item, SEB_SOFTWALL_HIT);
		} else {
			item->playEventSound(item, SEB_HARDWALL_HIT);
		}

		item->mHealth -= mDamage;
		f32 healthThreshold = item->mMaxHealth - (wall->mCurrStage + 1) * (item->mMaxHealth / wall->mNumStages);
		if (healthThreshold >= item->mHealth) {
			bool check = false;
			while (healthThreshold >= item->mHealth && !check) {
				MsgUser msg(0);
				PRINT("currStage = %d threshold=%.1f currLife=%.1f\n", wall->mCurrStage, healthThreshold, item->mHealth);
				C_SAI(item)->procMsg(item, &msg);
				wall->mCurrStage++;
				if (wall->mCurrStage >= wall->mNumStages) {
					item->mHealth = 0.0f;
					SeSystem::playSysSe(SYSSE_WORK_FINISH);
					check = true;
				}

				healthThreshold = item->mMaxHealth - (wall->mCurrStage + 1) * (item->mMaxHealth / wall->mNumStages);
			}
		} else {
			MsgUser msg(1);
			C_SAI(item)->procMsg(item, &msg);
		}

		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800F65E4
 * Size:	000144
 */
BuildingItem::BuildingItem(int objType, CreatureProp* props, ItemShapeObject* itemShape, SimpleAI* ai)
    : ItemCreature(objType, props, nullptr)
    , mBuildCollision(0)
{
	mItemShapeObject        = itemShape;
	mStateMachine           = ai;
	mLifeGauge.mRenderStyle = 1;
}

/*
 * --INFO--
 * Address:	800F6728
 * Size:	000064
 */
f32 BuildingItem::getBoundingSphereRadius()
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		CollPart* part = mCollInfo->getSphere('flag');
		if (part) {
			return part->mRadius;
		}
	}

	return 100.0f;
}

/*
 * --INFO--
 * Address:	800F678C
 * Size:	0001C8
 */
void BuildingItem::startAI(int)
{
	mItemShapeObject->mShape->makeInstance(mDynMats, 0);
	mCounter    = 0;
	mCurrAnimId = 0;
	_3C4        = 1;
	mSeContext  = &mBuildSFX;
	mSeContext->setContext(this, 4);
	PRINT("*** \n");
	enableFaceDirAdjust();
	mItemAnimator.startMotion(PaniMotionInfo(0));
	mHealth    = mMaxHealth;
	mCurrStage = 0;
	stopMotion();

	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	mCollInfo = &mBuildCollision;
	mCollInfo->initInfo(mItemShapeObject->mShape, mBuildParts, mBuildPartIDs);
	PRINT("*** \n");

	if (mItemShapeObject && mItemShapeObject->mShape) {
		mPlatMgr.init(this, mapMgr, mItemShapeObject->mShape);
	}

	mWayPoint            = routeMgr->findNearestWayPointAll('test', mPosition);
	mWayPoint->mPosition = mPosition;
	PRINT("*** \n");
	C_SAI(this)->start(this, SluiceAI::Sluice_WaitInit);

	_448   = mPosition;
	_448.y = mapMgr->getMinY(mPosition.x, mPosition.z, true);

	mPosition.y          = _448.y;
	mLifeGauge.mPosition = mPosition;
	mLifeGauge.mPosition.y += 110.0f;
	mLifeGauge.mOffset.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800F6954
 * Size:	000090
 */
void BuildingItem::startBreakEffect()
{
	playEventSound(this, SEB_WALL_DOWN);
	rumbleMgr->start(RUMBLE_Unk7, 0, mPosition);
	_3D8.init(mPosition, EffectMgr::EFF_Wl_Brk00);
	_3E8.init(mPosition, EffectMgr::EFF_Wl_Brk01);
	if (_3D8.mPtclGen) {
		_3D8.mPtclGen->setFreqFrm(5.0f);
	}
	if (_3E8.mPtclGen) {
		_3E8.mPtclGen->setFreqFrm(3.0f);
	}
}

/*
 * --INFO--
 * Address:	800F69E4
 * Size:	000060
 */
void BuildingItem::stopBreakEffect()
{
	if (_3D8.mPtclGen) {
		_3D8.mPtclGen->setFreqFrm(0.0f);
	}
	if (_3E8.mPtclGen) {
		_3E8.mPtclGen->setFreqFrm(0.0f);
	}

	_3D8.kill();
	_3E8.kill();
}

/*
 * --INFO--
 * Address:	800F6A44
 * Size:	000054
 */
void BuildingItem::update()
{
	updateStatic();
	_3D8.updatePos(mPosition);
	_3E8.updatePos(mPosition);
	mLifeGauge.updValue(mHealth, mMaxHealth);
}

/*
 * --INFO--
 * Address:	800F6A98
 * Size:	0001A4
 */
void BuildingItem::refresh(Graphics& gfx)
{
	f32 val = 0.0f;
	if (mObjType == OBJTYPE_SluiceSoft) {
		val = 0.0f;
	} else if (mObjType == OBJTYPE_SluiceHard) {
		val = 1.0f;
	} else if (mObjType == OBJTYPE_SluiceBomb) {
		val = 1.0f;
	} else {
		val = 2.0f;
	}

	mDynMats.animate(&val);

	bool isOffCamera = false;
	if (!gfx.mCamera->isPointVisible(mPosition, getBoundingSphereRadius())) {
		enableAICulling();
		isOffCamera = true;
	} else {
		disableAICulling();
	}

	if (mItemShapeObject) {
		_3C4 = 0;
		Matrix4f mtx;
		mWorldMtx.makeSRT(mScale, mRotation, mPosition);
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
		mItemAnimator.updateContext();
		mItemShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
		if (!isOffCamera) {
			gfx.useMatrix(Matrix4f::ident, 0);
			mItemShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mDynMats);
		}
	}

	mPlatMgr.update(gfx);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	800F6C3C
 * Size:	000004
 */
void BuildingItem::refresh2d(Graphics&)
{
}

/*
 * --INFO--
 * Address:	800F6C40
 * Size:	000048
 */
void BuildingItem::doKill()
{
	mPlatMgr.release();
	ItemCreature::doKill();
}

/*
 * --INFO--
 * Address:	800F6C88
 * Size:	0000AC
 */
void BuildingItem::doSave(RandomAccessStream& output)
{
	output.writeFloat(mHealth);
	output.writeFloat(mMaxHealth);
	output.writeInt(mCurrStage);
	output.writeInt(mNumStages);
	output.writeInt(mCurrAnimId);
	PRINT("\t life=%.1f maxLife=%.1f curr/num=%d/%d\n", mHealth, mMaxHealth, mCurrStage, mNumStages);
}

/*
 * --INFO--
 * Address:	800F6D34
 * Size:	00017C
 */
void BuildingItem::doLoad(RandomAccessStream& input)
{
	mHealth     = input.readFloat();
	mMaxHealth  = input.readFloat();
	mCurrStage  = input.readInt();
	mNumStages  = input.readInt();
	mCurrAnimId = input.readInt();

	PRINT("currStage %d numStages %d\n", mCurrStage, mNumStages);

	if (mCurrStage < mNumStages) {
		startMotion(mCurrStage);
		mWayPoint->setFlag(false);
	} else {
		startMotion(mNumStages - 1);
		int aKeys = mItemAnimator.mAnimInfo->countAKeys() - 1;
		startMotion(mNumStages - 1, mItemAnimator.mAnimInfo->getKeyValue(aKeys) - 1.0f);
		mWayPoint->setFlag(true);
	}

	stopMotion();
	C_SAI(this)->start(this, SluiceAI::Sluice_WaitInit);
	PRINT("* DONE\n");
}

/*
 * --INFO--
 * Address:	800F6EB0
 * Size:	000024
 */
void BuildingItem::doStore(CreatureInf* info)
{
	info->mHealth    = mHealth;
	info->mMaxHealth = mMaxHealth;
	info->mObjInfo1  = mCurrStage;
	info->mObjInfo2  = mNumStages;
}

/*
 * --INFO--
 * Address:	800F6ED4
 * Size:	000120
 */
void BuildingItem::doRestore(CreatureInf* info)
{
	startAI(0);

	mHealth    = info->mHealth;
	mMaxHealth = info->mMaxHealth;
	mCurrStage = info->mObjInfo1;
	mNumStages = info->mObjInfo2;

	// Wall still exists and isn't completely destroyed, so block off the waypoint
	if (mCurrStage < mNumStages) {
		startMotion(mCurrStage);
		mWayPoint->setFlag(false);
	}

	// wall is (presumably) destroyed, open waypoint
	else {
		int finalKeyframeIdx = mItemAnimator.mAnimInfo->countAKeys() - 1;
		startMotion(mNumStages - 1, mItemAnimator.mAnimInfo->getKeyValue(finalKeyframeIdx) - 1.0f);
		mWayPoint->setFlag(true);
	}

	// Don't actually animate, just start it to apply the transformation
	stopMotion();

	// Begin the AI
	C_SAI(this)->start(this, SluiceAI::Sluice_WaitInit);
}

/*
 * --INFO--
 * Address:	800F6FF4
 * Size:	000068
 */
Creature* ItemMgr::birth(int objType)
{
	switch (objType) {
	case OBJTYPE_Pikihead:
		return mPikiHeadMgr->birth();

	case OBJTYPE_Goal:
	case OBJTYPE_SluiceSoft:
	case OBJTYPE_SluiceHard:
	case OBJTYPE_SluiceBomb:
	case OBJTYPE_SluiceBombHard:
	case OBJTYPE_Kusa:
	case OBJTYPE_Ufo:
	case OBJTYPE_RockGen:
	case OBJTYPE_GrassGen:
	case OBJTYPE_BoBase:
	case OBJTYPE_Fish:
		return mMeltingPotMgr->birth(objType);

	default:
		return PolyObjectMgr::birth(objType);
	}
}

/*
 * --INFO--
 * Address:	800F705C
 * Size:	000068
 */
void ItemMgr::refresh(Graphics& gfx)
{
	PolyObjectMgr::refresh(gfx);
	mPikiHeadMgr->refresh(gfx);
	mMeltingPotMgr->refresh(gfx);
}

/*
 * --INFO--
 * Address:	800F70C4
 * Size:	000204
 */
void ItemMgr::refresh2d(Graphics& gfx)
{
	Iterator iterItem(this);
	CI_LOOP(iterItem)
	{
		(*iterItem)->refresh2d(gfx);
	}

	Iterator iterMelt(mMeltingPotMgr);
	CI_LOOP(iterMelt)
	{
		(*iterMelt)->refresh2d(gfx);
	}
}

/*
 * --INFO--
 * Address:	800F72C8
 * Size:	000064
 */
void ItemMgr::update()
{
	if (!GameCoreSection::inPause()) {
		PolyObjectMgr::update();
		mPikiHeadMgr->update();
	}

	mMeltingPotMgr->update();
}

/*
 * --INFO--
 * Address:	800F732C
 * Size:	000064
 */
void ItemMgr::kill(Creature* item)
{
	switch (item->mObjType) {
	case OBJTYPE_Pikihead:
		mPikiHeadMgr->kill(item);
		return;

	case OBJTYPE_Goal:
	case OBJTYPE_Ufo:
		PRINT("********* CANNOT KILL CONTAINER / UFO !!!\n");
		ERROR("GAKKARI\n");
		return;

	default:
		PolyObjectMgr::kill(item);
		return;
	}
}

/*
 * --INFO--
 * Address:	800F7390
 * Size:	0001D8
 */
PikiHeadMgr::PikiHeadMgr(ItemMgr* mgr)
{
	mItemMgr = mgr;
	PRINT("PIKIHEADMGR *** this = %x\n", this);
	mPikiHeadProps = new PikiHeadItemProp();
	mPikiHeadAI    = new PikiHeadAI();
	create(MAX_PIKI_ON_FIELD);
	PRINT("=====================================\n");
}

/*
 * --INFO--
 * Address:	800F7568
 * Size:	0000A0
 */
Creature* PikiHeadMgr::birth()
{
	int totalPikis = GameStat::mapPikis;
	totalPikis += mItemMgr->getContainerExitCount();

	if (buryMode) {
		if (totalPikis >= AIConstant::_instance->mConstants.mMaxPikisOnField() + 1) {
			return nullptr;
		}
	} else if (totalPikis >= AIConstant::_instance->mConstants.mMaxPikisOnField()) {
		return nullptr;
	}

	return MonoObjectMgr::birth();
}

/*
 * --INFO--
 * Address:	800F7608
 * Size:	000060
 */
Creature* PikiHeadMgr::createObject()
{
	return new PikiHeadItem(mPikiHeadProps, mItemMgr->mItemShapes[3], mPikiHeadAI);
}

/*
 * --INFO--
 * Address:	800F7668
 * Size:	00014C
 */
int ItemMgr::getContainerExitCount()
{
	int count = 0;
	for (int i = PikiMinColor; i < PikiColorCount; i++) {
		GoalItem* onyon = getContainer(i);
		if (onyon) {
			count += onyon->mPikisToExit;
		}
	}

	return count;
}
