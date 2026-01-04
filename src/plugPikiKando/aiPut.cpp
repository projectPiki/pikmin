#include "AIConstant.h"
#include "BombItem.h"
#include "Boss.h"
#include "BuildingItem.h"
#include "DebugLog.h"
#include "Interactions.h"
#include "ItemMgr.h"
#include "KMath.h"
#include "Navi.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "RumbleMgr.h"
#include "teki.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("PickItem") // Nice copy-paste...

/**
 * @todo: Documentation
 */
void ActPutBomb::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (mState == STATE_Wait) {
		Creature* collider = msg->mEvent.mCollider;
		if (collider->mObjType == OBJTYPE_Navi && !piki->isKinoko() && !collider->mStickListHead) {
			rumbleMgr->start(RUMBLE_Unk2, 0, nullptr);
			mTouchedPlayer = true;
			piki->mNavi    = static_cast<Navi*>(collider);
		}
	}
}

/**
 * @todo: Documentation
 */
ActPutBomb::ActPutBomb(Piki* piki)
    : Action(piki, true)
{
	setName("putbomb");
}

/**
 * @todo: Documentation
 */
void ActPutBomb::findTeki()
{
#if defined(VERSION_GPIJ01_01)
// surely the tekiMgr is fine...
#else
#if defined(VERSION_GPIE01_00) || defined(VERSION_GPIE01_01) || defined(VERSION_GPIP01_00)
	if (!tekiMgr)
#else
	if (!tekiMgr || !bossMgr)
#endif
	{
		mTarget = nullptr;
		return;
	}
#endif

	Iterator iterTeki(tekiMgr);
	f32 minDist = C_PIKI_PROP(mPiki).mBombTargetSearchRange();
	mTarget     = nullptr;
	CI_LOOP(iterTeki)
	{
		Creature* teki = *iterTeki;
		if (teki->isVisible() && teki->isAlive() && teki->isOrganic()) {
			f32 dist = qdist2(teki, mPiki);
			if (dist <= minDist) {
				minDist = dist;
				mTarget = teki;
			}
		}
	}

	Iterator iterBoss(bossMgr);
	CI_LOOP(iterBoss)
	{
		Creature* boss = *iterBoss;
		if (boss->isVisible() && boss->isAlive() && boss->isOrganic() && boss->mObjType != OBJTYPE_Mizu) // PLEASE DON'T BOMB THE GEYZERS
		{
			f32 dist = qdist2(boss, mPiki);
			if (dist <= minDist) {
				minDist = dist;
				mTarget = boss;
			}
		}
	}

	Iterator iterWall(itemMgr->getMeltingPotMgr());
	CI_LOOP(iterWall)
	{
		Creature* wall = *iterWall;
		if (wall->isSluice()) {
			BuildingItem* bWall = static_cast<BuildingItem*>(wall);
			if (!bWall->isCompleted()) {
				f32 dist = qdist2(wall, mPiki);
				if (dist <= minDist) {
					minDist = dist;
					mTarget = wall;
				}
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void ActPutBomb::init(Creature* target)
{
	mTouchedPlayer      = false;
	mState              = STATE_Unk5;
	mPiki->mActionState = 0;
	if (AIConstant::_instance->mConstants._124() != 0 && mPiki->isHolding()) {
		findTeki();
		if (mTarget) {
			if (!mTarget->isTeki() && !mTarget->isBoss()) {
				initSet();
			} else {
				mState = STATE_Aim;
				initAim();
			}
		} else {
			mState = STATE_Wait;
			initWait();
		}

		if (mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Pick) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
			mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 18.0f;
			mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 18.0f;
			mPiki->enableMotionBlend();
		}

		return;
	}

	if (!mPiki->isHolding()) {
		return;
	}

	if (mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() == PIKIANIM_Pick) {
		initPut();
		return;
	}

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
	mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 18.0f;
	mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 18.0f;
	initPut();
}

/**
 * @todo: Documentation
 */
void ActPutBomb::initSet()
{
	mState = STATE_Set;
}

/**
 * @todo: Documentation
 */
int ActPutBomb::exeSet()
{
	if (!mPiki->hasBomb()) {
		mPiki->mEmotion = PikiEmotion::Searching;
		return ACTOUT_Fail;
	}

	Vector3f dir          = mTarget->mSRT.t - mPiki->mSRT.t;
	f32 dist              = qdist2(mTarget, mPiki);
	f32 angle             = angDist(atan2f(dir.x, dir.z), mPiki->mFaceDirection);
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.1f * angle);
	if (dist <= C_PIKI_PROP(mPiki).mBombSetDistance() && absF(angle) < PI / 10.0f) {
		warnPikis();
		InteractRelease release(mPiki, 1.0f);
		Creature* held = mPiki->getHoldCreature();
		held->stimulate(release);
		BombItem* bomb = static_cast<BombItem*>(held);
		PRINT("BOMB SET!\n");
		C_SAI(bomb)->start(bomb, BombAI::BOMB_Set);
		return ACTOUT_Success;
	}

	dir.normalise();
	mPiki->setSpeed(0.5f, dir);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActPutBomb::warnPikis()
{
	PRINT("*** WARN PIKIS +++++++++++++++++++++\n");
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki != mPiki) {
			f32 dist = qdist2(piki, mPiki);
			if (dist <= C_PIKI_PROP(mPiki).mBombWarnPikiRange()) {
				piki->stimulate(InteractWarn(mPiki));
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void ActPutBomb::initAim()
{
	PRINT("+++++ INIT AIM\n");
	mState = STATE_Aim;
	warnPikis();
	mAimTimer   = C_PIKI_PROP(mPiki).mBombAimTime();
	mPlaceTimer = 0.0f;
}

/**
 * @todo: Documentation
 */
int ActPutBomb::exeAim()
{
	if (!mTarget->isVisible() || !mTarget->isAlive()) {
		initWait();
		return ACTOUT_Continue;
	}

	Vector3f dirToTarget  = mTarget->mSRT.t - mPiki->mSRT.t;
	f32 distanceToTarget  = qdist2(mTarget, mPiki);
	f32 angleToTarget     = angDist(atan2f(dirToTarget.x, dirToTarget.z), mPiki->mFaceDirection);
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.1f * angleToTarget);

	if (mAimTimer > 0.0f) {
		mAimTimer -= gsys->getFrameTime();
	}

	distanceToTarget -= mTarget->getCentreSize();

	// Check if in valid throwing range
	if (distanceToTarget > C_PIKI_PROP(mPiki).mBombThrowMinDistance() && distanceToTarget < C_PIKI_PROP(mPiki).mBombThrowMaxDistance()) {

		// If aimed correctly and aim timer expired, throw the bomb
		if (absF(angleToTarget) < PI / 10.0f && mAimTimer <= 0.0f) {
			initThrow();
			return ACTOUT_Continue;
		}

		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return ACTOUT_Continue;
	}

	if (absF(dirToTarget.normalise()) <= 0.01f) {
		dirToTarget.set(0.0f, 0.0f, 1.0f);
	}

	// Handle close range placement
	if (distanceToTarget < C_PIKI_PROP(mPiki).mBombThrowMinDistance()) {
		dirToTarget.multiply(-1.0f);

		mPlaceTimer += gsys->getFrameTime();
		if (mPlaceTimer >= C_PIKI_PROP(mPiki).mBombThrowTimeoutTime()) {
			initSet();
			return ACTOUT_Continue;
		}
	} else {
		mPlaceTimer = 0.0f;
	}

	mPiki->setSpeed(0.5f, dirToTarget);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActPutBomb::initWait()
{
	mState = STATE_Wait;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
int ActPutBomb::exeWait()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	findTeki();
	if (mTarget) {
		initAim();
	}
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActPutBomb::initThrow()
{
	mAnimationFinished = false;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Tanemaki, this), PaniMotionInfo(PIKIANIM_Tanemaki));
	mState = STATE_Throw;
}

/**
 * @todo: Documentation
 */
void ActPutBomb::initPut()
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Tanemaki, this), PaniMotionInfo(PIKIANIM_Tanemaki));
	InteractRelease release(mPiki, 1.0f);
	Creature* held = mPiki->getHoldCreature();
	held->stimulate(release);
	f32 horizSpeed = 40.0f;
	f32 vertSpeed  = 200.0f;
	Vector3f vel(horizSpeed * sinf(mPiki->mFaceDirection), vertSpeed, horizSpeed * cosf(mPiki->mFaceDirection));
	held->mVelocity.add(vel);
	MsgUser msg(0);
	BombItem* bomb = static_cast<BombItem*>(held);
	static_cast<SimpleAI*>(bomb->mStateMachine)->procMsg(bomb, &msg);
	mAnimationFinished = false;
	mState             = STATE_Put;
}

/**
 * @todo: Documentation
 */
int ActPutBomb::exeThrow()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (mAnimationFinished) {
		if (mPiki->isHolding()) {
			Vector3f centre = mTarget->getCentre();
			Vector3f vel(mTarget->mVelocity);
			Vector3f catchPos;
			CollPart* beat = nullptr;
			if (mTarget->mCollInfo && mTarget->mCollInfo->hasInfo()) {
				beat = mTarget->mCollInfo->getSphere('beat');
				PRINT("beat found !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			}
			if (!beat) {
				// sir
				CollPart* unused = mTarget->getRandomCollPart('****');
			}
			if (beat) {
				centre = beat->mCentre;
			}

			catchPos          = mPiki->getCatchPos(mPiki->getHoldCreature());
			Vector3f throwVel = getThrowVelocity(catchPos, C_PIKI_PROP(mPiki).mBombThrowSpeed(), centre, vel);
			InteractRelease release(mPiki, 1.0f);
			Creature* held = mPiki->getHoldCreature();
			held->stimulate(release);
			held->mVelocity       = throwVel;
			held->mTargetVelocity = throwVel;
			BombItem* bomb        = static_cast<BombItem*>(held);
			bomb->mCurrAnimId     = 0;
			C_SAI(bomb)->start(bomb, BombAI::BOMB_Unk1);
			bomb->disableFixPos();

			return ACTOUT_Success;
		}

		return ACTOUT_Fail;
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000038
 */
int ActPutBomb::exePut()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mAnimationFinished) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
int ActPutBomb::exec()
{
	if (mTouchedPlayer) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
		mPiki->mFSM->transit(mPiki, PIKISTATE_LookAt);
#else
		if (mPiki->getState() != PIKISTATE_LookAt) {
			mPiki->mFSM->transit(mPiki, PIKISTATE_LookAt);
		}
#endif
		return ACTOUT_Continue;
	}

	if (mState != STATE_Throw && mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Pick) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
		mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 18.0f;
		mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 18.0f;
		mPiki->enableMotionBlend();
	}

	if (mState != STATE_Throw && !mPiki->hasBomb()) {
		mPiki->mEmotion = PikiEmotion::Searching;
		return ACTOUT_Fail;
	}

	switch (mState) {
	case STATE_Set:
		return exeSet();
	case STATE_Aim:
		return exeAim();
	case STATE_Wait:
		return exeWait();
	case STATE_Throw:
		return exeThrow();
	case STATE_Put:
		return exePut();
	}

	return ACTOUT_Success;
}

/**
 * @todo: Documentation
 */
void ActPutBomb::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		break;
	case KEY_Finished:
		if (mState == STATE_Put || mState == STATE_Throw) {
			mAnimationFinished = true;
		}
		break;
	}
}

