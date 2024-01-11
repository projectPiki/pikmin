#ifndef _NAVIPROP_H
#define _NAVIPROP_H

#include "types.h"
#include "CreatureProp.h"

/**
 * @brief TODO
 */
struct NaviProp : public CreatureProp {
	NaviProp();

	virtual void read(RandomAccessStream&); // _08 (weak)

	// _F8     = VTBL
	// _00-_FC = CreatureProp
	// TODO: work out members
};

#endif
