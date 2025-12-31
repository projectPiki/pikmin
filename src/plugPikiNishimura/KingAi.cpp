#include "Collision.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "Interactions.h"
#include "ItemMgr.h"
#include "King.h"
#include "NaviMgr.h"
#include "NsMath.h"
#include "PaniAnimator.h"
#include "Pcam/CameraManager.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "Stickers.h"

static u32 kingSE[] = {
	SE_KING_WALK,  SE_KING_READY, SE_KING_BERO1, SE_KING_BERO2, SE_KING_GEPPU, SE_KING_DRINK,  SE_KING_EAT,
	SE_KING_CHEEK, SE_KING_NAME,  SE_KING_HIP,   SE_KING_DEAD1, SE_KING_DEAD2, SE_KING_APPEAR, SE_KING_SINK,
};

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("KingAi");

/**
 * @todo: Documentation
 */
KingAi::KingAi(King* king)
{
	mKing = king;
}

/**
 * @todo: Documentation
 */
void KingAi::initAI(King* king)
{
	mKing = king;
	mKing->setCurrentState(16);
	mKing->setNextState(16);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait2, this));
	mKing->setAnimTimer(30.0f);
	mAttackType    = KINGATK_Tongue;
	mIsTongueOut   = false;
	CollPart* slt1 = mKing->mCollInfo->getSphere('slt1');
	CollPart* slt2 = mKing->mCollInfo->getSphere('slt2');

	mMaxMouthSlots          = slt1->getChildCount() + slt2->getChildCount();
	mMouthSlotFlag          = 0;
	mConsecutiveJumpCount   = 0;
	mBombDamageCounter      = 0;
	mEatBombDamageCounter   = 0;
	mDamageScaleOscillation = 0.0f;
	mMaxJumpAttackAngle     = PI * (C_KING_PROP(mKing).mMaxJumpAttackAngle() / 360.0f);
}

/**
 * @todo: Documentation
 */
void KingAi::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		keyAction0();
		break;
	case KEY_Action1:
		keyAction1();
		break;
	case KEY_Action2:
		keyAction2();
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
	case KEY_PlayEffect:
		createEffect(event.mValue);
		break;
	}
}

/**
 * @todo: Documentation
 */
void KingAi::keyAction0()
{
	switch (mKing->getCurrentState()) {
	case KINGAI_Die:
		mKing->mKingBody->createUfoParts();
		break;

	case KINGAI_Damage:
		killStickToMouthPiki();
		mKing->mKingBody->setEatBombEffect();
		break;

	case KINGAI_BombDown:
		CollPart* nosePart = mKing->mCollInfo->getSphere('nose');
		if (nosePart) {
			Vector3f nosePos(nosePart->mCentre);
			effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, nosePos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, nosePos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, nosePos, nullptr, nullptr);
		}
		mKing->mKingBody->setSeedFlashEffect();
		break;

	case KINGAI_Attack:
		mIsTongueOut = true;
		tongueAttackNavi();
		break;

	case KINGAI_JumpAttack:
		effectMgr->create(EffectMgr::EFF_King_Jump, mKing->mSRT.t, nullptr, nullptr);
		break;

	case KINGAI_EatThrowPiki:
		mKing->setMotionFinish(true);
		break;

	case KINGAI_Flick:
		fallBackSide();
		mKing->calcFlickPiki();
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mSRT.t, nullptr, nullptr);
		rumbleMgr->start(RUMBLE_Unk4, 0, mKing->mSRT.t);
		cameraMgr->startVibrationEvent(2, mKing->mSRT.t);
		break;

#if defined(BUGFIX) || defined(VERSION_PIKIDEMO)
		// This case is never hit anyway.  Looks like someone forgot to add a keyAction0 to the appear animation.  See: the other bugfix.
#else
	case KINGAI_Appear:
		if (!mKing->needShadow()) {
			mapMgr->mShadowCaster.add(&mKing->mShadowCaster);
			mKing->setShadowNeed(true);
		}
		break;
#endif
	}
}

/**
 * @todo: Documentation
 */
void KingAi::keyAction1()
{
	switch (mKing->getCurrentState()) {
	case KINGAI_Die:
		rumbleMgr->start(RUMBLE_Unk5, 0, mKing->mSRT.t);
		break;

	case KINGAI_Damage:
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mSRT.t, nullptr, nullptr);
		break;

	case KINGAI_BombDown:
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mSRT.t, nullptr, nullptr);
		break;

	case KINGAI_JumpAttack:
		fallBackSide();
		mKing->calcFlickPiki();
		rumbleMgr->start(RUMBLE_Unk5, 0, mKing->mSRT.t);
		cameraMgr->startVibrationEvent(2, mKing->mSRT.t);
		break;
	}
}

/**
 * @todo: Documentation
 */
