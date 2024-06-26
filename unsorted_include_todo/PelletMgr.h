#ifndef _PELLETMGR_H
#define _PELLETMGR_H

#include "types.h"
#include "Node.h"
#include "Creature.h"
#include "PelletView.h"

/**
 * .obj __vt__9PelletMgr, global
 * .4byte __RTTI__9PelletMgr
 * .4byte 0
 * .4byte getCreature__13MonoObjectMgrFi
 * .4byte getFirst__13MonoObjectMgrFv
 * .4byte getNext__13MonoObjectMgrFi
 * .4byte isDone__13MonoObjectMgrFi
 * .4byte __RTTI__9PelletMgr
 * .4byte 0xFFFFFFF8
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@8@read__9PelletMgrFR18RandomAccessStream"
 * .4byte "@8@update__13MonoObjectMgrFv"
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte __dt__9PelletMgrFv
 * .4byte update__13MonoObjectMgrFv
 * .4byte postUpdate__13MonoObjectMgrFif
 * .4byte stickUpdate__9ObjectMgrFv
 * .4byte refresh__9PelletMgrFR8Graphics
 * .4byte drawShadow__13MonoObjectMgrFR8GraphicsP7Texture
 * .4byte getSize__13MonoObjectMgrFv
 * .4byte getMax__13MonoObjectMgrFv
 * .4byte findClosest__9ObjectMgrFR8Vector3ffP9Condition
 * .4byte findClosest__9ObjectMgrFR8Vector3fP9Condition
 * .4byte search__13MonoObjectMgrFP9ObjectMgr
 * .4byte killAll__9ObjectMgrFv
 * .4byte birth__13MonoObjectMgrFv
 * .4byte kill__13MonoObjectMgrFP8Creature
 * .4byte createObject__9PelletMgrFv
 * .4byte read__9PelletMgrFR18RandomAccessStream
 */

struct MonoObjectMgr {
	virtual void getCreature(int);                // _08
	virtual void getFirst();                      // _0C
	virtual void getNext(int);                    // _10
	virtual void isDone(int);                     // _14
	virtual void _18() = 0;                       // _18
	virtual void _1C() = 0;                       // _1C
	virtual void _20() = 0;                       // _20
	virtual void _24() = 0;                       // _24
	virtual void _28() = 0;                       // _28
	virtual void _2C() = 0;                       // _2C
	virtual void _30() = 0;                       // _30
	virtual void _34() = 0;                       // _34
	virtual void _38() = 0;                       // _38
	virtual void _3C() = 0;                       // _3C
	virtual void _40() = 0;                       // _40
	virtual void _44() = 0;                       // _44
	virtual ~MonoObjectMgr();                     // _48 (weak)
	virtual void update();                        // _4C (weak)
	virtual void postUpdate(int, f32);          // _50
	virtual void _54() = 0;                       // _54
	virtual void refresh(Graphics&);              // _58
	virtual void drawShadow(Graphics&, Texture*); // _5C
	virtual void getSize();                       // _60 (weak)
	virtual void getMax();                        // _64 (weak)
	virtual void _68() = 0;                       // _68
	virtual void _6C() = 0;                       // _6C
	virtual void search(ObjectMgr*);              // _70
	virtual void _74() = 0;                       // _74
	virtual void birth();                         // _78
	virtual void kill(Creature*);                 // _7C
};

struct ObjectMgr {
	virtual void _08() = 0;                                 // _08
	virtual void _0C() = 0;                                 // _0C
	virtual void _10() = 0;                                 // _10
	virtual void _14() = 0;                                 // _14
	virtual void _18() = 0;                                 // _18
	virtual void _1C() = 0;                                 // _1C
	virtual void _20() = 0;                                 // _20
	virtual void _24() = 0;                                 // _24
	virtual void _28() = 0;                                 // _28
	virtual void _2C() = 0;                                 // _2C
	virtual void _30() = 0;                                 // _30
	virtual void _34() = 0;                                 // _34
	virtual void _38() = 0;                                 // _38
	virtual void _3C() = 0;                                 // _3C
	virtual void _40() = 0;                                 // _40
	virtual void _44() = 0;                                 // _44
	virtual ~ObjectMgr();                                   // _48 (weak)
	virtual void _4C() = 0;                                 // _4C
	virtual void _50() = 0;                                 // _50
	virtual void stickUpdate();                             // _54
	virtual void refresh(Graphics&);                        // _58
	virtual void _5C() = 0;                                 // _5C
	virtual void _60() = 0;                                 // _60
	virtual void _64() = 0;                                 // _64
	virtual void findClosest(Vector3f&, f32, Condition*); // _68
	virtual void findClosest(Vector3f&, Condition*);        // _6C
	virtual void _70() = 0;                                 // _70
	virtual void killAll();                                 // _74
};

/**
 * @brief TODO
 */
struct PelletMgr : public MonoObjectMgr, public ANode, public Node, public ObjectMgr {
	virtual ~PelletMgr();                   // _48 (weak)
	virtual void refresh(Graphics&);        // _58
	virtual void createObject();            // _80
	virtual void read(RandomAccessStream&); // _84 (weak)

	void getUfoIndexFromID(u32);
	void getUfoIDFromIndex(int);
	void decomposeNumberPellet(u32, int&, int&);
	void registerUfoParts();
	void newNumberPellet(int, int);
	void newPellet(u32, PelletView*);
	void getShapeObject(u32);
	PelletMgr(struct MapMgr*);
	void addUseList(u32);
	void initShapeInfos();
	void getConfigIndex(u32);
	void getConfigFromIdx(int);
	void getConfig(u32);
	void readConfigs(RandomAccessStream&);
	void readAnimInfos(RandomAccessStream&);
	void initTekiNakaParts();
	void createShapeObjects();
	void refresh2d(Graphics&);
};

#endif
