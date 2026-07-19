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

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("gameStat");

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void GameStat::update()
{
	int color;

	for (color = PikiMinColor; color < PikiColorCount; color++) {
		mapPikis.set(formationPikis[color] + freePikis[color] + mePikis[color] + workPikis[color], color);
	}

	for (color = PikiMinColor; color < PikiColorCount; color++) {
		allPikis.set(mapPikis[color] + containerPikis[color], color);
	}

	if (allPikis > maxPikis) {
		maxPikis = allPikis;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void GameStat::Counter::dump(immut char* name)
{
	PRINT("<%s> %d\n", name, mCount);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void GameStat::ColCounter::dump(immut char* name)
{
	PRINT("<%s> %d (%d + %d + %d)\n", name, int(mCounts), mCounts[Blue], mCounts[Red], mCounts[Yellow]);
}

/**
 * @todo: Documentation
 */
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
