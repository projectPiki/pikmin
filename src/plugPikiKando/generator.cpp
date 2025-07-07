#include "Generator.h"
#include "Age.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "GlobalShape.h"
#include "Graphics.h"
#include "NaviMgr.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "gameflow.h"
#include "sysNew.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(17)

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
static void writeID(RandomAccessStream& output, u32 id)
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
static u32 readID(RandomAccessStream& input)
{
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
static void printID(u32)
{
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

		Vector3f& pos = getPos();
		mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), pos);

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
}

char* coStrings[] = { "なし", "常に" };

/*
 * --INFO--
 * Address:	800DC3DC
 * Size:	000734
 */
void Generator::read(RandomAccessStream& input)
{
	STACK_PAD_TERNARY(this, 2);
	STACK_PAD_VAR(4);

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

	STACK_PAD_INLINE(3);

	mGenArea   = nullptr;
	int areaID = readID(input);
	mGenArea   = GenAreaFactory::getProduct(areaID);
	if (mGenArea) {
		mGenArea->read(input);
	} else {
		PRINT("unknown area id : %x\n", areaID);
		printID(areaID);
	}

	STACK_PAD_INLINE(3);

	mGenType   = nullptr;
	int typeID = readID(input);
	mGenType   = GenTypeFactory::getProduct(typeID);
	if (mGenType) {
		mGenType->read(input);
	} else {
		PRINT("unknown genType id : %x\n", typeID);
		printID(typeID);
	}

	STACK_PAD_TERNARY(this, 5);
	STACK_PAD_INLINE(3);
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
			navi->mPosition      = mNaviPos;
			navi->mLastPosition  = mNaviPos;
			navi->mFaceDirection = PI * (mNaviDirection / 180.0f);
			navi->mRotation.y    = navi->mFaceDirection;
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
		color = gsys->getRand(1.0f) * 3.0f;
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
			C_SAI(sprout)->start(sprout, PikiHeadAI::PIKIHEAD_Wait);
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
				static_cast<Piki*>(piki)->changeMode(PikiMode::FreeMode, naviMgr->getNavi());
			} else { // in party
				static_cast<Piki*>(piki)->changeMode(PikiMode::FormationMode, naviMgr->getNavi());
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
	int randCount = _38() + int(gsys->getRand(1.0f) * f32(mMaxCount() - _38()));
	for (int i = 0; i < randCount; i++) {
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
	f32 radius;

	radius = gsys->getRand(1.0f);
	radius = gsys->getRand(1.0f) * (1.0f - radius) + radius;
	radius *= mRadius();

	f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));
	Vector3f delta(radius * sinf(randAngle), 0.0f, radius * cosf(randAngle));
	pos = delta + pos;

	return pos;
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
	f32 radius = mRadius() / 100.0f;
	scale.set(radius, 1.0f, radius);
	Vector3f& v = gen->getPos();
	mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), v);
	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);

	Colour colour;
	colour.set(255, 255, 0, 255);
	GlobalShape::enShape->mMaterialList->mColourInfo.mColour = colour;
	GlobalShape::enShape->drawshape(gfx, *gfx.mCamera, nullptr);

	STACK_PAD_STRUCT(1);
	STACK_PAD_TERNARY(gen, 2);
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

// The functions following this point are exclusively found in the windows .dll build
// None of this is confirmed to be equivalent for obvious reasons

