#ifndef _ROPEPROP_H
#define _ROPEPROP_H

/**
 * .obj __vt__8RopeProp, weak
 * .4byte __RTTI__8RopeProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

/**
 * @brief TODO
 */
struct RopeProp : public CreatureProp {
};

#endif
