#ifndef _DYNOBJECT_H
#define _DYNOBJECT_H

#include "types.h"
#include "DynSimulator.h"

struct MapMgr;

/**
 * @brief TODO
 *
 * @note Genuinely not sure where to put this, but here kind of makes sense?
 */
struct WorldSpring {
	WorldSpring();

	u8 _00[0x4];  // _00, unknown
	Vector3f _04; // _04
};

/**
 * @brief TODO
 */
struct DynObjBody : public RigidBody {
	DynObjBody(); // unused/inlined

	virtual void render(Graphics&);                           // _18
	virtual void initDimensions(f32, f32, f32);               // _30
	virtual void computeForces(int, f32);                     // _34
	virtual void integrate(int, int, f32);                    // _38
	virtual void initRender(int);                             // _5C
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _70
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _74

	void applyWorldSpring(int, int, Vector3f&);
	void initBodyCollisions();
	void readScript(MapMgr*, char*);

	// _00     = VTBL
	// _00-_?? = RigidBody?
	// TODO: members
};

/**
 * @brief TODO
 */
struct DynObjBridge : public DynObjBody {
	virtual void applyGroundForces(int, CollGroup*); // _6C

	// _00     = VTBL
	// _00-_?? = DynObjBody?
	// TODO: members
};

/**
 * @brief TODO
 */
struct DynObjPushable : public DynObjBody {
	virtual void render(Graphics&);                           // _18
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _70

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
