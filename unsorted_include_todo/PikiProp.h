#ifndef _PIKIPROP_H
#define _PIKIPROP_H

/**
 * .obj __vt__8PikiProp, weak
 * .4byte __RTTI__8PikiProp
 * .4byte 0
 * .4byte read__8PikiPropFR18RandomAccessStream
*/

/**
 * @brief TODO
 */
struct PikiProp {
	virtual void read(RandomAccessStream &);  // _08

};

#endif
