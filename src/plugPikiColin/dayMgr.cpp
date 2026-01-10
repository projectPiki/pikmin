#include "DayMgr.h"

#include "Controller.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "Menu.h"
#include "NaviMgr.h"
#include "gameflow.h"
#include "sysNew.h"

//////////////////////////////////////////////////////
//////////////// PRINT/ERROR DEFINES /////////////////
//////////////////////////////////////////////////////
#pragma region DECLARATIONS

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000C8
 */
DEFINE_PRINT(nullptr)

#pragma endregion
//////////////////////////////////////////////////////
///////////// POSITION EDITOR DEBUG MENU /////////////
//////////////////////////////////////////////////////
#pragma region POSITION MENU

/**
 * @brief Debug menu for editing a `Vector3f` (position or direction) component-by-component.
 *
 * Could also be used for editing rotations, but never actually is - only used for light positions and directions.
 *
 * @note Size: 0xC4.
 */
struct PositionMenu : public Menu {

	/**
	 * @brief Decreases the focused component by set amount and updates its value.
	 * @param parent Parent debug menu.
	 */
	void menuDecrease(Menu& parent)
	{
		if (!mIsSmallAdjustment) {
			*mComponentValue -= 10.0f;
			updateComponent(parent, mComponentName, mComponentValue);
		} else {
			*mComponentValue -= 0.01f;
			updateComponent(parent, mComponentName, mComponentValue);
		}
	}

	/**
	 * @brief Increases the focused component by set amount and updates its value.
	 * @param parent Parent debug menu.
	 */
	void menuIncrease(Menu& parent)
	{
		if (!mIsSmallAdjustment) {
			*mComponentValue += 10.0f;
			updateComponent(parent, mComponentName, mComponentValue);
		} else {
			*mComponentValue += 0.01f;
			updateComponent(parent, mComponentName, mComponentValue);
		}
	}

	/**
	 * @brief Changes focus to the x component of the vector.
	 * @param parent Parent debug menu.
	 */
	void menuEnterX(Menu& parent)
	{
		mComponentValue = &mTargetVector->x;
		mComponentName  = "X";

		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the y component of the vector.
	 * @param parent Parent debug menu.
	 */
	void menuEnterY(Menu& parent)
	{
		mComponentValue = &mTargetVector->y;
		mComponentName  = "Y";

		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the z component of the vector.
	 * @param parent Parent debug menu.
	 */
	void menuEnterZ(Menu& parent)
	{
		mComponentValue = &mTargetVector->z;
		mComponentName  = "Z";

		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Constructs a new vector-editing debug menu, for editing positions and directions.
	 *
	 * @param target Vector containing components to edit - may be a position, direction etc.
	 * @param controller Active player controller.
	 * @param font Font to use when rendering the menu.
	 * @param alignToParentItem Whether to align this menu's vertical position to its parent item's position.
	 * @param smlAdjust Whether to adjust value by 0.1 (true) or 10.0 (false) each increment.
	 */
	PositionMenu(Vector3f* target, Controller* controller, Font* font, bool alignToParentItem, bool smlAdjust)
	    : Menu(controller, font, alignToParentItem)
	{
		// set up basic menu settings
		mTargetVector       = target;
		mIsSmallAdjustment  = smlAdjust;
		mLabelAlignmentType = Menu::LabelAlignmentType::LeftAligned;
		mCenterPoint.mMinX  = glnWidth / 2;
		mCenterPoint.mMinY  = glnHeight / 2;
		mGradBGTopColour.set(MENU_COLOUR_TEAL);
		mGradBGBottomColour.set(MENU_COLOUR_GREEN_GREY);

		addKeyEvent(KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(this, &Menu::menuCloseMenu));

		// set up X component option
		char* str = new char[0x40];
		sprintf(str, "X = %.2f", mTargetVector->x);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuEnterX));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuIncrease));

		// set up Y component option
		str = new char[0x40];
		sprintf(str, "Y = %.2f", mTargetVector->y);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuEnterY));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuIncrease));

		// set up Z component option
		str = new char[0x40];
		sprintf(str, "Z = %.2f", mTargetVector->z);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuEnterZ));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<PositionMenu, Menu&>(this, &PositionMenu::menuIncrease));
	}

	/**
	 * @brief Updates menu item label to reflect current component value.
	 * @param parent Parent debug menu.
	 * @param name Name of item, to set as label like "[name] = [value]".
	 * @param valuePtr Pointer to value to update label with, like "[name] = [value]".
	 */
	void updateComponent(Menu& parent, immut char* name, f32* valuePtr)
	{
		sprintf(parent.mCurrentItem->mLabel, "%s = %.2f", name, *valuePtr);
	}

	// _00     = VTBL
	// _00-_B4 = Menu
	Vector3f* mTargetVector;    ///< _B4, pointer to vector of components to edit with this menu.
	bool mIsSmallAdjustment;    ///< _B8, whether to adjust value by 0.1f (true) or 10.0f (false) each increment/decrement.
	f32* mComponentValue;       ///< _BC, pointer to current component value being edited.
	immut char* mComponentName; ///< _C0, name of current component value being edited ("X", "Y" or "Z").
};

#pragma endregion
//////////////////////////////////////////////////////
////////////// COLOUR EDITOR DEBUG MENU //////////////
//////////////////////////////////////////////////////
#pragma region COLOUR MENU

/**
 * @brief Debug menu for editing a `Colour` component-by-component.
 *
 * @note Size: 0xC0.
 */
struct ColourMenu : public Menu {

