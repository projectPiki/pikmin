#include "MapMgr.h"

#include "AIPerf.h"
#include "Creature.h"
#include "CreatureCollPart.h"
#include "CreatureProp.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "DynColl.h"
#include "DynObject.h"
#include "EffectMgr.h"
#include "FlowController.h"
#include "Font.h"
#include "Graphics.h"
#include "MapParts.h"
#include "MemStat.h"
#include "MoviePlayer.h"
#include "gameflow.h"
#include "sysMath.h"
#include "sysNew.h"
#include "timers.h"

//////////////////////////////////////////////////////
//////////////// FORWARD DECLARATIONS ////////////////
//////////////////////////////////////////////////////
#pragma region DECLARATIONS

struct SoftLightAccumulator;

//////////////////////////////////////////////////////
//////////////// PRINT/ERROR DEFINES /////////////////
//////////////////////////////////////////////////////

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("mapMgr")

//////////////////////////////////////////////////////
///////////////// GLOBAL MAP MANAGER /////////////////
//////////////////////////////////////////////////////

/// Global manager for the current map, handling model, collisions, rendering, etc.
MapMgr* mapMgr;

#pragma endregion
//////////////////////////////////////////////////////
///////////////// DYNAMIC COLLISION //////////////////
//////////////////////////////////////////////////////
#pragma region DYNAMIC COLLISION

/**
 * @brief Duplicates vertex and triangle data from model, and sets up collision groups.
 */
void DynCollShape::createDupCollData()
{
	// dupe vertices
	mVertexList = new Vector3f[mCollisionModel->mVertexCount];
	memcpy(mVertexList, mCollisionModel->mVertexList, mCollisionModel->mVertexCount * sizeof(Vector3f));

	// dupe collision triangles
	mCollTriList = new CollTriInfo[mCollisionModel->mTriCount];
	memcpy(mCollTriList, mCollisionModel->mTriList, mCollisionModel->mTriCount * sizeof(CollTriInfo));

	mCollGroupList = nullptr;

	// dupe joint visibility information
	mJointVisibility = new bool[mCollisionModel->mJointCount];
	for (int i = 0; i < mCollisionModel->mJointCount; i++) {
		mJointVisibility[i] = mCollisionModel->mJointList[i].mVisibilityFlag != Joint::NotVisible;
	}

	// almost every model should have at least 1 "room" (group of collision)
	if (mCollisionModel->mBaseRoomCount <= 0) {
		return;
	}

	mCollGroupCount = mCollisionModel->mBaseRoomCount;
	mCollGroupList  = new CollGroup*[mCollGroupCount];

	// the only common objects that have more than 1 group are bridges (short have 12, long have 30 - 2 groups per stage)
	for (int i = 0; i < mCollisionModel->mBaseRoomCount; i++) {
		int triCount = 0;
		for (int j = 0; j < mCollisionModel->mTriCount; j++) {
			if (i == mCollTriList[j].mCollRoomIndex) {
				triCount++;
			}
		}

		mCollGroupList[i]                = new CollGroup;
		mCollGroupList[i]->mJointIndex   = mCollisionModel->mRoomInfoList[i].mJointIndex;
		mCollGroupList[i]->mTriCount     = triCount;
		mCollGroupList[i]->mTriangleList = new CollTriInfo*[mCollGroupList[i]->mTriCount];

		// populate triangle list
		int triIdx = 0;
		for (int j = 0; j < mCollisionModel->mTriCount; j++) {
			if (mCollTriList[j].mCollRoomIndex == i) {
				mCollGroupList[i]->mTriangleList[triIdx] = &mCollTriList[j];
				triIdx++;
			}
		}
	}
}

/**
 * @brief Draws the vertices and edges of the triangles comprising the object's collision model.
 *
 * @param gfx Graphics context for rendering.
 * @note UNUSED Size: 0001FC
 */
void DynCollShape::drawAtari(Graphics& gfx)
{
	gfx.setCamera(gfx.mCamera);
	gfx.initRender(0, 0);

	// draw vertices for each triangle
	gfx.setColour(Colour(255, 255, 0, 255), true); // bright yellow
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setPointSize(4.0f);
	gfx.drawPoints(mVertexList, mCollisionModel->mVertexCount);

	gfx.setColour(Colour(255, 0, 0, 255), true); // red
	for (int i = 0; i < mCollisionModel->mTriCount; i++) {
		// draw edges for each triangle
		for (int j = 0; j < 3; j++) {
			int k = (j + 1) % 3; // next vertex mod 3
			Vector3f start(mVertexList[mCollTriList[i].mVertexIndices[j]]);
			Vector3f end(mVertexList[mCollTriList[i].mVertexIndices[k]]);
			gfx.drawLine(start, end);
		}
	}
}

/**
 * @brief Transforms all vertices and triangle normals to world space and updates the bounding box.
 */
void DynCollShape::updatePos()
{
	// shrink box back down so it can be a minimum bound
	mBoundingBox.resetBound();
	// transform all vertices
	for (int i = 0; i < mCollisionModel->mVertexCount; i++) {
		mVertexList[i].x = mTransformMtx.mMtx[0][0] * mCollisionModel->mVertexList[i].x
		                 + mTransformMtx.mMtx[0][1] * mCollisionModel->mVertexList[i].y
		                 + mTransformMtx.mMtx[0][2] * mCollisionModel->mVertexList[i].z + mTransformMtx.mMtx[0][3];
		mVertexList[i].y = mTransformMtx.mMtx[1][0] * mCollisionModel->mVertexList[i].x
		                 + mTransformMtx.mMtx[1][1] * mCollisionModel->mVertexList[i].y
		                 + mTransformMtx.mMtx[1][2] * mCollisionModel->mVertexList[i].z + mTransformMtx.mMtx[1][3];
		mVertexList[i].z = mTransformMtx.mMtx[2][0] * mCollisionModel->mVertexList[i].x
		                 + mTransformMtx.mMtx[2][1] * mCollisionModel->mVertexList[i].y
		                 + mTransformMtx.mMtx[2][2] * mCollisionModel->mVertexList[i].z + mTransformMtx.mMtx[2][3];
		mBoundingBox.expandBound(mVertexList[i]);
	}

	// transform normals (and edge plane normals)
	for (int i = 0; i < mCollisionModel->mTriCount; i++) {
		mCollisionModel->mTriList[i].mTriangle.mNormal.rotateTo(mTransformMtx, mCollTriList[i].mTriangle.mNormal);
		mCollTriList[i].mTriangle.mNormal.normalise();
		mCollTriList[i].mTriangle.mOffset = mCollTriList[i].mTriangle.mNormal.DP(mVertexList[mCollTriList[i].mVertexIndices[0]]);
		for (int j = 0; j < 3; j++) {
			mCollisionModel->mTriList[i].mEdgePlanes[j].mNormal.rotateTo(mTransformMtx, mCollTriList[i].mEdgePlanes[j].mNormal);
			mCollTriList[i].mEdgePlanes[j].mNormal.normalise();
			mCollTriList[i].mEdgePlanes[j].mOffset
			    = mCollTriList[i].mEdgePlanes[j].mNormal.DP(mVertexList[mCollTriList[i].mVertexIndices[j]]);
		}
	}
}

/**
 * @brief Sets the visibility flag for all sibling joints to the given joint.
 *
 * @param jointIdx Index of the joint to update, along with its siblings (children of the same parent).
 * @param visFlag Visibility flag to set - see `Joint::VisibilityFlags` enum.
 */
void DynCollShape::jointVisible(int jointIdx, int visFlag)
{
	FOREACH_NODE(Joint, mCollisionModel->mJointList[jointIdx].mParent->mChild, joint)
	{
		mJointVisibility[joint->mIndex] = visFlag != Joint::NotVisible;
	}
}

/**
 * @brief Transforms the given creature's position along with the shape, in order to keep its relative position constant.
 *
 * Basically, keeps the creature "attached". Transforms using the shape's local space.
 *
 * @param creature Creature to adjust the position of (i.e. the creature to keep attached to this object).
 */
void DynCollShape::adjust(Creature* creature)
{
	creature->mCollAttachment.mCollSpacePosition = creature->mSRT.t;
	creature->mCollAttachment.mCollSpacePosition.multMatrix(mInverseMatrix);
	creature->mSRT.t = creature->mCollAttachment.mCollSpacePosition;
	creature->mSRT.t.multMatrix(mTransformMtx);
	creature->mLastPosition = creature->mSRT.t;
}

/**
 * @brief Updates the object's local space transformation matrices.
 */
void DynCollShape::update()
{
	mTransformMtx.inverse(&mInverseMatrix);
	mTransformMtx.makeSRT(mLocalSRT.s, mLocalSRT.r, mLocalSRT.t);
}

/**
 * @brief Synchronises joint visiblity flags between the object and its collision model.
 */
void DynCollShape::updateContext()
{
	for (int i = 0; i < mCollisionModel->mJointCount; i++) {
		mCollisionModel->mJointList[i].mVisibilityFlag = mJointVisibility[i];
	}
}

/**
 * @brief Draws the collision model.
 *
 * @param gfx Graphics context for rendering.
 */
void DynCollShape::refresh(Graphics& gfx)
{
	updateContext();
	mCollisionModel->drawshape(gfx, *gfx.mCamera, nullptr);
}

#pragma endregion
//////////////////////////////////////////////////////
//////////////// DYNAMIC MAP OBJECTS /////////////////
//////////////////////////////////////////////////////
#pragma region MAP OBJECTS

/**
 * @brief Ends a one-shot animation and advances the connected map object's state.
 */
void MapObjAnimator::finishOneShot()
{
	mPlayState = ANIMSTATE_Inactive;

	if (mMapObj) {
		mMapObj->nextState();
	}

	PRINT("%08x : finished animation : %f!!\n", this, mAnimationCounter);
}

/**
 * @brief Constructs a dynamic map object on the given map, with given animations and model.
 *
 * @param map Manager for map this object is on.
 * @param shapeObj Model wrapper containing animation info for object.
 * @note UNUSED Size: 000364
 */
DynMapObject::DynMapObject(MapMgr* map, MapAnimShapeObject* shapeObj)
    : DynCollShape(shapeObj->mModel)
{
	mShapeObject      = shapeObj;
	mCollisionModel   = mShapeObject->mModel;
	mAnimator.mMapObj = this;
	mAnimator.init(&mShapeObject->mAnimContext, mShapeObject->mMgr);
	mAnimator.startAnim(ANIMSTATE_Inactive, MAPANIM_Unk0, 0, 8);

	mState  = STATE_Unk0;
	mMapMgr = map;

	// never added to the global draw list, so never used
	mShadowCaster.initCore("");
	mShadowCaster.mShadowDrawer     = this;
	mShadowCaster.mLightCamera.mFov = 20.0f;

	mSRT.s.set(1.0f, 1.0f, 1.0f);
	mSRT.r.set(0.0f, 0.0f, 0.0f);
	mSRT.t.set(0.0f, 0.0f, 0.0f);

	mPlatObjCount = 0;
	for (ObjCollInfo* info = (ObjCollInfo*)mCollisionModel->mCollisionInfo.mParentShape->Child(); info; info = (ObjCollInfo*)info->mNext) {
		if (info->mPlatShape) {
			mPlatObjCount++;
		}
	}

	mPlatObjects = new MapObjectPart*[mPlatObjCount];
	int i        = 0;
	for (ObjCollInfo* info = (ObjCollInfo*)mCollisionModel->mCollisionInfo.mParentShape->Child(); info; info = (ObjCollInfo*)info->mNext) {
		if (info->mPlatShape) {
			MapObjectPart* part = new MapObjectPart(info->mPlatShape);
			part->mParentObject = this;
			part->mJointIndex   = info->mJointIndex;
			mMapMgr->mCollShapeList->add(part);
			mPlatObjects[i] = part;
			i++;
		}
	}
}

/**
 * @brief Increments the object's state, keeping it looped within the valid state range (0-5).
 */
void DynMapObject::nextState()
{
	mState++;
	if (mState == STATE_COUNT) {
		mState = STATE_Unk0;
	}
}

/**
 * @brief Updates object's state and transition timer if touched. Parameters unused.
 */
