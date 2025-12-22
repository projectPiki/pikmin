#include "Creature.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "KEffect.h"
#include "Matrix3f.h"
#include "zen/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(10)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("utEffect")

SlimeEffect::SlimeEffect()
{
	mEfxGen = nullptr;
}

void SlimeEffect::stop()
{
	if (mEfxGen)
		mEfxGen->invisible();
}

void SlimeEffect::restart()
{
	if (mEfxGen)
		mEfxGen->visible();
}

void SlimeEffect::emit(EffectParm& parm)
{
	mObj         = parm.mOwner;
	Vector3f pos = mObj->mSRT.t;
	if (!mEfxGen) {
		mEfxGen = effectMgr->create(EffectMgr::EFF_Piki_Bubble, pos, this, this);
		mEfxGen->setEmitPosPtr(&mObj->mSRT.t);
	}
}

bool SlimeEffect::invoke(zen::particleGenerator* gen, zen::particleMdl* mdl)
{
	if (mEfxGen && mdl) {
		Vector3f velocity = mObj->mVelocity;
		velocity.y        = 0.0f;
		velocity          = velocity * gsys->getFrameTime() * 0.9f;
		mdl->mVelocity    = velocity;
	}
	return true;
}

void SlimeEffect::kill()
{
	if (mEfxGen) {
		effectMgr->kill(mEfxGen, false);
		mEfxGen = nullptr;
	}
}

#include "NaviMgr.h"
#include "NaviWhistle.h"
#include "UtEffect.h"
UtEffectMgr* utEffectMgr;
KEffect** UtEffectMgr::effects;

UtEffectMgr::UtEffectMgr()
{
	UtEffectMgr::effects = new KEffect*[KandoEffect::COUNT];
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
	registerEffect(KandoEffect::WhistleTemplate0, new WhistleTemplate(EffectMgr::EFF_Rocket_Bm1o, EffectMgr::EFF_Rocket_Bm2o));
	registerEffect(KandoEffect::WhistleTemplate1, new WhistleTemplate(EffectMgr::EFF_Rocket_Bm1o, EffectMgr::EFF_Rocket_Bm2o));
	registerEffect(KandoEffect::IdleBluePiki, new SimpleEffect(EffectMgr::EFF_Piki_IdleBlue));
	registerEffect(KandoEffect::IdleRedPiki, new SimpleEffect(EffectMgr::EFF_Piki_IdleRed));
	registerEffect(KandoEffect::IdleYellowPiki, new SimpleEffect(EffectMgr::EFF_Piki_IdleYellow));
}

void UtEffectMgr::registerEffect(int kEffID, KEffect* efx)
{
	if (kEffID < KandoEffect::START || kEffID > KandoEffect::END) {
		ERROR("regist oob : %d", kEffID);
	}
	effects[kEffID] = efx;
}

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

void UtEffectMgr::kill(int kEffID)
{
	if (kEffID < KandoEffect::START || kEffID > KandoEffect::END) {
		ERROR("kill oob : %d", kEffID);
	}

	KEffect* eff = effects[kEffID];
	if (eff)
		eff->kill();
}

PermanentEffect::PermanentEffect()
{
	mPtclGen = nullptr;
	mPosition.set(0.0f, 0.0f, 0.0f);
}

void PermanentEffect::init(immut Vector3f& pos, int effType)
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

void PermanentEffect::updatePos(immut Vector3f& pos)
{
	mPosition = pos;
	if (mPtclGen) {
		mPtclGen->start();
	}
}

void PermanentEffect::changeEffect(int effType)
{
	if (mPtclGen) {
		effectMgr->kill(mPtclGen, false);
	}
	mPtclGen = effectMgr->create((EffectMgr::effTypeTable)effType, mPosition, nullptr, nullptr);
	if (mPtclGen) {
		mPtclGen->setEmitPosPtr(&mPosition);
	}
}

void PermanentEffect::stop()
{
	if (mPtclGen) {
		mPtclGen->invisible();
	}
}

void PermanentEffect::restart()
{
	if (mPtclGen) {
		mPtclGen->visible();
	}
}

void PermanentEffect::kill()
{
	if (mPtclGen) {
		effectMgr->kill(mPtclGen, false);
		mPtclGen = nullptr;
	}
}

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

void FreeLightEffect::stop()
{
	if (mEfx) {
		mEfx->invisible();
	}
}

void FreeLightEffect::restart()
{
	if (mEfx) {
		mEfx->visible();
	}
}

void FreeLightEffect::setScale(f32 scale)
{
	if (mEfx) {
		mEfx->setScaleSize(scale * mScale);
	}
}

void FreeLightEffect::kill()
{
	if (mEfx) {
		effectMgr->kill(mEfx, false);
		mEfx = nullptr;
	}
}

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

void RippleEffect::kill()
{
	if (mEfxB) {
		effectMgr->kill(mEfxB, false);
		mEfxB = nullptr;
	}
	if (mEfxC) {
		effectMgr->kill(mEfxC, false);
		mEfxC = nullptr;
	}
	if (mEfxA) {
		effectMgr->kill(mEfxA, false);
		mEfxA = nullptr;
	}
}

void RippleEffect::stop()
{
	if (mEfxB) {
		mEfxB->invisible();
	}
	if (mEfxA) {
		mEfxA->invisible();
	}
}

void RippleEffect::restart()
{
	if (mEfxB) {
		mEfxB->visible();
	}
	if (mEfxA) {
		mEfxA->visible();
	}
}

void BurnEffect::stop()
{
	if (mEfxA) {
		mEfxA->invisible();
	}
}

void BurnEffect::restart()
{
	if (mEfxA) {
		mEfxA->visible();
	}
}

void BurnEffect::emit(EffectParm& parm)
{
	if (mEfxA) {
		return;
	}

	mEfxA = effectMgr->create(EffectMgr::EFF_Piki_Fire, *parm.mPositionRef, this, nullptr);
	if (mEfxA) {
		mEfxA->setEmitPosPtr(parm.mPositionRef);
		mEfxA->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
		Vector3f vel(*_0C);
		vel.y = 0.0f;
		vel.multiply(0.01f);
		mEfxA->setAirField(Vector3f(vel), true);
	}

	mEfxB = effectMgr->create(EffectMgr::EFF_Piki_FireSparkles, *parm.mPositionRef, this, nullptr);
	if (mEfxB) {
		mEfxB->setEmitPosPtr(parm.mPositionRef);
		Vector3f vel(*_0C);
		vel.y = 0.0f;
		vel.multiply(0.01f);
		mEfxB->setAirField(Vector3f(vel), true);
	}
}

void BurnEffect::kill()
{
	if (mEfxA) {
		effectMgr->kill(mEfxA, false);
		mEfxA = nullptr;
	}
	if (mEfxB) {
		effectMgr->kill(mEfxB, false);
		mEfxB = nullptr;
	}
}

bool BurnEffect::invoke(zen::particleGenerator*)
{
	return true;
}
