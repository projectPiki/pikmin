#ifndef _KEYCONFIG_KEY_H
#define _KEYCONFIG_KEY_H

/**
 * .obj __vt__Q29KeyConfig3Key, global
 * .4byte __RTTI__Q29KeyConfig3Key
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__Q29KeyConfig3KeyFR18RandomAccessStream
 * .4byte update__4NodeFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct Node {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10
	virtual void draw(Graphics&);           // _14
	virtual void render(Graphics&);         // _18
	virtual void concat();                  // _1C (weak)
	virtual void concat(VQS&);              // _20 (weak)
	virtual void concat(SRT&);              // _24 (weak)
	virtual void concat(Matrix4f&);         // _28 (weak)
	virtual void getModelMatrix();          // _2C (weak)
};

namespace KeyConfig {
/**
 * @brief TODO
 */
struct Key : public ANode, public Node {
	virtual void read(RandomAccessStream&); // _0C
};
} // namespace KeyConfig

#endif
