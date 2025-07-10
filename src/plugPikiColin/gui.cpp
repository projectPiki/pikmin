#include "DebugLog.h"
#include "Font.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Menu.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/printf.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	8005D6F8
 * Size:	0001C8
 */
Menu::Menu(Controller* controller, Font* font, bool useCustomPosition)
{
	mController        = controller;
	mUseCustomPosition = useCustomPosition;

	mFont         = font;
	mParentMenu   = 0;
	mIsCustomMenu = FALSE;
	mLastItem     = new MenuItem(MenuNavigationType::Unk0, 0, "menu", nullptr);

	mLastItem->mPrev = mLastItem->mNext = mLastItem;

	mMenuCount   = 0;
	_38          = 0;
	mCurrentItem = nullptr;
	mFirstItem   = nullptr;

	mAnchorPoint.set(160, 120, 0, 0);
	mDefaultMargin.set(6, 12, 6, 12);

	mDiffuseColour.set(32, 32, 128, 192);
	mHighlightColour.set(32, 32, 32, 64);

	mAnimationProgress = PI;

	_5C                     = 0;
	mOnExitCallBack         = nullptr;
	mOnEnterCallBack        = nullptr;
	mOnOptionChangeCallback = nullptr;
	mIsMenuChanging         = true;
	mIsOptionSelected       = true;
	mInputCode              = KBBTN_START | KBBTN_A;
	mState                  = MenuStateType::Idle;
	mOpeningFadeProgress    = 0.0f;
	mNextMenu               = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::KeyEvent::insertAfter(Menu::KeyEvent* key)
{
	key->mNext = mNext;
	key->mPrev = this;

	mNext->mPrev = key;
	mNext        = key;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::KeyEvent::remove()
{
	mNext->mPrev = mPrev;
	mPrev->mNext = mNext;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::MenuItem::insertAfter(Menu::MenuItem* item)
{
	item->mNext = mNext;
	item->mPrev = this;

	mNext->mPrev = item;
	mNext        = item;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::MenuItem::remove()
{
	mNext->mPrev = mPrev;
	mPrev->mNext = mNext;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
Menu::KeyEvent::KeyEvent(int eventType, int inputCode, IDelegate1<Menu&>* delegate)
{
	mEventType = (KeyEventType::Type)eventType;
	mInputCode = inputCode;
	mDelegate  = delegate;

	mPrev = mNext = nullptr;
}

/*
 * --INFO--
 * Address:	8005D8C0
 * Size:	000094
 */
Menu::MenuItem::MenuItem(int type, int filterIndex, char* name, IDelegate1<Menu&>* delegate)
{
	mIsEnabled = true;
	mName      = name;

	mFilterIndex = filterIndex;
	mType        = (MenuNavigationType::Type)type;

	mPrev = mNext = nullptr;
	_08           = 0;
	mMenu         = nullptr;

	mEventList        = new KeyEvent(KeyEventType::Null, 0, nullptr);
	mEventList->mNext = mEventList->mPrev = mEventList;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Menu::setOnEnter(IDelegate1<Menu&>* callback)
{
	mOnEnterCallBack = callback;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Menu::setOnExit(IDelegate1<Menu&>* callback)
{
	mOnExitCallBack = callback;
}

/*
 * --INFO--
 * Address:	8005D954
 * Size:	0000C8
 */
void Menu::addKeyEvent(int eventCode, int inputCode, IDelegate1<Menu&>* delegate)
{
	KeyEvent* key = new KeyEvent(eventCode, inputCode, delegate);

	if (mFirstItem) {
		mFirstItem->mEventList->mPrev->insertAfter(key);

	} else {
		mLastItem->mEventList->mPrev->insertAfter(key);
	}
}

/*
 * --INFO--
 * Address:	8005DA1C
 * Size:	000004
 */
Menu* Menu::enterOption()
{
	return this;
}

/*
 * --INFO--
 * Address:	8005DA20
 * Size:	000048
 */
Menu* Menu::enterMenu(Menu* menu)
{
	Menu* ret = menu; // yes this is necessary
	if (ret) {
		ret->open(false);
	}
	return ret;
}

/*
 * --INFO--
 * Address:	8005DA68
 * Size:	000044
 */
Menu* Menu::exitMenu(Menu* menu)
{
	Menu* ret = menu;
	if (ret) {
		ret->close();
	}
	return ret;
}

/*
 * --INFO--
 * Address:	8005DAAC
 * Size:	00002C
 */
void Menu::open(bool p1)
{
	mOpeningFadeProgress = 0.0;
	mState               = MenuStateType::FadeIn;
	if (!mCurrentItem) {
		mCurrentItem = mLastItem->mNext;
	}
}

/*
 * --INFO--
 * Address:	8005DAD8
 * Size:	000024
 */
void Menu::close()
{
	if (!mParentMenu) { // sure.
		mPreviousMenu = mParentMenu;
	}
	mOpeningFadeProgress = 1.0f;
	mState               = MenuStateType::FadeOut;
}

/*
 * --INFO--
 * Address:	8005DAFC
 * Size:	000020
 */
void Menu::resetOptions()
{
	mMenuCount       = 0;
	mCurrentItem     = nullptr;
	mLastItem->mPrev = mLastItem->mNext = mLastItem;
}

/*
 * --INFO--
 * Address:	8005DB1C
 * Size:	000194
 */
void Menu::addOption(int p1, char* name, IDelegate1<Menu&>* delegate, bool p4)
{
	mFirstItem             = new MenuItem(MenuNavigationType::TopMenu, p1, name, delegate);
	mFirstItem->mIsEnabled = p4;
	mLastItem->mPrev->insertAfter(mFirstItem);
	if (delegate) {
		addKeyEvent(KeyEventType::Navigate, mInputCode, delegate);
	}

	if (!mCurrentItem && mFirstItem->mIsEnabled) {
		mCurrentItem = mFirstItem;
	}

	mMenuCount++;
}

/*
 * --INFO--
 * Address:	8005DCB0
 * Size:	000184
 */
void Menu::addMenu(Menu* menu, int p2, char* name)
{
	mFirstItem        = new MenuItem(MenuNavigationType::SubMenu, p2, name, nullptr);
	mFirstItem->mMenu = menu;
	menu->mParentMenu = this;
	mLastItem->mPrev->insertAfter(mFirstItem);

	addKeyEvent(KeyEventType::Navigate, mInputCode, nullptr);

	if (!mCurrentItem) {
		mCurrentItem = mFirstItem;
	}

	mMenuCount++;
}

/*
 * --INFO--
 * Address:	8005DE34
 * Size:	000150
 */
bool Menu::checkNewOption()
{
	// If down is pressed
	if (mController->keyUnClick(KBBTN_CSTICK_DOWN) || mController->keyUnClick(KBBTN_MSTICK_DOWN)) {
		mCurrentItem->checkEvents(this, KeyEventType::Hold);

		// Move to the next menu item
		mCurrentItem = mCurrentItem->mNext;

		// If we're at the end of the list, go back to the start
		if (mCurrentItem == mLastItem) {
			mCurrentItem = mCurrentItem->mNext;
		}

		// Skip over any items that don't have a name or are disabled
		while (!mCurrentItem->mName || !mCurrentItem->mIsEnabled) {
			mCurrentItem = mCurrentItem->mNext;
			if (mCurrentItem == mLastItem) {
				mCurrentItem = mCurrentItem->mNext;
			}
		}

		mIsOptionSelected = true;

	} else if (mController->keyUnClick(KBBTN_CSTICK_UP) || mController->keyUnClick(KBBTN_MSTICK_UP)) {
		mCurrentItem->checkEvents(this, KeyEventType::Hold);

		// Move to the previous menu item (go up)
		mCurrentItem = mCurrentItem->mPrev;

		// If we're at the start of the list, go to the end
		if (mCurrentItem == mLastItem) {
			mCurrentItem = mCurrentItem->mPrev;
		}

		// Skip over any items that don't have a name or are disabled
		while (!mCurrentItem->mName || !mCurrentItem->mIsEnabled) {
			mCurrentItem = mCurrentItem->mPrev;
			if (mCurrentItem == mLastItem) {
				mCurrentItem = mCurrentItem->mPrev;
			}
		}

		mIsOptionSelected = true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8005DF84
 * Size:	00001C
 */
bool Menu::checkSelectKey()
{
	return mController->keyClick(KBBTN_A) != false;
}

/*
 * --INFO--
 * Address:	8005DFA0
 * Size:	00001C
 */
bool Menu::checkCancelKey()
{
	return mController->keyClick(KBBTN_B) != false;
}

/*
 * --INFO--
 * Address:	8005DFBC
 * Size:	000258
 */
Menu* Menu::doUpdate(bool selectItem)
{
	STACK_PAD_VAR(2);

	Menu* resultMenu = this;
	mPreviousMenu    = this;
	mAnimationProgress += 7.0f * gsys->getFrameTime();

	switch (mState) {
	case MenuStateType::FadeIn:
		mOpeningFadeProgress += 8.0f * gsys->getFrameTime();
		if (mOpeningFadeProgress >= 1.0f) {
			mOpeningFadeProgress = 1.0f;
			mState               = MenuStateType::Open;
		}
		break;
	case MenuStateType::FadeOut:
		mOpeningFadeProgress -= 8.0f * gsys->getFrameTime();
		if (mOpeningFadeProgress < 0.0f) {
			mOpeningFadeProgress = 0.0f;
			mState               = MenuStateType::Idle;
			resultMenu           = mNextMenu;
		}
		break;
	case MenuStateType::Open:
		if (selectItem) {
			mIsOptionSelected = true;
		}

		checkNewOption();

		if (mIsMenuChanging) {
			if (mOnEnterCallBack) {
				mOnEnterCallBack->invoke(*this);
			}

			mIsMenuChanging   = false;
			mIsOptionSelected = true;
		}

		int flag = 0xFFFC;
		if (mIsOptionSelected) {
			flag |= 0x1;
			if (mOnOptionChangeCallback) {
				mOnOptionChangeCallback->invoke(*this);
			}

			mAnimationProgress = 0.0f;
			mIsOptionSelected  = false;
		}

		if (!mCurrentItem->checkEvents(this, flag)) {
			mLastItem->checkEvents(this, flag);
		}

		if (mPreviousMenu != this) {
			mCurrentItem->checkEvents(this, KeyEventType::Hold);
			if (mOnExitCallBack) {
				mOnExitCallBack->invoke(*this);
			}

			if (mPreviousMenu) {
				mPreviousMenu->open(false);
				resultMenu = mPreviousMenu;
			} else {
				close();
			}

			mNextMenu = mPreviousMenu;
		}
		break;
	}

	return resultMenu;
}

/*
 * --INFO--
 * Address:	8005E214
 * Size:	0001FC
 */
bool Menu::MenuItem::checkEvents(Menu* menu, int events)
{
	KeyEvent* event = mEventList->mNext;
	for (event; event != mEventList; event = event->mNext) {
		// If the event type doesn't match the flags, skip it
		if (!(events & event->mEventType)) {
			continue;
		}

		switch (event->mEventType) {
		case KeyEventType::Press:
			event->mDelegate->invoke(*menu);
			break;
		case KeyEventType::Hold:
			event->mDelegate->invoke(*menu);
			break;
		case KeyEventType::Input:
			if (menu->mController->keyDown(event->mInputCode)) {
				event->mDelegate->invoke(*menu);
			}
			break;
		case KeyEventType::Release:
		case KeyEventType::SpecialRelease:
			if (menu->mController->keyUnClick(event->mInputCode)) {
				event->mDelegate->invoke(*menu);
				return true;
			}
			break;
		case KeyEventType::Navigate:
			if (menu->mController->keyUnClick(event->mInputCode)) {
				// If the current item is a submenu, open it
				if (menu->mCurrentItem->mType == MenuNavigationType::SubMenu) {
					checkEvents(menu, KeyEventType::Hold);

					// Close the current menu and open the next one
					menu->close();
					menu->mPreviousMenu = menu;
					menu->mNextMenu     = menu->mCurrentItem->mMenu;
					menu->mNextMenu->open(false);

					// If the next menu has a custom position, set it
					if (menu->mNextMenu->mUseCustomPosition) {
						const int kMenuItemHeight = 14;

						menu->mNextMenu->mAnchorPoint.mMinY = menu->mAnchorPoint.mMinY - (menu->mMenuCount * kMenuItemHeight) / 2
						                                    + menu->mCurrentItemDisplayIndex * kMenuItemHeight;
					}

					menu->mIsMenuChanging                      = true;
					menu->mCurrentItem->mMenu->mIsMenuChanging = true;
					return false;
				}

				event->mDelegate->invoke(*menu);
				return true;
			}
			break;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	8005E410
 * Size:	00060C
 */
void Menu::draw(Graphics& gfx, f32 fadePct)
{
	// Determine the maximum string width for the menu items
	int baseYPosition  = mAnchorPoint.mMinY - (14 * mMenuCount / 2);
	int maxStringWidth = 0;

	MenuItem* currentItem;
	for (currentItem = mLastItem->mNext; currentItem != mLastItem; currentItem = currentItem->mNext) {
		if (currentItem->mName) {
			int stringWidth = mFont->stringWidth(currentItem->mName) / 2;
			if (stringWidth > maxStringWidth) {
				maxStringWidth = stringWidth;
			}
		}
	}

	maxStringWidth += 8;

	// Set up initial box dimensions based on the maximum string width
	int x  = mAnchorPoint.mMinX;
	int y  = 3 + baseYPosition + 7 * mMenuCount;
	int x2 = maxStringWidth + 8;
	int y2 = 7 * mMenuCount + 14;

	// Handle fade and animation progress
	f32 progress     = mOpeningFadeProgress;
	bool isAnimating = true;

	// If the menu is animating, adjust the progress
	if (mOpeningFadeProgress != 1.0f) {
		if (mNextMenu && mNextMenu->mUseCustomPosition) {
			progress = 0.5f * mOpeningFadeProgress + 0.5f;
		} else {
			if (mOpeningFadeProgress != 1.0f) {
				isAnimating = false;
			}
			x2 *= mOpeningFadeProgress;
			y2 *= mOpeningFadeProgress;
		}
	}

	// Apply fade percentage multiplier
	progress *= fadePct;

	// Use texture and set initial color for the menu box
	gfx.useTexture(nullptr, 0);
	gfx.setColour(Colour(mDiffuseColour.r, mDiffuseColour.g, mDiffuseColour.b, mDiffuseColour.a * progress), true);
	gfx.setAuxColour(Colour(mHighlightColour.r, mHighlightColour.g, mHighlightColour.b, mHighlightColour.a * progress));

	// Draw the background menu box
	gfx.fillRectangle(RectArea(x - x2, y - y2, x + x2, y + y2));

	gfx.setColour(Colour(64, 64, 192, 255.0f * progress), true);
	gfx.setAuxColour(Colour(64, 64, 192, 255.0f * progress));

	// Draw the background menu box
	gfx.lineRectangle(RectArea(x - x2, y - y2, x + x2, y + y2));

	// Iterate through the menu items and draw each one

	if (isAnimating) {
		f32 alpha      = mDiffuseColour.a * fadePct;
		MenuItem* item = mLastItem->mNext;

		mCurrentItemDisplayIndex = 0;
		for (int i = 0; i < mMenuCount; i++) {
			if (item->mName) {
				// Determine the color for the current menu item
				if (item == mCurrentItem) {
					if (mState == MenuStateType::Idle) {
						// fun fact: these int casts are necessary for codegen :')
						gfx.setColour(Colour(192, 192, 0, (int)alpha), true);
					} else {
						mCurrentItemDisplayIndex = i;
						int v                    = int((sinf(mAnimationProgress) + 1.0f) * 64.0f) + 64;
						gfx.setColour(Colour(v, v, v, (int)alpha), true);
					}
				} else if (!item->mIsEnabled) {
					gfx.setColour(Colour(255, 255, 128, (int)alpha), true);
				} else {
					gfx.setColour(Colour(128, 128, 64, (int)alpha), true);
				}

				// Prepare and draw the label
				char label[PATH_MAX];
				sprintf(label, "%s", item->mName);

				int labelWidth = mFont->stringWidth(label);
				gfx.texturePrintf(mFont, (!mIsCustomMenu) ? (x - labelWidth / 2) : (x - maxStringWidth), 14 * i + baseYPosition, label);
			}

			// Move to the next menu item and adjust vertical position
			item = item->mNext;
		}

		// Highlight the currently selected item with a rectangle
		int y3 = baseYPosition + 14 * mCurrentItemDisplayIndex + 1;
		gfx.setColour(Colour(128, 128, 128, 128), true);
		gfx.setAuxColour(Colour(192, 192, 192, 128));
		gfx.useTexture(nullptr, 0);
		gfx.lineRectangle(RectArea(x - maxStringWidth + 4, y3, mAnchorPoint.mMinX + maxStringWidth - 4, y3 + 14));
	}
}

/*
 * --INFO--
 * Address:	8005EA1C
 * Size:	000064
 */
void Menu::menuCloseMenu(Menu& menu)
{
	menu.mNextMenu = menu.mParentMenu;
	menu.close();
	if (menu.mNextMenu) {
		menu.mNextMenu->open(false);
	}
}
