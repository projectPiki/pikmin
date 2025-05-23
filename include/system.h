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
 * @brief For mHeaps array in StdSystem.
 */
enum SystemHeapType {
	SYSHEAP_Sys     = 0,
	SYSHEAP_Ovl     = 1,
	SYSHEAP_App     = 2,
	SYSHEAP_Load    = 3,
	SYSHEAP_Teki    = 4,
	SYSHEAP_Movie   = 5,
	SYSHEAP_Message = 6,
	SYSHEAP_Lang    = 7,
	SYSHEAP_COUNT, // 8
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
	AnimData* loadAnimation(Shape*, char*, bool);
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
	void findAnyGfxObject(char*, u32);
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
		mBloDirectory = bloDir;
		mTexDirectory = texDir;
	}
	inline void setTextureBase(char* base1, char* base2)
	{
		mTextureBase1 = base1;
		mTextureBase2 = base2;
	}
	inline void setDataRoot(char* dir) { mDataRoot = dir; }
	inline void softReset() { mIsSystemOperationPending = true; }
	inline void clearPending() { mIsSystemOperationPending = false; } // no idea what this should be called
	inline void Shutdown() { mSystemFlags = SystemFlags::Shutdown; }
	inline bool resetPending() { return mIsSystemOperationPending; }
	inline void setFrameClamp(s32 frameRate) { mFrameRate = frameRate; }
	inline int getHeapNum() { return mActiveHeapIdx; }

	bool mIsSystemOperationPending; // _00
	f32 mCurrentFade;               // _04
	f32 mFadeStart;                 // _08
	f32 mFadeEnd;                   // _0C
	Font* mConsFont;                // _10
	s32 mFrameRate;                 // _14
	u32 mTimerState;                // _18, see TimerState enum
	u32 mTogglePrint;               // _1C
	u32 mToggleDebugInfo;           // _20
	u32 mToggleDebugExtra;          // _24
	u32 mToggleBlur;                // _28
	u32 mToggleFileInfo;            // _2C
	u32 mToggleColls;               // _30
	Timers* mTimer;                 // _34
	TextureCacher* mCacher;         // _38
	u32 mMatrixCount;               // _3C
	Matrix4f* mMatrices;            // _40
	char* mBloDirectory;            // _44
	char* mTexDirectory;            // _48
	char* mCurrentDirectory;        // _4C
	char* mDataRoot;                // _50
	AyuHeap mHeaps[SYSHEAP_COUNT];  // _54 (54:sys, 7C:ovl, A4:app, CC:load, F4:teki, 11C:movie, 144:message, 16C:lang)
	int mActiveHeapIdx;             // _194
	int mForceTogglePrint;          // _198
	MemInfo* mCurrMemInfo;          // _19C

	// the vtable has to be at 0x1A0, so it's in the middle, yes.
	virtual void initSoftReset();                                               // _08
	virtual RandomAccessStream* openFile(char*, bool, bool) { return nullptr; } // _0C
	virtual u32 copyRamToCache(u32, u32, u32) { return 0; }                     // _10
	virtual void copyCacheToRam(u32, u32, u32) { }                              // _14
	virtual void copyWaitUntilDone() { }                                        // _18
	virtual void copyCacheToTexture(struct CacheTexture*) { }                   // _1C
	virtual void Activate(bool) { }                                             // _20
	virtual void parseArchiveDirectory(char*, char*) { }                        // _24
	virtual void sndPlaySe(u32) = 0;                                            // _28
	virtual void startLoading(struct LoadIdler*, bool, u32) { }                 // _2C
	virtual void endLoading() { }                                               // _30

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
	CoreNode mDvdFileTreeRoot;    // _200
	CoreNode mAramFileTreeRoot;   // _214
	DirEntry* mFileTreeList;      // _228
	int mFlareCount;              // _22C
	int mLfInfoCount;             // _230
	LFInfo* mFlareInfoList;       // _234
	LFlareGroup* mFlareGroupList; // _238
	int mDvdOpenFileCounter;      // _23C
	u32 mDvdReadBytesCount;       // _240
};

/**
 * @brief Fabricated - some structure needs to live at 0x310 in System.
 */
