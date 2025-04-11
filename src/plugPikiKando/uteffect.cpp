#include "UtEffect.h"
#include "Creature.h"
#include "EffectMgr.h"
#include "Matrix3f.h"
#include "NaviMgr.h"
#include "zen/Math.h"
#include "NaviWhistle.h"
#include "DebugLog.h"

UtEffectMgr* utEffectMgr;
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
		mEfxGen->invisible();
}

/*
 * --INFO--
 * Address:	801131E8
 * Size:	00001C
 */
void SlimeEffect::restart()
{
	if (mEfxGen)
		mEfxGen->visible();
}

/*
 * --INFO--
 * Address:	80113204
 * Size:	000090
 */
void SlimeEffect::emit(EffectParm& parm)
{
	mObj         = parm.mOwner;
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
	registerEffect(KandoEffect::Goal, new GoalEffect);
	registerEffect(KandoEffect::NaviWhistle0, new NaviWhistle(naviMgr->getNavi(0)));
	registerEffect(KandoEffect::NaviWhistle1, new NaviWhistle(naviMgr->getNavi(1))); // louie confirmed?
	registerEffect(KandoEffect::SmokeSoil, new SmokeSoilEffect);
	registerEffect(KandoEffect::SmokeGrass, new SmokeGrassEffect);
	registerEffect(KandoEffect::SmokeRock, new SmokeRockEffect);
	registerEffect(KandoEffect::SmokeTree, new SmokeTreeEffect);
	registerEffect(KandoEffect::NaviFue0, new NaviFue(naviMgr->getNavi(0)));
	registerEffect(KandoEffect::PikiGrowup1, new SimpleEffect(EffectMgr::EFF_Piki_GrowUp1));
	registerEffect(KandoEffect::PikiGrowup2, new SimpleEffect(EffectMgr::EFF_Piki_GrowUp2));
	registerEffect(KandoEffect::WallHit1, new SimpleEffect(EffectMgr::EFF_Wl_Hit1));
	registerEffect(KandoEffect::WallHit0, new SimpleEffect(EffectMgr::EFF_Wl_Hit0));
	registerEffect(KandoEffect::WallHit2, new SimpleEffect(EffectMgr::EFF_WL_Hit2));
	registerEffect(KandoEffect::WallHit3, new SimpleEffect(EffectMgr::EFF_WL_Hit3));
	registerEffect(KandoEffect::WallBreak0, new SimpleEffect(EffectMgr::EFF_Wl_Brk00));
	registerEffect(KandoEffect::WallBreak1, new SimpleEffect(EffectMgr::EFF_Wl_Brk01));
	registerEffect(KandoEffect::Bubbles, new SimpleEffect(EffectMgr::EFF_P_Bubbles));
	registerEffect(KandoEffect::Ripples, new SimpleEffect(EffectMgr::EFF_RippleWhite));
	registerEffect(KandoEffect::Bomb, new BombEffect);
	registerEffect(KandoEffect::BombLight, new BombEffectLight);
	registerEffect(KandoEffect::UfoSuck, new UfoSuckEffect);
	registerEffect(KandoEffect::UfoSuikomi, new UfoSuikomiEffect);
	registerEffect(KandoEffect::WhistleTemplate0, new WhistleTemplate(EffectMgr::EFF_Rocket_Bm2o, EffectMgr::EFF_UfoPart_ASN01));
	registerEffect(KandoEffect::WhistleTemplate1, new WhistleTemplate(EffectMgr::EFF_Rocket_Bm2o, EffectMgr::EFF_UfoPart_ASN01));
	registerEffect(KandoEffect::IdleBluePiki, new SimpleEffect(EffectMgr::EFF_Piki_IdleBlue));
	registerEffect(KandoEffect::IdleRedPiki, new SimpleEffect(EffectMgr::EFF_Piki_IdleRed));
	registerEffect(KandoEffect::IdleYellowPiki, new SimpleEffect(EffectMgr::EFF_Piki_IdleYellow));
}

