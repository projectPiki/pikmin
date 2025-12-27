#ifndef _LOADIDLER_H
#define _LOADIDLER_H

#include "CoreNode.h"
#include "types.h"

struct Graphics;

/**
 * @brief Base class for loading screen drawing managers.
 *
 * @note Size: 0x14.
 */
struct LoadIdler : public CoreNode {
	LoadIdler()
	    : CoreNode("")
	{
	}

	virtual void init() { }          // _10 (weak)
	virtual void draw(Graphics&) { } // _14 (weak)

	// _00     = VTBL
	// _00-_14 = CoreNode
};

/**
 * @brief Manager for drawing loading screens during gameplay (e.g. entering a map).
 *
 * @note Size: 0x14.
 */
struct GameLoadIdler : public LoadIdler {
	virtual void init() { }           // _10
	virtual void draw(Graphics& gfx); // _14

	// _00     = VTBL
	// _00-_14 = LoadIdler
};

#endif
