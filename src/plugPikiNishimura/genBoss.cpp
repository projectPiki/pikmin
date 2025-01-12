#include "Generator.h"
#include "Boss.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	8014D2D0
 * Size:	00008C
 */
static GenObject* makeObjectBoss()
{
	return new GenObjectBoss();
}

/*
 * --INFO--
 * Address:	8014D35C
 * Size:	000088
 */
void GenObjectBoss::initialise()
{
	GenObjectFactory::factory->registerMember('boss', &makeObjectBoss, "ボスを発生", 2);
}

/*
 * --INFO--
 * Address:	8014D3E4
 * Size:	0000EC
 */
void GenObjectBoss::doRead(RandomAccessStream& input)
{
	if (mVersion == 'v0.0') {
		mBossID = input.readInt();
		return;
	}

	if (mVersion < 2) {
		mBossID     = input.readInt();
		mItemIndex  = input.readInt();
		mItemColour = input.readInt();
		mItemCount  = input.readInt();
		ID32 id;
		id.read(input);
		return;
	}

	readParameters(input);
}

/*
 * --INFO--
 * Address:	8014D4D0
 * Size:	000020
 */
void GenObjectBoss::doWrite(RandomAccessStream& output)
{
	writeParameters(output);
}

/*
 * --INFO--
 * Address:	8014D4F0
 * Size:	000020
 */
void GenObjectBoss::ramLoadParameters(RandomAccessStream& input)
{
	readParameters(input);
}

/*
 * --INFO--
 * Address:	8014D510
 * Size:	000020
 */
void GenObjectBoss::ramSaveParameters(RandomAccessStream& output)
{
	writeParameters(output);
}

/*
 * --INFO--
 * Address:	8014D530
 * Size:	000080
 */
void GenObjectBoss::readParameters(RandomAccessStream& input)
{
	// this is too much compression, just read them as words goddamn it!
	union GenFlags {
		u32 w;
		struct {
			u32 m0 : 20;
			u32 m1 : 4;
			u32 m2 : 2;
			u32 m3 : 2;
			u32 m4 : 4;
		} b;
	} flags;

	flags.w = input.readInt();

	mBossID          = flags.b.m4;
	mItemIndex       = flags.b.m3;
	mItemColour      = flags.b.m2;
	mItemCount       = flags.b.m1;
	mPelletConfigIdx = flags.b.m0 - 1;
}

/*
 * --INFO--
 * Address:	8014D5B0
 * Size:	000090
 */
void GenObjectBoss::writeParameters(RandomAccessStream& output)
{
	// this is too much compression, just write them as words goddamn it!
	union GenFlags {
		u32 w;
		struct {
			u32 m0 : 20;
			u32 m1 : 4;
			u32 m2 : 2;
			u32 m3 : 2;
			u32 m4 : 4;
		} b;
	} flags;

	flags.w    = 0;
	flags.b.m4 = mBossID;
	flags.b.m3 = mItemIndex;
	flags.b.m2 = mItemColour;
	flags.b.m1 = mItemCount;
	flags.b.m0 = mPelletConfigIdx + 1;

	output.writeInt(flags.w);
}

/*
 * --INFO--
 * Address:	8014D640
 * Size:	000150
 */
void GenObjectBoss::updateUseList(Generator*, int count)
{
	if (mBossID == BOSS_Spider) {
		bossMgr->addUseCount(BOSS_Spider, 1);
		return;
	}
	if (mBossID == BOSS_Snake) {
		bossMgr->addUseCount(BOSS_Snake, 1);
		return;
	}
	if (mBossID == BOSS_Slime) {
		bossMgr->addUseCount(BOSS_Slime, 1);
		bossMgr->addUseCount(BOSS_Nucleus, 1);
		bossMgr->addUseCount(BOSS_CoreNucleus, 1);
		return;
	}
	if (mBossID == BOSS_King) {
		bossMgr->addUseCount(BOSS_King, 1);
		return;
	}
	if (mBossID == BOSS_Kogane) {
		bossMgr->addUseCount(BOSS_Kogane, count);
		return;
	}
	if (mBossID == BOSS_Pom) {
		bossMgr->addUseCount(BOSS_Pom, 1);
		return;
	}
	if (mBossID == BOSS_KingBack) {
		bossMgr->addUseCount(BOSS_KingBack, 1);
		return;
	}
	if (mBossID == BOSS_BoxSnakeMake) {
		bossMgr->addUseCount(BOSS_BoxSnake, 1);
		return;
	}
	if (mBossID == BOSS_MizuMake) {
		bossMgr->addUseCount(BOSS_Mizu, 1);
		return;
	}
	if (mBossID == BOSS_GeyzerMake) {
		bossMgr->addUseCount(BOSS_Geyzer, 1);
		return;
	}
}

/*
 * --INFO--
 * Address:	8014D790
 * Size:	00013C
 */
Creature* GenObjectBoss::birth(BirthInfo& info)
{
	Boss* boss = nullptr;
	if (mBossID == BOSS_Spider) {
		boss = bossMgr->create(BOSS_Spider, info, this);
	} else if (mBossID == BOSS_Snake) {
		boss = bossMgr->create(BOSS_Snake, info, this);
	} else if (mBossID == BOSS_Slime) {
		boss = bossMgr->create(BOSS_Slime, info, this);
	} else if (mBossID == BOSS_King) {
		boss = bossMgr->create(BOSS_King, info, this);
	} else if (mBossID == BOSS_Kogane) {
		boss = bossMgr->create(BOSS_Kogane, info, this);
	} else if (mBossID == BOSS_Pom) {
		boss = bossMgr->create(BOSS_Pom, info, this);
	} else if (mBossID == BOSS_KingBack) {
		boss = bossMgr->create(BOSS_KingBack, info, this);
	} else if (mBossID == BOSS_BoxSnakeMake) {
		boss = bossMgr->create(BOSS_BoxSnakeMake, info, this);
	} else if (mBossID == BOSS_MizuMake) {
		boss = bossMgr->create(BOSS_MizuMake, info, this);
	} else if (mBossID == BOSS_GeyzerMake) {
		boss = bossMgr->create(BOSS_GeyzerMake, info, this);
	}

	return boss;
}
