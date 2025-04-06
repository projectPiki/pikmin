#ifndef _SECTION_H
#define _SECTION_H

#include "types.h"
#include "Node.h"

struct Controller;
struct ModeState;
struct Menu;

/**
 * @brief TODO
 */
struct BaseGameSection : public Node {
	BaseGameSection();

	virtual void draw(Graphics&); // _14
	virtual void openMenu();      // _30

	// _00     = VTBL
	// _00-_20 = Node
	Menu* _20;               // _20
	Controller* mController; // _24
	f32 mCurrentFade;        // _28
	f32 mTargetFade;         // _2C
	f32 mFadeSpeed;          // _30
	ModeState* _34;          // _34, unknown
	ModeState* _38;          // _38, unknown
	u32 _3C;                 // _3C, unknown
	u32 _40;                 // _40, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct Section : public Node {
	Section() { }

	virtual void init() = 0; // _30

	// _00     = VTBL
	// _00-_20 = Node
};

#endif
