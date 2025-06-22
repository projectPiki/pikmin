#include "PikiAI.h"
#include "PlayerState.h"
#include "teki.h"
#include "SoundMgr.h"
#include "AIPerf.h"
#include "EffectMgr.h"
#include "PikiState.h"
#include "AIConstant.h"
#include "sysNew.h"
#include "zen/Math.h"
#include "CourseDebug.h"
#include "Dolphin/os.h"
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
DEFINE_PRINT("aiAttack")

/*
 * --INFO--
 * Address:	800A82E8
 * Size:	0000C8
 */
ActAttack::ActAttack(Piki* piki)
    : AndAction(piki)
{
	setName("attack");
	setChildren(1, new ActJumpAttack(piki), nullptr);
	mOther.clear();
	mIsPlayer = 0;
}

/*
 * --INFO--
 * Address:	800A8414
 * Size:	000150
 */
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
		mPlayerObject = nullptr;
		_20           = 0;
		mIsPlayer     = 0;
	} else if (creature->mObjType == OBJTYPE_Navi) {
		mPlayerObject = creature;
		mIsPlayer     = 1;
		creature      = findTarget();
	} else {
		mPlayerObject = nullptr;
		_20           = 0;
		mIsPlayer     = 0;
	}

	if (creature) {
		mOther.set(creature);

		AndAction::init(creature);
		if (creature->isTeki() && !playerState->mDemoFlags.isFlag(DEMOFLAG_Unk9) && static_cast<Teki*>(creature)->mTekiType == TEKI_Palm) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk9);
		}
	}

	seMgr->joinBattle();
	mHasLost          = 0;
	mIsAttackFinished = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void ActAttack::startLost()
{
	mHasLost          = 1;
	mIsAttackFinished = 0;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Sagasu2, this), PaniMotionInfo(PIKIANIM_Sagasu2));
}

/*
 * --INFO--
 * Address:	800A8564
 * Size:	0000FC
 */
void ActAttack::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		if (mHasLost) {
			mIsAttackFinished = 1;
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

/*
 * --INFO--
 * Address:	800A8660
 * Size:	00000C
 */
void ActAttack::resume()
{
	mHasLost = 0;
}

/*
 * --INFO--
 * Address:	800A866C
 * Size:	000054
 */
void ActAttack::restart()
{
	if (!mOther.isNull()) {
		seMgr->leaveBattle();
		init(mOther.getPtr());
	}
}

/*
 * --INFO--
 * Address:	800A86C0
 * Size:	000008
 */
bool ActAttack::resumable()
{
	return true;
}

/*
 * --INFO--
 * Address:	800A86C8
 * Size:	000008
 */
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

/*
 * --INFO--
 * Address:	800A86D0
 * Size:	00033C
 */
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
			PRINT("... found new target!\n");
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
		PRINT("target start flying\n");

		Creature* target = findTarget();
		if (target) {
			init(target);
			PRINT("... found new target!\n");
			return ACTOUT_Continue;
		}
		PRINT("TARGET LOST !!\n");
		startLost();
		return ACTOUT_Continue;
	}

	int andRet = AndAction::exec();
	if (andRet != ACTOUT_Continue) {
		if (mIsPlayer) {
			Creature* target = findTarget();
			PRINT("piki attack : res is %s\n", (andRet == 2) ? "success" : (andRet == 1) ? "failed" : "not");
			if (target && andRet == ACTOUT_Success) {
				seMgr->leaveBattle();
				init(mPlayerObject);
				return ACTOUT_Success;
			}

			PRINT("all targets are removed !\n");
			return ACTOUT_Success;
		}

		Creature* target = mOther.getPtr();
		if (AIConstant::_instance->mConstants._C4() == 0) {
			if (target->isAlive()) {
				seMgr->leaveBattle();
				init(target);
				return ACTOUT_Continue;
			}

			PRINT("genocide start ?\n"); // lol?
			target = findTarget();
			if (target) {
				seMgr->leaveBattle();
				init(target);
				PRINT("... found new target!\n");
				return ACTOUT_Continue;
			}
		}

		PRINT("once is done : %x\n", mPiki);
		return ACTOUT_Success;
	}

	return andRet;
}

/*
 * --INFO--
 * Address:	800A8A0C
 * Size:	000064
 */
void ActAttack::cleanup()
{
	mPiki->endClimb();
	seMgr->leaveBattle();
	mPiki->endStickObject();
	mOther.reset();
	mPiki->_519 = 0;
}

