#ifndef _GAMESETUPSECTION_H
#define _GAMESETUPSECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct GameSetupSection : public Section {
	GameSetupSection();

	virtual void update();  // _10
	virtual void init() { } // _30

	void preCacheShapes();

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
