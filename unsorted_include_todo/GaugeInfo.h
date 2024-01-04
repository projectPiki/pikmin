#ifndef _GAUGEINFO_H
#define _GAUGEINFO_H

/**
 * .obj __vt__9GaugeInfo, weak
 * .4byte __RTTI__9GaugeInfo
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

/**
 * @brief TODO
 */
struct GaugeInfo : public ANode, public CoreNode {
};

#endif
