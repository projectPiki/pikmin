#ifndef _ONEPLAYERSECTION_H
#define _ONEPLAYERSECTION_H

#include "BaseInf.h"
#include "GlobalGameOptions.h"
#include "Section.h"
#include "types.h"

struct CmdStream;

/**
 * @brief Basic context on what in-game days a pattern/file of generators will spawn on.
 *
 * The days are a bit confusing, but they serve subtly different purposes.
 * A generator will only activate if its parent map is entered between mFirstSpawnDay and mLastSpawnDay inclusively.
 * If it's activated, the generator will spawn objects any day that map is entered up until (and including) mDayLimit.
 * If mDayLimit is -1, it will spawn forever if it's been activated at least once between mFirstSpawnDay and mLastSpawnDay.
 * (In reality, mLastSpawnDay and mDayLimit are always the same.)
 *
 * @note Size: 0x17.
 */
struct GenFileInfo : public CoreNode {

	/// Constructs an empty generator file info. Trivial.
	inline GenFileInfo()
	    : CoreNode("")
	{
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	u8 mFirstSpawnDay; ///< _14, earliest day generator will activate (if map is entered).
	u8 mLastSpawnDay;  ///< _15, latest day generator will activate (if map is entered).
	u8 mDayLimit;      ///< _16, day generator will stop spawning if previously activated (-1 = no limit).
};

/**
 * @brief Basic information about a stage (area/course/map) read from its stages/[name].ini file.
 *
 * Also holds information about its pikmin sprouts and generators.
 *
 * @note Size: 0xA8.
 */
struct StageInfo : public CoreNode {

	/// Constructed `StageInfo` is for a non-Challenge Mode test map until otherwise overwritten.
	inline StageInfo()
	    : CoreNode("stageInfo")
	{
		mStageIndex     = 0;
		mStageID        = STAGE_TESTMAP;
		mChalStageID    = CHALSTAGE_NOT;
		mHasInitialised = FALSE;
		mGenFileList.initCore("");
	}

	virtual void read(RandomAccessStream&); // _0C

	void parseGenerators(CmdStream*);

	// unused/inlined:

	void write(RandomAccessStream&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	immut char* mStageName;   ///< _14, name of stage from stages file.
	immut char* mFileName;    ///< _18, file to read stage settings from - stages/[name].ini
	BOOL mIsVisible;          ///< _1C, whether stage should be added to the map list menu or not.
	BOOL mHasInitialised;     ///< _20, whether stage has been initialised for the first time or not.
	u16 mStageIndex;          ///< _24, order stage is loaded in from file.
	u16 mStageID;             ///< _26, identifier for stage - see `StageID` enum.
	u16 mChalStageID;         ///< _28, identifier for challenge mode stage - see `StageID` enum.
	StageInf mStageInf;       ///< _2C, manages what pikmin sprouts are on the stage, stored between days.
	GenFileInfo mGenFileList; ///< _90, list of generator file information, controlling what spawns on what days.
};

/**
 * @brief Game section for story mode and challenge mode.
 *
 * Has subsections to control different states within it, see `OnePlayerSectionID` enum:
 *
 * - `GameSetupSection` - load-in from title screen to file select or challenge mode - performs basic load and setup.
 *
 * - `CardSelectSection` - file select screen for story mode, or interediate load into challenge mode.
 *
 * - `IntroGameSection` - intro crash landing cutscene on new file start.
 *
 * - `MapSelectSection` - world map selection screen and challenge course selection screen.
 *
 * - `NewPikiGameSection` - actual gameplay (story and challenge mode) - has a subsubsection `GameCoreSection` for more complex actions.
 *
 * - `GameCourseClearSection` - inaccessible in retail - seems to be a debug section with access to multiple others.
 *
 * - `GameStageClearSection` - inaccessible in retail.
 *
 * - `GameCreditsSection` - inaccessible outside of the E3 demo.
 *
 * - `GameExitSection` - ending gameplay, handles cleanup and re-exiting to map select or title screen.
 *
 * @note Size: 0x20.
 */
struct OnePlayerSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
