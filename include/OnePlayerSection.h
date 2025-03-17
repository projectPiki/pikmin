#ifndef _ONEPLAYERSECTION_H
#define _ONEPLAYERSECTION_H

#include "types.h"
#include "Section.h"
#include "BaseInf.h"

struct CmdStream;

/**
 * @brief IDs for each stage, as per stages.ini.
 *
 * @note There are also test maps and teki stages, but these don't have IDs.
 */
enum StageID {
	STAGE_START,
	STAGE_Practice  = STAGE_START, // Impact Site
	STAGE_Forest    = 1,           // Forest of Hope
	STAGE_Cave      = 2,           // Forest Navel
	STAGE_Yakushima = 3,           // Distant Spring
	STAGE_Last      = 4,           // Final Trial
	STAGE_INVALID   = 5,           // default set on load, invalid
	STAGE_END       = STAGE_INVALID,
	STAGE_COUNT     = STAGE_INVALID,
	STAGE_LASTVALID = STAGE_Last, // last valid loadable stage
};

/**
 * @brief IDs for each stage, as per stages.ini.
 *
 * @note There are also test maps and teki stages, but these don't have IDs.
 */
enum ChalStageID {
	CHALSTAGE_Practice  = 0, // Impact Site CM
	CHALSTAGE_Forest    = 1, // Forest of Hope CM
	CHALSTAGE_Cave      = 2, // Forest Navel CM
	CHALSTAGE_Yakushima = 3, // Distant Spring CM
	CHALSTAGE_Last      = 4, // Final Trial CM
	// ...
	CHALSTAGE_INVALID = 7, // default set on load, invalid
};

/**
 * @brief TODO
 */
struct GenFileInfo : public CoreNode {
	inline GenFileInfo()
	    : CoreNode("")
	{
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	u8 mStartDay; // _14
	u8 mEndDay;   // _15
	u8 mDuration; // _16
};

/**
 * @brief TODO
 */
struct StageInfo : public CoreNode {
	inline StageInfo()
	    : CoreNode("stageInfo")
	{
		mStageIndex     = 0;
		mStageID        = STAGE_INVALID;
		mChalStageID    = CHALSTAGE_INVALID;
		mHasInitialised = 0;
		mFileInfoList.initCore("");
	}

	virtual void read(RandomAccessStream&); // _0C

	void parseGenerators(CmdStream*);

	// unused/inlined:
	void write(RandomAccessStream&);

	inline StageInfo* getChild() { return static_cast<StageInfo*>(mChild); }

	// _00     = VTBL
	// _00-_14 = CoreNode
	char* mStageName;          // _14
	char* mFileName;           // _18
	BOOL mIsVisible;           // _1C
	BOOL mHasInitialised;      // _20
	u16 mStageIndex;           // _24, order stage is loaded in from file
	u16 mStageID;              // _26, see StageID enum
	u16 mChalStageID;          // _28, see ChalStageID enum
	StageInf mStageInf;        // _2C
	GenFileInfo mFileInfoList; // _90
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct OnePlayerSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
