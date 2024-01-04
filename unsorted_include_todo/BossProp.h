#ifndef _BOSSPROP_H
#define _BOSSPROP_H

/**
 * .obj __vt__8BossProp, weak
 * .4byte __RTTI__8BossProp
 * .4byte 0
 * .4byte read__8BossPropFR18RandomAccessStream
 */

/**
 * @brief TODO
 */
struct BossProp {
	virtual void read(RandomAccessStream&); // _08
};

#endif
