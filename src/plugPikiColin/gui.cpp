#include "Menu.h"

#include "DebugLog.h"
#include "Font.h"
#include "Geometry.h"
#include "Graphics.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/printf.h"
#include "sysNew.h"

/// Total height to allow for each menu item, including padding, in pixels.
#define MENU_ITEM_HEIGHT (14)

/**
 * @note UNUSED Size: 000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr);

/**
 * @brief Constructs a new debug menu.
 *
 * @param controller Active player controller.
 * @param font Font to use when rendering the menu.
 * @param alignToParentItem Whether to align this menu's vertical position to its parent item's position. Default is `false`, and is never
 * changed from default.
 */
Menu::Menu(Controller* controller, Font* font, bool alignToParentItem)
{
	mController        = controller;
	mAlignToParentItem = alignToParentItem;
	mFont              = font;

	mParentMenu         = nullptr;
	mLabelAlignmentType = Menu::LabelAlignmentType::Centered;

	// set up blank item/option list
	mItemListHead        = new MenuItem(MenuItemType::EmptyHead, 0, "menu", nullptr);
	mItemListHead->mPrev = mItemListHead->mNext = mItemListHead;

	mMenuItemCount = 0;
	_38            = 0; // unused
	mCurrentItem   = nullptr;
	mLastAddedItem = nullptr;

	// default center point of menu box is 25% of screen size away from top left (640/4, 480/4).
	mCenterPoint.set(160, 120, 0, 0);
	_78.set(6, 12, 6, 12); // unused

	// set background gradient colours
	mGradBGTopColour.set(MENU_COLOUR_PURPLE);          // soft purple, 75% opacity
	mGradBGBottomColour.set(MENU_COLOUR_DEFAULT_GREY); // light grey, 25% opacity

	// starts at middle colour and gets darker first
	mSelectedLabelPulsePhase = PI;

	_5C = 0; // unused

	// reset all callbacks
	mOnExitCallBack         = nullptr;
	mOnEnterCallBack        = nullptr;
	mOnOptionChangeCallback = nullptr;

	// entering menu for the first time will trigger "change" callbacks
	mIsMenuChanging = true;
	mHasNewFocus    = true;
	mConfirmKeys    = KBBTN_START | KBBTN_A;
	mState          = MenuStateType::Idle;
	mFadeTimer      = 0.0f;
	mPendingMenu    = nullptr;
}

/**
 * @brief Inserts a given event into the caller's doubly-linked event list, after the caller event.
 *
 * @param event Event to add to the list.
 * @note UNUSED Size: 00001C
 */
void Menu::KeyEvent::insertAfter(Menu::KeyEvent* event)
{
	event->mNext = mNext;
	event->mPrev = this;

	mNext->mPrev = event;
	mNext        = event;
}

/**
 * @brief Removes the current event from its doubly-linked event list.
 * @note UNUSED Size: 00001C
 */
void Menu::KeyEvent::remove()
{
	mNext->mPrev = mPrev;
	mPrev->mNext = mNext;
}

/**
 * @brief Inserts a given item into the caller's doubly-linked item list, after the caller item.
 *
 * @param item Item to add to the list.
 * @note UNUSED Size: 00001C
 */
void Menu::MenuItem::insertAfter(Menu::MenuItem* item)
{
	item->mNext = mNext;
	item->mPrev = this;

	mNext->mPrev = item;
	mNext        = item;
}

/**
 * @brief Removes the current item from its doubly-linked item list.
 * @note UNUSED Size: 00001C
 */
void Menu::MenuItem::remove()
{
	mNext->mPrev = mPrev;
	mPrev->mNext = mNext;
}

/**
 * @brief Constructs a new event that triggers a callback based on button inputs.
 *
 * @param eventType Type of event to trigger - see `KeyEventType` enum.
 * @param triggerKeys Buttons that will trigger the event - see `KeyboardButtons` enum.
 * @param callback Wrapped callback to make when event is triggered.
 * @note UNUSED Size: 00001C
 */
Menu::KeyEvent::KeyEvent(int eventType, int triggerKeys, IDelegate1<Menu&>* callback)
{
	mEventType     = (KeyEventType::Type)eventType;
	mTriggerKeys   = triggerKeys;
	mEventCallback = callback;

	mPrev = mNext = nullptr;
}

