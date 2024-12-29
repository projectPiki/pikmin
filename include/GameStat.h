#ifndef _GAMESTAT_H
#define _GAMESTAT_H

#include "types.h"

/**
 * @brief TODO
 */
struct GameStat {

	/**
	 * @brief TODO
	 */
	struct Counter {
		inline Counter() { mCount = 0; }

		inline void init() { mCount = 0; }

		// unused/inlined:
		void dump(char*);

		int mCount; // _00
	};

	/**
	 * @brief TODO
	 */
	struct ColCounter {
		inline ColCounter() { mCounts[0] = mCounts[1] = mCounts[2] = 0; }

		inline void init() { mCounts[0] = mCounts[1] = mCounts[2] = 0; }

		inline int& operator()(int idx) { return mCounts[idx]; }

		inline int getTotal() { return mCounts[0] + mCounts[1] + mCounts[2]; }

		inline void set(int idx, int val) { mCounts[idx] = val; }

		// unused/inlined:
		void dump(char*);

		int mCounts[3]; // _00, indexed by piki color, probably
	};

	void init();
	void update();
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

	// TODO: members
};

#endif
