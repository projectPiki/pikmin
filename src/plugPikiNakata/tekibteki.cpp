#include "types.h"
#include "teki.h"
#include "TekiConditions.h"
#include "CreatureProp.h"
#include "Shape.h"
#include "zen/particle.h"
#include "Graphics.h"
#include "GameStat.h"
#include "BaseInf.h"
#include "SoundMgr.h"
#include "nlib/System.h"
#include "MapMgr.h"
#include "sysNew.h"
#include "Stickers.h"
#include "MizuItem.h"
#include "Pellet.h"
#include "RadarInfo.h"
#include "TekiStrategy.h"
#include "EffectMgr.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "DebugLog.h"
#include "Creature.h"
#include "MapCode.h"
#include "AIPerf.h"
#include "AIConstant.h"
#include "Route.h"

const int BTeki::TEKI_OPTION_VISIBLE            = 1 << 0;
const int BTeki::TEKI_OPTION_SHADOW_VISIBLE     = 1 << 1;
const int BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE = 1 << 2;
const int BTeki::TEKI_OPTION_ATARI              = 1 << 3;
const int BTeki::TEKI_OPTION_ALIVE              = 1 << 4;
const int BTeki::TEKI_OPTION_ORGANIC            = 1 << 5;
const int BTeki::TEKI_OPTION_MANUAL_ANIMATION   = 1 << 7;
const int BTeki::TEKI_OPTION_GRAVITATABLE       = 1 << 8;
const int BTeki::TEKI_OPTION_INVINCIBLE         = 1 << 9;
const int BTeki::TEKI_OPTION_PRESSED            = 1 << 10;
const int BTeki::TEKI_OPTION_DRAWED             = 1 << 13;
const int BTeki::TEKI_OPTION_SHAPE_VISIBLE      = 1 << 14;
const int BTeki::TEKI_OPTION_DAMAGE_COUNTABLE   = 1 << 15;

const int BTeki::ANIMATION_KEY_OPTION_FINISHED  = 1 << KEY_Finished;
const int BTeki::ANIMATION_KEY_OPTION_ACTION_0  = 1 << KEY_Action0;
const int BTeki::ANIMATION_KEY_OPTION_ACTION_1  = 1 << KEY_Action1;
const int BTeki::ANIMATION_KEY_OPTION_ACTION_2  = 1 << KEY_Action2;
const int BTeki::ANIMATION_KEY_OPTION_LOOPSTART = 1 << KEY_LoopStart;
const int BTeki::ANIMATION_KEY_OPTION_LOOPEND   = 1 << KEY_LoopEnd;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	80143F5C
 * Size:	000064
 */
void BTeki::viewStartTrembleMotion(f32 motionSpeed)
{
	startMotion(14);
	setTekiOption(TEKIOPT_ManualAnimation);
	mMotionSpeed = motionSpeed;
}

/*
 * --INFO--
 * Address:	80143FC0
 * Size:	000008
 */
void BTeki::viewSetMotionSpeed(f32 speed)
{
	mMotionSpeed = speed;
}

/*
 * --INFO--
 * Address:	80143FC8
 * Size:	00002C
 */
void BTeki::viewDoAnimation()
{
	doAnimation();
}

/*
 * --INFO--
 * Address:	80143FF4
 * Size:	00004C
 */
void BTeki::viewFinishMotion()
{
	mTekiAnimator->finishMotion(PaniMotionInfo(-1, this));
}

/*
 * --INFO--
 * Address:	80144040
 * Size:	00001C
 */
Vector3f BTeki::viewGetScale()
{
	return mScale;
}

/*
 * --INFO--
 * Address:	8014405C
 * Size:	000018
 */
f32 BTeki::viewGetBottomRadius()
{
	return mTekiParams->getF(TPF_CorpseSize);
}

/*
 * --INFO--
 * Address:	80144074
 * Size:	000018
 */
f32 BTeki::viewGetHeight()
{
	return mTekiParams->getF(TPF_CorpseHeight);
}

/*
 * --INFO--
 * Address:	8014408C
 * Size:	0000A4
 */
void BTeki::viewDraw(Graphics& gfx, Matrix4f& mat)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mTekiAnimator->updateContext();
	mTekiShape->mShape->updateAnim(gfx, mat, nullptr);
	mTekiShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	80144130
 * Size:	000024
 */
void BTeki::viewKill()
{
	kill(false);
}

/*
 * --INFO--
 * Address:	80144154
 * Size:	00000C
 */
void BTeki::doStore(CreatureInf* info)
{
	info->mObjInfo1 = mTekiType;
	PRINT("TEKI STORE *****************************************\n");
}

/*
 * --INFO--
 * Address:	80144160
 * Size:	00000C
 */
void BTeki::doRestore(CreatureInf* info)
{
	mTekiType = (TekiTypes)info->mObjInfo1;
}

/*
 * --INFO--
 * Address:	8014416C
 * Size:	0000B0
 */
TekiShapeObject::TekiShapeObject(Shape* shape)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;
	mAnimMgr             = new AnimMgr(shape, nullptr, 0x8000, nullptr);
	mShape->overrideAnim(0, &mAnimContext);
}

/*
 * --INFO--
 * Address:	8014421C
 * Size:	000010
 */
bool BTeki::isPellet(int objType)
{
	return objType == OBJTYPE_Pellet;
}

/*
 * --INFO--
 * Address:	8014422C
 * Size:	000050
 */
f32 BTeki::calcCircleDistanceStatic(Vector3f& pos1, f32 rad1, Vector3f& pos2, f32 rad2)
{
	return qdist2(pos1.x, pos1.z, pos2.x, pos2.z) - rad1 - rad2;
}

/*
 * --INFO--
 * Address:	8014427C
 * Size:	000014
 */
bool BTeki::alwaysUpdatePlatform()
{
	return mTekiType == TEKI_Shell;
}

/*
 * --INFO--
 * Address:	80144290
 * Size:	0000A8
 */
f32 BTeki::calcSphereDistanceStatic(Vector3f& pos1, f32 rad1, Vector3f& pos2, f32 rad2)
{
	return pos1.distance(pos2) - rad1 - rad2;
}

/*
 * --INFO--
 * Address:	80144338
 * Size:	000238
 */
bool BTeki::moveTowardStatic(Vector3f& currentPosition, Vector3f& targetPosition, f32 speed, Vector3f& output)
{
	NVector3f vec1(targetPosition);
	vec1.y = 0.0f;

	NVector3f vec2(currentPosition);
	vec2.y = 0.0f;

	output.sub2(vec1, vec2);

	f32 dist = output.length();
	if (!NMathF::isZero(dist)) {
		output.normalize();
	}
	output.scale(speed);
	f32 dist2 = vec1.distance(vec2);
	return (BTeki::arrivedAt(dist2, speed)) ? true : false;
}

/*
 * --INFO--
 * Address:	80144570
 * Size:	000028
 */
bool BTeki::arrivedAt(f32 distance, f32 speed)
{
	f32 threshold = 2.0f * speed * NSystem::getFrameTime();
	return distance <= threshold;
}

/*
 * --INFO--
 * Address:	80144598
 * Size:	000398
 */
BTeki::BTeki()
    : Creature(nullptr)
{
	mObjType             = OBJTYPE_Teki;
	mLifeGauge._1C       = 1;
	mProps               = new CreatureProp();
	mPersonality         = new TekiPersonality();
	mTekiAnimator        = new PaniTekiAnimator();
	mVibrationController = new NVibrationFunction();
	mRouteWayPointMax    = 20;
	mRouteWayPoints      = new WayPoint*[mRouteWayPointMax];
	mRouteWayPointCount  = 0;
	mParticleGenerators  = new zen::particleGenerator*[4];
	mCollInfo            = new CollInfo(22);
	mSeContext           = new SeContext(this, 1);
	mParticleGenPack     = new zen::PtclGenPack(3);
}

/*
 * --INFO--
 * Address:	80144930
 * Size:	000064
 */
