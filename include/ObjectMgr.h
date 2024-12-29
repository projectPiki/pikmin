#ifndef _OBJECTMGR_H
#define _OBJECTMGR_H

#include "types.h"
#include "Traversable.h"
#include "Node.h"

struct Condition;
struct Texture;

/**
 * @brief TODO.
 */
struct ObjectMgr : public Traversable, public Node {
	ObjectMgr()
	    : Node()
	{
	}

	virtual Creature* getCreature(int) = 0;                           // _08
	virtual int getFirst()             = 0;                           // _0C
	virtual int getNext(int)           = 0;                           // _10
	virtual bool isDone(int)           = 0;                           // _14
	virtual ~ObjectMgr() { }                                          // _48
	virtual void update();                                            // _4C
	virtual void postUpdate(int, f32);                                // _50
	virtual void stickUpdate();                                       // _54
	virtual void refresh(Graphics&);                                  // _58
	virtual void drawShadow(Graphics&, Texture*);                     // _5C
	virtual int getSize() = 0;                                        // _60
	virtual int getMax()  = 0;                                        // _64
	virtual Creature* findClosest(struct Vector3f&, f32, Condition*); // _68
	virtual Creature* findClosest(Vector3f&, Condition*);             // _6C
	virtual void search(ObjectMgr*);                                  // _70
	virtual void killAll();                                           // _74

	void invalidateSearch();
	void store();

	// unused/inlined:
	void restore();

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_08 = Traversable
	// _08-_28 = Node
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C.
 */
struct MonoObjectMgr : public ObjectMgr {
	MonoObjectMgr();

	virtual Creature* getCreature(int);           // _08
	virtual int getFirst();                       // _0C
	virtual int getNext(int);                     // _10
	virtual bool isDone(int);                     // _14
	virtual ~MonoObjectMgr() { }                  // _48 (weak)
	virtual void update();                        // _4C (weak)
	virtual void postUpdate(int, float);          // _50
	virtual void refresh(Graphics&);              // _58
	virtual void drawShadow(Graphics&, Texture*); // _5C
	virtual int getSize();                        // _60 (weak)
	virtual int getMax();                         // _64 (weak)
	virtual void search(ObjectMgr*);              // _70
	virtual Creature* birth();                    // _78
	virtual void kill(Creature*);                 // _7C
	virtual Creature* createObject() = 0;         // _80

	void create(int);
	void searchSelf();

	// unused/inlined:
	void getEmptyIndex();
	void getIndex(Creature*);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr
	Creature** mObjectList; // _28, array of objects
	int mMaxElements;       // _2C
	int mSize;              // _30
	int* _34;               // _34
	u32 _38;                // _38, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x4C.
 */
struct PolyObjectMgr : public ObjectMgr {
	PolyObjectMgr(int);

	virtual Creature* getCreature(int);           // _08
	virtual int getFirst();                       // _0C
	virtual int getNext(int);                     // _10
	virtual bool isDone(int);                     // _14
	virtual ~PolyObjectMgr();                     // _48
	virtual void update();                        // _4C
	virtual void postUpdate(int, float);          // _50
	virtual void refresh(Graphics&);              // _58
	virtual void drawShadow(Graphics&, Texture*); // _5C
	virtual int getSize();                        // _60
	virtual int getMax();                         // _64
	virtual void search(ObjectMgr*);              // _70
	virtual Creature* birth(int);                 // _78
	virtual void kill(Creature*);                 // _7C

	void create(int);
	void beginRegister();
	void registerClass(int objType, Creature* object, int size);
	void endRegister();
	void get(int);
	void searchSelf();

	// unused/inlined:
	void getEmptyIndex();
	void getIndex(Creature*);
	void getTemplateIndex(int);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr
	int _28;     // _28
	int mMax;    // _2C
	int mSize;   // _30
	u8 _34[0x4]; // _34, unknown
	u32 _38;     // _38, unknown
	int* _3C;    // _3C, indices maybe?
	int _40;     // _40
	u32 _44;     // _44, unknown
	u32 _48;     // _48, unknown, pointer to some array of objects of size 0xC.
};

#endif
