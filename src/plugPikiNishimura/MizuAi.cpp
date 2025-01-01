#include "Mizu.h"
#include "EffectMgr.h"
#include "SoundMgr.h"
#include "NaviMgr.h"
#include "Interactions.h"
#include "NsMath.h"
#include "MapMgr.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("MizuAi");

/*
 * --INFO--
 * Address:	8017B858
 * Size:	000080
 */
MizuAi::MizuAi(Mizu* mizu)
{
	mMizu = mizu;
	_08 = _0C     = nullptr;
	mPuffCallBack = new MizuGenSpringPuffCallBack();
}

/*
 * --INFO--
 * Address:	8017B8D8
 * Size:	0000B8
 */
void MizuAi::initMizu(Mizu* mizu)
{
	mMizu = mizu;
	_0C   = effectMgr->create(EffectMgr::EFF_Unk194, mMizu->mPosition, nullptr, nullptr);
	_08   = effectMgr->create(EffectMgr::EFF_Unk193, mMizu->mPosition, nullptr, nullptr);
	mMizu->setCurrentState(0);
	mMizu->setNextState(0);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->setAnimTimer(30.0f);
	initWait(0);
}

/*
 * --INFO--
 * Address:	8017B990
 * Size:	0000B8
 */
void MizuAi::initGeyzer(Mizu* geyzer)
{
	mMizu = geyzer;
	_0C   = effectMgr->create(EffectMgr::EFF_Unk194, mMizu->mPosition, nullptr, nullptr);
	_08   = effectMgr->create(EffectMgr::EFF_Unk193, mMizu->mPosition, nullptr, nullptr);
	mMizu->setCurrentState(1);
	mMizu->setNextState(1);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->setAnimTimer(30.0f);
	initReady(1);
}

/*
 * --INFO--
 * Address:	8017BA48
 * Size:	000004
 */
void MizuAi::animationKeyUpdated(PaniAnimKeyEvent&) { }

/*
 * --INFO--
 * Address:	8017BA4C
 * Size:	00007C
 */
void MizuAi::killCallBackEffect(bool p1)
{
	if (_08) {
		_08->forceFinish();
		_08 = nullptr;
	}

	if (_0C) {
		_0C->forceFinish();
		_0C = nullptr;
	}

	effectMgr->killGenerator(mPuffCallBack, nullptr, p1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void MizuAi::setEveryFrame()
{
	Vector3f* vec      = mMizu->getInitPosition();
	mMizu->mPosition.x = vec->x;
	mMizu->mPosition.y = vec->y;
	mMizu->mPosition.z = vec->z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void MizuAi::naviGeyzerJump()
{
	Vector3f dir(sinf(mMizu->mDirection), 0.0f, cosf(mMizu->mDirection));
	dir.multiply(C_BOSS_PROP(mMizu).mTerritoryRadius());
	Vector3f targetPos = mMizu->mPosition + dir;
	targetPos.y        = mapMgr->getMinY(targetPos.x, targetPos.z, true);

	Navi* navi = naviMgr->getNavi();
	navi->stimulate(InteractGeyzer(mMizu, targetPos));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
bool MizuAi::readyTransit() { return (mMizu->getFlickDamageCount() >= C_BOSS_PROP(mMizu).mFlickDamageCountD()) ? true : false; }

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool MizuAi::jetTransit() { return mMizu->_3B8 ? true : false; }

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool MizuAi::waitTransit() { return (mMizu->get2D4() > 4.0f) ? true : false; }

/*
 * --INFO--
 * Address:	8017BAC8
 * Size:	0000BC
 */
void MizuAi::initWait(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->_3B8 = 1;
	mMizu->_3B9 = true;
	mMizu->setIsAlive(1);
	mMizu->setIsOrganic(1);
	mMizu->set2D4(0.0f);
	mMizu->setFlickDamageCount(0);
	if (_0C) {
		_0C->stop();
	}
	if (_08) {
		_08->stop();
	}
}

/*
 * --INFO--
 * Address:	8017BB84
 * Size:	0000D0
 */
void MizuAi::initReady(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->_3B8 = 0;
	mMizu->_3B9 = false;
	mMizu->setIsAlive(0);
	mMizu->setIsOrganic(0);
	mMizu->set2D4(0.0f);
	mMizu->setFlickDamageCount(0);
	if (_0C) {
		_0C->start();
	}
	if (_08) {
		_08->start();
	}

	if (mMizu->mSeContext) {
		mMizu->mSeContext->playSound(0xA8);
	}
}

/*
 * --INFO--
 * Address:	8017BC54
 * Size:	00026C
 */
void MizuAi::initJet(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(10, this));
	mMizu->_3B8 = 1;
	mMizu->_3B9 = false;
	mMizu->setIsAlive(false);
	mMizu->setIsOrganic(false);
	mMizu->set2D4(0.0f);
	mMizu->setFlickDamageCount(0);
	naviGeyzerJump();

	if (_0C) {
		_0C->stop();
	}

	if (_08) {
		_08->stop();
	}

	effectMgr->create(EffectMgr::EFF_Unk196, mMizu->mPosition, mPuffCallBack, nullptr);
	zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Unk195, mMizu->mPosition, nullptr, nullptr);
	mPuffCallBack->set(ptcl);
	if (ptcl) {
		ptcl->set1DC(Vector3f(1.0f, 0.0f, 0.0f));
	}

	effectMgr->create(EffectMgr::EFF_Unk197, mMizu->mPosition, nullptr, nullptr);

	if (mMizu->mSeContext) {
		mMizu->mSeContext->stopSound(0xA8);
		mMizu->mSeContext->playSound(0xA9);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void MizuAi::waitState() { }

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void MizuAi::readyState()
{
	if (!mMizu->_3B8) {
		Navi* navi = naviMgr->getNavi();
		f32 absX   = NsLibMath<f32>::abs(mMizu->mPosition.x - navi->mPosition.x);
		if (absX < 7.5f) {
			f32 absZ = NsLibMath<f32>::abs(mMizu->mPosition.z - navi->mPosition.z);
			if (absZ < 7.5f && NsLibMath<f32>::abs(mMizu->mPosition.y - navi->mPosition.y) < 10.0f) {
				mMizu->_3B8 = 1;
			}
		}

		if (mMizu->get2D4() > 3.0f) {
			mMizu->set2D4(0.0f);
			if (mMizu->mSeContext) {
				mMizu->mSeContext->playSound(0xA8);
			}
		} else {
			mMizu->add2D4(gsys->getFrameTime());
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void MizuAi::jetState() { mMizu->add2D4(gsys->getFrameTime()); }

/*
 * --INFO--
 * Address:	8017BEC0
 * Size:	000358
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
