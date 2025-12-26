#include "UfoItem.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "MoviePlayer.h"
#include "NaviMgr.h"
#include "Pellet.h"
#include "PlayerState.h"
#include "Route.h"
#include "SoundID.h"
#include "UtEffect.h"
#include "gameflow.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

int numKeys          = 3;
f32 trKeys[3]        = { 0.0f, 13.0f, 50.0f };
static u32 leg_ids[] = { 'leg1', 'leg2', 'leg3' };

EffectMgr::effTypeTable effects[8][4] = {
	{
	    EffectMgr::EFF_Rocket_NJ2FB,
	    EffectMgr::EFF_Rocket_NJ2FA,
	    EffectMgr::EFF_Rocket_NJ2CB,
	    EffectMgr::EFF_Rocket_NJ2CA,
	},
	{
	    EffectMgr::EFF_Rocket_NJ2FB,
	    EffectMgr::EFF_Rocket_NJ2FA,
	    EffectMgr::EFF_Rocket_NJ3CB,
	    EffectMgr::EFF_Rocket_NJ3CA,
	},
	{
	    EffectMgr::EFF_Rocket_NJ3FB,
	    EffectMgr::EFF_Rocket_NJ3FA,
	    EffectMgr::EFF_Rocket_NJ3CB,
	    EffectMgr::EFF_Rocket_NJ3CA,
	},
	{
	    EffectMgr::EFF_Rocket_NJ3FB,
	    EffectMgr::EFF_Rocket_NJ3FA,
	    EffectMgr::EFF_Rocket_NJ3CB,
	    EffectMgr::EFF_Rocket_NJ3CA,
	},
	{
	    EffectMgr::EFF_Rocket_NJ1FB,
	    EffectMgr::EFF_Rocket_NJ1FA,
	    EffectMgr::EFF_Rocket_NJ1CB,
	    EffectMgr::EFF_Rocket_NJ1CA,
	},
	{
	    EffectMgr::EFF_Rocket_NJ1FB2,
	    EffectMgr::EFF_Rocket_NJ1FA2,
	    EffectMgr::EFF_Rocket_NJ1CB2,
	    EffectMgr::EFF_Rocket_NJ1CA2,
	},
	{
	    EffectMgr::EFF_Rocket_NJ1FB3,
	    EffectMgr::EFF_Rocket_NJ1FA3,
	    EffectMgr::EFF_Rocket_NJ1CB3,
	    EffectMgr::EFF_Rocket_NJ1CA3,
	},
	{
	    EffectMgr::EFF_Rocket_NJ1FB4,
	    EffectMgr::EFF_Rocket_NJ1FA4,
	    EffectMgr::EFF_Rocket_NJ1CB4,
	    EffectMgr::EFF_Rocket_NJ1CA4,
	},
};

static const EffectMgr::effTypeTable unusedEffects[3] = {
	EffectMgr::EFF_Onyon_HaloRingBlue,
	EffectMgr::EFF_Onyon_HaloRingRed,
	EffectMgr::EFF_Onyon_HaloRingYellow,
};

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("ufoItem")

/**
 * @todo: Documentation
 */
