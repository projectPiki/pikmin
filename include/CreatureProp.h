#ifndef _CREATUREPROP_H
#define _CREATUREPROP_H

#include "types.h"

/**
 * @brief TODO
 */
struct CreatureProp {

	virtual void read(struct RandomAccessStream&); // _08

	// _00 = VTBL
	u8 _04[0xFC - 0x4]; // _04, TODO: work out members
};

#endif
