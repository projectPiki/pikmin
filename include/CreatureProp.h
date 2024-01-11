#ifndef _CREATUREPROP_H
#define _CREATUREPROP_H

#include "types.h"

/**
 * @brief TODO
 */
struct CreatureProp {
	// _F8 = VTBL
	u8 _00[0xF8]; // _00, TODO: work out members

	virtual void read(struct RandomAccessStream&); // _08
};

#endif
