#ifndef _SECTION_H
#define _SECTION_H

#include "types.h"
#include "Node.h"

struct Controller;
struct ModeState;
struct Menu;

/**
 * @brief TODO
 *
 * @note Size: 0x44.
 */
struct BaseGameSection : public Node {
	BaseGameSection();

	virtual void draw(Graphics&); // _14
	virtual void openMenu() { }   // _30

	// _00     = VTBL
	// _00-_20 = Node
	Menu* mActiveMenu;            // _20
	Controller* mController;      // _24
	f32 mCurrentFade;             // _28
	f32 mTargetFade;              // _2C
	f32 mFadeSpeed;               // _30
	ModeState* mCurrentModeState; // _34, unknown
	ModeState* mNextModeState;    // _38, unknown
	u32 mUpdateFlags;             // _3C, unknown
	int mNextSectionId;           // _40
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
