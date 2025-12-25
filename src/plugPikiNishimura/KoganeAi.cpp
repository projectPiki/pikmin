#include "Collision.h"
#include "DebugLog.h"
#include "ItemMgr.h"
#include "Kogane.h"
#include "MapCode.h"
#include "MizuItem.h"
#include "NaviMgr.h"
#include "NsMath.h"
#include "Pellet.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "Route.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("KoganeAi");

static u32 koganeSE[] = { SE_KOGANE_WALK, SE_KOGANE_DAMAGE };

/**
 * @TODO: Documentation
 */
void KoganeAi::createWaterEffect()
{
	effectMgr->create(EffectMgr::EFF_P_Bubbles, mKogane->mSRT.t, nullptr, nullptr);
	mRippleCallBack->set(mKogane);

	zen::particleGenerator* ptcl14 = effectMgr->create(EffectMgr::EFF_RippleWhite, Vector3f(0.0f, 0.0f, 0.0f), mRippleCallBack, nullptr);
	if (ptcl14) {
		ptcl14->setEmitPosPtr(&mKogane->mSRT.t);
		ptcl14->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	zen::particleGenerator* ptcl12 = effectMgr->create(EffectMgr::EFF_RippleSurface, Vector3f(0.0f, 0.0f, 0.0f), mRippleCallBack, nullptr);
	if (ptcl12) {
		ptcl12->setEmitPosPtr(&mKogane->mSRT.t);
		ptcl12->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	zen::particleGenerator* ptcl13 = effectMgr->create(EffectMgr::EFF_RippleBlack, Vector3f(0.0f, 0.0f, 0.0f), mRippleCallBack, nullptr);
	if (ptcl13) {
		ptcl13->setEmitPosPtr(&mKogane->mSRT.t);
		ptcl13->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	// sigh.
	FORCE_DONT_INLINE;
}

/**
 * @TODO: Documentation
 */
void KoganeAi::killCallBackEffect(bool doForceFinish)
{
	effectMgr->kill(mRippleCallBack, nullptr, doForceFinish);
}

/**
 * @TODO: Documentation
 */
KoganeAi::KoganeAi(Kogane* kogane)
{
	mKogane         = kogane;
	mRippleCallBack = new KoganeGenRippleCallBack();
}

/**
 * @TODO: Documentation
 */
void KoganeAi::initAI(Kogane* kogane)
{
	mKogane = kogane;
	mKogane->mSRT.s.set(0.0f, 0.0f, 0.0f);
	mKogane->setCurrentState(1);
	mKogane->setNextState(1);
	mKogane->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
	mInWater     = false;
	mDropCount   = 0;
	mEffectType  = EffectMgr::EFF_NULL;
	mAppearTimer = C_KOGANE_PROP(mKogane).mAppearTimeMin()
	             + NsMathF::getRand(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mAppearTimeMax() - C_KOGANE_PROP(mKogane).mAppearTimeMin()));
}

/**
 * @TODO: Documentation
 */
void KoganeAi::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		keyAction0();
		break;
	case KEY_Action1:
		keyAction1();
		break;
	case KEY_LoopEnd:
		keyLoopEnd();
		break;
	case KEY_Finished:
		keyFinished();
		break;
	case KEY_PlaySound:
		playSound(event.mValue);
		break;
	}
}

/**
 * @TODO: Documentation
 */
void KoganeAi::keyAction0()
{
	if (mKogane->getCurrentState() == 4) {
		createPellet();
		return;
	}
	if (mKogane->getCurrentState() == 2 && mEffectType >= 0) {
		effectMgr->create(mEffectType, mKogane->mSRT.t, nullptr, nullptr);
	}
}

/**
 * @TODO: Documentation
 */
