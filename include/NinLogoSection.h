#ifndef _NINLOGOSECTION_H
#define _NINLOGOSECTION_H

#include "Controller.h"
#include "Section.h"
#include "types.h"

struct Menu;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct NinLogoSection : public Section {
	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