#ifdef DEVELOP
void GeneratorMgr::genAge(AgeServer& server)
{
	server.StartSection(mName, true);
	server.StartGroup("info");

	char version[8];
	mGeneratorVersionId.sprint(version);
	char latest[8];
	_24.sprint(latest);
	char buf[128];
	sprintf(buf, "version [%s] latest=[%s]", version, latest);
	server.NewLabel(buf);
	server.EndGroup();

	server.StartGroup("ファイル");
	server.NewButton("Load", new Delegate1<CoreNode, AgeServer&>(this, CoreNode::genRead), 221);
	server.NewButton("Save", new Delegate1<GeneratorMgr, AgeServer&>(this, genWrite), 221);
	server.EndGroup();

	server.StartGroup("operation");
	server.NewButton("new generator", new Delegate1<GeneratorMgr, AgeServer&>(this, addGenerator), 221);
	server.EndGroup();

	server.StartGroup("navi start position");
	server.NewButton("move to navi pos", new Delegate<GeneratorMgr>(this, setNaviPos), 221);
	server.NewButton("move navi to curr pos", new Delegate<GeneratorMgr>(this, changeNaviPos), 221);
	server.NewEditor("navi face", &mNaviDirection, 0.0f, 360.0f, 320);
	server.EndGroup();

	if (mGenListHead) {
		int index = 0;
		for (Generator* gen = mGenListHead; gen; gen = gen->mNextGenerator) {
			index++;
			char str[256];
			sprintf(str, "Generator%d <%s>", index, gen->mMemo);
			server.StartSection(str, true);
			server.setSectionRefresh(new Delegate1<CoreNode, AgeServer&>(gen, CoreNode::genAge));
			server.EndSection();
		}
	}

	server.EndSection();
}

void GeneratorMgr::genWrite(AgeServer& server)
{
	PRINT("GeneratorMgr::genWrite>\n");
	String string;
	if (server.getSaveFilename(string, "All Files (*.gen)|*.gen")) {
		AtxFileStream stream;
		if (stream.open(string.mString, 2)) {
			PRINT("saving as \'%s\'\n", string.mString);
			write(stream);
			stream.close();
			PRINT("closed file\n");
		} else {
			PRINT("cant save file \'%s\'\n");
		}
	}
	PRINT("GeneratorMgr::genWrite<\n");
}

void GeneratorMgr::addGenerator(AgeServer& server)
{
	Navi* navi = naviMgr->getNavi();

	if (mGenListHead == nullptr) {
		mGenListHead = new Generator;
		mGenListHead->setPos(navi->mPosition);
		mGenListHead->setOffset(Vector3f(0.0f, 0.0f, 0.0f));
		mGenListHead->mMgr = this;
		mGenCount++;
	} else {
		Generator* lastGen = mGenListHead;
		while (lastGen->mNextGenerator) {
			lastGen = lastGen->mNextGenerator;
		}
		Generator* gen          = new Generator;
		lastGen->mNextGenerator = gen;
		gen->mPrevGenerator     = lastGen;
		gen->setPos(navi->mPosition);
		gen->setOffset(Vector3f(0.0f, 0.0f, 0.0f));
		mGenListHead->mMgr = this;
		mGenCount++;
	}

	server.RefreshNode();
}

void GeneratorMgr::removeGenerator(AgeServer& server, Generator* gen)
{
	Generator* root = mGenListHead;
	while (true) {
		if (root == nullptr) {
			server.RefreshNode();
			return;
		}
		if (root == gen) {
			break;
		}
		root = root->mNextGenerator;
	}

	if (root->mPrevGenerator) {
		root->mPrevGenerator->mNextGenerator = root->mNextGenerator;
		if (root == mGenListHead) {
			mGenListHead = root->mPrevGenerator;
		}
	}

	if (root->mNextGenerator) {
		root->mNextGenerator->mPrevGenerator = root->mPrevGenerator;
		if (root == mGenListHead) {
			mGenListHead = root->mNextGenerator;
		}
	}

	if (root) {
		delete root;
	}
	mGenCount--;
	if (mGenCount == 0) {
		mGenListHead = nullptr;
	}
	server.RefreshNode();
}

void Generator::changeNaviPos()
{
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		navi->mPosition     = mGenPosition;
		navi->mLastPosition = mGenPosition;
	}
}

void Generator::setNaviPos()
{
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		mGenPosition = navi->mPosition;
	}
}

