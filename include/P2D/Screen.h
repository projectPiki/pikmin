#ifndef _P2D_SCREEN_H
#define _P2D_SCREEN_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"

/**
 * @brief TODO
 */
struct P2DScreen : public P2DPane {
	virtual void loadResource();                                   // _08
	virtual ~P2DScreen();                                          // _10
	virtual void search(u32, bool);                                // _34
	virtual void makeUserPane(u16, P2DPane*, RandomAccessStream*); // _3C

	void update();
	void set(const char*, bool, bool, bool);
	void makeHiearachyPanes(P2DPane*, RandomAccessStream*, bool, bool);
	void draw(int, int, const P2DGrafContext*);
	void makeResName(const char*, char*);

	// unused/inlined:
	void set(RandomAccessStream*);
	void stop();

	// _00     = VTBL
	// _00-_?? = P2DPane
	// TODO: members
};

#endif