void DynMapObject::touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&)
{
	switch (mState) {
	case STATE_Unk0:
	{
		mTransitionTimer = 2.0f;
		mState++;
		break;
	}
	case STATE_Unk4:
	{
		mTransitionTimer = 2.0f;
		break;
	}
	}
}

/**
 * @brief Updates the object's animation and shadow based on its current state.
 */
void DynMapObject::update()
{
	switch (mState) {
	case STATE_Unk1:
	{
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer < 0.0f) {
			mTransitionTimer = 2.0f;
			mAnimator.startAnim(ANIMSTATE_OneShot, MAPANIM_Unk0, 0, 8);
			mState++;
		}
		break;
	}
	case STATE_Unk3:
	{
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer < 0.0f) {
			mTransitionTimer = 0.0f;
			mState++;
		}
		break;
	}
	case STATE_Unk4:
	{
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer < 0.0f) {
			mTransitionTimer = 0.0f;
			mAnimator.startAnim(ANIMSTATE_OneShot, MAPANIM_Unk1, 0, 8);
			mState++;
		}
		break;
	}
	default:
	{
		break;
	}
	}

	mShadowCaster.mSourcePosition.set(mSRT.t.x + 100.0f, mSRT.t.y + 300.0f, mSRT.t.z + 300.0f);
	mShadowCaster.mTargetPosition.set(mSRT.t.x, mSRT.t.y + 100.0f, mSRT.t.z);
	mAnimator.animate(30.0f);
	DynCollShape::update();
}

/**
 * @brief Draws the object for the current frame. Just calls `DynMapObject::refresh`.
 *
 * @param gfx Graphics context for rendering.
 */
void DynMapObject::draw(Graphics& gfx)
{
	refresh(gfx);
}

/**
 * @brief Renders the object for the current frame, including updating its sub-parts.
 *
 * @param gfx Graphics context for rendering.
 */
void DynMapObject::refresh(Graphics& gfx)
{
	Matrix4f transformMtx;
	Matrix4f viewMtx;
	transformMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	gfx.calcViewMatrix(transformMtx, viewMtx);

	// update animation
	gsys->mTimer->start("animation", true);
	mAnimator.updateContext();
	mShapeObject->mModel->updateAnim(gfx, viewMtx, nullptr);
	gsys->mTimer->stop("animation");

	// update sub-parts
	for (int i = 0; i < mPlatObjCount; i++) {
		MapObjectPart* part = mPlatObjects[i];
		part->mTransformMtx.inverse(&part->mInverseMatrix);
		Matrix4f animMtx = mCollisionModel->getAnimMatrix(part->mJointIndex);
		gfx.mCamera->mInverseLookAtMtx.multiplyTo(animMtx, part->mTransformMtx);
	}

	gfx.useMatrix(Matrix4f::ident, 0);

	// draw the object's model
	mCollisionModel->drawshape(gfx, *gfx.mCamera, nullptr);
}

#pragma endregion
//////////////////////////////////////////////////////
//////////////// DYNAMIC RIGID BODIES ////////////////
//////////////////////////////////////////////////////
#pragma region RIGID BODIES

static f32 Kdl = 1.25f;
static f32 Kda = 0.0f;

/**
 * @brief Directs any contact callbacks to the rigid body for more robust physics calculations.
 *
 * @param contactPlane Plane of collision.
 * @param contactPos Contact position of collision.
 * @param colliderVel Velocity of colliding object.
 */
void DynCollObjBody::touchCallback(immut Plane& contactPlane, immut Vector3f& contactPos, immut Vector3f& colliderVel)
{
	mRigidBody->touchCallback(contactPlane, contactPos, colliderVel);
}

/**
 * @brief Directs any incoming velocity callbacks to the rigid body for more robust physics calculations.
 *
 * @param contactPlane Contact plane of collision.
 * @param contactPos Contact position of collision.
 * @param velocity Velocity to apply to object.
 */
void DynCollObjBody::applyVelocity(immut Plane& contactPlane, immut Vector3f& contactPos, immut Vector3f& velocity)
{
	mRigidBody->applyVelocity(contactPlane, contactPos, velocity);
}

/**
 * @brief Handles a contact/collision event by applying a force to the object (if the collision is directed towards it).
 *
 * @param contactPlane Plane of collision.
 * @param contactPos Contact position of collision.
 * @param colliderVel Velocity of colliding object.
 */
void DynObjBody::touchCallback(immut Plane& contactPlane, immut Vector3f& contactPos, immut Vector3f& colliderVel)
{
	// touch has to be toward an object, can't be glancing off it
	if (contactPlane.mNormal.DP(colliderVel) < 0.0f) {
		// get response vector based on how direct the collision is, how high the speed, and the collision triangle
		Vector3f force = contactPlane.mNormal.DP(colliderVel) * contactPlane.mNormal;
		force.multiply(mImpactForceScale);
		// yes, these are necessary
		applyForce(0, Vector3f(force.x, force.y, force.z), Vector3f(contactPos.x, contactPos.y, contactPos.z));
	}
}

/**
 * @brief Applies a velocity-based force to the object (if the collision is directed towards it).
 *
 * In practice, this operates the same way as a collision via `touchCallback`.
 *
 * @param contactPlane Contact plane of collision.
 * @param contactPos Contact position of collision.
 * @param velocity Velocity to apply to object.
 */
void DynObjBody::applyVelocity(immut Plane& contactPlane, immut Vector3f& contactPos, immut Vector3f& velocity)
{
	// have to be applying toward an object, can't be glancing off it
	if (contactPlane.mNormal.DP(velocity) < 0.0f) {
		// get response vector based on how direct the collision is, how high the speed, and the collision triangle
		Vector3f force = contactPlane.mNormal.DP(velocity) * contactPlane.mNormal;
		force.multiply(mImpactForceScale);
		// yes, these are (also) necessary
		applyForce(0, Vector3f(force.x, force.y, force.z), Vector3f(contactPos.x, contactPos.y, contactPos.z));
	}
}

/**
 * @brief Advances the physics simulation of the object by one time step, taking into account movement restrictions.
 *
 * @param prevConfigIdx Previous state index in configuration array (to use in calculations).
 * @param currConfigIdx State index for the new configuration (after this time step).
 * @param timeStep Time (delta) to integrate over.
 */
void DynObjBody::integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep)
{
	// process base-level physics simulation
	RigidBody::integrate(prevConfigIdx, currConfigIdx, timeStep);

	// apply movement restrictions on axes (both linear or angular)
	configuration& config = mIntegrationStates[currConfigIdx];
	config.mLinearVel.set(config.mLinearVel.x * mLinearVelMask.x, config.mLinearVel.y * mLinearVelMask.y,
	                      config.mLinearVel.z * mLinearVelMask.z);
	config.mLocalAngularVel.set(config.mLocalAngularVel.x * mAngularVelMask.x, config.mLocalAngularVel.y * mAngularVelMask.y,
	                            config.mLocalAngularVel.z * mAngularVelMask.z);

	// re-fix orientation and inertia tensor
	OrthonormaliseOrientation(config.mOrientationMtx);
	config.mOrientationQuat.fromMat3f(config.mOrientationMtx);

	config.mInertiaTensor = config.mOrientationMtx * mInertiaTensor * Transpose(config.mOrientationMtx);
	config.mAngularVel    = config.mInertiaTensor * config.mLocalAngularVel;
}

/**
 * @brief Advances the physics simulation of the object by one time step, using a constaint-space-based setup for direction restrictions.
 *
 * @param prevConfigIdx Previous state index in configuration array (to use in calculations).
 * @param currConfigIdx State index for the new configuration (after this time step).
 * @param timeStep Time (delta) to integrate over.
 */
void DynObjSeeSaw::integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep)
{
	RigidBody::integrate(prevConfigIdx, currConfigIdx, timeStep);
	configuration& config = mIntegrationStates[currConfigIdx];
	config.mLinearVel.rotate(mConstraintMtx);
	config.mLocalAngularVel.rotate(mConstraintMtx);
	config.mLinearVel.set(config.mLinearVel.x * mLinearVelMask.x, config.mLinearVel.y * mLinearVelMask.y,
	                      config.mLinearVel.z * mLinearVelMask.z);
	config.mLocalAngularVel.set(config.mLocalAngularVel.x * mAngularVelMask.x, config.mLocalAngularVel.y * mAngularVelMask.y,
	                            config.mLocalAngularVel.z * mAngularVelMask.z);
	config.mLinearVel.rotate(mInverseConstraintMtx);
	config.mLocalAngularVel.rotate(mInverseConstraintMtx);

	OrthonormaliseOrientation(config.mOrientationMtx);
	config.mOrientationQuat.fromMat3f(config.mOrientationMtx);

	config.mInertiaTensor = config.mOrientationMtx * mInertiaTensor * Transpose(config.mOrientationMtx);
	config.mAngularVel    = config.mInertiaTensor * config.mLocalAngularVel;
}

/**
 * @brief Performs pre-render steps for the current frame, namely re-calculating transform matrices.
 */
void DynObjBody::initRender(int)
{
	mRenderTransformMtx.makeVQS(mRenderPosition, mRenderOrientation, Vector3f(1.0f, 1.0f, 1.0f));
	mCollObj->mTransformMtx.inverse(&mCollObj->mInverseMatrix);
	mCollObj->mTransformMtx = mRenderTransformMtx;
}

/**
 * @brief Applies a spring force to a given hook point on the object, based on the spring's extension/contraction.
 *
 * This uses a damped harmonic oscillator setup, attached to a moving rigid body. The body's velocity applies some non-linear damping to the
 * spring.
 *
 * @param configIdx Current state index in configuration array.
 * @param hookIdx Index of the hook point on the object to attach the spring to.
 * @param springAnchorPt World space anchor position the other end of the spring is attached to.
 */
void DynObjBody::applyWorldSpring(int configIdx, int hookIdx, immut Vector3f& springAnchorPt)
{
	STACK_PAD_VAR(4);

	configuration& config = mIntegrationStates[configIdx];

	Vector3f attachPt(config.mBodyPoints[hookIdx]);
	Vector3f centerToAttach = attachPt - config.mPosition;
	// calc total velocity of hook point
	Vector3f attachPtVelocity = config.mLinearVel + CP(config.mAngularVel, centerToAttach);
	// calc contraction/extension of spring
	Vector3f displacement = springAnchorPt - attachPt;
	f32 springExtension   = displacement.length() - SPRING_REST_LENGTH;

	// calc spring constant (slightly non-linear)
	f32 springStiffness = 1.3f;
	springStiffness += (1.0f - displacement.length() / SPRING_REST_LENGTH) * 0.2f;

	// F = -k x
	Vector3f springForce = displacement * (springExtension / displacement.length());
	// damping
	Vector3f dampingForce = (springForce.DP(attachPtVelocity) / springForce.DP(springForce) * -springStiffness) * springForce;
	// calc total force
	springForce.add(dampingForce);

	applyForce(configIdx, springForce, attachPt);

	FORCE_DONT_INLINE;
}

/**
 * @brief Renders the springs attached to this object as white lines.
 *
 * @param gfx Graphics context for rendering.
 */
void DynObjBody::render(Graphics& gfx)
{
	Matrix4f viewMtx;
	gfx.calcViewMatrix(mRenderTransformMtx, viewMtx);
	gfx.mCamera->setBoundOffset(&mRenderPosition);
	gfx.useMatrix(viewMtx, 0);
	gfx.mCamera->setBoundOffset(nullptr);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(COLOUR_WHITE, true);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

	// render each spring between its attach position and anchor position
	for (int i = 0; i < mSpringCount; i++) {
		gfx.drawLine(mRenderBodyPoints[mSprings[i].mHookIdx], mSprings[i].mAnchorPoint);
	}
}

/**
 * @brief Computes and applies all forces on the object for the current frame (gravity, springs, damping, ground collision).
 *
 * @param configIdx Current configuration index.
 * @param timeStep Unused.
 */
