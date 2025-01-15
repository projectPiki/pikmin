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
    , _90(this, 0, 0, 0, "p03", nullptr)
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
	_2C.setID('none');
	_38.setID('none');
	_44.setID('none');
	initCore("pelletConfig");
	_130 = -1;
}

/*
 * --INFO--
 * Address:	80094F00
 * Size:	000074
 */
void PelletConfig::read(RandomAccessStream& input)
{
	Parameters::read(input);
	_2C.read(input);
	_44.read(input);
	_38.read(input);
	_130 = input.readInt();
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
	resetUnk22();
	resetCreatureFlag(CF_FixPosition);
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

		stuck->_194.y -= offset * dir;
	}

	if (!isOnlyPiki) {
		disablePickOffset();
		CI_LOOP(iter)
		{
			(*iter)->_194.y += offset * dir;
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
	setUnk22();
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
	if (mConfig->_2C.match('NAVI', '*')) {
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
	if (mConfig->_90()) {
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
	PRINT("ufo parts %s : (%.1f %.1f %.1f)", mConfig->_2C.mStringID, mPosition.x, mPosition.y, mPosition.z);
	resetUnk22();
	setUnk22();
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
	setUnk22();
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

	_458 = 0;
	_45C = 0;
	_478 = nullptr;

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
	if (pelletMgr->decomposeNumberPellet(mConfig->_2C.mId, color, type)) {
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
	_458 = 0;
	_478 = nullptr;
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
	if (isCreatureFlag(CF_Unk22) && isCreatureFlag(CF_FixPosition)) {
		resetCreatureFlag(CF_FixPosition);
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

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stw       r31, 0x144(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x140(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x13C(r1)
	  mr        r29, r3
	  lwz       r6, 0x45C(r3)
	  cmplwi    r6, 0
	  beq-      .loc_0x1B8
	  lwz       r3, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  lfs       f0, -0x73E8(r2)
	  stw       r3, 0xF0(r1)
	  stw       r0, 0xF4(r1)
	  lwz       r3, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r3, 0xF8(r1)
	  stw       r0, 0xFC(r1)
	  lwz       r3, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r3, 0x100(r1)
	  stw       r0, 0x104(r1)
	  lwz       r3, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r3, 0x108(r1)
	  stw       r0, 0x10C(r1)
	  lwz       r3, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r3, 0x110(r1)
	  stw       r0, 0x114(r1)
	  lwz       r3, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r3, 0x118(r1)
	  stw       r0, 0x11C(r1)
	  lwz       r3, 0x40(r6)
	  lwz       r0, 0x44(r6)
	  stw       r3, 0x120(r1)
	  stw       r0, 0x124(r1)
	  lwz       r3, 0x48(r6)
	  lwz       r0, 0x4C(r6)
	  stw       r3, 0x128(r1)
	  stw       r0, 0x12C(r1)
	  lfs       f2, 0xF0(r1)
	  lfs       f1, 0xF4(r1)
	  lfs       f3, 0xF8(r1)
	  fmuls     f2, f2, f2
	  fmuls     f1, f1, f1
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x134
	  fsqrte    f1, f4
	  lfd       f3, -0x73D0(r2)
	  lfd       f2, -0x73C8(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x38(r1)
	  lfs       f4, 0x38(r1)

	.loc_0x134:
	  lfs       f0, -0x73F0(r2)
	  addi      r6, r1, 0x48
	  lfs       f1, -0x57E4(r13)
	  addi      r5, r1, 0x54
	  fdivs     f4, f0, f4
	  lfs       f0, -0x57F0(r13)
	  addi      r4, r1, 0x60
	  stfs      f1, 0x48(r1)
	  addi      r3, r1, 0xB0
	  stfs      f4, 0x60(r1)
	  lfs       f3, -0x57E0(r13)
	  stfs      f0, 0x54(r1)
	  lfs       f1, -0x57EC(r13)
	  stfs      f4, 0x64(r1)
	  lfs       f2, -0x57DC(r13)
	  stfs      f3, 0x4C(r1)
	  lfs       f0, -0x57E8(r13)
	  stfs      f1, 0x58(r1)
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f4, 0x68(r1)
	  bl        -0x59EAC
	  lwz       r7, 0x45C(r29)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xF0
	  lwz       r6, 0x4(r7)
	  addi      r4, r1, 0xB0
	  lwz       r0, 0x8(r7)
	  stw       r6, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0xC(r7)
	  stw       r0, 0x9C(r29)
	  bl        -0x59EF8

	.loc_0x1B8:
	  lwz       r3, 0x4A8(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1EC
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x2DC
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2DC

	.loc_0x1EC:
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  mr        r3, r30
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0x4AC
	  bl        0x1B1C
	  lwz       r4, 0x55C(r29)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x254
	  xoris     r0, r0, 0x8000
	  lfd       f1, -0x73B8(r2)
	  stw       r0, 0x134(r1)
	  lis       r0, 0x4330
	  addi      r3, r29, 0x5A8
	  stw       r0, 0x130(r1)
	  addi      r4, r1, 0xAC
	  lfd       f0, 0x130(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0xAC(r1)
	  bl        -0x68FC8
	  b         .loc_0x288

	.loc_0x254:
	  cmplwi    r4, 0
	  beq-      .loc_0x270
	  lwz       r0, 0x5C(r4)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0x274

	.loc_0x270:
	  li        r0, 0

	.loc_0x274:
	  cmpwi     r0, 0
	  beq-      .loc_0x288
	  addi      r3, r29, 0x5A8
	  li        r4, 0
	  bl        -0x69000

	.loc_0x288:
	  lwz       r3, 0x554(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x62DA0
	  lwz       r3, 0x220(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x2B8
	  addi      r4, r30, 0
	  li        r5, 0
	  bl        -0xE5E0

	.loc_0x2B8:
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x2DC
	  lwz       r3, 0x554(r29)
	  mr        r4, r30
	  lwz       r5, 0x2E4(r30)
	  addi      r6, r29, 0x5A8
	  lwz       r3, 0x0(r3)
	  bl        -0x67C84

	.loc_0x2DC:
	  lwz       r0, 0x14C(r1)
	  lwz       r31, 0x144(r1)
	  lwz       r30, 0x140(r1)
	  lwz       r29, 0x13C(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098110
 * Size:	0001BC
 */
void Pellet::doCreateColls(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stfd      f30, 0x98(r1)
	  stfd      f29, 0x90(r1)
	  stfd      f28, 0x88(r1)
	  stfd      f27, 0x80(r1)
	  stfd      f26, 0x78(r1)
	  stfd      f25, 0x70(r1)
	  stmw      r27, 0x5C(r1)
	  mr        r27, r3
	  lfs       f0, -0x73E8(r2)
	  stfs      f0, 0x2F4(r27)
	  bl        -0x23A0
	  lwz       r4, 0x4A8(r27)
	  fmr       f31, f1
	  lwz       r3, 0x55C(r27)
	  cmplwi    r4, 0
	  lfs       f30, -0x7384(r2)
	  lfs       f29, -0x73E8(r2)
	  lwz       r29, 0xCC(r3)
	  beq-      .loc_0x78
	  lwz       r12, 0x0(r4)
	  addi      r3, r1, 0x28
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x28(r1)
	  fmuls     f31, f31, f0

	.loc_0x78:
	  lfs       f27, -0x73B0(r2)
	  xoris     r30, r29, 0x8000
	  lfd       f28, -0x73B8(r2)
	  li        r28, 0
	  lis       r31, 0x4330
	  b         .loc_0x184

	.loc_0x90:
	  stw       r30, 0x54(r1)
	  xoris     r0, r28, 0x8000
	  stw       r31, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  stw       r0, 0x4C(r1)
	  fsubs     f0, f0, f28
	  stw       r31, 0x48(r1)
	  fdivs     f1, f27, f0
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f28
	  fmuls     f25, f1, f0
	  fmr       f1, f25
	  bl        0x183B18
	  fmuls     f26, f31, f1
	  fmr       f1, f25
	  bl        0x183978
	  fmuls     f2, f31, f1
	  lfs       f0, -0x57D8(r13)
	  fmr       f1, f30
	  addi      r3, r27, 0
	  addi      r4, r1, 0x34
	  stfs      f2, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f26, 0x3C(r1)
	  bl        -0x55EC
	  fmr       f1, f25
	  bl        0x183AE0
	  fmuls     f26, f31, f1
	  fmr       f1, f25
	  bl        0x183940
	  fmuls     f1, f31, f1
	  lfs       f0, -0x57D4(r13)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f26, 0x3C(r1)
	  lwz       r0, 0x4A8(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x144
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  fmr       f2, f1
	  b         .loc_0x164

	.loc_0x144:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x55C(r27)
	  lfs       f0, 0xFC(r3)
	  fmuls     f2, f1, f0

	.loc_0x164:
	  lfs       f0, 0x38(r1)
	  fmr       f1, f29
	  mr        r3, r27
	  fadds     f0, f0, f2
	  addi      r4, r1, 0x34
	  stfs      f0, 0x38(r1)
	  bl        -0x5678
	  addi      r28, r28, 0x1

	.loc_0x184:
	  cmpw      r28, r29
	  blt+      .loc_0x90
	  lmw       r27, 0x5C(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lfd       f30, 0x98(r1)
	  lfd       f29, 0x90(r1)
	  lfd       f28, 0x88(r1)
	  lfd       f27, 0x80(r1)
	  lfd       f26, 0x78(r1)
	  lfd       f25, 0x70(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800982CC
 * Size:	000064
 */
bool InteractSwallow::actPellet(Pellet*)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x474(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0x24
	  lwz       r0, 0x4(r5)
	  b         .loc_0x28

	.loc_0x24:
	  li        r0, 0

	.loc_0x28:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x54

	.loc_0x38:
	  lwz       r0, 0xC(r6)
	  mr        r3, r4
	  stw       r0, 0x45C(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r5, 0xC(r6)
	  bl        -0x8380
	  li        r3, 0x1

	.loc_0x54:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098330
 * Size:	000148
 */
bool InteractKill::actPellet(Pellet*)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r4
	  lwz       r0, 0x45C(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x11C
	  addi      r3, r1, 0x24
	  addi      r4, r29, 0
	  bl        -0x76DC
	  addi      r31, r1, 0x24
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xC0

	.loc_0x54:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x78
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x90

	.loc_0x78:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  li        r4, 0
	  bl        -0xD6E4
	  cmpwi     r30, 0
	  blt-      .loc_0xA4
	  subi      r30, r30, 0x1

	.loc_0xA4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xC0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE8
	  li        r0, 0x1
	  b         .loc_0x114

	.loc_0xE8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x110
	  li        r0, 0x1
	  b         .loc_0x114

	.loc_0x110:
	  li        r0, 0

	.loc_0x114:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x54

	.loc_0x11C:
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0xD774
	  lwz       r0, 0x4C(r1)
	  li        r3, 0x1
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098478
 * Size:	000058
 */
bool PelletMgr::decomposeNumberPellet(u32, int&, int&)
{
	/*
	.loc_0x0:
	  lis       r3, 0x802B
	  li        r0, 0x14
	  subi      r3, r3, 0xE8
	  mtctr     r0
	  addi      r7, r3, 0xD8
	  li        r8, 0

	.loc_0x18:
	  lwz       r0, 0x8(r7)
	  cmplw     r4, r0
	  bne-      .loc_0x44
	  mulli     r0, r8, 0xC
	  add       r4, r3, r0
	  lwz       r0, 0xD8(r4)
	  li        r3, 0x1
	  stw       r0, 0x0(r5)
	  lwz       r0, 0xDC(r4)
	  stw       r0, 0x0(r6)
	  blr

	.loc_0x44:
	  addi      r7, r7, 0xC
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x18
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800984D0
 * Size:	000068
 */
void PelletMgr::registerUfoParts()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lwz       r31, 0x6C(r3)
	  b         .loc_0x4C

	.loc_0x18:
	  cmplwi    r31, 0
	  addi      r6, r31, 0
	  beq-      .loc_0x28
	  subi      r6, r6, 0x4

	.loc_0x28:
	  lwz       r0, 0x5C(r6)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x48
	  lwz       r3, 0x2F6C(r13)
	  lwz       r4, 0x130(r6)
	  lwz       r5, 0x2C(r6)
	  lwz       r6, 0x44(r6)
	  bl        -0x1784C

	.loc_0x48:
	  lwz       r31, 0xC(r31)

	.loc_0x4C:
	  cmplwi    r31, 0
	  bne+      .loc_0x18
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098538
 * Size:	000078
 */
Pellet* PelletMgr::newNumberPellet(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r6, 0x10
	  mr        r6, r0
	  stwu      r1, -0x8(r1)
	  li        r7, 0
	  b         .loc_0x40

	.loc_0x20:
	  cmpw      r4, r0
	  bne-      .loc_0x3C
	  lwz       r0, 0x4(r6)
	  cmpw      r5, r0
	  bne-      .loc_0x3C
	  lwz       r7, 0x8(r6)
	  b         .loc_0x4C

	.loc_0x3C:
	  addi      r6, r6, 0xC

	.loc_0x40:
	  lwz       r0, 0x0(r6)
	  cmpwi     r0, -0x1
	  bne+      .loc_0x20

	.loc_0x4C:
	  cmplwi    r7, 0
	  beq-      .loc_0x64
	  addi      r4, r7, 0
	  li        r5, 0
	  bl        .loc_0x78
	  b         .loc_0x68

	.loc_0x64:
	  li        r3, 0

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x78:
	*/
}

/*
 * --INFO--
 * Address:	800985B0
 * Size:	000154
 */
Pellet* PelletMgr::newPellet(u32, PelletView*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  addi      r27, r3, 0
	  addi      r31, r4, 0
	  addi      r28, r5, 0
	  bl        0x758
	  mr.       r30, r3
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x30:
	  lis       r4, 0x746B
	  addi      r3, r30, 0x2C
	  addi      r4, r4, 0x2A2A
	  li        r5, 0x2A
	  bl        -0x54708
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  cmplwi    r28, 0

	.loc_0x50:
	  cmplwi    r28, 0
	  beq-      .loc_0xD4
	  cmplwi    r30, 0
	  beq-      .loc_0x13C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r29, r3
	  beq-      .loc_0xCC
	  li        r31, 0
	  sth       r31, 0x570(r29)
	  li        r0, 0x1
	  addi      r4, r28, 0
	  stb       r0, 0x452(r29)
	  addi      r3, r1, 0x14
	  stw       r28, 0x4A8(r29)
	  stw       r30, 0x55C(r29)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x14(r1)
	  stfs      f0, 0x7C(r29)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0x80(r29)
	  lfs       f0, 0x1C(r1)
	  stfs      f0, 0x84(r29)
	  stw       r31, 0x554(r29)
	  stw       r31, 0x220(r29)

	.loc_0xCC:
	  mr        r3, r29
	  b         .loc_0x140

	.loc_0xD4:
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        .loc_0x154
	  addi      r29, r3, 0
	  addi      r4, r31, 0
	  addi      r3, r1, 0x20
	  bl        -0x54808
	  addi      r3, r1, 0x20
	  bl        -0x5454C
	  cmplwi    r30, 0
	  beq-      .loc_0x13C
	  cmplwi    r29, 0
	  beq-      .loc_0x13C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x134
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  bl        -0x1E18

	.loc_0x134:
	  mr        r3, r31
	  b         .loc_0x140

	.loc_0x13C:
	  li        r3, 0

	.loc_0x140:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x154:
	*/
}

/*
 * --INFO--
 * Address:	80098704
 * Size:	000094
 */
PelletShapeObject* PelletMgr::getShapeObject(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  bl        0x604
	  cmplwi    r3, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x7C

	.loc_0x30:
	  lwz       r6, 0x1A8(r30)
	  b         .loc_0x64

	.loc_0x38:
	  cmplwi    r6, 0
	  addi      r5, r6, 0
	  beq-      .loc_0x48
	  subi      r5, r5, 0x4

	.loc_0x48:
	  lwz       r4, 0x18(r5)
	  lwz       r0, 0x44(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x60
	  lwz       r3, 0x5C(r5)
	  b         .loc_0x7C

	.loc_0x60:
	  lwz       r6, 0xC(r6)

	.loc_0x64:
	  cmplwi    r6, 0
	  bne+      .loc_0x38
	  addi      r3, r1, 0x10
	  addi      r4, r31, 0
	  bl        -0x548E4
	  li        r3, 0

	.loc_0x7C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098798
 * Size:	000054
 */
Creature* PelletMgr::createObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  li        r3, 0x5BC
	  bl        -0x517B0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x30
	  bl        -0x3688

	.loc_0x30:
	  lwz       r0, 0x1F4(r30)
	  mr        r3, r31
	  stw       r0, 0x224(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800987EC
 * Size:	000254
 */
PelletMgr::PelletMgr(MapMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        0x48844
	  lis       r3, 0x802B
	  lwz       r31, 0x8(r1)
	  addi      r3, r3, 0x188
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  lis       r3, 0x8022
	  stw       r0, 0x8(r31)
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x3C(r31)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802B
	  stw       r0, 0x3C(r31)
	  li        r30, 0
	  subi      r4, r3, 0x5C
	  stw       r30, 0x4C(r31)
	  addi      r3, r31, 0x3C
	  stw       r30, 0x48(r31)
	  stw       r30, 0x44(r31)
	  bl        -0x73984
	  lis       r3, 0x802B
	  addi      r0, r3, 0x278
	  stw       r0, 0x3C(r31)
	  subi      r0, r13, 0x57D0
	  addi      r3, r31, 0x58
	  stw       r30, 0x4C(r31)
	  stw       r30, 0x48(r31)
	  stw       r30, 0x44(r31)
	  stw       r0, 0x40(r31)
	  bl        -0x3D10
	  addi      r3, r31, 0x194
	  bl        0xCC0
	  bl        0x1304
	  stw       r3, 0x1F8(r31)
	  subi      r0, r13, 0x57C8
	  li        r3, 0x58
	  stw       r30, 0x1A8(r31)
	  stw       r30, 0x1A4(r31)
	  stw       r30, 0x1A0(r31)
	  stw       r0, 0x19C(r31)
	  stw       r30, 0x190(r31)
	  bl        -0x518AC
	  mr.       r31, r3
	  beq-      .loc_0x1F8
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r31)
	  addi      r3, r1, 0x28
	  subi      r4, r13, 0x57C4
	  stw       r30, 0x0(r31)
	  bl        -0x47DFC
	  lwz       r0, 0x28(r1)
	  addi      r5, r1, 0x24
	  lfs       f1, -0x7398(r2)
	  mr        r4, r31
	  stw       r0, 0x24(r1)
	  lfs       f2, -0x73E8(r2)
	  addi      r3, r31, 0x4
	  lfs       f3, -0x73F0(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x30
	  subi      r4, r13, 0x57C0
	  bl        -0x47E30
	  lwz       r0, 0x30(r1)
	  addi      r5, r1, 0x2C
	  lfs       f1, -0x7398(r2)
	  mr        r4, r31
	  stw       r0, 0x2C(r1)
	  lfs       f2, -0x73E8(r2)
	  addi      r3, r31, 0x14
	  lfs       f3, -0x73F0(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x38
	  subi      r4, r13, 0x57BC
	  bl        -0x47E64
	  lwz       r0, 0x38(r1)
	  addi      r5, r1, 0x34
	  lfs       f1, -0x7380(r2)
	  mr        r4, r31
	  stw       r0, 0x34(r1)
	  lfs       f2, -0x73E8(r2)
	  addi      r3, r31, 0x24
	  lfs       f3, -0x73F0(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x40
	  subi      r4, r13, 0x57B8
	  bl        -0x47E98
	  lwz       r0, 0x40(r1)
	  addi      r5, r1, 0x3C
	  lfs       f1, -0x737C(r2)
	  mr        r4, r31
	  stw       r0, 0x3C(r1)
	  lfs       f2, -0x7378(r2)
	  addi      r3, r31, 0x34
	  lfs       f3, -0x73E4(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x48
	  subi      r4, r13, 0x57B4
	  bl        -0x47ECC
	  lwz       r0, 0x48(r1)
	  addi      r5, r1, 0x44
	  lfs       f1, -0x7374(r2)
	  mr        r4, r31
	  stw       r0, 0x44(r1)
	  lfs       f2, -0x7378(r2)
	  addi      r3, r31, 0x44
	  lfs       f3, -0x73E4(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  lis       r3, 0x802B
	  addi      r0, r3, 0x238
	  stw       r0, 0x54(r31)
	  lfs       f0, -0x737C(r2)
	  stfs      f0, 0x10(r31)

	.loc_0x1F8:
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x802B
	  addi      r5, r3, 0x8C
	  stw       r31, 0x1F4(r30)
	  li        r0, 0
	  addi      r3, r30, 0x8
	  stw       r0, 0x54(r30)
	  subi      r4, r13, 0x57B0
	  li        r6, 0x1
	  stw       r0, 0x1FC(r30)
	  bl        -0x5836C
	  addi      r3, r30, 0
	  li        r4, 0x60
	  bl        0x486D8
	  li        r0, 0x7
	  sth       r0, 0x200(r30)
	  mr        r3, r30
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x254:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
bool PelletMgr::useShape(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80098B04
 * Size:	0000F0
 */
void PelletMgr::addUseList(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  lwz       r3, 0x4C(r3)
	  b         .loc_0x44

	.loc_0x2C:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r31
	  bne-      .loc_0x40
	  li        r0, 0x1
	  b         .loc_0x50

	.loc_0x40:
	  lwz       r3, 0xC(r3)

	.loc_0x44:
	  cmplwi    r3, 0
	  bne+      .loc_0x2C
	  li        r0, 0

	.loc_0x50:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xD0
	  li        r3, 0x18
	  bl        -0x51B5C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xC0
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r28)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r28)
	  li        r29, 0
	  lis       r4, 0x802B
	  stw       r29, 0x10(r28)
	  subi      r4, r4, 0x5C
	  stw       r29, 0xC(r28)
	  stw       r29, 0x8(r28)
	  bl        -0x73CCC
	  lis       r3, 0x802B
	  addi      r0, r3, 0x278
	  stw       r0, 0x0(r28)
	  subi      r0, r13, 0x57D0
	  stw       r29, 0x10(r28)
	  stw       r29, 0xC(r28)
	  stw       r29, 0x8(r28)
	  stw       r0, 0x4(r28)

	.loc_0xC0:
	  stw       r31, 0x14(r28)
	  mr        r4, r28
	  addi      r3, r30, 0x3C
	  bl        -0x585F8

	.loc_0xD0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098BF4
 * Size:	000054
 */
void PelletMgr::initShapeInfos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  addi      r4, r4, 0x98
	  stwu      r1, -0x18(r1)
	  li        r6, 0x1
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x1FC(r3)
	  lis       r3, 0x802B
	  addi      r5, r3, 0xA4
	  addi      r3, r31, 0x8
	  bl        -0x58588
	  mr        r3, r31
	  bl        0x3BC
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098C48
 * Size:	000040
 */
int PelletMgr::getConfigIndex(u32)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x6C(r3)
	  li        r3, 0
	  b         .loc_0x30

	.loc_0xC:
	  cmplwi    r6, 0
	  addi      r5, r6, 0
	  beq-      .loc_0x1C
	  subi      r5, r5, 0x4

	.loc_0x1C:
	  lwz       r0, 0x2C(r5)
	  cmplw     r0, r4
	  beqlr-
	  lwz       r6, 0xC(r6)
	  addi      r3, r3, 0x1

	.loc_0x30:
	  cmplwi    r6, 0
	  bne+      .loc_0xC
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098C88
 * Size:	00009C
 */
PelletConfig* PelletMgr::getConfigFromIdx(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  blt-      .loc_0x14
	  lwz       r0, 0x54(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x1C

	.loc_0x14:
	  li        r3, 0
	  blr

	.loc_0x1C:
	  cmpwi     r4, 0
	  lwz       r3, 0x6C(r3)
	  li        r6, 0
	  ble-      .loc_0x8C
	  cmpwi     r4, 0x8
	  subi      r5, r4, 0x8
	  ble-      .loc_0x74
	  addi      r0, r5, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r5, 0
	  mtctr     r0
	  ble-      .loc_0x74

	.loc_0x4C:
	  lwz       r3, 0xC(r3)
	  addi      r6, r6, 0x8
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  bdnz+     .loc_0x4C

	.loc_0x74:
	  sub       r0, r4, r6
	  cmpw      r6, r4
	  mtctr     r0
	  bge-      .loc_0x8C

	.loc_0x84:
	  lwz       r3, 0xC(r3)
	  bdnz+     .loc_0x84

	.loc_0x8C:
	  cmplwi    r3, 0
	  beqlr-
	  subi      r3, r3, 0x4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
ID32 PelletMgr::getConfigIdAt(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80098D24
 * Size:	000038
 */
PelletConfig* PelletMgr::getConfig(u32)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x6C(r3)
	  b         .loc_0x28

	.loc_0x8:
	  cmplwi    r5, 0
	  addi      r3, r5, 0
	  beq-      .loc_0x18
	  subi      r3, r3, 0x4

	.loc_0x18:
	  lwz       r0, 0x2C(r3)
	  cmplw     r0, r4
	  beqlr-
	  lwz       r5, 0xC(r5)

	.loc_0x28:
	  cmplwi    r5, 0
	  bne+      .loc_0x8
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098D5C
 * Size:	000044
 */
void PelletMgr::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x1FC(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x30
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  bge-      .loc_0x28
	  b         .loc_0x34

	.loc_0x28:
	  bl        .loc_0x44
	  b         .loc_0x34

	.loc_0x30:
	  bl        0xD0

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x44:
	*/
}

/*
 * --INFO--
 * Address:	80098DA0
 * Size:	0000BC
 */
void PelletMgr::readConfigs(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x54(r28)
	  li        r30, 0
	  b         .loc_0x90

	.loc_0x44:
	  li        r3, 0x138
	  bl        -0x51DE4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x5C
	  bl        -0x4288

	.loc_0x5C:
	  lwz       r12, 0x134(r31)
	  mr        r3, r31
	  mr        r4, r29
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r31, 0
	  beq-      .loc_0x80
	  addi      r31, r31, 0x4

	.loc_0x80:
	  addi      r3, r28, 0x5C
	  addi      r4, r31, 0
	  bl        -0x58850
	  addi      r30, r30, 0x1

	.loc_0x90:
	  lwz       r0, 0x54(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x44
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098E5C
 * Size:	0000BC
 */
void PelletMgr::readAnimInfos(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x190(r28)
	  li        r30, 0
	  b         .loc_0x90

	.loc_0x44:
	  li        r3, 0x60
	  bl        -0x51EA0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x5C
	  bl        0x694

	.loc_0x5C:
	  lwz       r12, 0x58(r31)
	  mr        r3, r31
	  mr        r4, r29
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r31, 0
	  beq-      .loc_0x80
	  addi      r31, r31, 0x4

	.loc_0x80:
	  addi      r3, r28, 0x198
	  addi      r4, r31, 0
	  bl        -0x5890C
	  addi      r30, r30, 0x1

	.loc_0x90:
	  lwz       r0, 0x190(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x44
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098F18
 * Size:	0000D4
 */
void PelletMgr::initTekiNakaParts()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  lis       r31, 0x756E
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r30, 0x1A8(r3)
	  b         .loc_0xAC

	.loc_0x2C:
	  cmplwi    r30, 0
	  addi      r3, r30, 0
	  beq-      .loc_0x3C
	  subi      r3, r3, 0x4

	.loc_0x3C:
	  lwz       r4, 0x18(r3)
	  mr        r29, r3
	  lwz       r3, 0x4C(r28)
	  b         .loc_0x64

	.loc_0x4C:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r4
	  bne-      .loc_0x60
	  li        r0, 0x1
	  b         .loc_0x70

	.loc_0x60:
	  lwz       r3, 0xC(r3)

	.loc_0x64:
	  cmplwi    r3, 0
	  bne+      .loc_0x4C
	  li        r0, 0

	.loc_0x70:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xA8
	  lwz       r0, 0x5C(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xA8
	  addi      r3, r29, 0x18
	  addi      r4, r31, 0x2A2A
	  li        r5, 0x2A
	  bl        -0x550C0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  mr        r3, r29
	  bl        0x710
	  cmplwi    r3, 0

	.loc_0xA8:
	  lwz       r30, 0xC(r30)

	.loc_0xAC:
	  cmplwi    r30, 0
	  bne+      .loc_0x2C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098FEC
 * Size:	0000DC
 */
void PelletMgr::createShapeObjects()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r31, 0x1A8(r3)
	  b         .loc_0xBC

	.loc_0x20:
	  cmplwi    r31, 0
	  addi      r3, r31, 0
	  beq-      .loc_0x30
	  subi      r3, r3, 0x4

	.loc_0x30:
	  lwz       r0, 0x24(r3)
	  li        r4, 0
	  cmpwi     r0, 0x2
	  beq-      .loc_0x98
	  bge-      .loc_0xA8
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  bge-      .loc_0x60
	  b         .loc_0xA8
	  b         .loc_0xA8

	.loc_0x58:
	  li        r4, 0x1
	  b         .loc_0xA8

	.loc_0x60:
	  lwz       r5, 0x18(r3)
	  lwz       r4, 0x4C(r30)
	  b         .loc_0x84

	.loc_0x6C:
	  lwz       r0, 0x14(r4)
	  cmplw     r0, r5
	  bne-      .loc_0x80
	  li        r0, 0x1
	  b         .loc_0x90

	.loc_0x80:
	  lwz       r4, 0xC(r4)

	.loc_0x84:
	  cmplwi    r4, 0
	  bne+      .loc_0x6C
	  li        r0, 0

	.loc_0x90:
	  mr        r4, r0
	  b         .loc_0xA8

	.loc_0x98:
	  lwz       r4, 0x28(r3)
	  lwz       r5, 0x3160(r13)
	  addi      r0, r4, 0x164
	  lbzx      r4, r5, r0

	.loc_0xA8:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0xB8
	  bl        0x62C
	  cmplwi    r3, 0

	.loc_0xB8:
	  lwz       r31, 0xC(r31)

	.loc_0xBC:
	  cmplwi    r31, 0
	  bne+      .loc_0x20
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800990C8
 * Size:	000210
 */
void PelletMgr::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r27, 0x4C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  bl        0x48218
	  addi      r30, r27, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  addi      r31, r1, 0x18
	  b         .loc_0x1A0

	.loc_0x40:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x64
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x7C

	.loc_0x64:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x7C:
	  lbz       r0, 0x2FA8(r13)
	  addi      r27, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x184
	  li        r6, 0
	  stb       r6, 0x18(r1)
	  li        r0, 0xFF
	  addi      r3, r28, 0
	  stb       r0, 0x19(r1)
	  addi      r4, r31, 0
	  li        r5, 0x1
	  stb       r6, 0x1A(r1)
	  stb       r0, 0x1B(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  bl        -0x7204
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE4
	  addi      r3, r1, 0x28
	  crclr     6, 0x6
	  subi      r4, r13, 0x57A8
	  bl        0x17D3F4
	  b         .loc_0xF4

	.loc_0xE4:
	  addi      r3, r1, 0x28
	  crclr     6, 0x6
	  subi      r4, r13, 0x57A0
	  bl        0x17D3E0

	.loc_0xF4:
	  lfs       f0, 0x94(r27)
	  mr        r3, r27
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x98(r27)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x9C(r27)
	  stfs      f0, 0x24(r1)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x20(r1)
	  addi      r3, r1, 0x1C
	  fadds     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lwz       r4, 0x2E4(r28)
	  addi      r4, r4, 0x1E0
	  bl        -0x61AB4
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x28
	  lwz       r3, 0x10(r3)
	  bl        -0x710DC
	  lwz       r12, 0x3B4(r28)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r28, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x1C
	  crclr     6, 0x6
	  addi      r8, r1, 0x28
	  li        r7, 0
	  blrl

	.loc_0x184:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x1A0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  li        r0, 0x1
	  b         .loc_0x1F4

	.loc_0x1C8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1F0
	  li        r0, 0x1
	  b         .loc_0x1F4

	.loc_0x1F0:
	  li        r0, 0

	.loc_0x1F4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40
	  lmw       r27, 0x4C(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
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
