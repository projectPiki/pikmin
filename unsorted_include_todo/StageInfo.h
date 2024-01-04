#ifndef _STAGEINFO_H
#define _STAGEINFO_H

/**
 * .obj __vt__9StageInfo, global
 * .4byte __RTTI__9StageInfo
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__9StageInfoFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct StageInfo : public ANode {
	virtual void read(RandomAccessStream&); // _0C

	void parseGenerators(CmdStream*);
};

#endif