void DynObjBody::computeForces(int configIdx, f32 timeStep)
{
	configuration& config = mIntegrationStates[configIdx];
	CollGroup* collGroups = mMapShape->getCollTris(config.mPosition);

	// apply (very scaled) gravity
	applyCMForce(Vector3f(0.0f, -140.81f, 0.0f));

	// apply any attached springs
	for (int i = 0; i < mSpringCount; i++) {
		applyWorldSpring(configIdx, mSprings[i].mHookIdx, mSprings[i].mAnchorPoint);
	}

	// resolve ground collisions/restitution
	MATCHING_START_TIMER("applyGround", true);
	applyGroundForces(configIdx, collGroups);
	MATCHING_STOP_TIMER("applyGround");

	f32 a = Kdl;
	f32 b = Kda / 1.0f;

	Vector3f linearDamp(-a * config.mLinearVel.x, -a * config.mLinearVel.y, -a * config.mLinearVel.z);
	linearDamp.multiply(mMass);
	mLinearAccel.add(linearDamp);

	Vector3f angularDamp(-b * config.mAngularVel.x, -b * config.mAngularVel.y, -b * config.mAngularVel.z);
	mAngularAccel.add(angularDamp);
}

/**
 * @brief Initialises collision points and bounding box for the object, along with the collision object for physics calcs.
 */
