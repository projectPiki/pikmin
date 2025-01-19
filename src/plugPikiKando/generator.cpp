#include "Generator.h"
#include "Graphics.h"
#include "gameflow.h"
#include "NaviMgr.h"
#include "GlobalShape.h"
#include "PikiMgr.h"
#include "teki.h"
#include "PikiHeadItem.h"
#include "GameStat.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("generator");

bool Generator::ramMode;
GenObjectFactory* GenObjectFactory::factory;
GenTypeFactory* GenTypeFactory::factory;
GenAreaFactory* GenAreaFactory::factory;
GeneratorMgr* generatorMgr;
GeneratorMgr* plantGeneratorMgr;
GeneratorMgr* dailyGeneratorMgr;
GeneratorMgr* onceGeneratorMgr;
GeneratorMgr* limitGeneratorMgr;
GeneratorList* generatorList;

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void writeID(RandomAccessStream& output, u32 id)
{
	u8* outID = reinterpret_cast<u8*>(&id);

	output.writeByte(outID[3]);
	output.writeByte(outID[2]);
	output.writeByte(outID[1]);
	output.writeByte(outID[0]);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
u32 readID(RandomAccessStream& input)
{
	// the stack is wrong here somehow.
	u32 outID;
	u8* id = reinterpret_cast<u8*>(&outID);
	id[3]  = input.readByte();
	id[2]  = input.readByte();
	id[1]  = input.readByte();
	id[0]  = input.readByte();
	return outID;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void printID(u32)
{
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
 * Address:	800DACB4
 * Size:	000030
 */
GenBase::GenBase(u32 id, char* type, char* name)
    : mID(id)
    , mType(type)
    , mName(name)
{
	mVersion = '____';
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void GenBase::writeVersion(RandomAccessStream& output)
{
	writeID(output, getLatestVersion());
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
void GenBase::write(RandomAccessStream& output)
{
	writeID(output, mID);
	if (!Generator::ramMode) {
		writeVersion(output);
	}
	doWrite(output);
	if (Generator::ramMode) {
		ramSaveParameters(output);
	} else {
		Parameters::write(output);
	}
}

/*
 * --INFO--
 * Address:	800DACF0
 * Size:	000020
 */
void GenBase::ramSaveParameters(RandomAccessStream& output)
{
	Parameters::write(output);
}

/*
 * --INFO--
 * Address:	800DAD10
 * Size:	000020
 */
void GenBase::ramLoadParameters(RandomAccessStream& input)
{
	Parameters::read(input);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void GenBase::readVersion(RandomAccessStream& input)
{
	mVersion = readID(input);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void GenBase::read(RandomAccessStream& input)
{
	if (!Generator::ramMode) {
		readVersion(input);
	} else {
		mVersion = getLatestVersion();
	}

	doRead(input);

	if (Generator::ramMode) {
		ramLoadParameters(input);
	} else {
		Parameters::read(input);
	}
}

/*
 * --INFO--
 * Address:	800DAD34
 * Size:	0000FC
 */
static GenObject* makeObjectPiki()
{
	return new GenObjectPiki;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
GenObject* GenObjectFactory::getProduct(u32 id)
{
	return factory->create(id);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void GenObjectFactory::createInstance()
{
	if (!factory) {
		factory = new GenObjectFactory();
		factory->registerMember('piki', &makeObjectPiki, "create PIKI", 'v0.0');
	}
}

/*
 * --INFO--
 * Address:	800DAE30
 * Size:	000050
 */
u32 GenObject::getLatestVersion()
{
	return GenObjectFactory::factory->_getLatestVersion(mID);
}

/*
 * --INFO--
 * Address:	800DAE80
 * Size:	00017C
 */
static GenType* makeTypeOne()
{
	return new GenTypeOne;
}

/*
 * --INFO--
 * Address:	800DAFFC
 * Size:	000130
 */
static GenType* makeTypeAtOnce()
{
	return new GenTypeAtOnce;
}

/*
 * --INFO--
 * Address:	800DB12C
 * Size:	00015C
 */
static GenType* makeTypeInitRand()
{
	return new GenTypeInitRand;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
GenType* GenTypeFactory::getProduct(u32 id)
{
	return factory->create(id);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001FC
 */
void GenTypeFactory::createInstance()
{
	if (!factory) {
		factory = new GenTypeFactory();
		factory->registerMember('1one', &makeTypeOne, "１つだけ", 'v0.0');
		factory->registerMember('aton', &makeTypeAtOnce, "一定数最初から", 'v0.0');
		factory->registerMember('irnd', &makeTypeInitRand, "ランダムで最初から", 'v0.0');
	}
}

/*
 * --INFO--
 * Address:	800DB288
 * Size:	000050
 */
u32 GenType::getLatestVersion()
{
	return GenTypeFactory::factory->_getLatestVersion(mID);
}

/*
 * --INFO--
 * Address:	800DB2D8
 * Size:	00006C
 */
void GenType::ramSaveParameters(RandomAccessStream& output)
{
	output.writeByte(_18());
	output.writeByte(mAdjustFaceDirection());
}

/*
 * --INFO--
 * Address:	800DB344
 * Size:	00006C
 */
void GenType::ramLoadParameters(RandomAccessStream& input)
{
	_18()                  = input.readByte();
	mAdjustFaceDirection() = input.readByte();
}

/*
 * --INFO--
 * Address:	800DB3B0
 * Size:	0000C0
 */
void GenTypeOne::ramSaveParameters(RandomAccessStream& output)
{
	GenType::ramSaveParameters(output);
	output.writeShort(_38());
	output.writeShort(_48());
	output.writeShort(_58());
}

/*
 * --INFO--
 * Address:	800DB470
 * Size:	0000C0
 */
void GenTypeOne::ramLoadParameters(RandomAccessStream& input)
{
	GenType::ramLoadParameters(input);
	_38() = input.readShort();
	_48() = input.readShort();
	_58() = input.readShort();
}

/*
 * --INFO--
 * Address:	800DB530
 * Size:	000088
 */
void GenTypeAtOnce::ramSaveParameters(RandomAccessStream& output)
{
	GenType::ramSaveParameters(output);
	output.writeByte(mMaxCount());
}

/*
 * --INFO--
 * Address:	800DB5B8
 * Size:	000088
 */
void GenTypeAtOnce::ramLoadParameters(RandomAccessStream& input)
{
	GenType::ramLoadParameters(input);
	mMaxCount() = input.readByte();
}

/*
 * --INFO--
 * Address:	800DB640
 * Size:	0000A4
 */
void GenTypeInitRand::ramSaveParameters(RandomAccessStream& output)
{
	GenType::ramSaveParameters(output);
	output.writeByte(_38());
	output.writeByte(mMaxCount());
}

/*
 * --INFO--
 * Address:	800DB6E4
 * Size:	0000A4
 */
void GenTypeInitRand::ramLoadParameters(RandomAccessStream& input)
{
	GenType::ramLoadParameters(input);
	_38()       = input.readByte();
	mMaxCount() = input.readByte();
}

/*
 * --INFO--
 * Address:	800DB788
 * Size:	00007C
 */
void GenArea::doWrite(RandomAccessStream& output)
{
	output.writeFloat(_18.x);
	output.writeFloat(_18.y);
	output.writeFloat(_18.z);
}

/*
 * --INFO--
 * Address:	800DB804
 * Size:	00007C
 */
void GenArea::doRead(RandomAccessStream& input)
{
	_18.x = input.readFloat();
	_18.y = input.readFloat();
	_18.z = input.readFloat();
}

/*
 * --INFO--
 * Address:	800DB880
 * Size:	0000D8
 */
static GenArea* makeCircleArea()
{
	return new GenAreaCircle;
}

/*
 * --INFO--
 * Address:	800DB958
 * Size:	000098
 */
static GenArea* makePointArea()
{
	return new GenAreaPoint;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
GenArea* GenAreaFactory::getProduct(u32 id)
{
	return factory->create(id);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
void GenAreaFactory::createInstance()
{
	if (!factory) {
		factory = new GenAreaFactory();
		factory->registerMember('pint', &makePointArea, "at a point", 'v0.0');
		factory->registerMember('circ', &makeCircleArea, "distribute in a circle", 'v0.0');
		u32 v = factory->_getLatestVersion('circ');
	}
}

/*
 * --INFO--
 * Address:	800DB9F0
 * Size:	000050
 */
u32 GenArea::getLatestVersion()
{
	return GenAreaFactory::factory->_getLatestVersion(mID);
}

/*
 * --INFO--
 * Address:	800DBA40
 * Size:	000040
 */
void GenAreaCircle::ramSaveParameters(RandomAccessStream& output)
{
	output.writeShort(mRadius());
}

/*
 * --INFO--
 * Address:	800DBA80
 * Size:	000060
 */
void GenAreaCircle::ramLoadParameters(RandomAccessStream& input)
{
	mRadius() = input.readShort();
}

/*
 * --INFO--
 * Address:	800DBAE0
 * Size:	000170
 */
Generator::Generator()
{
	mGenArea   = nullptr;
	mGenAreaID = 'pint';
	mGenType   = nullptr;
	mGenTypeID = '1one';
	mGenPosition.set(0.0f, 0.0f, 0.0f);
	mGenObject      = nullptr;
	mGenObjectID    = 'piki';
	mCarryOverFlags = 0;
	mGeneratorName.setID('    ');
	mGeneratorVersion.setID('v0.0');

	strcpy(mMemo, "unset");
	mNextGenerator       = nullptr;
	mPrevGenerator       = nullptr;
	mLatestSpawnCreature = nullptr;
	mAliveCount          = 0;
	initCore("");
	mIsRamReadDisabled = true;
	mLatestSpawnDay    = gameflow.mWorldClock.mCurrentDay;
	setDayLimit(-1);
}

/*
 * --INFO--
 * Address:	800DBC50
 * Size:	000154
 */
Generator::Generator(int)
{
	mGenArea   = nullptr;
	mGenAreaID = 'pint';
	mGenType   = nullptr;
	mGenTypeID = '1one';
	mGenPosition.set(0.0f, 0.0f, 0.0f);
	mGenObject   = nullptr;
	mGenObjectID = 'piki';
	mGeneratorName.setID('    ');
	mGeneratorVersion.setID('v0.0');

	strcpy(mMemo, "unset");
	mNextGenerator = nullptr;
	mPrevGenerator = nullptr;
	initCore("");
	mIsRamReadDisabled = true;
	setDayLimit(-1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
Generator::~Generator()
{
	mNextGenerator = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Generator::updateUseList()
{
	if (!isExpired()) {
		if (mGenObject) {
			mGenObject->updateUseList(this, 1);
		}
	}
}

/*
 * --INFO--
 * Address:	800DBDA4
 * Size:	000038
 */
bool Generator::isExpired()
{
	if (mDayLimit == -1) {
		return false;
	}

	PRINT("CHECK EXPIRATION * DAYLIMIT = %d CURR DAY = %d\n", mDayLimit, gameflow.mWorldClock.mCurrentDay);

	if (mDayLimit < gameflow.mWorldClock.mCurrentDay) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800DBDDC
 * Size:	000104
 */
void Generator::loadCreature(RandomAccessStream& input)
{
	if (mGenObject) {
		BirthInfo info;
		if (mGenType) {
			mGenType->setBirthInfo(info, this);
		}

		ID32 objID(mGenObject->mID);
		PRINT("genObject = %s\n", objID.mStringID);
		mLatestSpawnCreature = mGenObject->birth(info);
		if (mLatestSpawnCreature) {
			mLatestSpawnCreature->mGenerator = this;
			mAliveCount++;
			if (mCarryOverFlags & GENCARRY_SavePosition) {
				mLatestSpawnCreature->load(input, true);
			} else {
				mLatestSpawnCreature->load(input, false);
			}

			PRINT("*** LOAD SUCCEEDED\n");
		} else {
			PRINT("*** NO CREATURE IS LOADED\n");
		}
	}
}

/*
 * --INFO--
 * Address:	800DBEE0
 * Size:	000078
 */
void Generator::saveCreature(RandomAccessStream& output)
{
	if (mLatestSpawnCreature) {
		PRINT("SAVING CREATURE %s\n", ObjType::getName(mLatestSpawnCreature->mObjType));

		if (mCarryOverFlags & GENCARRY_SavePosition) {
			mLatestSpawnCreature->save(output, true);
		} else {
			mLatestSpawnCreature->save(output, false);
		}
		PRINT("OK\n");
	} else {
		ERROR("save creature failed!\n");
	}
}

/*
 * --INFO--
 * Address:	800DBF58
 * Size:	00023C
 */
void Generator::init()
{
	// we're past our day limit, do nothing.
	if (isExpired()) {
		PRINT("*** OK ! NOTHING IS MADE\n");
		mAliveCount = 0;
		return;
	}

	if (!ramMode) {
		mAliveCount = 0;

	} else if (!(mCarryOverFlags & GENCARRY_Unk3)) {
		// do nothing.
		mAliveCount = 0;
		return;
	}

	mLatestSpawnCreature = nullptr;

	if (mGenArea) {
		mGenArea->init(this);
	}

	if (mGenObject) {
		mGenObject->init(this);
	}

	if (ramMode && (mCarryOverFlags & GENCARRY_Unk3)) {
		if (gameflow.mWorldClock.mCurrentDay >= mLatestSpawnDay + mRespawnInterval) {
			// we're due to respawn afresh.
			PRINT("****** RESET DAY (curr=%d / save=%d interval=%d)\n", gameflow.mWorldClock.mCurrentDay, mLatestSpawnDay,
			      mRespawnInterval);
			// set our latest spawn day
			mLatestSpawnDay = gameflow.mWorldClock.mCurrentDay;

			// spawn afresh based on spawn type
			if (mGenType) {
				mAliveCount = 0;
				mGenType->init(this);
			}
			return;
		}

		PRINT("****** NUM FUKKATU (curr=%d / save=%d interval=%d) count=%d\n", gameflow.mWorldClock.mCurrentDay, mLatestSpawnDay,
		      mRespawnInterval, mAliveCount);

		// respawn just however many we had alive last time
		int count   = mAliveCount;
		mAliveCount = 0;

		for (int i = 0; i < count; i++) {
			BirthInfo info;
			mGenType->setBirthInfo(info, this);

			// spawn the creature
			if (mGenObject) {
				Creature* spawn = mGenObject->birth(info);
				if (spawn) {
					spawn->mGenerator = this;
					mAliveCount++;
					mLatestSpawnCreature = spawn;
				}
			}
		}
		return;
	}

	// if we made it here, ramMode == false
	if (mGenType) {
		mAliveCount = 0;
		mGenType->init(this);
	}
}

/*
 * --INFO--
 * Address:	800DC19C
 * Size:	000088
 */
void Generator::informDeath(Creature* creature)
{
	if (creature == mLatestSpawnCreature) {
		mLatestSpawnCreature = nullptr;
	}

	mAliveCount--;

	if (creature->mObjType == OBJTYPE_Teki) {
		int count = mAliveCount;
		PRINT("GENERATOR * CREATURE(%s/%s) DEAD : %d\n", ObjType::getName(creature->mObjType),
		      TekiMgr::getTypeName(static_cast<Teki*>(creature)->mTekiType), count);
	}

	if (mAliveCount <= 0) {
		mAliveCount     = 0;
		mLatestSpawnDay = gameflow.mWorldClock.mCurrentDay;
	}
}

/*
 * --INFO--
 * Address:	800DC224
 * Size:	000004
 */
void Generator::update()
{
}

/*
 * --INFO--
 * Address:	800DC228
 * Size:	0001AC
 */
void Generator::render(Graphics& gfx)
{
	if (gsys->mToggleDebugInfo) {
		Matrix4f mtx1;
		Matrix4f mtx2;

		Vector3f scale;
		f32 s = 0.5f;
		scale.set(s, s, s);

		mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), getPos());

		gfx.calcViewMatrix(mtx1, mtx2);
		gfx.useMatrix(mtx2, 0);
		Colour colour;
		colour.set(255, 125, 0, 255);

		GlobalShape::markerShape->mMaterialList->Colour() = colour;
		GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);

		if (mGenArea) {
			mGenArea->render(gfx, this);
		}

		if (mGenObject) {
			mGenObject->render(gfx, this);
		}

		if (mGenType) {
			mGenType->render(gfx, this);
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xD8(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x2DEC(r13)
	  lwz       r0, 0x20(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x194
	  lfs       f0, -0x6790(r2)
	  addi      r6, r1, 0x38
	  addi      r5, r1, 0x2C
	  stfs      f0, 0x54(r1)
	  addi      r3, r1, 0x98
	  addi      r4, r1, 0x4C
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  lfs       f0, -0x6780(r2)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0xA4(r30)
	  lfs       f5, 0xA0(r30)
	  fadds     f1, f1, f0
	  lfs       f4, 0xAC(r30)
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0xA8(r30)
	  fadds     f4, f5, f4
	  stfs      f1, 0x24(r1)
	  fadds     f3, f3, f2
	  lfs       f0, -0x3A30(r13)
	  lfs       f2, 0x24(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f1, -0x3A2C(r13)
	  stfs      f2, 0x38(r1)
	  lfs       f0, -0x3A28(r13)
	  stfs      f3, 0x3C(r1)
	  stfs      f1, 0x30(r1)
	  stfs      f4, 0x40(r1)
	  stfs      f0, 0x34(r1)
	  bl        -0x9E1E0
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x98
	  addi      r5, r1, 0x58
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x58
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r5, 0xFF
	  lwz       r3, 0x2F54(r13)
	  stb       r5, 0x44(r1)
	  li        r4, 0x7D
	  li        r0, 0
	  stb       r4, 0x45(r1)
	  addi      r4, r31, 0
	  li        r6, 0
	  stb       r0, 0x46(r1)
	  stb       r5, 0x47(r1)
	  lwz       r3, 0x44(r3)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x2F54(r13)
	  lwz       r5, 0x2E4(r31)
	  bl        -0xABEE0
	  lwz       r3, 0x20(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x14C
	  lwz       r12, 0x4(r3)
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl

	.loc_0x14C:
	  lwz       r3, 0x30(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x170
	  lwz       r12, 0x4(r3)
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x170:
	  lwz       r3, 0x28(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x194
	  lwz       r12, 0x4(r3)
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl

	.loc_0x194:
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DC3DC
 * Size:	000734
 */
void Generator::read(RandomAccessStream& input)
{
	int fake[0x14];

	mGeneratorName.read(input);
	if (!ramMode) {
		mGeneratorVersion.read(input);
		_70 = readID(input);
	}

	mCarryOverFlags = input.readInt();

	// this isn't even printed or tested in the DLL lol, it just. sits here.
	mGeneratorVersion != 'v0.0';

	if (!ramMode) {
		for (int i = 0; i < 0x20; i++) {
			mMemo[i] = input.readByte();
		}
	} else {
		mAliveCount      = input.readShort();
		mLatestSpawnDay  = input.readShort();
		mRespawnInterval = input.readShort();
		mDayLimit        = input.readShort();

		PRINT("****** GENERATOR READ @ %d (count=%d saveday=%d interval=%d limit=%d)\n", input.getPosition(), mAliveCount, mLatestSpawnDay,
		      mRespawnInterval, mDayLimit);
	}

	if (ramMode) {
		mGenPosition.x = input.readShort();
		mGenPosition.y = input.readShort();
		mGenPosition.z = input.readShort();
	} else {
		mGenPosition.x = input.readFloat();
		mGenPosition.y = input.readFloat();
		mGenPosition.z = input.readFloat();
	}

	if (ramMode) {
		mGenOffset.set(0.0f, 0.0f, 0.0f);
	} else {
		mGenOffset.x = input.readFloat();
		mGenOffset.y = input.readFloat();
		mGenOffset.z = input.readFloat();
	}

	mGenObject = nullptr;
	int objID  = readID(input);
	mGenObject = GenObjectFactory::getProduct(objID);
	if (mGenObject) {
		mGenObject->read(input);
	} else {
		PRINT("unknown genObject id : %x\n", objID);
		printID(objID);
	}

	mGenArea   = nullptr;
	int areaID = readID(input);
	mGenArea   = GenAreaFactory::getProduct(areaID);
	if (mGenArea) {
		mGenArea->read(input);
	} else {
		PRINT("unknown area id : %x\n", areaID);
		printID(areaID);
	}

	mGenType   = nullptr;
	int typeID = readID(input);
	mGenType   = GenTypeFactory::getProduct(typeID);
	if (mGenType) {
		mGenType->read(input);
	} else {
		PRINT("unknown genType id : %x\n", typeID);
		printID(typeID);
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stw       r31, 0xE4(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xE0(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x58
	  stw       r29, 0xDC(r1)
	  bl        -0x98364
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0xA8
	  addi      r3, r30, 0x64
	  addi      r4, r31, 0
	  bl        -0x9837C
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xAF(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xAE(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xAD(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xAC(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0x70(r30)

	.loc_0xA8:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r30)
	  lis       r4, 0x7630
	  addi      r3, r30, 0x64
	  addi      r4, r4, 0x2E30
	  bl        -0x984B4
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x10C
	  li        r29, 0

	.loc_0xE0:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r29, 0x38
	  addi      r29, r29, 0x1
	  stbx      r3, r30, r0
	  cmpwi     r29, 0x20
	  blt+      .loc_0xE0
	  b         .loc_0x190

	.loc_0x10C:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  stw       r0, 0x88(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  stw       r0, 0x8C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  stw       r0, 0x90(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  stw       r0, 0x94(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x190:
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x240
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  lfd       f1, -0x6788(r2)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xD4(r1)
	  lis       r29, 0x4330
	  addi      r3, r31, 0
	  stw       r29, 0xD0(r1)
	  lfd       f0, 0xD0(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x98(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  lfd       f1, -0x6788(r2)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xCC(r1)
	  mr        r3, r31
	  stw       r29, 0xC8(r1)
	  lfd       f0, 0xC8(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x9C(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  lfd       f1, -0x6788(r2)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xC4(r1)
	  stw       r29, 0xC0(r1)
	  lfd       f0, 0xC0(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0xA0(r30)
	  b         .loc_0x288

	.loc_0x240:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x98(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x9C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xA0(r30)

	.loc_0x288:
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x2B0
	  lfs       f0, -0x3A14(r13)
	  stfs      f0, 0xA4(r30)
	  lfs       f0, -0x3A10(r13)
	  stfs      f0, 0xA8(r30)
	  lfs       f0, -0x3A0C(r13)
	  stfs      f0, 0xAC(r30)
	  b         .loc_0x2F8

	.loc_0x2B0:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xA4(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xA8(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xAC(r30)

	.loc_0x2F8:
	  li        r0, 0
	  stw       r0, 0x30(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xAB(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xAA(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xA9(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xA8(r1)
	  lwz       r4, 0xA8(r1)
	  lwz       r3, 0x3074(r13)
	  bl        0x4A4
	  stw       r3, 0x30(r30)
	  lwz       r29, 0x30(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x458
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x3F4
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x7B(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x7A(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x79(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x78(r1)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0xC(r29)
	  b         .loc_0x40C

	.loc_0x3F4:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r29)

	.loc_0x40C:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x44C
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x458

	.loc_0x44C:
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x7DC98

	.loc_0x458:
	  li        r0, 0
	  stw       r0, 0x20(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x9B(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x9A(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x99(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x98(r1)
	  lwz       r4, 0x98(r1)
	  lwz       r3, 0x307C(r13)
	  bl        0x2D8
	  stw       r3, 0x20(r30)
	  lwz       r29, 0x20(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x5B8
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x554
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x77(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x76(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x75(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x74(r1)
	  lwz       r0, 0x74(r1)
	  stw       r0, 0xC(r29)
	  b         .loc_0x56C

	.loc_0x554:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r29)

	.loc_0x56C:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x5AC
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5B8

	.loc_0x5AC:
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x7DDF8

	.loc_0x5B8:
	  li        r0, 0
	  stw       r0, 0x28(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x8B(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x8A(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x89(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x88(r1)
	  lwz       r4, 0x88(r1)
	  lwz       r3, 0x3078(r13)
	  bl        .loc_0x734
	  stw       r3, 0x28(r30)
	  lwz       r29, 0x28(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x718
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x6B4
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x73(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x72(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x71(r1)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x70(r1)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0xC(r29)
	  b         .loc_0x6CC

	.loc_0x6B4:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r29)

	.loc_0x6CC:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x70C
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x718

	.loc_0x70C:
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x7DF58

	.loc_0x718:
	  lwz       r0, 0xEC(r1)
	  lwz       r31, 0xE4(r1)
	  lwz       r30, 0xE0(r1)
	  lwz       r29, 0xDC(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr

	.loc_0x734:
	*/
}

/*
 * --INFO--
 * Address:	800DCC54
 * Size:	000760
 */
void Generator::write(RandomAccessStream& output)
{
	PRINT("** generator write start : %x\n", this);

	mGeneratorName.write(output);

	if (!ramMode) {
		mGeneratorVersion.write(output);
		writeID(output, _70);
	}

	output.writeInt(mCarryOverFlags);

	if (!ramMode) {
		for (int i = 0; i < 0x20; i++) {
			output.writeByte(mMemo[i]);
		}
	} else {
		PRINT("**** WRITE CREATE COUNT !! %d\n", mAliveCount);
		output.writeShort(mAliveCount);
		output.writeShort(mLatestSpawnDay);
		output.writeShort(getRebirthDay());
		output.writeShort(mDayLimit);
		PRINT("****** GENERATOR WRITE @ %d (count=%d saveday=%d interval=%d limit=%d)\n", output.getPosition(), mAliveCount,
		      mLatestSpawnDay, getRebirthDay(), mDayLimit);
	}

	if (ramMode) {
		// yeesh
		output.writeShort(s16(mGenPosition.x) + mGenOffset.x);
		output.writeShort(s16(mGenPosition.y) + mGenOffset.y);
		output.writeShort(s16(mGenPosition.z) + mGenOffset.z);
	} else {
		output.writeFloat(mGenPosition.x);
		output.writeFloat(mGenPosition.y);
		output.writeFloat(mGenPosition.z);
		output.writeFloat(mGenOffset.x);
		output.writeFloat(mGenOffset.y);
		output.writeFloat(mGenOffset.z);
	}

	if (mGenObject) {
		mGenObject->write(output);
	} else {
		output.writeInt(0);
	}

	if (mGenArea) {
		mGenArea->write(output);
	} else {
		output.writeInt(0);
	}

	if (mGenType) {
		mGenType->write(output);
	} else {
		output.writeInt(0);
	}
}

char* coStrings[] = { "なし", "常に" };

/*
 * --INFO--
 * Address:	800DD3B4
 * Size:	000514
 */
GeneratorMgr::GeneratorMgr()
    : Node("genMgr")
{
	mNaviPos.set(0.0f, 0.0f, 0.0f);
	mNaviDirection = 0.0f;
	mGenCount      = 0;
	mGenListHead   = nullptr;
	_24.setID('v0.1');
	mGeneratorVersionId.setID('v0.0');

	GenObjectFactory::createInstance();
	GenAreaFactory::createInstance();
	GenTypeFactory::createInstance();
	setLimitGenerator(false);
	setName("GeneratorMgr");
}

/*
 * --INFO--
 * Address:	800DD8C8
 * Size:	000040
 */
void GeneratorMgr::init()
{
	for (Generator* gen = mGenListHead; gen; gen = gen->mNextGenerator) {
		gen->init();
	}
}

/*
 * --INFO--
 * Address:	800DD908
 * Size:	00001C
 */
void GeneratorMgr::setDayLimit(int limit)
{
	for (Generator* gen = mGenListHead; gen; gen = gen->mNextGenerator) {
		gen->setDayLimit(limit);
	}
}

/*
 * --INFO--
 * Address:	800DD924
 * Size:	0000A0
 */
void GeneratorMgr::updateUseList()
{
	for (Generator* gen = mGenListHead; gen; gen = gen->mNextGenerator) {
		gen->updateUseList();
	}
}

/*
 * --INFO--
 * Address:	800DD9C4
 * Size:	00004C
 */
void GeneratorMgr::update()
{
	for (Generator* gen = mGenListHead; gen; gen = gen->mNextGenerator) {
		gen->update();
	}
}

/*
 * --INFO--
 * Address:	800DDA10
 * Size:	00005C
 */
void GeneratorMgr::render(Graphics& gfx)
{
	for (Generator* gen = mGenListHead; gen; gen = gen->mNextGenerator) {
		gen->render(gfx);
	}
}

/*
 * --INFO--
 * Address:	800DDA6C
 * Size:	000274
 */
void GeneratorMgr::read(RandomAccessStream& input, bool p2)
{
	if (mGenListHead) {
		delete mGenListHead;
		mGenCount = 0;
	}

	mGeneratorVersionId.read(input);
	if (!(mGeneratorVersionId == 'v0.0')) {
		PRINT("OLD VERSION !!!! %x\n", mGeneratorVersionId.mId);
	}

	mNaviPos.x = input.readFloat();
	mNaviPos.y = input.readFloat();
	mNaviPos.z = input.readFloat();

	if (mGeneratorVersionId == 'v0.1') {
		mNaviDirection = input.readFloat();
	}

	if (!p2) {
		Navi* navi = naviMgr->getNavi();
		if (navi) {
			navi->mPosition   = mNaviPos;
			navi->_1AC        = mNaviPos;
			navi->mDirection  = PI * (mNaviDirection / 180.0f);
			navi->mRotation.y = navi->mDirection;
		} else {
			PRINT("@@@@@@@@@ SET STARTPOS NAVI FAIL !!!!!!!!!!!!!!!\n");
		}
	}

	mGenCount    = input.readInt();
	mGenListHead = nullptr;

	for (int i = 0; i < mGenCount; i++) {
		if (!mGenListHead) {
			mGenListHead = new Generator();
			mGenListHead->read(input);
			mGenListHead->mMgr = this;
			generatorList->mGenListHead->add(mGenListHead);
		} else {
			Generator* newGen = new Generator();
			newGen->mMgr      = this;
			newGen->read(input);

			Generator* endList = mGenListHead;
			for (endList; endList->mNextGenerator; endList = endList->mNextGenerator) {
				;
			}
			endList->mNextGenerator = newGen;
			newGen->mPrevGenerator  = endList;
			generatorList->mGenListHead->add(newGen);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void GeneratorMgr::write(RandomAccessStream& output)
{
	PRINT("xxxx start writing %d generators\n", mGenCount);
	_24.write(output);
	output.writeFloat(mNaviPos.x);
	output.writeFloat(mNaviPos.y);
	output.writeFloat(mNaviPos.z);
	output.writeFloat(mNaviDirection);
	output.writeInt(mGenCount);
	for (Generator* gen = mGenListHead; gen; gen = gen->mNextGenerator) {
		gen->write(output);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void GeneratorMgr::setNaviPos()
{
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		mNaviPos = navi->mPosition;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void GeneratorMgr::changeNaviPos()
{
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		navi->mPosition = mNaviPos;
	}
}

/*
 * --INFO--
 * Address:	800DDCE0
 * Size:	00006C
 */
void GenObjectPiki::ramSaveParameters(RandomAccessStream& output)
{
	output.writeByte(mSpawnState());
	output.writeByte(mSpawnColor());
}

/*
 * --INFO--
 * Address:	800DDD4C
 * Size:	00006C
 */
void GenObjectPiki::ramLoadParameters(RandomAccessStream& input)
{
	mSpawnState() = input.readByte();
	mSpawnColor() = input.readByte();
}

/*
 * --INFO--
 * Address:	800DDDB8
 * Size:	000214
 */
Creature* GenObjectPiki::birth(BirthInfo& info)
{
	Creature* piki = nullptr;
	getLatestVersion();
	int color = mSpawnColor();
	if (color == 3) {
		color = System::getRand(1.0f) * 3.0f;
		if (color >= 3) {
			color = Blue;
		}
	}

	switch (mSpawnState()) {
	case 0: // buried, so spawn a PikiHeadItem
		PikiHeadItem* sprout = static_cast<PikiHeadItem*>(itemMgr->birth(OBJTYPE_Pikihead));
		if (sprout) {
			sprout->init(info.mPosition);
			sprout->mPosition.y = mapMgr->getMinY(sprout->mPosition.x, sprout->mPosition.z, true);
			sprout->setColor(color);
			sprout->startAI(0);
			static_cast<SimpleAI*>(sprout->mStateMachine)->start(sprout, 6);
			piki = sprout;
		}
		break;

	case 1:
	case 2: // free or in party, so spawn piki
		piki = pikiMgr->birth();
		if (piki) {
			GameStat::workPikis.inc(color);
			GameStat::update();
			static_cast<Piki*>(piki)->init(naviMgr->getNavi());
			piki->Creature::init(info.mPosition);
			static_cast<Piki*>(piki)->initColor(color);
			if (mSpawnState() == 1) { // free
				static_cast<Piki*>(piki)->changeMode(0, naviMgr->getNavi());
			} else { // in party
				static_cast<Piki*>(piki)->changeMode(1, naviMgr->getNavi());
			}
		}
		break;
	}

	return piki;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
f32 deg2rad(int val)
{
	return PI * (val / 180.0f);
}

/*
 * --INFO--
 * Address:	800DDFCC
 * Size:	0000A4
 */
void GenTypeOne::init(Generator* gen)
{
	BirthInfo info;
	setBirthInfo(info, gen);
	if (gen->mGenObject) {
		Creature* obj = gen->mGenObject->birth(info);
		if (obj) {
			obj->mGenerator = gen;
			gen->mAliveCount++;
			gen->mLatestSpawnCreature = obj;
		}
	}
}

/*
 * --INFO--
 * Address:	800DE070
 * Size:	0001B8
 */
void GenTypeOne::setBirthInfo(BirthInfo& info, Generator* gen)
{
	Vector3f pos;
	if (gen->mGenArea) {
		pos = gen->mGenArea->getPos(gen);
	} else {
		pos = gen->getPos();
	}

	Vector3f rot;
	rot.set(deg2rad(_38()), deg2rad(_48()), deg2rad(_58()));

	Vector3f& p = gen->getPos();
	info.set(pos, rot, p, gen);
}

/*
 * --INFO--
 * Address:	800DE228
 * Size:	000168
 */
void GenTypeOne::render(Graphics& gfx, Generator* gen)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	Vector3f scale;
	Vector3f rot;

	rot.set(deg2rad(_38()), deg2rad(_48()), deg2rad(_58()));
	f32 s = 2.0f;
	scale.set(s, s, s);

	Vector3f& pos = gen->getPos();
	mtx1.makeSRT(scale, rot, pos);
	gfx.calcViewMatrix(mtx1, mtx2);

	gfx.useMatrix(mtx2, 0);
	GlobalShape::axisShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	800DE390
 * Size:	000008
 */
int GenTypeAtOnce::getMaxCount()
{
	return mMaxCount();
}

/*
 * --INFO--
 * Address:	800DE398
 * Size:	0000E4
 */
void GenTypeAtOnce::init(Generator* gen)
{
	int max = mMaxCount();
	for (int i = 0; i < max; i++) {
		BirthInfo info;
		setBirthInfo(info, gen);
		if (gen->mGenObject) {
			Creature* obj = gen->mGenObject->birth(info);
			if (obj) {
				obj->mGenerator = gen;
				gen->mAliveCount++;
				gen->mLatestSpawnCreature = obj;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800DE47C
 * Size:	000138
 */
void GenTypeAtOnce::setBirthInfo(BirthInfo& info, Generator* gen)
{
	Vector3f vec;
	if (gen->mGenArea) {
		vec = gen->mGenArea->getPos(gen);
	} else {
		vec = gen->getPos();
	}

	Vector3f& pos = gen->getPos();
	info.set(vec, Vector3f(0.0f, 0.0f, 0.0f), pos, gen);
}

/*
 * --INFO--
 * Address:	800DE5B4
 * Size:	000008
 */
int GenTypeInitRand::getMaxCount()
{
	return mMaxCount();
}

/*
 * --INFO--
 * Address:	800DE5BC
 * Size:	000144
 */
void GenTypeInitRand::init(Generator* gen)
{
	int randCount = _38() + int(System::getRand(1.0f) * f32(mMaxCount() - _38()));
	for (int i = 0; i < randCount; i++) {
		BirthInfo info;
		setBirthInfo(info, gen);
		if (gen->mGenObject) {
			Creature* obj = gen->mGenObject->birth(info);
			if (obj) {
				obj->mGenerator = gen;
				gen->mAliveCount++;
				gen->mLatestSpawnCreature = obj;
				u32 badCompiler; // idk where this is from.
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800DE700
 * Size:	000138
 */
void GenTypeInitRand::setBirthInfo(BirthInfo& info, Generator* gen)
{
	Vector3f vec;
	if (gen->mGenArea) {
		vec = gen->mGenArea->getPos(gen);
	} else {
		vec = gen->getPos();
	}

	Vector3f& pos = gen->getPos();
	info.set(vec, Vector3f(0.0f, 0.0f, 0.0f), pos, gen);
}

/*
 * --INFO--
 * Address:	800DE838
 * Size:	000088
 */
Vector3f GenAreaPoint::getPos(Generator* gen)
{
	Vector3f pos = gen->getPos();
	return pos;
}

/*
 * --INFO--
 * Address:	800DE8C0
 * Size:	000004
 */
void GenAreaPoint::render(Graphics&, Generator*)
{
}

/*
 * --INFO--
 * Address:	800DE8C4
 * Size:	0001A4
 */
Vector3f GenAreaCircle::getPos(Generator* gen)
{
	Vector3f pos = gen->getPos();

	f32 minRadFactor = System::getRand(1.0f);
	f32 radius       = System::getRand(1.0f) * (1.0f - minRadFactor) + minRadFactor;
	radius *= mRadius();

	f32 randAngle = 2.0f * (PI * System::getRand(1.0f));
	pos           = Vector3f(radius * sinf(randAngle), 0.0f, radius * cosf(randAngle)) + pos;

	return pos;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  addi      r0, r1, 0x3C
	  addi      r6, r1, 0x40
	  stfd      f30, 0xB8(r1)
	  stfd      f29, 0xB0(r1)
	  stfd      f28, 0xA8(r1)
	  stfd      f27, 0xA0(r1)
	  stfd      f26, 0x98(r1)
	  stw       r31, 0x94(r1)
	  stw       r30, 0x90(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x8C(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x38
	  lfs       f1, 0xA0(r5)
	  addi      r4, r3, 0
	  lfs       f0, 0xAC(r5)
	  addi      r3, r1, 0x4C
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x9C(r5)
	  lfs       f0, 0xA8(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f1, 0x98(r5)
	  lfs       f0, 0xA4(r5)
	  mr        r5, r0
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  bl        -0xA7828
	  lfs       f31, 0x4C(r1)
	  lfs       f30, 0x50(r1)
	  lfs       f29, 0x54(r1)
	  bl        0x13971C
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6788(r2)
	  stw       r0, 0x84(r1)
	  lis       r31, 0x4330
	  lfs       f1, -0x6770(r2)
	  stw       r31, 0x80(r1)
	  lfs       f0, -0x6774(r2)
	  lfd       f2, 0x80(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f28, f0, f1
	  bl        0x1396EC
	  xoris     r0, r3, 0x8000
	  lfs       f2, -0x6774(r2)
	  stw       r0, 0x7C(r1)
	  lfd       f5, -0x6788(r2)
	  fsubs     f1, f2, f28
	  stw       r31, 0x78(r1)
	  lfs       f3, -0x6770(r2)
	  lfd       f4, 0x78(r1)
	  lfs       f0, 0x30(r30)
	  fsubs     f4, f4, f5
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f2
	  fadds     f27, f28, f1
	  fmuls     f27, f27, f0
	  bl        0x1396AC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6788(r2)
	  stw       r0, 0x74(r1)
	  lfs       f3, -0x6770(r2)
	  stw       r31, 0x70(r1)
	  lfs       f2, -0x6774(r2)
	  lfd       f1, 0x70(r1)
	  lfs       f0, -0x677C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6768(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f26, f1, f0
	  fmr       f1, f26
	  bl        0x13D150
	  fmuls     f28, f27, f1
	  fmr       f1, f26
	  bl        0x13D2D8
	  fmuls     f2, f27, f1
	  lfs       f1, -0x39DC(r13)
	  fadds     f0, f28, f29
	  fadds     f3, f1, f30
	  fadds     f1, f2, f31
	  stfs      f1, 0x0(r29)
	  stfs      f3, 0x4(r29)
	  stfs      f0, 0x8(r29)
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lfd       f29, 0xB0(r1)
	  lfd       f28, 0xA8(r1)
	  lfd       f27, 0xA0(r1)
	  lfd       f26, 0x98(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  lwz       r29, 0x8C(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DEA68
 * Size:	000130
 */
void GenAreaCircle::render(Graphics& gfx, Generator* gen)
{
	Matrix4f mtx1;
	Matrix4f mtx2;

	Vector3f scale;
	scale.set(mRadius() / 100.0f, 1.0f, mRadius() / 100.0f);
	mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), gen->getPos());
	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);

	Colour colour;
	colour.set(255, 255, 0, 255);

	GlobalShape::enShape->mMaterialList->mColourInfo.mColour = colour;
	GlobalShape::enShape->drawshape(gfx, *gfx.mCamera, nullptr);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stw       r31, 0xE4(r1)
	  addi      r31, r4, 0
	  addi      r0, r1, 0x34
	  lfs       f0, -0x6790(r2)
	  addi      r6, r1, 0x40
	  addi      r4, r1, 0x50
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  lfs       f1, -0x6764(r2)
	  lfs       f2, 0x30(r3)
	  addi      r3, r1, 0x9C
	  lfs       f0, -0x39D8(r13)
	  fdivs     f1, f2, f1
	  stfs      f1, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f1, 0x58(r1)
	  lfs       f1, 0x98(r5)
	  lfs       f0, 0xA4(r5)
	  lfs       f5, 0xA0(r5)
	  fadds     f1, f1, f0
	  lfs       f4, 0xAC(r5)
	  lfs       f3, 0x9C(r5)
	  lfs       f2, 0xA8(r5)
	  fadds     f4, f5, f4
	  stfs      f1, 0x2C(r1)
	  fadds     f3, f3, f2
	  lfs       f0, -0x39D4(r13)
	  mr        r5, r0
	  lfs       f2, 0x2C(r1)
	  stfs      f0, 0x34(r1)
	  lfs       f1, -0x39D0(r13)
	  stfs      f2, 0x40(r1)
	  lfs       f0, -0x39CC(r13)
	  stfs      f3, 0x44(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f4, 0x48(r1)
	  stfs      f0, 0x3C(r1)
	  bl        -0xA0A18
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x9C
	  addi      r5, r1, 0x5C
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x5C
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r5, 0xFF
	  lwz       r3, 0x2F5C(r13)
	  stb       r5, 0x4C(r1)
	  li        r0, 0
	  addi      r4, r31, 0
	  stb       r5, 0x4D(r1)
	  li        r6, 0
	  stb       r0, 0x4E(r1)
	  stb       r5, 0x4F(r1)
	  lwz       r3, 0x44(r3)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x2F5C(r13)
	  lwz       r5, 0x2E4(r31)
	  bl        -0xAE714
	  lwz       r0, 0xEC(r1)
	  lwz       r31, 0xE4(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DEB98
 * Size:	000058
 */
GeneratorList::GeneratorList()
{
	mGenListHead = new Generator(123456); // lol
}

/*
 * --INFO--
 * Address:	800DEBF0
 * Size:	000038
 */
Generator* GeneratorList::findGenerator(int idx)
{
	FOREACH_NODE(Generator, mGenListHead->mChild, gen)
	{
		if (gen->readFromRam() && gen->mGeneratorListIdx == idx) {
			return gen;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800DEC28
 * Size:	000070
 */
void GeneratorList::createRamGenerators()
{
	FOREACH_NODE(Generator, mGenListHead->mChild, gen)
	{
		if (gen->readFromRam()) {
			Generator::ramMode = true;
			gen->init();
			Generator::ramMode = false;
		}
	}
}

/*
 * --INFO--
 * Address:	800DEC98
 * Size:	0000B0
 */
void GeneratorList::updateUseList()
{
	FOREACH_NODE(Generator, mGenListHead->mChild, gen)
	{
		if (gen->readFromRam()) {
			gen->updateUseList();
		}
	}
}
