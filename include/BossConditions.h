#ifndef _BOSSCONDITIONS_H
#define _BOSSCONDITIONS_H

#include "types.h"
#include "Condition.h"

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
	// TODO: members
};

/**
 * @brief TODO
 */
struct CndStickBossKill : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	// TODO: members
};

/**
 * @brief TODO
 */
struct CndStickMouthKill : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	// TODO: members
};

/**
 * @brief TODO
 */
struct CndBossCollKill : public Condition {

	virtual bool satisfy(Creature*); // _08

	// _00     = VTBL
	// _00-_04 = Condition
	// TODO: members
};

#endif