bool UfoItem::insideSafeArea(immut Vector3f& pos)
{
	Vector3f diff = pos - mSRT.t;
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

/**
 * @todo: Documentation
 */
void UfoItem::setSpotTurn(bool set)
{
	Vector3f goal  = getGoalPos();
	CollPart* part = mCollInfo->getSphere('gol1');

	if (!set && mShouldLightActivate) {
		if (mRingFx) {
			effectMgr->kill(mRingFx, false);
			mRingFx = nullptr;
		}
		mRingFx = effectMgr->create(EffectMgr::EFF_Rocket_NaviNormalRings, goal, nullptr, nullptr);
	} else if (set && !mShouldLightActivate) {
		if (mRingFx) {
			effectMgr->kill(mRingFx, false);
			mRingFx = nullptr;
		}
		mRingFx = effectMgr->create(EffectMgr::EFF_Rocket_NaviActionRings, goal, nullptr, nullptr);
	}
	mShouldLightActivate = set;
}

/**
 * @todo: Documentation
 */
void UfoItem::setSpotActive(bool set)
{
	mShouldLightActivate = false;
	mIsLightActive       = set;

	Vector3f goal = Vector3f(getGoalPos());
	f32 padding[2]; // needed for stack to work
	CollPart* part = mCollInfo->getSphere('gol1');

	if (mIsLightActive) {
		if (mRingFx) {
			effectMgr->kill(mRingFx, false);
			mRingFx = nullptr;
		}
		mRingFx = effectMgr->create(EffectMgr::EFF_Rocket_NaviNormalRings, goal, nullptr, nullptr);

		if (mSparkleFx) {
			effectMgr->kill(mSparkleFx, false);
			mSparkleFx = nullptr;
		}
		mSparkleFx = effectMgr->create(EffectMgr::EFF_Rocket_NaviSparkle, goal, nullptr, nullptr);

	} else {
		if (mRingFx) {
			effectMgr->kill(mRingFx, false);
			mRingFx = nullptr;
		}
		if (mSparkleFx) {
			effectMgr->kill(mSparkleFx, false);
			mSparkleFx = nullptr;
		}
	}
}

/**
 * @todo: Documentation
 */
void UfoItem::setTroubleEffect(bool set)
{
	mIsTroubleFxEnabled = set;
	if (set) {
		mTroubleFxTimer = 0.0f;
		mTroubleFxState = -1;
		startTroubleEffectOne(0);
		startTroubleEffectOne(1);
		startTroubleEffectOne(5);
		return;
	}

	for (int i = 0; i < 6; i++) {
		if (mTroubleFxGenList[i]) {
			effectMgr->kill(mTroubleFxGenList[i], false);
			mTroubleFxGenList[i] = nullptr;
		}
	}
}

/**
 * @todo: Documentation
 */
void UfoItem::startTroubleEffectOne(int id)
{
	EffectMgr::effTypeTable ids[6] = { EffectMgr::EFF_Rocket_MkB,  EffectMgr::EFF_Rocket_MkS,  EffectMgr::EFF_Rocket_Hiba,
		                               EffectMgr::EFF_Rocket_Hiba, EffectMgr::EFF_Rocket_Hiba, EffectMgr::EFF_Rocket_Biri };
	mTroubleFxGenList[id]          = effectMgr->create(ids[id], mTroubleFxPositionList[id], nullptr, nullptr);
	mTroubleFxGenList[id]->setEmitPosPtr(&mTroubleFxPositionList[id]);

	if (ids[id] == EffectMgr::EFF_Rocket_Hiba) {
		playEventSound(this, SE_UFO_SPARK);
	}
}

/**
 * @todo: Documentation
 */
void UfoItem::updateTroubleEffect()
{
	if (!mIsTroubleFxEnabled) {
		return;
	}

	mTroubleFxTimer += gsys->getFrameTime() * 30.0f;
	int test = mTroubleFxState + 1;
	if (test < numKeys && mTroubleFxTimer >= trKeys[test]) {
		mTroubleFxState = test;
		switch (mTroubleFxState) {
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

	if (mTroubleFxTimer >= 80.0f) {
		mTroubleFxState = -1;
		mTroubleFxTimer = 0.0f;
	}
}

/**
 * @todo: Documentation
 */
void UfoItem::startConeEffect(int)
{
	Vector3f goal = getGoalPos();
	Vector3f suck = getSuckPos();
	EffectParm eff(goal, suck);
	mConeEffectId = KandoEffect::WhistleTemplate1;
	utEffectMgr->cast(mConeEffectId, eff);
	mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::Wait, this));
	mAnimator.setMotionSpeed(0, 30.0f);
	PRINT("*** UFO FUTA OPEN !!!!!!!!!!!!!!________________________________\n");
}

/**
 * @todo: Documentation
 */
void UfoItem::finishConeEffect()
{
	utEffectMgr->kill(mConeEffectId);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
void UfoItem::initLevelFlag(int level)
{
	lightLevelFlag(level);
	mAnimator.initFlagMotions(level);
}

/**
 * @todo: Documentation
 */
void UfoItem::startLevelFlag(int flag)
{
	lightLevelFlag(flag);
	zen::particleGenerator* efx;
	Vector3f pos = mSRT.t;
	if (playerState->mShipUpgradeLevel == 5) {
		efx = effectMgr->create(EffectMgr::EFF_Rocket_Complete1, pos, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 0.0f, 1.0f));
		efx = effectMgr->create(EffectMgr::EFF_Rocket_Complete2, pos, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 0.0f, 1.0f));
	} else {
		pos.y += 60.0f;
		efx = effectMgr->create(EffectMgr::EFF_Rocket_C, pos, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 0.0f, 1.0f));
	}
	mAnimator.startFlagMotions(flag);
}