/**
 * @brief Constructs a new menu item/option with a blank event list.
 *
 * @param itemType Type of option - see `MenuItemType` enum.
 * @param data Data payload to attach to item - casted to int, but actual type is understood based on usage.
 * @param label Label to display for this menu option.
 * @param confirmCallback Unused (but passed as this when an option is added).
 */
Menu::MenuItem::MenuItem(int itemType, int data, char* label, IDelegate1<Menu&>* confirmCallback)
{
	mIsEnabled = true;
	mLabel     = label;

	mData = data;
	mType = (MenuItemType::Type)itemType;

	mPrev = mNext = nullptr;
	_08           = 0; // unused
	mSubMenu      = nullptr;

	// set up blank event list, ready for events to be added
	mEventListHead        = new KeyEvent(KeyEventType::EmptyHead, KBBTN_NONE, nullptr);
	mEventListHead->mNext = mEventListHead->mPrev = mEventListHead;
}

/**
 * @brief Sets callback for when menu is opened (either from gameplay or another menu).
 *
 * @param callback Wrapped callback to trigger.
 * @note UNUSED Size: 000008
 */
void Menu::setOnEnter(IDelegate1<Menu&>* callback)
{
	mOnEnterCallBack = callback;
}

/**
 * @brief Sets callback for when menu is closed (either to gameplay or another menu).
 *
 * @param callback Wrapped callback to trigger.
 * @note UNUSED Size: 000008
 */
void Menu::setOnExit(IDelegate1<Menu&>* callback)
{
	mOnExitCallBack = callback;
}

/**
 * @brief Adds a new event to the most recently added item's event list.
 *
 * If there is no most recently added item, it will add to the list head's event list.
 * (The list head's event list will be checked if no halting (confirm/cancel/input release) event is found for the current item).
 *
 * @param eventType Type of event to add - see `KeyEventType` enum.
 * @param triggerKeys Button inputs to trigger the event - see `KeyboardButtons` enum.
 * @param callback Wrapped callback to trigger on event.
 */
void Menu::addKeyEvent(int eventType, int triggerKeys, IDelegate1<Menu&>* callback)
{
	KeyEvent* event = new KeyEvent(eventType, triggerKeys, callback);

	if (mLastAddedItem) {
		mLastAddedItem->mEventListHead->mPrev->insertAfter(event);

	} else {
		mItemListHead->mEventListHead->mPrev->insertAfter(event);
	}
}

/**
 * @brief Does nothing.
 *
 * @return Pointer to this menu.
 */
Menu* Menu::enterOption()
{
	return this;
}

/**
 * @brief Opens the given menu.
 *
 * @param menu Menu to open.
 * @return Pointer to menu that was opened.
 */
Menu* Menu::enterMenu(Menu* menu)
{
	Menu* ret = menu;
	if (ret) {
		ret->open(false);
	}
	// return input menu for chaining
	return ret;
}

/**
 * @brief Closes the given menu.
 *
 * @param menu Menu to close.
 * @return Pointer to menu that was closed.
 */
Menu* Menu::exitMenu(Menu* menu)
{
	Menu* ret = menu;
	if (ret) {
		ret->close();
	}
	// return input menu for chaining
	return ret;
}

/**
 * @brief Sets menu into fade-in state, to start opening.
 */
void Menu::open(bool)
{
	mFadeTimer = 0.0;
	mState     = MenuStateType::FadeIn;

	// if no selected item, select the top one
	if (!mCurrentItem) {
		mCurrentItem = mItemListHead->mNext;
	}
}

/**
 * @brief Sets menu into fade-out state, to start closing.
 */
void Menu::close()
{
	if (!mParentMenu) {
		// this... will always set mReturnMenu to nullptr (but is required to match)
		mReturnMenu = mParentMenu;
	}

	mFadeTimer = 1.0f;
	mState     = MenuStateType::FadeOut;
}

/**
 * @brief Resets item list and count.
 *
 * @bug Does not delete the old items from the list, just orphans them in memory. Probably causes memory leaks over time.
 */
void Menu::resetOptions()
{
	mMenuItemCount       = 0;
	mCurrentItem         = nullptr;
	mItemListHead->mPrev = mItemListHead->mNext = mItemListHead;
}

