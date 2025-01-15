#include "GoalItem.h"
#include "EffectMgr.h"
#include "DebugLog.h"
#include "Route.h"
#include "SoundMgr.h"
#include "Pellet.h"
#include "Piki.h"
#include "BaseInf.h"
#include "GameStat.h"
#include "PlayerState.h"
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
	switch (mItemAnimator.mCurrentAnimID) {
	default:
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
		switch (id) {
		case 0:
			setFlowEffect(false);
			break;
		case 1:
			startConeShrink();
			break;
		case 2:
			effectMgr->create(EffectMgr::EFF_Rocket_Tbc1, mPosition, nullptr, nullptr);
			break;
		case 3:
			setFlightLight(false);
			break;
		}
		break;
	case 9:
		if (mCreatureFlags & 0x200) {
			Vector3f pos[4];
			pos[0] = mCollInfo->getSphere('eff1')->mCentre;
			pos[1] = mCollInfo->getSphere('eff2')->mCentre;
			pos[2] = mCollInfo->getSphere('eff3')->mCentre;
			pos[3] = mCollInfo->getSphere('piki')->mCentre;
			if (id == 0) {
				effectMgr->create(EffectMgr::EFF_Onyon_Sparkles, pos[3], nullptr, nullptr);
			}
			effectMgr->create(EffectMgr::EFF_Onyon_Puff, pos[rand() % 3], nullptr, nullptr);
			playEventSound(this, EffectMgr::EFF_Bridge_FinishStage);
		}
		break;
	case 4:
		switch (id) {
		case 0:
			Vector3f pos = mCollInfo->getSphere('piki')->mCentre;
			effectMgr->create(EffectMgr::EFF_Kafun_BS, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Kafun_NG, pos, nullptr, nullptr);
			break;
		case 1:
			Vector3f pos2 = mPosition;
			if (mOnionColour == 0) {
				effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, pos, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_Ripples2, pos, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_Ripples1, pos, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_Onyon_Suck2, pos, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Rocket_Bm1o, pos, nullptr, nullptr);
			}
			break;
		case 2:
			routeMgr->getWayPoint('test', _42A)->setFlag(true);
			if (mOnionColour == 0) {
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
			}
			break;
		case 3:
			if (mOnionColour == 0) {
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
			_3D4 = 0.0f;
			_3D8 = 1;
			_3D0 = 20.0f;
			break;
		}
		break;
	};
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
			mSuckEfx       = effectMgr->create(EffectMgr::EFF_Rocket_FlowLight, part->mCentre, nullptr, nullptr);
			if (mSuckEfx) {
				mSuckEfx->mEmitPosPtr = &part->mCentre;
			}
		}
	} else if (mSuckEfx) {
		effectMgr->mPtclMgr.killGenerator(mSuckEfx, false);
		mSuckEfx = nullptr;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  stb       r4, 0x3E4(r3)
	  beq-      .loc_0x78
	  lwz       r0, 0x3E8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x9C
	  lis       r4, 0x7069
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6B69
	  bl        -0x617E0
	  mr        r31, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x128
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1C2C
	  stw       r3, 0x3E8(r30)
	  lwz       r3, 0x3E8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x9C
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)
	  b         .loc_0x9C

	.loc_0x78:
	  lwz       r4, 0x3E8(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x9C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xB6680
	  li        r0, 0
	  stw       r0, 0x3E8(r30)

	.loc_0x9C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EAF68
 * Size:	000178
 */
void GoalItem::setSpotActive(bool set)
{
	_3D9 = set;

	if (_3D9) {
		EffectMgr::effTypeTable efxIDs[3]
		    = { EffectMgr::EFF_Onyon_BeaconRingBlue, EffectMgr::EFF_Onyon_BeaconRingRed, EffectMgr::EFF_Onyon_BeaconRingYellow };

		if (!mSpotEfx) {
			mSpotEfx = effectMgr->create(efxIDs[mOnionColour], mPosition, nullptr, nullptr);
			if (mSpotEfx) {
				mSpotEfx->mEmitPosPtr = &mPosition;
			}
			SeSystem::playSysSe(SYSSE_CONTAINER_OK);
		}
	} else {
		if (mSpotEfx) {
			SeSystem::stopSysSe(SYSSE_CONTAINER_OK);
			effectMgr->mPtclMgr.killGenerator(mSpotEfx, false);
			mSpotEfx = nullptr;
		}
	}

	if (_3D9) {
		EffectMgr::effTypeTable efxIDs[3]
		    = { EffectMgr::EFF_Onyon_HaloRingBlue, EffectMgr::EFF_Onyon_HaloRingRed, EffectMgr::EFF_Onyon_HaloRingYellow };

		if (!mHaloEfx) {
			mHaloEfx = effectMgr->create(efxIDs[mOnionColour], mPosition, nullptr, nullptr);
			if (mHaloEfx) {
				mHaloEfx->mEmitPosPtr = &mPosition;
			}
		}
	} else {
		if (mHaloEfx) {
			effectMgr->mPtclMgr.killGenerator(mHaloEfx, false);
			mHaloEfx = nullptr;
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stb       r4, 0x3D9(r3)
	  lbz       r0, 0x3D9(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  lis       r3, 0x8022
	  addi      r4, r3, 0x264C
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x2C(r1)
	  lwz       r0, 0x3DC(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xC8
	  lhz       r0, 0x428(r31)
	  addi      r4, r1, 0x24
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1B60
	  stw       r3, 0x3DC(r31)
	  lwz       r3, 0x3DC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  addi      r0, r31, 0x94
	  stw       r0, 0x18(r3)

	.loc_0x8C:
	  li        r3, 0x120
	  bl        -0x45C84
	  b         .loc_0xC8

	.loc_0x98:
	  lwz       r0, 0x3DC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xC8
	  li        r3, 0x120
	  bl        -0x45C68
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  lwz       r4, 0x3DC(r31)
	  addi      r3, r3, 0x14
	  bl        0xB65A0
	  li        r0, 0
	  stw       r0, 0x3DC(r31)

	.loc_0xC8:
	  lbz       r0, 0x3D9(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x140
	  lis       r3, 0x8022
	  addi      r4, r3, 0x2658
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x18(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x20(r1)
	  lwz       r0, 0x3E0(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x164
	  lhz       r0, 0x428(r31)
	  addi      r4, r1, 0x18
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  li        r6, 0
	  li        r7, 0
	  bl        0xB1AB0
	  stw       r3, 0x3E0(r31)
	  lwz       r3, 0x3E0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x164
	  addi      r0, r31, 0x94
	  stw       r0, 0x18(r3)
	  b         .loc_0x164

	.loc_0x140:
	  lwz       r4, 0x3E0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x164
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xB6504
	  li        r0, 0
	  stw       r0, 0x3E0(r31)

	.loc_0x164:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
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
	if (mOnionColour == config->mPelletColor()) {
		pikiNum = config->mMatchingOnyonSeeds();
	} else {
		pikiNum = config->mNonMatchingOnyonSeeds();
	}

	if (pikiNum < 0) {
		_2D4 += 2;
		Msg msg(10);
		mStateMachine->procMsg(this, &msg);
		playEventSound(this, SE_CONTAINER_HANABI);
		playEventSound(this, SE_CONTAINER_PELLETIN2);
	} else {
		_2D0 += pikiNum;
		Msg msg(10);
		mStateMachine->procMsg(this, &msg);
		playEventSound(this, SE_CONTAINER_PELLETIN2);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r4, 0x55C(r4)
	  lhz       r3, 0x428(r3)
	  lwz       r0, 0x5C(r4)
	  cmpw      r3, r0
	  bne-      .loc_0x30
	  lwz       r5, 0xDC(r4)
	  b         .loc_0x34

	.loc_0x30:
	  lwz       r5, 0xEC(r4)

	.loc_0x34:
	  cmpwi     r5, 0
	  bge-      .loc_0x98
	  lwz       r4, 0x2D4(r31)
	  li        r3, 0xA
	  li        r0, 0
	  addi      r4, r4, 0x2
	  stw       r4, 0x2D4(r31)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x24
	  stw       r3, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xD8
	  bl        -0x60C30
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xD6
	  bl        -0x60C40
	  b         .loc_0xE0

	.loc_0x98:
	  lwz       r4, 0x2D0(r31)
	  li        r3, 0xA
	  li        r0, 0
	  add       r4, r4, r5
	  stw       r4, 0x2D0(r31)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x1C
	  stw       r3, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xD6
	  bl        -0x60C8C

	.loc_0xE0:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EB258
 * Size:	0000C4
 */
void GoalItem::enterGoal(Piki* piki)
{
	int old = mItemAnimator.mCurrentAnimID;
	playEventSound(this, SE_PIKI_GOHOME);
	pikiInfMgr.incPiki(piki);
	_42C[piki->mHappa]++;
	piki->_584 = 1;
	piki->kill(false);
	GameStat::containerPikis.mCounts[piki->mColor]++;
	GameStat::update();
	if (old == 1) {
		((SimpleAI*)mStateMachine)->start(this, 0);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xD2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  addi      r4, r29, 0
	  lwz       r31, 0x3B0(r3)
	  bl        -0x60CD0
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  addi      r4, r30, 0
	  bl        -0x25AB0
	  lwz       r4, 0x520(r30)
	  li        r0, 0x1
	  addi      r3, r30, 0
	  rlwinm    r4,r4,2,0,29
	  add       r6, r29, r4
	  lwz       r5, 0x42C(r6)
	  li        r4, 0
	  addi      r5, r5, 0x1
	  stw       r5, 0x42C(r6)
	  stb       r0, 0x584(r30)
	  bl        -0x605E0
	  lhz       r4, 0x510(r30)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1EA0
	  rlwinm    r3,r4,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x2727C
	  cmpwi     r31, 0x1
	  bne-      .loc_0xA8
	  lwz       r3, 0x2E8(r29)
	  addi      r4, r29, 0
	  li        r5, 0
	  bl        -0x6DBA4

	.loc_0xA8:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EB31C
 * Size:	000020
 */
void GoalItem::exitPikis(int pikis)
{
	_410 = 1;
	_414 += pikis;
	_418 = 0.0f;
}

/*
 * --INFO--
 * Address:	800EB33C
 * Size:	00027C
 */
void GoalItem::exitPiki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  stw       r28, 0x30(r1)
	  bl        0x12CD14
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x65A8(r2)
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x65BC(r2)
	  stw       r0, 0x28(r1)
	  lfs       f1, -0x65C0(r2)
	  lfd       f3, 0x28(r1)
	  lfs       f0, -0x65B4(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stfd      f0, 0x20(r1)
	  cmpwi     r0, 0x3
	  lwz       r31, 0x24(r1)
	  blt-      .loc_0x78
	  li        r31, 0x2

	.loc_0x78:
	  lis       r4, 0x802C
	  lwz       r3, 0x220(r29)
	  rlwinm    r5,r31,2,0,29
	  subi      r0, r4, 0x378C
	  add       r4, r0, r5
	  lwz       r4, 0x0(r4)
	  bl        -0x61CBC
	  li        r0, 0x1
	  addi      r28, r3, 0
	  stb       r0, 0x306F(r13)
	  lwz       r3, 0x3068(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  mr.       r30, r3
	  stb       r0, 0x306F(r13)
	  bne-      .loc_0xCC
	  li        r3, 0
	  b         .loc_0x25C

	.loc_0xCC:
	  lwz       r3, 0x3120(r13)
	  bl        0x2BFB8
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  bl        -0x1F3D4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r28, 0x4
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x428(r29)
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  mulli     r0, r0, 0xC
	  add       r3, r3, r0
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x120
	  li        r28, 0x2
	  b         .loc_0x138

	.loc_0x120:
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x134
	  li        r28, 0x1
	  b         .loc_0x138

	.loc_0x134:
	  li        r28, 0

	.loc_0x138:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lhz       r4, 0x428(r29)
	  bl        -0x21C1C
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  addi      r4, r30, 0
	  bl        -0x25C70
	  lfs       f0, -0x347C(r13)
	  addi      r4, r30, 0
	  li        r5, 0
	  stfs      f0, 0x7C(r30)
	  lfs       f0, -0x3478(r13)
	  stfs      f0, 0x80(r30)
	  lfs       f0, -0x3474(r13)
	  stfs      f0, 0x84(r30)
	  lwz       r3, 0x490(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r31,3,0,28
	  lfs       f1, -0x65C0(r2)
	  add       r3, r29, r0
	  lwz       r4, 0x448(r3)
	  mr        r3, r30
	  bl        -0x5AA28
	  addi      r3, r30, 0
	  li        r4, 0xC
	  li        r5, 0
	  bl        -0x1E334
	  rlwinm    r0,r28,2,0,29
	  add       r6, r29, r0
	  lwz       r5, 0x42C(r6)
	  lis       r4, 0x803D
	  lis       r3, 0x803D
	  subi      r0, r5, 0x1
	  stw       r0, 0x42C(r6)
	  addi      r4, r4, 0x1EA0
	  addi      r0, r3, 0x1E88
	  lhz       r3, 0x510(r30)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r4, r3
	  lwz       r3, 0x0(r4)
	  subi      r3, r3, 0x1
	  stw       r3, 0x0(r4)
	  lhz       r3, 0x510(r30)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x27008
	  addi      r3, r29, 0
	  addi      r4, r29, 0
	  li        r5, 0xD3
	  bl        -0x60FB4
	  lwz       r4, 0x434(r29)
	  lwz       r0, 0x430(r29)
	  lwz       r3, 0x42C(r29)
	  add       r0, r0, r4
	  add.      r0, r3, r0
	  bne-      .loc_0x258
	  lwz       r3, 0x2E8(r29)
	  addi      r4, r29, 0
	  li        r5, 0
	  bl        -0x6DE38

	.loc_0x258:
	  mr        r3, r30

	.loc_0x25C:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r27, r5, 0
	  addi      r28, r6, 0
	  addi      r5, r4, 0
	  addi      r31, r3, 0
	  addi      r29, r7, 0
	  addi      r30, r8, 0
	  li        r4, 0x10
	  li        r6, 0
	  bl        0xA2BC
	  lis       r3, 0x802C
	  subi      r3, r3, 0x3E80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x114
	  lis       r3, 0x802B
	  stw       r0, 0x2B8(r31)
	  addi      r0, r3, 0x5F4
	  lis       r3, 0x802C
	  stw       r0, 0x3C8(r31)
	  subi      r3, r3, 0x3474
	  addi      r4, r3, 0x114
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x174
	  addi      r3, r31, 0x45C
	  stw       r4, 0x2B8(r31)
	  stw       r0, 0x3C8(r31)
	  lfs       f0, -0x65C4(r2)
	  stfs      f0, 0x404(r31)
	  stfs      f0, 0x400(r31)
	  stfs      f0, 0x3FC(r31)
	  stfs      f0, 0x424(r31)
	  stfs      f0, 0x420(r31)
	  stfs      f0, 0x41C(r31)
	  bl        -0x479F4
	  li        r0, 0
	  stw       r0, 0x484(r31)
	  li        r3, 0x14
	  stw       r0, 0x488(r31)
	  stw       r0, 0x48C(r31)
	  stw       r0, 0x490(r31)
	  sth       r0, 0x428(r31)
	  stw       r0, 0x3C0(r31)
	  stw       r27, 0x438(r31)
	  stw       r28, 0x43C(r31)
	  stw       r29, 0x440(r31)
	  lwz       r0, 0x438(r31)
	  stw       r0, 0x3C0(r31)
	  stw       r30, 0x2E8(r31)
	  bl        -0xA4688
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xE4
	  li        r4, 0xF
	  bl        -0x62A70

	.loc_0xE4:
	  stw       r30, 0x220(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x3E0(r31)
	  stw       r0, 0x3DC(r31)
	  stw       r0, 0x3E8(r31)
	  lwz       r0, 0x3C(r1)
	  lmw       r27, 0x24(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
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
	// mItemShapeObject->makeInstance();
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,2,0,29
	  stwu      r1, -0x8(r1)
	  sth       r4, 0x428(r3)
	  add       r4, r3, r0
	  lwz       r0, 0x438(r4)
	  addi      r4, r3, 0x484
	  stw       r0, 0x3C0(r3)
	  lwz       r3, 0x3C0(r3)
	  lwz       r3, 0x0(r3)
	  bl        -0xBBDF0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
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
	mCreatureFlags |= 0x800;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lfs       f1, -0x659C(r2)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lhz       r4, 0x428(r31)
	  lwz       r12, 0x0(r31)
	  addi      r4, r4, 0x6
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x5C

	.loc_0x58:
	  bdnz-     .loc_0x58

	.loc_0x5C:
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x800
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EB7AC
 * Size:	000104
 */
void GoalItem::startLand()
{
	startMotion(mOnionColour + 9);
	setMotionSpeed(30.0f);
	setFlowEffect(true);
	setFlightLight(true);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  stb       r0, 0x3CC(r3)
	  lwz       r12, 0x0(r30)
	  lhz       r4, 0x428(r30)
	  lwz       r12, 0x130(r12)
	  addi      r4, r4, 0x9
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lfs       f1, -0x659C(r2)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x40C(r30)
	  li        r0, 0x1
	  lwz       r4, 0x14(r5)
	  lwz       r3, 0x18(r5)
	  stw       r4, 0x3FC(r30)
	  stw       r3, 0x400(r30)
	  lwz       r3, 0x1C(r5)
	  stw       r3, 0x404(r30)
	  stb       r0, 0x3E4(r30)
	  lwz       r0, 0x3E8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xC4
	  lis       r4, 0x7069
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6B69
	  bl        -0x62128
	  mr        r31, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x128
	  li        r6, 0
	  li        r7, 0
	  bl        0xB12E4
	  stw       r3, 0x3E8(r30)
	  lwz       r3, 0x3E8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xC4
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0xC4:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x740
	  lwz       r3, 0x40C(r30)
	  lfs       f0, -0x3470(r13)
	  stfsu     f0, 0x14(r3)
	  lfs       f0, -0x346C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x3468(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EB8B0
 * Size:	000030
 */
void GoalItem::startConeShrink()
{
	_3F6 = true;
	_3F8 = 0.8f;
	_3FC;
	/*
	.loc_0x0:
	  li        r0, 0x1
	  stb       r0, 0x3F6(r3)
	  lfs       f0, -0x6598(r2)
	  stfs      f0, 0x3F8(r3)
	  lwz       r5, 0x40C(r3)
	  lwz       r4, 0x14(r5)
	  lwz       r0, 0x18(r5)
	  stw       r4, 0x3FC(r3)
	  stw       r0, 0x400(r3)
	  lwz       r0, 0x1C(r5)
	  stw       r0, 0x404(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void GoalItem::updateConeShrink()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EB8E0
 * Size:	000014
 */
void GoalItem::startConeEmit()
{
	_408 = true;
	_3F8 = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void GoalItem::updateConeEmit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EB8F4
 * Size:	000494
 */
void GoalItem::startAI(int)
{
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
	playerState->_184 |= 1 << mOnionColour + 3;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x3
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x3CC(r3)
	  lwz       r12, 0x0(r31)
	  lfs       f1, -0x659C(r2)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0x5
	  bl        -0x6E66C
	  lwz       r6, 0x2F6C(r13)
	  li        r4, 0x1
	  lhz       r3, 0x428(r31)
	  lbz       r5, 0x184(r6)
	  addi      r0, r3, 0x3
	  slw       r0, r4, r0
	  or        r0, r5, r0
	  stb       r0, 0x184(r6)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
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
		_3D4 += (_3D0 * mMotionSpeed * gsys->mDeltaTime) / 30.0f;
		if (_3D4 > 1.0f) {
			_3D4 = 1.0f;
			_3D8 = 0;
		}
	}

	if (_3F6 && _3F6) { }
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r3
	  lfs       f0, -0x3458(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x3454(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x3450(r13)
	  stfs      f0, 0x78(r31)
	  bl        0x9D90
	  lbz       r0, 0x3D8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lfs       f1, 0x3D0(r31)
	  lfs       f0, 0x304(r31)
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f2, f1, f0
	  lfs       f0, -0x659C(r2)
	  lfs       f1, 0x28C(r3)
	  lfs       f3, 0x3D4(r31)
	  fmuls     f1, f2, f1
	  fdivs     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x3D4(r31)
	  lfs       f1, 0x3D4(r31)
	  lfs       f0, -0x65C0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x84
	  stfs      f0, 0x3D4(r31)
	  li        r0, 0
	  stb       r0, 0x3D8(r31)

	.loc_0x84:
	  lbz       r0, 0x3F6(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x138
	  beq-      .loc_0x138
	  lfs       f2, 0x3F8(r31)
	  lfs       f1, -0x6598(r2)
	  lfs       f0, 0x3FC(r31)
	  fdivs     f1, f2, f1
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x400(r31)
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x404(r31)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x50(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x58(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x58(r1)
	  lwz       r4, 0x40C(r31)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0x14(r4)
	  stw       r0, 0x18(r4)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0x1C(r4)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x3F8(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3F8(r31)
	  lfs       f1, 0x3F8(r31)
	  lfs       f0, -0x65C4(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x138
	  lwz       r3, 0x40C(r31)
	  li        r0, 0
	  lfs       f0, -0x3464(r13)
	  stfsu     f0, 0x14(r3)
	  lfs       f0, -0x3460(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x345C(r13)
	  stfs      f0, 0x8(r3)
	  stb       r0, 0x3F6(r31)

	.loc_0x138:
	  lbz       r0, 0x408(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F8
	  beq-      .loc_0x1F8
	  lfs       f1, 0x3F8(r31)
	  lfs       f2, -0x6598(r2)
	  lfs       f0, 0x3FC(r31)
	  fdivs     f1, f1, f2
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x400(r31)
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x404(r31)
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x44(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x4C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lwz       r4, 0x40C(r31)
	  lwz       r3, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r3, 0x14(r4)
	  stw       r0, 0x18(r4)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0x1C(r4)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x3F8(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3F8(r31)
	  lfs       f0, 0x3F8(r31)
	  fcmpo     cr0, f0, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1F8
	  lwz       r7, 0x40C(r31)
	  li        r0, 0
	  lwz       r6, 0x3FC(r31)
	  mr        r4, r31
	  lwz       r3, 0x400(r31)
	  li        r5, 0
	  stw       r6, 0x14(r7)
	  stw       r3, 0x18(r7)
	  lwz       r3, 0x404(r31)
	  stw       r3, 0x1C(r7)
	  stb       r0, 0x408(r31)
	  lwz       r3, 0x2E8(r31)
	  bl        -0x6E8D4

	.loc_0x1F8:
	  lwz       r3, 0x41C(r31)
	  lwz       r0, 0x420(r31)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x424(r31)
	  stw       r0, 0x9C(r31)
	  lbz       r0, 0x410(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C0
	  lfs       f1, 0x418(r31)
	  lfs       f0, -0x65C4(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x2B0
	  mr        r3, r31
	  bl        -0xD30
	  cmplwi    r3, 0
	  lwz       r3, 0x414(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0x414(r31)
	  lwz       r0, 0x414(r31)
	  cmpwi     r0, 0
	  bgt-      .loc_0x25C
	  li        r0, 0
	  stb       r0, 0x410(r31)

	.loc_0x25C:
	  bl        0x12BFDC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x65A8(r2)
	  stw       r0, 0x6C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x65BC(r2)
	  stw       r0, 0x68(r1)
	  lfs       f2, -0x65C0(r2)
	  lfd       f1, 0x68(r1)
	  lfs       f0, -0x6578(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x657C(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x418(r31)
	  lfs       f0, 0x418(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x418(r31)
	  b         .loc_0x2C0

	.loc_0x2B0:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x418(r31)

	.loc_0x2C0:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EC10C
 * Size:	000378
 */
void GoalItem::refresh(Graphics&)
{
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
s16 GoalItem::getRouteIndex()
{
	return _42A;
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
