#include "AIPerf.h"
#include "Age.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "Font.h"
#include "Graphics.h"
#include "Interactions.h"
#include "ItemMgr.h"
#include "KMath.h"
#include "MapMgr.h"
#include "Pellet.h"
#include "PelletState.h"
#include "PelletView.h"
#include "PlayerState.h"
#include "RadarInfo.h"
#include "SoundMgr.h"
#include "StateMachine.h"
#include "Stickers.h"
#include "UtEffect.h"
#include "jaudio/pikiinter.h"
#include "teki.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(33)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("pel");

bool SmartTurnOver;

static u32 _ufoIDTable[] = {
	UFOID_Bowsprit,
	UFOID_GluonDrive,
	UFOID_AntiDioxinFilter,
	UFOID_EternalFuelDynamo,
	UFOID_MainEngine,
	UFOID_WhimsicalRadar,
	UFOID_InterstellarRadio,
	UFOID_GuardSatellite,
	UFOID_ChronosReactor,
	UFOID_RadiationCanopy,
	UFOID_GeigerCounter,
	UFOID_Sagittarius,
	UFOID_Libra,
	UFOID_OmegaStabilizer,
	UFOID_IoniumJet1,
	UFOID_IoniumJet2,
	UFOID_ShockAbsorber,
	UFOID_GravityJumper,
	UFOID_PilotSeat,
	UFOID_NovaBlaster,
	UFOID_AutomaticGear,
	UFOID_ZirconiumRotor,
	UFOID_ExtraordinaryBolt,
	UFOID_RepairTypeBolt,
	UFOID_SpaceFloat,
	UFOID_MassageMachine,
	UFOID_SecretSafe,
	UFOID_PositronGenerator,
	UFOID_AnalogComputer,
	UFOID_UVLamp,
	UFOID_UNDEF,
};

/**
 * @todo: Documentation
 */
int PelletMgr::getUfoIndexFromID(u32 ufoID)
{
	int i;
	for (i = 0;; i++) {
		if (_ufoIDTable[i] == UFOID_UNDEF) {
			return -1;
		}

		if (_ufoIDTable[i] == ufoID) {
			return i;
		}
	}

	return i;
}

/**
 * @todo: Documentation
 */
u32 PelletMgr::getUfoIDFromIndex(int idx)
{
	if (idx < 0 || idx >= MAX_UFO_PARTS) {
		ERROR("N MECK!\n");
	}
	return _ufoIDTable[idx];
}

/**
 * @todo: Documentation
 */
PelletConfig::PelletConfig()
    : mPelletName(this, String("new", 0), String("", 0), String("", 0), "x99", "theName")
    , mPelletType(this, PELTYPE_Blue, 0, 0, "p00", "type(0-2:pel 3:ufo)")
    , mPelletColor(this, PELCOLOR_NULL, 0, 0, "p09", "color type")
    , mCarryMinPikis(this, 1, 0, 0, "p01", "min pikis")
    , mCarryMaxPikis(this, 1, 0, 0, "p02", "max pikis")
    , mUseDynamicMotion(this, 0, 0, 0, "p03", "dynamics")
    , _A0(this, 10.0f, 0.0f, 0.0f, "p04", "dynParm1")
    , _B0(this, 4.0f, 0.0f, 0.0f, "p05", "dynParm2")
    , _C0(this, 4, 0, 0, "p08", "dynCollNums")
    , mMatchingOnyonSeeds(this, 1, 0, 0, "p06", "intParm1")
    , mNonMatchingOnyonSeeds(this, 1, 0, 0, "p07", "intParm2")
    , mPelletScale(this, 1.0f, 0.0f, 0.0f, "p10", "scale")
    , mCarryInfoHeight(this, 30.0f, 0.0f, 0.0f, "p11", "height")
    , mAnimSoundID(this, 6, 0, 0, "p12", "sound")
    , mBounceSoundID(this, 0xFFFFFFFF, 0, 0, "p13", "bounceSound")
{
	mModelId.setID('none');
	mUnusedId.setID('none');
	mPelletId.setID('none');
	initCore("pelletConfig");
	mRepairAnimJointIndex = -1;
}

/**
 * @todo: Documentation
 */
void PelletConfig::read(RandomAccessStream& input)
{
	Parameters::read(input);
	mModelId.read(input);
	mPelletId.read(input);
	mUnusedId.read(input);
	mRepairAnimJointIndex = input.readInt();
}

#if defined(VERSION_GPIJ01_01)
#else
// see PelletBounceSoundID in Pellet.h
static u32 bounceSounds[] = {
	SE_PELLET_BOUND,   SE_UFOPARTS_BOUND, SE_UFOPARTS_SPRING, SE_UFOPARTS_MONEYBOX, SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND,
	SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND,  SE_UFOPARTS_BOUND,    SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND,
};

NumberPel numberPellets[13] = {
	{ PELCOLOR_Blue, NUMPEL_OnePellet, 'pb01' },   { PELCOLOR_Blue, NUMPEL_FivePellet, 'pb05' },
	{ PELCOLOR_Blue, NUMPEL_TenPellet, 'pb10' },   { PELCOLOR_Blue, NUMPEL_TwentyPellet, 'pb20' },
	{ PELCOLOR_Red, NUMPEL_OnePellet, 'pr01' },    { PELCOLOR_Red, NUMPEL_FivePellet, 'pr05' },
	{ PELCOLOR_Red, NUMPEL_TenPellet, 'pr10' },    { PELCOLOR_Red, NUMPEL_TwentyPellet, 'pr20' },
	{ PELCOLOR_Yellow, NUMPEL_OnePellet, 'py01' }, { PELCOLOR_Yellow, NUMPEL_FivePellet, 'py05' },
	{ PELCOLOR_Yellow, NUMPEL_TenPellet, 'py10' }, { PELCOLOR_Yellow, NUMPEL_TwentyPellet, 'py20' },
	{ PELCOLOR_NULL, NUMPEL_NULL, 'ujaa' },
};
#endif

/**
 * @todo: Documentation
 */
void PelletView::becomePellet(u32 id, Vector3f NRef pos, f32 direction)
{
	if (mPellet) {
		PRINT("becomePellet twice **\n");
		return;
	}

	Pellet* pellet = pelletMgr->newPellet(id, this);
	if (!pellet) {
		return;
	}

	f32 minY = mapMgr->getMinY(pos.x, pos.z, true);
	f32 maxY = mapMgr->getMaxY(pos.x, pos.z, true);

	if (absF(pos.y - maxY) < absF(pos.y - minY)) {
		pos.y = maxY;
	} else {
		pos.y = minY;
	}

	pellet->init(pos);
	pellet->mFaceDirection = direction;
	pellet->mRotationQuat.fromEuler(Vector3f(0.0f, direction, 0.0f));
	pellet->mSRT.r.set(0.0f, direction, 0.0f);
	pellet->mVelocity.set(0.0f, 0.0f, 0.0f);
	pellet->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	pellet->mAngularMomentum.set(0.0f, 0.0f, 0.0f);
	pellet->mAngularVelocity.set(0.0f, 0.0f, 0.0f);
	pellet->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	pellet->_B0.set(0.0f, 0.0f, 0.0f);
	pellet->startAI(0);
	pellet->useRealDynamics();

	mPellet = pellet;
}

/**
 * @todo: Documentation
 */
