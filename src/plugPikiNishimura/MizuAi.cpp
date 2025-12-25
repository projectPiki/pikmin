#include "DebugLog.h"
#include "EffectMgr.h"
#include "Interactions.h"
#include "MapMgr.h"
#include "Mizu.h"
#include "NaviMgr.h"
#include "NsMath.h"
#include "SoundMgr.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("MizuAi");

/**
 * @TODO: Documentation
 */
MizuAi::MizuAi(Mizu* mizu)
{
	mMizu = mizu;
	_08 = _0C     = nullptr;
	mPuffCallBack = new MizuGenSpringPuffCallBack();
}

/**
 * @TODO: Documentation
 */
void MizuAi::initMizu(Mizu* mizu)
{
	mMizu = mizu;
	_0C   = effectMgr->create(EffectMgr::EFF_Mizu_IdleMist, mMizu->mSRT.t, nullptr, nullptr);
	_08   = effectMgr->create(EffectMgr::EFF_Mizu_IdleBubbles, mMizu->mSRT.t, nullptr, nullptr);
	mMizu->setCurrentState(0);
	mMizu->setNextState(0);
	mMizu->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mMizu->setAnimTimer(30.0f);
	initWait(0);
}

/**
 * @TODO: Documentation
 */
void MizuAi::initGeyzer(Mizu* geyzer)
{
	mMizu = geyzer;
	_0C   = effectMgr->create(EffectMgr::EFF_Mizu_IdleMist, mMizu->mSRT.t, nullptr, nullptr);
	_08   = effectMgr->create(EffectMgr::EFF_Mizu_IdleBubbles, mMizu->mSRT.t, nullptr, nullptr);
	mMizu->setCurrentState(1);
	mMizu->setNextState(1);
	mMizu->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mMizu->setAnimTimer(30.0f);
	initReady(1);
}

/**
 * @TODO: Documentation
 */
void MizuAi::animationKeyUpdated(immut PaniAnimKeyEvent&)
{
}

/**
 * @TODO: Documentation
 */
void MizuAi::killCallBackEffect(bool doForceFinish)
{
	if (_08) {
		_08->forceFinish();
		_08 = nullptr;
	}

	if (_0C) {
		_0C->forceFinish();
		_0C = nullptr;
	}

	effectMgr->kill(mPuffCallBack, nullptr, doForceFinish);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00002C
 */
void MizuAi::setEveryFrame()
{
	Vector3f* vec   = mMizu->getInitPosition();
	mMizu->mSRT.t.x = vec->x;
	mMizu->mSRT.t.y = vec->y;
	mMizu->mSRT.t.z = vec->z;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000E4
 */
void MizuAi::naviGeyzerJump()
{
	Vector3f dir(sinf(mMizu->mFaceDirection), 0.0f, cosf(mMizu->mFaceDirection));
	dir.multiply(C_BOSS_PROP(mMizu).mTerritoryRadius());
	Vector3f targetPos = mMizu->mSRT.t + dir;
	targetPos.y        = mapMgr->getMinY(targetPos.x, targetPos.z, true);

	Navi* navi = naviMgr->getNavi();
	navi->stimulate(InteractGeyzer(mMizu, targetPos));
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
bool MizuAi::readyTransit()
{
	return (mMizu->getFlickDamageCount() >= C_BOSS_PROP(mMizu).mFlickDamageCountD()) ? true : false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
bool MizuAi::jetTransit()
{
	return mMizu->_3B8 ? true : false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
bool MizuAi::waitTransit()
{
	return (mMizu->getAttackTimer() > 4.0f) ? true : false;
}

/**
 * @TODO: Documentation
 */
void MizuAi::initWait(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mMizu->_3B8       = true;
	mMizu->mIsVisible = true;
	mMizu->setIsAlive(1);
	mMizu->setIsOrganic(1);
	mMizu->setAttackTimer(0.0f);
	mMizu->setFlickDamageCount(0);
	if (_0C) {
		_0C->stopGen();
	}
	if (_08) {
		_08->stopGen();
	}
}

/**
 * @TODO: Documentation
 */
void MizuAi::initReady(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mMizu->_3B8       = false;
	mMizu->mIsVisible = false;
	mMizu->setIsAlive(0);
	mMizu->setIsOrganic(0);
	mMizu->setAttackTimer(0.0f);
	mMizu->setFlickDamageCount(0);
	if (_0C) {
		_0C->startGen();
	}
	if (_08) {
		_08->startGen();
	}

	if (mMizu->mSeContext) {
		mMizu->mSeContext->playSound(SE_GEYSER_NORMAL);
	}
}

/**
 * @TODO: Documentation
 */
void MizuAi::initJet(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type1, this));
	mMizu->_3B8       = true;
	mMizu->mIsVisible = false;
	mMizu->setIsAlive(false);
	mMizu->setIsOrganic(false);
	mMizu->setAttackTimer(0.0f);
	mMizu->setFlickDamageCount(0);
	naviGeyzerJump();

	if (_0C) {
		_0C->stopGen();
	}

	if (_08) {
		_08->stopGen();
	}

	effectMgr->create(EffectMgr::EFF_Mizu_JetPuff, mMizu->mSRT.t, mPuffCallBack, nullptr);
	zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Mizu_JetStream, mMizu->mSRT.t, nullptr, nullptr);
	mPuffCallBack->set(ptcl);
	if (ptcl) {
		ptcl->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
	}

	effectMgr->create(EffectMgr::EFF_Mizu_JetMist, mMizu->mSRT.t, nullptr, nullptr);

	if (mMizu->mSeContext) {
		mMizu->mSeContext->stopSound(SE_GEYSER_NORMAL);
		mMizu->mSeContext->playSound(SE_GEYSER_SPOUT);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void MizuAi::waitState()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00011C
 */
void MizuAi::readyState()
{
	if (!mMizu->_3B8) {
		Navi* navi = naviMgr->getNavi();
		f32 absX   = NsLibMath<f32>::abs(mMizu->mSRT.t.x - navi->mSRT.t.x);
		if (absX < 7.5f) {
			f32 absZ = NsLibMath<f32>::abs(mMizu->mSRT.t.z - navi->mSRT.t.z);
			if (absZ < 7.5f && NsLibMath<f32>::abs(mMizu->mSRT.t.y - navi->mSRT.t.y) < 10.0f) {
				mMizu->_3B8 = true;
			}
		}

#if defined(VERSION_PIKIDEMO)
#else
		if (mMizu->getAttackTimer() > 3.0f) {
			mMizu->setAttackTimer(0.0f);
			if (mMizu->mSeContext) {
				mMizu->mSeContext->playSound(SE_GEYSER_NORMAL);
			}
		} else {
			mMizu->addAttackTimer(gsys->getFrameTime());
		}
#endif
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
void MizuAi::jetState()
{
	mMizu->addAttackTimer(gsys->getFrameTime());
}

/**
 * @TODO: Documentation
 */
void MizuAi::update()
{
	setEveryFrame();

	switch (mMizu->getCurrentState()) {
	case 0:
		waitState();
		if (readyTransit()) {
			initReady(1);
		}
		break;
	case 1:
		readyState();
		if (jetTransit()) {
			initJet(2);
		}
		break;
	case 2:
		jetState();
		if (waitTransit()) {
			initReady(1);
		}
		break;
	}
}
