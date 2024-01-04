#ifndef _TEXIMG_H
#define _TEXIMG_H

/**
 * .obj __vt__6TexImg, global
 * .4byte __RTTI__6TexImg
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__6TexImgFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct TexImg : public ANode {
	virtual void read(RandomAccessStream&); // _0C
};

#endif
