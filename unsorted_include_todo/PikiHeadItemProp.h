#ifndef _PIKIHEADITEMPROP_H
#define _PIKIHEADITEMPROP_H

/**
 * .obj __vt__16PikiHeadItemProp, weak
 * .4byte __RTTI__16PikiHeadItemProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

/**
 * @brief TODO
 */
struct PikiHeadItemProp : public CreatureProp {
};

#endif
