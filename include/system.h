#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "types.h"
#include "Ayu.h"
#include "GfxObject.h"
#include "CoreNode.h"
#include "Stream.h"
#include "Controller.h"
#include "Dolphin/dvd.h"
#include "Dolphin/rand.h"
#include "Dolphin/os.h"
#include "Dolphin/ar.h"
#include "Delegate.h"

struct DGXGraphics;
struct BaseApp;
struct CacheTexture;
struct TextureCacher;
struct LoadIdler;
struct Timers;
struct Font;
struct BaseShape;
struct CoreNode;
struct LFInfo;
struct LightFlare;
struct LFlareGroup;
struct Matrix4f;
struct AtxRouter;
struct ControllerMgr;
struct OSContext;
struct OSThread;
struct Shape;
struct AnimData;
struct AnimFrameCacher;
struct MemInfo;
struct CacheInfo;

/**
 * @brief Used to seperate the memory arenas held in StdSystem.
 */
enum SystemHeapType {
	SYSHEAP_Sys     = 0, // General system heap
	SYSHEAP_Ovl     = 1, // Overlay heap
	SYSHEAP_App     = 2, // Application heap
	SYSHEAP_Load    = 3, // Load heap
	SYSHEAP_Teki    = 4, // Enemy heap
	SYSHEAP_Movie   = 5, // Movie heap
	SYSHEAP_Message = 6, // Message heap
	SYSHEAP_Lang    = 7, // Language heap
	SYSHEAP_COUNT,       // 8, total number of heaps
};

/**
 * @brief TODO
 */
enum TimerState {
	TS_Off = 0, // 0
	TS_On,      // 1
	TS_Full     // 2
};

/**
 * @brief TODO
 */
