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
#include "String.h"
#include "Texture.h"
#include "CmdStream.h"
#include "system.h"

struct AnimMgr;
struct BaseShape;
struct CmdStream;
struct Shape;

/**
 * @brief TODO
 */
enum AnimInfoFlags {
	ANIMFLAG_Unk1 = 1 << 0, // 0x1
	ANIMFLAG_Unk2 = 1 << 1, // 0x2
	ANIMFLAG_Unk3 = 1 << 2, // 0x4
};

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

	void addData(f32 data)
	{
		if (mDataIndex >= mDataSize) {
			mDataSize    = mDataIndex + 0x800;
			f32* newData = new f32[mDataSize];

			if (mDataIndex) {
				memcpy(newData, mData, mDataIndex * sizeof(f32));
			}

			delete mData;
			mData = newData;
		}

		mData[mDataIndex++] = data;
	}
	void setDataSize(int size)
	{
		mData     = new f32[size];
		mDataSize = size;
	}

	void read(RandomAccessStream& stream)
	{
		int dataSize = stream.readInt();
		setDataSize(dataSize);
		for (int i = 0; i < dataSize; i++) {
			mData[i] = stream.readFloat();
		}
	}

	void getData(CmdStream* stream)
	{
		stream->getToken(true);
		int dataSize;
		int tokenCount = 0;

		while (!stream->endOfCmds() && !stream->endOfSection()) {
			if ((tokenCount & 7) == 0) {
				stream->getToken(true);
				if (stream->isToken("size")) {
					const char* token = stream->getToken(true);
					sscanf(token, "%d", &dataSize);
					setDataSize(dataSize);
					stream->getToken(true);
				}
			}

			const char* token = stream->getToken(true);
			f32 value;
			sscanf(token, "%f", &value);
			addData(value);
			++tokenCount;
		}

		if (!stream->endOfCmds()) {
			stream->getToken(true);
		}
	}

	int mDataIndex; // _00
	int mDataSize;  // _04
	f32* mData;     // _08
};

/**
 * @brief TODO
 */
struct AnimCacheInfo : public CacheInfo {
	AnimCacheInfo() { initData(); }

	void initData()
	{
		mBoneMatrices   = 0;
		mCachedMtxBlock = 0;
	}

	// _00 - _0C = CacheInfo
	u32 _0C;                    // _0C
	CacheInfo* mCachedMtxBlock; // _10
	Matrix4f* mBoneMatrices;    // _14
	Matrix4f** mBoneMtxList;    // _18
};

/**
 * @brief Animation parameter structure.
 */
struct AnimParam {
	int mEntryNum;   // _00
	int mDataOffset; // _04
	int mFlags;      // _08, controls if 3 or 4 values in block, maybe more stuff?
};

/**
 * @brief Information about animation data, read in from a file.
 */
struct AnimDataInfo {
	AnimDataInfo() { mFlags = 0; }

	AnimParam mScale[3];       // _00, x y and z
	AnimParam mRotation[3];    // _24, x y and z
	AnimParam mTranslation[3]; // _48, x y and z
	int mGroupIndex;           // _6C
	AnimDataInfo* mParentInfo; // _70
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

	AnimData(char* name)
	    : CoreNode(name)
	{
		mAnimFlags = 0;
		_38        = 0;
	}

	virtual void extractSRT(struct SRT&, int, AnimDataInfo*, f32);                  // _10
	virtual void makeAnimSRT(int, struct Matrix4f*, Matrix4f*, AnimDataInfo*, f32); // _14
	virtual void detach();                                                          // _18
	virtual void writeType(RandomAccessStream&) { }                                 // _1C

	void checkMask();
	void initData();

	// _00     = VTBL
	// _00-_14 = CoreNode
	DataChunk* mScaleDataBlock;       // _14
	DataChunk* mRotateDataBlock;      // _18
	DataChunk* mTranslationDataBlock; // _1C
	u16* mAnimJointIndices;           // _20
	int mAnimFlags;                   // _24
	int mJointCount;                  // _28
	int mActiveJointCount;            // _2C
	int mTotalFrameCount;             // _30
	BaseShape* mModel;                // _34
	int _38;                          // _38
	AnimDataInfo* mAnimInfo;          // _3C
	AnimCacheInfo* mAnimInfoList;     // _40
};

/**
 * @brief TODO
 */
struct AnimDca : public AnimData {
	AnimDca(BaseShape*, int)
	    : AnimData()
	{
	}

	AnimDca(char* name)
	    : AnimData(StdSystem::stringDup(name))
	{
	}

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
	AnimDck(char* name)
	    : AnimData(StdSystem::stringDup(name))
	{
	}

	virtual void read(RandomAccessStream&);                                  // _0C
	virtual void extractSRT(SRT&, int, AnimDataInfo*, f32);                  // _10
	virtual void makeAnimSRT(int, Matrix4f*, Matrix4f*, AnimDataInfo*, f32); // _14

	void parse(CmdStream*);
	void getAnimInfo(CmdStream*);

	// _00     = VTBL
	// _00-_44 = AnimData
};

/**
 * @brief TODO
 */
