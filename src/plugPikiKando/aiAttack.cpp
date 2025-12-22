#include "AIConstant.h"
#include "AIPerf.h"
#include "CourseDebug.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "PikiAI.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "teki.h"
#include "zen/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(25)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("aiAttack")

ActAttack::ActAttack(Piki* piki)
    : AndAction(piki)
{
	setName("attack");
	setChildren(CHILD_COUNT,                     //
	            new ActJumpAttack(piki), nullptr //
	);
	mOther.clear();
	mTargetIsPlayer = false;
}

void ActAttack::init(Creature* creature)
{
	if (playerState->inDayEnd()) {
		PRINT("DAY END ATTACK!\n");
		ERROR("day end attack!\n");
		return;
	}

	mPiki->mActionState = 0;
	mPiki->mEmotion     = PikiEmotion::Excited;
	mPiki->getState(); // this is also just like this in the DLL lol

	if (!creature) {
		PRINT("commander is 0 karl gotti!!!!!!!!!!1\n"); // lol
		mPlayerObject   = nullptr;
		_20             = nullptr;
		mTargetIsPlayer = false;
	} else if (creature->mObjType == OBJTYPE_Navi) {
		mPlayerObject   = creature;
		mTargetIsPlayer = true;
		creature        = findTarget();
	} else {
		mPlayerObject   = nullptr;
		_20             = nullptr;
		mTargetIsPlayer = false;
	}

	if (creature) {
		mOther.set(creature);

		AndAction::init(creature);
		if (creature->isTeki() && !playerState->mDemoFlags.isFlag(DEMOFLAG_Unk9) && static_cast<Teki*>(creature)->mTekiType == TEKI_Palm) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk9);
		}
	}

	seMgr->joinBattle();
	mHasLost          = false;
	mIsAttackFinished = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void ActAttack::startLost()
{
	mHasLost          = true;
	mIsAttackFinished = false;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Sagasu2, this), PaniMotionInfo(PIKIANIM_Sagasu2));
}

void ActAttack::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		if (mHasLost) {
			mIsAttackFinished = true;
		}
		break;
	case KEY_PlayEffect:
		if (mPiki->aiCullable() && (AIPerf::optLevel <= 1 || mPiki->mOptUpdateContext.updatable())) {
			Vector3f vec(mPiki->mEffectPos);
			if (mIsCriticalHit) {
				effectMgr->create(EffectMgr::EFF_Piki_BigHit, vec, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_Piki_HitA, vec, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Piki_HitB, vec, nullptr, nullptr);
			}
		}
		break;
	}
}

void ActAttack::resume()
{
	mHasLost = false;
}

void ActAttack::restart()
{
	if (!mOther.isNull()) {
		seMgr->leaveBattle();
		init(mOther.getPtr());
	}
}

bool ActAttack::resumable()
{
	return true;
}

