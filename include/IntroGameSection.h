#ifndef _INTROGAMESECTION_H
#define _INTROGAMESECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief Game section for the intro crash landing cutscene when starting a file for the first time.
 *
 * @note Size: 0x20.
 */
struct IntroGameSection : public Section {
	IntroGameSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
