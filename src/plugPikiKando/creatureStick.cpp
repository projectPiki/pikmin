#include "Creature.h"
#include "Iterator.h"
#include "Stickers.h"
#include "Interactions.h"
#include "Collision.h"
#include "RopeCreature.h"
#include "Condition.h"
#include "Pellet.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("CreatureStick");

char* _standType[] = { "GROUND", "TEKIPLAT", "PLAT", "AIR" };

/*
 * --INFO--
 * Address:	8008F9C4
 * Size:	000160
 */
void Creature::interactStickers(Creature* stuckTo, Interaction& interaction, Condition* condition)
{
	Stickers stuckList(stuckTo);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (!condition || condition->satisfy(stuck)) {
			if (stuck->stimulate(interaction)) {
				iter.dec();
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8008FB24
 * Size:	000174
 */
void Creature::killStickers(Creature* stuckTo, Condition* cond, int p3)
{
	InteractKill kill(stuckTo, p3);
	interactStickers(stuckTo, kill, cond);
}

/*
 * --INFO--
 * Address:	8008FED8
 * Size:	000068
 */
void Creature::startClimb()
{
	if (mStickTarget && mStickPart && mStickPart->isClimbable()) {
		setCreatureFlag(CF_IsClimbing);
	} else {
		PRINT("CANNOT CLIMB !\n");
		resetCreatureFlag(CF_IsClimbing);
	}
}

/*
 * --INFO--
 * Address:	8008FF40
 * Size:	000010
 */
void Creature::endClimb()
{
	resetCreatureFlag(CF_IsClimbing);
}

/*
 * --INFO--
 * Address:	8008FF50
 * Size:	000048
 */
bool Creature::isStickToPlatform()
{
	if (mStickTarget) {
		CollPart* part = mStickPart;
		if ((part && part->isPlatformType()) || (!part && !isCreatureFlag(CF_StuckToObject))) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
bool Creature::isStickToSphere()
{
	return !isStickToPlatform();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E8
 */
void Creature::adjustStickObject(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008FF98
 * Size:	000084
 */
void Creature::startStickMouth(Creature* mouthOwner, CollPart* mouthPart)
{
	resetCreatureFlag(CF_StuckToMouth);
	if (mStickTarget) {
		PRINT("startStickMouth:already stuck to %s : endStick\n", mStickPart->mCollInfo->mId.mStringID);
		endStick();
	}

	if (startStick(mouthOwner, mouthPart)) {
		if (mObjType == OBJTYPE_Rope) {
			PRINT("stick to mouth!!\n");
		}
		setCreatureFlag(CF_StuckToMouth);
	} else {
		PRINT("stick mouth failed !!\n");
		ERROR("karl gotti!\n");
	}
}

/*
 * --INFO--
 * Address:	8009001C
 * Size:	000040
 */
void Creature::endStickMouth()
{
	endStickObject();
	endStick();
	resetCreatureFlag(CF_StuckToMouth);
}

/*
 * --INFO--
 * Address:	8009005C
 * Size:	000310
 */
void Creature::startStickObjectSphere(Creature* obj, CollPart* stickPart, f32 stickDist)
{
	Matrix4f objMatrix;
	Matrix4f invObjMatrix;
	Vector3f vec; // unused lol

	if (stickPart) {
		objMatrix = mStickPart->getMatrix(); // should this be uh. stickPart->getMatrix()??
	} else {
		objMatrix.makeSRT(obj->mScale, obj->mRotation, obj->mPosition);
	}

	objMatrix.inverse(&invObjMatrix);

	_194 = mPosition;

	if (stickPart) {
		_194 = _194 - stickPart->mCentre;
		_194.normalise();
		_194 = _194 * (stickPart->mRadius + stickDist) + stickPart->mCentre;
	} else {
		_194 = _194 - obj->mPosition;
		_194.normalise();
		_194 = _194 * (obj->getCentreSize() + stickDist) + obj->mPosition;
	}

	_194.multMatrix(invObjMatrix);
}

/*
 * --INFO--
 * Address:	8009036C
 * Size:	00034C
 */
void Creature::startStickObjectTube(Creature*, CollPart*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  addi      r4, r1, 0xB8
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stw       r31, 0xDC(r1)
	  mr        r31, r3
	  addi      r3, r5, 0
	  lfs       f0, -0x74C8(r2)
	  stfs      f0, 0xC0(r1)
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xC4(r1)
	  bl        -0x7824
	  addi      r3, r1, 0xB8
	  addi      r4, r31, 0x94
	  bl        -0x8C10
	  lfs       f0, -0x74C8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x68
	  fmr       f1, f0
	  b         .loc_0x78

	.loc_0x68:
	  lfs       f0, -0x74B0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x78
	  fmr       f1, f0

	.loc_0x78:
	  stfs      f1, 0x194(r31)
	  addi      r3, r1, 0xB8
	  addi      r4, r31, 0x94
	  lfs       f0, -0x74C8(r2)
	  addi      r5, r1, 0xAC
	  addi      r6, r1, 0xA0
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xAC(r1)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0xA0(r1)
	  bl        -0x8B84
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x9C(r31)
	  lfs       f1, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  lfs       f2, 0xA8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x82810
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x118
	  lfs       f0, 0xA0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0xA8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xA8(r1)

	.loc_0x118:
	  lfs       f1, 0x194(r31)
	  addi      r3, r1, 0x64
	  addi      r4, r1, 0xB8
	  bl        -0x89C8
	  lfs       f3, 0x68(r1)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0x64(r1)
	  lfs       f1, 0x94(r31)
	  fsubs     f30, f3, f0
	  lfs       f3, 0x6C(r1)
	  fsubs     f31, f2, f1
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f30, f30
	  fsubs     f29, f3, f1
	  fmuls     f1, f31, f31
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x8288C
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x17C
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x17C:
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0xA4(r1)
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0xA8(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f31, 0x7C(r1)
	  stfs      f30, 0x80(r1)
	  stfs      f29, 0x84(r1)
	  lfs       f1, 0x84(r1)
	  lfs       f6, 0x8C(r1)
	  lfs       f5, 0x88(r1)
	  lfs       f7, 0x80(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x90(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x7C(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x7C(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x80(r1)
	  stfs      f0, 0x84(r1)
	  lfs       f1, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  lfs       f2, 0x84(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x82934
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x23C
	  lfs       f0, 0x7C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x84(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x84(r1)

	.loc_0x23C:
	  lfs       f4, -0x5C38(r13)
	  lfs       f0, 0x7C(r1)
	  lfs       f1, 0x80(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x84(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x7C(r1)
	  stfs      f3, 0x80(r1)
	  stfs      f1, 0x84(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x84(r1)
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f6, 0x8C(r1)
	  lfs       f5, 0x88(r1)
	  lfs       f7, 0x74(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x90(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x70(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x70(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x74(r1)
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  lfs       f2, 0x78(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x82A10
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x318
	  lfs       f0, 0x70(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x78(r1)

	.loc_0x318:
	  addi      r3, r1, 0x7C
	  addi      r4, r1, 0x88
	  addi      r5, r1, 0x70
	  addi      r6, r31, 0x114
	  bl        0x8208C
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lwz       r31, 0xDC(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void Creature::startStickObjectPellet(Pellet*, int, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800906B8
 * Size:	0001C0
 */
void Creature::startStickObject(Creature*, CollPart*, int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  fmr       f31, f1
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  stw       r29, 0x34(r1)
	  addi      r29, r6, 0
	  stw       r28, 0x30(r1)
	  addi      r28, r5, 0
	  stw       r0, 0x284(r3)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x34
	  bne-      .loc_0xE0
	  cmpwi     r29, -0x1
	  beq-      .loc_0xE0
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x5B8C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x98
	  fmr       f1, f31
	  stw       r29, 0x1A0(r30)
	  addi      r4, r31, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x20
	  bl        0x5ED4
	  lwz       r3, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r3, 0x194(r30)
	  stw       r0, 0x198(r30)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x19C(r30)
	  b         .loc_0xA0

	.loc_0x98:
	  li        r0, -0x1
	  stw       r0, 0x1A0(r30)

	.loc_0xA0:
	  lwz       r0, 0x1A0(r30)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x19C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        0x174
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19C
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,17,15
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x4000
	  stw       r0, 0xC8(r30)
	  b         .loc_0x19C

	.loc_0xE0:
	  li        r0, -0x1
	  stw       r0, 0x1A0(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  addi      r5, r28, 0
	  bl        0x138
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x194
	  cmplwi    r28, 0
	  beq-      .loc_0x12C
	  lbz       r3, 0x5C(r28)
	  li        r0, 0x1
	  cmplwi    r3, 0x1
	  beq-      .loc_0x124
	  cmplwi    r3, 0
	  beq-      .loc_0x124
	  li        r0, 0

	.loc_0x124:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x144

	.loc_0x12C:
	  fmr       f1, f31
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  addi      r5, r28, 0
	  bl        -0x798
	  b         .loc_0x174

	.loc_0x144:
	  subi      r0, r3, 0x5
	  rlwinm    r0,r0,0,24,31
	  cmplwi    r0, 0x1
	  li        r0, 0x1
	  ble-      .loc_0x15C
	  li        r0, 0

	.loc_0x15C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x174
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  addi      r5, r28, 0
	  bl        -0x4BC

	.loc_0x174:
	  stw       r28, 0x188(r30)
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,17,15
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x4000
	  stw       r0, 0xC8(r30)
	  b         .loc_0x19C

	.loc_0x194:
	  li        r0, 0
	  stw       r0, 0x188(r30)

	.loc_0x19C:
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80090878
 * Size:	00006C
 */
void Creature::endStickObject()
{
	if (mPelletStickSlot != -1 && mStickTarget) {
		if (mStickTarget->mObjType != OBJTYPE_Pellet) {
			ERROR("stick to non-pellet!\n");
		}
		Pellet* pellet = static_cast<Pellet*>(mStickTarget);
		pellet->stickOffSlot(mPelletStickSlot);
	}

	mPelletStickSlot = -1;
	endStick();
	mStickPart = nullptr;
	resetCreatureFlag(CF_StuckToObject);
}

/*
 * --INFO--
 * Address:	800908E4
 * Size:	0000F8
 */
bool Creature::startStick(Creature* stickTarget, CollPart* stickPart)
{
	mStickPart = nullptr;
	resetCreatureFlag(CF_StuckToObject);
	if (mStickTarget) {
		PRINT("already stick to something !\n");
		return false;
	}

	PRINT("piki%x :::: stick ! : standType = %s\n", _standType[getStandType()]);

	mStickTarget = stickTarget;
	if (!stickTarget->mStickListHead) {
		stickTarget->mStickListHead = this;
		mPrevSticker                = nullptr;
		mNextSticker                = nullptr;
	} else {
		Creature* prevSticker;
		for (prevSticker = stickTarget->mStickListHead; prevSticker->mNextSticker; prevSticker = prevSticker->mNextSticker) {
			;
		}
		prevSticker->mNextSticker = this;
		mPrevSticker              = prevSticker;
		mNextSticker              = nullptr;
	}

	if (!mStickTarget) {
		PRINT("error !\n");
	}
	if (!mStickTarget) {
		PRINT("error2 !\n");
	}

	mStickPart = stickPart;

	stickToCallback(stickTarget);
	stickTarget->stickCallback(this);
	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
bool Creature::isStickLeader()
{
	if (mStickTarget && !mPrevSticker) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800909DC
 * Size:	0000EC
 */
void Creature::endStick()
{
	mCollPlatNormal = nullptr;
	if (!mStickTarget) {
		return;
	}

	mStickTarget->offstickCallback(this);
	if (!mPrevSticker && !mNextSticker) {
		mStickTarget->mStickListHead = nullptr;
		mStickTarget                 = nullptr;
		PRINT("course 1 : only\n");

	} else if (!mPrevSticker) {
		mStickTarget->mStickListHead = mNextSticker;
		mStickTarget                 = nullptr;
		mNextSticker->mPrevSticker   = nullptr;
		mPrevSticker                 = nullptr;
		mNextSticker                 = nullptr;
		PRINT("course 2 : top\n");

	} else {
		mStickTarget               = nullptr;
		mPrevSticker->mNextSticker = mNextSticker;
		if (mNextSticker) {
			mNextSticker->mPrevSticker = mPrevSticker;
		}
		mPrevSticker = nullptr;
		mNextSticker = nullptr;
		PRINT("course 3 : prev and next\n");
	}

	mCollPlatform = nullptr;
}

/*
 * --INFO--
 * Address:	80090AC8
 * Size:	000124
 */
bool Creature::startRope(RopeCreature* rope, f32 ropeRatio)
{
	_114.makeIdentity();
	if (mRope) {
		PRINT("already hold on to something !\n");
		return false;
	}

	mRope = rope;

	Cylinder cylinder(rope->mPosition, rope->_2B8->mPosition, 2.0f);
	mRopeRatio = cylinder.getPosRatio(mPosition);
	mPosition  = rope->getRopePos(mRopeRatio);

	if (!rope->mRopeListHead) {
		rope->mRopeListHead = this;
		mPrevRopeHolder     = nullptr;
		mNextRopeHolder     = nullptr;

	} else {
		Creature* prevHolder = rope->mRopeListHead;
		for (prevHolder; prevHolder->mNextRopeHolder; prevHolder = prevHolder->mNextRopeHolder) {
			;
		}
		prevHolder->mNextRopeHolder = this;
		mPrevRopeHolder             = prevHolder;
		mNextRopeHolder             = nullptr;
	}

	mRopeRatio = ropeRatio;

	return true;
}

/*
 * --INFO--
 * Address:	80090BEC
 * Size:	000098
 */
void Creature::endRope()
{
	if (!mRope) {
		return;
	}

	PRINT("endRope called ! : %x\n", this);

	if (!mPrevRopeHolder && !mNextRopeHolder) {
		mRope->mRopeListHead = nullptr;
		mRope                = nullptr;
		return;
	}

	if (!mPrevRopeHolder) {
		mRope->mRopeListHead             = mNextRopeHolder;
		mRope                            = nullptr;
		mNextRopeHolder->mPrevRopeHolder = nullptr;
		mPrevRopeHolder                  = nullptr;
		mNextRopeHolder                  = nullptr;
		return;
	}

	mRope                            = nullptr;
	mPrevRopeHolder->mNextRopeHolder = mNextRopeHolder;
	if (mNextRopeHolder) {
		mNextRopeHolder->mPrevRopeHolder = mPrevRopeHolder;
	}
	mPrevRopeHolder = nullptr;
	mNextRopeHolder = nullptr;
}

/*
 * --INFO--
 * Address:	80090C84
 * Size:	000058
 */
Stickers::Stickers(Creature* owner)
{
	mOwner = owner;
	calcNum();
}

/*
 * --INFO--
 * Address:	80090CDC
 * Size:	000030
 */
void Stickers::calcNum()
{
	mCount          = 0;
	Creature* stuck = mOwner->mStickListHead;
	while (stuck) {
		stuck = stuck->mNextSticker;
		mCount++;
	}
}

/*
 * --INFO--
 * Address:	80090D0C
 * Size:	0000CC
 */
Creature* Stickers::getCreature(int idx)
{
	int startCount = mCount;
	calcNum();
	if (startCount > mCount && idx >= mCount) {
		idx = mCount - 1;
	}

	Creature* stuck = mOwner->mStickListHead;
	for (int i = 0; i < idx; i++) {
		stuck = stuck->mNextSticker;
	}
	if (stuck) {
		return stuck;
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	80090DD8
 * Size:	000008
 */
int Stickers::getFirst()
{
	return 0;
}

/*
 * --INFO--
 * Address:	80090DE0
 * Size:	000008
 */
int Stickers::getNext(int idx)
{
	return idx + 1;
}

/*
 * --INFO--
 * Address:	80090DE8
 * Size:	00001C
 */
bool Stickers::isDone(int idx)
{
	if (idx >= mCount) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80090E04
 * Size:	000254
 */
void Creature::updateStickPlatform()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stfd      f29, 0xB8(r1)
	  stfd      f28, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  mr        r31, r3
	  lwz       r0, 0x284(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x230
	  lwz       r0, 0x288(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x230
	  lwz       r3, 0x188(r31)
	  bl        -0x9160
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x70
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x70
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r31
	  lfs       f1, 0x28C(r4)
	  bl        -0x288C
	  mr        r3, r31
	  bl        -0x29A4

	.loc_0x70:
	  lwz       r3, 0x284(r31)
	  lfs       f30, 0x0(r3)
	  lfs       f29, 0x4(r3)
	  lfs       f28, 0x8(r3)
	  stfs      f30, 0x84(r1)
	  stfs      f29, 0x88(r1)
	  stfs      f28, 0x8C(r1)
	  lfs       f4, -0x5C20(r13)
	  lfs       f0, 0x84(r1)
	  lfs       f1, 0x88(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x8C(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x84(r1)
	  stfs      f3, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  lfs       f1, 0xA0(r31)
	  bl        0x18AC98
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x18AE20
	  stfs      f30, 0x6C(r1)
	  stfs      f29, 0x70(r1)
	  stfs      f28, 0x74(r1)
	  lfs       f7, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  lfs       f3, 0x6C(r1)
	  fmuls     f2, f7, f31
	  fmuls     f5, f0, f1
	  lfs       f6, -0x5C1C(r13)
	  fmuls     f4, f3, f31
	  fmuls     f0, f0, f6
	  fmuls     f3, f3, f6
	  fmuls     f1, f7, f1
	  fsubs     f0, f2, f0
	  fsubs     f2, f5, f4
	  stfs      f0, 0x6C(r1)
	  fsubs     f0, f3, f1
	  stfs      f2, 0x70(r1)
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  lfs       f2, 0x74(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x832F8
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x168
	  lfs       f0, 0x6C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x74(r1)

	.loc_0x168:
	  lfs       f0, 0x84(r1)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x68(r1)
	  lfs       f6, 0x70(r1)
	  lfs       f5, 0x6C(r1)
	  lfs       f7, 0x64(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x74(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x60(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x60(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x64(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x60(r1)
	  lfs       f0, 0x64(r1)
	  lfs       f2, 0x68(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x833AC
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x21C
	  lfs       f0, 0x60(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x64(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x68(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x68(r1)

	.loc_0x21C:
	  addi      r3, r1, 0x6C
	  addi      r4, r1, 0x60
	  addi      r5, r1, 0x84
	  addi      r6, r31, 0x114
	  bl        0x816F0

	.loc_0x230:
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lfd       f29, 0xB8(r1)
	  lfd       f28, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80091058
 * Size:	0000BC
 */
void Creature::updateStickNonPlatform()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r0, 0x1A0(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x2C
	  mr        r3, r31
	  bl        0x284
	  b         .loc_0xA8

	.loc_0x2C:
	  lwz       r4, 0x188(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x5C
	  lbz       r3, 0x5C(r4)
	  li        r0, 0x1
	  cmplwi    r3, 0x1
	  beq-      .loc_0x54
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  li        r0, 0

	.loc_0x54:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x68

	.loc_0x5C:
	  mr        r3, r31
	  bl        .loc_0xBC
	  b         .loc_0xA8

	.loc_0x68:
	  cmplwi    r3, 0x5
	  li        r0, 0x1
	  beq-      .loc_0x80
	  cmplwi    r3, 0x6
	  beq-      .loc_0x80
	  li        r0, 0

	.loc_0x80:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x94
	  mr        r3, r31
	  bl        0x57C
	  b         .loc_0xA8

	.loc_0x94:
	  addi      r3, r1, 0x24
	  bl        -0x9250
	  addi      r3, r1, 0x18
	  lwz       r4, 0x188(r31)
	  bl        -0x9220

	.loc_0xA8:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0xBC:
	*/
}

/*
 * --INFO--
 * Address:	80091114
 * Size:	0001EC
 */
void Creature::updateStickSphere()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  mr        r31, r3
	  stw       r30, 0xD8(r1)
	  lwz       r4, 0x188(r3)
	  lwz       r30, 0x184(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x34
	  addi      r3, r1, 0x94
	  bl        -0x9228
	  b         .loc_0x48

	.loc_0x34:
	  addi      r3, r1, 0x94
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0x53064

	.loc_0x48:
	  lfs       f0, 0x194(r31)
	  addi      r3, r1, 0x88
	  addi      r4, r1, 0x94
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x198(r31)
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x19C(r31)
	  stfs      f0, 0x90(r1)
	  bl        -0x59A30
	  lwz       r3, 0x188(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x94
	  lfsu      f3, 0x4(r3)
	  lfs       f1, 0x88(r1)
	  lfs       f2, 0x8(r3)
	  lfs       f0, 0x90(r1)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  b         .loc_0xAC

	.loc_0x94:
	  lfs       f3, 0x94(r30)
	  lfs       f1, 0x88(r1)
	  lfs       f2, 0x9C(r30)
	  lfs       f0, 0x90(r1)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0

	.loc_0xAC:
	  bl        0x18A838
	  lfs       f0, -0x5C18(r13)
	  mr        r3, r31
	  stfs      f0, 0x88(r31)
	  stfs      f1, 0x8C(r31)
	  lfs       f0, -0x5C14(r13)
	  stfs      f0, 0x90(r31)
	  lfs       f1, 0x88(r1)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x40(r1)
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lwz       r4, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, -0x74B0(r2)
	  lfs       f3, 0x28C(r4)
	  lfs       f0, 0x70(r31)
	  fdivs     f2, f1, f3
	  fmuls     f0, f0, f2
	  fmr       f1, f3
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x30(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x74(r31)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x78(r31)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x6C(r1)
	  lwz       r4, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0x70(r31)
	  lwz       r0, 0x74(r31)
	  stw       r4, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x78(r31)
	  stw       r0, 0xAC(r31)
	  bl        -0x2CC0
	  lfs       f0, -0x5C10(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x5C0C(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x5C08(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x5C04(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x5C00(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x5BFC(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1AC(r31)
	  stw       r0, 0x1B0(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1B4(r31)
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80091300
 * Size:	000360
 */
void Creature::updateStickPellet()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stfd      f30, 0x110(r1)
	  stw       r31, 0x10C(r1)
	  mr        r31, r3
	  stw       r30, 0x108(r1)
	  lwz       r3, 0x184(r3)
	  lbz       r0, 0x43C(r3)
	  addi      r30, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  addi      r3, r1, 0xC4
	  addi      r4, r30, 0x94
	  addi      r5, r30, 0xE0
	  addi      r6, r30, 0x7C
	  bl        -0x52640
	  b         .loc_0xA8

	.loc_0x4C:
	  lfs       f0, 0x7C(r30)
	  addi      r5, r1, 0x8C
	  addi      r6, r1, 0x98
	  stfs      f0, 0x80(r1)
	  addi      r3, r1, 0xC4
	  addi      r4, r1, 0x80
	  lfs       f0, 0x80(r30)
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x84(r30)
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x88(r30)
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x8C(r30)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x90(r30)
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0xA0(r1)
	  bl        -0x532B0

	.loc_0xA8:
	  lfs       f0, 0x194(r31)
	  mr        r3, r30
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0x198(r31)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0x19C(r31)
	  stfs      f0, 0xC0(r1)
	  lfs       f0, -0x74C8(r2)
	  stfs      f0, 0xBC(r1)
	  bl        0xC1C
	  lfs       f0, -0x74B0(r2)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  fsubs     f1, f1, f0
	  lfs       f0, -0x74A8(r2)
	  lwz       r12, 0x44(r12)
	  lfs       f31, 0x2D0(r30)
	  fmuls     f30, f0, f1
	  mtlr      r12
	  blrl
	  fmuls     f0, f30, f1
	  mr        r3, r30
	  fadds     f30, f31, f0
	  bl        0xBE4
	  fmuls     f0, f30, f1
	  addi      r3, r1, 0xB8
	  addi      r4, r1, 0xC4
	  stfs      f0, 0xBC(r1)
	  bl        -0x59CCC
	  lfs       f3, 0x94(r30)
	  lfs       f1, 0xB8(r1)
	  lfs       f2, 0x9C(r30)
	  lfs       f0, 0xC0(r1)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x18A5C4
	  lfs       f0, -0x5BF8(r13)
	  stfs      f0, 0x88(r31)
	  stfs      f1, 0x8C(r31)
	  lfs       f0, -0x5BF4(r13)
	  stfs      f0, 0x90(r31)
	  stfs      f1, 0xA0(r31)
	  lfs       f1, 0xB8(r1)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x78(r31)
	  lfs       f1, 0x70(r31)
	  lfs       f3, 0x78(r31)
	  lfs       f0, 0x74(r31)
	  fmuls     f2, f1, f1
	  fmuls     f3, f3, f3
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x74C8(r2)
	  lfs       f6, 0x28C(r3)
	  fadds     f1, f2, f1
	  fadds     f5, f3, f1
	  fmr       f1, f6
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x230
	  fsqrte    f2, f5
	  lfd       f4, -0x74C0(r2)
	  lfd       f3, -0x74B8(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f5, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f5, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f5, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f5, f0
	  frsp      f0, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f5, 0x3C(r1)

	.loc_0x230:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x28C
	  lfs       f0, -0x74A4(r2)
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x28C
	  lwz       r4, 0x1A0(r31)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x264
	  lwz       r3, 0x184(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x264
	  bl        0x4DA4

	.loc_0x264:
	  li        r0, -0x1
	  stw       r0, 0x1A0(r31)
	  mr        r3, r31
	  bl        -0xB94
	  li        r0, 0
	  stw       r0, 0x188(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,18,16
	  stw       r0, 0xC8(r31)
	  b         .loc_0x340

	.loc_0x28C:
	  lfs       f2, -0x74B0(r2)
	  mr        r3, r31
	  lfs       f0, 0x70(r31)
	  fdivs     f2, f2, f6
	  fmuls     f0, f0, f2
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x40(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x74(r31)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x78(r31)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x70(r1)
	  lwz       r4, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0x70(r31)
	  lwz       r0, 0x74(r31)
	  stw       r4, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x78(r31)
	  stw       r0, 0xAC(r31)
	  bl        -0x3018
	  lfs       f0, -0x5BF0(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x5BEC(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x5BE8(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x5BE4(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x5BE0(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x5BDC(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1AC(r31)
	  stw       r0, 0x1B0(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1B4(r31)

	.loc_0x340:
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lfd       f30, 0x110(r1)
	  lwz       r31, 0x10C(r1)
	  lwz       r30, 0x108(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80091660
 * Size:	0003BC
 */
void Creature::updateStickTube()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  addi      r4, r1, 0xF0
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  stw       r31, 0x114(r1)
	  addi      r31, r3, 0
	  lfs       f0, -0x74C8(r2)
	  stfs      f0, 0xF8(r1)
	  stfs      f0, 0xF4(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f0, 0x104(r1)
	  stfs      f0, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  lwz       r3, 0x188(r3)
	  bl        -0x8B18
	  lfs       f0, -0x74C8(r2)
	  addi      r3, r1, 0xF0
	  addi      r4, r31, 0x94
	  stfs      f0, 0xEC(r1)
	  addi      r5, r1, 0xE4
	  addi      r6, r1, 0xD8
	  stfs      f0, 0xE8(r1)
	  stfs      f0, 0xE4(r1)
	  stfs      f0, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  stfs      f0, 0xD8(r1)
	  lfs       f1, 0x194(r31)
	  bl        -0x9E48
	  lfs       f1, 0x194(r31)
	  addi      r3, r1, 0x84
	  addi      r4, r1, 0xF0
	  bl        -0x9C20
	  lfs       f3, 0x88(r1)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0x84(r1)
	  lfs       f1, 0x94(r31)
	  fsubs     f30, f3, f0
	  lfs       f3, 0x8C(r1)
	  fsubs     f31, f2, f1
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f30, f30
	  fsubs     f29, f3, f1
	  fmuls     f1, f31, f31
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x83AE4
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xE0
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0xE0:
	  lfs       f0, -0x74C8(r2)
	  mr        r3, r31
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  lfs       f3, 0xD8(r1)
	  lfs       f1, 0x70(r31)
	  lfs       f0, 0x74(r31)
	  lfs       f4, 0xDC(r1)
	  fmuls     f1, f1, f3
	  lfs       f2, 0x78(r31)
	  fmuls     f0, f0, f4
	  lfs       f5, 0xE0(r1)
	  fmuls     f2, f2, f5
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fmuls     f2, f3, f0
	  fmuls     f1, f4, f0
	  fmuls     f0, f5, f0
	  stfs      f2, 0xB4(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  lwz       r4, 0xB4(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xBC(r1)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x28C(r4)
	  bl        -0x31DC
	  lfs       f0, 0xD8(r1)
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0xDC(r1)
	  stfs      f0, 0xAC(r1)
	  lfs       f0, 0xE0(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f31, 0x9C(r1)
	  stfs      f30, 0xA0(r1)
	  stfs      f29, 0xA4(r1)
	  lfs       f1, 0xA4(r1)
	  lfs       f6, 0xAC(r1)
	  lfs       f5, 0xA8(r1)
	  lfs       f7, 0xA0(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0xB0(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x9C(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x9C(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0xA0(r1)
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  lfs       f2, 0xA4(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x83C08
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x21C
	  lfs       f0, 0x9C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xA4(r1)

	.loc_0x21C:
	  lfs       f4, -0x5BD8(r13)
	  lfs       f0, 0x9C(r1)
	  lfs       f1, 0xA0(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0xA4(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x9C(r1)
	  stfs      f3, 0xA0(r1)
	  stfs      f1, 0xA4(r1)
	  lfs       f0, 0x9C(r1)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0xA4(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x98(r1)
	  lfs       f6, 0xAC(r1)
	  lfs       f5, 0xA8(r1)
	  lfs       f7, 0x94(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0xB0(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x90(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x90(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  lfs       f2, 0x98(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x83CE4
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2F8
	  lfs       f0, 0x90(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x98(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x98(r1)

	.loc_0x2F8:
	  addi      r3, r1, 0x9C
	  addi      r4, r1, 0xA8
	  addi      r5, r1, 0x90
	  addi      r6, r31, 0x114
	  bl        0x80DB8
	  addi      r3, r1, 0xF0
	  addi      r4, r31, 0x94
	  bl        -0xA1C8
	  stfs      f1, 0x194(r31)
	  lfs       f0, -0x74B0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x36C
	  lwz       r4, 0x1A0(r31)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x344
	  lwz       r3, 0x184(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x344
	  bl        0x4964

	.loc_0x344:
	  li        r0, -0x1
	  stw       r0, 0x1A0(r31)
	  mr        r3, r31
	  bl        -0xFD4
	  li        r0, 0
	  stw       r0, 0x188(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,18,16
	  stw       r0, 0xC8(r31)
	  b         .loc_0x39C

	.loc_0x36C:
	  lfs       f1, 0x194(r31)
	  addi      r3, r1, 0xF0
	  addi      r4, r31, 0x94
	  addi      r5, r1, 0xE4
	  addi      r6, r1, 0xD8
	  bl        -0xA150
	  lwz       r3, 0xE4(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0xEC(r1)
	  stw       r0, 0x9C(r31)

	.loc_0x39C:
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lwz       r31, 0x114(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80091A1C
 * Size:	0004A4
 */
void Creature::updateStickRope()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x260(r1)
	  stfd      f31, 0x258(r1)
	  stfd      f30, 0x250(r1)
	  stfd      f29, 0x248(r1)
	  stw       r31, 0x244(r1)
	  mr        r31, r3
	  stw       r30, 0x240(r1)
	  lwz       r4, 0x158(r3)
	  lfsu      f31, 0x2C4(r4)
	  lfs       f0, -0x74C8(r2)
	  lfs       f30, 0x4(r4)
	  lfs       f29, 0x8(r4)
	  stfs      f0, 0x220(r1)
	  stfs      f0, 0x21C(r1)
	  stfs      f0, 0x218(r1)
	  lfs       f5, 0x70(r31)
	  lfs       f4, 0x74(r31)
	  lfs       f3, 0x78(r31)
	  fmuls     f1, f5, f31
	  fmuls     f0, f4, f30
	  fmuls     f2, f3, f29
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fmuls     f2, f31, f0
	  fmuls     f1, f30, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0x218(r1)
	  stfs      f1, 0x21C(r1)
	  stfs      f0, 0x220(r1)
	  lfs       f2, 0x220(r1)
	  lfs       f1, 0x21C(r1)
	  lfs       f0, 0x218(r1)
	  fsubs     f2, f3, f2
	  lwz       r4, 0x218(r1)
	  fsubs     f1, f4, f1
	  lwz       r0, 0x21C(r1)
	  fsubs     f3, f5, f0
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x220(r1)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0x158(r31)
	  lfs       f0, 0x70(r4)
	  addi      r5, r4, 0x70
	  fadds     f0, f0, f3
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x94(r1)
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0x74(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0x78(r4)
	  fadds     f0, f0, f2
	  stfs      f0, 0xC0(r1)
	  lwz       r4, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r4, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x8(r5)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x28C(r4)
	  bl        -0x3540
	  stfs      f31, 0x20C(r1)
	  stfs      f30, 0x210(r1)
	  stfs      f29, 0x214(r1)
	  lfs       f1, 0xA0(r31)
	  bl        0x18A024
	  fmr       f29, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x18A1AC
	  stfs      f1, 0x200(r1)
	  lfs       f0, -0x5BD4(r13)
	  stfs      f0, 0x204(r1)
	  stfs      f29, 0x208(r1)
	  lfs       f1, 0x208(r1)
	  lfs       f6, 0x210(r1)
	  lfs       f5, 0x20C(r1)
	  lfs       f7, 0x204(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x214(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x200(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x200(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x204(r1)
	  stfs      f0, 0x208(r1)
	  lfs       f1, 0x200(r1)
	  lfs       f0, 0x204(r1)
	  lfs       f2, 0x208(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x83F78
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1D0
	  lfs       f0, 0x200(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x200(r1)
	  lfs       f0, 0x204(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x204(r1)
	  lfs       f0, 0x208(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x208(r1)

	.loc_0x1D0:
	  lfs       f4, -0x5BD0(r13)
	  lfs       f0, 0x200(r1)
	  lfs       f1, 0x204(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x208(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x200(r1)
	  stfs      f3, 0x204(r1)
	  stfs      f1, 0x208(r1)
	  lfs       f0, 0x200(r1)
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x204(r1)
	  stfs      f0, 0x1F8(r1)
	  lfs       f0, 0x208(r1)
	  stfs      f0, 0x1FC(r1)
	  lfs       f1, 0x1FC(r1)
	  lfs       f6, 0x210(r1)
	  lfs       f5, 0x20C(r1)
	  lfs       f7, 0x1F8(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x214(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x1F4(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x1F4(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x1F8(r1)
	  stfs      f0, 0x1FC(r1)
	  lfs       f1, 0x1F4(r1)
	  lfs       f0, 0x1F8(r1)
	  lfs       f2, 0x1FC(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x84054
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2AC
	  lfs       f0, 0x1F4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x1F8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1F8(r1)
	  lfs       f0, 0x1FC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1FC(r1)

	.loc_0x2AC:
	  addi      r3, r1, 0x200
	  addi      r4, r1, 0x20C
	  addi      r5, r1, 0x1F4
	  addi      r6, r31, 0x114
	  bl        0x80A48
	  lwz       r3, 0x158(r31)
	  lwz       r0, 0x2B8(r3)
	  addi      r30, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0x2EC
	  lis       r3, 0x802B
	  lwz       r5, 0x6C(r30)
	  subi      r4, r3, 0xC98
	  crclr     6, 0x6
	  addi      r3, r1, 0xF0
	  bl        0x184894

	.loc_0x2EC:
	  lwz       r3, 0x2B8(r30)
	  addi      r4, r31, 0x94
	  lfs       f0, 0x94(r30)
	  addi      r5, r3, 0x94
	  stfs      f0, 0xD4(r1)
	  addi      r3, r1, 0xD4
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0xE4(r1)
	  lfs       f1, 0x8(r5)
	  lfs       f0, -0x74AC(r2)
	  stfs      f1, 0xE8(r1)
	  stfs      f0, 0xEC(r1)
	  bl        -0xA688
	  stfs      f1, 0x15C(r31)
	  lfs       f1, 0x15C(r31)
	  lfs       f0, -0x74B0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x384
	  mr        r3, r31
	  bl        -0x1180
	  lwz       r4, 0x2B8(r30)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x12
	  bne-      .loc_0x480
	  lfs       f1, -0x74C8(r2)
	  mr        r3, r31
	  bl        -0x12C0
	  lwz       r30, 0x2B8(r30)
	  lfs       f0, -0x74C8(r2)
	  stfs      f0, 0x15C(r31)
	  b         .loc_0x3C0
	  b         .loc_0x480

	.loc_0x384:
	  lfs       f0, -0x74C8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3C0
	  lwz       r0, 0x2BC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C0
	  mr        r3, r31
	  bl        -0x11D0
	  lwz       r4, 0x2BC(r30)
	  mr        r3, r31
	  lfs       f1, -0x74B0(r2)
	  bl        -0x1304
	  lwz       r30, 0x2BC(r30)
	  lfs       f0, -0x74B0(r2)
	  stfs      f0, 0x15C(r31)

	.loc_0x3C0:
	  lfs       f31, 0x1F4(r1)
	  lfs       f30, 0x1F8(r1)
	  fmuls     f1, f31, f31
	  lfs       f29, 0x1FC(r1)
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x841BC
	  lfs       f0, -0x74C8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x3FC
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x3FC:
	  lfs       f0, -0x74AC(r2)
	  cmplwi    r30, 0
	  fmuls     f29, f29, f0
	  fmuls     f30, f30, f0
	  fmuls     f31, f31, f0
	  beq-      .loc_0x43C
	  lfs       f1, 0x15C(r31)
	  addi      r4, r30, 0
	  addi      r3, r1, 0xAC
	  bl        0x2B3C
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x9C(r31)

	.loc_0x43C:
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f0, f30
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f0, f29
	  stfs      f0, 0xA8(r1)
	  lwz       r3, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x9C(r31)

	.loc_0x480:
	  lwz       r0, 0x264(r1)
	  lfd       f31, 0x258(r1)
	  lfd       f30, 0x250(r1)
	  lfd       f29, 0x248(r1)
	  lwz       r31, 0x244(r1)
	  lwz       r30, 0x240(r1)
	  addi      r1, r1, 0x260
	  mtlr      r0
	  blr
	*/
}
