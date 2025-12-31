#ifndef _NEWPIKIGAME_H
#define _NEWPIKIGAME_H

#include "Section.h"
#include "types.h"

/**
 * @brief Game section for gameplay, for both challenge mode and story mode.
 *
 * Finer control is done by the `NewPikiGameSetupSection` node in this section's list, as well as the setup node's `GameCoreSection`
 * dependent.
 *
 * @note Size: 0x20.
 */
struct NewPikiGameSection : public Section {
	NewPikiGameSection();

	virtual void init() { } // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
