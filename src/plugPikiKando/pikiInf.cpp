#include "BaseInf.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "GlobalGameOptions.h"
#include "Piki.h"
#include "PikiHeadItem.h"
#include "gameflow.h"
#include "sysNew.h"
#include "teki.h"

PikiInfMgr pikiInfMgr;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(10)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("pikiInf");

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
PikiInfMgr::PikiInfMgr()
{
	for (int i = 0; i < PikiHappaCount; i++) {
		mPikiCounts[Blue][i] = mPikiCounts[Red][i] = mPikiCounts[Yellow][i] = 0;
	}
}

/**
 * @todo: Documentation
 */
void PikiInfMgr::initGame()
{
	pikiInfMgr.clear();
}

/**
 * @todo: Documentation
 */
void PikiInfMgr::saveCard(RandomAccessStream& output)
{
	for (int i = 0; i < PikiColorCount; i++) {
		for (int j = 0; j < PikiHappaCount; j++) {
			output.writeInt(mPikiCounts[i][j]);
		}
	}
}

/**
 * @todo: Documentation
 */
void PikiInfMgr::loadCard(RandomAccessStream& input)
{
	// is this C? Kando, why did you do that?
	int i, j;

	for (i = 0; i < PikiColorCount; i++) {
		for (j = 0; j < PikiHappaCount; j++) {
			mPikiCounts[i][j] = input.readInt();
		}
	}

	PRINT("** loadCard (Container Piki Counts)\n");
	for (i = 0; i < PikiColorCount; i++) {
		for (j = 0; j < PikiHappaCount; j++) {
			PRINT("\tcolor%d:%d = %d pikis\n", i, j, mPikiCounts[i][j]);
		}
	}
}

/**
 * @todo: Documentation
 */
void PikiInfMgr::incPiki(Piki* piki)
{
	if (piki->mColor < PikiMinColor || piki->mColor > PikiMaxColor) {
		ERROR("illegal col %d\n", piki->mColor);
	}

	if (piki->mHappa < PikiMinHappa || piki->mHappa > PikiMaxHappa) {
		ERROR("illegal happa %d\n", piki->mHappa);
	}

	mPikiCounts[piki->mColor][piki->mHappa]++;
}

/**
 * @todo: Documentation
 */
void PikiInfMgr::incPiki(int color, int happa)
{
	if (color < PikiMinColor || color > PikiMaxColor) {
		ERROR("illegal col %d\n", color);
	}
	if (happa < PikiMinHappa || happa > PikiMaxHappa) {
		ERROR("illegal happa %d\n", happa);
	}
	mPikiCounts[color][happa]++;
}

/**
 * @todo: Documentation
 */
void PikiInfMgr::decPiki(Piki* piki)
{
	if (piki->mColor < PikiMinColor || piki->mColor > PikiMaxColor) {
		ERROR("illegal col %d\n", piki->mColor);
	}

	if (piki->mHappa < PikiMinHappa || piki->mHappa > PikiMaxHappa) {
		ERROR("illegal happa %d\n", piki->mHappa);
	}

	mPikiCounts[piki->mColor][piki->mHappa]--;
}

/**
 * @todo: Documentation
 */
