#include "Boss.h"
#include "BossConditions.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "Generator.h"
#include "Graphics.h"
#include "Interactions.h"
#include "MapCode.h"
#include "NaviMgr.h"
#include "NsMath.h"
#include "Pellet.h"
#include "PikiMgr.h"
#include "RadarInfo.h"
#include "SoundMgr.h"
#include "Stickers.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Boss");

/*
 * --INFO--
 * Address:	8014D8CC
 * Size:	0005AC
 */
BossProp::BossProp()
{
}

/*
 * --INFO--
 * Address:	8014DE78
 * Size:	0000EC
 */
Boss::Boss(CreatureProp* props)
    : Creature(props)
{
	mSeContext              = new SeContext(this, 1);
	mLifeGauge.mRenderStyle = LifeGauge::Wheel;
	mLifeGauge.mScale       = static_cast<BossProp*>(props)->mBossProps.mLifeGaugeScale();
	mSearchBuffer.init(mSearchData, 3);
}

/*
 * --INFO--
 * Address:	8014DF64
 * Size:	000114
 */
void Boss::initBoss(BirthInfo& birthInfo, int objType)
{
	Creature::init(birthInfo.mPosition);
	mObjType           = (EObjType)objType;
	mSRT.r             = birthInfo.mRotation;
	mFaceDirection     = mSRT.r.y;
	mIsAlive           = true;
	mIsAtari           = true;
	mIsVisible         = true;
	mIsOrganic         = true;
	mIsInvincible      = false;
	mIsMotionFinished  = false;
	mNeedShadow        = false;
	mIsOnWall          = false;
	mDamage            = 0.0f;
	f32 maxHealth      = BOSS_PROP.mMaxHealth();
	mMaxLife           = maxHealth;
	mCurrentLife       = maxHealth;
	mAnimTimer         = 0.0f;
	mAttackTimer       = 0.0f;
	mWalkTimer         = 0.0f;
	mLifeRecoveryTimer = 0.0f;
	mSearchAngle       = PI * (BOSS_PROP.mSearchAngle() / 360.0f);
	mShadowSize        = 0.0f;
	mAnimLoopCounter   = 0;
	mFlickDamageCount  = 0;
	mInitPosition      = birthInfo.mPosition;
	mTargetCreature    = nullptr;
	mTargetPosition    = birthInfo.mPosition;
}

/*
 * --INFO--
 * Address:	8014E078
 * Size:	000098
 */
void Boss::calcFlickPiki()
{
	interactStickers(this, InteractFlick(this, BOSS_PROP.mFlickKnockback(), BOSS_PROP.mFlickDamage(), FLICK_BACKWARDS_ANGLE),
	                 &CndBossFlick(this));

	mFlickDamageCount = 0;
}

/*
 * --INFO--
 * Address:	8014E110
 * Size:	0002A0
 */
void Boss::createPellet(Vector3f& bossPos, f32 vertSpeed, bool hasUfoPart)
{
	if (mItemCount != 0) {
		// release first item in a random 180 degree cone
		f32 randStartAngle = gsys->getRand(PI);

		// release each item after that equally spaced around a circle
		f32 angleOffset = TAU / mItemCount;

		for (int i = 0; i < mItemCount; i++) {
			int itemColour = mItemColour;
			f32 angle      = angleOffset * i + randStartAngle;
			f32 sinAngle   = sinf(angle);
			f32 cosAngle   = cosf(angle);
			Vector3f itemPos(bossPos.x + sinAngle, bossPos.y, bossPos.z + cosAngle);

			if (itemColour > PELCOLOUR_MAX || itemColour < PELCOLOR_MIN) {
				itemColour = NsMathI::getRand(PELCOLOUR_COUNT);
			}

			Pellet* numPellet = pelletMgr->newNumberPellet(itemColour, mItemIndex);
			if (numPellet) {
				numPellet->init(itemPos);
				numPellet->mVelocity.set(100.0f * sinAngle, vertSpeed, 100.0f * cosAngle);
				numPellet->startAI(0);
				numPellet->playEventSound(numPellet, SE_PELLET_BORN);
			}
		}
	}

	if (hasUfoPart) {
		Pellet* ufoPart = pelletMgr->newPellet(mPelletID.mId, nullptr);
		if (ufoPart) {
			ufoPart->init(bossPos);
			ufoPart->mVelocity.set(0.0f, vertSpeed, 0.0f);
			ufoPart->mFaceDirection = mFaceDirection;
			ufoPart->startAI(0);
			radarInfo->detachParts(this);

			if (Pellet::isUfoPartsID(mPelletID.mId)) {
				SeSystem::playSysSe(SYSSE_PARTS_APPEAR);
			}
		}
	}

	detachGenerator();
}

