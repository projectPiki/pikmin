#ifndef _MENU_H
#define _MENU_H

#include "types.h"
#include "Node.h"
#include "Delegate.h"

struct Colour;
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
	struct KeyEvent {
		KeyEvent(int, int, IDelegate1<Menu&>*); // unused/inlined

		// unused/inlined:
		void insertAfter(KeyEvent*);
		void remove();

		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct MenuItem {
		MenuItem(int, int, char*, IDelegate1<Menu&>*);

		void checkEvents(Menu*, int);

		// unused/inlined:
		void insertAfter(MenuItem*);
		void remove();

		// TODO: members
	};

	Menu(Controller*, Font*, bool);

	virtual void checkSelectKey(); // _30
	virtual void checkCancelKey(); // _34
	virtual void checkNewOption(); // _38
	virtual void enterOption();    // _3C
	virtual void enterMenu(Menu*); // _40
	virtual void exitMenu(Menu*);  // _44
	virtual void open(bool);       // _48
	virtual void close();          // _4C
	virtual void doUpdate(bool);   // _50

	void addKeyEvent(int, int, IDelegate1<Menu&>*);
	void resetOptions();
	void addOption(int, char*, IDelegate1<Menu&>*, bool);
	void addMenu(Menu*, int, char*);
	void draw(Graphics&, f32);
	void menuCloseMenu(Menu&);

	// unused/inlined:
	void setOnEnter(IDelegate1<Menu&>*);
	void setOnExit(IDelegate1<Menu&>*);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
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
