#ifndef _DYNAMICS_H
#define _DYNAMICS_H

#include "BoundBox.h"
#include "Collision.h"
#include "Matrix3f.h"
#include "Node.h"
#include "types.h"

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

	void init(int hookIdx, f32 x, f32 y, f32 z)
	{
		mHookIdx = hookIdx;
		mOffset.set(x, y, z);
	}

	int mHookIdx;     // _00
	Vector3f mOffset; // _04
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
		mMass                     = 0.0f;
		mHookPointCount           = 0;
		mBoundingPointCount       = 0;
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
	virtual void integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep); // _38
	virtual bool resolveCollisions(int, Collision&);                            // _3C
	virtual void calculateVertices(int);                                        // _40
	virtual void initCollisions(int configIdx)                                  // _44
	{
		configuration& state = mIntegrationStates[configIdx];
		mCollisionBounds.resetBound();
		for (int i = 0; i < mBoundingPointCount; i++) {
			mCollisionBounds.expandBound(state.mBodyPoints[i + mHookPointCount]);
		}
	}
	virtual bool checkForCollisions(int, CollState&);                                                                               // _48
	virtual void updateVecQuats(int, f32);                                                                                          // _4C
	virtual void updateViewInfo(int, int);                                                                                          // _50
	virtual void applyBodyFriction(int configIdx, immut Vector3f& contactNormal, immut Vector3f& contactPoint, immut Vector3f& vel) // _54
	{
		Vector3f frictionForce(vel);
		frictionForce.project(contactNormal);           // keep only tangential component
		frictionForce.multiply(-vel.length() * 0.125f); // scale friction by velocity + oppose motion
		applyForce(configIdx, Vector3f(frictionForce), contactPoint);
	}
	virtual void makeBodyQuat(immut Quat&) { }           // _58
	virtual void initRender(int);                        // _5C
	virtual void shadrender(Graphics&, LightCamera*) { } // _60
	virtual f32 getViewScale() { return 1.0f; }          // _64
	virtual void updateCont() { }                        // _68
	virtual void applyGroundForces(int, CollGroup*);     // _6C

	void initializeBody();
	void applyCMForce(immut Vector3f&);

	void applyForce(int configIdx, immut Vector3f& force, immut Vector3f& appliedPoint)
	{
		Vector3f arm = appliedPoint - mIntegrationStates[configIdx].mPosition;
		mLinearAccel.x += force.x * mMass;
		mLinearAccel.y += force.y * mMass;
		mLinearAccel.z += force.z * mMass;
		arm.CP(force);
		mAngularAccel.x += arm.x;
		mAngularAccel.y += arm.y;
		mAngularAccel.z += arm.z;
	}

	void addBoundingPoint(f32 x, f32 y, f32 z)
	{
		mBodyPoints[mBoundingPointCount + mHookPointCount].set(x, y, z);
		mBoundingPointCount++;
	}

	void addHook(f32 x, f32 y, f32 z)
	{
		mBodyPoints[mHookPointCount].set(x, y, z);
		mHookPointCount++;
	}

	void addSpring(int hookIdx, f32 x, f32 y, f32 z)
	{
		mSprings[mSpringCount].init(hookIdx, x, y, z);
		mSpringCount++;
	}

	// _00     = VTBL
	// _00-_20 = Node
	Vector3f mInitPosition;               // _20
	Vector3f mInitOrientationX;           // _2C
	Vector3f mInitOrientationY;           // _38
	Vector3f mInitOrientationZ;           // _44
	Vector3f mDimensions;                 // _50
	f32 mMass;                            // _5C
	f32 mInvMass;                         // _60
	Matrix3f mInertiaTensor;              // _64
	f32 mRestitutionFactor;               // _88
	int mBoundingPointCount;              // _8C
	int mHookPointCount;                  // _90
	Vector3f mBodyPoints[0x400];          // _94, hook points, then bounding points
	int mBodyPointHitCounts[0x400];       // _3094
	int mSpringCount;                     // _4094
	WorldSpring mSprings[8];              // _4098
	configuration mIntegrationStates[2];  // _4118, prev and current, which swap from frame to frame
	Vector3f mLinearAccel;                // _A230
	Vector3f mAngularAccel;               // _A23C
	Vector3f mBufferedPoints[2][0x400];   // _A248
	Vector3f mBodySpaceHookPoints[0x400]; // _10248
	Vector3f mBufferedPositions[2];       // _13248
	Vector3f mRenderPosition;             // _13260
	Quat mBufferedOrientations[2];        // _1326C
	Quat mRenderOrientation;              // _1328C
	BoundBox mCollisionBounds;            // _1329C
};

/**
 * @brief TODO
 */
struct DynSimulator : public Node {
	DynSimulator()
	    : Node("simulator")
	{
		_unused2C                     = 0;
		mIsPaused                     = FALSE;
		mWriteTargetRenderBufferIndex = 0;
	}

	void resetWorld();
	void doSimulation(f32 totalTime, f32 maxTimeStep, Shape* shape);
	void updateVecQuats(f32);

	// unused/inlined:
	void evolveSimulation(f32, Shape*);
	void Integrate(f32);
	void CalculateVertices(int);
	int CheckForCollisions(int, Shape*);
	void ResolveCollisions(int);

	bool isPaused() { return mIsPaused; }
	void updateConts()
	{
		for (RigidBody* body = (RigidBody*)Child(); body; body = (RigidBody*)body->Next()) {
			body->updateCont();
		}
	}
	void InitRender()
	{
		for (RigidBody* body = (RigidBody*)Child(); body; body = (RigidBody*)body->Next()) {
			body->initRender(mCurrentConfigIdx);
		}
	}
	void Render(Graphics& gfx)
	{
		for (RigidBody* body = (RigidBody*)Child(); body; body = (RigidBody*)body->Next()) {
			body->render(gfx);
		}
	}

	// _00     = VTBL
	// _00-_20 = Node
	BOOL mIsPaused;                    // _20
	int mWriteTargetRenderBufferIndex; // _24
	int mCurrentConfigIdx;             // _28
	u32 _unused2C;                     // _2C, unknown
	CollState mWorldState;             // _30
};

#endif
