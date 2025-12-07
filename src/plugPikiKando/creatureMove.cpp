#include "AIConstant.h"
#include "Collision.h"
#include "Creature.h"
#include "CreatureProp.h"
#include "DebugLog.h"
#include "DynColl.h"
#include "GameStat.h"
#include "GoalItem.h"
#include "MapMgr.h"
#include "Pellet.h"
#include "Piki.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "RopeCreature.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(28)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("CreatureMove")

/*
 * --INFO--
 * Address:	8008E2CC
 * Size:	000200
 */
void Creature::moveRotation(f32 p1)
{
	if (isCreatureFlag(CF_Unk10)) {
		Vector3f vec1 = mPrevAngularVelocity * p1;
		Quat q1(vec1.x, vec1.y, vec1.z, 0.0f);
		Quat q2(mRotationQuat);

		q2.multiply(q1);

		f32 scale = 0.5f;
		mRotationQuat.set(scale * q2.v.x + mRotationQuat.v.x, scale * q2.v.y + mRotationQuat.v.y, scale * q2.v.z + mRotationQuat.v.z,
		                  scale * q2.s + mRotationQuat.s);
		mRotationQuat.normalise();
	}

	if (!isCreatureFlag(CF_Unk10) && !isCreatureFlag(CF_Unk11)) {
		if (SQUARE(mTargetVelocity.x) + SQUARE(mTargetVelocity.z) > 1.0f) {
			f32 angle = atan2f(mTargetVelocity.x, mTargetVelocity.z);

#if 0 // DLL only:
			if (isNan(angle)) {
				dump();
				ERROR("meck is eating B-teishoku!");
			}
#endif

			mFaceDirection += angDist(angle, mFaceDirection) * mProps->mCreatureProps.mFaceDirAdjust() * p1 * 10.0f;
			mFaceDirection = roundAng(mFaceDirection);
			if (mRope) {
				mSRT.r.y = mFaceDirection;
			} else {
				mSRT.r.set(0.0f, mFaceDirection, 0.0f);
			}
			return;
		}

		if (mRope) {
			mSRT.r.y = mFaceDirection;
		} else {
			mSRT.r.set(0.0f, mFaceDirection, 0.0f);
		}
		return;
	}

	if (!isCreatureFlag(CF_Unk10) && isCreatureFlag(CF_Unk11)) {
		mSRT.r.set(0.0f, mFaceDirection, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	8008E4CC
 * Size:	000110
 */
void Creature::moveAttach()
{
	_29C = mSRT.t;
	if (mCollPlatform) {
		Creature* plat = mCollPlatform->mCreature;
		if (platAttachable() || mStickTarget && isStickToPlatform()) {
			if (mCollPlatform) {
				// this isn't used further in the DLL either
				int objType = mCollPlatform->mCreature->mObjType;
			}

			mCollPlatform->adjust(this);
		} else {
			plat = nullptr;
		}

		if (!plat) {
			mCollPlatform = nullptr;
		}
	}

	_29C = _29C - mSRT.t;
}

/*
 * --INFO--
 * Address:	8008E5DC
 * Size:	000D60
 */
void Creature::moveNew(f32 deltaTime)
{
	if (mSRT.t.y < -2000.0f && isAlive()) {
		if (mObjType == OBJTYPE_Piki) {
			Piki* piki = static_cast<Piki*>(this);
			GameStat::fallPikis.inc(piki->mColor);
			PRINT("fall piki %x\n", piki);
		}

		if (mObjType == OBJTYPE_Pellet) {
			Pellet* pellet = static_cast<Pellet*>(this);
			for (int i = 0; i < 20; i++) {
				PRINT("++++ PELLET (%s) FALL !!!!!!!\n", pellet->mConfig->mModelId.mStringID);
			}
#if 0
			// not used any further in the DLL either.
			pellet->isUfoParts();
#endif

			pellet->mSRT.t.y = mapMgr->getMinY(pellet->mSRT.t.x, pellet->mSRT.t.z, true) + 30.0f;

		} else {
			kill(false);
		}

		return;
	}

	if (!isCreatureFlag(CF_IsFlying) && !mRope && (!mStickTarget || !isStickToPlatform() || !mStickPart->isClimbable())
	    && !isCreatureFlag(CF_Unk8) && (!mStickTarget || mPelletStickSlot == -1)) {
		mVelocity.y -= AIConstant::_instance->mConstants.mGravity() * deltaTime;
	}

	if (isCreatureFlag(CF_Unk5)) {
		mVelocity.y -= deltaTime * mAirResistance * mVelocity.y;
		f32 scale   = 0.2f;
		mVelocity.x = mVelocity.x - (deltaTime * mAirResistance) * scale * mVelocity.x;
		mVelocity.z = mVelocity.z - (deltaTime * mAirResistance) * scale * mVelocity.z;
	}

	mGroundTriangle = nullptr;

	if (mObjType == OBJTYPE_Rope) {
		RopeCreature* rope = static_cast<RopeCreature*>(this);
		Cylinder ropeBoundary(rope->mParentRope->mSRT.t, rope->mSRT.t, 1.0f);
		Vector3f pushVec;
		f32 collisionRatio;
		RopeItem* ropeItem = static_cast<RopeItem*>(rope);
		Iterator iter(pikiMgr);

		CI_LOOP(iter)
		{
			Piki* piki     = static_cast<Piki*>(*iter);
			bool canAttach = true;
			if (ropeItem->mOwner->mObjType == OBJTYPE_Goal) {
				GoalItem* base = static_cast<GoalItem*>(ropeItem->mOwner);
				if (base->mOnionColour != piki->mColor) {
					canAttach = false;
				}
			}

			if (canAttach && piki->isRopable() && piki->isAlive() && !piki->isBuried()) {
				Vector3f centerPoint = piki->getCentre();
				Sphere pikminBounds(centerPoint, piki->getCentreSize());

				if (ropeBoundary.collide(pikminBounds, pushVec, collisionRatio) && !piki->mRope) {
					Vector3f attachPoint     = rope->getRopePos(collisionRatio);
					Vector3f directionVector = attachPoint - piki->mSRT.t;
					f32 angle                = atan2f(directionVector.x, directionVector.z);

					if (collisionRatio < 0.0f) {
						collisionRatio = 0.0f;
					}
					if (collisionRatio > 1.0f) {
						collisionRatio = 1.0f;
					}

					piki->startRope(rope, collisionRatio);
					piki->mFaceDirection = angle;
					piki->mFSM->transit(piki, PIKISTATE_Normal);
				}
			}
		}

		Vector3f dir                  = mSRT.t - rope->mParentRope->mSRT.t;
		f32 distance                  = dir.normalise();
		Vector3f ropeDirectedVelocity = mVelocity.DP(dir) * dir;
		Vector3f perpVelocity         = mVelocity - ropeDirectedVelocity;

		mVelocity = perpVelocity;
		mVelocity = mVelocity - mVelocity * gsys->getFrameTime();

		mTargetVelocity = perpVelocity;
		if (rope->mParentRope->mObjType == OBJTYPE_Rope) {
			rope->mParentRope->mVelocity = rope->mParentRope->mVelocity + ropeDirectedVelocity;
		}

		if (distance != rope->mRopeLength) {
			mSRT.t = rope->mParentRope->mSRT.t + rope->mRopeLength * dir;
		}
	}

	mCollPlatform = nullptr;

	if (mObjType != OBJTYPE_Pellet) {
		Vector3f adjustedPos(mSRT.t);
		if (isCreatureFlag(CF_GroundOffsetEnabled)) {
			adjustedPos.y -= mGroundOffset;
		}

		if (mObjType == OBJTYPE_Pikihead) {
			MoveTrace trace(adjustedPos, mVelocity, mCollisionRadius, true);
			mapMgr->traceMove(this, trace, deltaTime);
			mVelocity = trace.mVelocity;
			mSRT.t    = trace.mPosition;
		} else {
			MoveTrace trace(adjustedPos, mVelocity, mCollisionRadius, false);
			mapMgr->traceMove(this, trace, deltaTime);
			mVelocity = trace.mVelocity;
			mSRT.t    = trace.mPosition;
		}

		if (isCreatureFlag(CF_GroundOffsetEnabled)) {
			mSRT.t.y += mGroundOffset;
		}
	} else {
		Pellet* pellet = static_cast<Pellet*>(this);
		if (pellet->isRealDynamics()) {
			f32 cylinderHeight = pellet->getCylinderHeight();
			f32 grabOffset     = -pellet->getPickOffset();

			Vector3f heightVector(0.0f, 0.5f * cylinderHeight, 0.0f);
			Matrix4f rotationMtx;
			rotationMtx.makeVQS(Vector3f(0.0f, 0.0f, 0.0f), pellet->mRotationQuat, Vector3f(1.0f, 1.0f, 1.0f));
			heightVector.multMatrix(rotationMtx);

			Vector3f tmpHeightVec = heightVector;
			heightVector          = heightVector + mSRT.t;

			MoveTrace movePath(heightVector, mVelocity, 0.5f * cylinderHeight + grabOffset, false);
			traceMove2(this, movePath, deltaTime);

			mVelocity = movePath.mVelocity;
			mSRT.t    = movePath.mPosition - tmpHeightVec;

		} else {
			Vector3f adjustedPos(mSRT.t);
			if (isCreatureFlag(CF_GroundOffsetEnabled)) {
				adjustedPos.y -= mGroundOffset;
			}

			MoveTrace trace(adjustedPos, mVelocity, mCollisionRadius, false);
			mapMgr->traceMove(this, trace, deltaTime);

			mVelocity = trace.mVelocity;
			mSRT.t    = trace.mPosition;

			if (isCreatureFlag(CF_GroundOffsetEnabled)) {
				mSRT.t.y += mGroundOffset;
			}
		}
	}

	if (mGroundTriangle) {
		if (!mPreviousTriangle) {
			Creature* platCreature = (mCollPlatform) ? mCollPlatform->mCreature : nullptr;

			if (!platCreature || platCreature->mObjType == OBJTYPE_WorkObject) {
				bounceCallback();
			}
		}

		setCreatureFlag(CF_IsOnGround);
	} else {
		resetCreatureFlag(CF_IsOnGround);
		if (mPreviousTriangle) {
			int planeIdx = -1;
			f32 minDist  = 12800.0f;

			for (int i = 0; i < 3; i++) {
				f32 dist = mPreviousTriangle->mEdgePlanes[i].dist(mSRT.t);
				if (dist <= minDist) {
					planeIdx = mPreviousTriangle->mAdjacentTriIndices[i];
					minDist  = dist;
				}
			}

			if (planeIdx < 0) {
				jumpCallback();
			} else {
				CollTriInfo* tri = &mapMgr->mMapShape->mTriList[planeIdx];
				if (tri->mTriangle.mNormal.DP(mPreviousTriangle->mTriangle.mNormal)
				    < cosf(AIConstant::_instance->mConstants.mJumpTriangleAngleThreshold() / 180.0f * PI)) {
					jumpCallback();
				}
			}
		}
	}

	mPreviousTriangle = mGroundTriangle;

	STACK_PAD_VAR(2);
	STACK_PAD_INLINE(1);
	STACK_PAD_TERNARY(mPreviousTriangle, 3);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002E8
 */
CollTriInfo* Creature::checkForward(immut Vector3f&, f32, f32&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
CollTriInfo* Creature::getNextTri(CollTriInfo*, immut Vector3f&, int&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008F33C
 * Size:	000100
 */
Plane* Creature::getNearestPlane(CollTriInfo* tri)
{
	int planeIdx = -1;
	f32 minDist  = 12800.0f;
	for (int i = 0; i < 3; i++) {
		f32 dist = tri->mEdgePlanes[i].dist(mSRT.t);
		PRINT(" :: plane%d dist is %f\n", i, dist);
		if (dist <= minDist) {
			planeIdx = i;
			minDist  = dist;
		}
	}

	if (planeIdx != -1) {
		return &tri->mEdgePlanes[planeIdx];
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void Creature::renderCollTriInfo(Graphics&, CollTriInfo*, immut Colour&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008F43C
 * Size:	000588
 */
void traceMove2(Creature* target, MoveTrace& trace, f32 p3)
{
	int stepMultiplier = 1;
	int iterationCount = 0;

	for (f32 distanceToMove = trace.mVelocity.length() * p3; iterationCount < 100 && distanceToMove >= trace.mRadius;
	     distanceToMove *= 0.5f) {
		iterationCount++;
		stepMultiplier *= 2;
	}

	if (iterationCount > 50) {
		PRINT("Too many iterations [cr %08x : rad = %f : spd = %f]!!\n", target, trace.mRadius, trace.mVelocity.length() * p3);
	}

	mapMgr->mCollCheckCount++;

	trace.mStepFraction = 1.0f / stepMultiplier;

	for (int i = 0; i < stepMultiplier; i++) {
		BoundBox box;
		box.expandBound(trace.mPosition);

		box.mMin.sub(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));
		box.mMax.add(Vector3f(2.0f * trace.mRadius, 4.0f * trace.mRadius, 2.0f * trace.mRadius));
		trace.mObject = target;

		CollGroup* prevColl = nullptr;
		FOREACH_NODE(DynCollShape, mapMgr->mCollShape->mChild, collShape)
		{
			if ((!collShape->mCreature || collShape->mCreature != target) && box.intersects(collShape->mBoundingBox)) {
				for (int i = 0; i < collShape->mColliderCount; i++) {
					if (collShape->mVisibleList[collShape->mColliderList[i]->mRoomIndex]) {
						collShape->mColliderList[i]->mShape          = collShape->mShape;
						collShape->mColliderList[i]->mVertexList     = collShape->mVertexList;
						collShape->mColliderList[i]->mSourceCollider = collShape;
						collShape->mColliderList[i]->mNextCollider   = prevColl;
						prevColl                                     = collShape->mColliderList[i];
					}
				}
			}
		}

		CollGroup* coll = mapMgr->mMapShape->getCollTris(trace.mPosition);
		if (coll && coll->mTriCount) {
			coll->mShape          = mapMgr->mMapShape;
			coll->mVertexList     = mapMgr->mMapShape->mVertexList;
			coll->mSourceCollider = nullptr;
			coll->mNextCollider   = prevColl;
			prevColl              = coll;
		}

		if (prevColl) {
			mapMgr->recTraceMove(prevColl, trace, p3);
		} else {
			Vector3f vel(trace.mVelocity);
			vel.multiply(p3 * trace.mStepFraction);
			trace.mPosition.add(vel);
		}
	}
}