void PikiInfMgr::clear()
{
	for (int happa = 0; happa < PikiHappaCount; ++happa) {
		mPikiCounts[Yellow][happa] = 0;
		mPikiCounts[Red][happa]    = 0;
		mPikiCounts[Blue][happa]   = 0;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size)
 */
int PikiInfMgr::getTotal()
{
	int total = 0;
	for (int color = 0; color < PikiColorCount; ++color) {
		for (int happa = 0; happa < PikiHappaCount; ++happa) {
			total += mPikiCounts[color][happa];
		}
	}
	return total;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A4
 */
BaseInf::BaseInf()
{
	initCore("baseInf");
	mPosition.set(0.0f, 0.0f, 0.0f);
	mRotation.set(0.0f, 0.0f, 0.0f);
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void BaseInf::store(Creature* owner)
{
	mPosition = owner->mSRT.t;
	mRotation = owner->mSRT.r;
	doStore(owner);
}

/**
 * @todo: Documentation
 */
void BaseInf::restore(Creature* owner)
{
	owner->mSRT.t = mPosition;
	owner->mSRT.r = mRotation;
	doRestore(owner);
}

/**
 * @todo: Documentation
 */
void BaseInf::saveCard(RandomAccessStream& card)
{
	card.writeShort(mPosition.x);
	card.writeShort(mPosition.y);
	card.writeShort(mPosition.z);
}

/**
 * @todo: Documentation
 */
void BaseInf::loadCard(RandomAccessStream& card)
{
	mPosition.x = card.readShort();
	mPosition.y = card.readShort();
	mPosition.z = card.readShort();
	mRotation.set(0.0f, 0.0f, 0.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000EC
 */
BPikiInf::BPikiInf()
{
	mNextKeyIndex = 0;
	mPikiColour   = Blue;
}

/**
 * @todo: Documentation
 */
void BPikiInf::saveCard(RandomAccessStream& card)
{
	BaseInf::saveCard(card);
	u8 byte = (mNextKeyIndex << 2) | mPikiColour;
	card.writeByte(byte);
}

/**
 * @todo: Documentation
 */
void BPikiInf::loadCard(RandomAccessStream& card)
{
	BaseInf::loadCard(card);
	u8 byte       = card.readByte();
	mPikiColour   = byte & 0x3;
	mNextKeyIndex = (byte >> 2) & 0x3F;
}

/**
 * @todo: Documentation
 */
void BPikiInf::doStore(Creature* piki)
{
	if (piki->mObjType != OBJTYPE_Pikihead) {
		ERROR("mail to teppe\n");
	}
	mPikiColour   = static_cast<PikiHeadItem*>(piki)->mSeedColor;
	mNextKeyIndex = static_cast<PikiHeadItem*>(piki)->mFlowerStage;
}

/**
 * @todo: Documentation
 */
void BPikiInf::doRestore(Creature* piki)
{
	if (piki->mObjType != OBJTYPE_Pikihead) {
		ERROR("mail to teppe2\n");
	}
	static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mStartKeyIndex = mPikiColour;
	static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mEndKeyIndex   = mNextKeyIndex;
}

/**
 * @todo: Documentation
 */
MonoInfMgr::MonoInfMgr()
{
	mInfs = nullptr;
}

/**
 * @todo: Documentation
 */
void MonoInfMgr::init(int count)
{
	mActiveList.initCore("activeList");
	mFreeList.initCore("freeList");
	mInfCount = count;
	mInfs     = new BaseInf*[mInfCount];

	for (int i = 0; i < count; i++) {
		mInfs[i] = newInf();
		mFreeList.add(mInfs[i]);
	}
}

/**
 * @todo: Documentation
 */
BaseInf* MonoInfMgr::getFreeInf()
{
	BaseInf* inf = static_cast<BaseInf*>(mFreeList.mChild);
	if (inf) {
		inf->del();
		mActiveList.add(inf);
	}
	return inf;
}

/**
 * @todo: Documentation
 */
void MonoInfMgr::delInf(BaseInf* inf)
{
	inf->del();
	mFreeList.add(inf);
}

/**
 * @todo: Documentation
 */
int MonoInfMgr::getActiveNum()
{
	return mActiveList.getChildCount();
}

/**
 * @todo: Documentation
 */
int MonoInfMgr::getFreeNum()
{
	return mFreeList.getChildCount();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00008C (Matching by size)
 */
void MonoInfMgr::saveCard(RandomAccessStream& stream)
{
	int freeNum = getFreeNum();
	stream.writeInt(freeNum);
	FOREACH_NODE(BaseInf, mActiveList.mChild, inf)
	{
		inf->saveCard(stream);
	}
	PRINT(" SAVE CARD ***** %d です\n", freeNum); // " SAVE CARD ***** there are %d\n"
}

/**
 * @todo: Documentation
 */
void MonoInfMgr::loadCard(RandomAccessStream& input)
{
	BaseInf* inf = static_cast<BaseInf*>(mActiveList.mChild);
	while (inf) {
		BaseInf* next = static_cast<BaseInf*>(inf->mNext);
		inf->del();
		mFreeList.add(inf);
		inf = next;
	}

	int max = input.readInt();
	for (int i = 0; i < max; i++) {
		BaseInf* bi = getFreeInf();
		if (!bi) {
			ERROR("gakkari bi=0!\n");
		}
		bi->loadCard(input);
	}
	PRINT("*** %d ピキ デス\n", max); // "*** %d Piki Death\n"
}

/**
 * @todo: Documentation
 */
BaseInf* BPikiInfMgr::newInf()
{
	return new BPikiInf();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000064
 */
void BPikiInfMgr::initGame()
{
	BaseInf* inf;
	BaseInf* next;

	inf = static_cast<BaseInf*>(mActiveList.mChild);
	while (inf) {
		next = static_cast<BaseInf*>(inf->mNext);
		inf->del();
		mFreeList.add(inf);
		inf = next;
	}
}

/**
 * @todo: Documentation
 */
int BPikiInfMgr::getPikiCount(int color)
{
	int count = 0;
	FOREACH_NODE(BPikiInf, mActiveList.mChild, currInf)
	{
		if (currInf->mPikiColour == color) {
			count++;
		}
	}

	return count;
}

// These variable names do not appear in the MW Linker map because every function that uses them is unused.

int CreatureInfMgr::maxTypes;
int CreatureInfMgr::numTypes;
int* CreatureInfMgr::idx2type;
CreatureInfMgr::TypeData* CreatureInfMgr::typeData;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size)
 */
void CreatureInfMgr::beginRegister(int size)
{
	maxTypes = size;
	idx2type = new int[size];
	typeData = new TypeData[size];
	numTypes = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000038 (Matching by size)
 */
void CreatureInfMgr::registerType(int type, CreatureStoreFun storeFun, CreatureRestoreFun restoreFun)
{
	TypeData* data     = &typeData[numTypes];
	idx2type[numTypes] = type;

	data->mType       = type;
	data->mStoreFun   = storeFun;
	data->mRestoreFun = restoreFun;

	++numTypes;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004 (Matching by size)
 */
void CreatureInfMgr::endRegister()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size)
 */
CreatureStoreFun CreatureInfMgr::getStoreFun(int type)
{
	for (int i = 0; i < numTypes; ++i) {
		if (idx2type[i] == type) {
			return typeData[i].mStoreFun;
		}
	}
	return nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size)
 */
CreatureRestoreFun CreatureInfMgr::getRestoreFun(int type)
{
	for (int i = 0; i < numTypes; ++i) {
		if (idx2type[i] == type) {
			return typeData[i].mRestoreFun;
		}
	}
	return nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
CreatureInf::CreatureInf()
{
	mObjType    = OBJTYPE_INVALID;
	mCurrentDay = mRebirthDay = 0;
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
BaseInf* CreatureInfMgr::newInf()
{
	return new CreatureInf();
}

/**
 * @todo: Documentation
 */
void CreatureInf::doStore(Creature* owner)
{
	// probably inlines but honestly whatever.
	STACK_PAD_VAR(2);

	mObjType             = owner->mObjType;
	mRebirthDay          = 0;
	mCurrentDay          = -1;
	mAdjustFaceDirection = owner->isCreatureFlag(CF_AdjustFaceDirOnSpawn);
	owner->doStore(this);

	if (owner->getRebirthDay() > 0) {
		if (owner->isAlive()) {
			mAdjustFaceDirection = 1;
			mRebirthDay          = owner->mRebirthDay;
			PRINT_KANDO("KKKKKKKKKKKK ALIVE : CARRYOVER !!!\n");
		} else {
			mAdjustFaceDirection = 0;
			mCurrentDay          = gameflow.mWorldClock.mCurrentDay;
			mRebirthDay          = owner->mRebirthDay;
			PRINT_KANDO("KKKKKKKKKKKK DEAD : CARRYOVER !!!\n");
		}
	}
}

/**
 * @todo: Documentation
 */
void CreatureInf::doRestore(Creature* owner)
{
	if (mAdjustFaceDirection != 0) {
		owner->setCreatureFlag(CF_AdjustFaceDirOnSpawn);
	} else {
		owner->resetCreatureFlag(CF_AdjustFaceDirOnSpawn);
	}

	owner->doRestore(this);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084 (Matching by size)
 */
void CreatureInfMgr::updateUseList()
{
	FOREACH_NODE(CreatureInf, mActiveList.mChild, inf)
	{
		switch (inf->mObjType) {
		case OBJTYPE_SluiceSoft:
		case OBJTYPE_SluiceHard:
		case OBJTYPE_SluiceBomb:
		case OBJTYPE_SluiceBombHard:
		{
			itemMgr->addUseList(inf->mObjType);
			break;
		}
		case OBJTYPE_Teki:
		{
			tekiMgr->mUsingType[inf->mObjInfo1] = true;
			break;
		}
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00022C
 */
void CreatureInfMgr::restoreAll()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void StageInf::init()
{
	mBPikiInfMgr.init(MAX_PIKI_ON_FIELD);
}

/**
 * @todo: Documentation
 */
void StageInf::initGame()
{
	mBPikiInfMgr.initGame();
}

/**
 * @todo: Documentation
 */
void StageInf::saveCard(RandomAccessStream& output)
{
	int activeNum = mBPikiInfMgr.getActiveNum();
	output.writeInt(activeNum);

	FOREACH_NODE(BaseInf, mBPikiInfMgr.mActiveList.mChild, inf)
	{
		inf->saveCard(output);
	}

	BUMP_REGISTER(r0); // No fucking way
	PRINT(" SAVE CARD ***** %d です\n", activeNum);
}

/**
 * @todo: Documentation
 */
void StageInf::loadCard(RandomAccessStream& input)
{
	mBPikiInfMgr.loadCard(input);
}
