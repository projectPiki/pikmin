#ifndef _BUILDINGITEMPROP_H
#define _BUILDINGITEMPROP_H

/**
 * .obj __vt__16BuildingItemProp, weak
 * .4byte __RTTI__16BuildingItemProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
*/

struct CreatureProp {
	virtual void read(RandomAccessStream &);  // _08
};

/**
 * @brief TODO
 */
struct BuildingItemProp : public CreatureProp {

};

#endif
