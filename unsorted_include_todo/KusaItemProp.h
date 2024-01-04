#ifndef _KUSAITEMPROP_H
#define _KUSAITEMPROP_H

/**
 * .obj __vt__12KusaItemProp, weak
 * .4byte __RTTI__12KusaItemProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

/**
 * @brief TODO
 */
struct KusaItemProp : public CreatureProp {
};

#endif
