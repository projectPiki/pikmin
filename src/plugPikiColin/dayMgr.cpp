#include "Menu.h"
#include "DayMgr.h"
#include "Graphics.h"
#include "sysNew.h"
#include "gameflow.h"
#include "MapMgr.h"
#include "NaviMgr.h"
#include "DebugLog.h"
#include "Controller.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
DEFINE_PRINT(nullptr) //! TODO: Why is the size not proper?

/**
 * @brief TODO
 */
struct PositionMenu : public Menu {
	void menuDecrease(Menu& menu)
	{
		if (!mIsSmallAdjustment) {
			*mComponentValue -= 10.0f;
			updateComponent(menu, mComponentName, mComponentValue);
		} else {
			*mComponentValue -= 0.01f;
			updateComponent(menu, mComponentName, mComponentValue);
		}
	}
	void menuIncrease(Menu& menu)
	{
		if (!mIsSmallAdjustment) {
			*mComponentValue += 10.0f;
			updateComponent(menu, mComponentName, mComponentValue);
		} else {
			*mComponentValue += 0.01f;
			updateComponent(menu, mComponentName, mComponentValue);
		}
	}

	void menuEnterX(Menu& menu)
	{
		mComponentValue = &mPosition->x;
		mComponentName  = "X";

		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterY(Menu& menu)
	{
		mComponentValue = &mPosition->y;
		mComponentName  = "Y";

		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterZ(Menu& menu)
	{
		mComponentValue = &mPosition->z;
		mComponentName  = "Z";

		updateComponent(menu, mComponentName, mComponentValue);
	}

	PositionMenu(Vector3f* pos, Controller* controller, Font* font, bool p4, bool smlAdjust)
	    : Menu(controller, font, p4)
	{
		mPosition          = pos;
		mIsSmallAdjustment = smlAdjust;
		mIsCustomMenu      = 1;
		mAnchorPoint.mMinX = glnWidth / 2;
		mAnchorPoint.mMinY = glnHeight / 2;
		mDiffuseColour.set(32, 128, 128, 192);
		mHighlightColour.set(32, 64, 32, 64);
		addKeyEvent(0x20, KBBTN_B, new Delegate1<Menu, Menu&>(this, &menuCloseMenu));

		char* str = new char[0x40];
		sprintf(str, "X = %.2f", mPosition->x);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<PositionMenu, Menu&>(this, &menuEnterX));
		addKeyEvent(4, KBBTN_Y, new Delegate1<PositionMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<PositionMenu, Menu&>(this, &menuIncrease));

		str = new char[0x40];
		sprintf(str, "Y = %.2f", mPosition->y);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<PositionMenu, Menu&>(this, &menuEnterY));
		addKeyEvent(4, KBBTN_Y, new Delegate1<PositionMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<PositionMenu, Menu&>(this, &menuIncrease));

		str = new char[0x40];
		sprintf(str, "Z = %.2f", mPosition->z);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<PositionMenu, Menu&>(this, &menuEnterZ));
		addKeyEvent(4, KBBTN_Y, new Delegate1<PositionMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<PositionMenu, Menu&>(this, &menuIncrease));
	}

	void updateComponent(Menu& menu, char* name, f32* valuePtr) { sprintf(menu.mCurrentItem->mName, "%s = %.2f", name, *valuePtr); }

	// _00     = VTBL
	// _00-_B4 = Menu
	Vector3f* mPosition;     // _B4
	bool mIsSmallAdjustment; // _B8
	f32* mComponentValue;    // _BC
	char* mComponentName;    // _C0
};

/**
 * @brief TODO
 */
struct ColourMenu : public Menu {
	void menuDecrease(Menu& menu)
	{
		if (*mComponentValue) {
			(*mComponentValue)--;
		}
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuIncrease(Menu& menu)
	{
		if (*mComponentValue < 255) {
			(*mComponentValue)++;
		}
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterR(Menu& menu)
	{
		mComponentValue = &mColour->r;
		mComponentName  = "R";
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterG(Menu& menu)
	{
		mComponentValue = &mColour->g;
		mComponentName  = "G";
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterB(Menu& menu)
	{
		mComponentValue = &mColour->b;
		mComponentName  = "B";
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterA(Menu& menu)
	{
		mComponentValue = &mColour->a;
		mComponentName  = "A";
		updateComponent(menu, mComponentName, mComponentValue);
	}

	ColourMenu(Colour* color, Controller* controller, Font* font, bool p4)
	    : Menu(controller, font, p4)
	{
		mColour            = color;
		mIsCustomMenu      = 1;
		mAnchorPoint.mMinX = glnWidth / 2;
		mAnchorPoint.mMinY = glnHeight / 2;
		mDiffuseColour.set(32, 128, 128, 192);
		mHighlightColour.set(32, 64, 32, 64);
		addKeyEvent(0x20, KBBTN_B, new Delegate1<Menu, Menu&>(this, &menuCloseMenu));

		char* str = new char[0x40];
		sprintf(str, "R = %d", mColour->r);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &menuEnterR));
		addKeyEvent(4, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &menuIncrease));

		str = new char[0x40];
		sprintf(str, "G = %d", mColour->g);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &menuEnterG));
		addKeyEvent(4, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &menuIncrease));

