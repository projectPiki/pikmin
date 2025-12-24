#include "teki.h"
#include "AIConstant.h"
#include "AIPerf.h"
#include "BaseInf.h"
#include "Creature.h"
#include "CreatureProp.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "GameStat.h"
#include "Graphics.h"
#include "MapCode.h"
#include "MapMgr.h"
#include "MizuItem.h"
#include "NaviMgr.h"
#include "Pellet.h"
#include "PikiMgr.h"
#include "RadarInfo.h"
#include "Route.h"
#include "Shape.h"
#include "SoundMgr.h"
#include "Stickers.h"
#include "TekiConditions.h"
#include "TekiStrategy.h"
#include "nlib/System.h"
#include "sysNew.h"
#include "zen/particle.h"

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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(57)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("teki");

/**
 * @TODO: Documentation
 */
void BTeki::viewStartTrembleMotion(f32 motionSpeed)
{
	startMotion(TekiMotion::Type5);
	setTekiOption(TEKIOPT_ManualAnimation);
	mMotionSpeed = motionSpeed;
}

/**
 * @TODO: Documentation
 */
void BTeki::viewSetMotionSpeed(f32 speed)
{
	mMotionSpeed = speed;
}

/**
 * @TODO: Documentation
 */
void BTeki::viewDoAnimation()
{
	doAnimation();
}

/**
 * @TODO: Documentation
 */
void BTeki::viewFinishMotion()
{
	mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
}

/**
 * @TODO: Documentation
 */
Vector3f BTeki::viewGetScale()
{
	return mSRT.s;
}

/**
 * @TODO: Documentation
 */
f32 BTeki::viewGetBottomRadius()
{
	return mTekiParams->getF(TPF_CorpseSize);
}

/**
 * @TODO: Documentation
 */
f32 BTeki::viewGetHeight()
{
	return mTekiParams->getF(TPF_CorpseHeight);
}

/**
 * @TODO: Documentation
 */
void BTeki::viewDraw(Graphics& gfx, immut Matrix4f& mat)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mTekiAnimator->updateContext();
	mTekiShape->mShape->updateAnim(gfx, mat, nullptr);
	mTekiShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @TODO: Documentation
 */
void BTeki::viewKill()
{
	kill(false);
}

/**
 * @TODO: Documentation
 */
void BTeki::doStore(CreatureInf* info)
{
	info->mObjInfo1 = mTekiType;
	PRINT_NAKATA("TEKI STORE *****************************************\n");
}

/**
 * @TODO: Documentation
 */
void BTeki::doRestore(CreatureInf* info)
{
	mTekiType = (TekiTypes)info->mObjInfo1;
}

/**
 * @TODO: Documentation
 */
TekiShapeObject::TekiShapeObject(Shape* shape)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;
	mAnimMgr             = new AnimMgr(shape, nullptr, ANIMMGR_LOAD_BUNDLE, nullptr);
	PRINT_NAKATA("OVERRIDING ANIM with %08x\n", &mAnimContext);
	mShape->overrideAnim(0, &mAnimContext);
}

/**
 * @TODO: Documentation
 */
bool BTeki::isPellet(int objType)
{
	return objType == OBJTYPE_Pellet;
}

/**
 * @TODO: Documentation
 */
f32 BTeki::calcCircleDistanceStatic(immut Vector3f& pos1, f32 rad1, immut Vector3f& pos2, f32 rad2)
{
	return qdist2(pos1.x, pos1.z, pos2.x, pos2.z) - rad1 - rad2;
}

/**
 * @TODO: Documentation
 */
bool BTeki::alwaysUpdatePlatform()
{
	return mTekiType == TEKI_Shell;
}

/**
 * @TODO: Documentation
 */
f32 BTeki::calcSphereDistanceStatic(immut Vector3f& pos1, f32 rad1, immut Vector3f& pos2, f32 rad2)
{
	return pos1.distance(pos2) - rad1 - rad2;
}

/**
 * @TODO: Documentation
 */
bool BTeki::moveTowardStatic(immut Vector3f& currentPosition, immut Vector3f& targetPosition, f32 speed, Vector3f& output)
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

