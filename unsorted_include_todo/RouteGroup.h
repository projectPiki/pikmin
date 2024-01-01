#ifndef _ROUTEGROUP_H
#define _ROUTEGROUP_H

/**
 * .obj __vt__10RouteGroup, global
 * .4byte __RTTI__10RouteGroup
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte msgCommand__8EditNodeFR7DataMsg
 * .4byte render2d__10RouteGroupFR8GraphicsRi
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

struct EditNode {
	virtual void _08() = 0;              // _08
	virtual void _0C() = 0;              // _0C
	virtual void msgCommand(DataMsg &);  // _10 (weak)
};

/**
 * @brief TODO
 */
struct RouteGroup : public ANode, public CoreNode, public EditNode {
	virtual void render2d(Graphics &, int &);  // _14

};

#endif