struct AnmobjInfo : public GfxobjInfo {
	AnmobjInfo()
	    : mAnimation(nullptr)
	{
	}

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
		mKeyframeIndex = 0;
		mEventKeyType  = 0;
		mValue         = 0;
		mEventId       = 0;
		mPrev = mNext = nullptr;
	}

	AnimKey(int index, int value)
	{
		mKeyframeIndex = index;
		mValue         = value;
		mPrev          = nullptr;
		mNext          = nullptr;
	}

	void insertAfter(AnimKey* key)
	{
		key->mNext   = mNext;
		key->mPrev   = this;
		mNext->mPrev = key;
		mNext        = key;
	}

	// these are both fake according to the DLL - may be inlines for AnimInfo?
	inline void add(AnimKey* key) { mPrev->insertAfter(key); }
	inline f32 getKeyValue() { return mKeyframeIndex; }

	// DLL inlines to do:
	void remove();

	int mKeyframeIndex; // _00, unknown
	s16 mEventKeyType;  // _04
	u8 mValue;          // _06
	u8 mEventId;        // _07
	AnimKey* mPrev;     // _08
	AnimKey* mNext;     // _0C
};

/**
 * @brief TODO
 */
struct AnimInfo : public CoreNode {

	/**
	 * @brief Fabricated. Offsets relative to AnimInfo for convenience.
	 */
	struct Parms : public Parameters {
		Parms()
		    : mFlags(this, 2, 0, 0, "p00", nullptr)
		    , mSpeed(this, 30.0f, 0.0f, 0.0f, "spd", nullptr)
		{
		}

		// _14-_18 = Parameters
		Parm<int> mFlags; // _18, p00
		Parm<f32> mSpeed; // _28, spd
	};

	AnimInfo()
	    : CoreNode("")
	{
		mData = 0;
		mMgr  = nullptr;
	}

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
	AnimKey* addKeyFrame();

	// unused/inlined:
	void initAnimData(AnimData*);

	// only DLL inline:
	void addInfoKey(AnimKey* key) { mInfoKeys.mPrev->insertAfter(key); }

	// _00     = VTBL
	// _00-_14 = CoreNode
	Parms mParams;      // _14
	AnimKey mAnimKeys;  // _38
	AnimKey mEventKeys; // _48
	AnimKey mInfoKeys;  // _58
	AnimData* mData;    // _68
	int mIndex;         // _6C
	AnimMgr* mMgr;      // _70
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct AnimContext {
	AnimContext()
	    : mData(0)
	    , mCurrentFrame(0.0f)
	    , mFrameRate(30.0f)
	{
	}

	// _0C = VTBL
	AnimData* mData;   // _00
	f32 mCurrentFrame; // _04
	f32 mFrameRate;    // _08

	virtual void animate(f32 time); // _08
};

/**
 * @brief TODO
 */
struct Animator {
	Animator() { }

	void startAnim(int, int, int, int);
	void updateContext();

	void init(AnimContext* context, AnimMgr* mgr)
	{
		mContext          = context;
		mMgr              = mgr;
		mAnimInfo         = nullptr;
		mAnimationCounter = 0.0f;
	}

	// _30 = VTBL
	AnimMgr* mMgr;         // _00
	AnimContext* mContext; // _04
	int _08;               // _08
	int mAnimationId;      // _0C
	int _10;               // _10
	int _14;               // _14
	int mIsPlaying;        // _18
	int mCurrentAnimID;    // _1C
	int mFirstFrameIndex;  // _20
	int mLastFrameIndex;   // _24
	AnimInfo* mAnimInfo;   // _28
	f32 mAnimationCounter; // _2C

	virtual void changeContext(AnimContext* context) // _08
	{
		mContext = context;
	}
	virtual void animate(f32);    // _0C
	virtual void finishOneShot(); // _10
	virtual void finishLoop();    // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0xB8.
 */
struct AnimMgr : public CoreNode {

	/**
	 * @brief Offsets relative to AnimMgr for convenience.
	 */
	struct Parms : public Parameters {
		Parms()
		    : _18(this, 2, 0, 0, "a00", nullptr)
		    , mBasePath(this, String("base dir", 0), String("", 0), String("", 0), "a01", nullptr)
		{
		}

		// _14-_18 = Parameters
		Parm<int> _18;          // _18
		Parm<String> mBasePath; // _28
	};

	AnimMgr(Shape* model, char* animPath, int flags, char* bundlePath);

	virtual void read(RandomAccessStream&); // _0C

	void loadAnims(char* animPath, char* bundlePath);
	AnimInfo* addAnimation(char*, bool);
	int countAnims();

	// unused/inlined:
	AnimInfo* findAnim(int);

	// _00     = VTBL
	// _00-_14 = CoreNode
	Parms mParams;      // _14
	Shape* mParent;     // _3C
	AnimInfo mAnimList; // _40, parent of list of animations
	s32 mIsLoaded;      // _B4
};

/**
 * @brief Fabricated
 */
struct FrameCacher : public CacheInfo {
	// _00-_0C = CacheInfo
	CacheInfo** _0C; // _0C
	u8 _10[4];       // _10, unknown
	u32* _14;        // _14
	u32* _18;        // _18
	u32 _1C[1];      // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct AnimFrameCacher {
	AnimFrameCacher(int);
	void updateInfo(AnimCacheInfo*);
	void removeOldest();
	void cacheFrameSpace(int, AnimCacheInfo*);

	AyuCache* mCache; // _00
	CacheInfo mInfo;  // _04
	u8 _10[0x8];      // _10, unknown
};

#endif