void DynObjBody::initBodyCollisions()
{
	BoundBox boundingBox;
	// add all vertices to (minimal) bounding box
	for (int i = 0; i < mBodyShell->mVertexCount; i++) {
		bool isDuplicate = false;
		for (int j = 0; j < mBoundingPointCount; j++) {
			// check if vertex already exists in our bounding point list (bounding points come after hook points in the array)
			if (mBodyShell->mVertexList[i].x == mBodyPoints[j + mHookPointCount].x
			    && mBodyShell->mVertexList[i].y == mBodyPoints[j + mHookPointCount].y
			    && mBodyShell->mVertexList[i].z == mBodyPoints[j + mHookPointCount].z) {
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate) {
			// new point, add it and expand our box around it
			addBoundingPoint(mBodyShell->mVertexList[i].x, mBodyShell->mVertexList[i].y, mBodyShell->mVertexList[i].z);
			boundingBox.expandBound(mBodyShell->mVertexList[i]);
		}
	}

	PRINT("used %d verts\n", mBoundingPointCount);
	mRestitutionFactor = 0.0f;
	// update our dimensions based on the minimal box - this will also calc our mass
	initDimensions(boundingBox.mMax.x - boundingBox.mMin.x, boundingBox.mMax.y - boundingBox.mMin.y,
	               boundingBox.mMax.z - boundingBox.mMin.z);
	PRINT("mass = %f\n", mMass);

	// set up the associated collision object to connect to these physics
	mCollObj             = new DynCollObjBody(mBodyShell);
	mCollObj->mRigidBody = this;
}

/**
 * @brief Parses a (.ini) file to configure the dynamic object's properties.
 *
 * This is never run in used code, and the .ini files it would read are not left on the disc, unfortunately.
 *
 * @param map Manager for the map this object lives in/on.
 * @param filePath Path to (.ini) file to read, relative to the root data directory.
 */
void DynObjBody::readScript(MapMgr* map, immut char* filePath)
{
	// get commands list from file
	RandomAccessStream* file = gsys->openFile(filePath, true, true);
	if (!file) {
		return;
	}

	CmdStream* cmds = new CmdStream(file);
	file->close();

	/*
	    File structure would've been something like:

	    name 	"test"
	    body_shell 	"path/to/model.mod"

	    # as many of these as you want - x/y/z position on object
	    add_hook 	1.0f 	1.0f 	1.0f 	# 0
	    add_hook 	3.0f 	50.0f 	18.0f 	# 1

	    # as many of these as you want - hook idx from above, x/y/z position to anchor in world
	    add_spring 	0 	20.0f 	30.0f 	15.0f
	    add_spring 	1 	5.0f 	70.0f 	5.0f

	    use_verts

	    # restrict motion to certain axes
	    vel_mask 	1.0f 	0.0f 	1.0f
	    ang_mask 	0.0f 	1.0f 	0.0f
	*/

	while (!cmds->endOfCmds() && !cmds->endOfSection()) {
		cmds->getToken(true);
		// object name
		if (cmds->isToken("name")) {
			setName(StdSystem::stringDup(cmds->getToken(true)));
			continue;
		}

		// path to collision model
		if (cmds->isToken("body_shell")) {
			mBodyShell = map->loadPlatshape(cmds->getToken(true));
			continue;
		}

		// add as many hook points as you want - to attach springs to
		if (cmds->isToken("add_hook")) {
			f32 x;
			sscanf(cmds->getToken(true), "%f", &x);
			f32 y;
			sscanf(cmds->getToken(true), "%f", &y);
			f32 z;
			sscanf(cmds->getToken(true), "%f", &z);
			PRINT("adding hook at %f, %f, %f\n", x, y, z);
			addHook(x, y, z);
			continue;
		}

		// attach springs to hook points declared above - index = order they were declared in
		if (cmds->isToken("add_spring")) {
			int hookIdx;
			sscanf(cmds->getToken(true), "%d", &hookIdx);
			f32 x;
			sscanf(cmds->getToken(true), "%f", &x);
			f32 y;
			sscanf(cmds->getToken(true), "%f", &y);
			f32 z;
			sscanf(cmds->getToken(true), "%f", &z);
			PRINT("adding spring to hook %d at offset %f, %f, %f\n", hookIdx, x, y, z);
			addSpring(hookIdx, x, y, z);
			continue;
		}

		// does nothing - we're using the vertices either way
		if (cmds->isToken("use_verts")) {
			PRINT("using shapes' vertices\n");
			continue;
		}

		// restrictions on linear motion
		if (cmds->isToken("vel_mask")) {
			sscanf(cmds->getToken(true), "%f", &mLinearVelMask.x);
			sscanf(cmds->getToken(true), "%f", &mLinearVelMask.y);
			sscanf(cmds->getToken(true), "%f", &mLinearVelMask.z);
			continue;
		}

		// restrictions on angular motion
		if (cmds->isToken("ang_mask")) {
			sscanf(cmds->getToken(true), "%f", &mAngularVelMask.x);
			sscanf(cmds->getToken(true), "%f", &mAngularVelMask.y);
			sscanf(cmds->getToken(true), "%f", &mAngularVelMask.z);
			continue;
		}
	}

	if (!cmds->endOfCmds()) {
		cmds->getToken(true);
	}
}

/**
 * @brief Renders a pushable object, determines if it will move based on a preset force threshold, and displays its current attempted push
 * force as text.
 *
 * @param gfx Graphics context for rendering.
 */
void DynObjPushable::render(Graphics& gfx)
{
	Matrix4f viewMtx;
	gfx.calcViewMatrix(mRenderTransformMtx, viewMtx);
	gfx.useMatrix(viewMtx, 0);

	// calc how much force we're trying to apply
	if (mLinearAccel.length() > 0.0f) {
		mCurrPushForce = mLinearAccel.length() * mInvMass;
	}

	// check if it will actually cause motion
	if (mCurrPushForce < mMoveThreshold) {
		// no force added to object if we're below the threshold, no motion
		mLinearAccel.set(0.0f, 0.0f, 0.0f);
		mAngularAccel.set(0.0f, 0.0f, 0.0f);
	} else {
		// add constant linear force if we're at or above the threshold, motion
		mLinearAccel.normalise();
		mLinearAccel.multiply(mPushForceWhileMoving);
	}

	// set up graphics for debug text (no lighting, white text, alpha blending)
	bool lighting = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.setColour(COLOUR_WHITE, true);
	int blend = gfx.setCBlending(BLEND_Alpha);

	// draw how much force we're trying to apply above the object
	Vector3f textPos(0.0f, 90.0f, 0.0f);
	textPos.add(mRenderPosition);
	textPos.multMatrix(gfx.mCamera->mLookAtMtx);

	char forceText[PATH_MAX];
	sprintf(forceText, "%.1f", mCurrPushForce);
	gfx.perspPrintf(gsys->mConsFont, textPos, -(gsys->mConsFont->stringWidth(forceText) / 2), 0, forceText);

	// restore lighting/blend settings
	gfx.setCBlending(blend);
	gfx.setLighting(lighting, nullptr);

	// render the rest of the object
	DynObjBody::render(gfx);
}

#pragma endregion
//////////////////////////////////////////////////////
//////////////// (UNUSED) SOFT LIGHTS ////////////////
//////////////////////////////////////////////////////
#pragma region SOFT LIGHTS

static u32 numRepeats;
static u32 numUpdated;
static SoftLightAccumulator* vlink;

/**
 * @brief How soft lights turn on and interact. For use with `SoftLight::mSoftLightType`.
 */
enum SoftLightType {
	SOFTLIGHT_StandAlone = 0, ///< 0, slowly turns on, does not trigger other nearby lights.
	SOFTLIGHT_Cascade    = 1, ///< 1, turns on quickly, triggers other lights within its interaction radius to turn on immediately.
};

/**
 * @brief Unfinished/unused structure for accumulating light intensities from associated `SoftLight`s.
 *
 * Seems to transfer these intensities into a four-member u8 array or struct, which could be a colour, or channels to some other object.
 * So little code of this remains that it's hard to know for certain.
 *
 * (Fabricated name. Some struct has to exist here, but I don't think it's exposed anywhere.)
 *
 * @note Size: 0x10.
 */
struct SoftLightAccumulator {
	u32 mLastUpdateTick;         ///< _00, last update tick (relative to `MapLightMgr`'s `mCurrentUpdateTick`) to track updates.
	SoftLightAccumulator* mNext; ///< _04, next accumulator in the `vlink` list.
	u8* _08;                     ///< _08, array of four channels that intensity is updated into. Never hooked up to anything else.
	s16 mAccumulatedIntensity;   ///< _0C, accumulated intensity, to be increased or decreased by associated `SoftLight`s.
};

/**
 * @brief Unused structure for interactable and chainable light sources that fade in and vary in intensity.
 *
 * The code for this is never properly hooked up and never initialised, so it's hard to tell what it'd be used for.
 * Best guess is for light sources for areas like Forest Navel that would increase in brightness as the player approached.
 *
 * Lights of the same group could be chained together in a cascade, where near-enough lights to each other would all light up if a player
 * approached.
 *
 * No other functions are exposed aside from those listed, and it doesn't seem to have any additional stripped code in the DLL, so genuinely
 * seems unfinished.
 *
 * @note Size: 0x38.
 */
struct SoftLight {

	/**
	 * @brief Adds current light's intensity to its list of accumulators, and marks them as updated. Most params are unused.
	 * @param currentTick Current update tick, to avoid double-updating accumulators.
	 */
	void addLight(u32 currentTick, LShortColour*, Shape*)
	{
		if (mAccumulatorList) {
			for (int i = 0; i < mAccumulatorCount; i++) {
				if (mAccumulatorList[i]->mLastUpdateTick != currentTick) {
					mAccumulatorList[i]->mNext           = vlink;
					vlink                                = mAccumulatorList[i];
					mAccumulatorList[i]->mLastUpdateTick = currentTick;
				}
				mAccumulatorList[i]->mAccumulatedIntensity += (mIntensityScales[i] * mCurrentColour.r) >> 8;
			}
		}
	}

	/**
	 * @brief Subtracts this light's current intensity from each of its accumulators. Parameter is unused.
	 */
	void subLight(LShortColour*)
	{
		if (mAccumulatorList) {
			for (int i = 0; i < mAccumulatorCount; i++) {
				mAccumulatorList[i]->mAccumulatedIntensity -= (mIntensityScales[i] * mCurrentColour.r) >> 8;
			}
		}

		FORCE_DONT_INLINE;
	}

	Vector3f mPosition;                      ///< _00, position of soft light (to check against captain position).
	Colour mCurrentColour;                   ///< _0C, current display colour of the light - mTargetColour scaled by intensity.
	Colour mTargetColour;                    ///< _10, target colour of the light, to be faded into by our intensity scaling.
	f32 mInteractionRadius;                  ///< _14, radius to use for searching (for captain or other lights). Scaled based on type.
	f32 mTargetPhase;                        ///< _18, target phase for smooth fade-in. Max brightness is HALF_PI.
	f32 mCurrentPhase;                       ///< _1C, current phase for smooth fade-in. Assumes current phase < target phase.
	int mGroupID;                            ///< _20, grouping of light - for determining which lights can interact with others.
	int mSoftLightType;                      ///< _24, interaction/animation type - see `SoftLightType` enum.
	int mAccumulatorCount;                   ///< _28, number of accumulators in list.
	u8 _2C;                                  ///< _2C, confusingly used flag, related to whether subLight should be called when fading in.
	SoftLightAccumulator** mAccumulatorList; ///< _30, list of intensity accumulators for this light.
	s16* mIntensityScales;                   ///< _34, factors to scale each intensity accumulator by when adding or subtracting.
};

/**
 * @brief Unused/unfinished manager for a map's `SoftLight`s. Never initialised, so its functions are never actually run.
 *
 * Controls the fade-in of lights, and also interactions with them based on distance from player (and from other lights).
 *
 * @note Size: 0x18.
 */
struct MapLightMgr {

	/// Updates all managed soft lights, controlling fade-ins and light-light interactions, and updating accumulators' mysterious u8 arrays.
	void updateLights()
	{
		// track what frame we're on, so we can tell if we updated accumulators already this frame
		// (this probably implies accumulators were shared between lights)
		mCurrentUpdateTick++;

		numUpdated = 0; // unused
		numRepeats = 0; // unused
		vlink      = nullptr;

		// update all our lights
		for (int i = 0; i < mSoftLightCount; i++) {
			// unused
			sinf(mSoftLights[i]->mCurrentPhase);

			// check if we're at maximum brightness or not
			bool isFadingIn = false;
			if (mSoftLights[i]->mCurrentPhase != mSoftLights[i]->mTargetPhase) {
				// stand-alone lights turn on slowly (~3.2s), cascading lights turn on fast (~0.8s)
				f32 speed = (mSoftLights[i]->mSoftLightType != SOFTLIGHT_StandAlone) ? 2.0f : 0.5f;
				// calculate exponential approach (will clamp later so it's not infinite)
				mSoftLights[i]->mCurrentPhase
				    += gsys->getFrameTime() * speed * (mSoftLights[i]->mTargetPhase - mSoftLights[i]->mCurrentPhase);
				isFadingIn = true;
			}

			// we're not at maximum brightness
			if (isFadingIn) {
				// this feels like a typo - it seems like _2C should be a "pending reset" flag which is then cleared after this
				// but as-is, it calls subLight every frame (except maybe the first one) and then adds it again, which would stall it?
				// there's not enough remaining code to piece it back together very well tbh.
				if (!mSoftLights[i]->_2C) {
					mSoftLights[i]->subLight(_10);
				}
				mSoftLights[i]->_2C = 0;
				f32 intensity       = sinf(mSoftLights[i]->mCurrentPhase);
				if (intensity > 0.95f) {
					// clamp to 1 if we're close enough (to prevent an infinite approach)
					mSoftLights[i]->mCurrentPhase = mSoftLights[i]->mTargetPhase;
				}

				// update colour with our increased intensity
				mSoftLights[i]->mCurrentColour.set(mSoftLights[i]->mTargetColour.r * intensity, mSoftLights[i]->mTargetColour.g * intensity,
				                                   mSoftLights[i]->mTargetColour.b * intensity, 255);
				// add intensity to our accumulators and update the list
				mSoftLights[i]->addLight(mCurrentUpdateTick, _10, _00);
			}
		}

		// update accumulator list's u8 arrays (colour? channels? unknown)
		// vlink is reconstructed each frame to only keep relevant lights
		if (vlink) {
			for (SoftLightAccumulator* lightLink = vlink; lightLink; lightLink = lightLink->mNext) {
				u8 intensity      = (lightLink->mAccumulatedIntensity < 255) ? (u8)lightLink->mAccumulatedIntensity : 255;
				lightLink->_08[0] = intensity;
				lightLink->_08[1] = intensity;
				lightLink->_08[2] = intensity;
				lightLink->_08[3] = intensity;
			}
		}
	}

	/**
	 * @brief Updates each light's state based on distance from the player. Close lights are "touched" and increased in intensity.
	 *
	 * "Touched" lights of a non-stand-alone type can trigger other nearby lights to also increase intensity. Code is never run.
	 *
	 * @param naviPos Captain position, to check light distances relative to.
	 */
	void touchLights(immut Vector3f& naviPos)
	{
		for (int i = 0; i < mSoftLightCount; i++) {
			if (mSoftLights[i]->mTargetPhase != HALF_PI) {
				f32 touchDist = (mSoftLights[i]->mSoftLightType != SOFTLIGHT_StandAlone) ? mSoftLights[i]->mInteractionRadius * 0.5f
				                                                                         : mSoftLights[i]->mInteractionRadius * 1.5f;
				if (mSoftLights[i]->mPosition.distance(naviPos) < touchDist) {
					// if we're close enough, turn light to full brightness
					mSoftLights[i]->mTargetPhase = HALF_PI;
				}

				if (mSoftLights[i]->mSoftLightType != SOFTLIGHT_StandAlone) {
					// cascade and turn any other nearby lights in the same group to full brightness (if they're at least partially on)
					for (int j = 0; j < mSoftLightCount; j++) {
						if (i != j && mSoftLights[j]->mGroupID == mSoftLights[i]->mGroupID && mSoftLights[j]->mCurrentPhase > 0.4f) {
							f32 dist = mSoftLights[i]->mPosition.distance(mSoftLights[j]->mPosition);
							if (dist < mSoftLights[i]->mInteractionRadius) {
								mSoftLights[i]->mTargetPhase = HALF_PI;
							}
						}
					}
				}
			}
		}
	}

	Shape* _00;              ///< _00, unknown model of some description - possibly map model? Not enough remaining info to know.
	SoftLight** mSoftLights; ///< _04, array of soft lights to use and update.
	u8 _08[0x4];             ///< _08, unknown/unused.
	int mSoftLightCount;     ///< _0C, number of soft lights in use.
	LShortColour* _10;       ///< _10, unknown colour of some description - possibly ambient color? Not enough remaining info to know.
	u32 mCurrentUpdateTick;  ///< _14, counter for how many frames we've updated, to tell if we updated last frame or not.
};

#pragma endregion
//////////////////////////////////////////////////////
//////////////////// MAP MANAGER /////////////////////
//////////////////////////////////////////////////////
#pragma region MAP MANAGER

/**
 * @brief Constructs a new map manager, allocating memory for various subsystems and setting up map rendering and collision.
 *
 * @param controller Active player controller.
 */
MapMgr::MapMgr(Controller* controller)
{
	mController = controller;

	// zero-out fade and desaturation
	mCurrFadeLevel           = 0.0f;
	mCurrDesaturationLevel   = 0.0f;
	mTargetFadeLevel         = 0.0f;
	mTargetDesaturationLevel = 0.0f;

	effectMgr = nullptr;

	// this is adjusted by the Blur day manager debug menu, but doesn't actually affect anything
	// (bug fix is to align it with the actual default blur, usually handled by the camera)
	mBlur = TERNARY_BUGFIX(110, 145);

	// set up day manager, to handle lighting
	memStat->start("dayMgr");
	mDayMgr = new DayMgr(this, mController);
	memStat->end("dayMgr");

	mCurrTraceTick = 0;
	mMapModel      = nullptr;

	// set up debug collisions
	mDebugCollCount = 0;
	mMaxDebugColls  = 300;

	if (mMaxDebugColls != 0) {
		memStat->start("collisions");
		mDebugCollisions = new MapColls[mMaxDebugColls];
		memStat->end("collisions");
	}

	// set up (completely unused) coll parts
	memStat->start("collparts");
	mCollParts = new CreatureCollPart();
	mCollParts->initCore("");
	memStat->end("collparts");

	mMapBounds.resetBound();

	// set up (unused) rooms
	memStat->start("rooms");
	mMapRooms = new MapRoom[256];
	memStat->end("rooms");

	// set up map collision handler
	memStat->start("dyncolshape");
	mCollShapeList = new DynCollShape(nullptr);
	memStat->end("dyncolshape");

	// set up shadow handlers
	memStat->start("shadMats");
	mShadowDelayCounter = 3;
	mGlobalShadowList.initCore("");

	// set up material handlers for shadows
	mShadowCamMatHandler                          = new MapShadMatHandler();
	mShadowCamMatHandler->mShadowLightMat->mFlags = MATFLAG_Opaque;

	mShadowProjMatHandler                   = new MapProjMatHandler(nullptr);
	mShadowProjMatHandler->mProjMat->mFlags = MATFLAG_InverseColorBlend | MATFLAG_Opaque;
	mShadowProjMatHandler->mProjMat->getColour().set(255, 255, 255, 255);
	memStat->end("shadMats");

	// set up the infamous blur
	memStat->start("blurTextures");
	// set up storage buffer for current frame's depths
	mBlurSourceTexture                = new Texture();
	mBlurSourceTexture->mWidthFactor  = 1.0f / 320;
	mBlurSourceTexture->mHeightFactor = 1.0f / 240;
	mBlurSourceTexture->mTexFlags     = (Texture::TEX_CLAMP_S | Texture::TEX_Unk2 | Texture::TEX_CLAMP_T);
	mBlurSourceTexture->createBuffer(320, 240, TEX_FMT_Z8, nullptr);
	gsys->addTexture(mBlurSourceTexture, "internalLightmap");

	// set up storage buffer for blur, to layer next frame
	mBlurResultTexture                = new Texture();
	mBlurResultTexture->mWidthFactor  = 1.0f / 320;
	mBlurResultTexture->mHeightFactor = 1.0f / 240;
	mBlurResultTexture->mTexFlags     = (Texture::TEX_CLAMP_S | Texture::TEX_Unk2 | Texture::TEX_CLAMP_T);
	mBlurResultTexture->createBuffer(320, 240, TEX_FMT_RGB565, nullptr);
	gsys->addTexture(mBlurResultTexture, "internalLightmap");
	memStat->end("blurTextures");
}

/**
 * @brief Does nothing - tries to set up a new EffectMgr, but assigns it to nothing.
 *
 * Given its call location, potentially connected to the unused `SoftLight`s.
 */
void MapMgr::initEffects()
{
	// hmm.
	new EffectMgr;
}

/**
 * @brief Initialises the map model, collision, and the world's physics simulator.
 */
void MapMgr::initShape()
{
	mSoftLightMgr = nullptr;

	// set up model
	mMapModel = gameflow.loadShape(flowCont.mMapModelFilePath, true);
	mMapModel->mSystemFlags |= ShapeFlags::AlwaysRedraw;

	// set up instances for every animated material used by the map model
	mMapModel->makeInstance(mAnimatedMaterials, 0);

	for (int i = 0; i < mMapModel->mJointCount; i++) {
		PRINT("got bound (%.1f, %.1f, %.1f) - (%.1f, %.1f, %.1f)\n", mMapModel->mJointList[i].mBounds.mMin.x,
		      mMapModel->mJointList[i].mBounds.mMin.y, mMapModel->mJointList[i].mBounds.mMin.z, mMapModel->mJointList[i].mBounds.mMax.x,
		      mMapModel->mJointList[i].mBounds.mMax.y, mMapModel->mJointList[i].mBounds.mMax.z);
	}

	// set up collisions (with grid size of 64)
	mMapModel->createCollisions(MAP_GRID_SIZE);
	mMapBounds.expandBound(mMapModel->mCourseExtents);

	// set up physics
	mWorldSimulator         = new DynSimulator();
	mPhysicsStepInterval    = PHYSICS_UPDATE_STEP_TIME;      // NB: map physics calculates at 60 fps, but only renders at 30 fps
	mPhysicsSubStepInterval = PHYSICS_INTEGRATION_STEP_TIME; // probably tuned in development for better function (80 fps here)
	mLastPhysicsTime        = 0.0f;
	mAccumPhysicsTime       = 0.0f;

	// sigh. this is really there.
	// similar code exists in GenObjectMapObject::birth, but the assembly is actually stripped there.
	for (int i = 0; i < 0; i++) {
		DynObjBody* body = new DynObjBody();
		body->mMapShape  = mMapModel;
		body->readScript(this, "traffic/specLog.ini");
		body->initBodyCollisions();
		body->mInitPosition.set(0.0f, 60.0f, 100.0f);
		body->mInitOrientationZ = Vector3f(1.0f, 0.0f, 0.0f);
		body->mInitOrientationX = Vector3f(0.0f, 1.0f, 0.0f);
		body->mInitOrientationY = Vector3f(0.0f, 0.0f, 1.0f);
		mWorldSimulator->add(body);
		mCollShapeList->add(body->mCollObj);
	}

	mSimulationResetPending = true;
}

/**
 * @brief Does nothing - likely would've been used to set up the unused `SoftLight`s on the map.
 */
void MapMgr::createLights()
{
}

/**
 * @brief Advances the physics simulation for the map, up to the current frame.
 */
void MapMgr::updateSimulation()
{
	if (mSimulationResetPending) {
		// reset world after setup
		mWorldSimulator->resetWorld();
		mSimulationResetPending    = false;
		mWorldSimulator->mIsPaused = false;
	}

	f32 dt = gsys->getFrameTime();
	if (!mWorldSimulator->isPaused()) {
		// update our accumulated running time for the physics engine
		mAccumPhysicsTime += dt * 1.0f;
		// catch the physics engine up to our frame time
		while (mAccumPhysicsTime - mLastPhysicsTime > mPhysicsStepInterval) {
			if (!mWorldSimulator->isPaused()) {
				mWorldSimulator->updateConts();
				mWorldSimulator->doSimulation(mPhysicsStepInterval, mPhysicsSubStepInterval, mMapModel);
			}

			mLastPhysicsTime += mPhysicsStepInterval;
		}

		// with all the calculations done, update actual render information for the physics engine
		f32 interpFactor = (mAccumPhysicsTime - mLastPhysicsTime) / mPhysicsStepInterval;
		mWorldSimulator->updateVecQuats(interpFactor);
	}
}

/**
 * @brief Updates the world simulation and all dynamic collision models connected to the map.
 */
void MapMgr::update()
{
	updateSimulation();
	mWorldSimulator->InitRender();

	gsys->mTimer->start("updDynPlat", true);

	// these are genuinely unused in the DLL too
	int total        = 0;
	int wallCount    = 0;
	int workObjCount = 0;
	int tekiCount1   = 0;
	int tekiCount2   = 0;

	// update all dynamic collision models on the map
	FOREACH_NODE(DynCollShape, mCollShapeList->mChild, coll)
	{
		Creature* creature = coll->mCreature;
		// update IF:
		// - no attached creature OR
		// - attached creature always requires updating OR
		// - attached creature is not being culled AND not a wall or work object OR
		// - attached creature is just not being grid-culled
		if (!creature || creature->alwaysUpdatePlatform()
		    || ((creature->aiCullable() || !creature->mGrid.aiCulling())
		        && ((!creature->isSluice() && creature->mObjType != OBJTYPE_WorkObject) || !creature->mGrid.aiCulling()))) {

			coll->update();
			coll->updatePos();
			coll->mContactTickCount = 0;

			// these debug amounts are completely unused
			if (creature) {
				if (creature->isSluice()) {
					wallCount++;
				} else if (creature->mObjType == OBJTYPE_Teki) {
					tekiCount1++;
				} else if (creature->isTeki()) {
					tekiCount2++; // this will always be zero. why are we doing this
				} else if (creature->mObjType == OBJTYPE_WorkObject) {
					workObjCount++;
				}
			}
			total++;
		}
	}

	gsys->mTimer->stop("updDynPlat");
}

/**
 * @brief Prepares the map for rendering, resetting per-frame trackables and setting up shadow caster cameras.
 *
 * @param gfx Graphics context for rendering.
 */
void MapMgr::preRender(Graphics& gfx)
{
	mMinMaxYQueryCount = 0;
	mCurrTriQueryCount = 0;
	gfx.setMatHandler(mShadowCamMatHandler);
	// don't allow translucent things or shadows
	gfx.mMatRenderMask = (MATFLAG_Opaque | MATFLAG_AlphaTest);

	FOREACH_NODE(ShadowCaster, mGlobalShadowList.mChild, shadow)
	{
		LightCamera& cam = shadow->mLightCamera;
		cam.calcVectors(shadow->mSourcePosition, shadow->mTargetPosition);
		cam.calcProjection(gfx, false, mShadowDelayCounter > 0 ? nullptr : shadow->mShadowDrawer);
	}

	// allow everything except shadows
	gfx.mMatRenderMask = (MATFLAG_Opaque | MATFLAG_AlphaTest | MATFLAG_AlphaBlend);
	gfx.setMatHandler(nullptr);

	if (mShadowDelayCounter) {
		mShadowDelayCounter--;
	}
}

/**
 * @brief Draws all (complex model) shadow casters from the global list by projecting their model to the ground.
 *
 * @param gfx Graphics context for rendering.
 */
void MapMgr::drawShadowCasters(Graphics& gfx)
{
	// set up overall graphics settings
	gfx.setFog(false);
	int blend = gfx.setCBlending(BLEND_InverseColor);

	FOREACH_NODE(ShadowCaster, mGlobalShadowList.mChild, shadow)
	{
		// set up graphics state for this shadow caster
		LightCamera* cam = &shadow->mLightCamera;
		gfx.initProjTex(true, cam);
		mShadowProjMatHandler->mProjMat->mTexture = cam->mLightMap;
		mShadowProjMatHandler->mProjectionCamera  = cam;
		gfx.setMatHandler(mShadowProjMatHandler);
		// allow everything INCLUDING shadows
		gfx.mMatRenderMask = (MATFLAG_Opaque | MATFLAG_AlphaTest | MATFLAG_AlphaBlend | MATFLAG_InverseColorBlend);
		gfx.mLightCam      = cam;
		gfx.useMatrix(Matrix4f::ident, 0);

		// draw projected shadow
		mMapModel->drawculled(gfx, *gfx.mCamera, nullptr);

		// re-set graphics state
		gfx.mLightCam = nullptr;
		// allow everything EXCEPT shadows
		gfx.mMatRenderMask = (MATFLAG_Opaque | MATFLAG_AlphaTest | MATFLAG_AlphaBlend);
		gfx.setMaterial(nullptr, false);
		gfx.setMatHandler(nullptr);
		gfx.initProjTex(false, nullptr);
	}

	// reset overall graphics settings
	gfx.setCBlending(blend);
	gfx.setFog(true);
}

/**
 * @brief Renders the map for the current frame, including (unused) `SoftLight`s and any dynamic collision.
 */
void MapMgr::refresh(Graphics& gfx)
{
	gfx.setCBlending(BLEND_Alpha);
	if (mSoftLightMgr) {
		gsys->mTimer->start("SoftLights", true);
		mSoftLightMgr->updateLights();
		gsys->mTimer->stop("SoftLights");
	}

	if (mMapModel) {
		// this goes in the if condition above in the DLL, but fixes the stack in DOL if it's just empty.
		if (!mController->keyDown(KBBTN_DPAD_UP)) { }

		// update materials
		mAnimatedMaterials.animate(nullptr);

		// set up environment
		gfx.mHasTexGen = TRUE;
		Matrix4f viewMtx;
		Matrix4f modelMtx;
		modelMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		gfx.calcViewMatrix(modelMtx, viewMtx);
		gfx.setLighting(true, nullptr);
		// don't allow translucent things
		gfx.mMatRenderMask = (MATFLAG_Opaque | MATFLAG_AlphaTest);
		mMapModel->updateAnim(gfx, viewMtx, nullptr);
		gfx.useMatrix(Matrix4f::ident, 0);

		// draw only visible joints of the model to optimise performance
		mMapModel->drawculled(gfx, *gfx.mCamera, &mAnimatedMaterials);

		// reset environment - allow everything except shadows
		gfx.mMatRenderMask = (MATFLAG_Opaque | MATFLAG_AlphaTest | MATFLAG_AlphaBlend);
		gfx.mHasTexGen     = FALSE;

		// render all dynamic collision
		FOREACH_NODE(DynCollShape, mCollShapeList->mChild, coll)
		{
			// set up environment
			gfx.calcViewMatrix(coll->mTransformMtx, coll->mViewMtx);
			gfx.useMatrix(coll->mViewMtx, 0);
			gfx.mHasTexGen = TRUE;
			gfx.setLighting(true, nullptr);

			// draw the object
			coll->refresh(gfx);

			gfx.mHasTexGen = FALSE;
		}

		// render any rigid bodies
		mWorldSimulator->Render(gfx);
	}
}

/// Bounds to calculate captain collision within - only used for debug triangles.
BoundBox collExtents;

/**
 * @brief Prepares debug collision triangles around a given point for rendering.
 *
 * @param focusPos Position to calculate debug triangles around - only ever called with current captain position.
 */
void MapMgr::showCollisions(immut Vector3f& focusPos)
{
	mDebugFocusPosition = focusPos;
	f32 cellSize        = MAP_GRID_SIZE;
	int maxGridX        = (mMapBounds.mMax.x - mMapBounds.mMin.x + cellSize) / cellSize;
	int maxGridZ        = (mMapBounds.mMax.z - mMapBounds.mMin.z + cellSize) / cellSize;
	int gridX           = (mDebugFocusPosition.x - mMapBounds.mMin.x) / cellSize;
	int gridZ           = (mDebugFocusPosition.z - mMapBounds.mMin.z) / cellSize;
	f32 cellOriginX     = mMapBounds.mMin.x + gridX * cellSize;
	f32 cellOriginZ     = mMapBounds.mMin.z + gridZ * cellSize;
	f32 cellExpand      = cellSize * 1.0f;

	// set up our two giant colored prisms
	mOuterCollRenderBounds.resetBound();
	mOuterCollRenderBounds.expandBound(Vector3f(cellOriginX - cellExpand, mMapBounds.mMin.y - cellExpand, cellOriginZ - cellExpand));
	mOuterCollRenderBounds.expandBound(
	    Vector3f(cellOriginX + cellSize + cellExpand, mMapBounds.mMax.y + cellExpand, cellOriginZ + cellSize + cellExpand));

	mActiveCollisionBounds.resetBound();
	mActiveCollisionBounds.expandBound(Vector3f(cellOriginX, mMapBounds.mMin.y - cellExpand, cellOriginZ));
	mActiveCollisionBounds.expandBound(Vector3f(cellOriginX + cellSize, mMapBounds.mMax.y + cellExpand, cellOriginZ + cellSize));
	collExtents = mActiveCollisionBounds;

	// construct bounding box to search for triangles within
	BoundBox focusBox;
	focusBox.expandBound(focusPos);
	// make box 32x32x32 around focus position
	focusBox.mMin.sub(Vector3f(16.0f, 16.0f, 16.0f));
	focusBox.mMax.add(Vector3f(16.0f, 16.0f, 16.0f));

	// gather a list of all collision that intersects our 32x32x32 box
	CollGroup* collGroup = nullptr;

	// first, check list of dynamic collision
	FOREACH_NODE(DynCollShape, mCollShapeList->mChild, coll)
	{
		if (focusBox.intersects(coll->mBoundingBox)) {
			for (int i = 0; i < coll->mCollGroupCount; i++) {
				if (coll->mJointVisibility[coll->mCollGroupList[i]->mJointIndex]) {
					coll->mCollGroupList[i]->mModel         = coll->mCollisionModel;
					coll->mCollGroupList[i]->mVertexList    = coll->mVertexList;
					coll->mCollGroupList[i]->mPlatCollision = coll;
					coll->mCollGroupList[i]->mNextCollGroup = collGroup;
					collGroup                               = coll->mCollGroupList[i];
				}
			}
		}
	}

	// second, check list of ordinary/static map collision
	CollGroup* coll = mMapModel->getCollTris(focusPos);
	if (coll && coll->mTriCount) {
		coll->mModel         = mMapModel;
		coll->mVertexList    = mMapModel->mVertexList;
		coll->mPlatCollision = nullptr;
		coll->mNextCollGroup = collGroup;
		collGroup            = coll;
	}

	// add up all triangles in collision we found and add them to the debug collision display
	for (coll = collGroup; coll; coll = coll->mNextCollGroup) {
		if (!coll) {
			continue;
		}
		if (coll->mTriCount == 0) {
			continue;
		}

		mActiveTriCount += coll->mTriCount - coll->mFarCulledTriCount;
		int activeCount = coll->mTriCount - coll->mFarCulledTriCount;
		if (coll->mTriCount == coll->mFarCulledTriCount) {
			// no triangles are visible/not far culled
			PRINT("grid(%d,%d) collGroup : total %d far %d tris\n", gridX, gridZ, coll->mTriCount, coll->mFarCulledTriCount);
			for (int i = 0; i < coll->mFarCulledTriCount; i++) {
				PRINT("\t%d : dist = %d\n", i, coll->mFarCulledTriDistances[i]);
			}
		}

		for (int i = 0; i < coll->mTriCount; i++) {
			if (mDebugCollCount < mMaxDebugColls) {
				if (AIPerf::showColls) {
					// if showColls is on, we get nice differently colored triangles
					if (i < activeCount) {
						// not far culled
						mDebugCollisions[mDebugCollCount].mColorCategory = DCLR_Yellow;
					} else {
						if (coll->mFarCulledTriDistances[i - activeCount] < 16) {
							// far culled but not THAT far
							mDebugCollisions[mDebugCollCount].mColorCategory = DCLR_Blue;
						} else {
							// far culled and "far" away
							mDebugCollisions[mDebugCollCount].mColorCategory = DCLR_Red;
						}
					}
				} else {
					// everything is yellow
					mDebugCollisions[mDebugCollCount].mColorCategory = DCLR_Yellow;
				}

				mDebugCollisions[mDebugCollCount].mParentCollGroup = coll;
				mDebugCollisions[mDebugCollCount].mTriangle        = coll->mTriangleList[i];
				mDebugCollCount++;
			}
		}
	}
}

/**
 * @brief Checks if a given triangle in a given collision group is more than one unit away from our active collision bounds.
 *
 * @return `true` if further away than 1 unit, `false` otherwise.
 * @note UNUSED Size: 00006C
 */
bool MapMgr::closeCollTri(CollGroup* collGroup, CollTriInfo* tri)
{
	f32 dist = triRectDistance(&collGroup->mVertexList[tri->mVertexIndices[0]], &collGroup->mVertexList[tri->mVertexIndices[1]],
	                           &collGroup->mVertexList[tri->mVertexIndices[2]], mActiveCollisionBounds, false);
	return (dist > 1.0f) != 0; // this is necessary for matching by size, fun.
}

/**
 * @todo: Documentation
 */
void MapMgr::drawXLU(Graphics& gfx)
{
	if (mMapModel) {
		MATCHING_START_TIMER("mapPost", true);
		mDayMgr->setFog(gfx, nullptr);
#if 0 // DLL only condition
		if (!mController->keyDown(KBBTN_DPAD_DOWN))
#endif
		{
			// set up graphics environment
			gfx.mHasTexGen = TRUE;
			Matrix4f viewMtx;
			Matrix4f modelMtx;
			modelMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
			gfx.calcViewMatrix(modelMtx, viewMtx);
			gfx.useMatrix(viewMtx, 0);
			gfx.setLighting(true, nullptr);
			// only allow translucent things this pass
			gfx.mMatRenderMask = MATFLAG_AlphaBlend;
			mMapModel->updateAnim(gfx, viewMtx, nullptr);
			gfx.useMatrix(Matrix4f::ident, 0);

			mMapModel->drawshape(gfx, *gfx.mCamera, &mAnimatedMaterials);

			// allow everything except shadows
			gfx.mMatRenderMask = (MATFLAG_Opaque | MATFLAG_AlphaTest | MATFLAG_AlphaBlend);
		}
		MATCHING_STOP_TIMER("mapPost");
	}
}

/**
 * @brief Handles post-rendering steps, including shadow drawing, effects, blur, fades/desaturation and debug collision overlays.
 *
 * @param gfx Graphics context for rendering.
 */
void MapMgr::postrefresh(Graphics& gfx)
{
	if (mMapModel) {
		MATCHING_START_TIMER("mapPost", true);
		mDayMgr->setFog(gfx, nullptr);

		// draw shadows
		drawShadowCasters(gfx);

		// queue up carry info text
		if (lgMgr) {
			lgMgr->update();
			lgMgr->refresh(gfx);
		}

		// draw carry info text (and any other light flares)
		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.flushCachedShapes();
		gsys->flushLFlares(gfx);

		// draw effects
		if (effectMgr) {
			gsys->mTimer->start("eff draw", true);
			effectMgr->drawshapes(gfx);
			gsys->mTimer->stop("eff draw");
		}

		// make and draw infamous blur effect - on by default
		if (gsys->mToggleBlur) {
			// set up screen environment for drawing
			Matrix4f orthoMtx;
			gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
			bool lighting = gfx.setLighting(false, nullptr);
			gfx.setFog(false);
			gfx.setColour(COLOUR_WHITE, true);
			gfx.setAuxColour(COLOUR_WHITE);

			// store this frame's non-blurred scene into mBlurSourceTexture's pixel data
			mBlurSourceTexture->grabBuffer(mBlurSourceTexture->mWidth, mBlurSourceTexture->mHeight, false, true);
			gfx.useTexture(mBlurResultTexture, GX_TEXMAP0); // previous frame's blur
			gfx.useTexture(mBlurSourceTexture, GX_TEXMAP1); // current frame's data

			// Fun fact: the map manager's blur setting does *nothing* to adjust the blur, despite there being a
			// day manager debug menu option for it. This re-hooks it up as the actual blur alpha, to let you adjust it.
#if defined(BUGFIX)
			gfx.mCamera->mBlurAlpha = mBlur;
#endif

#if defined(VERSION_PIKIDEMO)
#else
			if (gameflow.mMoviePlayer->mIsActive) {
				gfx.mCamera->mBlurAlpha = 0.0f;
			}
#endif

			int blend = gfx.setCBlending(BLEND_MultiTexture);
			gfx.setPrimEnv(&Colour(255, 255, 255, gfx.mCamera->mBlurAlpha), nullptr);

			// render multi-texture blend (blur)
			gfx.blatRectangle(AREA_FULL_SCREEN(gfx));

			// clean up graphics settings + store current blur result for use next frame
			gfx.setCBlending(blend);
			mBlurResultTexture->grabBuffer(mBlurResultTexture->mWidth, mBlurResultTexture->mHeight, false, true);
			gfx.resetCopyFilter();
			gfx.setFog(true);
			gfx.setLighting(lighting, nullptr);
			gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
			                   gfx.mCamera->mFar, 1.0f);
		}

		// handle fading and desaturating
		if (mCurrFadeLevel < mTargetFadeLevel) {
			mCurrFadeLevel += 2.0f * gsys->getFrameTime();
			if (mCurrFadeLevel > mTargetFadeLevel) {
				mCurrFadeLevel = mTargetFadeLevel;
			}
		} else if (mCurrFadeLevel > mTargetFadeLevel) {
			mCurrFadeLevel -= 2.0f * gsys->getFrameTime();
			if (mCurrFadeLevel < mTargetFadeLevel) {
				mCurrFadeLevel = mTargetFadeLevel;
			}
		}

		if (mCurrDesaturationLevel < mTargetDesaturationLevel) {
			mCurrDesaturationLevel += 2.0f * gsys->getFrameTime();
			if (mCurrDesaturationLevel > mTargetDesaturationLevel) {
				mCurrDesaturationLevel = mTargetDesaturationLevel;
			}
		} else if (mCurrDesaturationLevel > mTargetDesaturationLevel) {
			mCurrDesaturationLevel -= 2.0f * gsys->getFrameTime();
			if (mCurrDesaturationLevel < mTargetDesaturationLevel) {
				mCurrDesaturationLevel = mTargetDesaturationLevel;
			}
		}

		// draw any fading or desaturation that's happening
		if (mCurrDesaturationLevel > 0.0f || mCurrFadeLevel > 0.0f) {
			Matrix4f orthoMtx;
			gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));

			// apply desaturated blur texture to desired level
			GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
			gfx.setColour(Colour(160, 160, 160, (int)(mCurrDesaturationLevel * 255.0f)), true);
			gfx.useTexture(mBlurResultTexture, GX_TEXMAP0);
			gfx.drawRectangle(AREA_FULL_SCREEN(gfx), RectArea(0, 0, mBlurResultTexture->mWidth, mBlurResultTexture->mHeight), nullptr);

			GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
			gfx.setColour(Colour(0, 0, 0, int(mCurrFadeLevel * 255.0f)), true);
			gfx.useTexture(nullptr, GX_TEXMAP0);
			gfx.fillRectangle(AREA_FULL_SCREEN(gfx));
		}

		// draw debug triangle outlines
		if (mDebugCollCount) {
			int blend     = gfx.setCBlending(BLEND_Alpha);
			bool lighting = gfx.setLighting(false, nullptr);
			gfx.setFog(false);
			gfx.useTexture(nullptr, GX_TEXMAP0);
			gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

			Colour colours[DCLR_COUNT];
			colours[DCLR_Yellow].set(255, 255, 0, 255); // yellow
			colours[DCLR_Red].set(255, 0, 0, 255);      // red
			colours[DCLR_Blue].set(0, 0, 255, 255);     // blue

			Vector3f vecs[3];

			for (int i = 0; i < mDebugCollCount; i++) {
				vecs[0] = mDebugCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mDebugCollisions[i].mParentCollGroup->mVertexList[mDebugCollisions[i].mTriangle->mVertexIndices[0]];
				vecs[1] = mDebugCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mDebugCollisions[i].mParentCollGroup->mVertexList[mDebugCollisions[i].mTriangle->mVertexIndices[1]];
				vecs[2] = mDebugCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mDebugCollisions[i].mParentCollGroup->mVertexList[mDebugCollisions[i].mTriangle->mVertexIndices[2]];

				for (int j = 0; j < 3; j++) {
					gfx.setColour(colours[mDebugCollisions[i].mColorCategory], true);
					gfx.drawLine(vecs[j % 3], vecs[(j + 1) % 3]);
					gfx.drawPoints(&vecs[j % 3], 1);
				}
			}

			// draw triangle counts to screen
			gfx.setColour(COLOUR_WHITE, true);
			Vector3f triCountTextPos(mDebugFocusPosition.x, mDebugFocusPosition.y + 50.0f, mDebugFocusPosition.z);
			triCountTextPos.multMatrix(gfx.mCamera->mLookAtMtx);

			char debugText[PATH_MAX];
			if (AIPerf::showColls) {
				sprintf(debugText, "%d / %d", mActiveTriCount, mDebugCollCount);
			} else {
				sprintf(debugText, "%d", mDebugCollCount);
			}

			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.perspPrintf(gsys->mConsFont, triCountTextPos, -(gsys->mConsFont->stringWidth(debugText) / 2), 0, debugText);

			// draw each triangle's distance from our local collision box
			for (int i = 0; i < mDebugCollCount; i++) {
				Vector3f vert1(mDebugCollisions[i].mParentCollGroup->mVertexList[mDebugCollisions[i].mTriangle->mVertexIndices[0]]);
				Vector3f vert2(mDebugCollisions[i].mParentCollGroup->mVertexList[mDebugCollisions[i].mTriangle->mVertexIndices[1]]);
				Vector3f vert3(mDebugCollisions[i].mParentCollGroup->mVertexList[mDebugCollisions[i].mTriangle->mVertexIndices[2]]);

				// round vertices down for less jitter I suppose?
				vert1.x = (int)vert1.x;
				vert1.z = (int)vert1.z;

				vert2.x = (int)vert2.x;
				vert2.z = (int)vert2.z;

				vert3.x = (int)vert3.x;
				vert3.z = (int)vert3.z;

				f32 distFromCaptainCollision = triRectDistance(&vert1, &vert2, &vert3, collExtents, false);

				Vector3f triangleTextPos = vert1 + vert2 + vert3;
				triangleTextPos.multiply(1.0f / 3.0f);
				triangleTextPos = triangleTextPos + mDebugCollisions[i].mTriangle->mTriangle.mNormal * 10.0f;
				triangleTextPos.multMatrix(gfx.mCamera->mLookAtMtx);
				sprintf(debugText, "%.1f", distFromCaptainCollision);
				gfx.perspPrintf(gsys->mConsFont, triangleTextPos, -(gsys->mConsFont->stringWidth(debugText) / 2), 0, debugText);
			}

			// draw our fun two boxes indicating collision and far culling
			gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

			if (AIPerf::showColls) {
				gfx.setColour(Colour(255, 128, 255, 255), true); // magenta, inner box
				mActiveCollisionBounds.draw(gfx);
			}

			gfx.setColour(Colour(64, 255, 255, 255), true); // cyan, outer box
			mOuterCollRenderBounds.draw(gfx);
			gfx.setFog(true);
			gfx.setLighting(lighting, nullptr);
			gfx.setCBlending(blend);
		}

		mDebugCollCount = 0;
		mActiveTriCount = 0;
		MATCHING_STOP_TIMER("mapPost");
		gfx.mHasTexGen = FALSE;
	}
}

