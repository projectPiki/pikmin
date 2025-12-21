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
#include "MemStat.h"
#include "MoviePlayer.h"
#include "gameflow.h"
#include "sysNew.h"
#include "timers.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("mapMgr")

/**
 * @brief Fabricated name. Some struct has to exist here, but I don't think it's exposed anywhere.
 */
struct SoftLightLight {
	u32 mLastUpdateTick;       // _00
	SoftLightLight* mNext;     // _04
	u8* mColorChannels;        // _08
	s16 mAccumulatedIntensity; // _0C
};

BoundBox collExtents;
MapMgr* mapMgr;
static f32 Kda;
static u32 numRepeats; // type unsure
static u32 numUpdated; // type unsure
static SoftLightLight* vlink;

/**
 * @brief TODO
 */
struct SoftLight {
	void addLight(u32 p1, LShortColour*, Shape*)
	{
		if (mSublightList) {
			for (int i = 0; i < mLightListSize; i++) {
				if (mSublightList[i]->mLastUpdateTick != p1) {
					mSublightList[i]->mNext           = vlink;
					vlink                             = mSublightList[i];
					mSublightList[i]->mLastUpdateTick = p1;
				}
				mSublightList[i]->mAccumulatedIntensity += (mIntensityScales[i] * mEffectiveColour.r) >> 8;
			}
		}
	}
	void subLight(LShortColour*)
	{
		if (mSublightList) {
			for (int i = 0; i < mLightListSize; i++) {
				mSublightList[i]->mAccumulatedIntensity -= (mIntensityScales[i] * mEffectiveColour.r) >> 8;
			}
		}

		FORCE_DONT_INLINE;
	}

	Vector3f mPosition;             // _00
	Colour mEffectiveColour;        // _0C
	Colour mBaseColour;             // _10
	f32 mInteractionRadius;         // _14
	f32 mTargetPhaseAngle;          // _18
	f32 mCurrentPhaseAngle;         // _1C
	int mGroupId;                   // _20
	int mIsAnimFast;                // _24
	int mLightListSize;             // _28
	u8 _2C;                         // _2C
	SoftLightLight** mSublightList; // _30
	s16* mIntensityScales;          // _34
};

/**
 * @brief TODO
 */
struct MapLightMgr {

	void updateLights()
	{
		mCurrentUpdateTick++;
		numUpdated = 0;
		numRepeats = 0;
		vlink      = nullptr;

		for (int i = 0; i < mLightCount; i++) {
			sinf(mLights[i]->mCurrentPhaseAngle);

			bool check = false;
			if (mLights[i]->mCurrentPhaseAngle != mLights[i]->mTargetPhaseAngle) {
				f32 a = (mLights[i]->mIsAnimFast) ? 2.0f : 0.5f;
				mLights[i]->mCurrentPhaseAngle
				    += gsys->getFrameTime() * a * (mLights[i]->mTargetPhaseAngle - mLights[i]->mCurrentPhaseAngle);
				check = true;
			}

			if (check) {
				if (!mLights[i]->_2C) {
					mLights[i]->subLight(mAmbientColor);
				}
				mLights[i]->_2C = 0;
				f32 a           = sinf(mLights[i]->mCurrentPhaseAngle);
				if (a > 0.95f) {
					mLights[i]->mCurrentPhaseAngle = mLights[i]->mTargetPhaseAngle;
				}

				mLights[i]->mEffectiveColour.set(mLights[i]->mBaseColour.r * a, mLights[i]->mBaseColour.g * a,
				                                 mLights[i]->mBaseColour.b * a, 255);
				mLights[i]->addLight(mCurrentUpdateTick, mAmbientColor, mDefaultShape);
			}
		}

		if (vlink) {
			for (SoftLightLight* c = vlink; c; c = c->mNext) {
				u8 a                 = (c->mAccumulatedIntensity < 255) ? (u8)c->mAccumulatedIntensity : 255;
				c->mColorChannels[0] = a;
				c->mColorChannels[1] = a;
				c->mColorChannels[2] = a;
				c->mColorChannels[3] = a;
			}
		}
	}

	void touchLights(immut Vector3f& pos)
	{
		for (int i = 0; i < mLightCount; i++) {
			if (mLights[i]->mTargetPhaseAngle != HALF_PI) {
				f32 a = (mLights[i]->mIsAnimFast) ? mLights[i]->mInteractionRadius * 0.5f : mLights[i]->mInteractionRadius * 1.5f;
				if (mLights[i]->mPosition.distance(pos) < a) {
					mLights[i]->mTargetPhaseAngle = HALF_PI;
				}

				if (mLights[i]->mIsAnimFast) {
					for (int j = 0; j < mLightCount; j++) {
						if (i != j && mLights[j]->mGroupId == mLights[i]->mGroupId && mLights[j]->mCurrentPhaseAngle > 0.4f) {
							f32 d = mLights[i]->mPosition.distance(mLights[j]->mPosition);
							if (d < mLights[i]->mInteractionRadius) {
								mLights[i]->mTargetPhaseAngle = HALF_PI;
							}
						}
					}
				}
			}
		}
	}

	Shape* mDefaultShape;        // _00
	SoftLight** mLights;         // _04
	u8 padding[0x4];             // _08, unknown
	int mLightCount;             // _0C
	LShortColour* mAmbientColor; // _10
	u32 mCurrentUpdateTick;      // _14
};

/*
 * --INFO--
 * Address:	800617C0
 * Size:	000268
 */
