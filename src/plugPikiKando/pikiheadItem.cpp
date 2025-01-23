#include "PikiHeadItem.h"
#include "DebugLog.h"
#include "KEffect.h"
#include "SoundMgr.h"
#include "GameStat.h"
#include "MapMgr.h"
#include "PikiMgr.h"
#include "NaviMgr.h"
#include "PikiState.h"
#include "Interactions.h"

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
DEFINE_PRINT("pikiheadItem")

/*
 * --INFO--
 * Address:	800EC4C8
 * Size:	000060
 */
void PikiHeadItem::startWaterEffect()
{
	EffectParm parm(&mPosition);
	mRippleEfx->emit(parm);
}

/*
 * --INFO--
 * Address:	800EC528
 * Size:	000030
 */
void PikiHeadItem::finishWaterEffect()
{
	mRippleEfx->kill();
}

/*
 * --INFO--
 * Address:	800EC558
 * Size:	000074
 */
void PikiHeadItem::playSound(int id)
{
	if (_3E0) {
		playEventSound(_3E0, id + 0xcc);
		return;
	}

	if (id > 0) {
		int sound = id + 0x108;
		seSystem->playPikiSound(sound, mPosition);
		PRINT("SEF_PIKI_GROW1 = %d / seIdx = %d\n", SEF_PIKI_GROW1, sound);
		seSystem->getJacID(sound);
		PRINT("play (idx=%d) Pikihead sound jac =%d/simz(dmg=%d grow1=%d)\n", id, sound, SE_PIKI_DAMAGED, 0x23);
	}
}

/*
 * --INFO--
 * Address:	800EC5CC
 * Size:	000058
 */
