#ifndef _GAMESTAGECLEARSECTION_H
#define _GAMESTAGECLEARSECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct GameStageClearSection : public Section {
	GameStageClearSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