/**
 * @brief Adds a new item/option to (the end of) the menu.
 *
 * @param data Data payload to attach to the menu item. This is not always an int (!!), but is casted to one for passing for some reason.
 * @param label Label to display for the menu item. No label will create a blank entry.
 * @param confirmCallback Delegate/callback to trigger when option is "confirmed" (A or START).
 * @param isEnabled Whether to enable the menu item as selectable. Default is `true` (never supplied as `false`).
 */
void Menu::addOption(int data, char* label, IDelegate1<Menu&>* confirmCallback, bool isEnabled)
{
	// set up new item
	mLastAddedItem             = new MenuItem(MenuItemType::Option, data, label, confirmCallback);
	mLastAddedItem->mIsEnabled = isEnabled;
	mItemListHead->mPrev->insertAfter(mLastAddedItem);

	// set up confirm callback event
	if (confirmCallback) {
		addKeyEvent(KeyEventType::OnConfirm, mConfirmKeys, confirmCallback);
	}

	// if we have no item selected, select the new item
	if (!mCurrentItem && mLastAddedItem->mIsEnabled) {
		mCurrentItem = mLastAddedItem;
	}

	mMenuItemCount++;
}

/**
 * @brief Adds a submenu item to the list. Will open the given submenu on "confirming" this option.
 *
 * @param subMenu Submenu to open when confirming this option.
 * @param data Data payload to attach to the item.
 * @param label Text label to render for this option.
 */
void Menu::addMenu(Menu* subMenu, int data, char* label)
{
	// add new item to list, and set up correct menu structure
	mLastAddedItem           = new MenuItem(MenuItemType::SubMenu, data, label, nullptr);
	mLastAddedItem->mSubMenu = subMenu;
	subMenu->mParentMenu     = this;
	mItemListHead->mPrev->insertAfter(mLastAddedItem);

	// add no-callback confirm entry, to trigger menu change
	addKeyEvent(KeyEventType::OnConfirm, mConfirmKeys, nullptr);

	// if we have no item selected, select the new item
	if (!mCurrentItem) {
		mCurrentItem = mLastAddedItem;
	}

	mMenuItemCount++;
}

/**
 * @brief Handles up/down navigation through the option list. Controls are only with the control stick or cstick (no dpad).
 *
 * Will trigger any OnFocusLost events for the current menu option if moving, and queues up the next menu item to be handled next doUpdate.
 *
 * @return Always `false`.
 */
bool Menu::checkNewOption()
{
	// if down is pressed
	if (mController->keyUnClick(KBBTN_CSTICK_DOWN) || mController->keyUnClick(KBBTN_MSTICK_DOWN)) {
		mCurrentItem->checkEvents(this, KeyEventType::OnFocusLost);

		// Move to the next menu item
		mCurrentItem = mCurrentItem->mNext;

		// If we're at the end of the list, go back to the start
		if (mCurrentItem == mItemListHead) {
			mCurrentItem = mCurrentItem->mNext;
		}

		// Skip over any items that don't have a name or are disabled
		while (!mCurrentItem->mLabel || !mCurrentItem->mIsEnabled) {
			mCurrentItem = mCurrentItem->mNext;
			if (mCurrentItem == mItemListHead) {
				mCurrentItem = mCurrentItem->mNext;
			}
		}

		mHasNewFocus = true;

	} else if (mController->keyUnClick(KBBTN_CSTICK_UP) || mController->keyUnClick(KBBTN_MSTICK_UP)) {
		mCurrentItem->checkEvents(this, KeyEventType::OnFocusLost);

		// Move to the previous menu item (go up)
		mCurrentItem = mCurrentItem->mPrev;

		// If we're at the start of the list, go to the end
		if (mCurrentItem == mItemListHead) {
			mCurrentItem = mCurrentItem->mPrev;
		}

		// Skip over any items that don't have a name or are disabled
		while (!mCurrentItem->mLabel || !mCurrentItem->mIsEnabled) {
			mCurrentItem = mCurrentItem->mPrev;
			if (mCurrentItem == mItemListHead) {
				mCurrentItem = mCurrentItem->mPrev;
			}
		}

		mHasNewFocus = true;
	}

	return false;
}

/**
 * @brief Checks if the "select" (A) button has been pressed.
 *
 * @return `true` if pressed, `false` otherwise.
 */
