#ifndef _LIGHTFLARE_H
#define _LIGHTFLARE_H

/**
 * .obj __vt__10LightFlare, weak
 * .4byte __RTTI__10LightFlare
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

/**
 * @brief TODO
 */
struct LightFlare : public ANode, public CoreNode {

};

#endif
