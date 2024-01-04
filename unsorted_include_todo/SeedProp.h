#ifndef _SEEDPROP_H
#define _SEEDPROP_H

/**
 * .obj __vt__8SeedProp, weak
 * .4byte __RTTI__8SeedProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

/**
 * @brief TODO
 */
struct SeedProp : public CreatureProp {
};

#endif
