#ifndef _DYNCOLL_H
#define _DYNCOLL_H

#include "types.h"
#include "Node.h"

struct Creature;
struct MapAnimShapeObject;
struct MapMgr;

/**
 * @brief TODO
 */
struct DynCollObject : public Node {
	DynCollObject()
	    : Node("")
	{
		_20 = 0;
		_24 = -1;
		_28 = 0;
	}

	virtual void adjust(Creature*);                           // _30
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _34
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual Shape* getShape();                                // _3C

	// _00     = VTBL
	// _00-_20 = Node
	u32 _20; // _20, unknown
	u32 _24; // _24, maybe int?
	u32 _28; // _28, unknown
};

/**
 * @brief TODO
 */
struct DynCollShape : public DynCollObject {
	DynCollShape(Shape* shape);

	virtual void update();               // _10
	virtual void adjust(Creature*);      // _30
	virtual Shape* getShape();           // _3C
	virtual void jointVisible(int, int); // _40
	virtual void refresh(Graphics&);     // _44

	void createDupCollData();
	void updatePos();
	void updateContext();

	// unused/inlined:
	void drawAtari(Graphics&);

	// _00     = VTBL
	// _00-_2C = DynCollObject
	Shape* mShape;        // _2C
	u8 _30[0x44 - 0x30];  // _30, unknown
	BoundBox _44;         // _44
	Matrix4f _5C;         // _5C
	u8 _9C[0x11C - 0x9C]; // _9C, unknown
	Vector3f _11C;        // _11C
	Vector3f _128;        // _128
	Vector3f _134;        // _134
};

/**
 * @brief TODO
 */
struct DynCollObjBody : public DynCollShape {
	DynCollObjBody() // TODO: fix this, it's implicit but required/this is just a guess
	    : DynCollShape(nullptr)
	{
	}

	virtual void update();                                    // _10
	virtual void adjust(Creature*);                           // _30
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _34
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38

	// _00     = VTBL
	// _00-_?? = DynCollShape
	// TODO: members
};

/**
 * @brief TODO
 */
struct DynBuildShape : public DynCollShape {
	DynBuildShape() // TODO: fix this, it's implicit but required/this is just a guess
	    : DynCollShape(nullptr)
	{
	}

	virtual void update();           // _10
	virtual void refresh(Graphics&); // _44

	// _00     = VTBL
	// _00-_?? = DynCollShape
	// TODO: members
};

#endif