/**
 * @todo: Documentation
 */
void UfoItem::lightLevelFlag(int flag)
{
	f32 rate = 0.0f;
	if (flag > 0) {
		rate = 30.0f;
	}

	for (int i = 0; i < 4; i++) {
		mLightAnims[i].start(flag);
		mLightAnims[i].setSpeed(rate);
	}

	FORCE_DONT_INLINE;
}

/**
 * @todo: Documentation
 */
void UfoItem::setJetEffect(int level, bool doSmokeEffects)
{
	int i, j;
	if (level > 0) {
		mJetLevel        = level;
		int jetLevels[6] = { 1, 1, 2, 2, 3, 3 };
		int engine; // idk why you wanna define this up here kando
		int stage = playerState->mShipUpgradeLevel - 2;
		PRINT("*** UFO LEVEL %d : JET LEVEL %d\n", playerState->mShipUpgradeLevel, jetLevels[playerState->mShipUpgradeLevel]);
		u32 tags[4] = { 'eng1', 'eng2', 'eng3', 'eng4' };
		int offset  = 0;
		if (playerState->mShipUpgradeLevel <= 1) {
			stage  = 4;
			offset = 1;
		}

		// reset all active ones first
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (mEngineParticleGenList[i][j]) {
					effectMgr->kill(mEngineParticleGenList[i][j], false);
					mEngineParticleGenList[i][j] = nullptr;
				}
			}
		}

		int type;
		for (type = 0; type < 4; type++) {
			for (engine = 0; engine < 4; engine++) { // engine number
				CollPart* coll = mCollInfo->getSphere(tags[engine]);
				switch (type) {
				case 0:
					mEngineParticleGenList[engine][3]
					    = effectMgr->create(effects[stage + engine * offset][0], coll->mCentre, nullptr, nullptr);
					if (mEngineParticleGenList[engine][3]) {
						mEngineParticleGenList[engine][3]->setEmitPosPtr(&coll->mCentre);
					}
					break;

				case 1:
					mEngineParticleGenList[engine][2]
					    = effectMgr->create(effects[stage + engine * offset][1], coll->mCentre, nullptr, nullptr);
					if (mEngineParticleGenList[engine][2]) {
						mEngineParticleGenList[engine][2]->setEmitPosPtr(&coll->mCentre);
						mEngineParticleGenList[engine][2]->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
					}
					break;
				case 2:
					// don't do smoke effect if we've fixed enough of the ship
					if (doSmokeEffects && playerState->mShipUpgradeLevel != 5) {
						PRINT("SMOKE * CB *\n");
						mEngineParticleGenList[engine][1]
						    = effectMgr->create(effects[stage + engine * offset][2], coll->mCentre, nullptr, nullptr);
						if (mEngineParticleGenList[engine][1]) {
							mEngineParticleGenList[engine][1]->setEmitPosPtr(&coll->mCentre);
						}
					}
					break;
				case 3:
					// don't do smoke effect if we've fixed enough of the ship
					if (doSmokeEffects && playerState->mShipUpgradeLevel != 5) {
						PRINT("SMOKE * CA *\n");
						mEngineParticleGenList[engine][0]
						    = effectMgr->create(effects[stage + engine * offset][3], coll->mCentre, nullptr, nullptr);
						if (mEngineParticleGenList[engine][0]) {
							mEngineParticleGenList[engine][0]->setEmitPosPtr(&coll->mCentre);
							mEngineParticleGenList[engine][0]->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
						}
					}
					break;
				}
			}
		}
		return;
	}

	// reset all active effects
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (mEngineParticleGenList[i][j]) {
				effectMgr->kill(mEngineParticleGenList[i][j], false);
				mEngineParticleGenList[i][j] = nullptr;
			}
		}
	}
	// invalid jet level, set it back to 0
	mJetLevel = 0;
}

/**
 * @todo: Documentation
 */
UfoItem::LightAnimator::LightAnimator()
{
	mDyn   = nullptr;
	mSpeed = 0.0f;
	mFrame = 0.0f;
	mType  = 0;
}

/**
 * @todo: Documentation
 */
