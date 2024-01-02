#ifndef _OBJECTMGR_H
#define _OBJECTMGR_H

/**
 * .obj __vt__9ObjectMgr, global
 * .4byte __RTTI__9ObjectMgr
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte __RTTI__9ObjectMgr
 * .4byte 0xFFFFFFF8
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte "@8@update__9ObjectMgrFv"
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte __dt__9ObjectMgrFv
 * .4byte update__9ObjectMgrFv
 * .4byte postUpdate__9ObjectMgrFif
 * .4byte stickUpdate__9ObjectMgrFv
 * .4byte refresh__9ObjectMgrFR8Graphics
 * .4byte drawShadow__9ObjectMgrFR8GraphicsP7Texture
 * .4byte 0
 * .4byte 0
 * .4byte findClosest__9ObjectMgrFR8Vector3ffP9Condition
 * .4byte findClosest__9ObjectMgrFR8Vector3fP9Condition
 * .4byte search__9ObjectMgrFP9ObjectMgr
 * .4byte killAll__9ObjectMgrFv
 */

struct ANode {
	virtual void _08() = 0;        // _08
	virtual void _0C() = 0;        // _0C
	virtual void _10() = 0;        // _10
	virtual void _14() = 0;        // _14
	virtual void _18() = 0;        // _18
	virtual void _1C() = 0;        // _1C
	virtual void getAgeNodeType(); // _20 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void _0C() = 0;                 // _0C
	virtual void _10() = 0;                 // _10
	virtual void _14() = 0;                 // _14
	virtual void _18() = 0;                 // _18
	virtual void _1C() = 0;                 // _1C
	virtual void _20() = 0;                 // _20
	virtual void read(RandomAccessStream&); // _24 (weak)
};

struct Node {
	virtual void _08() = 0;         // _08
	virtual void _0C() = 0;         // _0C
	virtual void _10() = 0;         // _10
	virtual void _14() = 0;         // _14
	virtual void _18() = 0;         // _18
	virtual void _1C() = 0;         // _1C
	virtual void _20() = 0;         // _20
	virtual void _24() = 0;         // _24
	virtual void _28() = 0;         // _28
	virtual void draw(Graphics&);   // _2C
	virtual void render(Graphics&); // _30
	virtual void concat();          // _34 (weak)
	virtual void concat(VQS&);      // _38 (weak)
	virtual void concat(SRT&);      // _3C (weak)
	virtual void concat(Matrix4f&); // _40 (weak)
	virtual void getModelMatrix();  // _44 (weak)
};

/**
 * @brief TODO
 */
struct ObjectMgr : public ANode, public CoreNode, public Node {
	virtual void _08() = 0;                               // _08
	virtual void _0C() = 0;                               // _0C
	virtual void _10() = 0;                               // _10
	virtual void _14() = 0;                               // _14
	virtual ~ObjectMgr();                                 // _48
	virtual void update();                                // _4C
	virtual void postUpdate(int, f32);                    // _50
	virtual void stickUpdate();                           // _54
	virtual void refresh(Graphics&);                      // _58
	virtual void drawShadow(Graphics&, Texture*);         // _5C
	virtual void _60() = 0;                               // _60
	virtual void _64() = 0;                               // _64
	virtual void findClosest(Vector3f&, f32, Condition*); // _68
	virtual void findClosest(Vector3f&, Condition*);      // _6C
	virtual void search(ObjectMgr*);                      // _70
	virtual void killAll();                               // _74
};

#endif