Pellet::Pellet()
{
	mUseSpawnPosition = true;
	mSpawnPosition.set(0.0f, 0.0f, 0.0f);
	mSeContext = new SeContext();
	mSeContext->setContext(this, JACEVENT_Pellet);
	mRippleEffect   = new RippleEffect();
	mPelletView     = nullptr;
	mPikiCarrier    = nullptr;
	mShapeObject    = nullptr;
	mConfig         = nullptr;
	mMotionSpeed    = 0.0f;
	mObjType        = OBJTYPE_Pellet;
	mCollInfo       = nullptr;
	mPelletCollInfo = new CollInfo(6);
	mCurrentState   = nullptr;
	mStateMachine   = new PelletStateMachine();
	mStateMachine->init(this);
	mSearchBuffer.init(mSearchData, 4);
	mCollisionRadius = 4.0f;
	mCarryDirection.set(0.0f, 0.0f, 0.0f);
	setTrySound(false);
}

/**
 * @todo: Documentation
 */
bool Pellet::isUfoPartsID(u32 partsID)
{
	ID32 id(partsID);
	return id.match('u***');
}

/**
 * @todo: Documentation
 */
void Pellet::startWaterEffect()
{
	EffectParm unused(&mSRT.t); // lol.
	EffectParm parm(mSRT.t);
	unused.mScale = 2.0f; // this is so dumb
	UtEffectMgr::cast(KandoEffect::Bubbles, parm);
}

/**
 * @todo: Documentation
 */
void Pellet::finishWaterEffect()
{
	mRippleEffect->kill();
}

/**
 * @todo: Documentation
 */
void Pellet::doKill()
{
	setTrySound(false);
	mIsAlive = 0;
	if (mPelletView) {
		mPelletView->viewKill();
		mPelletView = nullptr;
	}
	mSeContext->releaseEvent();
	DualCreature::doKill();
	pelletMgr->kill(this);
	mLifeGauge.countOff();
}

/**
 * @todo: Documentation
 */
int Pellet::getState()
{
	if (mCurrentState) {
		return mCurrentState->getID();
	}
	return PELSTATE_Normal;
}

/**
 * @todo: Documentation
 */
bool Pellet::ignoreAtari(Creature* creature)
{
	if (creature->getStickObject() == this) {
		return true;
	}

	// The following C-style cast is illegal, as `Creature` does not inherit from `PelletView`.
	if (mPelletView && creature == TERNARY_BUGFIX(static_cast<BTeki*>, (Creature*))(mPelletView)) {
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool Pellet::isAlive()
{
	return mIsAlive;
}

/**
 * @todo: Documentation
 */
bool Pellet::isAtari()
{
	int state = getState();
	if (state == PELSTATE_Appear) {
		return false;
	}
	if (state == PELSTATE_Swallowed || state == PELSTATE_Goal) {
		return false;
	}
	return true;
}

/**
 * @todo: Documentation
 */
bool Pellet::isVisible()
{
	int state = getState();
	if (!mIsAlive) {
		return false;
	}

	if (state == PELSTATE_Goal || state == PELSTATE_Appear || state == PELSTATE_Dead) {
		return false;
	}
	return true;
}

/**
 * @todo: Documentation
 */
void Pellet::setTrySound(bool doSetOn)
{
	if (!doSetOn) {
		mIsPlayTrySound = false;
		stopEventSound(this, SE_LIFT_TRY);

	} else if (!mIsPlayTrySound && getPickOffset() == 0.0f) {
		playEventSound(this, SE_LIFT_TRY);
		mIsPlayTrySound = true;
	}
}

/**
 * @todo: Documentation
 */
void Pellet::startPick()
{
	if (!playerState->mDemoFlags.isFlag(DEMOFLAG_Unk9)) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk9);
	}

	setTrySound(false);
	disableFixPos();
	resetCreatureFlag(CF_IsPositionFixed);
	disableFriction();
	startCarryMotion(30.0f);

	if (!mPelletView) {
		if (isMotionFlag(PelletMotionFlags::UsePiston)) {
			mAnimator.startMotion(PaniMotionInfo(PelletMotion::Carry), PaniMotionInfo(PelletMotion::Piston, this));
		} else {
			mAnimator.startMotion(PaniMotionInfo(PelletMotion::Carry));
		}
	}

	f32 offset = 8.0f;
	if (mPelletView) {
		offset = 4.0f;
	} else {
		offset = offset / mSRT.s.y;
	}

	f32 dir = 1.0f;
	if (!isFrontFace()) {
		dir = -1.0f;
	}

	enablePickOffset(offset);

	Stickers stuckList(this);
	Iterator iter(&stuckList);
	bool isOnlyPiki = true;
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck->isTeki()) {
			isOnlyPiki = false;
		}

		stuck->mAttachPosition.y -= offset * dir;
	}

	if (!isOnlyPiki) {
		disablePickOffset();
		CI_LOOP(iter)
		{
			(*iter)->mAttachPosition.y += offset * dir;
		}
	}

	f32 minY = mapMgr->getMinY(mSRT.t.x, mSRT.t.z, true);
	if (minY > mSRT.t.y) {
		PRINT("************* START PICK YABAI !!!\n");
	}
	if (!isRealDynamics()) {
		mSRT.t.y += offset;
	}
}

/**
 * @todo: Documentation
 */
void Pellet::finishPick()
{
	mCarrierCounter = 0;
	enableFixPos();
	stopEventSound(this, SE_LIFT_MOVE);
	stopEventSound(this, SE_LIFT_TRY);
	enableFriction();
	finishMotion();
	disablePickOffset();
	mCarryState = 0;
}

/**
 * @todo: Documentation
 */
void Pellet::startGoal()
{
	finishPick();
	mStateMachine->transit(this, PELSTATE_Goal);
	mPikiCarrier = nullptr;
	mCarryDirection.set(0.0f, 0.0f, 0.0f);
}

/**
 * @todo: Documentation
 */
void Pellet::doCarry(Creature* carryingPiki, immut Vector3f& direction, u16 carrierCount)
{
	if (mCarryState == 1) {
		mTransitionTimer -= gsys->getFrameTime();
		if (mTransitionTimer <= 0.0f) {
			mCarryState = 2;
		}

		mCarryDirection = direction * 0.5f;
		return;
	}

	if (mPikiCarrier && mPikiCarrier->mObjType != carryingPiki->mObjType) {
		if (mCarryState == 0) {
			mCarryState      = 1;
			mTransitionTimer = 3.5f;
			return;
		}

		if (mPikiCarrier->getStickObject() == this && mCarrierCount > carrierCount) {
			PRINT("%s win\n", ObjType::getName(mPikiCarrier->mObjType));
			return;
		}

		mCarryDirection = direction;
		mPikiCarrier    = carryingPiki;
		mCarrierCount   = carrierCount;
		PRINT("%s win\n", ObjType::getName(mPikiCarrier->mObjType));
		mCarryState      = 1;
		mTransitionTimer = 3.5f;

		return;
	}

	mCarryDirection = direction;
	mPikiCarrier    = carryingPiki;
	mCarrierCount   = carrierCount;
}

/**
 * @todo: Documentation
 */
