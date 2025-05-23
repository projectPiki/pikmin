#ifndef _ONEPLAYERSECTION_H
#define _ONEPLAYERSECTION_H

#include "types.h"
#include "Section.h"
#include "BaseInf.h"
#include "GlobalGameOptions.h"

struct CmdStream;

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
