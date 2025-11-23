#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "Ayu.h"
#include "CmdStream.h"
#include "CoreNode.h"
#include "GfxObject.h"
#include "Matrix4f.h"
#include "Parameters.h"
#include "SRT.h"
#include "Stream.h"
#include "String.h"
#include "Texture.h"
#include "system.h"
#include "types.h"

struct AnimMgr;
struct BaseShape;
struct CmdStream;
struct Shape;
struct AgeServer;

/**
 * @brief Enum for AnimInfo flags.
 */
enum AnimInfoFlags {
	ANIMFLAG_Unk1            = 1 << 0, ///< 0x1, unknown/unused.
	ANIMFLAG_UseDynamicSpeed = 1 << 1, ///< 0x2, use variable/stored speed (rather than from param file).
	ANIMFLAG_UseCache        = 1 << 2, ///< 0x4, cache anim info (?).
};

/**
 * @brief Enum for AnimKey event types.
 */
enum AnimKeyEvents {
	ANIMEVENT_Notify = 0, ///< 0, play sound effect or send message. TODO: some funny business going on here
	ANIMEVENT_Action = 1, ///< 1, play cutscene or particle effect.  TODO: some funny business going on here
	ANIMEVENT_None   = 2, ///< 2, do nothing (default).
	ANIMEVENT_COUNT,      ///< 3 (max).
};

/**
 * @brief Enum for Animator states.
 */
enum AnimPlayState {
	ANIMSTATE_Inactive = 0, ///< 0, not animating.
	ANIMSTATE_Loop     = 1, ///< 1, loop animation.
	ANIMSTATE_OneShot  = 2, ///< 2, play animation once, then stop.
};

/**
 * @brief Enum for key frame event types.
 */
enum KeyEventTypes {
	KEY_NULL       = -1,
	KEY_Finished   = 0,
	KEY_Action0    = 1,
	KEY_Action1    = 2,
	KEY_Action2    = 3,
	KEY_Action3    = 4,
	KEY_LoopStart  = 5,
	KEY_LoopEnd    = 6,
	KEY_PlaySound  = 7,
	KEY_PlayEffect = 8,
	KEY_Reserved   = 9,
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
 * @brief Flags indicating animation data status for scale/rotation/translation components
 */
BEGIN_ENUM_TYPE(AnimDataFlags)
enum {
	ScaleXStatic             = 1 << 0, // Scale X component has single value (no animation)
	ScaleYStatic             = 1 << 1, // Scale Y component has single value (no animation)
	ScaleZStatic             = 1 << 2, // Scale Z component has single value (no animation)
	AllIndividualScaleStatic = ScaleXStatic | ScaleYStatic | ScaleZStatic,
	AllScaleStatic           = 1 << 3, // All scale components are static

	RotationXStatic             = 1 << 4, // Rotation X component has single value (no animation)
	RotationYStatic             = 1 << 5, // Rotation Y component has single value (no animation)
	RotationZStatic             = 1 << 6, // Rotation Z component has single value (no animation)
	AllIndividualRotationStatic = RotationXStatic | RotationYStatic | RotationZStatic,
	AllRotationStatic           = 1 << 7, // All rotation components are static

	TranslationXStatic             = 1 << 8,  // Translation X component has single value (no animation)
	TranslationYStatic             = 1 << 9,  // Translation Y component has single value (no animation)
	TranslationZStatic             = 1 << 10, // Translation Z component has single value (no animation)
	AllIndividualTranslationStatic = TranslationXStatic | TranslationYStatic | TranslationZStatic,
	AllTranslationStatic           = 1 << 11, // All translation components are static

	AllComponentsStatic = AllIndividualScaleStatic | AllIndividualRotationStatic | AllIndividualTranslationStatic,
	MatrixCalculated    = 1 << 15, // Transform matrix has been calculated
} END_ENUM_TYPE;

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

	virtual void extractSRT(SRT&, int, AnimDataInfo*, f32);                         // _10
	virtual void makeAnimSRT(int, Matrix4f*, Matrix4f*, AnimDataInfo*, f32);        // _14
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
 * @brief Animation key frame object.
 *
 * Stores information for each "key" (event) frame for an animation.
 *
 * @note Size: 0x10.
 */
struct AnimKey {

	// Default constructor.
	AnimKey()
	{
		mFrameIndex = 0;
		mEventType  = 0;
		mKeyType    = 0;
		mEventCmdID = 0;
		mPrev = mNext = nullptr;
	}

	/// Constructor for given keyframe index and value.
	AnimKey(int index, int value)
	{
		mFrameIndex = index;
		mKeyType    = value;
		mPrev       = nullptr;
		mNext       = nullptr;
	}

