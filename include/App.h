#ifndef _APP_H
#define _APP_H

#include "types.h"
#include "BaseApp.h"

/**
 * @brief TODO
 */
struct GameApp : public BaseApp {
	virtual ~GameApp(); // _30 (weak)
	virtual int idle(); // _38 (weak)

	void renderall();

	// _00     = VTBL
	// _00-_14 = BaseApp
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x54.
 */
struct PlugPikiApp : public BaseApp {
	PlugPikiApp();

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14
	virtual ~PlugPikiApp();       // _30 (weak)
	virtual int idle();           // _38
	virtual void softReset();     // _40

	void hardReset();

	// _00     = VTBL
	// _00-_50 = BaseApp
};

#endif