Creature* ActAttack::findTarget()
{
	// yep.
	if (false) {
		Iterator iter(tekiMgr);
		CI_LOOP(iter)
		{
			Creature* teki = *iter;
			if (roughCull(teki, mPiki, 30.0f)) {
				continue;
			}
			// i'm bad at reading the DLL assembly, but it's genuinely something like this
			// (IDA and ghidra both don't try it bc it's inaccessible)
			if (qdist2(teki, mPiki) < 50.0f && teki->isAlive() && teki->isVisible() && !teki->isBuried() && !teki->isFlying()) {
				return teki;
			}
		}
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002C8
 */
Creature* ActAttack::decideTarget()
{
	f32 minDist = 12800.0f;
	Creature* targetList[MAX_PIKI_ON_FIELD];
	Iterator iter(_20);
	int count = 0;
	CI_LOOP(iter)
	{
		if ((*iter)->isAlive() && (*iter)->isVisible()) {
			if (qdist2(*iter, mPiki) < 1.0f) {
				return *iter;
			}
			targetList[count++] = *iter;
		}
	}

	if (count != 0) {
		return targetList[int(gsys->getRand(1.0f)) * count];
	}

	return nullptr;
}

int ActAttack::exec()
{
	if (playerState->inDayEnd()) {
		return ACTOUT_Success;
	}

	if (mHasLost) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		if (mIsAttackFinished) {
			return ACTOUT_Success;
		}

		return ACTOUT_Continue;
	}

	if (mOther.isNull()) {
		Creature* target = findTarget();
		if (target) {
			seMgr->leaveBattle();
			init(target);
			PRINT_KANDO("... found new target!\n");
			return ACTOUT_Continue;
		}

		return ACTOUT_Success;
	}

	if (!mOther.getPtr()->isAlive()) {
		if (mPiki->isStickTo()) {
			mPiki->endStickObject();
		}
		return ACTOUT_Success;
	}

	if (mOther.getPtr()->isPiki()) {
		Piki* targetPiki = static_cast<Piki*>(mOther.getPtr());
		if (!targetPiki->isKinoko() || (targetPiki->isKinoko() && targetPiki->getState() == PIKISTATE_KinokoChange)) {
			mPiki->mEmotion = PikiEmotion::Searching;
			return ACTOUT_Success;
		}
	}

	if (!mPiki->isStickTo() && (mOther.getPtr()->isFlying() || !mOther.getPtr()->isVisible())) {
		PRINT_KANDO("target start flying\n");

		Creature* target = findTarget();
		if (target) {
			init(target);
			PRINT_KANDO("... found new target!\n");
			return ACTOUT_Continue;
		}
		PRINT_KANDO("TARGET LOST !!\n");
		startLost();
		return ACTOUT_Continue;
	}

	int andRet = AndAction::exec();
	if (andRet != ACTOUT_Continue) {
		if (mTargetIsPlayer) {
			Creature* target = findTarget();
			PRINT_KANDO("piki attack : res is %s\n", (andRet == 2) ? "success" : (andRet == 1) ? "failed" : "not");
			if (target && andRet == ACTOUT_Success) {
				seMgr->leaveBattle();
				init(mPlayerObject);
				return ACTOUT_Success;
			}

			PRINT_KANDO("all targets are removed !\n");
			return ACTOUT_Success;
		}

		Creature* target = mOther.getPtr();
		if (AIConstant::_instance->mConstants._C4() == 0) {
			if (target->isAlive()) {
				seMgr->leaveBattle();
				init(target);
				return ACTOUT_Continue;
			}

			PRINT_KANDO("genocide start ?\n"); // lol?
			target = findTarget();
			if (target) {
				seMgr->leaveBattle();
				init(target);
				PRINT_KANDO("... found new target!\n");
				return ACTOUT_Continue;
			}
		}

		PRINT_KANDO("once is done : %x\n", mPiki);
		return ACTOUT_Success;
	}

	return andRet;
}

void ActAttack::cleanup()
{
	mPiki->endClimb();
	seMgr->leaveBattle();
	mPiki->endStickObject();
	mOther.reset();
	mPiki->_519 = false;
}

ActJumpAttack::ActJumpAttack(Piki* piki)
    : Action(piki, true)
{
	mTarget.clear(); // lol
}

void ActJumpAttack::init(Creature* creature)
{
	mPiki->mActionState = 0;
	mPiki->mEmotion     = PikiEmotion::Excited;
	if (creature) {
		mTarget.set(creature);
	}
	mState = 0;
	_2C    = false;
	if (mPiki->isStickTo()) {
		PRINT_KANDO("jump attack : piki sticks to %s\n", mPiki->mStickPart ? mPiki->mStickPart->mCollInfo->mId.mStringID : "?");
		if (mPiki->mStickPart && mPiki->mStickPart->isClimbable()) {
			mPiki->startClimb();
			mState = 6;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Noboru, this), PaniMotionInfo(PIKIANIM_Noboru));
		} else {
			mState         = 5;
			mIsCriticalHit = false;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
		}
		mAttackState = 0;
	} else {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
	}

	mTargetCollider = creature->getNearestCollPart(mPiki->mSRT.t, '*t**');
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
Vector3f ActJumpAttack::getAttackPos()
{
	if (mTargetCollider) {
		return mTargetCollider->mCentre;
	}
	return mTarget.getPtr()->getCentre();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
f32 ActJumpAttack::getAttackSize()
{
	if (mTargetCollider) {
		return mTargetCollider->mRadius;
	}
	return mTarget.getPtr()->getCentreSize();
}

void ActJumpAttack::procStickMsg(Piki* piki, MsgStick* msg)
{
	mState         = 5;
	mIsCriticalHit = false;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	mAttackState       = 0;
	piki->mWantToStick = false;
}

void ActJumpAttack::procBounceMsg(Piki* piki, MsgBounce* msg)
{
	if (mState == 1) {
		mState = 0;
		_2C    = false;
	}
}

void ActJumpAttack::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	// this definitely has inlines somewhere, the control flow is so wacky.

	if (!mTarget.getPtr() || !mTarget.getPtr()->isAlive() || piki->getState() == PIKISTATE_LookAt) {
		return;
	}

	if (mTarget.getPtr()->mObjType == OBJTYPE_Piki && !static_cast<Piki*>(mTarget.getPtr())->isKinoko()) {
		_2C = true;
		return;
	}

	if (msg->mEvent.mCollider != mTarget.getPtr()) {
		return;
	}

	if (mState != 1) {
		return;
	}

	if (piki->isStickTo()) {
		return;
	}

	PRINT_KANDO("JUMP STICK ###\n");

	if (msg->mEvent.mColliderPart == 0) {
		PRINT("ざまし! ta no coll part\n"); // 'alarm clock! ta no coll part'
		return;
	}

	if (msg->mEvent.mColliderPart->isPlatformType()) {
		if (msg->mEvent.mColliderPart->isStickable()) {
			PRINT_KANDO("stick to platform\n");
			piki->startStick(msg->mEvent.mCollider, msg->mEvent.mColliderPart);
		} else {
			if (msg->mEvent.mColliderPart->isClimbable()) {
				PRINT_KANDO("start climb platform\n");
				piki->startStick(msg->mEvent.mCollider, msg->mEvent.mColliderPart);
			} else {
				PRINT_KANDO("stickable nor climbable platform\n");
				return;
			}
		}
	} else {
		if (msg->mEvent.mColliderPart->isCollisionType() || msg->mEvent.mColliderPart->isTubeType()) {
			if (msg->mEvent.mColliderPart->isStickable()) {
				PRINT_KANDO(" stick to 球 or チューブ\n"); // 'stick to ball or tube'
				piki->startStickObject(msg->mEvent.mCollider, msg->mEvent.mColliderPart, -1, 0.0f);
			} else {
				PRINT_KANDO("try to stick to coll-sphere (%s:code %s): いまはくっっつかない\n", // 'it doesn't stick now'
				            msg->mEvent.mColliderPart->mCollInfo->mId.mStringID, msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				return;
			}
		} else {
			PRINT_KANDO("try to stick %s : いみない \n", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID); // 'no point'
			return;
		}
	}

	mState = 5;
	if (msg->mEvent.mColliderPart && msg->mEvent.mColliderPart->mPartType == PART_Platform && msg->mEvent.mColliderPart->isClimbable()) {
		piki->startClimb();
		piki->startMotion(PaniMotionInfo(PIKIANIM_Noboru, this), PaniMotionInfo(PIKIANIM_Noboru));
		mState = 6;
	} else {
		mIsCriticalHit = false;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	}

	mAttackState       = 0;
	piki->mWantToStick = false;

	STACK_PAD_VAR(2);
}

int ActJumpAttack::exec()
{
	Creature* target = mTarget.getPtr();
	if (!target || !target->isVisible() || !target->isAlive()) {
		if (mPiki->isStickTo()) {
			mPiki->endStickObject();
		}
		return ACTOUT_Success;
	}

	if (target->mObjType == OBJTYPE_Piki) {
		Piki* targPiki = static_cast<Piki*>(target);
		if (!targPiki->isKinoko()) {
			return ACTOUT_Success;
		}
	}

	if (mPiki->isStickTo() && mPiki->getStickObject() && !mPiki->getStickObject()->isAlive()) {
		return ACTOUT_Success;
	}

	switch (mState) {
	case 6:
		doClimb();
		break;
	case 2: {
		Vector3f direction = getAttackPos() - mPiki->mSRT.t;
		f32 dist2D         = speedy_sqrtf(direction.x * direction.x + direction.z * direction.z);
		f32 unused         = direction.normalise();
		f32 angle          = angDist(atan2f(direction.x, direction.z), mPiki->mFaceDirection);

		f32 size = getAttackSize() + mPiki->getCentreSize();
		if (dist2D < size) {
			mPiki->setSpeed(0.5f, direction);
			mPiki->mTargetVelocity = mPiki->mTargetVelocity * -1.0f;
			break;
		}

		STACK_PAD_VAR(1);
		if (dist2D > size + 6.0f) {
			mPiki->setSpeed(0.5f, direction);
			break;
		}

		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		if (angle < PI / 10.0f) {
			f32 vertSpeed = 200.0f;
			mPiki->mVelocity.set(100.0f * direction.x, vertSpeed, 100.0f * direction.z);
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_StillJump, this), PaniMotionInfo(PIKIANIM_StillJump));
			mState              = 1;
			mPiki->mWantToStick = true;
			PRINT_KANDO("jump !\n");
			break;
		}

		mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.2f * angle);

	} break;

	case 0: {
		Vector3f direction = getAttackPos() - mPiki->mSRT.t;
		f32 dist2D         = speedy_sqrtf(direction.x * direction.x + direction.z * direction.z);
		f32 dist3D         = direction.normalise();
		f32 angle          = absF(angDist(atan2f(direction.x, direction.z), mPiki->mFaceDirection));
		if ((!_2C || (_2C && mTargetCollider && !mTargetCollider->isStickable())) && angle < PI / 10.0f
		    && dist3D < getAttackSize() + mPiki->getCentreSize() + 10.0f) {
			if (!mPiki->isStickTo()) {
				mIsCriticalHit = false;
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Attack, this), PaniMotionInfo(PIKIANIM_Attack));
				mPiki->playEventSound(target, SE_PIKI_ATTACK_VOICE);
				mAttackState = 0;
				mState       = 4;
				mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			}
		} else if ((!mTargetCollider || mTargetCollider->isStickable()) && _2C && gsys->getRand(1.0f) > 0.9f) {
			mState = 2;
		} else {
			if (dist2D < getAttackSize() + mPiki->getCentreSize() && gsys->getRand(1.0f) > 0.7f) {
				PRINT_KANDO("jump adjust : dist2d = %.1f d = %.1f\n", dist2D, dist3D);
				mState = 2;
			}

			mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.2f * angle);
			mPiki->setSpeed(1.0f, direction);
		}

		if (mPiki->isStickTo() && !mPiki->mGroundTriangle) {
			mState = 5;
			PRINT("start ATTACK(KUTTUKU)!\n");
			mIsCriticalHit = false;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
			mPiki->playEventSound(target, SE_PIKI_ATTACK_VOICE);
			mAttackState = 0;
		}

	} break;

	case 4: {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		if (mPiki->isStickTo() && !mPiki->mGroundTriangle) {
			mState         = 5;
			mIsCriticalHit = false;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
			mPiki->playEventSound(target, SE_PIKI_ATTACK_VOICE);
			mAttackState = 0;
			break;
		}

		if (mAttackState == 1) {
			Vector3f direction = getAttackPos() - mPiki->mSRT.t;
			f32 angle          = angDist(atan2f(direction.x, direction.z), mPiki->mFaceDirection);
			f32 sep            = direction.length();
			f32 dist           = sep - getAttackSize() - mPiki->getCentreSize();
			if (dist < 10.0f && absF(angle) < PI / 4.0f && (target->isBoss() || target->isTeki()) && target->isAlive()
			    && target->isVisible()) {
				f32 damage = mPiki->getAttackPower();
				if (CourseDebug::pikiNoAttack) {
					damage = 0.001f;
				}

				InteractAttack attack(mPiki, nullptr, damage, false);
				if (target->stimulate(attack)) {
					PRINT("ATTACK SUCCESS\n");
					attackHit();
					mAttackState = 2;
					break;
				}
				mIsCriticalHit = true;
				break;
			}

			if (dist < 10.0f && target->mObjType == OBJTYPE_Piki) {
				Piki* targPiki = static_cast<Piki*>(target);
				if (targPiki->isTeki(mPiki) && targPiki->isAlive() && targPiki->isVisible() && !targPiki->isDamaged()) {
					f32 damage = mPiki->getAttackPower();
					if (CourseDebug::pikiNoAttack) {
						damage = 0.001f;
					}

					InteractAttack attack(mPiki, nullptr, damage, false);
					if (target->stimulate(attack)) {
						PRINT("ATTACK SUCCESS\n");
						attackHit();
						mAttackState = 2;
						break;
					}
					mIsCriticalHit = true;
					break;
				}
				break;
			}
			mIsCriticalHit = true;
			break;
		}
		if (mAttackState == 4) {
			return ACTOUT_Success;
		}
	} break;
	case 5: {
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		if (mAttackState == 1) {
			if (mPiki->isStickTo()) {
				Creature* stickObj = mPiki->getStickObject();
				if ((stickObj->isBoss() || stickObj->isTeki()) && stickObj->isAlive() && stickObj->isVisible()) {
					f32 damage = mPiki->getAttackPower();
					if (CourseDebug::pikiNoAttack) {
						damage = 0.001f;
					}

					InteractAttack attack(mPiki, mPiki->getStickPart(), damage, false);
					if (stickObj->stimulate(attack)) {
						PRINT("ATTACK SUCCESS\n");
						if (stickObj->isFlying()) {
							PRINT("飛んでいるやつに攻撃！！！\n"); // 'Attack the flying thing!!!' HAHA
						}

						attackHit();
						mAttackState = 2;
					} else {
						mIsCriticalHit = true;
					}
				}

				if (stickObj->mObjType == OBJTYPE_Piki) {
					Piki* stickPiki = static_cast<Piki*>(stickObj);
					if (stickPiki->isTeki(mPiki) && stickPiki->isAlive() && stickPiki->isVisible()) {
						f32 damage = mPiki->getAttackPower();
						if (CourseDebug::pikiNoAttack) {
							damage = 0.001f;
						}

						InteractAttack attack(mPiki, mPiki->getStickPart(), damage, false);
						if (stickObj->stimulate(attack)) {
							PRINT("ATTACK SUCCESS\n");

							attackHit();
							mAttackState = 2;
						} else {
							mIsCriticalHit = true;
						}
					}
				}
			}
		} else if (mAttackState == 4) {
			return ACTOUT_Success;
		}

		if (!mPiki->isStickTo()) {
			PRINT_KANDO("jump attack : finish stick\n");
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
			mState = 0;
			return ACTOUT_Continue;
		}
	} break;
	}

	return ACTOUT_Continue;
}

