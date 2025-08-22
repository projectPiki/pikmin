#include "Age.h"
#include "BombItem.h"
#include "BuildingItem.h"
#include "DebugLog.h"
#include "DoorItem.h"
#include "GemItem.h"
#include "Generator.h"
#include "GoalItem.h"
#include "ItemMgr.h"
#include "PikiHeadItem.h"
#include "PlayerState.h"
#include "WeedsItem.h"
#include "gameflow.h"
#include "sysNew.h"

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
DEFINE_PRINT("genItem")

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
    , mParameterD(this, 3, 3, 3, "p03", nullptr)
{
	mObjType = 1;
	sprintf(mStageName, " ");
	sprintf(mPrintName, " ");
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
	stream.writeByte(mParameterD() & 255);
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
	mParameterD() = stream.readByte();
}

/*
 * --INFO--
 * Address:	800EE470
 * Size:	000158
 */
static GenObject* makeObjectItem()
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
			mStageName[i] = stream.readByte();
		}

		for (int i = 0; i < 32; i++) {
			mPrintName[i] = stream.readByte();
		}
	} else {
		sprintf(mStageName, " ");
		sprintf(mPrintName, " ");
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
			stream.writeByte(mStageName[i]);
		}

		for (int i = 0; i < 32; i++) {
			stream.writeByte(mPrintName[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
static void sprintID(char*, u32)
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
			GoalItem* goal = (GoalItem*)item;
			goal->setColorType(mParameterA());
			break;
		case OBJTYPE_Rope:
			RopeItem* rope = (RopeItem*)item;
			rope->_2D0     = mParameterA();
			rope->autoInit();
			break;
		case OBJTYPE_GemItem:
			GemItem* gem = (GemItem*)item;
			gem->setColorType(mParameterA());
			break;
		case OBJTYPE_SluiceSoft:
		case OBJTYPE_SluiceHard:
		case OBJTYPE_SluiceBomb:
		case OBJTYPE_SluiceBombHard:
			BuildingItem* wall = (BuildingItem*)item;
			wall->mNumStages   = mParameterD();
			break;
		case OBJTYPE_RockGen:
			RockGen* rock = (RockGen*)item;
			f32 size      = mParameterA();
			if ((f32)mParameterA() <= 0.0f) {
				size = 30.0f;
			}
			rock->setSizeAndNum(size, mParameterD());
			break;
		case OBJTYPE_GrassGen:
			GrassGen* grass = (GrassGen*)item;
			size            = mParameterA();
			if (size <= 0.0f) {
				size = 30.0f;
			}
			grass->setSizeAndNum(size, mParameterD());
			break;
		case OBJTYPE_Weeds:
			WeedsGen* weeds    = (WeedsGen*)item;
			weeds->mWeedsCount = mParameterD();
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
			DoorItem* door              = (DoorItem*)item;
			door->mDestinationStagePath = mStageName;
			door->mLabelText            = mPrintName;
		}

		if (item->mObjType == OBJTYPE_BombGen) {
			s16 val        = mParameterA.mValue;
			BombItem* bomb = (BombItem*)item;
			bomb->_3CA     = val;
			bomb->_3C8     = val;
			bomb->mGrid.updateGrid(item->mPosition);
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
}

#ifdef WIN32

void GenObjectItem::doGenAge(AgeServer& server)
{
	if (getLatestVersion() != 'v0.0') {
		server.NewEditor("stage name", mStageName, 32);
		server.NewEditor("print name", mPrintName, 32);
	}

	server.StartOptionBox("アイテム", &mObjType, 252); // item
	for (int i = 0; i < itemMgr->getNumTemplates(); i++) {
		server.NewOption(ObjType::getName(itemMgr->getTemplateID(i)), i);
	}
	server.EndOptionBox();
}

#endif
