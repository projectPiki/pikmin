#ifndef _PELLETANIMINFO_H
#define _PELLETANIMINFO_H

/**
 * .obj __vt__14PelletAnimInfo, global
 * .4byte __RTTI__14PelletAnimInfo
 * .4byte 0
 * .4byte __RTTI__14PelletAnimInfo
 * .4byte 0xFFFFFFFC
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@4@read__14PelletAnimInfoFR18RandomAccessStream"
 * .4byte read__14PelletAnimInfoFR18RandomAccessStream
 */

struct ANode {
	virtual void _08() = 0;        // _08
	virtual void _0C() = 0;        // _0C
	virtual void getAgeNodeType(); // _10 (weak)
};

/**
 * @brief TODO
 */
struct PelletAnimInfo : public ANode {
	virtual void read(RandomAccessStream&); // _18
};

#endif
