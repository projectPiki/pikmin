#include "Navi.h"
#include "AIConstant.h"
#include "BombItem.h"
#include "CPlate.h"
#include "DebugLog.h"
#include "DoorItem.h"
#include "EffectMgr.h"
#include "FlowController.h"
#include "GameCoreSection.h"
#include "Generator.h"
#include "GlobalShape.h"
#include "GoalItem.h"
#include "Graphics.h"
#include "Interactions.h"
#include "Interface.h"
#include "ItemMgr.h"
#include "KIO.h"
#include "Kontroller.h"
#include "MapCode.h"
#include "MemStat.h"
#include "MoviePlayer.h"
#include "NaviMgr.h"
#include "NaviState.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "Pellet.h"
#include "Piki.h"
#include "PikiAI.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "Shape.h"
#include "SoundMgr.h"
#include "StateMachine.h"
#include "Stickers.h"
#include "UfoItem.h"
#include "UtEffect.h"
#include "WorkObject.h"
#include "gameflow.h"
#include "jaudio/piki_player.h"
#include "sysMath.h"
#include "sysNew.h"
#include "teki.h"
#include "zen/Math.h"

bool DelayPikiBirth = true;

static f32 controllerLen;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(89)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("navi");

/**
 * @todo: Documentation
 */
void Navi::viewDraw(Graphics& gfx, immut Matrix4f& mtx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mNaviAnimMgr.updateContext();
	mNaviShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	demoDraw(gfx, &mtx);
}

/**
 * @todo: Documentation
 */
void Navi::viewStartTrembleMotion(f32)
{
	mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_OCarry), PaniMotionInfo(PIKIANIM_OCarry));
}

/**
 * @todo: Documentation
 */
void Navi::viewKill()
{
	mSRT.t  = mPellet->mSRT.t;
	mPellet = nullptr;
}

/**
 * @todo: Documentation
 */
f32 Navi::viewGetBottomRadius()
{
	return 7.5f;
}

/**
 * @todo: Documentation
 */
f32 Navi::viewGetHeight()
{
	return 10.0f;
}

/**
 * @todo: Documentation
 */
bool Navi::isNuking()
{
	return mStateMachine->getCurrID(this) == NAVISTATE_Nuku;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00008C
 */
void Navi::startMovie(bool doStopEffects)
{
	int state = mStateMachine->getCurrID(this);
	if (doStopEffects) {
		mNaviLightEfx->stop();
		mNaviLightGlowEfx->stop();
	}

	if (state != NAVISTATE_DemoInf && state != NAVISTATE_Starting) {
		PRINT("************ NAVI => DEMO_WAIT STATE \n");
		mStateMachine->transit(this, NAVISTATE_DemoWait);
	}
}

/**
 * @todo: Documentation
 */
void Navi::startMovieInf()
{
	PRINT("************ NAVI => DEMO_INF STATE \n");
	mStateMachine->transit(this, NAVISTATE_DemoInf);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020
 */
bool Navi::movieMode()
{
	return (gameflow.mDemoFlags & GFDEMO_MovieMode) != 0;
}

/**
 * @todo: Documentation
 */
void Navi::incPlatePiki()
{
	mPlateMgr->mPlatePikiCount++;
}

/**
 * @todo: Documentation
 */
void Navi::decPlatePiki()
{
	mPlateMgr->mPlatePikiCount--;
}

/**
 * @todo: Documentation
 */
int Navi::getPlatePikis()
{
	return mPlateMgr->mPlatePikiCount;
}

/**
 * @todo: Documentation
 */
void Navi::startDayEnd()
{
	mIsDayEnd = TRUE;
}

/*
 * @note: 	100A1AD0 in plugPiki.dll
 */
void Navi::updateDayEnd(immut Vector3f& pos)
{
	if (mIsDayEnd) {
		mIsDayEnd = 0;

		mSRT.t          = pos;
		mDayEndPosition = pos;
		mPlateMgr->update();
		makeCStick(false);

		PRINT("********* UPDATE DAY END ** 1ST FRAME\n");
		PRINT("******** FORMATION =====================\n");

		Iterator iter(pikiMgr);
		int pikiCount = 0;
		CI_LOOP(iter)
		{
			Piki* piki = static_cast<Piki*>(*iter);
			piki->mFSM->transit(piki, PIKISTATE_Normal);

			if (piki->mMode != PikiMode::EnterMode) {
				piki->changeMode(PikiMode::FormationMode, piki->mNavi);
				piki->forceFinishLook();
				piki->startLook(&piki->mNavi->mSRT.t);
				pikiCount++;

				if (piki->mMode != PikiMode::FormationMode) {
					ERROR("nandeyanen!");
				}

				int slotID = ((ActCrowd*)piki->mActiveAction->getCurrAction())->mCPlateSlotID;
				if (slotID == -1) {
					ERROR("slotID = -1 desse\n");
				}

				// Issues here
				Vector3f slotPos = piki->mNavi->mPlateMgr->mSlotList[slotID].mOffsetFromCenter + piki->mNavi->mPlateMgr->mPlateCenter;
				piki->mSRT.t     = slotPos;
				piki->mSRT.t.y   = mapMgr->getMinY(piki->mSRT.t.x, piki->mSRT.t.z, true);
			}
		}

		PRINT("(( UPDATE DAY END)) %d pikis : formation\n", pikiCount);
		PRINT("** END IF\n");
	}

	mPlateMgr->update();
	mKontroller->mSubStickY = 0;
	mKontroller->mSubStickX = 0;

	makeCStick(false);

	mDayEndPosition = mSRT.t;
	mSRT.t          = pos;

	mVelocity  = pos - mDayEndPosition;
	f32 length = mVelocity.length();
	mVelocity.multiply(1.0f / gsys->getFrameTime());
}

/**
 * @todo: Documentation
 */
void Navi::enterAllPikis()
{
	// This has a capacity of 200 in the vanilla game for some reason.
	Piki* pikiList[MAX_PIKI_ON_FIELD == 100 ? 200 : MAX_PIKI_ON_FIELD];
	GoalItem* onyons[PikiColorCount];
	int i;
	for (i = 0; i < PikiColorCount; i++) {
		onyons[i] = itemMgr->getContainer(i);
	}

	for (i = 0; i < PikiColorCount; i++) {
		if (!onyons[i]) {
			char goalBuf[256];
			sprintf(goalBuf, "no goal (%d)", i);
			PRINT("no goal %d\n", i);
		}
	}

	int pikiCount = 0;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (piki->isAlive() && piki->mMode == PikiMode::FormationMode) {
			pikiList[pikiCount++] = piki;
		}
	}

	PRINT("#### enter pikis  : = %d \n", pikiCount);

	for (i = 0; i < pikiCount; i++) {
		if (pikiList[i]->mColor >= PikiColorCount) {
			PRINT("COLOR ID = %d\n", pikiList[i]->mColor);
			char colorBuf[256];
			sprintf(colorBuf, "COLOR %d !!", pikiList[i]->mColor);
			ERROR(colorBuf);
		}

		mGoalItem = onyons[pikiList[i]->mColor];
		if (mGoalItem) {
			if (pikiList[i]->getState() != PIKISTATE_Nukare) {
				pikiList[i]->changeMode(PikiMode::EnterMode, nullptr);
			}
		} else {
			PRINT("navi accesscontainer = 0\n");
		}
	}
}

/**
 * @todo: Documentation
 */
NaviProp::NaviProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.5f);
	mCreatureProps.mAcceleration(0.2f);
}

/**
 * @todo: Documentation
 */
bool Navi::isBuried()
{
	if (getCurrState()->getID() == NAVISTATE_Bury) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool Navi::isVisible()
{
	if (getCurrState()->getID() == NAVISTATE_Dead) {
		return false;
	}
	return true;
}

/**
 * @todo: Documentation
 */
bool Navi::isRopable()
{
	if (getCurrState()->getID() == NAVISTATE_RopeExit) {
		return false;
	}
	return true;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00008C
 */
bool Navi::startDamage()
{
	int stateID      = mStateMachine->getCurrID(this);
	NaviState* state = mStateMachine->getNaviState(this);
	if (state->invincible(this)) {
		return false;
	}

	startDamageEffect();
	setStateDamaged();
	mStateMachine->resume(this);
	return true;
}

/**
 * @todo: Documentation
 */
void Navi::startDamageEffect()
{
	CollPart* part = mCollInfo->getSphere('cent');
	if (!part) {
		return;
	}

	if (mHealth <= 1.0f) {
		gameflow.mGameInterface->message(MOVIECMD_SetInputEnabled, FALSE);
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);

	} else if (!gameflow.mMoviePlayer->mIsActive && mHealth <= 0.25f * NAVI_PROP.mHealth()
	           && !playerState->mDemoFlags.isFlag(DEMOFLAG_OlimarLowHealth)) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_OlimarLowHealth);
		gameflow.mGameInterface->message(MOVIECMD_TextDemo, 24);
	}

	zen::particleGenerator* ptclGenA = effectMgr->create(EffectMgr::EFF_Navi_DamageA, part->mCentre, nullptr, nullptr);
	zen::particleGenerator* ptclGenB = effectMgr->create(EffectMgr::EFF_Navi_DamageB, part->mCentre, nullptr, nullptr);
	if (ptclGenB) {
		ptclGenB->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	zen::particleGenerator* ptclGenC = effectMgr->create(EffectMgr::EFF_Navi_DamageC, part->mCentre, nullptr, nullptr);
	if (ptclGenC) {
		ptclGenC->setEmitPosPtr(&part->mCentre);
	}

	mDamageEfxA = ptclGenA;
	mDamageEfxB = ptclGenB;
	mDamageEfxC = ptclGenC;

	int vibTypes[2] = { 0, 1 };
	f32 randIdx     = gsys->getRand(1.0f);
	// int vib         = vibTypes[int(2.0f * randIdx * 0.9999999f)];
	cameraMgr->startVibrationEvent(vibTypes[int(2.0f * randIdx * 0.9999999f)], mSRT.t);

	SeSystem::playPlayerSe(SE_DAMAGED);
}

/**
 * @todo: Documentation
 */
void Navi::finishDamage()
{
	resetStateDamaged();
	mStateMachine->restart(this);

	if (mHealth <= 1.0f) {
		mStateMachine->transit(this, NAVISTATE_Dead);
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
	} else {
		if (!gameflow.mMoviePlayer->mIsActive && mHealth <= 0.25f * NAVI_PROP.mHealth()
		    && !playerState->mDemoFlags.isFlag(DEMOFLAG_OlimarLowHealth)) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_OlimarLowHealth);
			gameflow.mGameInterface->message(MOVIECMD_TextDemo, 24);
		}
	}

	mDamageEfxA = mDamageEfxB = mDamageEfxC = nullptr;
}

