#ifndef _STDSYSTEM_H
#define _STDSYSTEM_H

/**
 * .obj __vt__9StdSystem, global
 * .4byte __RTTI__9StdSystem
 * .4byte 0
 * .4byte initSoftReset__9StdSystemFv
 * .4byte openFile__9StdSystemFPcbb
 * .4byte copyRamToCache__9StdSystemFUlUlUl
 * .4byte copyCacheToRam__9StdSystemFUlUlUl
 * .4byte copyWaitUntilDone__9StdSystemFv
 * .4byte copyCacheToTexture__9StdSystemFP12CacheTexture
 * .4byte Activate__9StdSystemFb
 * .4byte parseArchiveDirectory__9StdSystemFPcPc
 * .4byte 0
 * .4byte startLoading__9StdSystemFP9LoadIdlerbUl
 * .4byte endLoading__9StdSystemFv
 */

/**
 * @brief TODO
 */
struct StdSystem {
	virtual void initSoftReset();                                             // _08
	virtual void openFile(char*, bool, bool);                                 // _0C
	virtual void copyRamToCache(unsigned long, unsigned long, unsigned long); // _10
	virtual void copyCacheToRam(unsigned long, unsigned long, unsigned long); // _14
	virtual void copyWaitUntilDone();                                         // _18
	virtual void copyCacheToTexture(CacheTexture*);                           // _1C
	virtual void Activate(bool);                                              // _20
	virtual void parseArchiveDirectory(char*, char*);                         // _24
	virtual void _28() = 0;                                                   // _28
	virtual void startLoading(LoadIdler*, bool, unsigned long);               // _2C
	virtual void endLoading();                                                // _30
};

#endif
