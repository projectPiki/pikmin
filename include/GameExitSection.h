#ifndef _GAMEEXITSECTION_H
#define _GAMEEXITSECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct GameExitSection : public Section {
	GameExitSection();

	virtual void update();  // _10
	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
