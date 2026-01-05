#ifndef _APP_H
#define _APP_H

#include "BaseApp.h"
#include "gameflow.h"
#include "timers.h"
#include "types.h"

/**
 * @brief Intermediate game application structure, for playing specifically on console.
 *
 * Not functional by itself with no non-trivial idle/update loop, so requires further specialisation.
 *
 * @note Size: 0x54.
 */
struct GameApp : public BaseApp {

	/// Trivial with nothing further to delete.
	virtual ~GameApp() { } // _30 (weak)

	/**
	 * @brief Trivial idle loop.
	 * @return Always 1.
	 */
	virtual int idle() { return 1; } // _38 (weak)

	void renderall();

	/// @todo Implement this unused DLL function.
	void doInitApp();

	// _00     = VTBL
	// _00-_54 = BaseApp
};

/**
 * @brief TODO
 *
 * @note Size: 0x54.
 */
struct PlugPikiApp : public GameApp {
	PlugPikiApp();

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	/// Trivial with nothing further to delete.
	virtual ~PlugPikiApp() { } // _30 (weak)

	virtual int idle();       // _38
	virtual void softReset(); // _40

	void hardReset();

	// _00     = VTBL
	// _00-_54 = GameApp
};

#endif
