#include "Kogane.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "Route.h"
#include "MapCode.h"
#include "Collision.h"
#include "ItemMgr.h"
#include "Pellet.h"
#include "MizuItem.h"
#include "PlayerState.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "NsMath.h"
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
DEFINE_PRINT("KoganeAi");

static u32 koganeSE[] = { SE_KOGANE_WALK, SE_KOGANE_DAMAGE };

/*
 * --INFO--
 * Address:	80176104
 * Size:	0001AC
 */
void KoganeAi::createWaterEffect()
{
	effectMgr->create(EffectMgr::EFF_P_Bubbles, mKogane->mPosition, nullptr, nullptr);
	mRippleCallBack->set(mKogane);

	zen::particleGenerator* ptcl14 = effectMgr->create(EffectMgr::EFF_RippleWhite, Vector3f(0.0f, 0.0f, 0.0f), mRippleCallBack, nullptr);
	if (ptcl14) {
		ptcl14->setEmitPosPtr(&mKogane->mPosition);
		ptcl14->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	zen::particleGenerator* ptcl12 = effectMgr->create(EffectMgr::EFF_RippleSurface, Vector3f(0.0f, 0.0f, 0.0f), mRippleCallBack, nullptr);
	if (ptcl12) {
		ptcl12->setEmitPosPtr(&mKogane->mPosition);
		ptcl12->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	zen::particleGenerator* ptcl13 = effectMgr->create(EffectMgr::EFF_RippleBlack, Vector3f(0.0f, 0.0f, 0.0f), mRippleCallBack, nullptr);
	if (ptcl13) {
		ptcl13->setEmitPosPtr(&mKogane->mPosition);
		ptcl13->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	// sigh.
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	801762B0
 * Size:	000038
 */
void KoganeAi::killCallBackEffect(bool p1)
{
	effectMgr->killGenerator(mRippleCallBack, nullptr, p1);
}

/*
 * --INFO--
 * Address:	801762E8
 * Size:	000074
 */
KoganeAi::KoganeAi(Kogane* kogane)
{
	mKogane         = kogane;
	mRippleCallBack = new KoganeGenRippleCallBack();
}

/*
 * --INFO--
 * Address:	8017635C
 * Size:	000110
 */
void KoganeAi::initAI(Kogane* kogane)
{
	mKogane = kogane;
	mKogane->mScale.set(0.0f, 0.0f, 0.0f);
	mKogane->setCurrentState(1);
	mKogane->setNextState(1);
	mKogane->mAnimator.startMotion(PaniMotionInfo(6, this));
	mInWater    = 0;
	mDropCount  = 0;
	mEffectType = EffectMgr::EFF_NULL;
	mAppearTimer
	    = C_KOGANE_PROP(mKogane).mAppearTimeMin()
	    + NsMathF::getRand1(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mAppearTimeMax() - C_KOGANE_PROP(mKogane).mAppearTimeMin()));
}

/*
 * --INFO--
 * Address:	8017646C
 * Size:	00007C
 */
void KoganeAi::animationKeyUpdated(PaniAnimKeyEvent& event)
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

/*
 * --INFO--
 * Address:	801764E8
 * Size:	00005C
 */
void KoganeAi::keyAction0()
{
	if (mKogane->getCurrentState() == 4) {
		createPellet();
		return;
	}
	if (mKogane->getCurrentState() == 2 && mEffectType >= 0) {
		effectMgr->create(mEffectType, mKogane->mPosition, nullptr, nullptr);
	}
}

/*
 * --INFO--
 * Address:	80176544
 * Size:	0000A8
 */
void KoganeAi::keyAction1()
{
	if (mKogane->getCurrentState() == 4) {
		if (mInWater) {
			effectMgr->create(EffectMgr::EFF_P_Bubbles, mKogane->mPosition, nullptr, nullptr);
			rumbleMgr->start(15, 0, mKogane->mPosition);
		} else {
			effectMgr->create(EffectMgr::EFF_CloudOfDust_2, mKogane->mPosition, nullptr, nullptr);
			rumbleMgr->start(15, 0, mKogane->mPosition);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KoganeAi::keyAction2()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KoganeAi::keyAction3()
{
}

/*
 * --INFO--
 * Address:	801765EC
 * Size:	000014
 */
void KoganeAi::keyLoopEnd()
{
	mKogane->addLoopCounter(1);
}

/*
 * --INFO--
 * Address:	80176600
 * Size:	000028
 */
void KoganeAi::keyFinished()
{
	mKogane->setMotionFinish(true);
	if (mKogane->getCurrentState() == 4) {
		mKogane->_3B9 = 0;
	}
}

/*
 * --INFO--
 * Address:	80176628
 * Size:	00003C
 */
void KoganeAi::playSound(int koganeSoundID)
{
	if (mKogane->mSeContext) {
		mKogane->mSeContext->playSound(koganeSE[koganeSoundID]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void KoganeAi::setEveryFrame()
{
	setMapAttribute();
	checkAppearTimeCounter();
}

/*
 * --INFO--
 * Address:	80176664
 * Size:	0000DC
 */
void KoganeAi::setMapAttribute()
{
	int mapAttr = mKogane->getMapAttribute(mKogane->mPosition);
	switch (mapAttr) {
	case ATTR_Unk0:
		mEffectType = EffectMgr::EFF_Kogane_Walk0;
		break;
	case ATTR_Unk1:
		mEffectType = EffectMgr::EFF_Kogane_Walk2;
		break;
	case ATTR_Unk2:
		mEffectType = EffectMgr::EFF_Kogane_Walk1;
		break;
	case ATTR_Unk3:
		mEffectType = EffectMgr::EFF_Kogane_Walk3;
		break;
	case ATTR_Unk4:
		mEffectType = EffectMgr::EFF_Kogane_Walk0;
		break;
	case ATTR_Water:
		if (!mInWater) {
			mInWater    = 1;
			mEffectType = EffectMgr::EFF_NULL;
			createWaterEffect();
		}
		break;
	case ATTR_Unk6:
		mEffectType = EffectMgr::EFF_Kogane_Walk0;
		break;
	}

	if (mapAttr != ATTR_Water) {
		mInWater = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void KoganeAi::checkAppearTimeCounter()
{
	if (mKogane->getCurrentState() != 1) {
		mKogane->addAttackTimer(gsys->getFrameTime());
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void KoganeAi::calcScaleUp()
{
	if (mKogane->mScale.x < C_KOGANE_PROP(mKogane).mModelScale()) {
		mKogane->mScale.x += C_KOGANE_PROP(mKogane).mAppearScaleUpSpeed() * gsys->getFrameTime();
		if (mKogane->mScale.x > C_KOGANE_PROP(mKogane).mModelScale()) {
			mKogane->mScale.x = C_KOGANE_PROP(mKogane).mModelScale();
		}

		mKogane->mScale.y = mKogane->mScale.z = mKogane->mScale.x;
	}
}

/*
 * --INFO--
 * Address:	80176740
 * Size:	0001E8
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
	       + NsMathF::getRand1(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mGoalDistMax() - C_KOGANE_PROP(mKogane).mGoalDistMin())));

	Vector3f targetPos;
	if (NsMathF::getRand1(1.0f) > 0.5f) {
		angle += randGoalAngle;
	} else {
		angle -= randGoalAngle;
	}

	targetPos.set(randGoalDist * sinf(angle) + mKogane->mPosition.x, 0.0f, randGoalDist * cosf(angle) + mKogane->mPosition.z);
	mKogane->setTargetPosition(targetPos);
}

/*
 * --INFO--
 * Address:	80176928
 * Size:	00022C
 */
void KoganeAi::setRouteTargetPosition()
{
	WayPoint* wp = routeMgr->findNearestWayPoint('test', mKogane->mPosition, false);
	Vector3f wayPointPos(wp->mPosition);
	f32 angle = atan2f(wayPointPos.x - mKogane->mPosition.x, wayPointPos.z - mKogane->mPosition.z);

	f32 randGoalAngle
	    = (C_KOGANE_PROP(mKogane).mGoalAngleMin()
	       + NsMathF::getRand(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mGoalAngleMax() - C_KOGANE_PROP(mKogane).mGoalAngleMin())))
	    * (PI / 360.0f);

	f32 randGoalDist
	    = (C_KOGANE_PROP(mKogane).mGoalDistMin()
	       + NsMathF::getRand1(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mGoalDistMax() - C_KOGANE_PROP(mKogane).mGoalDistMin())));

	Vector3f targetPos;
	if (NsMathF::getRand1(1.0f) > 0.5f) {
		angle += randGoalAngle;
	} else {
		angle -= randGoalAngle;
	}

	targetPos.set(randGoalDist * sinf(angle) + mKogane->mPosition.x, 0.0f, randGoalDist * cosf(angle) + mKogane->mPosition.z);
	mKogane->setTargetPosition(targetPos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void KoganeAi::makeTargetRandom()
{
	Vector3f* targetPos        = mKogane->getTargetPosition();
	mKogane->mTargetVelocity.x = targetPos->x - mKogane->mPosition.x;
	mKogane->mTargetVelocity.y = 0.0f;
	mKogane->mTargetVelocity.z = targetPos->z - mKogane->mPosition.z;
	mKogane->mTargetVelocity.normalise();
	mKogane->mTargetVelocity.multiply(C_KOGANE_PROP(mKogane).mMoveSpeed());
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void KoganeAi::makeStopMoving()
{
	mKogane->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mKogane->mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80176B54
 * Size:	0001A8
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

/*
 * --INFO--
 * Address:	80176CFC
 * Size:	0001E0
 */
void KoganeAi::birthItemWater(int numDrops, f32 p2)
{
	u32 badCompiler[2];

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

/*
 * --INFO--
 * Address:	80176EDC
 * Size:	0000C4
 */
void KoganeAi::createPellet()
{
	mDropCount++;

	// glint beetle can drop up to 8 things - same 4 things, repeated.
	if (mDropCount <= 8) {
		int dropTable[4] = { KOGANEDROP_1Pellet, KOGANEDROP_Nectar, KOGANEDROP_Nectar, KOGANEDROP_5Pellet };

		// grab the drop type
		int dropType = dropTable[(mDropCount - 1) % 4];
		switch (dropType) {
		case KOGANEDROP_1Pellet:
			birthItemPellet(0);
			break;
		case KOGANEDROP_5Pellet:
			birthItemPellet(1);
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

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void KoganeAi::resultFlagOn()
{
	if (mKogane->insideAndInSearch()) {
		playerState->mResultFlags.setOn(RESFLAG_Kogane);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KoganeAi::dieTransit()
{
	return (mKogane->getAttackTimer() > mAppearTimer) ? true : false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool KoganeAi::isMotionFinishTransit()
{
	return mKogane->getMotionFinish();
}

/*
 * --INFO--
 * Address:	80176FA0
 * Size:	0003A0
 */
bool KoganeAi::appearTransit()
{
	if (!mKogane->mIsAppear) {
		Iterator iter(naviMgr);
		CI_LOOP(iter)
		{
			Creature* navi = *iter;
			if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
			    && qdist2(navi->mPosition.x, navi->mPosition.z, mKogane->mPosition.x, mKogane->mPosition.z)
			           < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()
			    && NsLibMath<f32>::abs(navi->mPosition.y - mKogane->mPosition.y) < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()) {
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
			    && qdist2(piki->mPosition.x, piki->mPosition.z, mKogane->mPosition.x, mKogane->mPosition.z)
			           < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()
			    && NsLibMath<f32>::abs(piki->mPosition.y - mKogane->mPosition.y) < C_KOGANE_PROP(mKogane).mAppearTriggerRadius()) {
				mKogane->mIsAppear = true;
				break;
			}
		}
	}

	return mKogane->mIsAppear;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
bool KoganeAi::startWalkTransit()
{
	return mKogane->getWalkTimer() > _1C;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
bool KoganeAi::stopWalkTransit()
{
	Vector3f* targetPos = mKogane->getTargetPosition();
	return (qdist2(targetPos->x, targetPos->z, mKogane->mPosition.x, mKogane->mPosition.z) < 10.0f) ? true : false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool KoganeAi::createPelletTransit()
{
	return mKogane->_3B9;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void KoganeAi::initDie(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002CC
 */
void KoganeAi::initAppear(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->setAnimTimer(30.0f);
	mKogane->setWalkTimer(0.0f);
	mKogane->mAnimator.startMotion(PaniMotionInfo(6, this));

	mKogane->mPosition.x += 5.0f * sinf(mKogane->mRotation.y);
	mKogane->mPosition.z += 5.0f * cosf(mKogane->mRotation.y);
	mKogane->setIsOrganic(true);
	mKogane->setShadowNeed(true);
	setNewTargetPosition();
	resultFlagOn();
	effectMgr->create(EffectMgr::EFF_CloudOfDust_2, mKogane->mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00045C
 */
void KoganeAi::initWalkRandom(int nextState, bool isRandomPos)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->setWalkTimer(0.0f);

	if (isRandomPos) {
		mKogane->mAnimator.startMotion(PaniMotionInfo(6, this));
		setNewTargetPosition();
	} else {
		setRouteTargetPosition();
	}

	if (mEffectType >= 0) {
		effectMgr->create(mEffectType, mKogane->mPosition, nullptr, nullptr);
	}

	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
void KoganeAi::initStopWalk(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->setWalkTimer(0.0f);
	mKogane->mAnimator.startMotion(PaniMotionInfo(2, this));
	makeStopMoving();
	_1C = C_KOGANE_PROP(mKogane).mIdleTimeMin()
	    + NsMathF::getRand1(NsLibMath<f32>::abs(C_KOGANE_PROP(mKogane).mIdleTimeMax() - C_KOGANE_PROP(mKogane).mIdleTimeMin()));

	if (mEffectType >= 0) {
		effectMgr->create(mEffectType, mKogane->mPosition, nullptr, nullptr);
	}

	resultFlagOn();
}

/*
 * --INFO--
 * Address:	80177340
 * Size:	0001D4
 */
void KoganeAi::initCreate(int nextState)
{
	mKogane->setNextState(nextState);
	mKogane->setMotionFinish(false);
	mKogane->mAnimator.startMotion(PaniMotionInfo(1, this));

	f32 perpDir = mKogane->mFaceDirection + HALF_PI;
	Vector3f vec1(sinf(mKogane->mFaceDirection), 0.0f, cosf(mKogane->mFaceDirection));
	Vector3f vec2(sinf(perpDir), 0.0f, cosf(perpDir));
	Vector3f vec3 = -vec2;

	zen::particleGenerator* ptcl1 = effectMgr->create(EffectMgr::EFF_Kogane_Hit, mKogane->mPosition, nullptr, nullptr);
	if (ptcl1) {
		ptcl1->setEmitDir(vec1);
	}
	zen::particleGenerator* ptcl2 = effectMgr->create(EffectMgr::EFF_Kogane_SmokeR, mKogane->mPosition, nullptr, nullptr);
	if (ptcl2) {
		ptcl2->setEmitDir(vec2);
	}
	zen::particleGenerator* ptcl3 = effectMgr->create(EffectMgr::EFF_Kogane_SmokeL, mKogane->mPosition, nullptr, nullptr);
	if (ptcl3) {
		ptcl3->setEmitDir(vec3);
	}

	rumbleMgr->start(15, 0, mKogane->mPosition);
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void KoganeAi::dieState()
{
	if (mKogane->mScale.x > 0.0f) {
		mKogane->mScale.x -= C_KOGANE_PROP(mKogane).mDisappearScaleDownSpeed() * gsys->getFrameTime();
		if (mKogane->mScale.x < 0.0f) {
			mKogane->mScale.x = 0.0f;
		}

		mKogane->mScale.y = mKogane->mScale.z = mKogane->mScale.x;
	} else {
		effectMgr->create(EffectMgr::EFF_CloudOfDust_2, mKogane->mPosition, nullptr, nullptr);
		mKogane->doKill();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void KoganeAi::walkRandomState()
{
	mKogane->addWalkTimer(gsys->getFrameTime());
	mKogane->changeDirection(C_KOGANE_PROP(mKogane).mTurnSpeed());
	makeTargetRandom();
	calcScaleUp();
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void KoganeAi::stopWalkState()
{
	mKogane->addWalkTimer(gsys->getFrameTime());
	calcScaleUp();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void KoganeAi::createState()
{
	mKogane->mTargetVelocity.multiply(0.95f);
	calcScaleUp();
}

/*
 * --INFO--
 * Address:	80177514
 * Size:	0008A4
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