	/**
	 * @brief Decreases the focused component by 1 and updates its value. Minimum 0.
	 * @param parent Parent debug menu.
	 */
	void menuDecrease(Menu& parent)
	{
		if (*mComponentValue) {
			(*mComponentValue)--;
		}
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Increases the focused component by 1 and updates its value. Maximum 255.
	 * @param parent Parent debug menu.
	 */
	void menuIncrease(Menu& parent)
	{
		if (*mComponentValue < 255) {
			(*mComponentValue)++;
		}
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the red component of the colour.
	 * @param parent Parent debug menu.
	 */
	void menuEnterR(Menu& parent)
	{
		mComponentValue = &mTargetColour->r;
		mComponentName  = "R";
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the green component of the colour.
	 * @param parent Parent debug menu.
	 */
	void menuEnterG(Menu& parent)
	{
		mComponentValue = &mTargetColour->g;
		mComponentName  = "G";
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the blue component of the colour.
	 * @param parent Parent debug menu.
	 */
	void menuEnterB(Menu& parent)
	{
		mComponentValue = &mTargetColour->b;
		mComponentName  = "B";
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the alpha component of the colour.
	 * @param parent Parent debug menu.
	 */
	void menuEnterA(Menu& parent)
	{
		mComponentValue = &mTargetColour->a;
		mComponentName  = "A";
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Constructs a new RGBA colour-editing debug menu.
	 *
	 * @param target Colour containing components to edit.
	 * @param controller Active player controller.
	 * @param font Font to use when rendering the menu.
	 * @param alignToParentItem Whether to align this menu's vertical position to its parent item's position.
	 */
	ColourMenu(Colour* target, Controller* controller, Font* font, bool alignToParentItem)
	    : Menu(controller, font, alignToParentItem)
	{
		// set basic menu settings
		mTargetColour       = target;
		mLabelAlignmentType = Menu::LabelAlignmentType::LeftAligned;
		mCenterPoint.mMinX  = glnWidth / 2;
		mCenterPoint.mMinY  = glnHeight / 2;
		mGradBGTopColour.set(MENU_COLOUR_TEAL);
		mGradBGBottomColour.set(MENU_COLOUR_GREEN_GREY);
		addKeyEvent(KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(this, &Menu::menuCloseMenu));

		// red component option
		char* str = new char[0x40];
		sprintf(str, "R = %d", mTargetColour->r);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuEnterR));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuIncrease));

		// green component option
		str = new char[0x40];
		sprintf(str, "G = %d", mTargetColour->g);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuEnterG));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuIncrease));

		// blue component option
		str = new char[0x40];
		sprintf(str, "B = %d", mTargetColour->b);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuEnterB));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuIncrease));

		// alpha component option
		str = new char[0x40];
		sprintf(str, "A = %d", mTargetColour->a);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuEnterA));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &ColourMenu::menuIncrease));
	}

	/**
	 * @brief Updates menu item label to reflect current component value.
	 * @param parent Parent debug menu.
	 * @param name Name of item, to set as label like "[name] = [value]".
	 * @param valuePtr Pointer to value to update label with, like "[name] = [value]".
	 */
	void updateComponent(Menu& parent, immut char* name, u8* valuePtr) { sprintf(parent.mCurrentItem->mLabel, "%s = %d", name, *valuePtr); }

	// _00     = VTBL
	// _00-_B4 = Menu
	Colour* mTargetColour;      ///< _B4, pointer to Colour with components to edit with this menu.
	u8* mComponentValue;        ///< _B8, pointer to current component value being edited.
	immut char* mComponentName; ///< _BC, name of current component value being edited ("R", "G", "B" or "A").
};

#pragma endregion
//////////////////////////////////////////////////////
//////////////// FOG EDITOR DEBUG MENU ///////////////
//////////////////////////////////////////////////////
#pragma region FOG MENU

/**
 * @brief Debug menu for editing fog colour and distance.
 *
 * @note Size: 0xC4.
 */
struct FogMenu : public Menu {

	/**
	 * @brief Decreases the focused component by 10.0f and updates its value.
	 * @param parent Parent debug menu.
	 */
	void menuDecrease(Menu& parent)
	{
		*mComponentValue -= 10.0f;
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Increases the focused component by 10.0f and updates its value.
	 * @param parent Parent debug menu.
	 */
	void menuIncrease(Menu& parent)
	{
		*mComponentValue += 10.0f;
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the near (start) fog distance.
	 * @param parent Parent debug menu.
	 */
	void menuEnterNear(Menu& parent)
	{
		mComponentValue = mNear;
		mComponentName  = "Near";
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the far (end) fog distance.
	 * @param parent Parent debug menu.
	 */
	void menuEnterFar(Menu& parent)
	{
		mComponentValue = mFar;
		mComponentName  = "Far";
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Constructs a new fog-editing debug menu, for editing colour and near/far distances.
	 *
	 * @param colour Pointer to fog colour to edit.
	 * @param near Pointer to near-dist (fog start) value to edit.
	 * @param far Pointer to far-dist (fog end) value to edit.
	 * @param controller Active player controller.
	 * @param font Font to use when rendering the menu.
	 * @param alignToParentItem Whether to align this menu's vertical position to its parent item's position.
	 */
	FogMenu(Colour* colour, f32* near, f32* far, Controller* controller, Font* font, bool alignToParentItem)
	    : Menu(controller, font, alignToParentItem)
	{
		// set pointers and basic menu settings
		mNear               = near;
		mFar                = far;
		mLabelAlignmentType = Menu::LabelAlignmentType::LeftAligned;
		mCenterPoint.mMinX  = glnWidth / 2;
		mCenterPoint.mMinY  = glnHeight / 2;
		mGradBGTopColour.set(MENU_COLOUR_TEAL);
		mGradBGBottomColour.set(MENU_COLOUR_GREEN_GREY);
		addKeyEvent(KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(this, &Menu::menuCloseMenu));

		// fog colour submenu
		addMenu(new ColourMenu(colour, mController, gsys->mConsFont, true), 0, "fog colour");

		// near-dist option
		char* str = new char[0x40];
		sprintf(str, "Near = %.2f", *near);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<FogMenu, Menu&>(this, &FogMenu::menuEnterNear));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<FogMenu, Menu&>(this, &FogMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<FogMenu, Menu&>(this, &FogMenu::menuIncrease));

		// far-dist option
		str = new char[0x40];
		sprintf(str, "Far = %.2f", *far);
		addOption(0, str, nullptr);
		addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<FogMenu, Menu&>(this, &FogMenu::menuEnterFar));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<FogMenu, Menu&>(this, &FogMenu::menuDecrease));
		addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<FogMenu, Menu&>(this, &FogMenu::menuIncrease));
	}

	/**
	 * @brief Updates menu item label to reflect current component value.
	 * @param parent Parent debug menu.
	 * @param name Name of item, to set as label like "[name] = [value]".
	 * @param valuePtr Pointer to value to update label with, like "[name] = [value]".
	 */
	void updateComponent(Menu& parent, immut char* name, f32* valuePtr)
	{
		sprintf(parent.mCurrentItem->mLabel, "%s = %.2f", name, *valuePtr);
	}

	// _00     = VTBL
	// _00-_B4 = Menu
	f32* mNear;                 ///< _B4, pointer to "near" (start) fog distance to edit with this menu.
	f32* mFar;                  ///< _B8, pointer to "far" (end) fog distance to edit with this menu.
	f32* mComponentValue;       ///< _BC, pointer to current component value being edited (near or far).
	immut char* mComponentName; ///< _C0, name of current component value being edited ("Near" or "Far").
};

