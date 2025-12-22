#include "DynCreature.h"

#include "CreatureProp.h"
#include "DebugLog.h"
#include "DynParticle.h"
#include "Graphics.h"
#include "KMath.h"
#include "MapMgr.h"
#include "Matrix4f.h"
#include "UtilityKando.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(10)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

DynParticleHeap* particleHeap;

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
static void printMatrix(immut char* name, immut Matrix4f& mat)
{
	// This implementation borrowed from goalItem.cpp inflates the stack too much to be left in matching builds.
	// According to the DLL, this TU's implementation of this function was genuinely empty / commented-out.
#if defined(DEVELOP)
	PRINT("++++ MATRIX %s ++++\n", name);
	for (int i = 0; i < 4; ++i) {
		PRINT("  %f %f %f %f\n", mat.mMtx[i][0], mat.mMtx[i][1], mat.mMtx[i][2], mat.mMtx[i][3]);
	}
	PRINT("-------------------------\n");
#endif
}

/**
 * @TODO: Documentation
 */
DynParticle::DynParticle()
{
	initCore("particle");
	mIsFree = 0;
	mMass   = 100.0f;
	mLocalPosition.set(0.0f, 0.0f, 0.0f);
	mNextParticle    = nullptr;
	mCollisionRadius = 0.01f;

	// this is so this doesn't inline in DynParticleHeap
	FORCE_DONT_INLINE;
}

/**
 * @TODO: Documentation
 */
f32 DynParticle::getSize()
{
	return mCollisionRadius * 3.0f;
}

/**
 * @TODO: Documentation
 */
void DynParticle::refresh(Graphics&)
{
}

/**
 * @TODO: Documentation
 */
void DynParticle::doKill()
{
}

/**
 * @TODO: Documentation
 */
