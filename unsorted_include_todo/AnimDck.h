#ifndef _ANIMDCK_H
#define _ANIMDCK_H

/**
 * .obj __vt__7AnimDck, global
 * .4byte __RTTI__7AnimDck
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__7AnimDckFR18RandomAccessStream
 * .4byte extractSRT__7AnimDckFR3SRTiP12AnimDataInfof
 * .4byte makeAnimSRT__7AnimDckFiP8Matrix4fP8Matrix4fP12AnimDataInfof
 * .4byte detach__8AnimDataFv
 * .4byte writeType__8AnimDataFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct AnimData {
	virtual void _08() = 0;                                                    // _08
	virtual void read(RandomAccessStream&);                                    // _0C
	virtual void extractSRT(SRT&, int, AnimDataInfo*, float);                  // _10
	virtual void makeAnimSRT(int, Matrix4f*, Matrix4f*, AnimDataInfo*, float); // _14
	virtual void detach();                                                     // _18
	virtual void writeType(RandomAccessStream&);                               // _1C
};

/**
 * @brief TODO
 */
struct AnimDck : public ANode, public AnimData {
	virtual void read(RandomAccessStream&);                                    // _0C
	virtual void extractSRT(SRT&, int, AnimDataInfo*, float);                  // _10
	virtual void makeAnimSRT(int, Matrix4f*, Matrix4f*, AnimDataInfo*, float); // _14
};

#endif
