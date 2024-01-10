#ifndef _SECTION_H
#define _SECTION_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 */
struct BaseGameSection : public Node {
	BaseGameSection();

	virtual void draw(Graphics&); // _14
	virtual void openMenu();      // _30

	// _00     = VTBL
	// _00-_14 = Node
	// TODO: members
};

/**
 * @brief TODO
 */
struct Section : public Node {
	virtual void init() = 0; // _30

	// _00     = VTBL
	// _00-_14 = Node
	// TODO: members
};

#endif
