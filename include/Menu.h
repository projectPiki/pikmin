#ifndef _MENU_H
#define _MENU_H

#include "Colour.h"
#include "Delegate.h"
#include "Geometry.h"
#include "Node.h"
#include "system.h"
#include "types.h"

struct TimeSetting;
struct Controller;
struct Font;
struct Light;

// Menu background colors

/// Purple with 75% opacity, used as the default top colour.
#define MENU_COLOUR_PURPLE 32, 32, 128, 192

/// Dark red with 75% opacity, used as a top colour for some menus.
#define MENU_COLOUR_RED 128, 32, 32, 192

/// Green with 75% opacity, used as a top colour for some menus.
#define MENU_COLOUR_GREEN 32, 128, 32, 192

/// Teal-green with 75% opacity, used as a top colour for some menus.
#define MENU_COLOUR_TEAL 32, 128, 128, 192

/// Dark red with 100% opacity, used as a top colour for some menus.
#define MENU_COLOUR_DARK_RED 128, 32, 32, 255

/// Medium grey with 25% opacity, used as the default bottom colour.
#define MENU_COLOUR_DEFAULT_GREY 32, 32, 32, 64

/// Medium grey with 50% opacity, used as a bottom colour for some menus.
#define MENU_COLOUR_MEDIUM_GREY 32, 32, 32, 128

/// Grey with a very slight green tint with 50% opacity, used as a bottom colour for green menus.
#define MENU_COLOUR_GREEN_GREY 32, 64, 32, 64

/// Parameters to use for `Menu::addOption` to create an inert option that is skipped over.
#define MENU_FAKE_OPTION_FOR_GAP 0, nullptr, nullptr

/**
 * @brief Text-based debug menu for adjusting game parameters. Inaccessible from retail code, but used extensively in the DLL.
 *
 * Some exposed code remains, but is never called. Re-implemented debug menus are enabled using the `DEVELOP` build variable.
 *
 * @note Size: 0xB4.
 */
struct Menu : public Node {

	/**
	 * @brief `MenuStateType`: Operating states that a debug menu can be in.
	 */
	BEGIN_ENUM_TYPE(MenuStateType)
	enum {
		Idle    = 0, ///< 0, inactive/in the background if a pop-out menu is open.
		FadeIn  = 1, ///< 1, fading in/starting.
		Open    = 2, ///< 2, open and active.
		FadeOut = 3, ///< 3, fading out/closing.
	} END_ENUM_TYPE;

	/**
	 * @brief `KeyEventType`: Types of key events triggering different callbacks.
	 *
	 * "While" types are triggered every frame while the condition is true; "On" types are triggered once when condition becomes true.
	 */
	BEGIN_ENUM_TYPE(KeyEventType)
	enum {
		EmptyHead      = 0,      ///< 0, head/sentinel node of event list - not a valid actionable event.
		OnFocusGained  = 1 << 0, ///< 1, trigger callback when item becomes focused/highlighted.
		OnFocusLost    = 1 << 1, ///< 2, trigger callback when item stops being focused/highlighted.
		WhileInputHeld = 1 << 2, ///< 3, trigger callback every frame when input is pressed down.
		OnInputRelease = 1 << 3, ///< 4, trigger callback when input is released.
		OnConfirm      = 1 << 4, ///< 5, trigger callback when "confirming"/selecting input is released (handles bigger changes).
		OnCancel       = 1 << 5, ///< 6, trigger callback when "cancelling" input is released (for cancelling the item/menu).

		ALL_EVENTS_MASK = 0xFFFF, ///< mask for checking all events.
	} END_ENUM_TYPE;

	/**
	 * @brief `LabelAlignmentType`: Ways that menu item labels can be aligned horizontally when rendered.
	 */
	BEGIN_ENUM_TYPE(LabelAlignmentType)
	enum {
		Centered    = 0, ///< 0, labels are centered horizontally in the debug menu box.
		LeftAligned = 1, ///< 1, labels are all aligned to the same horizontal start position.
	} END_ENUM_TYPE;

	/**
	 * @brief `MenuItemType`: Types of menu items that can be added to debug menus.
	 */
	BEGIN_ENUM_TYPE(MenuItemType)
	enum {
		EmptyHead = 0, ///< 0, head/sentinel node of item list - not a valid selectable item.
		Option    = 1, ///< 1, regular option on list that can be interacted with or selected.
		SubMenu   = 2, ///< 2, item that transits to a submenu on selection.
	} END_ENUM_TYPE;

	/**
	 * @brief Linked list of key events to associate with a menu item. Activates a callback based on controller input or condition.
	 *
	 * @note Size: 0x14.
	 */
	struct KeyEvent {
		KeyEvent(int eventType, int triggerKeys, IDelegate1<Menu&>* callback);

		void insertAfter(KeyEvent* event);
		void remove();

		KeyEvent* mPrev;                   ///< _00, previous event in the event list.
		KeyEvent* mNext;                   ///< _04, next event in the event list.
		KeyEventType::Type mEventType;     ///< _08, type of event to trigger - see `KeyEventType` enum.
		int mTriggerKeys;                  ///< _0C, buttons that will trigger the event - see `KeyboardButtons` enum.
		IDelegate1<Menu&>* mEventCallback; ///< _10, wrapped callback function to trigger on event.
	};