		str = new char[0x40];
		sprintf(str, "B = %d", mColour->b);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &menuEnterB));
		addKeyEvent(4, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &menuIncrease));

		str = new char[0x40];
		sprintf(str, "A = %d", mColour->a);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<ColourMenu, Menu&>(this, &menuEnterA));
		addKeyEvent(4, KBBTN_Y, new Delegate1<ColourMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<ColourMenu, Menu&>(this, &menuIncrease));
	}

	void updateComponent(Menu& menu, char* name, u8* valuePtr) { sprintf(menu.mCurrentItem->mName, "%s = %d", name, *valuePtr); }

	// _00     = VTBL
	// _00-_B4 = Menu
	Colour* mColour;      // _B4
	u8* mComponentValue;  // _B8, this is a pointer to the component value (R, G, B, A) of mColour
	char* mComponentName; // _BC, this is the component name ("R", "G", "B", "A")
};

/**
 * @brief TODO
 */
struct FogMenu : public Menu {
	void menuDecrease(Menu& menu)
	{
		*mComponentValue -= 10.0f;
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuIncrease(Menu& menu)
	{
		*mComponentValue += 10.0f;
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterNear(Menu& menu)
	{
		mComponentValue = mNear;
		mComponentName  = "Near";
		updateComponent(menu, mComponentName, mComponentValue);
	}
	void menuEnterFar(Menu& menu)
	{
		mComponentValue = mFar;
		mComponentName  = "Far";
		updateComponent(menu, mComponentName, mComponentValue);
	}

	FogMenu(Colour* color, f32* near, f32* far, Controller* controller, Font* font, bool p6)
	    : Menu(controller, font, p6)
	{
		mNear              = near;
		mFar               = far;
		mIsCustomMenu      = 1;
		mAnchorPoint.mMinX = glnWidth / 2;
		mAnchorPoint.mMinY = glnHeight / 2;
		mDiffuseColour.set(32, 128, 128, 192);
		mHighlightColour.set(32, 64, 32, 64);
		addKeyEvent(0x20, KBBTN_B, new Delegate1<Menu, Menu&>(this, &menuCloseMenu));

		addMenu(new ColourMenu(color, mController, gsys->mConsFont, true), 0, "fog colour");

		char* str = new char[0x40];
		sprintf(str, "Near = %.2f", *near);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<FogMenu, Menu&>(this, &menuEnterNear));
		addKeyEvent(4, KBBTN_Y, new Delegate1<FogMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<FogMenu, Menu&>(this, &menuIncrease));

		str = new char[0x40];
		sprintf(str, "Far = %.2f", *far);
		addOption(0, str, nullptr, true);
		addKeyEvent(1, KBBTN_NONE, new Delegate1<FogMenu, Menu&>(this, &menuEnterFar));
		addKeyEvent(4, KBBTN_Y, new Delegate1<FogMenu, Menu&>(this, &menuDecrease));
		addKeyEvent(4, KBBTN_X, new Delegate1<FogMenu, Menu&>(this, &menuIncrease));
	}

	void updateComponent(Menu& menu, char* name, f32* valuePtr) { sprintf(menu.mCurrentItem->mName, "%s = %.2f", name, *valuePtr); }

	// _00     = VTBL
	// _00-_B4 = Menu
	f32* mNear;           // _B4
	f32* mFar;            // _B8
	f32* mComponentValue; // _BC
	char* mComponentName; // _C0
};

static char* lightTypeNames[4] = { "OFF", "PARALLEL", "POINT", "SPOT" };
static int lightTypes[2]       = { 1, 3 };
static int lightConv[4]        = { 0, 0, 0, 1 };
static char* lightMoveNames[2] = { "global", "attach to navi" };

/**
 * @brief TODO
 */
struct LightMenu : public Menu {

	LightMenu(Light* light, int* attachType, Controller* controller, Font* font, bool p5)
	    : Menu(controller, font, p5)
	{
		mLight             = light;
		mSelectedLightType = 0;
		mLightAttachType   = attachType;
		mLight->mLightType = mLight->mLightType & 0xFFFFFF00 | lightTypes[mSelectedLightType];

		mAnchorPoint.mMinX = glnWidth / 2;
		mAnchorPoint.mMinY = glnHeight / 2;
		mDiffuseColour.set(32, 128, 128, 192);
		mHighlightColour.set(32, 64, 32, 64);
		addKeyEvent(0x20, KBBTN_B, new Delegate1<Menu, Menu&>(this, &menuCloseMenu));

		addOptions();
	}