f32 Pellet::getBottomRadius()
{
	if (mPelletView) {
		return mPelletView->viewGetBottomRadius();
	}

	bool hasCentPart = false;
	if (mCollInfo && mCollInfo->hasInfo() && mCollInfo->getSphere('cent')) {
		hasCentPart = true;
	}

	if (!hasCentPart) {
		if (!mPelletView) {
			PRINT("PELLE IS %s (view=%x)\n", mConfig->mPelletName.mValue.mString, mPelletView);
			PRINT("*** NO VIEW NO CENT :: SIZE 10\n");
			static int count = 0;
			count++;
			if (count > 10) {
				if (isAlive()) {
					ERROR("okasii!\n");
				}

				ERROR("who called me ?\n");
			}
			return 10.0f;
		}

		PRINT("PELLE IS %s (view=%x)\n", mConfig->mPelletName.mValue.mString, mPelletView);
		// The following C-style cast is illegal, as `Creature` does not inherit from `PelletView`.
		PRINT("if view is creature, the name is %s\n",
		      ObjType::getName((TERNARY_BUGFIX(static_cast<BTeki*>, (Creature*))(mPelletView))->mObjType));
		ERROR("BottomRadius Loop\n");
	}

	return getCentreSize();
}

/**
 * @todo: Documentation
 */
Vector3f Pellet::getCentre()
{
	return mSRT.t;
}

/**
 * @todo: Documentation
 */
f32 Pellet::getCylinderHeight()
{
	if (mPelletView) {
		return mPelletView->viewGetHeight();
	}
	return mConfig->mCarryInfoHeight();
}

/**
 * @todo: Documentation
 */
f32 Pellet::getSize()
{
	if (mPelletView) {
		Vector3f viewScale(mPelletView->viewGetScale());
		return viewScale.x * mPelletView->viewGetBottomRadius();
	}
	return getBottomRadius();
}

/**
 * @todo: Documentation
 */
f32 Pellet::getiMass()
{
	return 0.0f;
}

/**
 * @todo: Documentation
 */
bool Pellet::startStickTeki(Creature* teki, f32 p2)
{
	Vector3f toEnemy = getCentre();
	toEnemy          = teki->getCentre() - toEnemy;
	f32 angle        = atan2f(toEnemy.x, toEnemy.z);
	mStuckAngle      = roundAng(angle - mFaceDirection);

	teki->startStickObject(this, nullptr, -2, p2);
	if (teki->getStickObject() != this) {
		return false;
	}

	startPick();
	return true;
}

/**
 * @todo: Documentation
 */
void Pellet::endStickTeki(Creature* teki)
{
	finishPick();
	teki->endStickObject();
}

/**
 * @todo: Documentation
 */
bool Pellet::winnable(int tekiStrength)
{
	if (mConfig->mModelId.match('NAVI')) {
		// breadbugs aren't allowed to yoink sleeping captains.
		return false;
	}

	Stickers stuckList(this);
	Iterator iter(&stuckList);
	int pikiCount = 0;
	CI_LOOP(iter)
	{
		if ((*iter)->isPiki()) {
			pikiCount++;
		}
	}

	if (tekiStrength > pikiCount) {
		// not enough pikis - get dragged to the nest losers!
		return true;
	}

	// get boot scooted to the onyon bread boi
	return false;
}

/**
 * @todo: Documentation
 */