void UfoItem::LightAnimator::start(int id)
{
	mType = id;
	if (id > 0) {
		mFrame = (id - 1) * 20.0f;
	} else {
		mFrame = 19.0f;
	}
	setSpeed(30.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000DC
 */
void UfoItem::LightAnimator::update()
{
	if (mType) {
		f32 frame = 20.0f * (mType - 1);
		mFrame += mSpeed * gsys->getFrameTime();
		if (mFrame >= 20.0f + frame - 1.0f) {
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

/**
 * @todo: Documentation
 */
Vector3f UfoItem::getGoalPos()
{
	playerState->isUfoBroken();
	return mCollInfo->getSphere('gol1')->mCentre;
}

/**
 * @todo: Documentation
 */
f32 UfoItem::getGoalPosRadius()
{
	playerState->isUfoBroken();
	return mCollInfo->getSphere('gol1')->mRadius;
}

/**
 * @todo: Documentation
 */
Vector3f UfoItem::getSuckPos()
{
	u32 tag = 'suc0';
	if (!playerState->isUfoBroken()) {
		tag = 'suc1';
	}
	return mCollInfo->getSphere(tag)->mCentre;
}

/**
 * @todo: Documentation
 */
void UfoItem::suckMe(Pellet* pelt)
{
	PRINT("UFO ** SUCK PELLET\n");
	if (playerState->isUfoBroken()) {
		mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::WaitTutorial, this));
	} else {
		mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::Wait, this));
	}

	Navi* navi = naviMgr->getNavi();
	mAnimator.setMotionSpeed(0, 30.0f);
	playEventSound(this, SE_UFO_PARTSIN);
}

/**
 * @todo: Documentation
 */
void UfoItem::startYozora()
{
	// "start night sky"
	mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::Wait));
	mAnimator.setMotionSpeed(0, 0.0f);

	u8 level    = playerState->mShipUpgradeLevel;
	int vals[6] = { 1, 1, 2, 2, 3, 3 };
	setJetEffect(vals[level], true); // do smoke
	PRINT("** START YOZORA\n");
}

/**
 * @todo: Documentation
 */
void UfoItem::startGalaxy()
{
	mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::Wait));
	mAnimator.setMotionSpeed(0, 0.0f);

	u8 level    = playerState->mShipUpgradeLevel;
	int vals[6] = { 1, 1, 2, 2, 3, 3 };
	setJetEffect(vals[level], false); // don't do smoke
	PRINT("** START GALAXY\n");
}

/**
 * @todo: Documentation
 */
void UfoItem::finishSuck(Pellet* pelt)
{
	if (!playerState->isTutorial()) {
		Vector3f pos                = getSuckPos();
		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Rocket_Gep, pos, nullptr, nullptr);
		if (efx) {
			Vector3f dir(sinf(mFaceDirection), 0.0f, cosf(mFaceDirection));
			efx->setEmitDir(dir);
		}
	}
	mShipUpgradeLevel    = playerState->mShipUpgradeLevel;
	PelletConfig* config = pelt->mConfig;
	if (config->mRepairAnimJointIndex != -1) {
		playerState->getUfoParts(config->mModelId.mId, false);
	} else {
		playerState->getUfoParts(config->mModelId.mId, true);
	}
	mAnimator.setMotionSpeed(0, 30.0f);
}

/**
 * @todo: Documentation
 */
