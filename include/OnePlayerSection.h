#ifndef _ONEPLAYERSECTION_H
#define _ONEPLAYERSECTION_H

#include "types.h"
#include "Section.h"
#include "BaseInf.h"

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
	u8 _14; // _14
	u8 _15; // _15
	u8 _16; // _16
};

/**
 * @brief TODO
 */
struct StageInfo : public CoreNode {
	virtual void read(RandomAccessStream&); // _0C

	void parseGenerators(CmdStream*);

	// unused/inlined:
	void write(RandomAccessStream&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	u8 _14[0x20 - 0x14];       // _14, unknown
	u32 _20;                   // _20, unknown
	u16 _24;                   // _24
	u16 _26;                   // _26
	u16 _28;                   // _28
	StageInf mStageInf;        // _2C
	GenFileInfo mFileInfoList; // _90
};

/**
 * @brief TODO
 */
struct OnePlayerSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

#endif
