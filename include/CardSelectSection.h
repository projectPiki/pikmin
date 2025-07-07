#ifndef _CARDSELECT_H
#define _CARDSELECT_H

#include "Section.h"
#include "types.h"

/**
 * @brief Game section for the memory card selection screen.
 *
 * @note Size: 0x20.
 */
struct CardSelectSection : public Section {

	/// Constructor.
	CardSelectSection();

	/// Initialises section (trivial).
	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
