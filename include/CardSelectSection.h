#ifndef _CARDSELECT_H
#define _CARDSELECT_H

#include "types.h"
#include "Section.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct CardSelectSection : public Section {
	CardSelectSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
