#ifndef _DYNAMICS_H
#define _DYNAMICS_H

#include "types.h"
#include "Node.h"
#include "Matrix3f.h"
#include "BoundBox.h"
#include "Collision.h"

struct Collision;
struct CollGroup;
struct CollState;
struct RigidBody;
struct Shape;
struct LightCamera;

/**
 * @brief TODO
 */
struct WorldSpring {
	WorldSpring() { }

	inline void init(int idx, f32 x, f32 y, f32 z)
	{
		mAttachPointIdx = idx;
		mAttachPos.set(x, y, z);
	}

	int mAttachPointIdx; // _00
	Vector3f mAttachPos; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x132B4.
 */
struct RigidBody : public Node {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x308C.
	 */
	struct configuration {
		configuration() { }

		Matrix3f mOrientationMtx;    // _00
		Quat mOrientationQuat;       // _24
		Vector3f mPosition;          // _34
		Vector3f mLinearVel;         // _40
		Vector3f mAngularVel;        // _4C
		Vector3f mLocalAngularVel;   // _58
		Matrix3f mInertiaTensor;     // _64
		u32 _88;                     // _88, unknown
		Vector3f mBodyPoints[0x400]; // _8C
	};

	RigidBody()
	    : Node("rigidBody")
	{
		mIntegrationStates[1]._88 = 0;
		mIntegrationStates[0]._88 = 0;
		mInvMass                  = 0.0f;
		_90                       = 0;
		mBodyPointCount           = 0;
		mSpringCount              = 0;
	}

	virtual void render(Graphics&);                               // _18
	virtual void initDimensions(f32 width, f32 height, f32 depth) // _30
	{
		mDimensions.set(width, height, depth);
	}
	virtual void computeForces(int, f32) // _34
	{
		mLinearAccel.set(0.0f, 0.0f, 0.0f);
		mAngularAccel.set(0.0f, 0.0f, 0.0f);
		applyCMForce(Vector3f(0.0f, -9.81f, 0.0f));
	}
	virtual void integrate(int, int, f32);           // _38
	virtual bool resolveCollisions(int, Collision&); // _3C
	virtual void calculateVertices(int);             // _40
	virtual void initCollisions(int configIdx)       // _44
	{
		configuration& state = mIntegrationStates[configIdx];
		_1329C.resetBound();
		for (int i = 0; i < mBodyPointCount; i++) {
			_1329C.expandBound(state.mBodyPoints[i + _90]);
		}
	}
	virtual bool checkForCollisions(int, CollState&);                                                             // _48
	virtual void updateVecQuats(int, f32);                                                                        // _4C
	virtual void updateViewInfo(int, int);                                                                        // _50
	virtual void applyBodyFriction(int configIdx, Vector3f& contactNormal, Vector3f& contactPoint, Vector3f& vel) // _54
	{
		Vector3f frictionForce(vel);
		frictionForce.project(contactNormal);           // keep only tangential component
		frictionForce.multiply(-vel.length() * 0.125f); // scale friction by velocity + oppose motion
		applyForce(configIdx, Vector3f(frictionForce), contactPoint);
	}
	virtual void makeBodyQuat(Quat&) { }                 // _58
	virtual void initRender(int);                        // _5C
	virtual void shadrender(Graphics&, LightCamera*) { } // _60
	virtual f32 getViewScale() { return 1.0f; }          // _64
	virtual void updateCont() { }                        // _68
	virtual void applyGroundForces(int, CollGroup*);     // _6C

	void initializeBody();
	void applyCMForce(Vector3f&);

	void applyForce(int configIdx, Vector3f& force, Vector3f& appliedPoint)
	{
		Vector3f arm = appliedPoint - mIntegrationStates[configIdx].mPosition;
		mLinearAccel.x += force.x * mInvMass;
		mLinearAccel.y += force.y * mInvMass;
		mLinearAccel.z += force.z * mInvMass;
		arm.CP(force);
		mAngularAccel.x += arm.x;
		mAngularAccel.y += arm.y;
		mAngularAccel.z += arm.z;
	}

	// DLL inlines to do:
	void addBoundingPoint(f32, f32, f32);
	void addHook(f32, f32, f32);
	void addSpring(int, f32, f32, f32);

	// _00     = VTBL
	// _00-_20 = Node
	Vector3f mInitPosition;              // _20
	Vector3f mInitOrientationX;          // _2C
	Vector3f mInitOrientationY;          // _38
	Vector3f mInitOrientationZ;          // _44
	Vector3f mDimensions;                // _50
	f32 mInvMass;                        // _5C
	f32 mMass;                           // _60
	Matrix3f mInertiaTensor;             // _64
	f32 mRestitutionFactor;              // _88
	int mBodyPointCount;                 // _8C
	int _90;                             // _90
	Vector3f mBodyPoints[0x400];         // _94
	int mBodyPointHitCounts[0x400];      // _3094
	int mSpringCount;                    // _4094
	WorldSpring mSprings[8];             // _4098
	configuration mIntegrationStates[2]; // _4118, prev and current, which swap from frame to frame
	Vector3f mLinearAccel;               // _A230
	Vector3f mAngularAccel;              // _A23C
	Vector3f _A248[2][0x400];            // _A248
	Vector3f _10248[0x400];              // _10248
	Vector3f _13248[2];                  // _13248
	Vector3f _13260;                     // _13260
	Quat _1326C[2];                      // _1326C
	Quat _1328C;                         // _1328C
	BoundBox _1329C;                     // _1329C
};

/**
 * @brief TODO
 */
struct DynSimulator : public Node {
	DynSimulator()
	    : Node("simulator")
	{
		_2C = 0;
		_20 = 0;
		_24 = 0;
	}

	void resetWorld();
	void doSimulation(f32, f32, Shape*);
	void updateVecQuats(f32);

	// unused/inlined:
	void evolveSimulation(f32, Shape*);
	void Integrate(f32);
	void CalculateVertices(int);
	int CheckForCollisions(int, Shape*);
	void ResolveCollisions(int);

	// DLL inlines to do:
	bool isPaused() { return _20 != 0; }
	void InitRender();
	void updateConts();
	void Render(Graphics&);

	// _00     = VTBL
	// _00-_20 = Node
	int _20;               // _20
	int _24;               // _24
	int mCurrentConfigIdx; // _28
	u32 _2C;               // _2C, unknown
	CollState _30;         // _30
};

#endif
