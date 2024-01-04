#ifndef _LIGHT_H
#define _LIGHT_H

/**
 * .obj __vt__5Light, weak
 * .4byte __RTTI__5Light
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
struct Light : public ANode, public CoreNode {

	Light();
	void setLightDistAttn(float, float, int);
	void setLightSpot(float, int);
	void update();
};

#endif
