#ifndef _GAMECOURSECLEARSECTION_H
#define _GAMECOURSECLEARSECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct GameCourseClearSection : public Section {
	GameCourseClearSection();

	virtual void init() { } // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