DynParticleHeap::DynParticleHeap(int numParticles)
{
	CreatureProp* unusedProps = new CreatureProp();
	mHeap                     = new DynParticle[numParticles];
	mNumParticles             = numParticles;

	mFreeParticleList.initCore("freeParticles");
	mUsedParticleList.initCore("useParticles");

	for (int i = 0; i < numParticles; i++) {
		mHeap[i].mNextParticle = nullptr;
		mFreeParticleList.add(&mHeap[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
DynParticle* DynParticleHeap::getFreeOne()
{
	DynParticle* ptcl = static_cast<DynParticle*>(mFreeParticleList.mChild);
	if (ptcl) {
		ptcl->del();
		ptcl->mNextParticle = nullptr;
		mUsedParticleList.add(ptcl);
	}
	return ptcl;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void DynParticleHeap::releaseOne(DynParticle* ptcl)
{
	ptcl->del();
	ptcl->mNextParticle = nullptr;
	mFreeParticleList.add(ptcl);
}

/**
 * @TODO: Documentation
 */
DynCreature::DynCreature()
    : Creature(nullptr)
{
	mParticleList  = nullptr;
	mParticleCount = 0;
	mMass          = 0.0f;
	mPickOffset    = 0.0f;
	mAngularImpulseAccum.set(0.0f, 0.0f, 0.0f);
	mAngularMomentum.set(0.0f, 0.0f, 0.0f);
	mAngularVelocity.set(0.0f, 0.0f, 0.0f);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	enableFriction();
}

/**
 * @TODO: Documentation
 */
void DynCreature::enablePickOffset(f32 offset)
{
	enableGroundOffset(offset);
	mPickOffset = -offset;
}

/**
 * @TODO: Documentation
 */
void DynCreature::disablePickOffset()
{
	disableGroundOffset();
	mPickOffset = 0.0f;
}

/**
 * @TODO: Documentation
 */
void DynCreature::addParticle(f32 mass, immut Vector3f& position)
{
	DynParticle* ptcl = particleHeap->getFreeOne();
	if (ptcl) {
		ptcl->mMass            = mass;
		ptcl->mLocalPosition   = position;
		ptcl->mInitialPosition = position;
		if (!mParticleList) {
			mParticleList = ptcl;
		} else {
			DynParticle* nextPtcl = mParticleList;
			while (nextPtcl->mNextParticle) {
				nextPtcl = nextPtcl->mNextParticle;
			}

			nextPtcl->mNextParticle = ptcl;
		}

		mMass += mass;
		mParticleCount++;
	} else {
#if defined(VERSION_GPIE01_00) || defined(VERSION_GPIE01_01) || defined(VERSION_GPIP01_00)
#else
		PRINT("PARTICLE ADD FAILED ! (%s)\n", ObjType::getName(mObjType));
		ERROR("ZANNEN !\n");
#endif
	}
}

/**
 * @TODO: Documentation
 */
void DynCreature::releaseAllParticles()
{
	DynParticle* ptcl = mParticleList;
	while (ptcl) {
		DynParticle* next = ptcl->mNextParticle;
		particleHeap->releaseOne(ptcl);
		ptcl = next;
	}

	mParticleList = nullptr;
}

/**
 * @TODO: Documentation
 */
void DynCreature::initialiseSystem()
{
	setCreatureFlag(CF_Unk1 | CF_Unk10);
	mCenterOfMass.set(0.0f, 0.0f, 0.0f);
	mMass = 0.0f;

	// First pass: Calculate total mass and weighted center of mass
	for (DynParticle* ptcl = mParticleList; ptcl; ptcl = ptcl->mNextParticle) {
		mCenterOfMass = mCenterOfMass + ptcl->mMass * ptcl->mInitialPosition;
		mMass += ptcl->mMass;
	}

	// Average out the center of mass by dividing by total mass
	mCenterOfMass = mCenterOfMass * (1.0f / mMass);

	// Second pass: Adjust particle positions relative to center of mass
	for (DynParticle* ptcl = mParticleList; ptcl; ptcl = ptcl->mNextParticle) {
		ptcl->mLocalPosition = ptcl->mInitialPosition - mCenterOfMass;
	}

	createInvInertiaTensor();
}

/**
 * @TODO: Documentation
 */
void DynCreature::update()
{
	simulate(gsys->getFrameTime());
	Creature::update();
}

/**
 * @TODO: Documentation
 */
void DynCreature::simulate(f32 timeStep)
{
	mAngularImpulseAccum.set(0.0f, 0.0f, 0.0f);
	mGroundFlag = 0;

	Matrix4f rotMtx;
	Matrix4f tmpMtx;
	Matrix4f rotTransMtx;

	// Build rotation matrix from current orientation quaternion
	rotMtx.makeVQS(Vector3f(0.0f, 0.0f, 0.0f), mRotationQuat, Vector3f(1.0f, 1.0f, 1.0f));
	rotMtx.transposeTo(rotTransMtx);

	printMatrix("rotate", rotMtx);
	printMatrix("rotate^T", rotTransMtx);

	// Transform inertia tensors to world space for physics calculations
	rotMtx.multiplyTo(mInvInertiaTensor, tmpMtx);
	tmpMtx.multiplyTo(rotTransMtx, mWorldInvInertiaTensor);
	rotMtx.multiplyTo(mInertiaTensor, tmpMtx);
	tmpMtx.multiplyTo(rotTransMtx, mWorldInertiaTensor);

	// Check if creature is in slow-fall state (terminal velocity check)
	bool isSlowFall = false;
	if (mVelocity.y >= -60.0f && mVelocity.y < 0.0f) {
		isSlowFall = true;
	}

	f32 maxPenetration = 0.0f;
	STACK_PAD_VAR(1);
	Vector3f maxNormal(0.0f, 1.0f, 0.0f);

	DynParticle* ptcl      = mParticleList;
	int collisionCount     = 0;
	int groundContactCount = 0;
	int particleIndex      = 0;

	// Process collision response for each particle
	for (ptcl; ptcl; ptcl = ptcl->mNextParticle, particleIndex++) {
		// Transform particle to world space
		Vector3f localPosition(ptcl->mLocalPosition);
		localPosition.y += mPickOffset;
		ptcl->mWorldPosition = localPosition;
		ptcl->mWorldPosition.multMatrix(rotMtx);
		ptcl->mWorldPosition.add(mCenterOfMass);
		ptcl->mWorldPosition.add(mSRT.t);

		ptcl->mWorldVelocity = mAngularVelocity;

		Vector3f rotatedPosition(ptcl->mLocalPosition);
		rotatedPosition.multMatrix(rotMtx);
		ptcl->mWorldVelocity.CP(rotatedPosition);

		// Apply creature velocity to particle, handling slow-fall case
		if (!isSlowFall) {
			ptcl->mWorldVelocity = ptcl->mWorldVelocity + mVelocity;
		} else {
			ptcl->mWorldVelocity.x += mVelocity.x;
			ptcl->mWorldVelocity.z += mVelocity.z;
		}

		ptcl->mPreCollisionVelocity = ptcl->mWorldVelocity;

		// Ground collision detection
		f32 groundHeight = mapMgr->getMinY(ptcl->mWorldPosition.x, ptcl->mWorldPosition.z, true);
		Vector3f vec(0.0f, 0.0f, 0.0f);
		f32 penetrationDepth = groundHeight - (ptcl->mWorldPosition.y - ptcl->mCollisionRadius);

		if (ptcl->mWorldPosition.y - groundHeight < ptcl->mCollisionRadius) {
			// Mark this particle as in contact with ground
			mGroundFlag |= (1 << particleIndex);
			groundContactCount++;

			// Calculate collision normal from terrain or cylinder collision
			Vector3f collisionNormal;
			STACK_PAD_VAR(1);
			CollTriInfo* groundTriangle = mapMgr->getCurrTri(ptcl->mWorldPosition.x, ptcl->mWorldPosition.z, true);
			if (groundTriangle) {
				collisionNormal = groundTriangle->mTriangle.mNormal;
				collisionNormal.normalise();
			} else {
				collisionNormal.set(0.0f, 1.0f, 0.0f);
			}

			// Handle deep penetration by using direction to center
			if (0.5f * getCylinderHeight() + mSRT.t.y < groundHeight) {
				collisionNormal = mSRT.t - ptcl->mWorldPosition;
				collisionNormal.normalise();
			}

			// Track deepest penetration for position correction
			if (maxPenetration < penetrationDepth) {
				maxPenetration = penetrationDepth;
				maxNormal      = collisionNormal;
			}

			// Apply collision response - bounce and friction
			ptcl->mWorldVelocity
			    = ptcl->mPreCollisionVelocity - (ptcl->mPreCollisionVelocity.DP(collisionNormal) * (0.4f + 1.0f)) * collisionNormal;

			Vector3f rotatedPos(ptcl->mLocalPosition);
			rotatedPos.multMatrix(rotMtx);

			// Calculate and apply impulse forces
			f32 impulse = calcImpulse(rotatedPos, mMass, collisionNormal, mWorldInvInertiaTensor, ptcl->mPreCollisionVelocity,
			                          ptcl->mWorldVelocity);
			if (impulse <= 0.0f) {
				impulse = 0.001f;
			}

			if (impulse > 0.0f) {
				// Apply linear impulse
				Vector3f impVec = impulse * collisionNormal;
				mVelocity       = mVelocity + impVec * (1.0f / mMass);

				// Apply angular impulse
				Vector3f rotatedPos2(ptcl->mLocalPosition);
				rotatedPos2.multMatrix(rotMtx);
				rotatedPos2.CP(impVec);
				mAngularImpulseAccum = mAngularImpulseAccum + rotatedPos2;

				// Apply friction if enabled
				if (mDynFlag & 0x1) {
					Vector3f tangentialVelocity = ptcl->mWorldVelocity - ptcl->mWorldVelocity.DP(collisionNormal) * collisionNormal;
					tangentialVelocity          = tangentialVelocity * -0.3f;
					mVelocity                   = mVelocity + tangentialVelocity * (1.0f / mMass);
				}
			}

			collisionCount++;
		}
	}

	// Apply position correction to resolve penetration
	if (maxPenetration > 0.0f) {
		f32 correctionStrength = maxPenetration * timeStep * 10.0f;
		if (correctionStrength > 30.0f) {
			correctionStrength = 30.0f;
		}

		mSRT.t = mSRT.t + maxNormal * correctionStrength;
	}

	// Update angular momentum
	mAngularMomentum = mAngularMomentum + mAngularImpulseAccum;

	// Clamp angular momentum to prevent excessive rotation
	if (mAngularMomentum.length() > 10000.0f) {
		mAngularMomentum.normalise();
		mAngularMomentum.multiply(10000.0f);
	}

	// Calculate new angular velocity
	mAngularVelocity = mAngularMomentum;
	mAngularVelocity.multMatrix(mWorldInvInertiaTensor);
	mPrevAngularVelocity = mAngularVelocity;

	// Apply angular damping - stronger when in air
	f32 dampingFactor = timeStep;
	if (groundContactCount <= 0) {
		dampingFactor *= 0.1f;
	}

	mAngularMomentum = mAngularMomentum - dampingFactor * mAngularMomentum;

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000254
 */
void DynCreature::applyTorque(int, f32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void DynCreature::createInvInertiaTensor()
{
	mInertiaTensor.makeIdentity();
	f32 diag = 0.0f;
	f32 xx   = 0.0f;
	f32 xy   = 0.0f;
	f32 xz   = 0.0f;
	f32 yy   = 0.0f;
	f32 yz   = 0.0f;
	f32 zz   = 0.0f;

	for (DynParticle* ptcl = mParticleList; ptcl; ptcl = ptcl->mNextParticle) {
		diag += (SQUARE(ptcl->mLocalPosition.x) + SQUARE(ptcl->mLocalPosition.y) + SQUARE(ptcl->mLocalPosition.z)) * ptcl->mMass;
		xx += ptcl->mLocalPosition.x * ptcl->mLocalPosition.x * ptcl->mMass;
		xy += ptcl->mLocalPosition.x * ptcl->mLocalPosition.y * ptcl->mMass;
		xz += ptcl->mLocalPosition.x * ptcl->mLocalPosition.z * ptcl->mMass;
		yy += ptcl->mLocalPosition.y * ptcl->mLocalPosition.y * ptcl->mMass;
		yz += ptcl->mLocalPosition.y * ptcl->mLocalPosition.z * ptcl->mMass;
		zz += ptcl->mLocalPosition.z * ptcl->mLocalPosition.z * ptcl->mMass;

		Matrix4f inertTensor;
		inertTensor.mMtx[0][0] = 0.0f;
		inertTensor.mMtx[0][1] = ptcl->mLocalPosition.z;
		inertTensor.mMtx[0][2] = ptcl->mLocalPosition.y;

		inertTensor.mMtx[1][0] = -ptcl->mLocalPosition.z;
		inertTensor.mMtx[1][1] = 0.0f;
		inertTensor.mMtx[1][2] = ptcl->mLocalPosition.x;

		inertTensor.mMtx[2][0] = -ptcl->mLocalPosition.y;
		inertTensor.mMtx[2][1] = -ptcl->mLocalPosition.x;
		inertTensor.mMtx[2][2] = 0.0f;

		inertTensor.inverse(&ptcl->mInvCrossMatrix);
	}

	mInertiaTensor.mMtx[0][0] = diag - xx;
	mInertiaTensor.mMtx[0][1] = -xy;
	mInertiaTensor.mMtx[0][2] = -xz;

	mInertiaTensor.mMtx[1][0] = -xy;
	mInertiaTensor.mMtx[1][1] = diag - yy;
	mInertiaTensor.mMtx[1][2] = -yz;

	mInertiaTensor.mMtx[2][0] = -xz;
	mInertiaTensor.mMtx[2][1] = -yz;
	mInertiaTensor.mMtx[2][2] = diag - zz;

	mInertiaTensor.inverse(&mInvInertiaTensor);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void DynCreature::calcModelMatrix(Matrix4f& modelMtx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx2.makeIdentity();
	mtx2.setTranslation(mCenterOfMass);
	mtx1.makeVQS(mSRT.t, mRotationQuat, mSRT.s);
	mtx1.multiplyTo(mtx2, modelMtx);
}

/**
 * @TODO: Documentation
 */
void DynCreature::refresh(Graphics& gfx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	Vector3f startScale(mSRT.s);

	mSRT.s.set(1.0f, 1.0f, 1.0f);
	calcModelMatrix(mtx1);
	mSRT.s = startScale;

	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.useMatrix(mtx2, 0);

	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(0, 255, 0, 255), true);

	for (DynParticle* ptcl = mParticleList; ptcl; ptcl = ptcl->mNextParticle) {
		bool isLight = gfx.setLighting(false, nullptr);
		gfx.setColour(Colour(0, 255, 100, 255), true);
		drawCube(gfx, ptcl->mWorldPosition, 2.0f);
		gfx.setLighting(isLight, nullptr);
	}

	gfx.setColour(Colour(255, 100, 0, 255), true);
	gfx.drawSphere(Vector3f(0.0f, 0.0f, 0.0f), 4.0f, mtx2);

	gfx.useMatrix(Matrix4f::ident, 0);
}

/**
 * @TODO: Documentation
 */
void DynCreature::doKill()
{
#if defined(VERSION_PIKIDEMO)
#else
	releaseAllParticles();
#endif
}

/*
 * --INFO--
 * Address:	........
 * Size:	000928
 */
void DynCreature::simulate2(f32)
{
	// UNUSED FUNCTION
}