/*
 * --INFO--
 * Address:	800A8A70
 * Size:	000060
 */
ActJumpAttack::ActJumpAttack(Piki* piki)
    : Action(piki, true)
{
	mTarget.clear(); // lol
}

/*
 * --INFO--
 * Address:	800A8AD0
 * Size:	0001CC
 */
void ActJumpAttack::init(Creature* creature)
{
	mPiki->mActionState = 0;
	mPiki->mEmotion     = PikiEmotion::Excited;
	if (creature) {
		mTarget.set(creature);
	}
	mState = 0;
	_2C    = 0;
	if (mPiki->isStickTo()) {
		PRINT("jump attack : piki sticks to %s\n", mPiki->mStickPart ? mPiki->mStickPart->mCollInfo->mId.mStringID : "?");
		if (mPiki->mStickPart && mPiki->mStickPart->isClimbable()) {
			mPiki->startClimb();
			mState = 6;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Noboru, this), PaniMotionInfo(PIKIANIM_Noboru));
		} else {
			mState         = 5;
			mIsCriticalHit = 0;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
		}
		mAttackState = 0;
	} else {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
	}

	mTargetCollider = creature->getNearestCollPart(mPiki->mPosition, '*t**');
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

/*
 * --INFO--
 * Address:	800A8C9C
 * Size:	00009C
 */
void ActJumpAttack::procStickMsg(Piki* piki, MsgStick* msg)
{
	mState         = 5;
	mIsCriticalHit = 0;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	mAttackState       = 0;
	piki->mWantToStick = 0;
}

/*
 * --INFO--
 * Address:	800A8D38
 * Size:	00001C
 */
void ActJumpAttack::procBounceMsg(Piki* piki, MsgBounce* msg)
{
	if (mState == 1) {
		mState = 0;
		_2C    = 0;
	}
}

/*
 * --INFO--
 * Address:	800A8D54
 * Size:	000268
 */
void ActJumpAttack::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	// this definitely has inlines somewhere, the control flow is so wacky.

	if (!mTarget.getPtr() || !mTarget.getPtr()->isAlive() || piki->getState() == PIKISTATE_LookAt) {
		return;
	}

	if (mTarget.getPtr()->mObjType == OBJTYPE_Piki && !static_cast<Piki*>(mTarget.getPtr())->isKinoko()) {
		_2C = 1;
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

	PRINT("JUMP STICK ###\n");

	if (msg->mEvent.mColliderPart == 0) {
		PRINT("ざまし! ta no coll part\n"); // 'alarm clock! ta no coll part'
		return;
	}

	if (msg->mEvent.mColliderPart->isPlatformType()) {
		if (msg->mEvent.mColliderPart->isStickable()) {
			PRINT("stick to platform\n");
			piki->startStick(msg->mEvent.mCollider, msg->mEvent.mColliderPart);
		} else {
			if (msg->mEvent.mColliderPart->isClimbable()) {
				PRINT("start climb platform\n");
				piki->startStick(msg->mEvent.mCollider, msg->mEvent.mColliderPart);
			} else {
				PRINT("stickable nor climbable platform\n");
				return;
			}
		}
	} else {
		if (msg->mEvent.mColliderPart->isCollisionType() || msg->mEvent.mColliderPart->isTubeType()) {
			if (msg->mEvent.mColliderPart->isStickable()) {
				PRINT(" stick to 球 or チューブ\n"); // 'stick to ball or tube'
				piki->startStickObject(msg->mEvent.mCollider, msg->mEvent.mColliderPart, -1, 0.0f);
			} else {
				PRINT("try to stick to coll-sphere (%s:code %s): ", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID,
				      msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				return;
			}
		} else {
			return;
		}
	}

	mState = 5;
	if (msg->mEvent.mColliderPart && msg->mEvent.mColliderPart->mPartType == PART_Platform && msg->mEvent.mColliderPart->isClimbable()) {
		piki->startClimb();
		piki->startMotion(PaniMotionInfo(PIKIANIM_Noboru, this), PaniMotionInfo(PIKIANIM_Noboru));
		mState = 6;
	} else {
		mIsCriticalHit = 0;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	}

	mAttackState       = 0;
	piki->mWantToStick = 0;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800A8FBC
 * Size:	000E6C
 */
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
		Vector3f direction = getAttackPos() - mPiki->mPosition;
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
			mPiki->mWantToStick = 1;
			PRINT("jump !\n");
			break;
		}

		mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.2f * angle);

	} break;

	case 0: {
		Vector3f direction = getAttackPos() - mPiki->mPosition;
		f32 dist2D         = speedy_sqrtf(direction.x * direction.x + direction.z * direction.z);
		f32 dist3D         = direction.normalise();
		f32 angle          = absF(angDist(atan2f(direction.x, direction.z), mPiki->mFaceDirection));
		if ((!_2C || (_2C && mTargetCollider && !mTargetCollider->isStickable())) && angle < PI / 10.0f
		    && dist3D < getAttackSize() + mPiki->getCentreSize() + 10.0f) {
			if (!mPiki->isStickTo()) {
				mIsCriticalHit = 0;
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
				PRINT("jump adjust : dist2d = %.1f d = %.1f\n", dist2D, dist3D);
				mState = 2;
			}

			mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection + 0.2f * angle);
			mPiki->setSpeed(1.0f, direction);
		}

		if (mPiki->isStickTo() && !mPiki->mGroundTriangle) {
			mState = 5;
			PRINT("start ATTACK(KUTTUKU)!\n");
			mIsCriticalHit = 0;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
			mPiki->playEventSound(target, SE_PIKI_ATTACK_VOICE);
			mAttackState = 0;
		}

	} break;

	case 4: {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		if (mPiki->isStickTo() && !mPiki->mGroundTriangle) {
			mState         = 5;
			mIsCriticalHit = 0;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
			mPiki->playEventSound(target, SE_PIKI_ATTACK_VOICE);
			mAttackState = 0;
			break;
		}

		if (mAttackState == 1) {
			Vector3f direction = getAttackPos() - mPiki->mPosition;
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
				mIsCriticalHit = 1;
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
					mIsCriticalHit = 1;
					break;
				}
				break;
			}
			mIsCriticalHit = 1;
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
						mIsCriticalHit = 1;
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
							mIsCriticalHit = 1;
						}
					}
				}
			}
		} else if (mAttackState == 4) {
			return ACTOUT_Success;
		}

		if (!mPiki->isStickTo()) {
			PRINT("jump attack : finish stick\n");
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
			mState = 0;
			return ACTOUT_Continue;
		}
	} break;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800A9E28
 * Size:	00004C
 */
