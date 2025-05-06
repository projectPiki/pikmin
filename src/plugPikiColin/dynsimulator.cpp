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
DEFINE_ERROR()

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
	_00             = 2;
	mShape          = shape;
	mCollisionCount = 0;
	_0C++;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
bool CollState::add(Vector3f& normal, Vector3f& contactPt, RigidBody* collider)
{
	if (mCollisionCount < 10) {
		_00                                        = 1;
		mCollisions[mCollisionCount].mNormal       = normal;
		mCollisions[mCollisionCount].mContactPoint = contactPt;
		mCollisions[mCollisionCount]._1C           = collider;
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
	mtx1.makeVQS(_13260, _1328C, Vector3f(1.0f, 1.0f, 1.0f));
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

	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r4, r4, 0x308C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x5C8(r1)
	  stfd      f31, 0x5C0(r1)
	  stfd      f30, 0x5B8(r1)
	  stfd      f29, 0x5B0(r1)
	  stfd      f28, 0x5A8(r1)
	  stfd      f27, 0x5A0(r1)
	  stfd      f26, 0x598(r1)
	  fmr       f26, f1
	  stfd      f25, 0x590(r1)
	  stfd      f24, 0x588(r1)
	  stfd      f23, 0x580(r1)
	  stmw      r26, 0x568(r1)
	  addi      r26, r3, 0
	  addi      r28, r4, 0x4118
	  add       r28, r26, r28
	  mulli     r3, r5, 0x308C
	  addi      r5, r3, 0x4118
	  add       r5, r26, r5
	  lfs       f0, 0x40(r28)
	  addi      r27, r5, 0
	  addi      r29, r1, 0x4C8
	  fmuls     f0, f0, f26
	  addi      r30, r1, 0x4D4
	  addi      r3, r1, 0x408
	  stfs      f0, 0x2F4(r1)
	  lfs       f1, 0x34(r28)
	  lfs       f0, 0x2F4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x438(r1)
	  lfs       f0, 0x438(r1)
	  stfs      f0, 0x558(r1)
	  lfs       f0, 0x44(r28)
	  lfs       f1, 0x38(r28)
	  fmuls     f0, f0, f26
	  fadds     f0, f1, f0
	  stfs      f0, 0x55C(r1)
	  lfs       f0, 0x48(r28)
	  lfs       f1, 0x3C(r28)
	  fmuls     f0, f0, f26
	  fadds     f0, f1, f0
	  stfs      f0, 0x560(r1)
	  lwz       r4, 0x558(r1)
	  lwz       r0, 0x55C(r1)
	  stw       r4, 0x34(r5)
	  stw       r0, 0x38(r5)
	  lwz       r0, 0x560(r1)
	  stw       r0, 0x3C(r5)
	  lfs       f1, -0x7B30(r2)
	  stfs      f1, 0x4BC(r1)
	  lfs       f0, 0x54(r28)
	  fneg      f0, f0
	  stfs      f0, 0x4C0(r1)
	  lfs       f0, 0x50(r28)
	  stfs      f0, 0x4C4(r1)
	  lfs       f0, 0x54(r28)
	  stfs      f0, 0x4C8(r1)
	  stfs      f1, 0x4CC(r1)
	  lfs       f0, 0x4C(r28)
	  fneg      f0, f0
	  stfs      f0, 0x4D0(r1)
	  lfs       f0, 0x50(r28)
	  fneg      f0, f0
	  stfs      f0, 0x4D4(r1)
	  lfs       f0, 0x4C(r28)
	  stfs      f0, 0x4D8(r1)
	  stfs      f1, 0x4DC(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x4BC(r1)
	  addi      r3, r1, 0x3D8
	  fmuls     f0, f26, f0
	  stfs      f0, 0x408(r1)
	  lfs       f0, 0x4C8(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x414(r1)
	  lfs       f0, 0x4D4(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x420(r1)
	  lfs       f0, 0x4C0(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x40C(r1)
	  lfs       f0, 0x4(r29)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x418(r1)
	  lfs       f0, 0x4(r30)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x424(r1)
	  lfs       f0, 0x4C4(r1)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x410(r1)
	  lfs       f0, 0x8(r29)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x41C(r1)
	  lfs       f0, 0x8(r30)
	  fmuls     f0, f26, f0
	  stfs      f0, 0x428(r1)
	  lwz       r0, 0x408(r1)
	  lwz       r4, 0x40C(r1)
	  stw       r0, 0x4E0(r1)
	  lwz       r0, 0x410(r1)
	  stw       r4, 0x4E4(r1)
	  lwz       r4, 0x414(r1)
	  stw       r0, 0x4E8(r1)
	  lwz       r0, 0x418(r1)
	  stw       r4, 0x4EC(r1)
	  lwz       r4, 0x41C(r1)
	  stw       r0, 0x4F0(r1)
	  lwz       r0, 0x420(r1)
	  stw       r4, 0x4F4(r1)
	  lwz       r4, 0x424(r1)
	  stw       r0, 0x4F8(r1)
	  lwz       r0, 0x428(r1)
	  stw       r4, 0x4FC(r1)
	  stw       r0, 0x500(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x0(r28)
	  addi      r5, r1, 0x3D8
	  lfs       f1, 0x4E0(r1)
	  addi      r6, r1, 0x4E0
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0xC(r28)
	  lfs       f5, 0x4E4(r1)
	  addi      r5, r5, 0xC
	  lfs       f1, 0x4E8(r1)
	  fadds     f3, f3, f2
	  lfs       f0, 0x18(r28)
	  fmuls     f2, f5, f4
	  addi      r6, r6, 0xC
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x3D8(r1)
	  lfs       f0, 0x4(r28)
	  lfs       f1, 0x4E0(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x10(r28)
	  lfs       f5, 0x4E4(r1)
	  lfs       f0, 0x1C(r28)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x4E8(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x3DC(r1)
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x4E0(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x14(r28)
	  lfs       f5, 0x4E4(r1)
	  lfs       f1, 0x4E8(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x20(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x3E0(r1)
	  lfs       f0, 0x0(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0xC(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x18(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x4(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x10(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x1C(r28)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x14(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  addi      r6, r6, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x20(r28)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  addi      r5, r5, 0xC
	  lfs       f0, 0x0(r28)
	  addi      r3, r1, 0x3B0
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0xC(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x18(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x4(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x10(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x1C(r28)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x14(r28)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x20(r28)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  lwz       r0, 0x3D8(r1)
	  lwz       r4, 0x3DC(r1)
	  stw       r0, 0x504(r1)
	  lwz       r0, 0x3E0(r1)
	  stw       r4, 0x508(r1)
	  lwz       r4, 0x3E4(r1)
	  stw       r0, 0x50C(r1)
	  lwz       r0, 0x3E8(r1)
	  stw       r4, 0x510(r1)
	  lwz       r4, 0x3EC(r1)
	  stw       r0, 0x514(r1)
	  lwz       r0, 0x3F0(r1)
	  stw       r4, 0x518(r1)
	  lwz       r4, 0x3F4(r1)
	  stw       r0, 0x51C(r1)
	  lwz       r0, 0x3F8(r1)
	  stw       r4, 0x520(r1)
	  stw       r0, 0x524(r1)
	  bl        .loc_0xD90
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x504(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3B0(r1)
	  lfs       f1, 0xC(r28)
	  lfs       f0, 0x510(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3BC(r1)
	  lfs       f1, 0x18(r28)
	  lfs       f0, 0x51C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C8(r1)
	  lfs       f1, 0x4(r28)
	  lfs       f0, 0x508(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3B4(r1)
	  lfs       f1, 0x10(r28)
	  lfs       f0, 0x514(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C0(r1)
	  lfs       f1, 0x1C(r28)
	  lfs       f0, 0x520(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3CC(r1)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x50C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3B8(r1)
	  lfs       f1, 0x14(r28)
	  lfs       f0, 0x518(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C4(r1)
	  lfs       f1, 0x20(r28)
	  lfs       f0, 0x524(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3D0(r1)
	  lwz       r0, 0x3B0(r1)
	  addis     r3, r26, 0x1
	  lwz       r4, 0x3B4(r1)
	  addi      r29, r27, 0x1C
	  stw       r0, 0x528(r1)
	  lwz       r0, 0x3B8(r1)
	  addi      r30, r27, 0x10
	  stw       r4, 0x52C(r1)
	  addi      r31, r27, 0x4
	  lwz       r4, 0x3BC(r1)
	  stw       r0, 0x530(r1)
	  lwz       r0, 0x3C0(r1)
	  stw       r4, 0x534(r1)
	  lwz       r4, 0x3C4(r1)
	  stw       r0, 0x538(r1)
	  lwz       r0, 0x3C8(r1)
	  stw       r4, 0x53C(r1)
	  lwz       r4, 0x3CC(r1)
	  stw       r0, 0x540(r1)
	  lwz       r0, 0x3D0(r1)
	  stw       r4, 0x544(r1)
	  stw       r0, 0x548(r1)
	  lwz       r4, 0x528(r1)
	  lwz       r0, 0x52C(r1)
	  stw       r4, 0x0(r27)
	  stw       r0, 0x4(r27)
	  lwz       r4, 0x530(r1)
	  lwz       r0, 0x534(r1)
	  stw       r4, 0x8(r27)
	  stw       r0, 0xC(r27)
	  lwz       r4, 0x538(r1)
	  lwz       r0, 0x53C(r1)
	  stw       r4, 0x10(r27)
	  stw       r0, 0x14(r27)
	  lwz       r4, 0x540(r1)
	  lwz       r0, 0x544(r1)
	  stw       r4, 0x18(r27)
	  stw       r0, 0x1C(r27)
	  lwz       r0, 0x548(r1)
	  stw       r0, 0x20(r27)
	  lfs       f1, 0x60(r26)
	  lfs       f0, -0x5DD0(r3)
	  fmuls     f2, f26, f1
	  lfs       f1, 0x40(r28)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r27)
	  lfs       f0, -0x5DCC(r3)
	  lfs       f1, 0x44(r28)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x44(r27)
	  lfs       f0, -0x5DC8(r3)
	  lfs       f1, 0x48(r28)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r27)
	  lfs       f0, -0x5DC4(r3)
	  lfs       f1, 0x58(r28)
	  fmuls     f0, f26, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r27)
	  lfs       f0, -0x5DC0(r3)
	  lfs       f1, 0x5C(r28)
	  fmuls     f0, f26, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C(r27)
	  lfs       f0, -0x5DBC(r3)
	  lfs       f1, 0x60(r28)
	  fmuls     f0, f26, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x60(r27)
	  lfs       f31, 0x0(r27)
	  lfs       f30, 0xC(r27)
	  lfs       f29, 0x18(r27)
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  lfs       f28, 0x4(r27)
	  fmuls     f2, f29, f29
	  lfs       f27, 0x10(r27)
	  fadds     f0, f1, f0
	  lfs       f26, 0x1C(r27)
	  fadds     f1, f2, f0
	  bl        -0x40AEC
	  lfs       f0, -0x7B30(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x62C
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x62C:
	  fmuls     f3, f30, f26
	  fmuls     f2, f29, f27
	  fmuls     f1, f29, f28
	  fmuls     f0, f31, f26
	  fsubs     f26, f3, f2
	  fmuls     f3, f31, f27
	  fsubs     f27, f1, f0
	  fmuls     f2, f30, f28
	  fmuls     f1, f26, f26
	  fmuls     f0, f27, f27
	  fsubs     f28, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f28, f28
	  fadds     f1, f1, f0
	  bl        -0x40B40
	  lfs       f0, -0x7B30(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x680
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x680:
	  fmuls     f3, f27, f29
	  fmuls     f2, f28, f30
	  fmuls     f1, f28, f31
	  fmuls     f0, f26, f29
	  fsubs     f25, f3, f2
	  fmuls     f3, f26, f30
	  fsubs     f24, f1, f0
	  fmuls     f2, f27, f31
	  fmuls     f1, f25, f25
	  fmuls     f0, f24, f24
	  fsubs     f23, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f23, f23
	  fadds     f1, f1, f0
	  bl        -0x40B94
	  lfs       f0, -0x7B30(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x6D4
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x6D4:
	  stfs      f31, 0x0(r27)
	  addi      r4, r27, 0
	  addi      r3, r27, 0x24
	  stfs      f25, 0x0(r31)
	  stfs      f26, 0x8(r27)
	  stfs      f30, 0xC(r27)
	  stfs      f24, 0x0(r30)
	  stfs      f27, 0x14(r27)
	  stfs      f29, 0x18(r27)
	  stfs      f23, 0x0(r29)
	  stfs      f28, 0x20(r27)
	  bl        -0x16F60
	  addi      r3, r1, 0x360
	  bl        .loc_0xD90
	  lfs       f1, 0x0(r27)
	  addi      r5, r1, 0x360
	  lfs       f0, 0x64(r26)
	  addi      r6, r27, 0xC
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r26)
	  lfs       f5, 0x4(r27)
	  addi      r5, r5, 0xC
	  lfs       f0, 0x7C(r26)
	  fadds     f3, f3, f2
	  lfs       f1, 0x8(r27)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x360(r1)
	  lfs       f0, 0x68(r26)
	  lfs       f1, 0x0(r27)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r26)
	  lfs       f5, 0x4(r27)
	  lfs       f0, 0x80(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r27)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x364(r1)
	  lfs       f0, 0x6C(r26)
	  lfs       f1, 0x0(r27)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r26)
	  lfs       f5, 0x4(r27)
	  lfs       f1, 0x8(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r26)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x368(r1)
	  lfs       f1, 0x0(r6)
	  lfs       f0, 0x64(r26)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  addi      r6, r6, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x84(r26)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  addi      r5, r5, 0xC
	  lfs       f1, 0x0(r6)
	  addi      r31, r1, 0x474
	  lfs       f0, 0x64(r26)
	  addi      r3, r1, 0x338
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r26)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r26)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r26)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r26)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  lwz       r0, 0x360(r1)
	  lwz       r4, 0x364(r1)
	  stw       r0, 0x474(r1)
	  lwz       r0, 0x368(r1)
	  stw       r4, 0x478(r1)
	  lwz       r4, 0x36C(r1)
	  stw       r0, 0x47C(r1)
	  lwz       r0, 0x370(r1)
	  stw       r4, 0x480(r1)
	  lwz       r4, 0x374(r1)
	  stw       r0, 0x484(r1)
	  lwz       r0, 0x378(r1)
	  stw       r4, 0x488(r1)
	  lwz       r4, 0x37C(r1)
	  stw       r0, 0x48C(r1)
	  lwz       r0, 0x380(r1)
	  stw       r4, 0x490(r1)
	  stw       r0, 0x494(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x0(r27)
	  addi      r3, r1, 0x30C
	  stfs      f0, 0x338(r1)
	  lfs       f0, 0x4(r27)
	  stfs      f0, 0x344(r1)
	  lfs       f0, 0x8(r27)
	  stfs      f0, 0x350(r1)
	  lfs       f0, 0xC(r27)
	  stfs      f0, 0x33C(r1)
	  lfs       f0, 0x10(r27)
	  stfs      f0, 0x348(r1)
	  lfs       f0, 0x14(r27)
	  stfs      f0, 0x354(r1)
	  lfs       f0, 0x18(r27)
	  stfs      f0, 0x340(r1)
	  lfs       f0, 0x1C(r27)
	  stfs      f0, 0x34C(r1)
	  lfs       f0, 0x20(r27)
	  stfs      f0, 0x358(r1)
	  lwz       r0, 0x338(r1)
	  lwz       r4, 0x33C(r1)
	  stw       r0, 0x450(r1)
	  lwz       r0, 0x340(r1)
	  stw       r4, 0x454(r1)
	  lwz       r4, 0x344(r1)
	  stw       r0, 0x458(r1)
	  lwz       r0, 0x348(r1)
	  stw       r4, 0x45C(r1)
	  lwz       r4, 0x34C(r1)
	  stw       r0, 0x460(r1)
	  lwz       r0, 0x350(r1)
	  stw       r4, 0x464(r1)
	  lwz       r4, 0x354(r1)
	  stw       r0, 0x468(r1)
	  lwz       r0, 0x358(r1)
	  stw       r4, 0x46C(r1)
	  stw       r0, 0x470(r1)
	  bl        .loc_0xD90
	  lfs       f0, 0x450(r1)
	  addi      r4, r1, 0x30C
	  lfs       f1, 0x474(r1)
	  addi      r5, r31, 0xC
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x45C(r1)
	  lfs       f5, 0x478(r1)
	  addi      r4, r4, 0xC
	  lfs       f1, 0x47C(r1)
	  fadds     f3, f3, f2
	  lfs       f0, 0x468(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x30C(r1)
	  lfs       f0, 0x454(r1)
	  lfs       f1, 0x474(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x460(r1)
	  lfs       f5, 0x478(r1)
	  lfs       f1, 0x47C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x46C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x310(r1)
	  lfs       f0, 0x458(r1)
	  lfs       f1, 0x474(r1)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x464(r1)
	  lfs       f5, 0x478(r1)
	  lfs       f1, 0x47C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x470(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x314(r1)
	  lfs       f0, 0x450(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x45C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x468(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x454(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x460(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x46C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x458(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x464(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  addi      r5, r5, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x470(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  addi      r4, r4, 0xC
	  lfs       f0, 0x450(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x45C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x468(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x454(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x460(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x46C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x458(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x7B30(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x464(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x470(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  lwz       r0, 0x30C(r1)
	  lwz       r3, 0x310(r1)
	  stw       r0, 0x498(r1)
	  lwz       r0, 0x314(r1)
	  stw       r3, 0x49C(r1)
	  lwz       r3, 0x318(r1)
	  stw       r0, 0x4A0(r1)
	  lwz       r0, 0x31C(r1)
	  stw       r3, 0x4A4(r1)
	  lwz       r3, 0x320(r1)
	  stw       r0, 0x4A8(r1)
	  lwz       r0, 0x324(r1)
	  stw       r3, 0x4AC(r1)
	  lwz       r3, 0x328(r1)
	  stw       r0, 0x4B0(r1)
	  lwz       r0, 0x32C(r1)
	  stw       r3, 0x4B4(r1)
	  stw       r0, 0x4B8(r1)
	  lwz       r3, 0x498(r1)
	  lwz       r0, 0x49C(r1)
	  stw       r3, 0x64(r27)
	  stw       r0, 0x68(r27)
	  lwz       r3, 0x4A0(r1)
	  lwz       r0, 0x4A4(r1)
	  stw       r3, 0x6C(r27)
	  stw       r0, 0x70(r27)
	  lwz       r3, 0x4A8(r1)
	  lwz       r0, 0x4AC(r1)
	  stw       r3, 0x74(r27)
	  stw       r0, 0x78(r27)
	  lwz       r3, 0x4B0(r1)
	  lwz       r0, 0x4B4(r1)
	  stw       r3, 0x7C(r27)
	  stw       r0, 0x80(r27)
	  lwz       r0, 0x4B8(r1)
	  stw       r0, 0x84(r27)
	  lfs       f0, -0x7B30(r2)
	  stfs      f0, 0x308(r1)
	  stfs      f0, 0x304(r1)
	  stfs      f0, 0x300(r1)
	  lfs       f4, 0x58(r27)
	  lfs       f1, 0x64(r27)
	  lfs       f3, 0x5C(r27)
	  lfs       f0, 0x68(r27)
	  fmuls     f1, f4, f1
	  lfs       f5, 0x60(r27)
	  fmuls     f0, f3, f0
	  lfs       f2, 0x6C(r27)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x300(r1)
	  lfs       f1, 0x70(r27)
	  lfs       f0, 0x74(r27)
	  lfs       f2, 0x78(r27)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x304(r1)
	  lfs       f1, 0x7C(r27)
	  lfs       f0, 0x80(r27)
	  lfs       f2, 0x84(r27)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x308(r1)
	  lfs       f0, 0x300(r1)
	  stfs      f0, 0x444(r1)
	  lfs       f0, 0x304(r1)
	  stfs      f0, 0x448(r1)
	  lfs       f0, 0x308(r1)
	  stfs      f0, 0x44C(r1)
	  lwz       r3, 0x444(r1)
	  lwz       r0, 0x448(r1)
	  stw       r3, 0x4C(r27)
	  stw       r0, 0x50(r27)
	  lwz       r0, 0x44C(r1)
	  stw       r0, 0x54(r27)
	  lmw       r26, 0x568(r1)
	  lwz       r0, 0x5CC(r1)
	  lfd       f31, 0x5C0(r1)
	  lfd       f30, 0x5B8(r1)
	  lfd       f29, 0x5B0(r1)
	  lfd       f28, 0x5A8(r1)
	  lfd       f27, 0x5A0(r1)
	  lfd       f26, 0x598(r1)
	  lfd       f25, 0x590(r1)
	  lfd       f24, 0x588(r1)
	  lfd       f23, 0x580(r1)
	  addi      r1, r1, 0x5C8
	  mtlr      r0
	  blr

	.loc_0xD90:
	*/
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
				u32 badCompiler;
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
		_A248[p1][i] = mIntegrationStates[configIdx].mBodyPoints[i];
	}

	_13248[p1] = mIntegrationStates[configIdx].mPosition;
	_1326C[p1] = mIntegrationStates[configIdx].mOrientationQuat;

	makeBodyQuat(_1326C[p1]);
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
		_10248[i] = _A248[idx1][i] + (_A248[idx2][i] - _A248[idx1][i]) * p2;
	}

	_13260 = _13248[idx1] + (_13248[idx2] - _13248[idx1]) * p2;
	_1328C = _1326C[idx1];
	_1328C.slerp(_1326C[idx2], p2, 1);
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

	_30._00 = 2;
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
		body->updateViewInfo(_24, mCurrentConfigIdx ^ 1);
	}

	_24 ^= 1;
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
		body->updateVecQuats(_24, p1);
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
