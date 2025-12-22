#ifndef _PANITESTSECTION_H
#define _PANITESTSECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct PaniTestSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
