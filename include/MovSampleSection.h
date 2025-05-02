#ifndef _MOVSAMPLESECTION_H
#define _MOVSAMPLESECTION_H

#include "types.h"
#include "Section.h"
#include "Controller.h"
#include "jaudio/app_inter.h"
#include "system.h"
#include "gameflow.h"

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

// Global functions:
void convHVQM4TexY8UV8(int, int, u8*, u8*);

#endif
