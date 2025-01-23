#include "Pellet.h"
#include "PelletView.h"
#include "PelletState.h"
#include "StateMachine.h"
#include "Interactions.h"
#include "MapMgr.h"
#include "Stickers.h"
#include "PlayerState.h"
#include "UtEffect.h"
#include "KMath.h"
#include "RadarInfo.h"
#include "SoundMgr.h"
#include "AIPerf.h"
#include "teki.h"
#include "Font.h"
#include "Graphics.h"
#include "EffectMgr.h"
#include "DebugLog.h"
#include "zen/Math.h"

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
DEFINE_PRINT(nullptr);

bool SmartTurnOver;

static u32 _ufoIDTable[] = {
	'ust1', 'ust2', 'ust3', 'ust4', 'ust5', 'uf01', 'uf02', 'uf03', 'uf04', 'uf05', 'uf06', 'uf07', 'uf08', 'uf09', 'uf10', 'uf11',
	'un01', 'un02', 'un03', 'un04', 'un05', 'un06', 'un07', 'un08', 'un09', 'un10', 'un11', 'un12', 'un13', 'un14', 'udef',
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
		if (_ufoIDTable[i] == 'udef') {
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
	if (idx >= 30) {
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
	_38.setID('none');
	mPelletId.setID('none');
	initCore("pelletConfig");
	mUfoPartIndex = -1;
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
	_38.read(input);
	mUfoPartIndex = input.readInt();
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

	if (zen::Abs(pos.y - maxY) < zen::Abs(pos.y - minY)) {
		pos.y = maxY;
	} else {
		pos.y = minY;
	}

	pellet->init(pos);
	pellet->mDirection = direction;
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
	_450 = true;
	_444.set(0.0f, 0.0f, 0.0f);
	mSeContext = new SeContext();
	mSeContext->setContext(this, 2);
	mRippleEffect   = new RippleEffect();
	mPelletView     = nullptr;
	_478            = nullptr;
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
	_47C.set(0.0f, 0.0f, 0.0f);
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
	return id.match('u***', '*');
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
	unused._24 = 2.0f; // this is so dumb
	UtEffectMgr::cast(17, parm);
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
	return 0;
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
	if (state == 2) {
		return false;
	}
	if (state == 3 || state == 1) {
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

	if (state == 1 || state == 2 || state == 4) {
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
	_570 = 0;
	enableFixPos();
	stopEventSound(this, SE_LIFT_MOVE);
	stopEventSound(this, SE_LIFT_TRY);
	enableFriction();
	finishMotion();
	disablePickOffset();
	_490 = 0;
}

/*
 * --INFO--
 * Address:	80095ACC
 * Size:	0000B8
 */
void Pellet::startGoal()
{
	finishPick();
	mStateMachine->transit(this, 1);
	_478 = 0;
	_47C.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80095C3C
 * Size:	00016C
 */
void Pellet::doCarry(Creature* p1, Vector3f& p2, u16 p3)
{
	if (_490 == 1) {
		_48C -= gsys->getFrameTime();
		if (_48C <= 0.0f) {
			_490 = 2;
		}
		_47C = p2 * 0.5f;
		return;
	}

	if (_478 && _478->mObjType != p1->mObjType) {
		if (_490 == 0) {
			_490 = 1;
			_48C = 3.5f;
			return;
		}

		if (_478->getStickObject() == this && _488 > p3) {
			PRINT("%s win\n", ObjType::getName(_478->mObjType));
			return;
		}

		_47C = p2;
		_478 = p1;
		_488 = p3;
		PRINT("%s win\n", ObjType::getName(_478->mObjType));
		_490 = 1;
		_48C = 3.5f;

		return;
	}

	_47C = p2;
	_478 = p1;
	_488 = p3;
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
	Vector3f pelCentre = getCentre();
	pelCentre          = teki->getCentre() - pelCentre;
	f32 angle          = atan2f(pelCentre.x, pelCentre.z);
	_460               = roundAng(angle - mDirection);

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
	if (mConfig->mModelId.match('NAVI', '*')) {
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
	int randIdx     = System::getRand(1.0f) * maxCarryNum;
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
		grabAngle = _460;
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
	globalPos.multMatrix(mTransformMatrix);
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
	_570         = 0;
	mMotionFlag  = 1;
	mShapeObject = shapeObj;
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
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Pellet::initPellet(PelletView* view, PelletConfig* config)
{
	_570        = 0;
	mMotionFlag = 1;
	mPelletView = view;
	mConfig     = config;
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

	_490 = 0;
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
	_450         = input.readByte();
	_444.x       = input.readFloat();
	_444.y       = input.readFloat();
	_444.z       = input.readFloat();
	Vector3f sep = _444 - mPosition;
	if (sep.length() < 40.0f) {
		PRINT("UFO PARTS DIDN'T MOVE!\n");
		mPosition = _444;
	} else if (isNan(mPosition.x) || isNan(mPosition.y) || isNan(mPosition.z)) {
		// this isn't in the DLL, funnily enough
		mPosition = _444;
	} else {
		PRINT("PARTS MOVED !!! (%.1f %.1f %.1f)\n", sep.x, sep.y, sep.z);
		mPosition = routeMgr->getSafePosition('test', mPosition);
	}

	mPosition.y = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	PRINT("ufo parts %s : (%.1f %.1f %.1f)", mConfig->mModelId.mStringID, mPosition.x, mPosition.y, mPosition.z);
	disableFixPos();
	enableFixPos();
	mStateMachine->transit(this, 5);
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
	output.writeByte(_450);
	output.writeFloat(_444.x);
	output.writeFloat(_444.y);
	output.writeFloat(_444.z);
}

/*
 * --INFO--
 * Address:	80096E7C
 * Size:	0003B8
 */
void Pellet::startAI(int stateID)
{
	mRotationQuat.fromEuler(Vector3f(0.0f, mDirection, 0.0f));
	mRotation.set(0.0f, mDirection, 0.0f);
	_464 = mPosition;
	enableFixPos();
	if (_450) {
		_444 = mPosition;
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
	_478            = nullptr;

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
		PRINT("view=%x isMotionFlag() = %s\n", mPelletView, isCreatureFlag(CF_GravityEnabled) ? "true" : "false");
		ERROR("DAME DESU YO !\n"); // 'no you can't!'
	}

	if (mPelletView || stateID == 1) {
		mStateMachine->transit(this, 0);
	} else {
		mStateMachine->transit(this, 2);
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
		_4A4 = heights[type];
		_494 = pos;

		zen::particleGenerator* ptclGen = effectMgr->create(effects[type], pos, nullptr, nullptr);
		if (ptclGen) {
			ptclGen->setEmitPosPtr(&_494);
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
	mTargetGoal = nullptr;
	_478        = nullptr;
	if (!mPelletView) {
		mAnimator.startMotion(PaniMotionInfo(0));
		mMotionSpeed = 30.0f;
	}
	mStateMachine->transit(this, 2);
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
	if (state == 3 && !pelletMgr->isMovieFlag(1)) {
		return;
	}

	if (state == 0 && mPickOffset != 0.0f && !pelletMgr->isMovieFlag(2)) {
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
void Pellet::postUpdate(int p1, f32 p2)
{
	int state = getState();
	if (state == 3 && !pelletMgr->isMovieFlag(1)) {
		return;
	}

	if (state == 0 && mPickOffset != 0.0f && !pelletMgr->isMovieFlag(2)) {
		return;
	}

	if (pelletMgr->isMovieFlag(4)) {
		DualCreature::postUpdate(p1, p2);
	}
}

/*
 * --INFO--
 * Address:	800973A8
 * Size:	00094C
 */
void Pellet::update()
{
	_464            = mPosition;
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

	if (state == 3 && !pelletMgr->isMovieFlag(1)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (state == 0 && mPickOffset != 0.0f && !pelletMgr->isMovieFlag(2)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (!pelletMgr->isMovieFlag(4)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (_4A0) {
		_4A0--;
		_494 = mPosition;
		_494.y += _4A4;
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

	_570                 = carryCount;
	f32 height           = getCylinderHeight();
	mLifeGauge.mPosition = mPosition;
	mLifeGauge.mPosition.y += height + 5.0f;
	mCollisionRadius = height * 0.5f;

	if (mPickOffset != 0.0f) {
		bool isFinishPick = false;
		if (!mStickListHead) {
			isFinishPick = true;
			PRINT("NO-STICKER- FINISH PICK\n");
		} else if (_478 && _478->isPiki()) {
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

			_570 = carryCount2;
			if (carryCount2 < mConfig->mCarryMinPikis()) {
				isFinishPick = true;
				PRINT("SHONINZU- FINISH PICK!\n");
			}
		}

		if (isFinishPick) {
			_478 = nullptr;
			finishPick();
			return;
		}
	}

	if (_478) {
		if (!mStickListHead) {
			_478 = nullptr;
			finishPick();
			return;
		}

		if (onGround()) {
			mVelocity.x = _47C.x;
			mVelocity.z = _47C.z;
			mVelocity.y += _47C.y;
		}

		if (mapMgr->getMinY(mPosition.x, mPosition.z, true) > mPosition.y) {
			PRINT("** YABAI YO!\n");
		}

		bool isTekiAttached    = false;
		Creature* attachedTeki = nullptr;
		if (_478->isPiki()) {
			Stickers stuckList3(this);
			Iterator iter3(&stuckList3);
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

			if (isOnlyPiki && _570 == 0) {
				stopEventSound(this, SE_LIFT_MOVE);
				stopEventSound(this, SE_LIFT_TRY);
			}
		}

		f32 targetAngle;
		if (isTekiAttached) {
			Vector3f tekiDir = mPosition - attachedTeki->mPosition;
			targetAngle      = atan2f(tekiDir.x, tekiDir.z);
		} else {
			Vector3f targetDir = _478->mPosition - mPosition;
			targetAngle        = atan2f(targetDir.x, targetDir.z);
		}

		f32 angle = angDist(atan2f(mVelocity.x, mVelocity.z), targetAngle);
		if (zen::Abs(angle) > PI / 20.0f) {
			f32 val = ((6.0f / getBottomRadius()) * 0.7f);
			rotateY(gsys->getFrameTime() * angle * val);
		}
	} else if (mFloorTri) {
		f32 rate    = 3.0f * gsys->getFrameTime();
		mVelocity.x = mVelocity.x - mVelocity.x * rate;
		mVelocity.z = mVelocity.z - mVelocity.z * rate;
	}

	// removed nan check here
	mStateMachine->exec(this);
	// removed nan check here
	DualCreature::update();
	// removed nan check here

	if (mFloorTri && isDynFlag(1)) {
		mVelocity = mVelocity - mVelocity * 2.0f * gsys->getFrameTime();
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stmw      r26, 0x1D8(r1)
	  mr        r31, r3
	  lwz       r4, 0x94(r3)
	  lwz       r0, 0x98(r31)
	  stw       r4, 0x464(r31)
	  stw       r0, 0x468(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x46C(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  addi      r29, r3, 0
	  beq-      .loc_0xE4
	  lbz       r0, 0x5B9(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xE4
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x12C(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xE4
	  lis       r3, 0x802B
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x40
	  add       r3, r0, r4
	  lwz       r5, 0x0(r3)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  bl        -0xCE78
	  mr        r3, r31
	  bl        -0x544C
	  lfs       f0, -0x73A8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xE4
	  lis       r3, 0x802B
	  lfs       f2, -0x73A4(r2)
	  subi      r0, r3, 0x3064
	  lfs       f1, -0x73E8(r2)
	  stw       r0, 0x1C0(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3168
	  lfs       f0, -0x73A0(r2)
	  stw       r31, 0x1C4(r1)
	  mr        r3, r31
	  stw       r0, 0x1C0(r1)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x1C0
	  stfs      f2, 0x1C8(r1)
	  li        r6, 0
	  stfs      f1, 0x1CC(r1)
	  stfs      f0, 0x1D0(r1)
	  bl        -0x7AC4

	.loc_0xE4:
	  stb       r29, 0x5B9(r31)
	  lwz       r3, 0x474(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  lwz       r4, 0x4(r3)
	  b         .loc_0x100

	.loc_0xFC:
	  li        r4, 0

	.loc_0x100:
	  cmpwi     r4, 0x3
	  bne-      .loc_0x134
	  lwz       r3, 0x301C(r13)
	  lhz       r0, 0x200(r3)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x134
	  lfs       f0, -0x5824(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5820(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x581C(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x934

	.loc_0x134:
	  cmpwi     r4, 0
	  bne-      .loc_0x178
	  lfs       f1, -0x73E8(r2)
	  lfs       f0, 0x2D0(r31)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x178
	  lwz       r3, 0x301C(r13)
	  lhz       r0, 0x200(r3)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x178
	  lfs       f0, -0x5818(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5814(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x5810(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x934

	.loc_0x178:
	  lwz       r3, 0x301C(r13)
	  lhz       r0, 0x200(r3)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x1A4
	  lfs       f0, -0x580C(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5808(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x5804(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x934

	.loc_0x1A4:
	  lhz       r3, 0x4A0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1E0
	  subi      r0, r3, 0x1
	  sth       r0, 0x4A0(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x494(r31)
	  stw       r0, 0x498(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x49C(r31)
	  lfs       f1, 0x498(r31)
	  lfs       f0, 0x4A4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x498(r31)

	.loc_0x1E0:
	  addi      r3, r1, 0x1AC
	  addi      r4, r31, 0
	  bl        -0x690C
	  addi      r29, r1, 0x1AC
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  li        r27, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x280

	.loc_0x210:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x234
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x24C

	.loc_0x234:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x24C:
	  cmplwi    r3, 0
	  beq-      .loc_0x264
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x264
	  addi      r27, r27, 0x1

	.loc_0x264:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x280:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2A8
	  li        r0, 0x1
	  b         .loc_0x2D4

	.loc_0x2A8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2D0
	  li        r0, 0x1
	  b         .loc_0x2D4

	.loc_0x2D0:
	  li        r0, 0

	.loc_0x2D4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x210
	  sth       r27, 0x570(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1E0(r31)
	  stw       r0, 0x1E4(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1E8(r31)
	  lfs       f0, -0x739C(r2)
	  lfs       f2, 0x1E4(r31)
	  fadds     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x1E4(r31)
	  lfs       f0, -0x7398(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x270(r31)
	  lfs       f1, -0x73E8(r2)
	  lfs       f0, 0x2D0(r31)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x51C
	  lwz       r0, 0x180(r31)
	  li        r30, 0
	  cmplwi    r0, 0
	  bne-      .loc_0x354
	  li        r30, 0x1
	  b         .loc_0x480

	.loc_0x354:
	  lwz       r3, 0x478(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x480
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x480
	  addi      r3, r1, 0x18C
	  addi      r4, r31, 0
	  bl        -0x6A98
	  addi      r29, r1, 0x18C
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  li        r27, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x40C

	.loc_0x39C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x3C0
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3D8

	.loc_0x3C0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x3D8:
	  cmplwi    r3, 0
	  beq-      .loc_0x3F0
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3F0
	  addi      r27, r27, 0x1

	.loc_0x3F0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x40C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x434
	  li        r0, 0x1
	  b         .loc_0x460

	.loc_0x434:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x45C
	  li        r0, 0x1
	  b         .loc_0x460

	.loc_0x45C:
	  li        r0, 0

	.loc_0x460:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x39C
	  sth       r27, 0x570(r31)
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x7C(r3)
	  cmpw      r27, r0
	  bge-      .loc_0x480
	  li        r30, 0x1

	.loc_0x480:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x51C
	  li        r0, 0
	  stw       r0, 0x478(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  sth       r0, 0x570(r31)
	  li        r5, 0xB9
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  bl        -0xD268
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xD278
	  lbz       r0, 0x438(r31)
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r31)
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4EC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x508

	.loc_0x4EC:
	  addi      r3, r1, 0xAC
	  li        r4, -0x1
	  bl        0x876BC
	  addi      r4, r3, 0
	  addi      r3, r31, 0x4AC
	  li        r5, 0
	  bl        0x2164

	.loc_0x508:
	  mr        r3, r31
	  bl        -0x4CB8
	  li        r0, 0
	  sth       r0, 0x490(r31)
	  b         .loc_0x934

	.loc_0x51C:
	  lwz       r0, 0x478(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x818
	  lwz       r0, 0x180(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x5C8
	  li        r0, 0
	  stw       r0, 0x478(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  sth       r0, 0x570(r31)
	  li        r5, 0xB9
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  bl        -0xD314
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xD324
	  lbz       r0, 0x438(r31)
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r31)
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x598
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5B4

	.loc_0x598:
	  addi      r3, r1, 0xA4
	  li        r4, -0x1
	  bl        0x87610
	  addi      r4, r3, 0
	  addi      r3, r31, 0x4AC
	  li        r5, 0
	  bl        0x20B8

	.loc_0x5B4:
	  mr        r3, r31
	  bl        -0x4D64
	  li        r0, 0
	  sth       r0, 0x490(r31)
	  b         .loc_0x934

	.loc_0x5C8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x604
	  lfs       f0, 0x47C(r31)
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x484(r31)
	  stfs      f0, 0x78(r31)
	  lfs       f1, 0x74(r31)
	  lfs       f0, 0x480(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x74(r31)

	.loc_0x604:
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x2FAB8
	  lwz       r3, 0x478(r31)
	  li        r30, 0
	  li        r29, 0
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x76C
	  addi      r3, r1, 0x16C
	  addi      r4, r31, 0
	  bl        -0x6D5C
	  addi      r28, r1, 0x16C
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  li        r26, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x6D0

	.loc_0x660:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x684
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x69C

	.loc_0x684:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x69C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x37
	  bne-      .loc_0x6B4
	  addi      r29, r3, 0
	  li        r26, 0
	  b         .loc_0x72C

	.loc_0x6B4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x6D0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x6F8
	  li        r0, 0x1
	  b         .loc_0x724

	.loc_0x6F8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x720
	  li        r0, 0x1
	  b         .loc_0x724

	.loc_0x720:
	  li        r0, 0

	.loc_0x724:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x660

	.loc_0x72C:
	  rlwinm.   r0,r26,0,24,31
	  bne-      .loc_0x738
	  li        r30, 0x1

	.loc_0x738:
	  rlwinm.   r0,r26,0,24,31
	  beq-      .loc_0x76C
	  lhz       r0, 0x570(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x76C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB9
	  bl        -0xD514
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xD524

	.loc_0x76C:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x798
	  lfs       f3, 0x94(r31)
	  lfs       f1, 0x94(r29)
	  lfs       f2, 0x9C(r31)
	  lfs       f0, 0x9C(r29)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x183EC4
	  fmr       f31, f1
	  b         .loc_0x7BC

	.loc_0x798:
	  lwz       r3, 0x478(r31)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x9C(r31)
	  lfs       f2, 0x8(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x183E9C
	  fmr       f31, f1

	.loc_0x7BC:
	  lfs       f1, 0x70(r31)
	  lfs       f2, 0x78(r31)
	  bl        0x183E8C
	  fmr       f2, f31
	  bl        -0x5F5C0
	  fmr       f31, f1
	  lfs       f0, -0x7394(r2)
	  fabs      f1, f31
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x854
	  mr        r3, r31
	  bl        -0x1DE8
	  lfs       f0, -0x738C(r2)
	  mr        r3, r31
	  lwz       r4, 0x2DEC(r13)
	  fdivs     f1, f0, f1
	  lfs       f0, -0x7390(r2)
	  lfs       f2, 0x28C(r4)
	  fmuls     f1, f0, f1
	  fmuls     f0, f31, f2
	  fmuls     f1, f1, f0
	  bl        -0x5A98
	  b         .loc_0x854

	.loc_0x818:
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7388(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x70(r31)
	  fmuls     f3, f1, f0
	  fmuls     f0, f2, f3
	  fsubs     f0, f2, f0
	  stfs      f0, 0x70(r31)
	  lfs       f1, 0x78(r31)
	  fmuls     f0, f1, f3
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r31)

	.loc_0x854:
	  lwz       r3, 0x470(r31)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x5A34
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x934
	  lbz       r0, 0x438(r31)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x934
	  lfs       f1, -0x5800(r13)
	  lfs       f6, 0x70(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f5, 0x74(r31)
	  fmuls     f0, f6, f1
	  lfs       f4, 0x78(r31)
	  lfs       f3, 0x28C(r3)
	  fmuls     f2, f5, f1
	  fmuls     f1, f4, f1
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0xD8(r1)
	  stfs      f0, 0x104(r1)
	  stfs      f2, 0x108(r1)
	  stfs      f1, 0x10C(r1)
	  lfs       f0, 0x104(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xC8(r1)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x108(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x10C(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x110(r1)
	  fsubs     f0, f6, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f0, 0x114(r1)
	  fsubs     f0, f5, f0
	  stfs      f0, 0x120(r1)
	  lfs       f0, 0x118(r1)
	  fsubs     f0, f4, f0
	  stfs      f0, 0x124(r1)
	  lwz       r3, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x124(r1)
	  stw       r0, 0x78(r31)

	.loc_0x934:
	  lmw       r26, 0x1D8(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
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
	u32 badCompiler[2]; // this is ACTUALLY from unused temps according to the DLL

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
	if (pellet->getState() == 3) {
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
	for (int i = 0; i < 20; i++) {
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
			playerState->registerUfoParts(config->mUfoPartIndex, config->mModelId.mId, config->mPelletId.mId);
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

	if (config->mModelId.match('tk**', '*') && !view) {
		PRINT("** newPellet( %s, 0 ) ! teki : use becomepellet!\n", config->mModelId.mStringID);
		PRINT("** newPellet( %s, 0 ) ! teki : use becomepellet!\n", config->mModelId.mStringID);
		ERROR("nakata!");
	}

	if (view) {
		if (config) {
			Pellet* pellet = static_cast<Pellet*>(birth());
			if (pellet) {
				pellet->initPellet(view, config);
			}
			return pellet;
		}
	} else {
		PelletShapeObject* obj = getShapeObject(pelletID);
		PRINT("pellet birth *******\n");
		ID32 pelID(pelletID);
		pelID.print();

		if (config && obj) {
			Pellet* pellet = static_cast<Pellet*>(birth());
			if (pellet) {
				pellet->initPellet(obj, config);
			}
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
	create(96);
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

	// UNUSED FUNCTION
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
		if (useShape(info->mID.mId) && !info->mPelletShapeObject && info->mID.match('un**', '*')) {
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
		case 0:
			doCreate = true;
			break;
		case 1:
			doCreate = useShape(info->mID.mId);
			break;
		case 2:
			doCreate = tekiMgr->mUsingType[info->mTekiType];
			break;
		case 3:
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