/*
 * --INFO--
 * Address:	801142D0
 * Size:	000010
 */
void UtEffectMgr::registerEffect(int kEffID, KEffect* efx)
{
	effects[kEffID] = efx;
}

/*
 * --INFO--
 * Address:	801142E0
 * Size:	000044
 */
void UtEffectMgr::cast(int kEffID, EffectParm& parm)
{
	if (kEffID < KandoEffect::START || kEffID > KandoEffect::END) {
		ERROR("cast oob : %d", kEffID);
	}

	KEffect* eff = effects[kEffID];
	if (eff) {
		eff->emit(parm);
	}
}

/*
 * --INFO--
 * Address:	80114324
 * Size:	000044
 */
void UtEffectMgr::kill(int kEffID)
{
	if (kEffID < KandoEffect::START || kEffID > KandoEffect::END) {
		ERROR("kill oob : %d", kEffID);
	}

	KEffect* eff = effects[kEffID];
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
void PermanentEffect::init(Vector3f& pos, int effType)
{
	if (mPtclGen) {
		return;
	}
	mPosition = pos;
	mPtclGen  = effectMgr->create((EffectMgr::effTypeTable)effType, mPosition, nullptr, nullptr);

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
}

/*
 * --INFO--
 * Address:	8011445C
 * Size:	000080
 */
void PermanentEffect::changeEffect(int effType)
{
	if (mPtclGen) {
		effectMgr->mPtclMgr.killGenerator(mPtclGen, false);
	}
	mPtclGen = effectMgr->create((EffectMgr::effTypeTable)effType, mPosition, nullptr, nullptr);
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
		mPtclGen->invisible();
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
		mPtclGen->visible();
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
		mEfx = effectMgr->create((EffectMgr::effTypeTable)(EffectMgr::EFF_Piki_IdleBlue - mColor), *parm.mPositionRef, nullptr, nullptr);
		if (mEfx) {
			mScale = mEfx->getScaleSize();
			mEfx->setEmitPosPtr(parm.mPositionRef);
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
		mEfx->invisible();
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
		mEfx->visible();
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
	f32 a = parm.mScale;

	mEfxB = effectMgr->create(EffectMgr::EFF_RippleBlack, *parm.mPositionRef, nullptr, nullptr);
	if (mEfxB) {
		f32 scale = a * mEfxB->getScaleSize();
		mEfxB->setEmitPosPtr(parm.mPositionRef);
		mEfxB->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		mEfxB->setScaleSize(scale);
	}

	mEfxA = effectMgr->create(EffectMgr::EFF_RippleWhite, *parm.mPositionRef, nullptr, nullptr);
	if (mEfxA) {
		f32 scale = a * mEfxA->getScaleSize();
		mEfxA->setEmitPosPtr(parm.mPositionRef);
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
		mEfxB->invisible();
	}
	if (mEfxA) {
		mEfxA->invisible();
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
		mEfxB->visible();
	}
	if (mEfxA) {
		mEfxA->visible();
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
		mEfxA->invisible();
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
		mEfxA->visible();
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

	mEfxA = effectMgr->create(EffectMgr::EFF_Piki_Fire, *parm.mPositionRef, this, nullptr);
	if (mEfxA) {
		mEfxA->setEmitPosPtr(parm.mPositionRef);
		mEfxA->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
		Vector3f vel(_0C[0]);
		vel.y = 0.0f;
		vel.multiply(0.01f);
		mEfxA->setAirField(Vector3f(vel), true);
	}

	mEfxB = effectMgr->create(EffectMgr::EFF_Piki_FireSparkles, *parm.mPositionRef, this, nullptr);
	if (mEfxB) {
		mEfxB->setEmitPosPtr(parm.mPositionRef);
		Vector3f vel(_0C[0]);
		vel.y = 0.0f;
		vel.multiply(0.01f);
		mEfxB->setAirField(Vector3f(vel), true);
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