/*
 * --INFO--
 * Address:	8014E3B0
 * Size:	000164
 */
bool Boss::changeDirection(f32 turnSpeed)
{
	bool notFacingTarget = false;
	f32 maxTurnDist      = turnSpeed * gsys->getFrameTime();
	f32 targetDir        = atan2f(mTargetPosition.x - mSRT.t.x, mTargetPosition.z - mSRT.t.z);
	mFaceDirection       = NsMathF::roundAngle(mFaceDirection);
	f32 properTargetDir  = NsMathF::calcNearerDirection(mFaceDirection, targetDir);

	if (properTargetDir > mFaceDirection) {
		if (properTargetDir - mFaceDirection < maxTurnDist) {
			mFaceDirection = properTargetDir;
		} else {
			mFaceDirection  = mFaceDirection + maxTurnDist;
			notFacingTarget = true;
		}
	} else if (mFaceDirection - properTargetDir < maxTurnDist) {
		mFaceDirection = properTargetDir;
	} else {
		mFaceDirection  = mFaceDirection - maxTurnDist;
		notFacingTarget = true;
	}

	mFaceDirection = mSRT.r.y = NsMathF::roundAngle(mFaceDirection);

	return notFacingTarget;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void Boss::towardFaceDirection(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014E514
 * Size:	000034
 */
void Boss::stopMovement()
{
	mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8014E548
 * Size:	000050
 */
void Boss::calcBossDamage()
{
	mCurrentLife -= mDamage;
	mLifeGauge.updValue(mCurrentLife, mMaxLife);
	mDamage = 0.0f;
}

/*
 * --INFO--
 * Address:	8014E598
 * Size:	000030
 */
void Boss::makeTargetCreature()
{
	if (mTargetCreature) {
		mTargetPosition.x = mTargetCreature->mSRT.t.x;
		mTargetPosition.y = mTargetCreature->mSRT.t.y;
		mTargetPosition.z = mTargetCreature->mSRT.t.z;
	}
}

/*
 * --INFO--
 * Address:	8014E5C8
 * Size:	000144
 */
void Boss::makeTargetRandom(f32 p1)
{
	mWalkTimer += gsys->getFrameTime();
	if (mWalkTimer > 5.0f || qdist2(mSRT.t.x, mSRT.t.z, mTargetPosition.x, mTargetPosition.z) < p1) {
		f32 randAngle = NsMathF::getRand(TAU);
		Vector3f vec;
		f32 randDist = NsMathF::getRand(BOSS_PROP.mMaxWaitRadius());
		vec.set(randDist * sinf(randAngle) + mInitPosition.x, 0.0f, randDist * cosf(randAngle) + mInitPosition.z);
		mTargetPosition.x = vec.x;
		mTargetPosition.y = vec.y;
		mTargetPosition.z = vec.z;

		mWalkTimer = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	8014E70C
 * Size:	0002D0
 */
bool Boss::chaseNaviTransit()
{
	Creature* target = nullptr;
	f32 minDist      = 12800.0f;
	if (mTargetCreature) {
		minDist = mSRT.t.distance(mTargetCreature->mSRT.t);
	}

	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {
			f32 quickDist = qdist2(mSRT.t.x, mSRT.t.z, navi->mSRT.t.x, navi->mSRT.t.z);
			if (quickDist < BOSS_PROP.mSearchRadius() && quickDist < minDist && inSearchAngle(navi)) {
				// we're actually close, so do things properly
				f32 naviDist = mSRT.t.distance(navi->mSRT.t);
				if (naviDist < BOSS_PROP.mSearchRadius() && naviDist < minDist) {
					minDist = naviDist;
					target  = navi;
				}
			}
		}
	}

	if (target) {
		mTargetCreature = target;
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014E9DC
 * Size:	0002DC
 */
bool Boss::chasePikiTransit()
{
	Creature* target = nullptr;
	f32 minDist      = 12800.0f;
	if (mTargetCreature) {
		minDist = mSRT.t.distance(mTargetCreature->mSRT.t);
	}

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->getStickObject() != this) {
			f32 quickDist = qdist2(mSRT.t.x, mSRT.t.z, piki->mSRT.t.x, piki->mSRT.t.z);
			if (quickDist < BOSS_PROP.mSearchRadius() && quickDist < minDist && inSearchAngle(piki)) {
				// we're actually close, so do things properly
				f32 pikiDist = mSRT.t.distance(piki->mSRT.t);
				if (pikiDist < BOSS_PROP.mSearchRadius() && pikiDist < minDist) {
					minDist = pikiDist;
					target  = piki;
				}
			}
		}
	}

	if (target) {
		mTargetCreature = target;
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014ECB8
 * Size:	000158
 */
bool Boss::targetLostTransit()
{
	if (mTargetCreature) {
		if (!mTargetCreature->isAlive() || !mTargetCreature->isVisible() || mTargetCreature->isBuried()
		    || mTargetCreature->getStickObject() == this) {
			mTargetCreature = nullptr;
			return true;
		}

		if (!inSearchAngle(mTargetCreature)) {
			mTargetCreature = nullptr;
			return true;
		}

		if (mSRT.t.distance(mTargetCreature->mSRT.t) > BOSS_PROP.mSearchRadius()) {
			mTargetCreature = nullptr;
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014EE10
 * Size:	000060
 */
bool Boss::inSideWaitRangeTransit()
{
	if (qdist2(mSRT.t.x, mSRT.t.z, mInitPosition.x, mInitPosition.z) < BOSS_PROP.mMaxWaitRadius()) {
		mTargetCreature = nullptr;
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8014EE70
 * Size:	000060
 */
bool Boss::outSideChaseRangeTransit()
{
	if (qdist2(mSRT.t.x, mSRT.t.z, mInitPosition.x, mInitPosition.z) > BOSS_PROP.mTerritoryRadius()) {
		mTargetCreature = nullptr;
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8014EED0
 * Size:	0000C4
 */
bool Boss::inSearchAngle(Creature* target)
{
	f32 dir       = atan2f(target->mSRT.t.x - mSRT.t.x, target->mSRT.t.z - mSRT.t.z);
	f32 targetDir = NsMathF::calcNearerDirection(mFaceDirection, dir);
	if (targetDir > mFaceDirection) {
		f32 diff = targetDir - mFaceDirection;
		if (diff < mSearchAngle) {
			return true;
		}

	} else if (mFaceDirection - targetDir < mSearchAngle) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014EF94
 * Size:	0000B8
 */
bool Boss::flickPikiTransit()
{
	int stickPikiNum = getStickNoMouthPikiCount();

	if (stickPikiNum >= BOSS_PROP.mFlickPikiCountCD()) {
		if (mFlickDamageCount >= BOSS_PROP.mFlickDamageCountD()) {
			return true;
		}

	} else if (stickPikiNum >= BOSS_PROP.mFlickPikiCountBC()) {
		if (mFlickDamageCount >= BOSS_PROP.mFlickDamageCountC()) {
			return true;
		}

	} else if (stickPikiNum >= BOSS_PROP.mFlickPikiCountAB()) {
		if (mFlickDamageCount >= BOSS_PROP.mFlickDamageCountB()) {
			return true;
		}

	} else if (mFlickDamageCount >= BOSS_PROP.mFlickDamageCountA()) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014F04C
 * Size:	00002C
 */
int Boss::getStickPikiCount()
{
	Stickers stickers(this);
	return stickers.getNumStickers();
}

/*
 * --INFO--
 * Address:	8014F078
 * Size:	000158
 */
int Boss::getStickMouthPikiCount()
{
	int count = 0;
	Stickers stuckList(this);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck->isAlive() && stuck->isStickToMouth()) {
			count++;
		}
	}
	return count;
}

/*
 * --INFO--
 * Address:	8014F1D0
 * Size:	000158
 */
int Boss::getStickNoMouthPikiCount()
{
	int count = 0;
	Stickers stuckList(this);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck->isAlive() && !stuck->isStickToMouth()) {
			count++;
		}
	}
	return count;
}

/*
 * --INFO--
 * Address:	8014F328
 * Size:	000048
 */
void Boss::killStickToMouthPiki()
{
	killStickers(this, &CndStickMouthKill(this), 0);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
bool Boss::checkInWater(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014F370
 * Size:	000050
 */
int Boss::getMapAttribute(Vector3f& pos)
{
	int attr         = ATTR_NULL;
	CollTriInfo* tri = mapMgr->getCurrTri(pos.x, pos.z, true);
	if (tri) {
		attr = MapCode::getAttribute(tri);
	}
	return attr;
}

/*
 * --INFO--
 * Address:	8014F3C0
 * Size:	00006C
 */
bool Boss::insideAndInSearch()
{
	if (aiCullable()) {
		Navi* navi = naviMgr->getNavi();
		if (qdist2(mSRT.t.x, mSRT.t.z, navi->mSRT.t.x, navi->mSRT.t.z) < BOSS_PROP.mSearchRadius()) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void Boss::recoveryLife()
{
	if (mCurrentLife > 0.0f && mCurrentLife < mMaxLife && BOSS_PROP.mLifeRecoveryRate() > 0.0f && BOSS_PROP.mLifeRecoveryTime() > 0.0f) {
		mLifeRecoveryTimer += gsys->getFrameTime();
		if (mLifeRecoveryTimer > BOSS_PROP.mLifeRecoveryTime()) {
			mCurrentLife += BOSS_PROP.mLifeRecoveryRate() * mMaxLife;
			if (mCurrentLife > mMaxLife) {
				mCurrentLife = mMaxLife;
			}

			mLifeGauge.updValue(mCurrentLife, mMaxLife);
			mLifeRecoveryTimer = 0.0f;
		}
	}
}

/*
 * --INFO--
 * Address:	8014F42C
 * Size:	000100
 */
void Boss::updateBoss()
{
	mGrid.updateGrid(mSRT.t);
	mGrid.updateAIGrid(mSRT.t, false);
	if (mSeContext) {
		mSeContext->update();
	}

	recoveryLife();
	mCurrentStateID = mNextStateID;
}

/*
 * --INFO--
 * Address:	8014F52C
 * Size:	00008C
 */
void Boss::refreshViewCulling(Graphics& gfx)
{
	Vector3f point(mSRT.t);
	point.y += BOSS_PROP.mRenderSphereHeight();
	if (!gfx.mCamera->isPointVisible(point, BOSS_PROP.mRenderSphereRadius())) {
		enableAICulling();
	} else {
		disableAICulling();
	}
}

/*
 * --INFO--
 * Address:	8014F5B8
 * Size:	000004
 */
void Boss::drawShape(Graphics&)
{
}

/*
 * --INFO--
 * Address:	8014F5BC
 * Size:	00006C
 */
void Boss::refresh2d(Graphics& gfx)
{
	mLifeGauge.mPosition = mSRT.t;
	mLifeGauge.mPosition.y += BOSS_PROP.mLifeGaugeHeight();
	mLifeGauge.mScale = BOSS_PROP.mLifeGaugeScale() / gfx.mCamera->mNear;
	mLifeGauge.refresh(gfx);
}

/*
 * --INFO--
 * Address:	8014F628
 * Size:	000030
 */
void Boss::wallCallback(Plane& plane, DynCollObject* wallObject)
{
	mIsOnWall       = true;
	mWallPlane      = plane;
	mWallCollObject = wallObject;
}

/*
 * --INFO--
 * Address:	8014F658
 * Size:	000114
 */
bool InteractAttack::actBoss(Boss* boss) immut
{
	if (boss->getAlive() && !boss->getInvincible()) {
		switch (getDamagePortion()) {
		case 0:
			boss->addFlickDamageCount(1);
			return false;

		case 1:
			boss->addFlickDamageCount(1);
			boss->addDamagePoint(mDamage);
			return true;

		case 2:
			boss->addFlickDamageCount(C_BOSS_PROP(boss)._15C());
			boss->addDamagePoint(mDamage * C_BOSS_PROP(boss)._CC());
			return true;

		default:
			boss->addFlickDamageCount(1);
			return boss->attackDefaultPortion();
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014F774
 * Size:	00003C
 */
bool InteractFlick::actBoss(Boss* boss) immut
{
	if (boss->getAlive() && !boss->getInvincible()) {
		boss->addDamagePoint(mDamage);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014F7B0
 * Size:	000084
 */
bool InteractBomb::actBoss(Boss* boss) immut
{
	if (boss->getAlive() && !boss->getInvincible()) {
		boss->addDamagePoint(C_BOSS_PROP(boss).mBombDamageMultiplier() * mDamage);
		if (mCollPart) {
			boss->bombDamageCounter(mCollPart);
		}
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014F838
 * Size:	000110
 */
bool InteractHitEffect::actBoss(Boss* boss) immut
{
	switch (boss->mObjType) {
	case OBJTYPE_Spider:
		effectMgr->create(EffectMgr::EFF_Piki_BigHit, mEffectPos, nullptr, nullptr);
		return true;

	case OBJTYPE_Snake:
		effectMgr->create(EffectMgr::EFF_Piki_BigHit, mEffectPos, nullptr, nullptr);
		return true;
		;

	case OBJTYPE_King:
		effectMgr->create(EffectMgr::EFF_Piki_BigHit, mEffectPos, nullptr, nullptr);
		if (mCollPart && boss->mSeContext && mCollPart->isBouncy()) {
			boss->mSeContext->playSound(SE_MUSH_GETUP);
		}
		return true;

	case OBJTYPE_Pom:
		effectMgr->create(EffectMgr::EFF_Piki_BigHit, mEffectPos, nullptr, nullptr);
		return true;
		;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014F948
 * Size:	00006C
 */
bool Boss::stimulate(immut Interaction& interaction)
{
	bool res = interaction.actCommon(this);
	if (res) {
		return interaction.actBoss(this);
	}

	// this is always false.
	return res;
}
