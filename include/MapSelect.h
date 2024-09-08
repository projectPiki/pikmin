#ifndef _MAPSELECT_H
#define _MAPSELECT_H

#include "types.h"
#include "Section.h"

struct Menu;

/**
 * @brief TODO
 */
struct MapSelectSection : public Section {
	MapSelectSection();

	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

/**
 * @brief TODO
 */
struct MapSelectSetupSection : public Node {
	virtual void update();        // _10 (weak)
	virtual void draw(Graphics&); // _14 (weak)

	void openAllChMaps(Menu&);
	void openAllMaps(Menu&);
	void menuSelectOption(Menu&);
	void makeMapsMenu();

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
