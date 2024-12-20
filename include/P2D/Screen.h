#ifndef _P2D_SCREEN_H
#define _P2D_SCREEN_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"

/**
 * @brief TODO
 *
 * @note Size: 0xF8.
 */
struct P2DScreen : public P2DPane {
	inline P2DScreen()
	    : P2DPane(nullptr, PANETYPE_Screen, true, 'root', PUTRect(640, 480))
	{
		_EC = 0;
		_F0 = 0;
		_F4 = 0;
	}

	virtual void loadResource();                                   // _08
	virtual ~P2DScreen();                                          // _10
	virtual P2DPane* search(u32, bool);                            // _34
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
	// _00-_EC = P2DPane
	u8 _EC;  // _EC
	u32 _F0; // _F0, unknown
	u32 _F4; // _F4, unknown
};

#endif
