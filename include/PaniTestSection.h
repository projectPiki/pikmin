#ifndef _PANITESTSECTION_H
#define _PANITESTSECTION_H

#include "types.h"
#include "Section.h"

struct PaniAnimKeyEvent;
struct Teki;
struct ViewPiki;

/**
 * @brief TODO
 */
struct PaniTestNode : public Node {
	PaniTestNode();

	virtual void update();                               // _10
	virtual void draw(Graphics&);                        // _14
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _3C

	void setTestMode(int);
	void updatePikis();
	void updateTekis();
	void drawPiki(ViewPiki*, Graphics&);
	void drawTeki(Teki*, Graphics&);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniTestSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

#endif
