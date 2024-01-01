#ifndef _TEXATTR_H
#define _TEXATTR_H

/**
 * .obj __vt__7TexAttr, global
 * .4byte __RTTI__7TexAttr
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__7TexAttrFR18RandomAccessStream
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

/**
 * @brief TODO
 */
struct TexAttr : public ANode {
	virtual void read(RandomAccessStream &);  // _0C

};

#endif
