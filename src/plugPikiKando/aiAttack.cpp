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
	mPiki->mEmotion     = PikiEmotion::Unk5;
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
	Creature* targetList[100];
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
			mPiki->mEmotion = PikiEmotion::Unk7;
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
	mPiki->mEmotion     = PikiEmotion::Unk5;
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

	u32 badCompiler[2];
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
		direction.normalise();
		f32 angle = angDist(atan2f(direction.x, direction.z), mPiki->mFaceDirection);

		f32 size = getAttackSize() + mPiki->getCentreSize();
		if (dist2D < size) {
			mPiki->setSpeed(0.5f, direction);
			mPiki->mTargetVelocity = mPiki->mTargetVelocity * -1.0f;
			break;
		}

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
		f32 angle          = zen::Abs(angDist(atan2f(direction.x, direction.z), mPiki->mFaceDirection));
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

		if (mPiki->isStickTo() && !mPiki->mFloorTri) {
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
		if (mPiki->isStickTo() && !mPiki->mFloorTri) {
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
			if (dist < 10.0f && zen::Abs(angle) < PI / 4.0f && (target->isBoss() || target->isTeki()) && target->isAlive()
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

	u32 badCompiler[3];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x250(r1)
	  stfd      f31, 0x248(r1)
	  stfd      f30, 0x240(r1)
	  stfd      f29, 0x238(r1)
	  stfd      f28, 0x230(r1)
	  stw       r31, 0x22C(r1)
	  mr        r31, r3
	  stw       r30, 0x228(r1)
	  stw       r29, 0x224(r1)
	  stw       r28, 0x220(r1)
	  lwz       r30, 0x24(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0x74
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x90

	.loc_0x74:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  bl        -0x187C8

	.loc_0x88:
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0x90:
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xC0
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC0
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0xC0:
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x184(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  beq-      .loc_0xF4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF4
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0xF4:
	  lwz       r0, 0x18(r31)
	  cmplwi    r0, 0x6
	  bgt-      .loc_0xE38
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5374
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  mr        r3, r31
	  bl        0xEF4
	  b         .loc_0xE38
	  lwz       r4, 0x28(r31)
	  lwz       r3, 0xC(r31)
	  cmplwi    r4, 0
	  addi      r29, r3, 0x94
	  beq-      .loc_0x148
	  addi      r3, r1, 0x170
	  addi      r4, r4, 0x4
	  bl        -0x35FB8
	  b         .loc_0x160

	.loc_0x148:
	  lwz       r4, 0x24(r31)
	  addi      r3, r1, 0x170
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x160:
	  lfs       f1, 0x170(r1)
	  lfs       f0, 0x0(r29)
	  lfs       f3, 0x174(r1)
	  lfs       f2, 0x4(r29)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r29)
	  lfs       f4, 0x178(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x20C(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x210(r1)
	  stfs      f0, 0x214(r1)
	  lfs       f0, 0x20C(r1)
	  lfs       f1, 0x214(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x7168(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x1C4
	  fsqrte    f0, f31
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0xCC(r1)
	  lfs       f31, 0xCC(r1)

	.loc_0x1C4:
	  lfs       f1, 0x20C(r1)
	  lfs       f0, 0x210(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x214(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9B560
	  lfs       f0, -0x7168(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x218
	  lfs       f0, 0x20C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20C(r1)
	  lfs       f0, 0x210(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x210(r1)
	  lfs       f0, 0x214(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x214(r1)

	.loc_0x218:
	  lfs       f1, 0x20C(r1)
	  lfs       f2, 0x214(r1)
	  bl        0x17281C
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x70C34
	  lwz       r3, 0x28(r31)
	  fmr       f29, f1
	  cmplwi    r3, 0
	  beq-      .loc_0x248
	  lfs       f30, 0x0(r3)
	  b         .loc_0x260

	.loc_0x248:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f30, f1

	.loc_0x260:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f30, f1
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0x2E4
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x20C
	  lfs       f1, -0x7150(r2)
	  bl        0x22B90
	  lwz       r3, 0xC(r31)
	  lfs       f2, -0x4FF4(r13)
	  addi      r4, r3, 0xA4
	  lfs       f0, 0xA4(r3)
	  lfs       f1, 0xAC(r3)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x164(r1)
	  lfs       f0, 0xA8(r3)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x168(r1)
	  stfs      f1, 0x16C(r1)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x8(r4)
	  b         .loc_0xE38

	.loc_0x2E4:
	  lfs       f0, -0x714C(r2)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x308
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x20C
	  lfs       f1, -0x7150(r2)
	  bl        0x22B1C
	  b         .loc_0xE38

	.loc_0x308:
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FF0(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FEC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FE8(r13)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7148(r2)
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x3AC
	  lfs       f2, -0x7144(r2)
	  cmplwi    r31, 0
	  lfs       f0, 0x20C(r1)
	  mr        r30, r31
	  lfs       f1, 0x214(r1)
	  fmuls     f0, f2, f0
	  lwz       r3, 0xC(r31)
	  fmuls     f1, f2, f1
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x7140(r2)
	  stfs      f0, 0x4(r3)
	  stfs      f1, 0x8(r3)
	  beq-      .loc_0x368
	  addi      r30, r30, 0x14

	.loc_0x368:
	  addi      r3, r1, 0x150
	  li        r4, 0x16
	  bl        0x75C2C
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x158
	  li        r4, 0x16
	  bl        0x75C4C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x21688
	  li        r0, 0x1
	  stw       r0, 0x18(r31)
	  lwz       r3, 0xC(r31)
	  stb       r0, 0x470(r3)
	  b         .loc_0xE38

	.loc_0x3AC:
	  lfs       f0, -0x713C(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f29
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x70DF4
	  lwz       r3, 0xC(r31)
	  stfs      f1, 0xA0(r3)
	  b         .loc_0xE38
	  lwz       r4, 0x28(r31)
	  lwz       r3, 0xC(r31)
	  cmplwi    r4, 0
	  addi      r29, r3, 0x94
	  beq-      .loc_0x3F4
	  addi      r3, r1, 0x138
	  addi      r4, r4, 0x4
	  bl        -0x36264
	  b         .loc_0x40C

	.loc_0x3F4:
	  lwz       r4, 0x24(r31)
	  addi      r3, r1, 0x138
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x40C:
	  lfs       f1, 0x138(r1)
	  lfs       f0, 0x0(r29)
	  lfs       f3, 0x13C(r1)
	  lfs       f2, 0x4(r29)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r29)
	  lfs       f4, 0x140(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x1F0(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x1F4(r1)
	  stfs      f0, 0x1F8(r1)
	  lfs       f0, 0x1F0(r1)
	  lfs       f1, 0x1F8(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x7168(r2)
	  fmuls     f1, f1, f1
	  fadds     f30, f2, f1
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x470
	  fsqrte    f0, f30
	  fmul      f0, f30, f0
	  frsp      f0, f0
	  stfs      f0, 0xB8(r1)
	  lfs       f30, 0xB8(r1)

	.loc_0x470:
	  lfs       f1, 0x1F0(r1)
	  lfs       f0, 0x1F4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x1F8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9B80C
	  fmr       f29, f1
	  lfs       f0, -0x7168(r2)
	  fcmpu     cr0, f0, f29
	  beq-      .loc_0x4C8
	  lfs       f0, 0x1F0(r1)
	  fdivs     f0, f0, f29
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x1F4(r1)
	  fdivs     f0, f0, f29
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x1F8(r1)
	  fdivs     f0, f0, f29
	  stfs      f0, 0x1F8(r1)

	.loc_0x4C8:
	  lfs       f1, 0x1F0(r1)
	  lfs       f2, 0x1F8(r1)
	  bl        0x17256C
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x70EE4
	  lbz       r0, 0x2C(r31)
	  fabs      f31, f1
	  cmplwi    r0, 0
	  beq-      .loc_0x50C
	  beq-      .loc_0x604
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x604
	  bl        -0x218FC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x604

	.loc_0x50C:
	  lfs       f0, -0x7148(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x604
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x52C
	  lfs       f28, 0x0(r3)
	  b         .loc_0x544

	.loc_0x52C:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f28, f1

	.loc_0x544:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f28, f1
	  lfs       f0, -0x7138(r2)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x604
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x730
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x2D(r31)
	  mr        r28, r31
	  beq-      .loc_0x594
	  addi      r28, r28, 0x14

	.loc_0x594:
	  addi      r3, r1, 0x128
	  li        r4, 0x17
	  bl        0x75A00
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x130
	  li        r4, 0x17
	  bl        0x75A20
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x2145C
	  lwz       r3, 0xC(r31)
	  addi      r4, r30, 0
	  li        r5, 0x17
	  bl        -0x1EFD8
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  li        r0, 0x4
	  stw       r0, 0x18(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FE4(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FE0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FDC(r13)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x730

	.loc_0x604:
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x61C
	  bl        -0x21A0C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x670

	.loc_0x61C:
	  lbz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x670
	  bl        0x16EA8C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7158(r2)
	  stw       r0, 0x21C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7160(r2)
	  stw       r0, 0x218(r1)
	  lfs       f1, -0x7164(r2)
	  lfd       f3, 0x218(r1)
	  lfs       f0, -0x7134(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x670
	  li        r0, 0x2
	  stw       r0, 0x18(r31)
	  b         .loc_0x730

	.loc_0x670:
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x684
	  lfs       f28, 0x0(r3)
	  b         .loc_0x69C

	.loc_0x684:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f28, f1

	.loc_0x69C:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f28, f1
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x700
	  bl        0x16E9F8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7158(r2)
	  stw       r0, 0x21C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7160(r2)
	  stw       r0, 0x218(r1)
	  lfs       f1, -0x7164(r2)
	  lfd       f3, 0x218(r1)
	  lfs       f0, -0x7130(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x700
	  li        r0, 0x2
	  stw       r0, 0x18(r31)

	.loc_0x700:
	  lfs       f0, -0x713C(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f31
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x71148
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x1F0
	  stfs      f1, 0xA0(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x7164(r2)
	  bl        0x226F0

	.loc_0x730:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xE38
	  lwz       r0, 0x28C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE38
	  li        r0, 0x5
	  stw       r0, 0x18(r31)
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x2D(r31)
	  mr        r28, r31
	  beq-      .loc_0x76C
	  addi      r28, r28, 0x14

	.loc_0x76C:
	  addi      r3, r1, 0x118
	  li        r4, 0x30
	  bl        0x75828
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x120
	  li        r4, 0x30
	  bl        0x75848
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x21284
	  lwz       r3, 0xC(r31)
	  addi      r4, r30, 0
	  li        r5, 0x17
	  bl        -0x1F1B0
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FD8(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FD4(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FD0(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x85C
	  lwz       r0, 0x28C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x85C
	  li        r0, 0x5
	  stw       r0, 0x18(r31)
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x2D(r31)
	  mr        r28, r31
	  beq-      .loc_0x810
	  addi      r28, r28, 0x14

	.loc_0x810:
	  addi      r3, r1, 0x108
	  li        r4, 0x30
	  bl        0x75784
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x110
	  li        r4, 0x30
	  bl        0x757A4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x211E0
	  lwz       r3, 0xC(r31)
	  addi      r4, r30, 0
	  li        r5, 0x17
	  bl        -0x1F254
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38

	.loc_0x85C:
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xBA0
	  lwz       r4, 0x28(r31)
	  addi      r29, r3, 0x94
	  cmplwi    r4, 0
	  beq-      .loc_0x888
	  addi      r3, r1, 0xF0
	  addi      r4, r4, 0x4
	  bl        -0x366F8
	  b         .loc_0x8A0

	.loc_0x888:
	  lwz       r4, 0x24(r31)
	  addi      r3, r1, 0xF0
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x8A0:
	  lfs       f3, 0xF8(r1)
	  lfs       f2, 0x8(r29)
	  lfs       f1, 0xF0(r1)
	  lfs       f0, 0x0(r29)
	  fsubs     f30, f3, f2
	  lfs       f2, 0xF4(r1)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x4(r29)
	  fsubs     f28, f2, f0
	  fmr       f2, f30
	  fmr       f1, f29
	  bl        0x172170
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x712E0
	  fmuls     f3, f29, f29
	  lfs       f0, -0x7168(r2)
	  fmuls     f2, f28, f28
	  fmr       f31, f1
	  fmuls     f4, f30, f30
	  fadds     f1, f3, f2
	  fadds     f30, f4, f1
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x958
	  fsqrte    f1, f30
	  lfd       f3, -0x7128(r2)
	  lfd       f2, -0x7120(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f30, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f30, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f30, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f30, f0
	  frsp      f0, f0
	  stfs      f0, 0x74(r1)
	  lfs       f30, 0x74(r1)

	.loc_0x958:
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x96C
	  lfs       f28, 0x0(r3)
	  b         .loc_0x984

	.loc_0x96C:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f28, f1

	.loc_0x984:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fsubs     f2, f30, f28
	  lfs       f0, -0x7138(r2)
	  fsubs     f28, f2, f1
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0xA98
	  fabs      f1, f31
	  lfs       f0, -0x7118(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xA98
	  mr        r3, r30
	  bl        -0x1F6D4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x9D8
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0x37
	  bne-      .loc_0xA98

	.loc_0x9D8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA98
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA98
	  lwz       r3, 0xC(r31)
	  bl        0x1D0EC
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xA28
	  lfs       f1, -0x7114(r2)

	.loc_0xA28:
	  lis       r3, 0x802B
	  lwz       r5, 0xC(r31)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x1C4(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x31FC
	  stw       r5, 0x1C8(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r4, 0x1C4(r1)
	  addi      r4, r1, 0x1C4
	  stfs      f1, 0x1CC(r1)
	  stw       r0, 0x1D0(r1)
	  stb       r0, 0x1D4(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8C
	  mr        r3, r31
	  bl        0x43C
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38

	.loc_0xA8C:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xE38

	.loc_0xA98:
	  lfs       f0, -0x7138(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0xB94
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xB94
	  mr        r28, r30
	  lwz       r4, 0xC(r31)
	  mr        r3, r28
	  bl        0x1E508
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE38
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE38
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE38
	  lbz       r0, 0x2B4(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0xE38
	  lwz       r3, 0xC(r31)
	  bl        0x1CFF0
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xB24
	  lfs       f1, -0x7114(r2)

	.loc_0xB24:
	  lis       r3, 0x802B
	  lwz       r5, 0xC(r31)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x1B0(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x31FC
	  stw       r5, 0x1B4(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r4, 0x1B0(r1)
	  addi      r4, r1, 0x1B0
	  stfs      f1, 0x1B8(r1)
	  stw       r0, 0x1BC(r1)
	  stb       r0, 0x1C0(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB88
	  mr        r3, r31
	  bl        0x340
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38

	.loc_0xB88:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xE38

	.loc_0xB94:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xE38

	.loc_0xBA0:
	  cmpwi     r0, 0x4
	  bne-      .loc_0xE38
	  li        r3, 0x2
	  b         .loc_0xE3C
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FCC(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4FC8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FC4(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FC0(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FBC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FB8(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xDC8
	  lwz       r3, 0xC(r31)
	  lwz       r28, 0x184(r3)
	  cmplwi    r28, 0
	  beq-      .loc_0xDD8
	  addi      r30, r28, 0
	  addi      r3, r30, 0
	  bl        -0x1F920
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC24
	  lwz       r0, 0x6C(r28)
	  cmpwi     r0, 0x37
	  bne-      .loc_0xCE4

	.loc_0xC24:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCE4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCE4
	  lwz       r3, 0xC(r31)
	  bl        0x1CEA0
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xC74
	  lfs       f1, -0x7114(r2)

	.loc_0xC74:
	  lwz       r7, 0xC(r31)
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  lwz       r6, 0x188(r7)
	  subi      r0, r4, 0x3064
	  subi      r5, r3, 0x31FC
	  stw       r0, 0x19C(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r7, 0x1A0(r1)
	  addi      r4, r1, 0x19C
	  stw       r5, 0x19C(r1)
	  stfs      f1, 0x1A4(r1)
	  stw       r6, 0x1A8(r1)
	  stb       r0, 0x1AC(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCDC
	  mr        r3, r31
	  bl        0x1EC
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xCE4

	.loc_0xCDC:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)

	.loc_0xCE4:
	  lwz       r0, 0x6C(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0xDD8
	  lwz       r4, 0xC(r31)
	  mr        r3, r28
	  bl        0x1E2CC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDD8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDD8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDD8
	  lwz       r3, 0xC(r31)
	  bl        0x1CDC0
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xD54
	  lfs       f1, -0x7114(r2)

	.loc_0xD54:
	  lwz       r7, 0xC(r31)
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  lwz       r6, 0x188(r7)
	  subi      r0, r4, 0x3064
	  subi      r5, r3, 0x31FC
	  stw       r0, 0x188(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r7, 0x18C(r1)
	  addi      r4, r1, 0x188
	  stw       r5, 0x188(r1)
	  stfs      f1, 0x190(r1)
	  stw       r6, 0x194(r1)
	  stb       r0, 0x198(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDBC
	  mr        r3, r31
	  bl        0x10C
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xDD8

	.loc_0xDBC:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xDD8

	.loc_0xDC8:
	  cmpwi     r0, 0x4
	  bne-      .loc_0xDD8
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0xDD8:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE38
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0xDF8
	  addi      r28, r28, 0x14

	.loc_0xDF8:
	  addi      r3, r1, 0xE0
	  li        r4, 0x2
	  bl        0x7519C
	  addi      r30, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xE8
	  li        r4, 0x2
	  bl        0x751BC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x20BF8
	  li        r0, 0
	  stw       r0, 0x18(r31)
	  li        r3, 0
	  b         .loc_0xE3C

	.loc_0xE38:
	  li        r3, 0

	.loc_0xE3C:
	  lwz       r0, 0x254(r1)
	  lfd       f31, 0x248(r1)
	  lfd       f30, 0x240(r1)
	  lfd       f29, 0x238(r1)
	  lfd       f28, 0x230(r1)
	  lwz       r31, 0x22C(r1)
	  lwz       r30, 0x228(r1)
	  lwz       r29, 0x224(r1)
	  lwz       r28, 0x220(r1)
	  addi      r1, r1, 0x250
	  mtlr      r0
	  blr
	*/
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
