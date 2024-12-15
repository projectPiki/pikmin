#ifndef _YAISTRATEGY_H
#define _YAISTRATEGY_H

#include "types.h"
#include "TekiStrategy.h"

struct TaiState;

/**
 * @brief TODO
 */
struct YaiStrategy : public TekiStrategy {
	YaiStrategy(int, int);

	virtual void start(Teki&);               // _08
	virtual void act(Teki&);                 // _0C
	virtual void eventPerformed(TekiEvent&); // _10
	virtual void draw(Teki&, Graphics&);     // _18

	void init(int, int);

	// _00     = VTBL
	// _00-_04 = TekiStrategy
	int mStateCount;       // _04
	TaiState** mStateList; // _08, array of something
	int mStateID;          // _0C, _324 in teki
};

#endif
