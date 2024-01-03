#ifndef _SLOTCHANGELISTNER_H
#define _SLOTCHANGELISTNER_H

#include "types.h"

/**
 * @brief TODO
 *
 * @note Dev spelling.
 */
struct SlotChangeListner {
	virtual void inform(int) = 0; // _08

	// _00 = VTBL
	// TODO: members
};

#endif
