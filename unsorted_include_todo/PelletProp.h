#ifndef _PELLETPROP_H
#define _PELLETPROP_H

/**
 * .obj __vt__10PelletProp, weak
 * .4byte __RTTI__10PelletProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
*/

struct CreatureProp {
	virtual void read(RandomAccessStream &);  // _08
};

/**
 * @brief TODO
 */
struct PelletProp : public CreatureProp {

};

#endif
