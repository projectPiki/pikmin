#include "DynSimulator.h"

#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Matrix3f.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("DynSimulator")

/**
 * @brief Resets (unused) collision state, likely after resolving the previous collision set.
 *
 * @param shape Likely the model/mesh of the owner object.
 * @note UNUSED Size: 000024
 */
void CollState::resetCollisions(Shape* model)
{
	mStatus         = Resolved;
	mModel          = model;
	mCollisionCount = 0;
	mResetCount++;
}

/**
 * @brief Adds a new collision to the collision list.
 *
 * Only adds collision if we're not maxed out (i.e. handling 10 collisions already).
 *
 * @param normal Normal of collision (i.e. collision "direction").
 * @param contactPt Contact point between the two objects.
 * @param collider Colliding body causing the collision.
 * @return `true` always.
 * @note UNUSED Size: 000080
 */
bool CollState::add(immut Vector3f& normal, immut Vector3f& contactPt, RigidBody* collider)
{
	// handles a max of 10 collisions
	if (mCollisionCount < 10) {
		mStatus                                    = PendingCollision;
		mCollisions[mCollisionCount].mNormal       = normal;
		mCollisions[mCollisionCount].mContactPoint = contactPt;
		mCollisions[mCollisionCount].mColliderBody = collider;
		mCollisionCount++;
	}

	return true;
}

/**
 * @brief Initialises the rigid body's physical properties and simulation state.
 */
void RigidBody::initializeBody()
{
	Vector3f halfExtents(mDimensions.x / 2.0f, mDimensions.y / 2.0f, mDimensions.z / 2.0f);
	mInvMass = 1.0f / mMass;

	mInertiaTensor.identity();
	mInertiaTensor(0, 0) = 3.0f / ((halfExtents.y * halfExtents.y + halfExtents.z * halfExtents.z) * mMass);
	mInertiaTensor(1, 1) = 3.0f / ((halfExtents.x * halfExtents.x + halfExtents.z * halfExtents.z) * mMass);
	mInertiaTensor(2, 2) = 3.0f / ((halfExtents.x * halfExtents.x + halfExtents.y * halfExtents.y) * mMass);

	// set (fixed) restitution/bounciness factor
	mRestitutionFactor = 0.4f;

	for (int i = 0; i < 2; i++) {
		mIntegrationStates[i]._unused88 = 0;
		mIntegrationStates[i].mOrientationMtx.identity();

		mIntegrationStates[i].mLinearVel.set(0.0f, 0.0f, 0.0f);
		mIntegrationStates[i].mAngularVel.set(0.0f, 0.0f, 0.0f);
		mIntegrationStates[i].mLocalAngularVel.set(0.0f, 0.0f, 0.0f);

		mIntegrationStates[i].mPosition = mInitPosition;

		mIntegrationStates[i].mOrientationMtx(0, 0) = mInitOrientationX.x;
		mIntegrationStates[i].mOrientationMtx(0, 1) = mInitOrientationX.y;
		mIntegrationStates[i].mOrientationMtx(0, 2) = mInitOrientationX.z;

		mIntegrationStates[i].mOrientationMtx(1, 0) = mInitOrientationY.x;
		mIntegrationStates[i].mOrientationMtx(1, 1) = mInitOrientationY.y;
		mIntegrationStates[i].mOrientationMtx(1, 2) = mInitOrientationY.z;

		mIntegrationStates[i].mOrientationMtx(2, 0) = mInitOrientationZ.x;
		mIntegrationStates[i].mOrientationMtx(2, 1) = mInitOrientationZ.y;
		mIntegrationStates[i].mOrientationMtx(2, 2) = mInitOrientationZ.z;

		mIntegrationStates[i].mOrientationQuat.fromMat3f(mIntegrationStates[i].mOrientationMtx);
		updateViewInfo(i, i);
	}

	for (int i = 0; i < mSpringCount; i++) {
		Vector3f hookWorldPos = mBodyPoints[mSprings[i].mHookIdx] + mInitPosition;
		mSprings[i].mOffset.add(hookWorldPos);
	}
}