	void menuDecrease(Menu& menu)
	{
		*mActiveValuePtr -= 1.0f;
		updateComponent(menu, mActiveValueName, mActiveValuePtr);
	}
	void menuIncrease(Menu& menu)
	{
		*mActiveValuePtr += 1.0f;
		updateComponent(menu, mActiveValueName, mActiveValuePtr);
	}
	void menuEnterNear(Menu& menu)
	{
		mActiveValuePtr  = mSpotFov;
		mActiveValueName = "Fov";
		updateComponent(menu, mActiveValueName, mActiveValuePtr);
	}
	void menuChangeType(Menu& menu)
	{
		mSelectedLightType = mSelectedLightType ^ 1;
		mLight->mLightType = mLight->mLightType & 0xFFFFFF00 | lightTypes[mSelectedLightType];
		resetOptions();
		addOptions();
		open(false);
	}
	void menuChangeMove(Menu& menu)
	{
		mLightAttachType[0] ^= 1;
		resetOptions();
		addOptions();
		open(false);
	}

	void addOptions()
	{
		mSelectedLightType = lightConv[(u8)mLight->mLightType];
		addOption(0, lightTypeNames[(u8)mLight->mLightType], new Delegate1<LightMenu, Menu&>(this, menuChangeType), true);
		addOption(0, nullptr, nullptr, true);
		if ((int)(u8)mLight->mLightType == 3) {
			mSpotFov = &mLight->mSpotAngle;
			addOption(0, lightMoveNames[mLightAttachType[0]], new Delegate1<LightMenu, Menu&>(this, menuChangeMove), true);

			char* str = new char[0x40];
			sprintf(str, "Fov = %.2f", *mSpotFov);
			addOption(0, str, nullptr, true);
			addKeyEvent(1, KBBTN_NONE, new Delegate1<LightMenu, Menu&>(this, menuEnterNear));
			addKeyEvent(4, KBBTN_Y, new Delegate1<LightMenu, Menu&>(this, menuDecrease));
			addKeyEvent(4, KBBTN_X, new Delegate1<LightMenu, Menu&>(this, menuIncrease));
		}

		if ((int)(u8)mLight->mLightType != 1) {
			addMenu(new PositionMenu(&mLight->mPosition, mController, gsys->mConsFont, true, false), 0, "position");
		}

		if ((int)(u8)mLight->mLightType == 3) {
			addMenu(new PositionMenu(&mLight->mDirection, mController, gsys->mConsFont, true, true), 0, "direction");
		}

		addMenu(new ColourMenu(&mLight->mDiffuseColour, mController, gsys->mConsFont, true), 0, "colour");
	}

	void updateComponent(Menu& menu, char* name, f32* valuePtr) { sprintf(menu.mCurrentItem->mName, "%s = %.2f", name, *valuePtr); }

	// _00     = VTBL
	// _00-_B4 = Menu
	int mSelectedLightType; //_B4, basically, is this a SPOT or a POINT light?
	int* mLightAttachType;  //_B8
	Light* mLight;          // _BC
	f32* mSpotFov;          // _C0
	f32* mActiveValuePtr;   // _C4
	char* mActiveValueName; // _C8
};

struct DaySetMenu : public Menu {
	DaySetMenu(TimeSetting* time, Controller* control, Font* font, bool flag)
	    : Menu(control, font, flag)
	{
		mTimeSettings      = time;
		mAnchorPoint.mMinX = glnWidth / 2;
		mAnchorPoint.mMinY = glnHeight / 2 + 60;
		mDiffuseColour.set(32, 128, 32, 192);
		mHighlightColour.set(32, 64, 32, 64);
		addKeyEvent(0x20, KBBTN_B, new Delegate1<Menu, Menu&>(this, &menuCloseMenu));
		addMenu(new ColourMenu(&mTimeSettings->mAmbientColour, mController, gsys->mConsFont, true), 0, "ambient colour");
		addMenu(
		    new FogMenu(&mTimeSettings->mFogColour, &mTimeSettings->mFogNear, &mTimeSettings->mFogFar, mController, gsys->mConsFont, true),
		    0, "fog");
		addOption(0, nullptr, nullptr, true);
		addMenu(new LightMenu(&mTimeSettings->mDayPhaseLights[0], &mTimeSettings->mAttachType[0], mController, gsys->mConsFont, true), 0,
		        "main light");
		addMenu(new LightMenu(&mTimeSettings->mDayPhaseLights[1], &mTimeSettings->mAttachType[1], mController, gsys->mConsFont, true), 0,
		        "sub light");
		addMenu(new LightMenu(&mTimeSettings->mDayPhaseLights[2], &mTimeSettings->mAttachType[2], mController, gsys->mConsFont, true), 0,
		        "+1 light");
		addMenu(new LightMenu(&mTimeSettings->mDayPhaseLights[3], &mTimeSettings->mAttachType[3], mController, gsys->mConsFont, true), 0,
		        "+2 light");
		addMenu(new LightMenu(&mTimeSettings->mDayPhaseLights[4], &mTimeSettings->mAttachType[4], mController, gsys->mConsFont, true), 0,
		        "+3 light");
		addMenu(new LightMenu(&mTimeSettings->mDayPhaseLights[5], &mTimeSettings->mAttachType[5], mController, gsys->mConsFont, true), 0,
		        "+4 light");
		addMenu(new LightMenu(&mTimeSettings->mDayPhaseLights[6], &mTimeSettings->mAttachType[6], mController, gsys->mConsFont, true), 0,
		        "+5 light");
	}

