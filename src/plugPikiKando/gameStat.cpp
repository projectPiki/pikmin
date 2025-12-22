#include "GameStat.h"
#include "DebugLog.h"

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
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("gameStat");

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

void GameStat::update()
{
	for (int i = PikiMinColor; i < PikiColorCount; i++) {
		mapPikis.set(formationPikis[i] + freePikis[i] + mePikis[i] + workPikis[i], i);
	}

	for (int i = PikiMinColor; i < PikiColorCount; i++) {
		allPikis.set(mapPikis[i] + containerPikis[i], i);
	}

	int total = allPikis;
	if (total > maxPikis) {
		maxPikis = allPikis;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GameStat::Counter::dump(immut char* name)
{
	PRINT("<%s> %d\n", name, mCount);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GameStat::ColCounter::dump(immut char* name)
{
	PRINT("<%s> %d (%d + %d + %d)\n", name, int(mCounts), mCounts[Blue], mCounts[Red], mCounts[Yellow]);
}

void GameStat::dump()
{
	PRINT("******** GAMESTAT DUMP **********\n");
	deadPikis.dump("deadPikis");
	fallPikis.dump("fallPikis");
	formationPikis.dump("formation");
	freePikis.dump("free");
	workPikis.dump("work");
	mePikis.dump("me");
	containerPikis.dump("container");
	bornPikis.dump("born");
	victimPikis.dump("victim");
	mapPikis.dump("map");
	allPikis.dump("all");
	PRINT("==================================\n");
}