/**
 * @brief Performs pre-render steps. Trivial in base class.
 */
void RigidBody::initRender(int)
{
}

/**
 * @brief Renders the rigid body, with a wire frame connecting the 8 bounding vertices.
 *
 * @param gfx Graphics unit performing the rendering.
 */
void RigidBody::render(Graphics& gfx)
{
	int edgeIndices[] = {
		0, 1, 1, 5, 5, 4, 4, 0, // bounding face 1
		2, 3, 3, 7, 7, 6, 6, 2, // bounding face 2
		0, 2, 1, 3, 5, 7, 4, 6, // edges connecting face 1 and face 2
	};

	// transform world space object into view space for rendering
	Matrix4f modelMtx;
	modelMtx.makeVQS(mRenderPosition, mRenderOrientation, Vector3f(1.0f, 1.0f, 1.0f));
	Matrix4f viewMtx;
	gfx.calcViewMatrix(modelMtx, viewMtx);

	// set graphics unit settings
	gfx.useMatrix(viewMtx, 0);
	gfx.setColour(COLOUR_WHITE, true);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	bool lighting = gfx.setLighting(false, nullptr);

	// draw edges of wire bounding frame
	for (int i = 0; i < 24; i += 2) {
		gfx.drawLine(mBodyPoints[edgeIndices[i]], mBodyPoints[edgeIndices[i + 1]]);
	}

	// draw all body points
	gfx.drawPoints(mBodyPoints, mBoundingPointCount);

	// reset graphics unit
	gfx.setLighting(lighting, nullptr);
}

/**
 * @brief Applies a force to the object's center of mass, causing linear acceleration.
 *
 * @bug Uses mass rather than inverse mass for the calculation.
 *
 * @param force Directional force to apply to object's center of mass.
 */
void RigidBody::applyCMForce(immut Vector3f& force)
{
	mLinearAccel.x += force.x * mMass;
	mLinearAccel.y += force.y * mMass;
	mLinearAccel.z += force.z * mMass;
}

/**
 * @brief Performs one integration step for the rigid body's state.
 *
 * Updates positions, orientations, and velocities.
 *
 * @param prevConfigIdx Previous state index in configuration array (to use in calculations).
 * @param currConfigIdx State index for the new configuration (after this time step).
 * @param timeStep Time (delta) to integrate over.
 */
void RigidBody::integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep)
{
	configuration& prevState = mIntegrationStates[prevConfigIdx];
	configuration& currState = mIntegrationStates[currConfigIdx];

	// calculate new position based on linear velocity
	currState.mPosition = prevState.mPosition + timeStep * prevState.mLinearVel;

	STACK_PAD_INLINE(2);

	// calculate new orientation based on angular velocity
	currState.mOrientationMtx
	    = prevState.mOrientationMtx + timeStep * Matrix3f(prevState.mAngularVel, Matrix3f::MODE_Unk0) * prevState.mOrientationMtx;

	// calculate new linear and angular velocities based on accelerations
	f32 invMassDt          = timeStep * mInvMass;
	currState.mLinearVel.x = invMassDt * mLinearAccel.x + prevState.mLinearVel.x;
	currState.mLinearVel.y = invMassDt * mLinearAccel.y + prevState.mLinearVel.y;
	currState.mLinearVel.z = invMassDt * mLinearAccel.z + prevState.mLinearVel.z;

	currState.mLocalAngularVel.x = timeStep * mAngularAccel.x + prevState.mLocalAngularVel.x;
	currState.mLocalAngularVel.y = timeStep * mAngularAccel.y + prevState.mLocalAngularVel.y;
	currState.mLocalAngularVel.z = timeStep * mAngularAccel.z + prevState.mLocalAngularVel.z;

	// normalise orientation and re-calculate angular properties
	OrthonormaliseOrientation(currState.mOrientationMtx);

	currState.mOrientationQuat.fromMat3f(currState.mOrientationMtx);
	currState.mInertiaTensor = currState.mOrientationMtx * mInertiaTensor * Transpose(currState.mOrientationMtx);
	currState.mAngularVel    = currState.mInertiaTensor * currState.mLocalAngularVel;

	STACK_PAD_TERNARY(prevConfigIdx, 10);
	STACK_PAD_TERNARY(prevConfigIdx, 10);
	STACK_PAD_TERNARY(prevConfigIdx, 5);
}

