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
#include "VersionGroups.h"
#include "teki.h"
#include "zen/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(33)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
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

/*
 * --INFO--
 * Address:	80094B14
 * Size:	000044
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

/*
 * --INFO--
 * Address:	80094B58
 * Size:	000018
 */
u32 PelletMgr::getUfoIDFromIndex(int idx)
{
	if (idx >= MAX_UFO_PARTS) {
		ERROR("N MECK!\n");
	}
	return _ufoIDTable[idx];
}

/*
 * --INFO--
 * Address:	80094B70
 * Size:	000390
 */
PelletConfig::PelletConfig()
    : mPelletName(this, String("new", 0), String("", 0), String("", 0), "x99", nullptr)
    , mPelletType(this, PELTYPE_Blue, 0, 0, "p00", nullptr)
    , mPelletColor(this, PELCOLOR_NULL, 0, 0, "p09", nullptr)
    , mCarryMinPikis(this, 1, 0, 0, "p01", nullptr)
    , mCarryMaxPikis(this, 1, 0, 0, "p02", nullptr)
    , mUseDynamicMotion(this, 0, 0, 0, "p03", nullptr)
    , _A0(this, 10.0f, 0.0f, 0.0f, "p04", nullptr)
    , _B0(this, 4.0f, 0.0f, 0.0f, "p05", nullptr)
    , _C0(this, 4, 0, 0, "p08", nullptr)
    , mMatchingOnyonSeeds(this, 1, 0, 0, "p06", nullptr)
    , mNonMatchingOnyonSeeds(this, 1, 0, 0, "p07", nullptr)
    , mPelletScale(this, 1.0f, 0.0f, 0.0f, "p10", nullptr)
    , mCarryInfoHeight(this, 30.0f, 0.0f, 0.0f, "p11", nullptr)
    , mAnimSoundID(this, 6, 0, 0, "p12", nullptr)
    , mBounceSoundID(this, 0xFFFFFFFF, 0, 0, "p13", nullptr)
{
	mModelId.setID('none');
	mUnusedId.setID('none');
	mPelletId.setID('none');
	initCore("pelletConfig");
	mRepairAnimJointIndex = -1;
}

/*
 * --INFO--
 * Address:	80094F00
 * Size:	000074
 */
void PelletConfig::read(RandomAccessStream& input)
{
	Parameters::read(input);
	mModelId.read(input);
	mPelletId.read(input);
	mUnusedId.read(input);
	mRepairAnimJointIndex = input.readInt();
}

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

/*
 * --INFO--
 * Address:	80094F74
 * Size:	0001C8
 */
void PelletView::becomePellet(u32 id, Vector3f& pos, f32 direction)
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
	pellet->mRotation.set(0.0f, direction, 0.0f);
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

/*
 * --INFO--
 * Address:	8009513C
 * Size:	000270
 */
