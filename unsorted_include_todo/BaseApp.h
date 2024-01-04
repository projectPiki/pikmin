#ifndef _BASEAPP_H
#define _BASEAPP_H

/**
 * .obj __vt__7BaseApp, global
 * .4byte __RTTI__7BaseApp
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__4NodeFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte __dt__7BaseAppFv
 * .4byte InitApp__7BaseAppFPc
 * .4byte idle__7BaseAppFv
 * .4byte keyDown__7BaseAppFiii
 * .4byte softReset__7BaseAppFv
 * .4byte useHeap__7BaseAppFi
 * .4byte procCmd__7BaseAppFPc
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

struct Node {
	virtual void _08() = 0;         // _08
	virtual void _0C() = 0;         // _0C
	virtual void update();          // _10
	virtual void draw(Graphics&);   // _14
	virtual void render(Graphics&); // _18
	virtual void concat();          // _1C (weak)
	virtual void concat(VQS&);      // _20 (weak)
	virtual void concat(SRT&);      // _24 (weak)
	virtual void concat(Matrix4f&); // _28 (weak)
	virtual void getModelMatrix();  // _2C (weak)
};

/**
 * @brief TODO
 */
struct BaseApp : public ANode, public CoreNode, public Node {
	virtual ~BaseApp();                  // _30
	virtual void InitApp(char*);         // _34 (weak)
	virtual void idle();                 // _38 (weak)
	virtual void keyDown(int, int, int); // _3C (weak)
	virtual void softReset();            // _40
	virtual void useHeap(int);           // _44 (weak)
	virtual void procCmd(char*);         // _48 (weak)

	BaseApp();
};

#endif
