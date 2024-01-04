#ifndef _MATERIAL_H
#define _MATERIAL_H

/**
 * .obj __vt__8Material, global
 * .4byte __RTTI__8Material
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8MaterialFR18RandomAccessStream
 * .4byte attach__8MaterialFv
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct Material : public ANode {
	virtual void read(RandomAccessStream&); // _0C
	virtual void attach();                  // _10
};

#endif