Pellet::Pellet()
{
	mUseSpawnPosition = true;
	mSpawnPosition.set(0.0f, 0.0f, 0.0f);
	mSeContext = new SeContext();
	mSeContext->setContext(this, 2);
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

/*
 * --INFO--
 * Address:	800953AC
 * Size:	00003C
 */
bool Pellet::isUfoPartsID(u32 partsID)
{
	ID32 id(partsID);
	return id.match('u***');
}

/*
 * --INFO--
 * Address:	800953E8
 * Size:	000090
 */
void Pellet::startWaterEffect()
{
	EffectParm unused(&mPosition); // lol.
	EffectParm parm(mPosition);
	unused.mScale = 2.0f; // this is so dumb
	UtEffectMgr::cast(KandoEffect::Bubbles, parm);
}

/*
 * --INFO--
 * Address:	80095478
 * Size:	000030
 */
void Pellet::finishWaterEffect()
{
	mRippleEffect->kill();
}

/*
 * --INFO--
 * Address:	800954A8
 * Size:	000090
 */
void Pellet::doKill()
{
	setTrySound(false);
	mIsAlive = 0;
	if (mPelletView) {
		static_cast<PelletView*>(mPelletView)->viewKill();
		mPelletView = nullptr;
	}
	mSeContext->releaseEvent();
	DualCreature::doKill();
	pelletMgr->kill(this);
	mLifeGauge.countOff();
}

/*
 * --INFO--
 * Address:	80095538
 * Size:	00001C
 */
int Pellet::getState()
{
	if (mCurrentState) {
		return mCurrentState->getID();
	}
	return PELSTATE_Normal;
}

/*
 * --INFO--
 * Address:	80095554
 * Size:	000038
 */
bool Pellet::ignoreAtari(Creature* creature)
{
	if (creature->getStickObject() == this) {
		return true;
	}

	if (mPelletView && creature == mPelletView) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8009558C
 * Size:	000008
 */
bool Pellet::isAlive()
{
	return mIsAlive;
}

/*
 * --INFO--
 * Address:	80095594
 * Size:	000048
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

/*
 * --INFO--
 * Address:	800955DC
 * Size:	000050
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

/*
 * --INFO--
 * Address:	8009562C
 * Size:	000080
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

/*
 * --INFO--
 * Address:	800956AC
 * Size:	0003A0
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
		if (isMotionFlag(2)) {
			mAnimator.startMotion(PaniMotionInfo(0), PaniMotionInfo(3, this));
		} else {
			mAnimator.startMotion(PaniMotionInfo(0));
		}
	}

	f32 offset = 8.0f;
	if (mPelletView) {
		offset = 4.0f;
	} else {
		offset = offset / mScale.y;
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

	f32 minY = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	if (minY > mPosition.y) {
		PRINT("************* START PICK YABAI !!!\n");
	}
	if (!isRealDynamics()) {
		mPosition.y += offset;
	}
}

/*
 * --INFO--
 * Address:	80095A4C
 * Size:	000080
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

/*
 * --INFO--
 * Address:	80095ACC
 * Size:	0000B8
 */
void Pellet::startGoal()
{
	finishPick();
	mStateMachine->transit(this, PELSTATE_Goal);
	mPikiCarrier = nullptr;
	mCarryDirection.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80095C3C
 * Size:	00016C
 */
void Pellet::doCarry(Creature* carryingPiki, Vector3f& direction, u16 carrierCount)
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

/*
 * --INFO--
 * Address:	80095DA8
 * Size:	000108
 */
f32 Pellet::getBottomRadius()
{
	if (mPelletView) {
		return static_cast<PelletView*>(mPelletView)->viewGetBottomRadius();
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
		PRINT("if view is creature, the name is %s\n", ObjType::getName(static_cast<Creature*>(mPelletView)->mObjType));
		ERROR("BottomRadius Loop\n");
	}

	return getCentreSize();
}

/*
 * --INFO--
 * Address:	80095EB0
 * Size:	00001C
 */
Vector3f Pellet::getCentre()
{
	return mPosition;
}

/*
 * --INFO--
 * Address:	80095ECC
 * Size:	000048
 */
f32 Pellet::getCylinderHeight()
{
	if (mPelletView) {
		return static_cast<PelletView*>(mPelletView)->viewGetHeight();
	}
	return mConfig->mCarryInfoHeight();
}

/*
 * --INFO--
 * Address:	80095F14
 * Size:	000078
 */
f32 Pellet::getSize()
{
	if (mPelletView) {
		Vector3f viewScale(static_cast<PelletView*>(mPelletView)->viewGetScale());
		return viewScale.x * static_cast<PelletView*>(mPelletView)->viewGetBottomRadius();
	}
	return getBottomRadius();
}

/*
 * --INFO--
 * Address:	80095FA8
 * Size:	000008
 */
f32 Pellet::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	80095FB0
 * Size:	0000E4
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

/*
 * --INFO--
 * Address:	80096094
 * Size:	000094
 */
void Pellet::endStickTeki(Creature* teki)
{
	finishPick();
	teki->endStickObject();
}

/*
 * --INFO--
 * Address:	80096128
 * Size:	000174
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

/*
 * --INFO--
 * Address:	8009629C
 * Size:	000068
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

/*
 * --INFO--
 * Address:	80096304
 * Size:	00005C
 */
void Pellet::stickOffSlot(int slotID)
{
	if (slotID != -1 && isSlotFlag(slotID)) {
		// valid, filled slot - reset it.
		resetSlotFlag(slotID);
	}
}

/*
 * --INFO--
 * Address:	80096360
 * Size:	00006C
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

/*
 * --INFO--
 * Address:	800963CC
 * Size:	000160
 */
int Pellet::getNearestFreeSlotIndex(Vector3f& pos)
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

/*
 * --INFO--
 * Address:	8009652C
 * Size:	0000D8
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

/*
 * --INFO--
 * Address:	80096604
 * Size:	0001A0
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
		grabRadius /= mScale.x;
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

/*
 * --INFO--
 * Address:	800967A4
 * Size:	000078
 */
Vector3f Pellet::getSlotGlobalPos(int slotID, f32 offset)
{
	Vector3f globalPos = getSlotLocalPos(slotID, offset);
	globalPos.multMatrix(mWorldMtx);
	return globalPos;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Pellet::initSlotFlags()
{
	mSlotFlags[0] = mSlotFlags[1] = mSlotFlags[2] = 0;
}

/*
 * --INFO--
 * Address:	8009681C
 * Size:	000034
 */
void Pellet::setSlotFlag(int slotID)
{
	if (slotID != -2) {
		// 32 flags per slot, so get correct slot (>> 5 == divide by 32 + drop remainder)
		mSlotFlags[slotID >> 5] |= (1 << (slotID - 32 * (slotID >> 5)));
	}
}

/*
 * --INFO--
 * Address:	80096850
 * Size:	000034
 */
void Pellet::resetSlotFlag(int slotID)
{
	if (slotID != -2) {
		// 32 flags per slot, so get correct slot (>> 5 == divide by 32 + drop remainder)
		mSlotFlags[slotID >> 5] &= ~(1 << (slotID - 32 * (slotID >> 5)));
	}
}

/*
 * --INFO--
 * Address:	80096884
 * Size:	000044
 */
bool Pellet::isSlotFlag(int slotID)
{
	if (slotID == -2) {
		return false;
	}

	return (mSlotFlags[slotID >> 5] & (1 << (slotID - 32 * (slotID >> 5)))) != 0;
}

/*
 * --INFO--
 * Address:	800968C8
 * Size:	0000E0
 */
void Pellet::initPellet(PelletShapeObject* shapeObj, PelletConfig* config)
{
	mCarrierCounter = 0;
	mMotionFlag     = 1;
	mShapeObject    = shapeObj;
	if (shapeObj->isMotionFlag(2)) {
		setMotionFlag(2);
		if (!isMotionFlag(2)) {
			ERROR("WHYYYYYYYYYYY\n"); // same kando
		}
	}

	mConfig   = config;
	mCollInfo = mPelletCollInfo;
	mCollInfo->initInfo(mShapeObject->mShape, nullptr, nullptr);
	f32 scale = config->mPelletScale();
	mScale.set(scale, scale, scale);
	if (config->mPelletColor() != PELCOLOR_NULL || isUfoParts()) {
		mShapeObject->mShape->makeInstance(mShapeDynMaterials, 0);
	}
	PRINT("*** MATERIAL : %d\n", mShapeDynMaterials.mParent);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Pellet::initPellet(PelletView* view, PelletConfig* config)
{
	mCarrierCounter = 0;
	mMotionFlag     = 1;
	mPelletView     = view;
	mConfig         = config;
	mScale.set(view->viewGetScale());
	mShapeObject = nullptr;
	mCollInfo    = nullptr;
}

/*
 * --INFO--
 * Address:	800969A8
 * Size:	000044
 */
void Pellet::startCarryMotion(f32 speed)
{
	mMotionSpeed = speed;
	if (mPelletView) {
		static_cast<PelletView*>(mPelletView)->viewStartTrembleMotion(mMotionSpeed);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Pellet::stopMotion()
{
	if (mPelletView) {
		static_cast<PelletView*>(mPelletView)->viewSetMotionSpeed(0.0f);
	} else {
		mMotionSpeed = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	800969F4
 * Size:	000064
 */
void Pellet::finishMotion()
{
	if (mPelletView) {
		static_cast<PelletView*>(mPelletView)->viewFinishMotion();
	} else {
		mAnimator.finishMotion(&PaniMotionInfo(-1), nullptr);
	}
}

/*
 * --INFO--
 * Address:	80096A5C
 * Size:	000098
 */
void Pellet::init(Vector3f& pos)
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

/*
 * --INFO--
 * Address:	80096AF4
 * Size:	000034
 */
bool Pellet::isFree()
{
	// mSlotFlags needs to be int for resetSlotFlags, this seems to be the easier fix
	if ((u32)(mSlotFlags[0]) == 0 && (u32)(mSlotFlags[1]) == 0 && (u32)(mSlotFlags[2]) == 0) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80096B28
 * Size:	000248
 */
void Pellet::doLoad(RandomAccessStream& input)
{
	mUseSpawnPosition     = input.readByte();
	mSpawnPosition.x      = input.readFloat();
	mSpawnPosition.y      = input.readFloat();
	mSpawnPosition.z      = input.readFloat();
	Vector3f displacement = mSpawnPosition - mPosition;
	if (displacement.length() < 40.0f) {
		PRINT("UFO PARTS DIDN'T MOVE!\n");
		mPosition = mSpawnPosition;
	}
#if defined(VERSION_GPIE01_00) || defined(VERSION_PIKIDEMO)
	// This isn't in the USA versions' DLL, meaning that DLL is based on rev 0 instead of rev 1 (it was not recompiled between revisions).
#else
	else if (isNan(mPosition.x) || isNan(mPosition.y) || isNan(mPosition.z)) {
		mPosition = mSpawnPosition;
	}
#endif
	else {
		PRINT("PARTS MOVED !!! (%.1f %.1f %.1f)\n", displacement.x, displacement.y, displacement.z);
		mPosition = routeMgr->getSafePosition('test', mPosition);
	}

	mPosition.y = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	PRINT_GLOBAL("ufo parts %s : (%.1f %.1f %.1f)", mConfig->mModelId.mStringID, mPosition.x, mPosition.y, mPosition.z);
	disableFixPos();
	enableFixPos();
	mStateMachine->transit(this, PELSTATE_UfoLoad);
}

/*
 * --INFO--
 * Address:	80096D70
 * Size:	000078
 */
void Pellet::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (isMotionFlag(2) && event.mEventType == KEY_LoopEnd && isUfoParts() && mConfig->mAnimSoundID() >= 0) {
		playEventSound(this, mConfig->mAnimSoundID() + SE_UFOPARTS_SOUNDTYPE);
	}
}

/*
 * --INFO--
 * Address:	80096DE8
 * Size:	000094
 */
void Pellet::doSave(RandomAccessStream& output)
{
	output.writeByte(mUseSpawnPosition);
	output.writeFloat(mSpawnPosition.x);
	output.writeFloat(mSpawnPosition.y);
	output.writeFloat(mSpawnPosition.z);
}

/*
 * --INFO--
 * Address:	80096E7C
 * Size:	0003B8
 */
void Pellet::startAI(int doSpawnScaleOff)
{
	mRotationQuat.fromEuler(Vector3f(0.0f, mFaceDirection, 0.0f));
	mRotation.set(0.0f, mFaceDirection, 0.0f);
	mLastPosition = mPosition;
	enableFixPos();
	if (mUseSpawnPosition) {
		mSpawnPosition = mPosition;
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

	bool check = false;
	if (mMotionFlag == 3) {
		check = true;
	}

	if (!mPelletView) {
		if (isMotionFlag(2)) {
			mAnimator.startMotion(PaniMotionInfo(0), PaniMotionInfo(3, this));
			check = false;
		} else {
			mAnimator.startMotion(PaniMotionInfo(0));
		}
	} else {
		startCarryMotion(0.0f);
	}

	if (check) {
		// The string says `isMotionFlag`, but the code says `isCreatureFlag`. I think `isMotionFlag` was intended.
		PRINT("view=%x isMotionFlag() = %s\n", mPelletView, isCreatureFlag(2) ? "true" : "false");
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
		Vector3f pos(mPosition);
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

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Pellet::startAppear()
{
	mTargetGoal  = nullptr;
	mPikiCarrier = nullptr;
	if (!mPelletView) {
		mAnimator.startMotion(PaniMotionInfo(0));
		mMotionSpeed = 30.0f;
	}
	mStateMachine->transit(this, PELSTATE_Appear);
}

/*
 * --INFO--
 * Address:	80097234
 * Size:	000060
 */
void Pellet::doAnimation()
{
	if (mShapeObject) {
		mAnimator.updateAnimation(mMotionSpeed, 30.0f);
	}

	if (mPelletView) {
		static_cast<PelletView*>(mPelletView)->viewDoAnimation();
	}
}

/*
 * --INFO--
 * Address:	80097298
 * Size:	000088
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

/*
 * --INFO--
 * Address:	80097320
 * Size:	000088
 */
void Pellet::postUpdate(int _, f32 __)
{
	int state = getState();
	if (state == PELSTATE_Swallowed && !pelletMgr->isMovieFlag(1)) {
		return;
	}

	if (state == PELSTATE_Normal && mPickOffset != 0.0f && !pelletMgr->isMovieFlag(2)) {
		return;
	}

	if (pelletMgr->isMovieFlag(4)) {
		DualCreature::postUpdate(_, __);
	}
}

/*
 * --INFO--
 * Address:	800973A8
 * Size:	00094C
 */
void Pellet::update()
{
#if defined(VERSION_PIKIDEMO)
#define ASSERT_POSITION_NOTNAN(...)  \
	/* Yeah, just the X position. */ \
	if (isNan(mPosition.x)) {        \
		ERROR(__VA_ARGS__);          \
	}
#else
#define ASSERT_POSITION_NOTNAN(...)
#endif

	mLastPosition   = mPosition;
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
		mCurrentPelletPosition = mPosition;
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
	mLifeGauge.mPosition = mPosition;
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

		if (mapMgr->getMinY(mPosition.x, mPosition.z, true) > mPosition.y) {
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
			Vector3f tekiDir = mPosition - attachedTeki->mPosition;
			targetAngle      = atan2f(tekiDir.x, tekiDir.z);
		} else {
			Vector3f targetDir = mPikiCarrier->mPosition - mPosition;
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

/*
 * --INFO--
 * Address:	80097D34
 * Size:	000050
 */
void Pellet::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	80097D84
 * Size:	000020
 */
void Pellet::collisionCallback(CollEvent& event)
{
	if (isCreatureFlag(CF_AllowFixPosition) && isCreatureFlag(CF_IsPositionFixed)) {
		resetCreatureFlag(CF_IsPositionFixed);
	}
}

/*
 * --INFO--
 * Address:	80097DA4
 * Size:	000074
 */
bool Pellet::stimulate(Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actPellet(this);
	}
	return false;
}

/*
 * --INFO--
 * Address:	80097E18
 * Size:	0002F8
 */
void Pellet::doRender(Graphics& gfx, Matrix4f& mtx)
{
	if (mStuckMouthPart) {
		Matrix4f jointMtx = mStuckMouthPart->getJointMatrix();
		Matrix4f transformMtx;
		f32 scale = 1.0f / reinterpret_cast<Vector3f*>(&jointMtx)->length();
		transformMtx.makeSRT(Vector3f(scale, scale, scale), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		mPosition = mStuckMouthPart->mCentre;
		jointMtx.multiplyTo(transformMtx, mtx);
	}

	if (mPelletView) {
		if (aiCullable()) {
			static_cast<PelletView*>(mPelletView)->viewDraw(gfx, mtx);
		}
		return;
	}

	gfx.useMatrix(Matrix4f::ident, 0);
	mAnimator.updateContext();

	if (mConfig->mPelletColor() != PELCOLOR_NULL) {
		f32 val = mConfig->mPelletColor();
		mShapeDynMaterials.animate(&val);
	} else if (isUfoParts()) {
		mShapeDynMaterials.animate(nullptr);
	}

	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	if (mCollInfo) {
		mCollInfo->updateInfo(gfx, false);
	}

	if (aiCullable()) {
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mShapeDynMaterials);
	}
}

/*
 * --INFO--
 * Address:	80098110
 * Size:	0001BC
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
		rad *= static_cast<PelletView*>(mPelletView)->viewGetScale().x;
	}

	for (int i = 0; i < collNum; i++) {
		f32 angle = (TAU / collNum) * i;
		Vector3f ptclPos(rad * cosf(angle), 0.0f, rad * sinf(angle));
		addParticle(firstPtclSize, ptclPos);

		ptclPos.set(rad * cosf(angle), 0.0f, rad * sinf(angle));

		ptclPos.y += (mPelletView) ? getCylinderHeight() : getCylinderHeight() * mConfig->mPelletScale();
		addParticle(secondPtclSize, ptclPos);
	}
}

/*
 * --INFO--
 * Address:	800982CC
 * Size:	000064
 */
bool InteractSwallow::actPellet(Pellet* pellet)
{
	if (pellet->getState() == PELSTATE_Swallowed) {
		return false;
	}
	pellet->mStuckMouthPart = mMouthPart;
	pellet->startStickMouth(mOwner, mMouthPart);
	return true;
}

/*
 * --INFO--
 * Address:	80098330
 * Size:	000148
 */
bool InteractKill::actPellet(Pellet* pellet)
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

/*
 * --INFO--
 * Address:	80098478
 * Size:	000058
 */
bool PelletMgr::decomposeNumberPellet(u32 id, int& color, int& type)
{
	// Blantant undefined behavior, as `numberPellets` contains less than 20 elements.
#if defined(BUGFIX)
	for (int i = 0; i < ARRAY_SIZE(numberPellets); i++)
#else
	for (int i = 0; i < 20; i++)
#endif
	{
		if (id == numberPellets[i].mPelletID) {
			color = numberPellets[i].mPelletColor;
			type  = numberPellets[i].mPelletType;
			return true;
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	800984D0
 * Size:	000068
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

/*
 * --INFO--
 * Address:	80098538
 * Size:	000078
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

/*
 * --INFO--
 * Address:	800985B0
 * Size:	000154
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
#if defined(VERSION_PIKIDEMO)
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
#if defined(VERSION_PIKIDEMO)
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

/*
 * --INFO--
 * Address:	80098704
 * Size:	000094
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

/*
 * --INFO--
 * Address:	80098798
 * Size:	000054
 */
Creature* PelletMgr::createObject()
{
	Pellet* pellet = new Pellet();
	pellet->mProps = mPelletProps;
	return pellet;
}

/*
 * --INFO--
 * Address:	800987EC
 * Size:	000254
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
#if defined(VERSION_PIKIDEMO)
	create(64);
#else
	create(96);
#endif
	mMovieFlags = PELMOVIE_Unk1 | PELMOVIE_Unk2 | PELMOVIE_Unk3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
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

/*
 * --INFO--
 * Address:	80098B04
 * Size:	0000F0
 */
void PelletMgr::addUseList(u32 pelletID)
{
	if (!useShape(pelletID)) {
		UseNode* newNode   = new UseNode();
		newNode->mPelletID = pelletID;
		mUseList.add(newNode);
	}
}

/*
 * --INFO--
 * Address:	80098BF4
 * Size:	000054
 */
void PelletMgr::initShapeInfos()
{
	mReadStage = 1;
	load("objects/", "pelAnim.bin", 1);
	createShapeObjects();
}

/*
 * --INFO--
 * Address:	80098C48
 * Size:	000040
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

/*
 * --INFO--
 * Address:	80098C88
 * Size:	00009C
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

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
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

/*
 * --INFO--
 * Address:	80098D24
 * Size:	000038
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

/*
 * --INFO--
 * Address:	80098D5C
 * Size:	000044
 */
void PelletMgr::read(RandomAccessStream& input)
{
	switch (mReadStage) {
	case 0:
		readConfigs(input);
		break;
	case 1:
		readAnimInfos(input);
		break;
	}
}

/*
 * --INFO--
 * Address:	80098DA0
 * Size:	0000BC
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

/*
 * --INFO--
 * Address:	80098E5C
 * Size:	0000BC
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

/*
 * --INFO--
 * Address:	80098F18
 * Size:	0000D4
 */
void PelletMgr::initTekiNakaParts()
{
	FOREACH_NODE(CoreNode, mAnimInfoList.mChild, node)
	{
		PelletAnimInfo* info = static_cast<PelletAnimInfo*>(node);
		if (useShape(info->mID.mId) && !info->mPelletShapeObject && info->mID.match('un**')) {
			PRINT("*** NAKA PARTS (%s)\n", info->mID.mStringID);
			if (info->createShapeObject()) {
				PRINT("NAKA (%s) create done !\n", info->mID.mStringID);
			} else {
				ERROR("failed to create NAKA SHAPEOBJECT\n");
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80098FEC
 * Size:	0000DC
 */
void PelletMgr::createShapeObjects()
{
	FOREACH_NODE(CoreNode, mAnimInfoList.mChild, node)
	{
		PelletAnimInfo* info = static_cast<PelletAnimInfo*>(node);
		bool doCreate        = false;
		switch (info->mCreationType) {
		case PCT_Resident:
			doCreate = true;
			break;
		case PCT_LoadIfExists:
			doCreate = useShape(info->mID.mId);
			break;
		case PCT_LoadOnTeki:
			doCreate = tekiMgr->mUsingType[info->mTekiType];
			break;
		case PCT_LoadOnBoss:
			PRINT("NOT YET\n");
			break;
		}

		if (doCreate) {
			if (!info->createShapeObject()) {
				PRINT("FAILED TO CREATE SHAPEOBJECT for %s\n", info->mID.mStringID);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800990C8
 * Size:	000210
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

			Vector3f pos(pellet->mPosition);
			pos.y += pellet->getCylinderHeight();
			pos.multMatrix(gfx.mCamera->mLookAtMtx);
			int val = -(gsys->mConsFont->stringWidth(buf) / 2);
			gfx.perspPrintf(gsys->mConsFont, pos, val, 0, buf);
		}
	}
}

/*
 * --INFO--
 * Address:	800992D8
 * Size:	000004
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