/**
 * @brief Updates unused `SoftLight`s with the current interaction position. Does nothing.
 *
 * @param x X position to check interactions from - only called with captain's x position.
 * @param z Z position to check interactions from - only called with captain's z position.
 */
void MapMgr::updatePos(f32 x, f32 z)
{
	Vector3f pos(x, 0.0f, z);
	if (mSoftLightMgr) {
		gsys->mTimer->start("touchLights", true);
		mSoftLightMgr->touchLights(pos);
		gsys->mTimer->stop("touchLights");
	}
}

/**
 * @brief Does nothing. Potentially would've done something with the unused `SoftLight`'s accumulators.
 *
 * @return 1 always.
 */
f32 MapMgr::getLight(f32, f32)
{
	return 1.0f;
}

/**
 * @brief Builds a linked list of collision groups intersecting with the given x,z position, optionally including platform collision.
 *
 * Will test if x,z lies within platform collision bounds, or gets whatever collision groups intersect with the map grid containing x,z.
 *
 * @param x X position to test.
 * @param z Z position to test.
 * @param includePlatColl Whether to test and include any platform collision triangles in the result.
 * @return Pointer to first element of a linked list of collision groups that intersect x,z - each containing a list of triangles.
 */
CollGroup* MapMgr::getCollGroupList(f32 x, f32 z, bool includePlatColl)
{
	CollGroup* collList = nullptr;
	// optionally check platform collision for any visible collision
	if (includePlatColl) {
		FOREACH_NODE(DynCollShape, mCollShapeList->mChild, coll)
		{
			if (x >= coll->mBoundingBox.mMin.x && x < coll->mBoundingBox.mMax.x && z >= coll->mBoundingBox.mMin.z
			    && z < coll->mBoundingBox.mMax.z && coll->mCollisionModel->mSystemFlags & ShapeFlags::IsPlatform) {
				for (int i = 0; i < coll->mCollGroupCount; i++) {
					if (coll->mJointVisibility[coll->mCollGroupList[i]->mJointIndex]) {
						coll->mCollGroupList[i]->mNextCollGroup = collList;
						collList                                = coll->mCollGroupList[i];
					}
				}
			}
		}
	}

	// get regular static map collision triangles
	CollGroup* mapColl = mMapModel->getCollTris(Vector3f(x, 0.0f, z));
	if (mapColl && mapColl->mTriCount) {
		mapColl->mNextCollGroup = collList;
		collList                = mapColl;
	}

	return collList;
}

