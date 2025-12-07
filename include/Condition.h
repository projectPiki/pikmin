#ifndef _CONDITION_H
#define _CONDITION_H

#include "types.h"

struct Creature;

/**
 * @brief TODO
 */
struct Condition {
	Condition() { }

	virtual bool satisfy(Creature*) immut { return true; } // _08

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct CndIsAtari : public Condition {
	virtual bool satisfy(Creature*) immut; // _08

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct CndIsVisible : public Condition {
	virtual bool satisfy(Creature*) immut; // _08

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct CndStickMouth : public Condition {
	virtual bool satisfy(Creature*) immut; // _08

	// _00 = VTBL
	Creature* mMouthOwner; // _04
};

#endif
