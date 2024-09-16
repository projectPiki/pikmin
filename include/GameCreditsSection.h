#ifndef _GAMECREDITSSECTION_H
#define _GAMECREDITSSECTION_H

#include "types.h"
#include "Section.h"

/*
 * @brief TODO
 */
struct GameCreditsSection : public Section {
	GameCreditsSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

#endif
