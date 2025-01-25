#include "GoalItem.h"
#include "EffectMgr.h"
#include "DebugLog.h"
#include "Route.h"
#include "SoundMgr.h"
#include "Pellet.h"
#include "Piki.h"
#include "BaseInf.h"
#include "GameStat.h"
#include "gameflow.h"
#include "PlayerState.h"
#include "Graphics.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "NaviMgr.h"
#include "CreatureCollPart.h"

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
DEFINE_PRINT("goalItem")

static u32 leg_ids[3] = { 'leg1', 'leg2', 'leg3' };

u8 GoalItem::demoHideFlag;

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void printMatrix(char*, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EA714
 * Size:	000040
 */
bool GoalItem::insideSafeArea(Vector3f& pos)
{
	Vector3f diff = pos - mPosition;
	if (diff.x * diff.x + diff.z * diff.z < 2500.0f) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	800EA754
 * Size:	000760
 */
void GoalItem::playEffect(int id)
{
	switch (mItemAnimator.getCurrentMotionIndex()) {
	case 9:
	case 10:
	case 11:
		switch (id) {
		case 0:
			effectMgr->create(EffectMgr::EFF_Rocket_C, mPosition, nullptr, nullptr);
			break;
		case 1:
			CollPart* part = mCollInfo->getSphere('bas1');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			break;
		case 2:
			part = mCollInfo->getSphere('bas1');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			part = mCollInfo->getSphere('bas2');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			part = mCollInfo->getSphere('bas3');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			break;
		case 3:
			setFlowEffect(false);
			break;
		case 4:
			setFlightLight(false);
			break;
		}
		break;
	case 6:
	case 7:
	case 8:
		switch (id) {
		case 0:
			setFlowEffect(true);
			break;
		case 1:
			startConeShrink();
			break;
		case 2:
			effectMgr->create(EffectMgr::EFF_Rocket_Tbc1, mPosition, nullptr, nullptr);
			break;
		case 3:
			setFlightLight(true);
			break;
		}
		break;
	case 12:
		if (aiCullable()) {
			Vector3f pos[4];
			pos[0] = mCollInfo->getSphere('eff1')->mCentre;
			pos[1] = mCollInfo->getSphere('eff2')->mCentre;
			pos[2] = mCollInfo->getSphere('eff3')->mCentre;
			pos[3] = mCollInfo->getSphere('piki')->mCentre;
			if (id == 0) {
				effectMgr->create(EffectMgr::EFF_Onyon_Sparkles, pos[3], nullptr, nullptr);
			}

			int randIdx                 = (int)(gsys->getRand(1.0f) * 3.0f * 0.999999f);
			zen::particleGenerator* gen = effectMgr->create(EffectMgr::EFF_Onyon_Puff, pos[randIdx], nullptr, nullptr);
			if (gen) {
				int legIDs[3] = { 2, 1, 0 };

				Vector3f test = -1.0f * mRope[legIDs[randIdx]]->mPosDifference;
				gen->setEmitDir(test);
			}

			playEventSound(this, EffectMgr::EFF_Bridge_FinishStage);
		}
		break;
	case 3:
	case 4:
	case 5:
		switch (id) {
		case 0:
			CollPart* coll = mCollInfo->getSphere('piki');
			if (coll) {
				ERROR("no flow!\n");
			}
			Vector3f pos(coll->mCentre);
			effectMgr->create(EffectMgr::EFF_Kafun_BS, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Kafun_NG, pos, nullptr, nullptr);
			break;
		case 1:
			Vector3f pos2(mPosition);
			if (mOnionColour == Blue) {
				effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, pos2, nullptr, nullptr);
				zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Onyon_Ripples2, pos2, nullptr, nullptr);
				if (efx) {
					// Vector3f nrm(0.0f, 1.0f, 0.0f);
					efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
				}
				efx = effectMgr->create(EffectMgr::EFF_Onyon_Ripples1, pos2, nullptr, nullptr);
				if (efx) {
					efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
				}
			} else {
				effectMgr->create(EffectMgr::EFF_Onyon_Suck2, pos2, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Rocket_Bm1o, pos2, nullptr, nullptr);
			}
			break;
		case 2:
			routeMgr->getWayPoint('test', mWaypointIdx)->setFlag(true);
			if (mOnionColour == Blue) {
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
			}
			break;
		case 3:
			if (mOnionColour == Blue) {
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas2')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas3')->mCentre, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas2')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas3')->mCentre, nullptr, nullptr);
			}
			break;
		case 4:
			enableColorAnim();
			_3D0 = 20.0f;
			break;
		}
		break;
	}

	u32 badCompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stw       r31, 0xCC(r1)
	  stw       r30, 0xC8(r1)
	  mr        r30, r3
	  stw       r29, 0xC4(r1)
	  addi      r29, r4, 0
	  lwz       r0, 0x3B0(r3)
	  cmpwi     r0, 0x9
	  bge-      .loc_0x40
	  cmpwi     r0, 0x6
	  bge-      .loc_0x164
	  cmpwi     r0, 0x3
	  bge-      .loc_0x3FC
	  b         .loc_0x744

	.loc_0x40:
	  cmpwi     r0, 0xC
	  beq-      .loc_0x1D4
	  bge-      .loc_0x744
	  cmpwi     r29, 0x2
	  beq-      .loc_0xC4
	  bge-      .loc_0x68
	  cmpwi     r29, 0
	  beq-      .loc_0x78
	  bge-      .loc_0x94
	  b         .loc_0x744

	.loc_0x68:
	  cmpwi     r29, 0x4
	  beq-      .loc_0x154
	  bge-      .loc_0x744
	  b         .loc_0x144

	.loc_0x78:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r30, 0x94
	  li        r4, 0x12A
	  li        r6, 0
	  li        r7, 0
	  bl        0xB2358
	  b         .loc_0x744

	.loc_0x94:
	  lis       r4, 0x6261
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7331
	  bl        -0x610E4
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xE5
	  li        r6, 0
	  li        r7, 0
	  bl        0xB2328
	  b         .loc_0x744

	.loc_0xC4:
	  lis       r31, 0x6261
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7331
	  bl        -0x61114
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xE5
	  li        r6, 0
	  li        r7, 0
	  bl        0xB22F8
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7332
	  bl        -0x6113C
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xE5
	  li        r6, 0
	  li        r7, 0
	  bl        0xB22D0
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7333
	  bl        -0x61164
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xE5
	  li        r6, 0
	  li        r7, 0
	  bl        0xB22A8
	  b         .loc_0x744

	.loc_0x144:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        .loc_0x760
	  b         .loc_0x744

	.loc_0x154:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x888
	  b         .loc_0x744

	.loc_0x164:
	  cmpwi     r29, 0x2
	  beq-      .loc_0x1A8
	  bge-      .loc_0x180
	  cmpwi     r29, 0
	  beq-      .loc_0x18C
	  bge-      .loc_0x19C
	  b         .loc_0x744

	.loc_0x180:
	  cmpwi     r29, 0x4
	  bge-      .loc_0x744
	  b         .loc_0x1C4

	.loc_0x18C:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        .loc_0x760
	  b         .loc_0x744

	.loc_0x19C:
	  mr        r3, r30
	  bl        0xFBC
	  b         .loc_0x744

	.loc_0x1A8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r30, 0x94
	  li        r4, 0x10D
	  li        r6, 0
	  li        r7, 0
	  bl        0xB2228
	  b         .loc_0x744

	.loc_0x1C4:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        0x818
	  b         .loc_0x744

	.loc_0x1D4:
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x744
	  lfs       f0, -0x65C4(r2)
	  lis       r31, 0x6566
	  addi      r4, r31, 0x6631
	  stfs      f0, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  stfs      f0, 0x9C(r1)
	  stfs      f0, 0x98(r1)
	  stfs      f0, 0x94(r1)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0xA0(r1)
	  lwz       r3, 0x220(r30)
	  bl        -0x61264
	  lwz       r5, 0x4(r3)
	  addi      r4, r31, 0x6632
	  lwz       r0, 0x8(r3)
	  stw       r5, 0x7C(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x84(r1)
	  lwz       r3, 0x220(r30)
	  bl        -0x61288
	  lwz       r5, 0x4(r3)
	  addi      r4, r31, 0x6633
	  lwz       r0, 0x8(r3)
	  stw       r5, 0x88(r1)
	  stw       r0, 0x8C(r1)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x90(r1)
	  lwz       r3, 0x220(r30)
	  bl        -0x612AC
	  lwz       r5, 0x4(r3)
	  lis       r4, 0x7069
	  lwz       r0, 0x8(r3)
	  addi      r4, r4, 0x6B69
	  stw       r5, 0x94(r1)
	  stw       r0, 0x98(r1)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x9C(r1)
	  lwz       r3, 0x220(r30)
	  bl        -0x612D4
	  lwz       r4, 0x4(r3)
	  cmpwi     r29, 0
	  lwz       r0, 0x8(r3)
	  addi      r5, r1, 0xA0
	  stw       r4, 0xA0(r1)
	  stw       r0, 0xA4(r1)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0xA8(r1)
	  bne-      .loc_0x2CC
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xD8
	  li        r6, 0
	  li        r7, 0
	  bl        0xB211C

	.loc_0x2CC:
	  bl        0x12D650
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x65A8(r2)
	  stw       r0, 0xBC(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x65BC(r2)
	  addi      r5, r1, 0x7C
	  stw       r0, 0xB8(r1)
	  lfs       f2, -0x65C0(r2)
	  li        r4, 0xD9
	  lfd       f1, 0xB8(r1)
	  li        r6, 0
	  lfs       f0, -0x65B4(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x65B8(r2)
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0xB0(r1)
	  lwz       r29, 0xB4(r1)
	  mulli     r0, r29, 0xC
	  add       r5, r5, r0
	  bl        0xB20B0
	  mr.       r31, r3
	  beq-      .loc_0x3E8
	  lis       r3, 0x8022
	  lfs       f1, -0x3498(r13)
	  addi      r8, r3, 0x2640
	  lwz       r0, 0x0(r8)
	  addi      r7, r1, 0x70
	  lwz       r3, 0x4(r8)
	  addi      r6, r1, 0x24
	  addi      r5, r1, 0x20
	  stw       r0, 0x70(r1)
	  rlwinm    r0,r29,2,0,29
	  addi      r4, r1, 0x1C
	  stw       r3, 0x74(r1)
	  addi      r3, r1, 0x40
	  lwz       r8, 0x8(r8)
	  stw       r8, 0x78(r1)
	  lwzx      r0, r7, r0
	  rlwinm    r0,r0,3,0,28
	  add       r7, r30, r0
	  lwz       r7, 0x448(r7)
	  addi      r7, r7, 0x2C4
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1C(r1)
	  bl        -0xB39EC
	  lfs       f0, 0x40(r1)
	  lfs       f1, 0x44(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x48(r1)
	  stfs      f1, 0x68(r1)
	  stfs      f0, 0x6C(r1)
	  lwz       r3, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0xA0(r31)
	  stw       r0, 0xA4(r31)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0xA8(r31)

	.loc_0x3E8:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xD7
	  bl        -0x60594
	  b         .loc_0x744

	.loc_0x3FC:
	  cmpwi     r29, 0x2
	  beq-      .loc_0x598
	  bge-      .loc_0x418
	  cmpwi     r29, 0
	  beq-      .loc_0x428
	  bge-      .loc_0x484
	  b         .loc_0x744

	.loc_0x418:
	  cmpwi     r29, 0x4
	  beq-      .loc_0x72C
	  bge-      .loc_0x744
	  b         .loc_0x620

	.loc_0x428:
	  lis       r4, 0x7069
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6B69
	  bl        -0x61478
	  lfs       f0, 0x4(r3)
	  addi      r5, r1, 0x58
	  li        r4, 0x126
	  stfs      f0, 0x58(r1)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0xC(r3)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x60(r1)
	  bl        0xB1F80
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x58
	  li        r4, 0x127
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1F68
	  b         .loc_0x744

	.loc_0x484:
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x54(r1)
	  lhz       r0, 0x428(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x564
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x4C
	  li        r4, 0xED
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1F28
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x4C
	  li        r4, 0xEF
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1F10
	  cmplwi    r3, 0
	  beq-      .loc_0x510
	  lfs       f0, -0x3494(r13)
	  lfs       f1, -0x3490(r13)
	  stfs      f0, 0x34(r1)
	  lfs       f0, -0x348C(r13)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lwz       r4, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x510:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x4C
	  li        r4, 0xEE
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1EC0
	  cmplwi    r3, 0
	  beq-      .loc_0x744
	  lfs       f0, -0x3488(r13)
	  lfs       f1, -0x3484(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x3480(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r4, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x1E4(r3)
	  b         .loc_0x744

	.loc_0x564:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x4C
	  li        r4, 0x120
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1E6C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x4C
	  li        r4, 0x121
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1E54
	  b         .loc_0x744

	.loc_0x598:
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  lha       r5, 0x42A(r30)
	  addi      r4, r4, 0x7374
	  bl        -0x49684
	  li        r4, 0x1
	  bl        -0x49594
	  lhz       r0, 0x428(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x5F0
	  lis       r4, 0x6261
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7331
	  bl        -0x61610
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xEC
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1DFC
	  b         .loc_0x744

	.loc_0x5F0:
	  lis       r4, 0x6261
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7331
	  bl        -0x61640
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x43
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1DCC
	  b         .loc_0x744

	.loc_0x620:
	  lhz       r0, 0x428(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x6AC
	  lis       r31, 0x6261
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7331
	  bl        -0x6167C
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xEC
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1D90
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7332
	  bl        -0x616A4
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xEC
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1D68
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7333
	  bl        -0x616CC
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xEC
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1D40
	  b         .loc_0x744

	.loc_0x6AC:
	  lis       r31, 0x6261
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7331
	  bl        -0x616FC
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x43
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1D10
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7332
	  bl        -0x61724
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x43
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1CE8
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0x7333
	  bl        -0x6174C
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x43
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1CC0
	  b         .loc_0x744

	.loc_0x72C:
	  lfs       f0, -0x65C4(r2)
	  li        r0, 0x1
	  stfs      f0, 0x3D4(r30)
	  stb       r0, 0x3D8(r30)
	  lfs       f0, -0x65B0(r2)
	  stfs      f0, 0x3D0(r30)

	.loc_0x744:
	  lwz       r0, 0xD4(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  lwz       r29, 0xC4(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr

	.loc_0x760:
	*/
}

/*
 * --INFO--
 * Address:	800EAEB4
 * Size:	0000B4
 */
void GoalItem::setFlowEffect(bool set)
{
	_3E4 = set;

	if (set) {
		if (!mSuckEfx) {
			CollPart* part = mCollInfo->getSphere('piki');
			if (!part) {
				ERROR("no flow part!\n");
			}
			mSuckEfx = effectMgr->create(EffectMgr::EFF_Rocket_FlowLight, part->mCentre, nullptr, nullptr);
			if (mSuckEfx) {
				mSuckEfx->setEmitPosPtr(&part->mCentre);
			}
		}
	} else if (mSuckEfx) {
		effectMgr->kill(mSuckEfx, false);
		mSuckEfx = nullptr;
	}
}

/*
 * --INFO--
 * Address:	800EAF68
 * Size:	000178
 */
void GoalItem::setSpotActive(bool set)
{
	mSpotEffectActive = set;

	if (mSpotEffectActive) {
		EffectMgr::effTypeTable efxIDs[3]
		    = { EffectMgr::EFF_Onyon_BeaconRingBlue, EffectMgr::EFF_Onyon_BeaconRingRed, EffectMgr::EFF_Onyon_BeaconRingYellow };

		if (!mSpotEfx) {
			mSpotEfx = effectMgr->create(efxIDs[mOnionColour], mPosition, nullptr, nullptr);
			if (mSpotEfx) {
				mSpotEfx->setEmitPosPtr(&mPosition);
			}
			SeSystem::playSysSe(SYSSE_CONTAINER_OK);
		}
	} else {
		if (mSpotEfx) {
			SeSystem::stopSysSe(SYSSE_CONTAINER_OK);
			effectMgr->kill(mSpotEfx, false);
			mSpotEfx = nullptr;
		}
	}

	if (mSpotEffectActive) {
		EffectMgr::effTypeTable efxIDs[3]
		    = { EffectMgr::EFF_Onyon_HaloRingBlue, EffectMgr::EFF_Onyon_HaloRingRed, EffectMgr::EFF_Onyon_HaloRingYellow };

		if (!mHaloEfx) {
			mHaloEfx = effectMgr->create(efxIDs[mOnionColour], mPosition, nullptr, nullptr);
			if (mHaloEfx) {
				mHaloEfx->setEmitPosPtr(&mPosition);
			}
		}
	} else {
		if (mHaloEfx) {
			effectMgr->kill(mHaloEfx, false);
			mHaloEfx = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	800EB0E0
 * Size:	000058
 */
bool GoalItem::invoke(zen::particleGenerator* efx, zen::particleMdl* mdl)
{
	if (mdl) {
		mdl->_18 = mCollInfo->getSphere('llit')->mCentre;
	}
	return true;
}

/*
 * --INFO--
 * Address:	800EB138
 * Size:	000008
 */
void GoalItem::setFlightLight(bool a1)
{
	_3EC = a1;
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	800EB140
 * Size:	000024
 */
Vector3f GoalItem::getSuckPos()
{
	Vector3f ret = mPosition;
	ret.y += 74.0f;
	return ret;
}

/*
 * --INFO--
 * Address:	800EB164
 * Size:	0000F4
 */
void GoalItem::suckMe(Pellet* item)
{
	PelletConfig* config = item->mConfig;
	int pikiNum;
	if (mOnionColour == config->mPelletType()) {
		pikiNum = config->mMatchingOnyonSeeds();
	} else {
		pikiNum = config->mNonMatchingOnyonSeeds();
	}

	if (pikiNum < 0) {
		_2D4 += 2;
		MsgUser msg(0);
		mStateMachine->procMsg(this, &msg);
		playEventSound(this, SE_CONTAINER_HANABI);
		playEventSound(this, SE_CONTAINER_PELLETIN2);
	} else {
		_2D0 += pikiNum;
		MsgUser msg(0);
		mStateMachine->procMsg(this, &msg);
		playEventSound(this, SE_CONTAINER_PELLETIN2);
	}
}

/*
 * --INFO--
 * Address:	800EB258
 * Size:	0000C4
 */
void GoalItem::enterGoal(Piki* piki)
{
	int old = mItemAnimator.mMotionIdx;
	playEventSound(this, SE_PIKI_GOHOME);
	pikiInfMgr.incPiki(piki);
	mHeldPikis[piki->mHappa]++;
	piki->setEraseKill();
	piki->kill(false);
	GameStat::containerPikis.inc(piki->mColor);
	GameStat::update();
	if (old == 1) {
		((SimpleAI*)mStateMachine)->start(this, 0);
	}
}

/*
 * --INFO--
 * Address:	800EB31C
 * Size:	000020
 */
void GoalItem::exitPikis(int pikis)
{
	mIsDispensingPikis = true;
	mPikisToExit += pikis;
	_418 = 0.0f;
}

/*
 * --INFO--
 * Address:	800EB33C
 * Size:	00027C
 */
Piki* GoalItem::exitPiki()
{
	int leg = gsys->getRand(1.0f) * 3.0f;
	if (leg >= 3) {
		leg = 2;
	}
	CollPart* legColl          = mCollInfo->getSphere(leg_ids[leg]);
	pikiMgr->containerExitMode = 1;
	Piki* piki                 = (Piki*)pikiMgr->birth();
	pikiMgr->containerExitMode = 0;
	if (!piki) {
		ERROR("*** PIKI BIRTH FAILED !!!\n");
		return nullptr;
	}

	Navi* navi = naviMgr->getNavi();
	piki->init(navi);
	piki->resetPosition(legColl->mCentre);

	// always pull the highest stage pikmin out first
	int happa;
	if (pikiInfMgr.mPikiCounts[mOnionColour][2] > 0) {
		happa = 2;
	} else if (pikiInfMgr.mPikiCounts[mOnionColour][1] > 0) {
		happa = 1;
	} else {
		happa = 0;
	}
	piki->setFlower(happa);
	piki->initColor(mOnionColour);
	pikiInfMgr.decPiki(piki);
	piki->mScale.set(1.0f, 1.0f, 1.0f);
	piki->mFSM->transit(piki, PIKISTATE_Normal);
	piki->startRope(mRope[leg * 2], 1.0f);
	piki->changeMode(12, nullptr);
	mHeldPikis[happa]--;
	GameStat::containerPikis.dec(piki->mColor);
	GameStat::workPikis.inc(piki->mColor);
	GameStat::update();
	playEventSound(this, SE_PIKI_OUTHOME);

	if (mHeldPikis[0] + mHeldPikis[1] + mHeldPikis[2] == 0) {
		((SimpleAI*)mStateMachine)->start(this, 0);
	}
	return piki;
}

/*
 * --INFO--
 * Address:	800EB5B8
 * Size:	000008
 */
bool GoalItem::needShadow()
{
	return false;
}

/*
 * --INFO--
 * Address:	800EB5C0
 * Size:	000110
 */
GoalItem::GoalItem(CreatureProp* prop, ItemShapeObject* shape1, ItemShapeObject* shape2, ItemShapeObject* shape3, SimpleAI* ai)
    : Suckable(16, prop)
{
	mOnionColour     = 0;
	mItemShapeObject = nullptr;
	_438[0]          = shape1;
	_438[1]          = shape2;
	_438[2]          = shape3;
	mItemShapeObject = _438[0];
	mStateMachine    = ai;
	mCollInfo        = new CollInfo(15);
	mHaloEfx         = nullptr;
	mSpotEfx         = nullptr;
	mSuckEfx         = nullptr;
}

/*
 * --INFO--
 * Address:	800EB6D0
 * Size:	00001C
 */
bool GoalItem::ignoreAtari(Creature* obj)
{
	if (obj->mObjType == OBJTYPE_NULL12) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800EB6EC
 * Size:	000044
 */
void GoalItem::setColorType(int type)
{
	mOnionColour     = type;
	mItemShapeObject = _438[type];
	mItemShapeObject->mShape->makeInstance(mDynMaterial, 0);
}

/*
 * --INFO--
 * Address:	800EB730
 * Size:	00007C
 */
void GoalItem::startTakeoff()
{
	setMotionSpeed(30.0f);
	startMotion(mOnionColour + 6);
	int i = 0;
	while (i < 10) {
		PRINT("** GOAL TAKEOFF !\n");
		i++;
	}
	setCreatureFlag(CF_IsAiDisabled);
}

/*
 * --INFO--
 * Address:	800EB7AC
 * Size:	000104
 */
void GoalItem::startLand()
{
	_3CC = 0;
	startMotion(mOnionColour + 9);
	setMotionSpeed(30.0f);
	_3FC = mSpotModelEff->_14;
	setFlowEffect(true);
	setFlightLight(true);
	mSpotModelEff->_14.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800EB8B0
 * Size:	000030
 */
void GoalItem::startConeShrink()
{
	_3F6           = true;
	mConeSizeTimer = 0.8f;
	_3FC           = mSpotModelEff->_14;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void GoalItem::updateConeShrink()
{
	if (!_3F6) {
		return;
	}

	f32 test     = mConeSizeTimer / 0.8f;
	Vector3f pos = _3FC;
	pos.x *= test;
	pos.z *= test;

	mSpotModelEff->_14 = pos;

	mConeSizeTimer -= gsys->getFrameTime();

	if (mConeSizeTimer <= 0.0f) {
		mSpotModelEff->_14.set(0.0f, 0.0f, 0.0f);
		_3F6 = false;
	}
}

/*
 * --INFO--
 * Address:	800EB8E0
 * Size:	000014
 */
void GoalItem::startConeEmit()
{
	mIsConeEmit    = true;
	mConeSizeTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void GoalItem::updateConeEmit()
{
	if (!mIsConeEmit) {
		return;
	}

	f32 val      = mConeSizeTimer; // don't ask.
	f32 test     = val / 0.8f;
	Vector3f pos = _3FC;
	pos.x *= test;
	pos.z *= test;

	mSpotModelEff->_14 = pos;

	mConeSizeTimer += gsys->getFrameTime();

	if (mConeSizeTimer >= 0.8f) {
		mSpotModelEff->_14 = _3FC;
		mIsConeEmit        = false;
		((SimpleAI*)mStateMachine)->start(this, 0);
	}
}

/*
 * --INFO--
 * Address:	800EB8F4
 * Size:	000494
 */
void GoalItem::startAI(int)
{
	_3F4     = 1;
	mSpotEfx = nullptr;
	mHaloEfx = nullptr;
	setSpotActive(false);
	setFlowEffect(false);
	_3F5        = 0;
	_3F6        = 0;
	mIsConeEmit = false;
	mSeContext  = &_45C;
	mSeContext->setContext(this, 3);
	mHeldPikis[2] = nullptr;
	mHeldPikis[1] = nullptr;
	mHeldPikis[0] = nullptr;
	mCollInfo->initInfo(mItemShapeObject->mShape, nullptr, nullptr);
	mWaypointIdx = routeMgr->findNearestWayPoint('test', mPosition, false)->mIndex;

	Vector3f a(0.0f, 0.0f, 0.0f);
	Vector3f b(1.0f, 1.0f, 1.0f);
	mSpotModelEff = effectMgr->create((EffectMgr::modelTypeTable)mOnionColour, mPosition, a, b);
	mScale.set(1.0f, 1.0f, 1.0f);
	_2D0 = 0;
	_2D4 = 0;

	for (int i = 0; i < 3; i++) {
		RopeItem* rope  = mRope[i];
		CollPart* coll  = mCollInfo->getSphere(leg_ids[i]);
		CollPart* child = coll->getChild();
		Vector3f diff   = coll->mCentre - child->mCentre;
		f32 len         = diff.length();

		Creature* obj = itemMgr->birth(OBJTYPE_Fulcrum);
		obj->init(coll->mCentre);
		obj->startAI(0);

		rope = (RopeItem*)itemMgr->birth(OBJTYPE_Rope);
		rope->init(coll->mCentre);
		rope->setRope(obj);
		rope->mRopeLength = len;
		rope->mOwner      = this;
		rope->startAI(0);
	}

	for (int i = 0; i < 3; i++) {
		PRINT("****** CONTAINER %d : %d/%d/%d pikis\n", mOnionColour, mHeldPikis[Leaf], mHeldPikis[Bud], mHeldPikis[Flower]);
		mHeldPikis[i] = pikiInfMgr.mPikiCounts[mOnionColour][i];
	}

	WayPoint* wp = routeMgr->getWayPoint('test', mWaypointIdx);
	if (!playerState->bootContainer(mOnionColour) || playerState->isTutorial()) {
		setMotionSpeed(0.0f);
		((SimpleAI*)mStateMachine)->start(this, 5);
		startConeShrink();
		enableColorAnim();
		_3D0 = 0.0f;
		wp->setFlag(false);
	} else {
		setMotionSpeed(30.0f);
		mItemAnimator.startMotion(PaniMotionInfo(1));
		((SimpleAI*)mStateMachine)->start(this, 0);
		disableColorAnim();
		wp->setFlag(true);
	}
	_41C               = mPosition;
	_41C.y             = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	mIsDispensingPikis = false;
	mPikisToExit       = 0;
	_418               = 0.0f;
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stfd      f29, 0xB8(r1)
	  stfd      f28, 0xB0(r1)
	  stmw      r25, 0x94(r1)
	  addi      r31, r3, 0
	  li        r30, 0
	  stb       r0, 0x3F4(r3)
	  stw       r30, 0x3DC(r31)
	  stw       r30, 0x3E0(r31)
	  bl        -0x9C8
	  stb       r30, 0x3E4(r31)
	  lwz       r4, 0x3E8(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x64
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xB5C74
	  stw       r30, 0x3E8(r31)

	.loc_0x64:
	  li        r30, 0
	  stb       r30, 0x3F5(r31)
	  addi      r0, r31, 0x45C
	  addi      r4, r31, 0
	  stb       r30, 0x3F6(r31)
	  li        r5, 0x3
	  stb       r30, 0x408(r31)
	  stw       r0, 0x2C(r31)
	  lwz       r3, 0x2C(r31)
	  bl        -0x47C48
	  stw       r30, 0x434(r31)
	  li        r5, 0
	  li        r6, 0
	  stw       r30, 0x430(r31)
	  stw       r30, 0x42C(r31)
	  lwz       r4, 0x3C0(r31)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x0(r4)
	  bl        -0x61E3C
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  addi      r5, r31, 0x94
	  li        r6, 0
	  bl        -0x4A8D0
	  lwz       r0, 0x10(r3)
	  addi      r7, r1, 0x60
	  addi      r6, r1, 0x6C
	  extsh     r0, r0
	  sth       r0, 0x42A(r31)
	  addi      r5, r31, 0x94
	  lfs       f1, -0x34A4(r13)
	  lfs       f0, -0x34B0(r13)
	  stfs      f1, 0x60(r1)
	  lfs       f1, -0x34A0(r13)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, -0x34AC(r13)
	  stfs      f1, 0x64(r1)
	  lfs       f1, -0x349C(r13)
	  stfs      f0, 0x70(r1)
	  lfs       f0, -0x34A8(r13)
	  stfs      f1, 0x68(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x74(r1)
	  lhz       r4, 0x428(r31)
	  bl        0xB11B0
	  stw       r3, 0x40C(r31)
	  li        r27, 0
	  lis       r3, 0x802C
	  lfs       f0, -0x65C0(r2)
	  rlwinm    r4,r27,2,0,29
	  subi      r0, r3, 0x378C
	  stfs      f0, 0x7C(r31)
	  add       r28, r0, r4
	  addi      r29, r31, 0
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  stw       r30, 0x2D0(r31)
	  stw       r30, 0x2D4(r31)
	  lfs       f30, -0x65C4(r2)
	  lfd       f31, -0x6590(r2)
	  lfd       f29, -0x6588(r2)

	.loc_0x15C:
	  lwz       r3, 0x220(r31)
	  addi      r26, r29, 0x444
	  lwz       r4, 0x0(r28)
	  bl        -0x6234C
	  mr        r25, r3
	  bl        -0x63CA0
	  lfs       f3, 0x8(r25)
	  mr        r30, r3
	  lfs       f2, 0x8(r3)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r3)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r25)
	  fsubs     f4, f1, f0
	  lfs       f1, 0xC(r3)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f28, f2, f0
	  fcmpo     cr0, f28, f30
	  ble-      .loc_0x208
	  fsqrte    f1, f28
	  fmul      f0, f1, f1
	  fmul      f1, f31, f1
	  fmul      f0, f28, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f31, f1
	  fmul      f0, f28, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f31, f1
	  fmul      f0, f28, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0x34(r1)
	  lfs       f28, 0x34(r1)

	.loc_0x208:
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x11
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r26)
	  addi      r4, r25, 0x4
	  lwz       r3, 0x0(r26)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x12
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4(r26)
	  addi      r4, r30, 0x4
	  lwz       r3, 0x4(r26)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r26)
	  lwz       r4, 0x0(r26)
	  bl        -0x57488
	  lwz       r3, 0x4(r26)
	  li        r4, 0
	  stfs      f28, 0x2C0(r3)
	  lwz       r3, 0x4(r26)
	  stw       r31, 0x2FC(r3)
	  lwz       r3, 0x4(r26)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x3
	  addi      r29, r29, 0x8
	  addi      r28, r28, 0x4
	  blt+      .loc_0x15C
	  lhz       r0, 0x428(r31)
	  lis       r4, 0x803D
	  lis       r3, 0x7465
	  mulli     r0, r0, 0xC
	  addi      r5, r4, 0x1DF0
	  add       r4, r5, r0
	  lwz       r0, 0x0(r4)
	  addi      r4, r3, 0x7374
	  stw       r0, 0x42C(r31)
	  lhz       r0, 0x428(r31)
	  mulli     r0, r0, 0xC
	  add       r3, r5, r0
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x430(r31)
	  lhz       r0, 0x428(r31)
	  mulli     r0, r0, 0xC
	  add       r3, r5, r0
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x434(r31)
	  lwz       r3, 0x302C(r13)
	  lha       r5, 0x42A(r31)
	  bl        -0x4A5A0
	  lwz       r7, 0x2F6C(r13)
	  li        r5, 0x1
	  lhz       r4, 0x428(r31)
	  addi      r25, r3, 0
	  lbz       r6, 0x184(r7)
	  addi      r0, r4, 0x3
	  slw       r0, r5, r0
	  and.      r0, r6, r0
	  beq-      .loc_0x35C
	  mr        r3, r7
	  bl        -0x6B7D0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3D0

	.loc_0x35C:
	  mr        r3, r31
	  lfs       f1, -0x65C4(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0x5
	  bl        -0x6E51C
	  li        r7, 0x1
	  stb       r7, 0x3F6(r31)
	  addi      r3, r25, 0
	  li        r4, 0
	  lfs       f0, -0x6598(r2)
	  stfs      f0, 0x3F8(r31)
	  lwz       r6, 0x40C(r31)
	  lwz       r5, 0x14(r6)
	  lwz       r0, 0x18(r6)
	  stw       r5, 0x3FC(r31)
	  stw       r0, 0x400(r31)
	  lwz       r0, 0x1C(r6)
	  stw       r0, 0x404(r31)
	  lfs       f0, -0x65C4(r2)
	  stfs      f0, 0x3D4(r31)
	  stb       r7, 0x3D8(r31)
	  stfs      f0, 0x3D0(r31)
	  bl        -0x4A54C
	  b         .loc_0x42C

	.loc_0x3D0:
	  mr        r3, r31
	  lfs       f1, -0x659C(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x4C
	  li        r4, 0x1
	  bl        0x33274
	  addi      r4, r3, 0
	  addi      r3, r31, 0x36C
	  bl        0x334D0
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x6E5A8
	  lfs       f0, -0x65C0(r2)
	  li        r0, 0
	  addi      r3, r25, 0
	  stfs      f0, 0x3D4(r31)
	  li        r4, 0x1
	  stb       r0, 0x3D8(r31)
	  bl        -0x4A5AC

	.loc_0x42C:
	  lwz       r3, 0x94(r31)
	  li        r4, 0x1
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x41C(r31)
	  stw       r0, 0x420(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x424(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x83E44
	  stfs      f1, 0x420(r31)
	  li        r0, 0
	  stb       r0, 0x410(r31)
	  stw       r0, 0x414(r31)
	  lfs       f0, -0x65C4(r2)
	  stfs      f0, 0x418(r31)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lfd       f29, 0xB8(r1)
	  lfd       f28, 0xB0(r1)
	  lmw       r25, 0x94(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EBD88
 * Size:	000074
 */
void GoalItem::startBoot()
{
	_3CC = 3;
	setMotionSpeed(30.0f);
	((SimpleAI*)mStateMachine)->start(this, 5);
	playerState->setBootContainer(mOnionColour);
}

/*
 * --INFO--
 * Address:	800EBDFC
 * Size:	00002C
 */
void GoalItem::emitPiki()
{
	((SimpleAI*)mStateMachine)->start(this, 2);
}

/*
 * --INFO--
 * Address:	800EBE28
 * Size:	000008
 */
f32 GoalItem::getSize()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800EBE30
 * Size:	000008
 */
f32 GoalItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800EBE38
 * Size:	0002D4
 */
void GoalItem::update()
{
	mVelocity.set(0.0f, 0.0f, 0.0f);
	ItemCreature::update();
	if (_3D8) {
		_3D4 += (_3D0 * mMotionSpeed * gsys->getFrameTime()) / 30.0f;
		if (_3D4 > 1.0f) {
			disableColorAnim();
		}
	}

	if (_3F6) {
		updateConeShrink();
	}

	if (mIsConeEmit) {
		updateConeEmit();
	}

	mPosition = _41C;

	if (mIsDispensingPikis) {
		if (_418 <= 0.0f) {
			if (!exitPiki()) {
				int mapPikis = GameStat::mapPikis;
				int mePikis  = GameStat::mePikis;
				PRINT("map=%d mePiki=%d exitC=%d", mapPikis, mePikis, mPikisToExit);
				ERROR("2d err %d %d %d", mapPikis, mePikis, mPikisToExit);
			}
			mPikisToExit--;
			if (mPikisToExit <= 0) {
				mIsDispensingPikis = false;
			}
			_418 = gsys->getRand(1.0f) * 0.1f + 0.2f;
			_418 *= 0.2f;
		} else {
			_418 -= gsys->getFrameTime();
		}
	}
}

/*
 * --INFO--
 * Address:	800EC10C
 * Size:	000378
 */
void GoalItem::refresh(Graphics& gfx)
{
	if (!gameflow.mGamePrefs._22 || demoHideFlag & 1 << mOnionColour) {
		return;
	}

	mScale.set(1.0f, 1.0f, 1.0f);
	Matrix4f mtx1;
	Vector3f pos = mPosition;
	mTransformMatrix.makeSRT(mScale, mRotation, pos);
	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, mtx1);
	if (!gfx.mCamera->isPointVisible(mPosition, 200.0f)) {
		enableAICulling();
		if (!gameflow.mGamePrefs._22) {
			// mSpotModelEff->_38.mOrigin = 0;
		}
	} else {
		disableAICulling();
		// mSpotModelEff->_38.mOrigin = 0;
	}

	gfx.setLighting(true, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	mItemAnimator.finishLoop();

	f32 rate;
	if (_3D8) {
		rate = int(mOnionColour * 2 + 1) - _3D4;
	} else {
		rate = int(mOnionColour << 1);
	}
	mDynMaterial.animate(&rate);
	mItemShapeObject->mShape->updateAnim(gfx, mtx1, nullptr);
	if (aiCullable()) {
		mItemShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mDynMaterial);
	}
	mCollInfo->updateInfo(gfx, false);

	for (int i = 0; i < 3; i++) {
		RopeItem* rope = mRope[i];
		if (pikiMgr->containerDebug) {
			PRINT("leg %d : (%.1f %.1f %.1f) \n", i);
		}
		CollPart* coll  = mCollInfo->getSphere(leg_ids[i]);
		CollPart* child = coll->getChild();
		rope->mPosition = coll->mCentre;
		rope->mPosition = child->mCentre;

		Vector3f diff     = coll->mCentre - child->mCentre;
		rope->mRopeLength = diff.length();
		if (pikiMgr->containerDebug) {
			PRINT("==> (%.1f %.1f %.1f) : motion %d\n");
			printMatrix("invCam", gfx.mCamera->mInverseLookAtMtx);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  stmw      r25, 0xCC(r1)
	  addi      r28, r5, 0x1DC
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  lwz       r5, 0x1DC(r5)
	  lbz       r0, 0x124(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x58
	  lhz       r0, 0x428(r26)
	  li        r3, 0x1
	  lbz       r4, 0x30A0(r13)
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  bne-      .loc_0x358

	.loc_0x58:
	  lfs       f0, -0x65C0(r2)
	  addi      r3, r26, 0x228
	  addi      r4, r26, 0x7C
	  stfs      f0, 0x7C(r26)
	  addi      r5, r26, 0x88
	  addi      r6, r1, 0x70
	  stfs      f0, 0x80(r26)
	  stfs      f0, 0x84(r26)
	  lfs       f0, 0x94(r26)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x98(r26)
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x9C(r26)
	  stfs      f0, 0x78(r1)
	  bl        -0xAE0A8
	  lwz       r3, 0x2E4(r27)
	  addi      r4, r26, 0x228
	  addi      r5, r1, 0x7C
	  addi      r3, r3, 0x1E0
	  bl        -0xAE0DC
	  lwz       r3, 0x2E4(r27)
	  addi      r4, r26, 0x94
	  lfs       f1, -0x6574(r2)
	  bl        -0xAAC3C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xEC
	  lwz       r0, 0xC8(r26)
	  oris      r0, r0, 0x8
	  stw       r0, 0xC8(r26)
	  lwz       r3, 0x0(r28)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x104
	  lwz       r3, 0x40C(r26)
	  li        r0, 0
	  stb       r0, 0x42(r3)
	  b         .loc_0x104

	.loc_0xEC:
	  lwz       r3, 0xC8(r26)
	  li        r0, 0x1
	  rlwinm    r3,r3,0,13,11
	  stw       r3, 0xC8(r26)
	  lwz       r3, 0x40C(r26)
	  stb       r0, 0x42(r3)

	.loc_0x104:
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r27)
	  lis       r4, 0x803A
	  mr        r3, r27
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  addi      r3, r26, 0x36C
	  lwz       r12, 0x39C(r26)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x3D8(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x198
	  lhz       r3, 0x428(r26)
	  lis       r0, 0x4330
	  lfd       f2, -0x65A8(r2)
	  rlwinm    r3,r3,1,0,30
	  lfs       f0, 0x3D4(r26)
	  addi      r3, r3, 0x1
	  xoris     r3, r3, 0x8000
	  stw       r3, 0xC4(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f1, 0xC0(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  b         .loc_0x1C0

	.loc_0x198:
	  lhz       r3, 0x428(r26)
	  lis       r0, 0x4330
	  lfd       f1, -0x65A8(r2)
	  rlwinm    r3,r3,1,0,30
	  xoris     r3, r3, 0x8000
	  stw       r3, 0xC4(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f0, 0xC0(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x6C(r1)

	.loc_0x1C0:
	  addi      r3, r26, 0x484
	  addi      r4, r1, 0x6C
	  bl        -0xBD238
	  lwz       r3, 0x3C0(r26)
	  addi      r4, r27, 0
	  addi      r5, r1, 0x7C
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0xB6FD8
	  lwz       r0, 0xC8(r26)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x208
	  lwz       r3, 0x3C0(r26)
	  mr        r4, r27
	  lwz       r5, 0x2E4(r27)
	  addi      r6, r26, 0x484
	  lwz       r3, 0x0(r3)
	  bl        -0xBBEA4

	.loc_0x208:
	  lwz       r3, 0x220(r26)
	  addi      r4, r27, 0
	  li        r5, 0
	  bl        -0x62834
	  li        r29, 0
	  lfs       f30, -0x65C4(r2)
	  lis       r3, 0x802C
	  lfd       f31, -0x6590(r2)
	  rlwinm    r4,r29,2,0,29
	  lfd       f29, -0x6588(r2)
	  subi      r0, r3, 0x378C
	  add       r30, r0, r4
	  addi      r31, r26, 0

	.loc_0x23C:
	  lbz       r0, 0x306C(r13)
	  addi      r28, r31, 0x444
	  cmplwi    r0, 0
	  lwz       r3, 0x220(r26)
	  lwz       r4, 0x0(r30)
	  bl        -0x62C4C
	  mr        r25, r3
	  bl        -0x645A0
	  lwz       r5, 0x0(r28)
	  lwz       r4, 0x4(r25)
	  lwz       r0, 0x8(r25)
	  stw       r4, 0x94(r5)
	  stw       r0, 0x98(r5)
	  lwz       r0, 0xC(r25)
	  stw       r0, 0x9C(r5)
	  lwz       r5, 0x4(r28)
	  lwz       r4, 0x4(r3)
	  lwz       r0, 0x8(r3)
	  stw       r4, 0x94(r5)
	  stw       r0, 0x98(r5)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x9C(r5)
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0x0(r28)
	  addi      r4, r4, 0x94
	  addi      r3, r3, 0x94
	  lfs       f2, 0x4(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x0(r4)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x8(r3)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x8(r4)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f30
	  ble-      .loc_0x334
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f31, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f31, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f31, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f2, 0x3C(r1)

	.loc_0x334:
	  lwz       r3, 0x4(r28)
	  stfs      f2, 0x2C0(r3)
	  lbz       r0, 0x306C(r13)
	  cmplwi    r0, 0
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x4
	  blt+      .loc_0x23C

	.loc_0x358:
	  lmw       r25, 0xCC(r1)
	  lwz       r0, 0x104(r1)
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EC484
 * Size:	00001C
 */
Vector3f GoalItem::getGoalPos()
{
	return mPosition;
}

/*
 * --INFO--
 * Address:	800EC4A0
 * Size:	000008
 */
f32 GoalItem::getGoalPosRadius()
{
	return 75.0f;
}

/*
 * --INFO--
 * Address:	800EC4A8
 * Size:	000008
 */
int GoalItem::getRouteIndex()
{
	return mWaypointIdx;
}

/*
 * --INFO--
 * Address:	800EC4B0
 * Size:	000008
 */
bool GoalItem::isVisible()
{
	return true;
}

/*
 * --INFO--
 * Address:	800EC4B8
 * Size:	000008
 */
bool GoalItem::isAlive()
{
	return true;
}
