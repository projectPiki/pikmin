#ifndef _SRTNODE_H
#define _SRTNODE_H

/**
 * .obj __vt__7SRTNode, global
 * .4byte __RTTI__7SRTNode
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__7SRTNodeFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__7SRTNodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__7SRTNodeFR8Matrix4f
 * .4byte getModelMatrix__7SRTNodeFv
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

struct Node {
	virtual void _08() = 0;           // _08
	virtual void _0C() = 0;           // _0C
	virtual void update();            // _10
	virtual void draw(Graphics &);    // _14
	virtual void render(Graphics &);  // _18
	virtual void concat();            // _1C (weak)
	virtual void concat(VQS &);       // _20 (weak)
	virtual void concat(SRT &);       // _24 (weak)
};

/**
 * @brief TODO
 */
struct SRTNode : public ANode, public CoreNode, public Node {
	virtual void update();            // _10
	virtual void concat();            // _1C (weak)
	virtual void concat(Matrix4f &);  // _28 (weak)
	virtual void getModelMatrix();    // _2C (weak)

};

#endif
