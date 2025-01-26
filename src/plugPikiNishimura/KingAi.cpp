#include "King.h"
#include "NsMath.h"
#include "PaniAnimator.h"
#include "Collision.h"
#include "GameStat.h"
#include "RumbleMgr.h"
#include "Stickers.h"
#include "NaviMgr.h"
#include "ItemMgr.h"
#include "PikiMgr.h"
#include "Interactions.h"
#include "PlayerState.h"
#include "Pcam/CameraManager.h"
#include "SoundMgr.h"
#include "DebugLog.h"

static u32 kingSE[] = {
	SE_KING_WALK,  SE_KING_READY, SE_KING_BERO1, SE_KING_BERO2, SE_KING_GEPPU, SE_KING_DRINK,  SE_KING_EAT,
	SE_KING_CHEEK, SE_KING_NAME,  SE_KING_HIP,   SE_KING_DEAD1, SE_KING_DEAD2, SE_KING_APPEAR, SE_KING_SINK,
};

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("KingAi");

/*
 * --INFO--
 * Address:	8016C2B0
 * Size:	000048
 */
KingAi::KingAi(King* king)
{
	mKing = king;
}

/*
 * --INFO--
 * Address:	8016C2F8
 * Size:	00010C
 */
void KingAi::initAI(King* king)
{
	mKing = king;
	mKing->setCurrentState(16);
	mKing->setNextState(16);
	mKing->mAnimator.startMotion(PaniMotionInfo(3, this));
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

/*
 * --INFO--
 * Address:	8016C404
 * Size:	00007C
 */
void KingAi::animationKeyUpdated(PaniAnimKeyEvent& event)
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

/*
 * --INFO--
 * Address:	8016C480
 * Size:	0001D0
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
		effectMgr->create(EffectMgr::EFF_King_Jump, mKing->mPosition, nullptr, nullptr);
		break;

	case KINGAI_EatThrowPiki:
		mKing->setMotionFinish(true);
		break;

	case KINGAI_Flick:
		fallBackSide();
		mKing->calcFlickPiki();
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mPosition, nullptr, nullptr);
		rumbleMgr->start(4, 0, mKing->mPosition);
		cameraMgr->startVibrationEvent(2, mKing->mPosition);
		break;

	case KINGAI_Appear:
		if (!mKing->needShadow()) {
			mapMgr->mShadowCaster.add(&mKing->mShadowCaster);
			mKing->setShadowNeed(true);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	8016C650
 * Size:	0000E4
 */
void KingAi::keyAction1()
{
	switch (mKing->getCurrentState()) {
	case KINGAI_Die:
		rumbleMgr->start(5, 0, mKing->mPosition);
		break;

	case KINGAI_Damage:
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mPosition, nullptr, nullptr);
		break;

	case KINGAI_BombDown:
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mPosition, nullptr, nullptr);
		break;

	case KINGAI_JumpAttack:
		fallBackSide();
		mKing->calcFlickPiki();
		rumbleMgr->start(5, 0, mKing->mPosition);
		cameraMgr->startVibrationEvent(2, mKing->mPosition);
		break;
	}
}

/*
 * --INFO--
 * Address:	8016C734
 * Size:	000050
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

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::keyAction3()
{
}

/*
 * --INFO--
 * Address:	8016C784
 * Size:	000014
 */
void KingAi::keyLoopEnd()
{
	mKing->addLoopCounter(1);
}

/*
 * --INFO--
 * Address:	8016C798
 * Size:	000090
 */
void KingAi::keyFinished()
{
	mKing->setMotionFinish(true);
	switch (mKing->getCurrentState()) {
	case KINGAI_Die:
		mKing->createPellet(mKing->mPosition, 300.0f, false);
		GameStat::killTekis.inc();
		mKing->doKill();
		break;

	case KINGAI_Swallow:
		killStickToMouthPiki();
		break;
	}
}

/*
 * --INFO--
 * Address:	8016C828
 * Size:	000044
 */
void KingAi::playSound(int kingSoundID)
{
	if (mKing->mSeContext) {
		mKing->mSeContext->playSound(kingSE[kingSoundID]);
	}
}