void UfoItem::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	int anim = mAnimator.getMotionIndex(0);
	if (event.mEventType == KEY_Finished) {
		PRINT("FINISHED --------- motion = %d\n", anim);
	}
	switch (anim) {
	case 16:
		switch (event.mEventType) {
		case KEY_Action0:
			mAnimator.setMotionSpeed(0, 0.0f);
			break;
		case KEY_Finished:
			mAnimator.setMotionSpeed(0, 0.0f);
			break;
		}
		break;
	case 0:
	case 1:
		switch (event.mEventType) {
		case KEY_Action0:
			mAnimator.setMotionSpeed(0, 0.0f);
			break;
		case KEY_Finished:
			playerState->ufoAssignStart();
			mAnimator.setMotionSpeed(0, 0.0f);
			PRINT("*** SET UFO MOTION SPEED 000\n");
			break;
		case KEY_PlayEffect:
			switch (event.mValue) { // yes this is a switch in a switch in a switch
			case 0:
				if (anim == 0) {
					effectMgr->create(EffectMgr::EFF_Rocket_Nke1, mSRT.t, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Nke2, mSRT.t, nullptr, nullptr);
				}
				break;
			case 2:
				if (anim == 0) {
					effectMgr->create(EffectMgr::EFF_CloudOfDust_1, mSRT.t, nullptr, nullptr);
				} else {
					effectMgr->create(EffectMgr::EFF_CloudOfDust_1, mSRT.t, nullptr, nullptr);
				}
				break;
			case 3:
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
		switch (event.mEventType) {
		case KEY_Finished:
			break;
		case KEY_PlayEffect:
			switch (event.mValue) {
			case 0:
				u8 level    = playerState->mShipUpgradeLevel;
				int vals[6] = { 1, 1, 2, 2, 3, 3 };
				setJetEffect(vals[level], false);
				break;
			case 2:
				if (playerState->hasUfoRightControl()) {
					setPca2Effect(true);
				}
				break;
			case 3:
				if (playerState->hasUfoLeftControl()) {
					setPca1Effect(true);
				}
				break;
			case 1:
				switch (playerState->mShipUpgradeLevel) {
				case 0:
				case 1:
					effectMgr->create(EffectMgr::EFF_Rocket_JetG01, mSRT.t, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Fkm1, mSRT.t, nullptr, nullptr);
					break;
				case 2:
				case 3:
					effectMgr->create(EffectMgr::EFF_Rocket_JetG02, mSRT.t, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Fkm1, mSRT.t, nullptr, nullptr);
					break;
				case 4:
					effectMgr->create(EffectMgr::EFF_Rocket_JetG03, mSRT.t, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Fkm1, mSRT.t, nullptr, nullptr);
					break;
				case 5:
					effectMgr->create(EffectMgr::EFF_Rocket_Bstg, mSRT.t, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Bst1db, mSRT.t, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_Bst1da, mSRT.t, nullptr, nullptr);
					break;
				}
				// no break here?
			case 9:
				if (playerState->mShipUpgradeLevel == 5) {
					CollPart* coll = mCollInfo->getSphere('gcen');
					zen::particleGenerator* efx;
					efx = effectMgr->create(EffectMgr::EFF_Rocket_Bst1fb, coll->mCentre, nullptr, nullptr);
					efx->setEmitPosPtr(&coll->mCentre);
					efx = effectMgr->create(EffectMgr::EFF_Rocket_Bst1fa, coll->mCentre, nullptr, nullptr);
					efx->setEmitPosPtr(&coll->mCentre);
					Vector3f nrm(1.0f, 0.0f, 0.0f);
					efx->setOrientedNormalVector(nrm);
					efx = effectMgr->create(EffectMgr::EFF_Rocket_Bst1cb, coll->mCentre, nullptr, nullptr);
					efx->setEmitPosPtr(&coll->mCentre);
				}
				break;
			}
		}
		break;
	}
}

/**
 * @todo: Documentation
 */
bool UfoItem::needShadow()
{
	return false;
}

/**
 * @todo: Documentation
 */
UfoItem::UfoItem(CreatureProp* prop, UfoShapeObject* shape)
    : Suckable(OBJTYPE_Ufo, prop)
{
	for (int i = 0; i < 6; i++) {
		mTroubleFxGenList[i] = nullptr;
	}
	mShipModel = shape;
	mSRT.s.set(1.0f, 1.0f, 1.0f);
	mDynMat = nullptr;

	ShapeDynMaterials* mat = shape->mShape->instanceMaterials(15);
	mLightAnims[0].mDyn    = mat;
	mat->mParent           = mDynMat;
	mDynMat                = mat;

	mat                 = shape->mShape->instanceMaterials(52);
	mLightAnims[1].mDyn = mat;
	mat->mParent        = mDynMat;
	mDynMat             = mat;

	mat                 = shape->mShape->instanceMaterials(51);
	mLightAnims[2].mDyn = mat;
	mat->mParent        = mDynMat;
	mDynMat             = mat;

	mat                 = shape->mShape->instanceMaterials(40);
	mLightAnims[3].mDyn = mat;
	mat->mParent        = mDynMat;
	mDynMat             = mat;
}

/**
 * @todo: Documentation
 */
bool UfoItem::ignoreAtari(Creature*)
{
	return false;
}

/**
 * @todo: Documentation
 */
void UfoItem::startTakeoff()
{
	int idx        = playerState->mShipUpgradeLevel - 1;
	int motions[5] = { UfoMotion::Takeoff1, UfoMotion::Takeoff1, UfoMotion::Takeoff2, UfoMotion::Takeoff3, UfoMotion::Takeoff3 };
	if (idx < 0) {
		idx = 0;
	}
	mAnimator.startMotion(0, &PaniMotionInfo(motions[idx], this));
	mAnimator.setMotionSpeed(0, 30.0f);
	UtEffectMgr::kill(mConeEffectId);
	playerState->startSpecialMotions();
}

/**
 * @todo: Documentation
 */
void UfoItem::startAI(int)
{
	mShouldLightActivate = false;
	mIsMenuOpen          = false;

	if (playerState->isTutorial()) {
		setTroubleEffect(true);
	} else {
		setTroubleEffect(false);
		effectMgr->create(EffectMgr::EFF_Rocket_Land, mSRT.t, nullptr, nullptr);
	}

	mConeEffectId = KandoEffect::UfoSuck;

	// This is an incredibly dumb thing for them to do, but I SAW THAT THEY DID THIS!!!
	// I COULD SEEEEE THEY WROTE THIS INSTEAD OF TWO FOR LOOPS!!!
	zen::particleGenerator** ptclGen = (zen::particleGenerator**)mEngineParticleGenList;
	for (int i = 0; i < 16; i++) {
		ptclGen[i] = nullptr;
	}

	// NONMATCHING HERE - addi vs mr memes :')

	setJetEffect(0, false);
	setPca1Effect(false);
	setPca2Effect(false);

	mNeedPathfindRefresh = true;

	mSeContext = &mShipSe;
	mSeContext->setContext(this, 7);
	mCollInfo = new CollInfo(16);
	mCollInfo->initInfo(mShipModel->mShape, nullptr, nullptr);
	mWaypointID = routeMgr->findNearestWayPoint('test', mSRT.t, false)->mIndex;
	setMotionSpeed(30.0f);
	mSpotlightPosition   = mSRT.t;
	mSpotlightPosition.y = mapMgr->getMinY(mSRT.t.x, mSRT.t.z, true);
	mAnimator.init(mShipModel, itemMgr->mUfoMotionTable);

	if (playerState->isUfoBroken()) {
		mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::WaitTutorial));
		playEventSound(this, SE_UFO_DESTROY);
	} else {
		mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::Wait));
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
			mSpots[i].mAngleOffset  = i * 2.0943952f;
			mSpots[i].mRadius       = 9.0f;
			mSpots[i].mRotationTime = 0.0f;
		}
	} else {
		setSpotActive(false);
	}
}