bool Pellet::stickSlot(int slotID)
{
	if (slotID != -1 && !isSlotFlag(slotID)) {
		// valid, empty slot - fill it.
		setSlotFlag(slotID);
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void Pellet::stickOffSlot(int slotID)
{
	if (slotID != -1 && isSlotFlag(slotID)) {
		// valid, filled slot - reset it.
		resetSlotFlag(slotID);
	}
}

/**
 * @todo: Documentation
 */
int Pellet::getMinFreeSlotIndex()
{
	for (int i = 0; i < mConfig->mCarryMaxPikis(); i++) {
		if (!isSlotFlag(i)) {
			return i;
		}
	}

	return -1;
}

/**
 * @todo: Documentation
 */
int Pellet::getNearestFreeSlotIndex(immut Vector3f& pos)
{
	f32 minDist    = 12800.0f;
	int nearestIdx = -1;
	for (int i = 0; i < mConfig->mCarryMaxPikis(); i++) {
		if (!isSlotFlag(i)) {
			// free slot, how far away is it
			Vector3f slotSep = getSlotGlobalPos(i, 0.0f) - pos;
			f32 slotDist     = slotSep.length();
			if (slotDist < minDist) {
				minDist    = slotDist;
				nearestIdx = i;
			}
		}
	}

	return nearestIdx;
}

/**
 * @todo: Documentation
 */
int Pellet::getRandomFreeSlotIndex()
{
	int maxCarryNum = mConfig->mCarryMaxPikis();
	int randIdx     = gsys->getRand(1.0f) * maxCarryNum;
	int idDist      = 128;
	int outIdx      = -1;
	for (int i = 0; i < maxCarryNum; i++) {
		if (!isSlotFlag(i)) {
			// there are like 50 abs inlines, you could've just used one kando.
			int slotidDist = (i - randIdx > 0) ? i - randIdx : -(i - randIdx);
			// looking for "nearest" free slot to our randomly picked slot ID
			if (slotidDist < idDist) {
				idDist = slotidDist;
				outIdx = i;
			}
		}
	}

	return outIdx;
}

/**
 * @todo: Documentation
 */
Vector3f Pellet::getSlotLocalPos(int slotID, f32 offset)
{
	f32 grabAngle;
	if (slotID == -2) {
		grabAngle = mStuckAngle;
	} else {
		grabAngle = (TAU / mConfig->mCarryMaxPikis()) * slotID;
	}

	f32 grabRadius;
	f32 pickupHeight = mPickOffset;
	if (!mPelletView) {
		grabRadius = getBottomRadius() + offset;
		grabRadius /= mSRT.s.x;
	} else {
		grabRadius = getBottomRadius() + offset;
	}

	Vector3f localPos;
	if (SmartTurnOver) {
		f32 y = pickupHeight;
		if (getGroundFlag() != 0x55) {
			y = getCylinderHeight() - pickupHeight;
		}
		localPos.set(grabRadius * sinf(grabAngle), y, grabRadius * cosf(grabAngle));

	} else if (isFrontFace()) {
		localPos.set(grabRadius * sinf(grabAngle), pickupHeight, grabRadius * cosf(grabAngle));

	} else {
		f32 y = getCylinderHeight() - pickupHeight;
		localPos.set(grabRadius * sinf(grabAngle), y, grabRadius * cosf(grabAngle));
	}

	return localPos;
}

/**
 * @todo: Documentation
 */
Vector3f Pellet::getSlotGlobalPos(int slotID, f32 offset)
{
	Vector3f globalPos = getSlotLocalPos(slotID, offset);
	globalPos.multMatrix(mWorldMtx);
	return globalPos;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
void Pellet::initSlotFlags()
{
	mSlotFlags[0] = mSlotFlags[1] = mSlotFlags[2] = 0;
}

/**
 * @todo: Documentation
 */
void Pellet::setSlotFlag(int slotID)
{
	if (slotID != -2) {
		// 32 flags per slot, so get correct slot (>> 5 == divide by 32 + drop remainder)
		mSlotFlags[slotID >> 5] |= (1 << (slotID - 32 * (slotID >> 5)));
	}
}

/**
 * @todo: Documentation
 */
void Pellet::resetSlotFlag(int slotID)
{
	if (slotID != -2) {
		// 32 flags per slot, so get correct slot (>> 5 == divide by 32 + drop remainder)
		mSlotFlags[slotID >> 5] &= ~(1 << (slotID - 32 * (slotID >> 5)));
	}
}

/**
 * @todo: Documentation
 */
bool Pellet::isSlotFlag(int slotID)
{
	if (slotID == -2) {
		return false;
	}

	return (mSlotFlags[slotID >> 5] & (1 << (slotID - 32 * (slotID >> 5)))) != 0;
}

/**
 * @todo: Documentation
 */
void Pellet::initPellet(PelletShapeObject* shapeObj, PelletConfig* config)
{
	mCarrierCounter = 0;
	mMotionFlag     = PelletMotionFlags::Unknown;
	mShapeObject    = shapeObj;
	if (shapeObj->isMotionFlag(PelletMotionFlags::UsePiston)) {
		setMotionFlag(PelletMotionFlags::UsePiston);
		if (!isMotionFlag(PelletMotionFlags::UsePiston)) {
			ERROR("WHYYYYYYYYYYY\n"); // same kando
		}
	}

	mConfig   = config;
	mCollInfo = mPelletCollInfo;
	mCollInfo->initInfo(mShapeObject->mShape, nullptr, nullptr);
	f32 scale = config->mPelletScale();
	mSRT.s.set(scale, scale, scale);
	if (config->mPelletColor() != PELCOLOR_NULL || isUfoParts()) {
		mShapeObject->mShape->makeInstance(mAnimatedMaterials, 0);
	}
	PRINT("*** MATERIAL : %d\n", mAnimatedMaterials.mNext);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00007C
 */
void Pellet::initPellet(PelletView* view, PelletConfig* config)
{
	mCarrierCounter = 0;
	mMotionFlag     = PelletMotionFlags::Unknown;
	mPelletView     = view;
	mConfig         = config;
	mSRT.s.set(view->viewGetScale());
	mShapeObject = nullptr;
	mCollInfo    = nullptr;
}

/**
 * @todo: Documentation
 */
void Pellet::startCarryMotion(f32 speed)
{
	mMotionSpeed = speed;
	if (mPelletView) {
		mPelletView->viewStartTrembleMotion(mMotionSpeed);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void Pellet::stopMotion()
{
	if (mPelletView) {
		mPelletView->viewSetMotionSpeed(0.0f);
	} else {
		mMotionSpeed = 0.0f;
	}
}

/**
 * @todo: Documentation
 */
void Pellet::finishMotion()
{
	if (mPelletView) {
		mPelletView->viewFinishMotion();
	} else {
		mAnimator.finishMotion(&PaniMotionInfo(PANI_NO_MOTION), nullptr);
	}
}

/**
 * @todo: Documentation
 */
void Pellet::init(immut Vector3f& pos)
{
	Creature::init(pos);
	if (mShapeObject) {
		mAnimator.init(&mShapeObject->mAnimatorA, &mShapeObject->mAnimatorB, mShapeObject->mAnimMgr, pelletMgr->mUfoMotionTable);
	}
	initSlotFlags();
	enableFriction();
	if (mConfig->mUseDynamicMotion()) {
		setDynamicsSimpleFixed(false);
	} else {
		setDynamicsSimpleFixed(true);
	}

	mCarryState = 0;
}

/**
 * @todo: Documentation
 */
bool Pellet::isFree()
{
	// mSlotFlags needs to be int for resetSlotFlags, this seems to be the easier fix
	if ((u32)(mSlotFlags[0]) == 0 && (u32)(mSlotFlags[1]) == 0 && (u32)(mSlotFlags[2]) == 0) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
void Pellet::doLoad(RandomAccessStream& input)
{
	mUseSpawnPosition     = input.readByte();
	mSpawnPosition.x      = input.readFloat();
	mSpawnPosition.y      = input.readFloat();
	mSpawnPosition.z      = input.readFloat();
	Vector3f displacement = mSpawnPosition - mSRT.t;
	if (displacement.length() < 40.0f) {
		PRINT("UFO PARTS DIDN'T MOVE!\n");
		mSRT.t = mSpawnPosition;
	}
#if defined(VERSION_GPIE01_00) || defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	// This isn't in the USA versions' DLL, meaning that DLL is based on rev 0 instead of rev 1 (it was not recompiled between revisions).
#else
	else if (isNan(mSRT.t.x) || isNan(mSRT.t.y) || isNan(mSRT.t.z)) {
		mSRT.t = mSpawnPosition;
	}
#endif
	else {
		PRINT("PARTS MOVED !!! (%.1f %.1f %.1f)\n", displacement.x, displacement.y, displacement.z);
		// This is really evil (mSRT.t is silently mutated), but ultimately doesn't matter (mSRT.t is overwritten).
		mSRT.t = routeMgr->getSafePosition('test', mSRT.t);
	}

	mSRT.t.y = mapMgr->getMinY(mSRT.t.x, mSRT.t.z, true);
	PRINT_GLOBAL("ufo parts %s : (%.1f %.1f %.1f)", mConfig->mModelId.mStringID, mSRT.t.x, mSRT.t.y, mSRT.t.z);
	disableFixPos();
	enableFixPos();
	mStateMachine->transit(this, PELSTATE_UfoLoad);
}

/**
 * @todo: Documentation
 */
void Pellet::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	if (isMotionFlag(PelletMotionFlags::UsePiston) && event.mEventType == KEY_LoopEnd && isUfoParts() && mConfig->mAnimSoundID() >= 0) {
		playEventSound(this, mConfig->mAnimSoundID() + SE_UFOPARTS_SOUNDTYPE);
	}
}

/**
 * @todo: Documentation
 */
void Pellet::doSave(RandomAccessStream& output)
{
	output.writeByte(mUseSpawnPosition);
	output.writeFloat(mSpawnPosition.x);
	output.writeFloat(mSpawnPosition.y);
	output.writeFloat(mSpawnPosition.z);
}

/**
 * @todo: Documentation
 */
void Pellet::startAI(int doSpawnScaleOff)
{
	mRotationQuat.fromEuler(Vector3f(0.0f, mFaceDirection, 0.0f));
	mSRT.r.set(0.0f, mFaceDirection, 0.0f);
	mLastPosition = mSRT.t;
	enableFixPos();
	if (mUseSpawnPosition) {
		mSpawnPosition = mSRT.t;
	}

	setTrySound(false);
	if (isUfoParts() && mConfig->mAnimSoundID() >= 0) {
		playEventSound(this, mConfig->mAnimSoundID() + SE_UFOPARTS_SOUNDTYPE);
	}

	mIsAlive = true;
	if (isUfoParts()) {
		radarInfo->attachParts(this);
	}

	mTargetGoal     = nullptr;
	mStuckMouthPart = 0;
	mPikiCarrier    = nullptr;

	// Pellets using mPelletView (corpses) are forbidden from using `PelletMotionFlags::UsePiston`.  This is because
	// the animation manager for a PelletView will have some unrelated animation at the index `PelletMotion::Piston`.
	bool badMotionOverride = false;
	if (mMotionFlag == (PelletMotionFlags::Unknown | PelletMotionFlags::UsePiston)) {
		badMotionOverride = true;
	}

	if (mPelletView == nullptr) {
		if (isMotionFlag(PelletMotionFlags::UsePiston)) {
			mAnimator.startMotion(PaniMotionInfo(PelletMotion::Carry), PaniMotionInfo(PelletMotion::Piston, this));
			badMotionOverride = false;
		} else {
			mAnimator.startMotion(PaniMotionInfo(PelletMotion::Carry));
		}
	} else {
		startCarryMotion(0.0f);
	}

	if (badMotionOverride) {
		// The string says `isMotionFlag`, but the code says `isCreatureFlag`.  Note that `Creature::isCreatureFlag` is
		// actually `Creature::isFlag` according to the ILK, but we chose to ignore that.  This must have been a typo.
		PRINT("view=%x isMotionFlag() = %s\n", mPelletView,
		      TERNARY_BUGFIX(isMotionFlag, isCreatureFlag)(PelletMotionFlags::UsePiston) ? "true" : "false");
		ERROR("DAME DESU YO !\n"); // 'no you can't!'
	}

	if (mPelletView || doSpawnScaleOff == TRUE) {
		mStateMachine->transit(this, PELSTATE_Normal);
	} else {
		mStateMachine->transit(this, PELSTATE_Appear);
	}

	stopMotion();
	int color;
	int type;
	if (pelletMgr->decomposeNumberPellet(mConfig->mModelId.mId, color, type)) {
		f32 heights[4] = {
			3.3f,
			7.0f,
			13.0f,
			18.0f,
		};
		EffectMgr::effTypeTable effects[4] = {
			EffectMgr::EFF_Empl_01,
			EffectMgr::EFF_Empl_05,
			EffectMgr::EFF_Empl_10,
			EffectMgr::EFF_Empl_20,
		};
		Vector3f pos(mSRT.t);
		pos.y += heights[type];
		mCurrentPelletHeight   = heights[type];
		mCurrentPelletPosition = pos;

		zen::particleGenerator* ptclGen = effectMgr->create(effects[type], pos, nullptr, nullptr);
		if (ptclGen) {
			ptclGen->setEmitPosPtr(&mCurrentPelletPosition);
			_4A0 = 90;
		} else {
			_4A0 = 0;
		}
	} else {
		_4A0 = 0;
	}

	mIsAIActive = true;
}

#if defined(VERSION_GPIJ01_01)
// see PelletBounceSoundID in Pellet.h
static u32 bounceSounds[] = {
	SE_PELLET_BOUND,   SE_UFOPARTS_BOUND, SE_UFOPARTS_SPRING, SE_UFOPARTS_MONEYBOX, SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND,
	SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND,  SE_UFOPARTS_BOUND,    SE_UFOPARTS_BOUND, SE_UFOPARTS_BOUND,
};

NumberPel numberPellets[13] = {
	{ PELCOLOR_Blue, NUMPEL_OnePellet, 'pb01' },   { PELCOLOR_Blue, NUMPEL_FivePellet, 'pb05' },
	{ PELCOLOR_Blue, NUMPEL_TenPellet, 'pb10' },   { PELCOLOR_Blue, NUMPEL_TwentyPellet, 'pb20' },
	{ PELCOLOR_Red, NUMPEL_OnePellet, 'pr01' },    { PELCOLOR_Red, NUMPEL_FivePellet, 'pr05' },
	{ PELCOLOR_Red, NUMPEL_TenPellet, 'pr10' },    { PELCOLOR_Red, NUMPEL_TwentyPellet, 'pr20' },
	{ PELCOLOR_Yellow, NUMPEL_OnePellet, 'py01' }, { PELCOLOR_Yellow, NUMPEL_FivePellet, 'py05' },
	{ PELCOLOR_Yellow, NUMPEL_TenPellet, 'py10' }, { PELCOLOR_Yellow, NUMPEL_TwentyPellet, 'py20' },
	{ PELCOLOR_NULL, NUMPEL_NULL, 'ujaa' },
};
#else
#endif

/**
 * @todo: Documentation
 * @note UNUSED Size: 00007C
 */
void Pellet::startAppear()
{
	mTargetGoal  = nullptr;
	mPikiCarrier = nullptr;
	if (!mPelletView) {
		mAnimator.startMotion(PaniMotionInfo(PelletMotion::Carry));
		mMotionSpeed = 30.0f;
	}
	mStateMachine->transit(this, PELSTATE_Appear);
}

/**
 * @todo: Documentation
 */
void Pellet::doAnimation()
{
	if (mShapeObject) {
		mAnimator.updateAnimation(mMotionSpeed, 30.0f);
	}

	if (mPelletView) {
		mPelletView->viewDoAnimation();
	}
}

/**
 * @todo: Documentation
 */
void Pellet::refresh(Graphics& gfx)
{
	int state = getState();
	if (state == PELSTATE_Swallowed && !pelletMgr->isMovieFlag(1)) {
		return;
	}

	if (state == PELSTATE_Normal && mPickOffset != 0.0f && !pelletMgr->isMovieFlag(2)) {
		return;
	}

	if (pelletMgr->isMovieFlag(4)) {
		DualCreature::refresh(gfx);
	}
}

/**
 * @todo: Documentation
 */
void Pellet::postUpdate(int unused, f32 deltaTime)
{
	int state = getState();
	if (state == PELSTATE_Swallowed && !pelletMgr->isMovieFlag(1)) {
		return;
	}

	if (state == PELSTATE_Normal && mPickOffset != 0.0f && !pelletMgr->isMovieFlag(2)) {
		return;
	}

	if (pelletMgr->isMovieFlag(4)) {
		DualCreature::postUpdate(unused, deltaTime);
	}
}

/**
 * @todo: Documentation
 */
void Pellet::update()
{
#if defined(VERSION_PIKIDEMO)
#define ASSERT_POSITION_NOTNAN(...)  \
	/* Yeah, just the X position. */ \
	if (isNan(mSRT.t.x)) {           \
		ERROR(__VA_ARGS__);          \
	}
#else
#define ASSERT_POSITION_NOTNAN(...)
#endif

	mLastPosition   = mSRT.t;
	bool isOnGround = onGround();
	if (isOnGround && !mIsAIActive && mConfig->mBounceSoundID() != -1) {
		playEventSound(this, bounceSounds[mConfig->mBounceSoundID()]);
		if (getY() < 0.12f) {
			PRINT("*** PELLET FLICK PIKIS !!!\n");
			InteractFlick flick(this, 100.0f, 0.0f, FLICK_BACKWARDS_ANGLE);
			interactStickers(this, flick, nullptr);
		}
	}

	mIsAIActive = isOnGround;
	int state   = getState();

	// TODO: This is supposed to use `isMovieFlag(1)`, but the stack gets too inflated if it does.
	if (state == PELSTATE_Swallowed && !(pelletMgr->mMovieFlags & 1)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (state == PELSTATE_Normal && mPickOffset != 0.0f && !pelletMgr->isMovieFlag(2)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (!pelletMgr->isMovieFlag(4)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (_4A0) {
		_4A0--;
		mCurrentPelletPosition = mSRT.t;
		mCurrentPelletPosition.y += mCurrentPelletHeight;
	}

	Stickers stuckList(this);
	Iterator iter(&stuckList);
	int carryCount = 0;
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki && piki->isPiki()) {
			carryCount++;
		}
	}

	mCarrierCounter      = carryCount;
	f32 height           = getCylinderHeight();
	mLifeGauge.mPosition = mSRT.t;
	mLifeGauge.mPosition.y += height + 5.0f;
	mCollisionRadius = height * 0.5f;

	if (mPickOffset != 0.0f) {
		bool isFinishPick = false;
		if (!mStickListHead) {
			isFinishPick = true;
			PRINT("NO-STICKER- FINISH PICK\n");
		} else if (mPikiCarrier && mPikiCarrier->isPiki()) {
			Stickers stuckList2(this);
			Iterator iter2(&stuckList2);
			int carryCount2 = 0;
			CI_LOOP(iter2)
			{
				Creature* piki = *iter2;
				if (piki && piki->isPiki()) {
					carryCount2++;
				}
			}

			mCarrierCounter = carryCount2;
			if (carryCount2 < mConfig->mCarryMinPikis()) {
				isFinishPick = true;
				PRINT("SHONINZU- FINISH PICK!\n");
			}
		}

		if (isFinishPick) {
			mPikiCarrier = nullptr;
			finishPick();
			return;
		}
	}

	if (mPikiCarrier) {
		if (!mStickListHead) {
			mPikiCarrier = nullptr;
			finishPick();
			return;
		}

		if (onGround()) {
			mVelocity.x = mCarryDirection.x;
			mVelocity.z = mCarryDirection.z;
			mVelocity.y += mCarryDirection.y;
		}

		if (mapMgr->getMinY(mSRT.t.x, mSRT.t.z, true) > mSRT.t.y) {
			PRINT("** YABAI YO!\n");
		}

		bool isTekiAttached    = false;
		Creature* attachedTeki = nullptr;
		if (mPikiCarrier->isPiki()) {
			Stickers stuckList3(this);
			Iterator iter3(&stuckList3);
			STACK_PAD_VAR(1);
			bool isOnlyPiki = true;
			CI_LOOP(iter3)
			{
				Creature* stuck = *iter3;
				if (stuck->isTeki()) {
					isOnlyPiki   = false;
					attachedTeki = stuck;
					break;
				}
			}

			if (!isOnlyPiki) {
				isTekiAttached = true;
			}

			if (isOnlyPiki && mCarrierCounter == 0) {
				stopEventSound(this, SE_LIFT_MOVE);
				stopEventSound(this, SE_LIFT_TRY);
			}
		}

		f32 targetAngle;
		if (isTekiAttached) {
			Vector3f tekiDir = mSRT.t - attachedTeki->mSRT.t;
			targetAngle      = atan2f(tekiDir.x, tekiDir.z);
		} else {
			Vector3f targetDir = mPikiCarrier->mSRT.t - mSRT.t;
			targetAngle        = atan2f(targetDir.x, targetDir.z);
		}

		f32 angle = angDist(atan2f(mVelocity.x, mVelocity.z), targetAngle);
		if (absF(angle) > PI / 20.0f) {
			f32 val = ((6.0f / getBottomRadius()) * 0.7f);
			rotateY(gsys->getFrameTime() * angle * val);
		}
	} else if (mGroundTriangle) {
		f32 rate    = 3.0f * gsys->getFrameTime();
		mVelocity.x = mVelocity.x - mVelocity.x * rate;
		mVelocity.z = mVelocity.z - mVelocity.z * rate;
	}

	ASSERT_POSITION_NOTNAN("pellet nan before fsm!");
	mStateMachine->exec(this);
	ASSERT_POSITION_NOTNAN("pellet nan before dual!");
	DualCreature::update();
	ASSERT_POSITION_NOTNAN("pellet nan after dual!");

	if (mGroundTriangle && isDynFlag(1)) {
		mVelocity = mVelocity - mVelocity * 2.0f * gsys->getFrameTime();
	}

#undef ASSERT_POSITION_NOTNAN
}

/**
 * @todo: Documentation
 */
void Pellet::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	sendMsg(&msg);
}

/**
 * @todo: Documentation
 */
void Pellet::collisionCallback(immut CollEvent& event)
{
	if (isCreatureFlag(CF_AllowFixPosition) && isCreatureFlag(CF_IsPositionFixed)) {
		resetCreatureFlag(CF_IsPositionFixed);
	}
}

/**
 * @todo: Documentation
 */
bool Pellet::stimulate(immut Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actPellet(this);
	}
	return false;
}

/**
 * @todo: Documentation
 */
void Pellet::doRender(Graphics& gfx, Matrix4f& mtx)
{
	if (mStuckMouthPart) {
		Matrix4f jointMtx = mStuckMouthPart->getJointMatrix();
		Matrix4f transformMtx;
		f32 scale = 1.0f / reinterpret_cast<Vector3f*>(&jointMtx)->length();
		transformMtx.makeSRT(Vector3f(scale, scale, scale), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		mSRT.t = mStuckMouthPart->mCentre;
		jointMtx.multiplyTo(transformMtx, mtx);
	}

	if (mPelletView) {
		if (aiCullable()) {
			mPelletView->viewDraw(gfx, mtx);
		}
		return;
	}

	gfx.useMatrix(Matrix4f::ident, 0);
	mAnimator.updateContext();

	if (mConfig->mPelletColor() != PELCOLOR_NULL) {
		f32 val = mConfig->mPelletColor();
		mAnimatedMaterials.animate(&val);
	} else if (isUfoParts()) {
		mAnimatedMaterials.animate(nullptr);
	}

	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	if (mCollInfo) {
		mCollInfo->updateInfo(gfx, false);
	}

	if (aiCullable()) {
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mAnimatedMaterials);
	}
}

/**
 * @todo: Documentation
 */
void Pellet::doCreateColls(Graphics& gfx)
{
	STACK_PAD_VAR(2); // this is ACTUALLY from unused temps according to the DLL

	mMass              = 0.0f;
	f32 rad            = getBottomRadius();
	f32 firstPtclSize  = 0.75f;
	f32 secondPtclSize = 0.0f;
	int collNum        = mConfig->_C0();

	if (mPelletView) {
		rad *= mPelletView->viewGetScale().x;
	}

	for (int i = 0; i < collNum; i++) {
		f32 angle = (TAU / collNum) * i;
		Vector3f ptclPos(rad * cosf(angle), 0.0f, rad * sinf(angle));
		addParticle(firstPtclSize, ptclPos);

		ptclPos.set(rad * cosf(angle), 0.0f, rad * sinf(angle));

		ptclPos.y += mPelletView ? getCylinderHeight() : getCylinderHeight() * mConfig->mPelletScale();
		addParticle(secondPtclSize, ptclPos);
	}
}

/**
 * @todo: Documentation
 */
bool InteractSwallow::actPellet(Pellet* pellet) immut
{
	if (pellet->getState() == PELSTATE_Swallowed) {
		return false;
	}
	pellet->mStuckMouthPart = mMouthPart;
	pellet->startStickMouth(mOwner, mMouthPart);
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractKill::actPellet(Pellet* pellet) immut
{
	if (pellet->mStuckMouthPart) {
		Stickers stuckList(pellet);
		Iterator iter(&stuckList);
		CI_LOOP(iter)
		{
			(*iter)->kill(false);
			iter.dec();
		}
	}
	pellet->kill(false);
	return true;
}

/**
 * @todo: Documentation
 */
bool PelletMgr::decomposeNumberPellet(u32 id, int& color, int& type)
{
	// Blantant undefined behavior, as `numberPellets` contains less than 20 elements.
	for (int i = 0; i < TERNARY_BUGFIX(ARRAY_SIZE(numberPellets), 20); i++) {
		if (id == numberPellets[i].mPelletID) {
			color = numberPellets[i].mPelletColor;
			type  = numberPellets[i].mPelletType;
			return true;
		}
	}
	return false;
}

/**
 * @todo: Documentation
 */
void PelletMgr::registerUfoParts()
{
	PRINT("BEGIN\n");
	FOREACH_NODE(CoreNode, mConfigList.mChild, node)
	{
		PelletConfig* config = static_cast<PelletConfig*>(node);
		if (config->mPelletType() == PELTYPE_UfoPart) {
			playerState->registerUfoParts(config->mRepairAnimJointIndex, config->mModelId.mId, config->mPelletId.mId);
		}
	}
}

/**
 * @todo: Documentation
 */
Pellet* PelletMgr::newNumberPellet(int color, int type)
{
	NumberPel* num = numberPellets;
	u32 id         = 0;
	for (num; num->mPelletColor != PELCOLOR_NULL; num++) {
		if (color == num->mPelletColor && type == num->mPelletType) {
			id = num->mPelletID;
			break;
		}
	}

	if (id) {
		return newPellet(id, nullptr);
	}

	PRINT("color(%d) size(%d) is not valid!\n", color, type);
	return nullptr;
}

/**
 * @todo: Documentation
 */
Pellet* PelletMgr::newPellet(u32 pelletID, PelletView* view)
{
	PelletConfig* config = getConfig(pelletID);
	if (!config) {
		return nullptr;
	}

	if (config->mModelId.match('tk**') && !view) {
		PRINT("** newPellet( %s, 0 ) ! teki : use becomepellet!\n", config->mModelId.mStringID);
		PRINT_GLOBAL("** newPellet( %s, 0 ) ! teki : use becomepellet!\n", config->mModelId.mStringID);
		ERROR("nakata!");
	}

	if (view) {
		if (config) {
			Pellet* pellet = static_cast<Pellet*>(birth());
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
			pellet->initPellet(view, config);
#else
			if (pellet) {
				pellet->initPellet(view, config);
			}
#endif
			return pellet;
		}
	} else {
		PelletShapeObject* obj = getShapeObject(pelletID);
		PRINT("pellet birth *******\n");
		ID32 pelID(pelletID);
		pelID.print();

		if (config && obj) {
			Pellet* pellet = static_cast<Pellet*>(birth());
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
			pellet->initPellet(obj, config);
#else
			if (pellet) {
				pellet->initPellet(obj, config);
			}
#endif
			PRINT("init pellet done ***\n");
			return pellet;
		}
	}

	return nullptr;
}

/**
 * @todo: Documentation
 */
PelletShapeObject* PelletMgr::getShapeObject(u32 pelletID)
{
	PelletConfig* config = getConfig(pelletID);
	if (!config) {
		return nullptr;
	}

	FOREACH_NODE(CoreNode, mAnimInfoList.mChild, node)
	{
		PelletAnimInfo* info = static_cast<PelletAnimInfo*>(node);
		if (info->mID.mId == config->mPelletId.mId) {
			return info->mPelletShapeObject;
		}
	}

	PRINT("no PelletShapeObject for %s\n", ID32(pelletID).mStringID);
	return nullptr;
}

/**
 * @todo: Documentation
 */
Creature* PelletMgr::createObject()
{
	Pellet* pellet = new Pellet();
	pellet->mProps = mPelletProps;
	return pellet;
}

/**
 * @todo: Documentation
 */
PelletMgr::PelletMgr(MapMgr* mgr)
{
	mUfoMotionTable = PaniPelletAnimator::createMotionTable();
	mAnimInfoList.initCore("");
	mAnimInfoNum = 0;
	mPelletProps = new PelletProp();
	mConfigNum   = 0;
	mReadStage   = 0;
	load("parms/", "pelMgr.bin", 1);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	create(64);
#else
	create(96);
#endif
	mMovieFlags = PELMOVIE_Unk1 | PELMOVIE_Unk2 | PELMOVIE_Unk3;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
bool PelletMgr::useShape(u32 pelletID)
{
	FOREACH_NODE(UseNode, mUseList.mChild, node)
	{
		if (node->mPelletID == pelletID) {
			return true;
		}
	}
	return false;
}

/**
 * @todo: Documentation
 */
void PelletMgr::addUseList(u32 pelletID)
{
	if (!useShape(pelletID)) {
		UseNode* newNode   = new UseNode();
		newNode->mPelletID = pelletID;
		mUseList.add(newNode);
	}
}

/**
 * @todo: Documentation
 */
void PelletMgr::initShapeInfos()
{
	mReadStage = 1;
	load("objects/", "pelAnim.bin", 1);
	createShapeObjects();
}

/**
 * @todo: Documentation
 */
int PelletMgr::getConfigIndex(u32 pelletID)
{
	int idx = 0;
	FOREACH_NODE(CoreNode, mConfigList.mChild, node)
	{
		PelletConfig* config = static_cast<PelletConfig*>(node);
		if (config->mModelId.mId == pelletID) {
			return idx;
		}
		idx++;
	}
	return -1;
}

/**
 * @todo: Documentation
 */
PelletConfig* PelletMgr::getConfigFromIdx(int idx)
{
	if (idx < 0 || idx >= mConfigNum) {
		return nullptr;
	}

	CoreNode* config = mConfigList.mChild;
	for (int i = 0; i < idx; i++) {
		config = config->mNext;
	}
	return static_cast<PelletConfig*>(config);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
ID32 PelletMgr::getConfigIdAt(int idx)
{
	// UNUSED FUNCTION (matching by size)
	PelletConfig* config = getConfigFromIdx(idx);
	if (config) {
		return config->mModelId;
	}
	ERROR("config index error");
	return config->mModelId; // Crash inbound if you have ERRORs disabled.
}

/**
 * @todo: Documentation
 */
PelletConfig* PelletMgr::getConfig(u32 pelletID)
{
	FOREACH_NODE(CoreNode, mConfigList.mChild, node)
	{
		PelletConfig* config = static_cast<PelletConfig*>(node);
		if (config->mModelId.mId == pelletID) {
			return config;
		}
	}

	return nullptr;
}

/**
 * @todo: Documentation
 */
void PelletMgr::read(RandomAccessStream& input)
{
	switch (mReadStage) {
	case 0:
	{
		readConfigs(input);
		break;
	}
	case 1:
	{
		readAnimInfos(input);
		break;
	}
	}
}

/**
 * @todo: Documentation
 */
void PelletMgr::readConfigs(RandomAccessStream& input)
{
	mConfigNum = input.readInt();

	for (int i = 0; i < mConfigNum; i++) {
		PelletConfig* config = new PelletConfig();
		config->read(input);
		mConfigList.add(config);
	}
}

/**
 * @todo: Documentation
 */
void PelletMgr::readAnimInfos(RandomAccessStream& input)
{
	mAnimInfoNum = input.readInt();

	for (int i = 0; i < mAnimInfoNum; i++) {
		PelletAnimInfo* info = new PelletAnimInfo();
		info->read(input);
		mAnimInfoList.add(info);
	}
}

/**
 * @todo: Documentation
 */
void PelletMgr::initTekiNakaParts()
{
	FOREACH_NODE(CoreNode, mAnimInfoList.mChild, node)
	{
		PelletAnimInfo* info = static_cast<PelletAnimInfo*>(node);
		if (useShape(info->mID.mId) && !info->mPelletShapeObject && info->mID.match('un**')) {
			PRINT("*** NAKA PARTS (%s)\n", info->mID.mStringID);
			if (info->createShapeObject()) {
#if defined(VERSION_GPIJ01_01)
#else
				PRINT("NAKA (%s) create done !\n", info->mID.mStringID);
#endif
			} else {
				ERROR("failed to create NAKA SHAPEOBJECT\n");
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void PelletMgr::createShapeObjects()
{
	FOREACH_NODE(CoreNode, mAnimInfoList.mChild, node)
	{
		PelletAnimInfo* info = static_cast<PelletAnimInfo*>(node);
		bool doCreate        = false;
		switch (info->mCreationType) {
		case PCT_Resident:
		{
			doCreate = true;
			break;
		}
		case PCT_LoadIfExists:
		{
			doCreate = useShape(info->mID.mId);
			break;
		}
		case PCT_LoadOnTeki:
		{
			doCreate = tekiMgr->mUsingType[info->mTekiType];
			break;
		}
		case PCT_LoadOnBoss:
		{
			PRINT("NOT YET\n");
			break;
		}
		}

		if (doCreate) {
			if (!info->createShapeObject()) {
				PRINT("FAILED TO CREATE SHAPEOBJECT for %s\n", info->mID.mStringID);
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void PelletMgr::refresh(Graphics& gfx)
{
	MonoObjectMgr::refresh(gfx);
	Iterator iter(this);
	CI_LOOP(iter)
	{
		Pellet* pellet = static_cast<Pellet*>(*iter);
		if (AIPerf::kandoOnly) {
			gfx.setColour(Colour(0, 255, 0, 255), true);
			char buf[16];
			if (pellet->isFrontFace()) {
				sprintf(buf, "front");
			} else {
				sprintf(buf, "back");
			}

			Vector3f pos(pellet->mSRT.t);
			pos.y += pellet->getCylinderHeight();
			pos.multMatrix(gfx.mCamera->mLookAtMtx);
			int val = -(gsys->mConsFont->stringWidth(buf) / 2);
			gfx.perspPrintf(gsys->mConsFont, pos, val, 0, buf);
		}
	}
}

/**
 * @todo: Documentation
 */
void PelletMgr::refresh2d(Graphics&)
{
}

PelletMgr* pelletMgr;

// The functions following this point are exclusively found in the windows .dll build
// None of this is confirmed to be equivalent for obvious reasons
#ifdef WIN32

void PelletConfig::genAge(AgeServer& server)
{
	server.StartGroup("config");
	server.NewButton("delete", new Delegate1<PelletConfig, AgeServer&>(this, removeSelf), 221);
	mModelId.genAge(server, "id");
	mPelletId.genAge(server, "shapeID");
	mUnusedId.genAge(server, "split");
	server.EndGroup();

	Shape* ufo = itemMgr->getUfoShape();
	if (ufo) {
		server.StartGroup("joint");
		server.StartOptionBox("ジョイント", &mRepairAnimJointIndex, 252);
		server.NewOption("なし", -1);
		for (int i = 0; i < ufo->mJointCount; i++) {
			server.NewOption(ufo->mJointList[i].mName, i);
		}
		server.EndOptionBox();
		server.EndGroup();
	}

	genAgeParms(server, 10);
}

void PelletConfig::write(RandomAccessStream& output)
{
	Parameters::write(output);
	mModelId.write(output);
	mPelletId.write(output);
	mUnusedId.write(output);
	output.writeInt(mRepairAnimJointIndex);
}

void PelletConfig::removeSelf(AgeServer& server)
{
	pelletMgr->removeConfig(server, this);
}

void PelletMgr::genAge(AgeServer& server)
{
	server.StartSection("ペレット", true);
	server.StartGroup("operation");
	server.NewButton("new animinfo", new Delegate1<PelletMgr, AgeServer&>(this, addAnimInfo), 221);
	server.NewButton("new config", new Delegate1<PelletMgr, AgeServer&>(this, addConfig), 221);
	server.EndGroup();

	server.StartSection("シェイプ管理", true); // shape management
	server.StartGroup("file");
	server.NewButton("new animinfo", new Delegate1<PelletMgr, AgeServer&>(this, addAnimInfo), 221);
	server.NewButton("Load", new Delegate1<PelletMgr, AgeServer&>(this, animInfoRead), 221);
	server.NewButton("Save", new Delegate1<PelletMgr, AgeServer&>(this, animInfoWrite), 221);
	FOREACH_NODE(PelletAnimInfo, mAnimInfoList.mChild, info)
	{
		server.StartSection(info->mID.mStringID, true);
		server.setSectionRefresh(new Delegate1<PelletAnimInfo, AgeServer&>(info, PelletAnimInfo::genAge));
		server.EndSection();
	}
	server.EndSection();

	server.StartSection("config", true);
	server.StartGroup("file");
	server.NewButton("new config", new Delegate1<PelletMgr, AgeServer&>(this, addConfig), 221);
	server.NewButton("Load", new Delegate1<PelletMgr, AgeServer&>(this, configRead), 221);
	server.NewButton("Save", new Delegate1<PelletMgr, AgeServer&>(this, configWrite), 221);
	FOREACH_NODE(PelletConfig, mConfigList.mChild, config)
	{
		server.StartSection(config->mPelletName().mString, true);
		server.setSectionRefresh(new Delegate1<PelletConfig, AgeServer&>(config, CoreNode::genAge));
		server.EndSection();
	}
	server.EndSection();

	server.StartSection("animMgr", true);
	FOREACH_NODE(PelletAnimInfo, mAnimInfoList.mChild, info)
	{
		if (info->mPelletShapeObject) {
			info->mPelletShapeObject->genAge(server);
		}
	}
	server.EndSection();

	server.EndSection();
}

void PelletMgr::writeAnimInfos(RandomAccessStream& output)
{
	output.writeInt(mAnimInfoNum);
	FOREACH_NODE(PelletAnimInfo, mAnimInfoList.mChild, info)
	{
		info->write(output);
	}
}

void PelletMgr::writeConfigs(RandomAccessStream& output)
{
	output.writeInt(mConfigNum);
	FOREACH_NODE(PelletConfig, mConfigList.mChild, config)
	{
		config->write(output);
	}
}

void PelletMgr::addAnimInfo(AgeServer& server)
{
	mAnimInfoList.add(new AnimInfo);
	mAnimInfoNum++;
	server.RefreshNode();
}

void PelletMgr::addConfig(AgeServer& server)
{
	mConfigList.add(new PelletConfig);
	mConfigNum++;
	server.RefreshNode();
}

void PelletMgr::animInfoRead(AgeServer& server)
{
	mReadStage = 1;
	genRead(server);
}

void PelletMgr::animInfoWrite(AgeServer& server)
{
	mReadStage = 1;
	genWrite(server);
}

void PelletMgr::configRead(AgeServer& server)
{
	mReadStage = 0;
	genRead(server);
}

void PelletMgr::configWrite(AgeServer& server)
{
	mReadStage = 0;
	genWrite(server);
}

void PelletMgr::removeAnimInfo(AgeServer& server, PelletAnimInfo* info)
{
	info->del();
	mAnimInfoNum--;
	server.RefreshNode();
}

void PelletMgr::removeConfig(AgeServer& server, PelletConfig* config)
{
	config->del();
	mConfigNum--;
	server.RefreshNode();
}

#endif
