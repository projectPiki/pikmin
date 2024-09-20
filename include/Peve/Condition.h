#ifndef _PEVE_CONDITION_H
#define _PEVE_CONDITION_H

#include "types.h"
#include "nlib/Node.h"

struct NVector3fIO;

/**
 * @brief TODO
 */
struct PeveCondition {
	PeveCondition();

	virtual bool isMet() = 0; // _08
	virtual void reset() { }  // _0C (weak)
	virtual void update() { } // _10 (weak)

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct PeveBooleanCondition : public PeveCondition {
	PeveBooleanCondition(); // unused/inlined

	virtual bool isMet(); // _08

	// unused/inlined:
	void construct(bool);

	// _00     = VTBL
	// _00-_04 = PeveCondition
	bool _04; // _04
};

/**
 * @brief TODO
 */
struct PeveComparisonYCondition : public PeveBooleanCondition {
	PeveComparisonYCondition(); // unused/inlined

	virtual void reset();  // _0C
	virtual void update(); // _10

	// unused/inlined:
	void construct(NVector3fIO*, NVector3fIO*);

	// _00     = VTBL
	// _00-_08 = PeveBooleanCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveDependenceCondition : public PeveCondition {
	PeveDependenceCondition(); // unused/inlined

	virtual bool isMet();  // _08
	virtual void reset();  // _0C
	virtual void update(); // _10

	// unused/inlined:
	void construct(PeveCondition*);

	// _00     = VTBL
	// _00-_04 = PeveCondition
};

/**
 * @brief TODO
 */
struct PeveDistanceCondition : public PeveBooleanCondition {
	PeveDistanceCondition(); // unused/inlined

	virtual void reset();  // _0C
	virtual void update(); // _10

	// unused/inlined:
	void construct(f32, NVector3fIO*, NVector3fIO*);

	// _00     = VTBL
	// _00-_08 = PeveBooleanCondition
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveTimeCondition : public PeveCondition {
	PeveTimeCondition();

	virtual bool isMet();  // _08
	virtual void reset();  // _0C
	virtual void update(); // _10

	// unused/inlined:
	void construct(f32);

	// _00     = VTBL
	// _00-_04 = PeveCondition
	f32 mCurrTime; // _04, in seconds
	f32 mLimit;    // _08, in seconds
};

#endif
