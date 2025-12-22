#include "Boss.h"
#include "BossConditions.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "NsMath.h"
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
DEFINE_PRINT(nullptr);

/**
 * @TODO: Documentation
 */
bool CndIsAlive::satisfy(Creature* target) immut
{
	if (target) {
		return target->isAlive();
	}
	return false;
}

/**
 * @TODO: Documentation
 */
bool CndBossFlick::satisfy(Creature* target) immut
{
	if (target && target->isAlive() && !target->isStickToMouth() && target->getStickObject() == mBoss) {
		if (NsMathF::getRand(1.0f) < static_cast<BossProp*>(mBoss->mProps)->mBossProps.mFlickChance()) {
			return true;
		}
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool CndStickBossKill::satisfy(Creature* target) immut
{
	if (target && target->isAlive() && target->getStickObject() == mBoss) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
bool CndStickMouthKill::satisfy(Creature* target) immut
{
	if (target && target->isAlive() && target->isStickToMouth() && target->getStickObject() == mBoss) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
bool CndBossCollKill::satisfy(Creature* target) immut
{
	if (target && target->isAlive() && !target->isStickToMouth() && target->getStickObject() == mBoss) {
		if (mCollID == target->getStickPart()->getID().mId) {
			return true;
		}
	}
	return false;
}