bool Menu::checkSelectKey()
{
	return mController->keyClick(KBBTN_A) != false;
}

/**
 * @brief Checks if the "cancel" (B) button has been pressed.
 *
 * @return `true` if pressed, `false` otherwise.
 */
bool Menu::checkCancelKey()
{
	return mController->keyClick(KBBTN_B) != false;
}

/**
 * @brief Updates the menu for this frame, handling state transitions, inputs, and menu switching.
 *
 * @param selectItem Whether to mark the current item as newly focused, triggering any OnFocusGained callbacks.
 * @return Pointer to the active menu for the next frame (either `this`, a submenu, a parent menu, or `nullptr`).
 */
Menu* Menu::doUpdate(bool selectItem)
{
	STACK_PAD_VAR(2);

	Menu* activeMenu = this;
	mReturnMenu      = this;

	// pulse current item's label colour
	mSelectedLabelPulsePhase += 7.0f * gsys->getFrameTime();

	switch (mState) {
	case MenuStateType::FadeIn:
	{
		mFadeTimer += 8.0f * gsys->getFrameTime();
		if (mFadeTimer >= 1.0f) {
			mFadeTimer = 1.0f;
			mState     = MenuStateType::Open;
		}
		break;
	}
	case MenuStateType::FadeOut:
	{
		mFadeTimer -= 8.0f * gsys->getFrameTime();
		if (mFadeTimer < 0.0f) {
			mFadeTimer = 0.0f;
			mState     = MenuStateType::Idle;
			activeMenu = mPendingMenu;
		}
		break;
	}
	case MenuStateType::Open:
	{
		if (selectItem) {
			mHasNewFocus = true;
		}

		checkNewOption();

		if (mIsMenuChanging) {
			if (mOnEnterCallBack) {
				mOnEnterCallBack->invoke(*this);
			}

			mIsMenuChanging = false;
			mHasNewFocus    = true;
		}

		// don't check focus-related events unless we have an item selected
		int eventMask = KeyEventType::ALL_EVENTS_MASK & ~(KeyEventType::OnFocusGained | KeyEventType::OnFocusLost);

		// only trigger OnFocusGained once
		if (mHasNewFocus) {
			eventMask |= KeyEventType::OnFocusGained;
			if (mOnOptionChangeCallback) {
				mOnOptionChangeCallback->invoke(*this);
			}

			mSelectedLabelPulsePhase = 0.0f;
			mHasNewFocus             = false;
		}

		// check events for currently selected item. if no halting (confirm/cancel/input release) events, check list head's events as well
		if (!mCurrentItem->checkEvents(this, eventMask)) {
			mItemListHead->checkEvents(this, eventMask);
		}

		// if we're cancelling back to another menu, check OnFocusLost events as well
		if (mReturnMenu != this) {
			mCurrentItem->checkEvents(this, KeyEventType::OnFocusLost);
			if (mOnExitCallBack) {
				mOnExitCallBack->invoke(*this);
			}

			// activate new menu
			if (mReturnMenu) {
				mReturnMenu->open(false);
				activeMenu = mReturnMenu;
			} else {
				// the "menu" we're returning to is `nullptr`, i.e. exiting out of menu altogether
				close();
			}

			mPendingMenu = mReturnMenu;
		}
		break;
	}
	}

	return activeMenu;
}

/**
 * @brief Checks for any queued events to trigger, based on the given event type mask.
 *
 * @param parentMenu Parent debug menu.
 * @param eventMask Mask of event flag types to check.
 * @return `true` if an event was handled that should stop further processing (confirm, cancel, input release); `false` for submenu
 * confirming and otherwise.
 */
