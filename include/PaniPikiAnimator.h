#ifndef _PANIPIKIANIMATOR_H
#define _PANIPIKIANIMATOR_H

#include "types.h"
#include "PaniAnimator.h"

/**
 * @brief Animation indices for Piki and Navi
 */
enum PikiNaviAnim {
	PIKIANIM_Run         = 0,  // Run
	PIKIANIM_Nigeru      = 1,  // 'Run away'
	PIKIANIM_Walk        = 2,  // Walk
	PIKIANIM_Wait        = 3,  // Wait
	PIKIANIM_Pick        = 4,  // Pick (up)
	PIKIANIM_Nuku        = 5,  // 'Pluck'
	PIKIANIM_Nukareru    = 6,  // 'Be plucked'
	PIKIANIM_Dead        = 7,  // Dead
	PIKIANIM_Dead2       = 8,  // Dead (2)
	PIKIANIM_Dead3       = 9,  // Dead (3)
	PIKIANIM_Damage      = 10, // Damage
	PIKIANIM_Asibumi     = 11, // 'Step'
	PIKIANIM_OCarry      = 12, // 'O(limar) carry'
	PIKIANIM_LSuberu     = 13, // 'L slip'
	PIKIANIM_RSuberu     = 14, // 'R slip'
	PIKIANIM_Tanemaki    = 15, // 'seed sowing'
	PIKIANIM_Job1        = 16, // Job (1)
	PIKIANIM_GrowUp1     = 17, // Grow up (1)
	PIKIANIM_GrowUp2     = 18, // Grow up (2)
	PIKIANIM_Job2        = 19, // Job (2)
	PIKIANIM_Korobu      = 20, // 'Fall'
	PIKIANIM_Jump        = 21, // Jump
	PIKIANIM_StillJump   = 22, // Still jump
	PIKIANIM_Attack      = 23, // Attack
	PIKIANIM_Butukaru    = 24, // 'Collide'
	PIKIANIM_Punch       = 25, // Punch
	PIKIANIM_Kenka       = 26, // 'Fight'
	PIKIANIM_Throw       = 27, // Throw
	PIKIANIM_Hang        = 28, // Hang
	PIKIANIM_Fall        = 29, // Fall
	PIKIANIM_JKoke       = 30, // 'J Moss(?)'
	PIKIANIM_JHit        = 31, // J Hit
	PIKIANIM_GetUp       = 32, // Get up
	PIKIANIM_NewJmp      = 33, // New jump
	PIKIANIM_RollJmp     = 34, // Roll jump
	PIKIANIM_WaveJmp     = 35, // Wave jump
	PIKIANIM_ThrowWait   = 36, // Throw wait
	PIKIANIM_Push        = 37, // Push
	PIKIANIM_Umaru       = 38, // 'Bury'
	PIKIANIM_Akubi       = 39, // 'Yawn'
	PIKIANIM_Rinbow      = 40, // 'Rainbow'
	PIKIANIM_Iraira      = 41, // 'Annoyed'
	PIKIANIM_Furimuku    = 42, // 'Turn around'
	PIKIANIM_JumpKick    = 43, // Jump Kick
	PIKIANIM_Kaifuku     = 44, // 'Recovery'
	PIKIANIM_Kizuku      = 45, // 'Scratches'
	PIKIANIM_PickLoop    = 46, // Pick (up) loop
	PIKIANIM_Mizunomi    = 47, // 'Water only'
	PIKIANIM_Kuttuku     = 48, // 'Stick'
	PIKIANIM_Fue         = 49, // 'Flute (whistle)'
	PIKIANIM_Suwaru      = 50, // 'Sit'
	PIKIANIM_Aogu        = 51, // 'Fan'
	PIKIANIM_Neru        = 52, // 'Sleep'
	PIKIANIM_Press1      = 53, // Press (1)
	PIKIANIM_Press2      = 54, // Press (2)
	PIKIANIM_SPress      = 55, // S Press
	PIKIANIM_TYakusui    = 56, // 'T Easy(?)'
	PIKIANIM_Oboreru     = 57, // 'Drowning'
	PIKIANIM_Sizumu      = 58, // 'Sink' or 'Trembling'?
	PIKIANIM_Hikakaru    = 59, // 'Get hit'
	PIKIANIM_Otikake     = 60, // 'Fall'
	PIKIANIM_Otiru       = 61, // 'Fall'
	PIKIANIM_HNoboru     = 62, // 'H Climb' (horizontal?)
	PIKIANIM_Noboru      = 63, // 'Climb'
	PIKIANIM_Chatting    = 64, // Chatting
	PIKIANIM_Sagasu2     = 65, // 'Search (2)'
	PIKIANIM_Otikake2    = 66, // 'Fall (2)'
	PIKIANIM_Kaifuku3    = 67, // 'Recovery (2)'
	PIKIANIM_Punch2      = 68, // 'Punch!'
	PIKIANIM_Moeru       = 69, // 'Burn'
	PIKIANIM_Esa         = 70, // 'Food'
	PIKIANIM_GameOver    = 71, // Game over
	PIKIANIM_Gattu       = 72, // 'Gluttony'
	PIKIANIM_Gakkari     = 73, // 'Disappointed'
	PIKIANIM_Okoru       = 74, // 'Occur'?
	PIKIANIM_RotJump     = 75, // Rotate jump
	PIKIANIM_GWait1      = 76, // G wait (1)
	PIKIANIM_GWait2      = 77, // G wait (2)
	PIKIANIM_GFuri1      = 78, // 'G pretend (1)'
	PIKIANIM_GFuri2      = 79, // 'G pretend (2)'
	PIKIANIM_GNuke       = 80, // 'G escape'
	PIKIANIM_Jump_B1     = 81, // Jump B(1)
	PIKIANIM_Nuku_Fast   = 82, // 'Pluck' fast
	PIKIANIM_Nukare_Fast = 83, // 'Be plucked' fast
	PIKIANIM_Mizuage     = 84, // 'Water' something
	PIKIANIM_Sagasu      = 85, // 'Search'
	PIKIANIM_Osu         = 86, // 'Push'
	PIKIANIM_Osu_Walk    = 87, // 'Push walk'
	PIKIANIM_Noru        = 88, // 'Ride'
	PIKIANIM_ODead       = 89, // O(limar) dead
	PIKIANIM_COUNT,            // 90
};

/**
 * @brief TODO
 */
struct PaniPikiAnimator : public PaniAnimator {
	PaniPikiAnimator();

	char* getCurrentMotionName()
	{
		if (mMotionIdx >= 0) {
			return motionLabels[mMotionIdx];
		} else {
			return "NULL";
		}
	}

	static PaniMotionTable* createMotionTable();
	static char* motionLabels[90];

	// _30     = VTBL
	// _00-_54 = PaniAnimator
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0xAC.
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
	static PaniMotionTable* getMotionTable();

	// these are fake according to the DLL
	inline bool isFinished() { return mUpperAnimator.isFinished(); }
	inline f32 getAnimSpeed() { return mAnimSpeed; }
	inline void setAnimSpeed(f32 speed) { mAnimSpeed = speed; }

	// Names taken from linker file
	PaniPikiAnimator& getUpperAnimator() { return mUpperAnimator; }
	PaniPikiAnimator& getLowerAnimator() { return mLowerAnimator; }

	// remaining DLL inlines:
	// static void initPaniPikiAnimMgr();

	static PaniMotionTable* motionTable;

	f32 mAnimSpeed;                  // _00
	PaniPikiAnimator mUpperAnimator; // _04
	PaniPikiAnimator mLowerAnimator; // _58
};

#endif
