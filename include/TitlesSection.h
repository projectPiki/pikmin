#ifndef _TITLESECTION_H
#define _TITLESECTION_H

#include "types.h"
#include "Section.h"

struct Menu;

/**
 * @brief TODO
 */
struct TitlesSection : public Section {
	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TitleSetupSection : public Node {
	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	void menuSelectOption(Menu&);
	void drawMenu(Graphics&, Menu*, f32);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
