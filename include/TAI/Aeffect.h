#ifndef _TAI_AEFFECT_H
#define _TAI_AEFFECT_H

#include "EffectMgr.h"
#include "SoundID.h"
#include "TAI/Action.h"
#include "types.h"

struct Vector3f;
struct CollPart;

/**
 * @brief TODO
 */
struct TAIAeffCloudOfDust : public TaiAction {
public:
	TAIAeffCloudOfDust(int nextState, EffectMgr::effTypeTable effID, f32 sinkThreshold, int footNum, int jointID0, int jointID1,
	                   int jointID2, int jointID3)
	    : TaiAction(nextState)
	{
		init(effID, true, SOUND_NULL, RUMBLE_NONE, sinkThreshold, footNum, jointID0, jointID1, jointID2, jointID3);
	}

	TAIAeffCloudOfDust(int nextState, EffectMgr::effTypeTable effID, int soundID, f32 sinkThreshold, int footNum, int jointID0,
	                   int jointID1, int jointID2, int jointID3)
	    : TaiAction(nextState)
	{
		init(effID, true, soundID, RUMBLE_NONE, sinkThreshold, footNum, jointID0, jointID1, jointID2, jointID3);
	}

	TAIAeffCloudOfDust(int nextState, EffectMgr::effTypeTable effID, int soundID, int rumbleID, f32 sinkThreshold, int footNum,
	                   int jointID0, int jointID1, int jointID2, int jointID3)
	    : TaiAction(nextState)
	{
		init(effID, true, soundID, rumbleID, sinkThreshold, footNum, jointID0, jointID1, jointID2, jointID3);
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
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
