#include "BaseInf.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "GlobalGameOptions.h"
#include "Piki.h"
#include "gameflow.h"
#include "sysNew.h"

PikiInfMgr pikiInfMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(10)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("pikiInf");

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
PikiInfMgr::PikiInfMgr()
{
	for (int i = 0; i < PikiHappaCount; i++) {
		mPikiCounts[Blue][i] = mPikiCounts[Red][i] = mPikiCounts[Yellow][i] = 0;
	}
}

void PikiInfMgr::initGame()
{
	pikiInfMgr.clear();
}

void PikiInfMgr::saveCard(RandomAccessStream& output)
{
	for (int i = 0; i < PikiColorCount; i++) {
		for (int j = 0; j < PikiHappaCount; j++) {
			output.writeInt(mPikiCounts[i][j]);
		}
	}
}

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

void PikiInfMgr::incPiki(Piki* piki)
{
	u16 color = piki->mColor;
	if (color < PikiMinColor || color > PikiMaxColor) {
		ERROR("illegal col %d\n", piki->mColor);
	}

	int happa = piki->mHappa;
	if (happa < PikiMinHappa || happa > PikiMaxHappa) {
		ERROR("illegal happa %d\n", piki->mHappa);
	}

	mPikiCounts[color][happa]++;
}

void PikiInfMgr::incPiki(int color, int happa)
{
	if (color >= PikiMinColor || color <= PikiMaxColor) {
		ERROR("illegal col %d\n", color);
	}
	if (happa >= PikiMinHappa || happa <= PikiMaxHappa) {
		ERROR("illegal happa %d\n", happa);
	}
	mPikiCounts[color][happa]++;
}

void PikiInfMgr::decPiki(Piki* piki)
{
	u16 color = piki->mColor;
	if (color < PikiMinColor || color > PikiMaxColor) {
		ERROR("illegal col %d\n", piki->mColor);
	}

	int happa = piki->mHappa;
	if (happa < PikiMinHappa || happa > PikiMaxHappa) {
		ERROR("illegal happa %d\n", piki->mHappa);
	}

	mPikiCounts[color][happa]--;
}

