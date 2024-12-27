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
DEFINE_PRINT("");

/*
 * --INFO--
 * Address:	8014D2D0
 * Size:	00008C
 */
static GenObject* makeObjectBoss() { return new GenObjectBoss(); }

/*
 * --INFO--
 * Address:	8014D35C
 * Size:	000088
 */
void GenObjectBoss::initialise()
{
	GenObjectFactory* fact = GenObjectFactory::factory;
	if (fact->mSpawnerCount >= fact->mMaxSpawners) {
		return;
	}

	fact->mSpawnerInfo[fact->mSpawnerCount].mID          = 'boss';
	fact->mSpawnerInfo[fact->mSpawnerCount].mGenFunction = &makeObjectBoss;
	fact->mSpawnerInfo[fact->mSpawnerCount].mName        = "ボスを発生"; // 'generate a boss'
	fact->mSpawnerInfo[fact->mSpawnerCount].mVersion     = 2;

	fact->mSpawnerCount++;
}

/*
 * --INFO--
 * Address:	8014D3E4
 * Size:	0000EC
 */
void GenObjectBoss::doRead(RandomAccessStream& input)
{
	if (mVersion == 'v0.0') {
		_18 = input.readInt();
		return;
	}

	if (mVersion < 2) {
		_18 = input.readInt();
		_1C = input.readInt();
		_20 = input.readInt();
		_24 = input.readInt();
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
void GenObjectBoss::doWrite(RandomAccessStream& output) { writeParameters(output); }

/*
 * --INFO--
 * Address:	8014D4F0
 * Size:	000020
 */
void GenObjectBoss::ramLoadParameters(RandomAccessStream& input) { readParameters(input); }

/*
 * --INFO--
 * Address:	8014D510
 * Size:	000020
 */
void GenObjectBoss::ramSaveParameters(RandomAccessStream& output) { writeParameters(output); }

/*
 * --INFO--
 * Address:	8014D530
 * Size:	000080
 */
void GenObjectBoss::readParameters(RandomAccessStream& input)
{
	// this is too much compression, just write them as words goddamn it!
	volatile union GenFlags {
		u32 w;
		u8 b[4];
	} flags;

	flags.w = input.readInt();
	_18     = flags.b[3] & 0xF;
	_1C     = (flags.b[3] >> 4) & 0x3;
	_20     = (flags.b[3] >> 6) & 0x3;
	_24     = flags.b[2] & 0xF;
	_28     = (flags.w >> 12) - 1;
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
		u8 b[4];
	} flags;

	flags.w    = 0;
	flags.b[3] = (_18 & 0xF) | (flags.b[3] & 0xFFFFFFF0);
	flags.b[3] = ((_1C << 4) & 0x30) | (flags.b[3] & 0xFFFFFFCF);
	flags.b[3] = ((_20 << 6) & 0xC0) | (flags.b[3] & 0xFFFFFF3F);
	flags.b[2] = (_24 & 0xF) | (flags.b[2] & 0xFFFFFFF0);
	flags.w    = (((_28 + 1) << 12) & ~0xFFF) | (flags.w & ~0xFFFFF000);

	output.writeInt(flags.w);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r0, 0x10(r1)
	  lwz       r5, 0x18(r3)
	  lbz       r0, 0x13(r1)
	  rlwimi    r0,r5,0,28,31
	  stb       r0, 0x13(r1)
	  lwz       r5, 0x1C(r3)
	  lbz       r0, 0x13(r1)
	  rlwimi    r0,r5,4,26,27
	  stb       r0, 0x13(r1)
	  lwz       r5, 0x20(r3)
	  lbz       r0, 0x13(r1)
	  rlwimi    r0,r5,6,24,25
	  stb       r0, 0x13(r1)
	  lwz       r5, 0x24(r3)
	  lbz       r0, 0x12(r1)
	  rlwimi    r0,r5,0,28,31
	  stb       r0, 0x12(r1)
	  lwz       r5, 0x28(r3)
	  mr        r3, r4
	  lwz       r0, 0x10(r1)
	  addi      r4, r5, 0x1
	  rlwimi    r0,r4,12,0,19
	  stw       r0, 0x10(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r4, 0x10(r1)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014D640
 * Size:	000150
 */
void GenObjectBoss::updateUseList(Generator*, int count)
{
	if (_18 == 0) {
		bossMgr->addUseCount(0, 1);
		return;
	}
	if (_18 == 1) {
		bossMgr->addUseCount(1, 1);
		return;
	}
	if (_18 == 2) {
		bossMgr->addUseCount(2, 1);
		bossMgr->addUseCount(7, 1);
		bossMgr->addUseCount(8, 1);
		return;
	}
	if (_18 == 3) {
		bossMgr->addUseCount(3, 1);
		return;
	}
	if (_18 == 4) {
		bossMgr->addUseCount(4, count);
		return;
	}
	if (_18 == 5) {
		bossMgr->addUseCount(5, 1);
		return;
	}
	if (_18 == 6) {
		bossMgr->addUseCount(6, 1);
		return;
	}
	if (_18 == 7) {
		bossMgr->addUseCount(9, 1);
		return;
	}
	if (_18 == 8) {
		bossMgr->addUseCount(10, 1);
		return;
	}
	if (_18 == 9) {
		bossMgr->addUseCount(11, 1);
		return;
	}
}

/*
 * --INFO--
 * Address:	8014D790
 * Size:	00013C
 */
void* GenObjectBoss::birth(BirthInfo& info)
{
	Boss* boss = nullptr;
	if (_18 == 0) {
		boss = bossMgr->create(0, info, this);
	} else if (_18 == 1) {
		boss = bossMgr->create(1, info, this);
	} else if (_18 == 2) {
		boss = bossMgr->create(2, info, this);
	} else if (_18 == 3) {
		boss = bossMgr->create(3, info, this);
	} else if (_18 == 4) {
		boss = bossMgr->create(4, info, this);
	} else if (_18 == 5) {
		boss = bossMgr->create(5, info, this);
	} else if (_18 == 6) {
		boss = bossMgr->create(6, info, this);
	} else if (_18 == 7) {
		boss = bossMgr->create(7, info, this);
	} else if (_18 == 8) {
		boss = bossMgr->create(8, info, this);
	} else if (_18 == 9) {
		boss = bossMgr->create(9, info, this);
	}

	return boss;
}