/**
 * @brief Resolve a single collision by applying impulses.
 *
 * @param configIdx Current configuration state index.
 * @param coll Collision to resolve.
 * @return `true` if objects collided, `false` otherwise.
 */
bool RigidBody::resolveCollisions(int configIdx, Collision& coll)
{
	configuration& config = mIntegrationStates[configIdx];

	// calculate `r` (in physics terms) - center of mass to contact point
	Vector3f contactOffset(coll.mContactPoint.x - config.mPosition.x, coll.mContactPoint.y - config.mPosition.y,
	                       coll.mContactPoint.z - config.mPosition.z);

	// calculate velocities at this point, both angular and total
	Vector3f contactAngularVel = CP(config.mAngularVel, contactOffset);
	Vector3f contactVel(config.mLinearVel.x + contactAngularVel.x, config.mLinearVel.y + contactAngularVel.y,
	                    config.mLinearVel.z + contactAngularVel.z);

	// check if objects are moving toward each other along the collision normal
	if (coll.mNormal.DP(contactVel) < 0.0f) {
		// objects approaching! collision! calculate impulse
		f32 bounceFactor  = contactVel.DP(coll.mNormal) * -(mRestitutionFactor + 1.0f);
		f32 inertiaFactor = CP(config.mInertiaTensor * CP(contactOffset, coll.mNormal), contactOffset).DP(coll.mNormal);
		f32 impulseMag    = bounceFactor / (mInvMass + inertiaFactor);

		// apply linear impulse
		Vector3f linearImpulse(impulseMag * coll.mNormal.x, impulseMag * coll.mNormal.y, impulseMag * coll.mNormal.z);
		config.mLinearVel.x += mInvMass * linearImpulse.x;
		config.mLinearVel.y += mInvMass * linearImpulse.y;
		config.mLinearVel.z += mInvMass * linearImpulse.z;

		// apply angular impulse
		Vector3f angularImpulse = CP(contactOffset, linearImpulse);
		config.mLocalAngularVel.x += angularImpulse.x;
		config.mLocalAngularVel.y += angularImpulse.y;
		config.mLocalAngularVel.z += angularImpulse.z;
		config.mAngularVel = config.mInertiaTensor * config.mLocalAngularVel;
		return true;
	}

	return false;
}

/**
 * @brief Checks for collisions between bottom bounding points and ground triangles, and resolves them.
 *
 * @param configIdx Current configuration state index.
 * @param collGroup Triangle information for current collision group ("room").
 */
