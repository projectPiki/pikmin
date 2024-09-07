#ifndef _LOADIDLER_H
#define _LOADIDLER_H

#include "types.h"
#include "CoreNode.h"

struct Graphics;

/**
 * @brief TODO
 */
struct LoadIdler : public CoreNode {
	virtual void init();          // _10 (weak)
	virtual void draw(Graphics&); // _14 (weak)

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameLoadIdler : public LoadIdler {
	virtual void init();          // _10
	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_14 = LoadIdler?
	// TODO: members
};

#endif