/**
 * @todo: Documentation
 */
Navi::Navi(CreatureProp* props, int naviID)
    : Creature(props)
{
	_700 = 4;
	memStat->start("naviCaster");
	mShadowCaster.initCore("");
	mShadowCaster.mDrawer           = new NaviDrawer(this);
	mShadowCaster.mLightCamera.mFov = 20.0f;
	memStat->end("naviCaster");

	memStat->start("naviEff");
	mBurnEffect       = new BurnEffect(&mVelocity);
	mRippleEffect     = new RippleEffect();
	mNaviLightEfx     = new PermanentEffect();
	mNaviLightGlowEfx = new PermanentEffect();
	_77C              = new PermanentEffect();
	_780              = new PermanentEffect();
	mSlimeEffect      = new SlimeEffect();
	memStat->end("naviEff");

	mPlateMgr        = nullptr;
	_AD8             = 0.0f;
	mNaviID          = naviID;
	_ACC             = false;
	_AD0             = 0;
	mNeutralTime     = 0.0f;
	_718             = false;
	_720             = 0;
	_71C             = 0;
	mCurrState       = nullptr;
	mNaviShapeObject = naviMgr->mNaviShapeObject[mNaviID];
	mCollInfo        = new CollInfo(5);
	mCollInfo->initInfo(mNaviShapeObject->mShape, nullptr, nullptr);
	mNaviAnimMgr.init(mNaviShapeObject->mAnimMgr, &mNaviShapeObject->mAnimatorB, &mNaviShapeObject->mAnimatorA, naviMgr->mMotionTable);
	_ABC    = 0;
	_AB8    = 0.0f;
	_AC4    = 0.0f;
	mHealth = static_cast<NaviProp*>(props)->mNaviProps.mHealth();

	mDayEndPosition.set(0.0f, 0.0f, 0.0f);
	_814 = 0.0f;
	_818 = 1.0f;
	_810 = 0;
	_80C = 0;
	startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));

	f32 s = 1.0f;
	mSRT.s.set(s, s, s);
	mSRT.r.set(0.0f, 0.0f, 0.0f);
	mSRT.t.set(0.0f, 0.0f, 0.0f);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_268        = 0.0f;
	mKontroller = new Kontroller(naviID + 1);
	mSize       = 20.0f;

	memStat->start("naviStateM");
	mStateMachine = new NaviStateMachine();
	mStateMachine->init(this);
	memStat->end("naviStateM");

	_828 = 0;
	_724 = false;
	_800 = 0.0f;
	_7FC = false;
	_928 = 0;
	resetCreatureFlag(CF_Unk1 | CF_DisableAutoFaceDir);
	mObjType = OBJTYPE_Navi;
	mSearchBuffer.init(mNaviSearchData, 6);

	_72C          = 0;
	_730          = 0;
	mCurrKeyCount = 0;
	_7D8.clear();
	_770 = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F8
 */
void Navi::Locus::update()
{
	// UNUSED FUNCTION (matching by size)
	f32 time = gsys->getFrameTime() * 2.4f;
	_00      = _00 + _0C * time;
	_18.updatePos(_00);
	if (_00.y < mapMgr->getMinY(_00.x, _00.z, true)) {
		_28 = 1;
		_18.kill();
	}
	_0C.y -= AIConstant::_instance->mConstants.mGravity() * time;
}

/**
 * @todo: Documentation
 */
void Navi::startKontroller()
{
	if (KIO::kontMode == KONT_Save) {
		mKontroller->save(controllerBuffer, 900);
		return;
	}

	if (KIO::kontMode == KONT_Load) {
		mKontroller->load(controllerBuffer, 900);
	}
}

/**
 * @todo: Documentation
 */
void Navi::rideUfo()
{
	mIsRidingUfo = true;
	mNaviLightEfx->kill();
	mNaviLightGlowEfx->kill();
}

/**
 * @todo: Documentation
 */
void Navi::reset()
{
	mDamageEfxA = mDamageEfxB = mDamageEfxC = nullptr;
	_304                                    = 0;
	_2F4                                    = 0.0f;
	_2F8                                    = 0.0f;
	enableFixPos();
	_830         = false;
	mIsRidingUfo = false;
	setPellet(false);
	mLookAtPosPtr     = nullptr;
	mIsPlucking       = false;
	mFastPluckKeyTaps = false;
	_2FC              = nullptr;
	_300              = 0.0f;
	mIsInWater        = false;
	_30C              = 0;
	mIsCursorVisible  = FALSE;
	_6FC              = 1;
	_700              = 5;
	_79C.set(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 32; i++) {
		_938[i].set(0.0f, 0.0f, 0.0f);
	}

	GlobalShape::cursorShape->makeInstance(mNaviDynMats, 0);

	_70C = false;
	mStateMachine->transit(this, NAVISTATE_Walk);
	mPlateMgr = new CPlate(mapMgr);

	_719 = false;
	mPlateMgr->init(mSRT.t);
	_7B4         = 0;
	mWallCollObj = nullptr;
	mAiTickTimer = 0.0f;
	mNaviLightPosition.set(0.0f, 0.0f, 0.0f);
	_724 = false;

	f32 dist = (NAVI_PROP._38C() + NAVI_PROP._39C()) * 0.5f;
	mCursorPosition.set(dist * sinf(mFaceDirection), 0.0f, dist * cosf(mFaceDirection));
	mCursorNaviDist       = mCursorPosition.length();
	mCursorTargetPosition = mCursorPosition;
	mCursorWorldPos.set(0.0f, 0.0f, 0.0f);
	_7DC           = mFaceDirection;
	mNextThrowPiki = nullptr;
	mNaviLightEfx->changeEffect(EffectMgr::EFF_Navi_Light);
	mNaviLightGlowEfx->changeEffect(EffectMgr::EFF_Navi_LightGlow);
}

/**
 * @todo: Documentation
 */
f32 Navi::getSize()
{
	return NAVI_PROP._1FC();
}

/**
 * @todo: Documentation
 */
f32 Navi::getiMass()
{
	int stateID = mStateMachine->getCurrID(this);
	if (stateID == NAVISTATE_Nuku || stateID == NAVISTATE_NukuAdjust) {
		return 0.0f;
	}

	if (stateID == NAVISTATE_Dead) {
		return 1.0f;
	}

	return NAVI_PROP._21C();
}

/**
 * @todo: Documentation
 */
void Navi::findNextThrowPiki()
{
	mNextThrowPiki = nullptr;
	Iterator iter(mPlateMgr);
	f32 minDist = 200.0f;
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (roughCull(this, piki, minDist)) {
			continue;
		}

		f32 dist = qdist2(piki, this);
		if (dist < minDist && piki->getState() == PIKISTATE_Normal && piki->isThrowable()) {
			mNextThrowPiki = piki;
			minDist        = dist;
		}
	}
}

/**
 * @todo: Documentation
 */
void Navi::startMotion(immut PaniMotionInfo& motion1, immut PaniMotionInfo& motion2)
{
	mNaviAnimMgr.startMotion(motion1, motion2);
	mPreBlendLowerMotionID = -1;
}

/**
 * @todo: Documentation
 */
void Navi::enableMotionBlend()
{
	mPreBlendLowerMotionID = mNaviAnimMgr.getLowerAnimator().getCurrentMotionIndex();
	mNaviAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(PIKIANIM_Nigeru));
	mNaviAnimMgr.getLowerAnimator().mAnimationCounter = 10.0f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
bool Navi::doMotionBlend()
{
	return mPreBlendLowerMotionID != -1;
}

/**
 * @todo: Documentation
 */
void Navi::updateWalkAnimation()
{
	mCollisionRadius  = NAVI_PROP._20C();
	Vector3f sep      = mSRT.t - _79C;
	sep.y             = 0.0f;
	f32 speed         = sep.length() / gsys->getFrameTime();
	int lowerMotionID = mNaviAnimMgr.getLowerAnimator().getCurrentMotionIndex();
	if (_30) {
		speed = 0.0f;
	}

	if (mRope) {
		return;
	}

	if (lowerMotionID != PIKIANIM_Wait && lowerMotionID != PIKIANIM_Walk && lowerMotionID != PIKIANIM_Asibumi
	    && lowerMotionID != PIKIANIM_Run && lowerMotionID != PIKIANIM_Nigeru) {
		if (!mRope) {
			mMotionSpeed = 30.0f;
		}
		return;
	}

	f32 angle      = absF(mFaceDirection - _7DC);
	Navi* listener = nullptr;
	int newMotionID;
	if (speed < NAVI_PROP._23C()) {
		newMotionID = PIKIANIM_Wait;
		if (angle > 0.01f) {
			newMotionID = PIKIANIM_Asibumi;
		}
		speed = 30.0f;

	} else if (speed < NAVI_PROP._24C()) {
		newMotionID = PIKIANIM_Asibumi;
		speed       = 30.0f;

	} else if (speed < NAVI_PROP._25C()) {
		newMotionID = PIKIANIM_Walk;
		listener    = this;
		f32 ratio   = (speed - NAVI_PROP._24C()) / (NAVI_PROP._25C() - NAVI_PROP._24C());
		speed       = NAVI_PROP._27C() + (NAVI_PROP._28C() - NAVI_PROP._27C()) * ratio;

	} else if (speed < NAVI_PROP._26C()) {
		newMotionID = PIKIANIM_Run;
		listener    = this;
		f32 ratio   = (speed - NAVI_PROP._25C()) / (NAVI_PROP._26C() - NAVI_PROP._25C());
		speed       = NAVI_PROP._29C() + (NAVI_PROP._2AC() - NAVI_PROP._29C()) * ratio;

	} else {
		speed       = NAVI_PROP._2BC();
		listener    = this;
		newMotionID = PIKIANIM_Nigeru;
	}

	if (newMotionID != lowerMotionID) {
		if (lowerMotionID == PIKIANIM_Wait && newMotionID != PIKIANIM_Asibumi) {
			_700 = 4;
		}

		if (lowerMotionID != PIKIANIM_Asibumi && newMotionID == PIKIANIM_Wait) {
			_700 = 4;
		}

		if (newMotionID != _6FC) {
			_700 = 0;
			_6FC = newMotionID;
		} else {
			_700++;
		}

		if (_700 < 4) {
			return;
		}
	}

	if (lowerMotionID != newMotionID) {
		if (lowerMotionID == PIKIANIM_Wait || lowerMotionID == PIKIANIM_Asibumi || newMotionID == PIKIANIM_Wait
		    || newMotionID == PIKIANIM_Asibumi) {
			if (!doMotionBlend()) {
				startMotion(PaniMotionInfo(newMotionID), PaniMotionInfo(newMotionID, listener));
			} else {
				mNaviAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(newMotionID, listener));
			}
		} else if (!doMotionBlend()) {

			swapMotion(PaniMotionInfo(newMotionID), PaniMotionInfo(newMotionID, listener));
		} else {
			f32 lowerCounter = mNaviAnimMgr.getLowerAnimator().mAnimationCounter;
			mNaviAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(newMotionID, listener));
			mNaviAnimMgr.getLowerAnimator().mAnimationCounter = lowerCounter;
		}
	}

	mMotionSpeed = speed;
}

