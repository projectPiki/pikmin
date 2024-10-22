#ifndef _MENU_H
#define _MENU_H

#include "types.h"
#include "Node.h"
#include "Delegate.h"
#include "Colour.h"

struct Controller;
struct Font;
struct Light;

/**
 * @brief TODO
 */
struct Menu : public Node {

	/**
	 * @brief TODO
	 */
	enum MenuState {
		STATE_Unk0 = 0,
		STATE_Unk1 = 1,
		STATE_Unk2 = 2,
		STATE_Unk3 = 3,
	};

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

		KeyEvent* mPrev;              // _00
		KeyEvent* mNext;              // _04
		int _08;                      // _08
		int _0C;                      // _0C
		IDelegate1<Menu&>* mDelegate; // _10
	};

	/**
	 * @brief TODO
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

		MenuItem* mPrev;      // _00
		MenuItem* mNext;      // _04
		u32 _08;              // _08, unknown
		Menu* mMenu;          // _0C
		u32 _10;              // _10, unknown
		bool _14;             // _14
		char* mName;          // _18
		int _1C;              // _1C
		int _20;              // _20
		KeyEvent* mEventList; // _24
	};

	Menu(Controller*, Font*, bool);

	virtual bool checkSelectKey();  // _30
	virtual bool checkCancelKey();  // _34
	virtual bool checkNewOption();  // _38
	virtual void enterOption();     // _3C
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
		_2C->mNext = item;
		_2C->mPrev = item;
	}

	// _00     = VTBL
	// _00-_20 = Node
	Menu* _20;               // _20
	Menu* _24;               // _24
	Menu* _28;               // _28
	MenuItem* _2C;           // _2C
	MenuItem* _30;           // _30
	MenuItem* _34;           // _34
	u32 _38;                 // _38, unknown
	int _3C;                 // _3C
	int _40;                 // _40, option count?
	f32 _44;                 // _44
	u32 _48;                 // _48, unknown - struct from here...
	int _4C;                 // _4C
	u32 _50;                 // _50, unknown
	u32 _54;                 // _54, unknown - to here?
	Controller* mController; // _58
	u32 _5C;                 // _5C, unknown
	Colour _60;              // _60
	Colour _64;              // _64
	u32 _68;                 // _68, unknown - struct from here...
	u32 _6C;                 // _6C, unknown
	u32 _70;                 // _70, unknown
	u32 _74;                 // _74, unknown - to here?
	u32 _78;                 // _78, unknown - struct from here...
	u32 _7C;                 // _7C, unknown
	u32 _80;                 // _80, unknown
	u32 _84;                 // _84, unknown - to here?
	IDelegate1<Menu&>* _88;  // _88
	IDelegate1<Menu&>* _8C;  // _8C
	u8 _90[0x4];             // _90, unknown
	IDelegate1<Menu&>* _94;  // _94
	u8 _98;                  // _98
	u8 _99;                  // _99
	Font* mFont;             // _9C
	int _A0;                 // _A0
	int _A4;                 // _A4
	u32 _A8;                 // _A8, unknown
	int mState;              // _AC, see MenuState enum
	f32 _B0;                 // _B0
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
