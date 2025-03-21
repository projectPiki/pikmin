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

	/**
	 * @brief TODO
	 */
	enum StatusFlag {
		STATUS_Unk0 = 0,
	};

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

	P2DScreen* getScreenPtr() { return &mScreen; }

	StatusFlag getStatusFlag() { return (StatusFlag)_100; }

	int getSelectMenu()
	{
		if (_1D0 >= 0) {
			return _110;
		}

		return (mSelectMenuCancel) ? -1 : _110;
	}

	// DLL inlines, to do:
	bool checkSelectMenuCancel() { return mSelectMenuCancel; }
	f32 getRatio();
	void setCancelKeyAssign(u32);
	void setCancelSE(int);
	void setDecideKeyAssign(u32);

	// _00     = VTBL
	// _00-_FC = DrawScreen
	u8 _FC[0x4];            // _FC, unknown
	int _100;               // _100, unknown
	u8 _104[0xc];           // _104, unknown
	int _110;               // _110, unknown
	u8 _114[0xBC];          // _114, unknown
	int _1D0;               // _1D0, unknown
	bool mSelectMenuCancel; // _1D4, unknown
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