/**
 * @todo: Documentation
 */
void Navi::postUpdate(int unused, f32 deltaTime)
{
	if (!movieMode()) {
		Creature::postUpdate(unused, deltaTime);
	}
}

/**
 * @todo: Documentation
 */
void Navi::update()
{
	if (!mGroundTriangle) {
		f32 maxY = mapMgr->getMaxY(mSRT.t.x, mSRT.t.z, true);
		if (maxY > mSRT.t.y) {
			PRINT("navi(%.1f %.1f %.1f) : map(%.1f %.1f %.1f)\n", mSRT.t.x, mSRT.t.y, mSRT.t.z, mSRT.t.x, maxY, mSRT.t.z);
			PRINT("mapY %.1f srt.t.y %.1f\n", maxY, mSRT.t.y);
			PRINT("navi almost fall !\n");
			mSRT.t.y = maxY;
		}
	}

	_2FC = nullptr;
	if (movieMode()) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (mIsPlucking) {
		int state = mStateMachine->getCurrID(this);
		if (state != NAVISTATE_Nuku && state != NAVISTATE_NukuAdjust) {
			mNoPluckTimer++;
			if (mNoPluckTimer > NAVI_PROP.mPostPluckZoomOutTime()) {
				mIsPlucking       = false;
				mFastPluckKeyTaps = 0;
				PRINT_GLOBAL("< camera FINISH MOTION");
				cameraMgr->mCamera->finishMotion();
				cameraMgr->mCamera->mControlsEnabled = true;
				mNoPluckTimer                        = 0;
			}
		}
	}

	int attr = ATTR_NULL;
	if (mGroundTriangle) {
		attr = MapCode::getAttribute(mGroundTriangle);
	}

	if (attr == ATTR_Water) {
		if (!mIsInWater) {
			// we just moved into water, create ripple effects
			EffectParm rippleParm(&mSRT.t);
			EffectParm castParm(mSRT.t);
			mRippleEffect->emit(rippleParm);
			UtEffectMgr::cast(KandoEffect::Bubbles, castParm);
			SeSystem::playPlayerSe(SE_PIKI_WATERDROP);
		}
		mIsInWater = true;
	} else {
		if (mIsInWater) {
			mIsInWater = false;
			mRippleEffect->kill();
		}
		// make DOUBLY sure this is set false.
		mIsInWater = false;
	}

	mNaviDynMats.animate(nullptr);

	Vector3f cursorMoveDir = mCursorTargetPosition - mCursorPosition;
	f32 cursorMoveDist     = cursorMoveDir.normalise();
	if (cursorMoveDist > 0.0f) {
		f32 moveDist = gsys->getFrameTime() * NAVI_PROP._3AC();
		if (moveDist > cursorMoveDist) {
			moveDist = cursorMoveDist;
		}

		mCursorPosition = mCursorPosition + moveDist * cursorMoveDir;
	}

	mPlateMgr->update();
	updateWalkAnimation();
	_79C = mSRT.t;
	mNaviAnimMgr.updateAnimation(mMotionSpeed);

	STACK_PAD_VAR(1);

	// Game freeze keybind? This has to be excluded from release because it inflates the stack a LOT.
#ifdef WIN32
	if (mKontroller->keyClick(KBBTN_R) && mKontroller->keyDown(KBBTN_B) && mKontroller->keyDown(KBBTN_A)) {
		// flip a debug flag
	}

	// if some other debug flag is true and debug flag is false, flip them both

	if (mKontroller->keyClick(KBBTN_Z)) { // && debug flag
		// other debug flag = true
		// debug flag = false
		int id = getCurrState()->getID();
		PRINT("---- game frozen : naviState %d\n", id);
	}
#endif

	mKontroller->update();
	_7DC = mFaceDirection;
	Creature::update();

	mapMgr->updatePos(mSRT.t.x, mSRT.t.z);

	Vector3f dayEndSep = mDayEndPosition - mSRT.t;
	if (dayEndSep.length() > 35.0f && mGroundTriangle) {
		Vector3f parmPos(mSRT.t.x, mSRT.t.y + 1.0f, mSRT.t.z);

		Vector3f parmVel(0.01667f * mVelocity.x, 2.0f, 0.01667f * mVelocity.z);
		int effAttr = MapCode::getAttribute(mGroundTriangle);
		if (effAttr >= ATTR_Solid && effAttr <= ATTR_Wood) {
			EffectParm parm(parmPos, parmVel);
			UtEffectMgr::cast(effAttr + KandoEffect::SmokeOffset, parm);
			mDayEndPosition = mSRT.t;
		}
	}
}

/**
 * @todo: Documentation
 */
void Navi::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	// sure kando.
	int lowerMotionID = mNaviAnimMgr.getLowerAnimator().getCurrentMotionIndex();
	int upperMotionID = mNaviAnimMgr.getUpperAnimator().getCurrentMotionIndex();
	if (event.mEventType == KEY_PlaySound) {
		int attr = ATTR_Solid;
		if (mGroundTriangle) {
			attr = MapCode::getAttribute(mGroundTriangle);
		}
		int soundType;
		switch (attr) {
		case ATTR_Solid:
			soundType = 1;
			break;
		case ATTR_Rock:
			soundType = 3;
			break;
		case ATTR_Grass:
			soundType = 0;
			break;
		case ATTR_Wood:
			soundType = 2;
			break;
		case ATTR_Water:
			soundType = 4;
			break;
		case ATTR_Mud:
			soundType = 5;
			break;
		default:
			soundType = 1;
			break;
		}

		Jac_Orima_Walk(soundType, 0);
	}

	MsgAnim msg(&event);
	sendMsg(&msg);

	if (isDamaged() && event.mEventType == KEY_Finished) {
		PRINT("finish damage\n");
		finishDamage();
	}
}

/**
 * @todo: Documentation
 */
void Navi::callPikis(f32 radius)
{
	Vector3f unused = mCursorWorldPos - mSRT.t;
	STACK_PAD_VAR(4);

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Piki* piki = static_cast<Piki*>(*iterPiki);
		if (!piki->isAlive()) {
			continue;
		}

		Vector3f sep = piki->mSRT.t - mCursorWorldPos;
		f32 dist     = speedy_sqrtf(sep.x * sep.x + sep.z * sep.z);
		if (dist >= radius) {
			continue;
		}

		int state = piki->getState();
		if (state == PIKISTATE_Drown) {
			static_cast<PikiDrownState*>(piki->getCurrState())->mIsBeingWhistled = true;
			PRINT("call drown piki\n");
		} else if (state == PIKISTATE_Flick) {
			static_cast<PikiFlickState*>(piki->getCurrState())->mGetUpTimer = 0.0f;
		} else if (state == PIKISTATE_Flown) {
			static_cast<PikiFlownState*>(piki->getCurrState())->_10 = 0.0f;
		}

		if ((piki->mNavi == this || piki->mNavi == nullptr) && !piki->isKinoko() && piki->isAlive() && !piki->isBuried()
		    && (piki->mMode != PikiMode::FormationMode || piki->getState() == PIKISTATE_Emotion) && piki->mIsCallable
		    && state != PIKISTATE_Nukare && state != PIKISTATE_Swallowed && state != PIKISTATE_Drown && state != PIKISTATE_Absorb
		    && state != PIKISTATE_LookAt && state != PIKISTATE_Pressed && dist < radius) {
			if (!piki->isDamaged() && state != PIKISTATE_Flick && state != PIKISTATE_GrowUp) {
				if (piki->isFired() && piki->mColor != Red) {
					piki->endFire();
				}

				piki->mNavi = this;
				if (state == PIKISTATE_Emotion) {
					static_cast<PikiEmotionState*>(piki->getCurrState())->mCheerCount = 0;
				}

				if (piki->mMode == PikiMode::PutbombMode && piki->isHolding()) {
					InteractRelease release(piki, 1.0f);
					Creature* held = piki->getHoldCreature();
					held->stimulate(release);
					MsgUser msg(0);
					BombItem* bomb = static_cast<BombItem*>(held);
					C_SAI(bomb)->procMsg(bomb, &msg);
				}

				piki->mFSM->transit(piki, PIKISTATE_LookAt);
			} else {
				piki->mNavi             = this;
				piki->mIsWhistlePending = true;
			}

		} else if (dist < radius && piki->mMode != PikiMode::FormationMode) {
			piki->getState();
		}

		if (AIConstant::_instance->mConstants.mDoPluckWithCursor() && (mNaviID == piki->mPlayerId || piki->mPlayerId == -1)
		    && piki->isBuried() && piki->getState() == PIKISTATE_Bury && dist < radius) {
			piki->mNavi = this;
			piki->mFSM->transit(piki, PIKISTATE_AutoNuki);
			// Why would you put an `ERROR` here?  Just don't enable it??
			TERNARY_BUGFIX(, ERROR("cursor nuki!\n"));
		}
	}

	Iterator iterSprout(itemMgr->getPikiHeadMgr());
	CI_LOOP(iterSprout)
	{
		Creature* maybeSprout = *iterSprout;
		if (maybeSprout->mObjType == OBJTYPE_Pikihead) {
			PikiHeadItem* sprout = static_cast<PikiHeadItem*>(maybeSprout);
			Vector3f sproutSep   = maybeSprout->mSRT.t - mCursorWorldPos;
			f32 sproutDist       = speedy_sqrtf(sproutSep.x * sproutSep.x + sproutSep.z * sproutSep.z);
			if (!AIConstant::_instance->mConstants.mDoPluckWithCursor()) {
				continue;
			}

			if (sprout->canPullout() && sproutDist < radius) {
				// Why would you put an `ERROR` here?  Just don't enable it??
				TERNARY_BUGFIX(, ERROR("cursor nuki!\n"));
				PikiMgr::meBirthMode = true;
				Piki* piki           = static_cast<Piki*>(pikiMgr->birth());
				PikiMgr::meBirthMode = false;

				if (piki) {
					piki->init(this);
					piki->initColor(sprout->mSeedColor);
					piki->setFlower(sprout->mFlowerStage);
					piki->resetPosition(sprout->mSRT.t);
					piki->mFSM->transit(piki, PIKISTATE_AutoNuki);
					sprout->kill(false);
				}
			}
		}
	}

	if (!tekiMgr) {
		return;
	}

	Iterator iterTeki(tekiMgr);
	CI_LOOP(iterTeki)
	{
		Creature* teki   = *iterTeki;
		Vector3f tekiSep = teki->mSRT.t - mCursorWorldPos;
		f32 tekiDist     = speedy_sqrtf(tekiSep.x * tekiSep.x + tekiSep.z * tekiSep.z);
		if (teki->isAlive() && teki->isVisible() && tekiDist < radius) {
			InteractFlute flute(this);
			teki->stimulate(flute);
		}
	}
}

