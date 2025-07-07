#ifndef _FLOWCONTROLLER_H
#define _FLOWCONTROLLER_H

#include "OnePlayerSection.h"
#include "types.h"

struct StageInfo;
struct Navi;

/**
 * @brief TODO
 *
 * @note Size: 0x25C.
 */
struct FlowController {
	inline FlowController()
	{
		_244       = 0;
		mNaviOnMap = 0;
	}

	void readMapList(char*);

	// unused/inlined:
	void setStage(char*);

	// TODO: members
	StageInfo mRootInfo;           // _00
	StageInfo* mCurrentStage;      // _A8
	u8 _AC[0x4];                   // _AC, unknown
	char mAnimationTestPath[0x80]; // _B0
	char mStagePath1[0x80];        // _130
	char mStagePath2[0x80];        // _1B0, identical to above
	int mNaviOnMap;                // _230, unknown
	int mGameEndCondition;         // _234
#if defined(VERSION_GPIP01_00)     //
	int _238PAL;                   // _238
	int _23CPAL;                   //
#endif                             //
	u32 mDayOverSeqStarted;        // _238
	u32 _23C;                      // _23C
	int _240;                      // _240
	int _244;                      // _244
	u32 _248;                      // _248, unknown
	u32 _24C;                      // _24C, unknown
	u32 _250;                      // _250, unknown
	u32 _254;                      // _254, unknown
	u32 _258;                      // _258, unknown
};

extern FlowController flowCont;

#endif