bool Menu::MenuItem::checkEvents(Menu* parentMenu, int eventMask)
{
	KeyEvent* event = mEventListHead->mNext;
	for (event; event != mEventListHead; event = event->mNext) {
		// If the event type doesn't match the mask, skip it
		if (!(eventMask & event->mEventType)) {
			continue;
		}

		switch (event->mEventType) {
		case KeyEventType::OnFocusGained:
		{
			// when item is freshly highlighted - triggered once
			event->mEventCallback->invoke(*parentMenu);
			break;
		}
		case KeyEventType::OnFocusLost:
		{
			// when item stops being highlighted - triggered once
			event->mEventCallback->invoke(*parentMenu);
			break;
		}
		case KeyEventType::WhileInputHeld:
		{
			// when trigger input is held down - triggered every frame
			if (parentMenu->mController->keyDown(event->mTriggerKeys)) {
				event->mEventCallback->invoke(*parentMenu);
			}
			break;
		}
		case KeyEventType::OnInputRelease:
		case KeyEventType::OnCancel:
		{
			// when releasing an input that will cause a gameplay or data change OR
			// when hitting the cancel (B) button - triggered once, and will halt further event processing
			if (parentMenu->mController->keyUnClick(event->mTriggerKeys)) {
				event->mEventCallback->invoke(*parentMenu);
				return true;
			}
			break;
		}
		case KeyEventType::OnConfirm:
		{
			// when hitting the confirm (A) button - triggered once, and will halt further event processing
			if (parentMenu->mController->keyUnClick(event->mTriggerKeys)) {
				// if the current item is a submenu, open it
				if (parentMenu->mCurrentItem->mType == MenuItemType::SubMenu) {
					checkEvents(parentMenu, KeyEventType::OnFocusLost);

					// close the current menu and open the next one
					parentMenu->close();
					parentMenu->mReturnMenu  = parentMenu;
					parentMenu->mPendingMenu = parentMenu->mCurrentItem->mSubMenu;
					parentMenu->mPendingMenu->open(false);

					// if the new menu is meant to have a pop-out effect aligned with this item, calculate that
					if (parentMenu->mPendingMenu->mAlignToParentItem) {
						const int kMenuItemHeight = MENU_ITEM_HEIGHT;

						// align submenu center with middle of currently selected item
						parentMenu->mPendingMenu->mCenterPoint.mMinY = parentMenu->mCenterPoint.mMinY
						                                             - (parentMenu->mMenuItemCount * kMenuItemHeight) / 2
						                                             + parentMenu->mCurrentItemDisplayIndex * kMenuItemHeight;
					}

					parentMenu->mIsMenuChanging                         = true;
					parentMenu->mCurrentItem->mSubMenu->mIsMenuChanging = true;
					return false;
				}

				event->mEventCallback->invoke(*parentMenu);
				return true;
			}
			break;
		}
		}
	}

	return false;
}

/**
 * @brief Renders the menu for this frame, handling highlighting, dynamic menu height, and fading.
 *
 * @param gfx Graphics context for rendering.
 * @param fadeFactor Factor to apply to the alpha of this menu, from 0 to 1 (0=completely faded out, 1=no fading).
 */
