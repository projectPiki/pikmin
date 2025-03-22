#ifndef _PANIANIMATOR_H
#define _PANIANIMATOR_H

#include "types.h"
#include "Animator.h"

struct PaniMotion;
struct PaniMotionTable;

enum KeyEventTypes {
	KEY_Finished   = 0,
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
	PaniAnimKeyEvent(int eventType)
	{
		mEventType = eventType;
		mValue     = -1;
	}

	PaniAnimKeyEvent(int eventType, int value)
	{
		mEventType = eventType;
		mValue     = value;
	}

	// void init(int eventType, int value);

	int mEventType; // _00
	int mValue;     // _04
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

	PaniMotion* getMotion(int motionIdx) { return mMotions[motionIdx]; }
	void setMotion(int motionIdx, PaniMotion* motion) { mMotions[motionIdx] = motion; }

	int mMotionCount;      // _00
	PaniMotion** mMotions; // _04
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

	// TODO: either match these inlines to DLL ones in the list below, or remove.
	inline int getCurrentKeyIndex() { return mCurrentKeyIndex; }
	inline int getInfoKeyValue(int idx) { return mAnimInfo->getInfoKey(idx)->mKeyframeIndex; }
	inline int getEventKeyValue(int idx) { return mAnimInfo->getEventKey(idx)->mKeyframeIndex; }

	// these are all DLL inlines
	bool isFinished() { return mIsFinished; }

	f32 getCounter() { return mAnimationCounter; }
	void setCounter(f32 frame) { mAnimationCounter = frame; }

	f32 getKeyValue(int idx) { return mAnimInfo->getKeyValue(idx); }

	int getCurrentMotionIndex() { return mMotionIdx; }

	PaniMotion* getMotion(int motionIdx) { return mMotionTable->getMotion(motionIdx); }

	bool getCurrentOption(int opt) { return mAnimInfo->mParams.mFlags() & opt; }

	f32 getAnimationSpeed() { return mAnimInfo->mParams.mSpeed(); }

	int getFrameCount()
	{
		if (!mAnimInfo) {
			return -1;
		}
		return mAnimInfo->mData->mNumFrames;
	}

	/*
	    remaining DLL inlines:
	    bool isFinishing();

	    AnimKey* getEventKey(int);

	    f32 getAnimationSpeed();
	    f32 getKeyValueByKeyType(int);

	    int getEventKeyCount();
	    int getKeyIndex(int);
	    int getKeyInfoCount();
	    int getKeyType(int);
	*/

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
 *
 * @note Size: 0x54.
 */
struct PaniItemAnimator : public PaniAnimator {
	PaniItemAnimator();

	char* getCurrentMotionName()
	{
		if (mMotionIdx < 0) {
			return "NULL";
		}

		return motionLabels[mMotionIdx];
	}

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

	static char* motionLabels[];

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

	// DLL inline:
	char* getCurrentMotionName()
	{
		if (mMotionIdx < 0) {
			return "NULL";
		}

		return motionLabels[mMotionIdx];
	}

	// _30     = VTBL
	// _00-_54 = PaniAnimator
};

/**
 * @brief TODO
 */
struct PaniUfoAnimator : public PaniAnimator {
	PaniUfoAnimator();

	static PaniMotionTable* createMotionTable();

	static char* motionLabels[17];

	// _30     = VTBL
	// _00-_54 = PaniAnimator
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

	int getSize() { return mSoundCount; }
	PaniSound* getSound(int idx) { return mSounds[idx]; }

	int mSoundCount;     // _00
	PaniSound** mSounds; // _04, array of mSoundCount sounds
};

#endif
