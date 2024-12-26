#include "Slime.h"
#include "Graphics.h"
#include "Shape.h"
#include "Interactions.h"
#include "PlayerState.h"
#include "system.h"
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
DEFINE_PRINT("Slime");

/*
 * --INFO--
 * Address:	80163714
 * Size:	000578
 */
SlimeProp::SlimeProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/*
 * --INFO--
 * Address:	80163C8C
 * Size:	0001D4
 */
Slime::Slime(CreatureProp* props, BossShapeObject* shape)
    : Boss(props)
{
	mShapeObject    = shape;
	mCollInfo       = new CollInfo(12);
	mSlimeCreatures = new SlimeCreature*[bossMgr->_28];

	for (int i = 0; i < bossMgr->_28; i++) {
		mSlimeCreatures[i]           = new SlimeCreature(props);
		mSlimeCreatures[i]->mObjType = mObjType;
	}

	mCentreUpdater         = new BoundSphereUpdater(this);
	mCollideSphereUpdaters = new CollideSphereUpdater[bossMgr->_28];
	mTubeSphereUpdaters    = new TubeSphereUpdater[bossMgr->_28];

	mSlimeAi   = new SlimeAi(this);
	mSlimeBody = new SlimeBody(this);
}

/*
 * --INFO--
 * Address:	80163F08
 * Size:	00000C
 */
f32 Slime::getCentreSize() { return mCentreUpdater->mSize; }

/*
 * --INFO--
 * Address:	80163F14
 * Size:	000008
 */
f32 Slime::getiMass() { return 0.0001f; }

/*
 * --INFO--
 * Address:	80163F1C
 * Size:	00027C
 */
void Slime::init(Vector3f& pos)
{
	u32 badCompiler[4];

	mCollisionRadius = 20.0f;
	_2BB             = 0;
	_3C4             = 1;
	_3C5             = 0;
	_3C8             = 0;
	_3CC             = bossMgr->_28 - 1;
	_3D0             = 0.0f;
	_3D4             = 0.0f;
	_3D8             = static_cast<SlimeProp*>(mProps)->mSlimeProps._354(); // body thickness?
	_3DC             = pos;
	_3E8             = pos;

	for (int i = 0; i < bossMgr->_28; i++) {
		mSlimeCreatures[i]->init(pos, this);
	}

	mSlimeAi->init(this);
	mSlimeBody->init(this);
	mCollInfo->setUpdater('cent', mCentreUpdater);

	mCollideSphereUpdaters[0].init(this, mSlimeCreatures[0]);
	mCollideSphereUpdaters[1].init(this, mSlimeCreatures[1]);
	mCollideSphereUpdaters[2].init(this, mSlimeCreatures[2]);
	mCollideSphereUpdaters[3].init(this, mSlimeCreatures[3]);

	mCollInfo->setUpdater('stk1', &mCollideSphereUpdaters[0]);
	mCollInfo->setUpdater('stk2', &mCollideSphereUpdaters[1]);
	mCollInfo->setUpdater('stk3', &mCollideSphereUpdaters[2]);
	mCollInfo->setUpdater('stk4', &mCollideSphereUpdaters[3]);

	mTubeSphereUpdaters[0].mSphere = mCollInfo->getSphere('stk1');
	mTubeSphereUpdaters[1].mSphere = mCollInfo->getSphere('stk2');
	mTubeSphereUpdaters[2].mSphere = mCollInfo->getSphere('stk3');
	mTubeSphereUpdaters[3].mSphere = mCollInfo->getSphere('stk4');

	mCollInfo->setUpdater('tub1', &mTubeSphereUpdaters[0]);
	mCollInfo->setUpdater('tub2', &mTubeSphereUpdaters[1]);
	mCollInfo->setUpdater('tub3', &mTubeSphereUpdaters[2]);
	mCollInfo->setUpdater('tub4', &mTubeSphereUpdaters[3]);

	mCollInfo->makeTubesChild('tub1', 3);
}

/*
 * --INFO--
 * Address:	80164198
 * Size:	000034
 */