void KingAi::keyAction2()
{
	// you're so right nishimura, this absolutely needed a switch statement.
	switch (mKing->getCurrentState()) {
	case KINGAI_Die:
		mKing->mShadowCaster.del();
		mKing->setShadowNeed(false);
		break;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::keyAction3()
{
}

/**
 * @todo: Documentation
 */
void KingAi::keyLoopEnd()
{
	mKing->addLoopCounter(1);
}

/**
 * @todo: Documentation
 */
void KingAi::keyFinished()
{
	mKing->setMotionFinish(true);
	switch (mKing->getCurrentState()) {
	case KINGAI_Die:
		mKing->createPellet(mKing->mSRT.t, 300.0f, false);
		GameStat::killTekis.inc();
		mKing->doKill();
		break;

	case KINGAI_Swallow:
		killStickToMouthPiki();
		break;
	}
}

/**
 * @todo: Documentation
 */
void KingAi::playSound(int kingSoundID)
{
	if (mKing->mSeContext) {
		mKing->mSeContext->playSound(kingSE[kingSoundID]);
	}
}

/**
 * @todo: Documentation
 */
void KingAi::createEffect(BOOL doStartSpreadSaliva)
{
	if (mKing->getCurrentState() == KINGAI_Attack) {
		if (doStartSpreadSaliva) {
			startSpreadSaliva();
		} else {
			endSpreadSaliva();
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000094
 */
void KingAi::setAttackPosition()
{
	mAttackPosition.x = mKing->mSRT.t.x + C_KING_PROP(mKing).mAttackDistance() * sinf(mKing->mFaceDirection);
	mAttackPosition.y = mKing->mSRT.t.y;
	mAttackPosition.z = mKing->mSRT.t.z + C_KING_PROP(mKing).mAttackDistance() * cosf(mKing->mFaceDirection);
}

/**
 * @todo: Documentation
 */
void KingAi::calcDamageScale()
{
	f32 xzScale = C_KING_PROP(mKing).mNormalKingScale();
	f32 yScale  = C_KING_PROP(mKing).mNormalKingScale();

	if (mDamageScaleOscillation == 0.0f) {
		int currState = mKing->getCurrentState();
		if ((currState == KINGAI_Damage || currState == KINGAI_BombDown) && mKing->getDamagePoint() > 0.0f) {
			mDamageScaleOscillation += C_KING_PROP(mKing).mDamageScaleOscillationSpeed() * gsys->getFrameTime();
			if (mDamageScaleOscillation > TAU) {
				mDamageScaleOscillation = 0.0f;
			}
			f32 sinVal = C_KING_PROP(mKing).mDamageScaleOscillationSize() * sinf(mDamageScaleOscillation);
			xzScale *= (1.0f + sinVal);
			yScale *= (1.0f - sinVal);
		}

	} else {
		mDamageScaleOscillation += C_KING_PROP(mKing).mDamageScaleOscillationSpeed() * gsys->getFrameTime();
		if (mDamageScaleOscillation > TAU) {
			mDamageScaleOscillation = 0.0f;
		}
		f32 sinVal = C_KING_PROP(mKing).mDamageScaleOscillationSize() * sinf(mDamageScaleOscillation);
		xzScale *= (1.0f + sinVal);
		yScale *= (1.0f - sinVal);
	}

	mKing->mSRT.s.set(xzScale, yScale, xzScale);
}

/**
 * @todo: Documentation
 */
void KingAi::startSpreadSaliva()
{
	mKing->mKingBody->mDoSpreadSalivaEffect = true;
}

/**
 * @todo: Documentation
 */
void KingAi::endSpreadSaliva()
{
	mKing->mKingBody->mDoSpreadSalivaEffect = false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020
 */
void KingAi::startFallSaliva()
{
	if (mAttackType != KINGATK_Jump) {
		mKing->mKingBody->mDoFallSalivaEffect = true;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
void KingAi::endFallSaliva()
{
	mKing->mKingBody->mDoFallSalivaEffect = false;
}

/**
 * @todo: Documentation
 */
void KingAi::fallBackSide()
{
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi && navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(mKing->mSRT.t.x, mKing->mSRT.t.z, navi->mSRT.t.x, navi->mSRT.t.z) < C_KING_PROP(mKing).mPressAttackRadius()) {
			// close enough, do actual distance check
			if (navi->mSRT.t.distance(mKing->mSRT.t) < C_KING_PROP(mKing).mPressAttackRadius()) {
				InteractPress crush(mKing, C_KING_PROP(mKing).mPressDamageNavi());
				navi->stimulate(crush);
			}
		}
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(mKing->mSRT.t.x, mKing->mSRT.t.z, piki->mSRT.t.x, piki->mSRT.t.z) < C_KING_PROP(mKing).mPressAttackRadius()) {
			// close enough, do actual distance check
			if (piki->mSRT.t.distance(mKing->mSRT.t) < C_KING_PROP(mKing).mPressAttackRadius()) {
				InteractPress crush(mKing, 500.0f);
				piki->stimulate(crush);
			}
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018
 */
void KingAi::setMouthCollPart(int partNum)
{
	mMouthSlotFlag |= (1 << partNum);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
int KingAi::getMouthCollPart(int partNum)
{
	return (mMouthSlotFlag >> partNum) & 1;
}

/**
 * @todo: Documentation
 */
void KingAi::pikiStickToKingMouth()
{

	if (mIsTongueOut) {
		int stickMouthPikiNum = mKing->getStickMouthPikiCount();
		if (stickMouthPikiNum < C_KING_PROP(mKing).mMaxEatPikiNum()) {
			CollPart* slot1 = mKing->mCollInfo->getSphere('slt1');
			CollPart* slot2 = mKing->mCollInfo->getSphere('slt2');
			int slot1Num    = slot1->getChildCount();
			int slot2Num    = slot2->getChildCount();
			int lastSlot    = mMaxMouthSlots - 1;
			int randSlotIndex;
			int i;
			bool isMouthFull = false;
			Iterator iter(pikiMgr);
			CI_LOOP(iter)
			{
				Creature* cPiki = *iter;

				// Ignore invalid objects
				if (!cPiki) {
					continue;
				}

				// Ignore dead, invisible, buried, or already stuck piki
				if (!cPiki->isAlive() || !cPiki->isVisible() || cPiki->isBuried() || cPiki->getStickObject() == mKing) {
					continue;
				}

				// Check if piki is close enough to king's mouth and within the tongue range
				if (!(qdist2(cPiki->mSRT.t.x, cPiki->mSRT.t.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ())) {
					continue;
				}
				if (NsLibMath<f32>::abs(cPiki->mSRT.t.y - slot2->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY()) {
					// Increment the number of piki stuck in the king's mouth
					stickMouthPikiNum++;
					if (stickMouthPikiNum > C_KING_PROP(mKing).mMaxEatPikiNum()) {
						return;
					}

					// Check if the king's mouth is full
					if (isMouthFull) {
						InteractSwallow eat(mKing, slot1->getChildAt(0), 0);
						cPiki->stimulate(eat);
						continue;
					}

					// Randomly select slots to stick the piki in
					randSlotIndex = NsMathI::getRand(mMaxMouthSlots);
					for (i = 0; i < mMaxMouthSlots; i++) {
						if (randSlotIndex > lastSlot) {
							randSlotIndex = 0;
						}

						// Check if the slot is already occupied
						if (!getMouthCollPart(randSlotIndex)) {
							// Stick the piki in the slot
							if (randSlotIndex < slot1Num) {
								InteractSwallow eat(mKing, slot1->getChildAt(randSlotIndex), 0);
								cPiki->stimulate(eat);
							} else {
								InteractSwallow eat(mKing, slot2->getChildAt(randSlotIndex - slot1Num), 0);
								cPiki->stimulate(eat);
							}

							setMouthCollPart(randSlotIndex);
							break;
						}

						// Check if the last slot has been reached
						if (i == lastSlot) {
							InteractSwallow eat(mKing, slot1->getChildAt(0), 0);
							cPiki->stimulate(eat);
							isMouthFull = true;
						}

						randSlotIndex++;
					}
				}
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void KingAi::tongueBombExplosion()
{
	if (mIsTongueOut) {
		CollPart* slot1 = mKing->mCollInfo->getSphere('slt1');
		CollPart* slot2 = mKing->mCollInfo->getSphere('slt2');
		Iterator iter(itemMgr);
		CI_LOOP(iter)
		{
			Creature* bomb = *iter;
			if (bomb && !bomb->isAlive() && !bomb->isVisible() && !bomb->isBuried() && bomb->mObjType == OBJTYPE_Bomb) {
				if ((qdist2(bomb->mSRT.t.x, bomb->mSRT.t.z, slot1->mCentre.x, slot1->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
				     && NsLibMath<f32>::abs(bomb->mSRT.t.y - slot1->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())
				    || (qdist2(bomb->mSRT.t.x, bomb->mSRT.t.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
				        && NsLibMath<f32>::abs(bomb->mSRT.t.y - slot2->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())) {
					InteractBomb blast(mKing, 100.0f, nullptr);
					bomb->stimulate(blast);
				}
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void KingAi::killStickToMouthPiki()
{
	mMouthSlotFlag = 0;
	mKing->killStickToMouthPiki();
}

/**
 * @todo: Documentation
 */
void KingAi::tongueAttackNavi()
{
	CollPart* slot1 = mKing->mCollInfo->getSphere('slt1');
	CollPart* slot2 = mKing->mCollInfo->getSphere('slt2');
	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi && navi->isAlive() && navi->isVisible() && !navi->isBuried()) {
			if ((qdist2(navi->mSRT.t.x, navi->mSRT.t.z, slot1->mCentre.x, slot1->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
			     && NsLibMath<f32>::abs(navi->mSRT.t.y - slot1->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())
			    || (qdist2(navi->mSRT.t.x, navi->mSRT.t.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
			        && NsLibMath<f32>::abs(navi->mSRT.t.y - slot2->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())) {
				InteractAttack blast(mKing, nullptr, C_KING_PROP(mKing).mTongueDamageNavi(), false);
				navi->stimulate(blast);
			}
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
void KingAi::setDispelParm(Creature* target, f32 distance)
{
	f32 knockback
	    = ((C_KING_PROP(mKing).mDispelRadius() - distance) / C_KING_PROP(mKing).mDispelRadius()) * C_KING_PROP(mKing).mDispelPower();
	InteractFlick flick(mKing, knockback, C_KING_PROP(mKing).mDispelDamage(), FLICK_BACKWARDS_ANGLE);
	target->stimulate(flick);
}

/**
 * @todo: Documentation
 */
void KingAi::dispelNaviPiki()
{
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi && navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(navi->mSRT.t.x, navi->mSRT.t.z, mKing->mSRT.t.x, mKing->mSRT.t.z) < C_KING_PROP(mKing).mDispelRadius()) {
			f32 dist = navi->mSRT.t.distance(mKing->mSRT.t);
			if (dist < C_KING_PROP(mKing).mDispelRadius()) {
				setDispelParm(navi, dist);
			}
		}
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, mKing->mSRT.t.x, mKing->mSRT.t.z) < C_KING_PROP(mKing).mDispelRadius()) {
			f32 dist = piki->mSRT.t.distance(mKing->mSRT.t);
			if (dist < C_KING_PROP(mKing).mDispelRadius()) {
				setDispelParm(piki, dist);
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void KingAi::setDamageLoopCounter(int startVal, int minVal, int maxVal, int loopMin, int loopMid, int loopMax)
{
	if (startVal >= maxVal) {
		mDamageLoopCounter = loopMax;
		return;
	}

	if (startVal > minVal) {
		f32 controlPts[3];
		controlPts[0] = loopMin;
		controlPts[1] = loopMid;
		controlPts[2] = loopMax;

		f32 val            = 2.0f * (f32(startVal - minVal) / f32(maxVal - minVal));
		mDamageLoopCounter = NsLibMath<f32>::lagrange3(controlPts, val) + 0.5f;
		mDamageLoopCounter = NsLibMath<int>::revice(mDamageLoopCounter, loopMin, loopMax);
		return;
	}

	mDamageLoopCounter = loopMin;
}

/**
 * @todo: Documentation
 */
void KingAi::setEatDamageLoopCounter()
{
	int bombPikiCount = 0;
	Stickers stuckList(mKing);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (piki->isAlive() && piki->hasBomb() && piki->isStickToMouth()) {
			bombPikiCount++;
		}
	}

	mEatBombDamageCounter += bombPikiCount;

	setDamageLoopCounter(bombPikiCount, C_KING_PROP(mKing).mSwallowedBombsMin(), C_KING_PROP(mKing).mSwallowedBombsMax(),
	                     C_KING_PROP(mKing).mEatBombDamageLoopMin(), C_KING_PROP(mKing).mEatBombDamageLoopMid(),
	                     C_KING_PROP(mKing).mEatBombDamageLoopMax());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000148
 */
void KingAi::setBombDamageLoopCounter()
{
	mEatBombDamageCounter = 0;
	setDamageLoopCounter(mBombDamageCounter, C_KING_PROP(mKing).mHitTongueBombsMin(), C_KING_PROP(mKing).mHitTongueBombsMax(),
	                     C_KING_PROP(mKing).mHitBombDamageLoopMin(), C_KING_PROP(mKing).mHitBombDamageLoopMid(),
	                     C_KING_PROP(mKing).mHitBombDamageLoopMax());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
void KingAi::setMoveVelocity(f32 speed)
{
	mKing->mKingBody->mMoveSpeed = speed;
}

/**
 * @todo: Documentation
 */
void KingAi::setAttackPriority()
{
	mAttackType = KINGATK_Tongue;
	if (mKing->getCurrentLife() < mKing->getMaxLife() * C_KING_PROP(mKing).mJumpAttackHealthThreshold()) {
		f32 factor        = (f32)mEatBombDamageCounter * C_KING_PROP(mKing).mJumpAttackEatBombFactor();
		f32 boundedFactor = NsLibMath<f32>::revice(factor, 0.0f, 1.0f);

		f32 jumpChance = boundedFactor * C_KING_PROP(mKing).mJumpAttackEatBombChance()
		               + (1.0f - boundedFactor) * C_KING_PROP(mKing).mJumpAttackNoEatBombChance();
		if (NsMathF::getRand(1.0f) < jumpChance) {
			mAttackType           = KINGATK_Jump;
			mConsecutiveJumpCount = 0;
			endFallSaliva();
		}
	}
	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
void KingAi::resetAttackPriority()
{
	if (mAttackType == KINGATK_Jump && mKing->getCurrentState() != KINGAI_JumpAttack
	    && mKing->getCurrentLife() > mKing->getMaxLife() * C_KING_PROP(mKing).mJumpAttackHealthThreshold()) {
		mAttackType = true;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void KingAi::resultFlagOn()
{
	if (mKing->insideAndInSearch()) {
		playerState->mResultFlags.setOn(zen::RESFLAG_King);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C
 */
void KingAi::resultFlagSeen()
{
	playerState->mResultFlags.setSeen(zen::RESFLAG_King);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000C0
 */
bool KingAi::attackInArea(Creature* target, immut Vector3f* centre)
{
	if (qdist2(target->mSRT.t.x, target->mSRT.t.z, centre->x, centre->z) < C_KING_PROP(mKing).mAttackTerritoryRadius()
	    && qdist2(target->mSRT.t.x, target->mSRT.t.z, mAttackPosition.x, mAttackPosition.z) < C_KING_PROP(mKing).mNormalAttackRangeXZ()
	    && NsLibMath<f32>::abs(target->mSRT.t.y - mAttackPosition.y) < C_KING_PROP(mKing).mNormalAttackRangeY()) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool KingAi::inJumpAngle(Creature* target)
{
	f32 dir = NsMathF::calcNearerDirection(mKing->mFaceDirection,
	                                       atan2f(target->mSRT.t.x - mKing->mSRT.t.x, target->mSRT.t.z - mKing->mSRT.t.z));
	if (dir > mKing->mFaceDirection) {
		f32 diff = dir - mKing->mFaceDirection;
		if (diff < mMaxJumpAttackAngle) {
			return true;
		}
	} else if (mKing->mFaceDirection - dir < mMaxJumpAttackAngle) {
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000148
 */
bool KingAi::jumpAttackInArea(Creature* target, immut Vector3f* centre)
{
	if (qdist2(target->mSRT.t.x, target->mSRT.t.z, centre->x, centre->z) < C_KING_PROP(mKing).mAttackTerritoryRadius()
	    && qdist2(target->mSRT.t.x, target->mSRT.t.z, mKing->mSRT.t.x, mKing->mSRT.t.z) < C_KING_PROP(mKing).mJumpAttackRangeXZ()
	    && NsLibMath<f32>::abs(target->mSRT.t.y - mAttackPosition.y) < C_KING_PROP(mKing).mNormalAttackRangeY() && inJumpAngle(target)) {
		mKing->setTargetCreature(target);
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool KingAi::dieTransit()
{
	return !mKing->getAlive();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000158
 */
bool KingAi::damageTransit()
{
	Stickers stuckList(mKing);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Piki* stuck = static_cast<Piki*>(*iter);
		if (stuck->isAlive() && stuck->hasBomb() && stuck->isStickToMouth()) {
			return true;
		}
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
bool KingAi::bombDownTransit()
{
	if (mBombDamageCounter > 0) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
bool KingAi::isMotionFinishTransit()
{
	return mKing->getMotionFinish();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool KingAi::outSideChaseRangeTransit()
{
	return mKing->outSideChaseRangeTransit();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool KingAi::inSideWaitRangeTransit()
{
	return mKing->inSideWaitRangeTransit();
}

/**
 * @todo: Documentation
 */
bool KingAi::inTurnAngleTransit()
{
	Vector3f* targetPos = mKing->getTargetPosition();
	f32 angle           = atan2f(targetPos->x - mKing->mSRT.t.x, targetPos->z - mKing->mSRT.t.z);
	f32 dir             = NsMathF::calcNearerDirection(mKing->mFaceDirection, angle);
	if (dir > mKing->mFaceDirection) {
		f32 diff = dir - mKing->mFaceDirection;
		if (diff > QUARTER_PI) {
			return true;
		}
	} else {
		if (mKing->mFaceDirection - dir > QUARTER_PI) {
			return true;
		}
	}

	return false;
	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
bool KingAi::chaseNaviTransit()
{
	Creature* target = nullptr;
	f32 dist;
	f32 minDist = 12800.0f;
	if (mKing->getTargetCreature()) {
		minDist = mKing->mSRT.t.distance(mKing->getTargetCreature()->mSRT.t);
	}

	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {

			f32 qdist = qdist2(mKing->mSRT.t.x, mKing->mSRT.t.z, navi->mSRT.t.x, navi->mSRT.t.z);
			if (qdist < C_BOSS_PROP(mKing).mSearchRadius() &&
			    // typo?? this should be qdist, not dist.
			    dist < minDist && mKing->inSearchAngle(navi)) {
				dist = mKing->mSRT.t.distance(navi->mSRT.t);
				if (dist > C_KING_PROP(mKing).mHiddenUnderneathRadius() && dist < C_BOSS_PROP(mKing).mSearchRadius() && dist < minDist) {
					minDist = dist;
					target  = navi;
				}
			}
		}
	}

	if (target) {
		mKing->setTargetCreature(target);
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool KingAi::chasePikiTransit()
{
	Creature* target = nullptr;
	f32 dist;
	f32 minDist = 12800.0f;
	if (mKing->getTargetCreature()) {
		minDist = mKing->mSRT.t.distance(mKing->getTargetCreature()->mSRT.t);
	}

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->getStickObject() != mKing) {
			f32 qdist = qdist2(mKing->mSRT.t.x, mKing->mSRT.t.z, piki->mSRT.t.x, piki->mSRT.t.z);
			if (qdist < C_BOSS_PROP(mKing).mSearchRadius() &&
			    // typo?? this should be qdist, not dist - they definitely copied and pasted this code lol.
			    dist < minDist && mKing->inSearchAngle(piki)) {
				dist = mKing->mSRT.t.distance(piki->mSRT.t);
				if (dist > C_KING_PROP(mKing).mHiddenUnderneathRadius() && dist < C_BOSS_PROP(mKing).mSearchRadius() && dist < minDist) {
					minDist = dist;
					target  = piki;
				}
			}
		}
	}

	if (target) {
		mKing->setTargetCreature(target);
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool KingAi::attackTransit()
{
	if (mAttackType != KINGATK_Jump) {
		Vector3f* initPos = mKing->getInitPosition();
		Iterator iterNavi(naviMgr);
		CI_LOOP(iterNavi)
		{
			Creature* navi = *iterNavi;
			if (navi->isAlive() && navi->isVisible() && !navi->isBuried() && attackInArea(navi, initPos)) {
				return true;
			}
		}

		Iterator iterPiki(pikiMgr);
		CI_LOOP(iterPiki)
		{
			Creature* piki = *iterPiki;
			if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && attackInArea(piki, initPos)) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000194
 */
bool KingAi::missAttackNextTransit()
{
	Vector3f attackCentre(mKing->mCollInfo->getSphere('slt2')->mCentre);
	attackCentre.x += C_KING_PROP(mKing)._314() * sinf(mKing->mFaceDirection);
	attackCentre.y += C_KING_PROP(mKing)._324();
	attackCentre.z += C_KING_PROP(mKing)._314() * cosf(mKing->mFaceDirection);

	bool res = false;
	MoveTrace trace(attackCentre, Vector3f(0.0f, 0.0f, 0.0f), C_KING_PROP(mKing)._334(), false);
	mapMgr->traceMove(mKing, trace, gsys->getFrameTime());
	if (attackCentre.x != trace.mPosition.x || attackCentre.y != trace.mPosition.y || attackCentre.z != trace.mPosition.z) {
		res = true;
	}
	return res;
}

/**
 * @todo: Documentation
 */
bool KingAi::jumpAttackTransit()
{
	if (mAttackType == KINGATK_Jump && mConsecutiveJumpCount < C_KING_PROP(mKing).mMaxConsecutiveJumpAttacks()) {
		Vector3f* initPos = mKing->getInitPosition();
		Iterator iterPiki(pikiMgr);
		CI_LOOP(iterPiki)
		{
			Creature* piki = *iterPiki;
			if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->getStickObject() != mKing
			    && jumpAttackInArea(piki, initPos)) {
				return true;
			}
		}
		Iterator iterNavi(naviMgr);
		CI_LOOP(iterNavi)
		{
			Creature* navi = *iterNavi;
			if (navi->isAlive() && navi->isVisible() && !navi->isBuried() && jumpAttackInArea(navi, initPos)) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
bool KingAi::swallowTransit()
{
	if (mMouthSlotFlag > 0) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool KingAi::eatThrowPikiTransit()
{
	bool result = false;
	if (!mIsTongueOut) {
		CollPart* slot3 = mKing->mCollInfo->getSphere('slt3');
		Vector3f attackCentre(slot3->mCentre);
		attackCentre.x += 30.0f * sinf(mKing->mFaceDirection);
		attackCentre.y += 15.0f;
		attackCentre.z += 30.0f * cosf(mKing->mFaceDirection);
		f32 slotRad         = slot3->mRadius;
		f32 minAttackHeight = attackCentre.y - slotRad;

		Iterator iter(pikiMgr);
		CI_LOOP(iter)
		{
			Creature* piki = *iter;
			if (piki && piki->isAlive() && piki->getStickObject() != mKing && piki->mSRT.t.y > minAttackHeight
			    && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, attackCentre.x, attackCentre.z) < slotRad) {
				// check actual distance
				if (piki->mSRT.t.distance(attackCentre) < slotRad) {
					InteractSwallow eat(mKing, slot3, 0);
					piki->stimulate(eat);
					result = true;
				}
			}
		}
	}

	return result;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool KingAi::flickTransit()
{
	return mKing->flickPikiTransit();
}

/**
 * @todo: Documentation
 */
bool KingAi::targetLostTransit()
{
	Creature* target = mKing->getTargetCreature();
	if (target) {
		if (!target->isAlive() || !target->isVisible() || target->isBuried() || target->getStickObject() == mKing) {
			mKing->setTargetCreature(nullptr);
			return true;
		}

		if (!mKing->inSearchAngle(target)) {
			mKing->setTargetCreature(nullptr);
			return true;
		}

		f32 dist = mKing->mSRT.t.distance(target->mSRT.t);
		if (dist > C_BOSS_PROP(mKing).mSearchRadius()) {
			mKing->setTargetCreature(nullptr);
			return true;
		}

		if (dist < C_KING_PROP(mKing).mHiddenUnderneathRadius()) {
			mKing->setTargetCreature(nullptr);
			return true;
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool KingAi::appearTransit()
{
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(navi->mSRT.t.x, navi->mSRT.t.z, mKing->mSRT.t.x, mKing->mSRT.t.z) < C_KING_PROP(mKing).mDetectionRadius()) {
			// close enough, check actual distance
			if (navi->mSRT.t.distance(mKing->mSRT.t) < C_KING_PROP(mKing).mDetectionRadius()) {
				return true;
			}
		}
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, mKing->mSRT.t.x, mKing->mSRT.t.z) < C_KING_PROP(mKing).mDetectionRadius()) {
			// close enough, check actual distance
			if (piki->mSRT.t.distance(mKing->mSRT.t) < C_KING_PROP(mKing).mDetectionRadius()) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @todo: Documentation
 */
void KingAi::initDie(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->setIsAlive(false);
	mKing->setIsOrganic(false);
	mKing->disableStick();
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Dead, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	mKing->mPlatMgr.release();
	resultFlagSeen();
	effectMgr->create(EffectMgr::EFF_King_DeadB, mKing->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadD, mKing->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadC, mKing->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadA, mKing->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadE, mKing->mSRT.t, nullptr, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001C8
 */
void KingAi::initDamage(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	setEatDamageLoopCounter();
	setMoveVelocity(0.0f);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Damage, this));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D0
 */
void KingAi::initBombDown(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	setBombDamageLoopCounter();
	killStickToMouthPiki();
	setMoveVelocity(0.0f);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type5, this));
	mKing->mKingBody->initBlending(3.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E8
 */
void KingAi::initWalkRandom(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// if we're not chasing a navi or piki, essentially.
		mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
		mKing->setAnimTimer(30.0f);
	}
	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E8
 */
void KingAi::initWalkGoHome(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// i.e. not chasing piki or navi
		mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
		mKing->setAnimTimer(30.0f);
	}

	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E0
 */
void KingAi::initChaseNavi(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// i.e. not chaseNavi or chasePiki
		mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
		mKing->setAnimTimer(30.0f);
	}

	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E0
 */
void KingAi::initChasePiki(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// i.e. not chaseNavi or chasePiki
		mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
		mKing->setAnimTimer(30.0f);
	}

	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00008C
 */
void KingAi::initHomeTurn(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::WaitAct1, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084
 */
void KingAi::initChaseTurn(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::WaitAct1, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000AC
 */
void KingAi::initAttack(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mIsTongueOut       = false;
	mBombDamageCounter = 0;
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Attack, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00011C
 */
void KingAi::initJumpAttack(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type4, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
	mJumpAttackStartPosition = mKing->mSRT.t;
	if (mKing->getTargetCreature()) {
		mJumpAttackTargetPosition = mKing->getTargetCreature()->mSRT.t;
		mKing->setTargetCreature(nullptr);
	} else {
		mJumpAttackTargetPosition = mKing->mSRT.t;
	}

	mConsecutiveJumpCount++;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A4
 */
void KingAi::initSwallow(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type1, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A4
 */
void KingAi::initEatThrowPiki(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type2, this));
	mKing->mKingBody->initBlending(6.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000198
 */
void KingAi::initFlick(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Flick, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	setAttackPriority();
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000AC
 */
void KingAi::initWaveNeck(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::WaitAct2, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/**
 * @todo: Documentation
 */
void KingAi::initAppear(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
#if defined(VERSION_PIKIDEMO)
	if (!mKing->mIsBossBgm)
#endif
	{
		mKing->mIsBossBgm = true;
		// Emperor Bulblax's shadow is... difficult.  I swear it can sometimes appear in USA rev 1, but frankly I don't know how.
		// In any case, this code originally from the demo versions works much better than the solution in `KingAi::keyAction0`.
#if defined(BUGFIX) || defined(VERSION_PIKIDEMO)
		mapMgr->mShadowCaster.add(&mKing->mShadowCaster);
		mKing->setShadowNeed(true);
#endif
	}
	mKing->setInvincible(false);
	mKing->setIsOrganic(true);
	dispelNaviPiki();
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type3, this));
	mKing->mKingBody->initBlending(10.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
	effectMgr->create(EffectMgr::EFF_King_AppearB, mKing->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_AppearC, mKing->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_AppearA, mKing->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_AppearD, mKing->mSRT.t, nullptr, nullptr);
	rumbleMgr->start(RUMBLE_Unk5, 0, mKing->mSRT.t);
	cameraMgr->startVibrationEvent(4, mKing->mSRT.t);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000098
 */
void KingAi::initStay(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->setAttackTimer(0.0f);
	mKing->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait2, this));
	mKing->mKingBody->initBlending(15.0f);
	setMoveVelocity(0.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
void KingAi::dieState()
{
	mKing->setIsAlive(true); // ?
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00005C
 */
void KingAi::damageState()
{
	if (mKing->getLoopCounter() >= mDamageLoopCounter) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00005C
 */
void KingAi::bombDownState()
{
	if (mKing->getLoopCounter() >= mDamageLoopCounter) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
void KingAi::walkRandomState()
{
	mKing->makeTargetRandom(30.0f);
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void KingAi::walkGoHomeState()
{
	mKing->setTargetPosition(*mKing->getInitPosition());
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F8
 */
void KingAi::homeTurnState()
{
	mKing->setTargetPosition(*mKing->getInitPosition());
	mKing->stopMovement();
	mKing->changeDirection(C_KING_PROP(mKing).mTurningTurnSpeed());
	if (!inTurnAngleTransit()) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000FC
 */
void KingAi::chaseTurnState()
{
	if (!mKing->getTargetCreature()) {
		chasePikiTransit();
		chaseNaviTransit();
	}

	mKing->makeTargetCreature();

	mKing->changeDirection(C_KING_PROP(mKing).mTurningTurnSpeed());
	if (!inTurnAngleTransit()) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
void KingAi::chaseNaviState()
{
	mKing->makeTargetCreature();
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
void KingAi::chasePikiState()
{
	mKing->makeTargetCreature();
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void KingAi::attackState()
{
	mKing->makeTargetCreature();
	pikiStickToKingMouth();
	tongueBombExplosion();
	if (mKing->getLoopCounter() >= C_KING_PROP(mKing).mTongueRollLoopCount()) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000C0
 */
void KingAi::jumpAttackState()
{
	if (mKing->mAnimator.mAnimationCounter > 41.0f && mKing->mAnimator.mAnimationCounter < 79.0f) {
		f32 diff        = (mKing->mAnimator.mAnimationCounter - 41.0f);
		f32 diff2       = 79.0f - 41.0f;
		f32 ratio       = diff / diff2;
		f32 complRatio  = 1.0f - ratio;
		mKing->mSRT.t.x = ratio * mJumpAttackTargetPosition.x + complRatio * mJumpAttackStartPosition.x;
		mKing->mSRT.t.z = ratio * mJumpAttackTargetPosition.z + complRatio * mJumpAttackStartPosition.z;
		mKing->mSRT.t.y = mapMgr->getMinY(mKing->mSRT.t.x, mKing->mSRT.t.z, true);
		mKing->changeDirection(C_KING_PROP(mKing).mTurningTurnSpeed());
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::swallowState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::eatThrowPikiState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::flickState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::waitState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::waveNeckState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::appearState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void KingAi::stayState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00012C
 */
void KingAi::setEveryFrame()
{
	setAttackPosition();
	calcDamageScale();
	resetAttackPriority();
	if (mKing->getDamagePoint() > 0.0f) {
		mKing->calcBossDamage();
	}
	if (mKing->getTargetCreature()) {
		startFallSaliva();
	} else {
		endFallSaliva();
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00033C
 */
void KingAi::afterProcessing()
{
	if (mKing->getCurrentState() != mKing->getNextState()) {
		switch (mKing->getCurrentState()) {
		case KINGAI_Damage:
			setAttackPriority();
			break;
		case KINGAI_Attack:
			mIsTongueOut = false;
			endSpreadSaliva();
			setAttackPriority();
			break;
		case KINGAI_JumpAttack:
			setAttackPriority();
			break;
		}
	}
}

/**
 * @todo: Documentation
 */
void KingAi::update()
{
	setEveryFrame();

	switch (mKing->getCurrentState()) {
	case KINGAI_Die:
		dieState();
		break;

	case KINGAI_Damage:
		damageState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (isMotionFinishTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_BombDown:
		bombDownState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (isMotionFinishTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_WalkRandom:
		walkRandomState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (flickTransit()) {
			initFlick(KINGAI_Flick);
		} else if (attackTransit()) {
			initAttack(KINGAI_Attack);
		} else if (jumpAttackTransit()) {
			initJumpAttack(KINGAI_JumpAttack);
		} else if (inTurnAngleTransit()) {
			initChaseTurn(KINGAI_ChaseTurn);
		} else if (outSideChaseRangeTransit()) {
			initWalkGoHome(KINGAI_WalkGoHome, false);
		} else if (chaseNaviTransit()) {
			initChaseNavi(KINGAI_ChaseNavi, false);
		} else if (chasePikiTransit()) {
			initChasePiki(KINGAI_ChasePiki, false);
		}
		break;

	case KINGAI_HomeTurn:
		homeTurnState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (flickTransit()) {
			initFlick(KINGAI_Flick);
		} else if (isMotionFinishTransit()) {
			initWalkGoHome(KINGAI_WalkGoHome, false);
		}
		break;

	case KINGAI_ChaseTurn:
		chaseTurnState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (flickTransit()) {
			initFlick(KINGAI_Flick);
		} else if (attackTransit()) {
			initAttack(KINGAI_Attack);
		} else if (jumpAttackTransit()) {
			initJumpAttack(KINGAI_JumpAttack);
		} else if (targetLostTransit()) {
			initWaveNeck(KINGAI_WaveNeck);
		} else if (isMotionFinishTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_ChaseNavi:
		chaseNaviState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (flickTransit()) {
			initFlick(KINGAI_Flick);
		} else if (attackTransit()) {
			initAttack(KINGAI_Attack);
		} else if (jumpAttackTransit()) {
			initJumpAttack(KINGAI_JumpAttack);
		} else if (outSideChaseRangeTransit()) {
			initWalkGoHome(KINGAI_WalkGoHome, false);
		} else if (targetLostTransit()) {
			initWaveNeck(KINGAI_WaveNeck);
		} else if (inTurnAngleTransit()) {
			initChaseTurn(KINGAI_ChaseTurn);
		} else if (chasePikiTransit()) {
			initChaseNavi(KINGAI_ChaseNavi, false);
		}
		break;

	case KINGAI_ChasePiki:
		chasePikiState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (flickTransit()) {
			initFlick(KINGAI_Flick);
		} else if (attackTransit()) {
			initAttack(KINGAI_Attack);
		} else if (jumpAttackTransit()) {
			initJumpAttack(KINGAI_JumpAttack);
		} else if (outSideChaseRangeTransit()) {
			initWalkGoHome(KINGAI_WalkGoHome, false);
		} else if (targetLostTransit()) {
			initWaveNeck(KINGAI_WaveNeck);
		} else if (inTurnAngleTransit()) {
			initChaseTurn(KINGAI_ChaseTurn);
		} else if (chaseNaviTransit()) {
			initChaseNavi(KINGAI_ChaseNavi, false);
		} else if (chasePikiTransit()) {
			initChasePiki(KINGAI_ChasePiki, false);
		}
		break;

	case KINGAI_Attack:
		attackState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (bombDownTransit()) {
			initBombDown(KINGAI_BombDown);
		} else if (eatThrowPikiTransit()) {
			initEatThrowPiki(KINGAI_EatThrowPiki);
		} else if (missAttackNextTransit()) {
			if (damageTransit()) {
				initEatThrowPiki(KINGAI_EatThrowPiki);
			} else if (swallowTransit()) {
				initSwallow(KINGAI_Swallow);
			} else {
				initHomeTurn(KINGAI_HomeTurn);
			}
		} else if (isMotionFinishTransit()) {
			if (damageTransit()) {
				initEatThrowPiki(KINGAI_EatThrowPiki);
			} else if (swallowTransit()) {
				initSwallow(KINGAI_Swallow);
			} else {
				initWalkRandom(KINGAI_WalkRandom, false);
			}
		}
		break;

	case KINGAI_JumpAttack:
		jumpAttackState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (isMotionFinishTransit()) {
			if (jumpAttackTransit()) {
				initJumpAttack(KINGAI_JumpAttack);
			} else {
				initWalkRandom(KINGAI_WalkRandom, false);
			}
		}
		break;

	case KINGAI_Swallow:
		swallowState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (isMotionFinishTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_EatThrowPiki:
		eatThrowPikiState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (isMotionFinishTransit()) {
			if (damageTransit()) {
				initDamage(KINGAI_Damage);
			} else {
				initSwallow(KINGAI_Swallow);
			}
		}
		break;

	case KINGAI_WalkGoHome:
		walkGoHomeState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (flickTransit()) {
			initFlick(KINGAI_Flick);
		} else if (inTurnAngleTransit()) {
			initHomeTurn(KINGAI_HomeTurn);
		} else if (inSideWaitRangeTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_Flick:
		flickState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (isMotionFinishTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_WaveNeck:
		waveNeckState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (flickTransit()) {
			initFlick(KINGAI_Flick);
		} else if (attackTransit()) {
			initAttack(KINGAI_Attack);
		} else if (jumpAttackTransit()) {
			initJumpAttack(KINGAI_JumpAttack);
		} else if (isMotionFinishTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_Appear:
		appearState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (isMotionFinishTransit()) {
			initWalkRandom(KINGAI_WalkRandom, false);
		}
		break;

	case KINGAI_Stay:
		stayState();
		if (appearTransit()) {
			initAppear(KINGAI_Appear);
		}
		break;
	}

	afterProcessing();
}
