#ifndef _ZEN_OGTEST_H
#define _ZEN_OGTEST_H

#include "types.h"
#include "Section.h"

namespace zen {

/**
 * @brief TODO
 */
struct OgTestScreen : public Node {
	OgTestScreen();

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	void modeSelectSub();

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct OgTestSection : public Section {
	OgTestSection();

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

} // namespace zen

#endif
