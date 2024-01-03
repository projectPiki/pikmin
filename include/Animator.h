#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "types.h"
#include "CoreNode.h"

struct AnimMgr;
struct BaseShape;
struct CmdStream;
struct Shape;

/**
 * @brief TODO
 */
struct AnimDataInfo {
	AnimDataInfo();

	// TODO: members
};

/**
 * @brief TODO
 */
struct AnimData : public CoreNode {

	virtual void extractSRT(struct SRT&, int, AnimDataInfo*, f32);                  // _10
	virtual void makeAnimSRT(int, struct Matrix4f*, Matrix4f*, AnimDataInfo*, f32); // _14
	virtual void detach();                                                          // _18
	virtual void writeType(RandomAccessStream&);                                    // _1C

	void checkMask();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct AnimDca : public AnimData {
	virtual void read(RandomAccessStream&); // _0C

	void parse(CmdStream*);
	void getAnimInfo(CmdStream*);

	// _00     = VTBL
	// _00-_14 = AnimData
	// TODO: members
};

/**
 * @brief TODO
 */
struct AnimDck : public AnimData {
	AnimDck(BaseShape*, int);

	virtual void read(RandomAccessStream&);                                  // _0C
	virtual void extractSRT(SRT&, int, AnimDataInfo*, f32);                  // _10
	virtual void makeAnimSRT(int, Matrix4f*, Matrix4f*, AnimDataInfo*, f32); // _14

	void parse(CmdStream*);
	void getAnimInfo(CmdStream*);

	// _00     = VTBL
	// _00-_14 = AnimData
	// TODO: members
};

/**
 * @brief TODO
 */
struct AnimInfo : public CoreNode {
	AnimInfo(AnimMgr*, AnimData*);

	void checkAnimData();
	void setIndex();
	void setAnimFlags(u32);
	void countAKeys();
	void countIKeys();
	void countEKeys();
	void getInfoKey(int);
	void getEventKey(int);
	void getKeyValue(int);
	void doread(RandomAccessStream&, int);
	void updateAnimFlags();
	void addKeyFrame();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct AnimContext {
	AnimContext();

	// _0C = VTBL
	int mFrameCount;   // _00
	f32 mCurrentFrame; // _04
	f32 _08;           // _08

	virtual void animate(f32 time); // _08
};

/**
 * @brief TODO
 */
struct AnimKey {
	AnimKey();

	u32 _00; // _00, unknown
	u16 _04; // _04
	u8 _06;  // _06
	u8 _07;  // _07
	u32 _08; // _08, unknown
	u32 _0C; // _0C, unknown
};

/**
 * @brief TODO
 */
struct Animator {
	void startAnim(int, int, int, int);
	void updateContext();

	// _30 = VTBL
	u8 _00[0x18]; // _00, unknown
	int _18;      // _18
	int _1C;      // _1C
	int _20;      // _20
	int _24;      // _24
	u32 _28;      // _28, unknown
	f32 _2C;      // _2C

	virtual void changeContext(AnimContext*); // _08
	virtual void animate(f32);                // _0C
	virtual void finishOneShot();             // _10
	virtual void finishLoop();                // _14
};

/**
 * @brief TODO
 */
struct AnimMgr : public CoreNode {
	AnimMgr(Shape*, char*, int, char*);

	virtual void read(RandomAccessStream&); // _0C

	void loadAnims(char*, char*);
	void addAnimation(char*, bool);
	void countAnims();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

#endif
