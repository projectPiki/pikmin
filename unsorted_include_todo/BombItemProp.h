#ifndef _BOMBITEMPROP_H
#define _BOMBITEMPROP_H

/**
 * .obj __vt__12BombItemProp, weak
 * .4byte __RTTI__12BombItemProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
*/

struct CreatureProp {
	virtual void read(RandomAccessStream &);  // _08
};

/**
 * @brief TODO
 */
struct BombItemProp : public CreatureProp {

};

#endif