/**
 * @todo: Documentation
 */
void Navi::callDebugs(f32 radius)
{
	Iterator iterPiki(pikiMgr);
	int pikiCount = 0;
	CI_LOOP(iterPiki)
	{
		Piki* piki       = static_cast<Piki*>(*iterPiki);
		Vector3f pikiSep = piki->mSRT.t - mCursorWorldPos;
		f32 tekiDist     = pikiSep.length();
		if (tekiDist < radius) {
			if (pikiCount == 0) {
				PRINT("--------------- PIKI INFO ------------------\n");
			}
			Piki::directDumpMode = true;
			piki->dump();
			Piki::directDumpMode = false;
			pikiCount++;
		}
	}

	int tekiCount = 0;
	Iterator iterTeki(tekiMgr);
	CI_LOOP(iterTeki)
	{
		Creature* teki   = *iterTeki;
		Vector3f tekiSep = teki->mSRT.t - mCursorWorldPos;
		f32 tekiDist     = tekiSep.length();
		if (tekiDist < radius) {
			if (tekiCount == 0) {
				PRINT("--------------- TEKI INFO ------------------\n");
			}
			teki->dump();
			tekiCount++;
		}
	}
}

/**
 * @brief Releases the Pikmin from the Navi's control and organizes them by color.
 *
 * This function iterates through the Pikmin managed by the Navi, filters out those that are not in a releasable state,
 * and then organizes the remaining Pikmin by their color. It calculates the center of mass and size for each color group,
 * adjusts their positions to avoid overlap, and finally changes their mode to FreeMode.
 *
 * @dor, and bomb-carrying Pikmin are treated as aetails
 * - Pikmin that are dead, dying, or in certain states are not considered for release.
 * - Pikmin are grouped by their col separate group.
 * - The center of mass and size for each color group are calculated.
 * - The positions of the color groups are adjusted to avoid overlap with the Navi and with each other.
 * - The mode of each Pikmin is changed to FreeMode, and their positions are updated based on the calculated center of mass and size.
 *
 * @note
 * - The function assumes a maximum of 200 Pikmin can be managed at a time.
 * - The function uses several constants and enumerations such as PikiColorCount, PikiMode, and PIKISTATE_*.
 * - The function modifies the Pikmin's active action to ActFree and initializes their boid behavior.
 */
