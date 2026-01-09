#ifndef _DYNSIMULATOR_H
#define _DYNSIMULATOR_H

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

/// Rest length of a spring, used in harmonic oscillator calculations.
#define SPRING_REST_LENGTH (20.0f)

/// Interval at which to update the world's physics.
#define PHYSICS_UPDATE_STEP_TIME (1 / 60.0f)

/// Interval at which to perform physics sub-steps.
#define PHYSICS_INTEGRATION_STEP_TIME (1 / 80.0f)

/**
 * @brief A spring attached to a "hook" point on a rigid body.
 *
 * @note Size: 0x10.
 */
struct WorldSpring {

	/// Default constructor (trivial).
	WorldSpring() { }

	/**
	 * @brief Initialises the hook with a given body point index to attach to, and an anchor position.
	 * @param hookIdx Index of point on rigid body to attach this spring to.
	 * @param x World space x coordinate of anchor position for (other end of) spring.
	 * @param y World space y coordinate of anchor position for (other end of) spring.
	 * @param z World space z coordinate of anchor position for (other end of) spring.
	 */
	void init(int hookIdx, f32 x, f32 y, f32 z)
	{
		mHookIdx = hookIdx;
		mAnchorPoint.set(x, y, z);
	}

	int mHookIdx;          ///< _00, index of rigid body hook point that spring is attached to.
	Vector3f mAnchorPoint; ///< _04, world-space position the other end of the spring is attached to.
};

/**
 * @brief A physical object being simulated.
 *
 * Includes mass, geometry, state and methods for simulation and rendering.
 *
 * @note Size: 0x132B4.
 */
struct RigidBody : public Node {

	/**
	 * @brief Stores the physical state of a rigid body at a given simulation step.
	 *
	 * @note Size: 0x308C.
	 */
	struct configuration {

		/// Trivial default constructor.
		configuration() { }

		Matrix3f mOrientationMtx;    ///< _00, orientation of rigid body (as matrix).
		Quat mOrientationQuat;       ///< _24, orientation of rigid body (as quaternion).
		Vector3f mPosition;          ///< _34, position of rigid body.
		Vector3f mLinearVel;         ///< _40, linear velocity of rigid body.
		Vector3f mAngularVel;        ///< _4C, angular velocity of rigid body (in world space).
		Vector3f mLocalAngularVel;   ///< _58, angular velocity of rigid body (in local space).
		Matrix3f mInertiaTensor;     ///< _64, inertia tensor (in world space).
		u32 _88;                     ///< _88, unknown/unused - only ever set to 0.
		Vector3f mBodyPoints[0x400]; ///< _8C, transformed body points (in world space) - hook points then bounding points.
	};

	/// Default constructor. Sets all basic counts to 0.
	RigidBody()
	    : Node("rigidBody")
	{
		mIntegrationStates[0]._88 = mIntegrationStates[1]._88 = 0;

		mMass               = 0.0f;
		mHookPointCount     = 0;
		mBoundingPointCount = 0;
		mSpringCount        = 0;
	}

	virtual void render(Graphics& gfx); // _18

	/**
	 * @brief Initialises dimensions of the object.
	 * @param width Width of object.
	 * @param height Height of object.
	 * @param depth Depth of object.
	 */
	virtual void initDimensions(f32 width, f32 height, f32 depth) // _30
	{
		mDimensions.set(width, height, depth);
	}

