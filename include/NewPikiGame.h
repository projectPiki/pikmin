#ifndef _NEWPIKIGAME_H
#define _NEWPIKIGAME_H

#include "types.h"
#include "Section.h"

struct MapMgr;

/**
 * @brief TODO
 */
struct NewPikiGameSection : public Section {
	NewPikiGameSection();

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members?
};

/**
 * @brief TODO
 */
struct NewPikiGameSetupSection : public BaseGameSection {
	virtual void update();        // _10
	virtual void draw(Graphics&); // _14
	virtual void openMenu();      // _30

	void init2Ddata();
	void createMapObjects(MapMgr*);

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	// TODO: members?
};

#endif
