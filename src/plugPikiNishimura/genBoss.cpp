#include "Age.h"
#include "Boss.h"
#include "DebugLog.h"
#include "Generator.h"
#include "Pellet.h"
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
DEFINE_PRINT("genBoss");

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
	if (mBossID == GENBOSS_Spider) {
		bossMgr->addUseCount(BOSS_Spider, 1);
		return;
	}
	if (mBossID == GENBOSS_Snake) {
		bossMgr->addUseCount(BOSS_Snake, 1);
		return;
	}
	if (mBossID == GENBOSS_Slime) {
		bossMgr->addUseCount(BOSS_Slime, 1);
		bossMgr->addUseCount(BOSS_Nucleus, 1);
		bossMgr->addUseCount(BOSS_CoreNucleus, 1);
		return;
	}
	if (mBossID == GENBOSS_King) {
		bossMgr->addUseCount(BOSS_King, 1);
		return;
	}
	if (mBossID == GENBOSS_Kogane) {
		bossMgr->addUseCount(BOSS_Kogane, count);
		return;
	}
	if (mBossID == GENBOSS_Pom) {
		bossMgr->addUseCount(BOSS_Pom, 1);
		return;
	}
	if (mBossID == GENBOSS_KingBack) {
		bossMgr->addUseCount(BOSS_KingBack, 1);
		return;
	}
	if (mBossID == GENBOSS_BoxSnake) {
		bossMgr->addUseCount(BOSS_BoxSnake, 1);
		return;
	}
	if (mBossID == GENBOSS_Mizu) {
		bossMgr->addUseCount(BOSS_Mizu, 1);
		return;
	}
	if (mBossID == GENBOSS_Geyzer) {
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
	Creature* boss = nullptr;
	PRINT("\n");
	PRINT("************ BOSS BIRTH START : kind = %d ************\n", mBossID);
	if (mBossID == GENBOSS_Spider) {
		boss = bossMgr->create(GENBOSS_Spider, info, this);
	} else if (mBossID == GENBOSS_Snake) {
		boss = bossMgr->create(GENBOSS_Snake, info, this);
	} else if (mBossID == GENBOSS_Slime) {
		boss = bossMgr->create(GENBOSS_Slime, info, this);
	} else if (mBossID == GENBOSS_King) {
		boss = bossMgr->create(GENBOSS_King, info, this);
	} else if (mBossID == GENBOSS_Kogane) {
		boss = bossMgr->create(GENBOSS_Kogane, info, this);
	} else if (mBossID == GENBOSS_Pom) {
		boss = bossMgr->create(GENBOSS_Pom, info, this);
	} else if (mBossID == GENBOSS_KingBack) {
		boss = bossMgr->create(GENBOSS_KingBack, info, this);
	} else if (mBossID == GENBOSS_BoxSnake) {
		boss = bossMgr->create(GENBOSS_BoxSnake, info, this);
	} else if (mBossID == GENBOSS_Mizu) {
		boss = bossMgr->create(GENBOSS_Mizu, info, this);
	} else if (mBossID == GENBOSS_Geyzer) {
		boss = bossMgr->create(GENBOSS_Geyzer, info, this);
	}

	if (!boss) {
		PRINT("************ BOSS BIRTH END   : FAILURE  ************\n");
	} else {
		PRINT("  VVVVVVVVV   \n");
		PRINT(" ww       ww  \n");
		PRINT("<-○--__   |  \n");
		PRINT(" |    Λ -○->\n");
		PRINT("  ＼  ё ／   \n");
		PRINT("************ BOSS BIRTH END   : SUCCESS  ************\n");
	}
	PRINT("\n");

	return boss;
}

#ifdef WIN32

void GenObjectBoss::doGenAge(AgeServer& server)
{
	server.StartOptionBox("ボスの種類", &mBossID, 252); // boss type
	server.NewOption("ダマグモ", 0);
	server.NewOption("ヘビガラス１", 1);
	server.NewOption("ヘビガラス２", 7);
	server.NewOption("スライム", 2);
	server.NewOption("キングチャッピー", 3);
	server.NewOption("コガネ", 4);
	server.NewOption("ポンガシ草", 5);
	server.NewOption("キングの背中", 6);
	server.NewOption("間欠泉１", 8);
	server.NewOption("間欠泉２", 9);
	server.EndOptionBox();

	server.StartOptionBox("ペレットの種類", &mItemIndex, 252);
	server.NewOption("１ペレット", 0);
	server.NewOption("５ペレット", 1);
	server.NewOption("１０ペレット", 2);
	server.NewOption("２０ペレット", 3);
	server.EndOptionBox();

	server.StartOptionBox("ペレットの色", &mItemColour, 252);
	server.NewOption("青ペレット", 0);
	server.NewOption("赤ペレット", 1);
	server.NewOption("黄ペレット", 2);
	server.NewOption("ランダム", 3);
	server.EndOptionBox();

	server.StartOptionBox("ペレットの数", &mItemCount, 252);
	for (int i = 0; i < 16; i++) {
		char id[4];
		if (i / 10 < 1) {
			id[0] = i % 10 + '0';
			id[1] = 0;
		} else {
			id[0] = i / 10 + '0';
			id[1] = i % 10 + '0';
			id[2] = 0;
		}
		server.NewOption(id, i);
	}
	server.EndOptionBox();

	server.StartOptionBox("ＵＦＯパーツ", &mPelletConfigIdx, 252);
	server.NewOption("none", -1);
	for (int i = 0; i < pelletMgr->getNumConfigs(); i++) {
		PelletConfig* config = pelletMgr->getConfigFromIdx(i);
		server.NewOption(config->mPelletName().mString, config->mPelletId.mId);
	}
	server.EndOptionBox();
}

#endif
