#ifndef _ANIMDATA_H
#define _ANIMDATA_H

/**
 * .obj __vt__8AnimData, global
 * .4byte __RTTI__8AnimData
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte extractSRT__8AnimDataFR3SRTiP12AnimDataInfof
 * .4byte makeAnimSRT__8AnimDataFiP8Matrix4fP8Matrix4fP12AnimDataInfof
 * .4byte detach__8AnimDataFv
 * .4byte writeType__8AnimDataFR18RandomAccessStream
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

/**
 * @brief TODO
 */
struct AnimData : public ANode, public CoreNode {
	virtual void extractSRT(SRT &, int, AnimDataInfo *, float);                    // _10
	virtual void makeAnimSRT(int, Matrix4f *, Matrix4f *, AnimDataInfo *, float);  // _14
	virtual void detach();                                                         // _18
	virtual void writeType(RandomAccessStream &);                                  // _1C

};

#endif
