#ifndef _PANIANIMATOR_H
#define _PANIANIMATOR_H

#include "types.h"
#include "Animator.h"

struct PaniMotionTable;

/**
 * @brief TODO
 */
struct PaniAnimKeyEvent {
};

/**
 * @brief TODO
 */
struct PaniAnimKeyListener {

	virtual void animationKeyUpdated(PaniAnimKeyEvent&) = 0; // _08

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniAnimator : public Animator {
	PaniAnimator();

	virtual void changeContext(AnimContext*); // _08
	virtual void animate(f32);                // _0C
	virtual void updateContext();             // _18

	void init(AnimContext*, AnimMgr*, PaniMotionTable*);
	void startMotion(struct PaniMotionInfo&);
	void finishMotion(PaniMotionInfo&);
	void checkConstantKeys();
	void checkConstantKey(int);
	void checkEventKeys(f32, f32);
	void finishAnimation();
	void getKeyValueByKeyType(int);

	// _30     = VTBL
	// _00-_34 = Animator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniItemAnimator : public PaniAnimator {
	// _30     = VTBL
	// _00-_34 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniPelletAnimator : public PaniAnimator {
	// _30     = VTBL
	// _00-_34 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniPikiAnimator : public PaniAnimator {
	// _30     = VTBL
	// _00-_34 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniPlantAnimator : public PaniAnimator {
	// _30     = VTBL
	// _00-_34 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniTekiAnimator : public PaniAnimator {
	PaniTekiAnimator();

	// _30     = VTBL
	// _00-_34 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniUfoAnimator : public PaniAnimator {
	// _30     = VTBL
	// _00-_34 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniPikiAnimMgr {
	PaniPikiAnimMgr();

	void init(AnimMgr*, AnimContext*, AnimContext*, PaniMotionTable*);
	void changeContext(AnimContext*, AnimContext*);
	void startMotion(PaniMotionInfo*, PaniMotionInfo*);
	void finishMotion(PaniMotionInfo*, PaniMotionInfo*);
	void startMotion(PaniMotionInfo&, PaniMotionInfo&);
	void finishMotion(PaniAnimKeyListener*);
	void updateAnimation(f32);
	void updateContext();

	// unused/inlined:
	PaniMotionTable* getMotionTable();

	static PaniMotionTable* motionTable;

	// TODO: members
};

#endif
