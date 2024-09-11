#ifndef _NINLOGOSECTION_H
#define _NINLOGOSECTION_H

#include "types.h"
#include "Section.h"

struct Menu;

/**
 * @brief TODO
 */
struct NinLogoSection : public Section {
	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

/**
 * @brief TODO
 */
struct NinLogoSetupSection : public Node {
	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	void drawMenu(Graphics&, Menu*, f32);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