#pragma endregion
//////////////////////////////////////////////////////
/////////////// LIGHT EDITOR DEBUG MENU //////////////
//////////////////////////////////////////////////////
#pragma region LIGHT MENU

/**
 * @brief Restricted type of light for menu editing - this is converted to actual light type by `lightTypes` lookup, and back by `lightConv`
 * lookup. Cannot convert to a point light, only between parallel and spot - point lights will become parallel lights when edited.
 */
enum LightEditType {
	EDITTYPE_Parallel = 0, ///< 0, parallel rays, no attenuation or spot effect.
	EDITTYPE_Spot     = 1, ///< 1, directional with a cone/angle, uses spot attenuation.
	EDITTYPE_COUNT,        ///< 2, number of types supported by editor.
};

static char* lightTypeNames[LIGHT_TYPECOUNT] = { "OFF", "PARALLEL", "POINT", "SPOT" };
static int lightTypes[EDITTYPE_COUNT]        = { LIGHT_Parallel, LIGHT_Spot };
static int lightConv[LIGHT_TYPECOUNT]        = { EDITTYPE_Parallel, EDITTYPE_Parallel, EDITTYPE_Parallel, EDITTYPE_Spot };
static char* lightMoveNames[LIGHTMOVE_COUNT] = { "global", "attach to navi" };

/**
 * @brief Debug menu for editing light type, attachment, FOV, position, direction and colour.
 *
 * @note Size: 0xCC.
 */
struct LightMenu : public Menu {

	/**
	 * @brief Constructs a new light-editing debug menu, for editing light type, movement style, colour.
	 *
	 * @param light Pointer to light to edit.
	 * @param moveType Pointer to light's move/attachment type to edit.
	 * @param controller Active player controller.
	 * @param font Font to use when rendering the menu.
	 * @param alignToParentItem Whether to align this menu's vertical position to its parent item's position.
	 */
	LightMenu(Light* light, int* moveType, Controller* controller, Font* font, bool alignToParentItem)
	    : Menu(controller, font, alignToParentItem)
	{
		// set pointers and basic menu settings
		mLight             = light;
		mSelectedLightType = EDITTYPE_Parallel;
		mLightMoveType     = moveType;

		// every light starts as a parallel light when edited
		SET_LIGHT_TYPE(mLight->mLightFlag, lightTypes[mSelectedLightType]);

		mCenterPoint.mMinX = glnWidth / 2;
		mCenterPoint.mMinY = glnHeight / 2;
		mGradBGTopColour.set(MENU_COLOUR_TEAL);
		mGradBGBottomColour.set(MENU_COLOUR_GREEN_GREY);
		addKeyEvent(KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(this, &Menu::menuCloseMenu));

		// farm out all the options setup to dedicated function
		addOptions();
	}

	/**
	 * @brief Decreases the focused component by 1 and updates its value.
	 * @param parent Parent debug menu.
	 */
	void menuDecrease(Menu& parent)
	{
		*mComponentValue -= 1.0f;
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Increases the focused component by 1 and updates its value.
	 * @param parent Parent debug menu.
	 */
	void menuIncrease(Menu& parent)
	{
		*mComponentValue += 1.0f;
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Changes focus to the field-of-view component of the (spot)light. Poorly named, clearly copied from FogMenu.
	 * @param parent Parent debug menu.
	 */
	void menuEnterNear(Menu& parent)
	{
		mComponentValue = mSpotFov;
		mComponentName  = "Fov";
		updateComponent(parent, mComponentName, mComponentValue);
	}

	/**
	 * @brief Swaps light type from Spot to Parallel and vice versa, and refreshes the options list. No support for point lights.
	 * @param parent Parent debug menu.
	 */
	void menuChangeType(Menu& parent)
	{
		mSelectedLightType ^= 1;
		SET_LIGHT_TYPE(mLight->mLightFlag, lightTypes[mSelectedLightType]);
		// re-set-up menu items
		resetOptions();
		addOptions();
		open(false);
	}

	/**
	 * @brief Swaps light move/attachment type from "global" to "attached to navi" and vice versa, and refreshes the options list.
	 * @param parent Parent debug menu.
	 */
	void menuChangeMove(Menu& parent)
	{
		*mLightMoveType ^= 1;
		// re-set-up menu items
		resetOptions();
		addOptions();
		open(false);
	}

	/// Dedicated function for setting up and updating menu options, based on selected light type.
	void addOptions()
	{
		mSelectedLightType = lightConv[GET_LIGHT_TYPE(mLight->mLightFlag)];

		// light type option
		addOption(0, lightTypeNames[GET_LIGHT_TYPE(mLight->mLightFlag)], new Delegate1<LightMenu, Menu&>(this, &LightMenu::menuChangeType));

		addOption(MENU_FAKE_OPTION_FOR_GAP);

		// spot-specific settings
		if (GET_LIGHT_TYPE(mLight->mLightFlag) == LIGHT_Spot) {
			mSpotFov = &mLight->mSpotAngle;

			// move/attachment type option
			addOption(0, lightMoveNames[mLightMoveType[0]], new Delegate1<LightMenu, Menu&>(this, &LightMenu::menuChangeMove));

			// field-of-view option
			char* str = new char[0x40];
			sprintf(str, "Fov = %.2f", *mSpotFov);
			addOption(0, str, nullptr);
			addKeyEvent(KeyEventType::OnFocusGained, KBBTN_NONE, new Delegate1<LightMenu, Menu&>(this, &LightMenu::menuEnterNear));
			addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<LightMenu, Menu&>(this, &LightMenu::menuDecrease));
			addKeyEvent(KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<LightMenu, Menu&>(this, &LightMenu::menuIncrease));
		}

		// spot and point specific settings (in practice you can't edit point lights because their type is instantly overridden to parallel)
		if (GET_LIGHT_TYPE(mLight->mLightFlag) != LIGHT_Parallel) {
			// submenu for editing focus position
			addMenu(new PositionMenu(&mLight->mPosition, mController, gsys->mConsFont, true, false), 0, "position");
		}

		// more spot settings
		if (GET_LIGHT_TYPE(mLight->mLightFlag) == LIGHT_Spot) {
			// sub-menu for editing spotlight direction
			addMenu(new PositionMenu(&mLight->mDirection, mController, gsys->mConsFont, true, true), 0, "direction");
		}

		// sub-menu for editing light colour
		addMenu(new ColourMenu(&mLight->mDiffuseColour, mController, gsys->mConsFont, true), 0, "colour");
	}

	/**
	 * @brief Updates menu item label to reflect current component value.
	 * @param parent Parent debug menu.
	 * @param name Name of item, to set as label like "[name] = [value]".
	 * @param valuePtr Pointer to value to update label with, like "[name] = [value]".
	 */
	void updateComponent(Menu& parent, immut char* name, f32* valuePtr)
	{
		sprintf(parent.mCurrentItem->mLabel, "%s = %.2f", name, *valuePtr);
	}

	// _00     = VTBL
	// _00-_B4 = Menu
	int mSelectedLightType;     ///< _B4, current (supported) type for light being edited - see `LightEditType` enum.
	int* mLightMoveType;        ///< _B8, pointer to move/attachment type of light being edited.
	Light* mLight;              ///< _BC, pointer to light being edited.
	f32* mSpotFov;              ///< _C0, pointer to field-of-view value being edited (spot types only).
	f32* mComponentValue;       ///< _C4, pointer to current component being edited - only ever points to the same value as `mSpotFov`.
	immut char* mComponentName; ///< _C8, name of current component being edited - only ever "Fov".
};

#pragma endregion
//////////////////////////////////////////////////////
/////////// TIME SETTING EDITOR DEBUG MENU ///////////
//////////////////////////////////////////////////////
#pragma region DAY SET MENU

/**
 * @brief Debug menu for editing all settings for a single `TimeSetting`.
 *
 * @note Size: 0xB8.
 */
struct DaySetMenu : public Menu {

