#include "UtEffect.h"
#include "Creature.h"
#include "EffectMgr.h"
#include "NaviMgr.h"
#include "DebugLog.h"

KEffect** UtEffectMgr::effects;

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
DEFINE_PRINT("utEffect")

/*
 * --INFO--
 * Address:	80113164
 * Size:	000068
 */
SlimeEffect::SlimeEffect()
{
	mEfxGen = nullptr;
}

/*
 * --INFO--
 * Address:	801131CC
 * Size:	00001C
 */
void SlimeEffect::stop()
{
	if (mEfxGen)
		mEfxGen->pmSwitchOff(0x10);
}

/*
 * --INFO--
 * Address:	801131E8
 * Size:	00001C
 */
void SlimeEffect::restart()
{
	if (mEfxGen)
		mEfxGen->pmSwitchOn(0x10);
}

/*
 * --INFO--
 * Address:	80113204
 * Size:	000090
 */
void SlimeEffect::emit(EffectParm& parm)
{
	mObj         = parm._28;
	Vector3f pos = mObj->mPosition;
	if (!mEfxGen) {
		mEfxGen = effectMgr->create(EffectMgr::EFF_Piki_Bubble, pos, this, this);
		mEfxGen->setEmitPosPtr(&mObj->mPosition);
	}
}

/*
 * --INFO--
 * Address:	80113294
 * Size:	00009C
 */
bool SlimeEffect::invoke(zen::particleGenerator* gen, zen::particleMdl* mdl)
{
	if (mEfxGen && mdl) {
		Vector3f velocity = mObj->mVelocity;
		velocity.y        = 0.0f;
		velocity          = velocity * gsys->getFrameTime() * 0.9f;
		mdl->_34          = velocity;
	}
	return true;
}

/*
 * --INFO--
 * Address:	80113330
 * Size:	00004C
 */
