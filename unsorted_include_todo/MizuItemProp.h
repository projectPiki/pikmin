#ifndef _MIZUITEMPROP_H
#define _MIZUITEMPROP_H

/**
 * .obj __vt__12MizuItemProp, weak
 * .4byte __RTTI__12MizuItemProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

/**
 * @brief TODO
 */
struct MizuItemProp : public CreatureProp {
};

#endif