void Generator::genAge(AgeServer& server)
{
	server.StartGroup("info");
	char version[8];
	mGeneratorVersion.sprint(version);
	char buf[128];
	sprintf("version [%s]", version);
	server.NewLabel(buf);
	server.EndGroup();

	server.StartGroup("id");
	mGeneratorName.genAge(server, "id");
	server.NewEditor("memo", mMemo, sizeof(mMemo) + 1);
	server.EndGroup();

	server.StartGroup("Carry Over");
	server.StartBitGroup("flags", &mCarryOverFlags, 200);
	server.NewBit("ジェネレータを残す", GENCARRY_Unk1, 0);         // Leave Generator
	server.NewBit("生んだやつを残す", GENCARRY_Unk2, 0);           // Leave the one you gave birth to
	server.NewBit("数を残す", GENCARRY_Unk3, 0);                   // Leave a number
	server.NewBit("ジェネレータを残す", GENCARRY_SavePosition, 0); // Leave a place
	server.EndBitGroup();
	server.EndGroup();

	server.StartGroup("Controll");
	server.NewButton("init", new Delegate<Generator>(this, init), 221);
	server.NewButton("delete", new Delegate1<Generator, AgeServer&>(this, removeSelf), 221);
	server.EndGroup();

	server.StartGroup("Position");
	server.NewButton("move to navi pos", new Delegate<Generator>(this, setNaviPos), 221);
	server.NewButton("move navi to this pos", new Delegate<Generator>(this, changeNaviPos), 221);
	server.NewEditor("pos x", &mGenPosition.x, -8000.0f, 8000.0f, 0x140);
	server.NewEditor("pos y", &mGenPosition.y, -8000.0f, 8000.0f, 0x140);
	server.NewEditor("pos z", &mGenPosition.z, -8000.0f, 8000.0f, 0x140);
	server.NewEditor("offset x", &mGenOffset.x, -1000.0f, 1000.0f, 0x140);
	server.NewEditor("offset y", &mGenOffset.y, -1000.0f, 1000.0f, 0x140);
	server.NewEditor("offset z", &mGenOffset.z, -1000.0f, 1000.0f, 0x140);
	server.EndGroup();

	u32 id = '    ';
	if (mGenObject) {
		id = mGenObject->mID;
	} else {
		id = '    ';
	}
	// some inline idk
	char buf2[256];
	sprintf(buf2, "Object : version(%s)", &id);
	server.StartGroup(buf2);
	server.setOnChange(new Delegate1<Generator, AgeServer&>(this, changeObject));
	server.StartOptionBox("change", (int*)&mGenObjectID, 0x110);
	// some jank here
	server.EndOptionBox();
	server.setOnChange((Delegate<Generator>*)nullptr);
	if (mGenObject) {
		mGenObject;
	} else {
		server.NewLabel("unset");
	}
	server.EndGroup();

	server.StartGroup("Area");
	server.setOnChange(new Delegate1<Generator, AgeServer&>(this, changeArea));
	server.StartOptionBox("change", (int*)&mGenAreaID, 0x110);
	// some jank here
	server.EndOptionBox();
	server.setOnChange((Delegate<Generator>*)nullptr);
	if (mGenArea) {
		mGenArea;
	} else {
		server.NewLabel("unset");
	}
	server.EndGroup();

	server.StartGroup("Number");
	server.setOnChange(new Delegate1<Generator, AgeServer&>(this, changeType));
	server.StartOptionBox("change", (int*)&mGenTypeID, 0x110);
	// some jank here
	server.EndOptionBox();
	server.setOnChange((Delegate<Generator>*)nullptr);
	if (mGenArea) {
		mGenArea;
	} else {
		server.NewLabel("unset");
	}
	server.EndGroup();
}

void Generator::changeArea(AgeServer& server)
{
	if (mGenArea) {
		if (mGenArea->mVersion == mGenAreaID) {
			return;
		}
		delete mGenArea;
	}
	mGenArea = GenAreaFactory::getProduct(mGenAreaID);
	server.RefreshSection();
}

void Generator::changeObject(AgeServer& server)
{
	if (mGenObject) {
		if (mGenObject->mVersion == mGenObjectID) {
			return;
		}
		delete mGenObject;
	}
	mGenObject = GenObjectFactory::getProduct(mGenObjectID);
	server.RefreshSection();
}

void Generator::changeType(AgeServer& server)
{
	if (mGenType) {
		if (mGenType->mVersion == mGenTypeID) {
			return;
		}
		delete mGenType;
	}
	mGenType = GenTypeFactory::getProduct(mGenTypeID);
	server.RefreshSection();
}

void Generator::removeSelf(AgeServer& server)
{
	mMgr->removeGenerator(server, this);
}

#endif
