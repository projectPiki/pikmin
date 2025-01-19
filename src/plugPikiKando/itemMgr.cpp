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
#include "sysNew.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
	MeltingPotMgr* mgr = mMeltingPotMgr;
	if (!mgr) {
		return nullptr;
	}
	Iterator iter(mgr);
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  addi      r29, r4, 0
	  lwz       r30, 0x68(r3)
	  cmplwi    r30, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x120

	.loc_0x30:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0xC0

	.loc_0x4C:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x70
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x88

	.loc_0x70:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x88:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x10
	  bne-      .loc_0xA4
	  lhz       r0, 0x428(r3)
	  cmpw      r0, r29
	  bne-      .loc_0xA4
	  b         .loc_0x120

	.loc_0xA4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0xC0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE8
	  li        r0, 0x1
	  b         .loc_0x114

	.loc_0xE8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x110
	  li        r0, 0x1
	  b         .loc_0x114

	.loc_0x110:
	  li        r0, 0

	.loc_0x114:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4C
	  li        r3, 0

	.loc_0x120:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  fmr       f31, f1
	  stmw      r27, 0x34(r1)
	  addi      r27, r4, 0
	  li        r29, 0
	  lwz       r31, 0x68(r3)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xCC

	.loc_0x40:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x64
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x7C

	.loc_0x64:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x7C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x10
	  bne-      .loc_0xB0
	  lfs       f1, 0x94(r3)
	  mr        r28, r3
	  lfs       f2, 0x9C(r3)
	  lfs       f3, 0x0(r27)
	  lfs       f4, 0x8(r27)
	  bl        -0xBA568
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0xB0
	  fmr       f31, f1
	  mr        r29, r28

	.loc_0xB0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xCC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF4
	  li        r0, 0x1
	  b         .loc_0x120

	.loc_0xF4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x11C
	  li        r0, 0x1
	  b         .loc_0x120

	.loc_0x11C:
	  li        r0, 0

	.loc_0x120:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40
	  mr        r3, r29
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2C38
 * Size:	000114
 */
