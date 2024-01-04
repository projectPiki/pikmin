#ifndef _PLUGPIKIAPP_H
#define _PLUGPIKIAPP_H

/**
 * .obj __vt__11PlugPikiApp, global
 * .4byte __RTTI__11PlugPikiApp
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__11PlugPikiAppFv
 * .4byte draw__11PlugPikiAppFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte __dt__11PlugPikiAppFv
 * .4byte InitApp__7BaseAppFPc
 * .4byte idle__11PlugPikiAppFv
 * .4byte keyDown__7BaseAppFiii
 * .4byte softReset__11PlugPikiAppFv
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

struct BaseApp {
	virtual void _08() = 0;              // _08
	virtual void _0C() = 0;              // _0C
	virtual void update();               // _10
	virtual void draw(Graphics&);        // _14
	virtual void _18() = 0;              // _18
	virtual void _1C() = 0;              // _1C
	virtual void _20() = 0;              // _20
	virtual void _24() = 0;              // _24
	virtual void _28() = 0;              // _28
	virtual void _2C() = 0;              // _2C
	virtual ~BaseApp();                  // _30 (weak)
	virtual void InitApp(char*);         // _34 (weak)
	virtual void idle();                 // _38
	virtual void keyDown(int, int, int); // _3C (weak)
	virtual void softReset();            // _40
	virtual void useHeap(int);           // _44 (weak)
	virtual void procCmd(char*);         // _48 (weak)
};

/**
 * @brief TODO
 */
struct PlugPikiApp : public ANode, public CoreNode, public Node, public BaseApp {
	virtual void update();        // _10
	virtual void draw(Graphics&); // _14
	virtual ~PlugPikiApp();       // _30 (weak)
	virtual void idle();          // _38
	virtual void softReset();     // _40

	void hardReset();
	PlugPikiApp();
};

#endif
