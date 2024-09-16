#ifndef _GAMESTAGECLEARSECTION_H
#define _GAMESTAGECLEARSECTION_H

#include "types.h"
#include "Section.h"

/*
 * @brief TODO
 */
struct GameStageClearSection : public Section {
	GameStageClearSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

#endif