void ActJumpAttack::cleanup()
{
	mTarget.reset();
	mPiki->mWantToStick = false;
}

void ActJumpAttack::attackHit()
{
	mPiki->playEventSound(mTarget.getPtr(), 25);
}

void ActJumpAttack::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		mAttackState = 1;
		break;
	case KEY_Action1:
		mAttackState = 0;
		break;
	case KEY_Finished:
		if (mState == 1) {
			mState = 0;
		}
		mAttackState = 4;
		break;
	case KEY_PlayEffect:
		if (mPiki->aiCullable() && (AIPerf::optLevel <= 1 || mPiki->mOptUpdateContext.updatable())) {
			Vector3f vec(mPiki->mEffectPos);
			if (mIsCriticalHit) {
				effectMgr->create(EffectMgr::EFF_Piki_BigHit, vec, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_Piki_HitA, vec, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Piki_HitB, vec, nullptr, nullptr);
			}
		}
		break;
	}
}

void ActJumpAttack::doClimb()
{
	Creature* target = mTarget.getPtr();
	if (target && target->mCollInfo && target->mCollInfo->hasInfo()) {
		CollPart* part = target->mCollInfo->getSphere('cent');
		if (part) {
			Vector3f dir = part->mCentre - mPiki->mSRT.t;
			f32 sep      = dir.length();
			f32 dist     = sep - part->mRadius - mPiki->getCentreSize();
			PRINT_KANDO("  :: climb target distance = %.1f\n", dist);
			if (dist < 5.0f) {
				mState         = 5;
				mIsCriticalHit = false;
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
				mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
				mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
				mAttackState = 0;
				mPiki->endClimb();
				return;
			}
		}
	}

	PRINT_KANDO("climbing ...\n");
	if (!mPiki->mClimbingTri) {
		mState = 0;
		mPiki->endClimb();
		return;
	}

	bool check = true;
	for (int i = 0; i < 3; i++) {
		if (mPiki->mClimbingTri->mEdgePlanes[i].dist(mPiki->mSRT.t) < -2.0f * mPiki->getCentreSize()) {
			PRINT_KANDO("out of tri : dist is %.1f | centre * -2.0f = %.1f\n", mPiki->mClimbingTri->mEdgePlanes[i].dist(mPiki->mSRT.t),
			            -2.0f * mPiki->getCentreSize());
			check = false;
		}
	}

	if (!check) {
		mPiki->endStick();
		mState = 0;
		PRINT_KANDO("finish stick :: out of tri\n");
		return;
	}

	Vector3f normal(0.0f, 1.0f, 0.0f);
	Vector3f sep;
	Vector3f cpNorm(*mPiki->mCollPlatNormal);
	cpNorm.normalise();
	cpNorm = normal - (normal.DP(cpNorm) * cpNorm); // this is completely unused lol.
	sep    = normal;
	sep.normalise();
	sep                    = sep * 20.0f;
	mPiki->mTargetVelocity = sep;
	mPiki->mVelocity       = sep;
}