void KoganeAi::keyAction1()
{
	if (mKogane->getCurrentState() == 4) {
		if (mInWater) {
			effectMgr->create(EffectMgr::EFF_P_Bubbles, mKogane->mSRT.t, nullptr, nullptr);
			rumbleMgr->start(RUMBLE_Unk15, 0, mKogane->mSRT.t);
		} else {
			effectMgr->create(EffectMgr::EFF_CloudOfDust_2, mKogane->mSRT.t, nullptr, nullptr);
			rumbleMgr->start(RUMBLE_Unk15, 0, mKogane->mSRT.t);
		}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void KoganeAi::keyAction2()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void KoganeAi::keyAction3()
{
}

/**
 * @TODO: Documentation
 */
void KoganeAi::keyLoopEnd()
{
	mKogane->addLoopCounter(1);
}

/**
 * @TODO: Documentation
 */
void KoganeAi::keyFinished()
{
	mKogane->setMotionFinish(true);
	if (mKogane->getCurrentState() == 4) {
		mKogane->_3B9 = false;
	}
}

/**
 * @TODO: Documentation
 */
void KoganeAi::playSound(int koganeSoundID)
{
	if (mKogane->mSeContext) {
		mKogane->mSeContext->playSound(koganeSE[koganeSoundID]);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void KoganeAi::setEveryFrame()
{
	setMapAttribute();
	checkAppearTimeCounter();
}

/**
 * @TODO: Documentation
 */
void KoganeAi::setMapAttribute()
{
	int mapAttr = mKogane->getMapAttribute(mKogane->mSRT.t);
	switch (mapAttr) {
	case ATTR_Solid:
		mEffectType = EffectMgr::EFF_Kogane_Walk0;
		break;
	case ATTR_Rock:
		mEffectType = EffectMgr::EFF_Kogane_Walk2;
		break;
	case ATTR_Grass:
		mEffectType = EffectMgr::EFF_Kogane_Walk1;
		break;
	case ATTR_Wood:
		mEffectType = EffectMgr::EFF_Kogane_Walk3;
		break;
	case ATTR_Mud:
		mEffectType = EffectMgr::EFF_Kogane_Walk0;
		break;
	case ATTR_Water:
		if (!mInWater) {
			mInWater    = true;
			mEffectType = EffectMgr::EFF_NULL;
			createWaterEffect();
		}
		break;
	case ATTR_Hole:
		mEffectType = EffectMgr::EFF_Kogane_Walk0;
		break;
	}

	if (mapAttr != ATTR_Water) {
		mInWater = false;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void KoganeAi::checkAppearTimeCounter()
{
	if (mKogane->getCurrentState() != 1) {
		mKogane->addAttackTimer(gsys->getFrameTime());
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000068
 */
void KoganeAi::calcScaleUp()
{
	if (mKogane->mSRT.s.x < C_KOGANE_PROP(mKogane).mModelScale()) {
		mKogane->mSRT.s.x += C_KOGANE_PROP(mKogane).mAppearScaleUpSpeed() * gsys->getFrameTime();
		if (mKogane->mSRT.s.x > C_KOGANE_PROP(mKogane).mModelScale()) {
			mKogane->mSRT.s.x = C_KOGANE_PROP(mKogane).mModelScale();
		}

		mKogane->mSRT.s.y = mKogane->mSRT.s.z = mKogane->mSRT.s.x;
	}
}

/**
 * @TODO: Documentation
 */
void KoganeAi::setNewTargetPosition()
{
	f32 angle = mKogane->mFaceDirection;
	f32 randGoalAngle
	    = (C_KOGANE_PROP(mKogane).mGoalAngleMin()
	       + NsMathF::getRand(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mGoalAngleMax() - C_KOGANE_PROP(mKogane).mGoalAngleMin())))
	    * (PI / 360.0f);

	f32 randGoalDist
	    = (C_KOGANE_PROP(mKogane).mGoalDistMin()
	       + NsMathF::getRand(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mGoalDistMax() - C_KOGANE_PROP(mKogane).mGoalDistMin())));

	Vector3f targetPos;
	if (NsMathF::getRand(1.0f) > 0.5f) {
		angle += randGoalAngle;
	} else {
		angle -= randGoalAngle;
	}

	targetPos.set(randGoalDist * sinf(angle) + mKogane->mSRT.t.x, 0.0f, randGoalDist * cosf(angle) + mKogane->mSRT.t.z);
	mKogane->setTargetPosition(targetPos);
}

/**
 * @TODO: Documentation
 */
void KoganeAi::setRouteTargetPosition()
{
	WayPoint* wp = routeMgr->findNearestWayPoint('test', mKogane->mSRT.t, false);
	Vector3f wayPointPos(wp->mPosition);
	f32 angle = atan2f(wayPointPos.x - mKogane->mSRT.t.x, wayPointPos.z - mKogane->mSRT.t.z);

	f32 randGoalAngle
	    = (C_KOGANE_PROP(mKogane).mGoalAngleMin()
	       + NsMathF::getRand(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mGoalAngleMax() - C_KOGANE_PROP(mKogane).mGoalAngleMin())))
	    * (PI / 360.0f);

	f32 randGoalDist
	    = (C_KOGANE_PROP(mKogane).mGoalDistMin()
	       + NsMathF::getRand(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mGoalDistMax() - C_KOGANE_PROP(mKogane).mGoalDistMin())));

	Vector3f targetPos;
	if (NsMathF::getRand(1.0f) > 0.5f) {
		angle += randGoalAngle;
	} else {
		angle -= randGoalAngle;
	}

	targetPos.set(randGoalDist * sinf(angle) + mKogane->mSRT.t.x, 0.0f, randGoalDist * cosf(angle) + mKogane->mSRT.t.z);
	mKogane->setTargetPosition(targetPos);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
void KoganeAi::makeTargetRandom()
{
	Vector3f* targetPos        = mKogane->getTargetPosition();
	mKogane->mTargetVelocity.x = targetPos->x - mKogane->mSRT.t.x;
	mKogane->mTargetVelocity.y = 0.0f;
	mKogane->mTargetVelocity.z = targetPos->z - mKogane->mSRT.t.z;
	mKogane->mTargetVelocity.normalise();
	mKogane->mTargetVelocity.multiply(C_KOGANE_PROP(mKogane).mMoveSpeed());
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void KoganeAi::makeStopMoving()
{
	mKogane->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mKogane->mVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
void KoganeAi::birthItemPellet(int size)
{
	f32 xOffs         = -sinf(mKogane->mFaceDirection);
	f32 zOffs         = -cosf(mKogane->mFaceDirection);
	Vector3f* partPos = &mKogane->mCollInfo->getSphere('cent')->mCentre;
	Vector3f pelletPos(*partPos);
	pelletPos.x += 20.0f * xOffs;
	pelletPos.y += 20.0f;
	pelletPos.z += 20.0f * zOffs;

	int itemColour = mKogane->getItemColour();
	if (itemColour < PELCOLOR_MIN || itemColour > PELCOLOUR_MAX) {
		itemColour = NsMathI::getRand(3);
	}

	Pellet* numPellet = pelletMgr->newNumberPellet(itemColour, size);
	if (numPellet) {
		numPellet->init(pelletPos);
		numPellet->mVelocity.set(100.0f * xOffs, 300.0f, 100.0f * zOffs);
		numPellet->mFaceDirection = mKogane->mFaceDirection;
		numPellet->startAI(0);
		playSound(KOGANESOUND_Damage);
	}
}

/**
 * @TODO: Documentation
 */
void KoganeAi::birthItemWater(int numDrops, f32 p2)
{
	STACK_PAD_VAR(2);

	f32 initAngle;
	f32 angleOffset;
	if (numDrops == 1) {
		angleOffset = 0.0f;
		initAngle   = mKogane->mFaceDirection;
	} else if (numDrops > 1) {
		initAngle   = mKogane->mFaceDirection - (PI * p2 * 0.5f);
		angleOffset = PI * p2 / (numDrops - 1);
	}

	if (numDrops > 0) {
		for (int i = 0; i < numDrops; i++) {
			f32 angle         = i * angleOffset + initAngle;
			f32 xOffs         = -sinf(angle);
			f32 zOffs         = -cosf(angle);
			Vector3f* partPos = &mKogane->mCollInfo->getSphere('cent')->mCentre;
			Vector3f dropPos(*partPos);
			dropPos.x += 20.0f * xOffs;
			dropPos.y += 20.0f;
			dropPos.z += 20.0f * zOffs;

			MizuItem* drop = static_cast<MizuItem*>(itemMgr->birth(OBJTYPE_FallWater));
			if (drop) {
				drop->init(dropPos);
				drop->mVelocity.set(50.0f * xOffs, 200.0f, 50.0f * zOffs);
				drop->startAI(0);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void KoganeAi::createPellet()
{
	mDropCount++;

	// flint beetle can drop up to 8 things - same 4 things, repeated.
	if (mDropCount <= 8) {
		int dropTable[4] = { KOGANEDROP_1Pellet, KOGANEDROP_Nectar, KOGANEDROP_Nectar, KOGANEDROP_5Pellet };

		// grab the drop type
		int dropType = dropTable[(mDropCount - 1) % 4];
		switch (dropType) {
		case KOGANEDROP_1Pellet:
			birthItemPellet(NUMPEL_OnePellet);
			break;
		case KOGANEDROP_5Pellet:
			birthItemPellet(NUMPEL_FivePellet);
			break;
		case KOGANEDROP_Nectar:
			birthItemWater(2, 0.4f);
			break;
		default:
			PRINT(" No Such Type Item \n");
			break;
		}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void KoganeAi::resultFlagOn()
{
	if (mKogane->insideAndInSearch()) {
		playerState->mResultFlags.setOn(RESFLAG_Kogane);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
bool KoganeAi::dieTransit()
{
	return (mKogane->getAttackTimer() > mAppearTimer) ? true : false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
bool KoganeAi::isMotionFinishTransit()
{
	return mKogane->getMotionFinish();
}

/**
 * @TODO: Documentation
 */
bool KoganeAi::appearTransit()
{
	if (!mKogane->mIsAppear) {
		Iterator iter(naviMgr);
		CI_LOOP(iter)
		{
			Creature* navi = *iter;
			if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
			    && qdist2(navi->mSRT.t.x, navi->mSRT.t.z, mKogane->mSRT.t.x, mKogane->mSRT.t.z)
			           < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()
			    && NsLibMath<f32>::abs(navi->mSRT.t.y - mKogane->mSRT.t.y) < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()) {
				mKogane->mIsAppear = true;
				break;
			}
		}
	}

	if (!mKogane->mIsAppear) {
		Iterator iter(pikiMgr);
		CI_LOOP(iter)
		{
			Creature* piki = *iter;
			if (piki->isAlive() && piki->isVisible() && !piki->isBuried()
			    && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, mKogane->mSRT.t.x, mKogane->mSRT.t.z)
			           < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()
			    && NsLibMath<f32>::abs(piki->mSRT.t.y - mKogane->mSRT.t.y) < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()) {
				mKogane->mIsAppear = true;
				break;
			}
		}
	}

	return mKogane->mIsAppear;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
bool KoganeAi::startWalkTransit()
{
	return mKogane->getWalkTimer() > _1C;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
bool KoganeAi::stopWalkTransit()
{
	Vector3f* targetPos = mKogane->getTargetPosition();
	return (qdist2(targetPos->x, targetPos->z, mKogane->mSRT.t.x, mKogane->mSRT.t.z) < 10.0f) ? true : false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
bool KoganeAi::changeTargetTransit()
{
	if (mKogane->getWalkTimer() > C_KOGANE_PROP(mKogane).mMaxSingleRunTime()) {
		return true;
	}
	if (mKogane->getOnWall()) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
bool KoganeAi::createPelletTransit()
{
	return mKogane->_3B9;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
void KoganeAi::initDie(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	resultFlagOn();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0002CC
 */
void KoganeAi::initAppear(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->setAnimTimer(30.0f);
	mKogane->setWalkTimer(0.0f);
	mKogane->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));

	mKogane->mSRT.t.x += 5.0f * sinf(mKogane->mSRT.r.y);
	mKogane->mSRT.t.z += 5.0f * cosf(mKogane->mSRT.r.y);
	mKogane->setIsOrganic(true);
	mKogane->setShadowNeed(true);
	setNewTargetPosition();
	resultFlagOn();
	effectMgr->create(EffectMgr::EFF_CloudOfDust_2, mKogane->mSRT.t, nullptr, nullptr);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00045C
 */
void KoganeAi::initWalkRandom(int nextState, bool isRandomPos)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->setWalkTimer(0.0f);

	if (isRandomPos) {
		mKogane->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
		setNewTargetPosition();
	} else {
		setRouteTargetPosition();
	}

	if (mEffectType >= 0) {
		effectMgr->create(mEffectType, mKogane->mSRT.t, nullptr, nullptr);
	}

	resultFlagOn();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000164
 */
void KoganeAi::initStopWalk(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->setWalkTimer(0.0f);
	mKogane->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	makeStopMoving();
	_1C = C_KOGANE_PROP(mKogane).mIdleTimeMin()
	    + NsMathF::getRand(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mIdleTimeMax() - C_KOGANE_PROP(mKogane).mIdleTimeMin()));

	if (mEffectType >= 0) {
		effectMgr->create(mEffectType, mKogane->mSRT.t, nullptr, nullptr);
	}

	resultFlagOn();
}

/**
 * @TODO: Documentation
 */
void KoganeAi::initCreate(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Damage, this));

	f32 perpDir = mKogane->mFaceDirection + HALF_PI;
	Vector3f vec1(sinf(mKogane->mFaceDirection), 0.0f, cosf(mKogane->mFaceDirection));
	Vector3f vec2(sinf(perpDir), 0.0f, cosf(perpDir));
	Vector3f vec3 = -vec2;

	zen::particleGenerator* ptcl1 = effectMgr->create(EffectMgr::EFF_Kogane_Hit, mKogane->mSRT.t, nullptr, nullptr);
	if (ptcl1) {
		ptcl1->setEmitDir(vec1);
	}
	zen::particleGenerator* ptcl2 = effectMgr->create(EffectMgr::EFF_Kogane_SmokeR, mKogane->mSRT.t, nullptr, nullptr);
	if (ptcl2) {
		ptcl2->setEmitDir(vec2);
	}
	zen::particleGenerator* ptcl3 = effectMgr->create(EffectMgr::EFF_Kogane_SmokeL, mKogane->mSRT.t, nullptr, nullptr);
	if (ptcl3) {
		ptcl3->setEmitDir(vec3);
	}

	rumbleMgr->start(RUMBLE_Unk15, 0, mKogane->mSRT.t);
	resultFlagOn();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B4
 */
void KoganeAi::dieState()
{
	if (mKogane->mSRT.s.x > 0.0f) {
		mKogane->mSRT.s.x -= C_KOGANE_PROP(mKogane).mDisappearScaleDownSpeed() * gsys->getFrameTime();
		if (mKogane->mSRT.s.x < 0.0f) {
			mKogane->mSRT.s.x = 0.0f;
		}

		mKogane->mSRT.s.y = mKogane->mSRT.s.z = mKogane->mSRT.s.x;
	} else {
		effectMgr->create(EffectMgr::EFF_CloudOfDust_2, mKogane->mSRT.t, nullptr, nullptr);
		mKogane->doKill();
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000180
 */
void KoganeAi::walkRandomState()
{
	mKogane->addWalkTimer(gsys->getFrameTime());
	mKogane->changeDirection(C_KOGANE_PROP(mKogane).mTurnSpeed());
	makeTargetRandom();
	calcScaleUp();
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
void KoganeAi::stopWalkState()
{
	mKogane->addWalkTimer(gsys->getFrameTime());
	calcScaleUp();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094
 */
void KoganeAi::createState()
{
	mKogane->mTargetVelocity.multiply(0.95f);
	calcScaleUp();
}

/**
 * @TODO: Documentation
 */
void KoganeAi::update()
{
	setEveryFrame();
	switch (mKogane->getCurrentState()) {
	case 0:
		dieState();
		break;
	case 1:
		if (appearTransit()) {
			initAppear(2);
		}
		break;
	case 2:
		walkRandomState();
		if (dieTransit()) {
			initDie(0);
		} else if (createPelletTransit()) {
			initCreate(4);
		} else if (stopWalkTransit()) {
			initStopWalk(3);
		} else if (changeTargetTransit()) {
			initWalkRandom(2, false);
		}
		break;
	case 3:
		stopWalkState();
		if (dieTransit()) {
			initDie(0);
		} else if (createPelletTransit()) {
			initCreate(4);
		} else if (startWalkTransit()) {
			initWalkRandom(2, true);
		}
		break;
	case 4:
		createState();
		if (isMotionFinishTransit()) {
			initWalkRandom(2, true);
		}
		break;
	}
}
