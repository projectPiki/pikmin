#include "Creature.h"
#include "SearchSystem.h"
#include "Collision.h"
#include "DynColl.h"
#include "Geometry.h"
#include "SoundMgr.h"
#include "Graphics.h"
#include "AIConstant.h"
#include "CreatureProp.h"
#include "Generator.h"
#include "Dolphin/os.h"
#include "math.h"
#include "Pellet.h"
#include "timers.h"
#include "BombItem.h"
#include "RadarInfo.h"
#include "AIPerf.h"
#include "MapCode.h"
#include "DebugLog.h"

static CollTriInfo* triList[0x200];

static int numTris;
static CollTriInfo* baseTri;
static f32 checkRadius;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("Creature");

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void Creature::startFixPosition()
{
	mFixedPosition = mPosition;
	setCreatureFlag(CF_FixPosition);
}

/*
 * --INFO--
 * Address:	8008A040
 * Size:	000010
 */
void Creature::finishFixPosition() { resetCreatureFlag(CF_FixPosition); }

/*
 * --INFO--
 * Address:	8008A050
 * Size:	000048
 */
bool Creature::isTerrible() { return isTeki() || isBoss(); }

/*
 * --INFO--
 * Address:	8008A098
 * Size:	0000D8
 */
void Creature::load(RandomAccessStream& stream, bool doLoadPosition)
{
	PRINT("* loading creature %s\n", ObjType::getName(mObjType));
	int startPos = stream.getPosition();
	if (doLoadPosition) {
		// idk why they didn't use the Vector3f::read inline here, but they didn't
		mPosition.x = stream.readFloat();
		mPosition.y = stream.readFloat();
		mPosition.z = stream.readFloat();
	}

	doLoad(stream);
	PRINT("******** done : %d\n", stream.getPosition() - startPos);
}

/*
 * --INFO--
 * Address:	8008A170
 * Size:	0000D8
 */
void Creature::save(RandomAccessStream& stream, bool doSavePosition)
{
	PRINT("* saving creature %s\n", ObjType::getName(mObjType));
	int startPos = stream.getPosition();
	if (doSavePosition) {
		// idk why they didn't use the Vector3f::write inline here but they didn't
		stream.writeFloat(mPosition.x);
		stream.writeFloat(mPosition.y);
		stream.writeFloat(mPosition.z);
	}

	doSave(stream);
	PRINT("******** done : %d\n", stream.getPosition() - startPos);
}

/*
 * --INFO--
 * Address:	8008A248
 * Size:	00001C
 */
Creature* Creature::getCollidePlatformCreature()
{
	if (mCollPlatform) {
		return mCollPlatform->mCreature;
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	8008A264
 * Size:	000044
 */
Vector3f Creature::getCollidePlatformNormal()
{
	if (!mCollPlatNormal) {
		return Vector3f(0.0, 0.0f, 0.0f);
	}
	return *mCollPlatNormal;
}

/*
 * --INFO--
 * Address:	8008A2A8
 * Size:	000024
 */
bool Creature::isBoss()
{
	if (mObjType >= OBJTYPE_BossBegin && mObjType <= OBJTYPE_BossEnd) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8008A2CC
 * Size:	000048
 */
void Creature::enableStick()
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		mCollInfo->enableStick();
	} else {
		PRINT("enableStick * nothing is done\n");
	}
}

/*
 * --INFO--
 * Address:	8008A314
 * Size:	000048
 */
void Creature::disableStick()
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		mCollInfo->disableStick();
	} else {
		PRINT("disableStick * nothing is done\n");
	}
}

/*
 * --INFO--
 * Address:	8008A35C
 * Size:	000070
 */
CollPart* Creature::getNearestCollPart(Vector3f& p1, u32 p2)
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		return mCollInfo->getNearestCollPart(p1, p2);
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	8008A3CC
 * Size:	000060
 */
CollPart* Creature::getRandomCollPart(u32 p1)
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		return mCollInfo->getRandomCollPart(p1);
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	8008A42C
 * Size:	0000D8
 */
Vector3f Creature::getBoundingSphereCentre()
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		if (mObjType != OBJTYPE_Navi && !isPiki() && !aiCullable() && mGrid.aiCulling()) {
			return mPosition;
		}

		CollPart* bound = mCollInfo->getBoundingSphere();
		return bound->mCentre;
	}

	return getCentre();
}

/*
 * --INFO--
 * Address:	8008A504
 * Size:	0000B0
 */
f32 Creature::getBoundingSphereRadius()
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		CollPart* bound = mCollInfo->getBoundingSphere();
		if (mObjType != OBJTYPE_Navi && !isPiki() && !aiCullable() && mGrid.aiCulling()) {
			return 2.0f * bound->mRadius;
		}

		return bound->mRadius;
	}

	return getCentreSize();
}

/*
 * --INFO--
 * Address:	8008A5B4
 * Size:	000038
 */
void Creature::playEventSound(Creature* target, int soundID)
{
	if (target && target->mSeContext) {
		target->mSeContext->playSound(soundID);
	}
}

/*
 * --INFO--
 * Address:	8008A5EC
 * Size:	000038
 */