bool PikiHeadItem::canPullout()
{
	AState<AICreature>* state = getCurrState();
	u32 id                    = state ? state->getID() : -1;
	if (id - 6 <= 2) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800EC624
 * Size:	000008
 */
bool PikiHeadItem::isVisible()
{
	return true;
}

/*
 * --INFO--
 * Address:	800EC62C
 * Size:	000068
 */
bool PikiHeadItem::needShadow()
{
	AState<AICreature>* state = getCurrState();
	int id                    = state ? state->getID() : -1;
	if (id == 3 || id == 14 || (u32)(id - 11) <= 1) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	800EC694
 * Size:	000008
 */
bool PikiHeadItem::isAlive()
{
	return true;
}

/*
 * --INFO--
 * Address:	800EC69C
 * Size:	00018C
 */
PikiHeadItem::PikiHeadItem(CreatureProp* props, ItemShapeObject* shape, SimpleAI* ai)
    : ItemCreature(15, props, nullptr)
{
	mItemShapeObject = shape;
	mStateMachine    = ai;
	mSeedColor       = 0;
	mFlowerStage     = 0;
	_3E0             = nullptr;
	mFreeLightEfx    = new FreeLightEffect;
	mRippleEfx       = new RippleEffect;
}

/*
 * --INFO--
 * Address:	800EC828
 * Size:	000150
 */
void PikiHeadItem::startAI(int)
{
	enableFixPos();
	_3E0 = nullptr;
	mItemAnimator.startMotion(PaniMotionInfo(0));

	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);

	enableAirResist(10.0f - gsys->getRand(1.0f) * 0.5f);

	static_cast<SimpleAI*>(mStateMachine)->start(this, 6);

	if (mSeedColor < 0 || mSeedColor > 2) {
		ERROR("set pikihead color before startAI\n");
	}

	GameStat::mePikis.inc(mSeedColor);
	GameStat::update();
	_3D4                  = mPosition;
	mFreeLightEfx->mColor = mSeedColor;
	EffectParm parm(&_3D4);
	mFreeLightEfx->emit(parm);

	f32 test; // this nearly fixes the stack

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r3
	  lwz       r4, 0xC8(r3)
	  addi      r3, r1, 0x1C
	  oris      r4, r4, 0x4
	  stw       r4, 0xC8(r31)
	  li        r4, 0
	  stw       r0, 0x3E0(r31)
	  bl        0x32700
	  addi      r4, r3, 0
	  addi      r3, r31, 0x36C
	  bl        0x3295C
	  lfs       f0, -0x6564(r2)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  bl        0x12B7F8
	  xoris     r3, r3, 0x8000
	  lwz       r0, 0xC8(r31)
	  stw       r3, 0x5C(r1)
	  lis       r3, 0x4330
	  lfd       f3, -0x6550(r2)
	  ori       r0, r0, 0x10
	  stw       r3, 0x58(r1)
	  lfs       f0, -0x6560(r2)
	  mr        r4, r31
	  lfd       f1, 0x58(r1)
	  li        r5, 0x6
	  lfs       f2, -0x6564(r2)
	  fsubs     f1, f1, f3
	  stw       r0, 0xC8(r31)
	  fdivs     f3, f1, f0
	  lfs       f0, -0x6558(r2)
	  lfs       f1, -0x655C(r2)
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0xCC(r31)
	  lwz       r3, 0x2E8(r31)
	  bl        -0x6F17C
	  lwz       r4, 0x3CC(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E94
	  rlwinm    r3,r4,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x25C68
	  lwz       r5, 0x94(r31)
	  addi      r0, r31, 0x3D4
	  lwz       r3, 0x98(r31)
	  addi      r4, r1, 0x24
	  stw       r5, 0x3D4(r31)
	  stw       r3, 0x3D8(r31)
	  lwz       r3, 0x9C(r31)
	  stw       r3, 0x3DC(r31)
	  lwz       r5, 0x3CC(r31)
	  lwz       r3, 0x3C8(r31)
	  sth       r5, 0xC(r3)
	  lfs       f1, -0x6568(r2)
	  lfs       f0, -0x6564(r2)
	  stfs      f1, 0x2C(r1)
	  stfs      f1, 0x28(r1)
	  stfs      f1, 0x24(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f1, 0x30(r1)
	  stw       r0, 0x44(r1)
	  stfs      f0, 0x48(r1)
	  lwz       r3, 0x3C8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EC978
 * Size:	00008C
 */
void PikiHeadItem::setPermanentEffects(bool set)
{
	if (set) {
		mFreeLightEfx->mColor = mSeedColor;
		EffectParm parm(&_3D4);
		mFreeLightEfx->emit(parm);
	} else {
		mFreeLightEfx->kill();
	}
}

/*
 * --INFO--
 * Address:	800ECA04
 * Size:	00008C
 */
void PikiHeadItem::doKill()
{
	ItemCreature::doKill();
	GameStat::mePikis.dec(mSeedColor);
	GameStat::workPikis.inc(mSeedColor);
	GameStat::update();
	mFreeLightEfx->kill();
	_3E4.kill();
}

/*
 * --INFO--
 * Address:	800ECA90
 * Size:	000008
 */
f32 PikiHeadItem::getSize()
{
	return 5.0f;
}

/*
 * --INFO--
 * Address:	800ECA98
 * Size:	000008
 */
f32 PikiHeadItem::getiMass()
{
	return 50.0f;
}

/*
 * --INFO--
 * Address:	800ECAA0
 * Size:	000008
 */
void PikiHeadItem::setColor(int color)
{
	mSeedColor = color;
}

/*
 * --INFO--
 * Address:	800ECAA8
 * Size:	00054C
 */
void PikiHeadItem::refresh(Graphics& gfx)
{
	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	mapMgr->getLight(mPosition.x, mPosition.z); // this returns something
	if (!mItemShapeObject) {
		return; // this is probably a goto
	}

	Matrix4f mtx;
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	int color     = mSeedColor;
	Material* mat = mItemShapeObject->mShape->mMaterialList;
	// mat.setColor();

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xD0(r1)
	  addi      r30, r3, 0
	  lfs       f0, -0x6564(r2)
	  stfs      f0, 0x7C(r3)
	  stfs      f0, 0x80(r3)
	  stfs      f0, 0x84(r3)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  bl        -0x84D48
	  lwz       r0, 0x3C0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x430
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xAEA0C
	  lwz       r3, 0x3C0(r30)
	  lis       r4, 0x803D
	  lwz       r5, 0x3CC(r30)
	  addi      r0, r4, 0x1E18
	  lwz       r3, 0x0(r3)
	  rlwinm    r4,r5,2,0,29
	  lwz       r5, 0x44(r3)
	  add       r4, r0, r4
	  lwz       r0, 0x4C(r5)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0xBC
	  lbz       r0, 0x0(r4)
	  lwz       r3, 0x90(r5)
	  sth       r0, 0x0(r3)
	  lbz       r0, 0x1(r4)
	  lwz       r3, 0x90(r5)
	  sth       r0, 0x2(r3)
	  lbz       r0, 0x2(r4)
	  lwz       r3, 0x90(r5)
	  sth       r0, 0x4(r3)
	  lbz       r0, 0x3(r4)
	  lwz       r3, 0x90(r5)
	  sth       r0, 0x6(r3)
	  b         .loc_0xC4

	.loc_0xBC:
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x2C(r5)

	.loc_0xC4:
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x3B8
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x74(r30)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x78(r30)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x6568(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x154
	  fsqrte    f1, f4
	  lfd       f3, -0x6540(r2)
	  lfd       f2, -0x6538(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x28(r1)
	  lfs       f4, 0x28(r1)

	.loc_0x154:
	  lfs       f0, -0x6568(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3B8
	  lfs       f0, 0x70(r30)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x74(r30)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x78(r30)
	  stfs      f0, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x80(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xDF000
	  lfs       f0, -0x6568(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1CC
	  lfs       f0, 0x78(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x80(r1)

	.loc_0x1CC:
	  lfs       f4, -0x3400(r13)
	  lfs       f0, 0x78(r1)
	  lfs       f1, 0x7C(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x80(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x78(r1)
	  stfs      f3, 0x7C(r1)
	  stfs      f1, 0x80(r1)
	  lfs       f1, -0x33FC(r13)
	  lfs       f0, -0x33F8(r13)
	  stfs      f1, 0x6C(r1)
	  stfs      f0, 0x70(r1)
	  lfs       f0, -0x33F4(r13)
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x68(r1)
	  lfs       f6, 0x70(r1)
	  lfs       f5, 0x6C(r1)
	  lfs       f7, 0x64(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x74(r1)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x60(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x60(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x64(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x60(r1)
	  lfs       f0, 0x64(r1)
	  lfs       f2, 0x68(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xDF0F4
	  lfs       f0, -0x6568(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2C0
	  lfs       f0, 0x60(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x64(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x68(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x68(r1)

	.loc_0x2C0:
	  lwz       r0, 0x60(r1)
	  lwz       r3, 0x64(r1)
	  stw       r0, 0x6C(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0x70(r1)
	  lfs       f5, 0x78(r1)
	  stw       r0, 0x74(r1)
	  lfs       f0, 0x74(r1)
	  lfs       f6, 0x7C(r1)
	  lfs       f7, 0x70(r1)
	  fmuls     f4, f0, f5
	  lfs       f3, 0x80(r1)
	  fmuls     f0, f0, f6
	  lfs       f2, 0x6C(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x6C(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x70(r1)
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  lfs       f2, 0x74(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xDF1A8
	  lfs       f0, -0x6568(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x374
	  lfs       f0, 0x6C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x74(r1)

	.loc_0x374:
	  addi      r3, r1, 0x60
	  addi      r4, r1, 0x78
	  addi      r5, r1, 0x6C
	  addi      r6, r30, 0x114
	  bl        0x258F4
	  lfs       f0, 0x94(r30)
	  addi      r4, r30, 0x114
	  addi      r5, r1, 0x84
	  stfs      f0, 0x120(r30)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x130(r30)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x140(r30)
	  lwz       r3, 0x2E4(r31)
	  addi      r3, r3, 0x1E0
	  bl        -0xAED84
	  b         .loc_0x3CC

	.loc_0x3B8:
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x84
	  addi      r3, r3, 0x1E0
	  bl        -0xAED9C

	.loc_0x3CC:
	  addi      r3, r30, 0x36C
	  lwz       r12, 0x39C(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3C0(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x84
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0xB7B88
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3C0(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  bl        -0xBCA68

	.loc_0x430:
	  lwz       r3, 0x3C0(r30)
	  li        r4, 0x3
	  lwz       r3, 0x0(r3)
	  bl        -0xB7EFC
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6568(r2)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  lwz       r0, 0x3D0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x494
	  lfs       f1, -0x33F0(r13)
	  lfs       f0, -0x33EC(r13)
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f0, -0x33E8(r13)
	  stfs      f0, 0x5C(r1)
	  b         .loc_0x4D0

	.loc_0x494:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x4B8
	  lfs       f1, -0x33E4(r13)
	  lfs       f0, -0x33E0(r13)
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f0, -0x33DC(r13)
	  stfs      f0, 0x5C(r1)
	  b         .loc_0x4D0

	.loc_0x4B8:
	  lfs       f1, -0x33D8(r13)
	  lfs       f0, -0x33D4(r13)
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f0, -0x33D0(r13)
	  stfs      f0, 0x5C(r1)

	.loc_0x4D0:
	  lwz       r3, 0x3C0(r30)
	  addi      r4, r31, 0
	  addi      r6, r1, 0x54
	  lwz       r3, 0x0(r3)
	  li        r5, 0x3
	  bl        -0xB76C8
	  lfs       f0, -0x6530(r2)
	  lwz       r3, 0x3C8(r30)
	  fmuls     f1, f0, f1
	  bl        0x2767C
	  lwz       r3, 0x54(r1)
	  mr        r4, r31
	  lwz       r0, 0x58(r1)
	  li        r6, 0
	  stw       r3, 0x3D4(r30)
	  stw       r0, 0x3D8(r30)
	  lwz       r0, 0x5C(r1)
	  stw       r0, 0x3DC(r30)
	  lwz       r0, 0x3D0(r30)
	  lwz       r3, 0x3068(r13)
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x2E4(r31)
	  add       r3, r3, r0
	  lwz       r3, 0x3C(r3)
	  bl        -0xBCB6C
	  lwz       r0, 0xDC(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ECFF4
 * Size:	000108
 */
bool PikiHeadItem::interactBikkuri(InteractBikkuri& act)
{
	PikiMgr::meBirthMode = true;
	Piki* piki           = (Piki*)pikiMgr->birth();
	PikiMgr::meBirthMode = false;

	if (piki) {
		Navi* navi = naviMgr->getNavi();
		piki->init(navi);
		piki->initColor(mSeedColor);
		piki->setFlower(mFlowerStage);
		piki->resetPosition(mPosition);

		PikiMgr::meNukiMode = true;
		piki->changeMode(0, nullptr);
		PikiMgr::meNukiMode = false;
		piki->mFSM->transit(piki, 5);

		kill(false);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800ED0FC
 * Size:	000100
 */
bool PikiHeadItem::interactSwallow(InteractSwallow& act)
{
	PikiMgr::meBirthMode = true;
	Piki* piki           = (Piki*)pikiMgr->birth();
	PikiMgr::meBirthMode = false;

	if (piki) {
		Navi* navi = naviMgr->getNavi();
		piki->init(navi);
		piki->initColor(mSeedColor);
		piki->setFlower(mFlowerStage);
		piki->resetPosition(mPosition);
		piki->mFSM->transit(piki, 5);
		kill(false);

		return act.actPiki(piki);
	}
	return false;
}

/*
 * --INFO--
 * Address:	800ED1FC
 * Size:	000008
 */
bool PikiHeadItem::isAtari()
{
	return false;
}
