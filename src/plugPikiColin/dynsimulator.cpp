#include "DynSimulator.h"
#include "Collision.h"
#include "Matrix3f.h"
#include "Graphics.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("DynSimulator")

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void CollState::resetCollisions(Shape* shape)
{
	mStatus         = 2;
	mShape          = shape;
	mCollisionCount = 0;
	mResetCount++;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
bool CollState::add(Vector3f& normal, Vector3f& contactPt, RigidBody* collider)
{
	if (mCollisionCount < 10) {
		mStatus                                    = 1;
		mCollisions[mCollisionCount].mNormal       = normal;
		mCollisions[mCollisionCount].mContactPoint = contactPt;
		mCollisions[mCollisionCount].mColliderRb   = collider;
		mCollisionCount++;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8004DC00
 * Size:	00030C
 */
void RigidBody::initializeBody()
{
	Vector3f halfExtents(mDimensions.x / 2.0f, mDimensions.y / 2.0f, mDimensions.z / 2.0f);
	mInvMass = 1.0f / mMass;
	mInertiaTensor.identity();
	mInertiaTensor(0, 0) = 3.0f / ((halfExtents.y * halfExtents.y + halfExtents.z * halfExtents.z) * mMass);
	mInertiaTensor(1, 1) = 3.0f / ((halfExtents.x * halfExtents.x + halfExtents.z * halfExtents.z) * mMass);
	mInertiaTensor(2, 2) = 3.0f / ((halfExtents.x * halfExtents.x + halfExtents.y * halfExtents.y) * mMass);
	mRestitutionFactor   = 0.4f;

	for (int i = 0; i < 2; i++) {
		mIntegrationStates[i]._88 = 0;
		mIntegrationStates[i].mOrientationMtx.identity();
		mIntegrationStates[i].mLinearVel.set(0.0f, 0.0f, 0.0f);
		mIntegrationStates[i].mAngularVel.set(0.0f, 0.0f, 0.0f);
		mIntegrationStates[i].mLocalAngularVel.set(0.0f, 0.0f, 0.0f);
		mIntegrationStates[i].mPosition             = mInitPosition;
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
		Vector3f vec2 = mBodyPoints[mSprings[i].mHookIdx] + mInitPosition;
		mSprings[i].mOffset.add(vec2);
	}
}

/*
 * --INFO--
 * Address:	8004DF0C
 * Size:	000004
 */
void RigidBody::initRender(int)
{
}

/*
 * --INFO--
 * Address:	8004DF10
 * Size:	0001BC
 */
void RigidBody::render(Graphics& gfx)
{
	int indices[] = { 0, 1, 1, 5, 5, 4, 4, 0, 2, 3, 3, 7, 7, 6, 6, 2, 0, 2, 1, 3, 5, 7, 4, 6 };
	Matrix4f mtx1;
	mtx1.makeVQS(mRenderPosition, mRenderOrientation, Vector3f(1.0f, 1.0f, 1.0f));
	Matrix4f mtx2;
	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useTexture(nullptr, 0);
	bool lighting = gfx.setLighting(false, nullptr);

	for (int i = 0; i < 24; i += 2) {
		gfx.drawLine(mBodyPoints[indices[i]], mBodyPoints[indices[i + 1]]);
	}

	gfx.drawPoints(mBodyPoints, mBoundingPointCount);
	gfx.setLighting(lighting, nullptr);
}

/*
 * --INFO--
 * Address:	8004E0CC
 * Size:	000050
 */
void RigidBody::applyCMForce(Vector3f& force)
{
	mLinearAccel.x += force.x * mMass;
	mLinearAccel.y += force.y * mMass;
	mLinearAccel.z += force.z * mMass;
}

/*
 * --INFO--
 * Address:	8004E11C
 * Size:	000D90
 */
void RigidBody::integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep)
{
	configuration& prevState = mIntegrationStates[prevConfigIdx];
	configuration& currState = mIntegrationStates[currConfigIdx];

	currState.mPosition = prevState.mPosition + timeStep * prevState.mLinearVel;
	STACK_PAD_INLINE(2);
	currState.mOrientationMtx
	    = prevState.mOrientationMtx + timeStep * Matrix3f(prevState.mAngularVel, Matrix3f::MODE_Unk0) * prevState.mOrientationMtx;
	f32 v                        = timeStep * mInvMass;
	currState.mLinearVel.x       = v * mLinearAccel.x + prevState.mLinearVel.x;
	currState.mLinearVel.y       = v * mLinearAccel.y + prevState.mLinearVel.y;
	currState.mLinearVel.z       = v * mLinearAccel.z + prevState.mLinearVel.z;
	currState.mLocalAngularVel.x = timeStep * mAngularAccel.x + prevState.mLocalAngularVel.x;
	currState.mLocalAngularVel.y = timeStep * mAngularAccel.y + prevState.mLocalAngularVel.y;
	currState.mLocalAngularVel.z = timeStep * mAngularAccel.z + prevState.mLocalAngularVel.z;
	OrthonormaliseOrientation(currState.mOrientationMtx);
	currState.mOrientationQuat.fromMat3f(currState.mOrientationMtx);
	currState.mInertiaTensor = currState.mOrientationMtx * mInertiaTensor * Transpose(currState.mOrientationMtx);
	currState.mAngularVel    = currState.mInertiaTensor * currState.mLocalAngularVel;
	STACK_PAD_TERNARY(prevConfigIdx, 10);
	STACK_PAD_TERNARY(prevConfigIdx, 10);
	STACK_PAD_TERNARY(prevConfigIdx, 5);
}

/*
 * --INFO--
 * Address:	8004EF18
 * Size:	00034C
 */
bool RigidBody::resolveCollisions(int configIdx, Collision& coll)
{
	configuration& config = mIntegrationStates[configIdx];
	Vector3f bodyNormal(coll.mContactPoint.x - config.mPosition.x, coll.mContactPoint.y - config.mPosition.y,
	                    coll.mContactPoint.z - config.mPosition.z);
	Vector3f tangentAngVel = CP(config.mAngularVel, bodyNormal);
	Vector3f totalVel(config.mLinearVel.x + tangentAngVel.x, config.mLinearVel.y + tangentAngVel.y, config.mLinearVel.z + tangentAngVel.z);
	if (coll.mNormal.DP(totalVel) < 0.0f) {
		// objects approaching! collision!
		f32 a          = totalVel.DP(coll.mNormal) * -(mRestitutionFactor + 1.0f);
		f32 b          = CP(config.mInertiaTensor * CP(bodyNormal, coll.mNormal), bodyNormal).DP(coll.mNormal);
		f32 impulseMag = a / (mInvMass + b);
		Vector3f linearImpulse(impulseMag * coll.mNormal.x, impulseMag * coll.mNormal.y, impulseMag * coll.mNormal.z);
		config.mLinearVel.x += mInvMass * linearImpulse.x;
		config.mLinearVel.y += mInvMass * linearImpulse.y;
		config.mLinearVel.z += mInvMass * linearImpulse.z;
		Vector3f angularImpulse = CP(bodyNormal, linearImpulse);
		config.mLocalAngularVel.x += angularImpulse.x;
		config.mLocalAngularVel.y += angularImpulse.y;
		config.mLocalAngularVel.z += angularImpulse.z;
		config.mAngularVel = config.mInertiaTensor * config.mLocalAngularVel;
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8004F264
 * Size:	000398
 */
void RigidBody::applyGroundForces(int configIdx, CollGroup* collGroup)
{
	configuration& config = mIntegrationStates[configIdx];
	for (int i = 0; i < mBoundingPointCount; i++) {
		mBodyPointHitCounts[i] = 0;
	}

	for (int i = 0; i < mBoundingPointCount; i++) {
		Vector3f& bodyPt = config.mBodyPoints[i + mHookPointCount];
		bool skipTriCalc = collGroup ? false : true;
		for (int j = 0; !skipTriCalc && j < collGroup->mTriCount; j++) {
			CollTriInfo* triangle = collGroup->mTriangleList[j];
			Plane* triPlane       = &triangle->mTriangle;
			Vector3f& posCoM      = config.mPosition;
			f32 triPtDist         = triPlane->dist(bodyPt);
			f32 triCoMDist        = triPlane->dist(posCoM);

			if (triPtDist < 0.0f && triCoMDist > 0.0f) {
				// body point is on other side of triangle to CoM - collision!
				f32 ratio = triPtDist / (triPtDist - triCoMDist);
				Vector3f intersectPt((posCoM.x - bodyPt.x) * ratio + bodyPt.x, (posCoM.y - bodyPt.y) * ratio + bodyPt.y,
				                     (posCoM.z - bodyPt.z) * ratio + bodyPt.z);
				STACK_PAD_VAR(1);
				bool insideTri = true;
				for (int k = 0; insideTri && k < 3; k++) {
					if (triangle->mEdgePlanes[k].dist(intersectPt) < 0.0f) {
						insideTri = false;
					}
				}
				if (insideTri) {
					Vector3f bodyNormal = bodyPt - config.mPosition;
					Vector3f tangentVel(config.mAngularVel);
					tangentVel.CP(bodyNormal);
					tangentVel.x += config.mLinearVel.x;
					tangentVel.y += config.mLinearVel.y;
					tangentVel.z += config.mLinearVel.z;
					if (tangentVel.DP(triPlane->mNormal) < 0.0f) {
						mBodyPointHitCounts[i]++;
						Collision coll;
						coll.mContactPoint = intersectPt;
						coll.mNormal       = triPlane->mNormal;
						resolveCollisions(configIdx, coll);
						applyBodyFriction(configIdx, triPlane->mNormal, intersectPt, tangentVel);
					}
				}
			}
		}
	}

	for (int i = 0; i < mBoundingPointCount; i++) {
		if (mBodyPointHitCounts[i] > 1) {
			PRINT("vert %d hit %d times\n", i, mBodyPointHitCounts[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	8004F7B4
 * Size:	0000E0
 */
void RigidBody::updateViewInfo(int p1, int configIdx)
{
	for (int i = 0; i < mBoundingPointCount + mHookPointCount; i++) {
		mBufferedPoints[p1][i] = mIntegrationStates[configIdx].mBodyPoints[i];
	}

	mBufferedPositions[p1]    = mIntegrationStates[configIdx].mPosition;
	mBufferedOrientations[p1] = mIntegrationStates[configIdx].mOrientationQuat;

	makeBodyQuat(mBufferedOrientations[p1]);
}

/*
 * --INFO--
 * Address:	8004F898
 * Size:	0001E8
 */
void RigidBody::updateVecQuats(int p1, f32 p2)
{
	int idx1 = p1;
	int idx2 = p1 ^ 1;

	for (int i = 0; i < mBoundingPointCount + mHookPointCount; i++) {
		mBodySpaceHookPoints[i] = mBufferedPoints[idx1][i] + (mBufferedPoints[idx2][i] - mBufferedPoints[idx1][i]) * p2;
	}

	mRenderPosition    = mBufferedPositions[idx1] + (mBufferedPositions[idx2] - mBufferedPositions[idx1]) * p2;
	mRenderOrientation = mBufferedOrientations[idx1];
	mRenderOrientation.slerp(mBufferedOrientations[idx2], p2, 1);
}

/*
 * --INFO--
 * Address:	8004FA80
 * Size:	00013C
 */
void RigidBody::calculateVertices(int configIdx)
{
	configuration& state  = mIntegrationStates[configIdx];
	configuration& state2 = mIntegrationStates[configIdx]; // why
	Vector3f& pos         = state.mPosition;

	for (int i = 0; i < mBoundingPointCount + mHookPointCount; i++) {
		state2.mBodyPoints[i] = pos + state.mOrientationMtx * mBodyPoints[i];
	}
}

/*
 * --INFO--
 * Address:	8004FBBC
 * Size:	000008
 */
bool RigidBody::checkForCollisions(int, CollState&)
{
	return false;
}

/*
 * --INFO--
 * Address:	8004FBC4
 * Size:	0000B8
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

	mWorldState.mStatus = 2;
}

/*
 * --INFO--
 * Address:	8004FC7C
 * Size:	0001B4
 */
void DynSimulator::doSimulation(f32 p1, f32 p2, Shape* p3)
{
	f32 i;
	f32 dt;
	for (i = p1; i > 0.0f; i -= dt) {
		dt = i;
		if (i > p2) {
			dt = p2;
		}
		if (!isPaused()) {
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
				body->mLinearAccel.set(0.0f, 0.0f, 0.0f);
				body->mAngularAccel.set(0.0f, 0.0f, 0.0f);
			}

			mCurrentConfigIdx ^= 1;
		}
	}

	FOREACH_NODE(RigidBody, mChild, body)
	{
		body->updateViewInfo(mWriteTargetRenderBufferIndex, mCurrentConfigIdx ^ 1);
	}

	mWriteTargetRenderBufferIndex ^= 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void DynSimulator::evolveSimulation(f32, Shape*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void DynSimulator::Integrate(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void DynSimulator::CalculateVertices(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004FF98
 * Size:	00006C
 */
void DynSimulator::updateVecQuats(f32 p1)
{
	for (RigidBody* body = (RigidBody*)mChild; body; body = (RigidBody*)body->Next()) {
		body->updateVecQuats(mWriteTargetRenderBufferIndex, p1);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
int DynSimulator::CheckForCollisions(int, Shape*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void DynSimulator::ResolveCollisions(int)
{
	// UNUSED FUNCTION
}
