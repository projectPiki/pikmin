#ifndef _BOSSCONDITIONS_H
#define _BOSSCONDITIONS_H

#include "types.h"
#include "Condition.h"
#include "ID32.h"

/**
 * @brief TODO
 */
struct CndIsAlive : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	// TODO: members
};

/**
 * @brief TODO
 */
struct CndBossFlick : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
};

/**
 * @brief TODO
 */
struct CndStickBossKill : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
};

/**
 * @brief TODO
 */
struct CndStickMouthKill : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
};

/**
 * @brief TODO
 */
struct CndBossCollKill : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	Creature* mBoss; // _04
	u32 mCollID;     // _08
};

#endif
