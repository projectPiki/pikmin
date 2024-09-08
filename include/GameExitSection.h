#ifndef _GAMEEXITSECTION_H
#define _GAMEEXITSECTION_H

#include "types.h"
#include "Section.h"

/**
 * @brief TODO
 */
struct GameExitSection : public Section {
	GameExitSection();

	virtual void update();  // _10
	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

#endif
