#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "types.h"
#include "CoreNode.h"
#include "Stream.h"
#include "Vector3f.h"
#include "Matrix4f.h"
#include "Stream.h"

struct AnimMgr;
struct BaseShape;
struct CmdStream;
struct Shape;

struct DataChunk {
	DataChunk()
	{
		mDataIndex = 0;
		mDataSize  = 0;
		mData      = nullptr;
	}

	void addData(f32);
	void setDataSize(int size)
	{
		mData     = new f32[size];
		mDataSize = size;
	}

	void read(RandomAccessStream& stream)
	{
		setDataSize(stream.readInt());
		for (int i = 0; i < mDataSize; i++) {
			mData[i] = stream.readFloat();
		}
	}

	int mDataIndex;
	int mDataSize; // _04
	f32* mData;    // _08
};

struct AnimCacheInfo {
	AnimCacheInfo();
	void updateContext();

	u8 _00[0x1c];
};

struct SRT {
	Vector3f mScale;     // _00
	Vector3f mRotate;    // _0C
	Vector3f mTranslate; // _18
};

/**
 * @brief TODO
 */
struct AnimParam {
	int mEntryNum;   // _00
	int mDataOffset; // _04
	int mFlags;      // _08, controls if 3 or 4 values in block, maybe more stuff?
};

/**
 * @brief TODO
 */
struct AnimDataInfo {
	AnimDataInfo();

	AnimParam mScale[3];       // _00, x y and z
	AnimParam mRotation[3];    // _24, x y and z
	AnimParam mTranslation[3]; // _48, x y and z
	int mGroupIndex;           // _6C
	int mParentJntIndex;       // _70
	Matrix4f mMtx;             // _74
	SRT mSRT;                  // _B4
	u16 mFlags;                // _D8
};

static f32 extract(f32, AnimParam&, DataChunk&);

/**
 * @brief TODO
 */
struct AnimData : public CoreNode {

	AnimData()
	    : CoreNode("")
	{
		_24 = 0;
		_38 = 0;
	}

	virtual void extractSRT(struct SRT&, int, AnimDataInfo*, f32);                  // _10
	virtual void makeAnimSRT(int, struct Matrix4f*, Matrix4f*, AnimDataInfo*, f32); // _14
	virtual void detach();                                                          // _18
	virtual void writeType(RandomAccessStream&);                                    // _1C

	void checkMask();
	void initData();

	// _00     = VTBL
	// _00-_14 = CoreNode
	DataChunk* mScaleDataBlock;       // _14
	DataChunk* mRotateDataBlock;      // _18
	DataChunk* mTranslationDataBlock; // _1C
	int _20;
	int _24;
	int mNumJoints; // _28
	int _2C;
	int mNumFrames;    // _30
	BaseShape* mModel; // _34
	int _38;
};

/**
 * @brief TODO
 */
struct AnimDca : public AnimData {
	virtual void read(RandomAccessStream&); // _0C

	void parse(CmdStream*);
	void getAnimInfo(CmdStream*);

	// _00     = VTBL
	// _00-_38 = AnimData
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
	// _00-_38 = AnimData
	AnimDataInfo* mAnimInfo;   // _3C
	AnimCacheInfo* mCacheInfo; // _40
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

	// unused/inlined:
	void initAnimData(AnimData*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct AnimContext {
	AnimContext()
	    : mData(0)
	    , mCurrentFrame(0.0f)
	    , _08(30.0f)
	{
	}

	// _0C = VTBL
	AnimData* mData;   // _00
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
	AnimInfo* addAnimation(char*, bool);
	void countAnims();

	// unused/inlined:
	void findAnim(int);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

template <typename T>
struct PVWAnimInfo1 {
	void read(RandomAccessStream&);
};

template <typename T>
struct PVWAnimInfo3 {
	void read(RandomAccessStream&);
};

struct AnimFrameCacher {
	AnimFrameCacher(int);
	void updateInfo(AnimCacheInfo*);
	void removeOldest();
	void cacheFrameSpace(int, AnimCacheInfo*);
};

#endif
