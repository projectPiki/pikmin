#include "Generator.h"
#include "DebugLog.h"
#include "sysNew.h"
#include "ItemMgr.h"
#include "PlayerState.h"
#include "GoalItem.h"
#include "BuildingItem.h"
#include "WeedsItem.h"
#include "DoorItem.h"
#include "GemItem.h"
#include "PikiHeadItem.h"
#include "BombItem.h"
#include "gameflow.h"

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
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
GenObjectItem::GenObjectItem()
    : GenObject('item', "アイテムを生む")
    , mParameterA(this, 0, 0, 0, "p00", nullptr)
    , mParameterB(this, 0, 0, 0, "p01", nullptr)
    , mParameterC(this, 0, 0, 0, "p02", nullptr)
    , _48(this, 3, 3, 3, "p03", nullptr)
{
	mObjType = 1;
	sprintf(mName1, " ");
	sprintf(mName2, " ");
}

/*
 * --INFO--
 * Address:	800EE320
 * Size:	0000A8
 */
void GenObjectItem::ramSaveParameters(RandomAccessStream& stream)
{
	stream.writeByte(mParameterA() + 1);
	stream.writeByte(mParameterB() & 255);
	stream.writeByte(mParameterC() & 255);
	stream.writeByte(_48() & 255);
}

/*
 * --INFO--
 * Address:	800EE3C8
 * Size:	0000A8
 */
void GenObjectItem::ramLoadParameters(RandomAccessStream& stream)
{
	mParameterA() = stream.readByte() - 1;
	mParameterB() = stream.readByte();
	mParameterC() = stream.readByte();
	_48()         = stream.readByte();
}

/*
 * --INFO--
 * Address:	800EE470
 * Size:	000158
 */
GenObject* makeObjectItem()
{
	return new GenObjectItem;
}

/*
 * --INFO--
 * Address:	800EE5C8
 * Size:	00008C
 */
void GenObjectItem::initialise()
{
	GenObjectFactory::factory->registerMember('item', makeObjectItem, "アイテムを発生", 'v0.1');
}

/*
 * --INFO--
 * Address:	800EE654
 * Size:	00011C
 */
void GenObjectItem::doRead(RandomAccessStream& stream)
{
	if (Generator::ramMode) {
		mObjType = stream.readByte();
		return;
	}

	char buffer[256];
	stream.readString(buffer, 0x100);

	mObjType = ObjType::getIndex(buffer);
	if (mObjType == -1) {
		PRINT("ItemGenerator * %s is not item\n", buffer);
	}

	if (mVersion != 'v0.0') {
		for (int i = 0; i < 32; i++) {
			mName1[i] = stream.readByte();
		}

		for (int i = 0; i < 32; i++) {
			mName2[i] = stream.readByte();
		}
	} else {
		sprintf(mName1, " ");
		sprintf(mName2, " ");
	}
}

/*
 * --INFO--
 * Address:	800EE770
 * Size:	000100
 */
