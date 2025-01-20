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

int numKeys          = 3;
f32 trKeys[3]        = { 0.0f, 13.0f, 50.0f };
static u32 leg_ids[] = { 'leg1', 'leg2', 'leg3' };

EffectMgr::effTypeTable effects[8][4] = {
	{
	    EffectMgr::EFF_Rocket_NJ3CA,
	    EffectMgr::EFF_Rocket_NJ2FB,
	    EffectMgr::EFF_Rocket_NJ2FA,
	    EffectMgr::EFF_Rocket_NJ2CB,
	},
	{
	    EffectMgr::EFF_Rocket_NJ3CA,
	    EffectMgr::EFF_Rocket_NJ2FB,
	    EffectMgr::EFF_Rocket_NJ3FA,
	    EffectMgr::EFF_Rocket_NJ3CB,
	},
	{
	    EffectMgr::EFF_Rocket_NJ3FB2,
	    EffectMgr::EFF_Rocket_NJ3FB,
	    EffectMgr::EFF_Rocket_NJ3FA,
	    EffectMgr::EFF_Rocket_NJ3CB,
	},
	{
	    EffectMgr::EFF_Rocket_NJ3FB2,
	    EffectMgr::EFF_Rocket_NJ3FB,
	    EffectMgr::EFF_Rocket_NJ3FA,
	    EffectMgr::EFF_Rocket_NJ3CB,
	},
	{
	    EffectMgr::EFF_Rocket_NJ1CA2,
	    EffectMgr::EFF_Rocket_NJ1FB,
	    EffectMgr::EFF_Rocket_NJ1FA,
	    EffectMgr::EFF_Rocket_NJ1CB,
	},
	{
	    EffectMgr::EFF_Rocket_NJ1CA3,
	    EffectMgr::EFF_Rocket_NJ1FB2,
	    EffectMgr::EFF_Rocket_NJ1FA2,
	    EffectMgr::EFF_Rocket_NJ1CB2,
	},
	{
	    EffectMgr::EFF_Rocket_NJ1CA4,
	    EffectMgr::EFF_Rocket_NJ1FB3,
	    EffectMgr::EFF_Rocket_NJ1FA3,
	    EffectMgr::EFF_Rocket_NJ1CB3,
	},
	{
	    EffectMgr::EFF_Rocket_NJ2CA,
	    EffectMgr::EFF_Rocket_NJ1FB4,
	    EffectMgr::EFF_Rocket_NJ1FA4,
	    EffectMgr::EFF_Rocket_NJ1CB4,
	},
};

static const EffectMgr::effTypeTable unusedEffects[3] = {
	EffectMgr::EFF_Onyon_HaloRingBlue,
	EffectMgr::EFF_Onyon_HaloRingRed,
	EffectMgr::EFF_Onyon_HaloRingYellow,
};

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
void UfoItem::initLevelFlag(int level)
{
	lightLevelFlag(level);
	mAnimator.initFlagMotions(level);
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
		mLightAnims[i].setSpeed(rate);
	}

	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	800E7A34
 * Size:	000390
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
				if (_4E0[i][j]) {
					effectMgr->kill(_4E0[i][j], false);
					_4E0[i][j] = nullptr;
				}
			}
		}

		int type;
		for (type = 0; type < 4; type++) {
			for (engine = 0; engine < 4; engine++) { // engine number
				CollPart* coll = mCollInfo->getSphere(tags[engine]);
				switch (type) {
				case 0:
					_4E0[engine][3] = effectMgr->create(effects[stage + engine * offset][0], coll->mCentre, nullptr, nullptr);
					if (_4E0[engine][3]) {
						_4E0[engine][3]->setEmitPosPtr(&coll->mCentre);
					}
					break;

				case 1:
					_4E0[engine][2] = effectMgr->create(effects[stage + engine * offset][1], coll->mCentre, nullptr, nullptr);
					if (_4E0[engine][2]) {
						_4E0[engine][2]->setEmitPosPtr(&coll->mCentre);
						_4E0[engine][2]->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
					}
					break;
				case 2:
					// don't do smoke effect if we've fixed enough of the ship
					if (doSmokeEffects && playerState->mShipUpgradeLevel != 5) {
						PRINT("SMOKE * CB *\n");
						_4E0[engine][1] = effectMgr->create(effects[stage + engine * offset][2], coll->mCentre, nullptr, nullptr);
						if (_4E0[engine][1]) {
							_4E0[engine][1]->setEmitPosPtr(&coll->mCentre);
						}
					}
					break;
				case 3:
					// don't do smoke effect if we've fixed enough of the ship
					if (doSmokeEffects && playerState->mShipUpgradeLevel != 5) {
						_4E0[engine][0] = effectMgr->create(effects[stage + engine * offset][3], coll->mCentre, nullptr, nullptr);
						if (_4E0[engine][0]) {
							_4E0[engine][0]->setEmitPosPtr(&coll->mCentre);
							_4E0[engine][0]->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
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
			if (_4E0[i][j]) {
				effectMgr->kill(_4E0[i][j], false);
				_4E0[i][j] = nullptr;
			}
		}
	}
	// invalid jet level, set it back to 0
	mJetLevel = 0;
}

/*
 * --INFO--
 * Address:	800E7DC4
 * Size:	00001C
 */
UfoItem::LightAnimator::LightAnimator()
{
	mDyn   = nullptr;
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
	setSpeed(30.0f);
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
	// "start night sky"
	mAnimator.startMotion(0, &PaniMotionInfo(1));
	mAnimator.setMotionSpeed(0, 0.0f);

	u8 level    = playerState->mShipUpgradeLevel;
	int vals[6] = { 1, 1, 2, 2, 3, 3 };
	setJetEffect(vals[level], true); // do smoke
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
	setJetEffect(vals[level], false); // don't do smoke
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

	// NONMATCHING HERE - addi vs mr memes :')

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

	if (gameflow.mWorldClock.mTimeOfDay > gameflow.mParameters->mEndHour() - 0.2f) {
		PRINT("tod = %f : endhour = %f\n", gameflow.mWorldClock.mTimeOfDay, gameflow.mParameters->mEndHour());
		return false;
	}

	if (!playerState->isTutorial() && (anim == 1 || anim == 16) && mAnimator.getMotionSpeed(0) <= 0.0f) {
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

	if (gameflow.mMoviePlayer->mIsActive || aiCullable()) {
		mShipModel->mShape->drawshape(gfx, *gfx.mCamera, mDynMat);
		playerState->renderParts(gfx, mShipModel->mShape);
	}

	Vector3f pos;
	u32 badCompiler;
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

		pos.set(-9.2f, -68.1f, 28.6f);
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
}