void BTeki::init(int tekiType)
{
	PRINT("Teki::init:%08x:%d\n", this, tekiType);
	mTekiType   = (TekiTypes)tekiType;
	mTekiParams = tekiMgr->getTekiParameters(mTekiType);
	mSearchBuffer.init(mTekiSearchData, 3);
	resetCreatureFlag(CF_Unk1 | CF_Unk10);
	Creature::init();
}

/*
 * --INFO--
 * Address:	80144994
 * Size:	000378
 */
void BTeki::reset()
{
	PRINT("Teki::reset>:%08x\n", this);
	if (tekiOptUpdateMgr) {
		mOptUpdateContext.init(tekiOptUpdateMgr);
	}

	clearTekiOptions();
	setTekiOption(TEKIOPT_Visible | TEKIOPT_ShadowVisible | TEKIOPT_LifeGaugeVisible | TEKIOPT_Atari | TEKIOPT_Alive | TEKIOPT_Organic
	              | TEKIOPT_Unk11 | TEKIOPT_ShapeVisible | TEKIOPT_DamageCountable);

	resetPosition(mPersonality->mPosition);
	setDirection(mPersonality->mFaceDirection);
	mSize             = getSize();
	mDeadState        = 0;
	mStateID          = 0;
	mReturnStateID    = 0;
	mActionStateId    = 0;
	mCurrentQueueId   = 0;
	mHealth           = getParameterF(TPF_Life);
	mStoredDamage     = 0.0f;
	mDamageCount      = 0.0f;
	_344              = -1;
	_3C0              = 0.0f;
	_3BC              = 0;
	mCurrentAnimEvent = KEY_NULL;

	clearAnimationKeyOptions();
	mMotionLoopCount = 0;
	mMotionSpeed     = 0.0f;
	mAnimationSpeed  = 0.0f;

	int i;
	for (i = 0; i < 4; i++) {
		mTargetCreatures[i].clear();
	}

	mPathHandle          = 'test';
	mCurrRouteWayPointID = -1;
	mTargetPosition.set(0.0f, 0.0f, 0.0f);
	mTargetAngle = 0.0f;
	mActionVelocity.set(0.0f, 0.0f, 0.0f);
	_3A4 = 0.0f;

	mPellet = nullptr;

	mTekiShape = tekiMgr->getTekiShapeObject(mTekiType);

	if (!mTekiShape) {
		clearTekiOption(TEKIOPT_Visible | TEKIOPT_ShadowVisible | TEKIOPT_LifeGaugeVisible | TEKIOPT_Atari | TEKIOPT_Alive
		                | TEKIOPT_Organic);
	} else {
		mTekiShape->mShape->makeInstance(mDynamicMaterials, 0);
		mCollInfo->initInfo(mTekiShape->mShape, nullptr, nullptr);
		mTekiAnimator->init(&mTekiShape->mAnimContext, mTekiShape->mAnimMgr, tekiMgr->mMotionTable);
	}

	if (mTekiShape && mTekiShape->mShape) {
		mPlatMgr.init(this, mapMgr, mTekiShape->mShape);
	}

	for (i = 0; i < mRouteWayPointMax; i++) {
		mRouteWayPoints[i] = nullptr;
	}

	for (i = 0; i < 4; i++) {
		mParticleGenerators[i] = 0;
	}

	for (i = 0; i < 5; i++) {
		mTimers[i] = 0.0f;
	}

	for (i = 0; i < 8; i++) {
		mCorpsePartJoints[i] = -1;
	}

	if (getParameterI(TPI_CullingType) == CULLAI_CullAIOffCamera) {
		setOutsideView();
	} else {
		setInsideView();
	}

	mCollisionRadius = getParameterF(TPF_CollisionRadius);

	prepareEffects();
	stopMove();

	PRINT("NNNNNreset:%08x:%d:%s:%f\n", this, mTekiType, TekiMgr::getTypeName(mTekiType), getCentreSize());
}

/*
 * --INFO--
 * Address:	80144D0C
 * Size:	00011C
 */