void GenObjectItem::doWrite(RandomAccessStream& stream)
{
	if (Generator::ramMode) {
		stream.writeByte(mObjType);
		return;
	}

	stream.writeString(ObjType::getName(mObjType));
	if (getLatestVersion() != 'v0.0') {
		for (int i = 0; i < 32; i++) {
			stream.writeByte(mName1[i]);
		}

		for (int i = 0; i < 32; i++) {
			stream.writeByte(mName2[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void sprintID(char*, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EE870
 * Size:	000030
 */
void GenObjectItem::updateUseList(Generator*, int)
{
	if (mObjType != -1) {
		itemMgr->addUseList(mObjType);
	}
}

/*
 * --INFO--
 * Address:	800EE8A0
 * Size:	000448
 */
Creature* GenObjectItem::birth(BirthInfo& info)
{
	if (mObjType == -1) {
		return nullptr;
	}

	// Has onion check
	if (mObjType == OBJTYPE_Goal) {
		if (!playerState->hasContainer(mParameterA())) {
			if (info.mGenerator->mGeneratorName != 'next') {
				return nullptr;
			}
		} else {
			if (info.mGenerator->mGeneratorName == 'next') {
				return nullptr;
			}
		}
	}

	Creature* item = itemMgr->birth(mObjType);
	if (item) {
		switch (item->mObjType) {
		case OBJTYPE_Goal:
			((GoalItem*)item)->setColorType(mParameterA());
			break;
		case OBJTYPE_Rope:
			((RopeItem*)item)->_2D0 = mParameterA();
			((RopeItem*)item)->autoInit();
			break;
		case OBJTYPE_NULL12:
			((GemItem*)item)->setColorType(mParameterA());
			break;
		case OBJTYPE_SluiceSoft:
		case OBJTYPE_SluiceHard:
		case OBJTYPE_SluiceBomb:
		case OBJTYPE_SluiceBombHard:
			((BuildingItem*)item)->mEndAnimId = _48();
			break;
		case OBJTYPE_RockGen:
			f32 size = mParameterA();
			if ((f32)mParameterA() <= 0.0f) {
				size = 30.0f;
			}
			((RockGen*)item)->setSizeAndNum(size, _48());
			break;
		case OBJTYPE_GrassGen:
			size = mParameterA();
			if ((f32)mParameterA() <= 0.0f) {
				size = 30.0f;
			}
			((GrassGen*)item)->setSizeAndNum(size, _48());
			break;
		case OBJTYPE_Weeds:
			((GrassGen*)item)->mWorkingPikis = _48();
			break;
		}

		int health = mParameterC() + mParameterB() * (int)gameflow.mWorldClock.mHoursInDay;
		item->init(info.mPosition);
		item->mRotation      = info.mRotation;
		item->mFaceDirection = item->mRotation.y;
		item->mGenerator     = info.mGenerator;
		item->mHealth        = health;
		item->mMaxHealth     = item->mHealth;
		item->startAI(0);
		if (info.mGenerator->doAdjustFaceDir()) {
			item->enableFaceDirAdjust();
		}
		char id[8];
		item->mGenerator->mGeneratorName.sprint(id);

		if (mVersion != 'v0.0' && item->mObjType == OBJTYPE_Door) {
			((DoorItem*)item)->mDestinationStagePath = mName1;
			((DoorItem*)item)->mLabelText            = mName2;
		}

		if (item->mObjType == OBJTYPE_BombGen) {
			s16 val                 = mParameterA();
			((BombItem*)item)->_3CA = val;
			((BombItem*)item)->_3C8 = val;
			item->mGrid.updateGrid(item->mPosition);
		}

		if (item->mObjType == OBJTYPE_Pikihead) {
			Iterator it(itemMgr);
			Creature* goal = nullptr;
			f32 maxDist    = 12800.0f;
			CI_LOOP(it)
			{
				Creature* obj = *it;
				if (obj->mObjType == OBJTYPE_Goal) {
					f32 dist = sphereDist(obj, item);
					if (dist < maxDist) {
						maxDist = dist;
						goal    = obj;
					}
				}
			}
			((PikiHeadItem*)item)->_3E0 = goal;
		}
	}
	return item;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stmw      r27, 0x8C(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  lwz       r0, 0x58(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x430

	.loc_0x30:
	  cmpwi     r0, 0x10
	  bne-      .loc_0x9C
	  lwz       r4, 0x2F6C(r13)
	  li        r3, 0x1
	  lwz       r0, 0x24(r29)
	  lbz       r4, 0x184(r4)
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  bne-      .loc_0x78
	  lwz       r5, 0x24(r30)
	  lis       r3, 0x6E65
	  addi      r4, r3, 0x7874
	  addi      r3, r5, 0x58
	  bl        -0xAA910
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0x430

	.loc_0x78:
	  lwz       r5, 0x24(r30)
	  lis       r3, 0x6E65
	  addi      r4, r3, 0x7874
	  addi      r3, r5, 0x58
	  bl        -0xAA948
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0x430

	.loc_0x9C:
	  lwz       r3, 0x30AC(r13)
	  lwz       r4, 0x58(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x42C
	  lwz       r3, 0x6C(r31)
	  subi      r0, r3, 0xC
	  cmplwi    r0, 0x16
	  bgt-      .loc_0x1E4
	  lis       r3, 0x802C
	  subi      r3, r3, 0x2830
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  addi      r4, r29, 0x24
	  lwz       r4, 0x0(r4)
	  addi      r3, r31, 0
	  bl        -0x32A4
	  b         .loc_0x1E4
	  lwz       r0, 0x24(r29)
	  mr        r3, r31
	  stw       r0, 0x2D0(r31)
	  bl        -0xEBC
	  b         .loc_0x1E4
	  addi      r4, r29, 0x24
	  lwz       r4, 0x0(r4)
	  addi      r3, r31, 0
	  bl        -0xA628
	  b         .loc_0x1E4
	  lwz       r0, 0x54(r29)
	  stw       r0, 0x440(r31)
	  b         .loc_0x1E4
	  lwz       r4, 0x24(r29)
	  lis       r0, 0x4330
	  lfd       f2, -0x6460(r2)
	  addi      r3, r31, 0
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x7C(r1)
	  lfs       f0, -0x6470(r2)
	  stw       r0, 0x78(r1)
	  lfd       f1, 0x78(r1)
	  stw       r4, 0x84(r1)
	  fsubs     f1, f1, f2
	  stw       r0, 0x80(r1)
	  fcmpo     cr0, f1, f0
	  lfd       f0, 0x80(r1)
	  fsubs     f1, f0, f2
	  cror      2, 0, 0x2
	  bne-      .loc_0x174
	  lfs       f1, -0x646C(r2)

	.loc_0x174:
	  addi      r4, r29, 0x54
	  lwz       r4, 0x0(r4)
	  bl        -0x9B10
	  b         .loc_0x1E4
	  lwz       r4, 0x24(r29)
	  lis       r0, 0x4330
	  lfd       f2, -0x6460(r2)
	  addi      r3, r31, 0
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x84(r1)
	  lfs       f0, -0x6470(r2)
	  stw       r0, 0x80(r1)
	  lfd       f1, 0x80(r1)
	  stw       r4, 0x7C(r1)
	  fsubs     f1, f1, f2
	  stw       r0, 0x78(r1)
	  fcmpo     cr0, f1, f0
	  lfd       f0, 0x78(r1)
	  fsubs     f1, f0, f2
	  cror      2, 0, 0x2
	  bne-      .loc_0x1CC
	  lfs       f1, -0x646C(r2)

	.loc_0x1CC:
	  addi      r4, r29, 0x54
	  lwz       r4, 0x0(r4)
	  bl        -0x9494
	  b         .loc_0x1E4
	  lwz       r0, 0x54(r29)
	  stw       r0, 0x3C8(r31)

	.loc_0x1E4:
	  lis       r3, 0x803A
	  lwz       r0, 0x34(r29)
	  subi      r3, r3, 0x2848
	  lwz       r6, 0x44(r29)
	  lfs       f0, 0x2DC(r3)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  fctiwz    f0, f0
	  lwz       r12, 0x28(r12)
	  stfd      f0, 0x78(r1)
	  mtlr      r12
	  lwz       r5, 0x7C(r1)
	  mullw     r0, r5, r0
	  add       r28, r6, r0
	  blrl
	  lwz       r4, 0xC(r30)
	  xoris     r3, r28, 0x8000
	  lwz       r5, 0x10(r30)
	  lis       r0, 0x4330
	  stw       r3, 0x84(r1)
	  mr        r3, r31
	  stw       r4, 0x88(r31)
	  li        r4, 0
	  stw       r5, 0x8C(r31)
	  lwz       r5, 0x14(r30)
	  stw       r0, 0x80(r1)
	  stw       r5, 0x90(r31)
	  lfd       f0, 0x80(r1)
	  lfs       f1, 0x8C(r31)
	  stfs      f1, 0xA0(r31)
	  lwz       r0, 0x24(r30)
	  stw       r0, 0x64(r31)
	  lfd       f1, -0x6460(r2)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x58(r31)
	  lfs       f0, 0x58(r31)
	  stfs      f0, 0x5C(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r30)
	  lwz       r3, 0x28(r3)
	  lwz       r0, 0x34(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x2AC
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x1
	  stw       r0, 0xC8(r31)

	.loc_0x2AC:
	  lwz       r3, 0x64(r31)
	  addi      r4, r1, 0x64
	  addi      r3, r3, 0x58
	  bl        -0xAA9FC
	  lwz       r3, 0xC(r29)
	  subis     r0, r3, 0x7630
	  cmplwi    r0, 0x2E30
	  beq-      .loc_0x2E8
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x2E8
	  addi      r0, r29, 0x5C
	  stw       r0, 0x3D0(r31)
	  addi      r0, r29, 0x7C
	  stw       r0, 0x3D4(r31)

	.loc_0x2E8:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xD
	  bne-      .loc_0x310
	  lwz       r0, 0x24(r29)
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  extsh     r0, r0
	  sth       r0, 0x3CA(r31)
	  sth       r0, 0x3C8(r31)
	  bl        -0x5A68C

	.loc_0x310:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xF
	  bne-      .loc_0x42C
	  lwz       r30, 0x30AC(r13)
	  li        r27, 0
	  lfs       f31, -0x6468(r2)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x3CC

	.loc_0x344:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x36C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x388

	.loc_0x36C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x388:
	  lwz       r0, 0x6C(r29)
	  addi      r3, r29, 0
	  cmpwi     r0, 0x10
	  bne-      .loc_0x3B0
	  mr        r4, r31
	  bl        -0x6311C
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x3B0
	  fmr       f31, f1
	  mr        r27, r29

	.loc_0x3B0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x3CC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3F4
	  li        r0, 0x1
	  b         .loc_0x420

	.loc_0x3F4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x41C
	  li        r0, 0x1
	  b         .loc_0x420

	.loc_0x41C:
	  li        r0, 0

	.loc_0x420:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x344
	  stw       r27, 0x3E0(r31)

	.loc_0x42C:
	  mr        r3, r31

	.loc_0x430:
	  lmw       r27, 0x8C(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}
