#ifndef _MOVSAMPLESECTION_H
#define _MOVSAMPLESECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct MovSampleSection : public Section {
	MovSampleSection() { }

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