void DynCollShape::createDupCollData()
{
	mVertexList = new Vector3f[mShape->mVertexCount];
	memcpy(mVertexList, mShape->mVertexList, mShape->mVertexCount * sizeof(Vector3f));

	mCollTriList = new CollTriInfo[mShape->mTriCount];
	memcpy(mCollTriList, mShape->mTriList, mShape->mTriCount * sizeof(CollTriInfo));

	mColliderList = nullptr;
	mVisibleList  = new bool[mShape->mJointCount];
	for (int i = 0; i < mShape->mJointCount; i++) {
		mVisibleList[i] = mShape->mJointList[i].mFlags != 0;
	}

	if (mShape->mBaseRoomCount <= 0) {
		return;
	}
	mColliderCount = mShape->mBaseRoomCount;
	mColliderList  = new CollGroup*[mColliderCount];
	for (int i = 0; i < mShape->mBaseRoomCount; i++) {
		int tris = 0;
		for (int j = 0; j < mShape->mTriCount; j++) {
			if (i == mCollTriList[j].mCollRoomId) {
				tris++;
			}
		}

		mColliderList[i]                = new CollGroup;
		mColliderList[i]->mRoomIndex    = mShape->mRoomInfoList[i].mIndex;
		mColliderList[i]->mTriCount     = tris;
		mColliderList[i]->mTriangleList = new CollTriInfo*[mColliderList[i]->mTriCount];

		int t = 0;
		for (int j = 0; j < mShape->mTriCount; j++) {
			if (mCollTriList[j].mCollRoomId == i) {
				mColliderList[i]->mTriangleList[t] = &mCollTriList[j];
				t++;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001FC
 */
void DynCollShape::drawAtari(Graphics& gfx)
{
	gfx.setCamera(gfx.mCamera);
	gfx.initRender(0, 0);

	gfx.setColour(Colour(255, 255, 0, 255), true);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setPointSize(4.0f);
	gfx.drawPoints(mVertexList, mShape->mVertexCount);

	gfx.setColour(Colour(255, 0, 0, 255), true);
	for (int i = 0; i < mShape->mTriCount; i++) {
		for (int j = 0; j < 3; j++) {
			int id = (j + 1) % 3;
			Vector3f start(mVertexList[mCollTriList[i].mVertexIndices[j]]);
			Vector3f end(mVertexList[mCollTriList[i].mVertexIndices[id]]);
			gfx.drawLine(start, end);
		}
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80061A28
 * Size:	0003CC
 */
void DynCollShape::updatePos()
{
	mBoundingBox.resetBound();
	for (int i = 0; i < mShape->mVertexCount; i++) {
		mVertexList[i].x = mTransformMtx.mMtx[0][0] * mShape->mVertexList[i].x + mTransformMtx.mMtx[0][1] * mShape->mVertexList[i].y
		                 + mTransformMtx.mMtx[0][2] * mShape->mVertexList[i].z + mTransformMtx.mMtx[0][3];
		mVertexList[i].y = mTransformMtx.mMtx[1][0] * mShape->mVertexList[i].x + mTransformMtx.mMtx[1][1] * mShape->mVertexList[i].y
		                 + mTransformMtx.mMtx[1][2] * mShape->mVertexList[i].z + mTransformMtx.mMtx[1][3];
		mVertexList[i].z = mTransformMtx.mMtx[2][0] * mShape->mVertexList[i].x + mTransformMtx.mMtx[2][1] * mShape->mVertexList[i].y
		                 + mTransformMtx.mMtx[2][2] * mShape->mVertexList[i].z + mTransformMtx.mMtx[2][3];
		mBoundingBox.expandBound(mVertexList[i]);
	}

	for (int i = 0; i < mShape->mTriCount; i++) {
		mShape->mTriList[i].mTriangle.mNormal.rotateTo(mTransformMtx, mCollTriList[i].mTriangle.mNormal);
		mCollTriList[i].mTriangle.mNormal.normalise();
		mCollTriList[i].mTriangle.mOffset = mCollTriList[i].mTriangle.mNormal.DP(mVertexList[mCollTriList[i].mVertexIndices[0]]);
		for (int j = 0; j < 3; j++) {
			mShape->mTriList[i].mEdgePlanes[j].mNormal.rotateTo(mTransformMtx, mCollTriList[i].mEdgePlanes[j].mNormal);
			mCollTriList[i].mEdgePlanes[j].mNormal.normalise();
			mCollTriList[i].mEdgePlanes[j].mOffset
			    = mCollTriList[i].mEdgePlanes[j].mNormal.DP(mVertexList[mCollTriList[i].mVertexIndices[j]]);
		}
	}
}

/*
 * --INFO--
 * Address:	80061DF4
 * Size:	000044
 */
void DynCollShape::jointVisible(int id, int set)
{
	FOREACH_NODE(Joint, mShape->mJointList[id].mParent->mChild, jnt)
	{
		mVisibleList[jnt->mIndex] = set != 0;
	}
}

/*
 * --INFO--
 * Address:	80061E38
 * Size:	000094
 */
void DynCollShape::adjust(Creature* obj)
{
	obj->mPositionInShapeSpace = obj->mSRT.t;
	obj->mPositionInShapeSpace.multMatrix(mInverseMatrix);
	obj->mSRT.t = obj->mPositionInShapeSpace;
	obj->mSRT.t.multMatrix(mTransformMtx);
	obj->mLastPosition = obj->mSRT.t;
}

/*
 * --INFO--
 * Address:	80061ECC
 * Size:	000048
 */
void DynCollShape::update()
{
	mTransformMtx.inverse(&mInverseMatrix);
	mTransformMtx.makeSRT(mScale, mRotation, mPosition);
}

/*
 * --INFO--
 * Address:	80061F14
 * Size:	00003C
 */
void DynCollShape::updateContext()
{
	for (int i = 0; i < mShape->mJointCount; i++) {
		mShape->mJointList[i].mFlags = mVisibleList[i];
	}
}

/*
 * --INFO--
 * Address:	80061F50
 * Size:	000064
 */
void DynCollShape::refresh(Graphics& gfx)
{
	updateContext();
	mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	80061FB4
 * Size:	000034
 */
void MapObjAnimator::finishOneShot()
{
	mPlayState = 0;

	if (mMapObj) {
		mMapObj->nextState();
	}

	PRINT("%08x : finished animation : %f!!\n", this, mAnimationCounter);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000364
 */
DynMapObject::DynMapObject(MapMgr* map, MapAnimShapeObject* obj)
    : DynCollShape(obj->mShape)
{
	mShapeObject      = obj;
	mShape            = mShapeObject->mShape;
	mAnimator.mMapObj = this;
	mAnimator.init(&mShapeObject->mAnimContext, mShapeObject->mMgr);
	mAnimator.startAnim(ANIMSTATE_Inactive, 0, 0, 8);
	mState  = 0;
	mMapMgr = map;
	mShadowCaster.initCore("");
	mShadowCaster.mDrawer           = this;
	mShadowCaster.mLightCamera.mFov = 20.0f;
	mScale.set(1.0f, 1.0f, 1.0f);
	mRotation.set(0.0f, 0.0f, 0.0f);
	mPosition.set(0.0f, 0.0f, 0.0f);
	mObjCount = 0;
	for (ObjCollInfo* info = (ObjCollInfo*)mShape->mCollisionInfo.mParentShape->Child(); info; info = (ObjCollInfo*)info->mNext) {
		if (info->mPlatShape) {
			mObjCount++;
		}
	}

	mObjects = new MapObjectPart*[mObjCount];
	int i    = 0;
	for (ObjCollInfo* info = (ObjCollInfo*)mShape->mCollisionInfo.mParentShape->Child(); info; info = (ObjCollInfo*)info->mNext) {
		if (info->mPlatShape) {
			MapObjectPart* part = new MapObjectPart(info->mPlatShape);
			part->mMapParent    = this;
			part->mJointIndex   = info->mJointIndex;
			mMapMgr->mCollShape->add(part);
			mObjects[i] = part;
			i++;
		}
	}
}

/*
 * --INFO--
 * Address:	800621A4
 * Size:	000024
 */
void DynMapObject::nextState()
{
	mState++;
	if (mState == 6) {
		mState = 0;
	}
}

/*
 * --INFO--
 * Address:	800621C8
 * Size:	00003C
 */
void DynMapObject::touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&)
{
	switch (mState) {
	case 0:
		mTransitionTimer = 2.0f;
		mState++;
		break;
	case 4:
		mTransitionTimer = 2.0f;
		break;
	}
}

/*
 * --INFO--
 * Address:	80062204
 * Size:	0001A8
 */
void DynMapObject::update()
{
	switch (mState) {
	case 1:
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer < 0.0f) {
			mTransitionTimer = 2.0f;
			mAnimator.startAnim(ANIMSTATE_OneShot, 0, 0, 8);
			mState++;
		}
		break;
	case 3:
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer < 0.0f) {
			mTransitionTimer = 0.0f;
			mState++;
		}
		break;
	case 4:
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer < 0.0f) {
			mTransitionTimer = 0.0f;
			mAnimator.startAnim(ANIMSTATE_OneShot, 1, 0, 8);
			mState++;
		}
		break;

	default:
		break;
	}

	mShadowCaster.mSourcePosition.set(mPosition.x + 100.0f, mPosition.y + 300.0f, mPosition.z + 300.0f);
	mShadowCaster.mTargetPosition.set(mPosition.x, mPosition.y + 100.0f, mPosition.z);
	mAnimator.animate(30.0f);
	DynCollShape::update();
}

/*
 * --INFO--
 * Address:	800623AC
 * Size:	00002C
 */
void DynMapObject::draw(Graphics& gfx)
{
	refresh(gfx);
}

/*
 * --INFO--
 * Address:	800623D8
 * Size:	000184
 */
void DynMapObject::refresh(Graphics& gfx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx1.makeSRT(mScale, mRotation, mPosition);
	gfx.calcViewMatrix(mtx1, mtx2);
	gsys->mTimer->start("animation", true);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx2, nullptr);
	gsys->mTimer->stop("animation");

	for (int i = 0; i < mObjCount; i++) {
		MapObjectPart* part = mObjects[i];
		part->mTransformMtx.inverse(&part->mInverseMatrix);
		Matrix4f animMtx = mShape->getAnimMatrix(part->mJointIndex);
		gfx.mCamera->mInverseLookAtMtx.multiplyTo(animMtx, part->mTransformMtx);
	}

	gfx.useMatrix(Matrix4f::ident, 0);
	mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

static f32 Kdl = 1.25f;
/*
 * --INFO--
 * Address:	8006255C
 * Size:	000030
 */
void DynCollObjBody::touchCallback(immut Plane& plane, immut Vector3f& a1, immut Vector3f& a2)
{
	mParentRigidBody->touchCallback(plane, a1, a2);
}

/*
 * --INFO--
 * Address:	8006258C
 * Size:	000030
 */
void DynCollObjBody::applyVelocity(immut Plane& plane, immut Vector3f& a1, immut Vector3f& a2)
{
	mParentRigidBody->applyVelocity(plane, a1, a2);
}

/*
 * --INFO--
 * Address:	800625BC
 * Size:	0001B8
 */
void DynObjBody::touchCallback(immut Plane& plane, immut Vector3f& p2, immut Vector3f& p3)
{
	if (plane.mNormal.DP(p3) < 0.0f) {
		Vector3f vec = plane.mNormal.DP(p3) * plane.mNormal;
		vec.multiply(mImpactResponseForceScale);
		// why.
		applyForce(0, Vector3f(vec.x, vec.y, vec.z), Vector3f(p2.x, p2.y, p2.z));
	}
}

/*
 * --INFO--
 * Address:	80062774
 * Size:	0001B8
 */
void DynObjBody::applyVelocity(immut Plane& plane, immut Vector3f& p2, immut Vector3f& p3)
{
	if (plane.mNormal.DP(p3) < 0.0f) {
		Vector3f vec = plane.mNormal.DP(p3) * plane.mNormal;
		vec.multiply(mImpactResponseForceScale);
		// why.
		applyForce(0, Vector3f(vec.x, vec.y, vec.z), Vector3f(p2.x, p2.y, p2.z));
	}
}

/*
 * --INFO--
 * Address:	8006292C
 * Size:	000868
 */
void DynObjBody::integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep)
{
	RigidBody::integrate(prevConfigIdx, currConfigIdx, timeStep);
	configuration& config = mIntegrationStates[currConfigIdx];
	config.mLinearVel.set(config.mLinearVel.x * mVelMask.x, config.mLinearVel.y * mVelMask.y, config.mLinearVel.z * mVelMask.z);
	config.mLocalAngularVel.set(config.mLocalAngularVel.x * mAngularVelMask.x, config.mLocalAngularVel.y * mAngularVelMask.y,
	                            config.mLocalAngularVel.z * mAngularVelMask.z);
	OrthonormaliseOrientation(config.mOrientationMtx);
	config.mOrientationQuat.fromMat3f(config.mOrientationMtx);

	config.mInertiaTensor = config.mOrientationMtx * mInertiaTensor * Transpose(config.mOrientationMtx);
	config.mAngularVel    = config.mInertiaTensor * config.mLocalAngularVel;
}

/*
 * --INFO--
 * Address:	80063194
 * Size:	0008A8
 */
void DynObjSeeSaw::integrate(int prevConfigIdx, int currConfigIdx, f32 timeStep)
{
	RigidBody::integrate(prevConfigIdx, currConfigIdx, timeStep);
	configuration& config = mIntegrationStates[currConfigIdx];
	config.mLinearVel.rotate(mPreMaskVelRotationMtx);
	config.mLocalAngularVel.rotate(mPreMaskVelRotationMtx);
	config.mLinearVel.set(config.mLinearVel.x * mVelMask.x, config.mLinearVel.y * mVelMask.y, config.mLinearVel.z * mVelMask.z);
	config.mLocalAngularVel.set(config.mLocalAngularVel.x * mAngularVelMask.x, config.mLocalAngularVel.y * mAngularVelMask.y,
	                            config.mLocalAngularVel.z * mAngularVelMask.z);
	config.mLinearVel.rotate(mPostMaskVelRotationMtx);
	config.mLocalAngularVel.rotate(mPostMaskVelRotationMtx);

	OrthonormaliseOrientation(config.mOrientationMtx);
	config.mOrientationQuat.fromMat3f(config.mOrientationMtx);

	config.mInertiaTensor = config.mOrientationMtx * mInertiaTensor * Transpose(config.mOrientationMtx);
	config.mAngularVel    = config.mInertiaTensor * config.mLocalAngularVel;
}

/*
 * --INFO--
 * Address:	80063A3C
 * Size:	0000F8
 */
void DynObjBody::initRender(int)
{
	mRenderTransformMtx.makeVQS(mRenderPosition, mRenderOrientation, Vector3f(1.0f, 1.0f, 1.0f));
	mCollObj->mTransformMtx.inverse(&mCollObj->mInverseMatrix);
	mCollObj->mTransformMtx = mRenderTransformMtx;
}

/*
 * --INFO--
 * Address:	80063B34
 * Size:	0003E8
 */
void DynObjBody::applyWorldSpring(int configIdx, int attachPointIdx, immut Vector3f& p3)
{
	STACK_PAD_VAR(4);
	configuration& config = mIntegrationStates[configIdx];
	Vector3f attachPt(config.mBodyPoints[attachPointIdx]);
	Vector3f vec2 = attachPt - config.mPosition;
	Vector3f vec3 = config.mLinearVel + CP(config.mAngularVel, vec2);
	Vector3f vec4 = p3 - attachPt;
	f32 b         = vec4.length() - 20.0f;
	f32 c         = 1.3f;
	c += (1.0f - vec4.length() / 20.0f) * 0.2f;
	Vector3f vec5 = vec4 * (b / vec4.length());
	Vector3f vec6 = (vec5.DP(vec3) / vec5.DP(vec5) * -c) * vec5;
	vec5.add(vec6);
	applyForce(configIdx, vec5, attachPt);

	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	80063F1C
 * Size:	0001AC
 */
void DynObjBody::render(Graphics& gfx)
{
	Matrix4f mtx;
	gfx.calcViewMatrix(mRenderTransformMtx, mtx);
	gfx.mCamera->setBoundOffset(&mRenderPosition);
	gfx.useMatrix(mtx, 0);
	gfx.mCamera->setBoundOffset(nullptr);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

	for (int i = 0; i < mSpringCount; i++) {
		gfx.drawLine(mBodySpaceHookPoints[mSprings[i].mHookIdx], mSprings[i].mOffset);
	}
}

/*
 * --INFO--
 * Address:	800640C8
 * Size:	0001E0
 */
void DynObjBody::computeForces(int configIdx, f32 p2)
{
	configuration& config = mIntegrationStates[configIdx];
	CollGroup* coll       = mStaticEnvironmentShape->getCollTris(config.mPosition);
	applyCMForce(Vector3f(0.0f, -140.81f, 0.0f));

	for (int i = 0; i < mSpringCount; i++) {
		applyWorldSpring(configIdx, mSprings[i].mHookIdx, mSprings[i].mOffset);
	}

	MATCHING_START_TIMER("applyGround", true);
	applyGroundForces(configIdx, coll);
	MATCHING_STOP_TIMER("applyGround");

	f32 a = Kdl;
	f32 b = Kda / 1.0f;

	Vector3f vec(-a * config.mLinearVel.x, -a * config.mLinearVel.y, -a * config.mLinearVel.z);
	vec.multiply(mMass);
	mLinearAccel.add(vec);

	Vector3f vec2(-b * config.mAngularVel.x, -b * config.mAngularVel.y, -b * config.mAngularVel.z);
	mAngularAccel.add(vec2);
}

/*
 * --INFO--
 * Address:	800642A8
 * Size:	000268
 */
void DynObjBody::initBodyCollisions()
{
	BoundBox box;
	for (int i = 0; i < mBodyShell->mVertexCount; i++) {
		bool check = false;
		for (int j = 0; j < mBoundingPointCount; j++) {
			if (mBodyShell->mVertexList[i].x == mBodyPoints[j + mHookPointCount].x
			    && mBodyShell->mVertexList[i].y == mBodyPoints[j + mHookPointCount].y
			    && mBodyShell->mVertexList[i].z == mBodyPoints[j + mHookPointCount].z) {
				check = true;
				break;
			}
		}
		if (!check) {
			addBoundingPoint(mBodyShell->mVertexList[i].x, mBodyShell->mVertexList[i].y, mBodyShell->mVertexList[i].z);
			box.expandBound(mBodyShell->mVertexList[i]);
		}
	}

	PRINT("used %d verts\n", mBoundingPointCount);
	mRestitutionFactor = 0.0f;
	initDimensions(box.mMax.x - box.mMin.x, box.mMax.y - box.mMin.y, box.mMax.z - box.mMin.z);
	PRINT("mass = %f\n", mMass);
	mCollObj                   = new DynCollObjBody(mBodyShell);
	mCollObj->mParentRigidBody = this;
}

/*
 * --INFO--
 * Address:	80064510
 * Size:	0003A4
 */
void DynObjBody::readScript(MapMgr* map, immut char* fileName)
{
	RandomAccessStream* stream = gsys->openFile(fileName, true, true);
	if (!stream) {
		return;
	}

	CmdStream* cmds = new CmdStream(stream);
	stream->close();

	while (!cmds->endOfCmds() && !cmds->endOfSection()) {
		cmds->getToken(true);
		if (cmds->isToken("name")) {
			setName(StdSystem::stringDup(cmds->getToken(true)));
			continue;
		}

		if (cmds->isToken("body_shell")) {
			mBodyShell = map->loadPlatshape(cmds->getToken(true));
			continue;
		}

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

		if (cmds->isToken("use_verts")) {
			PRINT("using shapes' vertices\n");
			continue;
		}

		if (cmds->isToken("vel_mask")) {
			sscanf(cmds->getToken(true), "%f", &mVelMask.x);
			sscanf(cmds->getToken(true), "%f", &mVelMask.y);
			sscanf(cmds->getToken(true), "%f", &mVelMask.z);
			continue;
		}

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

/*
 * --INFO--
 * Address:	800648B4
 * Size:	000538
 */
void DynObjPushable::render(Graphics& gfx)
{
	Matrix4f mtx;
	gfx.calcViewMatrix(mRenderTransformMtx, mtx);
	gfx.useMatrix(mtx, 0);

	if (mLinearAccel.length() > 0.0f) {
		mCurrPushStrength = mLinearAccel.length() * mInvMass;
	}

	if (mCurrPushStrength < mMinStrengthToMove) {
		mLinearAccel.set(0.0f, 0.0f, 0.0f);
		mAngularAccel.set(0.0f, 0.0f, 0.0f);
	} else {
		mLinearAccel.normalise();
		mLinearAccel.multiply(mMovingPushStrength);
	}

	bool lighting = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);

	int blend = gfx.setCBlending(0);
	Vector3f vec(0.0f, 90.0f, 0.0f);
	vec.add(mRenderPosition);
	vec.multMatrix(gfx.mCamera->mLookAtMtx);
	char buf[PATH_MAX];
	sprintf(buf, "%.1f", mCurrPushStrength);
	gfx.perspPrintf(gsys->mConsFont, vec, -(gsys->mConsFont->stringWidth(buf) / 2), 0, buf);
	gfx.setCBlending(blend);
	gfx.setLighting(lighting, nullptr);
	DynObjBody::render(gfx);
}

/*
 * --INFO--
 * Address:	80064DEC
 * Size:	0006B0
 */
MapMgr::MapMgr(Controller* controller)
{
	mController         = controller;
	mFadeProgress       = 0.0f;
	mDesaturationLevel  = 0.0f;
	mTargetFadeLevel    = 0.0f;
	mTargetDesaturation = 0.0f;
	effectMgr           = nullptr;
	mBlur               = 145;

	memStat->start("dayMgr");
	mDayMgr = new DayMgr(this, mController);
	memStat->end("dayMgr");

	mCollCheckCount = 0;
	mMapShape       = nullptr;

	mDebugCollCount = 0;
	mMaxDebugColls  = 300;

	if (mMaxDebugColls) {
		memStat->start("collisions");
		mCollisions = new MapColls[mMaxDebugColls];
		memStat->end("collisions");
	}

	memStat->start("collparts");
	mDefaultCollPart = new CreatureCollPart();
	mDefaultCollPart->initCore("");
	memStat->end("collparts");
	mMapBounds.resetBound();

	memStat->start("rooms");
	mMapRooms = new MapRoom[256];
	memStat->end("rooms");

	memStat->start("dyncolshape");
	mCollShape = new DynCollShape(nullptr);
	memStat->end("dyncolshape");

	memStat->start("shadMats");
	mShadowCountdown = 3;
	mShadowCaster.initCore("");
	mShadowHandler                   = new MapShadMatHandler();
	mShadowHandler->mShadMat->mFlags = MATFLAG_OPAQUE;

	mProjHandler                   = new MapProjMatHandler(nullptr);
	mProjHandler->mProjMat->mFlags = MATFLAG_INVERT_BLEND | MATFLAG_OPAQUE;

	mProjHandler->mProjMat->Colour().set(255, 255, 255, 255);
	memStat->end("shadMats");

	memStat->start("blurTextures");
	mCaptureTexture                = new Texture();
	mCaptureTexture->mWidthFactor  = 0.003125f;
	mCaptureTexture->mHeightFactor = 0.004166667f;
	mCaptureTexture->mTexFlags     = 0x105;
	mCaptureTexture->createBuffer(320, 240, 8, nullptr);
	gsys->addTexture(mCaptureTexture, "internalLightmap");
	mBlurredTexture                = new Texture();
	mBlurredTexture->mWidthFactor  = 0.003125f;
	mBlurredTexture->mHeightFactor = 0.004166667f;
	mBlurredTexture->mTexFlags     = 0x105;
	mBlurredTexture->createBuffer(320, 240, 0, nullptr);
	gsys->addTexture(mBlurredTexture, "internalLightmap");
	memStat->end("blurTextures");
}

/*
 * --INFO--
 * Address:	800654B4
 * Size:	000030
 */
void MapMgr::initEffects()
{
	// hmm.
	new EffectMgr;
}

/*
 * --INFO--
 * Address:	800654E4
 * Size:	0003C4
 */
void MapMgr::initShape()
{
	mLightMgr = 0;
	mMapShape = gameflow.loadShape(flowCont.mAnimationTestPath, true);
	mMapShape->mSystemFlags |= ShapeFlags::AlwaysRedraw;
	mMapShape->makeInstance(mDynMaterials, 0);

	for (int i = 0; i < mMapShape->mJointCount; i++) {
		PRINT("got bound (%.1f, %.1f, %.1f) - (%.1f, %.1f, %.1f)\n", mMapShape->mJointList[i].mBounds.mMin.x,
		      mMapShape->mJointList[i].mBounds.mMin.y, mMapShape->mJointList[i].mBounds.mMin.z, mMapShape->mJointList[i].mBounds.mMax.x,
		      mMapShape->mJointList[i].mBounds.mMax.y, mMapShape->mJointList[i].mBounds.mMax.z);
	}

	mMapShape->createCollisions(64);
	mMapBounds.expandBound(mMapShape->mCourseExtents);
	mDynSimulator = new DynSimulator();

	mFixedTimeStep    = 0.016666668f;
	mIntegrationStep  = 0.0125f;
	mLastPhysicsTime  = 0.0f;
	mAccumPhysicsTime = 0.0f;

	// sigh. this is really there.
	// similar code exists in GenObjectMapObject::birth, but the assembly is actually stripped there.
	for (int i = 0; i < 0; i++) {
		DynObjBody* body              = new DynObjBody();
		body->mStaticEnvironmentShape = mMapShape;
		body->readScript(this, "traffic/specLog.ini");
		body->initBodyCollisions();
		body->mInitPosition.set(0.0f, 60.0f, 100.0f);
		body->mInitOrientationZ = Vector3f(1.0f, 0.0f, 0.0f);
		body->mInitOrientationX = Vector3f(0.0f, 1.0f, 0.0f);
		body->mInitOrientationY = Vector3f(0.0f, 0.0f, 1.0f);
		mDynSimulator->add(body);
		mCollShape->add(body->mCollObj);
	}

	mResetPending = true;
}

/*
 * --INFO--
 * Address:	800658C8
 * Size:	000004
 */
void MapMgr::createLights()
{
}

/*
 * --INFO--
 * Address:	800658CC
 * Size:	0000FC
 */
void MapMgr::updateSimulation()
{
	if (mResetPending) {
		mDynSimulator->resetWorld();
		mResetPending            = false;
		mDynSimulator->mIsPaused = false;
	}

	f32 time = gsys->getFrameTime();
	if (!mDynSimulator->isPaused()) {
		mAccumPhysicsTime += time * 1.0f;
		while (mAccumPhysicsTime - mLastPhysicsTime > mFixedTimeStep) {
			if (!mDynSimulator->isPaused()) {
				mDynSimulator->updateConts();
				mDynSimulator->doSimulation(mFixedTimeStep, mIntegrationStep, mMapShape);
			}

			mLastPhysicsTime += mFixedTimeStep;
		}

		f32 a = (mAccumPhysicsTime - mLastPhysicsTime) / mFixedTimeStep;
		mDynSimulator->updateVecQuats(a);
	}
}

/*
 * --INFO--
 * Address:	800659C8
 * Size:	0001D4
 */
void MapMgr::update()
{
	updateSimulation();
	mDynSimulator->InitRender();

	gsys->mTimer->start("updDynPlat", true);

	// these are genuinely unused in the DLL too
	int total        = 0;
	int wallCount    = 0;
	int workObjCount = 0;
	int tekiCount1   = 0;
	int tekiCount2   = 0;
	FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
	{
		Creature* creature = coll->mCreature;
		if (!creature || creature->alwaysUpdatePlatform()
		    || (creature->aiCullable() || !creature->mGrid.aiCulling())
		           && (!creature->isSluice() && creature->mObjType != OBJTYPE_WorkObject || !creature->mGrid.aiCulling())) {
			coll->update();
			coll->updatePos();
			coll->mContactCount = 0;
			if (creature) {
				if (creature->isSluice()) {
					wallCount++;
				} else if (creature->mObjType == OBJTYPE_Teki) {
					tekiCount1++;
				} else if (creature->isTeki()) {
					tekiCount2++;
				} else if (creature->mObjType == OBJTYPE_WorkObject) {
					workObjCount++;
				}
			}
			total++;
		}
	}

	gsys->mTimer->stop("updDynPlat");
}

/*
 * --INFO--
 * Address:	80065BA4
 * Size:	0000F4
 */
void MapMgr::preRender(Graphics& gfx)
{
	mVertRayCount      = 0;
	mGroundTriRayCount = 0;
	gfx.setMatHandler(mShadowHandler);
	gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2);

	FOREACH_NODE(ShadowCaster, mShadowCaster.mChild, shadow)
	{
		LightCamera& cam = shadow->mLightCamera;
		cam.calcVectors(shadow->mSourcePosition, shadow->mTargetPosition);
		cam.calcProjection(gfx, false, mShadowCountdown > 0 ? nullptr : shadow->mDrawer);
	}

	gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
	gfx.setMatHandler(nullptr);

	if (mShadowCountdown) {
		mShadowCountdown--;
	}
}

/*
 * --INFO--
 * Address:	80065C98
 * Size:	00019C
 */
void MapMgr::drawShadowCasters(Graphics& gfx)
{
	gfx.setFog(false);
	int blend = gfx.setCBlending(2);

	FOREACH_NODE(ShadowCaster, mShadowCaster.mChild, shadow)
	{
		LightCamera* cam = &shadow->mLightCamera;
		gfx.initProjTex(true, cam);
		mProjHandler->mProjMat->mTexture = cam->mLightMap;
		mProjHandler->mLightCamera       = cam;
		gfx.setMatHandler(mProjHandler);
		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3 | GFXRENDER_Unk4);
		gfx.mLightCam    = cam;
		gfx.useMatrix(Matrix4f::ident, 0);
		mMapShape->drawculled(gfx, *gfx.mCamera, nullptr);
		gfx.mLightCam    = nullptr;
		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		gfx.setMaterial(nullptr, false);
		gfx.setMatHandler(nullptr);
		gfx.initProjTex(false, nullptr);
	}

	gfx.setCBlending(blend);
	gfx.setFog(true);
}

/*
 * --INFO--
 * Address:	80065E34
 * Size:	000438
 */
void MapMgr::refresh(Graphics& gfx)
{
	gfx.setCBlending(0);
	if (mLightMgr) {
		gsys->mTimer->start("SoftLights", true);
		mLightMgr->updateLights();
		gsys->mTimer->stop("SoftLights");
	}

	if (mMapShape) {
		// this goes in the if condition above in the DLL, but fixes the stack in DOL if it's just empty.
		if (!mController->keyDown(KBBTN_DPAD_UP)) { }
		mDynMaterials.animate(nullptr);
		gfx.mHasTexGen = TRUE;
		Matrix4f mtx1;
		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		gfx.calcViewMatrix(mtx2, mtx1);
		gfx.setLighting(true, nullptr);
		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2);
		mMapShape->updateAnim(gfx, mtx1, nullptr);
		gfx.useMatrix(Matrix4f::ident, 0);
		mMapShape->drawculled(gfx, *gfx.mCamera, &mDynMaterials);
		gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		gfx.mHasTexGen   = FALSE;

		FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
		{
			gfx.calcViewMatrix(coll->mTransformMtx, coll->mWorldMatrix);
			gfx.useMatrix(coll->mWorldMatrix, 0);
			gfx.mHasTexGen = TRUE;
			gfx.setLighting(true, nullptr);
			coll->refresh(gfx);
			gfx.mHasTexGen = FALSE;
		}
		mDynSimulator->Render(gfx);
	}
}

/*
 * --INFO--
 * Address:	80066360
 * Size:	00078C
 */
void MapMgr::showCollisions(immut Vector3f& pos)
{
	mDebugFocusPoint = pos;
	f32 a            = 64.0f;
	int b            = (mMapBounds.mMax.x - mMapBounds.mMin.x + a) / a;
	int c            = (mMapBounds.mMax.z - mMapBounds.mMin.z + a) / a;
	int d            = (mDebugFocusPoint.x - mMapBounds.mMin.x) / a;
	int e            = (mDebugFocusPoint.z - mMapBounds.mMin.z) / a;
	f32 f            = mMapBounds.mMin.x + d * a;
	f32 g            = mMapBounds.mMin.z + e * a;
	f32 h            = a * 1.0f;

	mBroadPhaseBox.resetBound();
	mBroadPhaseBox.expandBound(Vector3f(f - h, mMapBounds.mMin.y - h, g - h));
	mBroadPhaseBox.expandBound(Vector3f(f + a + h, mMapBounds.mMax.y + h, g + a + h));

	mQueryBox.resetBound();
	mQueryBox.expandBound(Vector3f(f, mMapBounds.mMin.y - h, g));
	mQueryBox.expandBound(Vector3f(f + a, mMapBounds.mMax.y + h, g + a));
	collExtents = mQueryBox;

	BoundBox box;
	box.expandBound(pos);
	box.mMin.sub(Vector3f(16.0f, 16.0f, 16.0f));
	box.mMax.add(Vector3f(16.0f, 16.0f, 16.0f));
	CollGroup* collGroup = nullptr;
	FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
	{
		if (box.intersects(coll->mBoundingBox)) {
			for (int i = 0; i < coll->mColliderCount; i++) {
				if (coll->mVisibleList[coll->mColliderList[i]->mRoomIndex]) {
					coll->mColliderList[i]->mShape          = coll->mShape;
					coll->mColliderList[i]->mVertexList     = coll->mVertexList;
					coll->mColliderList[i]->mSourceCollider = coll;
					coll->mColliderList[i]->mNextCollider   = collGroup;
					collGroup                               = coll->mColliderList[i];
				}
			}
		}
	}

	CollGroup* coll = mMapShape->getCollTris(pos);
	if (coll && coll->mTriCount) {
		coll->mShape          = mMapShape;
		coll->mVertexList     = mMapShape->mVertexList;
		coll->mSourceCollider = nullptr;
		coll->mNextCollider   = collGroup;
		collGroup             = coll;
	}

	for (coll = collGroup; coll; coll = coll->mNextCollider) {
		if (!coll) {
			continue;
		}
		if (coll->mTriCount == 0) {
			continue;
		}

		mActiveTriCount += coll->mTriCount - coll->mFarCulledTriCount;
		int count = coll->mTriCount - coll->mFarCulledTriCount;
		if (coll->mTriCount == coll->mFarCulledTriCount) {
			PRINT("grid(%d,%d) collGroup : total %d far %d tris\n", d, e, coll->mTriCount, coll->mFarCulledTriCount);
			for (int i = 0; i < coll->mFarCulledTriCount; i++) {
				PRINT("\t%d : dist = %d\n", i, coll->mFarCulledTriDistances[i]);
			}
		}

		for (int i = 0; i < coll->mTriCount; i++) {
			if (mDebugCollCount < mMaxDebugColls) {
				if (AIPerf::showColls) {
					if (i < count) {
						mCollisions[mDebugCollCount].mColorCategory = 0;
					} else {
						if (coll->mFarCulledTriDistances[i - count] < 16) {
							mCollisions[mDebugCollCount].mColorCategory = 2;
						} else {
							mCollisions[mDebugCollCount].mColorCategory = 1;
						}
					}
				} else {
					mCollisions[mDebugCollCount].mColorCategory = 0;
				}

				mCollisions[mDebugCollCount].mCollisions = coll;
				mCollisions[mDebugCollCount].mTriangle   = coll->mTriangleList[i];
				mDebugCollCount++;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
bool MapMgr::closeCollTri(CollGroup*, CollTriInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80066AEC
 * Size:	000160
 */
void MapMgr::drawXLU(Graphics& gfx)
{
	if (mMapShape) {
		MATCHING_START_TIMER("mapPost", true);
		mDayMgr->setFog(gfx, nullptr);
#if 0 // DLL only condition
		if (!mController->keyDown(KBBTN_DPAD_DOWN))
#endif
		{
			gfx.mHasTexGen = TRUE;
			Matrix4f mtx1;
			Matrix4f mtx2;
			mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
			gfx.calcViewMatrix(mtx2, mtx1);
			gfx.useMatrix(mtx1, 0);
			gfx.setLighting(true, nullptr);
			gfx.mRenderState = GFXRENDER_Unk3;
			mMapShape->updateAnim(gfx, mtx1, nullptr);
			gfx.useMatrix(Matrix4f::ident, 0);
			mMapShape->drawshape(gfx, *gfx.mCamera, &mDynMaterials);
			gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		}
		MATCHING_STOP_TIMER("mapPost");
	}
}

/*
 * --INFO--
 * Address:	80066C4C
 * Size:	000EDC
 */
void MapMgr::postrefresh(Graphics& gfx)
{
	if (mMapShape) {
		MATCHING_START_TIMER("mapPost", true);
		mDayMgr->setFog(gfx, nullptr);
		drawShadowCasters(gfx);
		if (lgMgr) {
			lgMgr->update();
			lgMgr->refresh(gfx);
		}

		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.flushCachedShapes();
		gsys->flushLFlares(gfx);

		if (effectMgr) {
			gsys->mTimer->start("eff draw", true);
			effectMgr->drawshapes(gfx);
			gsys->mTimer->stop("eff draw");
		}

		if (gsys->mToggleBlur) {
			Matrix4f mtx;
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			bool lighting = gfx.setLighting(false, nullptr);
			gfx.setFog(false);
			gfx.setColour(Colour(255, 255, 255, 255), true);
			gfx.setAuxColour(Colour(255, 255, 255, 255));
			mCaptureTexture->grabBuffer(mCaptureTexture->mWidth, mCaptureTexture->mHeight, false, true);
			gfx.useTexture(mBlurredTexture, GX_TEXMAP0);
			gfx.useTexture(mCaptureTexture, GX_TEXMAP1);
#if defined(VERSION_PIKIDEMO)
#else
			if (gameflow.mMoviePlayer->mIsActive) {
				gfx.mCamera->mBlur = 0.0f;
			}
#endif

			int blend = gfx.setCBlending(6);
			gfx.setPrimEnv(&Colour(255, 255, 255, gfx.mCamera->mBlur), nullptr);
			gfx.blatRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			gfx.setCBlending(blend);
			mBlurredTexture->grabBuffer(mBlurredTexture->mWidth, mBlurredTexture->mHeight, false, true);
			gfx.resetCopyFilter();
			gfx.setFog(true);
			gfx.setLighting(lighting, nullptr);
			gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
			                   gfx.mCamera->mFar, 1.0f);
		}

		if (mFadeProgress < mTargetFadeLevel) {
			mFadeProgress += 2.0f * gsys->getFrameTime();
			if (mFadeProgress > mTargetFadeLevel) {
				mFadeProgress = mTargetFadeLevel;
			}
		} else if (mFadeProgress > mTargetFadeLevel) {
			mFadeProgress -= 2.0f * gsys->getFrameTime();
			if (mFadeProgress < mTargetFadeLevel) {
				mFadeProgress = mTargetFadeLevel;
			}
		}

		if (mDesaturationLevel < mTargetDesaturation) {
			mDesaturationLevel += 2.0f * gsys->getFrameTime();
			if (mDesaturationLevel > mTargetDesaturation) {
				mDesaturationLevel = mTargetDesaturation;
			}
		} else if (mDesaturationLevel > mTargetDesaturation) {
			mDesaturationLevel -= 2.0f * gsys->getFrameTime();
			if (mDesaturationLevel < mTargetDesaturation) {
				mDesaturationLevel = mTargetDesaturation;
			}
		}

		if (mDesaturationLevel > 0.0f || mFadeProgress > 0.0f) {
			Matrix4f mtx;
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
			gfx.setColour(Colour(160, 160, 160, (int)(mDesaturationLevel * 255.0f)), true);
			gfx.useTexture(mBlurredTexture, GX_TEXMAP0);
			gfx.drawRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight),
			                  RectArea(0, 0, mBlurredTexture->mWidth, mBlurredTexture->mHeight), nullptr);
			GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
			gfx.setColour(Colour(0, 0, 0, int(mFadeProgress * 255.0f)), true);
			gfx.useTexture(nullptr, GX_TEXMAP0);
			gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		}

		if (mDebugCollCount) {
			int blend     = gfx.setCBlending(0);
			bool lighting = gfx.setLighting(false, nullptr);
			gfx.setFog(false);
			gfx.useTexture(nullptr, GX_TEXMAP0);
			gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

			Colour colours[3];
			colours[0].set(255, 255, 0, 255);
			colours[1].set(255, 0, 0, 255);
			colours[2].set(0, 0, 255, 255);

			Vector3f vecs[3];

			for (int i = 0; i < mDebugCollCount; i++) {
				vecs[0] = mCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[0]];
				vecs[1] = mCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[1]];
				vecs[2] = mCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[2]];

				for (int j = 0; j < 3; j++) {
					gfx.setColour(colours[mCollisions[i].mColorCategory], true);
					gfx.drawLine(vecs[j % 3], vecs[(j + 1) % 3]);
					gfx.drawPoints(&vecs[j % 3], 1);
				}
			}

			gfx.setColour(Colour(255, 255, 255, 255), true);
			Vector3f pos(mDebugFocusPoint.x, mDebugFocusPoint.y + 50.0f, mDebugFocusPoint.z);
			pos.multMatrix(gfx.mCamera->mLookAtMtx);

			char buffer[PATH_MAX];
			if (AIPerf::showColls) {
				sprintf(buffer, "%d / %d", mActiveTriCount, mDebugCollCount);
			} else {
				sprintf(buffer, "%d", mDebugCollCount);
			}

			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.perspPrintf(gsys->mConsFont, pos, -(gsys->mConsFont->stringWidth(buffer) / 2), 0, buffer);

			for (int i = 0; i < mDebugCollCount; i++) {
				Vector3f vert1(mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[0]]);
				Vector3f vert2(mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[1]]);
				Vector3f vert3(mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[2]]);

				vert1.x = (int)vert1.x;
				vert1.z = (int)vert1.z;
				vert2.x = (int)vert2.x;
				vert2.z = (int)vert2.z;
				vert3.x = (int)vert3.x;
				vert3.z = (int)vert3.z;

				f32 dist = triRectDistance(&vert1, &vert2, &vert3, collExtents, false);

				Vector3f midPt = vert1 + vert2 + vert3;
				midPt.multiply(1.0f / 3.0f);
				midPt = midPt + mCollisions[i].mTriangle->mTriangle.mNormal * 10.0f;
				midPt.multMatrix(gfx.mCamera->mLookAtMtx);
				sprintf(buffer, "%.1f", dist);
				gfx.perspPrintf(gsys->mConsFont, midPt, -(gsys->mConsFont->stringWidth(buffer) / 2), 0, buffer);
			}

			gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

			if (AIPerf::showColls) {
				gfx.setColour(Colour(255, 128, 255, 255), true);
				mQueryBox.draw(gfx);
			}

			gfx.setColour(Colour(64, 255, 255, 255), true);
			mBroadPhaseBox.draw(gfx);
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

/*
 * --INFO--
 * Address:	80067B28
 * Size:	000270
 */
void MapMgr::updatePos(f32 x, f32 z)
{
	Vector3f pos(x, 0.0f, z);
	if (mLightMgr) {
		gsys->mTimer->start("touchLights", true);
		mLightMgr->touchLights(pos);
		gsys->mTimer->stop("touchLights");
	}
}

/*
 * --INFO--
 * Address:	80067D98
 * Size:	000008
 */
f32 MapMgr::getLight(f32, f32)
{
	return 1.0f;
}

/*
 * --INFO--
 * Address:	80067DA0
 * Size:	000164
 */
CollGroup* MapMgr::getCollGroupList(f32 x, f32 z, bool doCheckDynColl)
{
	CollGroup* collList = nullptr;
	if (doCheckDynColl) {
		FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
		{
			if (x >= coll->mBoundingBox.mMin.x && x < coll->mBoundingBox.mMax.x && z >= coll->mBoundingBox.mMin.z
			    && z < coll->mBoundingBox.mMax.z && coll->mShape->mSystemFlags & ShapeFlags::IsPlatform) {
				for (int i = 0; i < coll->mColliderCount; i++) {
					if (coll->mVisibleList[coll->mColliderList[i]->mRoomIndex]) {
						coll->mColliderList[i]->mNextCollider = collList;
						collList                              = coll->mColliderList[i];
					}
				}
			}
		}
	}

	CollGroup* mapColl = mMapShape->getCollTris(Vector3f(x, 0.0f, z));
	if (mapColl && mapColl->mTriCount) {
		mapColl->mNextCollider = collList;
		collList               = mapColl;
	}

	return collList;
}

/*
 * --INFO--
 * Address:	80067F04
 * Size:	000164
 */
f32 MapMgr::getMinY(f32 x, f32 z, bool doCheckDynColl)
{
	mVertRayCount++;
	f32 minY = -32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, doCheckDynColl); colls; colls = colls->mNextCollider) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->mFarCulledTriCount : colls->mTriCount;
		if (count == 0) {
			count = colls->mTriCount;
		}

		for (int i = 0; i < count; i++) {
			if (colls->mTriangleList[i]->mTriangle.mNormal.y > 0.0f) {
				Vector3f triPos(x, 0.0f, z);
				if (colls->mTriangleList[i]->inTriClampTo(triPos) && triPos.y > minY) {
					minY = triPos.y;
				}
			}
		}
	}

	if (minY == -32768.0f) {
		return 0.0f;
	}
	return minY;
}