void BTeki::prepareEffects()
{
	if (!effectMgr) {
		return;
	}

	for (int i = 0; i < 3; i++) {
		zen::particleGenerator* ptcl
		    = effectMgr->create((EffectMgr::effTypeTable)(i + EffectMgr::EFF_RippleWhite2), Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
		if (!ptcl) {
			PRINT("!!!prepareEffects:generator==null:%08x:%d,%d:%08x\n", this, i, mTekiType, nullptr);
			break;
		}

		ptcl->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
		f32 val = ptcl->getScaleSize();
		ptcl->setScaleSize(val * getParameterF(TPF_RippleScale));
		ptcl->stopGen();
		mParticleGenPack->setPtclGenPtr(i, ptcl);
	}

	mParticleGenPack->setEmitPosPtr(&getPosition());

	// fake just to inflate stack.
	PRINT("fake", mParticleGenPack ? "yes" : "no", mParticleGenPack ? "yes" : "no", mParticleGenPack ? "yes" : "no",
	      mParticleGenPack ? "yes" : "no");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void BTeki::setCorpsePartJoint(int partIdx, int jointIdx)
{
	if (getCorpsePartID(partIdx).match('none', '*')) {
		PRINT("!setCorpsePartJoint:%08x:%d,%d\n", this, partIdx, jointIdx);
		return;
	}

	mCorpsePartJoints[partIdx] = jointIdx;
}

/*
 * --INFO--
 * Address:	80144E28
 * Size:	000080
 */
void BTeki::startAI(int)
{
	TekiStrategy* strat = getStrategy();
	if (!strat) {
		PRINT("!startAI:strategy==null:%08x\n", this);
		return;
	}
	strat->start(*static_cast<Teki*>(this));
	ID32& id = mPersonality->mID;
	PRINT("BTeki::reset:%08x:item:%s\n", this, id.mStringID);
	if (Pellet::isUfoPartsID(id.mId)) {
		radarInfo->attachParts(this);
		pelletMgr->addUseList(id.mId);
	}
}

/*
 * --INFO--
 * Address:	80144EA8
 * Size:	0000A0
 */
void BTeki::update()
{
	Creature::update();
	if (mDeadState == 0) {
		updateTimers();
		if (mHealth > 0.0f) {
			f32 max = getParameterF(TPF_Life);
			f32 inc = getParameterF(TPF_LifeRecoverRate);
			mHealth += NSystem::getFrameTime() * (max * inc);

			if (mHealth >= max) {
				mHealth = max;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80144F48
 * Size:	0000C8
 */
void BTeki::doAnimation()
{
	u32 badCompiler;
	if (!mTekiShape) {
		return;
	}
	if (getTekiOption(TEKIOPT_ManualAnimation)) {
		mAnimationSpeed = mMotionSpeed;
	} else if (!mTekiAnimator->getCurrentOption(ANIMFLAG_Unk2)) {
		mAnimationSpeed = mTekiAnimator->getAnimationSpeed();
	} else if (getTekiOption(TEKIOPT_StoppingMove)) {
		mAnimationSpeed = mPreStopAnimationSpeed;
	} else {
		f32 speed       = getDriveLength();
		mAnimationSpeed = getVelocityAnimationSpeed(speed);
	}

	mTekiAnimator->animate(mAnimationSpeed);
}

/*
 * --INFO--
 * Address:	80145010
 * Size:	000064
 */
void BTeki::startMotion(int motionID)
{
	mTekiAnimator->startMotion(PaniMotionInfo(motionID, this));
	mCurrentAnimEvent = KEY_NULL;
	clearAnimationKeyOptions();
}

/*
 * --INFO--
 * Address:	80145074
 * Size:	000098
 */
void BTeki::startStoppingMove()
{
	PRINT("startStoppingMove:%08x:%f,%f\n", this, mAnimationSpeed, mPreStopAnimationSpeed);
	stopMove();
	setTekiOption(TEKIOPT_StoppingMove);
	mPreStopAnimationSpeed = mAnimationSpeed;
}

/*
 * --INFO--
 * Address:	8014510C
 * Size:	000030
 */
void BTeki::finishStoppingMove()
{
	PRINT("finishStoppingMove:%08x:%f,%f\n", this, mAnimationSpeed, mPreStopAnimationSpeed);
	clearTekiOption(TEKIOPT_StoppingMove);
}

/*
 * --INFO--
 * Address:	8014513C
 * Size:	0000A4
 */
f32 BTeki::getVelocityAnimationSpeed(f32 p1)
{
	f32 animSpeed   = mTekiAnimator->getAnimationSpeed() / 30.0f;
	f32 scaledSpeed = p1 * animSpeed / getScaleRate();
	f32 minSpeed    = 10.0f * animSpeed;
	if (scaledSpeed < minSpeed) {
		scaledSpeed = minSpeed;
	}

	return scaledSpeed;
}

/*
 * --INFO--
 * Address:	801451E0
 * Size:	000080
 */
void BTeki::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (event.mEventType == KEY_PlaySound) {
		playTableSound(event.mValue);
		return;
	}

	if (event.mEventType == KEY_PlayEffect) {
		createTekiEffect(event.mValue);
		return;
	}

	mCurrentAnimEvent = event.mEventType;
	setAnimationKeyOption(1 << event.mEventType);
}

/*
 * --INFO--
 * Address:	80145260
 * Size:	0001E0
 */
void BTeki::doAI()
{
	u32 badCompiler[2];
	if (!mDeadState && (AIPerf::optLevel < 3 || mOptUpdateContext.updatable())) {
		TekiStrategy* strat = getStrategy();
		strat->act(*static_cast<Teki*>(this));
		mCurrentAnimEvent = KEY_NULL;
		clearAnimationKeyOptions();

		if (!mGroundTriangle) {
			mParticleGenPack->stopGen();
		} else {
			int attr         = MapCode::getAttribute(mGroundTriangle);
			bool isActiveGen = !mParticleGenPack->checkStopGen();
			if (isActiveGen) {
				if (attr != ATTR_Water) {
					mParticleGenPack->stopGen();
				}
			} else if (attr == ATTR_Water) {
				mParticleGenPack->startGen();
			}
		}

		if (getTekiOption(TEKIOPT_Gravitatable)) {
			gravitate(getGravity());
		}

		f32 factor = 1.0f;
		if (!timerElapsed(3)) {
			factor += mVibrationController->getValue(mTimers[3]);
		}

		if (getTekiOption(TEKIOPT_Pressed)) {
			mScale.set(1.2f, 0.2f, 1.2f);
		} else {
			f32 scale = getScale();
			mScale.set(scale * factor, scale / factor, scale * factor);
		}

		updateLifeGauge();
		if (mDeadState == 1) {
			dieSoon();
		}
	}
}

/*
 * --INFO--
 * Address:	80145440
 * Size:	00000C
 */
void BTeki::die()
{
	mDeadState = 1;
}

/*
 * --INFO--
 * Address:	8014544C
 * Size:	000258
 */
void BTeki::dieSoon()
{
	PRINT("dieSoon:%08x:\n", this);
	clearTekiOption(TEKIOPT_Alive | TEKIOPT_Visible | TEKIOPT_ShadowVisible | TEKIOPT_Atari);
	if (getParameterI(TPI_CorpseType) == TEKICORPSE_LeaveCorpse) {
		createSoulEffect();
		u32 typeID = TekiMgr::getTypeId(mTekiType);
		ID32 id(typeID);
		PRINT("dieSoon:%08x:%d,%s\n", this, mTekiType, id.mStringID);

		NVector3f vec1;
		CollPart* carcass = mCollInfo->getSphere('carc');
		if (!carcass) {
			vec1.set(getCentre());
		} else {
			PRINT("dieSoon:%08x:'carc'\n", this);
			vec1.set(carcass->mCentre);
		}

		becomePellet(typeID, vec1, getDirection());
		PRINT("dieSoon:%08x:pellet:%08x\n", this, mPellet);
		if (!mPellet) {
			ERROR("?dieSoon:%08x:pellet==null:abusan\n", this);
			return;
		}

		NVector3f vec2;
		outputDirectionVector(vec2);
		vec2.scale(getParameterF(TPF_CorpseVelocityHoriz));
		vec2.y = getParameterF(TPF_CorpseVelocityVert);
		mPellet->mVelocity.set(vec2);
		mDeadState = 2;
	}

	detachGenerator();
	spawnCorpseParts();
	mSeContext->releaseEvent();
	GameStat::killTekis.inc();
	clearCreaturePointers();
	mPlatMgr.release();
	if (mDeadState == 2) {
		becomeCorpse();
	} else {
		kill(false);
	}
}

/*
 * --INFO--
 * Address:	801456A4
 * Size:	000094
 */
void BTeki::becomeCorpse()
{
	PRINT("BTeki::becomeCorpse:%08x\n", this);
	for (int i = 0; i < 4; i++) {
		if (mParticleGenerators[i]) {
			mParticleGenerators[i]->finish();
		}
	}

	mParticleGenPack->finish();
}

/*
 * --INFO--
 * Address:	80145738
 * Size:	000150
 */
void BTeki::doKill()
{
	PRINT("BTeki::doKill:%08x\n", this);
	if (tekiOptUpdateMgr) {
		mOptUpdateContext.exit();
	}

	clearTekiOption(TEKIOPT_Alive);
	mSeContext->releaseEvent();
	clearCreaturePointers();
	mPlatMgr.release();
	for (int i = 0; i < 4; i++) {
		if (mParticleGenerators[i]) {
			mParticleGenerators[i]->finish();
			mParticleGenerators[i] = nullptr;
		}
	}

	mParticleGenPack->finish();
	tekiMgr->kill(this);
}

/*
 * --INFO--
 * Address:	80145888
 * Size:	000080
 */
void BTeki::exitCourse()
{
	PRINT("BTeki::exitCourse:%08x\n", this);
	for (int i = 0; i < 4; i++) {
		if (mParticleGenerators[i]) {
			mParticleGenerators[i]->forceFinish();
			mParticleGenerators[i] = nullptr;
		}
	}

	mParticleGenPack->forceFinish();
}

/*
 * --INFO--
 * Address:	80145908
 * Size:	0000AC
 */
void BTeki::gravitate(f32 accel)
{
	f32 fTime = NSystem::getFrameTime();
	mActionVelocity.y -= accel * fTime;
	Vector3f vec(mActionVelocity);
	vec.scale(fTime);
	mPosition.add(vec);
	f32 seaLevel = getSeaLevel();
	if (getPosition().y <= seaLevel) {
		getPosition().y = seaLevel;
		bounceCallback();
	}
}

/*
 * --INFO--
 * Address:	801459B4
 * Size:	0000D4
 */
void BTeki::updateTimers()
{
	f32 fTime = NSystem::getFrameTime();
	for (int i = 0; i < 5; i++) {
		if (mTimers[i] > 0.0f) {
			mTimers[i] -= fTime;
			if (mTimers[i] < 0.0f) {
				mTimers[i] = 0.0f;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80145A88
 * Size:	000074
 */
bool BTeki::stimulate(Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actTeki(static_cast<Teki*>(this));
	}
	return false;
}

/*
 * --INFO--
 * Address:	80145AFC
 * Size:	00009C
 */
f32 BTeki::getiMass()
{
	f32 weight = getParameterF(TPF_Weight);
	if (weight <= 0.0f) {
		return 0.0f;
	}
	return 1.0f / (getScaleRate() * weight);
}

/*
 * --INFO--
 * Address:	80145B98
 * Size:	00002C
 */
f32 BTeki::getTekiCollisionSize()
{
	return getCentreSize();
}

/*
 * --INFO--
 * Address:	80145BC4
 * Size:	000030
 */
void BTeki::makeDamaged()
{
	mHealth -= mStoredDamage;
	if (mHealth < 0.0f) {
		mHealth = 0.0f;
	}

	mStoredDamage = 0.0f;
}

/*
 * --INFO--
 * Address:	80145BF4
 * Size:	00004C
 */
void BTeki::startDamageMotion(f32 period, f32 amp)
{
	if (timerElapsed(3)) {
		mTimers[3] = period;
		mVibrationController->makeVibrationFunction(0.0f, period, amp);
	}
}

/*
 * --INFO--
 * Address:	80145C40
 * Size:	000024
 */
void BTeki::releasePlatCollisions()
{
	PRINT("releasePlatCollisions:%08x:\n", this);
	mPlatMgr.release();
}

/*
 * --INFO--
 * Address:	80145C64
 * Size:	000150
 */
void BTeki::createDeadEffect()
{
	Vector3f& effectPos = getBoundingSphereCentre();
	int carcassSize     = getParameterI(TPI_CarcassSize);
	if (carcassSize == 2) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveS, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowS, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeS, effectPos, nullptr, nullptr);
	} else if (carcassSize == 1) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveM, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowM, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeM, effectPos, nullptr, nullptr);
	} else if (carcassSize == 0) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, effectPos, nullptr, nullptr);

	} else if (carcassSize != 3) {
		PRINT("!createDeadEffect:%08x:%d\n", this, carcassSize);
	}
}

/*
 * --INFO--
 * Address:	80145DB4
 * Size:	0000B4
 */
void BTeki::createSoulEffect()
{
	Vector3f& effectPos = getBoundingSphereCentre();
	int carcassSize     = getParameterI(TPI_CarcassSize);
	if (carcassSize == 2) {
		effectMgr->create(EffectMgr::EFF_Teki_SoulS, effectPos, nullptr, nullptr);
	} else if (carcassSize == 1) {
		effectMgr->create(EffectMgr::EFF_Teki_SoulM, effectPos, nullptr, nullptr);
	} else if (carcassSize == 0) {
		effectMgr->create(EffectMgr::EFF_Teki_SoulL, effectPos, nullptr, nullptr);

	} else if (carcassSize != 3) {
		PRINT("!createSoulEffect:%08x:%d\n", this, carcassSize);
	}
}

/*
 * --INFO--
 * Address:	80145E68
 * Size:	00019C
 */
void BTeki::spawnItems()
{
	// spawn item
	ID32& id = mPersonality->mID;
	if (!id.match('none', '*')) {
		PRINT("spawnItems:%08x:spawn item:%s\n", this, id.mStringID);
		spawnPellets(id.mId, -2, 1);
		radarInfo->detachParts(this);
		detachGenerator();
	}

	// spawn pellets
	f32 pelletChance = getPersonalityF(TekiPersonality::FLT_PelletAppearChance);
	PRINT("spawnItems:PELLET:probability:%f\n", pelletChance);

	if (NMathF::occurred(pelletChance)) {
		int kind   = mPersonality->mPelletKind;
		int color  = mPersonality->mPelletColor;
		int min    = getPersonalityI(TekiPersonality::INT_PelletMinCount);
		int max    = getPersonalityI(TekiPersonality::INT_PelletMaxCount);
		int pelNum = NMathI::rangeRandom(min, max);
		PRINT("spawn pellet col=%d kind=%d\n", color, kind);
		spawnPellets(kind, color, pelNum);
	}

	// spawn nectar (waters)
	f32 nectarChance = getPersonalityF(TekiPersonality::FLT_NectarAppearChance);
	PRINT("spawnItems:WATER:probability:%f\n", nectarChance);
	if (NMathF::occurred(nectarChance)) {
		int min       = getPersonalityI(TekiPersonality::INT_NectarMinCount);
		int max       = getPersonalityI(TekiPersonality::INT_NectarMaxCount);
		int nectarNum = NMathI::rangeRandom(min, max);
		PRINT("spawnItems:spawnWaters:%08x:%d,%d,%d\n", this, min, max, nectarNum);
		spawnWaters(nectarNum);
	}
}

/*
 * --INFO--
 * Address:	80146004
 * Size:	0002A8
 */
void BTeki::spawnPellets(int kind, int color, int count)
{
	PRINT("spawnPellets:%08x:%d,%d,%d\n", this, kind, color, count);
	Vector3f spawnPos   = getCentre();
	f32 spawnSpeedVert  = getParameterF(TPF_SpawnPelletVelocityVert);
	f32 spawnSpeedHoriz = getParameterF(TPF_SpawnPelletVelocityHoriz);

	f32 direction;
	if (getParameterI(TPI_SpawnPelletForward) == TRUE) {
		direction = getDirection();
	} else {
		direction = 2 * NMathF::pi * NSystem::random();
	}

	for (int i = 0; i < count; i++) {
		Pellet* pellet = nullptr;
		if (color == PELCOLOR_Part) {
			pellet = pelletMgr->newPellet(kind, nullptr);
			if (Pellet::isUfoPartsID(kind)) {
				SeSystem::playSysSe(SYSSE_PARTS_APPEAR);
			}
		} else {
			int pelColor = Blue;
			if (color >= 0) {
				pelColor = color;
			} else {
				pelColor = NMathI::rangeRandom(PELCOLOR_MIN, PELCOLOUR_MAX);
			}
			pellet = pelletMgr->newNumberPellet(pelColor, kind);
		}

		if (!pellet) {
			PRINT("!spawnPellets:pellet==null:%08x\n", this);
			return;
		}

		pellet->init(spawnPos);
		f32 angle = direction + (f32(i) / f32(count)) * NMathF::pi * 2.0f;
		pellet->mVelocity.set(spawnSpeedHoriz * NMathF::sin(angle), spawnSpeedVert, spawnSpeedHoriz * NMathF::cos(angle));

		pellet->mFaceDirection = getDirection();
		pellet->mRotationQuat.fromEuler(Vector3f(0.0f, pellet->mFaceDirection, 0.0f));

		if (getParameterI(TPI_SpawnPelletScaleOff)) {
			pellet->startAI(TRUE);
		} else {
			pellet->startAI(FALSE);
		}

		pellet->playEventSound(pellet, SE_PELLET_BORN);
	}
}

/*
 * --INFO--
 * Address:	801462AC
 * Size:	0001EC
 */
void BTeki::spawnWaters(int count)
{
	PRINT("spawnWaters:%08x:%d\n", this, count);
	Vector3f spawnPos   = getCentre();
	f32 spawnSpeedVert  = getParameterF(TPF_SpawnPelletVelocityVert);
	f32 spawnSpeedHoriz = getParameterF(TPF_SpawnPelletVelocityHoriz);

	f32 direction;
	if (getParameterI(TPI_SpawnPelletForward) == TRUE) {
		direction = getDirection();
	} else {
		direction = 2 * NMathF::pi * NSystem::random();
	}

	for (int i = 0; i < count; i++) {
		MizuItem* nectar = (MizuItem*)itemMgr->birth(OBJTYPE_FallWater);

		if (!nectar) {
			PRINT("!spawnWaters::item==null:%08x\n", this);
			return;
		}

		nectar->init(spawnPos);
		f32 angle = direction + (f32(i) / f32(count)) * NMathF::pi * 2.0f;
		nectar->mVelocity.set(spawnSpeedHoriz * NMathF::sin(angle), spawnSpeedVert, spawnSpeedHoriz * NMathF::cos(angle));

		nectar->startAI(0);

		nectar->playEventSound(nectar, SE_PELLET_BORN);
	}
}

/*
 * --INFO--
 * Address:	80146498
 * Size:	000040
 */
void BTeki::spawnCorpseParts()
{
	return getStrategy()->spawnCorpseParts(*static_cast<Teki*>(this));
}

/*
 * --INFO--
 * Address:	801464D8
 * Size:	0000D8
 */
Teki* BTeki::generateTeki(int tekiType)
{
	Teki* teki = tekiMgr->newTeki(tekiType);
	PRINT("generateTeki:%08x->%08x:%d->%d\n", this, teki, mTekiType, tekiType);
	if (!teki) {
		return nullptr;
	}

	teki->mPersonality->reset();
	teki->mPersonality->mPosition.input(getPosition());
	teki->mPersonality->mNestPosition.input(getNestPosition());
	teki->mPersonality->mFaceDirection = getDirection();
	teki->setPersonalityF(TekiPersonality::FLT_TerritoryRange, getPersonalityF(TekiPersonality::FLT_TerritoryRange));
	teki->reset();
	return teki;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void BTeki::outputDirectionPosition(Vector3f& outPos, f32 dist, f32 height)
{
	Vector3f offset;
	outputDirectionVector(offset);

	offset.scale(dist * getScaleRate());
	outPos.input(getPosition());
	outPos.y += height * getScaleRate();
	outPos.add(offset);
}

/*
 * --INFO--
 * Address:	801465B0
 * Size:	000190
 */
void BTeki::outputSpawnPosition(Vector3f& spawnPos)
{
	outputDirectionPosition(spawnPos, getParameterF(TPF_SpawnDistance), getParameterF(TPF_SpawnHeight));
}

/*
 * --INFO--
 * Address:	80146740
 * Size:	000250
 */
Teki* BTeki::spawnTeki(int tekiType)
{
	Teki* teki = generateTeki(tekiType);
	if (!teki) {
		return nullptr;
	}

	Vector3f spawnPos;
	outputSpawnPosition(spawnPos);
	teki->inputPosition(spawnPos);

	Vector3f spawnVel;
	outputDirectionVector(spawnVel);
	spawnVel.scale(getParameterF(TPF_SpawnVelocity) * getPersonalityF(TekiPersonality::FLT_Strength));
	teki->inputVelocity(spawnVel);

	teki->startAI(0);
	return teki;
}

/*
 * --INFO--
 * Address:	80146A10
 * Size:	000004
 */
void BTeki::shootBall(Creature&)
{
}

/*
 * --INFO--
 * Address:	80146A14
 * Size:	0000B4
 */
void BTeki::dump()
{
	PRINT("BTeki:%s:%08x\n", TekiMgr::getTypeName(mTekiType), this);
	PRINT("MotionName:%s\n", mTekiAnimator->getCurrentMotionName());
	PRINT("MotionFrame:%f/%d\n", mTekiAnimator->getCounter(), mTekiAnimator->getFrameCount());
	int battlePikiCount = countPikis(TekiLowerRangeCondition(static_cast<Teki*>(this)));
	int stickPikiCount  = countPikis(TekiStickerCondition(static_cast<Teki*>(this)));
	PRINT("battlePikiCount:%d,stickPikiCount:%d\n", battlePikiCount, stickPikiCount);
	int flickCount = getFlickDamageCount(battlePikiCount);
	PRINT("DamageCount:%f/%f\n", mDamageCount, flickCount);
	PRINT("damage:%f\n", mStoredDamage);
	PRINT("tekiState:%d\n", mStateID);
	PRINT("returnState:%d\n", mReturnStateID);

	// nakata did you just forget to take this out for some reason.
	TekiLowerRangeCondition(static_cast<Teki*>(this));
}

/*
 * --INFO--
 * Address:	80146AC8
 * Size:	0000E8
 */
bool BTeki::nearestAngleTarget(Creature* newTarget)
{
	if (!newTarget) {
		PRINT("!nearestAngleTarget:newTarget==null:%08x\n", this);
		return false;
	}

	Creature* oldTarget = getCreaturePointer(0);
	if (!oldTarget) {
		return true;
	}

	if (newTarget == oldTarget) {
		return false;
	}

	bool isNewContact = contactCreature(*newTarget);
	bool isOldContact = contactCreature(*oldTarget);

	if (isNewContact) {
		if (isOldContact) {
			f32 newAngle = calcTargetAngle(newTarget->getPosition());
			f32 oldAngle = calcTargetAngle(oldTarget->getPosition());
			if (newAngle < oldAngle) {
				return true;
			}
			return false;
		}

		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80146BB0
 * Size:	000020
 */
bool BTeki::cullableCenter(Creature& target, f32 radius)
{
	return roughCull(this, &target, radius);
}

/*
 * --INFO--
 * Address:	80146BD0
 * Size:	000088
 */
bool BTeki::cullableSphere(Creature& target, f32 radius)
{
	return cullableCenter(target, getBoundingSphereRadius() + target.getBoundingSphereRadius() + radius);
}

/*
 * --INFO--
 * Address:	80146C58
 * Size:	0000BC
 */
bool BTeki::inSectorPosition(Vector3f& p1, f32 p2, f32 p3)
{
	NVector3f pos(getPosition());
	f32 dist = pos.distanceXZ(p1);
	if (dist > p2) {
		return false;
	}

	if (calcTargetAngle(p1) > p3 / 2.0f) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	80146D14
 * Size:	000190
 */
bool BTeki::visibleCreature(Creature& target)
{
	TekiRecognitionCondition recog(static_cast<Teki*>(this));
	if (!recog.satisfy(&target)) {
		return false;
	}

	f32 range = getParameterF(TPF_VisibleRange);
	if (cullableCenter(target, range)) {
		return false;
	}

	NVector3f pos(getPosition());
	NVector3f targetPos(target.getPosition());

	if (targetPos.y > pos.y + getParameterF(TPF_VisibleHeight)) {
		return false;
	}

	if (pos.distanceXZ(targetPos) > range) {
		return false;
	}

	if (!timerElapsed(4)) {
		return true;
	}

	f32 angle = calcTargetAngle(targetPos);
	f32 limit = NMathF::d2r(getParameterF(TPF_VisibleAngle) / 2.0f);
	if (angle > limit) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	80146EA4
 * Size:	000154
 */
bool BTeki::separateCreature(Creature& target)
{
	TekiRecognitionCondition recog(static_cast<Teki*>(this));
	if (!recog.satisfy(&target)) {
		return true;
	}

	if (target.getStickObject() == this) {
		return false;
	}

	f32 range = getAttackableRange() + 1.0f;

	if (cullableSphere(target, range)) {
		return true;
	}

	f32 collDist = calcCollisionDistance(target);
	if (collDist > range) {
		PRINT("separateCreature1:%08x:%08x:%f,%f\n", this, &target, range, collDist);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80146FF8
 * Size:	000154
 */
bool BTeki::contactCreature(Creature& target)
{
	TekiRecognitionCondition recog(static_cast<Teki*>(this));
	if (!recog.satisfy(&target)) {
		return false;
	}

	if (target.getStickObject() == this) {
		return true;
	}

	f32 range = getAttackableRange() - 1.0f;

	if (cullableSphere(target, range)) {
		return false;
	}

	f32 collDist = calcCollisionDistance(target);
	if (collDist > range) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8014714C
 * Size:	0001B4
 */
bool BTeki::attackableCreature(Creature& target)
{
	if (target.getStickObject() == this) {
		return false;
	}

	if (!contactCreature(target)) {
		return false;
	}

	f32 angle = calcTargetAngle(target.getPosition());
	f32 limit = NMathF::d2r(getParameterF(TPF_AttackableAngle)) / 2.0f;
	if (angle > limit) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	80147300
 * Size:	0000F0
 */
f32 BTeki::calcTargetAngle(Vector3f& targetPos)
{
	u32 badCompiler;

	f32 targetDir = calcTargetDirection(targetPos);
	f32 faceDir   = NMathF::roundAngle(getDirection());
	return NMathF::angleDifference(faceDir, targetDir);
}

/*
 * --INFO--
 * Address:	801473F0
 * Size:	0001DC
 */
bool BTeki::moveToward(Vector3f& target, f32 speed)
{
	return moveTowardStatic(getPosition(), target, speed, mTargetVelocity);
}

/*
 * --INFO--
 * Address:	801475CC
 * Size:	0000C8
 */
bool BTeki::turnToward(f32 p1, f32 p2)
{
	f32 faceDir   = NMathF::roundAngle(getDirection());
	f32 nearerDir = NMathF::calcNearerDirection(faceDir, p1);
	f32 speed     = p2 * NSystem::getFrameTime();

	bool res = false;
	if (nearerDir > faceDir) {
		if (nearerDir - faceDir < speed) {
			speed = nearerDir - faceDir;
			res   = true;
		}
		setDirection(faceDir + speed);
	} else {
		if (faceDir - nearerDir < speed) {
			speed = faceDir - nearerDir;
			res   = true;
		}
		setDirection(faceDir - speed);
	}

	return res;
}

/*
 * --INFO--
 * Address:	80147694
 * Size:	00004C
 */
void BTeki::rotateTeki(f32 speed)
{
	f32 faceDir = NMathF::roundAngle(getDirection());
	f32 amt     = speed * NSystem::getFrameTime();

	setDirection(faceDir + amt);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000218
 */
void BTeki::jumpTo(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000168
 */
bool BTeki::insideDirection(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801476E0
 * Size:	000254
 */
Creature* BTeki::getClosestNaviPiki(Condition& cond, f32* outDist)
{
	Creature* navi = naviMgr->getNavi();
	if (!cond.satisfy(navi)) {
		navi = nullptr;
	}

	Creature* piki   = pikiMgr->findClosest(getPosition(), &cond);
	Creature* result = nullptr;
	if (!navi) {
		if (piki) {
			result = piki;
		}
	} else if (!piki) {
		result = navi;
	} else {
		f32 naviDist = calcSphereDistance(*navi);
		f32 pikiDist = calcSphereDistance(*piki);
		if (naviDist < pikiDist) {
			result = navi;
		} else {
			result = piki;
		}
	}

	if (outDist && result) {
		*outDist = calcSphereDistance(*result);
	}
	return result;
}

/*
 * --INFO--
 * Address:	80147934
 * Size:	0000DC
 */
bool BTeki::attackTarget(Creature& target, f32 range, f32 damage, Condition& cond)
{
	if (!cond.satisfy(&target)) {
		return false;
	}

	f32 collDist = calcCollisionDistance(target);
	if (collDist > range + 1.0f) {
		return false;
	}

	target.stimulate(InteractAttack(this, nullptr, damage, false));
	return true;
}

/*
 * --INFO--
 * Address:	80147A10
 * Size:	000108
 */
void BTeki::outputHitCenter(Vector3f& outCenter)
{
	Vector3f dir;
	outputDirectionVector(dir);
	dir.scale(getTekiCollisionSize() + getAttackRange());
	outCenter.add2(getPosition(), dir);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001F4
 */
bool BTeki::attackRangeNaviPiki(Interaction&, Condition&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00015C
 */
bool BTeki::interactTeki(Interaction&, Condition&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80147B18
 * Size:	00007C
 */
bool BTeki::interactNaviPiki(Interaction& interaction, Condition& cond)
{
	bool navi = interactNavi(interaction, cond);
	bool piki = interactPiki(interaction, cond);

	return navi || piki;
}

/*
 * --INFO--
 * Address:	80147B94
 * Size:	000090
 */
bool BTeki::interactNavi(Interaction& interaction, Condition& cond)
{
	bool res   = false;
	Navi* navi = naviMgr->getNavi();
	if (cond.satisfy(navi)) {
		navi->stimulate(interaction);
		res = true;
	}

	return res;
}

/*
 * --INFO--
 * Address:	80147C24
 * Size:	000150
 */
bool BTeki::interactPiki(Interaction& interaction, Condition& cond)
{
	bool res = false;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (!piki) {
			PRINT("?interactPiki:%08x:creature==null\n", this);
			break;
		}
		if (cond.satisfy(piki)) {
			piki->stimulate(interaction);
			res = true;
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	80147D74
 * Size:	000034
 */
void BTeki::flick()
{
	flickUpper();
	flickLower();
}

/*
 * --INFO--
 * Address:	80147DA8
 * Size:	000044
 */
void BTeki::flick(InteractFlick& upperFlick, InteractFlick& lowerFlick)
{
	flickUpper(upperFlick);
	flickLower(lowerFlick);
}

/*
 * --INFO--
 * Address:	80147DEC
 * Size:	000068
 */
void BTeki::flickUpper()
{
	InteractFlick& flick = InteractFlick(this, getParameterF(TPF_UpperFlickPower), 0.0f, FLICK_BACKWARDS_ANGLE);
	flickUpper(flick);
}

/*
 * --INFO--
 * Address:	80147E54
 * Size:	0001AC
 */
void BTeki::flickUpper(InteractFlick& flick)
{
	Stickers stuckList(this);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (!stuck) {
			PRINT("?flickUpper:%08x:creature==null\n", this);
			break;
		}

		if (NMathF::occurred(getParameterF(TPF_FlickProbability))) {
			stuck->stimulate(flick);
			iter.dec();
		}
	}
}

/*
 * --INFO--
 * Address:	80148000
 * Size:	000068
 */
void BTeki::flickLower()
{
	InteractFlick& flick
	    = InteractFlick(this, getParameterF(TPF_LowerFlickPower), getParameterF(TPF_LowerAttackPower), FLICK_BACKWARDS_ANGLE);
	flickLower(flick);
}

// this is to get TekiAndCondition and TekiNotCondition vtables to spawn in the right order.
// probably related to whatever the hell is happening in flickLower but w/e
static void fakeFunc()
{
	TekiAndCondition andCond(nullptr, nullptr);
	andCond.satisfy(nullptr);
}

/*
 * --INFO--
 * Address:	80148068
 * Size:	000284
 */
void BTeki::flickLower(InteractFlick& flick)
{
	TekiAndCondition andCond(
	    &TekiAndCondition(&TekiRecognitionCondition(static_cast<Teki*>(this)), &TekiNotCondition(&TekiStickingCondition())),
	    &TekiDistanceCondition(static_cast<Teki*>(this), getLowerRange()));
	interactNavi(flick, andCond);
	flick.mDamage = 0.0f;

	interactPiki(flick, andCond);

	// this is so fake and cursed, but whatever bullshit nakata did with the condition stacking has me stumped.
	PRINT("fake", flick.mAngle ? "yes" : "no", flick.mAngle ? "yes" : "no", flick.mAngle ? "yes" : "no", flick.mAngle ? "yes" : "no",
	      flick.mAngle ? "yes" : "no", flick.mAngle ? "yes" : "no", flick.mAngle ? "yes" : "no", flick.mAngle ? "yes" : "no",
	      flick.mAngle ? "yes" : "no");
}

/*
 * --INFO--
 * Address:	801482EC
 * Size:	000174
 */
bool BTeki::checkNaviPiki(Condition& cond)
{
	Navi* navi = naviMgr->getNavi();
	if (cond.satisfy(navi)) {
		return true;
	}

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (cond.satisfy(piki)) {
			return true;
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	80148460
 * Size:	000148
 */
int BTeki::countPikis(Condition& cond)
{
	int count = 0;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (cond.satisfy(piki)) {
			count++;
		}
	}
	return count;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
int BTeki::countTekis(Condition& cond)
{
	int count = 0;
	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (cond.satisfy(piki)) {
			count++;
		}
	}
	return count;
}

/*
 * --INFO--
 * Address:	801485A8
 * Size:	000054
 */
int BTeki::getFlickDamageCount(int pikiCount)
{
	if (pikiCount <= getParameterI(TPI_FlickPikiCount1)) {
		return getParameterI(TPI_FlickDamageCount1);

	} else if (pikiCount <= getParameterI(TPI_FlickPikiCount2)) {
		return getParameterI(TPI_FlickDamageCount2);

	} else if (pikiCount <= getParameterI(TPI_FlickPikiCount3)) {
		return getParameterI(TPI_FlickDamageCount3);
	}

	return getParameterI(TPI_FlickDamageCount4);
}

/*
 * --INFO--
 * Address:	801485FC
 * Size:	000040
 */
void BTeki::eventPerformed(TekiEvent& event)
{
	TekiStrategy* tekiEvent = getStrategy();
	tekiEvent->eventPerformed(event);
}

/*
 * --INFO--
 * Address:	8014863C
 * Size:	000098
 */
void BTeki::collisionCallback(CollEvent& event)
{
	if (!isAlive()) {
		return;
	}

	Creature* collider = event.mCollider;
	if (collider->isAlive()) {
		eventPerformed(TekiEvent(TekiEventType::Entity, static_cast<Teki*>(this), collider));
	}
}

/*
 * --INFO--
 * Address:	801486D4
 * Size:	00001C
 */
bool BTeki::ignoreAtari(Creature* target)
{
	if (target->getStickObject() == this) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	801486F0
 * Size:	000050
 */
void BTeki::bounceCallback()
{
	eventPerformed(TekiEvent(TekiEventType::Ground, static_cast<Teki*>(this)));
}

/*
 * --INFO--
 * Address:	80148740
 * Size:	000050
 */
void BTeki::wallCallback(Plane&, DynCollObject*)
{
	eventPerformed(TekiEvent(TekiEventType::Wall, static_cast<Teki*>(this)));
}

/*
 * --INFO--
 * Address:	80148790
 * Size:	000050
 */
bool BTeki::interact(TekiInteractionKey& key)
{
	TekiStrategy* strat = getStrategy();
	return strat->interact(*static_cast<Teki*>(this), key);
}

/*
 * --INFO--
 * Address:	801487E0
 * Size:	000148
 */
bool BTeki::interactDefault(TekiInteractionKey& key)
{
	u32 badCompiler;
	if (key.mInteractionType == TekiInteractType::Attack) {
		InteractAttack* attack = (InteractAttack*)key.mInteraction;
		if (getTekiOption(TEKIOPT_Invincible)) {
			return false;
		}

		_344 = attack->getDamagePortion();
		mStoredDamage += attack->mDamage;
		if (getTekiOption(TEKIOPT_DamageCountable)) {
			mDamageCount++;
		}
		setCreaturePointer(1, attack->mOwner);
		return true;
	}

	if (key.mInteractionType == TekiInteractType::HitEffect) {
		InteractHitEffect* hitEffect = (InteractHitEffect*)key.mInteraction;
		effectMgr->create(EffectMgr::EFF_Piki_BigHit, hitEffect->mEffectPos, nullptr, nullptr);
		if (mTekiType == TEKI_Beatle) {
			if (hitEffect->mCollPart->isBouncy()) {
				playEventSound(this, SE_KABUTO_FLIP);
			}
		} else if (mTekiType == TEKI_Kinoko) {
			if (hitEffect->mCollPart->isBouncy()) {
				playEventSound(this, SE_MUSH_FLIP);
			}
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	80148928
 * Size:	00000C
 */
f32 BTeki::getGravity()
{
	return AIConstant::_instance->mConstants.mGravity();
}

/*
 * --INFO--
 * Address:	80148934
 * Size:	00002C
 */
TekiStrategy* BTeki::getStrategy()
{
	return tekiMgr->getStrategy(mTekiType);
}

/*
 * --INFO--
 * Address:	80148960
 * Size:	000034
 */
f32 BTeki::getSeaLevel()
{
	Vector3f& pos = getPosition();
	return mapMgr->getMinY(pos.x, pos.z, true);
}

/*
 * --INFO--
 * Address:	80148994
 * Size:	000044
 */
f32 BTeki::getYFromSeaLevel()
{
	Vector3f& pos = getPosition();
	return pos.y - getSeaLevel();
}

/*
 * --INFO--
 * Address:	801489D8
 * Size:	000074
 */
void BTeki::makePositionRoute(Vector3f& pos1, Vector3f& pos2, bool p3)
{
	int idx2 = getTargetNearestWayPoint(pos2)->mIndex;
	int idx1 = getTargetNearestWayPoint(pos1)->mIndex;
	makeWayPointRoute(idx1, idx2, p3);
}

/*
 * --INFO--
 * Address:	80148A4C
 * Size:	000098
 */
void BTeki::makeWayPointRoute(int p1, int p2, bool p3)
{
	for (int i = 0; i < mRouteWayPointMax; i++) {
		mRouteWayPoints[i] = nullptr;
	}

	mRouteWayPointCount = routeMgr->getPathFinder(mPathHandle)->findSync(mRouteWayPoints, mRouteWayPointMax, p1, p2, p3);

	if (mRouteWayPointCount > mRouteWayPointMax) {
		PRINT("!makeWayPointRoute:routeWayPointCount>routeWayPointMax:%08x:%d,%d\n", this, mRouteWayPointCount, mTekiType);
	}

	PRINT("makeWayPointRoute:%08x,%d->%d,%d\n", this, p1, p2, mRouteWayPointCount);
	if (mRouteWayPointCount == 0) {
		PRINT("!makeWayPointRoute:%08x,%d->%d,%d\n", this, p1, p2, mRouteWayPointCount);
	}
}

/*
 * --INFO--
 * Address:	80148AE4
 * Size:	000034
 */
WayPoint* BTeki::getTargetNearestWayPoint(Vector3f& pos)
{
	return routeMgr->findNearestWayPoint(mPathHandle, pos, false);
}

/*
 * --INFO--
 * Address:	80148B18
 * Size:	000034
 */
WayPoint* BTeki::getNearestWayPoint()
{
	return getTargetNearestWayPoint(getPosition());
}

/*
 * --INFO--
 * Address:	80148B4C
 * Size:	000030
 */
WayPoint* BTeki::getWayPoint(int wpIdx)
{
	return routeMgr->getWayPoint(mPathHandle, wpIdx);
}

/*
 * --INFO--
 * Address:	80148B7C
 * Size:	00002C
 */
WayPoint* BTeki::getRouteWayPoint(int idx)
{
	if (idx < 0 || idx > mRouteWayPointMax) {
		PRINT("!getRouteWayPoint:%08x:%d,%d\n", this, idx, mTekiType);
		return nullptr;
	}

	return mRouteWayPoints[idx];
}

/*
 * --INFO--
 * Address:	80148BA8
 * Size:	000040
 */
void BTeki::updateLifeGauge()
{
	mLifeGauge.updValue(mHealth, getParameterF(TPF_Life));
}

/*
 * --INFO--
 * Address:	80148BE8
 * Size:	00006C
 */
void BTeki::refresh(Graphics& gfx)
{
	if (mDeadState == 0) {
		TekiStrategy* strat = getStrategy();
		if (strat) {
			strat->draw(*static_cast<Teki*>(this), gfx);
		}
	}
}

/*
 * --INFO--
 * Address:	80148C54
 * Size:	000174
 */
void BTeki::drawDefault(Graphics& gfx)
{
	if (!mTekiShape) {
		return;
	}

	clearTekiOption(TEKIOPT_Unk6);
	clearTekiOption(TEKIOPT_Drawed);

	f32 rad = getBoundingSphereRadius();
	if (!gfx.mCamera->isPointVisible(getBoundingSphereCentre(), rad)) {
		enableAICulling();
	} else {
		disableAICulling();
	}

	if (!aiCullable() && mGrid.aiCulling() && !getTekiOption(CF_IsAiDisabled)) {
		setTekiOption(TEKIOPT_Unk6);
	}

	if (getTekiOption(TEKIOPT_Unk6) && !isCreatureFlag(CF_AIAlwaysActive)) {
		// some debug flag thing
	} else {
		drawTekiShape(gfx);
	}

	if (gsys->mToggleDebugInfo) {
		drawTekiDebugInfo(gfx);
	}

	// genuinely unsure what else would even be here, i assume it's the debug flag setting stuff
	PRINT("fake", rad ? "yes" : "no", rad ? "yes" : "no");
}

/*
 * --INFO--
 * Address:	80148DC8
 * Size:	00023C
 */
void BTeki::drawTekiShape(Graphics& gfx)
{
	if (!getTekiOption(TEKIOPT_ShapeVisible)) {
		return;
	}

	clearTekiOption(TEKIOPT_Unk11);
	Quat q1(0.0f, 0.0f, 0.0f, 1.0f);
	f32 dir = getDirection();
	q1.rotate(Vector3f(0.0f, 1.0f, 0.0f), dir);

	NVector3f zVec;
	q1.genVectorZ(zVec);
	q1.rotate(zVec, _3A4);

	mWorldMtx.makeVQS(mPosition, q1, mScale);

	Matrix4f onCamMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, onCamMtx);
	gfx.useMatrix(Matrix4f::ident, 0);
	mTekiAnimator->updateContext();
	mTekiShape->mShape->updateAnim(gfx, onCamMtx, nullptr);

	if (mCollInfo) {
		mCollInfo->updateInfo(gfx, false);
	}

	mPlatMgr.update(gfx);

	if (aiCullable()) {
		int lightType = getParameterI(TPI_LightType);
		if (lightType == 1) {
			gfx.calcLighting(_3C0);
		}
		int animType = getParameterI(TPI_AnimationType);
		if (animType == 1) {
			f32 val = _3BC;
			mDynamicMaterials.animate(&val);
		} else {
			mDynamicMaterials.animate(nullptr);
		}

		mTekiShape->mShape->drawshape(gfx, *gfx.mCamera, &mDynamicMaterials);
		if (lightType == 1) {
			gfx.calcLighting(1.0f);
		}
		setTekiOption(TEKIOPT_Drawed);
	}
}

/*
 * --INFO--
 * Address:	80149004
 * Size:	0000B0
 */
void BTeki::drawTekiDebugInfo(Graphics& gfx)
{
	TekiStrategy* strat = getStrategy();
	if (strat) {
		bool light = gfx.setLighting(false, nullptr);
		strat->drawDebugInfo(*static_cast<Teki*>(this), gfx);
		gfx.setLighting(light, nullptr);
	}
}

/*
 * --INFO--
 * Address:	801490B4
 * Size:	0002C0
 */
void BTeki::drawTekiDebugInfoDefault(Graphics& gfx)
{
	// don't ask why this works.
	Teki* teki = static_cast<Teki*>(this);
	teki->drawRange(gfx, teki->getPosition(), getParameterF(TPF_VisibleRange), Colour(0, 0, 255, 255));
	teki->drawRange(gfx, teki->getPosition(), getTekiCollisionSize() + getAttackableRange(), Colour(255, 255, 0, 255));

	NVector3f vec1;
	outputHitCenter(vec1);
	teki->drawRange(gfx, vec1, getAttackHitRange(), Colour(255, 0, 0, 255));
	teki->drawRange(gfx, teki->getPosition(), getLowerRange(), Colour(255, 0, 255, 255));
}

/*
 * --INFO--
 * Address:	80149374
 * Size:	0000F8
 */
void BTeki::drawRange(Graphics& gfx, Vector3f& centre, f32 range, Colour& colour)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx1.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
	gfx.setColour(colour, true);
	gfx.drawSphere(centre, range, mtx2);
}

/*
 * --INFO--
 * Address:	8014946C
 * Size:	0000F4
 */
void BTeki::refresh2d(Graphics& gfx)
{
	if (mDeadState != 0 || !tekiMgr->hasModel(mTekiType) || !isVisible() || isCreatureFlag(CF_IsAICullingActive)) {
		return;
	}

	if (getTekiOption(TEKIOPT_LifeGaugeVisible)) {
		Vector3f& pos = getCentre();
		mLifeGauge.mPosition.input(pos);
		mLifeGauge.mOffset.y = getParameterF(TPF_LifeGaugeOffset);
		mLifeGauge.mScale    = 5000.0f / gfx.mCamera->mNear;
		mLifeGauge.refresh(gfx);
	}

	// w/e man.
	PRINT("fake", mDeadState ? "yes" : "no");
}

/*
 * --INFO--
 * Address:	80149560
 * Size:	000088
 */
CollPart* BTeki::getFreeSlot()
{
	CollPart* mouth = mCollInfo->getSphere('slot');
	int slotCount   = mouth->getChildCount();
	for (int i = 0; i < slotCount; i++) {
		CollPart* slot = mouth->getChildAt(i);
		if (isFreeCollPart(slot)) {
			return slot;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	801495E8
 * Size:	000140
 */
bool BTeki::isFreeCollPart(CollPart* part)
{
	Stickers stuckList(this);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (!stuck) {
			return true;
		}

		CollPart* stickPart = stuck->getStickPart();
		if (stickPart == part) {
			return false;
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	80149728
 * Size:	000080
 */
void BTeki::playTableSound(int index)
{
	PaniSoundTable* table = tekiMgr->getSoundTable(mTekiType);
	if (!table) {
		PRINT("!playTableSound:%08x:soundTable==null\n", this);
		return;
	}

	if (index >= table->getSize()) {
		PRINT("!playTableSound:%08x:index>=soundCount\n", this);
		return;
	}

	PaniSound* sound = table->getSound(index);
	if (!sound) {
		PRINT("!playTableSound:%08x:sound==null\n", this);
		return;
	}

	playSound(sound->mSoundID);
}

/*
 * --INFO--
 * Address:	801497A8
 * Size:	000024
 */
void BTeki::playSound(int soundID)
{
	mSeContext->playSound(soundID);
}

/*
 * --INFO--
 * Address:	801497CC
 * Size:	000024
 */
void BTeki::stopSound(int soundID)
{
	mSeContext->stopSound(soundID);
}

/*
 * --INFO--
 * Address:	801497F0
 * Size:	000058
 */
void BTeki::createTekiEffect(int effectID)
{
	PRINT("createTekiEffect:%08x,%d:%d\n", this, mTekiType, effectID);
	TekiStrategy* strategy = tekiMgr->getStrategy(mTekiType);
	strategy->createEffect(*(Teki*)this, effectID);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
Matrix4f& BTeki::getCameraAnimationMatrix(int idx)
{
	return mTekiShape->mShape->getAnimMatrix(idx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void BTeki::outputWorldAnimationMatrix(Matrix4f& mtx1, int idx, Matrix4f& mtx2)
{
	Matrix4f& animMtx = getCameraAnimationMatrix(idx);
	NMatrix4f tmp;
	tmp.construct(animMtx);
	tmp.makeIdentRow(3);
	mtx2.multiplyTo(tmp, mtx1);
}

/*
 * --INFO--
 * Address:	80149848
 * Size:	0000A8
 */
void BTeki::outputWorldAnimationPosition(Vector3f& p1, int p2, Matrix4f& p3)
{
	NMatrix4f tmp;
	outputWorldAnimationMatrix(tmp, p2, p3);
	tmp.outputCol(3, p1);
}

/*
 * --INFO--
 * Address:	801498F0
 * Size:	000044
 */
int BTeki::getPositionMapCode(Vector3f& pos)
{
	CollTriInfo* currentTri = mapMgr->getCurrTri(pos.x, pos.z, true);
	if (currentTri == nullptr) {
		PRINT("!getPositionMapCode:%08x\n", this);
		return -1;
	}

	return MapCode::getAttribute(currentTri);
}

/*
 * --INFO--
 * Address:	80149934
 * Size:	000048
 */
int BTeki::getPositionMapCode()
{
	return getPositionMapCode(getPosition());
}

/*
 * --INFO--
 * Address:	8014997C
 * Size:	00005C
 */
bool BTeki::inWaterTeki()
{
	if (getPositionMapCode() == ATTR_Water) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	801499D8
 * Size:	000020
 */
void BTeki::moveNestPosition()
{
	mPosition = mPersonality->mNestPosition;
}

/*
 * --INFO--
 * Address:	801499F8
 * Size:	000024
 */
void BTeki::startParticleGenerator(int param_1)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->startGen();
	}
}

/*
 * --INFO--
 * Address:	80149A1C
 * Size:	000024
 */
void BTeki::stopParticleGenerator(int param_1)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->stopGen();
	}
}

/*
 * --INFO--
 * Address:	80149A40
 * Size:	000030
 */
void BTeki::setParticleGeneratorPosition(int param_1, Vector3f& effectPos)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->setEmitPos(effectPos);
	}
}

/*
 * --INFO--
 * Address:	80149A70
 * Size:	000030
 */
void BTeki::setParticleGeneratorDirection(int param_1, Vector3f& effectDir)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->setEmitDir(effectDir);
	}
}
/*
 * --INFO--
 * Address:	80149AA0
 * Size:	0000E0
 */
f32 BTeki::calcCollisionDistance(Creature& creature)
{
	f32 dist = qdist2(getCentre().x, getCentre().z, creature.getCentre().x, creature.getCentre().z);

	f32 collSize         = getCollisionSize();
	f32 creatureCollSize = creature.getCentreSize();

	return dist - creatureCollSize - collSize;
}

/*
 * --INFO--
 * Address:	80149B80
 * Size:	00002C
 */
f32 BTeki::getCollisionSize()
{
	return getCentreSize();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
Vector3f BTeki::getCollisionCenter()
{
	// UNUSED FUNCTION
}
