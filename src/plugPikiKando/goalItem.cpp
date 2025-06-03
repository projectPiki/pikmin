#include "GoalItem.h"
#include "EffectMgr.h"
#include "DebugLog.h"
#include "Route.h"
#include "SoundMgr.h"
#include "Pellet.h"
#include "Piki.h"
#include "BaseInf.h"
#include "GameStat.h"
#include "gameflow.h"
#include "PlayerState.h"
#include "Graphics.h"
#include "MoviePlayer.h"
#include "PikiMgr.h"
#include "ItemObject.h"
#include "PikiState.h"
#include "NaviMgr.h"
#include "CreatureCollPart.h"

// this nonsense is specifically to get the sdata ordered correctly
// GoalItem::startAI needs to generate these Vector3f floats before earlier functions in the file
// however, this hackiness below resolves the mismatch.
// the 0.0f generate in sbss if not in an array. best solution we have found.
// feel free to find a more elegant solution. inlines mess up the stack order. good luck

static f32 posX = 1.0f;
static f32 posY = 1.0f;
static f32 posZ = 1.0f;
static f32 rotateX[1] = { 0.0f };
static f32 rotateY[1] = { 0.0f };
static f32 rotateZ[1] = { 0.0f };

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
DEFINE_PRINT("goalItem")

static u32 leg_ids[3] = { 'leg1', 'leg2', 'leg3' };

u8 GoalItem::demoHideFlag;

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
static void printMatrix(char*, Matrix4f&)
{
}

/*
 * --INFO--
 * Address:	800EA714
 * Size:	000040
 */
bool GoalItem::insideSafeArea(Vector3f& pos)
{
	Vector3f diff = pos - mPosition;
	if (diff.x * diff.x + diff.z * diff.z < 2500.0f) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	800EA754
 * Size:	000760
 */
void GoalItem::playEffect(int id)
{
	switch (mItemAnimator.getCurrentMotionIndex()) {
	case 9:
	case 10:
	case 11:
		switch (id) {
		case 0:
			effectMgr->create(EffectMgr::EFF_Rocket_LandS, mPosition, nullptr, nullptr);
			break;
		case 1:
			CollPart* part = mCollInfo->getSphere('bas1');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			break;
		case 2:
			part = mCollInfo->getSphere('bas1');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			part = mCollInfo->getSphere('bas2');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			part = mCollInfo->getSphere('bas3');
			effectMgr->create(EffectMgr::EFF_Rocket_SmokeD, part->mCentre, nullptr, nullptr);
			break;
		case 3:
			setFlowEffect(false);
			break;
		case 4:
			setFlightLight(false);
			break;
		}
		break;
	case 6:
	case 7:
	case 8:
		switch (id) {
		case 0:
			setFlowEffect(true);
			break;
		case 1:
			startConeShrink();
			break;
		case 2:
			effectMgr->create(EffectMgr::EFF_Rocket_TakeS, mPosition, nullptr, nullptr);
			break;
		case 3:
			setFlightLight(true);
			break;
		}
		break;
	case 12:
		if (aiCullable()) {
			Vector3f pos[4];
			pos[0] = mCollInfo->getSphere('eff1')->mCentre;
			pos[1] = mCollInfo->getSphere('eff2')->mCentre;
			pos[2] = mCollInfo->getSphere('eff3')->mCentre;
			pos[3] = mCollInfo->getSphere('piki')->mCentre;
			if (id == 0) {
				effectMgr->create(EffectMgr::EFF_Onyon_Sparkles, pos[3], nullptr, nullptr);
			}

			int randIdx                 = (int)((3.0f * gsys->getRand(1.0f)) * 0.999999f);
			zen::particleGenerator* gen = effectMgr->create(EffectMgr::EFF_Onyon_Puff, pos[randIdx], nullptr, nullptr);
			if (gen) {
				int legIDs[3] = { 2, 1, 0 };

				Vector3f test = -1.0f * mRope[2 * legIDs[randIdx]]->mRopeDirection;
				gen->setEmitDir(test);
			}

			playEventSound(this, EffectMgr::EFF_Bridge_FinishStage);
		}
		break;
	case 3:
	case 4:
	case 5:
		switch (id) {
		case 0:
			CollPart* coll = mCollInfo->getSphere('piki');
			if (coll) {
				ERROR("no flow!\n");
			}
			Vector3f pos(coll->mCentre);
			effectMgr->create(EffectMgr::EFF_UfoPart_KafunB, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Kafun_BS, pos, nullptr, nullptr);
			break;
		case 1:
			Vector3f pos2(mPosition);
			if (mOnionColour == Blue) {
				effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, pos2, nullptr, nullptr);
				zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Onyon_Ripples2, pos2, nullptr, nullptr);
				if (efx) {
					efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
				}
				efx = effectMgr->create(EffectMgr::EFF_Onyon_Ripples1, pos2, nullptr, nullptr);
				if (efx) {
					efx->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
				}
			} else {
				effectMgr->create(EffectMgr::EFF_Rocket_Suck1, pos2, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_Suck2, pos2, nullptr, nullptr);
			}
			break;
		case 2:
			routeMgr->getWayPoint('test', mWaypointIdx)->setFlag(true);
			if (mOnionColour == Blue) {
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
			}
			break;
		case 3:
			if (mOnionColour == Blue) {
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas2')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_BubblesSmall, mCollInfo->getSphere('bas3')->mCentre, nullptr, nullptr);
			} else {
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas1')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas2')->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, mCollInfo->getSphere('bas3')->mCentre, nullptr, nullptr);
			}
			break;
		case 4:
			enableColorAnim();
			mColourFadeRate = 20.0f;
			break;
		}
		break;
	}

	PRINT("Fake", id ? "fake" : "fake");
}

