#ifndef _TEKISTRATEGY_H
#define _TEKISTRATEGY_H

#include "types.h"

struct Graphics;
struct Teki;
struct TekiEvent;
struct TekiInteractionKey;

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct TekiStrategy {
	TekiStrategy();

	virtual void start(Teki& teki);                                   // _08
	virtual void act(Teki& teki);                                     // _0C
	virtual void eventPerformed(immut TekiEvent&);                    // _10
	virtual void createEffect(Teki& teki, int);                       // _14
	virtual void draw(Teki& teki, Graphics& gfx);                     // _18
	virtual void drawDebugInfo(Teki& teki, Graphics& gfx);            // _1C
	virtual bool interact(Teki& teki, immut TekiInteractionKey& key); // _20
	virtual void spawnCorpseParts(Teki& teki);                        // _24

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct TekiStrategyTable {
	TekiStrategyTable(int count);

	TekiStrategy* getStrategy(int idx) { return mStrategies[idx]; }
	void setStrategy(int idx, TekiStrategy* strat) { mStrategies[idx] = strat; }

	int mCount;                 // _00
	TekiStrategy** mStrategies; // _04
};

#endif