void RigidBody::applyGroundForces(int configIdx, CollGroup* collGroup)
{
	configuration& config = mIntegrationStates[configIdx];

	// reset all bounding point hit counts
	for (int i = 0; i < mBoundingPointCount; i++) {
		mBoundingPointHitCounts[i] = 0;
	}

	// check for ground collision for each bounding point
	for (int i = 0; i < mBoundingPointCount; i++) {
		immut Vector3f& boundingPtPos = config.mBodyPoints[i + mHookPointCount];

		// only do collision calculations if we have collision triangles to check
		// (weird way to do this check but fine)
		bool skipCollCalc = collGroup ? false : true;

		// check each supplied triangle for a collision
		for (int j = 0; !skipCollCalc && j < collGroup->mTriCount; j++) {
			CollTriInfo* triangle  = collGroup->mTriangleList[j];
			Plane* triPlane        = &triangle->mTriangle;
			immut Vector3f& comPos = config.mPosition;

			f32 boundingPtDist = triPlane->dist(boundingPtPos);
			f32 comDist        = triPlane->dist(comPos);

			// if bounding point is "below" the ground and center of mass if "above" the ground, we're colliding
			if (boundingPtDist < 0.0f && comDist > 0.0f) {
				// calc intersection point between object line (CoM to bounding point) and triangle plane
				f32 intersectRatio = boundingPtDist / (boundingPtDist - comDist);
				Vector3f intersectPt((comPos.x - boundingPtPos.x) * intersectRatio + boundingPtPos.x,
				                     (comPos.y - boundingPtPos.y) * intersectRatio + boundingPtPos.y,
				                     (comPos.z - boundingPtPos.z) * intersectRatio + boundingPtPos.z);

				STACK_PAD_VAR(1);

				// check if intersection point is inside the triangle
				bool isInsideTri = true;
				for (int k = 0; isInsideTri && k < 3; k++) {
					if (triangle->mEdgePlanes[k].dist(intersectPt) < 0.0f) {
						isInsideTri = false;
					}
				}

				if (isInsideTri) {
					// compute (linear + angular) velocity at bounding point
					Vector3f offsetToBoundingPt = boundingPtPos - config.mPosition;
					Vector3f boundingPtVel(config.mAngularVel);
					boundingPtVel.CP(offsetToBoundingPt);
					boundingPtVel.x += config.mLinearVel.x;
					boundingPtVel.y += config.mLinearVel.y;
					boundingPtVel.z += config.mLinearVel.z;

					// if we're moving toward the triangle, apply collision response and friction
					if (boundingPtVel.DP(triPlane->mNormal) < 0.0f) {
						mBoundingPointHitCounts[i]++;
						Collision coll;
						coll.mContactPoint = intersectPt;
						coll.mNormal       = triPlane->mNormal;
						resolveCollisions(configIdx, coll);
						applyBodyFriction(configIdx, triPlane->mNormal, intersectPt, boundingPtVel);
					}
				}
			}
		}
	}

	// debug print to check if any bounding points have gotten hit more than once
	for (int i = 0; i < mBoundingPointCount; i++) {
		if (mBoundingPointHitCounts[i] > 1) {
			PRINT("vert %d hit %d times\n", i, mBoundingPointHitCounts[i]);
		}
	}
}

/**
 * @brief Updates buffered points, positions and orientations for rendering.
 *
 * @param targetBufferIdx Render buffer index to store info into for next render.
 * @param srcConfigIdx Latest configuration state index to get info from.
 */
void RigidBody::updateViewInfo(int targetBufferIdx, int srcConfigIdx)
{
	for (int i = 0; i < mBoundingPointCount + mHookPointCount; i++) {
		mBufferedBodyPoints[targetBufferIdx][i] = mIntegrationStates[srcConfigIdx].mBodyPoints[i];
	}

	mBufferedPositions[targetBufferIdx]    = mIntegrationStates[srcConfigIdx].mPosition;
	mBufferedOrientations[targetBufferIdx] = mIntegrationStates[srcConfigIdx].mOrientationQuat;
	makeBodyQuat(mBufferedOrientations[targetBufferIdx]);
}

/**
 * @brief Interpolates rendering information between previous buffer and current buffer.
 *
 * @param renderBufferIndex Render buffer index for current render.
 * @param interpFactor How far to interpolate between previous render and new render (1 to 0).
 */
void RigidBody::updateVecQuats(int renderBufferIndex, f32 interpFactor)
{
	int renderIdx = renderBufferIndex;     // for current render info
	int prevIdx   = renderBufferIndex ^ 1; // for render info from previous frame

	// interpolate all body points
	for (int i = 0; i < mBoundingPointCount + mHookPointCount; i++) {
		mRenderBodyPoints[i]
		    = mBufferedBodyPoints[renderIdx][i] + (mBufferedBodyPoints[prevIdx][i] - mBufferedBodyPoints[renderIdx][i]) * interpFactor;
	}

	// interpolate position and orientation
	mRenderPosition    = mBufferedPositions[renderIdx] + (mBufferedPositions[prevIdx] - mBufferedPositions[renderIdx]) * interpFactor;
	mRenderOrientation = mBufferedOrientations[renderIdx];
	mRenderOrientation.slerp(mBufferedOrientations[prevIdx], interpFactor, 1);
}