/**
 * @brief Gets the *highest* valid ground height at a given x,z position, optionally considering platform collision.
 *
 * This is poorly named, since it actually gets the highest valid ground (to pop up to, for example).
 *
 * @param x X position to project vertically.
 * @param z Z position to project vertically.
 * @param includePlatColl Whether to consider platform collision as valid "ground" to return.
 * @return Maximum Y value found, or 0.0f if none.
 */
f32 MapMgr::getMinY(f32 x, f32 z, bool includePlatColl)
{
	// track how many times we call this each frame for some reason
	mMinMaxYQueryCount++;

	// lowest possible value so it will always snap up to max actual collision
	f32 maxY = -32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, includePlatColl); colls; colls = colls->mNextCollGroup) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->mFarCulledTriCount : colls->mTriCount;
		// if everything's culled, just include everything
		if (count == 0) {
			count = colls->mTriCount;
		}

		// check for any triangles that aren't facing "down"
		for (int i = 0; i < count; i++) {
			if (colls->mTriangleList[i]->mTriangle.mNormal.y > 0.0f) {
				Vector3f triPos(x, 0.0f, z);
				if (colls->mTriangleList[i]->inTriClampTo(triPos) && triPos.y > maxY) {
					maxY = triPos.y;
				}
			}
		}
	}

	// we found no valid collision, return 0
	if (maxY == -32768.0f) {
		return 0.0f;
	}
	return maxY;
}