struct FakeSystemList {
	u32 _00; // _00, unknown
	u32 _04; // _04, unknown
	u32 _08; // _08, unknown
};

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

	// unused/inlined:
	void findAddress(u32);
	bool hasDebugInfo();
	static void halt(char* file, int line, char* message)
	{
		// char buffer[2048];
		// sprintf(buffer, "%s\n\nClick OK to quit now !", message);
		// MessageBox(NULL, buffer, "Error!", MB_ICONEXCLAMATION);
		// exit(0); // Failure!

		OSPanic(file, line, message);
	}

	static void* alloc(size_t);

	inline AtxRouter* getAtxRouter() { return mAtxRouter; }
	inline void setAtxRouter(AtxRouter* router) { mAtxRouter = router; }
	f32 getFrameTime() { return mDeltaTime; }
	f32 getFrameRate() { return mFramesPerSecond; }

	inline void initFakeThing1(FakeSystemList* p1, FakeSystemList* p2, u32 p3, u32 p4)
	{
		u32 x   = _31C._00 + p2->_08;
		p1->_00 = p3;
		p1->_08 = x - p4;
		p1->_04 = p1->_00;
	}

	inline void initFakeThing2() { _328 = &_310; }

	// _00      = VTBL
	// _00-_248 = StdSystem
	u32 mSystemHeapStart;                            // _244
	u32 mSystemHeapEnd;                              // _248
	DGXGraphics* mDGXGfx;                            // _24C
	u32 _250;                                        // _250, unknown
	Delegate1<System, Graphics&>* mDvdErrorCallback; // _254
	int mDvdErrorCode;                               // _258
	u32 mDvdBufferSize;                              // _25C
	u32 mIsLoadingThreadActive;                      // _260
	u32 _264;                                        // _264
	u32 mIsLoadingScreenActive;                      // _268
	vu32 mIsRendering;                               // _26C
	u32 mIsMemoryCardSaving;                         // _270
	OSThread* mCurrentThread;                        // _274
	AtxRouter* mAtxRouter;                           // _278
	ControllerMgr mControllerMgr;                    // _27C
	u32 mPreviousTickTime;                           // _280
	u32 mFpsSamplePeriodStartTick;                   // _284
	int mFrameDurationTicks;                         // _288
	f32 mDeltaTime;                                  // _28C
	f32 mFramesPerSecond;                            // _290
	u32 mEngineRunningFrameCount;                    // _294
	u32 mFrameCountAtSamplePeriodStart;              // _298
	u32 mEngineTotalFrames;                          // _29C
	u32 mRetraceCount;                               // _2A0
	u32 mPrevHeapAllocType;                          // _2A4
	AddressNode _2A8;                                // _2A8
	u32 mBuildMapFuncList;                           // _2BC, structure is nextItemPtr, virtAddr, char buf w/ demangled name/filename
	SystemCache _2C0;                                // _2C0
	SystemCache _2E8;                                // _2E8
	FakeSystemList _310;                             // _310, fake
	FakeSystemList _31C;                             // _31C, fake
	FakeSystemList* _328;                            // _328, unknown
	vu32 mDmaTransferComplete;                       // _32C
	vu32 mTextureTransferComplete;                   // _330
};

extern System* gsys;

// SYSTEM STREAMS

/**
 * @brief TODO
 */
struct LogStream : public Stream {
	LogStream()
	{
		_08 = 0;
		_0C = 0;
	}

	virtual void flush() // _54 (weak)
	{
		mBuffer[_08] = 0;
		if (gsys->mTogglePrint) {
			OSReport("%s\n", mBuffer);
		}

		_08 = 0;
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
				if (_08 >= 255) {
					flush();
				}
				mBuffer[_08++] = ' ';
				if (_08 >= 255) {
					flush();
				}
				mBuffer[_08++] = ' ';
				continue;
			}

			if (_08 >= 255) {
				flush();
			}
			mBuffer[_08++] = c;
		}
	}

	// _04     = VTBL
	// _00-_08 = Stream
	int _08;             // _08
	u32 _0C;             // _0C, unknown
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
		gsys->mDvdReadBytesCount += roundedSize;
		while (result == -1) {
			result = DVDReadPrio(&mFileInfo, addr, roundedSize, mOffset, 2);
		}

		mOffset += roundedSize;
	}
	virtual int getPending() { return mPending; } // _44 (weak)
	virtual void close()                          // _4C (weak)
	{
		numOpen--;
		if (mIsFileOpen) {
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
	bool mIsFileOpen;      // _4C, trigger to do DVDClose on close()
	int mSize;             // _50
};

extern int glnWidth;
extern int glnHeight;

extern "C" void OSPanic(const char* filename, int line, const char* msg, ...);

#endif
