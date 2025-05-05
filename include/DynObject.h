#ifndef _DYNOBJECT_H
#define _DYNOBJECT_H

#include "types.h"
#include "DynSimulator.h"

struct DynCollObjBody;
struct MapMgr;

/**
 * @brief TODO
 */
struct DynObjBody : public RigidBody {
	DynObjBody()
	{
		// _1329C.resetBound();
	} // unused/inlined

	virtual void initDimensions(f32 x, f32 y, f32 z) // _30
	{
		mDimensions.set(x, y, z);
		mInvMass = (x / 2) * (y / 2) * (z / 2) * 0.000075f;
	}
	virtual void render(Graphics&);                           // _18
	virtual void computeForces(int, f32);                     // _34
	virtual void integrate(int, int, f32);                    // _38
	virtual void initRender(int);                             // _5C
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _70
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _74

	void applyWorldSpring(int, int, Vector3f&);
	void initBodyCollisions();
	void readScript(MapMgr*, char*);

	// _00        = VTBL
	// _00-_132B4 = RigidBody?
	u32 _132B4;             // _132B4, unknown
	u8 _132B8[0x4];         // _132B8, unknown
	Matrix4f _132BC;        // _132BC
	DynCollObjBody* _132FC; // _132FC, probably
};

/**
 * @brief TODO
 */
struct DynObjBridge : public DynObjBody {
	virtual void applyGroundForces(int, CollGroup*) { } // _6C

	// _00     = VTBL
	// _00-_?? = DynObjBody?
	// TODO: members
};

/**
 * @brief TODO
 */
struct DynObjPushable : public DynObjBody {
	virtual void render(Graphics&);                              // _18
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&) { } // _70

	// _00     = VTBL
	// _00-_?? = DynObjBody?
	// TODO: members
};

/**
 * @brief TODO
 */
struct DynObjSeeSaw : public DynObjBody {
	virtual void integrate(int, int, f32); // _38

	// _00     = VTBL
	// _00-_?? = DynObjBody?
	// TODO: members
};

#endif