struct AddressNode : public CoreNode {
	AddressNode()
	    : CoreNode("")
	{
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct DirEntry : public CoreNode {
	DirEntry()
	    : CoreNode("")
	{
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mPending; // _14
	u32 mAddress; // _18
};

/**
 * @brief TODO
 */
struct BinobjInfo : public GfxobjInfo {
	BinobjInfo()
	    : mData(nullptr)
	{
	}

	// _1C     = VTBL
	// _00-_20 = GfxobjInfo
	char* mData; // _20
};

/**
 * @brief TODO
 */
struct SystemCache : public ARQRequest {
	void remove()
	{
		mNext->mPrev = mPrev;
		mPrev->mNext = mNext;
	}

	void insertAfter(SystemCache* other)
	{
		other->mNext = mNext;
		other->mPrev = this;

		mNext->mPrev = other;
		mNext        = other;
	}

	// _00-_20 = ARQRequest
	SystemCache* mNext; // _20
	SystemCache* mPrev; // _24
};

DEFINE_ENUM_TYPE(SystemFlags, Shutdown = 0x80000000);

/**
 * @brief TODO
 *
 * @note Size: 0x244.
 */
struct StdSystem {
	StdSystem();

	void onceInit();
	AyuHeap* getHeap(int heapIdx);
	void resetHeap(int heapIdx, int flag);
	int setHeap(int);
	GfxobjInfo* findGfxObject(char*, u32);
	Texture* loadTexture(char*, bool);
	Shape* loadShape(char*, bool);
	AnimData* findAnimation(char*);
	int findAnyIndex(char*, char*);
	AnimData* loadAnimation(Shape* model, char* path, bool isRelativePath);
	void addAnimation(AnimData*, char*);
	void addGfxObject(GfxobjInfo*);
	void attachObjs();
	void detachObjs();
	void invalidateObjs(u32, u32);
	void addTexture(Texture*, char*);
	Shape* getShape(char*, char*, char*, bool);
	void initLFlares(int);
	void resetLFlares();
	LFInfo* getLFlareInfo();
	LFlareGroup* registerLFlare(Texture*);
	void flushLFlares(Graphics&);
	void loadBundle(char*, bool);

	void getAppMemory(char*);
	GfxobjInfo* findAnyGfxObject(char*, u32);
	GfxobjInfo* findTexture(Texture*);
	AnimData* findAnyAnimation(char*);
	AnimData* findIndexAnimation(char*, int);

	// Static functions
	static char* stringDup(char*);
	static f32 getHalfRand(f32 max) { return max * (f32(rand()) / 32767.0f - 0.5f); }

	// Inline functions
	f32 getRand(f32 max) { return max * (f32(rand()) / 32767.0f); }
	inline f32 getFade() { return mCurrentFade; }
	inline void setFade(f32 start, f32 end)
	{
		mFadeStart = start;
		mFadeEnd   = end;
	}
	void set2DRoot(char* bloDir, char* texDir)
	{
		mBloDir = bloDir;
		mTexDir = texDir;
	}
	inline void setTextureBase(char* base1, char* base2)
	{
		mTextureBase1 = base1;
		mTextureBase2 = base2;
	}
	inline void setDataRoot(char* dir) { mDataRoot = dir; }
	inline void softReset() { mSysOpPending = true; }
	inline void clearPending() { mSysOpPending = false; } // no idea what this should be called
	inline void Shutdown() { mSystemFlags = SystemFlags::Shutdown; }
	inline bool resetPending() { return mSysOpPending; }
	inline void setFrameClamp(s32 frameRate) { mFrameRate = frameRate; }
	inline int getHeapNum() { return mActiveHeapIdx; }

	bool mSysOpPending;            // _00
	f32 mCurrentFade;              // _04
	f32 mFadeStart;                // _08
	f32 mFadeEnd;                  // _0C
	Font* mConsFont;               // _10
	s32 mFrameRate;                // _14
	u32 mTimerState;               // _18, see TimerState enum
	u32 mTogglePrint;              // _1C
	u32 mToggleDebugInfo;          // _20
	u32 mToggleDebugExtra;         // _24
	u32 mToggleBlur;               // _28
	u32 mToggleFileInfo;           // _2C
	u32 mToggleColls;              // _30
	Timers* mTimer;                // _34
	TextureCacher* mCacher;        // _38
	u32 mMatrixCount;              // _3C
	Matrix4f* mMatrices;           // _40
	char* mBloDir;                 // _44
	char* mTexDir;                 // _48
	char* mActiveDir;              // _4C
	char* mDataRoot;               // _50
	AyuHeap mHeaps[SYSHEAP_COUNT]; // _54 (54:sys, 7C:ovl, A4:app, CC:load, F4:teki, 11C:movie, 144:message, 16C:lang)
	int mActiveHeapIdx;            // _194
	int mForcePrint;               // _198
	MemInfo* mCurrMemInfo;         // _19C
#if defined(VERSION_GPIP01_00)
	u32 _1A0; // _1A0, language id, at least for PAL
#endif

	// the vtable has to be at 0x1A0, so it's in the middle, yes.
	virtual void initSoftReset();                                                                   // _08
	virtual RandomAccessStream* openFile(char* path, bool isRelativePath, bool) { return nullptr; } // _0C
	virtual u32 copyRamToCache(u32, u32, u32) { return 0; }                                         // _10
	virtual void copyCacheToRam(u32, u32, u32) { }                                                  // _14
	virtual void copyWaitUntilDone() { }                                                            // _18
	virtual void copyCacheToTexture(struct CacheTexture*) { }                                       // _1C
#if defined(VERSION_G98E01_PIKIDEMO)                                                                //
	virtual void forceHardReset() { }                                                               // _20 (USA DEMO only?)
#endif                                                                                              //
	virtual void Activate(bool) { }                                                                 // _20
	virtual void parseArchiveDirectory(char*, char*) { }                                            // _24
	virtual void sndPlaySe(u32) = 0;                                                                // _28
	virtual void startLoading(struct LoadIdler*, bool, u32) { }                                     // _2C
	virtual void endLoading() { }                                                                   // _30

	int mPolygonCount;            // _1A4
	u32 mMaterialCount;           // _1A8
	u32 mDispCount;               // _1AC
	u32 mLightCount;              // _1B0
	s32 mActiveLightCount;        // _1B4
	u32 mAnimatedPolygons;        // _1B8
	u32 mLightingSkips;           // _1BC
	u32 mLightingSets;            // _1C0
	u32 mLightSetNum;             // _1C4
	u32 mSystemFlags;             // _1C8
	Graphics* mGraphics;          // _1CC
	GfxobjInfo mGfxobjInfo;       // _1D0
	bool mHasGfxObjects;          // _1F0
	char* mTextureBase1;          // _1F4
	char* mTextureBase2;          // _1F8
	Shape* mCurrentShape;         // _1FC
	CoreNode mDvdRoot;            // _200
	CoreNode mAramRoot;           // _214
	DirEntry* mFileList;          // _228
	int mFlareCount;              // _22C
	int mLfInfoCount;             // _230
	LFInfo* mFlareInfoList;       // _234
	LFlareGroup* mFlareGroupList; // _238
	int mDvdOpenFiles;            // _23C
	u32 mDvdBytesRead;            // _240

	// .dll only functions
	void ageAnyAnimations(AgeServer&, char*);
};

/**
 * @brief Fabricated - some structure needs to live at 0x310 in System.
 */
struct AramAllocator {
	inline u32 getDest(u32 size)
	{
		u32 b = 0;
		u32 a = mCurrentOffset;
		if (a + size <= mBaseAddress + mSize) {
			b              = a;
			mCurrentOffset = a + size;
		}
		return b;
	}

	inline void init() { mCurrentOffset = mBaseAddress; }

	u32 mBaseAddress;   ///< _00
	u32 mCurrentOffset; ///< _04
	u32 mSize;          ///< _08
};

/**
 * @brief DVD error states for disc reading operations
 */
DEFINE_ENUM_TYPE(DvdError,
                 None        = -1, // No error, normal operation
                 ReadingDisc = 0,  // Currently reading game disc
                 FatalError  = 1,  // Fatal disc read error occurred
                 RetryError  = 2,  // Disc read error, retrying
                 NoDisc      = 3,  // No disc inserted
                 CoverOpen   = 4,  // Disc cover is open
                 WrongDisc   = 5   // Non-Pikmin disc inserted
);

/**
 * @brief TODO
 *
 * @note Size: 0x334.
 */
struct System : public StdSystem {
	System();

	virtual void initSoftReset();                            // _08
	virtual RandomAccessStream* openFile(char*, bool, bool); // _0C
	virtual u32 copyRamToCache(u32, u32, u32);               // _10
	virtual void copyCacheToRam(u32, u32, u32);              // _14
	virtual void copyWaitUntilDone();                        // _18
	virtual void copyCacheToTexture(CacheTexture*);          // _1C
	virtual void parseArchiveDirectory(char*, char*);        // _24
	virtual void sndPlaySe(u32);                             // _28
	virtual void startLoading(LoadIdler*, bool, u32);        // _2C
	virtual void endLoading();                               // _30

	~System();

	void run(BaseApp* app);
	void beginRender();
	void doneRender();
	void waitRetrace();
	f32 getTime();
	void updateSysClock();
	void hardReset();
	void showDvdError(Graphics&);
	void nudgeLoading();
	void nudgeDvdThread();
	void startDvdThread();
	void Initialise();
	RandomAccessStream* createFile(char*, BOOL);

	// unused/inlined:
	void findAddress(u32);
	bool hasDebugInfo();
	static void halt(char* file, int line, char* message);

	static void* alloc(size_t);

	inline AtxRouter* getAtxRouter() { return mAtxRouter; }
	inline void setAtxRouter(AtxRouter* router) { mAtxRouter = router; }
	f32 getFrameTime() { return mDeltaTime; }
	f32 getFrameRate() { return mFPS; }

	// Fake!
	inline void initAramAllocator(AramAllocator* target, AramAllocator* prev, u32 baseAddr, u32 endAddr)
	{
		u32 x                  = mAramAllocator.mBaseAddress + prev->mSize;
		target->mBaseAddress   = baseAddr;
		target->mSize          = x - endAddr;
		target->mCurrentOffset = target->mBaseAddress;
	}

	// Fake!
	inline void initCurrentAllocator() { mCurrentAllocator = &mBaseAramAllocator; }

	// _00      = VTBL
	// _00-_248 = StdSystem
	u32 mHeapStart;                                  // _244
	u32 mHeapEnd;                                    // _248
	Graphics* mDGXGfx;                               // _24C, cast to DGXGraphics in DOL
	u32 _250;                                        // _250, unknown
	Delegate1<System, Graphics&>* mDvdErrorCallback; // _254
	int mDvdErrorCode;                               // _258
	u32 mDvdBufferSize;                              // _25C
	u32 mIsLoadingActive;                            // _260
	u32 mLoadTimeBeforeIdling;                       // _264
	u32 mIsLoadScreenActive;                         // _268
	vu32 mIsRendering;                               // _26C
	u32 mIsCardSaving;                               // _270
	OSThread* mCurrentThread;                        // _274
#if defined(VERSION_G98E01_PIKIDEMO)                 //
	u8 _278[0x27C - 0x278];                          // _278, TODO: Confirm where this member actually is - definitely 0x278 or lower.
#endif                                               //
	AtxRouter* mAtxRouter;                           // _278
	ControllerMgr mControllerMgr;                    // _27C
	u32 mPrevTick;                                   // _280
	u32 mFpsSampleStart;                             // _284
	int mFrameTicks;                                 // _288
	f32 mDeltaTime;                                  // _28C
	f32 mFPS;                                        // _290
	u32 mEngineFrames;                               // _294
	u32 mFramesAtSampleStart;                        // _298
	u32 mTotalFrames;                                // _29C
	u32 mRetraceCount;                               // _2A0
	u32 mPrevAllocType;                              // _2A4
	AddressNode _2A8;                                // _2A8
	u32 mBuildMapFuncList;                           // _2BC, structure is nextItemPtr, virtAddr, char buf w/ demangled name/filename
	SystemCache mActiveCacheList;                    // _2C0
	SystemCache mFreeCacheList;                      // _2E8
	AramAllocator mBaseAramAllocator;                // _310, fake
	AramAllocator mAramAllocator;                    // _31C, fake
	AramAllocator* mCurrentAllocator;                // _328, unknown
	vu32 mDmaComplete;                               // _32C
	vu32 mTexComplete;                               // _330
};

extern System* gsys;

// SYSTEM STREAMS

/**
 * @brief TODO
 */
struct LogStream : public Stream {
	LogStream()
	{
		mBufPosition = 0;
		_UNUSED0C    = 0;
	}

	virtual void flush() // _54 (weak)
	{
		mBuffer[mBufPosition] = 0;
		if (gsys->mTogglePrint) {
			OSReport("%s\n", mBuffer);
		}

		mBufPosition = 0;
	}
	virtual void write(void* data, int size) // _40 (weak)
	{
		for (int i = 0; i < size; i++) {
			char c = ((char*)data)[i];
			if (c == 0xA) { // line feed
				flush();
				continue;
			}

			if (c == 0x9) { // horizontal tab
				if (mBufPosition >= 255) {
					flush();
				}

				mBuffer[mBufPosition++] = ' ';
				if (mBufPosition >= 255) {
					flush();
				}

				mBuffer[mBufPosition++] = ' ';
				continue;
			}

			if (mBufPosition >= 255) {
				flush();
			}

			mBuffer[mBufPosition++] = c;
		}
	}

	// _04     = VTBL
	// _00-_08 = Stream
	int mBufPosition;    // _08
	u32 _UNUSED0C;       // _0C
	char mBuffer[0x100]; // _10
};

/**
 * @brief TODO
 */
struct AramStream : public RandomAccessStream {
	virtual int getPending() { return mPending; } // _44 (weak)
	virtual void read(void* data, int size)       // _3C (weak)
	{
		int readSize = OSRoundUp32B(size);
		gsys->copyCacheToRam((u32)data, mBaseAddress + mOffset, readSize);
		gsys->copyWaitUntilDone();
		mOffset += readSize;
	}

	inline void init(char* path, u32 address, int pending)
	{
		mPath        = path;
		mPending     = pending;
		mBaseAddress = address;
		mOffset      = 0;
	}

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	u32 mBaseAddress; // _08, start address maybe?
	u32 mOffset;      // _0C, offset/position maybe?
	int mPending;     // _10
};

/**
 * @brief TODO
 */
struct DVDStream : public RandomAccessStream {
	DVDStream() { mSize = 0x40000; }

	virtual void read(void* addr, int size) // _3C (weak)
	{
		int roundedSize = ALIGN_NEXT(size, 32);
		s32 result      = -1;
		gsys->mDvdBytesRead += roundedSize;
		while (result == -1) {
			result = DVDReadPrio(&mFileInfo, addr, roundedSize, mOffset, 2);
		}

		mOffset += roundedSize;
	}
	virtual int getPending() { return mPending; } // _44 (weak)
	virtual void close()                          // _4C (weak)
	{
		numOpen--;
		if (mIsOpen) {
			DVDClose(&mFileInfo);
		}
	}

	void init();

	static u32 numOpen;
	static u8* readBuffer;

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	DVDFileInfo mFileInfo; // _08
	u32 mOffset;           // _44
	int mPending;          // _48
	bool mIsOpen;          // _4C, trigger to do DVDClose on close()
	int mSize;             // _50
};

extern int glnWidth;
extern int glnHeight;

extern "C" void OSPanic(const char* filename, int line, const char* msg, ...);

#endif
