#include "PikiAI.h"
#include "PikiState.h"
#include "AIConstant.h"
#include "Navi.h"
#include "RumbleMgr.h"
#include "teki.h"
#include "Interactions.h"
#include "BombItem.h"
#include "Boss.h"
#include "KMath.h"
#include "ItemMgr.h"
#include "zen/Math.h"
#include "BuildingItem.h"
#include "PikiMgr.h"
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
DEFINE_PRINT("PickItem")

/*
 * --INFO--
 * Address:	800BE9F4
 * Size:	0000A0
 */
void ActPutBomb::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (mState == STATE_Wait) {
		Creature* collider = msg->mEvent.mCollider;
		if (collider->mObjType == OBJTYPE_Navi && !piki->isKinoko() && !collider->mStickListHead) {
			rumbleMgr->start(RUMBLE_Unk2, 0, nullptr);
			mTouchedPlayer = 1;
			piki->mNavi    = static_cast<Navi*>(collider);
		}
	}
}

/*
 * --INFO--
 * Address:	800BEA94
 * Size:	000088
 */
ActPutBomb::ActPutBomb(Piki* piki)
    : Action(piki, true)
{
	setName("putbomb");
}

/*
 * --INFO--
 * Address:	800BEB1C
 * Size:	00048C
 */