/**
 * @brief Gets the *lowest* valid ground height at a given x,z position, optionally considering platform collision.
 *
 * This is poorly named, since it actually gets the lowest valid ground (to stop from falling, etc).
 * Will not return any collision below -2500 units.
 *
 * @param x X position to project vertically.
 * @param z Z position to project vertically.
 * @param includePlatColl Whether to consider platform collision as valid "ground" to return.
 * @return Minimum Y value found, or 0.0f if none.
 */
f32 MapMgr::getMaxY(f32 x, f32 z, bool includePlatColl)
{
	// track how many times we call this each frame for some reason
	mMinMaxYQueryCount++;

	// highest possible value so it will always snap up to min actual collision
	f32 minY = 32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, includePlatColl); colls; colls = colls->mNextCollGroup) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->mFarCulledTriCount : colls->mTriCount;
		// if everything's culled, just include everything
		if (count == 0) {
			count = colls->mTriCount;
		}

		// check for any triangles that aren't facing "down"
		for (int i = 0; i < count; i++) {
			if (colls->mTriangleList[i]->mTriangle.mNormal.y > 0.0f) {
				Vector3f triPos(x, 0.0f, z);
				if (colls->mTriangleList[i]->inTriClampTo(triPos) && triPos.y > -2500.0f && triPos.y < minY) {
					minY = triPos.y;
				}
			}
		}
	}

	if (minY == 32768.0f) {
		return 0.0f;
	}
	return minY;
}

/**
 * @brief Gets the highest triangle underneath the given x,z position.
 *
 * @param x X position to project vertically.
 * @param z Z position to project vertically.
 * @param includePlatColl Whether to consider platform collision as valid "ground" to return.
 * @return Pointer to highest triangle underneath position, or `nullptr` if none found.
 */
CollTriInfo* MapMgr::getCurrTri(f32 x, f32 z, bool includePlatColl)
{
	// track how many times we call this each frame for some reason
	mCurrTriQueryCount++;

	CollTriInfo* tri = nullptr;

	// project point into each triangle, and return triangle where point has highest y value.
	f32 maxY = -32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, includePlatColl); colls; colls = colls->mNextCollGroup) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->mFarCulledTriCount : colls->mTriCount;
		// if everything's culled, just include everything
		if (count == 0) {
			count = colls->mTriCount;
		}

		// triangle orientation does *not* matter for this check, unlike getMinY/getMaxY
		for (int i = 0; i < count; i++) {
			Vector3f triPos(x, 0.0f, z);
			if (colls->mTriangleList[i]->inTriClampTo(triPos) && triPos.y > maxY) {
				tri  = colls->mTriangleList[i];
				maxY = triPos.y;
			}
		}
	}
	return tri;
}

/**
 * @brief Checks if a sphere of given center and radius penetrates any edge or vertex of a given triangle, and returns penetration depth and
 * normal if so.
 *
 * @param tri Triangle to check against.
 * @param vertexList List of vertices to get the triangle vertices from, based on the triangle's stored vertex indices.
 * @param sphereCenter Center of sphere to test.
 * @param sphereRadius Radius of sphere to test.
 * @param outNormal Unit vector from closest edge point or vertex to sphere center.
 * @return Penetration depth, if intersecting; 0.0f if not intersecting.
 */
f32 MapMgr::findEdgePenetration(CollTriInfo& tri, immut Vector3f* vertexList, immut Vector3f& sphereCenter, f32 sphereRadius,
                                Vector3f& outNormal)
{
	// check each edge in turn
	for (int i = 0; i < 3; i++) {
		f32 dist = tri.mEdgePlanes[i].dist(sphereCenter);
		// check if we're a) centered outside the triangle, and b) radius intersects some part of the edge
		if (dist < 0.0f && dist >= -sphereRadius) {
			immut Vector3f& edgeStart = vertexList[tri.mVertexIndices[i % 3]];
			immut Vector3f& edgeEnd   = vertexList[tri.mVertexIndices[(i + 1) % 3]];

			Vector3f edgeVec = edgeEnd - edgeStart;
			f32 edgeSqrLen   = edgeVec.x * edgeVec.x + edgeVec.y * edgeVec.y + edgeVec.z * edgeVec.z;
			// calc normalised edge parameter - between 0 and 1 = edge point is closest; < 0 or > 1 = vertex is closest
			f32 t = edgeVec.DP(sphereCenter - edgeStart) / edgeSqrLen;
			if (t >= 0.0f && t < 1.0f) {
				// closest point is on an edge - get the position
				Vector3f edgePos(edgeVec.x * t + edgeStart.x, edgeVec.y * t + edgeStart.y, edgeVec.z * t + edgeStart.z);
				// calc direction from closest point to sphere center
				Vector3f dirEdge(sphereCenter.x - edgePos.x, sphereCenter.y - edgePos.y, sphereCenter.z - edgePos.z);
				outNormal.set(dirEdge.x, dirEdge.y, dirEdge.z);
				f32 distEdge = outNormal.normalise(); // normalise and return distance
				if (distEdge < sphereRadius) {
					return distEdge;
				}
			} else {
				// closest point is one of the two vertices - try the "start" one first
				Vector3f dirStartVtx(sphereCenter.x - edgeStart.x, sphereCenter.y - edgeStart.y, sphereCenter.z - edgeStart.z);
				f32 distStartVtx = dirStartVtx.normalise();
				if (distStartVtx < sphereRadius) {
					outNormal.set(dirStartVtx.x, dirStartVtx.y, dirStartVtx.z);
					return distStartVtx;
				}

				// otherwise, try "end" one
				Vector3f dirEndVtx(sphereCenter.x - edgeEnd.x, sphereCenter.y - edgeEnd.y, sphereCenter.z - edgeEnd.z);
				f32 distEndVtx = dirEndVtx.normalise();
				if (distEndVtx < sphereRadius) {
					outNormal.set(dirEndVtx.x, dirEndVtx.y, dirEndVtx.z);
					return distEndVtx;
				}
			}
		}
	}

	// no penetration found
	return 0.0f;
}

/**
 * @brief Performs a single movement/collision resolution step for a moving sphere against a list of collision.
 *
 * Handles bouncing and penetration resolution. Farms out work from `traceMove` once we've narrowed down any collision.
 *
 * @param collGroupList Pointer to first `CollGroup` in a list, each one having relevant collision to resolve.
 * @param trace Movement information for object, both for supply and for return.
 * @param timeStep Time to simulate movement over.
 */
