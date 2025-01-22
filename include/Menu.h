#ifndef _MENU_H
#define _MENU_H

#include "types.h"
#include "Node.h"
#include "Delegate.h"
#include "Colour.h"

struct Controller;
struct Font;
struct Light;

struct Menu : public Node {
	DEFINE_ENUM_TYPE(MenuStateType, Idle = 0, FadeIn = 1, Open = 2, FadeOut = 3);
	DEFINE_ENUM_TYPE(KeyEventType, Press = 1, Hold = 2, Input = 4, Release = 8, Navigate = 16, SpecialRelease = 32);

	/**
	 * @brief Linked list of key events.
	 *
	 * @note Size: 0x14.
	 */
	struct KeyEvent {
		KeyEvent(int, int, IDelegate1<Menu&>*); // unused/inlined

		// unused/inlined:
		void insertAfter(KeyEvent*);
		void remove();

		KeyEvent* mPrev;               // _00
		KeyEvent* mNext;               // _04
		KeyEventType::Type mEventType; // _08
		int mInputCode;                // _0C
		IDelegate1<Menu&>* mDelegate;  // _10
	};

	DEFINE_ENUM_TYPE(MenuNavigationType, TopMenu = 1, SubMenu = 2);

	/**
	 * @brief Represents an item in the menu.
	 *
	 * @note Size: 0x28.
	 */
	struct MenuItem {

		MenuItem(int, int, char*, IDelegate1<Menu&>*);

		bool checkEvents(Menu*, int);

		// unused/inlined:
		void insertAfter(MenuItem*);
		void remove();

		void resetKeyEvent(KeyEvent* key)
		{
			mEventList->mPrev = key;
			mEventList->mNext = key;
		}

		MenuItem* mPrev;                // _00
		MenuItem* mNext;                // _04
		u32 _08;                        // _08, unknown
		Menu* mMenu;                    // _0C
		u32 _10;                        // _10, unknown
		bool mIsEnabled;                // _14
		char* mName;                    // _18
		int mFilterIndex;               // _1C
		MenuNavigationType::Type mType; // _20
		KeyEvent* mEventList;           // _24
	};

	Menu(Controller*, Font*, bool);

	virtual bool checkSelectKey();  // _30
	virtual bool checkCancelKey();  // _34
	virtual bool checkNewOption();  // _38, apparently this should return BOOL not bool, idk
	virtual void enterOption();     // _3C, apparently this should return Menu*, doesn't seem to though
	virtual Menu* enterMenu(Menu*); // _40
	virtual Menu* exitMenu(Menu*);  // _44
	virtual void open(bool);        // _48
	virtual void close();           // _4C
	virtual Menu* doUpdate(bool);   // _50

	void addKeyEvent(int, int, IDelegate1<Menu&>*);
	void resetOptions();
	void addOption(int, char*, IDelegate1<Menu&>*, bool);
	void addMenu(Menu*, int, char*);
	void draw(Graphics&, f32);
	void menuCloseMenu(Menu&);

	// unused/inlined:
	void setOnEnter(IDelegate1<Menu&>*);
	void setOnExit(IDelegate1<Menu&>*);

	inline void resetMenuItem(MenuItem* item)
	{
		mLastItem->mNext = item;
		mLastItem->mPrev = item;
	}

	// _00     = VTBL
	// _00-_20 = Node
	Menu* mParentMenu;      // _20
	Menu* mPreviousMenu;    // _24
	Menu* mNextMenu;        // _28
	MenuItem* mLastItem;    // _2C
	MenuItem* mCurrentItem; // _30
	MenuItem* mFirstItem;   // _34
	u32 _38;                // _38, unknown
	int mUseCustomPosition; // _3C
	int mMenuCount;         // _40, option count?
	f32 mAnimationProgress; // _44

	// RectArea?
	u32 mScreenMiddleX; // _48, unknown - struct from here...
	int mScreenMiddleY; // _4C
	u32 _50;            // _50, unknown
	u32 _54;            // _54, unknown - to here?

	Controller* mController;                    // _58
	u32 _5C;                                    // _5C, unknown
	Colour mDiffuseColour;                      // _60
	Colour mHighlightColour;                    // _64
	u32 _68;                                    // _68, unknown - struct from here...
	u32 _6C;                                    // _6C, unknown
	u32 _70;                                    // _70, unknown
	u32 _74;                                    // _74, unknown - to here?
	u32 _78;                                    // _78, unknown - struct from here...
	u32 _7C;                                    // _7C, unknown
	u32 _80;                                    // _80, unknown
	u32 _84;                                    // _84, unknown - to here?
	IDelegate1<Menu&>* mOnStateChangeCallback;  // _88
	IDelegate1<Menu&>* mOnMenuSwitchCallback;   // _8C
	u8 _90[0x4];                                // _90, unknown
	IDelegate1<Menu&>* mOnOptionChangeCallback; // _94
	u8 mIsMenuChanging;                         // _98
	bool isOptionSelected;                      // _99
	Font* mFont;                                // _9C
	int _A0;                                    // _A0
	int mInputCode;                             // _A4
	u32 _A8;                                    // _A8, unknown
	int mState;                                 // _AC, see MenuState enum
	f32 mOpeningFadeProgress;                   // _B0
};

/**
 * @brief TODO
 */
struct ColourMenu : public Menu {
	ColourMenu(Colour*, Controller*, Font*, bool);

	void menuEnterA(Menu&);
	void menuEnterB(Menu&);
	void menuEnterG(Menu&);
	void menuEnterR(Menu&);
	void menuIncrease(Menu&);
	void menuDecrease(Menu&);

	// _00     = VTBL
	// _00-_?? = Menu
	// TODO: members
};

/**
 * @brief TODO
 */
struct DaySetMenu : public Menu {
	inline DaySetMenu(); // TODO: fix, not in map but needed

	// _00     = VTBL
	// _00-_?? = Menu
	// TODO: members
};

/**
 * @brief TODO
 */
struct FogMenu : public Menu {
	FogMenu(Colour*, f32*, f32*, Controller*, Font*, bool);

	void menuEnterFar(Menu&);
	void menuEnterNear(Menu&);
	void menuIncrease(Menu&);
	void menuDecrease(Menu&);

	// _00     = VTBL
	// _00-_?? = Menu
	// TODO: members
};

/**
 * @brief TODO
 */
struct LightMenu : public Menu {
	LightMenu(Light*, int*, Controller*, Font*, bool);

	void menuChangeMove(Menu&);
	void menuChangeType(Menu&);
	void menuEnterNear(Menu&);
	void menuIncrease(Menu&);
	void menuDecrease(Menu&);

	// _00     = VTBL
	// _00-_?? = Menu
	// TODO: members
};

/**
 * @brief TODO
 */
struct PositionMenu : public Menu {
	PositionMenu(Vector3f*, Controller*, Font*, bool, bool);

	void menuEnterZ(Menu&);
	void menuEnterY(Menu&);
	void menuEnterX(Menu&);
	void menuIncrease(Menu&);
	void menuDecrease(Menu&);

	// _00     = VTBL
	// _00-_?? = Menu
	// TODO: members
};

#endif