/**
 * @todo: Documentation
 */
void ActPutBomb::cleanup()
{
}

/**
 * @todo: Documentation
 */
ActPutItem::ActPutItem(Piki* piki)
    : Action(piki, true)
{
	mItem.clear();
}

/**
 * @todo: Documentation
 */
void ActPutItem::findPos()
{
	Creature* closestItem = nullptr;
	f32 minDist           = 200.0f;
	f32 lastDist;
	Iterator iter(itemMgr);
	CI_LOOP(iter)
	{
		Creature* item = *iter;
		Vector3f dir   = item->mSRT.t - mItem.getPtr()->mSRT.t;
		f32 dist       = dir.length();
		lastDist       = dist;
		if (dist <= minDist) {
			closestItem = item;
			minDist     = dist;
		}
	}

	if (closestItem) {
		while (!findAdjacent(closestItem)) {
			f32 minDist = 200.0f;
			Iterator iter(itemMgr);
			closestItem = nullptr;
			CI_LOOP(iter)
			{
				Creature* item = *iter;
				Vector3f dir   = item->mSRT.t - mItem.getPtr()->mSRT.t;
				f32 dist       = dir.length();
				if (dist <= minDist && dist >= lastDist) {
					closestItem = item;
					minDist     = dist;
				}
			}

			if (!closestItem) {
				PRINT("no room to place !\n");
				mItemPosition = mItem.getPtr()->mSRT.t;
				return;
			}
			lastDist = minDist;
		}

	} else {
		mItemPosition = mItem.getPtr()->mSRT.t;
	}
}

