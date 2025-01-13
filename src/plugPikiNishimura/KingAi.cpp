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
DEFINE_ERROR();

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
	_08            = 1;
	_09            = 0;
	CollPart* slt1 = mKing->mCollInfo->getSphere('slt1');
	CollPart* slt2 = mKing->mCollInfo->getSphere('slt2');

	_10                     = slt1->getChildCount() + slt2->getChildCount();
	mMouthSlotFlag          = 0;
	_18                     = 0;
	mBombDamageCounter      = 0;
	mEatBombDamageCounter   = 0;
	mDamageScaleOscillation = 0.0f;
	_28                     = PI * (C_KING_PROP(mKing)._3C4() / 360.0f);
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
	case 0:
		mKing->mKingBody->createUfoParts();
		break;

	case 1:
		killStickToMouthPiki();
		mKing->mKingBody->setEatBombEffect();
		break;

	case 2:
		CollPart* nosePart = mKing->mCollInfo->getSphere('nose');
		if (nosePart) {
			Vector3f nosePos(nosePart->mCentre);
			effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, nosePos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, nosePos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, nosePos, nullptr, nullptr);
		}
		mKing->mKingBody->setSeedFlashEffect();
		break;

	case 5:
		_09 = true;
		tongueAttackNavi();
		break;

	case 6:
		effectMgr->create(EffectMgr::EFF_King_Jump, mKing->mPosition, nullptr, nullptr);
		break;

	case 8:
		mKing->setMotionFinish(true);
		break;

	case 13:
		fallBackSide();
		mKing->calcFlickPiki();
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mPosition, nullptr, nullptr);
		rumbleMgr->start(4, 0, mKing->mPosition);
		cameraMgr->startVibrationEvent(2, mKing->mPosition);
		break;

	case 15:
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
	case 0:
		rumbleMgr->start(5, 0, mKing->mPosition);
		break;

	case 1:
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mPosition, nullptr, nullptr);
		break;

	case 2:
		effectMgr->create(EffectMgr::EFF_King_Flick, mKing->mPosition, nullptr, nullptr);
		break;

	case 6:
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
	case 0:
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
	case 0:
		mKing->createPellet(mKing->mPosition, 300.0f, false);
		GameStat::killTekis.inc();
		mKing->doKill();
		break;

	case 7:
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
	if (mKing->getCurrentState() == 5) {
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
	mAttackPosition.x = mKing->mPosition.x + C_KING_PROP(mKing).mAttackDistance() * sinf(mKing->mDirection);
	mAttackPosition.y = mKing->mPosition.y;
	mAttackPosition.z = mKing->mPosition.z + C_KING_PROP(mKing).mAttackDistance() * cosf(mKing->mDirection);
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
	if (_08) {
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
	if (_09) {
		int stickMouthPikiNum = mKing->getStickMouthPikiCount();
		if (stickMouthPikiNum < C_KING_PROP(mKing)._3D4()) {
			CollPart* slot1 = mKing->mCollInfo->getSphere('slt1');
			CollPart* slot2 = mKing->mCollInfo->getSphere('slt2');
			int slot1Num    = slot1->getChildCount();
			int slot2Num    = slot2->getChildCount();
			int lastSlot    = _10 - 1;
			bool check      = false;

			Iterator iter(pikiMgr);
			CI_LOOP(iter)
			{
				Piki* piki = static_cast<Piki*>(*iter);
				if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->getStickObject() != mKing
				    && qdist2(piki->mPosition.x, piki->mPosition.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing)._264()
				    && NsLibMath<f32>::abs(piki->mPosition.y - slot2->mCentre.y) < C_KING_PROP(mKing)._274()) {
					stickMouthPikiNum++;
					if (stickMouthPikiNum > C_KING_PROP(mKing)._3D4()) {
						return;
					}

					if (check) {
						InteractSwallow eat(mKing, slot1->getChildAt(0), 0);
						piki->stimulate(eat);
						continue;
					}

					int randMouthPart = NsMathI::getRand1(_10);
					for (int i = 0; i < _10; i++) {
						if (randMouthPart > lastSlot) {
							randMouthPart = 0;
						}

						if (!getMouthCollPart(randMouthPart)) {
							if (randMouthPart < slot1Num) {
								InteractSwallow eat(mKing, slot1->getChildAt(randMouthPart), 0);
								piki->stimulate(eat);
							} else {
								InteractSwallow eat(mKing, slot2->getChildAt(randMouthPart - slot1Num), 0);
								piki->stimulate(eat);
							}
							setMouthCollPart(randMouthPart);
						}

						if (i == lastSlot) {
							InteractSwallow eat(mKing, slot1->getChildAt(0), 0);
							piki->stimulate(eat);
							check = true;
						}
						randMouthPart++;
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
	if (_09) {
		CollPart* slot1 = mKing->mCollInfo->getSphere('slt1');
		CollPart* slot2 = mKing->mCollInfo->getSphere('slt2');
		Iterator iter(itemMgr);
		CI_LOOP(iter)
		{
			Creature* bomb = *iter;
			if (bomb && !bomb->isAlive() && !bomb->isVisible() && !bomb->isBuried() && bomb->mObjType == OBJTYPE_Bomb) {
				if ((qdist2(bomb->mPosition.x, bomb->mPosition.z, slot1->mCentre.x, slot1->mCentre.z) < C_KING_PROP(mKing)._264()
				     && NsLibMath<f32>::abs(bomb->mPosition.y - slot1->mCentre.y) < C_KING_PROP(mKing)._274())
				    || (qdist2(bomb->mPosition.x, bomb->mPosition.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing)._264()
				        && NsLibMath<f32>::abs(bomb->mPosition.y - slot2->mCentre.y) < C_KING_PROP(mKing)._274())) {
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
			if ((qdist2(navi->mPosition.x, navi->mPosition.z, slot1->mCentre.x, slot1->mCentre.z) < C_KING_PROP(mKing)._264()
			     && NsLibMath<f32>::abs(navi->mPosition.y - slot1->mCentre.y) < C_KING_PROP(mKing)._274())
			    || (qdist2(navi->mPosition.x, navi->mPosition.z, slot2->mCentre.x, slot2->mCentre.z) < C_KING_PROP(mKing)._264()
			        && NsLibMath<f32>::abs(navi->mPosition.y - slot2->mCentre.y) < C_KING_PROP(mKing)._274())) {
				InteractAttack blast(mKing, nullptr, C_KING_PROP(mKing)._2A4(), false);
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
void KingAi::setDispelParm(Creature* target, f32 p2)
{
	f32 knockback = ((C_KING_PROP(mKing)._2E4() - p2) / C_KING_PROP(mKing)._2E4()) * C_KING_PROP(mKing)._2F4();
	InteractFlick flick(mKing, knockback, C_KING_PROP(mKing)._304(), FLICK_BACKWARDS_ANGLE);
	target->stimulate(flick);
	// UNUSED FUNCTION
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
		    && qdist2(navi->mPosition.x, navi->mPosition.z, mKing->mPosition.x, mKing->mPosition.z) < C_KING_PROP(mKing)._2E4()) {
			f32 dist = navi->mPosition.distance(mKing->mPosition);
			if (dist < C_KING_PROP(mKing)._2E4()) {
				setDispelParm(navi, dist);
			}
		}
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mPosition.x, piki->mPosition.z, mKing->mPosition.x, mKing->mPosition.z) < C_KING_PROP(mKing)._2E4()) {
			f32 dist = piki->mPosition.distance(mKing->mPosition);
			if (dist < C_KING_PROP(mKing)._2E4()) {
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
	setDamageLoopCounter(mBombDamageCounter, C_KING_PROP(mKing)._434(), C_KING_PROP(mKing)._444(), C_KING_PROP(mKing)._454(),
	                     C_KING_PROP(mKing)._464(), C_KING_PROP(mKing)._474());
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
	_08 = 1;
	if (mKing->getCurrentLife() < mKing->getMaxLife() * C_KING_PROP(mKing).mJumpAttackHealthThreshold()) {
		f32 factor        = (f32)mEatBombDamageCounter * C_KING_PROP(mKing).mJumpAttackEatBombFactor();
		f32 boundedFactor = NsLibMath<f32>::revice(factor, 0.0f, 1.0f);

		f32 jumpChance = boundedFactor * C_KING_PROP(mKing).mJumpAttackEatBombChance()
		               + (1.0f - boundedFactor) * C_KING_PROP(mKing).mJumpAttackNoEatBombChance();
		if (NsMathF::getRand1(1.0f) < jumpChance) {
			_08 = 0;
			_18 = 0;
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
	if (!_08 && mKing->getCurrentState() != KINGAI_JumpAttack
	    && mKing->getCurrentLife() > mKing->getMaxLife() * C_KING_PROP(mKing).mJumpAttackHealthThreshold()) {
		_08 = true;
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
bool KingAi::attackInArea(Creature* target, Vector3f* attackPos)
{
	f32 dist = qdist2(target->mPosition.x, target->mPosition.z, attackPos->x, attackPos->z);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016E1E0
 * Size:	0000CC
 */
bool KingAi::inJumpAngle(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r3, 0x4(r3)
	  lfs       f3, 0x94(r4)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r4)
	  lfs       f0, 0x9C(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xAD7E8
	  lwz       r3, 0x4(r31)
	  lfs       f4, 0xA0(r3)
	  fcmpo     cr0, f1, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x64
	  fsubs     f3, f1, f4
	  lfs       f2, -0x537C(r2)
	  fsubs     f0, f2, f3
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x7C
	  fsubs     f1, f1, f2
	  b         .loc_0x7C

	.loc_0x64:
	  fsubs     f3, f4, f1
	  lfs       f2, -0x537C(r2)
	  fsubs     f0, f2, f3
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x7C
	  fadds     f1, f1, f2

	.loc_0x7C:
	  fcmpo     cr0, f1, f4
	  ble-      .loc_0x9C
	  fsubs     f1, f1, f4
	  lfs       f0, 0x28(r31)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB4
	  li        r3, 0x1
	  b         .loc_0xB8

	.loc_0x9C:
	  fsubs     f1, f4, f1
	  lfs       f0, 0x28(r31)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB4
	  li        r3, 0x1
	  b         .loc_0xB8

	.loc_0xB4:
	  li        r3, 0

	.loc_0xB8:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
bool KingAi::jumpAttackInArea(Creature*, Vector3f*)
{
	// UNUSED FUNCTION
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
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
bool KingAi::bombDownTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool KingAi::isMotionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KingAi::outSideChaseRangeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KingAi::inSideWaitRangeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016E2F4
 * Size:	0000CC
 */
bool KingAi::inTurnAngleTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r4, 0x4(r3)
	  lfs       f1, 0x94(r4)
	  lfs       f3, 0x30C(r4)
	  lfs       f2, 0x314(r4)
	  lfs       f0, 0x9C(r4)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xAD6D4
	  lwz       r3, 0x4(r31)
	  lfs       f4, 0xA0(r3)
	  fcmpo     cr0, f1, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x64
	  fsubs     f3, f1, f4
	  lfs       f2, -0x537C(r2)
	  fsubs     f0, f2, f3
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x7C
	  fsubs     f1, f1, f2
	  b         .loc_0x7C

	.loc_0x64:
	  fsubs     f3, f4, f1
	  lfs       f2, -0x537C(r2)
	  fsubs     f0, f2, f3
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x7C
	  fadds     f1, f1, f2

	.loc_0x7C:
	  fcmpo     cr0, f1, f4
	  ble-      .loc_0x9C
	  fsubs     f1, f1, f4
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  li        r3, 0x1
	  b         .loc_0xB8

	.loc_0x9C:
	  fsubs     f1, f4, f1
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  li        r3, 0x1
	  b         .loc_0xB8

	.loc_0xB4:
	  li        r3, 0

	.loc_0xB8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016E3C0
 * Size:	000300
 */
bool KingAi::chaseNaviTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stfd      f30, 0xC8(r1)
	  stfd      f29, 0xC0(r1)
	  stmw      r27, 0xAC(r1)
	  mr        r28, r3
	  li        r29, 0
	  lwz       r5, 0x4(r3)
	  lfs       f29, -0x534C(r2)
	  lwz       r3, 0x318(r5)
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  lfs       f0, -0x5390(r2)
	  addi      r4, r3, 0x94
	  stfs      f0, 0x90(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x94(r5)
	  lfs       f4, 0x8(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r5)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0x98(r5)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x64(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x64(r1)
	  stfs      f0, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f3, 0x90(r1)
	  lfs       f1, 0x88(r1)
	  lfs       f0, 0x8C(r1)
	  lfs       f2, 0x90(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x160824
	  fmr       f29, f1

	.loc_0xAC:
	  lwz       r31, 0x3120(r13)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r30, r3
	  b         .loc_0x268

	.loc_0xD0:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xF8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x114

	.loc_0xF8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x114:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x24C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x24C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x24C
	  lwz       r3, 0x4(r28)
	  lfs       f3, 0x94(r27)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f4, 0x9C(r27)
	  bl        -0x135F14
	  lwz       r3, 0x4(r28)
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x88(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x24C
	  fcmpo     cr0, f30, f29
	  bge-      .loc_0x24C
	  mr        r4, r27
	  bl        -0x1F690
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x24C
	  lwz       r3, 0x4(r28)
	  stfs      f31, 0x7C(r1)
	  stfs      f31, 0x78(r1)
	  stfs      f31, 0x74(r1)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x94(r27)
	  lfs       f4, 0x9C(r27)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r27)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x5C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x74(r1)
	  stfs      f1, 0x78(r1)
	  stfs      f3, 0x7C(r1)
	  lfs       f1, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  lfs       f2, 0x7C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x160994
	  lwz       r3, 0x4(r28)
	  fmr       f30, f1
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x2A0(r4)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x24C
	  lfs       f0, 0x88(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x24C
	  fcmpo     cr0, f1, f29
	  bge-      .loc_0x24C
	  fmr       f29, f1
	  mr        r29, r27

	.loc_0x24C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x268:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x290
	  li        r0, 0x1
	  b         .loc_0x2BC

	.loc_0x290:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2B8
	  li        r0, 0x1
	  b         .loc_0x2BC

	.loc_0x2B8:
	  li        r0, 0

	.loc_0x2BC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD0
	  cmplwi    r29, 0
	  beq-      .loc_0x2DC
	  lwz       r4, 0x4(r28)
	  li        r3, 0x1
	  stw       r29, 0x318(r4)
	  b         .loc_0x2E0

	.loc_0x2DC:
	  li        r3, 0

	.loc_0x2E0:
	  lmw       r27, 0xAC(r1)
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  lfd       f30, 0xC8(r1)
	  lfd       f29, 0xC0(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016E6C0
 * Size:	00030C
 */
bool KingAi::chasePikiTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stfd      f30, 0xD0(r1)
	  stfd      f29, 0xC8(r1)
	  stmw      r27, 0xB4(r1)
	  mr        r28, r3
	  li        r29, 0
	  lwz       r5, 0x4(r3)
	  lfs       f29, -0x534C(r2)
	  lwz       r3, 0x318(r5)
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  lfs       f0, -0x5390(r2)
	  addi      r4, r3, 0x94
	  stfs      f0, 0x94(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f0, 0x8C(r1)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x94(r5)
	  lfs       f4, 0x8(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r5)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0x98(r5)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x68(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f1, 0x90(r1)
	  stfs      f3, 0x94(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, 0x90(r1)
	  lfs       f2, 0x94(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x160B24
	  fmr       f29, f1

	.loc_0xAC:
	  lwz       r31, 0x3068(r13)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r30, r3
	  b         .loc_0x274

	.loc_0xD0:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xF8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x114

	.loc_0xF8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x114:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x258
	  lwz       r0, 0x184(r27)
	  lwz       r3, 0x4(r28)
	  cmplw     r0, r3
	  beq-      .loc_0x258
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f3, 0x94(r27)
	  lfs       f4, 0x9C(r27)
	  bl        -0x136220
	  lwz       r3, 0x4(r28)
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x88(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x258
	  fcmpo     cr0, f30, f29
	  bge-      .loc_0x258
	  mr        r4, r27
	  bl        -0x1F99C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  lwz       r3, 0x4(r28)
	  stfs      f31, 0x80(r1)
	  stfs      f31, 0x7C(r1)
	  stfs      f31, 0x78(r1)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x94(r27)
	  lfs       f4, 0x9C(r27)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r27)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x60(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f3, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  lfs       f2, 0x80(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x160CA0
	  lwz       r3, 0x4(r28)
	  fmr       f30, f1
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x2A0(r4)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x258
	  lfs       f0, 0x88(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x258
	  fcmpo     cr0, f1, f29
	  bge-      .loc_0x258
	  fmr       f29, f1
	  mr        r29, r27

	.loc_0x258:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x274:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x29C
	  li        r0, 0x1
	  b         .loc_0x2C8

	.loc_0x29C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2C4
	  li        r0, 0x1
	  b         .loc_0x2C8

	.loc_0x2C4:
	  li        r0, 0

	.loc_0x2C8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD0
	  cmplwi    r29, 0
	  beq-      .loc_0x2E8
	  lwz       r4, 0x4(r28)
	  li        r3, 0x1
	  stw       r29, 0x318(r4)
	  b         .loc_0x2EC

	.loc_0x2E8:
	  li        r3, 0

	.loc_0x2EC:
	  lmw       r27, 0xB4(r1)
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lfd       f29, 0xC8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016E9CC
 * Size:	0003E0
 */
bool KingAi::attackTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stmw      r27, 0xA4(r1)
	  mr        r28, r3
	  lbz       r0, 0x8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C4
	  lwz       r31, 0x3120(r13)
	  lwz       r4, 0x4(r28)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  addi      r29, r4, 0x300
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r30, r3
	  b         .loc_0x19C

	.loc_0x50:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x78
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x94

	.loc_0x78:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x94:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x180
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x180
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x180
	  lfs       f1, 0x94(r27)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x0(r29)
	  lfs       f4, 0x8(r29)
	  bl        -0x13649C
	  lwz       r3, 0x4(r28)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x3B0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x16C
	  lfs       f1, 0x94(r27)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x2C(r28)
	  lfs       f4, 0x34(r28)
	  bl        -0x1364C4
	  lwz       r3, 0x4(r28)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x250(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x16C
	  lfs       f1, 0x98(r27)
	  addi      r3, r3, 0x260
	  lfs       f0, 0x30(r28)
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x154
	  b         .loc_0x158

	.loc_0x154:
	  fneg      f1, f1

	.loc_0x158:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x16C
	  li        r0, 0x1
	  b         .loc_0x170

	.loc_0x16C:
	  li        r0, 0

	.loc_0x170:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x180
	  li        r3, 0x1
	  b         .loc_0x3C8

	.loc_0x180:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x19C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C4
	  li        r0, 0x1
	  b         .loc_0x1F0

	.loc_0x1C4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1EC
	  li        r0, 0x1
	  b         .loc_0x1F0

	.loc_0x1EC:
	  li        r0, 0

	.loc_0x1F0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x50
	  lwz       r30, 0x3068(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r31, r3
	  b         .loc_0x368

	.loc_0x21C:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x244
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x260

	.loc_0x244:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x260:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x34C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x34C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x34C
	  lfs       f1, 0x94(r27)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x0(r29)
	  lfs       f4, 0x8(r29)
	  bl        -0x136668
	  lwz       r3, 0x4(r28)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x3B0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x338
	  lfs       f1, 0x94(r27)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x2C(r28)
	  lfs       f4, 0x34(r28)
	  bl        -0x136690
	  lwz       r3, 0x4(r28)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x250(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x338
	  lfs       f1, 0x98(r27)
	  addi      r3, r3, 0x260
	  lfs       f0, 0x30(r28)
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x320
	  b         .loc_0x324

	.loc_0x320:
	  fneg      f1, f1

	.loc_0x324:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x338
	  li        r0, 0x1
	  b         .loc_0x33C

	.loc_0x338:
	  li        r0, 0

	.loc_0x33C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x34C
	  li        r3, 0x1
	  b         .loc_0x3C8

	.loc_0x34C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x368:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x390
	  li        r0, 0x1
	  b         .loc_0x3BC

	.loc_0x390:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3B8
	  li        r0, 0x1
	  b         .loc_0x3BC

	.loc_0x3B8:
	  li        r0, 0

	.loc_0x3BC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x21C

	.loc_0x3C4:
	  li        r3, 0

	.loc_0x3C8:
	  lmw       r27, 0xA4(r1)
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000194
 */
bool KingAi::missAttackNextTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016EDAC
 * Size:	000448
 */
bool KingAi::jumpAttackTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stmw      r26, 0xA8(r1)
	  mr        r28, r3
	  lbz       r0, 0x8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x42C
	  lwz       r5, 0x4(r28)
	  lwz       r3, 0x18(r28)
	  lwz       r4, 0x224(r5)
	  lwz       r0, 0x4A0(r4)
	  cmpw      r3, r0
	  bge-      .loc_0x42C
	  lwz       r31, 0x3068(r13)
	  addi      r29, r5, 0x300
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r30, r3
	  b         .loc_0x1E4

	.loc_0x64:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0xA8

	.loc_0x8C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0xA8:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1C8
	  lwz       r0, 0x184(r27)
	  lwz       r26, 0x4(r28)
	  cmplw     r0, r26
	  beq-      .loc_0x1C8
	  lfs       f1, 0x94(r27)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x0(r29)
	  lfs       f4, 0x8(r29)
	  bl        -0x1368A0
	  lwz       r3, 0x224(r26)
	  lfs       f0, 0x3B0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1B4
	  lwz       r4, 0x4(r28)
	  lfs       f1, 0x94(r27)
	  lwz       r3, 0x224(r4)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x94(r4)
	  addi      r26, r3, 0x3C0
	  lfs       f4, 0x9C(r4)
	  bl        -0x1368D0
	  lfs       f0, 0x0(r26)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1B4
	  lfs       f1, 0x98(r27)
	  lfs       f0, 0x30(r28)
	  lwz       r3, 0x4(r28)
	  fsubs     f1, f1, f0
	  lwz       r3, 0x224(r3)
	  fcmpo     cr0, f1, f31
	  addi      r3, r3, 0x260
	  ble-      .loc_0x180
	  b         .loc_0x184

	.loc_0x180:
	  fneg      f1, f1

	.loc_0x184:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1B4
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        -0xD64
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B4
	  lwz       r3, 0x4(r28)
	  li        r0, 0x1
	  stw       r27, 0x318(r3)
	  b         .loc_0x1B8

	.loc_0x1B4:
	  li        r0, 0

	.loc_0x1B8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1C8
	  li        r3, 0x1
	  b         .loc_0x430

	.loc_0x1C8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1E4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x20C
	  li        r0, 0x1
	  b         .loc_0x238

	.loc_0x20C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x234
	  li        r0, 0x1
	  b         .loc_0x238

	.loc_0x234:
	  li        r0, 0

	.loc_0x238:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x64
	  lwz       r30, 0x3120(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r31, r3
	  b         .loc_0x3D0

	.loc_0x264:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x28C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x2A8

	.loc_0x28C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x2A8:
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3B4
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3B4
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3B4
	  lfs       f1, 0x94(r27)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x0(r29)
	  lfs       f4, 0x8(r29)
	  bl        -0x136A90
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x3B0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3A0
	  lfs       f1, 0x94(r27)
	  addi      r26, r3, 0x3C0
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x94(r4)
	  lfs       f4, 0x9C(r4)
	  bl        -0x136ABC
	  lfs       f0, 0x0(r26)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3A0
	  lfs       f1, 0x98(r27)
	  lfs       f0, 0x30(r28)
	  lwz       r3, 0x4(r28)
	  fsubs     f1, f1, f0
	  lwz       r3, 0x224(r3)
	  fcmpo     cr0, f1, f31
	  addi      r3, r3, 0x260
	  ble-      .loc_0x36C
	  b         .loc_0x370

	.loc_0x36C:
	  fneg      f1, f1

	.loc_0x370:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3A0
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        -0xF50
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3A0
	  lwz       r3, 0x4(r28)
	  li        r0, 0x1
	  stw       r27, 0x318(r3)
	  b         .loc_0x3A4

	.loc_0x3A0:
	  li        r0, 0

	.loc_0x3A4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x3B4
	  li        r3, 0x1
	  b         .loc_0x430

	.loc_0x3B4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x3D0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3F8
	  li        r0, 0x1
	  b         .loc_0x424

	.loc_0x3F8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x420
	  li        r0, 0x1
	  b         .loc_0x424

	.loc_0x420:
	  li        r0, 0

	.loc_0x424:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x264

	.loc_0x42C:
	  li        r3, 0

	.loc_0x430:
	  lmw       r26, 0xA8(r1)
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
bool KingAi::swallowTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016F1F4
 * Size:	0002B8
 */
bool KingAi::eatThrowPikiTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stfd      f29, 0xA8(r1)
	  stfd      f28, 0xA0(r1)
	  stfd      f27, 0x98(r1)
	  stfd      f26, 0x90(r1)
	  stmw      r24, 0x70(r1)
	  mr        r27, r3
	  li        r28, 0
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x288
	  lwz       r5, 0x4(r27)
	  lis       r3, 0x736C
	  addi      r4, r3, 0x7433
	  lwz       r3, 0x220(r5)
	  bl        -0xE5B30
	  lwz       r4, 0x4(r27)
	  mr        r31, r3
	  lfs       f31, 0x4(r3)
	  lfs       f30, 0x8(r3)
	  lfs       f29, 0xC(r3)
	  lfs       f1, 0xA0(r4)
	  bl        0xACA8C
	  lfs       f2, -0x538C(r2)
	  lfs       f0, -0x5348(r2)
	  fmuls     f2, f2, f1
	  lwz       r3, 0x4(r27)
	  fadds     f30, f30, f0
	  lfs       f1, 0xA0(r3)
	  fadds     f31, f31, f2
	  bl        0xAC8D8
	  lwz       r30, 0x3068(r13)
	  lfs       f0, -0x538C(r2)
	  mr        r3, r30
	  lfs       f28, 0x0(r31)
	  fmuls     f0, f0, f1
	  lwz       r12, 0x0(r30)
	  fsubs     f27, f30, f28
	  lwz       r12, 0xC(r12)
	  fadds     f29, f29, f0
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f26, -0x5390(r2)
	  lis       r4, 0x802B
	  addi      r29, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r26, r4, 0x3244
	  b         .loc_0x22C

	.loc_0xD4:
	  cmpwi     r29, -0x1
	  bne-      .loc_0xFC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3
	  b         .loc_0x118

	.loc_0xFC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0x118:
	  cmplwi    r24, 0
	  beq-      .loc_0x210
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x210
	  lwz       r3, 0x184(r24)
	  lwz       r0, 0x4(r27)
	  cmplw     r3, r0
	  beq-      .loc_0x210
	  lfs       f0, 0x98(r24)
	  fcmpo     cr0, f0, f27
	  ble-      .loc_0x210
	  fmr       f3, f31
	  lfs       f1, 0x94(r24)
	  fmr       f4, f29
	  lfs       f2, 0x9C(r24)
	  bl        -0x136D34
	  fcmpo     cr0, f1, f28
	  bge-      .loc_0x210
	  stfs      f26, 0x3C(r1)
	  stfs      f26, 0x38(r1)
	  stfs      f26, 0x34(r1)
	  lfs       f0, 0x94(r24)
	  lfs       f2, 0x9C(r24)
	  fsubs     f0, f31, f0
	  lfs       f1, 0x98(r24)
	  fsubs     f2, f29, f2
	  fsubs     f1, f30, f1
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f2, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x3C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x161780
	  fcmpo     cr0, f1, f28
	  bge-      .loc_0x210
	  lwz       r5, 0x4(r27)
	  li        r0, 0
	  addi      r3, r24, 0
	  stw       r25, 0x44(r1)
	  addi      r4, r1, 0x44
	  stw       r5, 0x48(r1)
	  stw       r26, 0x44(r1)
	  stw       r0, 0x4C(r1)
	  stw       r31, 0x50(r1)
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r28, 0x1

	.loc_0x210:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x22C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x254
	  li        r0, 0x1
	  b         .loc_0x280

	.loc_0x254:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x27C
	  li        r0, 0x1
	  b         .loc_0x280

	.loc_0x27C:
	  li        r0, 0

	.loc_0x280:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD4

	.loc_0x288:
	  mr        r3, r28
	  lmw       r24, 0x70(r1)
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  lfd       f28, 0xA0(r1)
	  lfd       f27, 0x98(r1)
	  lfd       f26, 0x90(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool KingAi::flickTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016F4AC
 * Size:	000190
 */
bool KingAi::targetLostTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  stw       r30, 0x68(r1)
	  mr        r30, r3
	  lwz       r3, 0x4(r3)
	  lwz       r31, 0x318(r3)
	  cmplwi    r31, 0
	  beq-      .loc_0x174
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8C
	  lwz       r0, 0x184(r31)
	  lwz       r3, 0x4(r30)
	  cmplw     r0, r3
	  bne-      .loc_0xA0

	.loc_0x8C:
	  lwz       r4, 0x4(r30)
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x318(r4)
	  b         .loc_0x178

	.loc_0xA0:
	  mr        r4, r31
	  bl        -0x20680
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC4
	  lwz       r4, 0x4(r30)
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x318(r4)
	  b         .loc_0x178

	.loc_0xC4:
	  lwz       r3, 0x4(r30)
	  lfs       f0, -0x5390(r2)
	  stfs      f0, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x38(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f1, 0x50(r1)
	  stfs      f3, 0x54(r1)
	  lfs       f1, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  lfs       f2, 0x54(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x16199C
	  lwz       r4, 0x4(r30)
	  lwz       r5, 0x224(r4)
	  lfs       f0, 0x88(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x158
	  li        r0, 0
	  stw       r0, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x178

	.loc_0x158:
	  lfs       f0, 0x2A0(r5)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x174
	  li        r0, 0
	  stw       r0, 0x318(r4)
	  li        r3, 0x1
	  b         .loc_0x178

	.loc_0x174:
	  li        r3, 0

	.loc_0x178:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016F63C
 * Size:	00040C
 */
bool KingAi::appearTransit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stmw      r27, 0xBC(r1)
	  addi      r29, r3, 0
	  lwz       r31, 0x3120(r13)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r30, r3
	  b         .loc_0x1A8

	.loc_0x3C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x64
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x80

	.loc_0x64:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x80:
	  addi      r27, r28, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x18C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x18C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x18C
	  lwz       r4, 0x4(r29)
	  lfs       f1, 0x94(r27)
	  lwz       r3, 0x224(r4)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x94(r4)
	  addi      r27, r3, 0x2E0
	  lfs       f4, 0x9C(r4)
	  bl        -0x137108
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x18C
	  lwz       r3, 0x4(r29)
	  stfs      f31, 0x94(r1)
	  stfs      f31, 0x90(r1)
	  stfs      f31, 0x8C(r1)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x94(r28)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x98(r28)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x68(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f1, 0x90(r1)
	  stfs      f3, 0x94(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, 0x90(r1)
	  lfs       f2, 0x94(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x161B68
	  lwz       r3, 0x4(r29)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x2E0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x18C
	  li        r3, 0x1
	  b         .loc_0x3F4

	.loc_0x18C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1A8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  li        r0, 0x1
	  b         .loc_0x1FC

	.loc_0x1D0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x1FC

	.loc_0x1F8:
	  li        r0, 0

	.loc_0x1FC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x3C
	  lwz       r30, 0x3068(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5390(r2)
	  mr        r31, r3
	  b         .loc_0x394

	.loc_0x228:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x250
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x26C

	.loc_0x250:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x26C:
	  addi      r27, r28, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x378
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x378
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x378
	  lwz       r4, 0x4(r29)
	  lfs       f1, 0x94(r27)
	  lwz       r3, 0x224(r4)
	  lfs       f2, 0x9C(r27)
	  lfs       f3, 0x94(r4)
	  addi      r27, r3, 0x2E0
	  lfs       f4, 0x9C(r4)
	  bl        -0x1372F4
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x378
	  lwz       r3, 0x4(r29)
	  stfs      f31, 0x7C(r1)
	  stfs      f31, 0x78(r1)
	  stfs      f31, 0x74(r1)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x94(r28)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x98(r28)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x60(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x74(r1)
	  stfs      f1, 0x78(r1)
	  stfs      f3, 0x7C(r1)
	  lfs       f1, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  lfs       f2, 0x7C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x161D54
	  lwz       r3, 0x4(r29)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x2E0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x378
	  li        r3, 0x1
	  b         .loc_0x3F4

	.loc_0x378:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x394:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3BC
	  li        r0, 0x1
	  b         .loc_0x3E8

	.loc_0x3BC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3E4
	  li        r0, 0x1
	  b         .loc_0x3E8

	.loc_0x3E4:
	  li        r0, 0

	.loc_0x3E8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x228
	  li        r3, 0

	.loc_0x3F4:
	  lmw       r27, 0xBC(r1)
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016FA48
 * Size:	00014C
 */
void KingAi::initDie(int nextState)
{

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r3, 0x4(r3)
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0xE5780
	  addi      r5, r31, 0
	  addi      r3, r1, 0x28
	  li        r4, 0
	  bl        -0x50B18
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x508F4
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x3FD4
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  addi      r3, r3, 0x3C4
	  bl        -0xE1980
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEC0A0
	  lwz       r5, 0x4(r31)
	  li        r4, 0x6C
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2D02C
	  lwz       r5, 0x4(r31)
	  li        r4, 0x6E
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2D010
	  lwz       r5, 0x4(r31)
	  li        r4, 0x6D
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2CFF4
	  lwz       r5, 0x4(r31)
	  li        r4, 0x6B
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2CFD8
	  lwz       r5, 0x4(r31)
	  li        r4, 0x6F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2CFBC
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C8
 */
void KingAi::initDamage(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void KingAi::initBombDown(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void KingAi::initWalkRandom(int, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void KingAi::initWalkGoHome(int, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void KingAi::initChaseNavi(int, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void KingAi::initChasePiki(int, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void KingAi::initHomeTurn(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void KingAi::initChaseTurn(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void KingAi::initAttack(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void KingAi::initJumpAttack(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void KingAi::initSwallow(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void KingAi::initEatThrowPiki(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000198
 */
void KingAi::initFlick(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void KingAi::initWaveNeck(int nextState)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016FB94
 * Size:	00016C
 */
void KingAi::initAppear(int nextState)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r3, 0x4(r3)
	  stw       r4, 0x2E8(r3)
	  mr        r3, r31
	  lwz       r4, 0x4(r31)
	  stb       r5, 0x2BD(r4)
	  lwz       r4, 0x4(r31)
	  stw       r5, 0x2EC(r4)
	  lwz       r4, 0x4(r31)
	  stw       r5, 0x318(r4)
	  lwz       r4, 0x4(r31)
	  stb       r0, 0x3B8(r4)
	  lwz       r4, 0x4(r31)
	  stb       r5, 0x2BC(r4)
	  lwz       r4, 0x4(r31)
	  stb       r0, 0x2BB(r4)
	  bl        -0x2380
	  addi      r5, r31, 0
	  addi      r3, r1, 0x28
	  li        r4, 0xC
	  bl        -0x50C70
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x50A4C
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x533C(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x3E7C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x20874
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEC24C

	.loc_0xBC:
	  lwz       r5, 0x4(r31)
	  li        r4, 0x71
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2CED0
	  lwz       r5, 0x4(r31)
	  li        r4, 0x72
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2CEB4
	  lwz       r5, 0x4(r31)
	  li        r4, 0x70
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2CE98
	  lwz       r5, 0x4(r31)
	  li        r4, 0x73
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2CE7C
	  lwz       r6, 0x4(r31)
	  li        r4, 0x5
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0xD100
	  lwz       r5, 0x4(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x4BD10
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void KingAi::initStay(int nextState)
{
	// UNUSED FUNCTION
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
	if (mKing->getLoopCounter() > mDamageLoopCounter) {
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
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void KingAi::walkRandomState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void KingAi::walkGoHomeState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void KingAi::homeTurnState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void KingAi::chaseTurnState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void KingAi::chaseNaviState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void KingAi::chasePikiState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void KingAi::attackState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void KingAi::jumpAttackState()
{
	// UNUSED FUNCTION
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
			_09 = false;
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
		break;

	case KINGAI_ChasePiki:
		chasePikiState();
		break;

	case KINGAI_Attack:
		attackState();
		if (dieTransit()) {
			initDie(KINGAI_Die);
		} else if (bombDownTransit()) {
			initBombDown(KINGAI_BombDown);
		} else if (eatThrowPikiTransit()) {
			initEatThrowPiki(8);
		} else if (missAttackNextTransit()) {
		}
		break;

	case KINGAI_JumpAttack:
		jumpAttackState();
		break;

	case KINGAI_Swallow:
		swallowState();
		break;

	case KINGAI_EatThrowPiki:
		eatThrowPikiState();
		break;

	case KINGAI_WalkGoHome:
		walkGoHomeState();
		break;

	case KINGAI_Flick:
		flickState();
		break;

	case KINGAI_WaveNeck:
		waveNeckState();
		break;

	case KINGAI_Appear:
		appearState();
		break;

	case KINGAI_Stay:
		stayState();
		break;
	}

	afterProcessing();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xAC0(r1)
	  stw       r31, 0xABC(r1)
	  mr        r31, r3
	  stw       r30, 0xAB8(r1)
	  lwz       r4, 0x4(r3)
	  lwz       r3, 0x224(r4)
	  lfs       f1, 0xA0(r4)
	  addi      r30, r3, 0x240
	  bl        0xABFC0
	  lfs       f0, 0x0(r30)
	  lwz       r3, 0x4(r31)
	  fmuls     f1, f0, f1
	  lfs       f0, 0x94(r3)
	  fadds     f0, f0, f1
	  stfs      f0, 0x2C(r31)
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0x98(r3)
	  stfs      f0, 0x30(r31)
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x224(r4)
	  lfs       f1, 0xA0(r4)
	  addi      r30, r3, 0x240
	  bl        0xABDF4
	  lfs       f0, 0x0(r30)
	  mr        r3, r31
	  lwz       r4, 0x4(r31)
	  fmuls     f1, f0, f1
	  lfs       f0, 0x9C(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0x34(r31)
	  bl        -0x34D4
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xC4
	  lwz       r4, 0x4(r31)
	  lwz       r0, 0x2E4(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0xC4
	  lwz       r3, 0x224(r4)
	  lfs       f1, 0x2C8(r4)
	  lfs       f0, 0x370(r3)
	  lfs       f2, 0x2C4(r4)
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xC4
	  li        r0, 0x1
	  stb       r0, 0x8(r31)

	.loc_0xC4:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xDC
	  bl        -0x21890

	.loc_0xDC:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x318(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x108
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x114
	  lwz       r3, 0x3C0(r3)
	  li        r0, 0x1
	  stb       r0, 0x5(r3)
	  b         .loc_0x114

	.loc_0x108:
	  lwz       r3, 0x3C0(r3)
	  li        r0, 0
	  stb       r0, 0x5(r3)

	.loc_0x114:
	  lwz       r5, 0x4(r31)
	  lwz       r0, 0x2E4(r5)
	  cmplwi    r0, 0x10
	  bgt-      .loc_0x3000
	  lis       r3, 0x802D
	  addi      r3, r3, 0x478
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r0, 0x1
	  stb       r0, 0x2B8(r5)
	  b         .loc_0x3000
	  lwz       r3, 0x2EC(r5)
	  lwz       r0, 0x14(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x178
	  addi      r5, r31, 0
	  addi      r3, r1, 0xAAC
	  li        r4, -0x1
	  bl        -0x50ED8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x50C44

	.loc_0x178:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1A4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x454
	  b         .loc_0x3000

	.loc_0x1A4:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0x9
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x1EC
	  cmpwi     r0, 0xC
	  ble-      .loc_0x218

	.loc_0x1EC:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xAA4
	  li        r4, 0x6
	  bl        -0x50F6C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x50D48
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x218:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x20B70
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEC548
	  b         .loc_0x3000
	  lwz       r3, 0x2EC(r5)
	  lwz       r0, 0x14(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x280
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA9C
	  li        r4, -0x1
	  bl        -0x50FE0
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x50D4C

	.loc_0x280:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x2AC
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x55C
	  b         .loc_0x3000

	.loc_0x2AC:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0x9
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x2F4
	  cmpwi     r0, 0xC
	  ble-      .loc_0x320

	.loc_0x2F4:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA94
	  li        r4, 0x6
	  bl        -0x51074
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x50E50
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x320:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x20C78
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEC650
	  b         .loc_0x3000
	  mr        r3, r5
	  lfs       f1, -0x538C(r2)
	  bl        -0x21A98
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x220(r4)
	  bl        -0x21CC0
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x3A0
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x650
	  b         .loc_0x3000

	.loc_0x3A0:
	  bl        -0x2110C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x440
	  lwz       r3, 0x4(r31)
	  li        r4, 0xD
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA8C
	  lwz       r6, 0x4(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x51154
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x50F30
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x3998
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f0, -0x5390(r2)
	  lwz       r4, 0x3C0(r4)
	  stfs      f0, 0x20(r4)
	  bl        -0x2050
	  lwz       r3, 0x4(r31)
	  bl        -0x20D60
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEC738
	  b         .loc_0x3000

	.loc_0x440:
	  mr        r3, r31
	  bl        -0x1778
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4DC
	  lwz       r3, 0x4(r31)
	  li        r4, 0x5
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA84
	  lwz       r6, 0x4(r31)
	  li        r4, 0x8
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  stb       r0, 0x9(r31)
	  stw       r0, 0x1C(r31)
	  bl        -0x511F8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x50FD4
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x38F4
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x20DFC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEC7D4
	  b         .loc_0x3000

	.loc_0x4DC:
	  mr        r3, r31
	  bl        -0x1434
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5E8
	  lwz       r3, 0x4(r31)
	  li        r4, 0x6
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA7C
	  lwz       r6, 0x4(r31)
	  li        r4, 0xD
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5128C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51068
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x3860
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x20E90
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x56C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEC868

	.loc_0x56C:
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x38(r31)
	  stw       r0, 0x3C(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x40(r31)
	  lwz       r4, 0x4(r31)
	  lwz       r5, 0x318(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0x5C0
	  lwz       r4, 0x94(r5)
	  li        r0, 0
	  lwz       r3, 0x98(r5)
	  stw       r4, 0x44(r31)
	  stw       r3, 0x48(r31)
	  lwz       r3, 0x9C(r5)
	  stw       r3, 0x4C(r31)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  b         .loc_0x5D8

	.loc_0x5C0:
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x44(r31)
	  stw       r0, 0x48(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x4C(r31)

	.loc_0x5D8:
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  b         .loc_0x3000

	.loc_0x5E8:
	  lwz       r4, 0x4(r31)
	  lfs       f1, 0x94(r4)
	  lfs       f3, 0x30C(r4)
	  lfs       f2, 0x314(r4)
	  lfs       f0, 0x9C(r4)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xAB6F4
	  lwz       r3, 0x4(r31)
	  fmr       f2, f1
	  lfs       f1, 0xA0(r3)
	  bl        -0x2068
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0xA0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x640
	  fsubs     f1, f1, f0
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x658
	  li        r0, 0x1
	  b         .loc_0x65C

	.loc_0x640:
	  fsubs     f1, f0, f1
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x658
	  li        r0, 0x1
	  b         .loc_0x65C

	.loc_0x658:
	  li        r0, 0

	.loc_0x65C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x6C4
	  li        r0, 0x4
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0xA70
	  li        r4, 0x4
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x51400
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x511DC
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x36EC
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  b         .loc_0x3000

	.loc_0x6C4:
	  bl        -0x21554
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x774
	  lwz       r3, 0x4(r31)
	  li        r4, 0xC
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x710
	  cmpwi     r0, 0xC
	  ble-      .loc_0x73C

	.loc_0x710:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA68
	  li        r4, 0x6
	  bl        -0x51490
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5126C
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x73C:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21094
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xECA6C
	  b         .loc_0x3000

	.loc_0x774:
	  mr        r3, r31
	  bl        -0x20B8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x820
	  lwz       r3, 0x4(r31)
	  li        r4, 0xA
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x7BC
	  cmpwi     r0, 0xC
	  ble-      .loc_0x7E8

	.loc_0x7BC:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA60
	  li        r4, 0x6
	  bl        -0x5153C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51318
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x7E8:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21140
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xECB18
	  b         .loc_0x3000

	.loc_0x820:
	  mr        r3, r31
	  bl        -0x1E64
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x4(r31)
	  li        r4, 0xB
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x868
	  cmpwi     r0, 0xC
	  ble-      .loc_0x894

	.loc_0x868:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA58
	  li        r4, 0x6
	  bl        -0x515E8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x513C4
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x894:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x211EC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xECBC4
	  b         .loc_0x3000
	  lwz       r3, 0x300(r5)
	  lwz       r0, 0x304(r5)
	  stw       r3, 0x30C(r5)
	  stw       r0, 0x310(r5)
	  lwz       r0, 0x308(r5)
	  stw       r0, 0x314(r5)
	  lwz       r3, 0x4(r31)
	  bl        -0x220D4
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x230(r4)
	  bl        -0x22248
	  mr        r3, r31
	  bl        -0x230C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x92C
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA50
	  li        r4, -0x1
	  bl        -0x5168C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x513F8

	.loc_0x92C:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x958
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0xC08
	  b         .loc_0x3000

	.loc_0x958:
	  bl        -0x216C4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9F8
	  lwz       r3, 0x4(r31)
	  li        r4, 0xD
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA48
	  lwz       r6, 0x4(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x5170C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x514E8
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x33E0
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f0, -0x5390(r2)
	  lwz       r4, 0x3C0(r4)
	  stfs      f0, 0x20(r4)
	  bl        -0x2608
	  lwz       r3, 0x4(r31)
	  bl        -0x21318
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xECCF0
	  b         .loc_0x3000

	.loc_0x9F8:
	  lwz       r3, 0x4(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0xC
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0xA44
	  cmpwi     r0, 0xC
	  ble-      .loc_0xA70

	.loc_0xA44:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA40
	  li        r4, 0x6
	  bl        -0x517C4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x515A0
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0xA70:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x213C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xECDA0
	  b         .loc_0x3000
	  lwz       r0, 0x318(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0xAC4
	  mr        r3, r31
	  bl        -0x20F8
	  mr        r3, r31
	  bl        -0x2400

	.loc_0xAC4:
	  lwz       r3, 0x4(r31)
	  bl        -0x22230
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x230(r4)
	  bl        -0x22428
	  mr        r3, r31
	  bl        -0x24EC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB0C
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA38
	  li        r4, -0x1
	  bl        -0x5186C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x515D8

	.loc_0xB0C:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xB38
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0xDE8
	  b         .loc_0x3000

	.loc_0xB38:
	  bl        -0x218A4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBD8
	  lwz       r3, 0x4(r31)
	  li        r4, 0xD
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA30
	  lwz       r6, 0x4(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x518EC
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x516C8
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x3200
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f0, -0x5390(r2)
	  lwz       r4, 0x3C0(r4)
	  stfs      f0, 0x20(r4)
	  bl        -0x27E8
	  lwz       r3, 0x4(r31)
	  bl        -0x214F8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xECED0
	  b         .loc_0x3000

	.loc_0xBD8:
	  mr        r3, r31
	  bl        -0x1F10
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC74
	  lwz       r3, 0x4(r31)
	  li        r4, 0x5
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA28
	  lwz       r6, 0x4(r31)
	  li        r4, 0x8
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  stb       r0, 0x9(r31)
	  stw       r0, 0x1C(r31)
	  bl        -0x51990
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5176C
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x315C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21594
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xECF6C
	  b         .loc_0x3000

	.loc_0xC74:
	  mr        r3, r31
	  bl        -0x1BCC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD80
	  lwz       r3, 0x4(r31)
	  li        r4, 0x6
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA20
	  lwz       r6, 0x4(r31)
	  li        r4, 0xD
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x51A24
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51800
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x30C8
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21628
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD04
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED000

	.loc_0xD04:
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x38(r31)
	  stw       r0, 0x3C(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x40(r31)
	  lwz       r4, 0x4(r31)
	  lwz       r5, 0x318(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0xD58
	  lwz       r4, 0x94(r5)
	  li        r0, 0
	  lwz       r3, 0x98(r5)
	  stw       r4, 0x44(r31)
	  stw       r3, 0x48(r31)
	  lwz       r3, 0x9C(r5)
	  stw       r3, 0x4C(r31)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  b         .loc_0xD70

	.loc_0xD58:
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x44(r31)
	  stw       r0, 0x48(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x4C(r31)

	.loc_0xD70:
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  b         .loc_0x3000

	.loc_0xD80:
	  mr        r3, r31
	  bl        -0x15D8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE1C
	  lwz       r3, 0x4(r31)
	  li        r4, 0xE
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA18
	  lwz       r6, 0x4(r31)
	  li        r4, 0x5
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x51B38
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51914
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x2FB4
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x2173C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED114
	  b         .loc_0x3000

	.loc_0xE1C:
	  lwz       r3, 0x4(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0x9
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0xE68
	  cmpwi     r0, 0xC
	  ble-      .loc_0xE94

	.loc_0xE68:
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA10
	  li        r4, 0x6
	  bl        -0x51BE8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x519C4
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0xE94:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x217EC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED1C4
	  b         .loc_0x3000
	  mr        r3, r5
	  bl        -0x22638
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x220(r4)
	  bl        -0x22830
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xF10
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x11C0
	  b         .loc_0x3000

	.loc_0xF10:
	  bl        -0x21C7C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xFB0
	  lwz       r3, 0x4(r31)
	  li        r4, 0xD
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA08
	  lwz       r6, 0x4(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x51CC4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51AA0
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x2E28
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f0, -0x5390(r2)
	  lwz       r4, 0x3C0(r4)
	  stfs      f0, 0x20(r4)
	  bl        -0x2BC0
	  lwz       r3, 0x4(r31)
	  bl        -0x218D0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED2A8
	  b         .loc_0x3000

	.loc_0xFB0:
	  mr        r3, r31
	  bl        -0x22E8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x104C
	  lwz       r3, 0x4(r31)
	  li        r4, 0x5
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xA00
	  lwz       r6, 0x4(r31)
	  li        r4, 0x8
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  stb       r0, 0x9(r31)
	  stw       r0, 0x1C(r31)
	  bl        -0x51D68
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51B44
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x2D84
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x2196C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED344
	  b         .loc_0x3000

	.loc_0x104C:
	  mr        r3, r31
	  bl        -0x1FA4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1158
	  lwz       r3, 0x4(r31)
	  li        r4, 0x6
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9F8
	  lwz       r6, 0x4(r31)
	  li        r4, 0xD
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x51DFC
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51BD8
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x2CF0
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21A00
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10DC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED3D8

	.loc_0x10DC:
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x38(r31)
	  stw       r0, 0x3C(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x40(r31)
	  lwz       r4, 0x4(r31)
	  lwz       r5, 0x318(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0x1130
	  lwz       r4, 0x94(r5)
	  li        r0, 0
	  lwz       r3, 0x98(r5)
	  stw       r4, 0x44(r31)
	  stw       r3, 0x48(r31)
	  lwz       r3, 0x9C(r5)
	  stw       r3, 0x4C(r31)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  b         .loc_0x1148

	.loc_0x1130:
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x44(r31)
	  stw       r0, 0x48(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x4C(r31)

	.loc_0x1148:
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  b         .loc_0x3000

	.loc_0x1158:
	  lwz       r3, 0x4(r31)
	  bl        -0x21FEC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x120C
	  lwz       r3, 0x4(r31)
	  li        r4, 0xC
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x11A8
	  cmpwi     r0, 0xC
	  ble-      .loc_0x11D4

	.loc_0x11A8:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9F0
	  li        r4, 0x6
	  bl        -0x51F28
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51D04
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x11D4:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21B2C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED504
	  b         .loc_0x3000

	.loc_0x120C:
	  mr        r3, r31
	  bl        -0x1A64
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x12A8
	  lwz       r3, 0x4(r31)
	  li        r4, 0xE
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9E8
	  lwz       r6, 0x4(r31)
	  li        r4, 0x5
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x51FC4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51DA0
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x2B28
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21BC8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED5A0
	  b         .loc_0x3000

	.loc_0x12A8:
	  lwz       r4, 0x4(r31)
	  lfs       f1, 0x94(r4)
	  lfs       f3, 0x30C(r4)
	  lfs       f2, 0x314(r4)
	  lfs       f0, 0x9C(r4)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xAAA34
	  lwz       r3, 0x4(r31)
	  fmr       f2, f1
	  lfs       f1, 0xA0(r3)
	  bl        -0x2D28
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0xA0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1300
	  fsubs     f1, f1, f0
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1318
	  li        r0, 0x1
	  b         .loc_0x131C

	.loc_0x1300:
	  fsubs     f1, f0, f1
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1318
	  li        r0, 0x1
	  b         .loc_0x131C

	.loc_0x1318:
	  li        r0, 0

	.loc_0x131C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1384
	  li        r0, 0x4
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x9DC
	  li        r4, 0x4
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x520C0
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51E9C
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x2A2C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  b         .loc_0x3000

	.loc_0x1384:
	  mr        r3, r31
	  bl        -0x29C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x4(r31)
	  li        r4, 0xA
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x13CC
	  cmpwi     r0, 0xC
	  ble-      .loc_0x13F8

	.loc_0x13CC:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9D4
	  li        r4, 0x6
	  bl        -0x5214C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x51F28
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x13F8:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21D50
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED728
	  b         .loc_0x3000
	  mr        r3, r5
	  bl        -0x22B9C
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x220(r4)
	  bl        -0x22D94
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1474
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1724
	  b         .loc_0x3000

	.loc_0x1474:
	  bl        -0x221E0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1514
	  lwz       r3, 0x4(r31)
	  li        r4, 0xD
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9CC
	  lwz       r6, 0x4(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x52228
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52004
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x28C4
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f0, -0x5390(r2)
	  lwz       r4, 0x3C0(r4)
	  stfs      f0, 0x20(r4)
	  bl        -0x3124
	  lwz       r3, 0x4(r31)
	  bl        -0x21E34
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED80C
	  b         .loc_0x3000

	.loc_0x1514:
	  mr        r3, r31
	  bl        -0x284C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x15B0
	  lwz       r3, 0x4(r31)
	  li        r4, 0x5
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9C4
	  lwz       r6, 0x4(r31)
	  li        r4, 0x8
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  stb       r0, 0x9(r31)
	  stw       r0, 0x1C(r31)
	  bl        -0x522CC
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x520A8
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x2820
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21ED0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED8A8
	  b         .loc_0x3000

	.loc_0x15B0:
	  mr        r3, r31
	  bl        -0x2508
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x16BC
	  lwz       r3, 0x4(r31)
	  li        r4, 0x6
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9BC
	  lwz       r6, 0x4(r31)
	  li        r4, 0xD
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x52360
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5213C
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x278C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x21F64
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1640
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xED93C

	.loc_0x1640:
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x38(r31)
	  stw       r0, 0x3C(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x40(r31)
	  lwz       r4, 0x4(r31)
	  lwz       r5, 0x318(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0x1694
	  lwz       r4, 0x94(r5)
	  li        r0, 0
	  lwz       r3, 0x98(r5)
	  stw       r4, 0x44(r31)
	  stw       r3, 0x48(r31)
	  lwz       r3, 0x9C(r5)
	  stw       r3, 0x4C(r31)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  b         .loc_0x16AC

	.loc_0x1694:
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x44(r31)
	  stw       r0, 0x48(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x4C(r31)

	.loc_0x16AC:
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  b         .loc_0x3000

	.loc_0x16BC:
	  lwz       r3, 0x4(r31)
	  bl        -0x22550
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1770
	  lwz       r3, 0x4(r31)
	  li        r4, 0xC
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x170C
	  cmpwi     r0, 0xC
	  ble-      .loc_0x1738

	.loc_0x170C:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9B4
	  li        r4, 0x6
	  bl        -0x5248C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52268
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x1738:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22090
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEDA68
	  b         .loc_0x3000

	.loc_0x1770:
	  mr        r3, r31
	  bl        -0x1FC8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x180C
	  lwz       r3, 0x4(r31)
	  li        r4, 0xE
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x9AC
	  lwz       r6, 0x4(r31)
	  li        r4, 0x5
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x52528
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52304
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x25C4
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x2212C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEDB04
	  b         .loc_0x3000

	.loc_0x180C:
	  lwz       r4, 0x4(r31)
	  lfs       f1, 0x94(r4)
	  lfs       f3, 0x30C(r4)
	  lfs       f2, 0x314(r4)
	  lfs       f0, 0x9C(r4)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xAA4D0
	  lwz       r3, 0x4(r31)
	  fmr       f2, f1
	  lfs       f1, 0xA0(r3)
	  bl        -0x328C
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0xA0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1864
	  fsubs     f1, f1, f0
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x187C
	  li        r0, 0x1
	  b         .loc_0x1880

	.loc_0x1864:
	  fsubs     f1, f0, f1
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x187C
	  li        r0, 0x1
	  b         .loc_0x1880

	.loc_0x187C:
	  li        r0, 0

	.loc_0x1880:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x18E8
	  li        r0, 0x4
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x9A0
	  li        r4, 0x4
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x52624
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52400
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x24C8
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  b         .loc_0x3000

	.loc_0x18E8:
	  mr        r3, r31
	  bl        -0x322C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1994
	  lwz       r3, 0x4(r31)
	  li        r4, 0xA
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x1930
	  cmpwi     r0, 0xC
	  ble-      .loc_0x195C

	.loc_0x1930:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x998
	  li        r4, 0x6
	  bl        -0x526B0
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5248C
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x195C:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x222B4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEDC8C
	  b         .loc_0x3000

	.loc_0x1994:
	  mr        r3, r31
	  bl        -0x2FD8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x4(r31)
	  li        r4, 0xB
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x19DC
	  cmpwi     r0, 0xC
	  ble-      .loc_0x1A08

	.loc_0x19DC:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x990
	  li        r4, 0x6
	  bl        -0x5275C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52538
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x1A08:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22360
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEDD38
	  b         .loc_0x3000
	  mr        r3, r5
	  bl        -0x231AC
	  mr        r3, r31
	  bl        -0x48A4
	  mr        r3, r31
	  bl        -0x444C
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x2EC(r3)
	  lwz       r0, 0x490(r4)
	  cmpw      r3, r0
	  blt-      .loc_0x1A90
	  addi      r5, r31, 0
	  addi      r3, r1, 0x988
	  li        r4, -0x1
	  bl        -0x527F0
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5255C

	.loc_0x1A90:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1ABC
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1D6C
	  b         .loc_0x3000

	.loc_0x1ABC:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x1AD0
	  li        r0, 0x1
	  b         .loc_0x1AD4

	.loc_0x1AD0:
	  li        r0, 0

	.loc_0x1AD4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1B84
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  addi      r3, r31, 0
	  lwz       r4, 0x4(r31)
	  stb       r30, 0x2BD(r4)
	  lwz       r4, 0x4(r31)
	  stw       r30, 0x2EC(r4)
	  lwz       r4, 0x4(r31)
	  stw       r30, 0x318(r4)
	  stw       r30, 0x20(r31)
	  lwz       r5, 0x4(r31)
	  lwz       r4, 0x1C(r31)
	  lwz       r10, 0x224(r5)
	  addi      r6, r10, 0x450
	  lwz       r9, 0x480(r10)
	  addi      r5, r10, 0x440
	  lwz       r8, 0x470(r10)
	  lwz       r7, 0x460(r10)
	  lwz       r6, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  bl        -0x3B0C
	  stw       r30, 0xC(r31)
	  lwz       r3, 0x4(r31)
	  bl        -0x22514
	  lwz       r4, 0x4(r31)
	  mr        r5, r31
	  lfs       f0, -0x5390(r2)
	  addi      r3, r1, 0x980
	  lwz       r6, 0x3C0(r4)
	  li        r4, 0xE
	  stfs      f0, 0x20(r6)
	  bl        -0x528D0
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x526AC
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x221C
	  b         .loc_0x3000

	.loc_0x1B84:
	  mr        r3, r31
	  bl        -0x2694
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C18
	  lwz       r3, 0x4(r31)
	  li        r4, 0x8
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x978
	  lwz       r6, 0x4(r31)
	  li        r4, 0xB
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x52934
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52710
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5340(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x21B8
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22538
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEDF10
	  b         .loc_0x3000

	.loc_0x1C18:
	  lwz       r5, 0x4(r31)
	  lis       r3, 0x736C
	  addi      r4, r3, 0x7432
	  lwz       r3, 0x220(r5)
	  bl        -0xE8218
	  lfsu      f0, 0x4(r3)
	  stfs      f0, 0x938(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x93C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x940(r1)
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x224(r4)
	  lfs       f1, 0xA0(r4)
	  addi      r30, r3, 0x320
	  bl        0xAA394
	  lfs       f2, 0x0(r30)
	  lfs       f0, 0x938(r1)
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0x938(r1)
	  lwz       r4, 0x4(r31)
	  lfs       f1, 0x93C(r1)
	  lwz       r30, 0x224(r4)
	  lfs       f0, 0x330(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x93C(r1)
	  lfs       f1, 0xA0(r4)
	  bl        0xAA1CC
	  lfs       f2, 0x320(r30)
	  li        r30, 0
	  lfs       f0, 0x940(r1)
	  addi      r5, r1, 0x944
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0x940(r1)
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0x2F8(r13)
	  lwz       r3, 0x224(r3)
	  lfs       f2, 0x2FC(r13)
	  lfs       f3, 0x340(r3)
	  lfs       f1, 0x300(r13)
	  stfs      f0, 0x96C(r1)
	  lfs       f0, -0x5390(r2)
	  stfs      f2, 0x970(r1)
	  stfs      f1, 0x974(r1)
	  stfs      f0, 0x94C(r1)
	  stfs      f0, 0x948(r1)
	  stfs      f0, 0x944(r1)
	  stfs      f0, 0x958(r1)
	  stfs      f0, 0x954(r1)
	  stfs      f0, 0x950(r1)
	  stb       r30, 0x964(r1)
	  lwz       r0, 0x938(r1)
	  lwz       r3, 0x93C(r1)
	  stw       r0, 0x944(r1)
	  lwz       r0, 0x940(r1)
	  stw       r3, 0x948(r1)
	  lwz       r3, 0x96C(r1)
	  stw       r0, 0x94C(r1)
	  lwz       r0, 0x970(r1)
	  stw       r3, 0x950(r1)
	  stw       r0, 0x954(r1)
	  lwz       r0, 0x974(r1)
	  stw       r0, 0x958(r1)
	  stfs      f3, 0x95C(r1)
	  lfs       f0, -0x5378(r2)
	  stw       r30, 0x968(r1)
	  lwz       r4, 0x2DEC(r13)
	  stfs      f0, 0x960(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x28C(r4)
	  lwz       r4, 0x4(r31)
	  bl        -0x108BE8
	  lfs       f1, 0x938(r1)
	  lfs       f0, 0x944(r1)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x1D70
	  lfs       f1, 0x93C(r1)
	  lfs       f0, 0x948(r1)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x1D70
	  lfs       f1, 0x940(r1)
	  lfs       f0, 0x94C(r1)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x1D74

	.loc_0x1D70:
	  li        r30, 0x1

	.loc_0x1D74:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x2024
	  addi      r3, r1, 0x91C
	  lwz       r4, 0x4(r31)
	  bl        -0xE0E00
	  addi      r0, r1, 0x91C
	  stw       r0, 0x930(r1)
	  li        r0, 0
	  addi      r3, r1, 0x92C
	  stw       r0, 0x934(r1)
	  bl        -0xE1CE0
	  b         .loc_0x1E28

	.loc_0x1DA4:
	  lwz       r4, 0x92C(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x1DCC
	  lwz       r3, 0x930(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1DE0

	.loc_0x1DCC:
	  lwz       r3, 0x930(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1DE0:
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1E20
	  mr        r3, r30
	  bl        -0xA9C90
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1E20
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x1E20
	  li        r0, 0x1
	  b         .loc_0x1E88

	.loc_0x1E20:
	  addi      r3, r1, 0x92C
	  bl        -0xE1E8C

	.loc_0x1E28:
	  lwz       r3, 0x930(r1)
	  lwz       r4, 0x92C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1E50
	  li        r0, 0x1
	  b         .loc_0x1E7C

	.loc_0x1E50:
	  lwz       r3, 0x930(r1)
	  lwz       r4, 0x92C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1E78
	  li        r0, 0x1
	  b         .loc_0x1E7C

	.loc_0x1E78:
	  li        r0, 0

	.loc_0x1E7C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1DA4
	  li        r0, 0

	.loc_0x1E88:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1F14
	  lwz       r3, 0x4(r31)
	  li        r4, 0x8
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x914
	  lwz       r6, 0x4(r31)
	  li        r4, 0xB
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x52C30
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52A0C
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5340(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1EBC
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22834
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE20C
	  b         .loc_0x3000

	.loc_0x1F14:
	  lwz       r0, 0xC(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x1F28
	  li        r0, 0x1
	  b         .loc_0x1F2C

	.loc_0x1F28:
	  li        r0, 0

	.loc_0x1F2C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1FB8
	  lwz       r3, 0x4(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x90C
	  lwz       r6, 0x4(r31)
	  li        r4, 0xA
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x52CD4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52AB0
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1E18
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x228D8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE2B0
	  b         .loc_0x3000

	.loc_0x1FB8:
	  lwz       r3, 0x4(r31)
	  li        r4, 0x3
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x904
	  lwz       r6, 0x4(r31)
	  li        r4, 0x4
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x52D60
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52B3C
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1D8C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  b         .loc_0x3000

	.loc_0x2024:
	  lwz       r4, 0x4(r31)
	  lbz       r0, 0x2BD(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  addi      r3, r1, 0x8E8
	  bl        -0xE10B4
	  addi      r0, r1, 0x8E8
	  stw       r0, 0x8FC(r1)
	  li        r0, 0
	  addi      r3, r1, 0x8F8
	  stw       r0, 0x900(r1)
	  bl        -0xE1F94
	  b         .loc_0x20DC

	.loc_0x2058:
	  lwz       r4, 0x8F8(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x2080
	  lwz       r3, 0x8FC(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2094

	.loc_0x2080:
	  lwz       r3, 0x8FC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2094:
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x20D4
	  mr        r3, r30
	  bl        -0xA9F44
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x20D4
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x20D4
	  li        r0, 0x1
	  b         .loc_0x213C

	.loc_0x20D4:
	  addi      r3, r1, 0x8F8
	  bl        -0xE2140

	.loc_0x20DC:
	  lwz       r3, 0x8FC(r1)
	  lwz       r4, 0x8F8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2104
	  li        r0, 0x1
	  b         .loc_0x2130

	.loc_0x2104:
	  lwz       r3, 0x8FC(r1)
	  lwz       r4, 0x8F8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x212C
	  li        r0, 0x1
	  b         .loc_0x2130

	.loc_0x212C:
	  li        r0, 0

	.loc_0x2130:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2058
	  li        r0, 0

	.loc_0x213C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x21C8
	  lwz       r3, 0x4(r31)
	  li        r4, 0x8
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x8E0
	  lwz       r6, 0x4(r31)
	  li        r4, 0xB
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x52EE4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52CC0
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5340(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1C08
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22AE8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE4C0
	  b         .loc_0x3000

	.loc_0x21C8:
	  lwz       r0, 0xC(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x21DC
	  li        r0, 0x1
	  b         .loc_0x21E0

	.loc_0x21DC:
	  li        r0, 0

	.loc_0x21E0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x226C
	  lwz       r3, 0x4(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x8D8
	  lwz       r6, 0x4(r31)
	  li        r4, 0xA
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x52F88
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52D64
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1B64
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22B8C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE564
	  b         .loc_0x3000

	.loc_0x226C:
	  lwz       r3, 0x4(r31)
	  li        r4, 0x9
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x22AC
	  cmpwi     r0, 0xC
	  ble-      .loc_0x22D8

	.loc_0x22AC:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x8D0
	  li        r4, 0x6
	  bl        -0x5302C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52E08
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x22D8:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22C30
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE608
	  b         .loc_0x3000
	  lfs       f2, 0x368(r5)
	  lfs       f1, -0x5338(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x23A4
	  lfs       f0, -0x5334(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x23A4
	  fsubs     f3, f2, f1
	  lfs       f0, -0x5330(r2)
	  lfs       f2, -0x5378(r2)
	  li        r4, 0x1
	  lfs       f1, 0x44(r31)
	  fdivs     f3, f3, f0
	  lfs       f0, 0x38(r31)
	  fsubs     f2, f2, f3
	  fmuls     f1, f3, f1
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x94(r5)
	  lfs       f1, 0x4C(r31)
	  lfs       f0, 0x40(r31)
	  fmuls     f1, f3, f1
	  lwz       r3, 0x4(r31)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x9C(r3)
	  lwz       r5, 0x4(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r5)
	  lfs       f2, 0x9C(r5)
	  bl        -0x10A184
	  lwz       r3, 0x4(r31)
	  stfs      f1, 0x98(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x230(r4)
	  bl        -0x23CF0

	.loc_0x23A4:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x23D0
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x2680
	  b         .loc_0x3000

	.loc_0x23D0:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  mr        r3, r31
	  bl        -0x3334
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x24E8
	  lwz       r3, 0x4(r31)
	  li        r4, 0x6
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x8C0
	  lwz       r6, 0x4(r31)
	  li        r4, 0xD
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5318C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x52F68
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1960
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22D90
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x246C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE768

	.loc_0x246C:
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x38(r31)
	  stw       r0, 0x3C(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x40(r31)
	  lwz       r4, 0x4(r31)
	  lwz       r5, 0x318(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0x24C0
	  lwz       r4, 0x94(r5)
	  li        r0, 0
	  lwz       r3, 0x98(r5)
	  stw       r4, 0x44(r31)
	  stw       r3, 0x48(r31)
	  lwz       r3, 0x9C(r5)
	  stw       r3, 0x4C(r31)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  b         .loc_0x24D8

	.loc_0x24C0:
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x44(r31)
	  stw       r0, 0x48(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x4C(r31)

	.loc_0x24D8:
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  b         .loc_0x3000

	.loc_0x24E8:
	  lwz       r3, 0x4(r31)
	  li        r4, 0x9
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x2528
	  cmpwi     r0, 0xC
	  ble-      .loc_0x2554

	.loc_0x2528:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x8B8
	  li        r4, 0x6
	  bl        -0x532A8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53084
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x2554:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22EAC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE884
	  b         .loc_0x3000
	  lfs       f1, 0x2C4(r5)
	  lfs       f0, -0x5390(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x25B4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x2864
	  b         .loc_0x3000

	.loc_0x25B4:
	  lbz       r0, 0x2BD(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0x9
	  stw       r0, 0x2E8(r5)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x25FC
	  cmpwi     r0, 0xC
	  ble-      .loc_0x2628

	.loc_0x25FC:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x8B0
	  li        r4, 0x6
	  bl        -0x5337C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53158
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x2628:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x22F80
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEE958
	  b         .loc_0x3000
	  lfs       f1, 0x2C4(r5)
	  lfs       f0, -0x5390(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x2688
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x2938
	  b         .loc_0x3000

	.loc_0x2688:
	  lbz       r0, 0x2BD(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  addi      r3, r1, 0x894
	  addi      r4, r5, 0
	  bl        -0xE1718
	  addi      r0, r1, 0x894
	  stw       r0, 0x8A8(r1)
	  li        r0, 0
	  addi      r3, r1, 0x8A4
	  stw       r0, 0x8AC(r1)
	  bl        -0xE25F8
	  b         .loc_0x2740

	.loc_0x26BC:
	  lwz       r4, 0x8A4(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x26E4
	  lwz       r3, 0x8A8(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x26F8

	.loc_0x26E4:
	  lwz       r3, 0x8A8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x26F8:
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2738
	  mr        r3, r30
	  bl        -0xAA5A8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2738
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x2738
	  li        r0, 0x1
	  b         .loc_0x27A0

	.loc_0x2738:
	  addi      r3, r1, 0x8A4
	  bl        -0xE27A4

	.loc_0x2740:
	  lwz       r3, 0x8A8(r1)
	  lwz       r4, 0x8A4(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2768
	  li        r0, 0x1
	  b         .loc_0x2794

	.loc_0x2768:
	  lwz       r3, 0x8A8(r1)
	  lwz       r4, 0x8A4(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2790
	  li        r0, 0x1
	  b         .loc_0x2794

	.loc_0x2790:
	  li        r0, 0

	.loc_0x2794:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x26BC
	  li        r0, 0

	.loc_0x27A0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x280C
	  lwz       r3, 0x4(r31)
	  li        r4, 0x1
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  mr        r3, r31
	  lwz       r4, 0x4(r31)
	  stb       r0, 0x2BD(r4)
	  lwz       r4, 0x4(r31)
	  stw       r0, 0x2EC(r4)
	  lwz       r4, 0x4(r31)
	  stw       r0, 0x318(r4)
	  bl        -0x4690
	  lwz       r4, 0x4(r31)
	  mr        r5, r31
	  lfs       f0, -0x5390(r2)
	  addi      r3, r1, 0x88C
	  lwz       r6, 0x3C0(r4)
	  li        r4, 0x1
	  stfs      f0, 0x20(r6)
	  bl        -0x53568
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53344
	  b         .loc_0x3000

	.loc_0x280C:
	  lwz       r3, 0x4(r31)
	  li        r4, 0x7
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x884
	  lwz       r6, 0x4(r31)
	  li        r4, 0xA
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x535AC
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53388
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1540
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x231B0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEEB88
	  b         .loc_0x3000
	  lwz       r3, 0x300(r5)
	  lwz       r0, 0x304(r5)
	  stw       r3, 0x30C(r5)
	  stw       r0, 0x310(r5)
	  lwz       r0, 0x308(r5)
	  stw       r0, 0x314(r5)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f1, 0x220(r4)
	  bl        -0x24204
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x28E4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x2B94
	  b         .loc_0x3000

	.loc_0x28E4:
	  bl        -0x23650
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2984
	  lwz       r3, 0x4(r31)
	  li        r4, 0xD
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x87C
	  lwz       r6, 0x4(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x53698
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53474
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1454
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f0, -0x5390(r2)
	  lwz       r4, 0x3C0(r4)
	  stfs      f0, 0x20(r4)
	  bl        -0x4594
	  lwz       r3, 0x4(r31)
	  bl        -0x232A4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEEC7C
	  b         .loc_0x3000

	.loc_0x2984:
	  lwz       r4, 0x4(r31)
	  lfs       f1, 0x94(r4)
	  lfs       f3, 0x30C(r4)
	  lfs       f2, 0x314(r4)
	  lfs       f0, 0x9C(r4)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xA9358
	  lwz       r3, 0x4(r31)
	  fmr       f2, f1
	  lfs       f1, 0xA0(r3)
	  bl        -0x4404
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0xA0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x29DC
	  fsubs     f1, f1, f0
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x29F4
	  li        r0, 0x1
	  b         .loc_0x29F8

	.loc_0x29DC:
	  fsubs     f1, f0, f1
	  lfs       f0, -0x5350(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x29F4
	  li        r0, 0x1
	  b         .loc_0x29F8

	.loc_0x29F4:
	  li        r0, 0

	.loc_0x29F8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2A68
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x870
	  li        r4, 0x4
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x537A4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53580
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1348
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  b         .loc_0x3000

	.loc_0x2A68:
	  bl        -0x23958
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x4(r31)
	  li        r4, 0x9
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x2AB4
	  cmpwi     r0, 0xC
	  ble-      .loc_0x2AE0

	.loc_0x2AB4:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x868
	  li        r4, 0x6
	  bl        -0x53834
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53610
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x2AE0:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x23438
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEEE10
	  b         .loc_0x3000
	  lfs       f1, 0x2C4(r5)
	  lfs       f0, -0x5390(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x2B40
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x2DF0
	  b         .loc_0x3000

	.loc_0x2B40:
	  lbz       r0, 0x2BD(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0x9
	  stw       r0, 0x2E8(r5)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x2B88
	  cmpwi     r0, 0xC
	  ble-      .loc_0x2BB4

	.loc_0x2B88:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x860
	  li        r4, 0x6
	  bl        -0x53908
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x536E4
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x2BB4:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x2350C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEEEE4
	  b         .loc_0x3000
	  lfs       f1, 0x2C4(r5)
	  lfs       f0, -0x5390(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x2C14
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x2EC4
	  b         .loc_0x3000

	.loc_0x2C14:
	  mr        r3, r5
	  bl        -0x23984
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2CB8
	  lwz       r3, 0x4(r31)
	  li        r4, 0xD
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x858
	  lwz       r6, 0x4(r31)
	  li        r4, 0x9
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x539CC
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x537A8
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1120
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f0, -0x5390(r2)
	  lwz       r4, 0x3C0(r4)
	  stfs      f0, 0x20(r4)
	  bl        -0x48C8
	  lwz       r3, 0x4(r31)
	  bl        -0x235D8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEEFB0
	  b         .loc_0x3000

	.loc_0x2CB8:
	  mr        r3, r31
	  bl        -0x3FF0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D54
	  lwz       r3, 0x4(r31)
	  li        r4, 0x5
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x850
	  lwz       r6, 0x4(r31)
	  li        r4, 0x8
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  stb       r0, 0x9(r31)
	  stw       r0, 0x1C(r31)
	  bl        -0x53A70
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5384C
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0x107C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x23674
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEF04C
	  b         .loc_0x3000

	.loc_0x2D54:
	  mr        r3, r31
	  bl        -0x3CAC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2E60
	  lwz       r3, 0x4(r31)
	  li        r4, 0x6
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x848
	  lwz       r6, 0x4(r31)
	  li        r4, 0xD
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x53B04
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x538E0
	  lwz       r3, 0x4(r31)
	  lfs       f1, -0x5344(r2)
	  lwz       r3, 0x3C0(r3)
	  bl        0xFE8
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5390(r2)
	  lwz       r3, 0x3C0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x23708
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2DE4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEF0E0

	.loc_0x2DE4:
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x38(r31)
	  stw       r0, 0x3C(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x40(r31)
	  lwz       r4, 0x4(r31)
	  lwz       r5, 0x318(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0x2E38
	  lwz       r4, 0x94(r5)
	  li        r0, 0
	  lwz       r3, 0x98(r5)
	  stw       r4, 0x44(r31)
	  stw       r3, 0x48(r31)
	  lwz       r3, 0x9C(r5)
	  stw       r3, 0x4C(r31)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  b         .loc_0x2E50

	.loc_0x2E38:
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x44(r31)
	  stw       r0, 0x48(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x4C(r31)

	.loc_0x2E50:
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  b         .loc_0x3000

	.loc_0x2E60:
	  lwz       r3, 0x4(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0x9
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x2EAC
	  cmpwi     r0, 0xC
	  ble-      .loc_0x2ED8

	.loc_0x2EAC:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x840
	  li        r4, 0x6
	  bl        -0x53C2C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53A08
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x2ED8:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x23830
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEF208
	  b         .loc_0x3000
	  lfs       f1, 0x2C4(r5)
	  lfs       f0, -0x5390(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x2F38
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x31E8
	  b         .loc_0x3000

	.loc_0x2F38:
	  lbz       r0, 0x2BD(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x3000
	  li        r0, 0x9
	  stw       r0, 0x2E8(r5)
	  li        r0, 0
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x9
	  blt-      .loc_0x2F80
	  cmpwi     r0, 0xC
	  ble-      .loc_0x2FAC

	.loc_0x2F80:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x838
	  li        r4, 0x6
	  bl        -0x53D00
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x53ADC
	  lfs       f0, -0x538C(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)

	.loc_0x2FAC:
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x3C0(r3)
	  lfs       f0, 0x210(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x23904
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x31
	  addi      r3, r3, 0x70
	  bl        -0xEF2DC
	  b         .loc_0x3000
	  mr        r3, r31
	  bl        -0x36AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3000
	  addi      r3, r31, 0
	  li        r4, 0xF
	  bl        -0x3168

	.loc_0x3000:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E8(r3)
	  lwz       r3, 0x2E4(r3)
	  cmpw      r3, r0
	  beq-      .loc_0x306C
	  cmpwi     r3, 0x5
	  beq-      .loc_0x3044
	  bge-      .loc_0x302C
	  cmpwi     r3, 0x1
	  beq-      .loc_0x3038
	  b         .loc_0x306C

	.loc_0x302C:
	  cmpwi     r3, 0x7
	  bge-      .loc_0x306C
	  b         .loc_0x3064

	.loc_0x3038:
	  mr        r3, r31
	  bl        -0x4C74
	  b         .loc_0x306C

	.loc_0x3044:
	  li        r0, 0
	  stb       r0, 0x9(r31)
	  mr        r3, r31
	  lwz       r4, 0x4(r31)
	  lwz       r4, 0x3C0(r4)
	  stb       r0, 0x6(r4)
	  bl        -0x4C94
	  b         .loc_0x306C

	.loc_0x3064:
	  mr        r3, r31
	  bl        -0x4CA0

	.loc_0x306C:
	  lwz       r0, 0xAC4(r1)
	  lwz       r31, 0xABC(r1)
	  lwz       r30, 0xAB8(r1)
	  addi      r1, r1, 0xAC0
	  mtlr      r0
	  blr
	*/
}
