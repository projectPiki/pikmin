#ifndef _LIGHTGROUP_H
#define _LIGHTGROUP_H

/**
 * .obj __vt__10LightGroup, weak
 * .4byte __RTTI__10LightGroup
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

/**
 * @brief TODO
 */
struct LightGroup : public ANode, public CoreNode {

	void loadini(CmdStream*);
	void refresh(Graphics&, Matrix4f*);
};

#endif
