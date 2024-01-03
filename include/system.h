#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "types.h"
#include "AyuHeap.h"
#include "GfxobjInfo.h"
#include "CoreNode.h"

struct RandomAccessStream;
struct Graphics;
struct BaseApp;

enum TimerState {
	TS_Off = 0, // _00
	TS_On,      // _01
	TS_Full     // _02
};

struct CacheTexture;
struct LoadIdler;
struct Timers;
struct BaseShape;
struct CoreNode;
struct LFInfo;
struct LightFlare;
struct LFlareGroup;
struct AyuHeap;
struct Matrix4f;

/**
 * @brief TODO
 */
struct StdSystem {
	virtual void initSoftReset();                            // _08
	virtual void openFile(char*, bool, bool);                // _0C
	virtual void copyRamToCache(u32, u32, u32);              // _10
	virtual void copyCacheToRam(u32, u32, u32);              // _14
	virtual void copyWaitUntilDone();                        // _18
	virtual void copyCacheToTexture(struct CacheTexture*);   // _1C
	virtual void Activate(bool);                             // _20
	virtual void parseArchiveDirectory(char*, char*);        // _24
	virtual void sndPlaySe(u32) = 0;                         // _28
	virtual void startLoading(struct LoadIdler*, bool, u32); // _2C
	virtual void endLoading();                               // _30

	static char* stringDup(char*);

	bool mPending;                 // _04
	f32 mCurrentFade;              // _08
	f32 mFadeStart;                // _0C
	f32 mFadeEnd;                  // _10
	struct Font* mConsFont;        // _14
	s32 mFrameRate;                // _18
	TimerState mTimerState;        // _1C
	u32 mTogglePrint;              // _20
	u32 mToggleDebugInfo;          // _24
	u32 mToggleDebugExtra;         // _28
	u32 mToggleBlur;               // _2C
	u32 mToggleFileInfo;           // _30
	u32 mToggleColls;              // _34
	struct Timers* mTimer;         // _38
	struct TextureCacher* mCacher; // _3C
	u32 _40;                       // _40
	Matrix4f* mMatrix;             // _44
	s8* mBloDirectory;             // _48
	s8* mTexDirectory;             // _4C
	s8* mCurrentDirectory;         // _50
	s8* mDataRoot;                 // _54
	AyuHeap mHeaps[8];             // _58 (sys, ovl, app, load, teki, movie, message, lang)
	s32 mActiveHeapIdx;            // _198
	u32 _19C;                      // _19C
	u32 _1A0;                      // _1A0
	u32 _1A4;                      // _1A4
	u32 mMaterialCount;            // _1A8
	u32 mDispCount;                // _1AC
	u32 mLightCount;               // _1B0
	u32 _1B4;                      // _1B4
	u32 mLoadedPolys;              // _1B8
	u32 mLightingSkips;            // _1BC
	u32 mLightingSets;             // _1C0
	u32 mSystemState;              // _1C4
	u32 mSystemFlags;              // _1C8
	Graphics* mGraphics;           // _1CC
	GfxobjInfo mGfxObjects;        // _1D0
	bool mHasGfxObjects;           // _1F0
	char* mTextureBase1;           // _1F4
	char* mTextureBase2;           // _1F8
	BaseShape* mCurrentShape;      // _1FC
	CoreNode _200;                 // _200
	CoreNode _214;                 // _214
	u32 _228;                      // _228
	u32 mFlareCount;               // _22C
	u32 mLfInfoCount;              // _230
	LFInfo* mLfInfo;               // _234
	LightFlare* mLightFlares;      // _238
	LFlareGroup* mLfGroups;        // _23C
	u32 _240;                      // _240
};

struct System : public StdSystem {
	virtual void initSoftReset();                     // _08
	virtual void openFile(char*, bool, bool);         // _0C
	virtual void copyRamToCache(u32, u32, u32);       // _10
	virtual void copyCacheToRam(u32, u32, u32);       // _14
	virtual void copyWaitUntilDone();                 // _18
	virtual void copyCacheToTexture(CacheTexture*);   // _1C
	virtual void parseArchiveDirectory(char*, char*); // _24
	virtual void sndPlaySe(u32);                      // _28
	virtual void startLoading(LoadIdler*, bool, u32); // _2C
	virtual void endLoading();                        // _30

	void run(BaseApp* app);

	void Initialise();
	static void* alloc(size_t);

	// _244
	u32 _244;        // _244
	u32 _248;        // _248
	Graphics* mGfx;  // _24C
	char _250[0x3C]; // _250
	f32 _28C;        // _28C
	char _290[0xA4]; // _290
};

extern System* gsys;

struct NodeMgr {
	char filler0[0x18];
	NodeMgr();
};

extern NodeMgr* nodeMgr;

extern "C" void OSPanic(const char* filename, int line, const char* msg, ...);

inline void* operator new(size_t size) { return System::alloc(size); }
#endif
