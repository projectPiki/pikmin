#include "DynColl.h"
#include "DynObject.h"
#include "MapMgr.h"
#include "Creature.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "Font.h"
#include "gameflow.h"
#include "Graphics.h"
#include "MoviePlayer.h"
#include "timers.h"
#include "CreatureProp.h"
#include "EffectMgr.h"
#include "AIPerf.h"
#include "MemStat.h"
#include "DayMgr.h"
#include "CreatureCollPart.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @brief Fabricated name. Some struct has to exist here, but I don't think it's exposed anywhere.
 */
struct SoftLightLight {
	u32 _00;             // _00
	SoftLightLight* _04; // _04
	u8* _08;             // _08
	s16 _0C;             // _0C
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
		if (_30) {
			for (int i = 0; i < _28; i++) {
				if (_30[i]->_00 != p1) {
					_30[i]->_04 = vlink;
					vlink       = _30[i];
					_30[i]->_00 = p1;
				}
				_30[i]->_0C += (_34[i] * _0C.r) >> 8;
			}
		}
	}
	void subLight(LShortColour*)
	{
		if (_30) {
			for (int i = 0; i < _28; i++) {
				_30[i]->_0C -= (_34[i] * _0C.r) >> 8;
			}
		}
		FORCE_DONT_INLINE;
	}

	Vector3f _00;         // _00
	Colour _0C;           // _0C
	Colour _10;           // _10
	f32 _14;              // _14
	f32 _18;              // _18
	f32 _1C;              // _1C
	int _20;              // _20
	int _24;              // _24
	int _28;              // _28
	u8 _2C;               // _2C
	SoftLightLight** _30; // _30
	s16* _34;             // _34
};

/**
 * @brief TODO
 */
struct MapLightMgr {

	void updateLights()
	{
		_14++;
		numUpdated = 0;
		numRepeats = 0;
		vlink      = nullptr;

		for (int i = 0; i < mLightCount; i++) {
			sinf(mLights[i]->_1C);

			bool check = false;
			if (mLights[i]->_1C != mLights[i]->_18) {
				f32 a = (mLights[i]->_24) ? 2.0f : 0.5f;
				mLights[i]->_1C += gsys->getFrameTime() * a * (mLights[i]->_18 - mLights[i]->_1C);
				check = true;
			}

			if (check) {
				if (!mLights[i]->_2C) {
					mLights[i]->subLight(_10);
				}
				mLights[i]->_2C = 0;
				f32 a           = sinf(mLights[i]->_1C);
				if (a > 0.95f) {
					mLights[i]->_1C = mLights[i]->_18;
				}

				mLights[i]->_0C.set(mLights[i]->_10.r * a, mLights[i]->_10.g * a, mLights[i]->_10.b * a, 255);
				mLights[i]->addLight(_14, _10, _00);
			}
		}

		if (vlink) {
			for (SoftLightLight* c = vlink; c; c = c->_04) {
				u8 a      = (c->_0C < 255) ? (u8)c->_0C : 255;
				c->_08[0] = a;
				c->_08[1] = a;
				c->_08[2] = a;
				c->_08[3] = a;
			}
		}
	}

	void touchLights(Vector3f& pos)
	{
		for (int i = 0; i < mLightCount; i++) {
			if (mLights[i]->_18 != HALF_PI) {
				f32 a = (mLights[i]->_24) ? mLights[i]->_14 * 0.5f : mLights[i]->_14 * 1.5f;
				if (mLights[i]->_00.distance(pos) < a) {
					mLights[i]->_18 = HALF_PI;
				}

				if (mLights[i]->_24) {
					for (int j = 0; j < mLightCount; j++) {
						if (i != j && mLights[j]->_20 == mLights[i]->_20 && mLights[j]->_1C > 0.4f) {
							f32 d = mLights[i]->_00.distance(mLights[j]->_00);
							if (d < mLights[i]->_14) {
								mLights[i]->_18 = HALF_PI;
							}
						}
					}
				}
			}
		}
	}

