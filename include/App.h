#ifndef _APP_H
#define _APP_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 */
struct BaseApp : public Node {
	virtual ~BaseApp();                  // _30
	virtual void InitApp(char*);         // _34 (weak)
	virtual void idle();                 // _38 (weak)
	virtual void keyDown(int, int, int); // _3C (weak)
	virtual void softReset();            // _40
	virtual void useHeap(int);           // _44 (weak)
	virtual void procCmd(char*);         // _48 (weak)

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameApp : public BaseApp {
	virtual ~GameApp();  // _30 (weak)
	virtual void idle(); // _38 (weak)

	void renderall();

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct PlugPikiApp : public BaseApp {
	PlugPikiApp();

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14
	virtual ~PlugPikiApp();       // _30 (weak)
	virtual void idle();          // _38
	virtual void softReset();     // _40

	// _00 = VTBL
	// TODO: members
	u8 _04[0x54 - 0x4]; // _04, unknown
};

#endif