/**
 * @TODO: Documentation
 */
bool BTeki::arrivedAt(f32 distance, f32 speed)
{
	f32 threshold = 2.0f * speed * NSystem::getFrameTime();
	return distance <= threshold;
}

/**
 * @TODO: Documentation
 */
BTeki::BTeki()
    : Creature(nullptr)
{
	mObjType                = OBJTYPE_Teki;
	mLifeGauge.mRenderStyle = LifeGauge::Wheel;
	mProps                  = new CreatureProp();
	mPersonality            = new TekiPersonality();
	mTekiAnimator           = new PaniTekiAnimator();
	mVibrationController    = new NVibrationFunction();
	mRouteWayPointMax       = 20;
	mRouteWayPoints         = new WayPoint*[mRouteWayPointMax];
	mRouteWayPointCount     = 0;
	mParticleGenerators     = new zen::particleGenerator*[4];
	mCollInfo               = new CollInfo(22);
	mSeContext              = new SeContext(this, 1);
	mParticleGenPack        = new zen::PtclGenPack(3);
}

/**
 * @TODO: Documentation
 */
void BTeki::init(int tekiType)
{
	PRINT_NAKATA("Teki::init:%08x:%d\n", this, tekiType);
	mTekiType   = (TekiTypes)tekiType;
	mTekiParams = tekiMgr->getTekiParameters(mTekiType);
	mSearchBuffer.init(mTekiSearchData, 3);
	resetCreatureFlag(CF_Unk1 | CF_DisableAutoFaceDir);
	Creature::init();
}

/**
 * @TODO: Documentation
 */
void BTeki::reset()
{
	PRINT_NAKATA("Teki::reset>:%08x\n", this);
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

	PRINT_NAKATA("NNNNNreset:%08x:%d:%s:%f\n", this, mTekiType, TekiMgr::getTypeName(mTekiType), getCentreSize());
}

/**
 * @TODO: Documentation
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
	STACK_PAD_TERNARY(mParticleGenPack, 4);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000090
 */
void BTeki::setCorpsePartJoint(int partIdx, int jointIdx)
{
	if (getCorpsePartID(partIdx).match('none')) {
		PRINT("!setCorpsePartJoint:%08x:%d,%d\n", this, partIdx, jointIdx);
		return;
	}

	mCorpsePartJoints[partIdx] = jointIdx;
}

/**
 * @TODO: Documentation
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
	PRINT_NAKATA("BTeki::reset:%08x:item:%s\n", this, id.mStringID);
	if (Pellet::isUfoPartsID(id.mId)) {
		radarInfo->attachParts(this);
		pelletMgr->addUseList(id.mId);
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BTeki::doAnimation()
{
	STACK_PAD_VAR(1);
	if (!mTekiShape) {
		return;
	}
	if (getTekiOption(TEKIOPT_ManualAnimation)) {
		mAnimationSpeed = mMotionSpeed;
	} else if (!mTekiAnimator->getCurrentOption(ANIMFLAG_UseDynamicSpeed)) {
		mAnimationSpeed = mTekiAnimator->getAnimationSpeed();
	} else if (getTekiOption(TEKIOPT_StoppingMove)) {
		mAnimationSpeed = mPreStopAnimationSpeed;
	} else {
		f32 speed       = getDriveLength();
		mAnimationSpeed = getVelocityAnimationSpeed(speed);
	}

	mTekiAnimator->animate(mAnimationSpeed);
}

/**
 * @TODO: Documentation
 */
void BTeki::startMotion(int motionID)
{
	mTekiAnimator->startMotion(PaniMotionInfo(motionID, this));
	mCurrentAnimEvent = KEY_NULL;
	clearAnimationKeyOptions();
}

/**
 * @TODO: Documentation
 */
void BTeki::startStoppingMove()
{
	PRINT_NAKATA("startStoppingMove:%08x:%f,%f\n", this, mAnimationSpeed, mPreStopAnimationSpeed);
	stopMove();
	setTekiOption(TEKIOPT_StoppingMove);
	mPreStopAnimationSpeed = mAnimationSpeed;
}

