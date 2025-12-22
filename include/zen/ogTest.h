#ifndef _ZEN_OGTEST_H
#define _ZEN_OGTEST_H

#include "Section.h"
#include "types.h"

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct OgTestSection : public Section {
	OgTestSection();

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

} // namespace zen

#endif
