#ifndef _CARDSELECT_H
#define _CARDSELECT_H

#include "types.h"
#include "Section.h"

/**
 * @brief TODO
 */
struct CardSelectSection : public Section {
	CardSelectSection();

	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

/**
 * @brief TODO
 */
struct CardSelectSetupSection : public Node {
	virtual void update();        // _10 (weak)
	virtual void draw(Graphics&); // _14 (weak)

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