/**
 * @TODO: Documentation
 */
void BTeki::finishStoppingMove()
{
	PRINT_NAKATA("finishStoppingMove:%08x:%f,%f\n", this, mAnimationSpeed, mPreStopAnimationSpeed);
	clearTekiOption(TEKIOPT_StoppingMove);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BTeki::animationKeyUpdated(immut PaniAnimKeyEvent& event)
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

/**
 * @TODO: Documentation
 */
void BTeki::doAI()
{
	STACK_PAD_VAR(2);
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
			mSRT.s.set(1.2f, 0.2f, 1.2f);
		} else {
			f32 scale = getScale();
			mSRT.s.set(scale * factor, scale / factor, scale * factor);
		}

		updateLifeGauge();
		if (mDeadState == 1) {
			dieSoon();
		}
	}
}

/**
 * @TODO: Documentation
 */
void BTeki::die()
{
	mDeadState = 1;
}

/**
 * @TODO: Documentation
 */
void BTeki::dieSoon()
{
	PRINT_NAKATA("dieSoon:%08x:\n", this);
	clearTekiOption(TEKIOPT_Alive | TEKIOPT_Visible | TEKIOPT_ShadowVisible | TEKIOPT_Atari);
	if (getParameterI(TPI_CorpseType) == TEKICORPSE_LeaveCorpse) {
		createSoulEffect();
		u32 typeID = TekiMgr::getTypeId(mTekiType);
		ID32 id(typeID);
		PRINT_NAKATA("dieSoon:%08x:%d,%s\n", this, mTekiType, id.mStringID);

		NVector3f vec1;
		CollPart* carcass = mCollInfo->getSphere('carc');
		if (!carcass) {
			vec1.set(getCentre());
		} else {
			PRINT_NAKATA("dieSoon:%08x:'carc'\n", this);
			vec1.set(carcass->mCentre);
		}

		becomePellet(typeID, vec1, getDirection());
		PRINT_NAKATA("dieSoon:%08x:pellet:%08x\n", this, mPellet);
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

/**
 * @TODO: Documentation
 */
void BTeki::becomeCorpse()
{
	PRINT_NAKATA("BTeki::becomeCorpse:%08x\n", this);
	for (int i = 0; i < 4; i++) {
		if (mParticleGenerators[i]) {
			mParticleGenerators[i]->finish();
		}
	}

	mParticleGenPack->finish();
}

/**
 * @TODO: Documentation
 */
void BTeki::doKill()
{
	PRINT_NAKATA("BTeki::doKill:%08x\n", this);
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

/**
 * @TODO: Documentation
 */
void BTeki::exitCourse()
{
	PRINT_NAKATA("BTeki::exitCourse:%08x\n", this);
	for (int i = 0; i < 4; i++) {
		if (mParticleGenerators[i]) {
			mParticleGenerators[i]->forceFinish();
			mParticleGenerators[i] = nullptr;
		}
	}

	mParticleGenPack->forceFinish();
}

/**
 * @TODO: Documentation
 */
void BTeki::gravitate(f32 accel)
{
	f32 fTime = NSystem::getFrameTime();
	mActionVelocity.y -= accel * fTime;
	Vector3f vec(mActionVelocity);
	vec.scale(fTime);
	mSRT.t.add(vec);
	f32 seaLevel = getSeaLevel();
	if (getPosition().y <= seaLevel) {
		getPosition().y = seaLevel;
		bounceCallback();
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
bool BTeki::stimulate(immut Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actTeki(static_cast<Teki*>(this));
	}
	return false;
}

/**
 * @TODO: Documentation
 */
f32 BTeki::getiMass()
{
	f32 weight = getParameterF(TPF_Weight);
	if (weight <= 0.0f) {
		return 0.0f;
	}
	return 1.0f / (getScaleRate() * weight);
}

/**
 * @TODO: Documentation
 */
f32 BTeki::getTekiCollisionSize()
{
	return getCentreSize();
}

/**
 * @TODO: Documentation
 */
void BTeki::makeDamaged()
{
	mHealth -= mStoredDamage;
	if (mHealth < 0.0f) {
		mHealth = 0.0f;
	}

	mStoredDamage = 0.0f;
}

/**
 * @TODO: Documentation
 */
void BTeki::startDamageMotion(f32 period, f32 amp)
{
	if (timerElapsed(3)) {
		mTimers[3] = period;
		mVibrationController->makeVibrationFunction(0.0f, period, amp);
	}
}

/**
 * @TODO: Documentation
 */
void BTeki::releasePlatCollisions()
{
	PRINT_NAKATA("releasePlatCollisions:%08x:\n", this);
	mPlatMgr.release();
}

/**
 * @TODO: Documentation
 */
void BTeki::createDeadEffect()
{
	immut Vector3f& effectPos = getBoundingSphereCentre();
	int carcassSize           = getParameterI(TPI_CarcassSize);
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

/**
 * @TODO: Documentation
 */
void BTeki::createSoulEffect()
{
	immut Vector3f& effectPos = getBoundingSphereCentre();
	int carcassSize           = getParameterI(TPI_CarcassSize);
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

/**
 * @TODO: Documentation
 */
void BTeki::spawnItems()
{
	// spawn item
	ID32& id = mPersonality->mID;
	if (!id.match('none')) {
		PRINT_NAKATA("spawnItems:%08x:spawn item:%s\n", this, id.mStringID);
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
		PRINT_NAKATA("spawnItems:spawnWaters:%08x:%d,%d,%d\n", this, min, max, nectarNum);
		spawnWaters(nectarNum);
	}
}

/**
 * @TODO: Documentation
 */
void BTeki::spawnPellets(int kind, int color, int count)
{
	PRINT_NAKATA("spawnPellets:%08x:%d,%d,%d\n", this, kind, color, count);
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

/**
 * @TODO: Documentation
 */
void BTeki::spawnWaters(int count)
{
	PRINT_NAKATA("spawnWaters:%08x:%d\n", this, count);
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

/**
 * @TODO: Documentation
 */
void BTeki::spawnCorpseParts()
{
	return getStrategy()->spawnCorpseParts(*static_cast<Teki*>(this));
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000140
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

/**
 * @TODO: Documentation
 */
void BTeki::outputSpawnPosition(Vector3f& spawnPos)
{
	outputDirectionPosition(spawnPos, getParameterF(TPF_SpawnDistance), getParameterF(TPF_SpawnHeight));
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BTeki::shootBall(Creature&)
{
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
bool BTeki::cullableCenter(Creature& target, f32 radius)
{
	return roughCull(this, &target, radius);
}

/**
 * @TODO: Documentation
 */
bool BTeki::cullableSphere(Creature& target, f32 radius)
{
	return cullableCenter(target, getBoundingSphereRadius() + target.getBoundingSphereRadius() + radius);
}

/**
 * @TODO: Documentation
 */
bool BTeki::inSectorPosition(immut Vector3f& p1, f32 p2, f32 p3)
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
		PRINT_NAKATA("separateCreature1:%08x:%08x:%f,%f\n", this, &target, range, collDist);
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
f32 BTeki::calcTargetAngle(immut Vector3f& targetPos)
{
	STACK_PAD_VAR(1);

	f32 targetDir = calcTargetDirection(targetPos);
	f32 faceDir   = NMathF::roundAngle(getDirection());
	return NMathF::angleDifference(faceDir, targetDir);
}

/**
 * @TODO: Documentation
 */
bool BTeki::moveToward(immut Vector3f& target, f32 speed)
{
	return moveTowardStatic(getPosition(), target, speed, mTargetVelocity);
}

/**
 * @TODO: Documentation
 */
bool BTeki::turnToward(f32 targetAngle, f32 turnSpeed)
{
	f32 faceDir   = NMathF::roundAngle(getDirection());
	f32 nearerDir = NMathF::calcNearerDirection(faceDir, targetAngle);
	f32 speed     = turnSpeed * NSystem::getFrameTime();

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

/**
 * @TODO: Documentation
 */
void BTeki::rotateTeki(f32 speed)
{
	f32 faceDir = NMathF::roundAngle(getDirection());
	f32 amt     = speed * NSystem::getFrameTime();

	setDirection(faceDir + amt);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000218
 */
void BTeki::jumpTo(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000168
 */
bool BTeki::insideDirection(Vector3f&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
Creature* BTeki::getClosestNaviPiki(immut Condition& cond, f32* outDist)
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

/**
 * @TODO: Documentation
 */
bool BTeki::attackTarget(Creature& target, f32 range, f32 damage, immut Condition& cond)
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

/**
 * @TODO: Documentation
 */
void BTeki::outputHitCenter(Vector3f& outCenter)
{
	Vector3f dir;
	outputDirectionVector(dir);
	dir.scale(getTekiCollisionSize() + getAttackRange());
	outCenter.add2(getPosition(), dir);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001F4
 */
bool BTeki::attackRangeNaviPiki(immut Interaction&, immut Condition&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00015C
 */
bool BTeki::interactTeki(immut Interaction&, immut Condition&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
bool BTeki::interactNaviPiki(immut Interaction& interaction, immut Condition& cond)
{
	bool navi = interactNavi(interaction, cond);
	bool piki = interactPiki(interaction, cond);

	return navi || piki;
}

/**
 * @TODO: Documentation
 */
bool BTeki::interactNavi(immut Interaction& interaction, immut Condition& cond)
{
	bool res   = false;
	Navi* navi = naviMgr->getNavi();
	if (cond.satisfy(navi)) {
		navi->stimulate(interaction);
		res = true;
	}

	return res;
}

/**
 * @TODO: Documentation
 */
bool BTeki::interactPiki(immut Interaction& interaction, immut Condition& cond)
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

/**
 * @TODO: Documentation
 */
void BTeki::flick()
{
	flickUpper();
	flickLower();
}

/**
 * @TODO: Documentation
 */
void BTeki::flick(InteractFlick& upperFlick, InteractFlick& lowerFlick)
{
	flickUpper(upperFlick);
	flickLower(lowerFlick);
}

/**
 * @TODO: Documentation
 */
void BTeki::flickUpper()
{
	InteractFlick NRef flick = InteractFlick(this, getParameterF(TPF_UpperFlickPower), 0.0f, FLICK_BACKWARDS_ANGLE);
	flickUpper(flick);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BTeki::flickLower()
{
	InteractFlick NRef flick
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

/**
 * @TODO: Documentation
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
	STACK_PAD_TERNARY(flick.mAngle, 9);
}

/**
 * @TODO: Documentation
 */
bool BTeki::checkNaviPiki(immut Condition& cond)
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

/**
 * @TODO: Documentation
 */
int BTeki::countPikis(immut Condition& cond)
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000148
 */
int BTeki::countTekis(immut Condition& cond)
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BTeki::eventPerformed(immut TekiEvent& event)
{
	TekiStrategy* tekiEvent = getStrategy();
	tekiEvent->eventPerformed(event);
}

/**
 * @TODO: Documentation
 */
void BTeki::collisionCallback(immut CollEvent& event)
{
	if (!isAlive()) {
		return;
	}

	Creature* collider = event.mCollider;
	if (collider->isAlive()) {
		eventPerformed(TekiEvent(TekiEventType::Entity, static_cast<Teki*>(this), collider));
	}
}

/**
 * @TODO: Documentation
 */
bool BTeki::ignoreAtari(Creature* target)
{
	if (target->getStickObject() == this) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void BTeki::bounceCallback()
{
	eventPerformed(TekiEvent(TekiEventType::Ground, static_cast<Teki*>(this)));
}

/**
 * @TODO: Documentation
 */
void BTeki::wallCallback(immut Plane&, DynCollObject*)
{
	eventPerformed(TekiEvent(TekiEventType::Wall, static_cast<Teki*>(this)));
}

/**
 * @TODO: Documentation
 */
bool BTeki::interact(immut TekiInteractionKey& key)
{
	TekiStrategy* strat = getStrategy();
	return strat->interact(*static_cast<Teki*>(this), key);
}

/**
 * @TODO: Documentation
 */
bool BTeki::interactDefault(immut TekiInteractionKey& key)
{
	STACK_PAD_VAR(1);
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

/**
 * @TODO: Documentation
 */
f32 BTeki::getGravity()
{
	return AIConstant::_instance->mConstants.mGravity();
}

/**
 * @TODO: Documentation
 */
TekiStrategy* BTeki::getStrategy()
{
	return tekiMgr->getStrategy(mTekiType);
}

/**
 * @TODO: Documentation
 */
f32 BTeki::getSeaLevel()
{
	immut Vector3f& pos = getPosition();
	return mapMgr->getMinY(pos.x, pos.z, true);
}

/**
 * @TODO: Documentation
 */
f32 BTeki::getYFromSeaLevel()
{
	immut Vector3f& pos = getPosition();
	return pos.y - getSeaLevel();
}

/**
 * @TODO: Documentation
 */
void BTeki::makePositionRoute(immut Vector3f& pos1, immut Vector3f& pos2, bool includeBlockedPaths)
{
	int idx2 = getTargetNearestWayPoint(pos2)->mIndex;
	int idx1 = getTargetNearestWayPoint(pos1)->mIndex;
	makeWayPointRoute(idx1, idx2, includeBlockedPaths);
}

/**
 * @TODO: Documentation
 */
void BTeki::makeWayPointRoute(int p1, int p2, bool includeBlockedPaths)
{
	for (int i = 0; i < mRouteWayPointMax; i++) {
		mRouteWayPoints[i] = nullptr;
	}

	mRouteWayPointCount = routeMgr->getPathFinder(mPathHandle)->findSync(mRouteWayPoints, mRouteWayPointMax, p1, p2, includeBlockedPaths);

	if (mRouteWayPointCount > mRouteWayPointMax) {
		PRINT("!makeWayPointRoute:routeWayPointCount>routeWayPointMax:%08x:%d,%d\n", this, mRouteWayPointCount, mTekiType);
	}

	PRINT_NAKATA("makeWayPointRoute:%08x,%d->%d,%d\n", this, p1, p2, mRouteWayPointCount);
	if (mRouteWayPointCount == 0) {
		PRINT("!makeWayPointRoute:%08x,%d->%d,%d\n", this, p1, p2, mRouteWayPointCount);
	}
}

/**
 * @TODO: Documentation
 */
WayPoint* BTeki::getTargetNearestWayPoint(immut Vector3f& pos)
{
	return routeMgr->findNearestWayPoint(mPathHandle, pos, false);
}

/**
 * @TODO: Documentation
 */
WayPoint* BTeki::getNearestWayPoint()
{
	return getTargetNearestWayPoint(getPosition());
}

/**
 * @TODO: Documentation
 */
WayPoint* BTeki::getWayPoint(int wpIdx)
{
	return routeMgr->getWayPoint(mPathHandle, wpIdx);
}

/**
 * @TODO: Documentation
 */
WayPoint* BTeki::getRouteWayPoint(int idx)
{
	if (idx < 0 || idx > mRouteWayPointMax) {
		PRINT("!getRouteWayPoint:%08x:%d,%d\n", this, idx, mTekiType);
		return nullptr;
	}

	return mRouteWayPoints[idx];
}

/**
 * @TODO: Documentation
 */
void BTeki::updateLifeGauge()
{
	mLifeGauge.updValue(mHealth, getParameterF(TPF_Life));
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
	STACK_PAD_TERNARY(rad, 2);
}

/**
 * @TODO: Documentation
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

	mWorldMtx.makeVQS(mSRT.t, q1, mSRT.s);

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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BTeki::drawRange(Graphics& gfx, immut Vector3f& centre, f32 range, immut Colour& colour)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx1.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
	gfx.setColour(colour, true);
	gfx.drawSphere(centre, range, mtx2);
}

/**
 * @TODO: Documentation
 */
void BTeki::refresh2d(Graphics& gfx)
{
	if (mDeadState != 0 || !tekiMgr->hasModel(mTekiType) || !isVisible() || isCreatureFlag(CF_UseAICulling)) {
		return;
	}

	if (getTekiOption(TEKIOPT_LifeGaugeVisible)) {
		immut Vector3f& pos = getCentre();
		mLifeGauge.mPosition.input(pos);
		mLifeGauge.mOffset.y = getParameterF(TPF_LifeGaugeOffset);
		mLifeGauge.mScale    = 5000.0f / gfx.mCamera->mNear;
		mLifeGauge.refresh(gfx);
	}

	// w/e man.
	STACK_PAD_TERNARY(mDeadState, 1);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BTeki::playSound(int soundID)
{
	mSeContext->playSound(soundID);
}

/**
 * @TODO: Documentation
 */
void BTeki::stopSound(int soundID)
{
	mSeContext->stopSound(soundID);
}

/**
 * @TODO: Documentation
 */
void BTeki::createTekiEffect(int effectID)
{
	PRINT_NAKATA("createTekiEffect:%08x,%d:%d\n", this, mTekiType, effectID);
	TekiStrategy* strategy = tekiMgr->getStrategy(mTekiType);
	strategy->createEffect(*(Teki*)this, effectID);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
Matrix4f& BTeki::getCameraAnimationMatrix(int idx)
{
	return mTekiShape->mShape->getAnimMatrix(idx);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
void BTeki::outputWorldAnimationMatrix(Matrix4f& mtx1, int idx, immut Matrix4f& mtx2)
{
	immut Matrix4f& animMtx = getCameraAnimationMatrix(idx);
	NMatrix4f tmp;
	tmp.construct(animMtx);
	tmp.makeIdentRow(3);
	mtx2.multiplyTo(tmp, mtx1);
}

/**
 * @TODO: Documentation
 */
void BTeki::outputWorldAnimationPosition(Vector3f& p1, int p2, immut Matrix4f& p3)
{
	NMatrix4f tmp;
	outputWorldAnimationMatrix(tmp, p2, p3);
	tmp.outputCol(3, p1);
}

/**
 * @TODO: Documentation
 */
int BTeki::getPositionMapCode(immut Vector3f& pos)
{
	CollTriInfo* currentTri = mapMgr->getCurrTri(pos.x, pos.z, true);
	if (currentTri == nullptr) {
		PRINT("!getPositionMapCode:%08x\n", this);
		return -1;
	}

	return MapCode::getAttribute(currentTri);
}

/**
 * @TODO: Documentation
 */
int BTeki::getPositionMapCode()
{
	return getPositionMapCode(getPosition());
}

/**
 * @TODO: Documentation
 */
bool BTeki::inWaterTeki()
{
	if (getPositionMapCode() == ATTR_Water) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void BTeki::moveNestPosition()
{
	mSRT.t = mPersonality->mNestPosition;
}

/**
 * @TODO: Documentation
 */
void BTeki::startParticleGenerator(int param_1)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->startGen();
	}
}

/**
 * @TODO: Documentation
 */
void BTeki::stopParticleGenerator(int param_1)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->stopGen();
	}
}

/**
 * @TODO: Documentation
 */
void BTeki::setParticleGeneratorPosition(int param_1, immut Vector3f& effectPos)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->setEmitPos(effectPos);
	}
}

/**
 * @TODO: Documentation
 */
void BTeki::setParticleGeneratorDirection(int param_1, immut Vector3f& effectDir)
{
	zen::particleGenerator* particleGenerator = mParticleGenerators[param_1];
	if (particleGenerator != nullptr) {
		particleGenerator->setEmitDir(effectDir);
	}
}

/**
 * @TODO: Documentation
 */
f32 BTeki::calcCollisionDistance(Creature& creature)
{
	f32 dist = qdist2(getCentre().x, getCentre().z, creature.getCentre().x, creature.getCentre().z);

	f32 collSize         = getCollisionSize();
	f32 creatureCollSize = creature.getCentreSize();

	return dist - creatureCollSize - collSize;
}

/**
 * @TODO: Documentation
 */
f32 BTeki::getCollisionSize()
{
	return getCentreSize();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
Vector3f BTeki::getCollisionCenter()
{
	// UNUSED FUNCTION
}
