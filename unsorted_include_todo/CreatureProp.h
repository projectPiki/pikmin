#ifndef _CREATUREPROP_H
#define _CREATUREPROP_H

/**
 * .obj __vt__12CreatureProp, weak
 * .4byte __RTTI__12CreatureProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
 */

/**
 * @brief TODO
 */
struct CreatureProp {
	virtual void read(RandomAccessStream&); // _08
};

#endif