/*
 * --INFO--
 * Address:	80068068
 * Size:	000170
 */
f32 MapMgr::getMaxY(f32 x, f32 z, bool doCheckDynColl)
{
	mVertRayCount++;
	f32 minY = 32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, doCheckDynColl); colls; colls = colls->mNextCollider) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->mFarCulledTriCount : colls->mTriCount;
		if (count == 0) {
			count = colls->mTriCount;
		}

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

/*
 * --INFO--
 * Address:	800681D8
 * Size:	00015C
 */
CollTriInfo* MapMgr::getCurrTri(f32 x, f32 z, bool doCheckDynColl)
{
	mGroundTriRayCount++;
	CollTriInfo* tri = nullptr;
	f32 minY         = -32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, doCheckDynColl); colls; colls = colls->mNextCollider) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->mFarCulledTriCount : colls->mTriCount;
		if (count == 0) {
			count = colls->mTriCount;
		}

		for (int i = 0; i < count; i++) {
			Vector3f triPos(x, 0.0f, z);
			if (colls->mTriangleList[i]->inTriClampTo(triPos) && triPos.y > minY) {
				tri  = colls->mTriangleList[i];
				minY = triPos.y;
			}
		}
	}
	return tri;
}

/*
 * --INFO--
 * Address:	80068334
 * Size:	0002EC
 */