void ActJumpAttack::cleanup()
{
	mTarget.reset();
	mPiki->mWantToStick = 0;
}

/*
 * --INFO--
 * Address:	800A9E74
 * Size:	00002C
 */
void ActJumpAttack::attackHit()
{
	mPiki->playEventSound(mTarget.getPtr(), 25);
}

/*
 * --INFO--
 * Address:	800A9EA0
 * Size:	00012C
 */
void ActJumpAttack::animationKeyUpdated(PaniAnimKeyEvent& event)
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

/*
 * --INFO--
 * Address:	800A9FCC
 * Size:	000458
 */
void ActJumpAttack::doClimb()
{
	Creature* target = mTarget.getPtr();
	if (target && target->mCollInfo && target->mCollInfo->hasInfo()) {
		CollPart* part = target->mCollInfo->getSphere('cent');
		if (part) {
			Vector3f dir = part->mCentre - mPiki->mPosition;
			f32 sep      = dir.length();
			f32 dist     = sep - part->mRadius - mPiki->getCentreSize();
			PRINT("  :: climb target distance = %.1f\n", dist);
			if (dist < 5.0f) {
				mState         = 5;
				mIsCriticalHit = 0;
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
				mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
				mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
				mAttackState = 0;
				mPiki->endClimb();
				return;
			}
		}
	}

	PRINT("climbing ...\n");
	if (!mPiki->mClimbingTri) {
		mState = 0;
		mPiki->endClimb();
		return;
	}

	bool check = true;
	for (int i = 0; i < 3; i++) {
		if (mPiki->mClimbingTri->mEdgePlanes[i].dist(mPiki->mPosition) < -2.0f * mPiki->getCentreSize()) {
			PRINT("out of tri : dist is %.1f | centre * -2.0f = %.1f\n", mPiki->mClimbingTri->mEdgePlanes[i].dist(mPiki->mPosition),
			      -2.0f * mPiki->getCentreSize());
			check = false;
		}
	}

	if (!check) {
		mPiki->endStick();
		mState = 0;
		PRINT("finish stick :: out of tri\n");
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
