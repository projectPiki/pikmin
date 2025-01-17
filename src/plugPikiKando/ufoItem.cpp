#include "UfoItem.h"
#include "DebugLog.h"
#include "SoundID.h"
#include "UtEffect.h"
#include "Pellet.h"
#include "NaviMgr.h"
#include "Route.h"
#include "gameflow.h"
#include "Graphics.h"
#include "MoviePlayer.h"
#include "PlayerState.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

int numKeys              = 3;
f32 trKeys[3]            = { 0.0f, 13.0f, 50.0f };
static const int test[3] = { 205, 204, 203 };

const EffectMgr::effTypeTable effects[16]
    = { EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep,
	    EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep,
	    EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep,
	    EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep, EffectMgr::EFF_Rocket_Gep };

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("ufoItem")

/*
 * --INFO--
 * Address:	800E7018
 * Size:	0000B4
 */
bool UfoItem::insideSafeArea(Vector3f& pos)
{
	Vector3f diff = pos - mPosition;
	f32 dist      = diff.x * diff.x + diff.z * diff.z;
	if (dist < 8100.0f) {
		return false;
	}

	Vector3f goal = getGoalPos();
	diff          = goal - pos;
	dist          = diff.x * diff.x + diff.z * diff.z;
	if (dist < 4900.0f) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	800E70CC
 * Size:	000124
 */
void UfoItem::setSpotTurn(bool set)
{
	Vector3f goal  = getGoalPos();
	CollPart* part = mCollInfo->getSphere('gol1');

	if (!set && _3CA) {
		if (mRingEfx) {
			effectMgr->kill(mRingEfx, false);
			mRingEfx = nullptr;
		}
		mRingEfx = effectMgr->create(EffectMgr::EFF_Rocket_NaviNormalRings, goal, nullptr, nullptr);
	} else if (set && !_3CA) {
		if (mRingEfx) {
			effectMgr->kill(mRingEfx, false);
			mRingEfx = nullptr;
		}
		mRingEfx = effectMgr->create(EffectMgr::EFF_Rocket_NaviActionRings, goal, nullptr, nullptr);
	}
	_3CA = set;
}

/*
 * --INFO--
 * Address:	800E71F0
 * Size:	00014C
 */
void UfoItem::setSpotActive(bool set)
{
	_3CA = false;
	_3C9 = set;

	Vector3f goal = Vector3f(getGoalPos());
	f32 paddig[2]; // needed for stack to work
	CollPart* part = mCollInfo->getSphere('gol1');

	if (_3C9) {
		if (mRingEfx) {
			effectMgr->kill(mRingEfx, false);
			mRingEfx = nullptr;
		}
		mRingEfx = effectMgr->create(EffectMgr::EFF_Rocket_NaviNormalRings, goal, nullptr, nullptr);

		if (_3D0) {
			effectMgr->kill(_3D0, false);
			_3D0 = nullptr;
		}
		_3D0 = effectMgr->create(EffectMgr::EFF_Rocket_NaviSparkle, goal, nullptr, nullptr);

	} else {
		if (mRingEfx) {
			effectMgr->kill(mRingEfx, false);
			mRingEfx = nullptr;
		}
		if (_3D0) {
			effectMgr->kill(_3D0, false);
			_3D0 = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	800E733C
 * Size:	0000B8
 */
void UfoItem::setTroubleEffect(bool set)
{
	_428 = set;
	if (set) {
		_42C = 0.0f;
		_430 = -1;
		startTroubleEffectOne(0);
		startTroubleEffectOne(1);
		startTroubleEffectOne(5);
		return;
	}

	for (int i = 0; i < 6; i++) {
		if (_4C4[i]) {
			effectMgr->kill(_4C4[i], false);
			_4C4[i] = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	800E73F4
 * Size:	0000D4
 */
void UfoItem::startTroubleEffectOne(int id)
{
	EffectMgr::effTypeTable ids[6] = { EffectMgr::EFF_Rocket_MkS,  EffectMgr::EFF_Rocket_Hiba, EffectMgr::EFF_Rocket_Biri,
		                               EffectMgr::EFF_Rocket_Biri, EffectMgr::EFF_Rocket_Biri, EffectMgr::EFF_Rocket_TakeS };
	_4C4[id]                       = effectMgr->create(ids[id], _47C[id], nullptr, nullptr);
	_4C4[id]->setEmitPosPtr(&_47C[id]);

	if (ids[id] == EffectMgr::EFF_Rocket_Biri) {
		playEventSound(this, SE_UFO_SPARK);
	}
}

/*
 * --INFO--
 * Address:	800E74C8
 * Size:	00024C
 */
void UfoItem::updateTroubleEffect()
{
	if (!_428) {
		return;
	}

	_42C += gsys->getFrameTime() * 30.0f;
	int test = _430 + 1;
	if (test < numKeys && _42C >= trKeys[test]) {
		_430 = test;
		switch (_430) {
		case 0:
			startTroubleEffectOne(2);
			break;
		case 1:
			startTroubleEffectOne(4);
			break;
		case 2:
			startTroubleEffectOne(3);
			break;
		}
	}

	if (_42C >= 80.0f) {
		_430 = -1;
		_42C = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	800E7714
 * Size:	00012C
 */
void UfoItem::startConeEffect(int)
{
	Vector3f goal = getGoalPos();
	Vector3f suck = getSuckPos();
	EffectParm eff(goal, suck);
	_52C = 0x18;
	utEffectMgr->cast(_52C, eff);
	mAnimator.startMotion(0, &PaniMotionInfo(1, this));
	mAnimator.setMotionSpeed(0, 30.0f);
	PRINT("*** UFO FUTA OPEN !!!!!!!!!!!!!!________________________________\n");
}

/*
 * --INFO--
 * Address:	800E7840
 * Size:	000024
 */
void UfoItem::finishConeEffect()
{
	utEffectMgr->kill(_52C);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void UfoItem::initLevelFlag(int flag)
{
	lightLevelFlag(flag);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E7864
 * Size:	000158
 */
void UfoItem::startLevelFlag(int flag)
{
	lightLevelFlag(flag);
	zen::particleGenerator* efx;
	Vector3f pos = mPosition;
	if (playerState->mShipUpgradeLevel == 5) {
		efx = effectMgr->create(EffectMgr::EFF_Rocket_Complete1, pos, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 1.0f));
		efx = effectMgr->create(EffectMgr::EFF_Rocket_Complete2, pos, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 1.0f));
	} else {
		pos.y += 60.0f;
		efx = effectMgr->create(EffectMgr::EFF_Rocket_NJ1CA, pos, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 1.0f));
	}
	mAnimator.startFlagMotions(flag);
}

/*
 * --INFO--
 * Address:	800E79BC
 * Size:	000078
 */
void UfoItem::lightLevelFlag(int flag)
{
	f32 rate = 0.0f;
	if (flag > 0) {
		rate = 30.0f;
	}

	for (int i = 0; i < 4; i++) {
		mLightAnims[i].start(flag);
		mLightAnims[i].mSpeed = rate;
	}

	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	800E7A34
 * Size:	000390
 */
void UfoItem::setJetEffect(int id, bool set)
{
	if (id > 0) {
		_4DC                 = id;
		volatile int vals[6] = { 1, 1, 2, 2, 3, 3 };
		int stage            = playerState->mShipUpgradeLevel - 2;
		PRINT("*** UFO LEVEL %d : JET LEVEL %d\n", playerState->mShipUpgradeLevel, vals[playerState->mShipUpgradeLevel]);
		u32 tags[4] = { 'eng1', 'eng2', 'eng3', 'eng4' };
		if (playerState->mShipUpgradeLevel <= 1) {
			stage = 4;
		}

		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				if (_4E0[j][i]) {
					effectMgr->kill(_4E0[j][i], false);
					_4E0[j][i] = nullptr;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				CollPart* coll = mCollInfo->getSphere(tags[i]);
				switch (i) {
				case 0:
					_4E0[0][j] = effectMgr->create(effects[stage + j], coll->mCentre, nullptr, nullptr);
					if (_4E0[0][j]) {
						_4E0[0][j]->setEmitPosPtr(&coll->mCentre);
					}
					break;
				case 1:
					_4E0[0][j] = effectMgr->create(effects[stage + j], coll->mCentre, nullptr, nullptr);
					if (_4E0[0][j]) {
						_4E0[0][j]->setEmitPosPtr(&coll->mCentre);
						_4E0[0][j]->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
					}
					break;
				case 2:
					if (set && playerState->mShipUpgradeLevel != 5) {
						_4E0[0][j] = effectMgr->create(effects[stage + j], coll->mCentre, nullptr, nullptr);
						if (_4E0[0][j]) {
							_4E0[0][j]->setEmitPosPtr(&coll->mCentre);
						}
					}
					break;
				case 3:
					if (set && playerState->mShipUpgradeLevel != 5) {
						_4E0[0][j] = effectMgr->create(effects[stage + j], coll->mCentre, nullptr, nullptr);
						if (_4E0[0][j]) {
							_4E0[0][j]->setEmitPosPtr(&coll->mCentre);
							_4E0[0][j]->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
						}
					}
					break;
				}
			}
		}

	} else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (_4E0[i][j]) {
					effectMgr->kill(_4E0[i][j], false);
					_4E0[i][j] = nullptr;
				}
			}
		}
		//_4DC = 0;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  lis       r6, 0x802C
	  stwu      r1, -0xA0(r1)
	  stmw      r21, 0x74(r1)
	  addi      r21, r3, 0
	  addi      r25, r5, 0
	  subi      r29, r6, 0x4020
	  ble-      .loc_0x320
	  extsh     r0, r4
	  lis       r3, 0x8022
	  sth       r0, 0x4DC(r21)
	  addi      r6, r3, 0x25BC
	  lwz       r5, 0x0(r6)
	  lis       r3, 0x8022
	  lwz       r0, 0x4(r6)
	  addi      r4, r3, 0x25D4
	  lwz       r3, 0x2F6C(r13)
	  stw       r5, 0x54(r1)
	  li        r23, 0
	  addi      r7, r3, 0x10
	  stw       r0, 0x58(r1)
	  lwz       r3, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r3, 0x5C(r1)
	  stw       r0, 0x60(r1)
	  lwz       r3, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r3, 0x64(r1)
	  stw       r0, 0x68(r1)
	  lbz       r5, 0x0(r7)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  subi      r24, r5, 0x2
	  stw       r3, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  lbz       r0, 0x0(r7)
	  cmplwi    r0, 0x1
	  bgt-      .loc_0xB8
	  li        r24, 0x4
	  li        r23, 0x1

	.loc_0xB8:
	  addi      r27, r21, 0
	  li        r28, 0
	  li        r22, 0

	.loc_0xC4:
	  li        r30, 0
	  addi      r26, r27, 0

	.loc_0xCC:
	  lwz       r4, 0x4E0(r26)
	  cmplwi    r4, 0
	  beq-      .loc_0xEC
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xB9AAC
	  stw       r22, 0x4E0(r26)

	.loc_0xEC:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x4
	  addi      r26, r26, 0x4
	  blt+      .loc_0xCC
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x4
	  addi      r27, r27, 0x10
	  blt+      .loc_0xC4
	  li        r22, 0
	  rlwinm    r31,r25,0,24,31

	.loc_0x114:
	  li        r25, 0
	  mullw     r27, r25, r23
	  rlwinm    r0,r25,2,0,29
	  addi      r28, r1, 0x44
	  addi      r26, r21, 0
	  add       r28, r28, r0

	.loc_0x12C:
	  lwz       r3, 0x220(r21)
	  lwz       r4, 0x0(r28)
	  bl        -0x5E458
	  cmpwi     r22, 0x2
	  addi      r30, r3, 0
	  beq-      .loc_0x218
	  bge-      .loc_0x158
	  cmpwi     r22, 0
	  beq-      .loc_0x164
	  bge-      .loc_0x1A4
	  b         .loc_0x2F8

	.loc_0x158:
	  cmpwi     r22, 0x4
	  bge-      .loc_0x2F8
	  b         .loc_0x270

	.loc_0x164:
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x24(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4F80
	  stw       r3, 0x4EC(r26)
	  lwz       r3, 0x4EC(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  b         .loc_0x2F8

	.loc_0x1A4:
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x28(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4F40
	  stw       r3, 0x4E8(r26)
	  lwz       r3, 0x4E8(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x3680(r13)
	  lfs       f1, -0x367C(r13)
	  stfs      f0, 0x38(r1)
	  lfs       f0, -0x3678(r13)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r4, 0x4E8(r26)
	  lwz       r3, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0x1E4(r4)
	  b         .loc_0x2F8

	.loc_0x218:
	  cmplwi    r31, 0
	  beq-      .loc_0x2F8
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x5
	  beq-      .loc_0x2F8
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x2C(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4EB4
	  stw       r3, 0x4E4(r26)
	  lwz       r3, 0x4E4(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  b         .loc_0x2F8

	.loc_0x270:
	  cmplwi    r31, 0
	  beq-      .loc_0x2F8
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x5
	  beq-      .loc_0x2F8
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x30(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4E5C
	  stw       r3, 0x4E0(r26)
	  lwz       r3, 0x4E0(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x3674(r13)
	  lfs       f1, -0x3670(r13)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, -0x366C(r13)
	  stfs      f1, 0x30(r1)
	  stfs      f0, 0x34(r1)
	  lwz       r4, 0x4E0(r26)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x1E4(r4)

	.loc_0x2F8:
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x4
	  add       r27, r27, r23
	  addi      r26, r26, 0x10
	  addi      r28, r28, 0x4
	  blt+      .loc_0x12C
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  blt+      .loc_0x114
	  b         .loc_0x37C

	.loc_0x320:
	  li        r25, 0
	  addi      r24, r21, 0
	  addi      r22, r25, 0

	.loc_0x32C:
	  li        r26, 0
	  addi      r23, r24, 0

	.loc_0x334:
	  lwz       r4, 0x4E0(r23)
	  cmplwi    r4, 0
	  beq-      .loc_0x354
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xB9844
	  stw       r22, 0x4E0(r23)

	.loc_0x354:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x4
	  addi      r23, r23, 0x4
	  blt+      .loc_0x334
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x4
	  addi      r24, r24, 0x10
	  blt+      .loc_0x32C
	  li        r0, 0
	  sth       r0, 0x4DC(r21)

	.loc_0x37C:
	  lmw       r21, 0x74(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E7DC4
 * Size:	00001C
 */
UfoItem::LightAnimator::LightAnimator()
{
	mDyn   = 0;
	mSpeed = 0.0f;
	mFrame = 0.0f;
	mType  = 0;
}

/*
 * --INFO--
 * Address:	800E7DE0
 * Size:	000058
 */
void UfoItem::LightAnimator::start(int id)
{
	mType = id;
	if (id > 0) {
		mFrame = (id - 1) * 20.0f;
	} else {
		mFrame = 19.0f;
	}
	mSpeed = 30.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void UfoItem::LightAnimator::update()
{
	if (mType) {
		f32 frame = 20.0f * (mType - 1);
		mFrame += mSpeed * gsys->getFrameTime();
		if (20.0f + frame - 1.0f >= mFrame) {
			Creature* ufo = itemMgr->getUfo();
			if (mType < 5) {
				ufo->playEventSound(ufo, SE_UFO_LIGHT);
			} else {
				ufo->playEventSound(ufo, SE_UFO_LIGHT2);
			}
			mFrame = frame;
		}
	}
	mDyn->animate(&mFrame);
}

/*
 * --INFO--
 * Address:	800E7E38
 * Size:	000064
 */
Vector3f UfoItem::getGoalPos()
{
	playerState->isUfoBroken();
	return mCollInfo->getSphere('gol1')->mCentre;
}

/*
 * --INFO--
 * Address:	800E7E9C
 * Size:	000044
 */
f32 UfoItem::getGoalPosRadius()
{
	playerState->isUfoBroken();
	return mCollInfo->getSphere('gol1')->mRadius;
}

/*
 * --INFO--
 * Address:	800E7EE0
 * Size:	000084
 */
Vector3f UfoItem::getSuckPos()
{
	u32 tag = 'suc0';
	if (!playerState->isUfoBroken()) {
		tag = 'suc1';
	}
	return mCollInfo->getSphere(tag)->mCentre;
}

/*
 * --INFO--
 * Address:	800E7F64
 * Size:	0000BC
 */
void UfoItem::suckMe(Pellet* pelt)
{
	PRINT("UFO ** SUCK PELLET\n");
	if (playerState->isUfoBroken()) {
		mAnimator.startMotion(0, &PaniMotionInfo(0, this));
	} else {
		mAnimator.startMotion(0, &PaniMotionInfo(1, this));
	}

	Navi* navi = naviMgr->getNavi();
	mAnimator.setMotionSpeed(0, 30.0f);
	playEventSound(this, SE_UFO_PARTSIN);
}

/*
 * --INFO--
 * Address:	800E8020
 * Size:	0000AC
 */
void UfoItem::startYozora()
{
	mAnimator.startMotion(0, &PaniMotionInfo(1));
	mAnimator.setMotionSpeed(0, 0.0f);

	u8 level    = playerState->mShipUpgradeLevel;
	int vals[6] = { 1, 1, 2, 2, 3, 3 };
	setJetEffect(vals[level], true);
	PRINT("** START YOZORA\n");
}

/*
 * --INFO--
 * Address:	800E80CC
 * Size:	0000AC
 */
void UfoItem::startGalaxy()
{
	mAnimator.startMotion(0, &PaniMotionInfo(1));
	mAnimator.setMotionSpeed(0, 0.0f);

	u8 level    = playerState->mShipUpgradeLevel;
	int vals[6] = { 1, 1, 2, 2, 3, 3 };
	setJetEffect(vals[level], false);
	PRINT("** START GALAXY\n");
}

/*
 * --INFO--
 * Address:	800E8178
 * Size:	000130
 */
void UfoItem::finishSuck(Pellet* pelt)
{
	if (!playerState->isTutorial()) {
		Vector3f pos                = getSuckPos();
		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Rocket_Suck1, pos, nullptr, nullptr);
		if (efx) {
			Vector3f dir(sinf(mDirection), 0.0f, cosf(mDirection));
			efx->setEmitDir(dir);
		}
	}
	_520                 = playerState->mShipUpgradeLevel;
	PelletConfig* config = pelt->mConfig;
	if (config->_130 != -1) {
		playerState->getUfoParts(config->_2C.mId, false);
	} else {
		playerState->getUfoParts(config->_2C.mId, true);
	}
	mAnimator.setMotionSpeed(0, 30.0f);
}

/*
 * --INFO--
 * Address:	800E82A8
 * Size:	000454
 */
void UfoItem::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	int anim = mAnimator.getMotionIndex(0);
	if (event.mEventType == 0) {
		PRINT("FINISHED --------- motion = %d\n");
	}
	switch (anim) {
	case 16:
		switch (event.mEventType) {
		case 1:
			mAnimator.setMotionSpeed(0, 0.0f);
			break;
		case 0:
			mAnimator.setMotionSpeed(0, 0.0f);
			break;
		}
		break;
	case 0:
	case 1:
		switch (event.mEventType) {
		case 1:
			mAnimator.setMotionSpeed(0, 0.0f);
			break;
		case 0:
			playerState->ufoAssignStart();
			mAnimator.setMotionSpeed(0, 0.0f);
			PRINT("*** SET UFO MOTION SPEED 000\n");
			break;
		case 8:
			switch (event.mValue) { // yes this is a switch in a switch in a switch
			case 0:
				if (anim == 0) {
					effectMgr->create(EffectMgr::EFF_Rocket_Nke2, mPosition, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Fkm1, mPosition, nullptr, nullptr);
				}
				break;
			case 2:
				if (anim == 0) {
					effectMgr->create(EffectMgr::EFF_CloudOfDust_1, mPosition, nullptr, nullptr);
				} else {
					effectMgr->create(EffectMgr::EFF_CloudOfDust_1, mPosition, nullptr, nullptr);
				}
				break;
			}
			break;
		}
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		if (event.mEventType == 8) {
			switch (event.mValue) {
			case 0:
				u8 level    = playerState->mShipUpgradeLevel;
				int vals[6] = { 1, 1, 2, 2, 3, 3 };
				setJetEffect(vals[level], false);
				break;
			case 2:
				if (playerState->is11(4)) {
					setPca2Effect(true);
				}
				break;
			case 3:
				if (playerState->is11(2)) {
					setPca1Effect(true);
				}
				break;
			case 1:
				switch (playerState->mShipUpgradeLevel) {
				case 0:
				case 1:
					effectMgr->create(EffectMgr::EFF_Rocket_JetG02, mPosition, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_331, mPosition, nullptr, nullptr);
					break;
				case 2:
				case 3:
					effectMgr->create(EffectMgr::EFF_Rocket_JetG03, mPosition, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_331, mPosition, nullptr, nullptr);
					break;
				case 4:
					effectMgr->create(EffectMgr::EFF_Rocket_Bst1da, mPosition, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_331, mPosition, nullptr, nullptr);
					break;
				case 5:
					effectMgr->create(EffectMgr::EFF_Rocket_MkB, mPosition, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Bstg, mPosition, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Bst1db, mPosition, nullptr, nullptr);
					break;
				}
				// no break here?
			case 9:
				if (playerState->mShipUpgradeLevel == 5) {
					CollPart* coll = mCollInfo->getSphere('gcen');
					zen::particleGenerator* efx;
					efx = effectMgr->create(EffectMgr::EFF_Rocket_PCA1, coll->mCentre, nullptr, nullptr);
					efx->setEmitPosPtr(&coll->mCentre);
					efx = effectMgr->create(EffectMgr::EFF_Rocket_Bst1fb, coll->mCentre, nullptr, nullptr);
					efx->setEmitPosPtr(&coll->mCentre);
					Vector3f nrm(0.0f, 0.0f, 1.0f);
					efx->setOrientedNormalVector(nrm);
					efx = effectMgr->create(EffectMgr::EFF_Rocket_Bst1fa, coll->mCentre, nullptr, nullptr);
					efx->setEmitPosPtr(&coll->mCentre);
				}
				break;
			}
		}
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x524
	  stw       r30, 0x40(r1)
	  addi      r30, r4, 0
	  li        r4, 0
	  bl        0x1A94
	  cmpwi     r3, 0xB
	  bge-      .loc_0x44
	  cmpwi     r3, 0x2
	  bge-      .loc_0x43C
	  cmpwi     r3, 0
	  bge-      .loc_0x98
	  b         .loc_0x43C

	.loc_0x44:
	  cmpwi     r3, 0x10
	  beq-      .loc_0x54
	  bge-      .loc_0x43C
	  b         .loc_0x18C

	.loc_0x54:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x70
	  bge-      .loc_0x43C
	  cmpwi     r0, 0
	  bge-      .loc_0x84
	  b         .loc_0x43C

	.loc_0x70:
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1A2C
	  b         .loc_0x43C

	.loc_0x84:
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1A18
	  b         .loc_0x43C

	.loc_0x98:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xC0
	  bge-      .loc_0xB4
	  cmpwi     r0, 0
	  bge-      .loc_0xD4
	  b         .loc_0x43C

	.loc_0xB4:
	  cmpwi     r0, 0x8
	  beq-      .loc_0xF0
	  b         .loc_0x43C

	.loc_0xC0:
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x19DC
	  b         .loc_0x43C

	.loc_0xD4:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x67390
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x19C0
	  b         .loc_0x43C

	.loc_0xF0:
	  lwz       r0, 0x4(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x14C
	  bge-      .loc_0x43C
	  cmpwi     r0, 0
	  beq-      .loc_0x110
	  b         .loc_0x43C
	  b         .loc_0x43C

	.loc_0x110:
	  cmpwi     r3, 0
	  bne-      .loc_0x43C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x149
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4764
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14A
	  li        r6, 0
	  li        r7, 0
	  bl        0xB474C
	  b         .loc_0x43C

	.loc_0x14C:
	  cmpwi     r3, 0
	  bne-      .loc_0x170
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x79
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4728
	  b         .loc_0x43C

	.loc_0x170:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x79
	  li        r6, 0
	  li        r7, 0
	  bl        0xB470C
	  b         .loc_0x43C

	.loc_0x18C:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x1A8
	  bge-      .loc_0x43C
	  cmpwi     r0, 0
	  beq-      .loc_0x43C
	  b         .loc_0x43C

	.loc_0x1A8:
	  lwz       r0, 0x4(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x258
	  bge-      .loc_0x1D0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x278
	  bge-      .loc_0x238
	  cmpwi     r0, 0
	  bge-      .loc_0x1DC
	  b         .loc_0x43C

	.loc_0x1D0:
	  cmpwi     r0, 0x9
	  beq-      .loc_0x390
	  b         .loc_0x43C

	.loc_0x1DC:
	  lwz       r4, 0x2F6C(r13)
	  lis       r3, 0x8022
	  addi      r8, r3, 0x2614
	  lbz       r0, 0x10(r4)
	  addi      r4, r1, 0x24
	  lwz       r5, 0x0(r8)
	  mr        r3, r31
	  lwz       r6, 0x4(r8)
	  rlwinm    r0,r0,2,0,29
	  stw       r5, 0x24(r1)
	  li        r5, 0
	  stw       r6, 0x28(r1)
	  lwz       r7, 0x8(r8)
	  lwz       r6, 0xC(r8)
	  stw       r7, 0x2C(r1)
	  stw       r6, 0x30(r1)
	  lwz       r7, 0x10(r8)
	  lwz       r6, 0x14(r8)
	  stw       r7, 0x34(r1)
	  stw       r6, 0x38(r1)
	  lwzx      r4, r4, r0
	  bl        -0xAA4
	  b         .loc_0x43C

	.loc_0x238:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x43C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0xB94
	  b         .loc_0x43C

	.loc_0x258:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x43C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0xA5C
	  b         .loc_0x43C

	.loc_0x278:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x314
	  bge-      .loc_0x2A0
	  cmpwi     r0, 0x2
	  bge-      .loc_0x2E0
	  cmpwi     r0, 0
	  bge-      .loc_0x2AC
	  b         .loc_0x390

	.loc_0x2A0:
	  cmpwi     r0, 0x6
	  bge-      .loc_0x390
	  b         .loc_0x348

	.loc_0x2AC:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x103
	  li        r6, 0
	  li        r7, 0
	  bl        0xB45D0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14B
	  li        r6, 0
	  li        r7, 0
	  bl        0xB45B8
	  b         .loc_0x390

	.loc_0x2E0:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x104
	  li        r6, 0
	  li        r7, 0
	  bl        0xB459C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14B
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4584
	  b         .loc_0x390

	.loc_0x314:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x105
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4568
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14B
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4550
	  b         .loc_0x390

	.loc_0x348:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x108
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4534
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x107
	  li        r6, 0
	  li        r7, 0
	  bl        0xB451C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x106
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4504

	.loc_0x390:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x5
	  bne-      .loc_0x43C
	  lis       r4, 0x6763
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x656E
	  bl        -0x5EF44
	  mr        r31, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x11C
	  li        r6, 0
	  li        r7, 0
	  bl        0xB44C8
	  addi      r31, r31, 0x4
	  stw       r31, 0x18(r3)
	  addi      r5, r31, 0
	  li        r4, 0x11B
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0xB44A8
	  stw       r31, 0x18(r3)
	  addi      r5, r31, 0
	  li        r4, 0x11A
	  lfs       f0, -0x3664(r13)
	  li        r6, 0
	  lfs       f1, -0x3660(r13)
	  li        r7, 0
	  stfs      f0, 0x18(r1)
	  lfs       f0, -0x365C(r13)
	  stfs      f1, 0x1C(r1)
	  stfs      f0, 0x20(r1)
	  lwz       r8, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r8, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x20(r1)
	  stw       r0, 0x1E4(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0xB445C
	  stw       r31, 0x18(r3)

	.loc_0x43C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E86FC
 * Size:	000008
 */
bool UfoItem::needShadow()
{
	return false;
}

/*
 * --INFO--
 * Address:	800E8704
 * Size:	0001F4
 */
UfoItem::UfoItem(CreatureProp* prop, UfoShapeObject* shape)
    : Suckable(30, prop)
{
	for (int i = 0; i < 6; i++) {
		_4C4[i] = nullptr;
	}
	mShipModel = shape;
	mScale.set(1.0f, 1.0f, 1.0f);
	mDynMat = nullptr;

	ShapeDynMaterials* mat = shape->mShape->instanceMaterials(15);
	mLightAnims[0].mDyn    = mat;
	mat->_00               = (int)mDynMat;
	mDynMat                = mat;

	mat                 = shape->mShape->instanceMaterials(52);
	mLightAnims[1].mDyn = mat;
	mat->_00            = (int)mDynMat;
	mDynMat             = mat;

	mat                 = shape->mShape->instanceMaterials(51);
	mLightAnims[2].mDyn = mat;
	mat->_00            = (int)mDynMat;
	mDynMat             = mat;

	mat                 = shape->mShape->instanceMaterials(40);
	mLightAnims[3].mDyn = mat;
	mat->_00            = (int)mDynMat;
	mDynMat             = mat;
}

/*
 * --INFO--
 * Address:	800E88F8
 * Size:	000014
 */
UfoItem::Spot::Spot()
{
}

/*
 * --INFO--
 * Address:	800E890C
 * Size:	000008
 */
bool UfoItem::ignoreAtari(Creature*)
{
	return false;
}

/*
 * --INFO--
 * Address:	800E8914
 * Size:	0000C0
 */
void UfoItem::startTakeoff()
{
	int id     = playerState->mShipUpgradeLevel - 1;
	int ids[5] = { 11, 11, 12, 13, 13 };
	if (id < 0) {
		id = 0;
	}
	mAnimator.startMotion(0, &PaniMotionInfo(ids[id], this));
	mAnimator.setMotionSpeed(0, 30.0f);
	UtEffectMgr::kill(_52C);
	playerState->startSpecialMotions();
}

/*
 * --INFO--
 * Address:	800E89D4
 * Size:	0002BC
 */
void UfoItem::startAI(int)
{
	_3CA = 0;
	_3C8 = 0;
	if (playerState->isTutorial()) {
		setTroubleEffect(true);
	} else {
		setTroubleEffect(false);
		effectMgr->create(EffectMgr::EFF_Rocket_Land, mPosition, nullptr, nullptr);
	}
	_52C = 21;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_4E0[i][j] = nullptr;
		}
	}

	setJetEffect(0, false);
	setPca1Effect(false);
	setPca2Effect(false);
	_5CC       = 1;
	mSeContext = &mShipSe;
	mSeContext->setContext(this, 7);
	mCollInfo = new CollInfo(16);
	mCollInfo->initInfo(mShipModel->mShape, nullptr, nullptr);
	mWaypointID = routeMgr->findNearestWayPoint('test', mPosition, false)->mIndex;
	setMotionSpeed(30.0f);
	_54C   = mPosition;
	_54C.y = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	mAnimator.init(mShipModel, itemMgr->mUfoMotionTable);

	if (playerState->isUfoBroken()) {
		mAnimator.startMotion(0, &PaniMotionInfo(0));
		playEventSound(this, SE_UFO_DESTROY);
	} else {
		mAnimator.startMotion(0, &PaniMotionInfo(1));
		playEventSound(this, SE_UFO_IDLING);
	}
	mAnimator.stopAllMotions();
	u8 level = playerState->mShipUpgradeLevel;
	lightLevelFlag(playerState->mShipUpgradeLevel);
	PRINT("** start AI (%.1f %.1f %.1f) : routeIndex = %d\n");
	mAnimator.initFlagMotions(level);

	if (!playerState->isTutorial()) {
		setSpotActive(true);
		for (int i = 0; i < 3; i++) {
			mSpots[i]._10 = i * 2.0943952f;
			mSpots[i]._0C = 9.0f;
			mSpots[i]._14 = 0.0f;
		}
	} else {
		setSpotActive(false);
	}
}

/*
 * --INFO--
 * Address:	800E8C90
 * Size:	000008
 */
f32 UfoItem::getSize()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800E8C98
 * Size:	000008
 */
f32 UfoItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800E8CA0
 * Size:	0000B0
 */
bool UfoItem::accessible()
{
	int anim = mAnimator.getMotionIndex(0);

	if (gameflow.mWorldClock.mTotalTime > gameflow.mParameters->mEndHour() - 0.2f) {
		PRINT("tod = %f : endhour = %f\n", gameflow.mWorldClock.mTotalTime, gameflow.mParameters->mEndHour());
		return false;
	}

	if (!playerState->isTutorial() && (anim == 1 || anim == 16) && mAnimator.getSpeed(0) <= 0.0f) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800E8D50
 * Size:	000170
 */
void UfoItem::startAccess()
{
	_3C8 = 1;
	startConeEffect(false);

	mAnimator.startMotion(0, &PaniMotionInfo(16, this));
	mAnimator.setMotionSpeed(0, 30.0f);
}

/*
 * --INFO--
 * Address:	800E8EC0
 * Size:	000048
 */
void UfoItem::finishAccess()
{
	_3C8 = 0;
	UtEffectMgr::kill(_52C);
	mAnimator.setMotionSpeed(0, 30.0f);
}

/*
 * --INFO--
 * Address:	800E8F08
 * Size:	00006C
 */
void UfoItem::update()
{
	updateTroubleEffect();
	mVelocity.set(0.0f, 0.0f, 0.0f);
	ItemCreature::update();
	mAnimator.updateAnimation();
	mPosition = _54C;
}

/*
 * --INFO--
 * Address:	800E8F74
 * Size:	000118
 */
void UfoItem::setPca1Effect(bool set)
{
	_548 = set;
	if (set) {
		Vector3f dir(1.0f, 0.0f, 0.0f);
		dir.rotate(mTransformMatrix);

		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Rocket_PCA2, _530, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);

		efx = effectMgr->create(EffectMgr::EFF_Rocket_Gep, _530, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);
	}
}

/*
 * --INFO--
 * Address:	800E908C
 * Size:	000118
 */
void UfoItem::setPca2Effect(bool set)
{
	_548 = set;
	if (set) {
		Vector3f dir(1.0f, 0.0f, 0.0f);
		dir.rotate(mTransformMatrix);

		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Rocket_PCA2, _53C, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);

		efx = effectMgr->create(EffectMgr::EFF_Rocket_Gep, _53C, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);
	}
}

/*
 * --INFO--
 * Address:	800E91A4
 * Size:	0000E4
 */
void UfoItem::refresh(Graphics& gfx)
{
	Matrix4f mtx;
	Vector3f pos = mPosition;
	mTransformMatrix.makeSRT(mScale, mRotation, pos);

	if (!gfx.mCamera->isPointVisible(mPosition, 200.0f)) {
		enableAICulling();
	} else {
		disableAICulling();
	}
	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, mtx);
	gfx.useMatrix(Matrix4f::ident, 0);
	demoDraw(gfx, &mtx);
}

/*
 * --INFO--
 * Address:	800E9288
 * Size:	000504
 */
void UfoItem::demoDraw(Graphics& gfx, Matrix4f* mtx)
{
	for (int i = 0; i < 4; i++) {
		mLightAnims[i].update();
	}

	mAnimator.updateContext();
	mShipModel->mShape->updateAnim(gfx, *mtx, nullptr);

	if (gameflow.mMoviePlayer->mIsActive || doAlwaysUpdate()) {
		mShipModel->mShape->drawshape(gfx, *gfx.mCamera, mDynMat);
		playerState->renderParts(gfx, mShipModel->mShape);
	}

	Vector3f pos;

	pos.set(0.0f, 14.0f, 0.0f);
	mShipModel->mShape->calcJointWorldPos(gfx, 48, pos);
	_53C = pos;

	pos.set(0.0f, 14.0f, 0.0f);
	mShipModel->mShape->calcJointWorldPos(gfx, 49, pos);
	_530 = pos;

	if (playerState->isTutorial()) {

		pos.set(13.1f, -98.4f, -2.0f);
		mShipModel->mShape->calcJointWorldPos(gfx, 2, pos);
		_47C[0] = pos;

		pos.set(-9.1999998f, -68.099998f, 28.6f);
		mShipModel->mShape->calcJointWorldPos(gfx, 2, pos);
		_47C[1] = pos;

		_47C[2] = _47C[0];
		_47C[3] = _47C[1];

		pos.set(-22.2f, 4.9f, -25.0f);
		mShipModel->mShape->calcJointWorldPos(gfx, 41, pos);
		_47C[4] = pos;

		pos.set(0.0f, -93.0f, 0.0f);
		mShipModel->mShape->calcJointWorldPos(gfx, 2, pos);
		_47C[5] = pos;
	}

	mCollInfo->updateInfo(gfx, false);
	for (int i = 0; i < 3; i++) {
		CollPart* part = mCollInfo->getSphere('gol1');
		if (part) {
			f32 test = mDirection + mSpots[i]._10;
			if (_3CA) {
				mSpots[i]._14 += gsys->getFrameTime() * 37.69911193847656f;
				if (mSpots[i]._14 > TAU) {
					mSpots[i]._14 = 0.0f;
				}
				test += mSpots[i]._14;
			}
			Vector3f dir(mSpots[i]._0C * sinf(test), 0.0f, mSpots[i]._0C * cosf(test));
			mSpots[i]._00 = part->mCentre + dir;
		}
	}

	if (_5CC) {
		mWaypointID   = routeMgr->findNearestWayPoint('test', getGoalPos(), false)->mIndex;
		Vector3f goal = getGoalPos();
		PRINT("*** UFO ROUTE INDEX = %d (%.1f %.1f %.1f)\n", mWaypointID, goal.x, goal.y, goal.z);
		_5CC = 0;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stfd      f28, 0xC8(r1)
	  stfd      f27, 0xC0(r1)
	  stmw      r26, 0xA8(r1)
	  mr        r30, r3
	  mr        r31, r4
	  addi      r26, r5, 0
	  addi      r28, r30, 0
	  li        r27, 0
	  lis       r29, 0x4330
	  lfs       f31, -0x6624(r2)
	  lfd       f30, -0x6618(r2)
	  lfs       f29, -0x662C(r2)

	.loc_0x48:
	  lhz       r3, 0x598(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xD8
	  subi      r0, r3, 0x1
	  lwz       r3, 0x2DEC(r13)
	  xoris     r0, r0, 0x8000
	  lfs       f1, 0x594(r28)
	  stw       r0, 0xA4(r1)
	  lfs       f0, 0x28C(r3)
	  stw       r29, 0xA0(r1)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x590(r28)
	  lfd       f2, 0xA0(r1)
	  fsubs     f2, f2, f30
	  fadds     f0, f1, f0
	  fmuls     f28, f31, f2
	  stfs      f0, 0x590(r28)
	  fadds     f0, f31, f28
	  lfs       f1, 0x590(r28)
	  fsubs     f0, f0, f29
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD8
	  lwz       r3, 0x30AC(r13)
	  bl        0x9908
	  lhz       r0, 0x598(r28)
	  cmplwi    r0, 0x5
	  bge-      .loc_0xC8
	  addi      r4, r3, 0
	  li        r5, 0xE2
	  bl        -0x5ED94
	  b         .loc_0xD4

	.loc_0xC8:
	  addi      r4, r3, 0
	  li        r5, 0xE5
	  bl        -0x5EDA4

	.loc_0xD4:
	  stfs      f28, 0x590(r28)

	.loc_0xD8:
	  lwz       r3, 0x58C(r28)
	  addi      r4, r28, 0x590
	  bl        -0xBA2CC
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r28, r28, 0x10
	  blt+      .loc_0x48
	  addi      r3, r30, 0x524
	  bl        0xDA8
	  lwz       r3, 0x55C(r30)
	  addi      r4, r31, 0
	  addi      r5, r26, 0
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0xB4084
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x138
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x164

	.loc_0x138:
	  lwz       r3, 0x55C(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  lwz       r3, 0x0(r3)
	  lwz       r6, 0x588(r30)
	  bl        -0xB8F68
	  lwz       r5, 0x55C(r30)
	  mr        r4, r31
	  lwz       r3, 0x2F6C(r13)
	  lwz       r5, 0x0(r5)
	  bl        -0x67AD4

	.loc_0x164:
	  lfs       f0, -0x6638(r2)
	  mr        r4, r31
	  addi      r6, r1, 0x94
	  stfs      f0, 0x9C(r1)
	  li        r5, 0x30
	  stfs      f0, 0x98(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f1, -0x35F8(r13)
	  lfs       f0, -0x35F4(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35F0(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3B64
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x31
	  stw       r3, 0x53C(r30)
	  stw       r0, 0x540(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x544(r30)
	  lfs       f1, -0x35EC(r13)
	  lfs       f0, -0x35E8(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35E4(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3BAC
	  lwz       r3, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0x530(r30)
	  stw       r0, 0x534(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x538(r30)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x6901C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x364
	  lfs       f1, -0x35E0(r13)
	  mr        r4, r31
	  lfs       f0, -0x35DC(r13)
	  addi      r6, r1, 0x94
	  stfs      f1, 0x94(r1)
	  li        r5, 0x2
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35D8(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3C04
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x2
	  stw       r3, 0x47C(r30)
	  stw       r0, 0x480(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x484(r30)
	  lfs       f1, -0x35D4(r13)
	  lfs       f0, -0x35D0(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35CC(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3C4C
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x29
	  stw       r3, 0x488(r30)
	  stw       r0, 0x48C(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x490(r30)
	  lwz       r3, 0x47C(r30)
	  lwz       r0, 0x480(r30)
	  stw       r3, 0x494(r30)
	  stw       r0, 0x498(r30)
	  lwz       r0, 0x484(r30)
	  stw       r0, 0x49C(r30)
	  lwz       r3, 0x488(r30)
	  lwz       r0, 0x48C(r30)
	  stw       r3, 0x4A0(r30)
	  stw       r0, 0x4A4(r30)
	  lwz       r0, 0x490(r30)
	  stw       r0, 0x4A8(r30)
	  lfs       f1, -0x35C8(r13)
	  lfs       f0, -0x35C4(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35C0(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3CC4
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x2
	  stw       r3, 0x4AC(r30)
	  stw       r0, 0x4B0(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x4B4(r30)
	  lfs       f1, -0x35BC(r13)
	  lfs       f0, -0x35B8(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35B4(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3D0C
	  lwz       r3, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0x4B8(r30)
	  stw       r0, 0x4BC(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x4C0(r30)

	.loc_0x364:
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x5FB0C
	  lfs       f29, -0x65F8(r2)
	  mr        r28, r30
	  lfs       f30, -0x65F4(r2)
	  li        r27, 0
	  lfs       f31, -0x6638(r2)
	  lis       r29, 0x676F

	.loc_0x38C:
	  lwz       r3, 0x220(r30)
	  addi      r4, r29, 0x6C31
	  bl        -0x5FF0C
	  mr.       r31, r3
	  beq-      .loc_0x450
	  lbz       r0, 0x3CA(r30)
	  lfs       f1, 0xA0(r30)
	  lfs       f0, 0x3E4(r28)
	  cmplwi    r0, 0
	  fadds     f27, f1, f0
	  beq-      .loc_0x3E8
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x3E8(r28)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f29, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x3E8(r28)
	  lfs       f0, 0x3E8(r28)
	  fcmpo     cr0, f0, f30
	  ble-      .loc_0x3E0
	  stfs      f31, 0x3E8(r28)

	.loc_0x3E0:
	  lfs       f0, 0x3E8(r28)
	  fadds     f27, f27, f0

	.loc_0x3E8:
	  fmr       f1, f27
	  bl        0x1324E0
	  lfs       f0, 0x3E0(r28)
	  fmuls     f28, f0, f1
	  fmr       f1, f27
	  bl        0x132664
	  lfs       f0, 0x3E0(r28)
	  lfs       f2, 0x4(r31)
	  fmuls     f1, f0, f1
	  lfs       f0, -0x35B0(r13)
	  fadds     f1, f2, f1
	  stfs      f1, 0x44(r1)
	  lfs       f1, 0x44(r1)
	  stfs      f1, 0x6C(r1)
	  lfs       f1, 0x8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0xC(r31)
	  fadds     f0, f0, f28
	  stfs      f0, 0x74(r1)
	  lwz       r3, 0x6C(r1)
	  lwz       r0, 0x70(r1)
	  stw       r3, 0x3D4(r28)
	  stw       r0, 0x3D8(r28)
	  lwz       r0, 0x74(r1)
	  stw       r0, 0x3DC(r28)

	.loc_0x450:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x3
	  addi      r28, r28, 0x1C
	  blt+      .loc_0x38C
	  lbz       r0, 0x5CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x4DC
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x60
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  addi      r5, r1, 0x60
	  li        r6, 0
	  bl        -0x48638
	  lwz       r0, 0x10(r3)
	  addi      r4, r30, 0
	  addi      r3, r1, 0x54
	  stw       r0, 0x558(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x54(r1)
	  li        r0, 0
	  lfs       f1, 0x58(r1)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x5C(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x80(r1)
	  stb       r0, 0x5CC(r30)

	.loc_0x4DC:
	  lmw       r26, 0xA8(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  lfd       f27, 0xC0(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E978C
 * Size:	000008
 */
s16 UfoItem::getRouteIndex()
{
	return mWaypointID;
	/*
	.loc_0x0:
	  lwz       r3, 0x558(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E9794
 * Size:	000008
 */
bool UfoItem::isVisible()
{
	return true;
}

/*
 * --INFO--
 * Address:	800E979C
 * Size:	000008
 */
bool UfoItem::isAlive()
{
	return true;
}
