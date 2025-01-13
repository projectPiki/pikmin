#ifndef _ANODE_H
#define _ANODE_H

#include "types.h"

/**
 * @brief A base class for nodes. Shorthand for Age Node.
 * @note 'Age' is the system used for debugging in the Windows version.
 */
struct ANode {
	virtual int getAgeNodeType() { return 0; } // _08 (weak)

	// _00 = VTBL
};

#endif
