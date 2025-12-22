#ifndef _NEWPIKIGAME_H
#define _NEWPIKIGAME_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
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
