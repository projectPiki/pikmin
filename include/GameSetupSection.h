#ifndef _GAMESETUPSECTION_H
#define _GAMESETUPSECTION_H

#include "types.h"
#include "Section.h"

/**
 * @brief TODO
 */
struct GameSetupSection : public Section {
	GameSetupSection();

	virtual void update(); // _10
	virtual void init();   // _30

	void preCacheShapes();

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

#endif