void PikiInfMgr::clear()
{
	// leaves
	mPikiCounts[Blue][Leaf] = mPikiCounts[Red][Leaf] = mPikiCounts[Yellow][Leaf] = 0;

	// buds
	mPikiCounts[Blue][Bud] = mPikiCounts[Red][Bud] = mPikiCounts[Yellow][Bud] = 0;

	// flowers
	mPikiCounts[Blue][Flower] = mPikiCounts[Red][Flower] = mPikiCounts[Yellow][Flower] = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
int PikiInfMgr::getTotal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
BaseInf::BaseInf()
{
	initCore("baseInf");
	mPosition.set(0.0f, 0.0f, 0.0f);
	mRotation.set(0.0f, 0.0f, 0.0f);
	// UNUSED FUNCTION
}

void BaseInf::store(Creature* owner)
{
	mPosition = owner->mSRT.t;
	mRotation = owner->mSRT.r;
	doStore(owner);
}

void BaseInf::restore(Creature* owner)
{
	owner->mSRT.t = mPosition;
	owner->mSRT.r = mRotation;
	doRestore(owner);
}

void BaseInf::saveCard(RandomAccessStream& card)
{
	card.writeShort(mPosition.x);
	card.writeShort(mPosition.y);
	card.writeShort(mPosition.z);
}

void BaseInf::loadCard(RandomAccessStream& card)
{
	mPosition.x = card.readShort();
	mPosition.y = card.readShort();
	mPosition.z = card.readShort();
	mRotation.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
BPikiInf::BPikiInf()
{
	mPikiColour = mNextKeyIndex = 0;
	// UNUSED FUNCTION
}

void BPikiInf::saveCard(RandomAccessStream& card)
{
	BaseInf::saveCard(card);
	u8 byte = (mNextKeyIndex << 2) | mPikiColour;
	card.writeByte(byte);
}

void BPikiInf::loadCard(RandomAccessStream& card)
{
	BaseInf::loadCard(card);
	u8 byte       = card.readByte();
	mPikiColour   = byte & 0x3;
	mNextKeyIndex = (byte >> 2) & 0x3F;
}

void BPikiInf::doStore(Creature* piki)
{
	if (piki->mObjType != OBJTYPE_Pikihead) {
		ERROR("mail to teppe\n");
	}
	mPikiColour   = static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mStartKeyIndex;
	mNextKeyIndex = static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mEndKeyIndex;
}

void BPikiInf::doRestore(Creature* piki)
{
	if (piki->mObjType != OBJTYPE_Pikihead) {
		ERROR("mail to teppe2\n");
	}
	static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mStartKeyIndex = mPikiColour;
	static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mEndKeyIndex   = mNextKeyIndex;
}

MonoInfMgr::MonoInfMgr()
{
	mInfs = nullptr;
}

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

BaseInf* MonoInfMgr::getFreeInf()
{
	BaseInf* inf = static_cast<BaseInf*>(mFreeList.mChild);
	if (inf) {
		inf->del();
		mActiveList.add(inf);
	}
	return inf;
}

void MonoInfMgr::delInf(BaseInf* inf)
{
	inf->del();
	mFreeList.add(inf);
}

int MonoInfMgr::getActiveNum()
{
	return mActiveList.getChildCount();
}

int MonoInfMgr::getFreeNum()
{
	mFreeList.getChildCount();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void MonoInfMgr::saveCard(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

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

BaseInf* BPikiInfMgr::newInf()
{
	return new BPikiInf();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
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

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void CreatureInfMgr::beginRegister(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void CreatureInfMgr::registerType(int, InfFuncType1, InfFuncType2)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CreatureInfMgr::endRegister()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
CreatureInf* CreatureInfMgr::getStoreFun(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
CreatureInf* CreatureInfMgr::getRestoreFun(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
CreatureInf::CreatureInf()
{
	mObjType    = OBJTYPE_INVALID;
	mCurrentDay = mRebirthDay = 0;
	// UNUSED FUNCTION
}

BaseInf* CreatureInfMgr::newInf()
{
	return new CreatureInf();
}

void CreatureInf::doStore(Creature* owner)
{
	// probably inlines but honestly whatever.
	STACK_PAD_VAR(2);

	mObjType             = owner->mObjType;
	mRebirthDay          = 0;
	mCurrentDay          = -1;
	mAdjustFaceDirection = owner->isCreatureFlag(CF_FaceDirAdjust);
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

void CreatureInf::doRestore(Creature* owner)
{
	if (mAdjustFaceDirection != 0) {
		owner->setCreatureFlag(CF_FaceDirAdjust);
	} else {
		owner->resetCreatureFlag(CF_FaceDirAdjust);
	}

	owner->doRestore(this);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void CreatureInfMgr::updateUseList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void CreatureInfMgr::restoreAll()
{
	// UNUSED FUNCTION
}

void StageInf::init()
{
	mBPikiInfMgr.init(MAX_PIKI_ON_FIELD);
}

void StageInf::initGame()
{
	mBPikiInfMgr.initGame();
}

void StageInf::saveCard(RandomAccessStream& output)
{
	output.writeInt(mBPikiInfMgr.getActiveNum());

	FOREACH_NODE(BaseInf, mBPikiInfMgr.mActiveList.mChild, inf)
	{
		inf->saveCard(output);
	}

	// TODO: Figure out how to do this.
	PRINT(" SAVE CARD ***** %d です\n" /*, activeNum*/);
}

#pragma dont_inline on

void StageInf::loadCard(RandomAccessStream& input)
{
	mBPikiInfMgr.loadCard(input);
}

#pragma dont_inline reset
