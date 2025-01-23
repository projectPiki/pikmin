#include "BaseInf.h"
#include "Piki.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "gameflow.h"
#include "DebugLog.h"

PikiInfMgr pikiInfMgr;

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
DEFINE_PRINT("pikiInf");

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
PikiInfMgr::PikiInfMgr()
{
	for (int i = 0; i < 3; i++) {
		mPikiCounts[0][i] = mPikiCounts[1][i] = mPikiCounts[2][i] = 0;
	}
}

/*
 * --INFO--
 * Address:	800C56D4
 * Size:	000028
 */
void PikiInfMgr::initGame()
{
	pikiInfMgr.clear();
}

/*
 * --INFO--
 * Address:	800C56FC
 * Size:	000078
 */
void PikiInfMgr::saveCard(RandomAccessStream& output)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			output.writeInt(mPikiCounts[i][j]);
		}
	}
}

/*
 * --INFO--
 * Address:	800C5774
 * Size:	000070
 */
void PikiInfMgr::loadCard(RandomAccessStream& input)
{
	// is this C? Kando, why did you do that?
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			mPikiCounts[i][j] = input.readInt();
		}
	}

	PRINT("** loadCard (Container Piki Counts)\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			PRINT("\tcolor%d:%d = %d pikis\n", i, j, mPikiCounts[i][j]);
		}
	}
}

/*
 * --INFO--
 * Address:	800C57E4
 * Size:	000034
 */
void PikiInfMgr::incPiki(Piki* piki)
{
	u16 color = piki->mColor;
	if (color >= PikiMinColor && color <= PikiMaxColor) {
		// todo: COMEBACKHERE TODO TODO: TODO
		piki->mColor;
	}

	int happa = piki->mHappa;
	if (happa >= PikiMinHappa && happa <= PikiMaxHappa) {
		piki->mHappa;
	}

	mPikiCounts[color][happa]++;
}

/*
 * --INFO--
 * Address:	800C5818
 * Size:	00001C
 */
void PikiInfMgr::incPiki(int color, int happa)
{
	mPikiCounts[color][happa]++;
}

/*
 * --INFO--
 * Address:	800C5834
 * Size:	000034
 */
void PikiInfMgr::decPiki(Piki* piki)
{
	u16 color = piki->mColor;
	if (color >= PikiMinColor && color <= PikiMaxColor) {
		piki->mColor;
	}

	int happa = piki->mHappa;
	if (happa >= PikiMinHappa && happa <= PikiMaxHappa) {
		piki->mHappa;
	}

	mPikiCounts[color][happa]--;
}

/*
 * --INFO--
 * Address:	800C5868
 * Size:	00002C
 */
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

/*
 * --INFO--
 * Address:	800C5894
 * Size:	00005C
 */
void BaseInf::store(Creature* owner)
{
	mPosition = owner->mPosition;
	mRotation = owner->mRotation;
	doStore(owner);
}

/*
 * --INFO--
 * Address:	800C58F4
 * Size:	00005C
 */
void BaseInf::restore(Creature* owner)
{
	owner->mPosition = mPosition;
	owner->mRotation = mRotation;
	doRestore(owner);
}

/*
 * --INFO--
 * Address:	800C5954
 * Size:	0000A0
 */
void BaseInf::saveCard(RandomAccessStream& card)
{
	card.writeShort(mPosition.x);
	card.writeShort(mPosition.y);
	card.writeShort(mPosition.z);
}

/*
 * --INFO--
 * Address:	800C59F4
 * Size:	0000F4
 */
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

/*
 * --INFO--
 * Address:	800C5AE8
 * Size:	0000C4
 */
void BPikiInf::saveCard(RandomAccessStream& card)
{
	BaseInf::saveCard(card);
	u8 byte = (mNextKeyIndex << 2) | mPikiColour;
	card.writeByte(byte);
}

/*
 * --INFO--
 * Address:	800C5BAC
 * Size:	000118
 */