f32 MapMgr::findEdgePenetration(CollTriInfo& tri, immut Vector3f* vertexList, immut Vector3f& pos, f32 rad, Vector3f& normal)
{
	for (int i = 0; i < 3; i++) {
		f32 dist = tri.mEdgePlanes[i].dist(pos);
		if (dist < 0.0f && dist >= -rad) {
			immut Vector3f& vtx1 = vertexList[tri.mVertexIndices[i % 3]];
			immut Vector3f& vtx2 = vertexList[tri.mVertexIndices[(i + 1) % 3]];

			Vector3f edge12 = vtx2 - vtx1;
			f32 edgeLen     = edge12.x * edge12.x + edge12.y * edge12.y + edge12.z * edge12.z;
			f32 t           = edge12.DP(pos - vtx1) / edgeLen;
			if (t >= 0.0f && t < 1.0f) {
				Vector3f edgePos(edge12.x * t + vtx1.x, edge12.y * t + vtx1.y, edge12.z * t + vtx1.z);
				Vector3f dirEdge(pos.x - edgePos.x, pos.y - edgePos.y, pos.z - edgePos.z);
				normal.set(dirEdge.x, dirEdge.y, dirEdge.z);
				f32 distEdge = normal.normalise();
				if (distEdge < rad) {
					return distEdge;
				}
			} else {
				Vector3f dirVtx1(pos.x - vtx1.x, pos.y - vtx1.y, pos.z - vtx1.z);
				f32 distVtx1 = dirVtx1.normalise();
				if (distVtx1 < rad) {
					normal.set(dirVtx1.x, dirVtx1.y, dirVtx1.z);
					return distVtx1;
				}

				Vector3f dirVtx2(pos.x - vtx2.x, pos.y - vtx2.y, pos.z - vtx2.z);
				f32 distVtx2 = dirVtx2.normalise();
				if (distVtx2 < rad) {
					normal.set(dirVtx2.x, dirVtx2.y, dirVtx2.z);
					return distVtx2;
				}
			}
		}
	}

	return 0.0f;
}

