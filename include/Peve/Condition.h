#ifndef _PEVE_CONDITION_H
#define _PEVE_CONDITION_H

#include "types.h"
#include "nlib/Node.h"
#include "nlib/System.h"

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

	virtual bool isMet() { return mValue; } // _08

	// unused/inlined:
	void construct(bool value);

	// DLL inlines:
	void setValue(bool value) { mValue = value; }

	// _00     = VTBL
	// _00-_04 = PeveCondition
	bool mValue; // _04
};

/**
 * @brief TODO
 */
struct PeveComparisonYCondition : public PeveBooleanCondition {
	PeveComparisonYCondition(); // unused/inlined

	virtual void reset() { setValue(false); } // _0C
	virtual void update();                    // _10

	// unused/inlined:
	void construct(NVector3fIO*, NVector3fIO*);

	// _00     = VTBL
	// _00-_08 = PeveBooleanCondition
	NVector3fIO* mVectorIOA; // _08
	NVector3fIO* mVectorIOB; // _0C
};

/**
 * @brief TODO
 */
struct PeveDependenceCondition : public PeveCondition {
	PeveDependenceCondition(); // unused/inlined

	virtual bool isMet() { return mDependenceCondition->isMet(); } // _08
	virtual void reset() { }                                       // _0C
	virtual void update() { }                                      // _10

	// unused/inlined:
	void construct(PeveCondition*);

	// _00     = VTBL
	// _00-_04 = PeveCondition
	PeveCondition* mDependenceCondition; // _04
};

/**
 * @brief TODO
 */
struct PeveDistanceCondition : public PeveBooleanCondition {
	PeveDistanceCondition(); // unused/inlined

	virtual void reset() { setValue(false); } // _0C
	virtual void update();                    // _10

	// unused/inlined:
	void construct(f32, NVector3fIO*, NVector3fIO*);

	// _00     = VTBL
	// _00-_08 = PeveBooleanCondition
	f32 mThreshold;          // _08
	NVector3fIO* mVectorIOA; // _0C
	NVector3fIO* mVectorIOB; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct PeveTimeCondition : public PeveCondition {
	PeveTimeCondition();

	virtual bool isMet() { return mCurrTime >= mLimit; }            // _08
	virtual void reset() { mCurrTime = 0.0f; }                      // _0C
	virtual void update() { mCurrTime += NSystem::getFrameTime(); } // _10

	// unused/inlined:
	void construct(f32);

	// DLL inlines:
	f32 getTime() { return mCurrTime; }
	void setPeriod(f32 limit) { mLimit = limit; }

	// _00     = VTBL
	// _00-_04 = PeveCondition
	f32 mCurrTime; // _04, in seconds
	f32 mLimit;    // _08, in seconds, a.k.a. period
};

#endif