/**
 * @todo: Documentation
 */
bool ActPutItem::findAdjacent(Creature* target)
{
	Vector3f pos(mItem.getPtr()->mSRT.t);
	f32 size = (target->getSize() + mItem.getPtr()->getSize()) * 1.3f;
	Vector3f vec;
	for (int i = 0; i < 8; i++) {
		f32 angle = f32(i) * (PI / 4.0f);
		Vector3f offset(sinf(angle), 0.0f, cosf(angle));
		offset     = offset * size;
		vec        = pos + offset;
		bool check = false;
		Iterator iter(itemMgr);
		CI_LOOP(iter)
		{
			Creature* item = *iter;
			Vector3f sep   = item->mSRT.t - vec;
			f32 dist       = sep.length();
			if (dist <= item->getSize() + mItem.getPtr()->getSize()) {
				check = true;
				break;
			}
		}
		if (!check) {
			mItemPosition = vec;
			return true;
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
void ActPutItem::init(Creature* target)
{
	mItem.set(target);
	findPos();
}

/**
 * @todo: Documentation
 */
int ActPutItem::exec()
{
	Vector3f dir = mItemPosition - mPiki->mSRT.t;
	f32 dist     = dir.normalise();

	if (dist <= mItem.getPtr()->getSize()) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		InteractRelease release(mPiki, 1.0f);
		mPiki->getHoldCreature()->stimulate(release);
		PRINT("release GEM ! : dist %f\n", dist);
		return ACTOUT_Success;
	}

	mPiki->setSpeed(0.5f, dir);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActPutItem::cleanup()
{
	mItem.reset();
}
