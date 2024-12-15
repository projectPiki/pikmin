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

#ifdef _WIN32
#include <windows.h>
#endif

struct Graphics;
struct BaseApp;
struct CacheTexture;
struct LoadIdler;
struct Timers;
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
	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct BinobjInfo : public GfxobjInfo {
	// _1C     = VTBL
	// _00-_20 = GfxobjInfo
	// TODO: members
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
	void resetHeap(int, int);
	int setHeap(int);
	GfxobjInfo* findGfxObject(char*, u32);
	Texture* loadTexture(char*, bool);
	Shape* loadShape(char*, bool);
	void findAnimation(char*);
	int findAnyIndex(char*, char*);
	AnimData* loadAnimation(Shape*, char*, bool);
	void addAnimation(AnimData*, char*);
	void addGfxObject(GfxobjInfo*);
	void attachObjs();
	void detachObjs();
	void invalidateObjs(u32, u32);
	void addTexture(Texture*, char*);
	void getShape(char*, char*, char*, bool);
	void initLFlares(int);
	void resetLFlares();
	LFInfo* getLFlareInfo();
	LFlareGroup* registerLFlare(Texture*);
	void flushLFlares(Graphics&);
	void loadBundle(char*, bool);

	void getAppMemory(char*);
	void findAnyGfxObject(char*, u32);
	void findTexture(Texture*);
	void findAnyAnimation(char*);
	void findIndexAnimation(char*, int);

	// Static functions
	static char* stringDup(char*);
	static f32 getRand(f32 max) { return max * (f32(rand()) / 32767.0f); }

	// Inline functions
	inline f32 getFade() { return mCurrentFade; }
	inline void setFade(f32 start, f32 end)
	{
		mFadeStart = start;
		mFadeEnd   = end;
	}
	inline void setDirectories(char* bloDir, char* texDir)
	{
		mBloDirectory = bloDir;
		mTexDirectory = texDir;
	}
	inline void setDataRoot(char* dir) { mDataRoot = dir; }
	inline void softReset() { mPending = true; }
	inline void Shutdown() { mSystemFlags = SystemFlags::Shutdown; }

private:
	// Use the functions!
	bool mPending;    // _00
	f32 mCurrentFade; // _04
public:
	f32 mFadeStart;                // _08
	f32 mFadeEnd;                  // _0C
	struct Font* mConsFont;        // _10
	s32 mFrameRate;                // _14
	u32 mTimerState;               // _18, see TimerState enum
	u32 mTogglePrint;              // _1C
	u32 mToggleDebugInfo;          // _20
	u32 mToggleDebugExtra;         // _24
	u32 mToggleBlur;               // _28
	u32 mToggleFileInfo;           // _2C
	u32 mToggleColls;              // _30
	struct Timers* mTimer;         // _34
	struct TextureCacher* mCacher; // _38
	u32 mMatrixCount;              // _3C
	Matrix4f* mMatrices;           // _40
	char* mBloDirectory;           // _44
	char* mTexDirectory;           // _48
	char* mCurrentDirectory;       // _4C
	char* mDataRoot;               // _50
	AyuHeap mHeaps[SYSHEAP_COUNT]; // _54 (54:sys, 7C:ovl, A4:app, CC:load, F4:teki, 11C:movie, 144:message, 16C:lang)
	int mActiveHeapIdx;            // _194
	u32 _198;                      // _198, unknown
	MemInfo* mCurrMemInfo;         // _19C

	// the vtable has to be at 0x1A0, so it's in the middle, yes.
	// OR everything above this is a separate struct with some inheritance (doubt)
	virtual void initSoftReset();                               // _08
	virtual BufferedInputStream* openFile(char*, bool, bool);   // _0C
	virtual u32 copyRamToCache(u32, u32, u32) { return 0; }     // _10
	virtual void copyCacheToRam(u32, u32, u32) { }              // _14
	virtual void copyWaitUntilDone() { }                        // _18
	virtual void copyCacheToTexture(struct CacheTexture*) { }   // _1C
	virtual void Activate(bool) { }                             // _20
	virtual void parseArchiveDirectory(char*, char*) { }        // _24
	virtual void sndPlaySe(u32) = 0;                            // _28
	virtual void startLoading(struct LoadIdler*, bool, u32) { } // _2C
	virtual void endLoading() { }                               // _30

	u32 _1A4;                 // _1A4
	u32 mMaterialCount;       // _1A8
	u32 mDispCount;           // _1AC
	u32 mLightCount;          // _1B0
	u32 _1B4;                 // _1B4
	u32 mLoadedPolys;         // _1B8
	u32 mLightingSkips;       // _1BC
	u32 mLightingSets;        // _1C0
	u32 mSystemState;         // _1C4
	u32 mSystemFlags;         // _1C8
	Graphics* mGraphics;      // _1CC
	GfxobjInfo mGfxobjInfo;   // _1D0
	bool mHasGfxObjects;      // _1F0
	char* mTextureBase1;      // _1F4
	char* mTextureBase2;      // _1F8
	BaseShape* mCurrentShape; // _1FC
	CoreNode _200;            // _200
	CoreNode _214;            // _214
	CoreNode* _228;           // _228
	int mFlareCount;          // _22C
	int mLfInfoCount;         // _230
	LFInfo* mLfInfo;          // _234
	LightFlare* mLightFlares; // _238
	LFlareGroup* mLfGroups;   // _23C
	u32 _240;                 // _240
};

