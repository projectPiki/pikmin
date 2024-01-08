#ifndef _CONDITION_H
#define _CONDITION_H

#include "types.h"

struct Creature;

/**
 * @brief TODO
 */
struct Condition {
	virtual bool satisfy(Creature*); // _08

	// _00 = VTBL
};

#endif
