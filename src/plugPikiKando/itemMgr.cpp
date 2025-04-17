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
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("itemMgr")

u8 PikiHeadMgr::buryMode;
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
		mAnimMgr        = new AnimMgr(shape, buf, 0x8000, nullptr);
		mAnimMgr->mName = objName;
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, 0, nullptr);
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
	PikiHeadMgr::buryMode = 0;
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
	Shape* doorShape2; // DLL: = loadShape("objects/door.mod", true);
	Shape* doorShape1; // DLL: = loadShape("objects/door.mod", true);
	Shape* keyShape;   // DLL: = loadShape("objects/key.mod", true);

	Shape* seedShapes[2];
	seedShapes[0] = gameflow.loadShape("pikis/happas/leaf.mod", true);
	seedShapes[1] = gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
	// DLL only:
	// gameflow.loadShape("shapes/arrow.mod", true);
	// gameflow.loadShape("shapes/oldMarkr.mod", true);

	registerClass(OBJTYPE_Rope, new RopeItem(new RopeProp(), nullptr), sizeof(RopeItem));

	registerClass(OBJTYPE_Fulcrum, new Fulcrum(), sizeof(Fulcrum));

	registerClass(OBJTYPE_Seed, new SeedItem(new SeedProp(), seedShapes), sizeof(SeedItem));

	registerClass(OBJTYPE_Key, new KeyItem(new KeyProp(), keyShape), sizeof(KeyItem));

	registerClass(OBJTYPE_Door, new DoorItem(OBJTYPE_Door, new DoorProp(), doorShape1), sizeof(DoorItem));
	registerClass(OBJTYPE_Gate, new DoorItem(OBJTYPE_Gate, new DoorProp(), doorShape2), sizeof(DoorItem));
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

	// need 0x4 more stack from inlines >:(
	u32 badCompiler[3];

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x568(r1)
	  stmw      r24, 0x548(r1)
	  addi      r31, r3, 0
	  subi      r30, r4, 0x1B08
	  li        r3, 0x64
	  bl        -0xAD38C
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x38
	  mr        r4, r31
	  bl        -0x1658

	.loc_0x38:
	  stw       r25, 0x68(r31)
	  mr        r3, r31
	  bl        -0x12098
	  li        r3, 0x3C8
	  bl        -0xAD3B4
	  mr.       r24, r3
	  beq-      .loc_0x5C
	  mr        r3, r24
	  bl        0x3764

	.loc_0x5C:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x1B
	  li        r6, 0x3C8
	  bl        -0x120C0
	  li        r3, 0x3C8
	  bl        -0xAD3E0
	  mr.       r24, r3
	  beq-      .loc_0x88
	  mr        r3, r24
	  bl        0x37A4

	.loc_0x88:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x1C
	  li        r6, 0x3C8
	  bl        -0x120EC
	  li        r3, 0x18
	  bl        -0xAD40C
	  addi      r29, r3, 0
	  mr.       r26, r29
	  beq-      .loc_0x15C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x140
	  li        r5, 0x1
	  bl        -0xA1720
	  lis       r4, 0x8023
	  crclr     6, 0x6
	  subi      r0, r4, 0x7730
	  stw       r0, 0x14(r29)
	  li        r0, 0
	  addi      r27, r3, 0
	  stw       r0, 0x8(r29)
	  addi      r3, r1, 0x4B4
	  addi      r4, r30, 0xC
	  lfs       f0, -0x63F4(r2)
	  addi      r5, r30, 0x160
	  addi      r6, r30, 0x16C
	  stfs      f0, 0xC(r29)
	  lfs       f0, -0x63F0(r2)
	  stfs      f0, 0x10(r29)
	  stw       r27, 0x0(r29)
	  lwz       r7, 0x0(r29)
	  stw       r0, 0x24(r7)
	  bl        0x12211C
	  li        r3, 0xB8
	  bl        -0xAD480
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x13C
	  lis       r6, 0x1
	  addi      r4, r27, 0
	  addi      r5, r1, 0x4B4
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xA3C04

	.loc_0x13C:
	  stw       r25, 0x4(r29)
	  addi      r0, r30, 0x160
	  addi      r5, r26, 0x8
	  lwz       r3, 0x4(r29)
	  li        r4, 0
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x0(r26)
	  bl        -0xBF464

	.loc_0x15C:
	  lwz       r4, 0x88(r31)
	  li        r3, 0x18
	  stw       r29, 0xC(r4)
	  bl        -0xAD4D4
	  addi      r29, r3, 0
	  mr.       r26, r29
	  beq-      .loc_0x224
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x178
	  li        r5, 0x1
	  bl        -0xA17E8
	  lis       r4, 0x8023
	  crclr     6, 0x6
	  subi      r0, r4, 0x7730
	  stw       r0, 0x14(r29)
	  li        r0, 0
	  addi      r27, r3, 0
	  stw       r0, 0x8(r29)
	  addi      r3, r1, 0x434
	  addi      r4, r30, 0xC
	  lfs       f0, -0x63F4(r2)
	  addi      r6, r30, 0x16C
	  subi      r5, r13, 0x300C
	  stfs      f0, 0xC(r29)
	  lfs       f0, -0x63F0(r2)
	  stfs      f0, 0x10(r29)
	  stw       r27, 0x0(r29)
	  lwz       r7, 0x0(r29)
	  stw       r0, 0x24(r7)
	  bl        0x122054
	  li        r3, 0xB8
	  bl        -0xAD548
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x204
	  lis       r6, 0x1
	  addi      r4, r27, 0
	  addi      r5, r1, 0x434
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xA3CCC

	.loc_0x204:
	  stw       r25, 0x4(r29)
	  subi      r0, r13, 0x300C
	  addi      r5, r26, 0x8
	  lwz       r3, 0x4(r29)
	  li        r4, 0
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x0(r26)
	  bl        -0xBF52C

	.loc_0x224:
	  lwz       r4, 0x88(r31)
	  li        r3, 0x58
	  stw       r29, 0x8(r4)
	  bl        -0xAD59C
	  addi      r29, r3, 0
	  mr.       r26, r29
	  beq-      .loc_0x374
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r29)
	  li        r0, 0
	  addi      r3, r1, 0x190
	  stw       r0, 0x0(r29)
	  subi      r4, r13, 0x3020
	  bl        -0xA3AF4
	  lwz       r0, 0x190(r1)
	  addi      r5, r1, 0x18C
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x18C(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x4
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5BBB4
	  addi      r3, r1, 0x198
	  subi      r4, r13, 0x301C
	  bl        -0xA3B28
	  lwz       r0, 0x198(r1)
	  addi      r5, r1, 0x194
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x194(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x14
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5BBE8
	  addi      r3, r1, 0x1A0
	  subi      r4, r13, 0x3018
	  bl        -0xA3B5C
	  lwz       r0, 0x1A0(r1)
	  addi      r5, r1, 0x19C
	  lfs       f1, -0x63E4(r2)
	  mr        r4, r26
	  stw       r0, 0x19C(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x24
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5BC1C
	  addi      r3, r1, 0x1A8
	  subi      r4, r13, 0x3014
	  bl        -0xA3B90
	  lwz       r0, 0x1A8(r1)
	  addi      r5, r1, 0x1A4
	  lfs       f1, -0x63E0(r2)
	  mr        r4, r26
	  stw       r0, 0x1A4(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x34
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5BC50
	  addi      r3, r1, 0x1B0
	  subi      r4, r13, 0x3010
	  bl        -0xA3BC4
	  lwz       r0, 0x1B0(r1)
	  addi      r5, r1, 0x1AC
	  lfs       f1, -0x63D4(r2)
	  mr        r4, r26
	  stw       r0, 0x1AC(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x44
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5BC84
	  lis       r3, 0x802C
	  subi      r0, r3, 0x1270
	  stw       r0, 0x54(r29)
	  lfs       f0, -0x63E0(r2)
	  stfs      f0, 0x10(r29)
	  lfs       f0, -0x63D0(r2)
	  stfs      f0, 0x50(r29)

	.loc_0x374:
	  li        r3, 0x1C
	  bl        -0xAD6E4
	  mr.       r24, r3
	  beq-      .loc_0x38C
	  mr        r3, r24
	  bl        -0x4754

	.loc_0x38C:
	  li        r3, 0x840
	  bl        -0xAD6FC
	  mr.       r25, r3
	  beq-      .loc_0x3B4
	  lwz       r5, 0x88(r31)
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  lwz       r5, 0x8(r5)
	  mr        r6, r24
	  bl        -0xA430

	.loc_0x3B4:
	  addi      r3, r31, 0
	  addi      r5, r25, 0
	  li        r4, 0xE
	  li        r6, 0x840
	  bl        -0x12418
	  li        r3, 0x58
	  bl        -0xAD738
	  addi      r29, r3, 0
	  mr.       r26, r29
	  beq-      .loc_0x510
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r29)
	  li        r0, 0
	  addi      r3, r1, 0x168
	  stw       r0, 0x0(r29)
	  subi      r4, r13, 0x3020
	  bl        -0xA3C90
	  lwz       r0, 0x168(r1)
	  addi      r5, r1, 0x164
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x164(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x4
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5BD50
	  addi      r3, r1, 0x170
	  subi      r4, r13, 0x301C
	  bl        -0xA3CC4
	  lwz       r0, 0x170(r1)
	  addi      r5, r1, 0x16C
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x16C(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x14
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5BD84
	  addi      r3, r1, 0x178
	  subi      r4, r13, 0x3018
	  bl        -0xA3CF8
	  lwz       r0, 0x178(r1)
	  addi      r5, r1, 0x174
	  lfs       f1, -0x63E4(r2)
	  mr        r4, r26
	  stw       r0, 0x174(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x24
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5BDB8
	  addi      r3, r1, 0x180
	  subi      r4, r13, 0x3014
	  bl        -0xA3D2C
	  lwz       r0, 0x180(r1)
	  addi      r5, r1, 0x17C
	  lfs       f1, -0x63E0(r2)
	  mr        r4, r26
	  stw       r0, 0x17C(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x34
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5BDEC
	  addi      r3, r1, 0x188
	  subi      r4, r13, 0x3010
	  bl        -0xA3D60
	  lwz       r0, 0x188(r1)
	  addi      r5, r1, 0x184
	  lfs       f1, -0x63D4(r2)
	  mr        r4, r26
	  stw       r0, 0x184(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x44
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5BE20
	  lis       r3, 0x802C
	  subi      r0, r3, 0x1298
	  stw       r0, 0x54(r29)
	  lfs       f0, -0x63E0(r2)
	  stfs      f0, 0x10(r29)
	  lfs       f0, -0x63D0(r2)
	  stfs      f0, 0x50(r29)

	.loc_0x510:
	  li        r3, 0x1C
	  bl        -0xAD880
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x528
	  bl        -0x2500

	.loc_0x528:
	  addi      r26, r25, 0
	  li        r3, 0x18
	  bl        -0xAD89C
	  mr.       r27, r3
	  beq-      .loc_0x5E8
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x190
	  li        r5, 0x1
	  bl        -0xA1BAC
	  lis       r4, 0x8023
	  crclr     6, 0x6
	  subi      r0, r4, 0x7730
	  stw       r0, 0x14(r27)
	  li        r0, 0
	  addi      r25, r3, 0
	  stw       r0, 0x8(r27)
	  addi      r3, r1, 0x3B4
	  addi      r4, r30, 0xC
	  lfs       f0, -0x63F4(r2)
	  addi      r6, r30, 0x16C
	  subi      r5, r13, 0x3004
	  stfs      f0, 0xC(r27)
	  lfs       f0, -0x63F0(r2)
	  stfs      f0, 0x10(r27)
	  stw       r25, 0x0(r27)
	  lwz       r7, 0x0(r27)
	  stw       r0, 0x24(r7)
	  bl        0x121C90
	  li        r3, 0xB8
	  bl        -0xAD90C
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x5C8
	  lis       r6, 0x1
	  addi      r4, r25, 0
	  addi      r5, r1, 0x3B4
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xA4090

	.loc_0x5C8:
	  stw       r24, 0x4(r27)
	  subi      r0, r13, 0x3004
	  addi      r5, r27, 0x8
	  lwz       r3, 0x4(r27)
	  li        r4, 0
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x0(r27)
	  bl        -0xBF8F0

	.loc_0x5E8:
	  lwz       r4, 0x88(r31)
	  li        r3, 0x3C8
	  stw       r27, 0x0(r4)
	  bl        -0xAD960
	  mr.       r24, r3
	  beq-      .loc_0x61C
	  lwz       r4, 0x88(r31)
	  addi      r3, r24, 0
	  addi      r5, r29, 0
	  lwz       r6, 0x0(r4)
	  addi      r7, r26, 0
	  li        r4, 0x1
	  bl        0x3328

	.loc_0x61C:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x1
	  li        r6, 0x3C8
	  bl        -0x12680
	  li        r3, 0x1C
	  bl        -0xAD9A0
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x648
	  bl        -0x2364

	.loc_0x648:
	  addi      r26, r24, 0
	  li        r3, 0x18
	  bl        -0xAD9BC
	  mr.       r27, r3
	  beq-      .loc_0x708
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x1A8
	  li        r5, 0x1
	  bl        -0xA1CCC
	  lis       r4, 0x8023
	  crclr     6, 0x6
	  subi      r0, r4, 0x7730
	  stw       r0, 0x14(r27)
	  li        r0, 0
	  addi      r25, r3, 0
	  stw       r0, 0x8(r27)
	  addi      r3, r1, 0x334
	  addi      r4, r30, 0xC
	  lfs       f0, -0x63F4(r2)
	  addi      r5, r30, 0x1C8
	  addi      r6, r30, 0x16C
	  stfs      f0, 0xC(r27)
	  lfs       f0, -0x63F0(r2)
	  stfs      f0, 0x10(r27)
	  stw       r25, 0x0(r27)
	  lwz       r7, 0x0(r27)
	  stw       r0, 0x24(r7)
	  bl        0x121B70
	  li        r3, 0xB8
	  bl        -0xADA2C
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x6E8
	  lis       r6, 0x1
	  addi      r4, r25, 0
	  addi      r5, r1, 0x334
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xA41B0

	.loc_0x6E8:
	  stw       r24, 0x4(r27)
	  addi      r0, r30, 0x1C8
	  addi      r5, r27, 0x8
	  lwz       r3, 0x4(r27)
	  li        r4, 0
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x0(r27)
	  bl        -0xBFA10

	.loc_0x708:
	  lwz       r4, 0x88(r31)
	  li        r3, 0x3C8
	  stw       r27, 0x4(r4)
	  bl        -0xADA80
	  mr.       r24, r3
	  beq-      .loc_0x73C
	  lwz       r4, 0x88(r31)
	  addi      r3, r24, 0
	  addi      r5, r29, 0
	  lwz       r6, 0x4(r4)
	  addi      r7, r26, 0
	  li        r4, 0x6
	  bl        0x3208

	.loc_0x73C:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x6
	  li        r6, 0x3C8
	  bl        -0x127A0
	  lis       r3, 0x803A
	  subi      r26, r3, 0x2848
	  addi      r3, r26, 0
	  addi      r4, r30, 0x1D4
	  li        r5, 0x1
	  bl        -0xA1DC4
	  stw       r3, 0x540(r1)
	  addi      r3, r26, 0
	  addi      r4, r30, 0x1D4
	  li        r5, 0x1
	  bl        -0xA1DD8
	  stw       r3, 0x544(r1)
	  addi      r3, r26, 0
	  addi      r4, r30, 0x1D4
	  li        r5, 0x1
	  bl        -0xA1DEC
	  li        r3, 0x58
	  bl        -0xADB00
	  addi      r27, r3, 0
	  mr.       r26, r27
	  beq-      .loc_0x8D8
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r27)
	  li        r0, 0
	  addi      r3, r1, 0x140
	  stw       r0, 0x0(r27)
	  subi      r4, r13, 0x3020
	  bl        -0xA4058
	  lwz       r0, 0x140(r1)
	  addi      r5, r1, 0x13C
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x13C(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x4
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C118
	  addi      r3, r1, 0x148
	  subi      r4, r13, 0x301C
	  bl        -0xA408C
	  lwz       r0, 0x148(r1)
	  addi      r5, r1, 0x144
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x144(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x14
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C14C
	  addi      r3, r1, 0x150
	  subi      r4, r13, 0x3018
	  bl        -0xA40C0
	  lwz       r0, 0x150(r1)
	  addi      r5, r1, 0x14C
	  lfs       f1, -0x63E4(r2)
	  mr        r4, r26
	  stw       r0, 0x14C(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x24
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C180
	  addi      r3, r1, 0x158
	  subi      r4, r13, 0x3014
	  bl        -0xA40F4
	  lwz       r0, 0x158(r1)
	  addi      r5, r1, 0x154
	  lfs       f1, -0x63E0(r2)
	  mr        r4, r26
	  stw       r0, 0x154(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x34
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C1B4
	  addi      r3, r1, 0x160
	  subi      r4, r13, 0x3010
	  bl        -0xA4128
	  lwz       r0, 0x160(r1)
	  addi      r5, r1, 0x15C
	  lfs       f1, -0x63D4(r2)
	  mr        r4, r26
	  stw       r0, 0x15C(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x44
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C1E8
	  lis       r3, 0x802C
	  subi      r0, r3, 0x12C0
	  stw       r0, 0x54(r27)
	  lfs       f0, -0x63E0(r2)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x63D0(r2)
	  stfs      f0, 0x50(r27)

	.loc_0x8D8:
	  li        r3, 0x300
	  bl        -0xADC48
	  mr.       r24, r3
	  beq-      .loc_0x8F8
	  addi      r3, r24, 0
	  addi      r4, r26, 0
	  li        r5, 0
	  bl        -0x7288

	.loc_0x8F8:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x12
	  li        r6, 0x300
	  bl        -0x1295C
	  li        r3, 0x3C8
	  bl        -0xADC7C
	  mr.       r24, r3
	  beq-      .loc_0x924
	  mr        r3, r24
	  bl        0x2E30

	.loc_0x924:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x11
	  li        r6, 0x3C8
	  bl        -0x12988
	  li        r3, 0x58
	  bl        -0xADCA8
	  addi      r27, r3, 0
	  mr.       r26, r27
	  beq-      .loc_0xA78
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r27)
	  li        r0, 0
	  addi      r3, r1, 0x118
	  stw       r0, 0x0(r27)
	  subi      r4, r13, 0x3020
	  bl        -0xA4200
	  lwz       r0, 0x118(r1)
	  addi      r5, r1, 0x114
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x114(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x4
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C2C0
	  addi      r3, r1, 0x120
	  subi      r4, r13, 0x301C
	  bl        -0xA4234
	  lwz       r0, 0x120(r1)
	  addi      r5, r1, 0x11C
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x11C(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x14
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C2F4
	  addi      r3, r1, 0x128
	  subi      r4, r13, 0x3018
	  bl        -0xA4268
	  lwz       r0, 0x128(r1)
	  addi      r5, r1, 0x124
	  lfs       f1, -0x63E4(r2)
	  mr        r4, r26
	  stw       r0, 0x124(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x24
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C328
	  addi      r3, r1, 0x130
	  subi      r4, r13, 0x3014
	  bl        -0xA429C
	  lwz       r0, 0x130(r1)
	  addi      r5, r1, 0x12C
	  lfs       f1, -0x63E0(r2)
	  mr        r4, r26
	  stw       r0, 0x12C(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x34
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C35C
	  addi      r3, r1, 0x138
	  subi      r4, r13, 0x3010
	  bl        -0xA42D0
	  lwz       r0, 0x138(r1)
	  addi      r5, r1, 0x134
	  lfs       f1, -0x63D4(r2)
	  mr        r4, r26
	  stw       r0, 0x134(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x44
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C390
	  lis       r3, 0x802C
	  subi      r0, r3, 0x12E4
	  stw       r0, 0x54(r27)
	  lfs       f0, -0x63E0(r2)
	  stfs      f0, 0x10(r27)

	.loc_0xA78:
	  li        r3, 0x2FC
	  bl        -0xADDE8
	  mr.       r24, r3
	  beq-      .loc_0xA98
	  addi      r3, r24, 0
	  addi      r4, r26, 0
	  addi      r5, r1, 0x540
	  bl        -0x7034

	.loc_0xA98:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x2
	  li        r6, 0x2FC
	  bl        -0x12AFC
	  li        r3, 0x58
	  bl        -0xADE1C
	  addi      r27, r3, 0
	  mr.       r26, r27
	  beq-      .loc_0xBF4
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r27)
	  li        r0, 0
	  addi      r3, r1, 0xF0
	  stw       r0, 0x0(r27)
	  subi      r4, r13, 0x3020
	  bl        -0xA4374
	  lwz       r0, 0xF0(r1)
	  addi      r5, r1, 0xEC
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0xEC(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x4
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C434
	  addi      r3, r1, 0xF8
	  subi      r4, r13, 0x301C
	  bl        -0xA43A8
	  lwz       r0, 0xF8(r1)
	  addi      r5, r1, 0xF4
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0xF4(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x14
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C468
	  addi      r3, r1, 0x100
	  subi      r4, r13, 0x3018
	  bl        -0xA43DC
	  lwz       r0, 0x100(r1)
	  addi      r5, r1, 0xFC
	  lfs       f1, -0x63E4(r2)
	  mr        r4, r26
	  stw       r0, 0xFC(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x24
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C49C
	  addi      r3, r1, 0x108
	  subi      r4, r13, 0x3014
	  bl        -0xA4410
	  lwz       r0, 0x108(r1)
	  addi      r5, r1, 0x104
	  lfs       f1, -0x63E0(r2)
	  mr        r4, r26
	  stw       r0, 0x104(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x34
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C4D0
	  addi      r3, r1, 0x110
	  subi      r4, r13, 0x3010
	  bl        -0xA4444
	  lwz       r0, 0x110(r1)
	  addi      r5, r1, 0x10C
	  lfs       f1, -0x63D4(r2)
	  mr        r4, r26
	  stw       r0, 0x10C(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x44
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C504
	  lis       r3, 0x802C
	  subi      r0, r3, 0x1308
	  stw       r0, 0x54(r27)
	  lfs       f0, -0x63E0(r2)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x63D0(r2)
	  stfs      f0, 0x50(r27)

	.loc_0xBF4:
	  li        r3, 0x2E4
	  bl        -0xADF64
	  mr.       r24, r3
	  beq-      .loc_0xC14
	  addi      r3, r24, 0
	  addi      r4, r26, 0
	  addi      r5, r28, 0
	  bl        -0x7D7C

	.loc_0xC14:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x3
	  li        r6, 0x2E4
	  bl        -0x12C78
	  li        r3, 0x58
	  bl        -0xADF98
	  addi      r27, r3, 0
	  mr.       r26, r27
	  beq-      .loc_0xD70
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r27)
	  li        r0, 0
	  addi      r3, r1, 0xC8
	  stw       r0, 0x0(r27)
	  subi      r4, r13, 0x3020
	  bl        -0xA44F0
	  lwz       r0, 0xC8(r1)
	  addi      r5, r1, 0xC4
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0xC4(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x4
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C5B0
	  addi      r3, r1, 0xD0
	  subi      r4, r13, 0x301C
	  bl        -0xA4524
	  lwz       r0, 0xD0(r1)
	  addi      r5, r1, 0xCC
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0xCC(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x14
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C5E4
	  addi      r3, r1, 0xD8
	  subi      r4, r13, 0x3018
	  bl        -0xA4558
	  lwz       r0, 0xD8(r1)
	  addi      r5, r1, 0xD4
	  lfs       f1, -0x63E4(r2)
	  mr        r4, r26
	  stw       r0, 0xD4(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x24
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C618
	  addi      r3, r1, 0xE0
	  subi      r4, r13, 0x3014
	  bl        -0xA458C
	  lwz       r0, 0xE0(r1)
	  addi      r5, r1, 0xDC
	  lfs       f1, -0x63E0(r2)
	  mr        r4, r26
	  stw       r0, 0xDC(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x34
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C64C
	  addi      r3, r1, 0xE8
	  subi      r4, r13, 0x3010
	  bl        -0xA45C0
	  lwz       r0, 0xE8(r1)
	  addi      r5, r1, 0xE4
	  lfs       f1, -0x63D4(r2)
	  mr        r4, r26
	  stw       r0, 0xE4(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x44
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C680
	  lis       r3, 0x802C
	  subi      r0, r3, 0x1320
	  stw       r0, 0x54(r27)
	  lfs       f0, -0x63E0(r2)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x63D0(r2)
	  stfs      f0, 0x50(r27)

	.loc_0xD70:
	  li        r3, 0x3D8
	  bl        -0xAE0E0
	  mr.       r24, r3
	  beq-      .loc_0xD94
	  addi      r3, r24, 0
	  addi      r5, r26, 0
	  addi      r6, r28, 0
	  li        r4, 0x4
	  bl        -0x7B2C

	.loc_0xD94:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x4
	  li        r6, 0x3D8
	  bl        -0x12DF8
	  li        r3, 0x58
	  bl        -0xAE118
	  addi      r27, r3, 0
	  mr.       r26, r27
	  beq-      .loc_0xEF0
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r27)
	  li        r0, 0
	  addi      r3, r1, 0xA0
	  stw       r0, 0x0(r27)
	  subi      r4, r13, 0x3020
	  bl        -0xA4670
	  lwz       r0, 0xA0(r1)
	  addi      r5, r1, 0x9C
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0x9C(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x4
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C730
	  addi      r3, r1, 0xA8
	  subi      r4, r13, 0x301C
	  bl        -0xA46A4
	  lwz       r0, 0xA8(r1)
	  addi      r5, r1, 0xA4
	  lfs       f1, -0x63EC(r2)
	  mr        r4, r26
	  stw       r0, 0xA4(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x14
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C764
	  addi      r3, r1, 0xB0
	  subi      r4, r13, 0x3018
	  bl        -0xA46D8
	  lwz       r0, 0xB0(r1)
	  addi      r5, r1, 0xAC
	  lfs       f1, -0x63E4(r2)
	  mr        r4, r26
	  stw       r0, 0xAC(r1)
	  lfs       f2, -0x63F4(r2)
	  addi      r3, r26, 0x24
	  lfs       f3, -0x63E8(r2)
	  li        r6, 0
	  bl        -0x5C798
	  addi      r3, r1, 0xB8
	  subi      r4, r13, 0x3014
	  bl        -0xA470C
	  lwz       r0, 0xB8(r1)
	  addi      r5, r1, 0xB4
	  lfs       f1, -0x63E0(r2)
	  mr        r4, r26
	  stw       r0, 0xB4(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x34
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C7CC
	  addi      r3, r1, 0xC0
	  subi      r4, r13, 0x3010
	  bl        -0xA4740
	  lwz       r0, 0xC0(r1)
	  addi      r5, r1, 0xBC
	  lfs       f1, -0x63D4(r2)
	  mr        r4, r26
	  stw       r0, 0xBC(r1)
	  lfs       f2, -0x63DC(r2)
	  addi      r3, r26, 0x44
	  lfs       f3, -0x63D8(r2)
	  li        r6, 0
	  bl        -0x5C800
	  lis       r3, 0x802C
	  subi      r0, r3, 0x1320
	  stw       r0, 0x54(r27)
	  lfs       f0, -0x63E0(r2)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x63D0(r2)
	  stfs      f0, 0x50(r27)

	.loc_0xEF0:
	  li        r3, 0x3D8
	  bl        -0xAE260
	  mr.       r24, r3
	  beq-      .loc_0xF14
	  addi      r3, r24, 0
	  addi      r5, r26, 0
	  addi      r6, r28, 0
	  li        r4, 0x5
	  bl        -0x7CAC

	.loc_0xF14:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0x5
	  li        r6, 0x3D8
	  bl        -0x12F78
	  li        r3, 0x3CC
	  bl        -0xAE298
	  mr.       r24, r3
	  beq-      .loc_0xF44
	  addi      r3, r24, 0
	  li        r4, 0
	  bl        0x26F8

	.loc_0xF44:
	  addi      r3, r31, 0
	  addi      r5, r24, 0
	  li        r4, 0xD
	  li        r6, 0x3CC
	  bl        -0x12FA8
	  lwz       r3, 0x7C(r31)
	  b         .loc_0xF78

	.loc_0xF60:
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x1D
	  bne-      .loc_0xF74
	  li        r0, 0x1
	  b         .loc_0xF84

	.loc_0xF74:
	  lwz       r3, 0xC(r3)

	.loc_0xF78:
	  cmplwi    r3, 0
	  bne+      .loc_0xF60
	  li        r0, 0

	.loc_0xF84:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xFB0
	  addi      r3, r31, 0
	  li        r4, 0x1D
	  li        r5, 0
	  li        r6, 0
	  bl        -0x12FF0
	  lwz       r3, 0x68(r31)
	  li        r4, 0x1D
	  bl        -0x20AC
	  b         .loc_0xFC4

	.loc_0xFB0:
	  addi      r3, r31, 0
	  li        r4, 0x1D
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13014

	.loc_0xFC4:
	  addi      r3, r31, 0
	  li        r4, 0x23
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13028
	  addi      r3, r31, 0
	  li        r4, 0x21
	  li        r5, 0
	  li        r6, 0
	  bl        -0x1303C
	  addi      r3, r31, 0
	  li        r4, 0x22
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13050
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x1EC
	  bl        -0x6EC40
	  lwz       r3, 0x7C(r31)
	  b         .loc_0x102C

	.loc_0x1014:
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x16
	  bne-      .loc_0x1028
	  li        r0, 0x1
	  b         .loc_0x1038

	.loc_0x1028:
	  lwz       r3, 0xC(r3)

	.loc_0x102C:
	  cmplwi    r3, 0
	  bne+      .loc_0x1014
	  li        r0, 0

	.loc_0x1038:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1128
	  li        r3, 0x18
	  bl        -0xAE3B0
	  mr.       r24, r3
	  beq-      .loc_0x10FC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x1FC
	  li        r5, 0x1
	  bl        -0xA26C0
	  lis       r4, 0x8023
	  crclr     6, 0x6
	  subi      r0, r4, 0x7730
	  stw       r0, 0x14(r24)
	  li        r0, 0
	  addi      r25, r3, 0
	  stw       r0, 0x8(r24)
	  addi      r3, r1, 0x2B4
	  addi      r4, r30, 0xC
	  lfs       f0, -0x63F4(r2)
	  addi      r6, r30, 0x218
	  subi      r5, r13, 0x2FFC
	  stfs      f0, 0xC(r24)
	  lfs       f0, -0x63F0(r2)
	  stfs      f0, 0x10(r24)
	  stw       r25, 0x0(r24)
	  lwz       r7, 0x0(r24)
	  stw       r0, 0x24(r7)
	  bl        0x12117C
	  li        r3, 0xB8
	  bl        -0xAE420
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x10DC
	  lis       r6, 0x1
	  addi      r4, r25, 0
	  addi      r5, r1, 0x2B4
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xA4BA4

	.loc_0x10DC:
	  stw       r26, 0x4(r24)
	  subi      r0, r13, 0x2FFC
	  addi      r5, r24, 0x8
	  lwz       r3, 0x4(r24)
	  li        r4, 0
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x0(r24)
	  bl        -0xC0404

	.loc_0x10FC:
	  lwz       r5, 0x88(r31)
	  addi      r3, r31, 0
	  li        r4, 0x16
	  stw       r24, 0x20(r5)
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13168
	  lwz       r3, 0x68(r31)
	  li        r4, 0x16
	  bl        -0x2224
	  b         .loc_0x113C

	.loc_0x1128:
	  addi      r3, r31, 0
	  li        r4, 0x16
	  li        r5, 0
	  li        r6, 0
	  bl        -0x1318C

	.loc_0x113C:
	  lwz       r3, 0x7C(r31)
	  b         .loc_0x115C

	.loc_0x1144:
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x17
	  bne-      .loc_0x1158
	  li        r0, 0x1
	  b         .loc_0x1168

	.loc_0x1158:
	  lwz       r3, 0xC(r3)

	.loc_0x115C:
	  cmplwi    r3, 0
	  bne+      .loc_0x1144
	  li        r0, 0

	.loc_0x1168:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1194
	  lwz       r3, 0x68(r31)
	  li        r4, 0x17
	  bl        -0x227C
	  addi      r3, r31, 0
	  li        r4, 0x17
	  li        r5, 0
	  li        r6, 0
	  bl        -0x131E0
	  b         .loc_0x11A8

	.loc_0x1194:
	  addi      r3, r31, 0
	  li        r4, 0x17
	  li        r5, 0
	  li        r6, 0
	  bl        -0x131F8

	.loc_0x11A8:
	  lwz       r3, 0x7C(r31)
	  b         .loc_0x11C8

	.loc_0x11B0:
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x18
	  bne-      .loc_0x11C4
	  li        r0, 0x1
	  b         .loc_0x11D4

	.loc_0x11C4:
	  lwz       r3, 0xC(r3)

	.loc_0x11C8:
	  cmplwi    r3, 0
	  bne+      .loc_0x11B0
	  li        r0, 0

	.loc_0x11D4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x12C4
	  li        r3, 0x18
	  bl        -0xAE54C
	  mr.       r24, r3
	  beq-      .loc_0x1298
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x224
	  li        r5, 0x1
	  bl        -0xA285C
	  lis       r4, 0x8023
	  crclr     6, 0x6
	  subi      r0, r4, 0x7730
	  stw       r0, 0x14(r24)
	  li        r0, 0
	  addi      r25, r3, 0
	  stw       r0, 0x8(r24)
	  addi      r3, r1, 0x234
	  addi      r4, r30, 0xC
	  lfs       f0, -0x63F4(r2)
	  addi      r6, r30, 0x218
	  subi      r5, r13, 0x2FFC
	  stfs      f0, 0xC(r24)
	  lfs       f0, -0x63F0(r2)
	  stfs      f0, 0x10(r24)
	  stw       r25, 0x0(r24)
	  lwz       r7, 0x0(r24)
	  stw       r0, 0x24(r7)
	  bl        0x120FE0
	  li        r3, 0xB8
	  bl        -0xAE5BC
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x1278
	  lis       r6, 0x1
	  addi      r4, r25, 0
	  addi      r5, r1, 0x234
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xA4D40

	.loc_0x1278:
	  stw       r26, 0x4(r24)
	  subi      r0, r13, 0x2FFC
	  addi      r5, r24, 0x8
	  lwz       r3, 0x4(r24)
	  li        r4, 0
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x0(r24)
	  bl        -0xC05A0

	.loc_0x1298:
	  lwz       r3, 0x88(r31)
	  li        r4, 0x18
	  stw       r24, 0x24(r3)
	  lwz       r3, 0x68(r31)
	  bl        -0x23AC
	  addi      r3, r31, 0
	  li        r4, 0x18
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13310
	  b         .loc_0x12D8

	.loc_0x12C4:
	  addi      r3, r31, 0
	  li        r4, 0x18
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13328

	.loc_0x12D8:
	  lwz       r3, 0x7C(r31)
	  b         .loc_0x12F8

	.loc_0x12E0:
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x19
	  bne-      .loc_0x12F4
	  li        r0, 0x1
	  b         .loc_0x1304

	.loc_0x12F4:
	  lwz       r3, 0xC(r3)

	.loc_0x12F8:
	  cmplwi    r3, 0
	  bne+      .loc_0x12E0
	  li        r0, 0

	.loc_0x1304:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1330
	  lwz       r3, 0x68(r31)
	  li        r4, 0x19
	  bl        -0x2418
	  addi      r3, r31, 0
	  li        r4, 0x19
	  li        r5, 0
	  li        r6, 0
	  bl        -0x1337C
	  b         .loc_0x1344

	.loc_0x1330:
	  addi      r3, r31, 0
	  li        r4, 0x19
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13394

	.loc_0x1344:
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x1EC
	  bl        -0x6EE74
	  addi      r3, r31, 0
	  li        r4, 0x25
	  li        r5, 0
	  li        r6, 0
	  bl        -0x133B4
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x240
	  bl        -0x6EFA4
	  lwz       r3, 0x7C(r31)
	  b         .loc_0x1390

	.loc_0x1378:
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0x138C
	  li        r0, 0x1
	  b         .loc_0x139C

	.loc_0x138C:
	  lwz       r3, 0xC(r3)

	.loc_0x1390:
	  cmplwi    r3, 0
	  bne+      .loc_0x1378
	  li        r0, 0

	.loc_0x139C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x13B8
	  addi      r3, r31, 0
	  li        r4, 0x1E
	  li        r5, 0
	  li        r6, 0
	  bl        -0x13408

	.loc_0x13B8:
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x240
	  bl        -0x6EEE8
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x24C
	  bl        -0x6F004
	  lwz       r3, 0x7C(r31)
	  b         .loc_0x13F0

	.loc_0x13D8:
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x10
	  bne-      .loc_0x13EC
	  li        r0, 0x1
	  b         .loc_0x13FC

	.loc_0x13EC:
	  lwz       r3, 0xC(r3)

	.loc_0x13F0:
	  cmplwi    r3, 0
	  bne+      .loc_0x13D8
	  li        r0, 0

	.loc_0x13FC:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x14DC
	  li        r3, 0x18
	  bl        -0xAE774
	  mr.       r24, r3
	  beq-      .loc_0x14C0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x258
	  li        r5, 0x1
	  bl        -0xA2A84
	  lis       r4, 0x8023
	  crclr     6, 0x6
	  subi      r0, r4, 0x7730
	  stw       r0, 0x14(r24)
	  li        r0, 0
	  addi      r25, r3, 0
	  stw       r0, 0x8(r24)
	  addi      r3, r1, 0x1B4
	  addi      r4, r30, 0xC
	  lfs       f0, -0x63F4(r2)
	  addi      r6, r30, 0x16C
	  subi      r5, r13, 0x2FF4
	  stfs      f0, 0xC(r24)
	  lfs       f0, -0x63F0(r2)
	  stfs      f0, 0x10(r24)
	  stw       r25, 0x0(r24)
	  lwz       r7, 0x0(r24)
	  stw       r0, 0x24(r7)
	  bl        0x120DB8
	  li        r3, 0xB8
	  bl        -0xAE7E4
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x14A0
	  lis       r6, 0x1
	  addi      r4, r25, 0
	  addi      r5, r1, 0x1B4
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xA4F68

	.loc_0x14A0:
	  stw       r26, 0x4(r24)
	  subi      r0, r13, 0x2FF4
	  addi      r5, r24, 0x8
	  lwz       r3, 0x4(r24)
	  li        r4, 0
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x0(r24)
	  bl        -0xC07C8

	.loc_0x14C0:
	  lwz       r5, 0x88(r31)
	  addi      r3, r31, 0
	  li        r4, 0x10
	  stw       r24, 0x1C(r5)
	  li        r5, 0
	  li        r6, 0
	  bl        -0x1352C

	.loc_0x14DC:
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x24C
	  bl        -0x6F00C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x270
	  bl        -0x6F128
	  mr        r3, r31
	  bl        -0x134C4
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x270
	  bl        -0x6F02C
	  li        r3, 0x48
	  bl        -0xAE878
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x1524
	  mr        r4, r31
	  bl        0x1B00

	.loc_0x1524:
	  stw       r24, 0x64(r31)
	  lmw       r24, 0x548(r1)
	  lwz       r0, 0x56C(r1)
	  addi      r1, r1, 0x568
	  mtlr      r0
	  blr
	*/
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
		gfx._324 = 1;
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
	mItemShapeObject = itemShape;
	mStateMachine    = ai;
	mLifeGauge._1C   = 1;
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
	rumbleMgr->start(7, 0, mPosition);
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
	create(100);
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
