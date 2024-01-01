#ifndef _GOALITEMPROP_H
#define _GOALITEMPROP_H

/**
 * .obj __vt__12GoalItemProp, weak
 * .4byte __RTTI__12GoalItemProp
 * .4byte 0
 * .4byte read__12CreaturePropFR18RandomAccessStream
*/

struct CreatureProp {
	virtual void read(RandomAccessStream &);  // _08
};

/**
 * @brief TODO
 */
struct GoalItemProp : public CreatureProp {

};

#endif
