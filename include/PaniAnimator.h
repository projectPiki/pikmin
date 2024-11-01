#ifndef _PANIANIMATOR_H
#define _PANIANIMATOR_H

#include "types.h"
#include "Animator.h"

struct PaniMotionTable;

/**
 * @brief TODO
 */
struct PaniAnimKeyEvent {
	PaniAnimKeyEvent(int keyFrame, int value = -1)
	{
		mKeyFrame = keyFrame;
		mValue    = value;
	}

	int mKeyFrame; // _00
	int mValue;    // _04, used in KingAi for a couple different things - this struct might be differentiated for each use case? unsure.
};

/**
 * @brief TODO
 */
struct PaniAnimKeyListener {

	virtual void animationKeyUpdated(PaniAnimKeyEvent&) = 0; // _08

	// _00 = VTBL
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
	f32 getKeyValueByKeyType(int);

	// unused/inlined:
	void checkCounter_4DEBUG();

	inline bool isFinished() const { return mIsFinished; }

	inline int getInfoKeyValue(int idx) { return mAnimInfo->getInfoKey(idx)->_00; }
	inline int getEventKeyValue(int idx) { return mAnimInfo->getEventKey(idx)->_00; }
	inline f32 getKeyValue(int idx) { return mAnimInfo->getKeyValue(idx); }

	static char* keyNames[6];

	// _30     = VTBL
	// _00-_34 = Animator
	PaniAnimKeyListener* mListener; // _34, unknown
	int _38;                        // _38
	u8 _3C[0x4];                    // _3C, unknown
	u32 _40;                        // _40, unknown
	int mMotionIdx;                 // _44
	bool mIsFinished;               // _48
	u32 _4C;                        // _4C, unknown
	PaniMotionTable* mMotionTable;  // _50
};

/**
 * @brief TODO
 */
struct PaniItemAnimator : public PaniAnimator {
	PaniItemAnimator();

	PaniMotionTable* createMotionTable();

	// _30     = VTBL
	// _00-_54 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniPelletAnimator : public PaniAnimator {
	PaniPelletAnimator();

	static PaniMotionTable* createMotionTable();

	// _30     = VTBL
	// _00-_54 = PaniAnimator
};

/**
 * @brief TODO
 */
struct PaniPlantAnimator : public PaniAnimator {
	PaniPlantAnimator();

	static PaniMotionTable* createMotionTable();

	// _30     = VTBL
	// _00-_54 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniTekiAnimator : public PaniAnimator {
	PaniTekiAnimator();

	static PaniMotionTable* createMotionTable();

	// _30     = VTBL
	// _00-_54 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniUfoAnimator : public PaniAnimator {
	PaniUfoAnimator();

	static PaniMotionTable* createMotionTable();

	// _30     = VTBL
	// _00-_54 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniMotionInfo {
	PaniMotionInfo(int);
	PaniMotionInfo(int, PaniAnimKeyListener*);

	void init(int, PaniAnimKeyListener*);

	int mMotionIdx;                 // _00
	PaniAnimKeyListener* mListener; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct PaniMotion {
	PaniMotion(int);
	PaniMotion(int, int); // unused/inlined

	void init(int, int);

	int _00; // _00
	int _04; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct PaniMotionTable {
	PaniMotionTable(int);

	int mMotionCount;      // _00
	PaniMotion** mMotions; // _04
};

/**
 * @brief TODO
 */
struct PaniSoundTable {
	PaniSoundTable(int);

	int mSoundCount; // _00
	u32** mSounds;   // _04, array of some type of pointer
};

#endif