void ActPutBomb::findTeki()
{
	if (!tekiMgr) {
		mTarget = nullptr;
		return;
	}

	Iterator iterTeki(tekiMgr);
	f32 minDist = C_PIKI_PROP(mPiki).mBombTargetSearchRadius();
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

/*
 * --INFO--
 * Address:	800BEFA8
 * Size:	0001C0
 */
void ActPutBomb::init(Creature* target)
{
	mTouchedPlayer      = 0;
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

/*
 * --INFO--
 * Address:	800BF168
 * Size:	00000C
 */
void ActPutBomb::initSet()
{
	mState = STATE_Set;
}

/*
 * --INFO--
 * Address:	800BF174
 * Size:	0001D8
 */
int ActPutBomb::exeSet()
{
	if (!mPiki->hasBomb()) {
		mPiki->mEmotion = PikiEmotion::Unk7;
		return ACTOUT_Fail;
	}

	Vector3f dir          = mTarget->mPosition - mPiki->mPosition;
	f32 dist              = qdist2(mTarget, mPiki);
	f32 angle             = angDist(atan2f(dir.x, dir.z), mPiki->mFaceDirection);
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.1f * angle);
	if (dist <= C_PIKI_PROP(mPiki)._51C() && absF(angle) < PI / 10.0f) {
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

/*
 * --INFO--
 * Address:	800BF34C
 * Size:	000164
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
			if (dist <= C_PIKI_PROP(mPiki)._4FC()) {
				piki->stimulate(InteractWarn(mPiki));
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800BF4B0
 * Size:	00016C
 */
void ActPutBomb::initAim()
{
	PRINT("+++++ INIT AIM\n");
	mState = STATE_Aim;
	warnPikis();
	mAimTimer   = C_PIKI_PROP(mPiki)._50C();
	mPlaceTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	800BF61C
 * Size:	0002CC
 */
int ActPutBomb::exeAim()
{
	if (!mTarget->isVisible() || !mTarget->isAlive()) {
		initWait();
		return ACTOUT_Continue;
	}

	Vector3f dirToTarget  = mTarget->mPosition - mPiki->mPosition;
	f32 distanceToTarget  = qdist2(mTarget, mPiki);
	f32 angleToTarget     = angDist(atan2f(dirToTarget.x, dirToTarget.z), mPiki->mFaceDirection);
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.1f * angleToTarget);

	if (mAimTimer > 0.0f) {
		mAimTimer -= gsys->getFrameTime();
	}

	distanceToTarget -= mTarget->getCentreSize();

	// Check if in valid throwing range
	if (distanceToTarget > C_PIKI_PROP(mPiki).mBombPlaceMinDistance() && distanceToTarget < C_PIKI_PROP(mPiki).mBombThrowMaxDistance()) {

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
	if (distanceToTarget < C_PIKI_PROP(mPiki).mBombPlaceMinDistance()) {
		dirToTarget.multiply(-1.0f);

		mPlaceTimer += gsys->getFrameTime();
		if (mPlaceTimer >= C_PIKI_PROP(mPiki).mBombPlaceDuration()) {
			initSet();
			return ACTOUT_Continue;
		}
	} else {
		mPlaceTimer = 0.0f;
	}

	mPiki->setSpeed(0.5f, dirToTarget);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800BF8E8
 * Size:	00000C
 */
void ActPutBomb::initWait()
{
	mState = STATE_Wait;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
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

/*
 * --INFO--
 * Address:	800BF8F4
 * Size:	000084
 */
void ActPutBomb::initThrow()
{
	mAnimationFinished = 0;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Tanemaki, this), PaniMotionInfo(PIKIANIM_Tanemaki));
	mState = STATE_Throw;
}

/*
 * --INFO--
 * Address:	800BF978
 * Size:	00014C
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
	mAnimationFinished = 0;
	mState             = STATE_Put;
}

/*
 * --INFO--
 * Address:	800BFAC4
 * Size:	00023C
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
			Vector3f throwVel = getThrowVelocity(catchPos, C_PIKI_PROP(mPiki)._4EC(), centre, vel);
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

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
int ActPutBomb::exePut()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mAnimationFinished) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800BFD00
 * Size:	000210
 */
int ActPutBomb::exec()
{
	if (mTouchedPlayer) {
		if (mPiki->getState() != PIKISTATE_LookAt) {
			mPiki->mFSM->transit(mPiki, PIKISTATE_LookAt);
		}
		return ACTOUT_Continue;
	}

	if (mState != STATE_Throw && mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Pick) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
		mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 18.0f;
		mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 18.0f;
		mPiki->enableMotionBlend();
	}

	if (mState != STATE_Throw && !mPiki->hasBomb()) {
		mPiki->mEmotion = PikiEmotion::Unk7;
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

/*
 * --INFO--
 * Address:	800BFF10
 * Size:	000038
 */
void ActPutBomb::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		break;
	case KEY_Finished:
		if (mState == STATE_Put || mState == STATE_Throw) {
			mAnimationFinished = 1;
		}
	}
}

/*
 * --INFO--
 * Address:	800BFF48
 * Size:	000004
 */
void ActPutBomb::cleanup()
{
}

/*
 * --INFO--
 * Address:	800BFF4C
 * Size:	00005C
 */
ActPutItem::ActPutItem(Piki* piki)
    : Action(piki, true)
{
	mItem.clear();
}

/*
 * --INFO--
 * Address:	800BFFA8
 * Size:	00040C
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
		Vector3f dir   = item->mPosition - mItem.getPtr()->mPosition;
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
				Vector3f dir   = item->mPosition - mItem.getPtr()->mPosition;
				f32 dist       = dir.length();
				if (dist <= minDist && dist >= lastDist) {
					closestItem = item;
					minDist     = dist;
				}
			}

			if (!closestItem) {
				PRINT("no room to place !\n");
				mItemPosition = mItem.getPtr()->mPosition;
				return;
			}
			lastDist = minDist;
		}

	} else {
		mItemPosition = mItem.getPtr()->mPosition;
	}
}

/*
 * --INFO--
 * Address:	800C03B4
 * Size:	000340
 */
bool ActPutItem::findAdjacent(Creature* target)
{
	Vector3f pos(mItem.getPtr()->mPosition);
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
			Vector3f sep   = item->mPosition - vec;
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

/*
 * --INFO--
 * Address:	800C06F4
 * Size:	00006C
 */
void ActPutItem::init(Creature* target)
{
	mItem.set(target);
	findPos();
}

/*
 * --INFO--
 * Address:	800C0760
 * Size:	000178
 */
int ActPutItem::exec()
{
	Vector3f dir = mItemPosition - mPiki->mPosition;
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

/*
 * --INFO--
 * Address:	800C08D8
 * Size:	000040
 */
void ActPutItem::cleanup()
{
	mItem.reset();
}
