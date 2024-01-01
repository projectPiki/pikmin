#ifndef _BOSSMGR_H
#define _BOSSMGR_H

/**
 * .obj __vt__7BossMgr, global
 * .4byte __RTTI__7BossMgr
 * .4byte 0
 * .4byte getCreature__7BossMgrFi
 * .4byte getFirst__7BossMgrFv
 * .4byte getNext__7BossMgrFi
 * .4byte isDone__7BossMgrFi
 * .4byte __RTTI__7BossMgr
 * .4byte 0xFFFFFFF8
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte "@8@update__7BossMgrFv"
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte __dt__7BossMgrFv
 * .4byte update__7BossMgrFv
 * .4byte postUpdate__9ObjectMgrFif
 * .4byte stickUpdate__9ObjectMgrFv
 * .4byte refresh__7BossMgrFR8Graphics
 * .4byte drawShadow__9ObjectMgrFR8GraphicsP7Texture
 * .4byte getSize__7BossMgrFv
 * .4byte getMax__7BossMgrFv
 * .4byte findClosest__9ObjectMgrFR8Vector3ffP9Condition
 * .4byte findClosest__9ObjectMgrFR8Vector3fP9Condition
 * .4byte search__9ObjectMgrFP9ObjectMgr
 * .4byte killAll__7BossMgrFv
*/

struct ANode {
	virtual void getCreature(int);  // _08
	virtual void getFirst();        // _0C
	virtual void getNext(int);      // _10
	virtual void isDone(int);       // _14
	virtual void _18() = 0;         // _18
	virtual void _1C() = 0;         // _1C
	virtual void getAgeNodeType();  // _20 (weak)
};

struct CoreNode {
	virtual void getCreature(int);            // _08
	virtual void getFirst();                  // _0C
	virtual void getNext(int);                // _10
	virtual void isDone(int);                 // _14
	virtual void _18() = 0;                   // _18
	virtual void _1C() = 0;                   // _1C
	virtual void _20() = 0;                   // _20
	virtual void read(RandomAccessStream &);  // _24 (weak)
};

struct Node {
	virtual void getCreature(int);    // _08
	virtual void getFirst();          // _0C
	virtual void getNext(int);        // _10
	virtual void isDone(int);         // _14
	virtual void _18() = 0;           // _18
	virtual void _1C() = 0;           // _1C
	virtual void _20() = 0;           // _20
	virtual void _24() = 0;           // _24
	virtual void _28() = 0;           // _28
	virtual void draw(Graphics &);    // _2C
	virtual void render(Graphics &);  // _30
	virtual void concat();            // _34 (weak)
	virtual void concat(VQS &);       // _38 (weak)
	virtual void concat(SRT &);       // _3C (weak)
	virtual void concat(Matrix4f &);  // _40 (weak)
	virtual void getModelMatrix();    // _44 (weak)
};

struct ObjectMgr {
	virtual void getCreature(int);                             // _08
	virtual void getFirst();                                   // _0C
	virtual void getNext(int);                                 // _10
	virtual void isDone(int);                                  // _14
	virtual void _18() = 0;                                    // _18
	virtual void _1C() = 0;                                    // _1C
	virtual void _20() = 0;                                    // _20
	virtual void _24() = 0;                                    // _24
	virtual void _28() = 0;                                    // _28
	virtual void _2C() = 0;                                    // _2C
	virtual void _30() = 0;                                    // _30
	virtual void _34() = 0;                                    // _34
	virtual void _38() = 0;                                    // _38
	virtual void _3C() = 0;                                    // _3C
	virtual void _40() = 0;                                    // _40
	virtual void _44() = 0;                                    // _44
	virtual ~ObjectMgr();                                      // _48
	virtual void update();                                     // _4C
	virtual void postUpdate(int, float);                       // _50
	virtual void stickUpdate();                                // _54
	virtual void refresh(Graphics &);                          // _58
	virtual void drawShadow(Graphics &, Texture *);            // _5C
	virtual void getSize();                                    // _60
	virtual void getMax();                                     // _64
	virtual void findClosest(Vector3f &, float, Condition *);  // _68
	virtual void findClosest(Vector3f &, Condition *);         // _6C
	virtual void search(ObjectMgr *);                          // _70
};

/**
 * @brief TODO
 */
struct BossMgr : public ANode, public CoreNode, public Node, public ObjectMgr {
	virtual void getCreature(int);     // _08
	virtual void getFirst();           // _0C
	virtual void getNext(int);         // _10
	virtual void isDone(int);          // _14
	virtual ~BossMgr();                // _48
	virtual void update();             // _4C
	virtual void refresh(Graphics &);  // _58
	virtual void getSize();            // _60
	virtual void getMax();             // _64
	virtual void killAll();            // _74

};

#endif
