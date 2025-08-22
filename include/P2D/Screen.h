#ifndef _P2D_SCREEN_H
#define _P2D_SCREEN_H

#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "types.h"

namespace zen {
struct PikaAlphaMgr;
struct ogTexAnimMgr;
} // namespace zen

/**
 * @brief TODO
 *
 * @note Size: 0xF8.
 */
struct P2DScreen : public P2DPane {
public:
	P2DScreen()
	    : P2DPane(nullptr, PANETYPE_Screen, true, 'root', PUTRect(640, 480))
	{
		_EC         = 0;
		mAlphaMgr   = nullptr;
		mTexAnimMgr = nullptr;
	}

	virtual void loadResource();                                       // _08
	virtual ~P2DScreen();                                              // _10
	virtual P2DPane* search(u32, bool);                                // _34

	void update();
	void draw(int, int, const P2DGrafContext*);

	void set(const char* bloFileName, bool useAlphaMgr, bool useTexAnimMgr, bool p4);
	void set(const char* bloFileName, bool p2) { set(bloFileName, false, false, p2); }
	void set(RandomAccessStream*);

protected:
	virtual P2DPane* makeUserPane(u16, P2DPane*, RandomAccessStream*); // _3C

	void makeHiearachyPanes(P2DPane*, RandomAccessStream*, bool, bool);

private:
	P2DPane* stop();
	void makeResName(const char*, char*);

	// _00     = VTBL
	// _00-_EC = P2DPane
	bool _EC;                       // _EC
	zen::PikaAlphaMgr* mAlphaMgr;   // _F0
	zen::ogTexAnimMgr* mTexAnimMgr; // _F4, unknown
};

#endif