	/**
	 * @brief Calculates and applies forces to object due to accelerations.
	 * @param configIdx Current configuration index.
	 * @param timeStep Time step to calculate over.
	 */
	virtual void computeForces(int configIdx, f32 timeStep) // _34
	{
		// apply gravity and nothing else.
		mLinearAccel.set(0.0f, 0.0f, 0.0f);
		mAngularAccel.set(0.0f, 0.0f, 0.0f);
		applyCMForce(Vector3f(0.0f, -9.81f, 0.0f));
	}
	virtual void integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep); // _38
	virtual bool resolveCollisions(int configIdx, Collision& coll);             // _3C
	virtual void calculateVertices(int configIdx);                              // _40
	virtual void initCollisions(int configIdx)                                  // _44
	{
		configuration& state = mIntegrationStates[configIdx];
		mCollisionBounds.resetBound();
		for (int i = 0; i < mBoundingPointCount; i++) {
			mCollisionBounds.expandBound(state.mBodyPoints[i + mHookPointCount]);
		}
	}
	virtual bool checkForCollisions(int, CollState&);                                                                               // _48
	virtual void updateVecQuats(int renderBufferIndex, f32 interpFactor);                                                           // _4C
	virtual void updateViewInfo(int targetBufferIdx, int srcConfigIdx);                                                             // _50
	virtual void applyBodyFriction(int configIdx, immut Vector3f& contactNormal, immut Vector3f& contactPoint, immut Vector3f& vel) // _54
	{
		Vector3f frictionForce(vel);
		frictionForce.project(contactNormal);           // keep only tangential component
		frictionForce.multiply(-vel.length() * 0.125f); // scale friction by velocity + oppose motion
		applyForce(configIdx, Vector3f(frictionForce), contactPoint);
	}
	virtual void makeBodyQuat(immut Quat&) { }                           // _58
	virtual void initRender(int);                                        // _5C
	virtual void shadrender(Graphics&, LightCamera*) { }                 // _60
	virtual f32 getViewScale() { return 1.0f; }                          // _64
	virtual void updateCont() { }                                        // _68
	virtual void applyGroundForces(int configIdx, CollGroup* collGroup); // _6C

	void initializeBody();
	void applyCMForce(immut Vector3f& force);

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
	Vector3f mInitPosition;                 ///< _00020, initial position of object.
	Vector3f mInitOrientationX;             ///< _0002C, initial orientation (X axis).
	Vector3f mInitOrientationY;             ///< _00038, initial orientation (Y axis).
	Vector3f mInitOrientationZ;             ///< _00044, initial orientation (Z axis).
	Vector3f mDimensions;                   ///< _00050, dimensions (width, height, depth).
	f32 mMass;                              ///< _0005C, mass.
	f32 mInvMass;                           ///< _00060, inverse mass.
	Matrix3f mInertiaTensor;                ///< _00064, inertia tensor (local space).
	f32 mRestitutionFactor;                 ///< _00088, i.e. bounciness.
	int mBoundingPointCount;                ///< _0008C, number of bounding points.
	int mHookPointCount;                    ///< _00090, number of hook points.
	Vector3f mBodyPoints[0x400];            ///< _00094, local-space points; hook points first, then bounding points.
	int mBoundingPointHitCounts[0x400];     ///< _03094, number of times each bounding point has been hit (for collision processing).
	int mSpringCount;                       ///< _04094, number of springs connected to object.
	WorldSpring mSprings[8];                ///< _04098, array of springs connected to object.
	configuration mIntegrationStates[2];    ///< _04118, prev and current, which swap from frame to frame (i.e. double-buffered simulation).
	Vector3f mLinearAccel;                  ///< _0A230, linear acceleration.
	Vector3f mAngularAccel;                 ///< _0A23C, angular acceleration.
	Vector3f mBufferedBodyPoints[2][0x400]; ///< _0A248, double-buffered points for rendering/interpolation.
	Vector3f mRenderBodyPoints[0x400];      ///< _10248, interpolated hook points for rendering.
	Vector3f mBufferedPositions[2];         ///< _13248, double-buffered positions for rendering.
	Vector3f mRenderPosition;               ///< _13260, interpolated position for rendering.
	Quat mBufferedOrientations[2];          ///< _1326C, double-buffered orientations for rendering.
	Quat mRenderOrientation;                ///< _1328C, interpolated orientation for rendering.
	BoundBox mCollisionBounds;              ///< _1329C, bounding box for collision detection.
};

/**
 * @brief Manages the overall simulation world, including all rigid bodies and the sim state.
 *
 * @note Size: 0x1B0.
 */
struct DynSimulator : public Node {
	DynSimulator()
	    : Node("simulator")
	{
		_unused2C                 = 0;
		mIsPaused                 = FALSE;
		mCurrentRenderBufferIndex = 0;
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
	BOOL mIsPaused;                ///< _20, whether simulation is paused.
	int mCurrentRenderBufferIndex; ///< _24, index for double-buffered rendering.
	int mCurrentConfigIdx;         ///< _28, index for double-buffered simulation state.
	u32 _unused2C;                 ///< _2C, unknown - only ever set to 0.
	CollState mWorldState;         ///< _30, global collision state (largely unused structure).
};

#endif