/**
 * @todo: Documentation
 */
f32 UfoItem::getSize()
{
	return 10.0f;
}

/**
 * @todo: Documentation
 */
f32 UfoItem::getiMass()
{
	return 0.0f;
}

/**
 * @todo: Documentation
 */
bool UfoItem::accessible()
{
	int anim = mAnimator.getMotionIndex(0);

	if (gameflow.mWorldClock.mTimeOfDay > gameflow.mParameters->mEndHour() - 0.2f) {
		PRINT("tod = %f : endhour = %f\n", gameflow.mWorldClock.mTimeOfDay, gameflow.mParameters->mEndHour());
		return false;
	}

	if (!playerState->isTutorial() && (anim == 1 || anim == 16) && mAnimator.getMotionSpeed(0) <= 0.0f) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
void UfoItem::startAccess()
{
	mIsMenuOpen = true;
	startConeEffect(false);

	mAnimator.startMotion(0, &PaniMotionInfo(UfoMotion::OpenClose, this));
	mAnimator.setMotionSpeed(0, 30.0f);
}

/**
 * @todo: Documentation
 */
void UfoItem::finishAccess()
{
	mIsMenuOpen = false;
	UtEffectMgr::kill(mConeEffectId);
	mAnimator.setMotionSpeed(0, 30.0f);
}

/**
 * @todo: Documentation
 */
void UfoItem::update()
{
	updateTroubleEffect();
	mVelocity.set(0.0f, 0.0f, 0.0f);
	ItemCreature::update();
	mAnimator.updateAnimation();
	mSRT.t = mSpotlightPosition;
}

/**
 * @todo: Documentation
 */
void UfoItem::setPca1Effect(bool set)
{
	mIsPca1FxActive = set;
	if (set) {
		Vector3f dir(1.0f, 0.0f, 0.0f);
		dir.rotate(mWorldMtx);

		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Rocket_PCA1, mPca1FxPosition, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);

		efx = effectMgr->create(EffectMgr::EFF_Rocket_PCA2, mPca1FxPosition, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);
	}
}

