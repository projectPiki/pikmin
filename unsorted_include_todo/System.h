#ifndef _SYSTEM_H
#define _SYSTEM_H

/**
 * .obj __vt__6System, global
 * .4byte __RTTI__6System
 * .4byte 0
 * .4byte initSoftReset__6SystemFv
 * .4byte openFile__6SystemFPcbb
 * .4byte copyRamToCache__6SystemFUlUlUl
 * .4byte copyCacheToRam__6SystemFUlUlUl
 * .4byte copyWaitUntilDone__6SystemFv
 * .4byte copyCacheToTexture__6SystemFP12CacheTexture
 * .4byte Activate__9StdSystemFb
 * .4byte parseArchiveDirectory__6SystemFPcPc
 * .4byte sndPlaySe__6SystemFUl
 * .4byte startLoading__6SystemFP9LoadIdlerbUl
 * .4byte endLoading__6SystemFv
 */

struct StdSystem {
	virtual void initSoftReset();                                             // _08
	virtual void openFile(char*, bool, bool);                                 // _0C
	virtual void copyRamToCache(unsigned long, unsigned long, unsigned long); // _10
	virtual void copyCacheToRam(unsigned long, unsigned long, unsigned long); // _14
	virtual void copyWaitUntilDone();                                         // _18
	virtual void copyCacheToTexture(CacheTexture*);                           // _1C
	virtual void Activate(bool);                                              // _20
};

/**
 * @brief TODO
 */
struct System : public StdSystem {
	virtual void initSoftReset();                                             // _08
	virtual void openFile(char*, bool, bool);                                 // _0C
	virtual void copyRamToCache(unsigned long, unsigned long, unsigned long); // _10
	virtual void copyCacheToRam(unsigned long, unsigned long, unsigned long); // _14
	virtual void copyWaitUntilDone();                                         // _18
	virtual void copyCacheToTexture(CacheTexture*);                           // _1C
	virtual void parseArchiveDirectory(char*, char*);                         // _24
	virtual void sndPlaySe(unsigned long);                                    // _28
	virtual void startLoading(LoadIdler*, bool, unsigned long);               // _2C
	virtual void endLoading();                                                // _30

	void beginRender();
	void doneRender();
	void waitRetrace();
	void run(BaseApp*);
	void getTime();
	void updateSysClock();
	void hardReset();
	System();
	void showDvdError(Graphics&);
	void Initialise();
	~System();
	void nudgeLoading();
	void nudgeDvdThread();
	void startDvdThread();
	void alloc(unsigned long);
};

#endif