/*
 * --INFO--
 * Address:	800EAEB4
 * Size:	0000B4
 */
void GoalItem::setFlowEffect(bool set)
{
	_3E4 = set;

	if (set) {
		if (!mSuckEfx) {
			CollPart* part = mCollInfo->getSphere('piki');
			if (!part) {
				ERROR("no flow part!\n");
			}
			mSuckEfx = effectMgr->create(EffectMgr::EFF_Kafun_NG, part->mCentre, nullptr, nullptr);
			if (mSuckEfx) {
				mSuckEfx->setEmitPosPtr(&part->mCentre);
			}
		}
	} else if (mSuckEfx) {
		effectMgr->kill(mSuckEfx, false);
		mSuckEfx = nullptr;
	}
}

/*
 * --INFO--
 * Address:	800EAF68
 * Size:	000178
 */
void GoalItem::setSpotActive(bool set)
{
	mSpotEffectActive = set;

	if (mSpotEffectActive) {
		EffectMgr::effTypeTable efxIDs[3]
		    = { EffectMgr::EFF_Onyon_BeaconRingBlue, EffectMgr::EFF_Onyon_BeaconRingRed, EffectMgr::EFF_Onyon_BeaconRingYellow };

		if (!mSpotEfx) {
			mSpotEfx = effectMgr->create(efxIDs[mOnionColour], mPosition, nullptr, nullptr);
			if (mSpotEfx) {
				mSpotEfx->setEmitPosPtr(&mPosition);
			}
			SeSystem::playSysSe(SYSSE_CONTAINER_OK);
		}
	} else {
		if (mSpotEfx) {
			SeSystem::stopSysSe(SYSSE_CONTAINER_OK);
			effectMgr->kill(mSpotEfx, false);
			mSpotEfx = nullptr;
		}
	}

	if (mSpotEffectActive) {
		EffectMgr::effTypeTable efxIDs[3]
		    = { EffectMgr::EFF_Onyon_HaloRingBlue, EffectMgr::EFF_Onyon_HaloRingRed, EffectMgr::EFF_Onyon_HaloRingYellow };

		if (!mHaloEfx) {
			mHaloEfx = effectMgr->create(efxIDs[mOnionColour], mPosition, nullptr, nullptr);
			if (mHaloEfx) {
				mHaloEfx->setEmitPosPtr(&mPosition);
			}
		}
	} else {
		if (mHaloEfx) {
			effectMgr->kill(mHaloEfx, false);
			mHaloEfx = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	800EB0E0
 * Size:	000058
 */
bool GoalItem::invoke(zen::particleGenerator* efx, zen::particleMdl* mdl)
{
	if (mdl) {
		mdl->mGlobalPosition = mCollInfo->getSphere('llit')->mCentre;
	}
	return true;
}

/*
 * --INFO--
 * Address:	800EB138
 * Size:	000008
 */
void GoalItem::setFlightLight(bool a1)
{
	_3EC = a1;
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	800EB140
 * Size:	000024
 */
Vector3f GoalItem::getSuckPos()
{
	Vector3f ret = mPosition;
	ret.y += 74.0f;
	return ret;
}

/*
 * --INFO--
 * Address:	800EB164
 * Size:	0000F4
 */
void GoalItem::suckMe(Pellet* item)
{
	PelletConfig* config = item->mConfig;
	int pikiNum;
	if (mOnionColour == config->mPelletType()) {
		pikiNum = config->mMatchingOnyonSeeds();
	} else {
		pikiNum = config->mNonMatchingOnyonSeeds();
	}

	if (pikiNum < 0) {
		mCounter += 2;
		MsgUser msg(0);
		C_SAI(this)->procMsg(this, &msg);
		playEventSound(this, SE_CONTAINER_HANABI);
		playEventSound(this, SE_CONTAINER_PELLETIN2);
	} else {
		mCurrAnimId += pikiNum;
		MsgUser msg(0);
		C_SAI(this)->procMsg(this, &msg);
		playEventSound(this, SE_CONTAINER_PELLETIN2);
	}
}

/*
 * --INFO--
 * Address:	800EB258
 * Size:	0000C4
 */
void GoalItem::enterGoal(Piki* piki)
{
	int old = mItemAnimator.mMotionIdx;
	playEventSound(this, SE_PIKI_GOHOME);
	pikiInfMgr.incPiki(piki);
	mHeldPikis[piki->mHappa]++;
	piki->setEraseKill();
	piki->kill(false);
	GameStat::containerPikis.inc(piki->mColor);
	GameStat::update();
	if (old == 1) {
		C_SAI(this)->start(this, GoalAI::GOAL_Wait);
	}
}

/*
 * --INFO--
 * Address:	800EB31C
 * Size:	000020
 */
void GoalItem::exitPikis(int pikis)
{
	mIsDispensingPikis = true;
	mPikisToExit += pikis;
	mPikiSpawnTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	800EB33C
 * Size:	00027C
 */
Piki* GoalItem::exitPiki()
{
	int leg = gsys->getRand(1.0f) * 3.0f;
	if (leg >= 3) {
		leg = 2;
	}
	CollPart* legColl          = mCollInfo->getSphere(leg_ids[leg]);
	pikiMgr->containerExitMode = 1;
	Piki* piki                 = (Piki*)pikiMgr->birth();
	pikiMgr->containerExitMode = 0;
	if (!piki) {
		ERROR("*** PIKI BIRTH FAILED !!!\n");
		return nullptr;
	}

	Navi* navi = naviMgr->getNavi();
	piki->init(navi);
	piki->resetPosition(legColl->mCentre);

	// always pull the highest stage pikmin out first
	int happa;
	if (pikiInfMgr.mPikiCounts[mOnionColour][2] > 0) {
		happa = 2;
	} else if (pikiInfMgr.mPikiCounts[mOnionColour][1] > 0) {
		happa = 1;
	} else {
		happa = 0;
	}
	piki->setFlower(happa);
	piki->initColor(mOnionColour);
	pikiInfMgr.decPiki(piki);
	piki->mScale.set(1.0f, 1.0f, 1.0f);
	piki->mFSM->transit(piki, PIKISTATE_Normal);
	piki->startRope(mRope[leg * 2], 1.0f);
	piki->changeMode(12, nullptr);
	mHeldPikis[happa]--;
	GameStat::containerPikis.dec(piki->mColor);
	GameStat::workPikis.inc(piki->mColor);
	GameStat::update();
	playEventSound(this, SE_PIKI_OUTHOME);

	if (mHeldPikis[0] + mHeldPikis[1] + mHeldPikis[2] == 0) {
		C_SAI(this)->start(this, GoalAI::GOAL_Wait);
	}
	return piki;
}

/*
 * --INFO--
 * Address:	800EB5B8
 * Size:	000008
 */
bool GoalItem::needShadow()
{
	return false;
}

/*
 * --INFO--
 * Address:	800EB5C0
 * Size:	000110
 */
GoalItem::GoalItem(CreatureProp* prop, ItemShapeObject* shape1, ItemShapeObject* shape2, ItemShapeObject* shape3, SimpleAI* ai)
    : Suckable(16, prop)
{
	mOnionColour     = 0;
	mItemShapeObject = nullptr;
	_438[0]          = shape1;
	_438[1]          = shape2;
	_438[2]          = shape3;
	mItemShapeObject = _438[0];
	mStateMachine    = ai;
	mCollInfo        = new CollInfo(15);
	mHaloEfx         = nullptr;
	mSpotEfx         = nullptr;
	mSuckEfx         = nullptr;
}

/*
 * --INFO--
 * Address:	800EB6D0
 * Size:	00001C
 */
bool GoalItem::ignoreAtari(Creature* obj)
{
	if (obj->mObjType == OBJTYPE_GemItem) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800EB6EC
 * Size:	000044
 */
void GoalItem::setColorType(int type)
{
	mOnionColour     = type;
	mItemShapeObject = _438[type];
	mItemShapeObject->mShape->makeInstance(mDynMaterial, 0);
}

/*
 * --INFO--
 * Address:	800EB730
 * Size:	00007C
 */
void GoalItem::startTakeoff()
{
	setMotionSpeed(30.0f);
	startMotion(mOnionColour + 6);
	int i = 0;
	while (i < 10) {
		PRINT("** GOAL TAKEOFF !\n");
		i++;
	}
	setCreatureFlag(CF_IsAiDisabled);
}

/*
 * --INFO--
 * Address:	800EB7AC
 * Size:	000104
 */
void GoalItem::startLand()
{
	_3CC = 0;
	startMotion(mOnionColour + 9);
	setMotionSpeed(30.0f);
	_3FC = mSpotModelEff->mSRT.mScale;
	setFlowEffect(true);
	setFlightLight(true);
	mSpotModelEff->mSRT.mScale.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800EB8B0
 * Size:	000030
 */
void GoalItem::startConeShrink()
{
	mIsClosing     = true;
	mConeSizeTimer = 0.8f;
	_3FC           = mSpotModelEff->mSRT.mScale;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void GoalItem::updateConeShrink()
{
	if (!mIsClosing) {
		return;
	}

	f32 test       = mConeSizeTimer / 0.8f;
	Vector3f scale = _3FC;
	scale.x *= test;
	scale.z *= test;

	mSpotModelEff->mSRT.mScale = scale;

	mConeSizeTimer -= gsys->getFrameTime();

	if (mConeSizeTimer <= 0.0f) {
		mSpotModelEff->mSRT.mScale.set(0.0f, 0.0f, 0.0f);
		mIsClosing = false;
	}
}

/*
 * --INFO--
 * Address:	800EB8E0
 * Size:	000014
 */
void GoalItem::startConeEmit()
{
	mIsConeEmit    = true;
	mConeSizeTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void GoalItem::updateConeEmit()
{
	if (!mIsConeEmit) {
		return;
	}

	f32 test     = mConeSizeTimer / 0.8f;
	Vector3f pos = _3FC;
	pos.x *= test;
	pos.z *= test;

	mSpotModelEff->mSRT.mScale = pos;

	mConeSizeTimer += gsys->getFrameTime();

	if (mConeSizeTimer >= 0.8f) {
		mSpotModelEff->mSRT.mScale = _3FC;
		mIsConeEmit                = false;
		C_SAI(this)->start(this, GoalAI::GOAL_Wait);
	}
}

/*
 * --INFO--
 * Address:	800EB8F4
 * Size:	000494
 */
void GoalItem::startAI(int)
{
	_3F4     = 1;
	mSpotEfx = nullptr;
	mHaloEfx = nullptr;
	setSpotActive(false);
	setFlowEffect(false);
	_3F5        = 0;
	mIsClosing  = 0;
	mIsConeEmit = false;
	mSeContext  = &_45C;
	mSeContext->setContext(this, 3);
	mHeldPikis[Leaf] = mHeldPikis[Bud] = mHeldPikis[Flower] = nullptr;
	mCollInfo->initInfo(mItemShapeObject->mShape, nullptr, nullptr);
	mWaypointIdx = routeMgr->findNearestWayPoint('test', mPosition, false)->mIndex;

    mSpotModelEff = effectMgr->create((EffectMgr::modelTypeTable)mOnionColour, mPosition, Vector3f(posX, posY, posZ), Vector3f(rotateX[0], rotateY[0], rotateZ[0]));
	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	mCurrAnimId = 0;
	mCounter    = 0;

	int i;
	for (i = 0; i < 3; i++) {
		GoalLeg* leg    = (GoalLeg*)((&this->_444) + i * 2);
		CollPart* coll  = mCollInfo->getSphere(leg_ids[i]);
		CollPart* child = coll->getChild();
		Vector3f diff   = coll->mCentre - child->mCentre;
		f32 len         = diff.length();

		leg->mFulcrum = (Fulcrum*)itemMgr->birth(OBJTYPE_Fulcrum);
		leg->mFulcrum->init(coll->mCentre);
		leg->mFulcrum->startAI(0);

		leg->mRope = (RopeItem*)itemMgr->birth(OBJTYPE_Rope);
		leg->mRope->init(child->mCentre);
		leg->mRope->setRope(leg->mFulcrum);
		leg->mRope->mRopeLength = len;
		leg->mRope->mOwner      = this;
		leg->mRope->startAI(0);
	}

	for (i = 0; i < 3; i++) {
		PRINT("****** CONTAINER %d : %d/%d/%d pikis\n", mOnionColour, mHeldPikis[Leaf], mHeldPikis[Bud], mHeldPikis[Flower]);
		mHeldPikis[i] = pikiInfMgr.mPikiCounts[mOnionColour][i];
	}

	WayPoint* wp = routeMgr->getWayPoint('test', mWaypointIdx);
	if (!playerState->bootContainer(mOnionColour) || playerState->isTutorial()) {
		setMotionSpeed(0.0f);
		C_SAI(this)->start(this, GoalAI::GOAL_BootInit);
		startConeShrink();
		enableColorAnim();
		mColourFadeRate = 0.0f;
		wp->setFlag(false);
	} else {
		setMotionSpeed(30.0f);
		mItemAnimator.startMotion(PaniMotionInfo(1));
		C_SAI(this)->start(this, GoalAI::GOAL_Wait);
		disableColorAnim();
		wp->setFlag(true);
	}
	_41C               = mPosition;
	_41C.y             = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	mIsDispensingPikis = false;
	mPikisToExit       = 0;
	mPikiSpawnTimer    = 0.0f;
}

/*
 * --INFO--
 * Address:	800EBD88
 * Size:	000074
 */
void GoalItem::startBoot()
{
	_3CC = 3;
	setMotionSpeed(30.0f);
	C_SAI(this)->start(this, GoalAI::GOAL_BootInit);
	playerState->setBootContainer(mOnionColour);
}

/*
 * --INFO--
 * Address:	800EBDFC
 * Size:	00002C
 */
void GoalItem::emitPiki()
{
	C_SAI(this)->start(this, GoalAI::GOAL_Unk2);
}

/*
 * --INFO--
 * Address:	800EBE28
 * Size:	000008
 */
f32 GoalItem::getSize()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800EBE30
 * Size:	000008
 */
f32 GoalItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800EBE38
 * Size:	0002D4
 */
void GoalItem::update()
{
	mVelocity.set(0.0f, 0.0f, 0.0f);
	ItemCreature::update();
	if (mColourAnimationEnabled) {
		mColourAnimProgress += (mColourFadeRate * mMotionSpeed * gsys->getFrameTime()) / 30.0f;
		if (mColourAnimProgress > 1.0f) {
			disableColorAnim();
		}
	}

	if (mIsClosing) {
		updateConeShrink();
	}

	if (mIsConeEmit) {
		updateConeEmit();
	}

	mPosition = _41C;

	if (mIsDispensingPikis) {
		if (mPikiSpawnTimer <= 0.0f) {
			if (!exitPiki()) {
				int mapPikis = GameStat::mapPikis;
				int mePikis  = GameStat::mePikis;
				PRINT("map=%d mePiki=%d exitC=%d", mapPikis, mePikis, mPikisToExit);
				ERROR("2d err %d %d %d", mapPikis, mePikis, mPikisToExit);
			}

			mPikisToExit--;
			if (mPikisToExit <= 0) {
				mIsDispensingPikis = false;
			}

			mPikiSpawnTimer = gsys->getRand(1.0f) * 0.1f + 0.2f;
			mPikiSpawnTimer *= 0.2f;
		} else {
			mPikiSpawnTimer -= gsys->getFrameTime();
		}
	}
}

/*
 * --INFO--
 * Address:	800EC10C
 * Size:	000378
 */
void GoalItem::refresh(Graphics& gfx)
{
	if (gameflow.mMoviePlayer->mIsActive && demoHideFlag & 1 << mOnionColour) {
		return;
	}

	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	Matrix4f mtx1;
	Vector3f pos = mPosition;
	mWorldMtx.makeSRT(mScale, mRotation, pos);
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx1);
	if (!gfx.mCamera->isPointVisible(mPosition, 200.0f)) {
		enableAICulling();
		if (!gameflow.mMoviePlayer->mIsActive) {
			mSpotModelEff->mIsVisible = false;
		}
	} else {
		disableAICulling();
		mSpotModelEff->mIsVisible = true;
	}

	gfx.setLighting(true, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	mItemAnimator.updateContext();

	f32 rate;
	if (mColourAnimationEnabled) {
		rate = int(mOnionColour * 2 + 1) - mColourAnimProgress;
	} else {
		rate = int(mOnionColour << 1);
	}
	mDynMaterial.animate(&rate);
	mItemShapeObject->mShape->updateAnim(gfx, mtx1, nullptr);
	if (aiCullable()) {
		mItemShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mDynMaterial);
	}
	mCollInfo->updateInfo(gfx, false);

	for (int i = 0; i < 3; i++) {
		GoalLeg* leg = (GoalLeg*)((&this->_444) + i * 2);
		if (pikiMgr->containerDebug) {
			PRINT("leg %d : (%.1f %.1f %.1f) \n", i, leg->mRope->mPosition.x, leg->mRope->mPosition.y, leg->mRope->mPosition.z);
		}
		CollPart* coll           = mCollInfo->getSphere(leg_ids[i]);
		CollPart* child          = coll->getChild();
		leg->mFulcrum->mPosition = coll->mCentre;
		leg->mRope->mPosition    = child->mCentre;

		Vector3f diff           = leg->mFulcrum->mPosition - leg->mRope->mPosition;
		leg->mRope->mRopeLength = diff.length();
		if (pikiMgr->containerDebug) {
			PRINT("==> (%.1f %.1f %.1f) : motion %d\n", leg->mRope->mPosition.x, leg->mRope->mPosition.y, leg->mRope->mPosition.z,
			      mItemAnimator.getCurrentMotionIndex());
			printMatrix("invCam", gfx.mCamera->mInverseLookAtMtx);
		}
	}

	mCollInfo ? "fake" : "fake";
	mCollInfo ? "fake" : "fake";
	u32 badCompiler[5];
}