/*
 * --INFO--
 * Address:	80068620
 * Size:	00082C
 */
void MapMgr::recTraceMove(CollGroup* colls, MoveTrace& trace, f32 timeStep)
{
	f32 offset;
	Vector3f vel(trace.mVelocity);
	vel.multiply(timeStep * trace.mStepFraction);
	if (vel.length() >= trace.mRadius) {
		PRINT("speed violation!! %f\n", vel.length());
	}

	Vector3f nextPos = trace.mPosition + vel;
	Vector3f* v      = &vel; // this is just for stack fixing
	offset           = 0.05f;
	f32 radPlus      = trace.mRadius + offset;
	f32 radMinus     = trace.mRadius - 0.05f;
	u8 radInt        = radPlus;

	BoundBox box;
	box.expandBound(nextPos);
	box.mMin.sub(Vector3f(radPlus, radPlus, radPlus));
	box.mMax.add(Vector3f(radPlus, radPlus, radPlus));

	CollGroup* currColls = colls;
	Vector3f vec;
	bool check1 = false;

	for (currColls; currColls; currColls = currColls->mNextCollider) {
		int count = currColls->mTriCount - currColls->mFarCulledTriCount;
		if (!count) {
			count = colls->mTriCount;
		}

		for (int i = 0; i < currColls->mTriCount; i++) {
			CollTriInfo* tri = currColls->mTriangleList[i];
			if (AIPerf::showColls && i >= count && currColls->mFarCulledTriDistances[i - count] > radInt + 4) {
				if (AIPerf::useCollSort) {
					break;
				}
				continue;
			}

			int a = 0;
			Vector3f normal(tri->mTriangle.mNormal);
			f32 rad = trace.mRadius;
			f32 pen = tri->mTriangle.dist(nextPos);
			if (pen < rad && pen > 0.0f) {
				if (tri->behindEdge(nextPos) == -1) {
					a = 1;
				} else {
					pen = findEdgePenetration(*tri, currColls->mVertexList, nextPos, rad, normal);
					if (pen != 0.0f) {
						a = 2;
					}
				}
			}

			if (a == 0) {
				continue;
			}

			f32 bounceFactor = 1.0f;
			if (trace.mObject && trace.mObject->mProps) {
				bounceFactor = trace.mObject->mProps->mCreatureProps.mBounceFactor();
			}
			if (trace.mObject) {
				trace.mObject->mCollisionOccurred = 1;
			}
			PRINT_IF(false, ">> before bounce : n(%.1f,%.1f,%.1f) vel(%.1f,%.1f,%.1f) p(%.1f,%.1f,%.1f) % s :%.1f %.1f\n", normal.x,
			         normal.y, normal.z, vel.x, vel.y, vel.z, nextPos.x, nextPos.y, nextPos.z,
			         currColls->mSourceCollider ? "PLATFORM" : "MAP", pen, rad);
			bool check2 = false;
			if (!currColls->mSourceCollider) {
				check1 = true;
				vec    = normal;
				trace.mVelocity.bounce(normal, bounceFactor);
				vel.bounce(normal, bounceFactor);
			} else if (check1 && vec.DP(normal) < -0.5f) {
				check2 = true;
				PRINT_IF(false, "ignore platform\n");
			} else {
				if (trace.mObject && currColls->mSourceCollider && currColls->mSourceCollider->mCreature) {
					bounceFactor = 1.0f;
				}
				trace.mVelocity.bounce(normal, bounceFactor);
				vel.bounce(normal, bounceFactor);
			}
			PRINT_IF(false, ">> after bounce : n(%.1f,%.1f,%.1f) vel(%.1f,%.1f,%.1f) p(%.1f,%.1f,%.1f) %s\n", normal.x, normal.y, normal.z,
			         vel.x, vel.y, vel.z, nextPos.x, nextPos.y, nextPos.z, currColls->mSourceCollider ? "PLATFORM" : "MAP");
			if (!check2) {
				nextPos.x += normal.x * (rad - pen);
				nextPos.y += normal.y * (rad - pen);
				nextPos.z += normal.z * (rad - pen);
			}

			if (trace.mObject) {
				if (normal.y > 0.6f) {
					trace.mObject->mGroundTriangle     = tri;
					trace.mObject->mCurrCollisionModel = currColls->mShape;
				}
				if (a && tri->mTriangle.mNormal.y < 0.5f && tri->mTriangle.mNormal.y > -0.5f) {
					trace.mObject->wallCallback(tri->mTriangle, currColls->mSourceCollider);
				}
				trace.mObject->mCollPlatform   = currColls->mSourceCollider;
				trace.mObject->mCollPlatNormal = &tri->mTriangle.mNormal;

				if (currColls->mSourceCollider && trace.mObject->mObjType == OBJTYPE_Piki) {
					trace.mObject->mClimbingTri = tri;
				} else {
					trace.mObject->mClimbingTri = nullptr;
				}

				if (currColls->mSourceCollider) {
					if (a == 1 && currColls->mSourceCollider->mLastContactFrameID != mCollCheckCount) {
						currColls->mSourceCollider->mContactCount++;
						currColls->mSourceCollider->mLastContactFrameID = mCollCheckCount;
					}
					currColls->mSourceCollider->touchCallback(tri->mTriangle, nextPos, trace.mVelocity);
				}
			}
		}
	}
	trace.mPosition = nextPos;
}