void Slime::doKill()
{
	_2B8 = 0;
	_2B9 = 0;
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	801641CC
 * Size:	000004
 */
void Slime::exitCourse() { }

/*
 * --INFO--
 * Address:	801641D0
 * Size:	0000A4
 */
void Slime::update()
{
	doAI();
	for (int i = 0; i < bossMgr->_28; i++) {
		if (mSlimeCreatures[i]) {
			mSlimeCreatures[i]->update();
		}
	}

	moveVelocity();
	moveNew(gsys->getFrameTime());
}

/*
 * --INFO--
 * Address:	80164274
 * Size:	0000A8
 */
void Slime::refresh(Graphics& gfx)
{
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	Matrix4f onCamMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mSlimeBody->refresh(mShapeObject, gfx);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	8016431C
 * Size:	0000A0
 */
void Slime::drawShape(Graphics& gfx)
{
	doAnimation();
	gfx.useMatrix(Matrix4f::ident, 0);
	if (_3D4 > 0.0f) {
		mShapeObject->mShape->_13C |= 3;
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}

/*
 * --INFO--
 * Address:	801643BC
 * Size:	000024
 */
void Slime::doAI() { mSlimeAi->update(); }

/*
 * --INFO--
 * Address:	801643E0
 * Size:	000024
 */
void Slime::doAnimation() { mSlimeBody->update(); }

/*
 * --INFO--
 * Address:	80164404
 * Size:	000168
 */
void Slime::collisionCallback(CollEvent& event)
{
	if (event.mCollider->mObjType == OBJTYPE_Piki || event.mCollider->mObjType == OBJTYPE_Navi) {
		if (event.mCollider->isAlive() && event.mCollider->isVisible() && !event.mCollider->isBuried()) {
			if (event.mCollider->mObjType == OBJTYPE_Piki) {
				InteractBubble bubble(this, 200.0f);
				event.mCollider->stimulate(bubble);
			} else if (event.mCollider->mObjType == OBJTYPE_Navi) {
				InteractFlick flick(this, static_cast<SlimeProp*>(mProps)->mBossProps.mFlickKnockback(),
				                    static_cast<SlimeProp*>(mProps)->mBossProps.mFlickDamage(), -1000.0f);
				event.mCollider->stimulate(flick);
			}

			if (insideAndInSearch()) {
				playerState->mResultFlags.setOn(RESFLAG_Unk50);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8016456C
 * Size:	000020
 */
Vector3f Slime::CollideSphereUpdater::getPos() { return mCreature->mPosition; }

/*
 * --INFO--
 * Address:	8016458C
 * Size:	000440
 */
f32 Slime::CollideSphereUpdater::getSize()
{
	// stack shenanigans

	Vector3f adjustVecs[4];

	adjustVecs[0].set(1.0f, 0.0f, 0.0f);
	adjustVecs[1].set(0.0f, 0.0f, 1.0f);
	adjustVecs[2] = Vector3f(-adjustVecs[0].x, -adjustVecs[0].y, -adjustVecs[0].z);
	adjustVecs[3] = Vector3f(-adjustVecs[1].x, -adjustVecs[1].y, -adjustVecs[1].z);

	f32 minDist = 12800.0f;
	for (int i = 0; i < 4; i++) {

		// weightPos is kind of the centre of mass?
		Vector3f weightPos
		    = mCreature->mPosition + adjustVecs[i] * static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._364(); // max radius compensation

		Vector3f farPos  = weightPos;
		Vector3f nearPos = mCreature->mPosition;

		// iterate like 10 times to jiggle the weightPos closer to the middle of the 4 stick slimes
		for (int j = 0; j < static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps.mMaxSortCount(); j++) { // number of sorts?
			weightPos.add2(farPos, nearPos);
			weightPos.multiply(0.5f);

			f32 score = 0.0f;
			for (int k = 0; k < 4; k++) {
				Vector3f cPos = weightPos;
				cPos.x -= mSlime->mSlimeCreatures[k]->mPosition.x;
				cPos.y -= mSlime->mSlimeCreatures[k]->mPosition.y;
				cPos.z -= mSlime->mSlimeCreatures[k]->mPosition.z;
				score += mSlime->_3D4 / cPos.length();
			}

			// closer to other stick slimes = higher score
			if (score > static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._384()) { // vertex position score?
				nearPos.set(weightPos);
			} else {
				farPos.set(weightPos);
			}
		}

		// keep track of smallest distance from this piece of slime
		f32 dist = weightPos.distance(mCreature->mPosition);
		if (minDist > dist) {
			minDist = dist;
		}
	}

	return minDist - 15.0f;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stfd      f29, 0x170(r1)
	  stfd      f28, 0x168(r1)
	  stfd      f27, 0x160(r1)
	  stfd      f26, 0x158(r1)
	  stfd      f25, 0x150(r1)
	  stmw      r26, 0x138(r1)
	  mr        r26, r3
	  addi      r28, r1, 0x104
	  addi      r31, r1, 0x68
	  addi      r30, r1, 0x64
	  addi      r29, r1, 0x60
	  li        r27, 0
	  lfs       f27, -0x54D8(r2)
	  stfs      f27, 0x10C(r1)
	  stfs      f27, 0x108(r1)
	  stfs      f27, 0x104(r1)
	  lfs       f1, 0x10(r13)
	  stfs      f27, 0x118(r1)
	  lfs       f0, 0x14(r13)
	  stfs      f27, 0x114(r1)
	  stfs      f27, 0x110(r1)
	  stfs      f27, 0x124(r1)
	  stfs      f27, 0x120(r1)
	  stfs      f27, 0x11C(r1)
	  stfs      f27, 0x130(r1)
	  stfs      f27, 0x12C(r1)
	  stfs      f27, 0x128(r1)
	  stfs      f1, 0x104(r1)
	  stfs      f0, 0x108(r1)
	  lfs       f0, 0x18(r13)
	  stfs      f0, 0x10C(r1)
	  lfs       f0, 0x1C(r13)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x20(r13)
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x24(r13)
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x104(r1)
	  lfs       f31, -0x54C8(r2)
	  fneg      f0, f0
	  lfd       f29, -0x54C0(r2)
	  lfd       f30, -0x54B8(r2)
	  lfs       f28, -0x54DC(r2)
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0xD0(r1)
	  lfs       f0, 0x108(r1)
	  fneg      f0, f0
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0x10C(r1)
	  fneg      f0, f0
	  stfs      f0, 0xD8(r1)
	  lwz       r0, 0xD0(r1)
	  lwz       r3, 0xD4(r1)
	  stw       r0, 0x11C(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r3, 0x120(r1)
	  stw       r0, 0x124(r1)
	  lfs       f0, 0x110(r1)
	  fneg      f0, f0
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x94(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0x114(r1)
	  fneg      f0, f0
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0x118(r1)
	  fneg      f0, f0
	  stfs      f0, 0xCC(r1)
	  lwz       r0, 0xC4(r1)
	  lwz       r3, 0xC8(r1)
	  stw       r0, 0x128(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r3, 0x12C(r1)
	  stw       r0, 0x130(r1)

	.loc_0x140:
	  lwz       r3, 0x1C(r26)
	  mr        r4, r29
	  lfs       f1, 0x8(r28)
	  mr        r5, r30
	  lwz       r3, 0x224(r3)
	  addi      r6, r31, 0
	  addi      r7, r3, 0x370
	  lfs       f0, 0x370(r3)
	  addi      r3, r1, 0xAC
	  fmuls     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x4(r28)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  bl        -0x12D5FC
	  lwz       r3, 0x20(r26)
	  li        r5, 0
	  lfs       f1, 0xB4(r1)
	  addi      r3, r3, 0x94
	  lfs       f0, 0xB0(r1)
	  lfs       f8, 0x8(r3)
	  lfs       f7, 0x4(r3)
	  fadds     f2, f8, f1
	  lfs       f6, 0x0(r3)
	  fadds     f1, f7, f0
	  lfs       f0, 0xAC(r1)
	  fadds     f0, f6, f0
	  fmr       f4, f1
	  fmr       f5, f2
	  fmr       f3, f0
	  b         .loc_0x378

	.loc_0x1D0:
	  fadds     f0, f3, f6
	  li        r0, 0x2
	  fadds     f1, f4, f7
	  mtctr     r0
	  fadds     f2, f5, f8
	  fmuls     f0, f0, f28
	  lfs       f9, -0x54D8(r2)
	  fmuls     f1, f1, f28
	  li        r6, 0
	  fmuls     f2, f2, f28
	  li        r4, 0

	.loc_0x1FC:
	  lwz       r3, 0x1C(r26)
	  lwz       r3, 0x3F4(r3)
	  lwzx      r3, r3, r4
	  lfs       f13, 0x94(r3)
	  lfs       f12, 0x98(r3)
	  fsubs     f13, f0, f13
	  lfs       f11, 0x9C(r3)
	  fsubs     f26, f1, f12
	  fsubs     f25, f2, f11
	  fmuls     f12, f13, f13
	  fmuls     f11, f26, f26
	  fmuls     f13, f25, f25
	  fadds     f10, f12, f11
	  fadds     f12, f13, f10
	  fcmpo     cr0, f12, f27
	  ble-      .loc_0x28C
	  fsqrte    f11, f12
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f10, f11, f10
	  fmul      f10, f12, f10
	  frsp      f10, f10
	  stfs      f10, 0x8C(r1)
	  lfs       f12, 0x8C(r1)

	.loc_0x28C:
	  lwz       r3, 0x1C(r26)
	  addi      r4, r4, 0x4
	  lfs       f10, 0x3D4(r3)
	  lwz       r3, 0x3F4(r3)
	  fdivs     f10, f10, f12
	  lwzx      r3, r3, r4
	  lfs       f13, 0x94(r3)
	  lfs       f12, 0x98(r3)
	  lfs       f11, 0x9C(r3)
	  fsubs     f13, f0, f13
	  fsubs     f26, f1, f12
	  fsubs     f25, f2, f11
	  fmuls     f12, f13, f13
	  fmuls     f11, f26, f26
	  fadds     f9, f9, f10
	  fmuls     f13, f25, f25
	  fadds     f10, f12, f11
	  fadds     f12, f13, f10
	  fcmpo     cr0, f12, f27
	  ble-      .loc_0x32C
	  fsqrte    f11, f12
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f10, f11, f10
	  fmul      f10, f12, f10
	  frsp      f10, f10
	  stfs      f10, 0x8C(r1)
	  lfs       f12, 0x8C(r1)

	.loc_0x32C:
	  lwz       r3, 0x1C(r26)
	  addi      r4, r4, 0x4
	  addi      r6, r6, 0x1
	  lfs       f10, 0x3D4(r3)
	  fdivs     f10, f10, f12
	  fadds     f9, f9, f10
	  bdnz+     .loc_0x1FC
	  lwz       r3, 0x224(r3)
	  lfs       f10, 0x390(r3)
	  fcmpo     cr0, f9, f10
	  ble-      .loc_0x368
	  fmr       f6, f0
	  fmr       f7, f1
	  fmr       f8, f2
	  b         .loc_0x374

	.loc_0x368:
	  fmr       f3, f0
	  fmr       f4, f1
	  fmr       f5, f2

	.loc_0x374:
	  addi      r5, r5, 0x1

	.loc_0x378:
	  lwz       r3, 0x1C(r26)
	  lwz       r3, 0x224(r3)
	  lwz       r0, 0x3C0(r3)
	  cmpw      r5, r0
	  blt+      .loc_0x1D0
	  lwz       r3, 0x20(r26)
	  stfs      f27, 0x80(r1)
	  stfs      f27, 0x7C(r1)
	  stfs      f27, 0x78(r1)
	  lfsu      f3, 0x94(r3)
	  fsubs     f0, f3, f0
	  lfs       f4, 0x8(r3)
	  lfs       f3, 0x4(r3)
	  fsubs     f2, f4, f2
	  stfs      f0, 0x74(r1)
	  fsubs     f1, f3, f1
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f2, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x80(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x156D34
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x3F8
	  fmr       f31, f1

	.loc_0x3F8:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r28, r28, 0xC
	  blt+      .loc_0x140
	  lmw       r26, 0x138(r1)
	  lfs       f0, -0x54CC(r2)
	  lwz       r0, 0x18C(r1)
	  fsubs     f1, f31, f0
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lfd       f29, 0x170(r1)
	  lfd       f28, 0x168(r1)
	  lfd       f27, 0x160(r1)
	  lfd       f26, 0x158(r1)
	  lfd       f25, 0x150(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801649CC
 * Size:	000020
 */
Vector3f Slime::TubeSphereUpdater::getPos() { return mSphere->mCentre; }

/*
 * --INFO--
 * Address:	801649EC
 * Size:	00000C
 */
f32 Slime::TubeSphereUpdater::getSize() { return mSphere->mRadius; }

/*
 * --INFO--
 * Address:	801649F8
 * Size:	000020
 */
Vector3f Slime::BoundSphereUpdater::getPos() { return mSlime->mPosition; }

/*
 * --INFO--
 * Address:	80164A18
 * Size:	000110
 */
f32 Slime::BoundSphereUpdater::getSize()
{
	mSize = 0.0f;
	for (int i = 0; i < bossMgr->_28; i++) {
		if (mSlime->mSlimeCreatures[i]) {
			f32 dist = mSlime->mPosition.distance(mSlime->mSlimeCreatures[i]->mPosition);
			if (dist > mSize) {
				mSize = dist;
			}
		}
	}

	mSize += 75.0f;
	return mSize;
}

/*
 * --INFO--
 * Address:	80164B28
 * Size:	000050
 */
void SlimeProp::read(RandomAccessStream& input)
{
	mCreatureProps.read(input);
	mBossProps.read(input);
	mSlimeProps.read(input);
}
