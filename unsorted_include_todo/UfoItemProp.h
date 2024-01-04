#ifndef _UFOITEMPROP_H
#define _UFOITEMPROP_H

/**
 * .obj __vt__11UfoItemProp, weak
 * .4byte __RTTI__11UfoItemProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

/**
 * @brief TODO
 */
struct UfoItemProp : public CreatureProp {
};

#endif
