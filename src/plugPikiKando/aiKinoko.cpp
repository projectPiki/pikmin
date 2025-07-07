#include "DebugLog.h"
#include "Interactions.h"
#include "Navi.h"
#include "NaviMgr.h"
#include "PikiAI.h"
#include "SoundMgr.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(22)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("aiKinoko")

/*
 * --INFO--
 * Address:	800B4570
 * Size:	0000A4
 */
ActKinoko::ActKinoko(Piki* piki)
    : Action(piki, true)
{
	mName = "kinoko";
	mTarget.clear();
}

/*
 * --INFO--
 * Address:	800B4614
 * Size:	000080
 */
void ActKinoko::init(Creature* creature)
{
	mPiki->mActionState = 0;
	if (creature) {
		mTarget.set(creature);
	}

	mState = STATE_Boid;
}

/*
 * --INFO--
 * Address:	800B4694
 * Size:	00006C
 */
int ActKinoko::exec()
{
	switch (mState) {
	case STATE_Boid:
		return exeBoid();
	case STATE_Attack:
		return exeAttack();
	case STATE_Jump:
		return exeJump();
	case STATE_Stick:
		return exeStick();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ActKinoko::initStick()
{
	mState = STATE_Stick;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
}

/*
 * --INFO--
 * Address:	800B4700
 * Size:	000080
 */
int ActKinoko::exeStick()
{
	if (!mPiki->mStickTarget) {
		initAttack();
		return ACTOUT_Continue;
	}

	if (!mPiki->mNavi->isAlive()) {
		mPiki->endStickObject();
		initBoid();
		return ACTOUT_Continue;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void ActKinoko::initJump()
{
	mState         = STATE_Jump;
	f32 vertSpeed  = 170.0f;
	f32 horizSpeed = 50.0f;
	Vector3f vel(horizSpeed * sinf(mPiki->mFaceDirection), vertSpeed, horizSpeed * cosf(mPiki->mFaceDirection));
	mPiki->mVelocity       = vel;
	mPiki->mTargetVelocity = vel;
}

/*
 * --INFO--
 * Address:	800B4780
 * Size:	000128
 */
int ActKinoko::exeJump()
{
	if (mPiki->mGroundTriangle) {
		initAttack();
		return ACTOUT_Continue;
	}

	Vector3f sep = mPiki->mNavi->mPosition - mPiki->mPosition;
	f32 dist     = sep.normalise();
	if (dist < 12.0f) {
		mPiki->startStickObject(mPiki->mNavi, mPiki->mNavi->mCollInfo->getSphere('head'), -1, 0.0f);
		initStick();
		return ACTOUT_Continue;
	}
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B48A8
 * Size:	00000C
 */
void ActKinoko::initAttack()
{
	mState = STATE_Attack;
}

/*
 * --INFO--
 * Address:	800B48B4
 * Size:	0001C0
 */
int ActKinoko::exeAttack()
{
	Creature* target = mTarget.getPtr();
	if (!target || !target->isAlive()) {
		return ACTOUT_Fail;
	}

	f32 dist = qdist2(target, mPiki);
	if (dist > 500.0f) {
		initBoid();
		return ACTOUT_Continue;
	}

	Vector3f sep = mPiki->mNavi->mPosition - mPiki->mPosition;
	dist         = sep.normalise();
	if (dist < 25.0f) {
		initJump();
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(1.0f, sep);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B4A74
 * Size:	000288
 */
void ActKinoko::initBoid()
{
	mState           = STATE_Boid;
	Creature* target = mTarget.getPtr();
	if (!target) {
		return;
	}

	mStateTimer  = 2.0f * gsys->getRand(1.0f) + 1.5f;
	Vector3f sep = target->mPosition - mPiki->mPosition;
	f32 dist     = sep.normalise();
	Vector3f orthoDir(sep.z, 0.0f, -sep.x);
	if (gsys->getRand(1.0f) > 0.5f) {
		orthoDir.multiply(-1.0f);
	}

	orthoDir = orthoDir + (0.2f * (gsys->getRand(1.0f) - 0.5f)) * sep;
	orthoDir.normalise();
	mTargetDirection = orthoDir;

	mPiki->playEventSound(target, SE_KINOKOPIKI_DANCE);
}

/*
 * --INFO--
 * Address:	800B4CFC
 * Size:	00085C
 */
int ActKinoko::exeBoid()
{
	Creature* target = mTarget.getPtr();
	if (!target || !target->isAlive()) {
		return ACTOUT_Fail;
	}

	if (qdist2(mPiki->mNavi->mPosition.x, mPiki->mNavi->mPosition.z, mPiki->mPosition.x, mPiki->mPosition.z) < 120.0f) {
		initAttack();
		return ACTOUT_Continue;
	}

	mStateTimer -= gsys->getFrameTime();
	if (mStateTimer < 0.0f) {
		initBoid();
	}

	Iterator iter(&mPiki->mSearchBuffer);
	int boidCount = 0;
	Vector3f boidPos(0.0f, 0.0f, 0.0f);
	Vector3f boidVel(0.0f, 0.0f, 0.0f);
	Vector3f closestPartnerDir(0.0f, 0.0f, 0.0f);
	bool isClosePartner = false;
	f32 minDist         = 50.0f;

	CI_LOOP(iter)
	{
		Creature* obj = *iter;
		if (obj->mObjType == OBJTYPE_Piki) {
			Piki* piki = static_cast<Piki*>(obj);
			if (piki != mPiki && piki->isKinoko()) {
				f32 dist = qdist2(piki->mPosition.x, piki->mPosition.z, mPiki->mPosition.x, mPiki->mPosition.z);
				if (dist < minDist) {
					minDist           = dist;
					closestPartnerDir = mPiki->mPosition - piki->mPosition;
					isClosePartner    = true;
				}

				boidPos = boidPos + piki->mPosition;
				boidVel = boidVel + piki->mVelocity;
				boidCount++;
			}
		}
	}

	if (boidCount > 0) {
		closestPartnerDir.normalise();
		boidPos.multiply(1.0f / f32(boidCount));
		boidVel.multiply(1.0f / f32(boidCount));
		boidVel.normalise();
		Vector3f boidDir = boidPos - mPiki->mPosition;
		Vector3f offset(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
		boidDir.normalise();
		Vector3f moveDir;
		if (isClosePartner) {
			moveDir = offset * 0.01f + closestPartnerDir * 0.99f;
		} else {
			moveDir = offset * 0.4f + boidDir * 0.5f + mTargetDirection * 0.1f;
		}

		moveDir.normalise();
		mPiki->setSpeed(0.3f, moveDir);

	} else {
		mPiki->setSpeed(0.3f, mTargetDirection);
	}

	Vector3f newMoveDir = target->mPosition - mPiki->mPosition;
	f32 len             = 100.0f;
	if (!(newMoveDir.normalise() < len)) {
		mPiki->setSpeed(0.5f, newMoveDir);
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B5558
 * Size:	000098
 */
void ActKinoko::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		if (mState == STATE_Stick) {
			Navi* navi = naviMgr->getNavi();
			if (!navi) {
				ERROR("kinoko no navi!\n");
			}
			PRINT("navi=%x", navi);
			InteractSuck suck(mPiki, 0.5f);
			if (navi->stimulate(suck)) {
				SeSystem::playPlayerSe(SE_KINOKOPIKI_ATTACK);
			}
		}
		break;
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800B55F0
 * Size:	000004
 */
void ActKinoko::cleanup()
{
}
