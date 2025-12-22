#ifndef _MAPSELECT_H
#define _MAPSELECT_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct MapSelectSection : public Section {
	MapSelectSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
