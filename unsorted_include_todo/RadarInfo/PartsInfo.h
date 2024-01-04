#ifndef _RADARINFO_PARTSINFO_H
#define _RADARINFO_PARTSINFO_H

/**
 * .obj __vt__Q29RadarInfo9PartsInfo, weak
 * .4byte __RTTI__Q29RadarInfo9PartsInfo
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

namespace RadarInfo {
/**
 * @brief TODO
 */
struct PartsInfo : public ANode, public CoreNode {

	void getPos();
};
} // namespace RadarInfo

#endif
