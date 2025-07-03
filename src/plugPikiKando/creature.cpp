#include "Creature.h"
#include "SearchSystem.h"
#include "Collision.h"
#include "DynColl.h"
#include "Geometry.h"
#include "SoundMgr.h"
#include "Graphics.h"
#include "AIConstant.h"
#include "CreatureProp.h"
#include "MapMgr.h"
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
DEFINE_ERROR(32)

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
	setCreatureFlag(CF_IsPositionFixed);
}

/*
 * --INFO--
 * Address:	8008A040
 * Size:	000010
 */
void Creature::finishFixPosition()
{
	resetCreatureFlag(CF_IsPositionFixed);
}

/*
 * --INFO--
 * Address:	8008A050
 * Size:	000048
 */
bool Creature::isTerrible()
{
	return isTeki() || isBoss();
}

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
	if (!mGroundTriangle) {
		if (mCollPlatform) {
			if (mCollPlatform->mCreature) {
				// standing on a platform creature?
				return STANDTYPE_TekiPlatform;
			}

			// standing on a platform with no creature?
			return STANDTYPE_Platform;
		}

		// no platform
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

	// no platform
	return STANDTYPE_Ground;
}

/*
 * --INFO--
 * Address:	8008A7F8
 * Size:	00005C
 */
SearchData::SearchData()
{
	mSearchIteration = 0;
	mTargetCreature.reset();
	mDistance = 12800.0f;
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
	mPreGrabRotation = mRotationQuat;
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
void Creature::turnTo(Vector3f& targetDir)
{
	mFaceDirection = atan2f(targetDir.x - mPosition.x, targetDir.z - mPosition.z);
}

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
	mConstrainedMoveMtx.makeIdentity();
	mWorldMtx.makeIdentity();
	mRotationQuat.set(0.0f, 0.0f, 0.0f, 1.0f);
	mWaterFxTimer    = 0;
	mCreatureFlags   = 0;
	mPelletStickSlot = -1;
	disableAICulling();
	mFormMgr = nullptr;
	setCreatureFlag(CF_Free);
	resetCreatureFlag(CF_GroundOffsetEnabled | CF_IsAiDisabled | CF_IsClimbing | CF_AIAlwaysActive);
	mGroundOffset = 0.0f;
	mHoldingCreature.clear();
	mGrabbedCreature.clear();
	resetCreatureFlag(CF_Unk6 | CF_Unk17);
	clearCnt();
	mIsBeingDamaged = false;

	setCreatureFlag(CF_IsOnGround | CF_Unk4);
	resetCreatureFlag(CF_Unk5 | CF_IsFlying | CF_Unk8 | CF_Unk11);
	mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	mLastPosition.set(0.0f, 0.0f, 0.0f);
	mStickTarget = nullptr;
	mStickPart   = nullptr;

	mPrevSticker   = nullptr;
	mNextSticker   = nullptr;
	mStickListHead = nullptr;
	resetCreatureFlag(CF_StuckToObject | CF_StuckToMouth);

	mRopeListHead   = nullptr;
	mRope           = nullptr;
	mRopePosRatio   = 0.0f;
	mPrevRopeHolder = nullptr;
	mNextRopeHolder = nullptr;
	if (searchUpdateMgr) {
		if (isPiki()) {
			mSearchContext.setPiki(true);
		}

		mSearchContext.init(searchUpdateMgr);
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
	mHasCollChangedVelocity = 0;
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
	mPosition     = pos;
	mLastPosition = pos;
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
		Creature* held = getHoldCreature();
		held->resetStateGrabbed();
		if (held->mObjType == OBJTYPE_Bomb) {
			AICreature* ai = static_cast<AICreature*>(held);
			if (ai->getCurrState()->getID() != 1) {
				BombItem* bomb = static_cast<BombItem*>(held);
				MsgUser msg(1);
				bomb->mCurrAnimId = 1;
				static_cast<SimpleAI*>(bomb->mStateMachine)->procMsg(bomb, &msg);
			}
		}
	}

	if (searchUpdateMgr) {
		mSearchContext.exit();
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
	resetCreatureFlag(CF_IsFlying);
	mCollInfo       = nullptr;
	mGroundTriangle = nullptr;
	_30             = 0;

	disableFaceDirAdjust();
	setRebirthDay(0);

	mCollPlatNormal = nullptr;
	mClimbingTri    = 0;
	mGenerator      = nullptr;

	mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_B0.set(0.0f, 0.0f, 0.0f);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	mRotation.set(0.0f, 0.0f, 0.0f);
	mPosition.set(0.0f, 0.0f, 0.0f);
	mScale.set(1.0f, 1.0f, 1.0f);

	mFaceDirection   = 0.0f;
	mSize            = 10.0f;
	mCollisionRadius = 16.0f;
	mProps           = props;
	mFormPoint       = nullptr;
	resetCreatureFlag(CF_Unk10);

	mRotationQuat.fromEuler(Vector3f(0.0f, 0.0f, 0.0f));
	mPrevAngularVelocity.set(0.0f, 0.0f, 0.0f);

	resetCreatureFlag(CF_Unk1 | CF_Unk6);

	mHoldingCreature.clear();
	mGrabbedCreature.clear();

	mIsBeingDamaged   = false;
	mCollPlatform     = nullptr;
	mPreviousTriangle = 0;
	_298              = 0;
	mIsFrozen         = 0;
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
	// Update sound effects
	if (mSeContext) {
		mSeContext->update();
	}

	// Update spatial grid positions
	mGrid.updateGrid(mPosition);
	bool isPikiOrNavi = false;
	if (mObjType == OBJTYPE_Piki || mObjType == OBJTYPE_Navi) {
		isPikiOrNavi = true;
	}
	mGrid.updateAIGrid(mPosition, isPikiOrNavi);

	// Skip AI updates for non-important and CULLED objects
	if (!isPikiOrNavi && !isCreatureFlag(CF_AIAlwaysActive) && mGrid.aiCulling() && !aiCullable()) {
		return;
	}

	mHasCollChangedVelocity = 0;
	mCollisionOccurred      = 0;

	// Handle AI and animations if not frozen
	if (!mIsFrozen) {
		doAnimation();
		updateAI();
	}

	// Skip remaining updates if holding something
	if (!mHoldingCreature.isNull()) {
		return;
	}

	// Handle being stuck to another creature's mouth
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

	// Update rope physics if attached to one
	if (mRope) {
		updateStickRope();
	}

	moveAttach();

	// Handle different types of sticking behaviour
	if (mStickTarget) {
		if (isStickToPlatform()) {
			updateStickPlatform();
		} else {
			updateStickNonPlatform();
		}

		return;
	}

	// Handle effects if we're on the floor
	int terrainAttribute = ATTR_NULL;
	if (mGroundTriangle) {
		terrainAttribute = MapCode::getAttribute(mGroundTriangle);
	}

	// Handle water effects if walking in water
	if (terrainAttribute == ATTR_Water) {
		if (mWaterFxTimer == 0) {
			startWaterEffect();
		}

		mWaterFxTimer++;

		if (mWaterFxTimer > 240) {
			mWaterFxTimer = 240;
		}
	} else if (mWaterFxTimer != 0) {
		// When leaving the water, reset the water effect
		mWaterFxTimer = 0;
		finishWaterEffect();
	}

	if (isCreatureFlag(CF_DisableMovement)) {
		return;
	}

	// Apply movement in two passes - volatile (temporary) and normal velocity
	f32 deltaTime = gsys->getFrameTime();
	Vector3f originalVel(mVelocity);
	mVelocity = mVolatileVelocity;
	moveNew(deltaTime);

	// Handle fixed position on non-slippery surfaces, with a slope < 60 degrees
	if (mVolatileVelocity.length() > 0.0f && isCreatureFlag(CF_AllowFixPosition) && isCreatureFlag(CF_IsPositionFixed) && mGroundTriangle
	    && MapCode::getSlipCode(mGroundTriangle) == 0 && mGroundTriangle->mTriangle.mNormal.y > sinf(THIRD_PI)) {
		mFixedPosition = mPosition;
	}

	mVelocity = originalVel;
	moveNew(deltaTime);

	// Update the fixed position status
	if (isCreatureFlag(CF_AllowFixPosition)) {
		// If we're on the ground, it's not slippery, and the slope is < 60 degrees
		if (mGroundTriangle && MapCode::getSlipCode(mGroundTriangle) == 0 && mGroundTriangle->mTriangle.mNormal.y > sinf(THIRD_PI)) {

			// If we're barely moving, just stay still
			if (mTargetVelocity.length() < 0.01f) {
				if (!isCreatureFlag(CF_IsPositionFixed)) {
					setCreatureFlag(CF_IsPositionFixed);
					mFixedPosition = mPosition;
				}

			} else {
				// We're moving too fast to stay fixed
				resetCreatureFlag(CF_IsPositionFixed);
			}

		} else {
			// Not on stable ground, so don't fix position (either slope or slippery triangle)
			resetCreatureFlag(CF_IsPositionFixed);
		}

		// Pull creature back to fixed position if drifted
		if (isCreatureFlag(CF_IsPositionFixed)) {
			Vector3f pullDir = mFixedPosition - mPosition;
			f32 driftDist    = pullDir.normalise();

			// Only apply pull force if within 30 units
			if (!(driftDist < 30.0f)) {
				driftDist = 0.0f;
			}

			// Apply spring-like force back to fixed point
			if (driftDist > 0.0f) {
				// Stronger pull when further away
				originalVel = (10.0f * driftDist) * pullDir;

				mVelocity = originalVel;
			}
		}
	}

	mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	moveRotation(deltaTime);
}

/*
 * --INFO--
 * Address:	8008B788
 * Size:	0001F4
 */
void Creature::postUpdate(int, f32 _unused)
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

	collisionCheck(_unused);

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

	mLastPosition = mPosition;

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

	if (!isCreatureFlag(CF_IsFlying) && !isCreatureFlag(CF_IsOnGround)) {
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
void Creature::collisionCheck(f32 _unused)
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
					respondColl(collider, _unused, nullptr, nullptr, collisionVec);
				}
				continue;
			}

			if (ourInfo && !colliderInfo) {
				// we have our collision, but not the incoming object's collision.
				CollPart* collisionPart = ourInfo->checkCollision(collider, collisionVec);
				if (collisionPart) {
					respondColl(collider, _unused, collisionPart, nullptr, collisionVec);
				}
				continue;
			}

			if (!ourInfo && colliderInfo) {
				// we have the incoming object info, but none for us.
				CollPart* collisionPart = colliderInfo->checkCollision(this, collisionVec);
				if (collisionPart) {
					collisionVec.multiply(-1.0f);
					respondColl(collider, _unused, nullptr, collisionPart, collisionVec);
				}
				continue;
			}
			STACK_PAD_VAR(1); // there's an extra variable *somewhere* but idk where.

			// we have info for both of us, so pass it off to CollInfo to do the work
			CollPart* ourPart;
			CollPart* colliderPart;
			if (ourInfo->checkCollision(colliderInfo, &ourPart, &colliderPart, collisionVec)) {
				respondColl(collider, _unused, ourPart, colliderPart, collisionVec);
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
	f32 rad = 0.95f * getSize();

	Vector3f v(rad * sinf(mFaceDirection), 0.0f, rad * cosf(mFaceDirection));
	v = v + mPosition;
	return v;
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
f32 Creature::getShadowSize()
{
	return mScale.x * getSize();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
void showTri(Graphics& gfx, Vector3f& vec, CollTriInfo* tri)
{
	Vector3f tmpV3[3];
	Vector2f tmpV2[3];

	f32 val = (30.0f / checkRadius) * (1.0f / 64.0f);
	for (int i = 0; i < 3; i++) {
		tmpV3[i] = tri->mTriangle.mNormal * 0.1f + mapMgr->mMapShape->mVertexList[tri->mVertexIndices[i]];
		tmpV2[i].set((tmpV3[i].x - vec.x) * val + 0.5f, (tmpV3[i].z - vec.z) * val + 0.5f);
	}

	gfx.drawOneTri(tmpV3, nullptr, tmpV2, 3);
}

/*
 * --INFO--
 * Address:	8008C40C
 * Size:	0002B4
 */
static void recTraceShadowTris(Graphics& gfx, Vector3f& vec, CollTriInfo* tri)
{
	showTri(gfx, vec, tri);

	for (int i = 0; i < 3; i++) {
		if (tri->mEdgePlanes[i].dist(vec) < checkRadius) {
			int idx = tri->mAdjacentTriIndices[i];
			if (idx < 0) {
				continue;
			}

			CollTriInfo* currTri = &mapMgr->mMapShape->mTriList[idx];
			if (baseTri->mTriangle.mNormal.DP(currTri->mTriangle.mNormal) > 0.5f) {
				bool check = false;
				for (int j = 0; j < numTris; j++) {
					if (triList[j] == currTri) {
						check = true;
						break;
					}
				}
				if (!check && numTris < 50) {
					triList[numTris++] = currTri;
					recTraceShadowTris(gfx, vec, currTri);
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void calcShadowTris(Graphics& gfx, Vector3f& vec, f32 rad)
{
	numTris          = 0;
	CollTriInfo* tri = mapMgr->getCurrTri(vec.x, vec.z, true);
	if (tri) {
		baseTri            = tri;
		checkRadius        = rad;
		triList[numTris++] = tri;
		recTraceShadowTris(gfx, vec, tri);
	}
}

/*
 * --INFO--
 * Address:	8008C6C0
 * Size:	0007BC
 */
void Creature::drawShadow(Graphics& gfx)
{
	if (!needShadow()) {
		return;
	}

	if (!aiCullable()) {
		return;
	}

	Vector3f shadowPos = getShadowPos();
	f32 size           = getShadowSize();
	CollTriInfo* tri   = mapMgr->getCurrTri(shadowPos.x, shadowPos.z, true);
	if (!tri) {
		return;
	}

	Vector3f clampedPos(shadowPos.x, 0.0f, shadowPos.z);
	tri->inTriClampTo(clampedPos);

	f32 y = clampedPos.y;
	if (shadowPos.y < clampedPos.y - 5.0f) {
		return;
	}

	if (size < 20.0f) {
		Vector2f tmpV2[6];
		Vector3f tmpV3[6];

		Vector3f pos(shadowPos);
		pos.y     = y + 0.1f;
		f32 yDiff = shadowPos.y - y;
		f32 alpha = (yDiff < 200.0f) ? 1.0f - yDiff / 200.0f : 0.0f;

		if (alpha <= 0.0f) {
			return;
		}

		gfx.setColour(Colour(255, 255, 255, u8(255.0f * alpha)), true);

		Vector3f diff1 = gfx.mSunPosition - shadowPos;
		f32 diff1Y     = diff1.y;
		diff1.project(Vector3f(0.0f, 1.0f, 0.0f));
		f32 yRatio    = diff1.length() / diff1Y;
		f32 diff1Dist = diff1.length() / 4.0f;
		if (diff1Dist > 30.0f) {
			diff1Dist = 30.0f;
		}

		diff1Dist *= (yDiff < 30.0f) ? 1.0f - yDiff / 30.0f : 0.0f;
		diff1.normalise();

		f32 factor1   = diff1Dist / 30.0f * 0.5f + 1.0f;
		f32 factor2   = size * (1.0f - alpha + 1.0f);
		Vector3f vec1 = diff1 * factor2;
		Vector3f vec2 = diff1 * (factor2 + diff1Dist);
		Vector3f vec3(diff1.z, 0.0f, -diff1.x);
		vec3.multiply(factor2);
		pos.sub(diff1);

		tmpV2[0].set(0.5f, 0.5f);
		tmpV3[0] = pos;

		tmpV2[1].set(0.0f, 0.0f);
		tmpV3[1] = pos + (-vec3 + vec1);

		tmpV2[2].set(0.0f, 1.0f);
		tmpV3[2] = pos + (-(vec3 * factor1) - vec2);

		tmpV2[3].set(1.0f, 1.0f);
		tmpV3[3] = pos + (vec3 * factor1 - vec2);

		tmpV2[4].set(1.0f, 0.0f);
		tmpV3[4] = pos + (vec3 + vec1);

		tmpV2[5].set(0.0f, 0.0f);
		tmpV3[5] = pos + (-vec3 + vec1);

		gfx.drawOneTri(tmpV3, nullptr, tmpV2, 6);
		STACK_PAD_VAR(1);
		return;
	}

	calcShadowTris(gfx, shadowPos, getShadowSize());
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
	Vector3f vel(mTargetVelocity);
	Vector3f vec(0.0f, 0.0f, 0.0f);
	f32 y       = mVelocity.y;
	bool unused = false;
	if (mGroundTriangle) {
		Vector3f normal(mGroundTriangle->mTriangle.mNormal);
		f32 speed = vel.length();
		vel       = vel - vel.DP(normal) * normal;
		vel.normalise();
		vel = vel * speed;

		int slipCode = MapCode::getSlipCode(mGroundTriangle);
		if (slipCode == 0) {
			if (speed < 0.1f) {
				Vector3f tmp1(0.0f, -(AIConstant::_instance->mConstants.mGravity() * gsys->getFrameTime()), 0.0f);
				tmp1   = tmp1 - tmp1.DP(normal) * normal;
				vec    = -tmp1;
				vec    = vec * 1.0f;
				unused = true;
			}
		} else {

			Vector3f tmp1(0.0f, -(AIConstant::_instance->mConstants.mGravity() * gsys->getFrameTime()), 0.0f);
			tmp1 = tmp1 - tmp1.DP(normal) * normal;
			tmp1.normalise();

			f32 factor;
			if (slipCode == 2) {
				factor = AIConstant::_instance->mConstants.mStrongSlipFactor();
			} else {
				factor = AIConstant::_instance->mConstants.mWeakSlipFactor();
			}

			if (mObjType == OBJTYPE_Navi) {
				PRINT("navi slip!\n");
			}

			vec    = tmp1 * AIConstant::_instance->mConstants.mGravity() * gsys->getFrameTime() * factor;
			unused = true;
		}
	}

	Vector3f vec2;
	vec2  = vel + _B0 - mVelocity;
	f32 d = vec2.length();

	mVelocity = mVelocity + vec2 * gsys->getFrameTime() / mProps->mCreatureProps.mAcceleration();
	mVelocity = mVelocity + vec;
}

/*
 * --INFO--
 * Address:	8008D53C
 * Size:	000008
 */
bool Creature::getAvoid(Vector3f&, Vector3f&)
{
	return false;
}

/*
 * --INFO--
 * Address:	8008D544
 * Size:	00034C
 */
void Creature::renderAtari(Graphics& gfx)
{
	if (mObjType != OBJTYPE_Pellet) {
		Matrix4f mtx1;
		Matrix4f mtx2;

		mtx1.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), mPosition);
		gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
		gfx.setColour(Colour(0, 255, 0, 255), true);
		gfx.drawSphere(Vector3f(0.0f, -mGroundOffset, 0.0f), mCollisionRadius, mtx2);
		return;
	}

	Pellet* pel = static_cast<Pellet*>(this);
	if (pel->isRealDynamics()) {
		f32 h        = pel->getCylinderHeight();
		f32 pickOffs = -pel->getPickOffset();

		Vector3f pos(0.0f, 0.5f * h, 0.0f);
		Matrix4f mtx;
		mtx.makeVQS(Vector3f(0.0f, 0.0f, 0.0f), mRotationQuat, Vector3f(1.0f, 1.0f, 1.0f));
		pos.multMatrix(mtx);
		Vector3f unused(pos);
		pos = pos + mPosition;

		Matrix4f mtx2;
		Matrix4f mtx3;

		mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), pos);
		gfx.mCamera->mLookAtMtx.multiplyTo(mtx2, mtx3);

		gfx.setColour(Colour(255, 0, 0, 255), true);
		gfx.drawSphere(Vector3f(0.0f, 0.0f, 0.0f), 0.5f * h + pickOffs, mtx3);
		return;
	}

	// pellet but not a ufo part
	Matrix4f mtx1;
	Matrix4f mtx2;
	mtx1.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), mPosition);
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
	gfx.setColour(Colour(0, 255, 0, 255), true);
	gfx.drawSphere(Vector3f(0.0f, -mGroundOffset, 0.0f), mCollisionRadius, mtx2);
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
