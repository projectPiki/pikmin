#ifndef _NAVIPROP_H
#define _NAVIPROP_H

/**
 * .obj __vt__8NaviProp, weak
 * .4byte __RTTI__8NaviProp
 * .4byte 0
 * .4byte read__8NaviPropFR18RandomAccessStream
 */

/**
 * @brief TODO
 */
struct NaviProp {
	virtual void read(RandomAccessStream&); // _08 (weak)

	NaviProp();
};

#endif
