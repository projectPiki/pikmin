#include "PikiHeadItem.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "Graphics.h"
#include "Interactions.h"
#include "KEffect.h"
#include "KMath.h"
#include "MapMgr.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "SoundMgr.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(22)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("pikiheadItem")

void PikiHeadItem::startWaterEffect()
{
	EffectParm parm(&mSRT.t);
	mRippleEfx->emit(parm);
}

void PikiHeadItem::finishWaterEffect()
{
	mRippleEfx->kill();
}

void PikiHeadItem::playSound(int id)
{
	if (_3E0) {
		playEventSound(_3E0, id + 0xcc);
		return;
	}

	if (id > 0) {
		int sound = id + 0x108;
		seSystem->playPikiSound(sound, mSRT.t);
		PRINT("SEF_PIKI_GROW1 = %d / seIdx = %d\n", SEF_PIKI_GROW1, sound);
		seSystem->getJacID(sound);
		PRINT("play (idx=%d) Pikihead sound jac =%d/simz(dmg=%d grow1=%d)\n", id, sound, SE_PIKI_DAMAGED, 0x23);
	}
}

bool PikiHeadItem::canPullout()
{
	AState<AICreature>* state = getCurrState();
	u32 id                    = state ? state->getID() : -1;
	if (id - 6 <= 2) {
		return true;
	}
	return false;
}

bool PikiHeadItem::isVisible()
{
	return true;
}

bool PikiHeadItem::needShadow()
{
	AState<AICreature>* state = getCurrState();
	int id                    = state ? state->getID() : -1;
	if (id == 3 || id == 14 || (u32)(id - 11) <= 1) {
		return false;
	}
	return true;
}

bool PikiHeadItem::isAlive()
{
	return true;
}

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

void PikiHeadItem::startAI(int)
{
	startFix();
	_3E0 = nullptr;
	mItemAnimator.startMotion(PaniMotionInfo(PikiHeadMotion::TaneFall));

	f32 scale = 1.0f;
	mSRT.s.set(scale, scale, scale);

	enableAirResist(10.0f - (0.5f * gsys->getRand(1.0f)));

	C_SAI(this)->start(this, PikiHeadAI::PIKIHEAD_Wait);

	if (mSeedColor < PikiMinColor || mSeedColor > PikiMaxColor) {
		ERROR("set pikihead color before startAI\n");
	}

	GameStat::mePikis.inc(mSeedColor);
	GameStat::update();
	_3D4                  = mSRT.t;
	mFreeLightEfx->mColor = mSeedColor;
	EffectParm parm(&_3D4);
	mFreeLightEfx->emit(parm);
}

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

void PikiHeadItem::doKill()
{
	ItemCreature::doKill();
	GameStat::mePikis.dec(mSeedColor);
	GameStat::workPikis.inc(mSeedColor);
	GameStat::update();
	mFreeLightEfx->kill();
	_3E4.kill();
}

f32 PikiHeadItem::getSize()
{
	return 5.0f;
}

f32 PikiHeadItem::getiMass()
{
	return 50.0f;
}

void PikiHeadItem::setColor(int color)
{
	mSeedColor = color;
}

void PikiHeadItem::refresh(Graphics& gfx)
{
	f32 scale = 1.0f;
	mSRT.s.set(scale, scale, scale);
	f32 light = mapMgr->getLight(mSRT.t.x, mSRT.t.z);
	if (mItemShapeObject) {
		Matrix4f mtx;
		mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
		mItemShapeObject->mShape->mMaterialList->setColour(Piki::pikiColors[mSeedColor]);

		if (!isCreatureFlag(CF_IsOnGround) && mVelocity.length() > 0.0f) {
			Vector3f vel(mVelocity);
			vel.normalise();
			vel = vel * -1.0f;

			Vector3f zVel(0.0f, 0.0f, 1.0f);
			Vector3f xVel(vel);
			xVel.CP(zVel);
			xVel.normalise();

			zVel = xVel;
			zVel.CP(vel);
			zVel.normalise();

			makePostureMatrix(xVel, vel, zVel, mConstrainedMoveMtx);
			mConstrainedMoveMtx.setTranslation(mSRT.t);
			gfx.mCamera->mLookAtMtx.multiplyTo(mConstrainedMoveMtx, mtx);
		} else {
			gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
		}

		mItemAnimator.updateContext();
		mItemShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
		gfx.useMatrix(Matrix4f::ident, 0);
		mItemShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}

	gfx.useMatrix(mItemShapeObject->mShape->getAnimMatrix(3), 0);

	Vector3f leafGlowScale;
	if (mFlowerStage == Bud) {
		leafGlowScale.set(4.0f, 0.0f, 0.0f);
	} else if (mFlowerStage == Flower) {
		leafGlowScale.set(3.0f, 0.0f, 0.0f);
	} else {
		leafGlowScale.set(6.0f, 0.0f, 0.0f);
	}

	mFreeLightEfx->setScale(0.84f * mItemShapeObject->mShape->calcJointWorldPos(gfx, 3, leafGlowScale));
	_3D4 = leafGlowScale;

	pikiMgr->mLeafModel[mFlowerStage]->drawshape(gfx, *gfx.mCamera, nullptr);
}

bool PikiHeadItem::interactBikkuri(immut InteractBikkuri& act)
{
	PikiMgr::meBirthMode = true;
	Piki* piki           = (Piki*)pikiMgr->birth();
	PikiMgr::meBirthMode = false;

	if (piki) {
		Navi* navi = naviMgr->getNavi();
		piki->init(navi);
		piki->initColor(mSeedColor);
		piki->setFlower(mFlowerStage);
		piki->resetPosition(mSRT.t);

		PikiMgr::meNukiMode = true;
		piki->changeMode(PikiMode::FreeMode, nullptr);
		PikiMgr::meNukiMode = false;
		piki->mFSM->transit(piki, PIKISTATE_AutoNuki);

		kill(false);
		return true;
	}
	return false;
}

bool PikiHeadItem::interactSwallow(immut InteractSwallow& act)
{
	PikiMgr::meBirthMode = true;
	Piki* piki           = (Piki*)pikiMgr->birth();
	PikiMgr::meBirthMode = false;

	if (piki) {
		Navi* navi = naviMgr->getNavi();
		piki->init(navi);
		piki->initColor(mSeedColor);
		piki->setFlower(mFlowerStage);
		piki->resetPosition(mSRT.t);
		piki->mFSM->transit(piki, PIKISTATE_AutoNuki);
		kill(false);

		return act.actPiki(piki);
	}
	return false;
}
