#ifndef _GAMESTAT_H
#define _GAMESTAT_H

#include "types.h"
#include "Piki.h"

/**
 * @brief TODO
 */
struct GameStat {

	/**
	 * @brief TODO
	 */
	struct Counter {
		Counter() { mCount = 0; }

		void init() { mCount = 0; }

		void inc() { mCount++; }

		operator int() { return mCount; }

		// unused/inlined:
		void dump(char*);

		int mCount; // _00
	};

	/**
	 * @brief TODO
	 */
	struct ColCounter {
		ColCounter() { mCounts[Blue] = mCounts[Red] = mCounts[Yellow] = 0; }

		void init() { mCounts[Blue] = mCounts[Red] = mCounts[Yellow] = 0; }

		operator int() { return mCounts[Blue] + mCounts[Red] + mCounts[Yellow]; }
		int operator[](int color) { return mCounts[color]; }

		void set(int color, int val) { mCounts[color] = val; }
		void add(int color, int amt) { mCounts[color] += amt; }
		void dec(int color) { mCounts[color]--; }
		void inc(int color) { mCounts[color]++; }

		// unused/inlined:
		void dump(char*);

		int mCounts[PikiColorCount]; // _00, indexed by piki color
	};

	static void init();
	static void update();
	static void dump();

	static ColCounter deadPikis;
	static ColCounter fallPikis;
	static ColCounter formationPikis;
	static ColCounter freePikis;
	static ColCounter workPikis;
	static ColCounter mePikis;
	static ColCounter containerPikis;
	static ColCounter bornPikis;
	static ColCounter victimPikis;
	static ColCounter mapPikis;
	static ColCounter allPikis;

	static Counter killTekis;
	static Counter getPellets;
	static int minPikis;
	static int maxPikis;
	static bool orimaDead;
};

#endif
