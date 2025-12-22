#ifndef _DYNOBJECT_H
#define _DYNOBJECT_H

#include "DynSimulator.h"
#include "types.h"

struct DynCollObjBody;
struct MapMgr;

/**
 * @brief TODO
 */
struct DynObjBody : public RigidBody {
	DynObjBody()
	{
		mBodyShell          = nullptr;
		mBoundingPointCount = 0;
		mVelMask.set(1.0f, 1.0f, 1.0f);
		mAngularVelMask.set(1.0f, 1.0f, 1.0f);
		mImpactResponseForceScale = 1.0f;
	}

	virtual void initDimensions(f32 x, f32 y, f32 z) // _30
	{
		RigidBody::initDimensions(x, y, z);
		mMass = (x / 2) * (y / 2) * (z / 2) * 0.000075f;
	}
	virtual void render(Graphics&);                                             // _18
	virtual void computeForces(int, f32);                                       // _34
	virtual void integrate(int, int, f32);                                      // _38
	virtual void initRender(int);                                               // _5C
	virtual void touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&); // _70
	virtual void applyVelocity(immut Plane&, immut Vector3f&, immut Vector3f&); // _74

	void applyWorldSpring(int, int, immut Vector3f&);
	void initBodyCollisions();
	void readScript(MapMgr*, immut char*);

	// _00        = VTBL
	// _00-_132B4 = RigidBody
	Shape* mBodyShell;              // _132B4
	Shape* mStaticEnvironmentShape; // _132B8
	Matrix4f mRenderTransformMtx;   // _132BC
	DynCollObjBody* mCollObj;       // _132FC, probably
	Vector3f mVelMask;              // _13300
	Vector3f mAngularVelMask;       // _1330C
	f32 mImpactResponseForceScale;  // _13318
};

/**
 * @brief TODO
 */
struct DynObjBridge : public DynObjBody {
	DynObjBridge() { }

	virtual void applyGroundForces(int, CollGroup*) { } // _6C

	// _00        = VTBL
	// _00-_1331C = DynObjBody
};

/**
 * @brief TODO
 */
struct DynObjPushable : public DynObjBody {
	virtual void render(Graphics&);                                                // _18
	virtual void touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&) { } // _70

	// _00        = VTBL
	// _00-_1331C = DynObjBody
	f32 mCurrPushStrength;   // _1331C, current applied force magnitude
	f32 mMinStrengthToMove;  // _13320, min mag required to cause object to move
	f32 mMovingPushStrength; // _13324, actual applied force strength once moving (always the same)
};

/**
 * @brief TODO
 */
struct DynObjSeeSaw : public DynObjBody {
	virtual void integrate(int, int, f32); // _38

	// _00        = VTBL
	// _00-_1331C = DynObjBody
	Matrix4f mPostMaskVelRotationMtx; // _1331C
	Matrix4f mPreMaskVelRotationMtx;  // _1335C
};

#endif
