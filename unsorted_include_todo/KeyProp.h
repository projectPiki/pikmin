#ifndef _KEYPROP_H
#define _KEYPROP_H

/**
 * .obj __vt__7KeyProp, weak
 * .4byte __RTTI__7KeyProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

/**
 * @brief TODO
 */
struct KeyProp : public CreatureProp {
};

#endif