	/**
	 * @brief Constructs a new time setting-editing debug menu, for editing positions and directions.
	 *
	 * All actions are farmed out to submenus.
	 *
	 * @param time Pointer to time setting to edit.
	 * @param controller Active player controller.
	 * @param font Font to use when rendering the menu.
	 * @param alignToParentItem Whether to align this menu's vertical position to its parent item's position.
	 */
	DaySetMenu(TimeSetting* time, Controller* controller, Font* font, bool alignToParentItem)
	    : Menu(controller, font, alignToParentItem)
	{
		// set up pointers and basic menu settings
		mTargetTimeSetting = time;
		mCenterPoint.mMinX = glnWidth / 2;
		mCenterPoint.mMinY = glnHeight / 2 + 60;
		mGradBGTopColour.set(MENU_COLOUR_GREEN);
		mGradBGBottomColour.set(MENU_COLOUR_GREEN_GREY);
		addKeyEvent(KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(this, &Menu::menuCloseMenu));

		// set up submenu for editing ambient colour
		addMenu(new ColourMenu(&mTargetTimeSetting->mAmbientColour, mController, gsys->mConsFont, true), 0, "ambient colour");

		// set up submenu for editing fog
		addMenu(new FogMenu(&mTargetTimeSetting->mFogColour, &mTargetTimeSetting->mFogNear, &mTargetTimeSetting->mFogFar, mController,
		                    gsys->mConsFont, true),
		        0, "fog");

		addOption(MENU_FAKE_OPTION_FOR_GAP);

		// set up submenus for each of the 7 possible lights
		addMenu(new LightMenu(&mTargetTimeSetting->mLights[DAYLIGHT_Main], &mTargetTimeSetting->mLightMoveTypes[DAYLIGHT_Main], mController,
		                      gsys->mConsFont, true),
		        0, "main light");
		addMenu(new LightMenu(&mTargetTimeSetting->mLights[DAYLIGHT_Sub], &mTargetTimeSetting->mLightMoveTypes[DAYLIGHT_Sub], mController,
		                      gsys->mConsFont, true),
		        0, "sub light");
		addMenu(new LightMenu(&mTargetTimeSetting->mLights[DAYLIGHT_Plus1], &mTargetTimeSetting->mLightMoveTypes[DAYLIGHT_Plus1],
		                      mController, gsys->mConsFont, true),
		        0, "+1 light");
		addMenu(new LightMenu(&mTargetTimeSetting->mLights[DAYLIGHT_Plus2], &mTargetTimeSetting->mLightMoveTypes[DAYLIGHT_Plus2],
		                      mController, gsys->mConsFont, true),
		        0, "+2 light");
		addMenu(new LightMenu(&mTargetTimeSetting->mLights[DAYLIGHT_Plus3], &mTargetTimeSetting->mLightMoveTypes[DAYLIGHT_Plus3],
		                      mController, gsys->mConsFont, true),
		        0, "+3 light");
		addMenu(new LightMenu(&mTargetTimeSetting->mLights[DAYLIGHT_Plus4], &mTargetTimeSetting->mLightMoveTypes[DAYLIGHT_Plus4],
		                      mController, gsys->mConsFont, true),
		        0, "+4 light");
		addMenu(new LightMenu(&mTargetTimeSetting->mLights[DAYLIGHT_Plus5], &mTargetTimeSetting->mLightMoveTypes[DAYLIGHT_Plus5],
		                      mController, gsys->mConsFont, true),
		        0, "+5 light");
	}