void Creature::stopEventSound(Creature* target, int soundID)
{
	if (target && target->mSeContext) {
		target->mSeContext->stopSound(soundID);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
bool Creature::insideSphere(Sphere& sphere)
{
	Vector3f diff = sphere.mCentre - mPosition;
	if (diff.length() <= sphere.mRadius) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8008A624
 * Size:	0000F4
 */
Vector3f Creature::getCentre()
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		CollPart* spherePart = mCollInfo->getSphere('cent');
		if (mObjType != OBJTYPE_Navi && !isPiki() && !aiCullable() && mGrid.aiCulling()) {
			return mPosition;
		}
		if (spherePart) {
			return spherePart->mCentre;
		}
	}

	Vector3f pos = mPosition;
	return pos;
}

/*
 * --INFO--
 * Address:	8008A718
 * Size:	000074
 */
f32 Creature::getCentreSize()
{
	if (mCollInfo && mCollInfo->hasInfo()) {
		CollPart* spherePart = mCollInfo->getSphere('cent');
		if (spherePart) {
			return spherePart->mRadius;
		}
	}
	return getSize();
}

/*
 * --INFO--
 * Address:	8008A78C
 * Size:	00006C
 */
int Creature::getStandType()
{
	if (!mFloorTri) {
		if (mCollPlatform) {
			if (mCollPlatform->mCreature) {
				// standing on a platform creature?
				return STANDTYPE_TekiPlatform;
			}
			// standing on a platform with no creature?
			return STANDTYPE_Platform;
		}
		// no platform, _2BC == 0
		return STANDTYPE_Air;
	}

	if (mCollPlatform) {
		if (mCollPlatform->mCreature) {
			// standing on a platform creature?
			return STANDTYPE_TekiPlatform;
		}
		// standing on a platform with no creature?
		return STANDTYPE_Platform;
	}

	// no platform, _2BC != 0
	return STANDTYPE_Ground;
}

/*
 * --INFO--
 * Address:	8008A7F8
 * Size:	00005C
 */
SearchData::SearchData()
{
	_08 = 0;
	_00.reset();
	_04 = 12800.0f;
}

/*
 * --INFO--
 * Address:	8008A854
 * Size:	000020
 */
u32 Creature::getGeneratorID()
{
	if (mGenerator) {
		return mGenerator->mGeneratorName.mId;
	}
	return 'null';
}

/*
 * --INFO--
 * Address:	8008A874
 * Size:	000028
 */
bool Creature::stimulate(Interaction& interaction)
{
	PRINT("objType=%s creature %x got interaction %x\n", ObjType::getName(mObjType), &interaction);
	return false;
}

/*
 * --INFO--
 * Address:	8008A89C
 * Size:	000138
 */
bool Creature::setStateGrabbed(Creature* holder)
{
	if (isGrabbed()) {
		// we're already being held by something
		return false;
	}

	mHoldingCreature.set(holder);
	holder->mGrabbedCreature.set(this);
	mPreGrabRotation = _E0;
	_100.fromEuler(Vector3f(0.39269909f, 0.0f, 0.0f));
	_110 = 0.0f;

	PRINT("setStateGrabbed : this=%x c=%x\n", this, holder);
	if (mObjType != OBJTYPE_Bomb) {
		PRINT("*** THIS IS NOT BOMB !!\n");
		dump();
		holder->dump();
	}

	return true;
}

/*
 * --INFO--
 * Address:	8008A9D4
 * Size:	000068
 */
void Creature::resetStateGrabbed()
{
	mHoldingCreature.getPtr()->mGrabbedCreature.reset();
	mHoldingCreature.reset();
	PRINT("## resetStateGrabbed\n");
}

/*
 * --INFO--
 * Address:	8008AA3C
 * Size:	000048
 */
void Creature::turnTo(Vector3f& targetDir) { mDirection = atan2f(targetDir.x - mPosition.x, targetDir.z - mPosition.z); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void Creature::adjustDistance(Vector3f& targetPos, f32 targetDist)
{
	Vector3f sep = targetPos - mPosition;
	f32 dist     = sep.length();
	sep          = (targetDist / dist) * sep;
	mPosition    = targetPos - sep;
}

/*
 * --INFO--
 * Address:	8008AA84
 * Size:	000180
 */
void Creature::init()
{
	mSearchBuffer.invalidate();
	_114.makeIdentity();
	mTransformMatrix.makeIdentity();
	_E0.set(0.0f, 0.0f, 0.0f, 1.0f);
	_60              = 0;
	mCreatureFlags   = 0;
	mPelletStickSlot = -1;
	disableAICulling();
	_21C = 0;
	setCreatureFlag(CF_Free);
	resetCreatureFlag(CF_GroundOffsetEnabled | CF_IsAiDisabled | CF_IsClimbing | CF_AIAlwaysActive);
	mGroundOffset = 0.0f;
	mHoldingCreature.clear();
	mGrabbedCreature.clear();
	resetCreatureFlag(CF_Unk6 | CF_Unk17);
	clearCnt();
	mIsBeingDamaged = false;

	setCreatureFlag(CF_IsOnGround | CF_Unk4);
	resetCreatureFlag(CF_Unk5 | CF_Unk7 | CF_Unk8 | CF_Unk11);
	mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	_1AC.set(0.0f, 0.0f, 0.0f);
	mStickTarget = nullptr;
	mStickPart   = nullptr;

	mPrevSticker   = nullptr;
	mNextSticker   = nullptr;
	mStickListHead = nullptr;
	resetCreatureFlag(CF_StuckToObject | CF_StuckToMouth);

	mRopeListHead   = nullptr;
	mRope           = nullptr;
	mRopeRatio      = 0.0f;
	mPrevRopeHolder = nullptr;
	mNextRopeHolder = nullptr;
	if (searchUpdateMgr) {
		if (isPiki()) {
			_168.setPiki(true);
		}

		_168.init(searchUpdateMgr);
	}
}

/*
 * --INFO--
 * Address:	8008AC04
 * Size:	000064
 */
void Creature::init(Vector3f& pos)
{
	Creature::init();
	resetPosition(pos);
	_1A4 = 0;
	resetCreatureFlag(CF_StuckToMouth);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
int Creature::getAtariType()
{
	return 0; // from the DLL - lol.
}

/*
 * --INFO--
 * Address:	8008AC68
 * Size:	000034
 */
void Creature::resetPosition(Vector3f& pos)
{
	mPosition = pos;
	_1AC      = pos;
}

/*
 * --INFO--
 * Address:	8008AC9C
 * Size:	000044
 */
void Creature::detachGenerator()
{
	if (mGenerator) {
		mGenerator->informDeath(this);
		mGenerator = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8008ACE0
 * Size:	0001F8
 */
void Creature::kill(bool p1)
{
	finishWaterEffect();

	if (mObjType == OBJTYPE_Teki) {
		PRINT("TEKI DIED ************************************\n");
	}

	detachGenerator();

	if (isHolding()) {
		Creature* bomb = getHoldCreature();
		bomb->resetStateGrabbed();
		if (static_cast<AICreature*>(bomb)->mObjType == OBJTYPE_Bomb) {
			if (static_cast<AICreature*>(bomb)->getCurrState()->getID() != 1) {
				MsgUser msg(1);
				static_cast<AICreature*>(bomb)->_2D0 = 1;
				static_cast<AICreature*>(bomb)->mStateMachine->procMsg(static_cast<AICreature*>(bomb), &msg);
			}
		}
	}

	if (searchUpdateMgr) {
		_168.exit();
	}

	if (mObjType == OBJTYPE_Piki || mObjType == OBJTYPE_Navi) {
		mGrid.delAIGrid();
	}

	mSearchBuffer.clear();

	if (mStickTarget) {
		endStick();
	}

	if (mStickListHead) {
		PRINT("%x(type%d) died : release all stickers ..\n", this, mObjType);
		while (mStickListHead) {
			if (mStickListHead->isCreatureFlag(CF_StuckToObject)) {
				PRINT("stick off object\n");
				mStickListHead->endStickObject();

			} else if (mStickListHead->isCreatureFlag(CF_StuckToMouth)) {
				PRINT("stick off mouth\n");
				mStickListHead->endStickMouth();

			} else {
				PRINT("stick off\n");
				mStickListHead->endStick();
			}
		}
		PRINT("done\n");
	}

	if (mRope) {
		endRope();
	}

	if (mRopeListHead) {
		while (mRopeListHead) {
			mRopeListHead->endRope();
		}
	}

	doKill();
	if (mSeContext) {
		mSeContext->releaseEvent();
	}

	radarInfo->detachParts(this);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x64(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  mr        r4, r31
	  bl        0x51480
	  li        r0, 0
	  stw       r0, 0x64(r31)

	.loc_0x48:
	  lwz       r30, 0x2AC(r31)
	  cmplwi    r30, 0
	  beq-      .loc_0xE8
	  lwz       r3, 0x2A8(r30)
	  addi      r29, r3, 0x2AC
	  lwz       r3, 0x2AC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  bl        0x59624
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x74:
	  lwz       r3, 0x2A8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  bl        0x5960C
	  li        r0, 0
	  stw       r0, 0x2A8(r30)

	.loc_0x8C:
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0xE
	  bne-      .loc_0xE8
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xE8
	  li        r0, 0xA
	  stw       r0, 0x2C(r1)
	  li        r0, 0x1
	  addi      r4, r30, 0
	  stw       r0, 0x30(r1)
	  addi      r5, r1, 0x2C
	  stw       r0, 0x2D0(r30)
	  lwz       r3, 0x2E8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0xE8:
	  lwz       r0, 0x3044(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  addi      r3, r31, 0x168
	  bl        0x1A6FC

	.loc_0xFC:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x110
	  cmpwi     r0, 0x36
	  bne-      .loc_0x118

	.loc_0x110:
	  addi      r3, r31, 0x40
	  bl        0x936C

	.loc_0x118:
	  addi      r3, r31, 0x1B8
	  bl        0x5905C
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x134
	  mr        r3, r31
	  bl        0x5BCC

	.loc_0x134:
	  lwz       r0, 0x180(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x178
	  b         .loc_0x16C

	.loc_0x144:
	  lwz       r4, 0xC8(r3)
	  rlwinm.   r0,r4,0,17,17
	  beq-      .loc_0x158
	  bl        0x5A48
	  b         .loc_0x16C

	.loc_0x158:
	  rlwinm.   r0,r4,0,16,16
	  beq-      .loc_0x168
	  bl        0x51DC
	  b         .loc_0x16C

	.loc_0x168:
	  bl        0x5B94

	.loc_0x16C:
	  lwz       r3, 0x180(r31)
	  cmplwi    r3, 0
	  bne+      .loc_0x144

	.loc_0x178:
	  lwz       r0, 0x158(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x18C
	  mr        r3, r31
	  bl        0x5D84

	.loc_0x18C:
	  lwz       r0, 0x154(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1AC
	  b         .loc_0x1A0

	.loc_0x19C:
	  bl        0x5D70

	.loc_0x1A0:
	  lwz       r3, 0x154(r31)
	  cmplwi    r3, 0
	  bne+      .loc_0x19C

	.loc_0x1AC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1D0
	  bl        0x190D4

	.loc_0x1D0:
	  lwz       r3, 0x2F28(r13)
	  mr        r4, r31
	  bl        -0xF7A4
	  lwz       r0, 0x4C(r1)
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
 * Address:	8008AED8
 * Size:	0002C0
 */
Creature::Creature(CreatureProp* props)
{
	mObjType       = OBJTYPE_INVALID;
	mSeContext     = nullptr;
	mCreatureFlags = 0;
	resetCreatureFlag(CF_Unk7);
	mCollInfo = nullptr;
	mFloorTri = nullptr;
	_30       = 0;

	disableFlag10000();
	setRebirthDay(0);

	mCollPlatNormal = nullptr;
	_288            = 0;
	mGenerator      = nullptr;

	mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_B0.set(0.0f, 0.0f, 0.0f);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	mRotation.set(0.0f, 0.0f, 0.0f);
	mPosition.set(0.0f, 0.0f, 0.0f);
	mScale.set(1.0f, 1.0f, 1.0f);

	mDirection       = 0.0f;
	_26C             = 10.0f;
	mCollisionRadius = 16.0f;
	mProps           = props;
	_28              = 0;
	resetCreatureFlag(CF_Unk10);

	_E0.fromEuler(Vector3f(0.0f, 0.0f, 0.0f));
	_D4.set(0.0f, 0.0f, 0.0f);

	resetCreatureFlag(CF_Unk1 | CF_Unk6);

	mHoldingCreature.clear();
	mGrabbedCreature.clear();

	mIsBeingDamaged = false;
	mCollPlatform   = nullptr;
	_290            = 0;
	_298            = 0;
	_2B0            = 0;
}

/*
 * --INFO--
 * Address:	8008B198
 * Size:	000070
 */
void Creature::updateStatic()
{
	if (mSeContext) {
		mSeContext->update();
	}
	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);
	doAnimation();
	updateAI();
}

/*
 * --INFO--
 * Address:	8008B208
 * Size:	000580
 */
void Creature::update()
{
	if (mSeContext) {
		mSeContext->update();
	}

	mGrid.updateGrid(mPosition);
	bool isPikiOrNavi = false;
	if (mObjType == OBJTYPE_Piki || mObjType == OBJTYPE_Navi) {
		isPikiOrNavi = true;
	}

	mGrid.updateAIGrid(mPosition, isPikiOrNavi);

	// in the DLL this ONE TIME doesn't use the isCreatureFlag inline
	// but it doesn't affect anything (for now) so i'm adding it in
	if (!isPikiOrNavi && !isCreatureFlag(CF_AIAlwaysActive) && mGrid.aiCulling() && !aiCullable()) {
		return;
	}
	_1A4 = 0;
	_1A8 = 0;

	if (!_2B0) {
		doAnimation();
		updateAI();
	}

	if (!mHoldingCreature.isNull()) {
		return;
	}

	if (isCreatureFlag(CF_StuckToMouth)) {
		if (mStickListHead) {
			mPosition = mStickListHead->mPosition;
		}
		if (!mStickTarget) {
			resetCreatureFlag(CF_StuckToMouth);
			PRINT("MOUTH RESET\n");
		}
		return;
	}

	if (mRope) {
		updateStickRope();
	}

	moveAttach();

	if (mStickTarget) {
		if (isStickToPlatform()) {
			updateStickPlatform();
		} else {
			updateStickNonPlatform();
		}
		return;
	}

	int attr = ATTR_NULL;
	if (mFloorTri) {
		attr = MapCode::getAttribute(mFloorTri);
	}

	if (attr == ATTR_Unk5) {
		if (_60 == 0) {
			startWaterEffect();
		}

		_60++;

		if (_60 > 240) {
			_60 = 240;
		}
	} else {
		if (_60 != 0) {
			_60 = 0;
			finishWaterEffect();
		}
	}

	if (isCreatureFlag(CF_Unk18)) {
		return;
	}

	f32 stepTime = gsys->getFrameTime();
	Vector3f vel(mVelocity);
	mVelocity = mVolatileVelocity;
	moveNew(stepTime);

	if (mVolatileVelocity.length() > 0.0f && isCreatureFlag(CF_Unk22) && isCreatureFlag(CF_FixPosition) && mFloorTri
	    && MapCode::getSlipCode(mFloorTri) == 0 && mFloorTri->_18.y > sinf(THIRD_PI)) {
		mFixedPosition = mPosition;
	}

	mVelocity = vel;
	moveNew(stepTime);

	if (isCreatureFlag(CF_Unk22)) {
		if (mFloorTri && MapCode::getSlipCode(mFloorTri) == 0 && mFloorTri->_18.y > sinf(THIRD_PI)) {
			if (mTargetVelocity.length() < 0.01f) {
				if (!isCreatureFlag(CF_FixPosition)) {
					setCreatureFlag(CF_FixPosition);
					mFixedPosition = mPosition;
				}
			} else {
				resetCreatureFlag(CF_FixPosition);
			}
		} else {
			resetCreatureFlag(CF_FixPosition);
		}

		if (isCreatureFlag(CF_FixPosition)) {
			Vector3f fixedDir = mFixedPosition - mPosition;
			f32 dist          = fixedDir.normalise();
			if (!(dist < 30.0f)) {
				dist = 0.0f;
			}
			if (dist > 0.0f) {
				vel       = (10.0f * dist) * fixedDir;
				mVelocity = vel;
			}
		}
	}

	mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	moveRotation(stepTime);
}

/*
 * --INFO--
 * Address:	8008B788
 * Size:	0001F4
 */
void Creature::postUpdate(int, f32 p2)
{
	bool isPikiOrNavi = false;
	if (mObjType == OBJTYPE_Piki || mObjType == OBJTYPE_Navi) {
		isPikiOrNavi = true;
	}

	if (!isPikiOrNavi && mGrid.aiCulling() && !aiCullable()) {
		return;
	}

	if (!mHoldingCreature.isNull()) {
		return;
	}

	collisionCheck(p2);

	if (mCollPlatform) {
		Creature* platCreature = mCollPlatform->mCreature;
		if (platCreature && platCreature->isAlive()) {
			CollPart* platPart = nullptr;
			if (platCreature->mCollInfo && platCreature->mCollInfo->hasInfo()) {
				platPart = platCreature->mCollInfo->getPlatform(mCollPlatform);
			}

			CollEvent event1(this, nullptr, platPart);
			CollEvent event2(platCreature, platPart, nullptr);

			if (platCreature->isAlive()) {
				platCreature->collisionCallback(event1);
			}
			if (isAlive()) {
				collisionCallback(event2);
			}
		}
	}

	_1AC = mPosition;

	if (getHoldCreature()) {
		Creature* held  = getHoldCreature();
		held->mPosition = getCatchPos(held);
		held->mRotation = mRotation;
	}
}

/*
 * --INFO--
 * Address:	8008B97C
 * Size:	0000B4
 */
void Creature::updateAI()
{
	if (!mHoldingCreature.isNull()) {
		return;
	}

	if (!mIsBeingDamaged && !isCreatureFlag(CF_IsAiDisabled) && doDoAI()) {
		doAI();
	}

	if (!isCreatureFlag(CF_Unk7) && !isCreatureFlag(CF_IsOnGround)) {
		return;
	}

	if (!isCreatureFlag(CF_Unk6) && !mIsBeingDamaged && !isCreatureFlag(CF_IsAiDisabled)) {
		moveVelocity();
	}
}

/*
 * --INFO--
 * Address:	8008BA30
 * Size:	0000F0
 */
f32 centreDist(Creature* c1, Creature* c2)
{
	Vector3f sep = c1->getCentre() - c2->getCentre();
	return sep.length();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
f32 sphereDistQuick(Creature* c1, Creature* c2)
{
	Vector3f c1Cent = c1->getCentre();
	Vector3f c2Cent = c2->getCentre();
	f32 dist        = qdist3(c1Cent.x, c1Cent.y, c1Cent.z, c2Cent.x, c2Cent.y, c2Cent.z);
	return dist - (c1->getCentreSize() + c2->getCentreSize());
}

/*
 * --INFO--
 * Address:	8008BB20
 * Size:	00011C
 */
f32 sphereDist(Creature* c1, Creature* c2)
{
	f32 dist = centreDist(c1, c2);
	return dist - (c1->getCentreSize() + c2->getCentreSize());
}

/*
 * --INFO--
 * Address:	8008BC3C
 * Size:	0006E8
 */
void Creature::collisionCheck(f32 p1)
{
	if (!isAlive()) {
		return;
	}

	if (!isAtari()) {
		return;
	}

	if (isCreatureFlag(CF_Unk6)) {
		return;
	}

	Iterator iter(&mSearchBuffer, &CndIsAtari());
	CI_LOOP(iter)
	{
		Creature* collider = *iter;

		// don't worry about dead creatures.
		if (!collider->isAlive()) {
			continue;
		}

		// ignore held creatures (such as bombs)
		if (isHolding() && getHoldCreature() == collider) {
			continue;
		}

		// ignore creatures holding us (such as if we're a bomb)
		if (isGrabbed() && getHolder() == collider) {
			continue;
		}

		if (!isGrabbed() && !collider->isGrabbed()) {
			CollInfo* ourInfo      = nullptr;
			CollInfo* colliderInfo = nullptr;
			Vector3f collisionVec;
			if (mCollInfo && mCollInfo->hasInfo()) {
				ourInfo = mCollInfo;
			}

			if (collider->mCollInfo && collider->mCollInfo->hasInfo()) {
				colliderInfo = collider->mCollInfo;
			}

			if (!ourInfo && !colliderInfo) {
				// neither of us have collision information. great. treat us both as spheres.
				if (centreDist(this, collider) < getSize() + collider->getSize()) {
					collisionVec = getCentre() - collider->getCentre();
					f32 dist     = collisionVec.normalise();
					collisionVec = -(getCentreSize() + collider->getCentreSize() - dist) * collisionVec;
					respondColl(collider, p1, nullptr, nullptr, collisionVec);
				}
				continue;
			}

			if (ourInfo && !colliderInfo) {
				// we have our collision, but not the incoming object's collision.
				CollPart* collisionPart = ourInfo->checkCollision(collider, collisionVec);
				if (collisionPart) {
					respondColl(collider, p1, collisionPart, nullptr, collisionVec);
				}
				continue;
			}

			if (!ourInfo && colliderInfo) {
				// we have the incoming object info, but none for us.
				CollPart* collisionPart = colliderInfo->checkCollision(this, collisionVec);
				if (collisionPart) {
					collisionVec.multiply(-1.0f);
					respondColl(collider, p1, nullptr, collisionPart, collisionVec);
				}
				continue;
			}
			u32 badCompiler; // there's an extra variable *somewhere* but idk where.

			// we have info for both of us, so pass it off to CollInfo to do the work
			CollPart* ourPart;
			CollPart* colliderPart;
			if (ourInfo->checkCollision(colliderInfo, &ourPart, &colliderPart, collisionVec)) {
				respondColl(collider, p1, ourPart, colliderPart, collisionVec);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8008C324
 * Size:	0000A0
 */
Vector3f Creature::getCatchPos(Creature* target)
{
	Vector3f catchPos;
	f32 rad = 0.95f * getSize();

	catchPos = Vector3f(rad * sinf(mDirection), 0.0f, rad * cosf(mDirection)) + mPosition;
	return catchPos;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7550(r2)
	  fmuls     f30, f0, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x18F7EC
	  fmuls     f31, f30, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x18F974
	  fmuls     f4, f30, f1
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x9C(r31)
	  lfs       f2, -0x5DAC(r13)
	  lfs       f1, 0x98(r31)
	  fadds     f0, f4, f0
	  fadds     f2, f2, f1
	  fadds     f1, f31, f3
	  stfs      f0, 0x0(r30)
	  stfs      f2, 0x4(r30)
	  stfs      f1, 0x8(r30)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008C3C4
 * Size:	000008
 */
bool Creature::needShadow()
{
	if (mObjType == OBJTYPE_Piki) {
		PRINT(" ????????? piki uses Creature::needShadow \n"); // lol
	}
	return true;
}

/*
 * --INFO--
 * Address:	8008C3CC
 * Size:	000040
 */
f32 Creature::getShadowSize() { return mScale.x * getSize(); }

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
void showTri(Graphics&, Vector3f&, CollTriInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008C40C
 * Size:	0002B4
 */
static void recTraceShadowTris(Graphics&, Vector3f&, CollTriInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x3
	  mtctr     r0
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  addi      r6, r1, 0x7C
	  stmw      r26, 0xB0(r1)
	  mr        r29, r5
	  addi      r28, r4, 0
	  mr        r27, r3
	  addi      r4, r29, 0
	  addi      r5, r1, 0x58
	  lfs       f1, -0x7558(r2)
	  lfs       f0, 0x2FF8(r13)
	  lfs       f2, -0x7584(r2)
	  fdivs     f0, f1, f0
	  lfs       f1, -0x754C(r2)
	  stfs      f2, 0x60(r1)
	  lfs       f3, -0x7548(r2)
	  stfs      f2, 0x5C(r1)
	  stfs      f2, 0x58(r1)
	  fmuls     f4, f1, f0
	  stfs      f2, 0x6C(r1)
	  stfs      f2, 0x68(r1)
	  stfs      f2, 0x64(r1)
	  stfs      f2, 0x78(r1)
	  stfs      f2, 0x74(r1)
	  stfs      f2, 0x70(r1)

	.loc_0x74:
	  lwz       r3, 0x2F00(r13)
	  lfs       f6, -0x5DA8(r13)
	  lfs       f0, 0x18(r29)
	  lwz       r3, 0x60(r3)
	  lwzu      r0, 0x4(r4)
	  fmuls     f0, f0, f6
	  lfs       f1, 0x1C(r29)
	  lfs       f2, 0x20(r29)
	  mulli     r0, r0, 0xC
	  lwz       r3, 0x23C(r3)
	  fmuls     f5, f1, f6
	  stfs      f0, 0x54(r1)
	  fmuls     f1, f2, f6
	  add       r3, r3, r0
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f5, 0xA4(r1)
	  stfs      f1, 0xA8(r1)
	  lfs       f1, 0xA0(r1)
	  lfs       f0, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x48(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0xA4(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0xA8(r1)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x8(r5)
	  lfs       f1, 0x0(r5)
	  lfs       f0, 0x0(r28)
	  lfs       f2, 0x8(r5)
	  addi      r5, r5, 0xC
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r28)
	  fsubs     f1, f2, f1
	  fmuls     f0, f4, f0
	  fmuls     f1, f4, f1
	  fadds     f0, f3, f0
	  fadds     f1, f3, f1
	  stfs      f0, 0x0(r6)
	  stfs      f1, 0x4(r6)
	  addi      r6, r6, 0x8
	  bdnz+     .loc_0x74
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r1, 0x58
	  addi      r6, r1, 0x7C
	  lwz       r12, 0xA0(r12)
	  li        r5, 0
	  li        r7, 0x3
	  mtlr      r12
	  blrl
	  lis       r3, 0x803D
	  lfs       f31, -0x7548(r2)
	  addi      r26, r3, 0x15F0
	  addi      r31, r29, 0
	  addi      r30, r29, 0
	  li        r29, 0

	.loc_0x184:
	  lfs       f3, 0x28(r31)
	  lfs       f2, 0x0(r28)
	  lfs       f1, 0x2C(r31)
	  lfs       f0, 0x4(r28)
	  fmuls     f3, f3, f2
	  lfs       f4, 0x30(r31)
	  fmuls     f2, f1, f0
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x34(r31)
	  fmuls     f4, f4, f0
	  lfs       f0, 0x2FF8(r13)
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x288
	  lha       r0, 0x12(r30)
	  cmpwi     r0, 0
	  blt-      .loc_0x288
	  lwz       r4, 0x2F00(r13)
	  mulli     r0, r0, 0x58
	  lwz       r3, 0x2FF4(r13)
	  lwz       r4, 0x60(r4)
	  addi      r6, r3, 0x18
	  lwz       r3, 0x16C(r4)
	  lfs       f3, 0x0(r6)
	  add       r5, r3, r0
	  lfs       f1, 0x4(r6)
	  lfs       f2, 0x18(r5)
	  lfs       f0, 0x1C(r5)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8(r6)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x20(r5)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x288
	  lwz       r4, 0x2FF0(r13)
	  addi      r3, r26, 0
	  li        r6, 0
	  cmpwi     r4, 0
	  mtctr     r4
	  ble-      .loc_0x254

	.loc_0x238:
	  lwz       r0, 0x0(r3)
	  cmplw     r0, r5
	  bne-      .loc_0x24C
	  li        r6, 0x1
	  b         .loc_0x254

	.loc_0x24C:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x238

	.loc_0x254:
	  rlwinm.   r0,r6,0,24,31
	  bne-      .loc_0x288
	  cmpwi     r4, 0x32
	  bge-      .loc_0x288
	  lwz       r7, 0x2FF0(r13)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  addi      r6, r7, 0x1
	  rlwinm    r0,r7,2,0,29
	  stw       r6, 0x2FF0(r13)
	  add       r6, r26, r0
	  stw       r5, 0x0(r6)
	  bl        .loc_0x0

	.loc_0x288:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r31, r31, 0x10
	  addi      r30, r30, 0x2
	  blt+      .loc_0x184
	  lmw       r26, 0xB0(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void calcShadowTris(Graphics&, Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008C6C0
 * Size:	0007BC
 */
void Creature::drawShadow(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x450(r1)
	  stfd      f31, 0x448(r1)
	  stfd      f30, 0x440(r1)
	  stfd      f29, 0x438(r1)
	  stfd      f28, 0x430(r1)
	  stfd      f27, 0x428(r1)
	  stfd      f26, 0x420(r1)
	  stfd      f25, 0x418(r1)
	  stfd      f24, 0x410(r1)
	  stw       r31, 0x40C(r1)
	  mr        r31, r4
	  stw       r30, 0x408(r1)
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x90(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x784
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x784
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x310
	  lwz       r12, 0x68(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x310(r1)
	  mr        r3, r30
	  lfs       f0, 0x314(r1)
	  stfs      f1, 0x3F0(r1)
	  stfs      f0, 0x3F4(r1)
	  lfs       f0, 0x318(r1)
	  stfs      f0, 0x3F8(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  fmr       f31, f1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x3F0(r1)
	  li        r4, 0x1
	  lfs       f2, 0x3F8(r1)
	  bl        -0x245A0
	  cmplwi    r3, 0
	  beq-      .loc_0x784
	  lfs       f7, 0x3F0(r1)
	  li        r5, 0x1
	  lfs       f1, 0x18(r3)
	  li        r4, 0
	  lfs       f6, 0x3F8(r1)
	  lfs       f0, 0x20(r3)
	  fmuls     f4, f7, f1
	  lfs       f2, 0x24(r3)
	  fmuls     f3, f6, f0
	  lfs       f1, 0x1C(r3)
	  lfs       f0, -0x7584(r2)
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2
	  fneg      f2, f2
	  fdivs     f5, f2, f1
	  b         .loc_0x140

	.loc_0x104:
	  lfs       f2, 0x28(r3)
	  lfs       f1, 0x2C(r3)
	  fmuls     f3, f2, f7
	  lfs       f4, 0x30(r3)
	  fmuls     f2, f1, f5
	  lfs       f1, 0x34(r3)
	  fmuls     f4, f4, f6
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x138
	  li        r5, 0

	.loc_0x138:
	  addi      r3, r3, 0x10
	  addi      r4, r4, 0x1

	.loc_0x140:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x150
	  cmpwi     r4, 0x3
	  blt+      .loc_0x104

	.loc_0x150:
	  lfs       f0, -0x7544(r2)
	  lfs       f1, 0x3F4(r1)
	  fsubs     f0, f5, f0
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x784
	  lfs       f0, -0x7540(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x714
	  lfs       f30, -0x7584(r2)
	  fsubs     f26, f1, f5
	  stfs      f7, 0x35C(r1)
	  stfs      f30, 0x370(r1)
	  stfs      f30, 0x36C(r1)
	  stfs      f30, 0x368(r1)
	  stfs      f30, 0x37C(r1)
	  stfs      f30, 0x378(r1)
	  stfs      f30, 0x374(r1)
	  stfs      f30, 0x388(r1)
	  stfs      f30, 0x384(r1)
	  stfs      f30, 0x380(r1)
	  stfs      f30, 0x394(r1)
	  stfs      f30, 0x390(r1)
	  stfs      f30, 0x38C(r1)
	  stfs      f30, 0x3A0(r1)
	  stfs      f30, 0x39C(r1)
	  stfs      f30, 0x398(r1)
	  stfs      f30, 0x3AC(r1)
	  stfs      f30, 0x3A8(r1)
	  stfs      f30, 0x3A4(r1)
	  stfs      f1, 0x360(r1)
	  stfs      f6, 0x364(r1)
	  lfs       f0, -0x753C(r2)
	  fadds     f0, f0, f5
	  stfs      f0, 0x360(r1)
	  lfs       f0, -0x7538(r2)
	  fcmpo     cr0, f26, f0
	  bge-      .loc_0x1F0
	  fdivs     f0, f26, f0
	  lfs       f1, -0x756C(r2)
	  fsubs     f30, f1, f0

	.loc_0x1F0:
	  lfs       f0, -0x7584(r2)
	  fcmpo     cr0, f30, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x784
	  lfs       f0, -0x7534(r2)
	  li        r0, 0xFF
	  stb       r0, 0x30C(r1)
	  addi      r4, r1, 0x30C
	  fmuls     f0, f0, f30
	  stb       r0, 0x30D(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  fctiwz    f0, f0
	  stb       r0, 0x30E(r1)
	  stfd      f0, 0x400(r1)
	  lwz       r0, 0x404(r1)
	  stb       r0, 0x30F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x340(r31)
	  lfs       f2, 0x3F4(r1)
	  lfs       f1, 0x33C(r31)
	  lfs       f0, 0x3F0(r1)
	  fsubs     f5, f3, f2
	  lfs       f8, -0x5DA0(r13)
	  fsubs     f6, f1, f0
	  lfs       f7, -0x5DA4(r13)
	  lfs       f3, 0x344(r31)
	  lfs       f0, 0x3F8(r1)
	  fmuls     f1, f5, f8
	  fmuls     f2, f6, f7
	  lfs       f9, -0x5D9C(r13)
	  fsubs     f4, f3, f0
	  lfs       f0, -0x7584(r2)
	  fadds     f1, f2, f1
	  fmuls     f2, f4, f9
	  fadds     f1, f2, f1
	  fmuls     f3, f1, f7
	  fmuls     f2, f1, f8
	  fmuls     f1, f1, f9
	  fsubs     f3, f3, f6
	  fsubs     f2, f2, f5
	  fsubs     f1, f1, f4
	  fneg      f29, f3
	  fneg      f28, f2
	  fneg      f27, f1
	  fmuls     f2, f29, f29
	  fmuls     f1, f28, f28
	  fmuls     f3, f27, f27
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x324
	  fsqrte    f2, f1
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x168(r1)
	  lfs       f0, 0x168(r1)

	.loc_0x324:
	  lfs       f0, -0x7584(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x38C
	  fsqrte    f2, f1
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x164(r1)
	  lfs       f3, 0x164(r1)
	  b         .loc_0x390

	.loc_0x38C:
	  fmr       f3, f1

	.loc_0x390:
	  lfs       f2, -0x7530(r2)
	  lfs       f0, -0x7558(r2)
	  fmuls     f2, f3, f2
	  fcmpo     cr0, f2, f0
	  fmr       f24, f2
	  ble-      .loc_0x3AC
	  fmr       f24, f0

	.loc_0x3AC:
	  lfs       f0, -0x7558(r2)
	  fcmpo     cr0, f26, f0
	  bge-      .loc_0x3C8
	  fdivs     f0, f26, f0
	  lfs       f2, -0x756C(r2)
	  fsubs     f0, f2, f0
	  b         .loc_0x3CC

	.loc_0x3C8:
	  lfs       f0, -0x7584(r2)

	.loc_0x3CC:
	  fmuls     f24, f24, f0
	  bl        -0x7EE50
	  lfs       f0, -0x7584(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x3EC
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1

	.loc_0x3EC:
	  lfs       f0, 0x35C(r1)
	  fneg      f11, f29
	  lfs       f2, -0x7558(r2)
	  fsubs     f0, f0, f29
	  lfs       f3, -0x756C(r2)
	  fdivs     f2, f24, f2
	  lfs       f9, -0x7548(r2)
	  stfs      f0, 0x35C(r1)
	  lfs       f10, -0x5D98(r13)
	  lfs       f0, 0x360(r1)
	  fsubs     f1, f3, f30
	  fsubs     f0, f0, f28
	  fmuls     f8, f9, f2
	  fadds     f1, f3, f1
	  stfs      f0, 0x360(r1)
	  fadds     f13, f3, f8
	  fmuls     f12, f31, f1
	  lfs       f0, 0x364(r1)
	  fsubs     f0, f0, f27
	  fmuls     f4, f27, f12
	  fmuls     f10, f10, f12
	  stfs      f0, 0x364(r1)
	  fmuls     f11, f11, f12
	  fneg      f25, f4
	  lwz       r0, 0x35C(r1)
	  fneg      f1, f11
	  stfs      f9, 0x3B0(r1)
	  fmuls     f6, f29, f12
	  stfs      f25, 0x210(r1)
	  fmuls     f5, f28, f12
	  stfs      f9, 0x3B4(r1)
	  fadds     f9, f12, f24
	  fmuls     f30, f10, f13
	  lfs       f2, 0x210(r1)
	  stw       r0, 0x368(r1)
	  lwz       r3, 0x360(r1)
	  fneg      f7, f10
	  fadds     f0, f1, f4
	  lwz       r0, 0x364(r1)
	  stw       r3, 0x36C(r1)
	  fmuls     f31, f4, f13
	  fadds     f1, f7, f5
	  fadds     f7, f2, f6
	  lfs       f2, -0x7584(r2)
	  stw       r0, 0x370(r1)
	  fmuls     f26, f11, f13
	  stfs      f7, 0x204(r1)
	  fmuls     f7, f27, f9
	  lfs       f12, 0x204(r1)
	  fmuls     f8, f28, f9
	  stfs      f2, 0x3B8(r1)
	  fneg      f24, f30
	  stfs      f2, 0x3BC(r1)
	  fmuls     f9, f29, f9
	  stfs      f12, 0x2C0(r1)
	  stfs      f1, 0x2C4(r1)
	  stfs      f0, 0x2C8(r1)
	  lfs       f13, 0x35C(r1)
	  lfs       f12, 0x2C0(r1)
	  fadds     f12, f13, f12
	  stfs      f12, 0x1F8(r1)
	  lfs       f12, 0x1F8(r1)
	  stfs      f12, 0x2CC(r1)
	  lfs       f12, 0x360(r1)
	  lfs       f13, 0x2C4(r1)
	  fadds     f13, f12, f13
	  stfs      f13, 0x2D0(r1)
	  lfs       f13, 0x364(r1)
	  lfs       f27, 0x2C8(r1)
	  fadds     f28, f13, f27
	  stfs      f31, 0x1F4(r1)
	  lfs       f27, 0x1F4(r1)
	  stfs      f28, 0x2D4(r1)
	  fneg      f27, f27
	  lwz       r0, 0x2CC(r1)
	  stfs      f2, 0x3C0(r1)
	  lwz       r3, 0x2D0(r1)
	  stw       r0, 0x374(r1)
	  lwz       r0, 0x2D4(r1)
	  stfs      f27, 0x1E8(r1)
	  stw       r3, 0x378(r1)
	  lfs       f27, 0x1E8(r1)
	  stw       r0, 0x37C(r1)
	  stfs      f3, 0x3C4(r1)
	  stfs      f27, 0x290(r1)
	  stfs      f24, 0x294(r1)
	  fneg      f24, f26
	  fadds     f10, f10, f5
	  fadds     f5, f11, f4
	  stfs      f24, 0x298(r1)
	  fsubs     f24, f26, f7
	  fsubs     f28, f31, f9
	  lfs       f11, 0x290(r1)
	  fsubs     f27, f30, f8
	  fsubs     f26, f11, f9
	  fadds     f11, f4, f6
	  fadds     f9, f12, f10
	  stfs      f26, 0x1DC(r1)
	  fadds     f4, f25, f6
	  fadds     f5, f13, f5
	  lfs       f10, 0x1DC(r1)
	  stfs      f10, 0x29C(r1)
	  lfs       f6, 0x294(r1)
	  fsubs     f6, f6, f8
	  stfs      f6, 0x2A0(r1)
	  lfs       f6, 0x298(r1)
	  fsubs     f6, f6, f7
	  stfs      f6, 0x2A4(r1)
	  lfs       f7, 0x35C(r1)
	  lfs       f6, 0x29C(r1)
	  fadds     f6, f7, f6
	  stfs      f6, 0x1D0(r1)
	  lfs       f6, 0x1D0(r1)
	  stfs      f6, 0x2A8(r1)
	  lfs       f6, 0x2A0(r1)
	  fadds     f6, f12, f6
	  stfs      f6, 0x2AC(r1)
	  lfs       f6, 0x2A4(r1)
	  fadds     f7, f13, f6
	  stfs      f28, 0x1B8(r1)
	  stfs      f3, 0x3C8(r1)
	  lfs       f6, 0x1B8(r1)
	  stfs      f7, 0x2B0(r1)
	  lwz       r0, 0x2A8(r1)
	  lwz       r3, 0x2AC(r1)
	  stw       r0, 0x380(r1)
	  lwz       r0, 0x2B0(r1)
	  stw       r3, 0x384(r1)
	  stw       r0, 0x388(r1)
	  stfs      f3, 0x3CC(r1)
	  stfs      f6, 0x26C(r1)
	  stfs      f27, 0x270(r1)
	  stfs      f24, 0x274(r1)
	  lfs       f8, 0x35C(r1)
	  lfs       f6, 0x26C(r1)
	  fadds     f6, f8, f6
	  stfs      f6, 0x1AC(r1)
	  lfs       f6, 0x1AC(r1)
	  stfs      f6, 0x278(r1)
	  lfs       f6, 0x270(r1)
	  fadds     f6, f12, f6
	  stfs      f6, 0x27C(r1)
	  lfs       f6, 0x274(r1)
	  fadds     f7, f13, f6
	  stfs      f11, 0x1A0(r1)
	  lfs       f6, 0x1A0(r1)
	  stfs      f7, 0x280(r1)
	  fadds     f6, f8, f6
	  lwz       r4, 0x278(r1)
	  lwz       r3, 0x27C(r1)
	  stfs      f6, 0x194(r1)
	  lwz       r0, 0x280(r1)
	  lfs       f6, 0x194(r1)
	  stw       r4, 0x38C(r1)
	  stfs      f6, 0x254(r1)
	  stfs      f9, 0x258(r1)
	  stfs      f5, 0x25C(r1)
	  stw       r3, 0x390(r1)
	  lwz       r4, 0x254(r1)
	  stw       r0, 0x394(r1)
	  lwz       r3, 0x258(r1)
	  stfs      f3, 0x3D0(r1)
	  lwz       r0, 0x25C(r1)
	  stfs      f2, 0x3D4(r1)
	  stw       r4, 0x398(r1)
	  stfs      f4, 0x17C(r1)
	  stw       r3, 0x39C(r1)
	  lfs       f3, 0x17C(r1)
	  stfs      f2, 0x3D8(r1)
	  stw       r0, 0x3A0(r1)
	  stfs      f2, 0x3DC(r1)
	  stfs      f3, 0x230(r1)
	  stfs      f1, 0x234(r1)
	  stfs      f0, 0x238(r1)
	  lfs       f1, 0x35C(r1)
	  mr        r3, r31
	  lfs       f0, 0x230(r1)
	  addi      r4, r1, 0x368
	  addi      r6, r1, 0x3B0
	  fadds     f0, f1, f0
	  li        r5, 0
	  li        r7, 0x6
	  stfs      f0, 0x170(r1)
	  lfs       f0, 0x170(r1)
	  stfs      f0, 0x23C(r1)
	  lfs       f0, 0x234(r1)
	  fadds     f0, f12, f0
	  stfs      f0, 0x240(r1)
	  lfs       f0, 0x238(r1)
	  fadds     f0, f13, f0
	  stfs      f0, 0x244(r1)
	  lwz       r0, 0x23C(r1)
	  lwz       r8, 0x240(r1)
	  stw       r0, 0x3A4(r1)
	  lwz       r0, 0x244(r1)
	  stw       r8, 0x3A8(r1)
	  stw       r0, 0x3AC(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x784

	.loc_0x714:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  fmr       f24, f1
	  stw       r0, 0x2FF0(r13)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x3F0(r1)
	  lfs       f2, 0x3F8(r1)
	  bl        -0x24C2C
	  mr.       r5, r3
	  beq-      .loc_0x784
	  lwz       r4, 0x2FF0(r13)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x15F0
	  stw       r5, 0x2FF4(r13)
	  addi      r6, r4, 0x1
	  rlwinm    r3,r4,2,0,29
	  stfs      f24, 0x2FF8(r13)
	  add       r4, r0, r3
	  stw       r6, 0x2FF0(r13)
	  mr        r3, r31
	  stw       r5, 0x0(r4)
	  addi      r4, r1, 0x3F0
	  bl        -0xA34

	.loc_0x784:
	  lwz       r0, 0x454(r1)
	  lfd       f31, 0x448(r1)
	  lfd       f30, 0x440(r1)
	  lfd       f29, 0x438(r1)
	  lfd       f28, 0x430(r1)
	  lfd       f27, 0x428(r1)
	  lfd       f26, 0x420(r1)
	  lfd       f25, 0x418(r1)
	  lfd       f24, 0x410(r1)
	  lwz       r31, 0x40C(r1)
	  lwz       r30, 0x408(r1)
	  addi      r1, r1, 0x450
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008CE7C
 * Size:	000094
 */
f32 qdist2(Creature* c1, Creature* c2)
{
	f32 xDiff = c1->mPosition.x - c2->mPosition.x;
	f32 zDiff = c1->mPosition.z - c2->mPosition.z;
	return std::sqrtf(SQUARE(xDiff) + SQUARE(zDiff));
}

/*
 * --INFO--
 * Address:	8008CF10
 * Size:	0000EC
 */
f32 circleDist(Creature* c1, Creature* c2)
{
	f32 dist = qdist2(c1->getCentre().x, c1->getCentre().z, c2->getCentre().x, c2->getCentre().z);
	return dist - c1->getCentreSize() - c2->getCentreSize();
}

/*
 * --INFO--
 * Address:	8008CFFC
 * Size:	000540
 */
void Creature::moveVelocity()
{
	u32 badCompiler[6]; // this is a placeholder, something else has to get tweaked for this to match

	Vector3f vel(mTargetVelocity);
	Vector3f vec(0.0f, 0.0f, 0.0f);

	if (mFloorTri) {
		Vector3f normal(mFloorTri->_18);
		f32 speed = vel.length();
		vel       = vel - vel.DP(normal) * normal;
		vel.normalise();
		vel = vel * speed;

		int slipCode = MapCode::getSlipCode(mFloorTri);
		if (slipCode == 0) {
			if (speed < 0.1f) {
				Vector3f tmp1(0.0f, -(AIConstant::_instance->mConstants._24() * gsys->getFrameTime()), 0.0f);
				tmp1 = tmp1 - (tmp1.DP(normal) * normal);
				vec  = -tmp1;
				vec  = vec * 1.0f;
			}
		} else {

			Vector3f tmp1(0.0f, -(AIConstant::_instance->mConstants._24() * gsys->getFrameTime()), 0.0f);
			tmp1 = tmp1 - (tmp1.DP(normal) * normal);
			tmp1.normalise();

			f32 factor;
			if (slipCode == 2) {
				factor = AIConstant::_instance->mConstants._144();
			} else {
				factor = AIConstant::_instance->mConstants._134();
			}

			if (mObjType == OBJTYPE_Navi) {
				PRINT("navi slip!\n");
			}

			vec = tmp1 * AIConstant::_instance->mConstants._24() * gsys->getFrameTime() * factor;
		}
	}

	Vector3f vec2;
	vec2 = vel + _B0 - mVelocity;
	vec2.length();

	mVelocity = mVelocity + vec2 * gsys->getFrameTime() / mProps->mCreatureProps.mAcceleration();
	mVelocity = mVelocity + vec;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x310(r1)
	  stfd      f31, 0x308(r1)
	  stfd      f30, 0x300(r1)
	  stfd      f29, 0x2F8(r1)
	  stfd      f28, 0x2F0(r1)
	  stfd      f27, 0x2E8(r1)
	  stfd      f26, 0x2E0(r1)
	  stfd      f25, 0x2D8(r1)
	  stfd      f24, 0x2D0(r1)
	  stfd      f23, 0x2C8(r1)
	  stfd      f22, 0x2C0(r1)
	  stw       r31, 0x2BC(r1)
	  mr        r31, r3
	  stw       r30, 0x2B8(r1)
	  lwz       r3, 0x28C(r3)
	  lfs       f30, -0x5D94(r13)
	  cmplwi    r3, 0
	  lfs       f23, 0xA4(r31)
	  lfs       f22, 0xA8(r31)
	  lfs       f31, 0xAC(r31)
	  lfs       f29, -0x5D90(r13)
	  lfs       f28, -0x5D8C(r13)
	  beq-      .loc_0x360
	  fmuls     f2, f23, f23
	  lfsu      f27, 0x18(r3)
	  fmuls     f1, f22, f22
	  lfs       f0, -0x7584(r2)
	  fmuls     f3, f31, f31
	  fadds     f1, f2, f1
	  lfs       f26, 0x4(r3)
	  lfs       f25, 0x8(r3)
	  fadds     f24, f3, f1
	  fcmpo     cr0, f24, f0
	  ble-      .loc_0xE8
	  fsqrte    f1, f24
	  lfd       f3, -0x7580(r2)
	  lfd       f2, -0x7578(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f24, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f24, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f24, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f24, f0
	  frsp      f0, f0
	  stfs      f0, 0x138(r1)
	  lfs       f24, 0x138(r1)

	.loc_0xE8:
	  fmuls     f1, f23, f27
	  addi      r6, r1, 0xF0
	  fmuls     f0, f22, f26
	  addi      r5, r1, 0xEC
	  fmuls     f2, f31, f25
	  fadds     f0, f1, f0
	  addi      r4, r1, 0xE8
	  addi      r3, r1, 0x250
	  fadds     f0, f2, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0xF0(r1)
	  stfs      f1, 0xEC(r1)
	  stfs      f0, 0xE8(r1)
	  bl        -0x56004
	  lfs       f0, 0x250(r1)
	  lfs       f1, 0x254(r1)
	  fsubs     f23, f23, f0
	  lfs       f0, 0x258(r1)
	  fsubs     f22, f22, f1
	  fsubs     f31, f31, f0
	  fmuls     f1, f23, f23
	  fmuls     f0, f22, f22
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7F510
	  lfs       f0, -0x7584(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x170
	  fdivs     f23, f23, f1
	  fdivs     f22, f22, f1
	  fdivs     f31, f31, f1

	.loc_0x170:
	  fmuls     f23, f23, f24
	  lwz       r3, 0x28C(r31)
	  fmuls     f22, f22, f24
	  fmuls     f31, f31, f24
	  bl        0x88F10
	  mr.       r30, r3
	  bne-      .loc_0x230
	  lfs       f0, -0x753C(r2)
	  fcmpo     cr0, f24, f0
	  bge-      .loc_0x360
	  lwz       r4, 0x2F80(r13)
	  addi      r6, r1, 0xE4
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0xE0
	  lfs       f1, 0x30(r4)
	  lfs       f0, 0x28C(r3)
	  addi      r4, r1, 0xDC
	  lfs       f28, -0x5D84(r13)
	  addi      r3, r1, 0x240
	  fmuls     f0, f1, f0
	  lfs       f24, -0x5D88(r13)
	  fmuls     f2, f28, f25
	  fneg      f30, f0
	  fmuls     f1, f24, f27
	  fmuls     f0, f30, f26
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0xE4(r1)
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  bl        -0x560D4
	  lfs       f2, 0x240(r1)
	  lfs       f1, 0x244(r1)
	  lfs       f0, 0x248(r1)
	  fsubs     f2, f24, f2
	  fsubs     f1, f30, f1
	  lfs       f3, -0x5D80(r13)
	  fsubs     f0, f28, f0
	  fneg      f2, f2
	  fneg      f1, f1
	  fneg      f0, f0
	  fmuls     f30, f2, f3
	  fmuls     f29, f1, f3
	  fmuls     f28, f0, f3
	  b         .loc_0x360

	.loc_0x230:
	  lwz       r4, 0x2F80(r13)
	  addi      r6, r1, 0xD8
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0xD4
	  lfs       f1, 0x30(r4)
	  lfs       f0, 0x28C(r3)
	  addi      r4, r1, 0xD0
	  lfs       f28, -0x5D78(r13)
	  addi      r3, r1, 0x230
	  fmuls     f0, f1, f0
	  lfs       f24, -0x5D7C(r13)
	  fmuls     f2, f28, f25
	  fneg      f30, f0
	  fmuls     f1, f24, f27
	  fmuls     f0, f30, f26
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0xD8(r1)
	  stfs      f1, 0xD4(r1)
	  stfs      f0, 0xD0(r1)
	  bl        -0x5616C
	  lfs       f0, 0x230(r1)
	  lfs       f1, 0x234(r1)
	  fsubs     f24, f24, f0
	  lfs       f0, 0x238(r1)
	  fsubs     f27, f30, f1
	  fsubs     f28, f28, f0
	  fmuls     f1, f24, f24
	  fmuls     f0, f27, f27
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7F678
	  lfs       f0, -0x7584(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2D8
	  fdivs     f24, f24, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x2D8:
	  cmpwi     r30, 0x2
	  bne-      .loc_0x2EC
	  lwz       r3, 0x2F80(r13)
	  lfs       f25, 0x150(r3)
	  b         .loc_0x2F4

	.loc_0x2EC:
	  lwz       r3, 0x2F80(r13)
	  lfs       f25, 0x140(r3)

	.loc_0x2F4:
	  lwz       r3, 0x2F80(r13)
	  addi      r6, r1, 0xC8
	  lwz       r7, 0x2DEC(r13)
	  addi      r5, r1, 0xC4
	  lfs       f0, 0x30(r3)
	  addi      r8, r3, 0x30
	  lfs       f26, 0x28C(r7)
	  fmuls     f0, f28, f0
	  addi      r4, r1, 0xC0
	  addi      r3, r1, 0x214
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0x0(r8)
	  fmuls     f0, f27, f0
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0x0(r8)
	  fmuls     f0, f24, f0
	  stfs      f0, 0xC0(r1)
	  bl        -0x56218
	  lfs       f2, 0x214(r1)
	  lfs       f1, 0x218(r1)
	  lfs       f0, 0x21C(r1)
	  fmuls     f2, f2, f26
	  fmuls     f1, f1, f26
	  fmuls     f0, f0, f26
	  fmuls     f30, f2, f25
	  fmuls     f29, f1, f25
	  fmuls     f28, f0, f25

	.loc_0x360:
	  lfs       f1, 0xB4(r31)
	  lfs       f0, 0xB0(r31)
	  fadds     f4, f22, f1
	  lfs       f5, 0xB8(r31)
	  lfs       f1, 0x74(r31)
	  fadds     f3, f23, f0
	  lfs       f2, 0x70(r31)
	  fsubs     f0, f4, f1
	  lfs       f4, 0x78(r31)
	  fadds     f5, f31, f5
	  lfs       f1, -0x7584(r2)
	  fsubs     f6, f3, f2
	  fsubs     f5, f5, f4
	  fmuls     f3, f6, f6
	  fmuls     f2, f0, f0
	  fmuls     f4, f5, f5
	  fadds     f2, f3, f2
	  fadds     f7, f4, f2
	  fcmpo     cr0, f7, f1
	  ble-      .loc_0x408
	  fsqrte    f2, f7
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f7, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f7, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f7, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f1, f7, f1
	  frsp      f1, f1
	  stfs      f1, 0x100(r1)
	  lfs       f1, 0x100(r1)

	.loc_0x408:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x224(r31)
	  lfs       f3, 0x28C(r3)
	  fmuls     f2, f6, f3
	  fmuls     f1, f0, f3
	  fmuls     f0, f5, f3
	  stfs      f2, 0x15C(r1)
	  lfs       f2, 0x15C(r1)
	  stfs      f2, 0x1E0(r1)
	  stfs      f1, 0x1E4(r1)
	  stfs      f0, 0x1E8(r1)
	  lfs       f2, -0x756C(r2)
	  lfs       f1, 0x40(r4)
	  lfs       f0, 0x1E0(r1)
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xF4(r1)
	  lfs       f0, 0xF4(r1)
	  stfs      f0, 0x1EC(r1)
	  lfs       f0, 0x1E4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x1E8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F4(r1)
	  lfs       f1, 0x70(r31)
	  lfs       f0, 0x1EC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x148(r1)
	  lfs       f0, 0x148(r1)
	  stfs      f0, 0x1F8(r1)
	  lfs       f1, 0x74(r31)
	  lfs       f0, 0x1F0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1FC(r1)
	  lfs       f1, 0x78(r31)
	  lfs       f0, 0x1F4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x200(r1)
	  lwz       r3, 0x1F8(r1)
	  lwz       r0, 0x1FC(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x200(r1)
	  stw       r0, 0x78(r31)
	  lfs       f0, 0x70(r31)
	  fadds     f0, f0, f30
	  stfs      f0, 0x13C(r1)
	  lfs       f0, 0x13C(r1)
	  stfs      f0, 0x1D0(r1)
	  lfs       f0, 0x74(r31)
	  fadds     f0, f0, f29
	  stfs      f0, 0x1D4(r1)
	  lfs       f0, 0x78(r31)
	  fadds     f0, f0, f28
	  stfs      f0, 0x1D8(r1)
	  lwz       r3, 0x1D0(r1)
	  lwz       r0, 0x1D4(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x1D8(r1)
	  stw       r0, 0x78(r31)
	  lwz       r0, 0x314(r1)
	  lfd       f31, 0x308(r1)
	  lfd       f30, 0x300(r1)
	  lfd       f29, 0x2F8(r1)
	  lfd       f28, 0x2F0(r1)
	  lfd       f27, 0x2E8(r1)
	  lfd       f26, 0x2E0(r1)
	  lfd       f25, 0x2D8(r1)
	  lfd       f24, 0x2D0(r1)
	  lfd       f23, 0x2C8(r1)
	  lfd       f22, 0x2C0(r1)
	  lwz       r31, 0x2BC(r1)
	  lwz       r30, 0x2B8(r1)
	  addi      r1, r1, 0x310
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008D53C
 * Size:	000008
 */
bool Creature::getAvoid(Vector3f&, Vector3f&) { return false; }

/*
 * --INFO--
 * Address:	8008D544
 * Size:	00034C
 */
void Creature::renderAtari(Graphics& gfx)
{
	u32 badCompiler[6]; // something needs adjusting.

	if (mObjType != OBJTYPE_Pellet) {
		Matrix4f mtx1;
		Matrix4f mtx2;

		mtx1.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), mPosition);
		gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
		gfx.setColour(Colour(0, 255, 0, 255), true);
		gfx.drawSphere(Vector3f(0.0f, -mGroundOffset, 0.0f), mCollisionRadius, mtx2);
		return;
	}

	if (static_cast<Pellet*>(this)->isRealDynamics()) {
		f32 halfHeight = 0.5f * getCylinderHeight();
		f32 pickOffs   = -static_cast<Pellet*>(this)->getPickOffset();

		Vector3f pos(0.0f, halfHeight, 0.0f);
		Matrix4f mtx;
		mtx.makeVQS(Vector3f(0.0f, 0.0f, 0.0f), _E0, Vector3f(1.0f, 1.0f, 1.0f));
		pos.multMatrix(mtx);
		pos = pos + mPosition;

		Matrix4f mtx2;
		Matrix4f mtx3;

		mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), pos);
		gfx.mCamera->mLookAtMtx.multiplyTo(mtx2, mtx3);

		gfx.setColour(Colour(255, 0, 0, 255), true);
		gfx.drawSphere(Vector3f(0.0f, 0.0f, 0.0f), halfHeight + pickOffs, mtx3);
		return;
	}

	// pellet but not a ufo part
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx1.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), mPosition);
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
	gfx.setColour(Colour(0, 255, 0, 255), true);
	gfx.drawSphere(Vector3f(0.0f, -mGroundOffset, 0.0f), mCollisionRadius, mtx2);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2A8(r1)
	  stfd      f31, 0x2A0(r1)
	  stfd      f30, 0x298(r1)
	  stw       r31, 0x294(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x290(r1)
	  mr        r30, r3
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x34
	  beq-      .loc_0xF0
	  lfs       f1, -0x5D68(r13)
	  addi      r5, r1, 0xA0
	  lfs       f0, -0x5D74(r13)
	  addi      r4, r1, 0xAC
	  stfs      f1, 0xA0(r1)
	  lfs       f1, -0x5D64(r13)
	  addi      r3, r1, 0x250
	  stfs      f0, 0xAC(r1)
	  addi      r6, r30, 0x94
	  lfs       f0, -0x5D70(r13)
	  stfs      f1, 0xA4(r1)
	  lfs       f1, -0x5D60(r13)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, -0x5D6C(r13)
	  stfs      f1, 0xA8(r1)
	  stfs      f0, 0xB4(r1)
	  bl        -0x4F4C0
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0x250
	  addi      r5, r1, 0x210
	  addi      r3, r3, 0x1E0
	  bl        -0x4F4F4
	  li        r5, 0
	  stb       r5, 0x9C(r1)
	  li        r0, 0xFF
	  addi      r4, r1, 0x9C
	  stb       r0, 0x9D(r1)
	  mr        r3, r31
	  stb       r5, 0x9E(r1)
	  li        r5, 0x1
	  stb       r0, 0x9F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xD0(r30)
	  addi      r4, r1, 0x90
	  lfs       f0, -0x5D5C(r13)
	  mr        r3, r31
	  fneg      f1, f1
	  stfs      f0, 0x90(r1)
	  addi      r5, r1, 0x210
	  lfs       f0, -0x5D58(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x270(r30)
	  bl        -0x641BC
	  b         .loc_0x32C

	.loc_0xF0:
	  lbz       r0, 0x43C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x270
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7548(r2)
	  addi      r6, r1, 0x74
	  lfs       f3, 0x2D0(r30)
	  addi      r4, r1, 0x80
	  lfs       f2, -0x5D54(r13)
	  fmuls     f31, f0, f1
	  addi      r3, r1, 0x1C4
	  stfs      f2, 0x204(r1)
	  fneg      f30, f3
	  addi      r5, r30, 0xE0
	  stfs      f31, 0x208(r1)
	  lfs       f0, -0x5D50(r13)
	  stfs      f0, 0x20C(r1)
	  lfs       f1, -0x5D40(r13)
	  lfs       f0, -0x5D4C(r13)
	  stfs      f1, 0x74(r1)
	  lfs       f1, -0x5D3C(r13)
	  stfs      f0, 0x80(r1)
	  lfs       f0, -0x5D48(r13)
	  stfs      f1, 0x78(r1)
	  lfs       f1, -0x5D38(r13)
	  stfs      f0, 0x84(r1)
	  lfs       f0, -0x5D44(r13)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x88(r1)
	  bl        -0x4E9B4
	  addi      r3, r1, 0x204
	  addi      r4, r1, 0x1C4
	  bl        -0x55F78
	  lfs       f1, 0x204(r1)
	  addi      r5, r1, 0x5C
	  lfs       f0, 0x94(r30)
	  addi      r4, r1, 0x68
	  lfs       f3, 0x208(r1)
	  lfs       f2, 0x98(r30)
	  fadds     f0, f1, f0
	  lfs       f4, 0x20C(r1)
	  addi      r3, r1, 0x178
	  lfs       f1, 0x9C(r30)
	  fadds     f2, f3, f2
	  stfs      f0, 0x204(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x204
	  stfs      f2, 0x208(r1)
	  stfs      f0, 0x20C(r1)
	  lfs       f1, -0x5D28(r13)
	  lfs       f0, -0x5D34(r13)
	  stfs      f1, 0x5C(r1)
	  lfs       f1, -0x5D24(r13)
	  stfs      f0, 0x68(r1)
	  lfs       f0, -0x5D30(r13)
	  stfs      f1, 0x60(r1)
	  lfs       f1, -0x5D20(r13)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, -0x5D2C(r13)
	  stfs      f1, 0x64(r1)
	  stfs      f0, 0x70(r1)
	  bl        -0x4F644
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0x178
	  addi      r5, r1, 0x138
	  addi      r3, r3, 0x1E0
	  bl        -0x4F678
	  li        r6, 0xFF
	  stb       r6, 0x58(r1)
	  li        r0, 0
	  addi      r4, r1, 0x58
	  stb       r0, 0x59(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r0, 0x5A(r1)
	  stb       r6, 0x5B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x5D1C(r13)
	  fadds     f1, f31, f30
	  lfs       f2, -0x5D18(r13)
	  addi      r4, r1, 0x4C
	  stfs      f0, 0x4C(r1)
	  lfs       f0, -0x5D14(r13)
	  stfs      f2, 0x50(r1)
	  mr        r3, r31
	  addi      r5, r1, 0x138
	  stfs      f0, 0x54(r1)
	  bl        -0x6433C
	  b         .loc_0x32C

	.loc_0x270:
	  lfs       f1, -0x5D04(r13)
	  addi      r5, r1, 0x34
	  lfs       f0, -0x5D10(r13)
	  addi      r4, r1, 0x40
	  stfs      f1, 0x34(r1)
	  lfs       f1, -0x5D00(r13)
	  addi      r3, r1, 0xF8
	  stfs      f0, 0x40(r1)
	  addi      r6, r30, 0x94
	  lfs       f0, -0x5D0C(r13)
	  stfs      f1, 0x38(r1)
	  lfs       f1, -0x5CFC(r13)
	  stfs      f0, 0x44(r1)
	  lfs       f0, -0x5D08(r13)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x48(r1)
	  bl        -0x4F700
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0xF8
	  addi      r5, r1, 0xB8
	  addi      r3, r3, 0x1E0
	  bl        -0x4F734
	  li        r5, 0
	  stb       r5, 0x30(r1)
	  li        r0, 0xFF
	  addi      r4, r1, 0x30
	  stb       r0, 0x31(r1)
	  mr        r3, r31
	  stb       r5, 0x32(r1)
	  li        r5, 0x1
	  stb       r0, 0x33(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xD0(r30)
	  addi      r4, r1, 0x24
	  lfs       f0, -0x5CF8(r13)
	  mr        r3, r31
	  fneg      f1, f1
	  stfs      f0, 0x24(r1)
	  addi      r5, r1, 0xB8
	  lfs       f0, -0x5CF4(r13)
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f1, 0x270(r30)
	  bl        -0x643FC

	.loc_0x32C:
	  lwz       r0, 0x2AC(r1)
	  lfd       f31, 0x2A0(r1)
	  lfd       f30, 0x298(r1)
	  lwz       r31, 0x294(r1)
	  lwz       r30, 0x290(r1)
	  addi      r1, r1, 0x2A8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008D890
 * Size:	000054
 */
bool roughCull(Creature* p1, Creature* p2, f32 p3)
{
	if (AIPerf::useGrid && AIPerf::iteratorCull && p1->roughCulling(p2, p3)) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8008D8E4
 * Size:	000070
 */
void Creature::stickUpdate()
{
	if (mRope) {
		updateStickRope();
		return;
	}

	if (mStickTarget) {
		if (isStickToPlatform()) {
			updateStickPlatform();
		} else {
			updateStickNonPlatform();
		}
	}
}
