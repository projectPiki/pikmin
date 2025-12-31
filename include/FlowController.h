#ifndef _FLOWCONTROLLER_H
#define _FLOWCONTROLLER_H

#include "OnePlayerSection.h"
#include "types.h"

struct StageInfo;
struct Navi;

/**
 * @brief Type of ending reached (in order to play the correct credit movie when required).
 */
enum EndingType {
	ENDING_None    = 0, ///< 0, no ending triggered (yet).
	ENDING_Neutral = 1, ///< 1, neutral ending (>= 25 parts, but not 30).
	ENDING_Happy   = 2, ///< 2, good ending (all 30 parts).
};

/**
 * @brief Flags for controlling when gameplay is forced to end. Used by FlowController.
 */
enum GameEndFlag {
	GAMEEND_None             = 0, ///< 0, default reason, no other specific handling required.
	GAMEEND_PikminExtinction = 1, ///< 1, you killed all your pikmin!
	GAMEEND_NaviDown         = 2, ///< 2, your captain has no health!
	GAMEEND_Clear            = 3, ///< 3, unused navi "clear" state results in this. Never handled.
};

/**
 * @brief Possible reasons to end gameplay. Used when passing messages.
 */
enum GameEndCause {
	ENDCAUSE_PikminZero = 0, ///< 1, you killed all your pikmin!
	ENDCAUSE_NaviDown   = 1, ///< 2, your captain has no health!
};

/**
 * @brief Specialised game flow controller for single-player (story or challenge mode) gameplay.
 *
 * Has a lot of unused features, likely from cut elements of gameplay or debugging, including the unused NaviDemoSunsetState.
 *
 * @note Size: 0x25C.
 */
struct FlowController {

	/// Constructs a bare-bones single-player game flow controller.
	inline FlowController()
	{
		mEndingType   = ENDING_None;
		mIsVersusMode = FALSE;
	}

	void readMapList(immut char* fileName);

	void setStage(immut char* fileName);

	StageInfo mStageList;          ///< _00, list of all stages read in from file (stages/stages.ini).
	StageInfo* mCurrentStage;      ///< _A8, pointer to the current stage.
	u8 _AC[0x4];                   ///< _AC, unknown/unused.
	char mMapModelFilePath[0x80];  ///< _B0, path to .mod file for current stage's map.
	char mCurrStageFilePath[0x80]; ///< _130, path to .ini file for current stage.
	char mDoorStageFilePath[0x80]; ///< _1B0, likely stage unused "door" item would've led to - same as above + unused in reality.
	BOOL mIsVersusMode;            ///< _230, indicator of an (unimplemented) VS mode - never TRUE because we never spawn a second navi.
	int mGameEndFlag;              ///< _234, type of situation forcing the day/gameplay to end - see `GameEndFlag` enum.
#if defined(VERSION_GPIP01_00)     ///
	BOOL mIsDayEndSkippable;       ///< _238, day ends from extinction and navi down aren't skippable.
	BOOL mIsDayEndSkipped;         ///< _23C, has day end cutscene been skipped?
#endif                             ///
	BOOL mIsDayEndSeqStarted;      ///< _238, are we in the day end sequence? Tracked but never referenced.
	BOOL mIsSunsetWhistleActive;   ///< _23C, has Olimar blown his whistle in the (unused) sunset state? Tracked but never referenced.
	BOOL mIsSunsetStateForceEnded; ///< _240, did the (unused) sunset state get skipped or timed out? Tracked but never referenced.
	int mEndingType;               ///< _244, whether we've triggered an ending - see `EndingType` enum.
	u32 mClearStatePikiCount;      ///< _248, how many Pikmin we end with in our squad in the (unused) NaviClearState.
	u32 mNaviSeedCount;            ///< _24C, largely unused, related to unused SeedItem collection.
	u32 _250;                      ///< _250, unknown - only ever set to 0. Corresponds to 0x730 in Navi.
	u32 _254;                      ///< _254, unknown - only ever set to 0.
	u32 _258;                      ///< _258, unknown - only ever set to 0.
};

extern FlowController flowCont;

#endif