/**
 * @brief Transforms local body points to world space for the given configuration.
 *
 * @param configIdx Configuration state index of points to transform.
 */
void RigidBody::calculateVertices(int configIdx)
{
	configuration& preState  = mIntegrationStates[configIdx];
	configuration& postState = mIntegrationStates[configIdx]; // why do this when these are references?

	immut Vector3f& pos = preState.mPosition;

	// transform all body points
	for (int i = 0; i < mBoundingPointCount + mHookPointCount; i++) {
		postState.mBodyPoints[i] = pos + preState.mOrientationMtx * mBodyPoints[i];
	}
}

/**
 * @brief Stubbed function with no overrides. Unknown parameters.
 *
 * @return `false` always.
 */
bool RigidBody::checkForCollisions(int, CollState&)
{
	return false;
}

/**
 * @brief Resets the simulation world and all rigid bodies to their initial state.
 *
 * Also performs one initial integration step for each body so we have a "previous" state to work from.
 */
void DynSimulator::resetWorld()
{
	mCurrentConfigIdx = 0;
	FOREACH_NODE(RigidBody, mChild, body)
	{
		body->initializeBody();
		for (int i = 0; i < 2; i++) {
			body->integrate(mCurrentConfigIdx, mCurrentConfigIdx ^ 1, 0.0f);
			body->calculateVertices(mCurrentConfigIdx);
			mCurrentConfigIdx ^= 1;
		}
	}

	mWorldState.mStatus = CollState::Resolved;
}

/**
 * @brief Simulates world for given total time, using capped time steps.
 *
 * Steps through `totalTime` amount of simulation, in steps of `maxTimeStep`
 * (or smaller for the final remainder, if `totalTime` is not a multiple of `maxTimeStep`).
 *
 * @param totalTime Total time to run the simulation for (sec).
 * @param maxTimeStep Max time between individual calculation steps (sec).
 * @param mapModel Map model for world being simulated (unused).
 */
void DynSimulator::doSimulation(f32 totalTime, f32 maxTimeStep, Shape* mapModel)
{
	f32 remainingTime, dt;
	for (remainingTime = totalTime; remainingTime > 0.0f; remainingTime -= dt) {
		dt = remainingTime;
		if (remainingTime > maxTimeStep) {
			dt = maxTimeStep;
		}
		if (!isPaused()) {
			// simulation steps:
			// 1. initialise all collisions
			// 2. compute all forces
			// 3. integrate all bodies over dt amount of time
			// 4. calculate all vertices
			// 5. reset accelerations

			FOREACH_NODE(RigidBody, mChild, body)
			{
				body->initCollisions(mCurrentConfigIdx);
			}
			FOREACH_NODE(RigidBody, mChild, body)
			{
				body->computeForces(mCurrentConfigIdx, dt);
			}
			FOREACH_NODE(RigidBody, mChild, body)
			{
				body->integrate(mCurrentConfigIdx, mCurrentConfigIdx ^ 1, dt);
				body->calculateVertices(mCurrentConfigIdx ^ 1);

				// reset accelerations
				body->mLinearAccel.set(0.0f, 0.0f, 0.0f);
				body->mAngularAccel.set(0.0f, 0.0f, 0.0f);
			}

			// advance config state to use for next calculations
			mCurrentConfigIdx ^= 1;
		}
	}

	FOREACH_NODE(RigidBody, mChild, body)
	{
		// update render info with the new config state (toggle back because we advanced it above)
		body->updateViewInfo(mCurrentRenderBufferIndex, mCurrentConfigIdx ^ 1);
	}

	// advance render buffer
	mCurrentRenderBufferIndex ^= 1;
}