	/**
	 * @brief Represents an item in the menu.
	 *
	 * @note Size: 0x28.
	 */
	struct MenuItem {
		MenuItem(int itemType, int data, char* label, IDelegate1<Menu&>* confirmCallback);

		bool checkEvents(Menu* parentMenu, int eventMask);

		void insertAfter(MenuItem* item);
		void remove();

		MenuItem* mPrev;          ///< _00, previous item in list.
		MenuItem* mNext;          ///< _04, next item in list.
		u32 _08;                  ///< _08, unknown/unused.
		Menu* mSubMenu;           ///< _0C, submenu to open, if item is a SubMenu type.
		u8 _10[0x4];              ///< _10, unknown/unused.
		bool mIsEnabled;          ///< _14, whether item is selectable or not.
		char* mLabel;             ///< _18, label to render for the item.
		int mData;                ///< _1C, data attached to item - the meaning of this data payload is determined by the callback using it.
		MenuItemType::Type mType; ///< _20, type of item - see `MenuItemType` enum.
		KeyEvent* mEventListHead; ///< _24, head/sentinel node of (doubly linked) event list.
	};

	Menu(Controller* controller, Font* font, bool alignToParentItem = false);

	virtual bool checkSelectKey();           // _30
	virtual bool checkCancelKey();           // _34
	virtual bool checkNewOption();           // _38
	virtual Menu* enterOption();             // _3C
	virtual Menu* enterMenu(Menu* menu);     // _40
	virtual Menu* exitMenu(Menu* menu);      // _44
	virtual void open(bool);                 // _48
	virtual void close();                    // _4C
	virtual Menu* doUpdate(bool selectItem); // _50

	void addKeyEvent(int eventType, int triggerKeys, IDelegate1<Menu&>* callback);
	void resetOptions();
	void addOption(int data, char* label, IDelegate1<Menu&>* confirmCallback, bool isEnabled = true);
	void addMenu(Menu* subMenu, int data, char* label);
	void draw(Graphics& gfx, f32 fadeFactor);
	void menuCloseMenu(Menu& menu);

	void setOnEnter(IDelegate1<Menu&>* callback);
	void setOnExit(IDelegate1<Menu&>* callback);

	// _00     = VTBL
	// _00-_20 = Node
	Menu* mParentMenu;                          ///< _20, menu one higher in the hierarchy - contains the menu's parent item, if any.
	Menu* mReturnMenu;                          ///< _24, menu to return to on menu cancel.
	Menu* mPendingMenu;                         ///< _28, menu queued to open next on next close finish.
	MenuItem* mItemListHead;                    ///< _2C, head/sentinel node of item list - not a valid selection.
	MenuItem* mCurrentItem;                     ///< _30, currently focused/highlighted item.
	MenuItem* mLastAddedItem;                   ///< _34, most recently added item in item list (bottom of menu).
	u32 _38;                                    ///< _38, unknown/unused.
	BOOL mAlignToParentItem;                    ///< _3C, whether to align this menu vertically to its parent menu (for pop-out effect).
	int mMenuItemCount;                         ///< _40, number of items/options in list.
	f32 mSelectedLabelPulsePhase;               ///< _44, "phase" of label colour pulse effect - oscillates from light to dark grey.
	RectArea mCenterPoint;                      ///< _48, center of menu box on screen - only mMinX and mMinY are set and used.
	Controller* mController;                    ///< _58, active player controller.
	u32 _5C;                                    ///< _5C, unknown/unused.
	Colour mGradBGTopColour;                    ///< _60, colour to use for the top of the menu background gradient.
	Colour mGradBGBottomColour;                 ///< _64, colour to use for the bottom of the menu background gradient.
	RectArea _68;                               ///< _68, unknown/unused.
	RectArea _78;                               ///< _78, unknown/unused.
	IDelegate1<Menu&>* mOnEnterCallBack;        ///< _88, callback to trigger when menu is opened/entered.
	IDelegate1<Menu&>* mOnExitCallBack;         ///< _8C, callback to trigger when menu is closed/exited.
	u8 _90[0x4];                                ///< _90, unknown/unused.
	IDelegate1<Menu&>* mOnOptionChangeCallback; ///< _94, callback to trigger when selection has been changed.
	bool mIsMenuChanging;                       ///< _98, whether there is a pending "on enter" callback to trigger.
	bool mHasNewFocus;                          ///< _99, whether the current selection has been changed (by user or by force).
	Font* mFont;                                ///< _9C, font to use when rendering item labels.
	int mCurrentItemDisplayIndex;               ///< _A0, index of item currently in focus/highlighted.
	int mConfirmKeys;                           ///< _A4, button inputs to treat as "confirming" (A and START by default).
	int mLabelAlignmentType;                    ///< _A8, horizontal alignment of item labels - see `LabelAlignmentType` enum.
	int mState;                                 ///< _AC, display state of menu - see `MenuStateType` enum.
	f32 mFadeTimer;                             ///< _B0, timer used to control fade in and out (0:faded out, 1:faded in).
};

#endif
