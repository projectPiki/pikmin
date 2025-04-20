#include "TAI/Aattack.h"
#include "TekiConditions.h"
#include "SoundMgr.h"
#include "WorkObject.h"
#include "gameflow.h"
#include "PikiMgr.h"
#include "NaviMgr.h"
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
DEFINE_PRINT("TAIAattack")

/*
 * --INFO--
 * Address:	801AE19C
 * Size:	00003C
 */
void TAIAattackWorkObject::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setStatus(0);
	teki.setFrameCounter(0.0f);
}

/*
 * --INFO--
 * Address:	801AE1D8
 * Size:	000254
 */
bool TAIAattackWorkObject::act(Teki& teki)
{
	bool res = false;
	switch (teki.getStatus()) {
	case 0:
		if (teki.startNewMotion(_0C)) {
			if (setTargetPosition(teki)) {
				teki.setStatus(1);
				teki.setFrameCounter(0.0f);
			} else {
				res = true;
			}
		}
		break;
	case 1:
		if (teki.startNewMotion(_0C)) {
			if (teki.mTargetPosition.distance(teki.getPosition()) < getAttackPointRadius(teki)) {
				teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
				teki.mVelocity = teki.mTargetVelocity;
				teki.setStatus(2);
			} else {
				teki.addFrameCounter(gsys->getFrameTime());
				if (teki.getFrameCounter() < 15.0f) {
					teki.moveTowardPriorityFaceDir(teki.mTargetPosition, teki.getParameterF(TPF_WalkVelocity));
				} else if (teki.getCollidePlatformCreature() == teki.getWorkObjectPointer()) {
					teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
					teki.mVelocity = teki.mTargetVelocity;
					teki.setStatus(2);
				}
			}
		}
		break;
	case 2:
		if (teki.startNewMotion(_10)) {
			res = attackWorkObject(teki);
		}
		break;
	default:
		ERROR("Unknown status %d \n", teki.getStatus());
		break;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AE434
 * Size:	000124
 */
bool TAIAattackWorkObject::attackWorkObject(Teki& teki)
{
	bool res        = false;
	WorkObject* obj = teki.getWorkObjectPointer();
	if (obj && obj->isBridge()) {
		Bridge* bridge = (Bridge*)obj;
		if (teki.getTableIndex() < 0) {
			res = true;
		} else {
			if (getLastFinishedStageBridge(bridge) == teki.getTableIndex()) {
				InteractBreak intBreak(&teki, teki.getTableIndex(),
				                       gsys->getFrameTime() / gameflow.mWorldClock.mTimeScale * getDamage(teki));
				bridge->stimulate(intBreak);
				attackEffect(teki);
			} else {
				teki.setStatus(0);
			}
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AE564
 * Size:	000218
 */
bool TAIAattackWorkObject::setTargetPosition(Teki& teki)
{
	bool res        = false;
	WorkObject* obj = teki.getWorkObjectPointer();
	teki.mTargetPosition.set(teki.getPosition());
	if (obj && obj->isBridge()) {
		Bridge* bridge = (Bridge*)obj;
		int stage      = getLastFinishedStageBridge(bridge);
		if (stage >= 0) {
			Vector3f offset;
			teki.mTargetPosition.set(bridge->getStagePos(stage));
			offset = bridge->getBridgeZVec();
			offset.multiply(-bridge->getStageDepth());
			teki.mTargetPosition.add(offset);
			teki.mTargetPosition.y = mapMgr->getMinY(teki.mTargetPosition.x, teki.mTargetPosition.z, true);
			offset                 = bridge->getBridgeXVec();
			offset.multiply(bridge->getStageWidth() * (zen::Rand(1.0f) - 0.5f) * 0.8f);
			teki.mTargetPosition.add(offset);
			res = true;
		}
		teki.setTableIndex(stage);
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AE77C
 * Size:	000068
 */
int TAIAattackWorkObject::getLastFinishedStageBridge(Bridge* bridge)
{
	for (int i = bridge->getStage() - 1; i >= 0; i--) {
		if (bridge->isStageFinished(i)) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	801AE7E4
 * Size:	000044
 */
void TAIAflickingAfterMotionLoop::start(Teki& teki)
{
	TAIAmotionLoop::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/*
 * --INFO--
 * Address:	801AE828
 * Size:	00001C
 */
bool TAIAflickingAfterMotionLoop::permitFlick(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Action0) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	801AE844
 * Size:	0000A0
 */
bool TAIAflickingAfterMotionLoop::act(Teki& teki)
{
	bool res = false;
	if (permitFlick(teki)) {
		teki.flick();
	}
	if (TAIAmotionLoop::act(teki) && teki.mCurrentAnimEvent == KEY_Finished) {
		teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
		res = true;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AE8E4
 * Size:	00008C
 */
bool TAIAtargetNavi::act(Teki& teki)
{
	Navi* navi = naviMgr->getNavi();
	if (teki.attackableCreature(*navi)) {
		teki.setCreaturePointer(0, navi);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	801AE970
 * Size:	000158
 */
bool TAIAtargetPiki::act(Teki& teki)
{
	bool res = false;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (teki.attackableCreature(*piki)) {
			teki.setCreaturePointer(0, piki);
			res = true;
			break;
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AEAC8
 * Size:	000078
 */
void TAIAfireBreath::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setAnimSpeed(getPreviousAnimSpeed(teki));
}

/*
 * --INFO--
 * Address:	801AEB48
 * Size:	0000D8
 */
bool TAIAfireBreath::act(Teki& teki)
{
	if (TAIAreserveMotion::act(teki)) {
		teki.setAnimSpeed(getAttackAnimSpeed(teki));
		if (mCallBack) {
			mCallBack->invoke(teki);
		}

		if (teki.mCurrentAnimEvent == KEY_Finished) {
			teki.setManualAnimation(false);
			return true;
		}
		return false;
	}
	return false;
}

/*
 * --INFO--
 * Address:	801AEC28
 * Size:	000128
 */
bool TAIAflickCheck::act(Teki& teki)
{
	bool res = false;
	if (getDamageCountLimit(teki) < 0) {
		f32 damageCount = teki.getFlickDamageCount(teki.countPikis(TekiLowerRangeCondition(&teki)));
		res             = teki.mDamageCount >= damageCount;
	} else if (teki.mDamageCount >= getDamageCountLimit(teki)) {
		res = true;
	}

	if (res) {
		teki.mDamageCount = 0.0f;
	}

	return res;
	TekiLowerCondition(nullptr);
}

/*
 * --INFO--
 * Address:	801AED58
 * Size:	000094
 */
void TAIAflicking::start(Teki& teki)
{
	TAIAmotion::start(teki);
	teki.stopMove();
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/*
 * --INFO--
 * Address:	801AEDEC
 * Size:	000080
 */
bool TAIAflicking::act(Teki& teki)
{
	bool res = false;
	if (teki.mCurrentAnimEvent == KEY_Finished) {
		teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
		teki.mDamageCount = 0.0f;
		res               = true;
	} else {
		flick(teki);
	}
	return res;
}

/*
 * --INFO--
 * Address:	801AEE6C
 * Size:	000098
 */
void TAIAflicking::flick(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Action0) {
		InteractFlick& flick = InteractFlick(&teki, teki.getParameterF(TPF_UpperFlickPower), teki.getParameterF(TPF_UpperAttackPower),
		                                     getFlickDirection(teki));
		teki.flick(flick, flick);
	}
}

/*
 * --INFO--
 * Address:	801AEF04
 * Size:	000094
 */
void TAIAflickingReserveMotion::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.stopMove();
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/*
 * --INFO--
 * Address:	801AEF98
 * Size:	00009C
 */
bool TAIAflickingReserveMotion::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mCurrentAnimEvent == KEY_Finished) {
			teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
			teki.mDamageCount = 0.0f;
			res               = true;
		} else {
			flick(teki);
		}
	}
	return res;
}

/*
 * --INFO--
 * Address:	801AF034
 * Size:	000098
 */
void TAIAflickingReserveMotion::flick(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Action0) {
		InteractFlick& flick = InteractFlick(&teki, teki.getParameterF(TPF_UpperFlickPower), teki.getParameterF(TPF_UpperAttackPower),
		                                     getFlickDirection(teki));
		teki.flick(flick, flick);
	}
}

/*
 * --INFO--
 * Address:	801AF0D4
 * Size:	000074
 */
void TAIAbiteForKabekui::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setBiteSwitch(false);
	teki.setCreaturePointer(2, nullptr);
}

/*
 * --INFO--
 * Address:	801AF148
 * Size:	0000D0
 */
bool TAIAbiteForKabekui::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mCurrentAnimEvent == KEY_Finished) {
			if (teki.getCreaturePointer(2)) {
				mNextState = _0C;
			} else {
				mNextState = _10;
			}
			res = true;
		} else {
			if (teki.mCurrentAnimEvent == KEY_Action0) {
				teki.setBiteSwitch(true);
			} else if (teki.mCurrentAnimEvent == KEY_Action1) {
				teki.setBiteSwitch(false);
			}
			if (teki.getBiteSwitch()) {
				hitCheck(teki);
			}
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AF218
 * Size:	0004B4
 */
bool TAIAbiteForKabekui::hitCheck(Teki& teki)
{
	bool res = false;
	if (!teki.getCreaturePointer(2)) {
		CollPart* mouth = teki.mCollInfo->getSphere('slot');
		for (int i = 0; i < mouth->getChildCount(); i++) {
			Iterator iter(pikiMgr);
			CI_LOOP(iter)
			{
				Creature* piki = *iter;
				if (piki->isAlive()) {
					if (mouth->getChildAt(i)->mCentre.distance(piki->getPosition()) < getPikiAttackSize(teki)) {

						teki.setCreaturePointer(2, piki);
						InteractSwallow swallow(&teki, mouth->getChildAt(i), 1);
						piki->stimulate(swallow);
						res = true;
						break;
					}
				}
			}
		}

		if (!res) {
			Iterator iter(naviMgr);
			CI_LOOP(iter)
			{
				Creature* navi = *iter;
				if (mouth->mCentre.distance(navi->getPosition()) < getNaviAttackSize(teki)) {
					teki.attackTarget(*navi, teki.getAttackRange(), teki.getParameterF(TPF_AttackPower), TekiRecognitionCondition(&teki));
				}
			}
		}
	}

	return res;
	TekiRecognitionCondition(nullptr);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x158(r1)
	  stfd      f31, 0x150(r1)
	  stfd      f30, 0x148(r1)
	  stfd      f29, 0x140(r1)
	  stfd      f28, 0x138(r1)
	  stmw      r21, 0x10C(r1)
	  mr        r29, r4
	  addi      r28, r3, 0
	  li        r31, 0
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x48C
	  lis       r4, 0x736C
	  lwz       r3, 0x220(r29)
	  addi      r4, r4, 0x6F74
	  bl        -0x125B4C
	  lis       r5, 0x802B
	  lfs       f30, -0x49D0(r2)
	  lis       r4, 0x802B
	  addi      r30, r3, 0
	  subi      r26, r5, 0x3064
	  subi      r25, r4, 0x3244
	  li        r22, 0
	  b         .loc_0x274

	.loc_0x68:
	  lwz       r24, 0x3068(r13)
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x214

	.loc_0x88:
	  cmpwi     r27, -0x1
	  bne-      .loc_0xB0
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  b         .loc_0xCC

	.loc_0xB0:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3

	.loc_0xCC:
	  lwz       r12, 0x0(r21)
	  mr        r3, r21
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  addi      r3, r30, 0
	  addi      r4, r22, 0
	  addi      r23, r21, 0x94
	  bl        -0x127520
	  stfs      f30, 0xD0(r1)
	  stfs      f30, 0xCC(r1)
	  stfs      f30, 0xC8(r1)
	  lfsu      f0, 0x4(r3)
	  lfs       f1, 0x0(r23)
	  lfs       f4, 0x8(r23)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r23)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xA8(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xA8(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f1, 0xCC(r1)
	  stfs      f3, 0xD0(r1)
	  lfs       f1, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  lfs       f2, 0xD0(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1A1734
	  mr        r3, r28
	  fmr       f29, f1
	  lwz       r12, 0x4(r28)
	  mr        r4, r29
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f29, f1
	  bge-      .loc_0x1F8
	  lwz       r3, 0x420(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A0
	  beq-      .loc_0x1A0
	  bl        -0xCB040
	  li        r0, 0
	  stw       r0, 0x420(r29)

	.loc_0x1A0:
	  stw       r21, 0x420(r29)
	  lwz       r3, 0x420(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1B4
	  bl        -0xCB06C

	.loc_0x1B4:
	  addi      r3, r30, 0
	  addi      r4, r22, 0
	  bl        -0x1275E8
	  stw       r26, 0xEC(r1)
	  li        r0, 0x1
	  addi      r4, r1, 0xEC
	  stw       r29, 0xF0(r1)
	  stw       r25, 0xEC(r1)
	  stw       r0, 0xF4(r1)
	  stw       r3, 0xF8(r1)
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0x1
	  b         .loc_0x270

	.loc_0x1F8:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x214:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x23C
	  li        r0, 0x1
	  b         .loc_0x268

	.loc_0x23C:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x264
	  li        r0, 0x1
	  b         .loc_0x268

	.loc_0x264:
	  li        r0, 0

	.loc_0x268:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x88

	.loc_0x270:
	  addi      r22, r22, 0x1

	.loc_0x274:
	  mr        r3, r30
	  bl        -0x127700
	  cmpw      r22, r3
	  blt+      .loc_0x68
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0x48C
	  lwz       r23, 0x3120(r13)
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r6, 0x802B
	  lfs       f29, -0x49D0(r2)
	  lis       r5, 0x802C
	  lis       r4, 0x802D
	  addi      r22, r3, 0
	  subi      r25, r6, 0xF68
	  addi      r26, r5, 0x6964
	  subi      r27, r4, 0x295C
	  addi      r24, r1, 0xD8
	  b         .loc_0x430

	.loc_0x2CC:
	  cmpwi     r22, -0x1
	  bne-      .loc_0x2F0
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x308

	.loc_0x2F0:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x308:
	  stfs      f29, 0xBC(r1)
	  mr        r21, r3
	  stfs      f29, 0xB8(r1)
	  stfs      f29, 0xB4(r1)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x4(r30)
	  lfs       f4, 0x9C(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0xC(r30)
	  lfs       f2, 0x98(r3)
	  lfs       f1, 0x8(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xA0(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f3, 0xBC(r1)
	  lfs       f1, 0xB4(r1)
	  lfs       f0, 0xB8(r1)
	  lfs       f2, 0xBC(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1A1948
	  mr        r3, r28
	  fmr       f30, f1
	  lwz       r12, 0x4(r28)
	  mr        r4, r29
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f30, f1
	  bge-      .loc_0x414
	  stw       r25, 0xD8(r1)
	  li        r4, 0
	  stw       r26, 0xD8(r1)
	  stw       r27, 0xD8(r1)
	  stw       r29, 0xDC(r1)
	  lwz       r3, 0x2C4(r29)
	  lwz       r6, 0x2C8(r29)
	  lwz       r5, 0x84(r3)
	  lwz       r3, 0x34(r6)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f28, 0x30(r5)
	  bl        -0x8C3D0
	  lwz       r3, 0x2C4(r29)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x8C3E4
	  lwz       r3, 0x2C4(r29)
	  fmr       f31, f1
	  li        r4, 0xA
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x8D138
	  fmuls     f0, f31, f30
	  mr        r3, r29
	  fmr       f2, f28
	  addi      r4, r21, 0
	  addi      r5, r24, 0
	  fmuls     f1, f1, f0
	  bl        -0x67CF4

	.loc_0x414:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x430:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x458
	  li        r0, 0x1
	  b         .loc_0x484

	.loc_0x458:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x480
	  li        r0, 0x1
	  b         .loc_0x484

	.loc_0x480:
	  li        r0, 0

	.loc_0x484:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2CC

	.loc_0x48C:
	  mr        r3, r31
	  lmw       r21, 0x10C(r1)
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lfd       f29, 0x140(r1)
	  lfd       f28, 0x138(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF6DC
 * Size:	000020
 */
void TAIAeatPiki::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
}

/*
 * --INFO--
 * Address:	801AF6FC
 * Size:	000080
 */
bool TAIAeatPiki::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki) && teki.mCurrentAnimEvent == KEY_Action0) {
		eatEffect(teki);
		teki.killStickToMouthPiki();
		res = true;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801AF77C
 * Size:	000028
 */
void TAIAeatPiki::eatEffect(Teki& teki)
{
	teki.playEventSound(&teki, SE_WALLEAT_NIP);
}