/**
 * @brief Steps the simulation forward in time by only integrating and updating vertices. Completely unused.
 *
 * @bug Only evaluates once, likely had a variable factor to control step size that got removed.
 *
 * @param totalTime Total time to evolve simulation for.
 * @param mapModel Map model for simulation (unused).
 * @note UNUSED Size: 000094
 */
void DynSimulator::evolveSimulation(f32 totalTime, Shape* mapModel)
{
	f32 currentTime = 0.0f;
	f32 nextTime    = totalTime;
	int stepCount   = 0;

	while (currentTime < totalTime) {
		Integrate(nextTime - currentTime);
		CalculateVertices(mCurrentConfigIdx ^ 1);
		currentTime = nextTime;
		nextTime    = totalTime;
		mCurrentConfigIdx ^= 1;
		stepCount++;
		if (stepCount > 1500) {
			PRINT("too many iterations");
			mIsPaused = TRUE;
			return;
		}
	}
}

/**
 * @brief Integrates all rigid bodies over the given time step. Completely unused.
 *
 * @param timeStep Time (delta) to integrate all rigid bodies over.
 * @note UNUSED Size: 000070
 */
void DynSimulator::Integrate(f32 timeStep)
{
	for (RigidBody* body = (RigidBody*)mChild; body; body = (RigidBody*)body->Next()) {
		body->integrate(mCurrentConfigIdx, mCurrentConfigIdx ^ 1, timeStep);
	}
}

/**
 * @brief Converts vertices of all rigid bodies from local to world space. Completely unused.
 *
 * @param configIdx Configuration state index to transform info for.
 * @note UNUSED Size: 00005C
 */
void DynSimulator::CalculateVertices(int configIdx)
{
	for (RigidBody* body = (RigidBody*)mChild; body; body = (RigidBody*)body->Next()) {
		body->calculateVertices(configIdx);
	}
}

/**
 * @brief Updates the rendering information for all rigid bodies in the simulation.
 *
 * @param interpFactor Interpolation factor between previous and current render state (1 to 0).
 */
void DynSimulator::updateVecQuats(f32 interpFactor)
{
	for (RigidBody* body = (RigidBody*)mChild; body; body = (RigidBody*)body->Next()) {
		body->updateVecQuats(mCurrentRenderBufferIndex, interpFactor);
	}
}

/**
 * @brief Resets world state and "checks" for collisions against all bodies. Completely unused.
 *
 * Called collision checking function is trivial and has no overrides, so never checks anything.
 *
 * @param configIdx Current configuration state index.
 * @param model Map model.
 * @return Status of world collision state (see `CollState::Status` enum).
 * @note UNUSED Size: 00009C
 */
int DynSimulator::CheckForCollisions(int configIdx, Shape* model)
{
	mWorldState.resetCollisions(model);
	for (RigidBody* body = (RigidBody*)mChild; body; body = (RigidBody*)body->Next()) {
		body->checkForCollisions(configIdx, mWorldState);
		if (mWorldState.mStatus == CollState::Unk0) {
			// unsure what this status would've been - maybe collision buffer filled, or some trigger hit to evaluate them all?
			break;
		}
	}

	return mWorldState.mStatus;
}

/**
 * @brief Attempts to resolve all collisions stored by the world state. Completely unused.
 *
 * Iterates until all collisions are resolved, or 100 iterations are reached.
 *
 * @param configIdx Current configuration state index.
 * @note UNUSED Size: 000090
 */
void DynSimulator::ResolveCollisions(int configIdx)
{
	bool collisionsRemaining;
	int maxColls = 100;
	do {
		collisionsRemaining = false;
		for (int i = 0; i < mWorldState.mCollisionCount; i++) {
			if (mWorldState.mCollisions[i].mColliderBody->resolveCollisions(configIdx, mWorldState.mCollisions[i])) {
				collisionsRemaining = true;
			}
		}
		maxColls--;
	} while (maxColls != 0 && collisionsRemaining);
}
