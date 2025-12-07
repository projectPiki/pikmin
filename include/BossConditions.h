#ifndef _BOSSCONDITIONS_H
#define _BOSSCONDITIONS_H

#include "Condition.h"
#include "ID32.h"
#include "types.h"

/**
 * @brief TODO
 */
struct CndIsAlive : public Condition {

	virtual bool satisfy(Creature*) immut; // _08

	// _00     = VTBL
	// _00-_04 = Condition
};

/**
 * @brief TODO
 */
struct CndBossFlick : public Condition {
	CndBossFlick(Creature* boss)
	    : mBoss(boss)
	{
	}

	virtual bool satisfy(Creature*) immut; // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
};

/**
 * @brief TODO
 */
struct CndStickBossKill : public Condition {

	virtual bool satisfy(Creature*) immut; // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
};

/**
 * @brief TODO
 */
struct CndStickMouthKill : public Condition {
	CndStickMouthKill(Creature* boss) { mBoss = boss; }

	virtual bool satisfy(Creature*) immut; // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
};

/**
 * @brief TODO
 */
struct CndBossCollKill : public Condition {

	virtual bool satisfy(Creature*) immut; // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
	u32 mCollID;     // _08
};

#endif