	// _00     = VTBL
	// _00-_B4 = Menu
	TimeSetting* mTargetTimeSetting; ///< _B4, pointer to time setting being edited.
};

#pragma endregion
//////////////////////////////////////////////////////
///////////////////// DAY MANAGER ////////////////////
//////////////////////////////////////////////////////
#pragma region DAY MANAGER

/**
 * @brief Updates menu item label to reflect current component value.
 *
 * @param parent Parent debug menu.
 * @param name Name of item, to set as label like "[name] = [value]".
 * @param valuePtr Pointer to value to update label with, like "[name] = [value]".
 * @note UNUSED Size: 000034
 */
void DayMgr::updateComponent(Menu& parent, immut char* name, int* valuePtr)
{
	sprintf(parent.mCurrentItem->mLabel, "%s = %d", name, *valuePtr);
}

/**
 * @brief Increases the map blur by 1 and updates its value (maximum 255).
 *
 * Does nothing in retail, since this blur value is completely unused.
 *
 * @param parent Parent debug menu.
 */
void DayMgr::menuBIncrease(Menu& parent)
{
	if (mMapMgr->mBlur < 255) {
		mMapMgr->mBlur++;
	}
	updateComponent(parent, "Blur", &mMapMgr->mBlur);
}

/**
 * @brief Decreases the map blur by 1 and updates its value (minimum 0).
 *
 * Does nothing in retail, since this blur value is completely unused.
 *
 * @param parent Parent debug menu.
 */
void DayMgr::menuBDecrease(Menu& parent)
{
	if (mMapMgr->mBlur > 0) {
		mMapMgr->mBlur--;
	}
	updateComponent(parent, "Blur", &mMapMgr->mBlur);
}

/**
 * @brief Constructs a new lighting and fog manager for the given map, including a debug menu to adjust settings.
 *
 * @param map Manager for current active map/area.
 * @param controller Active player controller.
 */
DayMgr::DayMgr(MapMgr* map, Controller* controller)
{
	mMapMgr           = map;
	mActiveLightCount = DAYLIGHT_DefaultCount;
	mMaxLightCount    = DAYLIGHT_COUNT;
	mTimeSettings     = new TimeSetting[TIME_COUNT];

	// set up debug menu - this is put under NewPikiGameSetupSection's debug menu as "Lighting"
	mDebugMenu                      = new Menu(controller, gsys->mConsFont);
	mDebugMenu->mLabelAlignmentType = Menu::LabelAlignmentType::LeftAligned;
	mDebugMenu->mCenterPoint.mMinX  = glnWidth / 2;
	mDebugMenu->mCenterPoint.mMinY  = glnHeight / 2 + 90;
	mDebugMenu->mGradBGTopColour.set(MENU_COLOUR_GREEN);
	mDebugMenu->mGradBGBottomColour.set(MENU_COLOUR_GREEN_GREY);
	mDebugMenu->addKeyEvent(Menu::KeyEventType::OnCancel, KBBTN_B, new Delegate1<Menu, Menu&>(mDebugMenu, &Menu::menuCloseMenu));

	// light count option
	char* str = new char[0x40];
	sprintf(str, "Light Count %d", mActiveLightCount);
	mDebugMenu->addOption(0, str, nullptr);
	mDebugMenu->addKeyEvent(Menu::KeyEventType::OnInputRelease, KBBTN_Y, new Delegate1<DayMgr, Menu&>(this, &DayMgr::menuDecreaseLights));
	mDebugMenu->addKeyEvent(Menu::KeyEventType::OnInputRelease, KBBTN_X, new Delegate1<DayMgr, Menu&>(this, &DayMgr::menuIncreaseLights));

	// time of day option
	str = new char[0x40];
	sprintf(str, "Time : % 2.1f", gameflow.mWorldClock.mTimeOfDay);
	mDebugMenu->addOption(0, str, nullptr);
	mDebugMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<DayMgr, Menu&>(this, &DayMgr::menuDecreaseTime));
	mDebugMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<DayMgr, Menu&>(this, &DayMgr::menuIncreaseTime));

	mDebugMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);

	// dump settings option
	mDebugMenu->addOption(0, "Dump Settings", new Delegate1<DayMgr, Menu&>(this, &DayMgr::menuDumpSettings));

	mDebugMenu->addOption(MENU_FAKE_OPTION_FOR_GAP);

	// submenus for each time setting (morning, day, evening, night, movie)
	str = new char[0x40];
	sprintf(str, "morning : % 2.1f", gameflow.mParameters->mMorningMid());
	mDebugMenu->addMenu(new DaySetMenu(&mTimeSettings[TIME_Morning], controller, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "day     : % 2.1f -> % 2.1f", gameflow.mParameters->mMorningEnd(), gameflow.mParameters->mEveningStart());
	mDebugMenu->addMenu(new DaySetMenu(&mTimeSettings[TIME_Day], controller, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "evening : % 2.1f", gameflow.mParameters->mEveningMid());
	mDebugMenu->addMenu(new DaySetMenu(&mTimeSettings[TIME_Evening], controller, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "night   : % 2.1f -> % 2.1f", gameflow.mParameters->mEveningEnd(), gameflow.mParameters->mMorningStart());
	mDebugMenu->addMenu(new DaySetMenu(&mTimeSettings[TIME_Night], controller, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "movie   : % 2.1f -> % 2.1f", MOVIE_TIME, MOVIE_TIME);
	mDebugMenu->addMenu(new DaySetMenu(&mTimeSettings[TIME_Movie], controller, gsys->mConsFont, false), 0, str);

	// option for map mgr's blur setting (which does nothing, because it's not connected to that value at all)
	if (mMapMgr) {
		str = new char[0x40];
		sprintf(str, "Blur = %d", mMapMgr->mBlur);
		mDebugMenu->addOption(0, str, nullptr);
		mDebugMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_Y, new Delegate1<DayMgr, Menu&>(this, &DayMgr::menuBDecrease));
		mDebugMenu->addKeyEvent(Menu::KeyEventType::WhileInputHeld, KBBTN_X, new Delegate1<DayMgr, Menu&>(this, &DayMgr::menuBIncrease));
	}
}

/**
 * @brief Updates light count menu option to reflect current value.
 *
 * @param parent Parent debug menu.
 * @note UNUSED Size: 000038
 */
void DayMgr::updateLightCount(Menu& parent)
{
	sprintf(parent.mCurrentItem->mLabel, "Light Count %d", mActiveLightCount);
}

/**
 * @brief Increases the number of lights used by 1 and updates its value (max mMaxLightCount).
 *
 * @param parent Parent debug menu.
 */
void DayMgr::menuIncreaseLights(Menu& parent)
{
	mActiveLightCount++;
	if (mActiveLightCount > mMaxLightCount) {
		mActiveLightCount = mMaxLightCount;
	}

	updateLightCount(parent);
}

/**
 * @brief Decreases the number of lights used by 1 and updates its value (min 0).
 *
 * @param parent Parent debug menu.
 */
void DayMgr::menuDecreaseLights(Menu& parent)
{
	mActiveLightCount--;
	if (mActiveLightCount < 0) {
		mActiveLightCount = 0;
	}

	updateLightCount(parent);
}

/**
 * @brief Updates time of day menu option to reflect current value.
 *
 * @param parent Parent debug menu.
 * @note UNUSED Size: 000040
 */
void DayMgr::updateTime(Menu& parent)
{
	sprintf(parent.mCurrentItem->mLabel, "Time : % 2.1f", gameflow.mWorldClock.mTimeOfDay);
}

/**
 * @brief Increases the time of day by 3 in-game minutes and updates its value (max 36 in-game secs before midnight).
 *
 * @param parent Parent debug menu.
 */
void DayMgr::menuIncreaseTime(Menu& parent)
{
	f32 time = gameflow.mWorldClock.mTimeOfDay + 0.05f;
	if (time > 23.99f) {
		time = 23.99f;
	}
	gameflow.mWorldClock.setTime(time);

	updateTime(parent);
}

/**
 * @brief Decreases the time of day by 3 in-game minutes and updates its value (min midnight).
 *
 * @param parent Parent debug menu.
 */
void DayMgr::menuDecreaseTime(Menu& parent)
{
	f32 time = gameflow.mWorldClock.mTimeOfDay - 0.05f;
	if (time < 0.0f) {
		time = 0.0f;
	}
	gameflow.mWorldClock.setTime(time);

	updateTime(parent);
}

/**
 * @brief Blends time settings to create current time-based lighting conditions and updates graphics settings for lighting, fog and sun
 * position.
 *
 * @param gfx Graphics context for rendering.
 * @param time In-game time to use for blending time settings - pass `MOVIE_TIME` (25.0f) for special movie lighting.
 * @param numLights Number of active lights to use.
 */
void DayMgr::refresh(Graphics& gfx, f32 time, int numLights)
{
	// cap number of lights at active light count (default: 2)
	int lights = (numLights < mActiveLightCount) ? numLights : mActiveLightCount;

	// get blending parameters based on time of day
	f32 blendRatio = 0.0f;
	TimeSetting* timeSettingStart;
	TimeSetting* timeSettingEnd;
	if (time == MOVIE_TIME) {
		// special movie lighting
		timeSettingStart = timeSettingEnd = &mTimeSettings[TIME_Movie];
		blendRatio                        = 0.0f;

	} else if (time < gameflow.mParameters->mMorningStart() || time >= gameflow.mParameters->mEveningEnd()) {
		// night time - this is really just for the end of day cutscene (7pm-5:15am)
		timeSettingStart = timeSettingEnd = &mTimeSettings[TIME_Night];
		blendRatio                        = 0.0f;

	} else if (time < gameflow.mParameters->mMorningMid()) {
		// early morning, blend night into morning - this is before gameplay, so never happens (5:15am-7am)
		timeSettingStart = &mTimeSettings[TIME_Night];
		timeSettingEnd   = &mTimeSettings[TIME_Morning];
		blendRatio       = (time - gameflow.mParameters->mMorningStart())
		           / (gameflow.mParameters->mMorningMid() - gameflow.mParameters->mMorningStart());

	} else if (time < gameflow.mParameters->mMorningEnd()) {
		// late morning, blend morning into day - this is from when gameplay starts for the day (7am-8am)
		timeSettingStart = &mTimeSettings[TIME_Morning];
		timeSettingEnd   = &mTimeSettings[TIME_Day];
		blendRatio
		    = (time - gameflow.mParameters->mMorningMid()) / (gameflow.mParameters->mMorningEnd() - gameflow.mParameters->mMorningMid());

	} else if (time < gameflow.mParameters->mEveningStart()) {
		// peak daytime - just use constant day setting (8am-3pm)
		timeSettingStart = timeSettingEnd = &mTimeSettings[TIME_Day];
		blendRatio                        = 0.0f;

	} else if (time < gameflow.mParameters->mEveningMid()) {
		// early evening - start blending day into evening (3pm-4:30pm)
		timeSettingStart = &mTimeSettings[TIME_Day];
		timeSettingEnd   = &mTimeSettings[TIME_Evening];
		blendRatio       = (time - gameflow.mParameters->mEveningStart())
		           / (gameflow.mParameters->mEveningMid() - gameflow.mParameters->mEveningStart());

	} else if (time < gameflow.mParameters->mEveningEnd()) {
		// late evening - start blending evening into night (4:30pm-7pm)
		timeSettingStart = &mTimeSettings[TIME_Evening];
		timeSettingEnd   = &mTimeSettings[TIME_Night];
		blendRatio
		    = (time - gameflow.mParameters->mEveningMid()) / (gameflow.mParameters->mEveningEnd() - gameflow.mParameters->mEveningMid());
	}

	// lerp lighting and colour settings the appropriate amount between our parameters for all used lights
	// ambient colour
	timeSettingStart->mAmbientColour.lerpTo(timeSettingEnd->mAmbientColour, blendRatio, mCurrentTimeSetting.mAmbientColour);

	for (int i = 0; i < lights; i++) {
		// light colour
		timeSettingStart->mLights[i].mDiffuseColour.lerpTo(timeSettingEnd->mLights[i].mDiffuseColour, blendRatio,
		                                                   mCurrentTimeSetting.mLights[i].mDiffuseColour);

		// light types
		mCurrentTimeSetting.mLights[i].mLightFlag = timeSettingStart->mLights[i].mLightFlag;
		mCurrentTimeSetting.mLightMoveTypes[i]    = timeSettingStart->mLightMoveTypes[i];

		// light ranges/angles/positions/directions
		mCurrentTimeSetting.mLights[i].mDistancedRange
		    = timeSettingStart->mLights[i].mDistancedRange
		    + (timeSettingEnd->mLights[i].mDistancedRange - timeSettingStart->mLights[i].mDistancedRange) * blendRatio;

		mCurrentTimeSetting.mLights[i].mSpotAngle
		    = timeSettingStart->mLights[i].mSpotAngle
		    + (timeSettingEnd->mLights[i].mSpotAngle - timeSettingStart->mLights[i].mSpotAngle) * blendRatio;

		timeSettingStart->mLights[i].mPosition.lerpTo(timeSettingEnd->mLights[i].mPosition, blendRatio,
		                                              mCurrentTimeSetting.mLights[i].mPosition);

		timeSettingStart->mLights[i].mDirection.lerpTo(timeSettingEnd->mLights[i].mDirection, blendRatio,
		                                               mCurrentTimeSetting.mLights[i].mDirection);
	}

	// lerp fog settings
	timeSettingStart->mFogColour.lerpTo(timeSettingEnd->mFogColour, blendRatio, mCurrentTimeSetting.mFogColour);
	mCurrentTimeSetting.mFogNear = timeSettingStart->mFogNear + (timeSettingEnd->mFogNear - timeSettingStart->mFogNear) * blendRatio;
	mCurrentTimeSetting.mFogFar  = timeSettingStart->mFogFar + (timeSettingEnd->mFogFar - timeSettingStart->mFogFar) * blendRatio;

	// push ambient colour to graphics unit
	gfx.mAmbientColour = mCurrentTimeSetting.mAmbientColour;

	// calculate appropriate sun position based on time-of-day
	// sun should move from east (positive x) to west (negative x) and always in the sky, never at the horizon (infinite shadows)
	Matrix4f sunTransformMtx;
	sunTransformMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(time / 24.0f * PI - HALF_PI, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
	mCurrentSunPosition.set(0.0f, 2500.0f, 0.0f);
	mCurrentSunPosition.multMatrix(sunTransformMtx);
	// adjust axes so sun goes the direction we want - east (positive x) to west (negative x)
	f32 z                 = mCurrentSunPosition.z;
	mCurrentSunPosition.z = mCurrentSunPosition.x;
	mCurrentSunPosition.x = -z;

	// push sun position to graphics unit
	gfx.mSunPosition = mCurrentSunPosition;

	// set some unused sun-related vector
	if (mMapMgr) {
		mMapMgr->_08.set(mCurrentSunPosition.x / 20.0f, mCurrentSunPosition.y / 5.0f, mCurrentSunPosition.z / 20.0f);
	}

	//
	for (int i = 0; i < lights; i++) {
		if (GET_LIGHT_TYPE(mCurrentTimeSetting.mLights[i].mLightFlag) == LIGHT_Parallel) {
			// calculate appropriate parallel light directions/positions for sun and underlighting
			if (!(i & 1)) {
				// even-numbered lights (main, +1, +3, +5) - sun
				mCurrentTimeSetting.mLights[i].mPosition.set(mCurrentSunPosition.x, mCurrentSunPosition.y, mCurrentSunPosition.z);
				mCurrentTimeSetting.mLights[i].mDirection.set(-mCurrentSunPosition.x, -mCurrentSunPosition.y, -mCurrentSunPosition.z);
				mCurrentTimeSetting.mLights[i].mDirection.normalise();
			} else {
				// odd-numbered lights (sub, +2, +4) - underlighting
				mCurrentTimeSetting.mLights[i].mPosition.set(-mCurrentSunPosition.x, -mCurrentSunPosition.y, -mCurrentSunPosition.z);
				mCurrentTimeSetting.mLights[i].mDirection.set(mCurrentSunPosition.x, mCurrentSunPosition.y, mCurrentSunPosition.z);
				mCurrentTimeSetting.mLights[i].mDirection.normalise();
			}
		} else if (mCurrentTimeSetting.mLightMoveTypes[i] == LIGHTMOVE_AttachToNavi && naviMgr && naviMgr->getNavi()) {
			// (non-parallel) light moves with captain, calculate directions and positions
			// calc rotation in navi local coordinates, then move with navi
			Matrix4f naviLocalMtx;
			naviLocalMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, naviMgr->getNavi()->mFaceDirection, 0.0f),
			                     Vector3f(0.0f, 0.0f, 0.0f));
			mCurrentTimeSetting.mLights[i].mDirection.rotate(naviLocalMtx);
			mCurrentTimeSetting.mLights[i].mPosition.rotate(naviLocalMtx);
			mCurrentTimeSetting.mLights[i].mPosition.add(naviMgr->getNavi()->mSRT.t);
		}
	}

	// push lights to graphics unit
	for (int i = 0; i < lights; i++) {
		mCurrentTimeSetting.mLights[i].update();
		gfx.addLight(&mCurrentTimeSetting.mLights[i]);
	}

	// push fog settings to graphics unit
	setFog(gfx, nullptr);
}

/**
 * @brief Pushes fog settings to the graphics unit.
 *
 * @param gfx Graphics context to push fog settings to.
 * @param fogColour Colour to override fog colour to, or `nullptr` to use time-based setting.
 */
void DayMgr::setFog(Graphics& gfx, Colour* fogColour)
{
	gfx.setFog(true, fogColour ? *fogColour : mCurrentTimeSetting.mFogColour, 1.0f, mCurrentTimeSetting.mFogNear,
	           mCurrentTimeSetting.mFogFar);
}

/**
 * @brief Dumps all current settings to debug output.
 */
void DayMgr::menuDumpSettings(Menu&)
{
	// set up names for time settings and lights
	static const char* settingnames[TIME_COUNT]   = { "night", "morning", "day", "evening", "movie" };
	static const char* lightnames[DAYLIGHT_COUNT] = { "main light", "sub light", "+1", "+2", "+3", "+4", "+5" };

	BOOL old           = gsys->mTogglePrint;
	gsys->mTogglePrint = TRUE;

	PRINT("\n------- cut here -----------------\n\n");
	PRINT("dayMgr {\n");
	PRINT("numsettings %d\n\n", TIME_COUNT);

	// print out each time setting in turn
	for (int i = 0; i < TIME_COUNT; i++) {
		// setting name
		PRINT("timesetting %d {\t// %s\n", i, settingnames[i]);

		// print out each light in light setting
		for (int j = 0; j < mActiveLightCount; j++) {
			// light name
			PRINT("\tlight %d {\t// %s\n", j, lightnames[j]);
			// light type
			PRINT("\t\ttype\t%d\n", GET_LIGHT_TYPE(mTimeSettings[i].mLights[j].mLightFlag));
			// move/attachment type
			PRINT("\t\tattach\t%d\n", mTimeSettings[i].mLightMoveTypes[j]);

			if (GET_LIGHT_TYPE(mTimeSettings[i].mLights[j].mLightFlag) == LIGHT_Spot) {
				// field-of-view, if spot type
				PRINT("\t\tfov\t%.1f\n", mTimeSettings[i].mLights[j].mSpotAngle);
			}

			if (GET_LIGHT_TYPE(mTimeSettings[i].mLights[j].mLightFlag) != LIGHT_Parallel) {
				// position, if not parallel type
				PRINT("\t\tposition\t%.2f %.2f %.2f\n", mTimeSettings[i].mLights[j].mPosition.x, mTimeSettings[i].mLights[j].mPosition.y,
				      mTimeSettings[i].mLights[j].mPosition.z);
			}

			if (GET_LIGHT_TYPE(mTimeSettings[i].mLights[j].mLightFlag) == LIGHT_Spot) {
				// direction, if spot type
				PRINT("\t\tdirection\t%.2f %.2f %.2f\n", mTimeSettings[i].mLights[j].mDirection.x, mTimeSettings[i].mLights[j].mDirection.y,
				      mTimeSettings[i].mLights[j].mDirection.z);
			}

			// light colour
			PRINT("\t\tcolour\t%d %d %d %d\n", mTimeSettings[i].mLights[j].mDiffuseColour.r, mTimeSettings[i].mLights[j].mDiffuseColour.g,
			      mTimeSettings[i].mLights[j].mDiffuseColour.b, mTimeSettings[i].mLights[j].mDiffuseColour.a);

			PRINT("\t\t}\n");
		}

		// ambient colour
		PRINT("\tambient {\n");
		PRINT("\t\tcolour\t%d %d %d %d\n", mTimeSettings[i].mAmbientColour.r, mTimeSettings[i].mAmbientColour.g,
		      mTimeSettings[i].mAmbientColour.b, mTimeSettings[i].mAmbientColour.a);
		PRINT("\t\t}\n");

		// fog settings
		PRINT("\tfog {\n");
		PRINT("\t\tcolour\t%d %d %d %d\n", mTimeSettings[i].mFogColour.r, mTimeSettings[i].mFogColour.g, mTimeSettings[i].mFogColour.b,
		      mTimeSettings[i].mFogColour.a);
		// near far
		PRINT("\t\tdist\t%.2f %.2f\n", mTimeSettings[i].mFogNear, mTimeSettings[i].mFogFar);

		PRINT("\t\t}\n");
		PRINT("\t}\n");
	}
	PRINT("}\n\n");
	PRINT("\n------- cut here -----------------\n");

	gsys->mTogglePrint = old;
}

/**
 * @brief Reads in all time settings from file stream (stage's .ini file, or opening.ini for title screen).
 *
 * @param cmds Stream of commands from file.
 */
void DayMgr::init(CmdStream* cmds)
{
	mActiveLightCount = 0;
	while (!cmds->endOfCmds() && !cmds->endOfSection()) {
		cmds->getToken(true);
		// unused setting count - always 5
		if (cmds->isToken("numsettings")) {
			cmds->getToken(true);
			continue;
		}

		if (cmds->isToken("timesetting")) {
			int settingType; // see TimeSettingType enum
			sscanf(cmds->getToken(true), "%d", &settingType);
			cmds->getToken(true);

			// read in setting
			while (!cmds->endOfCmds() && !cmds->endOfSection()) {
				cmds->getToken(true);

				if (cmds->isToken("light")) {
					int lightNum;
					sscanf(cmds->getToken(true), "%d", &lightNum);
					if (lightNum > mActiveLightCount - 1) {
						mActiveLightCount = lightNum + 1;
					}

					cmds->getToken(true);

					// read in this light's info
					while (!cmds->endOfCmds() && !cmds->endOfSection()) {
						cmds->getToken(true);
						if (cmds->isToken("type")) {
							u32 type;
							sscanf(cmds->getToken(true), "%d", &type);
							SET_LIGHT_TYPE(mTimeSettings[settingType].mLights[lightNum].mLightFlag, type);
							continue;
						}

						if (cmds->isToken("attach")) {
							sscanf(cmds->getToken(true), "%d", &mTimeSettings[settingType].mLightMoveTypes[lightNum]);
							continue;
						}

						if (cmds->isToken("fov")) {
							sscanf(cmds->getToken(true), "%f", &mTimeSettings[settingType].mLights[lightNum].mSpotAngle);
							continue;
						}

						if (cmds->isToken("position")) {
							f32 x;
							sscanf(cmds->getToken(true), "%f", &x);
							f32 y;
							sscanf(cmds->getToken(true), "%f", &y);
							f32 z;
							sscanf(cmds->getToken(true), "%f", &z);
							mTimeSettings[settingType].mLights[lightNum].mPosition.set(x, y, z);
							continue;
						}

						if (cmds->isToken("direction")) {
							f32 x;
							sscanf(cmds->getToken(true), "%f", &x);
							f32 y;
							sscanf(cmds->getToken(true), "%f", &y);
							f32 z;
							sscanf(cmds->getToken(true), "%f", &z);
							mTimeSettings[settingType].mLights[lightNum].mDirection.set(x, y, z);
							continue;
						}

						if (cmds->isToken("colour")) {
							int r;
							sscanf(cmds->getToken(true), "%d", &r);
							int g;
							sscanf(cmds->getToken(true), "%d", &g);
							int b;
							sscanf(cmds->getToken(true), "%d", &b);
							int a;
							sscanf(cmds->getToken(true), "%d", &a);
							mTimeSettings[settingType].mLights[lightNum].mDiffuseColour.set(r, g, b, a);
							continue;
						}
					}

					if (!cmds->endOfCmds()) {
						cmds->getToken(true);
					}
				} else if (cmds->isToken("ambient")) {
					cmds->getToken(true);
					// read in this colour
					while (!cmds->endOfCmds() && !cmds->endOfSection()) {
						cmds->getToken(true);
						if (cmds->isToken("colour")) {
							int r;
							sscanf(cmds->getToken(true), "%d", &r);
							int g;
							sscanf(cmds->getToken(true), "%d", &g);
							int b;
							sscanf(cmds->getToken(true), "%d", &b);
							int a;
							sscanf(cmds->getToken(true), "%d", &a);
							mTimeSettings[settingType].mAmbientColour.set(r, g, b, a);
						}
					}
					if (!cmds->endOfCmds()) {
						cmds->getToken(true);
					}

				} else if (cmds->isToken("specular")) {
					// unused specular colour, reads into nothing
					cmds->getToken(true);
					while (!cmds->endOfCmds() && !cmds->endOfSection()) {
						cmds->getToken(true);
						if (cmds->isToken("colour")) {
							int r;
							sscanf(cmds->getToken(true), "%d", &r);
							int g;
							sscanf(cmds->getToken(true), "%d", &g);
							int b;
							sscanf(cmds->getToken(true), "%d", &b);
							int a;
							sscanf(cmds->getToken(true), "%d", &a);
							// nice.
						}
					}
					if (!cmds->endOfCmds()) {
						cmds->getToken(true);
					}

				} else if (cmds->isToken("fog")) {
					cmds->getToken(true);
					// read in fog settings
					while (!cmds->endOfCmds() && !cmds->endOfSection()) {
						cmds->getToken(true);
						if (cmds->isToken("colour")) {
							int r;
							sscanf(cmds->getToken(true), "%d", &r);
							int g;
							sscanf(cmds->getToken(true), "%d", &g);
							int b;
							sscanf(cmds->getToken(true), "%d", &b);
							int a;
							sscanf(cmds->getToken(true), "%d", &a);
							mTimeSettings[settingType].mFogColour.set(r, g, b, a);
						} else if (cmds->isToken("dist")) {
							f32 near;
							sscanf(cmds->getToken(true), "%f", &near);
							f32 far;
							sscanf(cmds->getToken(true), "%f", &far);
							mTimeSettings[settingType].mFogNear = near;
							mTimeSettings[settingType].mFogFar  = far;
						}
					}
					if (!cmds->endOfCmds()) {
						cmds->getToken(true);
					}
				}
			}

			if (!cmds->endOfCmds()) {
				cmds->getToken(true);
			}
		} else {
			PRINT("got command %s\n", cmds->mCurrentToken);
		}
	}

	if (!cmds->endOfCmds()) {
		cmds->getToken(true);
	}
}

#pragma endregion
//////////////////////////////////////////////////////
