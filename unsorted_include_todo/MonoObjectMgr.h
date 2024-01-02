#ifndef _MONOOBJECTMGR_H
#define _MONOOBJECTMGR_H

/**
 * .obj __vt__13MonoObjectMgr, global
 * .4byte __RTTI__13MonoObjectMgr
 * .4byte 0
 * .4byte getCreature__13MonoObjectMgrFi
 * .4byte getFirst__13MonoObjectMgrFv
 * .4byte getNext__13MonoObjectMgrFi
 * .4byte isDone__13MonoObjectMgrFi
 * .4byte __RTTI__13MonoObjectMgr
 * .4byte 0xFFFFFFF8
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte "@8@update__13MonoObjectMgrFv"
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte __dt__13MonoObjectMgrFv
 * .4byte update__13MonoObjectMgrFv
 * .4byte postUpdate__13MonoObjectMgrFif
 * .4byte stickUpdate__9ObjectMgrFv
 * .4byte refresh__13MonoObjectMgrFR8Graphics
 * .4byte drawShadow__13MonoObjectMgrFR8GraphicsP7Texture
 * .4byte getSize__13MonoObjectMgrFv
 * .4byte getMax__13MonoObjectMgrFv
 * .4byte findClosest__9ObjectMgrFR8Vector3ffP9Condition
 * .4byte findClosest__9ObjectMgrFR8Vector3fP9Condition
 * .4byte search__13MonoObjectMgrFP9ObjectMgr
 * .4byte killAll__9ObjectMgrFv
 * .4byte birth__13MonoObjectMgrFv
 * .4byte kill__13MonoObjectMgrFP8Creature
 * .4byte 0
 */

struct ANode {
	virtual void getCreature(int); // _08
	virtual void getFirst();       // _0C
	virtual void getNext(int);     // _10
	virtual void isDone(int);      // _14
	virtual void _18() = 0;        // _18
	virtual void _1C() = 0;        // _1C
	virtual void getAgeNodeType(); // _20 (weak)
};

struct CoreNode {
	virtual void getCreature(int);          // _08
	virtual void getFirst();                // _0C
	virtual void getNext(int);              // _10
	virtual void isDone(int);               // _14
	virtual void _18() = 0;                 // _18
	virtual void _1C() = 0;                 // _1C
	virtual void _20() = 0;                 // _20
	virtual void read(RandomAccessStream&); // _24 (weak)
};

struct Node {
	virtual void getCreature(int);  // _08
	virtual void getFirst();        // _0C
	virtual void getNext(int);      // _10
	virtual void isDone(int);       // _14
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

struct ObjectMgr {
	virtual void getCreature(int);                        // _08
	virtual void getFirst();                              // _0C
	virtual void getNext(int);                            // _10
	virtual void isDone(int);                             // _14
	virtual void _18() = 0;                               // _18
	virtual void _1C() = 0;                               // _1C
	virtual void _20() = 0;                               // _20
	virtual void _24() = 0;                               // _24
	virtual void _28() = 0;                               // _28
	virtual void _2C() = 0;                               // _2C
	virtual void _30() = 0;                               // _30
	virtual void _34() = 0;                               // _34
	virtual void _38() = 0;                               // _38
	virtual void _3C() = 0;                               // _3C
	virtual void _40() = 0;                               // _40
	virtual void _44() = 0;                               // _44
	virtual ~ObjectMgr();                                 // _48 (weak)
	virtual void update();                                // _4C (weak)
	virtual void postUpdate(int, f32);                    // _50
	virtual void stickUpdate();                           // _54
	virtual void refresh(Graphics&);                      // _58
	virtual void drawShadow(Graphics&, Texture*);         // _5C
	virtual void getSize();                               // _60 (weak)
	virtual void getMax();                                // _64 (weak)
	virtual void findClosest(Vector3f&, f32, Condition*); // _68
	virtual void findClosest(Vector3f&, Condition*);      // _6C
	virtual void search(ObjectMgr*);                      // _70
	virtual void killAll();                               // _74
};

/**
 * @brief TODO
 */
struct MonoObjectMgr : public ANode, public CoreNode, public Node, public ObjectMgr {
	virtual void getCreature(int);                // _08
	virtual void getFirst();                      // _0C
	virtual void getNext(int);                    // _10
	virtual void isDone(int);                     // _14
	virtual ~MonoObjectMgr();                     // _48 (weak)
	virtual void update();                        // _4C (weak)
	virtual void postUpdate(int, f32);            // _50
	virtual void refresh(Graphics&);              // _58
	virtual void drawShadow(Graphics&, Texture*); // _5C
	virtual void getSize();                       // _60 (weak)
	virtual void getMax();                        // _64 (weak)
	virtual void search(ObjectMgr*);              // _70
	virtual void birth();                         // _78
	virtual void kill(Creature*);                 // _7C
	virtual void _80() = 0;                       // _80
};

#endif
