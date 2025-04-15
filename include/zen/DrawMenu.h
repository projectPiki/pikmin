#ifndef _ZEN_DRAWMENU_H
#define _ZEN_DRAWMENU_H

#include "types.h"
#include "zen/DrawCommon.h"
#include "P2D/Picture.h"
#include "Colour.h"

struct Colour;
struct Graphics;
struct Controller;
struct P2DScreen;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct DrawMenuText {
	DrawMenuText()
	{
		_10 = 0.0f;
		_00 = 0;
		_14 = 1;
		_04 = 0;
		_00 = 0;
	}

	void init(bool, Colour&, Colour&);
	void setPane(P2DPane*, P2DPane*);
	void update(bool, Colour&, Colour&);

	// unused/inlined:
	void setScale(f32, f32);

	// DLL to do:
	bool getActiveSw();
	void setActiveSw(bool);
	u8 colorBlend(u8, f32, u8, f32);

	static const f32 frameMax;

	P2DTextBox* _00; // _00
	P2DTextBox* _04; // _04
	Colour _08;      // _08
	Colour _0C;      // _0C
	f32 _10;         // _10
	u8 _14;          // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct DrawMenuItem {
	DrawMenuItem()
	{
		mText      = new DrawMenuText();
		mIconLPane = nullptr;
		mIconRPane = nullptr;
	}

	~DrawMenuItem() { delete mText; }

	// DLL:
	void setTextPane(P2DPane* pane1, P2DPane* pane2) { mText->setPane(pane1, pane2); }

	bool setIconLPane(P2DPane* iconPane, P2DPane* iconParent)
	{
		bool isNotPic = true;
		if (iconPane->getTypeID() == PANETYPE_Picture) {
			mIconLPane = (P2DPicture*)iconPane;
			mIconLPane->hide();
			P2DPaneLibrary::changeParent(mIconLPane, iconParent);
			isNotPic = false;
		}

		return isNotPic;
	}

	bool setIconRPane(P2DPane* iconPane, P2DPane* iconParent)
	{
		bool isNotPic = true;
		if (iconPane->getTypeID() == PANETYPE_Picture) {
			mIconRPane = (P2DPicture*)iconPane;
			mIconRPane->hide();
			P2DPaneLibrary::changeParent(mIconRPane, iconParent);
			isNotPic = false;
		}

		return isNotPic;
	}

	void init(bool p1, Colour& p2, Colour& p3) { mText->init(p1, p2, p3); }

	void update(bool p1, Colour& p2, Colour& p3) { mText->update(p1, p2, p3); }

	int getIconLPosH() { return mIconLPane->getPosH(); }
	int getIconLPosV() { return mIconLPane->getPosV(); }
	int getIconRPosH() { return mIconRPane->getPosH(); }
	int getIconRPosV() { return mIconRPane->getPosV(); }

	// DLL inlines to do:
	bool getActiveSw();
	void setActiveSw(bool);
	void setScale(f32, f32);

	DrawMenuText* mText;    // _00
	P2DPicture* mIconLPane; // _04
	P2DPicture* mIconRPane; // _08
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

	// _00-_100 = DrawScreen
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
		STATUS_Unk1 = 1,
		STATUS_Unk2 = 2,
		STATUS_Unk3 = 3,
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

	f32 getRatio() { return mRatio; }

	// DLL inlines, to do:
	bool checkSelectMenuCancel() { return mSelectMenuCancel; }
	void setCancelKeyAssign(u32);
	void setCancelSE(int);
	void setDecideKeyAssign(u32);

	// _00     = VTBL
	// _00-_100 = DrawScreen
	int _100;               // _100
	u8 _104[0x8];           // _104, unknown
	f32 mRatio;             // _10C
	int _110;               // _110
	u8 _114[0xBC];          // _114, unknown
	int _1D0;               // _1D0
	bool mSelectMenuCancel; // _1D4
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
