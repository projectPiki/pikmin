#ifndef _DYNOBJECT_H
#define _DYNOBJECT_H

#include "DynSimulator.h"
#include "types.h"

struct DynCollObjBody;
struct MapMgr;

/**
 * @brief Dynamic rigid body in the game world that can interact with the map and collision systems.
 *
 * Unused in the actual release of the game, only present in some inaccessible code blocks.
 *
 * @note Size: 0x1331C.
 */
struct DynObjBody : public RigidBody {

	/// Constructs a dynamic rigid body with no model and no movement constraints.
	DynObjBody()
	{
		mBodyShell          = nullptr;
		mBoundingPointCount = 0;
		mLinearVelMask.set(1.0f, 1.0f, 1.0f);
		mAngularVelMask.set(1.0f, 1.0f, 1.0f);
		mImpactForceScale = 1.0f;
	}

	/**
	 * @brief Initialises dimensions of the object, along with setting its mass relative to it.
	 * @param width Width of object.
	 * @param height Height of object.
	 * @param depth Depth of object.
	 */
	virtual void initDimensions(f32 width, f32 height, f32 depth) // _30
	{
		RigidBody::initDimensions(width, height, depth);
		mMass = (width / 2) * (height / 2) * (depth / 2) * 0.000075f;
	}

	virtual void render(Graphics& gfx);                                                                             // _18
	virtual void computeForces(int configIdx, f32 timeStep);                                                        // _34
	virtual void integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep);                                     // _38
	virtual void initRender(int);                                                                                   // _5C
	virtual void touchCallback(immut Plane& contactPlane, immut Vector3f& contactPos, immut Vector3f& colliderVel); // _70
	virtual void applyVelocity(immut Plane& contactPlane, immut Vector3f& contactPos, immut Vector3f& velocity);    // _74

	void applyWorldSpring(int configIdx, int hookIdx, immut Vector3f& springAnchorPt);
	void initBodyCollisions();
	void readScript(MapMgr* map, immut char* filePath);

	// _00        = VTBL
	// _00-_132B4 = RigidBody
	Shape* mBodyShell;            ///< _132B4, collision model for this object.
	Shape* mMapShape;             ///< _132B8, map model that this object is on/interacting with.
	Matrix4f mRenderTransformMtx; ///< _132BC, transform from object's local (render) space to world space.
	DynCollObjBody* mCollObj;     ///< _132FC, collision handler for this body.
	Vector3f mLinearVelMask;      ///< _13300, mask for restricting movement along each axis. 0=no movement, 1=normal movement.
	Vector3f mAngularVelMask;     ///< _1330C, mask for restricting rotation around each axis. 0=no rotation, 1=normal rotation.
	f32 mImpactForceScale;        ///< _13318, factor to scale impact forces (touch and applied velocities) by.
};

/**
 * @brief Dynamic rigid body in the game world that can clip into the ground without popping up.
 *
 * Unused in the actual game, but constructed in some inaccessible code blocks.
 *
 * @note Size: 0x1331C.
 */
struct DynObjBridge : public DynObjBody {

	/// Constructs a blank "bridge" object (not actually used by bridges in-game).
	DynObjBridge() { }

	// Overridden to be trivial, to allow bridges to clip into the ground without triggering collision resolution.
	virtual void applyGroundForces(int, CollGroup*) { } // _6C

	// _00        = VTBL
	// _00-_1331C = DynObjBody
};

/**
 * @brief Dynamic rigid body in the game world that handles its own pushing collision, including a threshold system for when it can be
 * pushed.
 *
 * Unused in the actual game.
 *
 * @note Size: 0x13328.
 */
struct DynObjPushable : public DynObjBody {

	virtual void render(Graphics& gfx); // _18

	/// Overridden to be trivial, to let pushing be handled more thresholded, rather than per-collision.
	virtual void touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&) { } // _70

	// _00        = VTBL
	// _00-_1331C = DynObjBody
	f32 mCurrPushForce;        ///< _1331C, current force magnitude applied by pushers (may not move object).
	f32 mMoveThreshold;        ///< _13320, minimum force required to cause object to move.
	f32 mPushForceWhileMoving; ///< _13324, actual applied force strength once moving (never set, but would always be the same).
};

/**
 * @brief Dynamic rigid body in the game world that handles its own dynamics, including restricted motion along pre-defined axes.
 *
 * Unused in the actual game. Matrices are never set up, just used by its integrate function. These would restrict motion along axes that
 * may not align with the world axes OR the object's local axes.
 *
 * @note Size: 0x1339C.
 */
struct DynObjSeeSaw : public DynObjBody {

	virtual void integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep); // _38

	// _00        = VTBL
	// _00-_1331C = DynObjBody
	Matrix4f mInverseConstraintMtx; ///< _1331C, matrix for transforming object into local constraint space, to apply axes restrictions.
	Matrix4f mConstraintMtx;        ///< _1335C, matrix for transforming object back into world space, after applying axes restrictions.
};

#endif
