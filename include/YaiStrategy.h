#ifndef _YAISTRATEGY_H
#define _YAISTRATEGY_H

#include "types.h"
#include "TekiStrategy.h"

/**
 * @brief TODO
 */
struct YaiStrategy {
	YaiStrategy(int, int);

	virtual void start(Teki&);               // _08
	virtual void act(Teki&);                 // _0C
	virtual void eventPerformed(TekiEvent&); // _10
	virtual void draw(Teki&, Graphics&);     // _18

	void init(int, int);

	// _00     = VTBL
	// _00-_?? = TekiStrategy
	// TODO: members
};

#endif
