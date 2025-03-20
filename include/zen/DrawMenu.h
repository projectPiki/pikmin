#ifndef _ZEN_DRAWMENU_H
#define _ZEN_DRAWMENU_H

#include "types.h"
#include "zen/DrawCommon.h"

struct Colour;
struct Graphics;
struct Controller;
struct P2DScreen;
struct P2DPicture;

namespace zen {

/**
 * @brief TODO
 */
struct DrawMenuItem {
	DrawMenuItem();

	~DrawMenuItem();

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawMenuBase : public DrawScreen {

	DrawMenuBase(char*, bool, bool);

	virtual void draw(Graphics&);            // _10
	virtual bool update(Controller*);        // _14
	virtual void start();                    // _18
	virtual bool modeDefault(Controller*);   // _1C
	virtual bool modeSleep(Controller*);     // _20
	virtual bool modeOperation(Controller*); // _24
	virtual void setModeFunc(int);           // _28

	void init(int);

	// unused/inlined:
	~DrawMenuBase();

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawMenu : public DrawScreen {
	DrawMenu(char*, bool, bool);

	void start(int);
	void updateMenuPanes();
	void updateSelectMenuNo(Controller*);
	bool update(Controller*);
	void draw(Graphics&);
	void setMenuItemActiveSw(int, bool);
	void setCancelSelectMenuNo(int);

	// unused/inlined:
	void setMirror(P2DPane*);
	void updateSpectPanes(P2DPane*, P2DPicture**, bool);

	u8 _00; // _00, unknown
	u8 _04; // _04, unknown
	u8 _08[0x98]; // _08, unknown
	int _100; // _100, unknown
	u8 _104[0xc]; // _104, unknown
	int _110; // _110, unknown
	u8 _114[0xb8]; // _114, unknown
	int _1d0; // _1d0, unknown
	char _1d4; // _1d4, unknown

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawMenuText {
	void init(bool, Colour&, Colour&);
	void setPane(P2DPane*, P2DPane*);
	void update(bool, Colour&, Colour&);

	// unused/inlined:
	void setScale(f32, f32);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawMenuTitle {

	void setPane(P2DScreen*, P2DPane*, u32);
	void start();
	void wait();
	void end();
	bool update(f32);

	// unused/inlined:
	void operation();

	// TODO: members
};

} // namespace zen

#endif