void SlimeEffect::kill()
{
	if (mEfxGen) {
		effectMgr->mPtclMgr.killGenerator(mEfxGen, false);
		mEfxGen = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8011337C
 * Size:	000F54
 */
UtEffectMgr::UtEffectMgr()
{
	UtEffectMgr::effects = new KEffect*[28];
	registerEffect(0, new GoalEffect);
	registerEffect(1, new NaviWhistle(naviMgr->getNavi(0)));
	registerEffect(2, new NaviWhistle(naviMgr->getNavi(1))); // louie confirmed?
	registerEffect(3, new SmokeSoilEffect);
	registerEffect(5, new SmokeGrassEffect);
	registerEffect(4, new SmokeRockEffect);
	registerEffect(6, new SmokeTreeEffect);
	registerEffect(7, new NaviFue(naviMgr->getNavi(0)));
	registerEffect(9, new SimpleEffect(EffectMgr::EFF_Piki_GrowUp1));
	registerEffect(10, new SimpleEffect(EffectMgr::EFF_Piki_GrowUp2));
	registerEffect(11, new SimpleEffect(EffectMgr::EFF_Wl_Hit1));
	registerEffect(12, new SimpleEffect(EffectMgr::EFF_Wl_Hit0));
	registerEffect(13, new SimpleEffect(EffectMgr::EFF_WL_Hit2));
	registerEffect(14, new SimpleEffect(EffectMgr::EFF_WL_Hit3));
	registerEffect(15, new SimpleEffect(EffectMgr::EFF_Wl_Brk00));
	registerEffect(16, new SimpleEffect(EffectMgr::EFF_Wl_Brk01));
	registerEffect(17, new SimpleEffect(EffectMgr::EFF_P_Bubbles));
	registerEffect(18, new SimpleEffect(EffectMgr::EFF_RippleWhite));
	registerEffect(19, new BombEffect);
	registerEffect(20, new BombEffectLight);
	registerEffect(21, new UfoSuckEffect);
	registerEffect(22, new UfoSuikomiEffect);
	registerEffect(23, new WhistleTemplate(0x122, 0x123));
	registerEffect(24, new WhistleTemplate(0x122, 0x123));
	registerEffect(25, new SimpleEffect(EffectMgr::EFF_Piki_IdleBlue));
	registerEffect(26, new SimpleEffect(EffectMgr::EFF_Piki_IdleRed));
	registerEffect(27, new SimpleEffect(EffectMgr::EFF_Piki_IdleYellow));
}

/*
 * --INFO--
 * Address:	801142D0
 * Size:	000010
 */
void UtEffectMgr::registerEffect(int id, KEffect* efx)
{
	effects[id] = efx;
}

/*
 * --INFO--
 * Address:	801142E0
 * Size:	000044
 */
void UtEffectMgr::cast(int id, EffectParm& parm)
{
	if (id < 0 || id > 27) {
		ERROR("cast oob : %d", id);
	}

	KEffect* eff = effects[id];
	if (eff)
		eff->emit(parm);
}

/*
 * --INFO--
 * Address:	80114324
 * Size:	000044
 */
void UtEffectMgr::kill(int id)
{
	if (id < 0 || id > 27) {
		ERROR("kill oob : %d", id);
	}

	KEffect* eff = effects[id];
	if (eff)
		eff->kill();
}

/*
 * --INFO--
 * Address:	80114368
 * Size:	000034
 */
PermanentEffect::PermanentEffect()
{
	mPtclGen = nullptr;
	mPosition.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8011439C
 * Size:	00008C
 */
void PermanentEffect::init(Vector3f& pos, int id)
{
	if (mPtclGen) {
		return;
	}
	mPosition = pos;
	mPtclGen  = effectMgr->create((EffectMgr::effTypeTable)id, mPosition, nullptr, nullptr);

	if (mPtclGen) {
		mPtclGen->setEmitPosPtr(&mPosition);
		mPtclGen->stop();
	}
}

/*
 * --INFO--
 * Address:	80114428
 * Size:	000034
 */
void PermanentEffect::updatePos(Vector3f& pos)
{
	mPosition = pos;
	if (mPtclGen) {
		mPtclGen->start();
	}
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,0,30
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011445C
 * Size:	000080
 */
void PermanentEffect::changeEffect(int id)
{
	if (mPtclGen) {
		effectMgr->mPtclMgr.killGenerator(mPtclGen, false);
	}
	mPtclGen = effectMgr->create((EffectMgr::effTypeTable)id, mPosition, nullptr, nullptr);
	if (mPtclGen) {
		mPtclGen->setEmitPosPtr(&mPosition);
	}
}

/*
 * --INFO--
 * Address:	801144DC
 * Size:	00001C
 */
void PermanentEffect::stop()
{
	if (mPtclGen) {
		mPtclGen->pmSwitchOff(0x10);
	}
}

/*
 * --INFO--
 * Address:	801144F8
 * Size:	00001C
 */
void PermanentEffect::restart()
{
	if (mPtclGen) {
		mPtclGen->pmSwitchOn(0x10);
	}
}

/*
 * --INFO--
 * Address:	80114514
 * Size:	00004C
 */
void PermanentEffect::kill()
{
	if (mPtclGen) {
		effectMgr->mPtclMgr.killGenerator(mPtclGen, false);
		mPtclGen = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80114560
 * Size:	000080
 */
void FreeLightEffect::emit(EffectParm& parm)
{
	if (!mEfx) {
		mEfx = effectMgr->create((EffectMgr::effTypeTable)(EffectMgr::EFF_Piki_IdleBlue - mColor), *parm._20, nullptr, nullptr);
		if (mEfx) {
			mScale = mEfx->getScaleSize();
			mEfx->setEmitPosPtr(parm._20);
		}
	}
}

/*
 * --INFO--
 * Address:	801145E0
 * Size:	00001C
 */
void FreeLightEffect::stop()
{
	if (mEfx) {
		mEfx->pmSwitchOff(0x10);
	}
}

/*
 * --INFO--
 * Address:	801145FC
 * Size:	00001C
 */
void FreeLightEffect::restart()
{
	if (mEfx) {
		mEfx->pmSwitchOn(0x10);
	}
}

/*
 * --INFO--
 * Address:	80114618
 * Size:	00001C
 */
void FreeLightEffect::setScale(f32 scale)
{
	if (mEfx) {
		mEfx->setScaleSize(scale * mScale);
	}
}

/*
 * --INFO--
 * Address:	80114634
 * Size:	00004C
 */
void FreeLightEffect::kill()
{
	if (mEfx) {
		effectMgr->mPtclMgr.killGenerator(mEfx, false);
		mEfx = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80114680
 * Size:	000134
 */
void RippleEffect::emit(EffectParm& parm)
{
	if (mEfxA) {
		return;
	}
	f32 a = parm._24;

	mEfxB = effectMgr->create(EffectMgr::EFF_RippleBlack, *parm._20, nullptr, nullptr);
	if (mEfxB) {
		f32 scale = a * mEfxB->getScaleSize();
		mEfxB->setEmitPosPtr(parm._20);
		mEfxB->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		mEfxB->setScaleSize(scale);
	}

	mEfxA = effectMgr->create(EffectMgr::EFF_RippleWhite, *parm._20, nullptr, nullptr);
	if (mEfxA) {
		f32 scale = a * mEfxA->getScaleSize();
		mEfxA->setEmitPosPtr(parm._20);
		mEfxA->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		mEfxA->setScaleSize(scale);
	}
}

/*
 * --INFO--
 * Address:	801147B4
 * Size:	000094
 */
void RippleEffect::kill()
{
	if (mEfxB) {
		effectMgr->mPtclMgr.killGenerator(mEfxB, false);
		mEfxB = nullptr;
	}
	if (mEfxC) {
		effectMgr->mPtclMgr.killGenerator(mEfxC, false);
		mEfxC = nullptr;
	}
	if (mEfxA) {
		effectMgr->mPtclMgr.killGenerator(mEfxA, false);
		mEfxA = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80114848
 * Size:	000034
 */
void RippleEffect::stop()
{
	if (mEfxB) {
		mEfxB->pmSwitchOff(0x10);
	}
	if (mEfxA) {
		mEfxA->pmSwitchOff(0x10);
	}
}

/*
 * --INFO--
 * Address:	8011487C
 * Size:	000034
 */
void RippleEffect::restart()
{
	if (mEfxB) {
		mEfxB->pmSwitchOn(0x10);
	}
	if (mEfxA) {
		mEfxA->pmSwitchOn(0x10);
	}
}

/*
 * --INFO--
 * Address:	801148B0
 * Size:	00001C
 */
void BurnEffect::stop()
{
	if (mEfxA) {
		mEfxA->pmSwitchOff(0x10);
	}
}

/*
 * --INFO--
 * Address:	801148CC
 * Size:	00001C
 */
void BurnEffect::restart()
{
	if (mEfxA) {
		mEfxA->pmSwitchOn(0x10);
	}
}

/*
 * --INFO--
 * Address:	801148E8
 * Size:	00014C
 */
void BurnEffect::emit(EffectParm& parm)
{
	if (mEfxA) {
		return;
	}

	mEfxA = effectMgr->create(EffectMgr::EFF_Piki_Fire, *parm._20, this, nullptr);
	if (mEfxA) {
		mEfxA->setEmitPosPtr(parm._20);
		mEfxA->setOrientedNormalVector(Vector3f(0.0f, 0.0f, 1.0f));
		Vector3f vel(_0C[0]);
		vel.y = 0.0f;
		vel.multiply(0.01f);
		mEfxA->setEmitVelocity(Vector3f(vel));
	}

	mEfxB = effectMgr->create(EffectMgr::EFF_Piki_FireSparkles, *parm._20, this, nullptr);
	if (mEfxB) {
		mEfxB->setEmitPosPtr(parm._20);
		Vector3f vel(_0C[0]);
		vel.y = 0.0f;
		vel.multiply(0.01f);
		mEfxB->setEmitVelocity(Vector3f(vel));
	}
}

/*
 * --INFO--
 * Address:	80114A34
 * Size:	000070
 */
void BurnEffect::kill()
{
	if (mEfxA) {
		effectMgr->mPtclMgr.killGenerator(mEfxA, false);
		mEfxA = nullptr;
	}
	if (mEfxB) {
		effectMgr->mPtclMgr.killGenerator(mEfxB, false);
		mEfxB = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80114AA4
 * Size:	000008
 */
bool BurnEffect::invoke(zen::particleGenerator*)
{
	return true;
}

/*
 * --INFO--
 * Address:	80114AAC
 * Size:	0001C4
 */
void UfoSuikomiEffect::emit(EffectParm& parm)
{
	_0C = parm.mPosition;
	_18 = parm.mDirection;
	if (mEfx) {
		return;
	}
	mEfx          = effectMgr->create(EffectMgr::EFF_Rocket_Nke1, _0C, this, this);
	Vector3f diff = _18 - _0C;
	mEfx->setNewtonField(diff, 0.0016f, true);
	diff.normalise();
	mEfx->setVortexField(Vector3f(diff), -0.12f, -0.09f, 0.3f, 400.0f, true);

	f32 badcompiler[6];
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
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x14(r3)
	  lwz       r3, 0xC(r4)
	  lwz       r0, 0x10(r4)
	  stw       r3, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x14(r4)
	  stw       r0, 0x20(r30)
	  lwz       r0, 0x24(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x194
	  cmplwi    r30, 0
	  addi      r7, r30, 0
	  beq-      .loc_0x7C
	  addi      r7, r7, 0x4

	.loc_0x7C:
	  lwz       r3, 0x3180(r13)
	  addi      r6, r30, 0
	  addi      r5, r30, 0xC
	  li        r4, 0x148
	  bl        0x88000
	  stw       r3, 0x24(r30)
	  lfs       f26, 0x20(r30)
	  lfs       f0, 0x14(r30)
	  lfs       f27, 0x1C(r30)
	  lfs       f1, 0x10(r30)
	  fsubs     f29, f26, f0
	  lwz       r31, 0x24(r30)
	  lfs       f28, 0x18(r30)
	  fsubs     f30, f27, f1
	  lfs       f0, 0xC(r30)
	  mr        r3, r31
	  fsubs     f31, f28, f0
	  bl        .loc_0x1C4
	  lfs       f0, 0x8(r3)
	  addi      r6, r1, 0x3C
	  addi      r5, r1, 0x38
	  fsubs     f0, f26, f0
	  addi      r4, r1, 0x34
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f0, f27, f0
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x48
	  fsubs     f0, f28, f0
	  stfs      f0, 0x34(r1)
	  bl        -0xDDA88
	  lfs       f2, 0x48(r1)
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  stfs      f2, 0x170(r31)
	  fmuls     f2, f29, f29
	  lfs       f3, 0x4C(r1)
	  fadds     f0, f1, f0
	  stfs      f3, 0x174(r31)
	  fadds     f1, f2, f0
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x178(r31)
	  lfs       f0, -0x60A8(r2)
	  stfs      f0, 0x17C(r31)
	  lwz       r0, 0x84(r31)
	  oris      r0, r0, 0x10
	  stw       r0, 0x84(r31)
	  bl        -0x106FA8
	  lfs       f0, -0x60B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x158
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x158:
	  lwz       r3, 0x24(r30)
	  stfs      f31, 0x144(r3)
	  stfs      f30, 0x148(r3)
	  stfs      f29, 0x14C(r3)
	  lfs       f0, -0x60A4(r2)
	  stfs      f0, 0x150(r3)
	  lfs       f0, -0x60A0(r2)
	  stfs      f0, 0x154(r3)
	  lfs       f0, -0x609C(r2)
	  stfs      f0, 0x158(r3)
	  lfs       f0, -0x6098(r2)
	  stfs      f0, 0x15C(r3)
	  lwz       r0, 0x84(r3)
	  oris      r0, r0, 0x4
	  stw       r0, 0x84(r3)

	.loc_0x194:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  lfd       f28, 0xA0(r1)
	  lfd       f27, 0x98(r1)
	  lfd       f26, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x1C4:
	*/
}

/*
 * --INFO--
 * Address:	80114C8C
 * Size:	00004C
 */
void UfoSuikomiEffect::kill()
{
	if (mEfx) {
		effectMgr->mPtclMgr.killGenerator(mEfx, false);
		mEfx = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80114CD8
 * Size:	0000E0
 */
void WhistleTemplate::emit(EffectParm& parm)
{
	_0C = parm.mPosition;
	_18 = parm.mDirection;
	if (mEfxA || mEfxB) {
		return;
	}
	mEfxA = effectMgr->create((EffectMgr::effTypeTable)_2C, _18, this, this);
	mEfxB = effectMgr->create((EffectMgr::effTypeTable)_30, _18, this, this);

	if (mEfxA) {
		mEfxA->setOrientedConstZAxis(true);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x14(r3)
	  lwz       r3, 0xC(r4)
	  lwz       r0, 0x10(r4)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x14(r4)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC
	  lwz       r0, 0x28(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  b         .loc_0xCC

	.loc_0x60:
	  cmplwi    r31, 0
	  addi      r7, r31, 0
	  beq-      .loc_0x70
	  addi      r7, r7, 0x4

	.loc_0x70:
	  lwz       r3, 0x3180(r13)
	  mr        r6, r31
	  lwz       r4, 0x2C(r31)
	  addi      r5, r31, 0x18
	  bl        0x87DE0
	  cmplwi    r31, 0
	  stw       r3, 0x24(r31)
	  mr        r7, r31
	  beq-      .loc_0x98
	  addi      r7, r7, 0x4

	.loc_0x98:
	  lwz       r3, 0x3180(r13)
	  mr        r6, r31
	  lwz       r4, 0x30(r31)
	  addi      r5, r31, 0x18
	  bl        0x87DB8
	  stw       r3, 0x28(r31)
	  lwz       r4, 0x24(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xCC
	  lbz       r0, 0x68(r4)
	  li        r3, 0x1
	  rlwimi    r0,r3,5,26,26
	  stb       r0, 0x68(r4)

	.loc_0xCC:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114DB8
 * Size:	000070
 */
void WhistleTemplate::kill()
{
	PRINT("** KILL WHISTLE TYPE\n");
	if (mEfxA) {
		PRINT("* DO KILL pg2\n");
		effectMgr->mPtclMgr.killGenerator(mEfxA, false);
		mEfxA = nullptr;
	}
	if (mEfxB) {
		PRINT("* DO KILL pg3\n");
		effectMgr->mPtclMgr.killGenerator(mEfxB, false);
		mEfxB = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80114E28
 * Size:	00034C
 */
bool WhistleTemplate::invoke(zen::particleGenerator* efx, zen::particleMdl* mdl)
{
	Vector3f diff = _18 - _0C;
	mdl->_18      = diff;
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  lis       r4, 0x4330
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stw       r31, 0x124(r1)
	  mr        r31, r5
	  stw       r30, 0x120(r1)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x18(r3)
	  lfs       f3, 0x10(r3)
	  lfs       f2, 0x1C(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x14(r3)
	  lfs       f1, 0x20(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x100(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x104(r1)
	  stfs      f0, 0x108(r1)
	  lha       r3, 0x2E(r5)
	  lha       r0, 0x2C(r5)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x6088(r2)
	  stw       r3, 0x11C(r1)
	  xoris     r0, r0, 0x8000
	  lwz       r3, 0x18(r6)
	  stw       r0, 0x114(r1)
	  lwz       r0, 0x1C(r6)
	  stw       r4, 0x118(r1)
	  stw       r4, 0x110(r1)
	  lfd       f1, 0x118(r1)
	  lfd       f0, 0x110(r1)
	  fsubs     f1, f1, f2
	  stw       r3, 0x18(r5)
	  fsubs     f0, f0, f2
	  stw       r0, 0x1C(r5)
	  fdivs     f31, f1, f0
	  lwz       r0, 0x20(r6)
	  stw       r0, 0x20(r5)
	  lfs       f0, 0x100(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x104(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x108(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0x7C(r1)
	  lwz       r0, 0x80(r1)
	  stw       r3, 0xC(r5)
	  stw       r0, 0x10(r5)
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x14(r5)
	  lfs       f1, -0x6094(r2)
	  lfs       f0, 0x1C(r6)
	  lfs       f2, 0x10(r6)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x2F0
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0xC(r6)
	  lfs       f2, 0x14(r6)
	  bl        -0xACD60
	  lfs       f0, -0x60B0(r2)
	  mr        r30, r3
	  li        r3, 0x8
	  stfs      f0, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  stfs      f0, 0xE0(r1)
	  stfs      f0, 0xE4(r1)
	  stfs      f0, 0xE8(r1)
	  stfs      f0, 0xEC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f0, 0xF4(r1)
	  b         .loc_0x310

	.loc_0x144:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x160

	.loc_0x154:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x154

	.loc_0x160:
	  lfs       f1, -0x6090(r2)
	  li        r3, 0x8
	  lfs       f0, -0x60B0(r2)
	  stfs      f1, 0xF8(r1)
	  stfs      f1, 0xE8(r1)
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  b         .loc_0x320

	.loc_0x19C:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x1B8

	.loc_0x1AC:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x1AC

	.loc_0x1B8:
	  lfs       f0, -0x60B0(r2)
	  lfs       f2, -0x6090(r2)
	  stfs      f0, 0xAC(r1)
	  lfs       f1, 0x100(r1)
	  stfs      f2, 0xD4(r1)
	  fmuls     f1, f1, f1
	  stfs      f0, 0x9C(r1)
	  stfs      f2, 0xC4(r1)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0x98(r1)
	  stfs      f2, 0xB4(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x104(r1)
	  lfs       f2, 0x108(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1073EC
	  lfs       f0, -0x60B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x238
	  lfs       f0, 0x100(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x100(r1)
	  lfs       f0, 0x104(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x104(r1)
	  lfs       f0, 0x108(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x108(r1)

	.loc_0x238:
	  addi      r3, r1, 0x100
	  addi      r4, r1, 0xD8
	  bl        0x86A78
	  lfs       f3, -0x2498(r13)
	  addi      r3, r1, 0x70
	  lfs       f0, 0x18(r30)
	  addi      r4, r1, 0xB4
	  lfs       f2, 0x20(r30)
	  lfs       f1, 0x1C(r30)
	  fmuls     f0, f0, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f2, 0x78(r1)
	  bl        0x86A3C
	  addi      r3, r1, 0xA4
	  addi      r4, r1, 0xD8
	  bl        -0xDD7F4
	  addi      r3, r1, 0x94
	  addi      r4, r1, 0xB4
	  bl        -0xDD800
	  fmr       f1, f31
	  addi      r3, r1, 0xA4
	  addi      r4, r1, 0x94
	  li        r5, 0
	  bl        -0xDCF4C
	  addi      r3, r1, 0xA4
	  addi      r4, r31, 0x5C
	  bl        -0xDD058
	  addi      r3, r1, 0xA4
	  addi      r4, r31, 0x34
	  bl        -0xDD0E4
	  lfs       f0, 0x34(r31)
	  lfs       f1, -0x60AC(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x38(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r31)
	  lfs       f0, 0x3C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r31)
	  b         .loc_0x308

	.loc_0x2F0:
	  lfs       f0, 0x100(r1)
	  stfs      f0, 0x5C(r31)
	  lfs       f0, 0x104(r1)
	  stfs      f0, 0x60(r31)
	  lfs       f0, 0x108(r1)
	  stfs      f0, 0x64(r31)

	.loc_0x308:
	  li        r3, 0
	  b         .loc_0x330

	.loc_0x310:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xD8
	  add       r4, r4, r0
	  b         .loc_0x144

	.loc_0x320:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xB4
	  add       r4, r4, r0
	  b         .loc_0x19C

	.loc_0x330:
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115174
 * Size:	0000D8
 */
void BombEffectLight::emit(EffectParm& parm)
{
	zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Bomb_Glow, parm.mPosition, nullptr, nullptr);
	if (efx) {
		Vector3f nrm(0.0f, 1.0f, 0.0f);
		efx->setOrientedNormalVector(nrm);
	}
	effectMgr->create(EffectMgr::EFF_BombLight_Bang, parm.mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_BombLight_Wave, parm.mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_BombLight_FireBang, parm.mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_BombLight_FireGlow, parm.mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	8011524C
 * Size:	000004
 */
void BombEffectLight::kill()
{
}

/*
 * --INFO--
 * Address:	80115250
 * Size:	0000F0
 */
void BombEffect::emit(EffectParm& parm)
{
	zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Bomb_Glow, parm.mPosition, nullptr, nullptr);
	if (efx) {
		Vector3f nrm(0.0f, 1.0f, 0.0f);
		efx->setOrientedNormalVector(nrm);
	}
	effectMgr->create(EffectMgr::EFF_Bomb_Wave, parm.mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Bomb_DustRing, parm.mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Bomb_Bang, parm.mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Bomb_FireBang, parm.mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Bomb_FireGlow, parm.mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	80115340
 * Size:	000004
 */
void BombEffect::kill()
{
}

/*
 * --INFO--
 * Address:	80115344
 * Size:	000044
 */
void SimpleEffect::emit(EffectParm& parm)
{
	mEfx = effectMgr->create((EffectMgr::effTypeTable)mEfxId, parm.mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	80115388
 * Size:	000038
 */
void SimpleEffect::kill()
{
	if (mEfx)
		effectMgr->mPtclMgr.killGenerator(mEfx, false);
}

/*
 * --INFO--
 * Address:	801153C0
 * Size:	000008
 */
bool NaviFue::invoke(zen::particleGenerator*)
{
	return true;
}

/*
 * --INFO--
 * Address:	801153C8
 * Size:	0000C0
 */
void NaviFue::emit(EffectParm& parm)
{
	if (mEntries[0]) {
		return;
	}

	for (int i = 0; i < mEntryNum; i++) {
		mEntries[i] = effectMgr->create(EffectMgr::EFF_Navi_WhistleCursor, mNavi->_938[i], this, nullptr);
		if (mEntries[i]) {
			mEntries[i]->setEmitPosPtr(&mNavi->_938[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	80115488
 * Size:	0000B4
 */
void NaviFue::kill()
{
	if (!mEntries[0]) {
		return;
	}

	for (int i = 0; i < mEntryNum; i++) {
		if (mEntries[i]) {
			mEntries[i]->setInitVel(0.0f);
			effectMgr->mPtclMgr.killGenerator(mEntries[i], false);
		}
		mEntries[i] = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8011553C
 * Size:	000034
 */
void SmokeTreeEffect::emit(EffectParm& parm)
{
	effectMgr->create(EffectMgr::EFF_Kogane_Walk0, parm.mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	80115570
 * Size:	000034
 */
void SmokeRockEffect::emit(EffectParm& parm)
{
	effectMgr->create(EffectMgr::EFF_Kogane_Walk2, parm.mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	801155A4
 * Size:	000034
 */
void SmokeGrassEffect::emit(EffectParm& parm)
{
	effectMgr->create(EffectMgr::EFF_Kogane_Walk1, parm.mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	801155D8
 * Size:	000034
 */
void SmokeSoilEffect::emit(EffectParm& parm)
{
	effectMgr->create(EffectMgr::EFF_Kogane_Walk0, parm.mPosition, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	8011560C
 * Size:	0000FC
 */
void NaviWhistle::emit(EffectParm& parm)
{
	if (mEfxA || mEfxB || mEfxC) {
		return;
	}
	mEfxA = effectMgr->create(EffectMgr::EFF_Navi_Whistle1, mNavi->mNaviLightPosition, this, nullptr);
	mEfxB = effectMgr->create(EffectMgr::EFF_Navi_Whistle2, mNavi->mNaviLightPosition, this, this);
	mEfxC = effectMgr->create(EffectMgr::EFF_Navi_Whistle3, mNavi->mNaviLightPosition, this, this);

	if (mEfxA) {
		mEfxA->setEmitPosPtr(&mNavi->mNaviLightPosition);
	}
	if (mEfxB) {
		mEfxB;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE8
	  lwz       r0, 0x14(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xE8
	  lwz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  b         .loc_0xE8

	.loc_0x3C:
	  lwz       r5, 0xC(r31)
	  mr        r6, r31
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xB
	  addi      r5, r5, 0x784
	  li        r7, 0
	  bl        0x874D8
	  cmplwi    r31, 0
	  stw       r3, 0x10(r31)
	  mr        r7, r31
	  beq-      .loc_0x6C
	  addi      r7, r7, 0x4

	.loc_0x6C:
	  lwz       r4, 0xC(r31)
	  mr        r6, r31
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x784
	  li        r4, 0xA
	  bl        0x874AC
	  cmplwi    r31, 0
	  stw       r3, 0x14(r31)
	  mr        r7, r31
	  beq-      .loc_0x98
	  addi      r7, r7, 0x4

	.loc_0x98:
	  lwz       r4, 0xC(r31)
	  mr        r6, r31
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x784
	  li        r4, 0x9
	  bl        0x87480
	  stw       r3, 0x18(r31)
	  lwz       r4, 0x10(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xCC
	  lwz       r3, 0xC(r31)
	  addi      r0, r3, 0x784
	  stw       r0, 0x18(r4)

	.loc_0xCC:
	  lwz       r4, 0x14(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xE8
	  lbz       r0, 0x68(r4)
	  li        r3, 0x1
	  rlwimi    r0,r3,5,26,26
	  stb       r0, 0x68(r4)

	.loc_0xE8:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115708
 * Size:	000094
 */
void NaviWhistle::kill()
{
	if (mEfxA) {
		effectMgr->mPtclMgr.killGenerator(mEfxA, false);
		mEfxA = nullptr;
	}

	if (mEfxB) {
		effectMgr->mPtclMgr.killGenerator(mEfxB, false);
		mEfxB = nullptr;
	}

	if (mEfxC) {
		effectMgr->mPtclMgr.killGenerator(mEfxC, false);
		mEfxC = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8011579C
 * Size:	000364
 */
bool NaviWhistle::invoke(zen::particleGenerator*, zen::particleMdl*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x4330
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x138(r1)
	  stfd      f31, 0x130(r1)
	  stw       r31, 0x12C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x128(r1)
	  lwz       r4, 0xC(r3)
	  addi      r5, r4, 0x784
	  lfs       f0, 0x784(r4)
	  lfsu      f1, 0x6F0(r4)
	  lfs       f2, 0x4(r5)
	  lfs       f3, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r4)
	  lfs       f1, 0x8(r5)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x108(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x10C(r1)
	  stfs      f0, 0x110(r1)
	  lha       r4, 0x2E(r31)
	  lha       r0, 0x2C(r31)
	  xoris     r4, r4, 0x8000
	  lfd       f2, -0x6088(r2)
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x124(r1)
	  lwz       r5, 0xC(r3)
	  stw       r0, 0x11C(r1)
	  lwz       r4, 0x784(r5)
	  stw       r6, 0x120(r1)
	  lwz       r0, 0x788(r5)
	  stw       r6, 0x118(r1)
	  lfd       f1, 0x120(r1)
	  lfd       f0, 0x118(r1)
	  fsubs     f1, f1, f2
	  stw       r4, 0x18(r31)
	  fsubs     f0, f0, f2
	  stw       r0, 0x1C(r31)
	  fdivs     f31, f1, f0
	  lwz       r0, 0x78C(r5)
	  stw       r0, 0x20(r31)
	  lfs       f0, 0x108(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x10C(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x110(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8C(r1)
	  lwz       r4, 0x84(r1)
	  lwz       r0, 0x88(r1)
	  stw       r4, 0xC(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x8C(r1)
	  stw       r0, 0x14(r31)
	  lwz       r5, 0xC(r3)
	  lfs       f1, -0x6094(r2)
	  lfs       f0, 0x98(r5)
	  lfs       f2, 0x6F4(r5)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x308
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x6F0(r5)
	  lfs       f2, 0x6F8(r5)
	  bl        -0xAD6E0
	  mr.       r30, r3
	  bne-      .loc_0x130
	  li        r3, 0
	  b         .loc_0x348

	.loc_0x130:
	  lfs       f0, -0x60B0(r2)
	  li        r3, 0x8
	  stfs      f0, 0xE0(r1)
	  stfs      f0, 0xE4(r1)
	  stfs      f0, 0xE8(r1)
	  stfs      f0, 0xEC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f0, 0xF4(r1)
	  stfs      f0, 0xF8(r1)
	  stfs      f0, 0xFC(r1)
	  b         .loc_0x328

	.loc_0x15C:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x178

	.loc_0x16C:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x16C

	.loc_0x178:
	  lfs       f1, -0x6090(r2)
	  li        r3, 0x8
	  lfs       f0, -0x60B0(r2)
	  stfs      f1, 0x100(r1)
	  stfs      f1, 0xF0(r1)
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  stfs      f0, 0xD4(r1)
	  stfs      f0, 0xD8(r1)
	  b         .loc_0x338

	.loc_0x1B4:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x1D0

	.loc_0x1C4:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x1C4

	.loc_0x1D0:
	  lfs       f0, -0x60B0(r2)
	  lfs       f2, -0x6090(r2)
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0x108(r1)
	  stfs      f2, 0xDC(r1)
	  fmuls     f1, f1, f1
	  stfs      f0, 0xA4(r1)
	  stfs      f2, 0xCC(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f2, 0xBC(r1)
	  stfs      f0, 0xAC(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0x10C(r1)
	  lfs       f2, 0x110(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x107D78
	  lfs       f0, -0x60B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x250
	  lfs       f0, 0x108(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x108(r1)
	  lfs       f0, 0x10C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x10C(r1)
	  lfs       f0, 0x110(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x110(r1)

	.loc_0x250:
	  addi      r3, r1, 0x108
	  addi      r4, r1, 0xE0
	  bl        0x860EC
	  lfs       f3, -0x2494(r13)
	  addi      r3, r1, 0x78
	  lfs       f0, 0x18(r30)
	  addi      r4, r1, 0xBC
	  lfs       f2, 0x20(r30)
	  lfs       f1, 0x1C(r30)
	  fmuls     f0, f0, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f2, 0x80(r1)
	  bl        0x860B0
	  addi      r3, r1, 0xAC
	  addi      r4, r1, 0xE0
	  bl        -0xDE180
	  addi      r3, r1, 0x9C
	  addi      r4, r1, 0xBC
	  bl        -0xDE18C
	  fmr       f1, f31
	  addi      r3, r1, 0xAC
	  addi      r4, r1, 0x9C
	  li        r5, 0
	  bl        -0xDD8D8
	  addi      r3, r1, 0xAC
	  addi      r4, r31, 0x5C
	  bl        -0xDD9E4
	  addi      r3, r1, 0xAC
	  addi      r4, r31, 0x34
	  bl        -0xDDA70
	  lfs       f0, 0x34(r31)
	  lfs       f1, -0x60AC(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x38(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r31)
	  lfs       f0, 0x3C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r31)
	  b         .loc_0x320

	.loc_0x308:
	  lfs       f0, 0x108(r1)
	  stfs      f0, 0x5C(r31)
	  lfs       f0, 0x10C(r1)
	  stfs      f0, 0x60(r31)
	  lfs       f0, 0x110(r1)
	  stfs      f0, 0x64(r31)

	.loc_0x320:
	  li        r3, 0
	  b         .loc_0x348

	.loc_0x328:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xE0
	  add       r4, r4, r0
	  b         .loc_0x15C

	.loc_0x338:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xBC
	  add       r4, r4, r0
	  b         .loc_0x1B4

	.loc_0x348:
	  lwz       r0, 0x13C(r1)
	  lfd       f31, 0x130(r1)
	  lwz       r31, 0x12C(r1)
	  lwz       r30, 0x128(r1)
	  addi      r1, r1, 0x138
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115B00
 * Size:	000038
 */
bool GoalEffect::invoke(zen::particleGenerator* efx)
{
	if (efx->_88[8] > 50) {
		Vector3f grav(0.0f, 0.0f, 0.0f);
		efx->setGravityField(grav, true);
	}
	return true;
	/*
	.loc_0x0:
	  lha       r0, 0x90(r4)
	  cmpwi     r0, 0x32
	  blt-      .loc_0x30
	  lfs       f1, -0x24B8(r13)
	  lfs       f2, -0x24B4(r13)
	  lfs       f0, -0x24BC(r13)
	  stfs      f0, 0x12C(r4)
	  stfs      f1, 0x130(r4)
	  stfs      f2, 0x134(r4)
	  lwz       r0, 0x84(r4)
	  rlwinm    r0,r0,0,16,14
	  stw       r0, 0x84(r4)

	.loc_0x30:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115B38
 * Size:	00003C
 */
void GoalEffect::emit(EffectParm& parm)
{
	effectMgr->create(EffectMgr::EFF_Onyon_Suck, parm.mPosition, this, this);
}
