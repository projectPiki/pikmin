#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "types.h"
#include "CoreNode.h"
#include "Stream.h"
#include "SRT.h"
#include "Matrix4f.h"
#include "GfxObject.h"
#include "Parameters.h"
#include "Ayu.h"
#include "string.h"

struct AnimMgr;
struct BaseShape;
struct CmdStream;
struct Shape;

/**
 * @brief TODO
 */
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

	int mDataIndex; // _00
	int mDataSize;  // _04
	f32* mData;     // _08
};

/**
 * @brief TODO
 */
struct AnimCacheInfo {
	AnimCacheInfo();
	void updateContext();

	u8 _00[0x1c];
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

/**
 * @brief TODO
 */
struct AnimData : public CoreNode {

	AnimData()
	    : CoreNode("")
	{
		mAnimFlags = 0;
		_38        = 0;
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
	int _20;                          // _20
	int mAnimFlags;                   // _24
	int mNumJoints;                   // _28
	int _2C;                          // _2C
	int mNumFrames;                   // _30
	BaseShape* mModel;                // _34
	int _38;                          // _38
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
struct AnmobjInfo : public GfxobjInfo {
	virtual void detach(); // _0C

	// _00     = VTBL?
	// _00-_20 = GfxobjInfo?
	AnimData* mAnimation; // _20
};

/**
 * @brief TODO
 */
struct AnimKey {
	AnimKey()
	{
		_00   = 0;
		_04   = 0;
		_06   = 0;
		_07   = 0;
		mPrev = mNext = nullptr;
	}

	inline void insertAfter(AnimKey* key)
	{
		key->mNext   = mNext;
		key->mPrev   = this;
		mNext->mPrev = key;
		mNext        = key;
	}

	inline void add(AnimKey* key) { mPrev->insertAfter(key); }

	inline f32 getKeyValue() { return _00; }

	int _00;        // _00, unknown
	s16 _04;        // _04
	u8 _06;         // _06
	u8 _07;         // _07
	AnimKey* mPrev; // _08
	AnimKey* mNext; // _0C
};

/**
 * @brief TODO
 */
struct AnimInfo : public CoreNode {

	enum AnimInfoFlags {
		FLAG_Unk1 = 0x1,
		FLAG_Unk2 = 0x2,
	};

	/**
	 * @brief Fabricated. Offsets relative to AnimInfo for convenience.
	 */
	struct AnimInfoParams : public Parameters {
		inline AnimInfoParams()
		    : mFlags(this, 2, 0, 0, "p00", nullptr)
		    , mSpeed(this, 30.0f, 0.0f, 0.0f, "spd", nullptr)
		{
		}

		// _14-_18 = Parameters
		Parm<int> mFlags; // _18, p00
		Parm<f32> mSpeed; // _28, spd
	};

	AnimInfo(AnimMgr*, AnimData*);

	void checkAnimData();
	void setIndex();
	void setAnimFlags(u32);
	int countAKeys();
	int countIKeys();
	int countEKeys();
	AnimKey* getInfoKey(int);
	AnimKey* getEventKey(int);
	int getKeyValue(int);
	void doread(RandomAccessStream&, int);
	void updateAnimFlags();
	void addKeyFrame();

	// unused/inlined:
	void initAnimData(AnimData*);

	inline f32 getAnimSpeed() { return mParams.mSpeed(); }

	// _00     = VTBL
	// _00-_14 = CoreNode
	AnimInfoParams mParams; // _14
	AnimKey _38;            // _38
	AnimKey mEventKeys;     // _48
	AnimKey mInfoKeys;      // _58
	AnimData* mData;        // _68
	u8 _6C[0x4];            // _6C, unknown
	AnimMgr* mMgr;          // _70
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
struct Animator {
	void startAnim(int, int, int, int);
	void updateContext();

	// _30 = VTBL
	AnimMgr* mMgr;         // _00
	AnimContext* mContext; // _04
	u8 _08[0x10];          // _08, unknown
	int _18;               // _18
	int _1C;               // _1C
	int _20;               // _20
	int _24;               // _24
	AnimInfo* mAnimInfo;   // _28
	f32 mCurrentFrame;     // _2C

	virtual void changeContext(AnimContext*); // _08
	virtual void animate(f32);                // _0C
	virtual void finishOneShot();             // _10
	virtual void finishLoop();                // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0xB8.
 */
struct AnimMgr : public CoreNode {

	/**
	 * @brief Fabricated. Offsets relative to AnimMgr for convenience.
	 */
	struct AnimMgrParams : public Parameters {
		inline AnimMgrParams()
		    : _18(this, 2, 0, 0, "a00", nullptr)
		    , _28(this, *(String*)(0), *(String*)(0), *(String*)(0), "a01", nullptr)
		{
		}

		// _14-_18 = Parameters
		Parm<int> _18;    // _18
		Parm<String> _28; // _28
	};

	AnimMgr(Shape*, char*, int, char*);

	virtual void read(RandomAccessStream&); // _0C

	void loadAnims(char*, char*);
	AnimInfo* addAnimation(char*, bool);
	int countAnims();

	// unused/inlined:
	void findAnim(int);

	// _00     = VTBL
	// _00-_14 = CoreNode
	AnimMgrParams mParams; // _14
	u8 _3C[0x4];           // _3C, unknown
	AnimInfo mAnimList;    // _40, parent of list of animations
	u8 _B4;                // _B4, unknown
};

/**
 * @brief TODO
 */
struct AnimFrameCacher {
	AnimFrameCacher(int);
	void updateInfo(AnimCacheInfo*);
	void removeOldest();
	void cacheFrameSpace(int, AnimCacheInfo*);
};

#endif
