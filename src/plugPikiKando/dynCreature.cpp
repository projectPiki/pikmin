#include "types.h"
#include "DynCreature.h"
#include "DynParticle.h"
#include "MapMgr.h"
#include "CreatureProp.h"
#include "Graphics.h"
#include "Matrix4f.h"
#include "UtilityKando.h"
#include "KMath.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

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
static void printMatrix(char*, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80092808
 * Size:	0000D8
 */
DynParticle::DynParticle()
{
	initCore("particle");
	mIsFree = 0;
	_14     = 100.0f;
	_24.set(0.0f, 0.0f, 0.0f);
	mNextParticle = nullptr;
	_90           = 0.01f;

	// this is so this doesn't inline in DynParticleHeap
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	800928E0
 * Size:	000010
 */
f32 DynParticle::getSize()
{
	return _90 * 3.0f;
}

/*
 * --INFO--
 * Address:	800928F0
 * Size:	000004
 */
void DynParticle::refresh(Graphics&)
{
}

/*
 * --INFO--
 * Address:	800928F4
 * Size:	000004
 */
void DynParticle::doKill()
{
}

/*
 * --INFO--
 * Address:	800928F8
 * Size:	0001F4
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

/*
 * --INFO--
 * Address:	80092AEC
 * Size:	0000F4
 */
DynCreature::DynCreature()
    : Creature(nullptr)
{
	mParticleList  = nullptr;
	mParticleCount = 0;
	_2F4           = 0.0f;
	mPickOffset    = 0.0f;
	_2DC.set(0.0f, 0.0f, 0.0f);
	_2B8.set(0.0f, 0.0f, 0.0f);
	_2C4.set(0.0f, 0.0f, 0.0f);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	enableFriction();
}

/*
 * --INFO--
 * Address:	80092BE0
 * Size:	00001C
 */
void DynCreature::enablePickOffset(f32 offset)
{
	enableGroundOffset(offset);
	mPickOffset = -offset;
}

/*
 * --INFO--
 * Address:	80092BFC
 * Size:	000018
 */
void DynCreature::disablePickOffset()
{
	disableGroundOffset();
	mPickOffset = 0.0f;
}

/*
 * --INFO--
 * Address:	80092C14
 * Size:	000100
 */
void DynCreature::addParticle(f32 p1, Vector3f& p2)
{
	DynParticle* ptcl = particleHeap->getFreeOne();
	if (!ptcl) {
		// PRINT("PARTICLE ADD FAILED ! (%s)\n", ObjType::getName(mObjType));
		ERROR("ZANNEN !\n");
		return;
	}

	ptcl->_14 = p1;
	ptcl->_24 = p2;
	ptcl->_18 = p2;
	if (!mParticleList) {
		mParticleList = ptcl;
	} else {
		DynParticle* nextPtcl = mParticleList;
		while (nextPtcl->mNextParticle) {
			nextPtcl = nextPtcl->mNextParticle;
		}

		nextPtcl->mNextParticle = ptcl;
	}

	_2F4 += p1;
	mParticleCount++;
}

/*
 * --INFO--
 * Address:	80092D14
 * Size:	000068
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

/*
 * --INFO--
 * Address:	80092D7C
 * Size:	00018C
 */
void DynCreature::initialiseSystem()
{
	setCreatureFlag(CF_Unk1 | CF_Unk10);
	_2E8.set(0.0f, 0.0f, 0.0f);
	_2F4 = 0.0f;

	for (DynParticle* ptcl = mParticleList; ptcl; ptcl = ptcl->mNextParticle) {
		_2E8 = _2E8 + ptcl->_14 * ptcl->_18;
		_2F4 += ptcl->_14;
	}

	_2E8 = _2E8 * (1.0f / _2F4);

	for (DynParticle* ptcl = mParticleList; ptcl; ptcl = ptcl->mNextParticle) {
		ptcl->_24 = ptcl->_18 - _2E8;
	}

	createInvInertiaTensor();
}

/*
 * --INFO--
 * Address:	80092F08
 * Size:	00003C
 */
void DynCreature::update()
{
	simulate(gsys->getFrameTime());
	Creature::update();
}

/*
 * --INFO--
 * Address:	80092F44
 * Size:	000B64
 */
void DynCreature::simulate(f32 timeStep)
{
	_2DC.set(0.0f, 0.0f, 0.0f);
	mGroundFlag = 0;

	Matrix4f rotMtx;
	Matrix4f tmpMtx;
	Matrix4f rotTransMtx;

	rotMtx.makeVQS(Vector3f(0.0f, 0.0f, 0.0f), _E0, Vector3f(1.0f, 1.0f, 1.0f));
	rotMtx.transposeTo(rotTransMtx);

	printMatrix("rotate", rotMtx);
	printMatrix("rotate^T", rotTransMtx);

	rotMtx.multiplyTo(mInvInertiaTensor, tmpMtx);
	tmpMtx.multiplyTo(rotTransMtx, _338);
	rotMtx.multiplyTo(mInertiaTensor, tmpMtx);
	tmpMtx.multiplyTo(rotTransMtx, _2F8);

	bool isSlowFall = false;
	if (mVelocity.y >= -60.0f && mVelocity.y < 0.0f) {
		isSlowFall = true;
	}

	f32 maxDiff = 0.0f;
	u32 badCompiler3;
	Vector3f maxNormal(0.0f, 1.0f, 0.0f);

	DynParticle* ptcl = mParticleList;
	int count1        = 0;
	int count2        = 0;
	int ptclNum       = 0;
	for (ptcl; ptcl; ptcl = ptcl->mNextParticle, ptclNum++) {
		Vector3f ptclPos(ptcl->_24);
		ptclPos.y += mPickOffset;
		ptcl->_94 = ptclPos;
		ptcl->_94.multMatrix(rotMtx);
		ptcl->_94.add(_2E8);
		ptcl->_94.add(mPosition);

		ptcl->_A0 = _2C4;

		Vector3f ptclPos2(ptcl->_24);
		ptclPos2.multMatrix(rotMtx);
		ptcl->_A0.CP(ptclPos2);
		if (!isSlowFall) {
			ptcl->_A0 = ptcl->_A0 + mVelocity;
		} else {
			ptcl->_A0.x += mVelocity.x;
			ptcl->_A0.z += mVelocity.z;
		}

		ptcl->_3C = ptcl->_A0;

		f32 minY = mapMgr->getMinY(ptcl->_94.x, ptcl->_94.z, true);
		Vector3f vec(0.0f, 0.0f, 0.0f);

		f32 heightDiff = minY - (ptcl->_94.y - ptcl->_90);
		if (ptcl->_94.y - minY < ptcl->_90) {
			mGroundFlag |= (1 << ptclNum);
			count2++;

			Vector3f normal;
			u32 badCompiler2;
			CollTriInfo* floorTri = mapMgr->getCurrTri(ptcl->_94.x, ptcl->_94.z, true);
			if (floorTri) {
				normal = floorTri->_18;
				normal.normalise();
			} else {
				normal.set(0.0f, 1.0f, 0.0f);
			}

			if (0.5f * getCylinderHeight() + mPosition.y < minY) {
				normal = mPosition - ptcl->_94;
				normal.normalise();
			}

			if (maxDiff < heightDiff) {
				maxDiff   = heightDiff;
				maxNormal = normal;
			}

			ptcl->_A0 = ptcl->_3C - (ptcl->_3C.DP(normal) * (0.4f + 1.0f)) * normal;

			Vector3f ptclPos3(ptcl->_24);
			ptclPos3.multMatrix(rotMtx);

			f32 impulse = calcImpulse(ptclPos3, _2F4, normal, _338, ptcl->_3C, ptcl->_A0);
			if (impulse <= 0.0f) {
				impulse = 0.001f;
			}

			if (impulse > 0.0f) {
				Vector3f impVec = impulse * normal;
				mVelocity       = mVelocity + impVec * (1.0f / _2F4);

				Vector3f ptclPos4(ptcl->_24);
				ptclPos4.multMatrix(rotMtx);

				ptclPos4.CP(impVec);
				_2DC = _2DC + ptclPos4;

				if (mDynFlag & 0x1) {
					Vector3f diff = ptcl->_A0 - ptcl->_A0.DP(normal) * normal;
					diff          = diff * -0.3f;
					mVelocity     = mVelocity + diff * (1.0f / _2F4);
				}
			}

			count1++;
		}
	}

	if (maxDiff > 0.0f) {
		f32 offsetFactor = maxDiff * timeStep * 10.0f;
		if (offsetFactor > 30.0f) {
			offsetFactor = 30.0f;
		}

		mPosition = mPosition + maxNormal * offsetFactor;
	}

	_2B8 = _2B8 + _2DC;

	if (_2B8.length() > 10000.0f) {
		_2B8.normalise();
		_2B8.multiply(10000.0f);
	}

	_2C4 = _2B8;
	_2C4.multMatrix(_338);
	_D4 = _2C4;

	f32 factor = timeStep;
	if (count2 <= 0) {
		factor *= 0.1f;
	}

	_2B8 = _2B8 - factor * _2B8;

	u32 badCompiler;
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

/*
 * --INFO--
 * Address:	80093AA8
 * Size:	0001B0
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
		diag += (SQUARE(ptcl->_24.x) + SQUARE(ptcl->_24.y) + SQUARE(ptcl->_24.z)) * ptcl->_14;
		xx += ptcl->_24.x * ptcl->_24.x * ptcl->_14;
		xy += ptcl->_24.x * ptcl->_24.y * ptcl->_14;
		xz += ptcl->_24.x * ptcl->_24.z * ptcl->_14;
		yy += ptcl->_24.y * ptcl->_24.y * ptcl->_14;
		yz += ptcl->_24.y * ptcl->_24.z * ptcl->_14;
		zz += ptcl->_24.z * ptcl->_24.z * ptcl->_14;

		Matrix4f inertTensor;
		inertTensor.mMtx[0][0] = 0.0f;
		inertTensor.mMtx[0][1] = ptcl->_24.z;
		inertTensor.mMtx[0][2] = ptcl->_24.y;

		inertTensor.mMtx[1][0] = -ptcl->_24.z;
		inertTensor.mMtx[1][1] = 0.0f;
		inertTensor.mMtx[1][2] = ptcl->_24.x;

		inertTensor.mMtx[2][0] = -ptcl->_24.y;
		inertTensor.mMtx[2][1] = -ptcl->_24.x;
		inertTensor.mMtx[2][2] = 0.0f;

		inertTensor.inverse(&ptcl->_50);
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
	mtx2.setTranslation(_2E8);
	mtx1.makeVQS(mPosition, _E0, mScale);
	mtx1.multiplyTo(mtx2, modelMtx);
}

/*
 * --INFO--
 * Address:	80093C58
 * Size:	0002B4
 */
void DynCreature::refresh(Graphics& gfx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	Vector3f startScale(mScale);

	mScale.set(1.0f, 1.0f, 1.0f);
	calcModelMatrix(mtx1);
	mScale = startScale;

	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.useMatrix(mtx2, 0);

	gfx.useTexture(nullptr, 0);
	gfx.setColour(Colour(0, 255, 0, 255), true);

	for (DynParticle* ptcl = mParticleList; ptcl; ptcl = ptcl->mNextParticle) {
		bool isLight = gfx.setLighting(false, nullptr);
		gfx.setColour(Colour(0, 255, 100, 255), true);
		drawCube(gfx, ptcl->_94, 2.0f);
		gfx.setLighting(isLight, nullptr);
	}

	gfx.setColour(Colour(255, 100, 0, 255), true);
	gfx.drawSphere(Vector3f(0.0f, 0.0f, 0.0f), 4.0f, mtx2);

	gfx.useMatrix(Matrix4f::ident, 0);
}

/*
 * --INFO--
 * Address:	80093F0C
 * Size:	000068
 */
void DynCreature::doKill()
{
	releaseAllParticles();
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