/*
 * --INFO--
 * Address:	8016C86C
 * Size:	000040
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

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void KingAi::setAttackPosition()
{
	mAttackPosition.x = mKing->mPosition.x + C_KING_PROP(mKing).mAttackDistance() * sinf(mKing->mFaceDirection);
	mAttackPosition.y = mKing->mPosition.y;
	mAttackPosition.z = mKing->mPosition.z + C_KING_PROP(mKing).mAttackDistance() * cosf(mKing->mFaceDirection);
}

/*
 * --INFO--
 * Address:	8016C8AC
 * Size:	000154
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

	mKing->mScale.set(xzScale, yScale, xzScale);
}

/*
 * --INFO--
 * Address:	8016CA00
 * Size:	000014
 */
void KingAi::startSpreadSaliva()
{
	mKing->mKingBody->mDoSpreadSalivaEffect = true;
}

/*
 * --INFO--
 * Address:	8016CA14
 * Size:	000014
 */
void KingAi::endSpreadSaliva()
{
	mKing->mKingBody->mDoSpreadSalivaEffect = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void KingAi::startFallSaliva()
{
	if (mAttackType != KINGATK_Jump) {
		mKing->mKingBody->mDoFallSalivaEffect = true;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void KingAi::endFallSaliva()
{
	mKing->mKingBody->mDoFallSalivaEffect = false;
}

/*
 * --INFO--
 * Address:	8016CA28
 * Size:	000480
 */
void KingAi::fallBackSide()
{
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi && navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(mKing->mPosition.x, mKing->mPosition.z, navi->mPosition.x, navi->mPosition.z)
		           < C_KING_PROP(mKing).mPressAttackRadius()) {
			// close enough, do actual distance check
			if (navi->mPosition.distance(mKing->mPosition) < C_KING_PROP(mKing).mPressAttackRadius()) {
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
		    && qdist2(mKing->mPosition.x, mKing->mPosition.z, piki->mPosition.x, piki->mPosition.z)
		           < C_KING_PROP(mKing).mPressAttackRadius()) {
			// close enough, do actual distance check
			if (piki->mPosition.distance(mKing->mPosition) < C_KING_PROP(mKing).mPressAttackRadius()) {
				InteractPress crush(mKing, 500.0f);
				piki->stimulate(crush);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void KingAi::setMouthCollPart(int partNum)
{
	mMouthSlotFlag |= (1 << partNum);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
int KingAi::getMouthCollPart(int partNum)
{
	return (mMouthSlotFlag >> partNum) & 1;
}

/*
 * --INFO--
 * Address:	8016CEA8
 * Size:	000460
 */
void KingAi::pikiStickToKingMouth()
{
	if (mIsTongueOut) {
		int stickMouthPikiNum = mKing->getStickMouthPikiCount();
		if (stickMouthPikiNum < C_KING_PROP(mKing).mMaxEatPikiNum()) {
			CollPart* slot1  = mKing->mCollInfo->getSphere('slt1');
			CollPart* slot2  = mKing->mCollInfo->getSphere('slt2');
			int slot1Num     = slot1->getChildCount();
			int slot2Num     = slot2->getChildCount();
			int lastSlot     = mMaxMouthSlots - 1;
			bool isMouthFull = false;

			Iterator iter(pikiMgr);
			CI_LOOP(iter)
			{
				// pretty sure this needs to be Creature* then cast to Piki at points, but the cast is never required?
				// idk what Nishimura was doing. maybe it was Piki* with a down cast? I can't get either to work properly
				Piki* piki = (Piki*)*iter;

				// Ignore invalid objects
				if (!piki) {
					continue;
				}

				// Ignore dead, invisible, buried, or already stuck piki
				if (!piki->isAlive() || !piki->isVisible() || piki->isBuried() || piki->getStickObject() == mKing) {
					continue;
				}

				// Check if piki is close enough to king's mouth and within the tongue range
				if (qdist2(piki->mPosition.x, piki->mPosition.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
				    && NsLibMath<f32>::abs(piki->mPosition.y - slot2->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY()) {
					// Increment the number of piki stuck in the king's mouth
					stickMouthPikiNum++;
					if (stickMouthPikiNum > C_KING_PROP(mKing).mMaxEatPikiNum()) {
						return;
					}

					// Check if the king's mouth is full
					if (isMouthFull) {
						InteractSwallow eat(mKing, slot1->getChildAt(0), 0);
						piki->stimulate(eat);
						continue;
					}

					// Randomly select slots to stick the piki in
					int randSlotIndex = NsMathI::getRand1(mMaxMouthSlots);
					for (int i = 0; i < mMaxMouthSlots; i++) {
						if (randSlotIndex > lastSlot) {
							randSlotIndex = 0;
						}

						// Check if the slot is already occupied
						if (!getMouthCollPart(randSlotIndex)) {
							// Stick the piki in the slot
							if (randSlotIndex < slot1Num) {
								InteractSwallow eat(mKing, slot1->getChildAt(randSlotIndex), 0);
								piki->stimulate(eat);
							} else {
								InteractSwallow eat(mKing, slot2->getChildAt(randSlotIndex - slot1Num), 0);
								piki->stimulate(eat);
							}

							setMouthCollPart(randSlotIndex);
							break;
						}

						// Check if the last slot has been reached
						if (i == lastSlot) {
							InteractSwallow eat(mKing, slot1->getChildAt(0), 0);
							piki->stimulate(eat);
							isMouthFull = true;
						}

						randSlotIndex++;
					}
				}
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stfd      f31, 0x120(r1)
	  stfd      f30, 0x118(r1)
	  stfd      f29, 0x110(r1)
	  stfd      f28, 0x108(r1)
	  stfd      f27, 0x100(r1)
	  stmw      r17, 0xC4(r1)
	  mr        r30, r3
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x438
	  lwz       r3, 0x4(r30)
	  bl        -0x1DE68
	  lwz       r4, 0x4(r30)
	  mr        r22, r3
	  lwz       r3, 0x224(r4)
	  lwz       r0, 0x3E0(r3)
	  cmpw      r22, r0
	  bge-      .loc_0x438
	  lis       r17, 0x736C
	  lwz       r3, 0x220(r4)
	  addi      r4, r17, 0x7431
	  bl        -0xE37F8
	  lwz       r4, 0x4(r30)
	  mr        r21, r3
	  lwz       r3, 0x220(r4)
	  addi      r4, r17, 0x7432
	  bl        -0xE380C
	  addi      r20, r3, 0
	  addi      r3, r21, 0
	  bl        -0xE5198
	  addi      r26, r3, 0
	  addi      r3, r20, 0
	  bl        -0xE51A4
	  lwz       r24, 0x3068(r13)
	  li        r31, 0
	  lwz       r4, 0x10(r30)
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  subi      r19, r4, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfd       f28, -0x5368(r2)
	  lis       r4, 0x802B
	  lfs       f29, -0x5370(r2)
	  lfs       f30, -0x5378(r2)
	  mr        r23, r3
	  lfs       f31, -0x536C(r2)
	  subi      r28, r5, 0x3064
	  lfs       f27, -0x5390(r2)
	  subi      r29, r4, 0x3244
	  lis       r27, 0x4330
	  b         .loc_0x3DC

	.loc_0xE4:
	  cmpwi     r23, -0x1
	  bne-      .loc_0x10C
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3
	  b         .loc_0x128

	.loc_0x10C:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3

	.loc_0x128:
	  cmplwi    r25, 0
	  addi      r17, r25, 0
	  beq-      .loc_0x3C0
	  mr        r3, r17
	  lwz       r12, 0x0(r17)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C0
	  mr        r3, r17
	  lwz       r12, 0x0(r17)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C0
	  mr        r3, r17
	  lwz       r12, 0x0(r17)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3C0
	  lwz       r0, 0x184(r25)
	  lwz       r18, 0x4(r30)
	  cmplw     r0, r18
	  beq-      .loc_0x3C0
	  lfs       f1, 0x94(r17)
	  lfs       f2, 0x9C(r17)
	  lfs       f3, 0x4(r20)
	  lfs       f4, 0xC(r20)
	  bl        -0x134A28
	  lwz       r3, 0x224(r18)
	  lfs       f0, 0x270(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3C0
	  lfs       f1, 0x98(r25)
	  lfs       f0, 0x8(r20)
	  lwz       r3, 0x4(r30)
	  fsubs     f1, f1, f0
	  lwz       r4, 0x224(r3)
	  fcmpo     cr0, f1, f27
	  addi      r3, r4, 0x280
	  ble-      .loc_0x1E0
	  b         .loc_0x1E4

	.loc_0x1E0:
	  fneg      f1, f1

	.loc_0x1E4:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3C0
	  lwz       r0, 0x3E0(r4)
	  addi      r22, r22, 0x1
	  cmpw      r22, r0
	  bgt-      .loc_0x438
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x24C
	  addi      r3, r21, 0
	  li        r4, 0
	  bl        -0xE52CC
	  lwz       r5, 0x4(r30)
	  li        r0, 0
	  addi      r4, r1, 0x88
	  stw       r28, 0x88(r1)
	  stw       r5, 0x8C(r1)
	  stw       r29, 0x88(r1)
	  stw       r0, 0x90(r1)
	  stw       r3, 0x94(r1)
	  mr        r3, r17
	  lwz       r12, 0x0(r17)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3C0

	.loc_0x24C:
	  lwz       r18, 0x10(r30)
	  bl        0xAAF78
	  xoris     r0, r3, 0x8000
	  stw       r0, 0xBC(r1)
	  xoris     r0, r18, 0x8000
	  li        r18, 0
	  stw       r27, 0xB8(r1)
	  lfd       f0, 0xB8(r1)
	  stw       r0, 0xB4(r1)
	  fsubs     f0, f0, f28
	  stw       r27, 0xB0(r1)
	  fdivs     f1, f0, f29
	  lfd       f0, 0xB0(r1)
	  fsubs     f0, f0, f28
	  fmuls     f1, f30, f1
	  fmuls     f0, f31, f0
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0xA8(r1)
	  lwz       r25, 0xAC(r1)
	  b         .loc_0x3B4

	.loc_0x2A0:
	  cmpw      r25, r19
	  ble-      .loc_0x2AC
	  li        r25, 0

	.loc_0x2AC:
	  lwz       r0, 0xC(r30)
	  sraw      r0, r0, r25
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x360
	  cmpw      r25, r26
	  bge-      .loc_0x308
	  addi      r3, r21, 0
	  addi      r4, r25, 0
	  bl        -0xE5388
	  lwz       r5, 0x4(r30)
	  li        r0, 0
	  addi      r4, r1, 0x78
	  stw       r28, 0x78(r1)
	  stw       r5, 0x7C(r1)
	  stw       r29, 0x78(r1)
	  stw       r0, 0x80(r1)
	  stw       r3, 0x84(r1)
	  mr        r3, r17
	  lwz       r12, 0x0(r17)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x348

	.loc_0x308:
	  addi      r3, r20, 0
	  sub       r4, r25, r26
	  bl        -0xE53CC
	  lwz       r5, 0x4(r30)
	  li        r0, 0
	  addi      r4, r1, 0x68
	  stw       r28, 0x68(r1)
	  stw       r5, 0x6C(r1)
	  stw       r29, 0x68(r1)
	  stw       r0, 0x70(r1)
	  stw       r3, 0x74(r1)
	  mr        r3, r17
	  lwz       r12, 0x0(r17)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x348:
	  li        r0, 0x1
	  lwz       r3, 0xC(r30)
	  slw       r0, r0, r25
	  or        r0, r3, r0
	  stw       r0, 0xC(r30)
	  b         .loc_0x3C0

	.loc_0x360:
	  cmpw      r18, r19
	  bne-      .loc_0x3AC
	  addi      r3, r21, 0
	  li        r4, 0
	  bl        -0xE542C
	  lwz       r5, 0x4(r30)
	  li        r0, 0
	  addi      r4, r1, 0x58
	  stw       r28, 0x58(r1)
	  stw       r5, 0x5C(r1)
	  stw       r29, 0x58(r1)
	  stw       r0, 0x60(r1)
	  stw       r3, 0x64(r1)
	  mr        r3, r17
	  lwz       r12, 0x0(r17)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0x1

	.loc_0x3AC:
	  addi      r25, r25, 0x1
	  addi      r18, r18, 0x1

	.loc_0x3B4:
	  lwz       r0, 0x10(r30)
	  cmpw      r18, r0
	  blt+      .loc_0x2A0

	.loc_0x3C0:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r23, r3

	.loc_0x3DC:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x404
	  li        r0, 0x1
	  b         .loc_0x430

	.loc_0x404:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x42C
	  li        r0, 0x1
	  b         .loc_0x430

	.loc_0x42C:
	  li        r0, 0

	.loc_0x430:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xE4

	.loc_0x438:
	  lmw       r17, 0xC4(r1)
	  lwz       r0, 0x12C(r1)
	  lfd       f31, 0x120(r1)
	  lfd       f30, 0x118(r1)
	  lfd       f29, 0x110(r1)
	  lfd       f28, 0x108(r1)
	  lfd       f27, 0x100(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016D308
 * Size:	0002A8
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
				if ((qdist2(bomb->mPosition.x, bomb->mPosition.z, slot1->mCentre.x, slot1->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
				     && NsLibMath<f32>::abs(bomb->mPosition.y - slot1->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())
				    || (qdist2(bomb->mPosition.x, bomb->mPosition.z, slot2->mCentre.x, slot2->mCentre.z)
				            < C_KING_PROP(mKing).mTongueRangeXZ()
				        && NsLibMath<f32>::abs(bomb->mPosition.y - slot2->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())) {
					InteractBomb blast(mKing, 100.0f, nullptr);
					bomb->stimulate(blast);
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8016D5B0
 * Size:	00002C
 */
void KingAi::killStickToMouthPiki()
{
	mMouthSlotFlag = 0;
	mKing->killStickToMouthPiki();
}

/*
 * --INFO--
 * Address:	8016D5DC
 * Size:	000290
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
			if ((qdist2(navi->mPosition.x, navi->mPosition.z, slot1->mCentre.x, slot1->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
			     && NsLibMath<f32>::abs(navi->mPosition.y - slot1->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())
			    || (qdist2(navi->mPosition.x, navi->mPosition.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing).mTongueRangeXZ()
			        && NsLibMath<f32>::abs(navi->mPosition.y - slot2->mCentre.y) < C_KING_PROP(mKing).mTongueRangeY())) {
				InteractAttack blast(mKing, nullptr, C_KING_PROP(mKing).mTongueDamageNavi(), false);
				navi->stimulate(blast);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void KingAi::setDispelParm(Creature* target, f32 distance)
{
	f32 knockback
	    = ((C_KING_PROP(mKing).mDispelRadius() - distance) / C_KING_PROP(mKing).mDispelRadius()) * C_KING_PROP(mKing).mDispelPower();
	InteractFlick flick(mKing, knockback, C_KING_PROP(mKing).mDispelDamage(), FLICK_BACKWARDS_ANGLE);
	target->stimulate(flick);
}

/*
 * --INFO--
 * Address:	8016D86C
 * Size:	0004B8
 */
void KingAi::dispelNaviPiki()
{
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi && navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(navi->mPosition.x, navi->mPosition.z, mKing->mPosition.x, mKing->mPosition.z) < C_KING_PROP(mKing).mDispelRadius()) {
			f32 dist = navi->mPosition.distance(mKing->mPosition);
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
		    && qdist2(piki->mPosition.x, piki->mPosition.z, mKing->mPosition.x, mKing->mPosition.z) < C_KING_PROP(mKing).mDispelRadius()) {
			f32 dist = piki->mPosition.distance(mKing->mPosition);
			if (dist < C_KING_PROP(mKing).mDispelRadius()) {
				setDispelParm(piki, dist);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8016DD24
 * Size:	000120
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

/*
 * --INFO--
 * Address:	8016DE44
 * Size:	000284
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

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
void KingAi::setBombDamageLoopCounter()
{
	mEatBombDamageCounter = 0;
	setDamageLoopCounter(mBombDamageCounter, C_KING_PROP(mKing).mHitTongueBombsMin(), C_KING_PROP(mKing).mHitTongueBombsMax(),
	                     C_KING_PROP(mKing).mHitBombDamageLoopMin(), C_KING_PROP(mKing).mHitBombDamageLoopMid(),
	                     C_KING_PROP(mKing).mHitBombDamageLoopMax());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void KingAi::setMoveVelocity(f32 speed)
{
	mKing->mKingBody->mMoveSpeed = speed;
}

/*
 * --INFO--
 * Address:	8016E0C8
 * Size:	000118
 */
void KingAi::setAttackPriority()
{
	mAttackType = KINGATK_Tongue;
	if (mKing->getCurrentLife() < mKing->getMaxLife() * C_KING_PROP(mKing).mJumpAttackHealthThreshold()) {
		f32 factor        = (f32)mEatBombDamageCounter * C_KING_PROP(mKing).mJumpAttackEatBombFactor();
		f32 boundedFactor = NsLibMath<f32>::revice(factor, 0.0f, 1.0f);

		f32 jumpChance = boundedFactor * C_KING_PROP(mKing).mJumpAttackEatBombChance()
		               + (1.0f - boundedFactor) * C_KING_PROP(mKing).mJumpAttackNoEatBombChance();
		if (NsMathF::getRand1(1.0f) < jumpChance) {
			mAttackType           = KINGATK_Jump;
			mConsecutiveJumpCount = 0;
			endFallSaliva();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void KingAi::resetAttackPriority()
{
	if (mAttackType == KINGATK_Jump && mKing->getCurrentState() != KINGAI_JumpAttack
	    && mKing->getCurrentLife() > mKing->getMaxLife() * C_KING_PROP(mKing).mJumpAttackHealthThreshold()) {
		mAttackType = true;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void KingAi::resultFlagOn()
{
	if (mKing->insideAndInSearch()) {
		playerState->mResultFlags.setOn(RESFLAG_Unk49);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void KingAi::resultFlagSeen()
{
	playerState->mResultFlags.setSeen(RESFLAG_Unk49);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
bool KingAi::attackInArea(Creature* target, Vector3f* centre)
{
	if (qdist2(target->mPosition.x, target->mPosition.z, centre->x, centre->z) < C_KING_PROP(mKing).mAttackTerritoryRadius()
	    && qdist2(target->mPosition.x, target->mPosition.z, mAttackPosition.x, mAttackPosition.z)
	           < C_KING_PROP(mKing).mNormalAttackRangeXZ()
	    && NsLibMath<f32>::abs(target->mPosition.y - mAttackPosition.y) < C_KING_PROP(mKing).mNormalAttackRangeY()) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8016E1E0
 * Size:	0000CC
 */
bool KingAi::inJumpAngle(Creature* target)
{
	f32 dir = NsMathF::calcNearerDirection(mKing->mFaceDirection,
	                                       atan2f(target->mPosition.x - mKing->mPosition.x, target->mPosition.z - mKing->mPosition.z));
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

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
bool KingAi::jumpAttackInArea(Creature* target, Vector3f* centre)
{
	if (qdist2(target->mPosition.x, target->mPosition.z, centre->x, centre->z) < C_KING_PROP(mKing).mAttackTerritoryRadius()
	    && qdist2(target->mPosition.x, target->mPosition.z, mKing->mPosition.x, mKing->mPosition.z)
	           < C_KING_PROP(mKing).mJumpAttackRangeXZ()
	    && NsLibMath<f32>::abs(target->mPosition.y - mAttackPosition.y) < C_KING_PROP(mKing).mNormalAttackRangeY() && inJumpAngle(target)) {
		mKing->setTargetCreature(target);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KingAi::dieTransit()
{
	return !mKing->getAlive();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000158
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

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
bool KingAi::bombDownTransit()
{
	if (mBombDamageCounter > 0) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool KingAi::isMotionFinishTransit()
{
	return mKing->getMotionFinish();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KingAi::outSideChaseRangeTransit()
{
	return mKing->outSideChaseRangeTransit();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KingAi::inSideWaitRangeTransit()
{
	return mKing->inSideWaitRangeTransit();
}

/*
 * --INFO--
 * Address:	8016E2F4
 * Size:	0000CC
 */
bool KingAi::inTurnAngleTransit()
{
	Vector3f* targetPos = mKing->getTargetPosition();
	f32 angle           = atan2f(targetPos->x - mKing->mPosition.x, targetPos->z - mKing->mPosition.z);
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
	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	8016E3C0
 * Size:	000300
 */
bool KingAi::chaseNaviTransit()
{
	Creature* target = nullptr;
	f32 dist;
	f32 minDist = 12800.0f;
	if (mKing->getTargetCreature()) {
		minDist = mKing->mPosition.distance(mKing->getTargetCreature()->mPosition);
	}

	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {

			f32 qdist = qdist2(mKing->mPosition.x, mKing->mPosition.z, navi->mPosition.x, navi->mPosition.z);
			if (qdist < C_BOSS_PROP(mKing).mSearchRadius() &&
			    // typo?? this should be qdist, not dist.
			    dist < minDist && mKing->inSearchAngle(navi)) {
				dist = mKing->mPosition.distance(navi->mPosition);
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

/*
 * --INFO--
 * Address:	8016E6C0
 * Size:	00030C
 */
bool KingAi::chasePikiTransit()
{
	Creature* target = nullptr;
	f32 dist;
	f32 minDist = 12800.0f;
	if (mKing->getTargetCreature()) {
		minDist = mKing->mPosition.distance(mKing->getTargetCreature()->mPosition);
	}

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->getStickObject() != mKing) {
			f32 qdist = qdist2(mKing->mPosition.x, mKing->mPosition.z, piki->mPosition.x, piki->mPosition.z);
			if (qdist < C_BOSS_PROP(mKing).mSearchRadius() &&
			    // typo?? this should be qdist, not dist - they definitely copied and pasted this code lol.
			    dist < minDist && mKing->inSearchAngle(piki)) {
				dist = mKing->mPosition.distance(piki->mPosition);
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

/*
 * --INFO--
 * Address:	8016E9CC
 * Size:	0003E0
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

/*
 * --INFO--
 * Address:	........
 * Size:	000194
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

/*
 * --INFO--
 * Address:	8016EDAC
 * Size:	000448
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

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
bool KingAi::swallowTransit()
{
	if (mMouthSlotFlag > 0) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8016F1F4
 * Size:	0002B8
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
			if (piki && piki->isAlive() && piki->getStickObject() != mKing && piki->mPosition.y > minAttackHeight
			    && qdist2(piki->mPosition.x, piki->mPosition.z, attackCentre.x, attackCentre.z) < slotRad) {
				// check actual distance
				if (piki->mPosition.distance(attackCentre) < slotRad) {
					InteractSwallow eat(mKing, slot3, 0);
					piki->stimulate(eat);
					result = true;
				}
			}
		}
	}

	return result;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KingAi::flickTransit()
{
	return mKing->flickPikiTransit();
}

/*
 * --INFO--
 * Address:	8016F4AC
 * Size:	000190
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

		f32 dist = mKing->mPosition.distance(target->mPosition);
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

/*
 * --INFO--
 * Address:	8016F63C
 * Size:	00040C
 */
bool KingAi::appearTransit()
{
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(navi->mPosition.x, navi->mPosition.z, mKing->mPosition.x, mKing->mPosition.z)
		           < C_KING_PROP(mKing).mDetectionRadius()) {
			// close enough, check actual distance
			if (navi->mPosition.distance(mKing->mPosition) < C_KING_PROP(mKing).mDetectionRadius()) {
				return true;
			}
		}
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mPosition.x, piki->mPosition.z, mKing->mPosition.x, mKing->mPosition.z)
		           < C_KING_PROP(mKing).mDetectionRadius()) {
			// close enough, check actual distance
			if (piki->mPosition.distance(mKing->mPosition) < C_KING_PROP(mKing).mDetectionRadius()) {
				return true;
			}
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	8016FA48
 * Size:	00014C
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
	mKing->mAnimator.startMotion(PaniMotionInfo(0, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	mKing->mPlatMgr.release();
	resultFlagSeen();
	effectMgr->create(EffectMgr::EFF_King_DeadB, mKing->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadD, mKing->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadC, mKing->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadA, mKing->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_DeadE, mKing->mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C8
 */
void KingAi::initDamage(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	setEatDamageLoopCounter();
	setMoveVelocity(0.0f);
	mKing->mAnimator.startMotion(PaniMotionInfo(1, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
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
	mKing->mAnimator.startMotion(PaniMotionInfo(14, this));
	mKing->mKingBody->initBlending(3.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void KingAi::initWalkRandom(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// if we're not chasing a navi or piki, essentially.
		mKing->mAnimator.startMotion(PaniMotionInfo(6, this));
		mKing->setAnimTimer(30.0f);
	}
	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void KingAi::initWalkGoHome(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// i.e. not chasing piki or navi
		mKing->mAnimator.startMotion(PaniMotionInfo(6, this));
		mKing->setAnimTimer(30.0f);
	}

	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void KingAi::initChaseNavi(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// i.e. not chaseNavi or chasePiki
		mKing->mAnimator.startMotion(PaniMotionInfo(6, this));
		mKing->setAnimTimer(30.0f);
	}

	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void KingAi::initChasePiki(int nextState, bool doBlending)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	if (mKing->getCurrentState() < KINGAI_WalkRandom || mKing->getCurrentState() > KINGAI_WalkGoHome) {
		// i.e. not chaseNavi or chasePiki
		mKing->mAnimator.startMotion(PaniMotionInfo(6, this));
		mKing->setAnimTimer(30.0f);
	}

	if (doBlending) {
		mKing->mKingBody->initBlending(3.0f);
	}

	setMoveVelocity(C_KING_PROP(mKing).mKingWalkSpeed());
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void KingAi::initHomeTurn(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->mAnimator.startMotion(PaniMotionInfo(4, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void KingAi::initChaseTurn(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(4, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void KingAi::initAttack(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mIsTongueOut       = false;
	mBombDamageCounter = 0;
	mKing->mAnimator.startMotion(PaniMotionInfo(8, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void KingAi::initJumpAttack(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(13, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
	mJumpAttackStartPosition = mKing->mPosition;
	if (mKing->getTargetCreature()) {
		mJumpAttackTargetPosition = mKing->getTargetCreature()->mPosition;
		mKing->setTargetCreature(nullptr);
	} else {
		mJumpAttackTargetPosition = mKing->mPosition;
	}

	mConsecutiveJumpCount++;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void KingAi::initSwallow(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(10, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void KingAi::initEatThrowPiki(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->mAnimator.startMotion(PaniMotionInfo(11, this));
	mKing->mKingBody->initBlending(6.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000198
 */
void KingAi::initFlick(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->mAnimator.startMotion(PaniMotionInfo(9, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	setAttackPriority();
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void KingAi::initWaveNeck(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->mAnimator.startMotion(PaniMotionInfo(5, this));
	mKing->mKingBody->initBlending(3.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	8016FB94
 * Size:	00016C
 */
void KingAi::initAppear(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->mIsBossBgm = true;
	mKing->setInvincible(false);
	mKing->setIsOrganic(true);
	dispelNaviPiki();
	mKing->mAnimator.startMotion(PaniMotionInfo(12, this));
	mKing->mKingBody->initBlending(10.0f);
	setMoveVelocity(0.0f);
	resultFlagOn();
	effectMgr->create(EffectMgr::EFF_King_AppearB, mKing->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_AppearC, mKing->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_AppearA, mKing->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_King_AppearD, mKing->mPosition, nullptr, nullptr);
	rumbleMgr->start(5, 0, mKing->mPosition);
	cameraMgr->startVibrationEvent(4, mKing->mPosition);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void KingAi::initStay(int nextState)
{
	mKing->setNextState(nextState);
	mKing->setMotionFinish(false);
	mKing->setLoopCounter(0);
	mKing->setTargetCreature(nullptr);
	mKing->setAttackTimer(0.0f);
	mKing->mAnimator.startMotion(PaniMotionInfo(3, this));
	mKing->mKingBody->initBlending(15.0f);
	setMoveVelocity(0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void KingAi::dieState()
{
	mKing->setIsAlive(true); // ?
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void KingAi::damageState()
{
	if (mKing->getLoopCounter() >= mDamageLoopCounter) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void KingAi::bombDownState()
{
	if (mKing->getLoopCounter() >= mDamageLoopCounter) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void KingAi::walkRandomState()
{
	mKing->makeTargetRandom(30.0f);
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void KingAi::walkGoHomeState()
{
	mKing->setTargetPosition(*mKing->getInitPosition());
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void KingAi::homeTurnState()
{
	mKing->setTargetPosition(*mKing->getInitPosition());
	mKing->stopMovement();
	mKing->changeDirection(C_KING_PROP(mKing).mTurningTurnSpeed());
	if (!inTurnAngleTransit()) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
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
		mKing->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void KingAi::chaseNaviState()
{
	mKing->makeTargetCreature();
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void KingAi::chasePikiState()
{
	mKing->makeTargetCreature();
	mKing->changeDirection(C_KING_PROP(mKing).mWalkingTurnSpeed());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void KingAi::attackState()
{
	mKing->makeTargetCreature();
	pikiStickToKingMouth();
	tongueBombExplosion();
	if (mKing->getLoopCounter() >= C_KING_PROP(mKing).mTongueRollLoopCount()) {
		mKing->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void KingAi::jumpAttackState()
{
	if (mKing->mAnimator.mAnimationCounter > 41.0f && mKing->mAnimator.mAnimationCounter < 79.0f) {
		f32 diff           = (mKing->mAnimator.mAnimationCounter - 41.0f);
		f32 diff2          = 79.0f - 41.0f;
		f32 ratio          = diff / diff2;
		f32 complRatio     = 1.0f - ratio;
		mKing->mPosition.x = ratio * mJumpAttackTargetPosition.x + complRatio * mJumpAttackStartPosition.x;
		mKing->mPosition.z = ratio * mJumpAttackTargetPosition.z + complRatio * mJumpAttackStartPosition.z;
		mKing->mPosition.y = mapMgr->getMinY(mKing->mPosition.x, mKing->mPosition.z, true);
		mKing->changeDirection(C_KING_PROP(mKing).mTurningTurnSpeed());
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::swallowState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::eatThrowPikiState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::flickState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::waitState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::waveNeckState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::appearState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KingAi::stayState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	00012C
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

/*
 * --INFO--
 * Address:	........
 * Size:	00033C
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

/*
 * --INFO--
 * Address:	8016FD00
 * Size:	003084
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
