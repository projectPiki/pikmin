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

	bool m_pending;                 // _04
	f32 m_currentFade;              // _08
	f32 m_fadeStart;                // _0C
	f32 m_fadeEnd;                  // _10
	struct Font* m_consFont;        // _14
	s32 m_frameClamp;               // _18
	TimerState m_timerState;        // _1C
	u32 m_togglePrint;              // _20
	u32 m_toggleDInfo;              // _24
	u32 m_toggleDExtra;             // _28
	u32 m_toggleBlur;               // _2C
	u32 m_toggleFileInfo;           // _30
	u32 m_toggleColls;              // _34
	struct Timers* m_timer;         // _38
	struct TextureCacher* m_cacher; // _3C
	u32 m_dword40;                  // _40
	Matrix4f* m_matrix;             // _44
	s8* m_bloDirectory;             // _48
	s8* m_texDirectory;             // _4C
	s8* m_currentDirectory;         // _50
	s8* m_dataRoot;                 // _54
	AyuHeap m_heaps[8];             // _58 (sys, ovl, app, load, teki, movie, message, lang)
	s32 m_activeHeapNum;            // _5C, TODO: the offsets must be wrong, LOL
	u32 m_dword19C;                 // _19C
	u32 m_dword1A0;                 // _1A0
	u32 m_dword1A4;                 // _1A4
	u32 m_materialCount;            // _1A8
	u32 m_dispCount;                // _1AC
	u32 m_lightCount;               // _1B0
	u32 m_dword1B4;                 // _1B4
	u32 m_loadedPolys;              // _1B8
	u32 m_lightingSkips;            // _1BC
	u32 m_lightingSets;             // _1C0
	u32 m_systemState;              // _1C4
	u32 m_systemFlags;              // _1C8
	Graphics* m_graphics;           // _1CC
	GfxobjInfo m_gfxObjects;        // _1D0
	bool m_hasGfxObjects;           // _1F0
	char* m_textureBase1;           // _1F4
	char* m_textureBase2;           // _1F8
	BaseShape* m_currentShape;      // _1FC
	CoreNode m_coreNode200;         // _200
	CoreNode m_coreNode214;         // _214
	u32 m_dword228;                 // _228
	u32 m_flareCount;               // _22C
	u32 m_lfInfoCount;              // _230
	LFInfo* m_lfInfo;               // _234
	LightFlare* m_lightFlares;      // _238
	LFlareGroup* m_lfGroups;        // _23C
	u32 m_dword240;                 // _240
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
	u32 _248;
	Graphics* mGfx;  // _24C
	char _250[0x3C]; // _250
	f32 _28C;
	char _290[0xA4];
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
