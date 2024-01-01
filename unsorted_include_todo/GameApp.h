#ifndef _GAMEAPP_H
#define _GAMEAPP_H

/**
 * .obj __vt__7GameApp, weak
 * .4byte __RTTI__7GameApp
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
 * .4byte __dt__7GameAppFv
 * .4byte InitApp__7BaseAppFPc
 * .4byte idle__7GameAppFv
 * .4byte keyDown__7BaseAppFiii
 * .4byte softReset__7BaseAppFv
 * .4byte useHeap__7BaseAppFi
 * .4byte procCmd__7BaseAppFPc
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
	virtual void concat(Matrix4f &);  // _28 (weak)
	virtual void getModelMatrix();    // _2C (weak)
};

struct BaseApp {
	virtual void _08() = 0;               // _08
	virtual void _0C() = 0;               // _0C
	virtual void _10() = 0;               // _10
	virtual void _14() = 0;               // _14
	virtual void _18() = 0;               // _18
	virtual void _1C() = 0;               // _1C
	virtual void _20() = 0;               // _20
	virtual void _24() = 0;               // _24
	virtual void _28() = 0;               // _28
	virtual void _2C() = 0;               // _2C
	virtual ~BaseApp();                   // _30 (weak)
	virtual void InitApp(char *);         // _34 (weak)
	virtual void idle();                  // _38 (weak)
	virtual void keyDown(int, int, int);  // _3C (weak)
	virtual void softReset();             // _40
	virtual void useHeap(int);            // _44 (weak)
	virtual void procCmd(char *);         // _48 (weak)
};

/**
 * @brief TODO
 */
struct GameApp : public ANode, public CoreNode, public Node, public BaseApp {
	virtual ~GameApp();  // _30 (weak)
	virtual void idle(); // _38 (weak)

};

#endif