UfoItem* ItemMgr::getUfo()
{
	Iterator iter(mMeltingPotMgr);
	CI_LOOP(iter)
	{
		Creature* creature = *iter;
		if (creature->mObjType == OBJTYPE_Ufo) {
			return static_cast<UfoItem*>(creature);
		}
	}

	return nullptr;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  lwz       r31, 0x68(r3)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x9C

	.loc_0x34:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x70

	.loc_0x58:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0x80
	  b         .loc_0xFC

	.loc_0x80:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x9C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC4
	  li        r0, 0x1
	  b         .loc_0xF0

	.loc_0xC4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xEC
	  li        r0, 0x1
	  b         .loc_0xF0

	.loc_0xEC:
	  li        r0, 0

	.loc_0xF0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x34
	  li        r3, 0

	.loc_0xFC:
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
 * Address:	........
 * Size:	000110
 */
ItemShapeObject::ItemShapeObject(Shape* shape, char* objName, char* file)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;
	char buf[128];
	sprintf(buf, "objects/%s/%s", objName, file);
	mAnimMgr = new AnimMgr(shape, buf, 0x8000, nullptr);
	mAnimMgr->setName(objName);
	mShape->overrideAnim(0, &mAnimContext);
	// UNUSED FUNCTION
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
			GoalItem* goal = static_cast<GoalItem*>(creature);
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

	_4C = gameflow.loadShape("objects/weeds/stone1.mod", true);
	_50 = gameflow.loadShape("objects/weeds/stone2.mod", true);
	_54 = gameflow.loadShape("objects/weeds/stone3.mod", true);
	_58 = gameflow.loadShape("objects/weeds/weed1.mod", true);
	_5C = gameflow.loadShape("objects/weeds/weed1.mod", true);
	_60 = gameflow.loadShape("objects/weeds/weed1.mod", true);

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
	// UNUSED FUNCTION
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
	// UNUSED FUNCTION
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

	Shape* seedShapes[2];
	seedShapes[0] = gameflow.loadShape("pikis/happas/leaf.mod", true);
	seedShapes[1] = gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);

	registerClass(OBJTYPE_Rope, new RopeItem(new RopeProp(), nullptr), sizeof(RopeItem));

	registerClass(OBJTYPE_Fulcrum, new Fulcrum(), sizeof(Fulcrum));

	registerClass(OBJTYPE_Seed, new SeedItem(new SeedProp(), seedShapes), sizeof(SeedItem));

	registerClass(OBJTYPE_Key, new KeyItem(new KeyProp(), nullptr), sizeof(KeyItem));

	registerClass(OBJTYPE_Door, new DoorItem(OBJTYPE_Door, new DoorProp(), nullptr), sizeof(DoorItem));
	registerClass(OBJTYPE_Gate, new DoorItem(OBJTYPE_Gate, new DoorProp(), nullptr), sizeof(DoorItem));
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
	if (mItemAnimator.mMotionIdx < 0) {
		return "NULL";
	}

	return PaniItemAnimator::motionLabels[mItemAnimator.mMotionIdx];
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
void ItemCreature::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x98(r1)
	  mr        r30, r3
	  stw       r29, 0x94(r1)
	  li        r29, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x94
	  bl        -0xB4730
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x5C
	  lwz       r0, 0xC8(r30)
	  li        r29, 0x1
	  oris      r0, r0, 0x8
	  stw       r0, 0xC8(r30)
	  b         .loc_0x68

	.loc_0x5C:
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,13,11
	  stw       r0, 0xC8(r30)

	.loc_0x68:
	  lwz       r0, 0x3C0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x114
	  li        r0, 0
	  stb       r0, 0x3C4(r30)
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xB7C10
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x50
	  addi      r3, r3, 0x1E0
	  bl        -0xB7C44
	  addi      r3, r30, 0x36C
	  lwz       r12, 0x39C(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3C0(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x50
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0xC0A30
	  rlwinm.   r0,r29,0,24,31
	  bne-      .loc_0x204
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3C0(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  bl        -0xC5918
	  b         .loc_0x204

	.loc_0x114:
	  lwz       r0, 0x308(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x204
	  rlwinm.   r0,r29,0,24,31
	  bne-      .loc_0x204
	  lwz       r3, 0x6C(r30)
	  bl        -0x6136C
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xB7CC4
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stw       r0, 0x324(r31)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x10
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r30, 0x94
	  lwz       r4, 0x2E4(r31)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x160(r4)

	.loc_0x1C0:
	  lwz       r3, 0x308(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0xC59DC
	  lwz       r4, 0x2E4(r31)
	  li        r0, 0
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x204
	  lwz       r3, 0x0(r0)
	  lwz       r0, 0x4(r0)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x8(r0)
	  stw       r0, 0x160(r4)

	.loc_0x204:
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
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
	if (item->mObjType == OBJTYPE_BoBase) {
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
	if (item->mObjType == OBJTYPE_Pikihead) {
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
	if (item->mObjType == OBJTYPE_NULL12) {
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
bool InteractBomb::actItem(ItemCreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  addi      r29, r3, 0
	  lwz       r5, 0x6C(r4)
	  li        r4, 0x1
	  addi      r3, r4, 0
	  cmpwi     r5, 0x16
	  addi      r0, r4, 0
	  beq-      .loc_0x4C
	  cmpwi     r5, 0x17
	  beq-      .loc_0x4C
	  li        r0, 0

	.loc_0x4C:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x60
	  cmpwi     r5, 0x18
	  beq-      .loc_0x60
	  li        r3, 0

	.loc_0x60:
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x74
	  cmpwi     r5, 0x19
	  beq-      .loc_0x74
	  li        r4, 0

	.loc_0x74:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x234
	  lwz       r3, 0x444(r31)
	  lwz       r0, 0x440(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x94
	  li        r3, 0
	  b         .loc_0x2B0

	.loc_0x94:
	  cmpwi     r5, 0x17
	  beq-      .loc_0xC0
	  bge-      .loc_0xD0
	  cmpwi     r5, 0x16
	  bge-      .loc_0xAC
	  b         .loc_0xD0

	.loc_0xAC:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAA
	  bl        -0x6BB44
	  b         .loc_0xD0

	.loc_0xC0:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAF
	  bl        -0x6BB58

	.loc_0xD0:
	  lfs       f1, 0x58(r31)
	  lis       r30, 0x4330
	  lfs       f0, 0x8(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r0, 0x440(r31)
	  lfd       f30, -0x63C8(r2)
	  xoris     r0, r0, 0x8000
	  lfs       f3, 0x5C(r31)
	  stw       r0, 0x44(r1)
	  lwz       r3, 0x444(r31)
	  stw       r30, 0x40(r1)
	  addi      r0, r3, 0x1
	  lfs       f0, 0x58(r31)
	  lfd       f1, 0x40(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x4C(r1)
	  fsubs     f1, f1, f30
	  stw       r30, 0x48(r1)
	  fdivs     f1, f3, f1
	  lfd       f2, 0x48(r1)
	  fsubs     f2, f2, f30
	  fmuls     f1, f2, f1
	  fsubs     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x200
	  lfs       f31, -0x63F4(r2)
	  li        r29, 0
	  b         .loc_0x1E4

	.loc_0x148:
	  li        r0, 0xA
	  stw       r0, 0x34(r1)
	  li        r0, 0
	  addi      r4, r31, 0
	  stw       r0, 0x38(r1)
	  addi      r5, r1, 0x34
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x444(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x444(r31)
	  lwz       r3, 0x444(r31)
	  lwz       r0, 0x440(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x1A0
	  stfs      f31, 0x58(r31)
	  li        r3, 0x11B
	  bl        -0x50E64
	  li        r29, 0x1

	.loc_0x1A0:
	  lwz       r0, 0x440(r31)
	  lwz       r3, 0x444(r31)
	  xoris     r0, r0, 0x8000
	  lfs       f2, 0x5C(r31)
	  stw       r0, 0x4C(r1)
	  addi      r0, r3, 0x1
	  xoris     r0, r0, 0x8000
	  stw       r30, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  stw       r0, 0x44(r1)
	  fsubs     f0, f0, f30
	  stw       r30, 0x40(r1)
	  fdivs     f0, f2, f0
	  lfd       f1, 0x40(r1)
	  fsubs     f1, f1, f30
	  fmuls     f0, f1, f0
	  fsubs     f1, f2, f0

	.loc_0x1E4:
	  lfs       f0, 0x58(r31)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x22C
	  rlwinm.   r0,r29,0,24,31
	  beq+      .loc_0x148
	  b         .loc_0x22C

	.loc_0x200:
	  li        r0, 0xA
	  stw       r0, 0x2C(r1)
	  li        r0, 0x1
	  addi      r4, r31, 0
	  stw       r0, 0x30(r1)
	  addi      r5, r1, 0x2C
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x22C:
	  li        r3, 0x1
	  b         .loc_0x2B0

	.loc_0x234:
	  cmpwi     r5, 0xE
	  bne-      .loc_0x2AC
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x260
	  lwz       r0, 0x4(r3)
	  b         .loc_0x264

	.loc_0x260:
	  li        r0, -0x1

	.loc_0x264:
	  cmpwi     r0, 0x3
	  beq-      .loc_0x2AC
	  cmpwi     r0, 0x4
	  beq-      .loc_0x2AC
	  cmpwi     r0, 0x5
	  beq-      .loc_0x2AC
	  li        r0, 0xA
	  stw       r0, 0x1C(r1)
	  li        r0, 0x1
	  addi      r4, r31, 0
	  stw       r0, 0x20(r1)
	  addi      r5, r1, 0x1C
	  stw       r0, 0x2D0(r31)
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x2AC:
	  li        r3, 0

	.loc_0x2B0:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F6314
 * Size:	000060
 */
void BuildingItem::playEffect(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  addi      r4, r3, 0
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x1C
	  b         .loc_0x50

	.loc_0x1C:
	  lwz       r3, 0x444(r4)
	  lwz       r0, 0x440(r4)
	  cmpw      r3, r0
	  blt-      .loc_0x40
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r4, 0x94
	  li        r4, 0x4
	  bl        0x2DC8C
	  b         .loc_0x50

	.loc_0x40:
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r4, 0x94
	  li        r4, 0x2
	  bl        0x2DC78

	.loc_0x50:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F6374
 * Size:	000270
 */
bool InteractAttack::actItem(ItemCreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  addi      r29, r3, 0
	  lwz       r5, 0x6C(r4)
	  cmpwi     r5, 0x18
	  beq-      .loc_0x3C
	  cmpwi     r5, 0x19
	  bne-      .loc_0x54

	.loc_0x3C:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAC
	  bl        -0x6BE08
	  li        r3, 0
	  b         .loc_0x24C

	.loc_0x54:
	  subi      r0, r5, 0x16
	  cmplwi    r0, 0x1
	  li        r3, 0x1
	  addi      r4, r3, 0
	  addi      r0, r3, 0
	  ble-      .loc_0x70
	  li        r0, 0

	.loc_0x70:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x84
	  cmpwi     r5, 0x18
	  beq-      .loc_0x84
	  li        r4, 0

	.loc_0x84:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x98
	  cmpwi     r5, 0x19
	  beq-      .loc_0x98
	  li        r3, 0

	.loc_0x98:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x248
	  lwz       r3, 0x444(r31)
	  lwz       r0, 0x440(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xB8
	  li        r3, 0
	  b         .loc_0x24C

	.loc_0xB8:
	  cmpwi     r5, 0x16
	  bne-      .loc_0xD4
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAA
	  bl        -0x6BE8C
	  b         .loc_0xE4

	.loc_0xD4:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAF
	  bl        -0x6BEA0

	.loc_0xE4:
	  lfs       f1, 0x58(r31)
	  lis       r30, 0x4330
	  lfs       f0, 0x8(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r0, 0x440(r31)
	  lfd       f30, -0x63C8(r2)
	  xoris     r0, r0, 0x8000
	  lfs       f3, 0x5C(r31)
	  stw       r0, 0x24(r1)
	  lwz       r3, 0x444(r31)
	  stw       r30, 0x20(r1)
	  addi      r0, r3, 0x1
	  lfs       f0, 0x58(r31)
	  lfd       f1, 0x20(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x2C(r1)
	  fsubs     f1, f1, f30
	  stw       r30, 0x28(r1)
	  fdivs     f1, f3, f1
	  lfd       f2, 0x28(r1)
	  fsubs     f2, f2, f30
	  fmuls     f1, f2, f1
	  fsubs     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x214
	  lfs       f31, -0x63F4(r2)
	  li        r29, 0
	  b         .loc_0x1F8

	.loc_0x15C:
	  li        r0, 0xA
	  stw       r0, 0x18(r1)
	  li        r0, 0
	  addi      r4, r31, 0
	  stw       r0, 0x1C(r1)
	  addi      r5, r1, 0x18
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x444(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x444(r31)
	  lwz       r3, 0x444(r31)
	  lwz       r0, 0x440(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x1B4
	  stfs      f31, 0x58(r31)
	  li        r3, 0x11B
	  bl        -0x511AC
	  li        r29, 0x1

	.loc_0x1B4:
	  lwz       r0, 0x440(r31)
	  lwz       r3, 0x444(r31)
	  xoris     r0, r0, 0x8000
	  lfs       f2, 0x5C(r31)
	  stw       r0, 0x2C(r1)
	  addi      r0, r3, 0x1
	  xoris     r0, r0, 0x8000
	  stw       r30, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  stw       r0, 0x24(r1)
	  fsubs     f0, f0, f30
	  stw       r30, 0x20(r1)
	  fdivs     f0, f2, f0
	  lfd       f1, 0x20(r1)
	  fsubs     f1, f1, f30
	  fmuls     f0, f1, f0
	  fsubs     f1, f2, f0

	.loc_0x1F8:
	  lfs       f0, 0x58(r31)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x240
	  rlwinm.   r0,r29,0,24,31
	  beq+      .loc_0x15C
	  b         .loc_0x240

	.loc_0x214:
	  li        r0, 0xA
	  stw       r0, 0x10(r1)
	  li        r0, 0x1
	  addi      r4, r31, 0
	  stw       r0, 0x14(r1)
	  addi      r5, r1, 0x10
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x240:
	  li        r3, 0x1
	  b         .loc_0x24C

	.loc_0x248:
	  li        r3, 0

	.loc_0x24C:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F65E4
 * Size:	000144
 */
BuildingItem::BuildingItem(int objType, CreatureProp* props, ItemShapeObject* itemShape, SimpleAI* ai)
    : ItemCreature(objType, props, nullptr)
    , _3C8(0)
    , _3CC(0)
    , _3D0(0)
    , _3D4(0)
    , mEndAnimId(0)
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        -0x6CBF8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4C
	  lis       r4, 0x666C
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x6167
	  bl        -0x6D050
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  lfs       f1, 0x0(r3)
	  b         .loc_0x50

	.loc_0x4C:
	  lfs       f1, -0x63C0(r2)

	.loc_0x50:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F678C
 * Size:	0001C8
 */
void BuildingItem::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  addi      r4, r31, 0x3C8
	  stw       r30, 0x20(r1)
	  lwz       r3, 0x3C0(r3)
	  lwz       r3, 0x0(r3)
	  bl        -0xC6E88
	  li        r30, 0
	  stw       r30, 0x2D4(r31)
	  li        r3, 0x1
	  addi      r0, r31, 0x8A4
	  stw       r30, 0x2D0(r31)
	  addi      r4, r31, 0
	  li        r5, 0x4
	  stb       r3, 0x3C4(r31)
	  stw       r0, 0x2C(r31)
	  lwz       r3, 0x2C(r31)
	  bl        -0x52AAC
	  lwz       r0, 0xC8(r31)
	  addi      r3, r1, 0x10
	  li        r4, 0
	  oris      r0, r0, 0x1
	  stw       r0, 0xC8(r31)
	  bl        0x28760
	  addi      r4, r3, 0
	  addi      r3, r31, 0x36C
	  bl        0x289BC
	  lfs       f0, 0x5C(r31)
	  mr        r3, r31
	  stfs      f0, 0x58(r31)
	  stw       r30, 0x444(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x150(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x63E8(r2)
	  addi      r0, r31, 0x458
	  addi      r5, r31, 0x46C
	  stfs      f0, 0x7C(r31)
	  addi      r6, r31, 0x87C
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  stw       r0, 0x220(r31)
	  lwz       r4, 0x3C0(r31)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x0(r4)
	  bl        -0x6CCF0
	  lwz       r3, 0x3C0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  lwz       r6, 0x0(r3)
	  cmplwi    r6, 0
	  beq-      .loc_0xF4
	  lwz       r5, 0x2F00(r13)
	  addi      r4, r31, 0
	  addi      r3, r31, 0x3F8
	  bl        -0x687BC

	.loc_0xF4:
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  addi      r5, r31, 0x94
	  bl        -0x55354
	  stw       r3, 0x454(r31)
	  addi      r4, r31, 0
	  li        r5, 0x1
	  lwz       r6, 0x454(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x0(r6)
	  stw       r0, 0x4(r6)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x8(r6)
	  lwz       r3, 0x2E8(r31)
	  bl        -0x79168
	  lwz       r3, 0x94(r31)
	  li        r4, 0x1
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x448(r31)
	  stw       r0, 0x44C(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x450(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x8E9E8
	  stfs      f1, 0x44C(r31)
	  lfs       f0, 0x44C(r31)
	  stfs      f0, 0x98(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1E0(r31)
	  stw       r0, 0x1E4(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1E8(r31)
	  lfs       f1, 0x1E4(r31)
	  lfs       f0, -0x63BC(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1E4(r31)
	  lfs       f0, -0x2FE4(r13)
	  stfs      f0, 0x1EC(r31)
	  lfs       f0, -0x2FE0(r13)
	  stfs      f0, 0x1F0(r31)
	  lfs       f0, -0x2FDC(r13)
	  stfs      f0, 0x1F4(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F6954
 * Size:	000090
 */
void BuildingItem::startBreakEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xAB
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  bl        -0x6C3BC
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x7
	  li        r5, 0
	  bl        0x86450
	  addi      r3, r31, 0x3D8
	  addi      r4, r31, 0x94
	  li        r5, 0xDD
	  bl        0x1DA08
	  addi      r3, r31, 0x3E8
	  addi      r4, r31, 0x94
	  li        r5, 0xDC
	  bl        0x1D9F8
	  lwz       r3, 0x3E4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  lfs       f0, -0x63B8(r2)
	  stfs      f0, 0xB8(r3)

	.loc_0x68:
	  lwz       r3, 0x3F4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  lfs       f0, -0x63B4(r2)
	  stfs      f0, 0xB8(r3)

	.loc_0x7C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F69E4
 * Size:	000060
 */
void BuildingItem::stopBreakEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r3, 0x3E4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lfs       f0, -0x63F4(r2)
	  stfs      f0, 0xB8(r3)

	.loc_0x28:
	  lwz       r3, 0x3F4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lfs       f0, -0x63F4(r2)
	  stfs      f0, 0xB8(r3)

	.loc_0x3C:
	  addi      r3, r31, 0x3D8
	  bl        0x1DAF0
	  addi      r3, r31, 0x3E8
	  bl        0x1DAE8
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F6A44
 * Size:	000054
 */
void BuildingItem::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x6B8C0
	  addi      r3, r31, 0x3D8
	  addi      r4, r31, 0x94
	  bl        0x1D9C4
	  addi      r3, r31, 0x3E8
	  addi      r4, r31, 0x94
	  bl        0x1D9B8
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f2, 0x5C(r31)
	  bl        -0x9AA0C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F6A98
 * Size:	0001A4
 */
void BuildingItem::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x5C(r1)
	  addi      r29, r3, 0
	  lfs       f0, -0x63F4(r2)
	  stfs      f0, 0x50(r1)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x16
	  bne-      .loc_0x3C
	  stfs      f0, 0x50(r1)
	  b         .loc_0x6C

	.loc_0x3C:
	  cmpwi     r0, 0x17
	  bne-      .loc_0x50
	  lfs       f0, -0x63E8(r2)
	  stfs      f0, 0x50(r1)
	  b         .loc_0x6C

	.loc_0x50:
	  cmpwi     r0, 0x18
	  bne-      .loc_0x64
	  lfs       f0, -0x63E8(r2)
	  stfs      f0, 0x50(r1)
	  b         .loc_0x6C

	.loc_0x64:
	  lfs       f0, -0x63D8(r2)
	  stfs      f0, 0x50(r1)

	.loc_0x6C:
	  addi      r3, r29, 0x3C8
	  addi      r4, r1, 0x50
	  bl        -0xC7A70
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r31, 0
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r30)
	  addi      r4, r29, 0x94
	  bl        -0xB55AC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB8
	  lwz       r0, 0xC8(r29)
	  li        r31, 0x1
	  oris      r0, r0, 0x8
	  stw       r0, 0xC8(r29)
	  b         .loc_0xC4

	.loc_0xB8:
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,13,11
	  stw       r0, 0xC8(r29)

	.loc_0xC4:
	  lwz       r0, 0x3C0(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x16C
	  li        r0, 0
	  stb       r0, 0x3C4(r29)
	  addi      r3, r29, 0x228
	  addi      r4, r29, 0x7C
	  addi      r5, r29, 0x88
	  addi      r6, r29, 0x94
	  bl        -0xB8A8C
	  lwz       r3, 0x2E4(r30)
	  addi      r4, r29, 0x228
	  addi      r5, r1, 0x10
	  addi      r3, r3, 0x1E0
	  bl        -0xB8AC0
	  addi      r3, r29, 0x36C
	  lwz       r12, 0x39C(r29)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3C0(r29)
	  addi      r4, r30, 0
	  addi      r5, r1, 0x10
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0xC18AC
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0x16C
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  mr        r3, r30
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3C0(r29)
	  mr        r4, r30
	  lwz       r5, 0x2E4(r30)
	  addi      r6, r29, 0x3C8
	  lwz       r3, 0x0(r3)
	  bl        -0xC6794

	.loc_0x16C:
	  addi      r3, r29, 0x3F8
	  addi      r4, r30, 0
	  bl        -0x68A44
	  lwz       r3, 0x220(r29)
	  addi      r4, r30, 0
	  li        r5, 0
	  bl        -0x6D130
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x3F8
	  bl        -0x68AF8
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x7C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
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
	output.writeInt(mStartAnimId);
	output.writeInt(mEndAnimId);
	output.writeInt(_2D0);
}

/*
 * --INFO--
 * Address:	800F6D34
 * Size:	00017C
 */
void BuildingItem::doLoad(RandomAccessStream& input)
{
	mHealth      = input.readFloat();
	mMaxHealth   = input.readFloat();
	mStartAnimId = input.readInt();
	mEndAnimId   = input.readInt();
	_2D0         = input.readInt();
	if (mStartAnimId < mEndAnimId) {
		startMotion(mStartAnimId);
		mWayPoint->setFlag(false);
	} else {
		startMotion(mEndAnimId - 1);
		int aKeys = mItemAnimator.mAnimInfo->countAKeys() - 1;
		startMotion(mEndAnimId - 1, mItemAnimator.mAnimInfo->getKeyValue(aKeys) - 1.0f);
		mWayPoint->setFlag(true);
	}

	stopMotion();
	static_cast<SimpleAI*>(mStateMachine)->start(this, 1);
}

/*
 * --INFO--
 * Address:	800F6EB0
 * Size:	000024
 */
void BuildingItem::doStore(CreatureInf* info)
{
	info->mHealth      = mHealth;
	info->mMaxHealth   = mMaxHealth;
	info->mStartAnimId = mStartAnimId;
	info->mEndAnimId   = mEndAnimId;
}

/*
 * --INFO--
 * Address:	800F6ED4
 * Size:	000120
 */
void BuildingItem::doRestore(CreatureInf* info)
{
	startAI(0);

	mHealth      = info->mHealth;
	mMaxHealth   = info->mMaxHealth;
	mStartAnimId = info->mStartAnimId;
	mEndAnimId   = info->mEndAnimId;

	// When restoring from a save, if the start is less than the end,
	// We can start the 'start' animation, and disable the waypoint
	if (mStartAnimId < mEndAnimId) {
		startMotion(mStartAnimId);
		mWayPoint->setFlag(false);
	}
	// Otherwise, we reset the object to its final animation state,
	// I.e. gate is underground, like at the end of its 'fall' animation
	else {
		int finalKeyframeIdx = mItemAnimator.mAnimInfo->countAKeys() - 1;
		startMotion(mEndAnimId - 1, mItemAnimator.mAnimInfo->getKeyValue(finalKeyframeIdx) - 1.0f);
		mWayPoint->setFlag(true);
	}

	// Don't actually animate, just start it to apply the transformation
	stopMotion();

	// Begin the AI
	static_cast<SimpleAI*>(mStateMachine)->start(this, 1);
}

/*
 * --INFO--
 * Address:	800F6FF4
 * Size:	000068
 */
Creature* ItemMgr::birth(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  subi      r0, r4, 0xF
	  cmplwi    r0, 0x16
	  stwu      r1, -0x8(r1)
	  bgt-      .loc_0x54
	  lis       r5, 0x802C
	  subi      r5, r5, 0x188C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r5, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x64(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x58
	  lwz       r3, 0x68(r3)
	  bl        -0x3A60
	  b         .loc_0x58

	.loc_0x54:
	  bl        -0x14C28

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F705C
 * Size:	000068
 */
void ItemMgr::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x14EA4
	  lwz       r3, 0x64(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x68(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F70C4
 * Size:	000204
 */
void ItemMgr::refresh2d(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  stw       r29, 0x3C(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0xA4

	.loc_0x38:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0xF0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0xA4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCC
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xCC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xF4
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xF4:
	  li        r0, 0

	.loc_0xF8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lwz       r29, 0x68(r30)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x18C

	.loc_0x120:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x144
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x15C

	.loc_0x144:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x15C:
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0xF0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x18C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B4
	  li        r0, 0x1
	  b         .loc_0x1E0

	.loc_0x1B4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1DC
	  li        r0, 0x1
	  b         .loc_0x1E0

	.loc_0x1DC:
	  li        r0, 0

	.loc_0x1E0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x120
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F72C8
 * Size:	000064
 */
void ItemMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lhz       r0, 0x30C8(r13)
	  rlwinm.   r0,r0,0,16,16
	  bne-      .loc_0x3C
	  mr        r3, r31
	  bl        -0x152CC
	  lwz       r3, 0x64(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C:
	  lwz       r3, 0x68(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F732C
 * Size:	000064
 */
void ItemMgr::kill(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x10
	  beq-      .loc_0x54
	  bge-      .loc_0x28
	  cmpwi     r0, 0xF
	  bge-      .loc_0x34
	  b         .loc_0x50

	.loc_0x28:
	  cmpwi     r0, 0x1E
	  beq-      .loc_0x54
	  b         .loc_0x50

	.loc_0x34:
	  lwz       r3, 0x64(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x7C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x54
	  b         .loc_0x54

	.loc_0x50:
	  bl        -0x14E40

	.loc_0x54:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7390
 * Size:	0001D8
 */
PikiHeadMgr::PikiHeadMgr(ItemMgr* mgr)
{
	mItemMgr       = mgr;
	mPikiHeadProps = new PikiHeadItemProp();
	mPikiHeadAI    = new PikiHeadAI();
	create(100);
}

/*
 * --INFO--
 * Address:	800F7568
 * Size:	0000A0
 */
Creature* PikiHeadMgr::birth()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x1EC4
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r5, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  add       r31, r0, r5
	  lwz       r3, 0x3C(r3)
	  add       r31, r4, r31
	  bl        0xC8
	  lbz       r0, 0x30A8(r13)
	  add       r31, r31, r3
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lwz       r3, 0x2F80(r13)
	  lwz       r3, 0x120(r3)
	  addi      r0, r3, 0x1
	  cmpw      r31, r0
	  blt-      .loc_0x80
	  li        r3, 0
	  b         .loc_0x88

	.loc_0x68:
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x120(r3)
	  cmpw      r31, r0
	  blt-      .loc_0x80
	  li        r3, 0
	  b         .loc_0x88

	.loc_0x80:
	  mr        r3, r30
	  bl        -0x16178

	.loc_0x88:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7608
 * Size:	000060
 */
PikiHeadItem* PikiHeadMgr::createObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  li        r3, 0x3F8
	  bl        -0xB0620
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x44
	  lwz       r5, 0x3C(r30)
	  lwz       r4, 0x40(r30)
	  lwz       r5, 0x88(r5)
	  lwz       r6, 0x44(r30)
	  lwz       r5, 0xC(r5)
	  bl        -0xAFAC

	.loc_0x44:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7668
 * Size:	00014C
 */
int ItemMgr::getContainerExitCount()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  li        r30, 0
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0

	.loc_0x24:
	  lwz       r0, 0x68(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x110

	.loc_0x38:
	  stw       r0, 0x14(r1)
	  li        r0, 0
	  addi      r3, r1, 0x10
	  stw       r0, 0x18(r1)
	  bl        -0x678F4
	  b         .loc_0xB0

	.loc_0x50:
	  lwz       r4, 0x10(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x78
	  lwz       r3, 0x14(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x8C

	.loc_0x78:
	  lwz       r3, 0x14(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x8C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x10
	  bne-      .loc_0xA8
	  lhz       r0, 0x428(r3)
	  cmpw      r0, r30
	  bne-      .loc_0xA8
	  b         .loc_0x110

	.loc_0xA8:
	  addi      r3, r1, 0x10
	  bl        -0x67A7C

	.loc_0xB0:
	  lwz       r3, 0x14(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD8
	  li        r0, 0x1
	  b         .loc_0x104

	.loc_0xD8:
	  lwz       r3, 0x14(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x100
	  li        r0, 0x1
	  b         .loc_0x104

	.loc_0x100:
	  li        r0, 0

	.loc_0x104:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x50
	  li        r3, 0

	.loc_0x110:
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  lwz       r0, 0x414(r3)
	  add       r31, r31, r0

	.loc_0x120:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x3
	  blt+      .loc_0x24
	  mr        r3, r31
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F77B4
 * Size:	000084
 */
PikiHeadMgr::~PikiHeadMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x1758
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x5038
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)

	.loc_0x5C:
	  extsh.    r0, r4
	  ble-      .loc_0x6C
	  mr        r3, r31
	  bl        -0xB0670

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7838
 * Size:	000084
 */
ItemMgr::~ItemMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x1628
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x50F4
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)

	.loc_0x5C:
	  extsh.    r0, r4
	  ble-      .loc_0x6C
	  mr        r3, r31
	  bl        -0xB06F4

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F78BC
 * Size:	000084
 */
MeltingPotMgr::~MeltingPotMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x10C8
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x51A8
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)

	.loc_0x5C:
	  extsh.    r0, r4
	  ble-      .loc_0x6C
	  mr        r3, r31
	  bl        -0xB0778

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7940
 * Size:	000008
 */
f32 BuildingItem::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x63F4(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7948
 * Size:	000008
 */
bool BuildingItem::needShadow()
{
	return false;
}
