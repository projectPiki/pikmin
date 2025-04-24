#ifndef _ZEN_DRAWMENU_H
#define _ZEN_DRAWMENU_H

#include "types.h"
#include "zen/DrawCommon.h"
#include "P2D/Picture.h"
#include "zen/SpectrumCursorMgr.h"
#include "zen/MenuPanelMgr.h"
#include "zen/Math.h"
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
		mBlendTimer = 0.0f;
		mTextPane   = 0;
		mIsActive   = true;
		mParentPane = 0;
		mTextPane   = 0;
	}

	void init(bool useNewColors, Colour& charColor, Colour& gradColor);
	void setPane(P2DPane* textPane, P2DPane* parentPane);
	void update(bool, Colour&, Colour&);

	// unused/inlined:
	void setScale(f32 xScale, f32 yScale);

	bool getActiveSw() { return mIsActive; }

	u8 colorBlend(u8 comp1, f32 t1, u8 comp2, f32 t2) { return RoundOff(comp1 * t1 + comp2 * t2); }

	void setActiveSw(bool isActive) { mIsActive = isActive; }

	static const f32 frameMax;

	P2DTextBox* mTextPane;   // _00
	P2DTextBox* mParentPane; // _04
	Colour mCharColor;       // _08
	Colour mGradColor;       // _0C
	f32 mBlendTimer;         // _10
	bool mIsActive;          // _14
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

	bool getActiveSw() { return mText->getActiveSw(); }
	void setActiveSw(bool isActive) { mText->setActiveSw(isActive); }

	void setScale(f32 xScale, f32 yScale) { mText->setScale(xScale, yScale); }

	DrawMenuText* mText;    // _00
	P2DPicture* mIconLPane; // _04
	P2DPicture* mIconRPane; // _08
};

/**
 * @brief TODO
 */
struct DrawMenuTitle {

	enum Mode {
		MODE_Wait      = 0,
		MODE_Start     = 1,
		MODE_Operation = 2,
		MODE_End       = 3,
	};

	DrawMenuTitle()
	{
		mTitlePane = nullptr;
		mMode      = 0;
	}

	void setPane(P2DScreen* screen, P2DPane* parent, u32 tag);
	void start();
	void wait();
	void end();
	bool update(f32);

	// unused/inlined:
	void operation();

	int mMode;           // _00
	P2DPane* mTitlePane; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x198.
 */
struct DrawMenuBase : public DrawScreen {
	enum Mode {
		MODE_Sleep     = 0,
		MODE_Operation = 1,
	};

	typedef bool (DrawMenuBase::*ModeFunc)(Controller*);

	DrawMenuBase(char* bloFileName, bool useAlphaMgr, bool useTexAnimMgr);

	virtual void draw(Graphics&);                           // _10
	virtual bool update(Controller*);                       // _14
	virtual void start();                                   // _18
	virtual bool modeDefault(Controller*) { return false; } // _1C
	virtual bool modeSleep(Controller*);                    // _20
	virtual bool modeOperation(Controller*);                // _24
	virtual void setModeFunc(int);                          // _28

	void init(int);

	// unused/inlined:
	~DrawMenuBase() { }

	void setKeyAssignDecide(u32 button) { mKeyDecide = button; }
	void setKeyAssignCancel(u32 button) { mKeyCancel = button; }

	// DLL inlines to do:
	int getSelectNo() { return mSelectedNum; }
	u32 getEventFlag() { return mEventFlag; }

	static const int SELECT_CANCEL;

	// _00-_100 = DrawScreen
	int mMode;                         // _100
	int mCurrentHover;                 // _104
	int mSelectedNum;                  // _108
	int mOptionCount;                  // _10C
	u8 _110[0x4];                      // _110, unknown
	SpectrumCursorMgr mLeftCursorMgr;  // _114
	SpectrumCursorMgr mRightCursorMgr; // _144
	DrawMenuItem* mMenuItems;          // _174
	Colour mCharColor;                 // _178
	Colour mGradColor;                 // _17C
	ModeFunc mModeFunction;            // _180
	u32 mEventFlag;                    // _18C
	u32 mKeyDecide;                    // _190, see KeyboardButtons enum
	u32 mKeyCancel;                    // _194, see KeyboardButtons enum
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

	StatusFlag getStatusFlag() { return mState; }

	int getSelectMenu()
	{
		if (mCancelSelectMenuNo >= 0) {
			return mCurrentSelect;
		}

		return (mIsSelectMenuCancel) ? -1 : mCurrentSelect;
	}

	f32 getRatio() { return mRatio; }

	void setCancelSE(int soundID) { mCancelSoundID = soundID; }

	// DLL inlines, to do:
	bool checkSelectMenuCancel() { return mIsSelectMenuCancel; }
	void setCancelKeyAssign(u32);
	void setDecideKeyAssign(u32);

	// _00     = VTBL
	// _00-_100 = DrawScreen
	StatusFlag mState;                 // _100
	f32 _104;                          // _104
	f32 _108;                          // _108
	f32 mRatio;                        // _10C
	int mCurrentSelect;                // _110
	int mSelectCount;                  // _114
	int mSpecCount;                    // _118
	f32 _11C;                          // _11C
	f32 _120;                          // _120
	Vector2f mLeftCursorPos;           // _124
	Vector2f mRightCursorPos;          // _12C
	P2DPane* mParentPane;              // _134, 'pall'
	DrawMenuItem* mMenuItems;          // _138
	P2DPicture** mLeftCursorIcons;     // _13C
	P2DPicture** mRightCursorIcons;    // _140
	DrawMenuTitle mTitle;              // _144
	SpectrumCursorMgr mLeftCursorMgr;  // _14C
	SpectrumCursorMgr mRightCursorMgr; // _17C
	Colour mCharColor;                 // _1AC
	Colour mGradColor;                 // _1B0
	MenuPanelMgr mMenuPanelMgr;        // _1B4
	u32 mKeyDecide;                    // _1C4
	u32 mKeyCancel;                    // _1C8
	int mCancelSoundID;                // _1CC
	int mCancelSelectMenuNo;           // _1D0
	bool mIsSelectMenuCancel;          // _1D4
};

} // namespace zen

#endif
