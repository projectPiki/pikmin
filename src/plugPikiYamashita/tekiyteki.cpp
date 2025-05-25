#include "teki.h"

#include "NaviMgr.h"
#include "Stickers.h"
#include "MapCode.h"
#include "TAI/EffectAttack.h"
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
DEFINE_PRINT("tekiyteki")

/*
 * --INFO--
 * Address:	801A2754
 * Size:	0000F8
 */
YTeki::YTeki()
{
}

/*
 * --INFO--
 * Address:	801A28D0
 * Size:	000120
 */
void YTeki::doKill()
{
	BTeki::doKill();
	for (int i = 0; i < 9; i++) {
		if (mPtclGenPtrs[i]) {
			PRINT("KILL PTCL -----------------------------\n");
			mPtclGenPtrs[i]->finish();
		}
	}
}

/*
 * --INFO--
 * Address:	801A29F0
 * Size:	000058
 */
void YTeki::exitCourse()
{
	BTeki::exitCourse();
	for (int i = 0; i < 9; i++) {
		if (mPtclGenPtrs[i]) {
			PRINT("KILL PTCL -----------------------------\n");
			mPtclGenPtrs[i]->forceFinish();
		}
	}
}

/*
 * --INFO--
 * Address:	801A2A48
 * Size:	000080
 */
bool YTeki::isNaviWatch()
{
	bool res   = false;
	Navi* navi = naviMgr->getNavi();
	if (qdist2(getPosition().x, getPosition().z, navi->getPosition().x, navi->getPosition().z) < getParameterF(TPF_VisibleRange)
	    && aiCullable()) {
		res = true;
	}

	return res;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
int YTeki::getMapAttribute()
{
	int attr         = -1;
	CollTriInfo* tri = mapMgr->getCurrTri(getPosition().x, getPosition().z, true);
	if (tri) {
		attr = MapCode::getAttribute(tri);
	}
	return attr;
}

/*
 * --INFO--
 * Address:	801A2AC8
 * Size:	000034
 */
void YTeki::moveTowardPriorityFaceDir(Vector3f& p1, f32 p2)
{
	moveTowardPriorityFaceDir(p1, p2, getParameterF(TPF_TurnVelocity));
}

/*
 * --INFO--
 * Address:	801A2AFC
 * Size:	000150
 */
void YTeki::moveTowardPriorityFaceDir(Vector3f& p1, f32 p2, f32 turnSpeed)
{
	u32 badCompiler[4];

	f32 ySpeed   = mTargetVelocity.y;
	mTargetAngle = NMathF::atan2(p1.x - getPosition().x, p1.z - getPosition().z);
	f32 angSep   = angDist(mTargetAngle, mFaceDirection);
	mFaceDirection += gsys->getFrameTime() * (angSep * turnSpeed);
	mFaceDirection = roundAng(mFaceDirection);
	mRotation.set(0.0f, mFaceDirection, 0.0f);

	f32 angle = 2.0f * (zen::Abs(angSep) / PI);
	if (angle > 1.0f) {
		angle = 1.0f;
	} else {
		p2 *= (1.0f - angle);
	}
	f32 faceDir = mFaceDirection;
	f32 zSpeed  = cosf(faceDir);

	// sigh
	faceDir    = mFaceDirection;
	f32 xSpeed = sinf(faceDir);

	mTargetVelocity.set(xSpeed, 0.0f, zSpeed);
	mTargetVelocity.multiply(p2);
	mTargetVelocity.y = ySpeed;
}

/*
 * --INFO--
 * Address:	801A2C4C
 * Size:	0000FC
 */
bool YTeki::turnToTarget()
{
	Creature* target = getCreaturePointer(0);
	if (target) {
		mTargetAngle = NMathF::atan2(target->getPosition().x - getPosition().x, target->getPosition().z - getPosition().z);
		f32 angSep   = angDist(mTargetAngle, mFaceDirection);
		mFaceDirection += mProps->mCreatureProps.mFaceDirAdjust() * angSep * gsys->getFrameTime() * 10.0f;
		mFaceDirection = roundAng(mFaceDirection);
		mRotation.set(0.0f, mFaceDirection, 0.0f);
		if (angSep < getParameterF(TPF_AttackableAngle) * PI / 180.0f) {
			return true;
		}
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	801A2D48
 * Size:	000114
 */
void YTeki::flyingStay(f32 speed)
{
	f32 seaLevel = getYFromSeaLevel();
	f32 height   = getParameterF(TPF_FlightHeight) - seaLevel;
	f32 limit    = 0.05f * speed;
	if (zen::Abs(height) > limit) {
		height = ((height > 0.0f) ? 1.0f : -1.0f) * limit;
	}

	f32 val   = height * 900.0f;
	f32 fTime = gsys->getFrameTime();
	mTargetVelocity.y += val * fTime * gsys->getFrameTime();

	if (zen::Abs(mTargetVelocity.y) > speed) {
		mTargetVelocity.y = ((mTargetVelocity.y > 0.0f) ? 1.0f : -1.0f) * speed;
	}
	mVelocity = mTargetVelocity;
}

/*
 * --INFO--
 * Address:	801A2E5C
 * Size:	0001A4
 */
void YTeki::killStickToMouthPiki()
{
	Stickers stuckList(this);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck && stuck->isStickToMouth()) {
			stuck->stimulate(InteractKill(this, 0));
			effectMgr->create(EffectMgr::EFF_Piki_HitA, stuck->getPosition(), nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Piki_HitB, stuck->getPosition(), nullptr, nullptr);
			iter.dec();
		}
	}
}

/*
 * --INFO--
 * Address:	801A3000
 * Size:	0000C8
 */
bool YTeki::startNewMotion(int motionIdx)
{
	if (mTekiAnimator->getCurrentMotionIndex() != motionIdx || mTekiAnimator->isFinished()) {
		if (!mTekiAnimator->isFinished()) {
			mTekiAnimator->finishMotion(PaniMotionInfo(-1, this));
		}

		if (mTekiAnimator->isFinishing()) {
			mTekiAnimator->startMotion(PaniMotionInfo(motionIdx, this));
		}
		return false;
	}

	return true;
}
