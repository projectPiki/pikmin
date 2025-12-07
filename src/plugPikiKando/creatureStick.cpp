#include "Collision.h"
#include "Condition.h"
#include "Creature.h"
#include "DebugLog.h"
#include "Interactions.h"
#include "Iterator.h"
#include "KMath.h"
#include "Pellet.h"
#include "RopeCreature.h"
#include "Stickers.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(16)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("CreatureStick");

/*
 * --INFO--
 * Address:	8008F9C4
 * Size:	000160
 */
void Creature::interactStickers(Creature* stuckTo, immut Interaction& interaction, immut Condition* condition)
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
void Creature::killStickers(Creature* stuckTo, immut Condition* cond, int p3)
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
void Creature::adjustStickObject(immut Vector3f&)
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
		PRINT("startStickMouth::already stuck to %s : endStick\n", mStickPart->mCollInfo->mId.mStringID);
		endStick();
	}

	if (startStick(mouthOwner, mouthPart)) {
		if (mObjType == OBJTYPE_Rope) {
			ERROR("stick to mouth!!\n");
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
	Matrix4f worldMatrix;
	Matrix4f invWorldMatrix;
	Vector3f unused;

	// Get world transform from either attach point or full object
	if (stickPart) {
		worldMatrix = mStickPart->getMatrix(); // Likely bug: should use stickPart instead of mStickPart
	} else {
		worldMatrix.makeSRT(obj->mSRT.s, obj->mSRT.r, obj->mSRT.t);
	}

	worldMatrix.inverse(&invWorldMatrix);

	// Start from current position
	mAttachPosition = mSRT.t;

	if (stickPart) {
		// Position relative to attach point's center
		mAttachPosition = mAttachPosition - stickPart->mCentre;
		mAttachPosition.normalise();

		// Move out to the surface of the sphere plus the offset
		mAttachPosition = mAttachPosition * (stickPart->mRadius + stickDist) + stickPart->mCentre;
	} else {
		// Same process but using full object's center and size
		mAttachPosition = mAttachPosition - obj->mSRT.t;
		mAttachPosition.normalise();

		mAttachPosition = mAttachPosition * (obj->getCentreSize() + stickDist) + obj->mSRT.t;
	}

	// Convert final position to object's local space
	mAttachPosition.multMatrix(invWorldMatrix);
	PRINT_KANDO("StartStick SPHERE * (%.1f %.1f %.1f) \n", mAttachPosition.x, mAttachPosition.y, mAttachPosition.z);
}

/*
 * --INFO--
 * Address:	8009036C
 * Size:	00034C
 */
void Creature::startStickObjectTube(Creature* obj, CollPart* stickPart)
{
	Tube tube;
	stickPart->makeTube(tube);
	f32 ratio = tube.getPosRatio(mSRT.t);
	if (ratio < 0.0f) {
		ratio = 0.0f;
	} else if (ratio > 1.0f) {
		ratio = 1.0f;
	}

	mAttachPosition.x = ratio;
	Vector3f vec1;
	Vector3f vec2;
	tube.getPosGradient(mSRT.t, ratio, vec1, vec2);
	mSRT.t = vec1;
	vec2.normalise();

	Vector3f vec3 = tube.setPos(mAttachPosition.x);
	vec3          = vec3 - mSRT.t;
	vec3.normalise();
	Vector3f yVec(vec2);
	Vector3f xVec(vec3);
	xVec.CP(yVec);
	xVec.normalise();
	xVec = xVec * -1.0f;
	Vector3f zVec(xVec);
	zVec.CP(yVec);
	zVec.normalise();
	makePostureMatrix(xVec, yVec, zVec, mConstrainedMoveMtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void Creature::startStickObjectPellet(Pellet* pellet, int slotIdx, f32 offset)
{
	if (pellet->stickSlot(slotIdx)) {
		mPelletStickSlot = slotIdx;
		mAttachPosition  = pellet->getSlotLocalPos(slotIdx, offset);
		return;
	}

	mPelletStickSlot = -1;
}

/*
 * --INFO--
 * Address:	800906B8
 * Size:	0001C0
 */
void Creature::startStickObject(Creature* obj, CollPart* stickPart, int slot, f32 p4)
{
	mCollPlatNormal = nullptr;
	if (obj->mObjType == OBJTYPE_Pellet && slot != -1) {
		startStickObjectPellet(static_cast<Pellet*>(obj), slot, p4);
		if (mPelletStickSlot != -1 && startStick(obj, nullptr)) {
			resetCreatureFlag(CF_StuckToMouth);
			setCreatureFlag(CF_StuckToObject);
		}
		return;
	}

	mPelletStickSlot = -1;

	if (startStick(obj, stickPart)) {
		if (!stickPart || stickPart->isBouncySphereType()) {
			if (isTeki()) {
				PRINT("STICK TO SPHERE !\n");
			}

			startStickObjectSphere(obj, stickPart, p4);

		} else if (stickPart->isTubeType()) {
			startStickObjectTube(obj, stickPart);

		} else {
			PRINT("try to stick : ? part->flag\n");
			ERROR("mail to uja\n");
		}

		mStickPart = stickPart;
		resetCreatureFlag(CF_StuckToMouth);
		setCreatureFlag(CF_StuckToObject);
		return;
	}

	mStickPart = nullptr;
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

char* _standType[] = { "GROUND", "TEKIPLAT", "PLAT", "AIR" };

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

	PRINT_KANDO("piki%x :::: stick ! : standType = %s\n", _standType[getStandType()]);

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
	mConstrainedMoveMtx.makeIdentity();
	if (mRope) {
		PRINT("already hold on to something !\n");
		return false;
	}

	mRope = rope;

	Cylinder cylinder(rope->mSRT.t, rope->mParentRope->mSRT.t, 2.0f);
	mRopePosRatio = cylinder.getPosRatio(mSRT.t);
	mSRT.t        = rope->getRopePos(mRopePosRatio);

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

	mRopePosRatio = ropeRatio;

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

	PRINT_KANDO("endRope called ! : %x\n", this);

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
	if (mCollPlatNormal && mClimbingTri) {
		if (mStickPart->isClimbable() && isCreatureFlag(CF_IsClimbing)) {
			Vector3f pos(mSRT.t);
			moveNew(gsys->getFrameTime());
			moveAttach();
		}

		Vector3f normal(*mCollPlatNormal);
		Vector3f zVec(normal);
		zVec = -1.0f * zVec;
		Vector3f dir(sinf(mFaceDirection), 0.0f, cosf(mFaceDirection));
		Vector3f xVec(normal);
		xVec.CP(dir);
		xVec.normalise();
		Vector3f yVec(zVec);
		yVec.CP(xVec);
		yVec.normalise();
		makePostureMatrix(xVec, yVec, zVec, mConstrainedMoveMtx);
	}
}

/*
 * --INFO--
 * Address:	80091058
 * Size:	0000BC
 */
void Creature::updateStickNonPlatform()
{
	if (mPelletStickSlot != -1) {
		updateStickPellet();
		return;
	}

	if (!mStickPart || mStickPart->isBouncySphereType()) {
		updateStickSphere();
		return;
	}

	if (mStickPart->isTubeType()) {
		updateStickTube();
		return;
	}

	PRINT("flag is %x\n", mStickPart->mPartType);
	PRINT("%s : %s\n", mStickPart->getID().mStringID, mStickPart->getCode().mStringID);
	ERROR(" mail to partol : flag is %x\n", mStickPart->mPartType);
	ERROR("mail to m\n");
}

/*
 * --INFO--
 * Address:	80091114
 * Size:	0001EC
 */
void Creature::updateStickSphere()
{
	Matrix4f partMtx;
	Creature* stickObj = getStickObject();
	if (mStickPart) {
		partMtx = mStickPart->getMatrix();
	} else {
		partMtx.makeSRT(stickObj->mSRT.s, stickObj->mSRT.r, stickObj->mSRT.t);
	}

	Vector3f attachPos(mAttachPosition);
	attachPos.multMatrix(partMtx);
	Vector3f dir;
	if (mStickPart) {
		dir = mStickPart->mCentre - attachPos;
	} else {
		dir = stickObj->mSRT.t - attachPos;
	}

	mSRT.r.set(0.0f, atan2f(dir.x, dir.z), 0.0f);

	mVelocity       = attachPos - mSRT.t;
	f32 fTime       = gsys->getFrameTime();
	mVelocity       = mVelocity * (1.0f / fTime);
	mTargetVelocity = mVelocity;
	moveNew(fTime);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mLastPosition = mSRT.t;
}

/*
 * --INFO--
 * Address:	80091300
 * Size:	000360
 */
void Creature::updateStickPellet()
{
	if (getStickObject()->mObjType != OBJTYPE_Pellet) {
		ERROR("stick to non-pellet : update\n");
	}

	Pellet* stickObj = static_cast<Pellet*>(getStickObject());
	Matrix4f pelMtx;
	if (stickObj->isRealDynamics()) {
		pelMtx.makeVQS(stickObj->mSRT.t, stickObj->mRotationQuat, stickObj->mSRT.s);
	} else {
		pelMtx.makeSRT(stickObj->mSRT);
	}

	Vector3f attachPos(mAttachPosition);
	attachPos.y = 0.0f;
	f32 yOffs   = (stickObj->getY() - 1.0f) * 0.5f;
	f32 v       = (stickObj->getPickOffset() + yOffs * stickObj->getCylinderHeight());
	attachPos.y = stickObj->getY() * v;

	attachPos.multMatrix(pelMtx);

	Vector3f dir;
	dir         = stickObj->mSRT.t - attachPos;
	f32 faceDir = atan2f(dir.x, dir.z);
	mSRT.r.set(0.0f, faceDir, 0.0f);
	mFaceDirection = faceDir;
	mVelocity      = attachPos - mSRT.t;

	f32 fTime = gsys->getFrameTime();
	f32 speed = mVelocity.length();
	if (isPiki() && speed > 100.0f) {
		PRINT("** PIKI STICK OFF!!!\n");
		endStickObject();
		return;
	}

	mVelocity       = mVelocity * (1.0f / fTime);
	mTargetVelocity = mVelocity;
	moveNew(fTime);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mLastPosition = mSRT.t;

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	80091660
 * Size:	0003BC
 */
void Creature::updateStickTube()
{
	Tube tube;
	mStickPart->makeTube(tube);
	Vector3f vec1;
	Vector3f vec2;
	tube.getPosGradient(mSRT.t, mAttachPosition.x, vec1, vec2);
	Vector3f vec3 = tube.setPos(mAttachPosition.x);
	vec3          = vec3 - mSRT.t;
	vec3.normalise();
	Vector3f unused;
	Vector3f vec4;
	vec4      = mVelocity.DP(vec2) * vec2;
	unused    = mVelocity - vec4;
	mVelocity = vec4;
	moveNew(gsys->getFrameTime());
	Vector3f yVec(vec2);
	Vector3f xVec(vec3);
	xVec.CP(yVec);
	xVec.normalise();

	xVec = xVec * -1.0f;
	Vector3f zVec(xVec);
	zVec.CP(yVec);
	zVec.normalise();

	makePostureMatrix(xVec, yVec, zVec, mConstrainedMoveMtx);
	f32 ratio         = tube.getPosRatio(mSRT.t);
	mAttachPosition.x = ratio;
	if (ratio > 1.0f) {
		endStickObject();
	} else {
		tube.getPosGradient(mSRT.t, mAttachPosition.x, vec1, vec2);
		mSRT.t = vec1;
	}
}

/*
 * --INFO--
 * Address:	80091A1C
 * Size:	0004A4
 */
void Creature::updateStickRope()
{
	if (!mRope) {
		ERROR("no _ropeObject!\n");
	}

	Vector3f ropeDir(mRope->mRopeDirection);
	Vector3f vec1;
	Vector3f vec2;
	vec2      = mVelocity.DP(ropeDir) * ropeDir;
	vec1      = mVelocity - vec2;
	mVelocity = vec2;

	mRope->mVelocity = mRope->mVelocity + vec1;

	moveNew(gsys->getFrameTime());
	Vector3f yVec(ropeDir);
	Vector3f xVec(sinf(mFaceDirection), 0.0f, cosf(mFaceDirection));
	xVec.CP(yVec);
	xVec.normalise();
	xVec = xVec * -1.0f;

	Vector3f zVec(xVec);
	zVec.CP(yVec);
	zVec.normalise();
	makePostureMatrix(xVec, yVec, zVec, mConstrainedMoveMtx);
	RopeCreature* rope = mRope;
	f32 scale          = 2.0f;
	if (!rope->mParentRope) {
		PRINT("no fulcrum\n");
		char buf[256];
		sprintf(buf, "no fulc obj%d", rope->mObjType);
		ERROR(buf);
	}

	Cylinder cyl(rope->mSRT.t, rope->mParentRope->mSRT.t, scale);
	mRopePosRatio = cyl.getPosRatio(mSRT.t);
	if (cyl.mStartPoint.x == cyl.mEndPoint.x && cyl.mStartPoint.y == cyl.mEndPoint.y && cyl.mStartPoint.z == cyl.mEndPoint.z) {
		ERROR("rope kowareta!\n");
	}

	if (mRopePosRatio > 1.0f) {
		endRope();
		if (rope->mParentRope->mObjType == OBJTYPE_Rope) {
			PRINT_KANDO("upper rope\n");
			PRINT("%x upper rope!\n", this);
			startRope(static_cast<RopeCreature*>(rope->mParentRope), 0.0f);
			PRINT("==> ratio = %f\n", mRopePosRatio);
			rope          = static_cast<RopeCreature*>(rope->mParentRope);
			mRopePosRatio = 0.0f;
		} else {
			return;
		}

	} else if (mRopePosRatio < 0.0f && rope->mAttachedObj) {
		endRope();
		PRINT_KANDO("lower rope\n");
		PRINT("%x lower rope!\n", this);
		startRope(rope->mAttachedObj, 1.0f);
		PRINT("==> ratio = %f\n", mRopePosRatio);
		rope          = rope->mAttachedObj;
		mRopePosRatio = 1.0f;
	}

	Vector3f vec3(zVec);
	vec3.normalise();
	vec3 = vec3 * scale;
	if (rope) {
		mSRT.t = rope->getRopePos(mRopePosRatio);
	}

	mSRT.t = mSRT.t - vec3;
}