	// _00     = VTBL
	// _00-_B4 = Menu
	TimeSetting* mTimeSettings; // _B4
};

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void DayMgr::updateComponent(Menu& menu, char* name, int* valuePtr)
{
	sprintf(menu.mCurrentItem->mName, "%s = %d", name, *valuePtr);
}

/*
 * --INFO--
 * Address:	8006B3FC
 * Size:	00005C
 */
void DayMgr::menuBIncrease(Menu& menu)
{
	if (mMapMgr->mBlur < 255) {
		mMapMgr->mBlur++;
	}
	updateComponent(menu, "Blur", &mMapMgr->mBlur);
}

/*
 * --INFO--
 * Address:	8006B458
 * Size:	00005C
 */
void DayMgr::menuBDecrease(Menu& menu)
{
	if (mMapMgr->mBlur > 0) {
		mMapMgr->mBlur--;
	}
	updateComponent(menu, "Blur", &mMapMgr->mBlur);
}

/*
 * --INFO--
 * Address:	8006B4B4
 * Size:	001B80
 */
DayMgr::DayMgr(MapMgr* map, Controller* control)
{
	mMapMgr       = map;
	mLightCount   = 2;
	mMaxLights    = 7;
	mTimeSettings = new TimeSetting[5];

	mMenu                     = new Menu(control, gsys->mConsFont, false);
	mMenu->mIsCustomMenu      = 1;
	mMenu->mAnchorPoint.mMinX = glnWidth / 2;
	mMenu->mAnchorPoint.mMinY = glnHeight / 2 + 90;
	mMenu->mDiffuseColour.set(32, 128, 32, 192);
	mMenu->mHighlightColour.set(32, 64, 32, 64);
	mMenu->addKeyEvent(0x20, KBBTN_B, new Delegate1<Menu, Menu&>(mMenu, &Menu::menuCloseMenu));

	char* str = new char[0x40];
	sprintf(str, "Light Count %d", mLightCount);
	mMenu->addOption(0, str, nullptr, true);
	mMenu->addKeyEvent(8, KBBTN_Y, new Delegate1<DayMgr, Menu&>(this, &menuDecreaseLights));
	mMenu->addKeyEvent(8, KBBTN_X, new Delegate1<DayMgr, Menu&>(this, &menuIncreaseLights));

	str = new char[0x40];
	sprintf(str, "Time : % 2.1f", gameflow.mWorldClock.mTimeOfDay);
	mMenu->addOption(0, str, nullptr, true);
	mMenu->addKeyEvent(4, KBBTN_Y, new Delegate1<DayMgr, Menu&>(this, &menuDecreaseTime));
	mMenu->addKeyEvent(4, KBBTN_X, new Delegate1<DayMgr, Menu&>(this, &menuIncreaseTime));

	mMenu->addOption(0, nullptr, nullptr, true);
	mMenu->addOption(0, "Dump Settings", new Delegate1<DayMgr, Menu&>(this, &menuDumpSettings), true);
	mMenu->addOption(0, nullptr, nullptr, true);

	str = new char[0x40];
	sprintf(str, "morning : % 2.1f", gameflow.mParameters->mMorningMid());
	mMenu->addMenu(new DaySetMenu(&mTimeSettings[1], control, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "day     : % 2.1f -> % 2.1f", gameflow.mParameters->mMorningEnd(), gameflow.mParameters->mNightStart());
	mMenu->addMenu(new DaySetMenu(&mTimeSettings[2], control, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "evening : % 2.1f", gameflow.mParameters->mNightMid());
	mMenu->addMenu(new DaySetMenu(&mTimeSettings[3], control, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "night   : % 2.1f -> % 2.1f", gameflow.mParameters->mNightEnd(), gameflow.mParameters->mMorningStart());
	mMenu->addMenu(new DaySetMenu(&mTimeSettings[0], control, gsys->mConsFont, false), 0, str);
	str = new char[0x40];
	sprintf(str, "movie   : % 2.1f -> % 2.1f", 25.0f, 25.0f);
	mMenu->addMenu(new DaySetMenu(&mTimeSettings[4], control, gsys->mConsFont, false), 0, str);

	if (mMapMgr) {
		str = new char[0x40];
		sprintf(str, "Blur = %d", mMapMgr->mBlur);
		mMenu->addOption(0, str, nullptr, true);
		mMenu->addKeyEvent(4, KBBTN_Y, new Delegate1<DayMgr, Menu&>(this, &menuBDecrease));
		mMenu->addKeyEvent(4, KBBTN_X, new Delegate1<DayMgr, Menu&>(this, &menuBIncrease));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DayMgr::updateLightCount(Menu& menu)
{
	sprintf(menu.mCurrentItem->mName, "Light Count %d", mLightCount);
}

/*
 * --INFO--
 * Address:	8006E3A4
 * Size:	000058
 */
void DayMgr::menuIncreaseLights(Menu& menu)
{
	mLightCount++;
	if (mLightCount > mMaxLights) {
		mLightCount = mMaxLights;
	}

	updateLightCount(menu);
}

/*
 * --INFO--
 * Address:	8006E3FC
 * Size:	000058
 */
void DayMgr::menuDecreaseLights(Menu& menu)
{
	mLightCount--;
	if (mLightCount < 0) {
		mLightCount = 0;
	}

	updateLightCount(menu);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DayMgr::updateTime(Menu& menu)
{
	sprintf(menu.mCurrentItem->mName, "Time : % 2.1f", gameflow.mWorldClock.mTimeOfDay);
}

/*
 * --INFO--
 * Address:	8006E454
 * Size:	000084
 */
void DayMgr::menuIncreaseTime(Menu& menu)
{
	f32 time = gameflow.mWorldClock.mTimeOfDay + 0.05f;
	if (time > 23.99f) {
		time = 23.99f;
	}
	gameflow.mWorldClock.setTime(time);

	updateTime(menu);
}

/*
 * --INFO--
 * Address:	8006E4D8
 * Size:	000084
 */
void DayMgr::menuDecreaseTime(Menu& menu)
{
	f32 time = gameflow.mWorldClock.mTimeOfDay - 0.05f;
	if (time < 0.0f) {
		time = 0.0f;
	}
	gameflow.mWorldClock.setTime(time);

	updateTime(menu);
}

/*
 * --INFO--
 * Address:	8006E55C
 * Size:	000A38
 */
void DayMgr::refresh(Graphics& gfx, f32 time, int p2)
{
	int lights     = (p2 < mLightCount) ? p2 : mLightCount;
	f32 blendRatio = 0.0f;
	TimeSetting* timeSettingStart;
	TimeSetting* timeSettingEnd;
	if (time == 25.0f) {
		// movie?
		timeSettingStart = timeSettingEnd = &mTimeSettings[4];
		blendRatio                        = 0.0f;

	} else if (time < gameflow.mParameters->mMorningStart() || time >= gameflow.mParameters->mNightEnd()) {
		// night!
		timeSettingStart = timeSettingEnd = &mTimeSettings[0];
		blendRatio                        = 0.0f;

	} else if (time < gameflow.mParameters->mMorningMid()) {
		// early morning
		timeSettingStart = &mTimeSettings[0];
		timeSettingEnd   = &mTimeSettings[1];
		blendRatio       = (time - gameflow.mParameters->mMorningStart())
		           / (gameflow.mParameters->mMorningMid() - gameflow.mParameters->mMorningStart());

	} else if (time < gameflow.mParameters->mMorningEnd()) {
		// late morning
		timeSettingStart = &mTimeSettings[1];
		timeSettingEnd   = &mTimeSettings[2];
		blendRatio
		    = (time - gameflow.mParameters->mMorningMid()) / (gameflow.mParameters->mMorningEnd() - gameflow.mParameters->mMorningMid());

	} else if (time < gameflow.mParameters->mNightStart()) {
		// day
		timeSettingStart = timeSettingEnd = &mTimeSettings[2];
		blendRatio                        = 0.0f;

	} else if (time < gameflow.mParameters->mNightMid()) {
		// early evening
		timeSettingStart = &mTimeSettings[2];
		timeSettingEnd   = &mTimeSettings[3];
		blendRatio
		    = (time - gameflow.mParameters->mNightStart()) / (gameflow.mParameters->mNightMid() - gameflow.mParameters->mNightStart());

	} else if (time < gameflow.mParameters->mNightEnd()) {
		// late evening
		timeSettingStart = &mTimeSettings[3];
		timeSettingEnd   = &mTimeSettings[0];
		blendRatio = (time - gameflow.mParameters->mNightMid()) / (gameflow.mParameters->mNightEnd() - gameflow.mParameters->mNightMid());
	}

	timeSettingStart->mAmbientColour.lerpTo(timeSettingEnd->mAmbientColour, blendRatio, mCurrentTimeSetting.mAmbientColour);

	for (int i = 0; i < lights; i++) {
		timeSettingStart->mDayPhaseLights[i].mDiffuseColour.lerpTo(timeSettingEnd->mDayPhaseLights[i].mDiffuseColour, blendRatio,
		                                                           mCurrentTimeSetting.mDayPhaseLights[i].mDiffuseColour);
		mCurrentTimeSetting.mDayPhaseLights[i].mLightType = timeSettingStart->mDayPhaseLights[i].mLightType;
		mCurrentTimeSetting.mAttachType[i]                = timeSettingStart->mAttachType[i];
		mCurrentTimeSetting.mDayPhaseLights[i].mDistancedRange
		    = timeSettingStart->mDayPhaseLights[i].mDistancedRange
		    + (timeSettingEnd->mDayPhaseLights[i].mDistancedRange - timeSettingStart->mDayPhaseLights[i].mDistancedRange) * blendRatio;
		mCurrentTimeSetting.mDayPhaseLights[i].mSpotAngle
		    = timeSettingStart->mDayPhaseLights[i].mSpotAngle
		    + (timeSettingEnd->mDayPhaseLights[i].mSpotAngle - timeSettingStart->mDayPhaseLights[i].mSpotAngle) * blendRatio;

		timeSettingStart->mDayPhaseLights[i].mPosition.lerpTo(timeSettingEnd->mDayPhaseLights[i].mPosition, blendRatio,
		                                                      mCurrentTimeSetting.mDayPhaseLights[i].mPosition);
		timeSettingStart->mDayPhaseLights[i].mDirection.lerpTo(timeSettingEnd->mDayPhaseLights[i].mDirection, blendRatio,
		                                                       mCurrentTimeSetting.mDayPhaseLights[i].mDirection);
	}

	timeSettingStart->mFogColour.lerpTo(timeSettingEnd->mFogColour, blendRatio, mCurrentTimeSetting.mFogColour);
	mCurrentTimeSetting.mFogNear = timeSettingStart->mFogNear + (timeSettingEnd->mFogNear - timeSettingStart->mFogNear) * blendRatio;
	mCurrentTimeSetting.mFogFar  = timeSettingStart->mFogFar + (timeSettingEnd->mFogFar - timeSettingStart->mFogFar) * blendRatio;

	gfx.mAmbientFogColour = mCurrentTimeSetting.mAmbientColour;

	Matrix4f mtx;
	mtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(time / 24.0f * PI - HALF_PI, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
	mSunPosition.set(0.0f, 2500.0f, 0.0f);
	mSunPosition.multMatrix(mtx);
	f32 z            = mSunPosition.z;
	mSunPosition.z   = mSunPosition.x;
	mSunPosition.x   = -z;
	gfx.mSunPosition = mSunPosition;

	if (mMapMgr) {
		mMapMgr->_UNUSED08.set(mSunPosition.x / 20.0f, mSunPosition.y / 5.0f, mSunPosition.z / 20.0f);
	}

	for (int i = 0; i < lights; i++) {
		if (int(mCurrentTimeSetting.mDayPhaseLights[i].mLightType & 0xFF) == 1) {
			if (!(i & 1)) {
				mCurrentTimeSetting.mDayPhaseLights[i].mPosition.set(mSunPosition.x, mSunPosition.y, mSunPosition.z);
				mCurrentTimeSetting.mDayPhaseLights[i].mDirection.set(-mSunPosition.x, -mSunPosition.y, -mSunPosition.z);
				mCurrentTimeSetting.mDayPhaseLights[i].mDirection.normalise();
			} else {
				mCurrentTimeSetting.mDayPhaseLights[i].mPosition.set(-mSunPosition.x, -mSunPosition.y, -mSunPosition.z);
				mCurrentTimeSetting.mDayPhaseLights[i].mDirection.set(mSunPosition.x, mSunPosition.y, mSunPosition.z);
				mCurrentTimeSetting.mDayPhaseLights[i].mDirection.normalise();
			}
		} else if (mCurrentTimeSetting.mAttachType[i] == 1 && naviMgr && naviMgr->getNavi()) {
			Matrix4f mtx2;
			mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, naviMgr->getNavi()->mFaceDirection, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
			mCurrentTimeSetting.mDayPhaseLights[i].mDirection.rotate(mtx2);
			mCurrentTimeSetting.mDayPhaseLights[i].mPosition.rotate(mtx2);
			mCurrentTimeSetting.mDayPhaseLights[i].mPosition.add(naviMgr->getNavi()->mPosition);
		}
	}

	for (int i = 0; i < lights; i++) {
		mCurrentTimeSetting.mDayPhaseLights[i].update();
		gfx.addLight(&mCurrentTimeSetting.mDayPhaseLights[i]);
	}

	setFog(gfx, nullptr);
}

/*
 * --INFO--
 * Address:	8006EF94
 * Size:	000054
 */
void DayMgr::setFog(Graphics& gfx, Colour* color)
{
	gfx.setFog(true, color ? *color : mCurrentTimeSetting.mFogColour, 1.0f, mCurrentTimeSetting.mFogNear, mCurrentTimeSetting.mFogFar);
}

/*
 * --INFO--
 * Address:	8006EFE8
 * Size:	000084
 */
void DayMgr::menuDumpSettings(Menu&)
{
	static char* settingnames[5] = { "night", "morning", "day", "evening", "movie" };
	static char* lightnames[7]   = { "main light", "sub light", "+1", "+2", "+3", "+4", "+5" };

	int old            = gsys->mTogglePrint;
	gsys->mTogglePrint = 1;

	PRINT("\n------- cut here -----------------\n\n");
	PRINT("dayMgr {\n");
	PRINT("numsettings %d\n\n", 5);
	for (int i = 0; i < 5; i++) {
		PRINT("timesetting %d {\t// %s\n", i, settingnames[i]);
		for (int j = 0; j < mLightCount; j++) {
			PRINT("\tlight %d {\t// %s\n", j, lightnames[j]);
			PRINT("\t\ttype\t%d\n", mTimeSettings[i].mDayPhaseLights[j].mLightType);
			PRINT("\t\tattach\t%d\n", mTimeSettings[i].mAttachType[j]);
			u8 type = mTimeSettings[i].mDayPhaseLights[j].mLightType;
			if ((int)type == 3) {
				PRINT("\t\tfov\t%.1f\n", mTimeSettings[i].mDayPhaseLights[j].mSpotAngle);
			}
			if ((int)type != 1) {
				PRINT("\t\tposition\t%.2f %.2f %.2f\n", mTimeSettings[i].mDayPhaseLights[j].mPosition.x,
				      mTimeSettings[i].mDayPhaseLights[j].mPosition.y, mTimeSettings[i].mDayPhaseLights[j].mPosition.z);
			}
			if ((int)type == 3) {
				PRINT("\t\tdirection\t%.2f %.2f %.2f\n", mTimeSettings[i].mDayPhaseLights[j].mDirection.x,
				      mTimeSettings[i].mDayPhaseLights[j].mDirection.y, mTimeSettings[i].mDayPhaseLights[j].mDirection.z);
			}
			PRINT("\t\tcolour\t%d %d %d %d\n", mTimeSettings[i].mDayPhaseLights[j].mDiffuseColour.r,
			      mTimeSettings[i].mDayPhaseLights[j].mDiffuseColour.g, mTimeSettings[i].mDayPhaseLights[j].mDiffuseColour.b,
			      mTimeSettings[i].mDayPhaseLights[j].mDiffuseColour.a);
			PRINT("\t\t}\n");
		}
		PRINT("\tambient {\n");
		PRINT("\t\tcolour\t%d %d %d %d\n", mTimeSettings[i].mAmbientColour.r, mTimeSettings[i].mAmbientColour.g,
		      mTimeSettings[i].mAmbientColour.b, mTimeSettings[i].mAmbientColour.a);
		PRINT("\t\t}\n");

		PRINT("\tfog {\n");
		PRINT("\t\tcolour\t%d %d %d %d\n", mTimeSettings[i].mFogColour.r, mTimeSettings[i].mFogColour.g, mTimeSettings[i].mFogColour.b,
		      mTimeSettings[i].mFogColour.a);
		PRINT("\t\tdist\t%.2f %.2f\n", mTimeSettings[i].mFogNear, mTimeSettings[i].mFogFar);
		PRINT("\t\t}\n");
	}
	PRINT("\t}\n");
	PRINT("\n------- cut here -----------------\n");

	gsys->mTogglePrint = old;
}

/*
 * --INFO--
 * Address:	8006F06C
 * Size:	0008C0
 */
void DayMgr::init(CmdStream* stream)
{
	mLightCount = 0;
	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);
		if (stream->isToken("numsettings")) {
			stream->getToken(true);
			continue;
		}

		if (stream->isToken("timesetting")) {
			int settingType;
			sscanf(stream->getToken(true), "%d", &settingType);
			stream->getToken(true);

			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);

				if (stream->isToken("light")) {
					int lightNum;
					sscanf(stream->getToken(true), "%d", &lightNum);
					if (lightNum > mLightCount - 1) {
						mLightCount = lightNum + 1;
					}

					stream->getToken(true);

					while (!stream->endOfCmds() && !stream->endOfSection()) {
						stream->getToken(true);
						if (stream->isToken("type")) {
							u32 type;
							sscanf(stream->getToken(true), "%d", &type);
							mTimeSettings[settingType].mDayPhaseLights[lightNum].mLightType
							    = type | (mTimeSettings[settingType].mDayPhaseLights[lightNum].mLightType & ~0xFF);
							continue;
						}

						if (stream->isToken("attach")) {
							sscanf(stream->getToken(true), "%d", &mTimeSettings[settingType].mAttachType[lightNum]);
							continue;
						}

						if (stream->isToken("fov")) {
							sscanf(stream->getToken(true), "%f", &mTimeSettings[settingType].mDayPhaseLights[lightNum].mSpotAngle);
							continue;
						}

						if (stream->isToken("position")) {
							f32 x;
							sscanf(stream->getToken(true), "%f", &x);
							f32 y;
							sscanf(stream->getToken(true), "%f", &y);
							f32 z;
							sscanf(stream->getToken(true), "%f", &z);
							mTimeSettings[settingType].mDayPhaseLights[lightNum].mPosition.set(x, y, z);
							continue;
						}

						if (stream->isToken("direction")) {
							f32 x;
							sscanf(stream->getToken(true), "%f", &x);
							f32 y;
							sscanf(stream->getToken(true), "%f", &y);
							f32 z;
							sscanf(stream->getToken(true), "%f", &z);
							mTimeSettings[settingType].mDayPhaseLights[lightNum].mDirection.set(x, y, z);
							continue;
						}

						if (stream->isToken("colour")) {
							int r;
							sscanf(stream->getToken(true), "%d", &r);
							int g;
							sscanf(stream->getToken(true), "%d", &g);
							int b;
							sscanf(stream->getToken(true), "%d", &b);
							int a;
							sscanf(stream->getToken(true), "%d", &a);
							mTimeSettings[settingType].mDayPhaseLights[lightNum].mDiffuseColour.set(r, g, b, a);
							continue;
						}
					}

					if (!stream->endOfCmds()) {
						stream->getToken(true);
					}
				} else if (stream->isToken("ambient")) {
					stream->getToken(true);
					while (!stream->endOfCmds() && !stream->endOfSection()) {
						stream->getToken(true);
						if (stream->isToken("colour")) {
							int r;
							sscanf(stream->getToken(true), "%d", &r);
							int g;
							sscanf(stream->getToken(true), "%d", &g);
							int b;
							sscanf(stream->getToken(true), "%d", &b);
							int a;
							sscanf(stream->getToken(true), "%d", &a);
							mTimeSettings[settingType].mAmbientColour.set(r, g, b, a);
						}
					}
					if (!stream->endOfCmds()) {
						stream->getToken(true);
					}

				} else if (stream->isToken("specular")) {
					stream->getToken(true);
					while (!stream->endOfCmds() && !stream->endOfSection()) {
						stream->getToken(true);
						if (stream->isToken("colour")) {
							int r;
							sscanf(stream->getToken(true), "%d", &r);
							int g;
							sscanf(stream->getToken(true), "%d", &g);
							int b;
							sscanf(stream->getToken(true), "%d", &b);
							int a;
							sscanf(stream->getToken(true), "%d", &a);
							// nice.
						}
					}
					if (!stream->endOfCmds()) {
						stream->getToken(true);
					}

				} else if (stream->isToken("fog")) {
					stream->getToken(true);
					while (!stream->endOfCmds() && !stream->endOfSection()) {
						stream->getToken(true);
						if (stream->isToken("colour")) {
							int r;
							sscanf(stream->getToken(true), "%d", &r);
							int g;
							sscanf(stream->getToken(true), "%d", &g);
							int b;
							sscanf(stream->getToken(true), "%d", &b);
							int a;
							sscanf(stream->getToken(true), "%d", &a);
							mTimeSettings[settingType].mFogColour.set(r, g, b, a);
						} else if (stream->isToken("dist")) {
							f32 near;
							sscanf(stream->getToken(true), "%f", &near);
							f32 far;
							sscanf(stream->getToken(true), "%f", &far);
							mTimeSettings[settingType].mFogNear = near;
							mTimeSettings[settingType].mFogFar  = far;
						}
					}
					if (!stream->endOfCmds()) {
						stream->getToken(true);
					}
				}
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		} else {
			PRINT("got command %s\n", stream->mCurrentToken);
		}
	}

	if (!stream->endOfCmds()) {
		stream->getToken(true);
	}
}