void Navi::releasePikis()
{
	Iterator iter(mPlateMgr);
	// This has a capacity of 200 in the vanilla game for some reason.
	Piki* pikiList[MAX_PIKI_ON_FIELD == 100 ? 200 : MAX_PIKI_ON_FIELD];
	int pikiCount = 0;
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		int state  = piki->getState();
		if (piki->isAlive() && piki->mMode != PikiMode::FreeMode && state != PIKISTATE_GrowUp && state != PIKISTATE_Absorb
		    && state != PIKISTATE_Swallowed && state != PIKISTATE_LookAt && state != PIKISTATE_Dying && state != PIKISTATE_Dead
		    && state != PIKISTATE_Nukare && state != PIKISTATE_NukareWait && state != PIKISTATE_Pressed && state != PIKISTATE_Drown
		    && state != PIKISTATE_KinokoChange && state != PIKISTATE_Flick && !piki->isKinoko() && piki->isAIActive()) {
			pikiList[pikiCount++] = static_cast<Piki*>(*iter);
		}
	}

	if (!pikiCount) {
		// no pikis to dismiss
		return;
	}
	Vector3f colorCoMs[PikiColorCount + 1]; // each color + bomb-carriers
	int colorCounts[PikiColorCount + 1];    // each color + bomb-carriers
	f32 colorSizes[PikiColorCount + 1];
	int j, i;
	for (i = 0; i < PikiColorCount + 1; i++) {
		colorCoMs[i].set(0.0f, 0.0f, 0.0f);
		colorCounts[i] = 0;
	}

	for (i = 0; i < PikiColorCount + 1; i++) {
		for (j = 0; j < pikiCount; j++) {
			if (i == Blue || i == Red) {
				if (i == pikiList[j]->mColor) {
					colorCounts[i]++;
					colorCoMs[i].add(pikiList[j]->mSRT.t);
				}
			} else {
				if (pikiList[j]->mColor == Yellow) {
					if (pikiList[j]->hasBomb()) {
						colorCounts[3]++;
						colorCoMs[3].add(pikiList[j]->mSRT.t);
					} else {
						colorCounts[Yellow]++;
						colorCoMs[Yellow].add(pikiList[j]->mSRT.t);
					}
				}
			}
		}
	}

	for (i = 0; i < PikiColorCount + 1; i++) {
		if (colorCounts[i] > 0) {
			colorCoMs[i].multiply(1.0f / colorCounts[i]);
			colorSizes[i] = (2.5f * pikiList[0]->getSize()) * std::sqrtf(colorCounts[i]);
		}
	}

	for (int i = 0; i < PikiColorCount + 1; i++) {
		if (colorCounts[i] > 0) {
			Vector3f sepNaviGroup = colorCoMs[i] - mSRT.t;
			f32 dist              = sepNaviGroup.normalise() - colorSizes[i] - 15.0f;
			if (dist < 18.0f) {
				dist = 18.0f - dist;
				Vector3f offsetFromNavi;
				offsetFromNavi = dist * sepNaviGroup;
				colorCoMs[i].add(offsetFromNavi);
			}
		}

		for (int j = i + 1; j < PikiColorCount + 1; j++) {
			if (colorCounts[i] > 0 && colorCounts[j] > 0) {
				Vector3f colorColorSep = colorCoMs[i] - colorCoMs[j];
				f32 colorDist          = colorColorSep.normalise() - colorSizes[i] - colorSizes[j];
				if (colorDist < 18.0f) {
					colorDist = (18.0f - colorDist);
					Vector3f interColorOffset;
					interColorOffset = colorDist * colorColorSep;
					colorCoMs[i].add(interColorOffset);
					colorCoMs[j].sub(interColorOffset);
				}
			}
		}
	}

	for (i = 0; i < pikiCount; i++) {
		pikiList[i]->changeMode(PikiMode::FreeMode, this);
		int color = pikiList[i]->mColor;
		if (pikiList[i]->hasBomb()) {
			color = 3;
		}

		ActFree* action = static_cast<ActFree*>(pikiList[i]->mActiveAction->getCurrAction());
		action->initBoid(colorCoMs[color], colorSizes[color]);
		if (flowCont.mNaviOnMap == 1 && pikiList[i]->mPlayerId == -1) {
			pikiList[i]->mNavi = nullptr;
		}
	}

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void Navi::doAI()
{
	if (gameflow.mDemoFlags & GFDEMO_MovieMode) {
		return;
	}

	mAiTickTimer -= gsys->getFrameTime();
	if (mAiTickTimer <= 0.0f) {
		if (_7B4 == 0) {
			offwallCallback(mWallCollObj);
			mWallCollObj = nullptr;
			mAiTickTimer = 0.0f;
		} else {
			mAiTickTimer = 0.1f;
		}
	}

	mStateMachine->exec(this);
	_7B4 = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00008C
 */
void Navi::doAttack()
{
	Creature* target = _7D8.getPtr();
	InteractAttack attack(this, nullptr, 1.0f, false);
	target->stimulate(attack);
	_7D8.reset();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
bool Navi::insideOnyon()
{
	for (int i = 0; i < PikiColorCount; i++) {
		GoalItem* onyon = itemMgr->getContainer(i);
		if (onyon) {
			f32 xDiff = onyon->mSRT.t.x - mSRT.t.x;
			f32 zDiff = onyon->mSRT.t.z - mSRT.t.z;
			f32 sqrXZ = xDiff * xDiff + zDiff * zDiff;

			if (sqrXZ <= SQUARE(220.0f)) {
				return true;
			}
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */

bool Navi::procActionButton()
{
	// can't fix this with stack alone - needs 0x8 more stack from inlines :(
	STACK_PAD_VAR(2);

	// ACCESS UFO PART INFO - see if there's a ufo part for us to interact with
	// int naviState = getCurrState()->getID();

	if (getCurrState()->getID() == NAVISTATE_Walk) {
		Iterator iter(pelletMgr);
		CI_LOOP(iter)
		{
			Pellet* pellet = static_cast<Pellet*>(*iter);
			if (pellet->mConfig->mPelletType() == PELTYPE_UfoPart && pellet->onGround() && pellet->getState() == 0) {
				UfoItem* ship = itemMgr->getUfo();
				// No nullptr check means any stage with UFO parts and without the SS Dolphin will crash when the
				// action button is pressed.  This is relevant for some leftover test maps.
				if (TERNARY_BUGFIX(ship, true)) {
					Vector3f pelShipSep = pellet->mSRT.t - ship->getGoalPos();
					f32 distFromShip    = std::sqrtf(pelShipSep.x * pelShipSep.x + pelShipSep.z * pelShipSep.z);
					if (distFromShip < 30.0f && pellet->mCarrierCounter != 0) {
						continue;
					}
				}

				Vector3f pelNaviSep = pellet->mSRT.t - mSRT.t;
				f32 distFromNavi    = std::sqrtf(pelNaviSep.x * pelNaviSep.x + pelNaviSep.z * pelNaviSep.z) - pellet->getBottomRadius();
				if (distFromNavi <= 20.0f) {
					int idx = PelletMgr::getUfoIndexFromID(pellet->mConfig->mModelId.mId);
					if (idx == -1) {
						ERROR("WHY !! THIS IS NOT UFO PARTS!!\n");
					}
					_304 = pellet;
					mStateMachine->transit(this, NAVISTATE_PartsAccess);
					return true;
				}
			}
		}
	}

	// ACCESS SHIP INFO - see if there's a ship for us to interact with
	if (!gameflow.mMoviePlayer->mIsActive && getCurrState()->getID() == NAVISTATE_Walk
	    && gameflow.mWorldClock.mTimeOfDay < (gameflow.mParameters->mEndHour() - 0.2f)) {
		PRINT("tod = %f : endhour = %f\n", gameflow.mWorldClock.mTimeOfDay, gameflow.mParameters->mEndHour());
		UfoItem* ship = itemMgr->getUfo();
		if (ship) {
			Vector3f naviShipSep = ship->mSRT.t - mSRT.t;
			f32 naviShipDist     = std::sqrtf(naviShipSep.x * naviShipSep.x + naviShipSep.z * naviShipSep.z);
			if (naviShipDist <= 50.0f) {
				mStateMachine->transit(this, NAVISTATE_UfoAccess);
				return true;
			}
		}
	}

	// PLUCK A SPROUT - see if there's a sprout near enough for us to pluck
	bool isInsideOnyon = insideOnyon();
	Iterator iter(itemMgr->getPikiHeadMgr());
	PikiHeadItem* closestSprout = nullptr;
	f32 minDist;
	if (isInsideOnyon) {
		minDist = NAVI_PROP._5C();
	} else {
		minDist = NAVI_PROP._7C();
	}
	if (mFastPluckKeyTaps > 0) {
		minDist = NAVI_PROP._6C();
	}
	CI_LOOP(iter)
	{
		Creature* maybeSprout = *iter;
		if (maybeSprout->mObjType == OBJTYPE_Pikihead) {
			PikiHeadItem* sprout = static_cast<PikiHeadItem*>(maybeSprout);
			if (roughCull(this, sprout, minDist)) {
				continue;
			}

			Vector3f sproutNaviSep = sprout->mSRT.t - mSRT.t;
			f32 sproutDist         = std::sqrtf(sproutNaviSep.x * sproutNaviSep.x + sproutNaviSep.z * sproutNaviSep.z);
			f32 heightDiff         = absF(sproutNaviSep.y);
			if (sprout->canPullout() && sproutDist < minDist && heightDiff < 25.0f) {
				minDist       = sproutDist;
				closestSprout = sprout;
			}
		}
	}

	if (closestSprout) {
		if (DelayPikiBirth) {
			_814 = 0.0f;
			startMotion(PaniMotionInfo(PIKIANIM_Asibumi), PaniMotionInfo(PIKIANIM_Asibumi));
			PRINT_GLOBAL("nuki d=%.1f rn=%d", minDist, mFastPluckKeyTaps);
			Vector3f sproutSep = closestSprout->mSRT.t - mSRT.t;
			_7D0               = angDist(roundAng(atan2f(sproutSep.x, sproutSep.z)), mFaceDirection) / 10.0f;
			f32 dist           = sproutSep.length();
			// f32 scaledDist     = 3.0003002f * ((1.0f / dist) * (dist - 15.0f));
			_7C4 = 3.0003002f * ((1.0f / dist) * (dist - 15.0f)) * sproutSep;
			_7B8 = 2;
			_7C0 = closestSprout;
			_7BC = 0;
			mStateMachine->transit(this, NAVISTATE_NukuAdjust);
			return true;
		}

		PikiMgr::meBirthMode = true;
		Piki* piki           = static_cast<Piki*>(pikiMgr->birth());
		PikiMgr::meBirthMode = false;

		if (piki) {
			piki->init(this);
			piki->initColor(closestSprout->mSeedColor);
			piki->setFlower(closestSprout->mFlowerStage);
			piki->resetPosition(closestSprout->mSRT.t);
			piki->changeMode(PikiMode::FreeMode, this);
			piki->mFSM->transit(piki, PIKISTATE_NukareWait);
			closestSprout->kill(false);

			_814 = 0.0f;
			startMotion(PaniMotionInfo(PIKIANIM_Asibumi), PaniMotionInfo(PIKIANIM_Asibumi));

			Vector3f pikiSep = piki->mSRT.t - mSRT.t;
			_7D0             = angDist(roundAng(atan2f(pikiSep.x, pikiSep.z)), mFaceDirection) / 10.0f;

			f32 pikiDist = pikiSep.length();
			// f32 scaledDist = 3.0003002f * ((1.0f / pikiDist) * (pikiDist - 15.0f));
			_7C4 = 3.0003002f * ((1.0f / pikiDist) * (pikiDist - 15.0f)) * pikiSep;

			_7B8 = 2;
			_7BC = piki;
			mStateMachine->transit(this, NAVISTATE_NukuAdjust);
			PRINT("start nuku !\n");
			return true;
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
void Navi::offwallCallback(DynCollObject* wall)
{
	MsgOffWall msg(wall);
	sendMsg(&msg);
}

/**
 * @todo: Documentation
 */
void Navi::wallCallback(immut Plane& wallPlane, DynCollObject* wallObj)
{
	mWallPlane   = &wallPlane;
	_7B4         = 1;
	mWallCollObj = wallObj;
	mAiTickTimer = 0.1f;
	MsgWall msg(wallPlane, wallObj);
	sendMsg(&msg);
}

/**
 * @todo: Documentation
 */
void Navi::jumpCallback()
{
}

/**
 * @todo: Documentation
 */
bool Navi::isAtari()
{
	int state = mStateMachine->getCurrID(this);
	return state != NAVISTATE_Pressed && state != NAVISTATE_Bury && state != NAVISTATE_Container;
}

/**
 * @todo: Documentation
 */
bool Navi::ignoreAtari(Creature* target)
{
	if (target->mObjType == OBJTYPE_Piki) {
		int state = static_cast<Piki*>(target)->getState();
		if (state == PIKISTATE_Flying || state == PIKISTATE_Hanged) {
			return true;
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
void Navi::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	sendMsg(&msg);
}

/**
 * @todo: Documentation
 */
void Navi::letPikiWork()
{
	Iterator iter(mPlateMgr);
	// this sure is one way to get the first piki in mPlateMgr
	iter.first();
	Piki* piki = static_cast<Piki*>(*iter);
	if (piki) {
		if (_2FC->mObjType == OBJTYPE_WorkObject) {
			WorkObject* obj = static_cast<WorkObject*>(_2FC);
			if (obj->isBridge()) {
				Bridge* bridge = static_cast<Bridge*>(obj);
				Vector3f zVec(bridge->getBridgeZVec());
				zVec.multiply(-1.0f);
				piki->checkBridgeWall(obj, zVec);
				return;
			}
		}
		CollPart* part;
		if (_2FC->isSluice()) {
			part = _2FC->mCollInfo->getSphere('gate');
		}

		CollEvent event(_2FC, part, nullptr);
		_830 = true;
		piki->collisionCallback(event);
		_830 = false;
	}
}

/**
 * @todo: Documentation
 */
void Navi::collisionCallback(immut CollEvent& event)
{
	Creature* collider = event.mCollider;
	if (collider != _2FC) {
		switch (collider->mObjType) {
		case OBJTYPE_WorkObject:
			Bridge* bridge = static_cast<Bridge*>(collider);
			if (bridge->isBridge()) {
				if (bridge->mDoUseJointSegments && getCollidePlatformCreature() == bridge) {
					Vector3f normal(getCollidePlatformNormal());
					if ((normal.DP(bridge->getBridgeZVec()) >= -0.8f)) {
						return;
					}
				} else {
					return;
				}
			}
		case OBJTYPE_SluiceSoft:
		case OBJTYPE_SluiceHard:
		case OBJTYPE_SluiceBomb:
		case OBJTYPE_SluiceBombHard:
		case OBJTYPE_Pellet:
			if (_2FC) {
				_300 = 0.0f;
			}
			_2FC = collider;
			_300 += gsys->getFrameTime();
			if (_300 > 0.5f) {
				letPikiWork();
				_300 = 0.0f;
			}
			break;
		}
	}

	MsgCollide msg(event);
	sendMsg(&msg);

	int state = mStateMachine->getCurrID(this);
	if (collider->isVisible()) {
		switch (collider->mObjType) {
		case OBJTYPE_Key:
			if (collider->mGenerator) {
				PRINT("key->generator->id = %x\n", collider->mGenerator->mGeneratorName.mId);
			}
			Event event(2, collider->getGeneratorID());
			informEvent(event);
			mCurrKeyCount++;
			collider->kill(false);
			break;
		case OBJTYPE_Gate:
			if (mCurrKeyCount > 0 && static_cast<DoorItem*>(collider)->mStateId == DoorState::Active) {
				mCurrKeyCount--;
				static_cast<DoorItem*>(collider)->disappear();
			}
			break;
		case OBJTYPE_Door:
			if (mCurrKeyCount > 0 && state != NAVISTATE_Clear) {
				DoorItem* door = static_cast<DoorItem*>(collider);
				sprintf(flowCont.mStagePath2, "%s", door->mDestinationStagePath);
				Vector3f naviDoorSep = mSRT.t - door->mSRT.t;
				naviDoorSep.normalise();
				Vector3f faceDir(sinf(door->mFaceDirection), 0.0f, cosf(door->mFaceDirection));
				if (faceDir.DP(naviDoorSep) >= cosf(HALF_PI)) {
					mStateMachine->transit(this, NAVISTATE_Clear);
				}
			}
			break;
		}
	}
}

/**
 * @todo: Documentation
 */
void Navi::doKill()
{
}

/**
 * @todo: Documentation
 */
void Navi::reviseController(Vector3f& stickPos)
{
	f32 newMag = stickPos.length();
	f32 theta  = roundAng(atan2f(stickPos.x, stickPos.z));

	// bin angle in amounts set by navi parameter
	f32 binWidth    = (PI / 180.0f) * NAVI_PROP.mShakePreventionAngle();
	f32 binnedAngle = binWidth * int((theta + binWidth * 0.5f) / binWidth);

	// calculate amount to boost stick magnitude by
	f32 boostFactor = (binnedAngle - (int)(binnedAngle / QUARTER_PI) * QUARTER_PI);
	theta           = sinf(QUARTER_PI - boostFactor);
	boostFactor     = sinf(boostFactor);
	boostFactor += theta;

	// boost stick magnitude
	f32 len = (sinf(QUARTER_PI) / boostFactor);
	newMag *= (1.0f / len);

	// make 'close enough' good enough
	if (newMag >= NAVI_PROP.mClampStickToMaxThreshold()) {
		newMag = 1.0f;
	}

	// enforce dead zone
	if (newMag < NAVI_PROP.mNeutralStickThreshold()) {
		newMag = 0.0f;
	}

	controllerLen = len;

	stickPos.set(newMag * sinf(binnedAngle), 0.0f, newMag * cosf(binnedAngle));

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */

int gupper()
{
	int x;
	return x;
}

// Assumed parameter name from makeCStick, only ever called with false
void Navi::makeVelocity(bool isSunset)
{

	mNeutralTime += gsys->getFrameTime();

	if (mKontroller->keyDown(KBBTN_B) || mKontroller->keyDown(KBBTN_A) || mKontroller->keyDown(KBBTN_X) || mKontroller->keyDown(KBBTN_Z)) {
		mNeutralTime = 0.0f;
	}

	NVector3f stickVec(mKontroller->getMainStickX(), 0.0f, -mKontroller->getMainStickY());
	if (stickVec.x >= 1.0f) {
		stickVec.x = 1.0f;
	} else if (stickVec.x <= -1.0f) {
		stickVec.x = -1.0f;
	}

	if (stickVec.z >= 1.0f) {
		stickVec.z = 1.0f;
	} else if (stickVec.z <= -1.0f) {
		stickVec.z = -1.0f;
	}

	reviseController(stickVec);

	bool alwaysTrue = true;
	_740            = _74C;
	if (alwaysTrue) {
		_74C = stickVec;
	} else {
		_74C.set(0.0f, 0.0f, 0.0f);
	}
	f32 angle                   = NMathF::atan2(mNaviCamera->mViewXAxis.z, mNaviCamera->mViewXAxis.x);
	NAxisAngle4f NRef axisAngle = NAxisAngle4f(NVector3f(0.0f, 1.0f, 0.0f), angle);
	NTransform3D NRef transform = NTransform3D();
	transform.inputAxisAngle(axisAngle);

	if (!isSunset) {
		mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}

	if (alwaysTrue) {
		transform.transform(stickVec);
		if (!isSunset) {
			Stickers stuckList(this);
			int stickCount = stuckList.getNumStickers();
			f32 drag       = 1.0f;
			if (stickCount > 0) {
				drag -= stickCount * 0.08f;
				if (drag < 0.1f) {
					drag = 0.1f;
				}
			}

			if (mPlateMgr->canNaviRunFast()) {
				mTargetVelocity = (stickVec * NAVI_PROP._DC()) * drag;
			} else {
				mTargetVelocity = (stickVec * NAVI_PROP._CC()) * drag;
			}

			if (mGroundTriangle) {
				// ?? this does nothing.
				f32 speed = mTargetVelocity.length();
				Vector3f vec
				    = mTargetVelocity - mTargetVelocity.DP(mGroundTriangle->mTriangle.mNormal) * mGroundTriangle->mTriangle.mNormal;
				vec.normalise();
				vec = vec * speed;
			}
		}

		transform.transform(_74C);
	}

	f32 stickMag = stickVec.length();

	Vector3f stickVec2(stickVec);

	stickVec2.normalise();
	stickVec2 = stickVec2 * NAVI_PROP._3AC();

	f32 step           = gsys->getFrameTime();
	Vector3f targetPos = stickVec2 * step + mCursorPosition;
	if (targetPos.length() >= NAVI_PROP._39C()) {
		Vector3f vec(targetPos);
		vec.normalise();
		stickVec2 = stickVec2 - vec.DP(stickVec2) * vec;
		targetPos = stickVec2 * step + mCursorPosition;
	}

	mCursorPosition       = targetPos;
	f32 dist              = targetPos.length();
	mCursorNaviDist       = dist;
	mCursorTargetPosition = targetPos;

	if (!(stickMag <= NAVI_PROP.mNeutralStickThreshold())) {
		mNeutralTime = 0.0f;
	}

	bool check = false;
	if (mNeutralTime >= NAVI_PROP._33C()) {
		check = true;
	}

	if ((check || (!check && stickMag > NAVI_PROP.mNeutralStickThreshold())) && stickMag <= NAVI_PROP._36C()) {
		mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		Vector3f cursorPos(mCursorPosition);
		mFaceDirection += 0.2f * angDist(roundAng(atan2f(cursorPos.x, cursorPos.z)), mFaceDirection);
		mFaceDirection = roundAng(mFaceDirection);
		mSRT.r.set(0.0f, mFaceDirection, 0.0f);
		setCreatureFlag(CF_UsePriorityFaceDir);
	} else {
		resetCreatureFlag(CF_UsePriorityFaceDir);
	}

	stickVec.set(0.0f, 0.0f, 0.0f);
	makeCStick(false);

	// this hides many developer sins i am sure.
	STACK_PAD_VAR(5);
	return;
	Vector2f();
}

/**
 * @todo: Documentation
 */
void Navi::makeCStick(bool isSunset)
{
	f32 angle                   = NMathF::atan2(mNaviCamera->mViewXAxis.z, mNaviCamera->mViewXAxis.x);
	NAxisAngle4f NRef axisAngle = NAxisAngle4f(NVector3f(0.0f, 1.0f, 0.0f), angle);

	NTransform3D NRef transform = NTransform3D();
	transform.inputAxisAngle(axisAngle);

	NVector3f subStick(mKontroller->getSubStickX(), 0.0f, -mKontroller->getSubStickY());

	if (isSunset) {
		subStick.set(0.0f, 0.0f, 0.0f);
	}

	reviseController(subStick);

	if (mPlateMgr) {
		if (getCurrState()->getID() != NAVISTATE_DemoSunset && getCurrState()->getID() != NAVISTATE_Dead) {
			if (mPlateMgr->mTotalSlotCount > 0) {
				seMgr->playNaviSound(74.0f * subStick.x, 74.0f * subStick.z);
			} else {
				seMgr->playNaviSound(0, 0);
			}
		}
	}

	subStick.scale(1.0f);
	transform.transform(subStick);

	_764.set(0.0f, 0.0f, 0.0f);

	f32 val = 0.05f;
	if (subStick.length() > val) {
		mNeutralTime = 0.0f;
		_764         = subStick;
		f32 angle1   = atan2f(subStick.x, subStick.z);
		f32 angle2   = mPlateMgr->mDirectionAngle;
		Vector3f dir1(sinf(angle1), 0.0f, cosf(angle1));
		Vector3f dir2(sinf(angle2), 0.0f, cosf(angle2));

		f32 newAngle;
		if (dir1.DP(dir2) > cosf(2.0943952f)) {
			newAngle = angDist(angle1, angle2) * 0.4f + angle2;
		} else {
			newAngle = angle1;
		}

		newAngle = roundAng(newAngle);
		_714     = newAngle;

		f32 dist = (subStick.length() - val) / (1.0f - val);
		if (dist >= 0.9f) {
			dist = 1.0f;
		} else {
			dist = 0.6f * (dist / 0.9f);
		}

		mPlateMgr->refresh(getPlatePikis(), dist);

		mPlateMgr->setPos(mSRT.t, newAngle, mVelocity);
		_718 = false;
		_724 = false;
	} else {
		if (!_718) {
			_724 = true;
		}

		f32 backDir = mFaceDirection + PI;
		if (!_718 && mTargetVelocity.length() < 50.0f && mStateMachine->getCurrID(this) != NAVISTATE_ThrowWait) {
			backDir = _714;
			mPlateMgr->setPos(mSRT.t, backDir, mVelocity);
		} else {
			_718 = true;
		}

		mPlateMgr->refresh(getPlatePikis(), 0.0f);
		Iterator iter(mPlateMgr);
		f32 minDist = 12800.0f;

		CI_LOOP(iter)
		{
			Creature* c = *iter;
			Piki* piki  = static_cast<Piki*>(c);
			int state   = piki->getState();
			if (state == PIKISTATE_Hanged || state == PIKISTATE_GoHang) {
				continue;
			}

			Vector3f sep = c->mSRT.t - mSRT.t;
			f32 dist     = sep.length();
			if (dist < minDist) {
				minDist = dist;
			}
		}

		if (minDist < NAVI_PROP._1DC()) {
			if (_71C == 0) {
				_720++;
			} else {
				_720 = 0;
				_71C = 0;
			}
		} else if (minDist < NAVI_PROP._1EC()) {
			if (_71C == 1) {
				_720++;
			} else {
				_720 = 0;
				_71C = 1;
			}
		} else {
			if (_71C == 2) {
				_720++;
			} else {
				_720 = 0;
				_71C = 2;
			}
		}

		if (_71C == 0) {
			_719 = true;
		} else if (_71C == 1) {
			_719              = true;
			Vector3f squadSep = mPlateMgr->mPlateOffset - mSRT.t;
			squadSep.normalise();
			mPlateMgr->setPosGray(mSRT.t, atan2f(squadSep.x, squadSep.z), mVelocity);
		} else if (_71C == 2) {
			_724 = false;
			if (_719) {
				mPlateMgr->rearrangeSlot(mSRT.t, backDir, mVelocity);
				_719 = false;
			}
			mPlateMgr->setPos(mSRT.t, backDir, mVelocity);
		}
	}

	_758 = subStick;

	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
void Navi::refresh(Graphics& gfx)
{
	draw(gfx);
	if (!movieMode()) {
		if (gsys->mToggleColls) {
			mapMgr->showCollisions(mSRT.t);
		}

		Matrix4f viewMtx;
		mPlateMgr->render(gfx);

		// these aren't used for anything in the DLL either, lol.
		f32 unusedVal  = sinf(mFaceDirection);
		f32 unusedVal2 = cosf(mFaceDirection);
		STACK_PAD_VAR(1);

		mCursorWorldPos   = mCursorPosition + mSRT.t;
		mCursorWorldPos.y = mapMgr->getMinY(mCursorWorldPos.x, mCursorWorldPos.z, true) + 1.0f;

		CollTriInfo* cursorTri = mapMgr->getCurrTri(mCursorWorldPos.x, mCursorWorldPos.z, true);

		Matrix4f orientMatrix;
		orientMatrix.makeIdentity();

		Vector3f cursorDir = mCursorWorldPos - mSRT.t;
		cursorDir.normalise();

		Vector3f surfaceNormal(0.0f, 1.0f, 0.0f);
		if (cursorTri) {
			surfaceNormal = cursorTri->mTriangle.mNormal;
			surfaceNormal.normalise();
		}

		Vector3f rightVector;
		rightVector = surfaceNormal;
		rightVector.CP(cursorDir);
		rightVector.normalise();

		cursorDir = rightVector;
		cursorDir.CP(surfaceNormal);
		cursorDir.normalise();

		orientMatrix.mMtx[0][0] = rightVector.x;
		orientMatrix.mMtx[1][0] = rightVector.y;
		orientMatrix.mMtx[2][0] = rightVector.z;

		orientMatrix.mMtx[0][1] = surfaceNormal.x;
		orientMatrix.mMtx[1][1] = surfaceNormal.y;
		orientMatrix.mMtx[2][1] = surfaceNormal.z;

		orientMatrix.mMtx[0][2] = cursorDir.x;
		orientMatrix.mMtx[1][2] = cursorDir.y;
		orientMatrix.mMtx[2][2] = cursorDir.z;

		mWorldMtx = orientMatrix;
		mWorldMtx.setTranslation(mCursorWorldPos);

		if (mIsCursorVisible && getCurrState()->getID() != NAVISTATE_DemoSunset) {
			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, viewMtx);

			gfx.useMatrix(viewMtx, 0);

			mNaviDynMats.updateContext();
			GlobalShape::cursorShape->drawshape(gfx, *gfx.mCamera, nullptr);

			Colour markerColour;
			if (mNextThrowPiki) {
				markerColour = mNextThrowPiki->mCurrentColour;
			} else {
				markerColour.set(255, 255, 255, 255);
			}

			bool isLighting                                    = gfx.setLighting(false, nullptr);
			GlobalShape::markerShape2->mMaterialList->Colour() = markerColour;
			GlobalShape::markerShape2->drawshape(gfx, *gfx.mCamera, nullptr);
			gfx.setLighting(isLighting, nullptr);
		}
	}
}

/**
 * @todo: Documentation
 */
void Navi::demoDraw(Graphics& gfx, immut Matrix4f* mtx)
{
	mShadowCaster.mSourcePosition.set(mSRT.t.x + 75.0f, mSRT.t.y + 100.0f, mSRT.t.z + 25.0f);
	mShadowCaster.mTargetPosition.set(mSRT.t.x, mSRT.t.y + 10.0f, mSRT.t.z);
	mNaviShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	mCollInfo->updateInfo(gfx, false);
	mNaviLightPosition = mCollInfo->getSphere('ante')->mCentre;
	mNaviLightEfx->updatePos(mNaviLightPosition);
	mNaviLightGlowEfx->updatePos(mNaviLightPosition);
}

/**
 * @todo: Documentation
 */
void Navi::draw(Graphics& gfx)
{
	if (isPellet()) {
		return;
	}

	if (mStateMachine->getCurrID(this) != NAVISTATE_Pressed) {
		f32 scale = NAVI_PROP.mDisplayScale();
		mSRT.s.set(scale, scale, scale);
	}

	if (mRope) {
		mWorldMtx = mConstrainedMoveMtx;
		mWorldMtx.setTranslation(mSRT.t.x, mSRT.t.y, mSRT.t.z);
	} else {
		mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
		mConstrainedMoveMtx = mWorldMtx;
	}

	gfx.useMatrix(Matrix4f::ident, 0);

	STACK_PAD_VAR(1);
	Matrix4f viewMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, viewMtx);

	mNaviAnimMgr.updateContext();
	mapMgr->getLight(mSRT.t.x, mSRT.t.z);

	bool hasAnimError = false;
	for (int i = 0; i < mNaviShapeObject->mShape->mJointCount; i++) {
		if (mNaviShapeObject->mShape->mAnimOverrides[i]->mData && &mNaviShapeObject->mShape->mAnimOverrides[i]->mCurrentFrame) {
			int frame1 = mNaviShapeObject->mShape->mAnimOverrides[i]->mCurrentFrame;
			int frame2 = mNaviShapeObject->mShape->mAnimOverrides[i]->mCurrentFrame;
			if (frame1 < 0 || frame2 >= mNaviShapeObject->mShape->mAnimOverrides[i]->mData->mTotalFrameCount) {
				PRINT(" NAVI -------- error : joint is %d\n", i);
				PRINT(" motion is %s\n", mNaviAnimMgr.getUpperAnimator().getCurrentMotionName());
				hasAnimError = true;
			}
		}
	}

	if (!hasAnimError) {
		mNaviShapeObject->mShape->updateAnim(gfx, viewMtx, nullptr);
	}

	updateHeadMatrix();
	if (!(gameflow.mDemoFlags & GFDEMO_HideNavi) && !mIsRidingUfo) {
		demoDraw(gfx, nullptr);
	}

	STACK_PAD_VAR(7);
}

/**
 * @todo: Documentation
 */
void Navi::renderCircle(Graphics& gfx)
{
	f32 tmp;
	f32 rad;
	switch (_ABC) {
	case 0:
		rad = NAVI_PROP._9C() + _AC0 * (NAVI_PROP._8C() - NAVI_PROP._9C());
		break;
	case 1:
		tmp = (_AB8 / NAVI_PROP._AC());
		rad = NAVI_PROP._9C() + tmp * (NAVI_PROP._8C() - NAVI_PROP._9C());
		break;
	default:
		rad = NAVI_PROP._9C() + _AC0 * (NAVI_PROP._8C() - NAVI_PROP._9C());
		break;
	}

	_AC8 = rad;

	static f32 ang = 0.0f;
	ang            = ang + 0.03f;
	if (ang > TAU) {
		ang -= TAU;
	}

	for (int i = 0; i < 24; i++) {
		tmp = i * (TAU / 24.0f);
		tmp += ang;
		Vector3f dir(rad * sinf(tmp), 0.0f, rad * cosf(tmp));
		Vector3f pos(mCursorWorldPos);
		pos     = pos + dir;
		pos.y   = mapMgr->getMinY(pos.x, pos.z, true);
		_938[i] = pos;
	}
}

/**
 * @todo: Documentation
 */
void Navi::refresh2d(Graphics&)
{
}

/**
 * @todo: Documentation
 */
void Navi::sendMsg(Msg* msg)
{
	mStateMachine->procMsg(this, msg);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void Navi::procDamage(f32)
{
}

/**
 * @todo: Documentation
 */
bool Navi::stimulate(immut Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actNavi(this);
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool InteractGeyzer::actNavi(Navi* navi) immut
{
	if (navi->isDamaged()) {
		return false;
	}

	int state = navi->mStateMachine->getCurrID(navi);
	if (state == NAVISTATE_Geyzer) {
		return false;
	}
	if (state == NAVISTATE_Pellet) {
		return false;
	}

	navi->mStateMachine->transit(navi, NAVISTATE_Geyzer);
	NaviGeyzerState* geyzer = static_cast<NaviGeyzerState*>(navi->mStateMachine->getNaviState(navi));
	geyzer->_20             = _08;
	PRINT("geyzer !\n");
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractBury::actNavi(Navi* navi) immut
{
	NaviState* state = navi->mStateMachine->getNaviState(navi);
	if (state->invincible(navi)) {
		return false;
	}

	navi->mStateMachine->transit(navi, NAVISTATE_Bury);
	rumbleMgr->start(RUMBLE_Unk1, 0, nullptr);
	navi->mHealth -= _0C;
	navi->startDamageEffect();
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		navi->mStateMachine->transit(navi, NAVISTATE_Dead);
	}

	return true;
}

/**
 * @todo: Documentation
 */
bool InteractWind::actNavi(Navi* navi) immut
{
	NaviState* state = navi->mStateMachine->getNaviState(navi);
	if (state->invincible(navi)) {
		return false;
	}

	navi->mVelocity       = mVelocity;
	navi->mTargetVelocity = mVelocity;
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractSuck::actNavi(Navi* navi) immut
{
	PRINT_GLOBAL("actNavi");
	if (!navi->isAlive()) {
		return false;
	}

	if (!navi->mStateMachine) {
		ERROR("navi->stateM = 0!\n");
	}
	if (!navi->mStateMachine->getNaviState(navi)) {
		ERROR("no navi state:suck!\n");
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	PRINT_GLOBAL("invicible check false");
	navi->mHealth -= mDamage;
	PRINT_GLOBAL("life = %.1f", navi->mHealth);

	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	rumbleMgr->start(RUMBLE_Unk15, 0, nullptr);
	PRINT_GLOBAL("lgauge");
	navi->startDamageEffect();
	PRINT_GLOBAL("dmg eff");
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		navi->mStateMachine->transit(navi, NAVISTATE_Dead);
		PRINT_GLOBAL("navi dead");
	}
	PRINT_GLOBAL(">");

	return true;
}

/**
 * @todo: Documentation
 */
bool InteractAttack::actNavi(Navi* navi) immut
{
	if (navi->isDamaged()) {
		return false;
	}

	if (!navi->startDamage()) {
		return false;
	}

	rumbleMgr->start(RUMBLE_Unk1, 0, nullptr);
	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("ATTACK DEAD ******\n");
	} else {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));
	}

	PRINT("navi got attack interaction!\n");
	navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractPress::actNavi(Navi* navi) immut
{
	if (navi->isDamaged()) {
		return false;
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	rumbleMgr->start(RUMBLE_Unk1, 0, nullptr);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("PRESS DEAD ******\n");
	}

	navi->startDamageEffect();
	navi->mStateMachine->transit(navi, NAVISTATE_Pressed);
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractSwallow::actNavi(Navi* navi) immut
{
	PRINT("NAVI GOT SWALLOW INTERACTION !\n");
	if (!navi->startDamage()) {
		return false;
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	rumbleMgr->start(RUMBLE_Unk1, 0, nullptr);
	navi->mHealth -= 10.0f;
	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->startDamageEffect();
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("SWALLOW DEAD ******\n");
	} else {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));
	}
	navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));

	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractBomb::actNavi(Navi* navi) immut
{
	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	if (navi->mStateMachine->getCurrID(navi) == NAVISTATE_PikiZero) {
		return false;
	}

	rumbleMgr->start(RUMBLE_Unk1, 0, nullptr);
	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->startDamageEffect();
	navi->_704 = 100.0f;
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("BOMB DEAD ******\n");
	}
	navi->mStateMachine->transit(navi, NAVISTATE_Flick);

	STACK_PAD_VAR(2);
	return true;
}

/**
 * @todo: Documentation
 */
bool Navi::orimaDamaged()
{
	int state = mStateMachine->getCurrID(this);
	return isDamaged() || state == NAVISTATE_Flick || state == NAVISTATE_Pressed || state == NAVISTATE_Stuck || state == NAVISTATE_Bury;
}

/**
 * @todo: Documentation
 */
bool InteractFlick::actNavi(Navi* navi) immut
{
	if (navi->mStateMachine->getCurrID(navi) == NAVISTATE_PikiZero) {
		return false;
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	if (mDamage > 0.0f) {
		rumbleMgr->start(RUMBLE_Unk10, 0, nullptr);
		navi->startDamageEffect();
	} else {
		rumbleMgr->start(RUMBLE_Unk10, 0, nullptr);
	}

	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->_704 = mIntensity;
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("FLICK DEAD ******\n");
	}

	navi->mStateMachine->transit(navi, NAVISTATE_Flick);

	STACK_PAD_VAR(2);
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractBubble::actNavi(Navi* navi) immut
{
	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	rumbleMgr->start(RUMBLE_Unk1, 0, nullptr);
	SeSystem::playPlayerSe(SE_FIRED);
	navi->startDamageEffect();
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
	}
	navi->_704 = 2.0f;
	navi->mStateMachine->transit(navi, NAVISTATE_Flick);
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractFire::actNavi(Navi* navi) immut
{
	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->startDamageEffect();
	rumbleMgr->start(RUMBLE_Unk1, 0, nullptr);
	SeSystem::playPlayerSe(SE_FIRED);
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
	}
	navi->_704 = 2.0f;
	navi->mStateMachine->transit(navi, NAVISTATE_Flick);
	return true;
}

/**
 * @todo: Documentation
 */
void Navi::dump()
{
	if (Piki::directDumpMode) {
		PRINT_GLOBAL("-- navi : mode = %d\n", mStateMachine->getCurrID(this));
		PRINT_GLOBAL(" onground : %s isFlying %s\n", isCreatureFlag(CF_IsOnGround) ? "true" : "false",
		             isCreatureFlag(CF_IsFlying) ? "true" : "false");
		PRINT_GLOBAL(" isAlive=%s isVisible=%s isBuried=%s\n", isAlive() ? "true" : "false", isVisible() ? "true" : "false",
		             isBuried() ? "true" : "false");
		PRINT_GLOBAL(" neutralTime = %.2f\n", mNeutralTime);
	} else {
		PRINT("-- navi : mode = %d\n", mStateMachine->getCurrID(this));
		PRINT(" onground : %s isFlying %s\n", isCreatureFlag(CF_IsOnGround) ? "true" : "false",
		      isCreatureFlag(CF_IsFlying) ? "true" : "false");
		PRINT(" isAlive=%s isVisible=%s isBuried=%s\n", isAlive() ? "true" : "false", isVisible() ? "true" : "false",
		      isBuried() ? "true" : "false");
		// `neutralTime` PRINT is intentionally omitted here.  Well, maybe not by the original devs.
	}
}

/**
 * @todo: Documentation
 */
void Navi::throwPiki(Piki* piki, immut Vector3f& pos)
{
	f32 unused = mFaceDirection + PI;
	piki->mActiveAction->abandon(nullptr);
	rumbleMgr->start(RUMBLE_Unk2, 0, nullptr);
	piki->mSRT.t         = mSRT.t + Vector3f(0.0f, 10.0f, 0.0f);
	Vector3f throwDir    = pos - piki->mSRT.t;
	f32 throwDist        = speedy_sqrtf(throwDir.x * throwDir.x + throwDir.z * throwDir.z);
	f32 throwAngle       = atan2f(throwDir.x, throwDir.z);
	piki->mFaceDirection = roundAng(throwAngle);

	f32 halfTime = 0.5f * NAVI_PROP._1AC();
	f32 height;
	if (piki->mColor == Yellow) {
		height = NAVI_PROP._19C();
	} else {
		height = NAVI_PROP._18C() + (_800 / NAVI_PROP._14C()) * (NAVI_PROP._17C() - NAVI_PROP._18C());
	}

	f32 vSpeed = AIConstant::_instance->mConstants.mGravity() * 0.5f * halfTime + (height / halfTime);
	f32 hSpeed = throwDist / (2.0f * halfTime);

	piki->mVelocity.set(hSpeed * sinf(throwAngle), vSpeed, hSpeed * cosf(throwAngle));

	piki->mVelocity       = piki->mVelocity + mVelocity;
	piki->mTargetVelocity = piki->mVelocity;
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001DC
 */
void Navi::throwLocus(Vector3f&)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void Navi::swapMotion(immut PaniMotionInfo& motion1, immut PaniMotionInfo& motion2)
{
	STACK_PAD_VAR(4);

	f32* frame1 = &mNaviAnimMgr.mUpperAnimator.mAnimationCounter;
	f32* frame2 = &mNaviAnimMgr.mLowerAnimator.mAnimationCounter;
	f32 val1    = *frame1;
	f32 val2    = *frame2;
	mNaviAnimMgr.startMotion(motion1, motion2);
	*frame1 = val1;
	*frame2 = val2;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0002D4
 */
void Navi::renderParabola(Graphics& gfx, f32 height, f32 len)
{
	if (mStateMachine->getCurrID(this) != NAVISTATE_ThrowWait) {
		return;
	}

	PRINT("len %f height %f\n", len, height);

	f32 a = -4.0f * height / (len * len);
	f32 b = height;
	Vector3f prevPos(mSRT.t);
	Vector3f dir(sinf(mFaceDirection), 0.0f, cosf(mFaceDirection));
	Vector3f up(0.0f, 1.0f, 0.0f);

	Vector3f nextPos;
	int segmentCount = 16;
	f32 inc          = len / 16.0f;
	f32 x            = 0.0f;
	gfx.setLighting(false, nullptr);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(0, 255, 0, 255), true);

	for (int i = 0; i < segmentCount - 1; i++) {
		x += inc;
		f32 y = (x - len * 0.5f) * a * (x - len * 0.5f) + b;
		PRINT(" %d : x:%.1f/%.1f y : %f\n", i, x, len, y);
		nextPos = prevPos;
		nextPos = nextPos + x * dir;
		nextPos = nextPos + y * up;
		gfx.drawLine(prevPos, nextPos);
		prevPos = nextPos;
	}
}

/**
 * @todo: Documentation
 */
void Navi::finishLook()
{
	mLookAtPosPtr = nullptr;
	_2F0          = 10;
}

/**
 * @todo: Documentation
 */
void Navi::updateLook()
{
	f32 angle1;
	f32 angle2;
	f32 val = 0.05f;
	if (mLookAtPosPtr) {
		Vector3f lookDir = *mLookAtPosPtr - mSRT.t;
		angle2           = atan2f(lookDir.x, lookDir.z);
		f32 dist         = std::sqrtf(lookDir.x * lookDir.x + lookDir.z * lookDir.z);
		angle1           = atan2f(lookDir.y, dist);
	} else {
		f32 factor = 0.2f;
		f32 tmp1   = angDist(0.0f, _2F4);
		_2F4       = roundAng(tmp1 * factor + _2F4);
		f32 tmp2   = angDist(0.0f, _2F8);
		_2F8       = roundAng(tmp2 * factor + _2F8);

		if (absF(_2F4) < 0.1f && absF(_2F8) < 0.1f) {
			forceFinishLook();
		}
		return;
	}

	f32 angle3 = roundAng(_2F4 + mFaceDirection);
	f32 angle4 = roundAng(angle2 - mFaceDirection);

	f32 angle5;
	if (angle4 < PI) {
		if (_2F4 > PI) {
			angle5 = TAU - (_2F4 - angle4);
		} else {
			angle5 = angDist(angle2, angle3);
		}
	} else if (_2F4 <= PI) {
		angle5 = (TAU - (_2F4 - angle4));
		angle5 *= -1.0f;
	} else {
		angle5 = angDist(angle2, angle3);
	}

	if (absF(angle5) < PI / 20.0f) {
		angle5 = 0.0f;
	}

	_2F4 = roundAng(angle5 * val + _2F4);

	if (_2F4 > 2.0f * PI / 3.0f && _2F4 < PI) {
		_2F4 = 2.0f * PI / 3.0f;
	} else if (_2F4 < 4.0f * PI / 3.0f && _2F4 >= PI) {
		_2F4 = 4.0f * PI / 3.0f;
	}

	f32 angle6 = angDist(angle1, _2F8);
	if (absF(angle6) < PI / 20.0f) {
		angle6 = 0.0f;
	}

	_2F8 = roundAng(angle6 * val + _2F8);

	if (_2F8 > PI / 3.0f && _2F8 < PI) {
		_2F8 = PI / 3.0f;
	} else if (_2F8 < 5.2359877f && _2F8 >= PI) {
		_2F8 = 5.2359877f; // 5 pi / 3 but not quite
	}

	if (_2F0) {
		_2F0--;
		if (_2F0 == 0) {
			forceFinishLook();
		}
	}
}

/**
 * @todo: Documentation
 */
void Navi::updateHeadMatrix()
{
	if (!mLookAtPosPtr && _2F0 == 0) {
		return;
	}

	updateLook();

	Matrix4f animMtx = mNaviShapeObject->mShape->getAnimMatrix(2);
	Matrix4f mtx1;
	Matrix4f mtx2;
	animMtx.inverse(&mtx1);
	Matrix4f mtx3;
	mtx3.makeIdentity();

	f32 sin8 = sinf(-_2F8);
	f32 cos8 = cosf(-_2F8);
	f32 sin4 = sinf(_2F4);
	f32 cos4 = cosf(_2F4);

	mtx3.mMtx[0][0] = cos8;
	mtx3.mMtx[0][1] = -sin8;
	mtx3.mMtx[0][2] = 0.0f;

	mtx3.mMtx[1][0] = cos4 * sin8;
	mtx3.mMtx[1][1] = cos4 * cos8;
	mtx3.mMtx[1][2] = -sin4;

	mtx3.mMtx[2][0] = sin4 * sin8;
	mtx3.mMtx[2][1] = sin4 * cos8;
	mtx3.mMtx[2][2] = cos4;

	animMtx.multiplyTo(mtx3, mtx2);

	mNaviShapeObject->mShape->getAnimMatrix(2) = mtx2;

	for (int i = 3; i <= 6; i++) {
		Matrix4f tempAnim = mNaviShapeObject->mShape->getAnimMatrix(i);
		Matrix4f tmp1;
		Matrix4f tmp2;
		mtx1.multiplyTo(tempAnim, tmp1);
		mtx2.multiplyTo(tmp1, tmp2);
		mNaviShapeObject->mShape->getAnimMatrix(i) = tmp2;
	}

	mNaviShapeObject->mShape->calcWeightedMatrices();
}
