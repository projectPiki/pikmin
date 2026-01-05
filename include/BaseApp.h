#ifndef _BASEAPP_H
#define _BASEAPP_H

#include "Node.h"
#include "system.h"

struct AtxCommandStream;
struct AgeServer;

/**
 * @brief Base class for applications, managing app lifecycle, resources, and some debugging.
 *
 * Game-specific sections are hooked up to this update loop by making them child nodes of this list
 * (or child nodes of their children) so they are iteratively updated and drawn.
 * Only used in the DOL for the PlugPikiApp game application, but has more built-in flexibility that is unused.
 *
 * @note Size: 0x54.
 */
struct BaseApp : public Node {
public:
	BaseApp();

	int idleupdate();

	/**
	 * @brief Gets a random float between 0 and given value. Unused in DOL.
	 * @param range Range to return over (i.e. between 0 and `range`).
	 * @return Random value within range.
	 */
	f32 rnd(f32 range) { return range * rnd(); }

	/**
	 * @brief Gets a random float between 0 and 1. Unused in DOL.
	 * @return Random value between 0 and 1.
	 */
	f32 rnd() { return rand() / 32767.0f; }

	void startAgeServer();
	void stopAgeServer();

	virtual ~BaseApp(); // _30

	/// Trivial. Parameter unknown/unused.
	virtual void InitApp(char*) { } // _34

	/**
	 * @brief Trivial idle loop.
	 * @return Always 0.
	 */
	virtual int idle() { return 0; } // _38

	/**
	 * @brief Trivial. Parameters unknown.
	 * @return Always `false`.
	 */
	virtual bool keyDown(int, int, int) { return false; } // _3C

	virtual void softReset(); // _40

	/**
	 * @brief Sets system heap by index, and stores the index to use for the idle game loop.
	 * @param index Heap index to set - see `SystemHeapType` enum.
	 */
	virtual void useHeap(int index) // _44
	{
		mHeapIndex = index;
		gsys->setHeap(mHeapIndex);
	}

	/// Trivial. Parameter unknown.
	virtual void procCmd(char*) { } // _48

protected:
	// _00     = VTBL
	// _00-_20 = Node
	AtxCommandStream* mCommandStream; ///< _20, stream of commands from ATX server.
	AgeServer* mAgeServer;            ///< _24, Age server for editing/debugging.
	s8 _28;                           ///< _28, unknown/unused.
	BOOL mIsReadyToDraw;              ///< _2C, whether application is ready to commence drawing - requires a soft reset.
	Node mWindowNode;                 ///< _30, likely a list of windows related to debugging, but never used beyond name in the DOL.
	u32 mHeapIndex;                   ///< _50, index of heap to use for the idle game loop.
};

extern BaseApp* app;

#endif
