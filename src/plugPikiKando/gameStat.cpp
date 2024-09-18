#include "GameStat.h"

GameStat::ColCounter GameStat::deadPikis;
GameStat::ColCounter GameStat::fallPikis;

GameStat::Counter GameStat::killTekis;
GameStat::Counter GameStat::getPellets;

GameStat::ColCounter GameStat::formationPikis;
GameStat::ColCounter GameStat::freePikis;
GameStat::ColCounter GameStat::workPikis;
GameStat::ColCounter GameStat::mePikis;
GameStat::ColCounter GameStat::containerPikis;
GameStat::ColCounter GameStat::bornPikis;
GameStat::ColCounter GameStat::victimPikis;
GameStat::ColCounter GameStat::mapPikis;
GameStat::ColCounter GameStat::allPikis;

int GameStat::minPikis;
int GameStat::maxPikis;
bool GameStat::orimaDead;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801124B8
 * Size:	0000A8
 */
void GameStat::init()
{
	deadPikis.init();
	fallPikis.init();

	killTekis.init();
	getPellets.init();

	formationPikis.init();
	freePikis.init();
	workPikis.init();
	mePikis.init();
	containerPikis.init();
	bornPikis.init();
	victimPikis.init();
	mapPikis.init();
	allPikis.init();

	maxPikis  = 0;
	minPikis  = 0;
	orimaDead = false;
}

/*
 * --INFO--
 * Address:	80112560
 * Size:	0000C4
 */
void GameStat::update()
{
	for (int i = 0; i < 3; i++) {
		mapPikis(i) = formationPikis(i) + freePikis(i) + mePikis(i) + workPikis(i);
	}

	for (int i = 0; i < 3; i++) {
		allPikis(i) = mapPikis(i) + containerPikis(i);
	}

	int total = allPikis(0) + allPikis(1) + allPikis(2);
	if (total > maxPikis) {
		maxPikis = total;
	}
	/*
	.loc_0x0:
	  lis       r3, 0x803D
	  addi      r5, r3, 0x1E58
	  lwz       r0, 0x24(r5)
	  lwz       r3, 0x3C(r5)
	  lwz       r4, 0x30(r5)
	  add       r0, r0, r3
	  lwz       r3, 0x18(r5)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  stw       r0, 0x6C(r5)
	  lwz       r3, 0x40(r5)
	  lwz       r0, 0x28(r5)
	  lwz       r4, 0x34(r5)
	  add       r0, r0, r3
	  lwz       r3, 0x1C(r5)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  stw       r0, 0x70(r5)
	  lwz       r3, 0x44(r5)
	  lwz       r0, 0x2C(r5)
	  lwz       r4, 0x38(r5)
	  add       r0, r0, r3
	  lwz       r3, 0x20(r5)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  stw       r0, 0x74(r5)
	  addi      r4, r5, 0x80
	  lwz       r3, 0x6C(r5)
	  lwz       r0, 0x48(r5)
	  add       r0, r3, r0
	  stw       r0, 0x78(r5)
	  lwz       r3, 0x70(r5)
	  lwz       r0, 0x4C(r5)
	  add       r0, r3, r0
	  stw       r0, 0x7C(r5)
	  lwz       r3, 0x74(r5)
	  lwz       r0, 0x50(r5)
	  add       r0, r3, r0
	  stw       r0, 0x80(r5)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x7C(r5)
	  lwz       r3, 0x78(r5)
	  add       r4, r0, r4
	  lwz       r0, 0x3104(r13)
	  add       r4, r3, r4
	  cmpw      r4, r0
	  blelr-
	  stw       r4, 0x3104(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GameStat::Counter::dump(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GameStat::ColCounter::dump(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80112624
 * Size:	000004
 */
void GameStat::dump() { }