void Menu::draw(Graphics& gfx, f32 fadeFactor)
{
	// calc where the top of the menu should be, based on the item count
	int topY = mCenterPoint.mMinY - (MENU_ITEM_HEIGHT * mMenuItemCount / 2);

	// determine what half the maximum string width for the menu items is, so we know how wide to make the selection boxes
	int maxStrHalfWidth = 0;
	MenuItem* currentItem;
	for (currentItem = mItemListHead->mNext; currentItem != mItemListHead; currentItem = currentItem->mNext) {
		if (currentItem->mLabel) {
			int strHalfWidth = mFont->stringWidth(currentItem->mLabel) / 2;
			if (strHalfWidth > maxStrHalfWidth) {
				maxStrHalfWidth = strHalfWidth;
			}
		}
	}

	// padding
	maxStrHalfWidth += 8;

	// Set up initial box dimensions based on the maximum string width
	int centerX    = mCenterPoint.mMinX;
	int centerY    = 3 + topY + (MENU_ITEM_HEIGHT / 2) * mMenuItemCount; // add 3 units of padding to the very top of the menu
	int halfWidth  = maxStrHalfWidth + 8;                                // add padding to the sides of the menu
	int halfHeight = (MENU_ITEM_HEIGHT / 2) * mMenuItemCount + MENU_ITEM_HEIGHT;

	// handle fade progress
	f32 menuBoxAlphaFactor = mFadeTimer;

	// check for if the menu is fully open and no longer fading
	bool isFullDisplay = true;

	if (mFadeTimer != 1.0f) {
		// we're fading in or out (or completely faded out)

		if (mPendingMenu && mPendingMenu->mAlignToParentItem) {
			// do pop-out submenu effect by half-fading background menu rather than hiding it
			menuBoxAlphaFactor = 0.5f * mFadeTimer + 0.5f;

		} else {
			if (mFadeTimer != 1.0f) {
				isFullDisplay = false;
			}
			// adjust label widths to grow/shrink on fade in/out
			halfWidth *= mFadeTimer;
			halfHeight *= mFadeTimer;
		}
	}

	// apply fade percentage multiplier (only non-1 for parents of pop-out submenus)
	menuBoxAlphaFactor *= fadeFactor;

	// draw menu background (with gradient)
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(mGradBGTopColour.r, mGradBGTopColour.g, mGradBGTopColour.b, mGradBGTopColour.a * menuBoxAlphaFactor), true);
	gfx.setAuxColour(
	    Colour(mGradBGBottomColour.r, mGradBGBottomColour.g, mGradBGBottomColour.b, mGradBGBottomColour.a * menuBoxAlphaFactor));
	gfx.fillRectangle(RectArea(centerX - halfWidth, centerY - halfHeight, centerX + halfWidth, centerY + halfHeight));

	// draw menu box outline
	gfx.setColour(Colour(64, 64, 192, 255.0f * menuBoxAlphaFactor), true);
	gfx.setAuxColour(Colour(64, 64, 192, 255.0f * menuBoxAlphaFactor));
	gfx.lineRectangle(RectArea(centerX - halfWidth, centerY - halfHeight, centerX + halfWidth, centerY + halfHeight));

	// iterate through the menu items/options and draw each one's label
	if (isFullDisplay) {
		f32 labelAlpha = mGradBGTopColour.a * fadeFactor;
		MenuItem* item = mItemListHead->mNext;

		mCurrentItemDisplayIndex = 0; // check selected index to know what to highlight/put a box around
		for (int i = 0; i < mMenuItemCount; i++) {
			// item has to have a label to display it
			if (item->mLabel) {
				// determine the color for the label
				if (item == mCurrentItem) {
					// highlighted/focused items get a different colour
					if (mState == MenuStateType::Idle) {
						// this is for if a menu is open behind another menu (unused pop-out submenus)
						gfx.setColour(Colour(192, 192, 0, (int)labelAlpha), true);
					} else {
						mCurrentItemDisplayIndex = i;
						// this goes from 64 (dark grey) to 192 (light grey)
						int greyRGB = int((sinf(mSelectedLabelPulsePhase) + 1.0f) * 64.0f) + 64;
						gfx.setColour(Colour(greyRGB, greyRGB, greyRGB, (int)labelAlpha), true);
					}
				} else if (!item->mIsEnabled) {
					// light yellow for unselectable items
					gfx.setColour(Colour(255, 255, 128, (int)labelAlpha), true);
				} else {
					// dark gold for everything else
					gfx.setColour(Colour(128, 128, 64, (int)labelAlpha), true);
				}

				// prepare and draw the label
				char label[PATH_MAX];
				sprintf(label, "%s", item->mLabel);

				int labelWidth = mFont->stringWidth(label);
				gfx.texturePrintf(
				    mFont, (mLabelAlignmentType == LabelAlignmentType::Centered) ? (centerX - labelWidth / 2) : (centerX - maxStrHalfWidth),
				    MENU_ITEM_HEIGHT * i + topY, label);
			}

			// move to the next menu item and adjust vertical position
			item = item->mNext;
		}

		// highlight the currently selected item with a rectangle
		int currItemTopY = topY + MENU_ITEM_HEIGHT * mCurrentItemDisplayIndex + 1;
		gfx.setColour(Colour(128, 128, 128, 128), true); // light grey
		gfx.setAuxColour(Colour(192, 192, 192, 128));    // even lighter grey
		gfx.useTexture(nullptr, GX_TEXMAP0);
		gfx.lineRectangle(RectArea(centerX - maxStrHalfWidth + 4, currItemTopY, mCenterPoint.mMinX + maxStrHalfWidth - 4,
		                           currItemTopY + MENU_ITEM_HEIGHT));
	}
}

/**
 * @brief Callback to close the given menu, and open any pending/queued menu.
 *
 * @param menu Menu to close.
 */
void Menu::menuCloseMenu(Menu& menu)
{
	menu.mPendingMenu = menu.mParentMenu;
	menu.close();
	if (menu.mPendingMenu) {
		menu.mPendingMenu->open(false);
	}
}
