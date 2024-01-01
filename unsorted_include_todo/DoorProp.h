#ifndef _DOORPROP_H
#define _DOORPROP_H

/**
 * .obj __vt__8DoorProp, weak
 * .4byte __RTTI__8DoorProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
*/

struct CreatureProp {
	virtual void read(RandomAccessStream &);  // _08
};

/**
 * @brief TODO
 */
struct DoorProp : public CreatureProp {

};

#endif
