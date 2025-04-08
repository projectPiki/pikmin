#ifndef _TAI_AEFFECT_H
#define _TAI_AEFFECT_H

#include "types.h"
#include "TAI/Action.h"
#include "EffectMgr.h"
#include "SoundID.h"

struct Vector3f;
struct CollPart;

/**
 * @brief TODO
 */
struct TAIAeffCloudOfDust : public TaiAction {
	TAIAeffCloudOfDust(int nextState, EffectMgr::effTypeTable effID, f32 sinkThreshold, int footNum, int jointID0, int jointID1,
	                   int jointID2, int jointID3)
	    : TaiAction(nextState)
	{
		init(effID, true, SOUND_NULL, RUMBLE_NONE, sinkThreshold, footNum, jointID0, jointID1, jointID2, jointID3);
	}

	// DLL inlines to do:
	TAIAeffCloudOfDust(int p1, EffectMgr::effTypeTable p2, int p3, f32 p4, int p5, int p6, int p7, int p8, int p9);
	TAIAeffCloudOfDust(int p1, EffectMgr::effTypeTable p2, int p3, int p4, f32 p5, int p6, int p7, int p8, int p9, int p10);

	virtual void start(Teki&);                 // _08
	virtual bool act(Teki&);                   // _10
	virtual void setType(Vector3f&, int, int); // _1C

	void init(EffectMgr::effTypeTable effID, bool p2, int soundID, int rumbleType, f32 sinkThreshold, int footNum, int jointID0,
	          int jointID1, int jointID2, int jointID3);
	void createCloudOfDust(Teki&, int);
	CollPart* getCollPart(Teki&, int);

	static const int RUMBLE_NONE;

	// _04     = VTBL
	// _00-_08 = TaiAction
	int* mFootJointID;                   // _08
	int mFootNum;                        // _0C
	f32 mFootSinkThreshold;              // _10
	EffectMgr::effTypeTable mEffectType; // _14
	int mSoundID;                        // _18
	int mRumbleType;                     // _1C
	bool _20;                            // _20
};

#endif
