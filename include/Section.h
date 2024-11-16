#ifndef _SECTION_H
#define _SECTION_H

#include "types.h"
#include "Node.h"

struct Controller;

/**
 * @brief TODO
 */
struct BaseGameSection : public Node {
	BaseGameSection();

	virtual void draw(Graphics&); // _14
	virtual void openMenu();      // _30

	// _00     = VTBL
	// _00-_20 = Node
	u32 _20;                 // _20, unknown
	Controller* mController; // _24
	f32 _28;                 // _28
	f32 _2C;                 // _2C
	f32 _30;                 // _30
	u32 _34;                 // _34, unknown
	u32 _38;                 // _38, unknown
	u32 _3C;                 // _3C, unknown
	u32 _40;                 // _40, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct Section : public Node {
	virtual void init() = 0; // _30

	// _00     = VTBL
	// _00-_20 = Node
};

#endif