void MapMgr::recTraceMove(CollGroup* collGroupList, MoveTrace& trace, f32 timeStep)
{
	f32 collisionMargin;

	// compute the tentative movement vector
	Vector3f stepVelocity(trace.mVelocity);
	stepVelocity.multiply(timeStep * trace.mStepFraction);
	if (stepVelocity.length() >= trace.mRadius) {
		PRINT("speed violation!! %f\n", stepVelocity.length());
	}

	// calculate tentative next position and radii for collision tests
	Vector3f proposedPosition = trace.mPosition + stepVelocity;
	Vector3f* v               = &stepVelocity; // this is just for stack fixing
	collisionMargin           = 0.05f;
	f32 expandedRadius        = trace.mRadius + collisionMargin;
	f32 contractedRadius      = trace.mRadius - 0.05f;
	u8 farCullRadius          = expandedRadius;

	// build checking box around new point, with a radius a little larger than the trace radius
	BoundBox collCheckBox;
	collCheckBox.expandBound(proposedPosition);
	collCheckBox.mMin.sub(Vector3f(expandedRadius, expandedRadius, expandedRadius));
	collCheckBox.mMax.add(Vector3f(expandedRadius, expandedRadius, expandedRadius));

	// check all provided collision groups, to see how many triangles we need to check
	CollGroup* currGroup = collGroupList;
	Vector3f lastMapCollNormal;
	bool collidedWithMap = false;

	for (currGroup; currGroup; currGroup = currGroup->mNextCollGroup) {
		int activeTriCount = currGroup->mTriCount - currGroup->mFarCulledTriCount;
		if (!activeTriCount) {
			// if everything is far culled, treat it as a bit suspicious and check them all anyway
			activeTriCount = collGroupList->mTriCount;
		}

		for (int i = 0; i < currGroup->mTriCount; i++) {
			CollTriInfo* tri = currGroup->mTriangleList[i];
			if (AIPerf::showColls && i >= activeTriCount && currGroup->mFarCulledTriDistances[i - activeTriCount] > farCullRadius + 4) {
				// if we can guarantee that tris are sorted from nearest to farthest, we can just straight up skip this group
				if (AIPerf::useCollSort) {
					break;
				}
				// current triangle is culled, skip it
				continue;
			}

			// pretty sure this is just used here
			enum {
				NoCollision       = 0,
				FaceCollision     = 1,
				BoundaryCollision = 2,
			};

			int collisionType = NoCollision; // no collision
			Vector3f collNormal(tri->mTriangle.mNormal);
			f32 collRadius = trace.mRadius;
			f32 penDepth   = tri->mTriangle.dist(proposedPosition);

			// if triangle is within trace radius of tentative position AND we're above it, we have some collision happening
			if (penDepth < collRadius && penDepth > 0.0f) {

				if (tri->behindEdge(proposedPosition) == -1) {
					// no edge collision, so must be face collision (i.e. inside triangle)
					collisionType = FaceCollision;
				} else {
					// check edge collision again to be sure
					penDepth = findEdgePenetration(*tri, currGroup->mVertexList, proposedPosition, collRadius, collNormal);
					if (penDepth != 0.0f) {
						// trace sphere collides with one of the triangle edges or vertices
						collisionType = BoundaryCollision;
					}
				}
			}

			if (collisionType == NoCollision) {
				// nothing left to do if we don't collide with the triangle
				continue;
			}

			// handle bouncing!
			f32 bounceFactor = 1.0f;
			if (trace.mObject && trace.mObject->mProps) {
				// get elasticity from object if possible
				bounceFactor = trace.mObject->mProps->mCreatureProps.mBounceFactor();
			}
			if (trace.mObject) {
				trace.mObject->mCollisionOccurred = 1;
			}
			PRINT_IF(false, ">> before bounce : n(%.1f,%.1f,%.1f) vel(%.1f,%.1f,%.1f) p(%.1f,%.1f,%.1f) %s :%.1f %.1f\n", collNormal.x,
			         collNormal.y, collNormal.z, stepVelocity.x, stepVelocity.y, stepVelocity.z, proposedPosition.x, proposedPosition.y,
			         proposedPosition.z, currGroup->mPlatCollision ? "PLATFORM" : "MAP", penDepth, collRadius);

			bool ignorePlatform = false;
			if (!currGroup->mPlatCollision) {
				// no platform collision => map collision - bounce!
				collidedWithMap   = true;
				lastMapCollNormal = collNormal;
				trace.mVelocity.bounce(collNormal, bounceFactor);
				stepVelocity.bounce(collNormal, bounceFactor);

			} else if (collidedWithMap && lastMapCollNormal.DP(collNormal) < -0.5f) {
				// we just bounced from map collision into the "wrong side" of a platform, ignore it
				ignorePlatform = true;
				PRINT_IF(false, "ignore platform\n");

			} else {
				if (trace.mObject && currGroup->mPlatCollision && currGroup->mPlatCollision->mCreature) {
					// platform collision always has an elasticity of 1
					bounceFactor = 1.0f;
				}
				trace.mVelocity.bounce(collNormal, bounceFactor);
				stepVelocity.bounce(collNormal, bounceFactor);
			}

			PRINT_IF(false, ">> after bounce : n(%.1f,%.1f,%.1f) vel(%.1f,%.1f,%.1f) p(%.1f,%.1f,%.1f) %s\n", collNormal.x, collNormal.y,
			         collNormal.z, stepVelocity.x, stepVelocity.y, stepVelocity.z, proposedPosition.x, proposedPosition.y,
			         proposedPosition.z, currGroup->mPlatCollision ? "PLATFORM" : "MAP");

			if (!ignorePlatform) {
				// resolve any penetration
				proposedPosition.x += collNormal.x * (collRadius - penDepth);
				proposedPosition.y += collNormal.y * (collRadius - penDepth);
				proposedPosition.z += collNormal.z * (collRadius - penDepth);
			}

			if (trace.mObject) {
				// update object's collision information
				// if triangle is sufficiently "flat", save it as a ground triangle
				if (collNormal.y > 0.6f) {
					trace.mObject->mGroundTriangle     = tri;
					trace.mObject->mCurrCollisionModel = currGroup->mModel;
				}

				// if collision is too close to vertical, call it a wall and do the appropriate callback
				if (collisionType != NoCollision && tri->mTriangle.mNormal.y < 0.5f && tri->mTriangle.mNormal.y > -0.5f) {
					trace.mObject->wallCallback(tri->mTriangle, currGroup->mPlatCollision);
				}
				trace.mObject->mCollPlatform = currGroup->mPlatCollision;
				trace.mObject->mCollNormal   = &tri->mTriangle.mNormal;

				if (currGroup->mPlatCollision && trace.mObject->mObjType == OBJTYPE_Piki) {
					// update piki's platform triangle (often used for climbing sticks, but also used for sticking to objects)
					trace.mObject->mPikiPlatformTriangle = tri;
				} else {
					trace.mObject->mPikiPlatformTriangle = nullptr;
				}

				// if we touched the platform, do the appropriate callback
				if (currGroup->mPlatCollision) {
					if (collisionType == FaceCollision && currGroup->mPlatCollision->mLastContactTick != mCurrTraceTick) {
						// track the number of collisions with this platform this frame, for map sliders
						currGroup->mPlatCollision->mContactTickCount++;
						currGroup->mPlatCollision->mLastContactTick = mCurrTraceTick;
					}
					currGroup->mPlatCollision->touchCallback(tri->mTriangle, proposedPosition, trace.mVelocity);
				}
			}
		}
	}

	// report our position back, now that all our collisions are resolved
	trace.mPosition = proposedPosition;
}

/**
 * @brief Performs a full movement trace for an object over a given time, breaking the movement into substeps when required to avoid
 * tunnelling.
 *
 * Resolves collision at each step by farming out to `recTraceMove`.
 *
 * @param creature Object to trace movement of.
 * @param trace Movement information for object, both for supply and for return.
 * @param timeStep Time to simulate movement over.
 */
void MapMgr::traceMove(Creature* creature, MoveTrace& trace, f32 timeStep)
{
	// account for sphere tracing
	trace.mPosition.add(Vector3f(0.0f, trace.mRadius, 0.0f));

	// find "safe" amount of steps based on speed, timestep and radius
	// double our step count until we can safely stay within the trace radius on a given step
	int safeSubStepCount = 1;
	int doublingCount    = 0;
	for (f32 i = trace.mVelocity.length() * timeStep; doublingCount < 100 && i >= trace.mRadius; i *= 0.5f) {
		doublingCount++;
		safeSubStepCount *= 2;
	}

	// report if we're in insane "we're tracing this object for WAY too long given its speed" territory
	if (doublingCount > 50) {
		PRINT("Too many iterations [cr %08x : rad = %f : spd = %f]!!\n", creature, trace.mRadius, trace.mVelocity.length() * timeStep);
	}

	// increment trace tick to prevent double counting of collision
	mCurrTraceTick++;

	// calc fraction so we can calc our displacement for each step correctly
	trace.mStepFraction = 1.0f / safeSubStepCount;

	for (int i = 0; i < safeSubStepCount; i++) {
		// for each step, set up a box for checking collision
		BoundBox collCheckBox;
		collCheckBox.expandBound(trace.mPosition);
		collCheckBox.mMin.sub(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));
		collCheckBox.mMax.add(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));

		trace.mObject = creature;

		// set up list of any relevant collision that intersects with our box
		CollGroup* collGroup = nullptr;
		if (!trace.mIgnoreDynamicCollision) {
			// unless we're ignoring it, check any dynamic collision parts of the map first
			// (in reality, only pikmin sprouts ignore this)
			FOREACH_NODE(DynCollShape, mCollShapeList->mChild, coll)
			{
				if ((!coll->mCreature || coll->mCreature != creature) && collCheckBox.intersects(coll->mBoundingBox)) {
					for (int j = 0; j < coll->mCollGroupCount; j++) {
						if (coll->mJointVisibility[coll->mCollGroupList[j]->mJointIndex]) {
							coll->mCollGroupList[j]->mModel         = coll->mCollisionModel;
							coll->mCollGroupList[j]->mVertexList    = coll->mVertexList;
							coll->mCollGroupList[j]->mPlatCollision = coll;
							coll->mCollGroupList[j]->mNextCollGroup = collGroup;
							collGroup                               = coll->mCollGroupList[j];
						}
					}
				}
			}
		}

		// also collect any static map collision as well
		CollGroup* mapColls = mMapModel->getCollTris(trace.mPosition);
		if (mapColls && mapColls->mTriCount) {
			mapColls->mModel         = mMapModel;
			mapColls->mVertexList    = mMapModel->mVertexList;
			mapColls->mPlatCollision = nullptr;
			mapColls->mNextCollGroup = collGroup;
			collGroup                = mapColls;
		}

		// we have collision to resolve, farm it out to the sub-function
		if (collGroup) {
			recTraceMove(collGroup, trace, timeStep);

		} else {
			// no collision! we can just move safely
			Vector3f delta(trace.mVelocity);
			delta.multiply(timeStep * trace.mStepFraction);
			trace.mPosition.add(delta);
		}
	}

	// re-account for us using a sphere
	trace.mPosition.sub(Vector3f(0.0f, trace.mRadius, 0.0f));
}

/**
 * @brief Loads the model for a platform from file (or from cache, if already cached).
 *
 * @param modelFilePath Path to model file, relative to data directory.
 * @return Pointer to model.
 */
Shape* MapMgr::loadPlatshape(immut char* modelFilePath)
{
	Shape* model = nullptr;
	// check cache
	GfxobjInfo* info = gsys->findGfxObject(modelFilePath, '_shp');
	if (info) {
		model = ((ShpobjInfo*)info)->mTarget;
	}

	if (!model) {
		// otherwise, load from file - this also re-checks the cache, because why not
		model = gsys->loadShape(modelFilePath, true);
	}
	return model;
}

/**
 * @brief Creates and registers a new platform collision part with an associate creature, from supplied collision info (model and joint).
 *
 * Also adds the part to the global map list of dynamic collision.
 *
 * @param info Collision info to use when setting up part.
 * @param obj Object to associate with new part.
 * @return Pointer to newly created collision part.
 */
CreatureCollPart* MapMgr::requestCollPart(ObjCollInfo* info, Creature* obj)
{
	CreatureCollPart* part = new CreatureCollPart(info->mPlatShape);
	part->mCreature        = obj;
	part->mParentCreature  = obj;
	part->mJointIndex      = info->mJointIndex;
	mCollShapeList->add(part);
	return part;
}

#pragma endregion
//////////////////////////////////////////////////////
/////////////////// SHADOW CASTER ////////////////////
//////////////////////////////////////////////////////
#pragma region SHADOW CASTER

/**
 * @brief Constructs a new shadow caster with default camera parameters and no associated drawer object.
 */
ShadowCaster::ShadowCaster()
    : CoreNode("")
{
	bool togglePrint   = gsys->mTogglePrint;
	gsys->mTogglePrint = TRUE; // no printing happens here or in the DLL?

	// set up default camera parameters
	mLightCamera.mPosition.set(0.0f, 10.0f, 0.0f);
	mLightCamera.mFocus.set(0.0f, 0.0f, 0.00001f);
	mLightCamera.mRotation.set(0.0f, 0.0f, 0.0f);
	mLightCamera.mFov  = 90.0f;
	mLightCamera.mNear = 1.0f;
	mLightCamera.mFar  = 3000.0f;
	gsys->mTogglePrint = togglePrint;

	// no associated object drawer, will always need to be set based on context
	mShadowDrawer = nullptr;
}

/**
 * @brief Creates a light map texture buffer for the shadow's light camera, for drawing shadows with.
 */
void ShadowCaster::initShadow()
{
	PRINT("making shadow buffer!\n");
	mLightCamera.initLightmap(256, TEX_FMT_I8);
}

//////////////////////////////////////////////////////