/**
 * @brief TODO
 *
 * @note Size: 0x334.
 */
struct System : public StdSystem {
	System();

	virtual void initSoftReset();                             // _08
	virtual BufferedInputStream* openFile(char*, bool, bool); // _0C
	virtual u32 copyRamToCache(u32, u32, u32);                // _10
	virtual void copyCacheToRam(u32, u32, u32);               // _14
	virtual void copyWaitUntilDone();                         // _18
	virtual void copyCacheToTexture(CacheTexture*);           // _1C
	virtual void parseArchiveDirectory(char*, char*);         // _24
	virtual void sndPlaySe(u32);                              // _28
	virtual void startLoading(LoadIdler*, bool, u32);         // _2C
	virtual void endLoading();                                // _30

	~System();

	void run(BaseApp* app);
	void beginRender();
	void doneRender();
	void waitRetrace();
	void getTime();
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
#ifdef _WIN32
		char buffer[2048];
		sprintf(buffer, "%s\n\nClick OK to quit now !", message);
		MessageBox(NULL, buffer, "Error!", MB_ICONEXCLAMATION);
		exit(0); // Failure!
#else
		OSPanic(file, line, message);
#endif
	}

	static void* alloc(size_t);

	inline AtxRouter* getAtxRouter() { return mAtxRouter; }
	inline void setAtxRouter(AtxRouter* router) { mAtxRouter = router; }
	f32 getFrameTime() { return mDeltaTime; }
	inline void setCurrMemInfo(MemInfo* info) { mCurrMemInfo = info; }

	// _00      = VTBL
	// _00-_248 = StdSystem
	u32 _244;                     // _244
	u32 _248;                     // _248
	Graphics* mGfx;               // _24C
	u8 _250[0x4];                 // _250, unknown
	u32 _254;                     // _254, unknown
	int _258;                     // _258
	u32 _25C;                     // _25C
	u32 _260;                     // _260, unknown
	u8 _264[0x274 - 0x264];       // _264, unknown
	OSThread* mCurrentThread;     // _274
	AtxRouter* mAtxRouter;        // _278
	ControllerMgr mControllerMgr; // _27C
	u8 _280[0xC];                 // _280, unknown
	f32 mDeltaTime;               // _28C
	u8 _290[0x2A4 - 0x290];       // _290, unknown
	u32 _2A4;                     // _2A4, unknown
	AddressNode _2A8;             // _2A8, unknown size
	u32 _2BC;                     // _2BC, unknown, could be part of _2A8
	u8 _2C0[0x32C - 0x2C0];       // _2C0, unknown, adjust with size of AddressNode
	u32 _32C;                     // _32C
	u32 _330;                     // _330
};

extern System* gsys;

// SYSTEM STREAMS

/**
 * @brief TODO
 */
struct LogStream : public Stream {
	virtual void write(void*, int); // _40 (weak)
	virtual void flush();           // _54 (weak)

	// _04     = VTBL
	// _00-_08 = Stream
	// TODO: members
};

/**
 * @brief TODO
 */
struct AramStream : public RandomAccessStream {
	virtual void read(void*, int); // _3C (weak)
	virtual int getPending();      // _44 (weak)

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	u32 _08;      // _08, start address maybe?
	u32 _0C;      // _0C, offset/position maybe?
	int mPending; // _10
};

/**
 * @brief TODO
 */
struct DVDStream : public RandomAccessStream {
	virtual void read(void*, int); // _3C (weak)
	virtual int getPending();      // _44 (weak)
	virtual void close();          // _4C (weak)

	void init();

	static u32 numOpen;

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	DVDFileInfo mFileInfo; // _08
	u32 mOffset;           // _44
	int mPending;          // _48
	bool mIsFileOpen;      // _4C, trigger to do DVDClose on close()
};

static inline f32 randFloat() { return System::getRand(1.0f); }
static inline f32 randFloat(f32 max) { return max * System::getRand(1.0f); }
static inline f32 randBalanced(f32 centre) { return System::getRand(1.0f) - centre; }
static inline bool coinFlip() { return System::getRand(1.0f) > 0.5f; }

extern "C" void OSPanic(const char* filename, int line, const char* msg, ...);

#endif
