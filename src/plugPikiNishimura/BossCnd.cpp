#include "BossConditions.h"
#include "Boss.h"
#include "Collision.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "DebugLog.h"

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

/*
 * --INFO--
 * Address:	8014FAFC
 * Size:	000040
 */
bool CndIsAlive::satisfy(Creature* target)
{
	if (target) {
		return target->isAlive();
	}
	return false;
}

/*
 * --INFO--
 * Address:	8014FB3C
 * Size:	0000C8
 */
bool CndBossFlick::satisfy(Creature* target)
{
	u32 badCompiler[2];

	if (target && target->isAlive() && !target->isCreatureFlag(CF_StuckToMouth) && target->isStuckTo(mBoss)) {
		if (randFloat(0.999999f) < static_cast<BossProp*>(mBoss->mProps)->mBossProps.mFlickChance()) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	8014FC04
 * Size:	000070
 */
bool CndStickBossKill::satisfy(Creature* target)
{
	if (target && target->isAlive() && target->isStuckTo(mBoss)) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8014FC74
 * Size:	00007C
 */
bool CndStickMouthKill::satisfy(Creature* target)
{
	if (target && target->isAlive() && target->isCreatureFlag(CF_StuckToMouth) && target->isStuckTo(mBoss)) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8014FCF0
 * Size:	000098
 */
bool CndBossCollKill::satisfy(Creature* target)
{
	if (target && target->isAlive() && !target->isCreatureFlag(CF_StuckToMouth) && target->isStuckTo(mBoss)) {
		CollPart* part = target->getStickPart();
		if (mCollID == part->getID().mId) {
			return true;
		}
	}
	return false;
}