/*
 * --INFO--
 * Address:	80068E54
 * Size:	0005D0
 */
void MapMgr::traceMove(Creature* creature, MoveTrace& trace, f32 timeStep)
{
	trace.mPosition.add(Vector3f(0.0f, trace.mRadius, 0.0f));
	int a = 1;
	int b = 0;
	for (f32 i = trace.mVelocity.length() * timeStep; b < 100 && i >= trace.mRadius; i *= 0.5f) {
		b++;
		a *= 2;
	}

	if (b > 50) {
		PRINT("Too many iterations [cr %08x : rad = %f : spd = %f]!!\n", creature, trace.mRadius, trace.mVelocity.length() * timeStep);
	}
	mCollCheckCount++;
	trace.mStepFraction = 1.0f / a;

	for (int i = 0; i < a; i++) {
		BoundBox box;
		box.expandBound(trace.mPosition);
		box.mMin.sub(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));
		box.mMax.add(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));
		trace.mObject        = creature;
		CollGroup* collGroup = nullptr;

		if (!trace.mIgnoreDynamic) {
			FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
			{
				if ((!coll->mCreature || coll->mCreature != creature) && box.intersects(coll->mBoundingBox)) {
					for (int j = 0; j < coll->mColliderCount; j++) {
						if (coll->mVisibleList[coll->mColliderList[j]->mRoomIndex]) {
							coll->mColliderList[j]->mShape          = coll->mShape;
							coll->mColliderList[j]->mVertexList     = coll->mVertexList;
							coll->mColliderList[j]->mSourceCollider = coll;
							coll->mColliderList[j]->mNextCollider   = collGroup;
							collGroup                               = coll->mColliderList[j];
						}
					}
				}
			}
		}

		CollGroup* mapColls = mMapShape->getCollTris(trace.mPosition);
		if (mapColls && mapColls->mTriCount) {
			mapColls->mShape          = mMapShape;
			mapColls->mVertexList     = mMapShape->mVertexList;
			mapColls->mSourceCollider = nullptr;
			mapColls->mNextCollider   = collGroup;
			collGroup                 = mapColls;
		}
		if (collGroup) {
			recTraceMove(collGroup, trace, timeStep);
		} else {
			Vector3f vel(trace.mVelocity);
			vel.multiply(timeStep * trace.mStepFraction);
			trace.mPosition.add(vel);
		}
	}

	trace.mPosition.sub(Vector3f(0.0f, trace.mRadius, 0.0f));
}