	/// Inserts given key after this key in its parent list.
	void insertAfter(AnimKey* key)
	{
		key->mNext   = mNext;
		key->mPrev   = this;
		mNext->mPrev = key;
		mNext        = key;
	}

	// Remove this key from the overall list, only used in .dll code
	void remove()
	{
		mNext->mPrev = mPrev;
		mPrev->mNext = mNext;
	}

	/// Unused DLL inline.
	void ageDelLastKey(AgeServer&);

	int mFrameIndex; ///< _00, frame number this key is attached to.
	s16 mEventType;  ///< _04, event type - see AnimKeyEvents enum.
	u8 mKeyType;     ///< _06, key type - see KeyEventTypes enum.
	u8 mEventCmdID;  ///< _07, command ID to execute on event.
	AnimKey* mPrev;  ///< _08, previous key in list.
	AnimKey* mNext;  ///< _0C, next key in list.
};

/**
 * @brief Basic animation object.
 *
 * Stores all active information for a given animation.
 *
 * @note Size: 0x74.
 */
struct AnimInfo : public CoreNode {

#ifdef WIN32
	virtual void genAge(AgeServer& server);
#endif

	/**
	 * @brief AnimInfo parameters.
	 *
	 * Offsets relative to AnimInfo for convenience.
	 */
	struct Parms : public Parameters {

		/// Constructor.
		Parms()
		    : mFlags(this, 2, 0, 0, "p00", nullptr)
		    , mSpeed(this, 30.0f, 0.0f, 0.0f, "spd", nullptr)
		{
		}

		// _14-_18 = Parameters
		Parm<int> mFlags; ///< _18, 'p00'
		Parm<f32> mSpeed; ///< _28, 'spd'
	};

	/// Default constructor.
	AnimInfo()
	    : CoreNode("")
	{
		mData = 0;
		mMgr  = nullptr;
	}

	/// Constructor that also sets connections and checks data.
	AnimInfo(AnimMgr* mgr, AnimData* data);

	/// Checks all Anim, Info and Event key indices are correctly bounded.
	void checkAnimData();

	/// Sets index to first available with stored manager and data filenames.
	void setIndex();

	/// Sets and updates animation flags.
	void setAnimFlags(u32 flags);

	/// Counts elements in Anim key list.
	int countAKeys();

	/// Counts elements in Info key list.
	int countIKeys();

	/// Counts elements in Events key list.
	int countEKeys();

	/// Gets Info key list element at index `idx`.
	AnimKey* getInfoKey(int idx);

	/// Gets Event key list element at index `idx`.
	AnimKey* getEventKey(int idx);

	/// Gets keyframe index of Anim key list element at index `idx`.
	int getKeyValue(int idx);

	/// Reads in parameters and keyframe indices from (streamed) file.
	void doread(RandomAccessStream& input, int version);

	/// Updates data flags to align with info flags.
	void updateAnimFlags();

	/// Adds new Anim key to end of list, with keyframe index at end of anim.
	AnimKey* addKeyFrame();

	/// Initializes the file name and data for an animation.
	void initAnimData(AnimData* data);

	/// Adds new info key to end of list.
	void addInfoKey(AnimKey* key) { mInfoKeys.mPrev->insertAfter(key); }

// .dll exclusive function for writing animation data to file.
#ifdef WIN32
	virtual void write(RandomAccessStream&);
#endif
	void ageAddEffectKey(AgeServer&);
	void ageAddInfoKey(AgeServer&);
	void ageAddKey(AgeServer&);
	void ageChangeAnim(AgeServer&);
	void ageDelAnim(AgeServer&);
	void genAgeKeyTypes(AgeServer&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	Parms mParams;      ///< _14, parameters read from file (and actively updated).
	AnimKey mAnimKeys;  ///< _38, list of animation keys.
	AnimKey mEventKeys; ///< _48, list of event keys.
	AnimKey mInfoKeys;  ///< _58, list of info keys.
	AnimData* mData;    ///< _68, animation data.
	int mIndex;         ///< _6C, index in system-wide GfxobjInfo list.
	AnimMgr* mMgr;      ///< _70, animation manager.
};

/**
 * @brief Animation context.
 *
 * Tracks information connecting objects and animations (data, frame, speed).
 *
 * @note Size: 0x10.
 */
struct AnimContext {

	/// Default constructor.
	AnimContext()
	    : mData(nullptr)
	    , mCurrentFrame(0.0f)
	    , mAnimSpeed(30.0f)
	{
	}

	// _0C = VTBL
	AnimData* mData;   ///< _00, animation data.
	f32 mCurrentFrame; ///< _04, current animation frame.
	f32 mAnimSpeed;    ///< _08, current animation speed (fps).

