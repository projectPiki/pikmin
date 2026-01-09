#ifndef _DYNCOLL_H
#define _DYNCOLL_H

#include "BoundBox.h"
#include "Node.h"
#include "types.h"

struct Creature;
struct MapAnimShapeObject;
struct CollTriInfo;
struct CollGroup;
struct DynObjBody;
struct MapMgr;
struct Shape;

/**
 * @brief Base class for all dynamic collision objects, providing a minimal interface for collision detection and response.
 *
 * @note Size: 0x2C.
 */
struct DynCollObject : public Node {

	/// Constructs a collision object with no attached creature.
	DynCollObject()
	    : Node("")
	{
		mContactTickCount = 0;
		mLastContactTick  = -1;
		mCreature         = nullptr;
	}

	/// Trivial in base class - attached creatures are not moved with the object by default.
	virtual void adjust(Creature*) { } // _30

	/// Trivial in base class - velocities are not applied to this object by default.
	virtual void applyVelocity(immut Plane&, immut Vector3f&, immut Vector3f&) { } // _34

	/// Trivial in base class - collisions do nothing by default.
	virtual void touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&) { } // _38

	/// Returns `nullptr` always - no collision model is set up for base class.
	virtual Shape* getShape() { return nullptr; } // _3C

	// _00     = VTBL
	// _00-_20 = Node
	u32 mContactTickCount; ///< _20, how many objects have collided with this one on this frame - reset every frame.
	u32 mLastContactTick;  ///< _24, last tick that an object made a collision with this - to prevent double counting the same object.
	Creature* mCreature;   ///< _28, the creature this object is attached to, if any (wall, bridge, etc).
};

/**
 * @brief Dynamic collision objects that also have a model - adds functionality for joint visibility and rendering.
 *
 * @note Size: 0x140.
 */
struct DynCollShape : public DynCollObject {

	/**
	 * @brief Construct a new dynamic collision object from the given collision model.
	 * @param model Collision model to use.
	 */
	DynCollShape(Shape* model)
	{
		mCollisionModel = model;
		if (mCollisionModel) {
			createDupCollData();
		}

		mLocalSRT.s = Vector3f(1.0f, 1.0f, 1.0f);
		mLocalSRT.r = mLocalSRT.t = Vector3f(0.0f, 0.0f, 0.0f);
		mTransformMtx.makeIdentity();
	}

	virtual void update();                   // _10
	virtual void adjust(Creature* creature); // _30

	/**
	 * @brief Gets the collision model of the object.
	 * @return Pointer to object's collision model/shape.
	 */
	virtual Shape* getShape() { return mCollisionModel; } // _3C

	virtual void jointVisible(int jointIdx, int visFlag); // _40
	virtual void refresh(Graphics& gfx);                  // _44

	void createDupCollData();
	void updatePos();
	void updateContext();

	// unused/inlined:

	void drawAtari(Graphics& gfx);

	// _00     = VTBL
	// _00-_2C = DynCollObject
	Shape* mCollisionModel;     ///< _02C, the collision model for the object.
	Vector3f* mVertexList;      ///< _030, list of all collision vertices for the object.
	CollTriInfo* mCollTriList;  ///< _034, list of all collision triangles for the object.
	bool* mJointVisibility;     ///< _038, whether each joint of the object is visible - indexed by joint index.
	int mCollGroupCount;        ///< _03C, number of collision groupings in object's collision model.
	CollGroup** mCollGroupList; ///< _040, list of all collision groupings in object's collision model.
	BoundBox mBoundingBox;      ///< _044, bounding box of object, encompassing all of the object's collision vertices.
	Matrix4f mTransformMtx;     ///< _05C, matrix for transforming other objects from this object's local space to world space.
	Matrix4f mInverseMatrix;    ///< _09C, matrix for transforming other objects into this object's local space from world space.
	Matrix4f mViewMtx;          ///< _0DC, object's transform matrix, transformed to the camera's view space.
	SRT mLocalSRT;              ///< _11C, object's scale (_11C), rotation (_128) and position (_134) in its local space.
};

/**
 * @brief Dynamic collision model connected to a rigid body, to handle more complicated simulated physics.
 *
 * @note Size: 0x144.
 */
struct DynCollObjBody : public DynCollShape {

	/**
	 * @brief Constructs a new dynamic collision model with no rigid body.
	 * @param model Collision model to use.
	 */
	DynCollObjBody(Shape* model)
	    : DynCollShape(model)
	{
		mRigidBody = nullptr;
	}

	/// Overridden to be trivial, since transforms are handled by the rigid body.
	virtual void update() { } // _10

	/// Overridden to be trivial, since transforms are handled by the rigid body.
	virtual void adjust(Creature*) { } // _30

	virtual void applyVelocity(immut Plane&, immut Vector3f&, immut Vector3f&); // _34
	virtual void touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&); // _38

	// _00      = VTBL
	// _00-_140 = DynCollShape
	DynObjBody* mRigidBody; ///< _140, rigid body this collision object is attached to.
};

/**
 * @brief Dynamic collision model associated with a Pikmin-workable object (bridges and push boxes).
 *
 * @note Size: 0x140.
 */
struct DynBuildShape : public DynCollShape {

	/**
	 * @brief Constructs a new dynamic collision object from the given collision model.
	 * @param model Collision model to apply to the object.
	 */
	DynBuildShape(Shape* model)
	    : DynCollShape(model)
	{
	}

	/// Overridden to be trivial, since transforms are handled by the parent creature.
	virtual void update() { } // _10

	/// Overridden to be trivial, since rendering is handled by the parent creature.
	virtual void refresh(Graphics&) { } // _44

	// _00      = VTBL
	// _00-_140 = DynCollShape
};

#endif