/**
 * @todo: Documentation
 */
void UfoItem::setPca2Effect(bool set)
{
	mIsPca2FxActive = set;
	if (set) {
		Vector3f dir(-1.0f, 0.0f, 0.0f);
		dir.rotate(mWorldMtx);

		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Rocket_PCA1, mPca2FxPosition, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);

		efx = effectMgr->create(EffectMgr::EFF_Rocket_PCA2, mPca2FxPosition, nullptr, nullptr);
		efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		efx->setEmitDir(dir);
	}
}

/**
 * @todo: Documentation
 */
void UfoItem::refresh(Graphics& gfx)
{
	Matrix4f mtx;
	Vector3f pos = mSRT.t;
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, pos);

	if (!gfx.mCamera->isPointVisible(mSRT.t, 200.0f)) {
		enableAICulling();
	} else {
		disableAICulling();
	}
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	gfx.useMatrix(Matrix4f::ident, 0);
	demoDraw(gfx, &mtx);
}

/**
 * @todo: Documentation
 */
void UfoItem::demoDraw(Graphics& gfx, immut Matrix4f* mtx)
{
	for (int i = 0; i < 4; i++) {
		mLightAnims[i].update();
	}

	mAnimator.updateContext();
	mShipModel->mShape->updateAnim(gfx, *mtx, nullptr);

	if (gameflow.mMoviePlayer->mIsActive || aiCullable()) {
		mShipModel->mShape->drawshape(gfx, *gfx.mCamera, mDynMat);
		playerState->renderParts(gfx, mShipModel->mShape);
	}

	Vector3f pos;
	STACK_PAD_VAR(1);
	pos.set(0.0f, 14.0f, 0.0f);
	mShipModel->mShape->calcJointWorldPos(gfx, 48, pos);
	mPca2FxPosition = pos;

	pos.set(0.0f, 14.0f, 0.0f);
	mShipModel->mShape->calcJointWorldPos(gfx, 49, pos);
	mPca1FxPosition = pos;

	if (playerState->isTutorial()) {

		pos.set(13.1f, -98.4f, -2.0f);
		mShipModel->mShape->calcJointWorldPos(gfx, 2, pos);
		mTroubleFxPositionList[0] = pos;

		pos.set(-9.2f, -68.1f, 28.6f);
		mShipModel->mShape->calcJointWorldPos(gfx, 2, pos);
		mTroubleFxPositionList[1] = pos;

		mTroubleFxPositionList[2] = mTroubleFxPositionList[0];
		mTroubleFxPositionList[3] = mTroubleFxPositionList[1];

		pos.set(-22.2f, 4.9f, -25.0f);
		mShipModel->mShape->calcJointWorldPos(gfx, 41, pos);
		mTroubleFxPositionList[4] = pos;

		pos.set(0.0f, -93.0f, 0.0f);
		mShipModel->mShape->calcJointWorldPos(gfx, 2, pos);
		mTroubleFxPositionList[5] = pos;
	}

	mCollInfo->updateInfo(gfx, false);
	for (int i = 0; i < 3; i++) {
		CollPart* part = mCollInfo->getSphere('gol1');
		if (part) {
			f32 anglePosition = mFaceDirection + mSpots[i].mAngleOffset;

			if (mShouldLightActivate) {
				mSpots[i].mRotationTime += gsys->getFrameTime() * (12.0f * PI);
				if (mSpots[i].mRotationTime > TAU) {
					mSpots[i].mRotationTime = 0.0f;
				}
				anglePosition += mSpots[i].mRotationTime;
			}

			Vector3f dir(mSpots[i].mRadius * sinf(anglePosition), 0.0f, mSpots[i].mRadius * cosf(anglePosition));
			mSpots[i].mPosition = part->mCentre + dir;
		}
	}

	if (mNeedPathfindRefresh) {
		mWaypointID   = routeMgr->findNearestWayPoint('test', getGoalPos(), false)->mIndex;
		Vector3f goal = getGoalPos();
		PRINT("*** UFO ROUTE INDEX = %d (%.1f %.1f %.1f)\n", mWaypointID, goal.x, goal.y, goal.z);
		mNeedPathfindRefresh = false;
	}
}