	/// Advances animation one (game) frame.
	virtual void animate(f32 animSpeed); // _08
};

/**
 * @brief Animator object.
 *
 * Coordinates information on current animation for a given game object.
 *
 * @note Size: 0x30.
 */
struct Animator {

	/// Default constructor.
	Animator() { }

	/// Starts a new animation with index `animIdx`.
	void startAnim(int playState, int animIdx, int firstKeyFrameIdx, int lastKeyFrameIdx);

	/// Updates data and frame counter of stored context to align with the animator.
	void updateContext();

	/// Initialises animator with given context and manager.
	void init(AnimContext* context, AnimMgr* mgr)
	{
		mContext          = context;
		mMgr              = mgr;
		mAnimInfo         = nullptr;
		mAnimationCounter = 0.0f;
	}

	// _30 = VTBL
	AnimMgr* mMgr;                 ///< _00, manager object.
	AnimContext* mContext;         ///< _04, animation context.
	int mPostOneShotPlayState;     ///< _08, state to restore to after oneshot (never set).
	int mPostOneShotAnimID;        ///< _0C, anim index to restore to after oneshot (never set).
	int mPostOneShotStartKeyIndex; ///< _10, start key index to restore to after oneshot (never set).
	int mPostOneShotEndKeyIndex;   ///< _14, end key index to restore to after oneshot (never set).
	int mPlayState;                ///< _18, current play state - see AnimPlayState enum.
	int mCurrentAnimID;            ///< _1C, current animation index, relative to mMgr anim list.
	int mStartKeyIndex;            ///< _20, index for first AnimKey keyframe.
	int mEndKeyIndex;              ///< _24, index for last AnimKey keyframe.
	AnimInfo* mAnimInfo;           ///< _28, current animation.
	f32 mAnimationCounter;         ///< _2C, animation frame counter.

	/// Sets animation context.
	virtual void changeContext(AnimContext* context) // _08
	{
		mContext = context;
	}

	/// Advances animation one (game) frame at given speed.
	virtual void animate(f32 animSpeed); // _0C

	/// Starts post-oneshot stored animation (unused).
	virtual void finishOneShot(); // _10

	/// Post-loop actions (trivial in base class).
	virtual void finishLoop(); // _14
};

/**
 * @brief Animation managing object.
 *
 * Manager for a given list of animations, for a given model.
 *
 * @note Size: 0xB8.
 */
struct AnimMgr : public CoreNode {

/// These do the same thing (and are the only flags passed to AnimMgr, but whatever).
#define ANIMMGR_LOAD_BUNDLE    (0x8000)
#define ANIMMGR_LOAD_NOSKIP    (0x0)
#define ANIMMGR_LOAD_SKIP_MASK (0x7FFF)

	/**
	 * @brief AnimMgr parameters.
	 *
	 * Offsets relative to AnimMgr for convenience.
	 */
	struct Parms : public Parameters {

		/// Constructor.
		Parms()
		    : _18(this, 2, 0, 0, "a00", nullptr)
		    , mBasePath(this, String("base dir", 0), String("", 0), String("", 0), "a01", nullptr)
		{
		}

		// _14-_18 = Parameters
		Parm<int> _18;          ///< _18, 'a00', unknown and unused.
		Parm<String> mBasePath; ///< _28, 'base dir', path to data dir containing AnimInfo data files.
	};

	/// Constructor, also loads animations and bundle file info.
	AnimMgr(Shape* model, char* animPath, int flags, char* bundlePath);

	/// Reads information for manager parameters and all managed animations.
	virtual void read(RandomAccessStream& input); // _0C

	/// Loads all parameter and animation information, including bundle.
	void loadAnims(char* animPath, char* bundlePath);

	/// Adds and loads new animation into list from specified file.
	AnimInfo* addAnimation(char* animPath, bool isRelativePath);

	/// Gets number of managed animations in list.
	int countAnims();

	/// STRIPPED - gets animation from list at index `idx` and if not loaded, loads it.
	AnimInfo* findAnim(int idx);

#ifdef WIN32
	virtual void genAge(AgeServer&);
	virtual void write(RandomAccessStream&);
#endif

	void importAnimationButton(AgeServer&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	Parms mParams;      ///< _14, parameters from file.
	Shape* mModel;      ///< _3C, model the animations are attached to.
	AnimInfo mAnimList; ///< _40, list of managed animations.
	BOOL mSkipLoading;  ///< _B4, if non-zero, skips all animation and bundle loading.
};

/**
 * @brief Fabricated
 */
struct FrameCacher : public CacheInfo {
	// _00-_0C = CacheInfo
	CacheInfo** mInfo;     // _0C
	u8 _10[4];             // _10, unknown
	u32* mBoneMatricesEnd; // _14
	u32* mBoneMtxList;     // _18
	u32 mBoneMatrices[1];  // _1C
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
