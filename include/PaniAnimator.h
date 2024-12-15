#ifndef _PANIANIMATOR_H
#define _PANIANIMATOR_H

#include "types.h"
#include "Animator.h"

struct PaniMotionTable;

enum KeyEventTypes {
	KEY_Done       = 0,
	KEY_Action0    = 1,
	KEY_Action1    = 2,
	KEY_Action2    = 3,
	KEY_Action3    = 4,
	KEY_LoopStart  = 5,
	KEY_LoopEnd    = 6,
	KEY_PlaySound  = 7,
	KEY_PlayEffect = 8,
};

/**
 * @brief TODO
 */
struct PaniAnimKeyEvent {
	PaniAnimKeyEvent(int eventType, int value = -1)
	{
		mEventType = eventType;
		mValue     = value;
	}

	int mEventType; // _00
	int mValue;     // _04, used in KingAi for a couple different things - this struct might be differentiated for each use case? unsure.
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

	void checkCounter_4DEBUG();

	inline bool isFinished() const { return mIsFinished; }
	inline f32 getCurrentFrame() const { return mCurrentFrame; }
	inline void setCurrentFrame(f32 frame) { mCurrentFrame = frame; }

	inline int getMotionID() { return mMotionIdx; }

	inline int get38() { return mCurrentKeyIndex; } // TODO: rename later

	inline int getInfoKeyValue(int idx) { return mAnimInfo->getInfoKey(idx)->mKeyframeIndex; }
	inline int getEventKeyValue(int idx) { return mAnimInfo->getEventKey(idx)->mKeyframeIndex; }
	inline f32 getKeyValue(int idx) { return mAnimInfo->getKeyValue(idx); }

	static char* keyNames[6];

	// _30     = VTBL
	// _00-_34 = Animator
	PaniAnimKeyListener* mListener; // _34, unknown
	int mCurrentKeyIndex;           // _38
	u8 _3C[0x4];                    // _3C, unknown
	u32 mPreviousKeyIndex;          // _40, unknown
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

	static PaniMotionTable* createMotionTable();

	static char* motionLabels[15];

	// _30     = VTBL
	// _00-_54 = PaniAnimator
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

	static char* motionLabels[7];

	// _30     = VTBL
	// _00-_54 = PaniAnimator
};

/**
 * @brief TODO
 */
struct PaniTekiAnimator : public PaniAnimator {
	PaniTekiAnimator();

	static PaniMotionTable* createMotionTable();

	static char* motionLabels[15];

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

	int mAnimID; // _00
	int _04;     // _04
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
 * @brief Fabricated.
 *
 * @note Size: 0x4.
 */
struct PaniSound {
	PaniSound(int soundID)
	    : mSoundID(soundID)
	{
	}

	int mSoundID; // _00
};

/**
 * @brief TODO
 */
struct PaniSoundTable {
	PaniSoundTable(int);

	int mSoundCount;     // _00
	PaniSound** mSounds; // _04, array of mSoundCount sounds
};

#endif