	Shape* _00;          // _00
	SoftLight** mLights; // _04
	u8 _08[0x4];         // _08, unknown
	int mLightCount;     // _0C
	LShortColour* _10;   // _10
	u32 _14;             // _14
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
			if (i == mCollTriList[j]._10) {
				tris++;
			}
		}

		mColliderList[i]                = new CollGroup;
		mColliderList[i]->mStateIndex   = mShape->mRoomInfoList[i]._00;
		mColliderList[i]->mTriCount     = tris;
		mColliderList[i]->mTriangleList = new CollTriInfo*[mColliderList[i]->mTriCount];

		int t = 0;
		for (int j = 0; j < mShape->mTriCount; j++) {
			if (mCollTriList[j]._10 == i) {
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
	gfx.useTexture(nullptr, 0);
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
	obj->_274 = obj->mPosition;
	obj->_274.multMatrix(mInverseMatrix);
	obj->mPosition = obj->_274;
	obj->mPosition.multMatrix(mTransformMtx);
	obj->mLastPosition = obj->mPosition;
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
	_18 = 0;
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
	mAnimator.startAnim(0, 0, 0, 8);
	mState  = 0;
	mMapMgr = map;
	mShadowCaster.initCore("");
	mShadowCaster.mDrawer           = this;
	mShadowCaster.mLightCamera.mFov = 20.0f;
	mMapScale.set(1.0f, 1.0f, 1.0f);
	mMapRotation.set(0.0f, 0.0f, 0.0f);
	mMapTranslation.set(0.0f, 0.0f, 0.0f);
	mObjPartCount = 0;
	for (ObjCollInfo* info = (ObjCollInfo*)mShape->mCollisionInfo.mParentShape->Child(); info; info = (ObjCollInfo*)info->mNext) {
		if (info->mPlatShape) {
			mObjPartCount++;
		}
	}

	mObjParts = new MapObjectPart*[mObjPartCount];
	int i     = 0;
	for (ObjCollInfo* info = (ObjCollInfo*)mShape->mCollisionInfo.mParentShape->Child(); info; info = (ObjCollInfo*)info->mNext) {
		if (info->mPlatShape) {
			MapObjectPart* part = new MapObjectPart(info->mPlatShape);
			part->_144          = this;
			part->_140          = info->mJointIndex;
			mMapMgr->mCollShape->add(part);
			mObjParts[i] = part;
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
void DynMapObject::touchCallback(Plane&, Vector3f&, Vector3f&)
{
	switch (mState) {
	case 0:
		_51C = 2.0f;
		mState++;
		break;
	case 4:
		_51C = 2.0f;
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
		_51C -= gsys->getFrameTime();
		if (_51C < 0.0f) {
			_51C = 2.0f;
			mAnimator.startAnim(2, 0, 0, 8);
			mState++;
		}
		break;
	case 3:
		_51C -= gsys->getFrameTime();
		if (_51C < 0.0f) {
			_51C = 0.0f;
			mState++;
		}
		break;
	case 4:
		_51C -= gsys->getFrameTime();
		if (_51C < 0.0f) {
			_51C = 0.0f;
			mAnimator.startAnim(2, 1, 0, 8);
			mState++;
		}
		break;

	default:
		break;
	}

	mShadowCaster.mSourcePosition.set(mMapTranslation.x + 100.0f, mMapTranslation.y + 300.0f, mMapTranslation.z + 300.0f);
	mShadowCaster.mTargetPosition.set(mMapTranslation.x, mMapTranslation.y + 100.0f, mMapTranslation.z);
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
	mtx1.makeSRT(mMapScale, mMapRotation, mMapTranslation);
	gfx.calcViewMatrix(mtx1, mtx2);
	gsys->mTimer->start("animation", true);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx2, nullptr);
	gsys->mTimer->stop("animation");

	for (int i = 0; i < mObjPartCount; i++) {
		MapObjectPart* part = mObjParts[i];
		part->mTransformMtx.inverse(&part->mInverseMatrix);
		Matrix4f animMtx = mShape->getAnimMatrix(part->_140);
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
void DynCollObjBody::touchCallback(Plane& plane, Vector3f& a1, Vector3f& a2)
{
	_140->touchCallback(plane, a1, a2);
}

/*
 * --INFO--
 * Address:	8006258C
 * Size:	000030
 */
void DynCollObjBody::applyVelocity(Plane& plane, Vector3f& a1, Vector3f& a2)
{
	_140->applyVelocity(plane, a1, a2);
}

/*
 * --INFO--
 * Address:	800625BC
 * Size:	0001B8
 */
void DynObjBody::touchCallback(Plane& plane, Vector3f& p2, Vector3f& p3)
{
	if (plane.mNormal.DP(p3) < 0.0f) {
		Vector3f vec = plane.mNormal.DP(p3) * plane.mNormal;
		vec.multiply(_13318);
		// why.
		applyForce(0, Vector3f(vec.x, vec.y, vec.z), Vector3f(p2.x, p2.y, p2.z));
	}
}

/*
 * --INFO--
 * Address:	80062774
 * Size:	0001B8
 */
void DynObjBody::applyVelocity(Plane& plane, Vector3f& p2, Vector3f& p3)
{
	if (plane.mNormal.DP(p3) < 0.0f) {
		Vector3f vec = plane.mNormal.DP(p3) * plane.mNormal;
		vec.multiply(_13318);
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
	config.mLinearVel.rotate(_1335C);
	config.mLocalAngularVel.rotate(_1335C);
	config.mLinearVel.set(config.mLinearVel.x * mVelMask.x, config.mLinearVel.y * mVelMask.y, config.mLinearVel.z * mVelMask.z);
	config.mLocalAngularVel.set(config.mLocalAngularVel.x * mAngularVelMask.x, config.mLocalAngularVel.y * mAngularVelMask.y,
	                            config.mLocalAngularVel.z * mAngularVelMask.z);
	config.mLinearVel.rotate(_1331C);
	config.mLocalAngularVel.rotate(_1331C);

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
	_132BC.makeVQS(_13260, _1328C, Vector3f(1.0f, 1.0f, 1.0f));
	mCollObj->mTransformMtx.inverse(&mCollObj->mInverseMatrix);
	mCollObj->mTransformMtx = _132BC;
}

/*
 * --INFO--
 * Address:	80063B34
 * Size:	0003E8
 */
void DynObjBody::applyWorldSpring(int configIdx, int attachPointIdx, Vector3f& p3)
{
	u32 badCompiler[4];
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
	gfx.calcViewMatrix(_132BC, mtx);
	gfx.mCamera->setBoundOffset(&_13260);
	gfx.useMatrix(mtx, 0);
	gfx.mCamera->setBoundOffset(nullptr);
	gfx.useTexture(nullptr, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

	for (int i = 0; i < mSpringCount; i++) {
		gfx.drawLine(_10248[mSprings[i].mHookIdx], mSprings[i].mOffset);
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
	CollGroup* coll       = _132B8->getCollTris(config.mPosition);
	applyCMForce(Vector3f(0.0f, -140.81f, 0.0f));

	for (int i = 0; i < mSpringCount; i++) {
		applyWorldSpring(configIdx, mSprings[i].mHookIdx, mSprings[i].mOffset);
	}

	// gsys->mTimer->start("applyGround", true);
	applyGroundForces(configIdx, coll);
	// gsys->mTimer->stop("applyGround");

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
	mCollObj       = new DynCollObjBody(mBodyShell);
	mCollObj->_140 = this;
}

/*
 * --INFO--
 * Address:	80064510
 * Size:	0003A4
 */
void DynObjBody::readScript(MapMgr* map, char* fileName)
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
	gfx.calcViewMatrix(_132BC, mtx);
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
	vec.add(_13260);
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
	mController = controller;
	_4C4        = 0.0f;
	_4C0        = 0.0f;
	_4CC        = 0.0f;
	_4C8        = 0.0f;
	effectMgr   = nullptr;
	mBlur       = 145;

	memStat->start("dayMgr");
	mDayMgr = new DayMgr(this, mController);
	memStat->end("dayMgr");

	mCollisionCheckCount = 0;
	mMapShape            = nullptr;

	_A8 = 0;
	_B0 = 300;

	if (_B0) {
		memStat->start("collisions");
		mCollisions = new MapColls[_B0];
		memStat->end("collisions");
	}

	memStat->start("collparts");
	_4D0 = new CreatureCollPart();
	_4D0->initCore("");
	memStat->end("collparts");
	_90.resetBound();

	memStat->start("rooms");
	mMapRooms = new MapRoom[256];
	memStat->end("rooms");

	memStat->start("dyncolshape");
	mCollShape = new DynCollShape(nullptr);
	memStat->end("dyncolshape");

	memStat->start("shadMats");
	_110 = 3;
	mShadowCaster.initCore("");
	mMapShadMatHandler                   = new MapShadMatHandler();
	mMapShadMatHandler->mShadMat->mFlags = 0x100;

	mMapProjMatHandler                   = new MapProjMatHandler(nullptr);
	mMapProjMatHandler->mProjMat->mFlags = 0x8100;

	mMapProjMatHandler->mProjMat->Colour().set(255, 255, 255, 255);
	memStat->end("shadMats");

	memStat->start("blurTextures");
	_4B4                = new Texture();
	_4B4->mWidthFactor  = 0.003125f;
	_4B4->mHeightFactor = 0.004166667f;
	_4B4->mTexFlags     = 0x105;
	_4B4->createBuffer(320, 240, 8, nullptr);
	gsys->addTexture(_4B4, "internalLightmap");
	_4B8                = new Texture();
	_4B8->mWidthFactor  = 0.003125f;
	_4B8->mHeightFactor = 0.004166667f;
	_4B8->mTexFlags     = 0x105;
	_4B8->createBuffer(320, 240, 0, nullptr);
	gsys->addTexture(_4B8, "internalLightmap");
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
	mMapShape->mSystemFlags |= 0x4;
	mMapShape->makeInstance(mDynMaterials, 0);

	for (int i = 0; i < mMapShape->mJointCount; i++) {
		PRINT("got bound (%.1f, %.1f, %.1f) - (%.1f, %.1f, %.1f)\n", mMapShape->mJointList[i].mBounds.mMin.x,
		      mMapShape->mJointList[i].mBounds.mMin.y, mMapShape->mJointList[i].mBounds.mMin.z, mMapShape->mJointList[i].mBounds.mMax.x,
		      mMapShape->mJointList[i].mBounds.mMax.y, mMapShape->mJointList[i].mBounds.mMax.z);
	}

	mMapShape->createCollisions(64);
	_90.expandBound(mMapShape->mCourseExtents);
	mDynSimulator = new DynSimulator();

	_FC  = 0.016666668f;
	_100 = 0.0125f;
	_F4  = 0.0f;
	_F8  = 0.0f;

	// sigh. this is really there.
	// similar code exists in GenObjectMapObject::birth, but the assembly is actually stripped there.
	for (int i = 0; i < 0; i++) {
		DynObjBody* body = new DynObjBody();
		body->_132B8     = mMapShape;
		body->readScript(this, "traffic/specLog.ini");
		body->initBodyCollisions();
		body->mInitPosition.set(0.0f, 60.0f, 100.0f);
		body->mInitOrientationZ = Vector3f(1.0f, 0.0f, 0.0f);
		body->mInitOrientationX = Vector3f(0.0f, 1.0f, 0.0f);
		body->mInitOrientationY = Vector3f(0.0f, 0.0f, 1.0f);
		mDynSimulator->add(body);
		mCollShape->add(body->mCollObj);
	}

	_104 = 1;
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
	if (_104) {
		mDynSimulator->resetWorld();
		_104               = 0;
		mDynSimulator->_20 = 0;
	}

	f32 time = gsys->getFrameTime();
	if (!mDynSimulator->isPaused()) {
		_F8 += time * 1.0f;
		while (_F8 - _F4 > _FC) {
			if (!mDynSimulator->isPaused()) {
				mDynSimulator->updateConts();
				mDynSimulator->doSimulation(_FC, _100, mMapShape);
			}

			_F4 += _FC;
		}

		f32 a = (_F8 - _F4) / _FC;
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
	_18 = 0;
	_1C = 0;
	gfx.setMatHandler(mMapShadMatHandler);
	gfx.mRenderState = 0x300;

	FOREACH_NODE(ShadowCaster, mShadowCaster.mChild, shadow)
	{
		LightCamera& cam = shadow->mLightCamera;
		cam.calcVectors(shadow->mSourcePosition, shadow->mTargetPosition);
		cam.calcProjection(gfx, false, _110 > 0 ? nullptr : shadow->mDrawer);
	}

	gfx.mRenderState = 0x700;
	gfx.setMatHandler(nullptr);

	if (_110) {
		_110--;
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
		mMapProjMatHandler->mProjMat->_24 = cam->mLightMap;
		mMapProjMatHandler->mLightCamera  = cam;
		gfx.setMatHandler(mMapProjMatHandler);
		gfx.mRenderState = 0x8700;
		gfx.mLightCam    = cam;
		gfx.useMatrix(Matrix4f::ident, 0);
		mMapShape->drawculled(gfx, *gfx.mCamera, nullptr);
		gfx.mLightCam    = nullptr;
		gfx.mRenderState = 0x700;
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
		gfx._324 = 1;
		Matrix4f mtx1;
		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		gfx.calcViewMatrix(mtx2, mtx1);
		gfx.setLighting(true, nullptr);
		gfx.mRenderState = 0x300;
		mMapShape->updateAnim(gfx, mtx1, nullptr);
		gfx.useMatrix(Matrix4f::ident, 0);
		mMapShape->drawculled(gfx, *gfx.mCamera, &mDynMaterials);
		gfx.mRenderState = 0x700;
		gfx._324         = 0;

		FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
		{
			gfx.calcViewMatrix(coll->mTransformMtx, coll->mWorldMatrix);
			gfx.useMatrix(coll->mWorldMatrix, 0);
			gfx._324 = 1;
			gfx.setLighting(true, nullptr);
			coll->refresh(gfx);
			gfx._324 = 0;
		}
		mDynSimulator->Render(gfx);
	}
}

/*
 * --INFO--
 * Address:	80066360
 * Size:	00078C
 */
void MapMgr::showCollisions(Vector3f& pos)
{
	_B4   = pos;
	f32 a = 64.0f;
	int b = (_90.mMax.x - _90.mMin.x + a) / a;
	int c = (_90.mMax.z - _90.mMin.z + a) / a;
	int d = (_B4.x - _90.mMin.x) / a;
	int e = (_B4.z - _90.mMin.z) / a;
	f32 f = _90.mMin.x + d * a;
	f32 g = _90.mMin.z + e * a;
	f32 h = a * 1.0f;

	_C0.resetBound();
	_C0.expandBound(Vector3f(f - h, _90.mMin.y - h, g - h));
	_C0.expandBound(Vector3f(f + a + h, _90.mMax.y + h, g + a + h));

	_D8.resetBound();
	_D8.expandBound(Vector3f(f, _90.mMin.y - h, g));
	_D8.expandBound(Vector3f(f + a, _90.mMax.y + h, g + a));
	collExtents = _D8;

	BoundBox box;
	box.expandBound(pos);
	box.mMin.sub(Vector3f(16.0f, 16.0f, 16.0f));
	box.mMax.add(Vector3f(16.0f, 16.0f, 16.0f));
	CollGroup* collGroup = nullptr;
	FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
	{
		if (box.intersects(coll->mBoundingBox)) {
			for (int i = 0; i < coll->mColliderCount; i++) {
				if (coll->mVisibleList[coll->mColliderList[i]->mStateIndex]) {
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

		_AC += coll->mTriCount - coll->_06;
		int count = coll->mTriCount - coll->_06;
		if (coll->mTriCount == coll->_06) {
			PRINT("grid(%d,%d) collGroup : total %d far %d tris\n", d, e, coll->mTriCount, coll->_06);
			for (int i = 0; i < coll->_06; i++) {
				PRINT("\t%d : dist = %d\n", i, coll->_0C[i]);
			}
		}

		for (int i = 0; i < coll->mTriCount; i++) {
			if (_A8 < _B0) {
				if (AIPerf::showColls) {
					if (i < count) {
						mCollisions[_A8]._08 = 0;
					} else {
						if (coll->_0C[i - count] < 16) {
							mCollisions[_A8]._08 = 2;
						} else {
							mCollisions[_A8]._08 = 1;
						}
					}
				} else {
					mCollisions[_A8]._08 = 0;
				}

				mCollisions[_A8].mCollisions = coll;
				mCollisions[_A8].mTriangle   = coll->mTriangleList[i];
				_A8++;
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
		// gsys->mTimer->start("mapPost", true);
		mDayMgr->setFog(gfx, nullptr);
		// DLL only condition
		// if (!mController->keyDown(KBBTN_DPAD_DOWN)) {
		gfx._324 = 1;
		Matrix4f mtx1;
		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		gfx.calcViewMatrix(mtx2, mtx1);
		gfx.useMatrix(mtx1, 0);
		gfx.setLighting(true, nullptr);
		gfx.mRenderState = 0x400;
		mMapShape->updateAnim(gfx, mtx1, nullptr);
		gfx.useMatrix(Matrix4f::ident, 0);
		mMapShape->drawshape(gfx, *gfx.mCamera, &mDynMaterials);
		gfx.mRenderState = 0x700;
		// }
		// gsys->mTimer->stop("mapPost");
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
		// gsys->mTimer->start("mapPost", true);
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
			// gsys->mTimer->start("eff draw", true);
			effectMgr->drawshapes(gfx);
			// gsys->mTimer->stop("eff draw");
		}

		if (gsys->mToggleBlur) {
			Matrix4f mtx;
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			bool lighting = gfx.setLighting(false, nullptr);
			gfx.setFog(false);
			gfx.setColour(Colour(255, 255, 255, 255), true);
			gfx.setAuxColour(Colour(255, 255, 255, 255));
			_4B4->grabBuffer(_4B4->mWidth, _4B4->mHeight, false, true);
			gfx.useTexture(_4B8, 0);
			gfx.useTexture(_4B4, 1);
			if (gameflow.mMoviePlayer->mIsActive) {
				gfx.mCamera->mBlur = 0.0f;
			}

			int blend = gfx.setCBlending(6);
			gfx.setPrimEnv(&Colour(255, 255, 255, gfx.mCamera->mBlur), nullptr);
			gfx.blatRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			gfx.setCBlending(blend);
			_4B8->grabBuffer(_4B8->mWidth, _4B8->mHeight, false, true);
			gfx.resetCopyFilter();
			gfx.setFog(true);
			gfx.setLighting(lighting, nullptr);
			gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
			                   gfx.mCamera->mFar, 1.0f);
		}

		if (_4C4 < _4CC) {
			_4C4 += 2.0f * gsys->getFrameTime();
			if (_4C4 > _4CC) {
				_4C4 = _4CC;
			}
		} else if (_4C4 > _4CC) {
			_4C4 -= 2.0f * gsys->getFrameTime();
			if (_4C4 < _4CC) {
				_4C4 = _4CC;
			}
		}

		if (_4C0 < _4C8) {
			_4C0 += 2.0f * gsys->getFrameTime();
			if (_4C0 > _4C8) {
				_4C0 = _4C8;
			}
		} else if (_4C0 > _4C8) {
			_4C0 -= 2.0f * gsys->getFrameTime();
			if (_4C0 < _4C8) {
				_4C0 = _4C8;
			}
		}

		if (_4C0 > 0.0f || _4C4 > 0.0f) {
			Matrix4f mtx;
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
			gfx.setColour(Colour(160, 160, 160, (int)(_4C0 * 255.0f)), true);
			gfx.useTexture(_4B8, 0);
			gfx.drawRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight), RectArea(0, 0, _4B8->mWidth, _4B8->mHeight), nullptr);
			GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
			gfx.setColour(Colour(0, 0, 0, int(_4C4 * 255.0f)), true);
			gfx.useTexture(nullptr, 0);
			gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		}

		if (_A8) {
			int blend     = gfx.setCBlending(0);
			bool lighting = gfx.setLighting(false, nullptr);
			gfx.setFog(false);
			gfx.useTexture(nullptr, 0);
			gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

			Colour colours[3];
			colours[0].set(255, 255, 0, 255);
			colours[1].set(255, 0, 0, 255);
			colours[2].set(0, 0, 255, 255);

			Vector3f vecs[3];

			for (int i = 0; i < _A8; i++) {
				vecs[0] = mCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[0]];
				vecs[1] = mCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[1]];
				vecs[2] = mCollisions[i].mTriangle->mTriangle.mNormal * 0.1f
				        + mCollisions[i].mCollisions->mVertexList[mCollisions[i].mTriangle->mVertexIndices[2]];

				for (int j = 0; j < 3; j++) {
					gfx.setColour(colours[mCollisions[i]._08], true);
					gfx.drawLine(vecs[j % 3], vecs[(j + 1) % 3]);
					gfx.drawPoints(&vecs[j % 3], 1);
				}
			}

			gfx.setColour(Colour(255, 255, 255, 255), true);
			Vector3f pos(_B4.x, _B4.y + 50.0f, _B4.z);
			pos.multMatrix(gfx.mCamera->mLookAtMtx);

			char buffer[PATH_MAX];
			if (AIPerf::showColls) {
				sprintf(buffer, "%d / %d", _AC, _A8);
			} else {
				sprintf(buffer, "%d", _A8);
			}

			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.perspPrintf(gsys->mConsFont, pos, -(gsys->mConsFont->stringWidth(buffer) / 2), 0, buffer);

			for (int i = 0; i < _A8; i++) {
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
				_D8.draw(gfx);
			}

			gfx.setColour(Colour(64, 255, 255, 255), true);
			_C0.draw(gfx);
			gfx.setFog(true);
			gfx.setLighting(lighting, nullptr);
			gfx.setCBlending(blend);
		}

		_A8 = 0;
		_AC = 0;
		// gsys->mTimer->stop("mapPost");
		gfx._324 = 0;
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
			    && z < coll->mBoundingBox.mMax.z && coll->mShape->mSystemFlags & 0x10) {
				for (int i = 0; i < coll->mColliderCount; i++) {
					if (coll->mVisibleList[coll->mColliderList[i]->mStateIndex]) {
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
	_18++;
	f32 minY = -32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, doCheckDynColl); colls; colls = colls->mNextCollider) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->_06 : colls->mTriCount;
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
	_18++;
	f32 minY = 32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, doCheckDynColl); colls; colls = colls->mNextCollider) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->_06 : colls->mTriCount;
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
	_1C++;
	CollTriInfo* tri = nullptr;
	f32 minY         = -32768.0f;
	for (CollGroup* colls = getCollGroupList(x, z, doCheckDynColl); colls; colls = colls->mNextCollider) {
		int count = (AIPerf::showColls) ? colls->mTriCount - colls->_06 : colls->mTriCount;
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
f32 MapMgr::findEdgePenetration(CollTriInfo& tri, Vector3f* vertexList, Vector3f& pos, f32 rad, Vector3f& normal)
{
	for (int i = 0; i < 3; i++) {
		f32 dist = tri.mEdgePlanes[i].dist(pos);
		if (dist < 0.0f && dist >= -rad) {
			Vector3f& vtx1 = vertexList[tri.mVertexIndices[i % 3]];
			Vector3f& vtx2 = vertexList[tri.mVertexIndices[(i + 1) % 3]];

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
		int count = currColls->mTriCount - currColls->_06;
		if (!count) {
			count = colls->mTriCount;
		}

		for (int i = 0; i < currColls->mTriCount; i++) {
			CollTriInfo* tri = currColls->mTriangleList[i];
			if (AIPerf::showColls && i >= count && currColls->_0C[i - count] > radInt + 4) {
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
				trace.mObject->_1A8 = 1;
			}
			bool check2 = false;
			if (!currColls->mSourceCollider) {
				check1 = true;
				vec    = normal;
				trace.mVelocity.bounce(normal, bounceFactor);
				vel.bounce(normal, bounceFactor);
			} else {
				if (check1 && vec.DP(normal) < -0.5f) {
					check2 = true;
				} else {
					if (trace.mObject && currColls->mSourceCollider && currColls->mSourceCollider->mCreature) {
						bounceFactor = 1.0f;
					}
					trace.mVelocity.bounce(normal, bounceFactor);
					vel.bounce(normal, bounceFactor);
				}
			}
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
					if (a == 1 && currColls->mSourceCollider->_24 != mCollisionCheckCount) {
						currColls->mSourceCollider->mContactCount++;
						currColls->mSourceCollider->_24 = mCollisionCheckCount;
					}
					currColls->mSourceCollider->touchCallback(tri->mTriangle, nextPos, trace.mVelocity);
				}
			}
		}
	}
	trace.mPosition = nextPos;

	check1 ? "fake" : "fake";
	check1 ? "fake" : "fake";
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
	mCollisionCheckCount++;
	trace.mStepFraction = 1.0f / a;

	for (int i = 0; i < a; i++) {
		BoundBox box;
		box.expandBound(trace.mPosition);
		box.mMin.sub(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));
		box.mMax.add(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));
		trace.mObject        = creature;
		CollGroup* collGroup = nullptr;

		if (!trace._20) {
			FOREACH_NODE(DynCollShape, mCollShape->mChild, coll)
			{
				if ((!coll->mCreature || coll->mCreature != creature) && box.intersects(coll->mBoundingBox)) {
					for (int j = 0; j < coll->mColliderCount; j++) {
						if (coll->mVisibleList[coll->mColliderList[j]->mStateIndex]) {
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  stfd      f28, 0xE0(r1)
	  fmr       f28, f1
	  stmw      r27, 0xCC(r1)
	  mr        r27, r3
	  mr        r29, r5
	  mr        r28, r4
	  li        r31, 0x1
	  li        r3, 0
	  lfs       f0, -0x6BB8(r13)
	  lfs       f2, 0x0(r5)
	  lfs       f1, 0x18(r5)
	  fadds     f0, f2, f0
	  lfs       f2, -0x6BB4(r13)
	  stfs      f0, 0x0(r5)
	  lfs       f0, 0x4(r5)
	  fadds     f0, f0, f1
	  stfs      f0, 0x4(r5)
	  lfs       f0, 0x8(r5)
	  fadds     f0, f0, f2
	  stfs      f0, 0x8(r5)
	  lfs       f1, 0xC(r5)
	  lfs       f0, 0x10(r5)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x14(r5)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x78B0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xEC
	  fsqrte    f1, f4
	  lfd       f3, -0x78A8(r2)
	  lfd       f2, -0x78A0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x44(r1)
	  lfs       f4, 0x44(r1)

	.loc_0xEC:
	  fmuls     f2, f28, f4
	  lfs       f1, -0x7878(r2)
	  b         .loc_0x104

	.loc_0xF8:
	  fmuls     f2, f2, f1
	  rlwinm    r31,r31,1,0,30
	  addi      r3, r3, 0x1

	.loc_0x104:
	  cmpwi     r3, 0x64
	  bge-      .loc_0x11C
	  lfs       f0, 0x18(r29)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  beq+      .loc_0xF8

	.loc_0x11C:
	  cmpwi     r3, 0x32
	  ble-      .loc_0x1A8
	  lfs       f1, 0xC(r29)
	  lfs       f0, 0x10(r29)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x14(r29)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x78B0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1A8
	  fsqrte    f1, f4
	  lfd       f3, -0x78A8(r2)
	  lfd       f2, -0x78A0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x40(r1)
	  lfs       f4, 0x40(r1)

	.loc_0x1A8:
	  xoris     r0, r31, 0x8000
	  lwz       r3, 0x10C(r27)
	  stw       r0, 0xC4(r1)
	  lis       r0, 0x4330
	  addi      r3, r3, 0x1
	  stw       r3, 0x10C(r27)
	  li        r30, 0
	  stw       r0, 0xC0(r1)
	  lfd       f1, -0x7848(r2)
	  lfd       f0, 0xC0(r1)
	  lfs       f2, -0x7884(r2)
	  fsubs     f0, f0, f1
	  fdivs     f0, f2, f0
	  stfs      f0, 0x1C(r29)
	  lfs       f29, -0x78B0(r2)
	  lfs       f30, -0x7894(r2)
	  lfs       f31, -0x78AC(r2)
	  b         .loc_0x574

	.loc_0x1F0:
	  stfs      f29, 0xA0(r1)
	  stfs      f29, 0x9C(r1)
	  stfs      f29, 0x98(r1)
	  stfs      f29, 0xAC(r1)
	  stfs      f29, 0xA8(r1)
	  stfs      f29, 0xA4(r1)
	  lfs       f1, -0x6D18(r13)
	  lfs       f0, -0x6D14(r13)
	  stfs      f1, 0x98(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0xA0(r1)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0xA8(r1)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0xAC(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x98(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x24C
	  stfs      f1, 0x98(r1)

	.loc_0x24C:
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x9C(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x260
	  stfs      f1, 0x9C(r1)

	.loc_0x260:
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0xA0(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x274
	  stfs      f1, 0xA0(r1)

	.loc_0x274:
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0xA4(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x288
	  stfs      f1, 0xA4(r1)

	.loc_0x288:
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0xA8(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x29C
	  stfs      f1, 0xA8(r1)

	.loc_0x29C:
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0xAC(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2B0
	  stfs      f1, 0xAC(r1)

	.loc_0x2B0:
	  lfs       f0, 0x18(r29)
	  li        r4, 0
	  lfs       f1, 0x98(r1)
	  fmuls     f2, f30, f0
	  fmuls     f0, f31, f0
	  fsubs     f1, f1, f2
	  stfs      f1, 0x98(r1)
	  lfs       f1, 0x9C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0x18(r29)
	  lfs       f1, 0xA4(r1)
	  fmuls     f2, f30, f0
	  fmuls     f0, f31, f0
	  fadds     f1, f1, f2
	  stfs      f1, 0xA4(r1)
	  lfs       f1, 0xA8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0xAC(r1)
	  fadds     f0, f0, f2
	  stfs      f0, 0xAC(r1)
	  stw       r28, 0x24(r29)
	  lbz       r0, 0x20(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x450
	  lwz       r3, 0x88(r27)
	  lwz       r7, 0x10(r3)
	  b         .loc_0x448

	.loc_0x330:
	  lwz       r0, 0x28(r7)
	  cmplwi    r0, 0
	  beq-      .loc_0x344
	  cmplw     r0, r28
	  beq-      .loc_0x444

	.loc_0x344:
	  lfs       f1, 0x44(r7)
	  lfs       f0, 0xA4(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x50(r7)
	  lfs       f0, 0x98(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x48(r7)
	  lfs       f0, 0xA8(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x54(r7)
	  lfs       f0, 0x9C(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x4C(r7)
	  lfs       f0, 0xAC(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x58(r7)
	  lfs       f0, 0xA0(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C4
	  li        r0, 0x1
	  b         .loc_0x3C8

	.loc_0x3C4:
	  li        r0, 0

	.loc_0x3C8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x444
	  li        r8, 0
	  li        r6, 0
	  b         .loc_0x438

	.loc_0x3DC:
	  lwz       r3, 0x40(r7)
	  lwz       r5, 0x38(r7)
	  lwzx      r3, r3, r6
	  lwz       r0, 0x18(r3)
	  lbzx      r0, r5, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x430
	  lwz       r0, 0x2C(r7)
	  stw       r0, 0x10(r3)
	  lwz       r3, 0x40(r7)
	  lwz       r0, 0x30(r7)
	  lwzx      r3, r3, r6
	  stw       r0, 0x14(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r3, r3, r6
	  stw       r7, 0x1C(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r3, r3, r6
	  stw       r4, 0x20(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r4, r3, r6

	.loc_0x430:
	  addi      r6, r6, 0x4
	  addi      r8, r8, 0x1

	.loc_0x438:
	  lwz       r0, 0x3C(r7)
	  cmpw      r8, r0
	  blt+      .loc_0x3DC

	.loc_0x444:
	  lwz       r7, 0xC(r7)

	.loc_0x448:
	  cmplwi    r7, 0
	  bne+      .loc_0x330

	.loc_0x450:
	  lwz       r7, 0x60(r27)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x140(r7)
	  lfs       f3, 0x158(r7)
	  fsubs     f2, f1, f0
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x148(r7)
	  fdivs     f2, f2, f3
	  fctiwz    f2, f2
	  fsubs     f0, f1, f0
	  stfd      f2, 0xB0(r1)
	  fdivs     f0, f0, f3
	  lwz       r0, 0xB4(r1)
	  stfd      f2, 0xC0(r1)
	  cmpwi     r0, 0
	  lwz       r5, 0xC4(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0xB8(r1)
	  lwz       r3, 0xBC(r1)
	  blt-      .loc_0x4C0
	  cmpwi     r3, 0
	  blt-      .loc_0x4C0
	  lwz       r6, 0x15C(r7)
	  cmpw      r5, r6
	  bge-      .loc_0x4C0
	  lwz       r0, 0x160(r7)
	  cmpw      r3, r0
	  blt-      .loc_0x4C8

	.loc_0x4C0:
	  li        r5, 0
	  b         .loc_0x4DC

	.loc_0x4C8:
	  mullw     r0, r3, r6
	  lwz       r3, 0x164(r7)
	  add       r0, r5, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r3, r0

	.loc_0x4DC:
	  cmplwi    r5, 0
	  beq-      .loc_0x510
	  lha       r0, 0x4(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x510
	  stw       r7, 0x10(r5)
	  li        r0, 0
	  lwz       r3, 0x60(r27)
	  lwz       r3, 0x23C(r3)
	  stw       r3, 0x14(r5)
	  stw       r0, 0x1C(r5)
	  stw       r4, 0x20(r5)
	  mr        r4, r5

	.loc_0x510:
	  cmplwi    r4, 0
	  beq-      .loc_0x52C
	  fmr       f1, f28
	  addi      r3, r27, 0
	  addi      r5, r29, 0
	  bl        -0xD58
	  b         .loc_0x570

	.loc_0x52C:
	  lfs       f0, 0x1C(r29)
	  lfs       f2, 0xC(r29)
	  fmuls     f1, f28, f0
	  lfs       f3, 0x10(r29)
	  lfs       f4, 0x14(r29)
	  lfs       f0, 0x0(r29)
	  fmuls     f2, f2, f1
	  fmuls     f3, f3, f1
	  fmuls     f4, f4, f1
	  fadds     f0, f0, f2
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f0, f3
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f0, f4
	  stfs      f0, 0x8(r29)

	.loc_0x570:
	  addi      r30, r30, 0x1

	.loc_0x574:
	  cmpw      r30, r31
	  blt+      .loc_0x1F0
	  lfs       f1, 0x0(r29)
	  lfs       f0, -0x6BB0(r13)
	  lfs       f2, 0x18(r29)
	  fsubs     f0, f1, f0
	  lfs       f1, -0x6BAC(r13)
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x8(r29)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x8(r29)
	  lwz       r0, 0x104(r1)
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  lfd       f28, 0xE0(r1)
	  lmw       r27, 0xCC(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069424
 * Size:	000070
 */
Shape* MapMgr::loadPlatshape(char* path)
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
	part->_140             = obj;
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
	int togglePrint    = !!gsys->mTogglePrint;
	gsys->mTogglePrint = 1;
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
