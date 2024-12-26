#ifndef _DYNCOLL_H
#define _DYNCOLL_H

#include "types.h"
#include "Node.h"
#include "BoundBox.h"

struct Creature;
struct MapAnimShapeObject;
struct MapMgr;
struct Shape;

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
	u32 _20;       // _20, unknown
	u32 _24;       // _24, maybe int?
	Creature* _28; // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x140.
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
	Shape* mShape;           // _2C
	u8 _30[0x44 - 0x30];     // _30, unknown
	BoundBox _44;            // _44
	Matrix4f mTransformMtx;  // _5C
	Matrix4f mInverseMatrix; // _9C
	u8 _DC[0x11C - 0xDC];    // _CC, unknown
	Vector3f _11C;           // _11C
	Vector3f _128;           // _128
	Vector3f _134;           // _134
};

/**
 * @brief TODO
 *
 * @note Size: 0x144.
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

	// _00      = VTBL
	// _00-_140 = DynCollShape
	u8 _140[0x4]; // _140, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x140.
 */
struct DynBuildShape : public DynCollShape {
	DynBuildShape(Shape* s) // TODO: fix this, it's implicit but required/this is just a guess
	    : DynCollShape(s)
	{
	}

	virtual void update();           // _10
	virtual void refresh(Graphics&); // _44

	// _00      = VTBL
	// _00-_140 = DynCollShape
};

#endif