void BPikiInf::loadCard(RandomAccessStream& card)
{
	BaseInf::loadCard(card);
	u8 byte       = card.readByte();
	mPikiColour   = byte & 0x3;
	mNextKeyIndex = (byte >> 2) & 0x3F;
}

/*
 * --INFO--
 * Address:	800C5CC4
 * Size:	000014
 */
void BPikiInf::doStore(Creature* piki)
{
	mPikiColour   = static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mFirstFrameIndex;
	mNextKeyIndex = static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mLastFrameIndex;
}

/*
 * --INFO--
 * Address:	800C5CD8
 * Size:	000014
 */
void BPikiInf::doRestore(Creature* piki)
{
	static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mFirstFrameIndex = mPikiColour;
	static_cast<Piki*>(piki)->mPikiAnimMgr.mLowerAnimator.mLastFrameIndex  = mNextKeyIndex;
}

/*
 * --INFO--
 * Address:	800C5CEC
 * Size:	000170
 */
MonoInfMgr::MonoInfMgr()
{
	mInfs = nullptr;
}

/*
 * --INFO--
 * Address:	800C5E5C
 * Size:	0000D0
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

/*
 * --INFO--
 * Address:	800C5F2C
 * Size:	000058
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

/*
 * --INFO--
 * Address:	800C5F84
 * Size:	000048
 */
void MonoInfMgr::delInf(BaseInf* inf)
{
	inf->del();
	mFreeList.add(inf);
}

/*
 * --INFO--
 * Address:	800C5FCC
 * Size:	000024
 */
int MonoInfMgr::getActiveNum()
{
	return mActiveList.getChildCount();
}

/*
 * --INFO--
 * Address:	800C5FF0
 * Size:	000024
 */
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

/*
 * --INFO--
 * Address:	800C6014
 * Size:	0000C4
 */
void MonoInfMgr::loadCard(RandomAccessStream& input)
{
	clearActiveList();

	int max = input.readInt();

	for (int i = 0; i < max; i++) {
		getFreeInf()->loadCard(input);
	}
}

/*
 * --INFO--
 * Address:	800C60D8
 * Size:	0000CC
 */
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

/*
 * --INFO--
 * Address:	800C61A4
 * Size:	00002C
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

/*
 * --INFO--
 * Address:	800C61D0
 * Size:	0000D4
 */
BaseInf* CreatureInfMgr::newInf()
{
	return new CreatureInf();
}

/*
 * --INFO--
 * Address:	800C62A4
 * Size:	0000E0
 */
void CreatureInf::doStore(Creature* owner)
{
	// probably inlines but honestly whatever.
	u32 badCompiler;
	u32 badCompiler2;

	mObjType             = owner->mObjType;
	mRebirthDay          = 0;
	mCurrentDay          = -1;
	mAdjustFaceDirection = owner->isCreatureFlag(CF_FaceDirAdjust) != 0;
	owner->doStore(this);

	if (owner->mRebirthDay > 0) {
		if (owner->isAlive()) {
			mAdjustFaceDirection = 1;
			mRebirthDay          = owner->mRebirthDay;
		} else {
			mAdjustFaceDirection = 0;
			mCurrentDay          = gameflow.mWorldClock.mCurrentDay;
			mRebirthDay          = owner->mRebirthDay;
		}
	}
}

/*
 * --INFO--
 * Address:	800C6384
 * Size:	000060
 */
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

/*
 * --INFO--
 * Address:	800C63E4
 * Size:	000030
 */
void StageInf::init()
{
	mBPikiInfMgr.init(100);
}

/*
 * --INFO--
 * Address:	800C6414
 * Size:	000064
 */
void StageInf::initGame()
{
	mBPikiInfMgr.initGame();
}

/*
 * --INFO--
 * Address:	800C6478
 * Size:	000088
 */
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
/*
 * --INFO--
 * Address:	800C6500
 * Size:	000020
 */
void StageInf::loadCard(RandomAccessStream& input)
{
	mBPikiInfMgr.loadCard(input);
}
#pragma dont_inline reset
