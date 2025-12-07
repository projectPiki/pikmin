#ifndef _YAISTRATEGY_H
#define _YAISTRATEGY_H

#include "TekiStrategy.h"
#include "types.h"

struct TaiState;

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct YaiStrategy : public TekiStrategy {
	YaiStrategy(int, int);

	virtual void start(Teki&);                     // _08
	virtual void act(Teki&);                       // _0C
	virtual void eventPerformed(immut TekiEvent&); // _10
	virtual void draw(Teki&, Graphics&);           // _18

	void setState(int index, TaiState* state) { mStateList[index] = state; }

	void init(int, int);

	// _00     = VTBL
	// _00-_04 = TekiStrategy
	int mStateCount;       // _04
	TaiState** mStateList; // _08
	int mStateID;          // _0C
};

#endif