/*
 * --INFO--
 * Address:	80069424
 * Size:	000070
 */
Shape* MapMgr::loadPlatshape(immut char* path)
{
	Shape* shp       = nullptr;
	GfxobjInfo* info = gsys->findGfxObject(path, '_shp');
	if (info) {
		shp = ((ShpobjInfo*)info)->mTarget;
	}

	if (!shp) {
		shp = gsys->loadShape(path, true);
	}
	return shp;
}

/*
 * --INFO--
 * Address:	80069494
 * Size:	00009C
 */
CreatureCollPart* MapMgr::requestCollPart(ObjCollInfo* info, Creature* obj)
{
	CreatureCollPart* part = new CreatureCollPart(info->mPlatShape);
	part->mCreature        = obj;
	part->mOwner           = obj;
	part->mAnimMatrixID    = info->mJointIndex;
	mCollShape->add(part);
	return part;
}

/*
 * --INFO--
 * Address:	80069530
 * Size:	000134
 */
ShadowCaster::ShadowCaster()
    : CoreNode("")
{
	bool togglePrint   = gsys->mTogglePrint;
	gsys->mTogglePrint = TRUE;
	mLightCamera.mPosition.set(0.0f, 10.0f, 0.0f);
	mLightCamera.mFocus.set(0.0f, 0.0f, 0.00001f);
	mLightCamera.mRotation.set(0.0f, 0.0f, 0.0f);
	mLightCamera.mFov  = 90.0f;
	mLightCamera.mNear = 1.0f;
	mLightCamera.mFar  = 3000.0f;
	gsys->mTogglePrint = togglePrint;
	mDrawer            = nullptr;
}

/*
 * --INFO--
 * Address:	80069664
 * Size:	00002C
 */
void ShadowCaster::initShadow()
{
	PRINT("making shadow buffer!\n");
	mLightCamera.initLightmap(256, 4);
}
