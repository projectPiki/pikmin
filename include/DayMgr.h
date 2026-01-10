#ifndef _DAYMGR_H
#define _DAYMGR_H

#include "Light.h"
#include "types.h"

struct CmdStream;
struct Colour;
struct Controller;
struct Graphics;
struct MapMgr;
struct Menu;

/// Types/names of lights used in `TimeSetting`.
enum DayLightType {
	DAYLIGHT_Main  = 0, ///< 0, primary light ("main light").
	DAYLIGHT_Sub   = 1, ///< 1, secondary light ("sub light").
	DAYLIGHT_Plus1 = 2, ///< 2, first additional/optional light ("+1 light").
	DAYLIGHT_Plus2 = 3, ///< 3, second additional/optional light ("+2 light").
	DAYLIGHT_Plus3 = 4, ///< 4, third additional/optional light ("+3 light").
	DAYLIGHT_Plus4 = 5, ///< 5, fourth additional/optional light ("+4 light").
	DAYLIGHT_Plus5 = 6, ///< 6, fifth additional/optional light ("+5 light").
	DAYLIGHT_COUNT,     ///< 7, max number of lights in a light setting.

	DAYLIGHT_DefaultCount = DAYLIGHT_Sub + 1, ///< 2, default lights to use (main + sub).
};

/// Attachment/"move" type for lights used in `TimeSetting`.
enum DayLightMoveTypes {
	LIGHTMOVE_Global       = 0, ///< 0, position of light isn't tied to a local object.
	LIGHTMOVE_AttachToNavi = 1, ///< 1, position of light follows captain's movement.
	LIGHTMOVE_COUNT,            ///< 2, number of attachment/movement types.
};

/// Time setting types/presets to blend between.
enum TimeSettingType {
	TIME_Night   = 0, ///< 0, night lighting.
	TIME_Morning = 1, ///< 1, morning lighting.
	TIME_Day     = 2, ///< 2, day lighting (majority of the day)
	TIME_Evening = 3, ///< 3, evening lighting.
	TIME_Movie   = 4, ///< 4, special movie lighting.
	TIME_COUNT,       ///< 5, total number of time settings available.
};

/**
 * @brief Holds all lighting, fog and colour parameters for a specific time-of-day phase.
 *
 * Also includes a setting for "movie".
 *
 * @note Size: 0x13F8.
 */
struct TimeSetting {

	/// Constructs a new time setting, with all default parallel lights, colour, and fog settings.
	TimeSetting()
	{
		mLights[DAYLIGHT_Main].mDiffuseColour.set(255, 255, 255, 255);
		mLights[DAYLIGHT_Main].mPosition.set(0.0f, 470.0f, 0.0f);
		mLights[DAYLIGHT_Main].mDirection.set(0.0f, -1.0f, 0.0f);
		mLights[DAYLIGHT_Main].mDistancedRange = 450.0f;
		mLights[DAYLIGHT_Main].mSpotAngle      = 45.0f;
		mLights[DAYLIGHT_Main].mLightFlag      = LIGHT_Parallel;
		mLights[DAYLIGHT_Main].update();

		mLights[DAYLIGHT_Sub].mDiffuseColour.set(255, 255, 255, 255);
		mLights[DAYLIGHT_Sub].mPosition.set(-270.0f, -470.0f, 640.0f);
		mLights[DAYLIGHT_Sub].mDirection.set(0.0f, 1.0f, 0.0f);
		mLights[DAYLIGHT_Sub].mDistancedRange = 3300.0f;
		mLights[DAYLIGHT_Sub].mSpotAngle      = 45.0f;
		mLights[DAYLIGHT_Sub].mLightFlag      = LIGHT_Parallel;
		mLights[DAYLIGHT_Sub].update();

		mLights[DAYLIGHT_Plus1].mDiffuseColour.set(255, 255, 255, 255);
		mLights[DAYLIGHT_Plus1].mPosition.set(0.0f, 470.0f, 0.0f);
		mLights[DAYLIGHT_Plus1].mDirection.set(0.0f, -1.0f, 0.0f);
		mLights[DAYLIGHT_Plus1].mDistancedRange = 450.0f;
		mLights[DAYLIGHT_Plus1].mSpotAngle      = 45.0f;
		mLights[DAYLIGHT_Plus1].mLightFlag      = LIGHT_Parallel;
		mLights[DAYLIGHT_Plus1].update();

		mLights[DAYLIGHT_Plus2].mDiffuseColour.set(255, 255, 255, 255);
		mLights[DAYLIGHT_Plus2].mPosition.set(-270.0f, -470.0f, 640.0f);
		mLights[DAYLIGHT_Plus2].mDirection.set(0.0f, -1.0f, 0.0f);
		mLights[DAYLIGHT_Plus2].mDistancedRange = 3300.0f;
		mLights[DAYLIGHT_Plus2].mSpotAngle      = 45.0f;
		mLights[DAYLIGHT_Plus2].mLightFlag      = LIGHT_Parallel;
		mLights[DAYLIGHT_Plus2].update();

		mLights[DAYLIGHT_Plus3].mDiffuseColour.set(255, 255, 255, 255);
		mLights[DAYLIGHT_Plus3].mPosition.set(0.0f, 470.0f, 0.0f);
		mLights[DAYLIGHT_Plus3].mDirection.set(0.0f, -1.0f, 0.0f);
		mLights[DAYLIGHT_Plus3].mDistancedRange = 450.0f;
		mLights[DAYLIGHT_Plus3].mSpotAngle      = 45.0f;
		mLights[DAYLIGHT_Plus3].mLightFlag      = LIGHT_Parallel;
		mLights[DAYLIGHT_Plus3].update();

		mLights[DAYLIGHT_Plus4].mDiffuseColour.set(255, 255, 255, 255);
		mLights[DAYLIGHT_Plus4].mPosition.set(-270.0f, -470.0f, 640.0f);
		mLights[DAYLIGHT_Plus4].mDirection.set(0.0f, -1.0f, 0.0f);
		mLights[DAYLIGHT_Plus4].mDistancedRange = 3300.0f;
		mLights[DAYLIGHT_Plus4].mSpotAngle      = 45.0f;
		mLights[DAYLIGHT_Plus4].mLightFlag      = LIGHT_Parallel;
		mLights[DAYLIGHT_Plus4].update();

		mLights[DAYLIGHT_Plus5].mDiffuseColour.set(255, 255, 255, 255);
		mLights[DAYLIGHT_Plus5].mPosition.set(0.0f, 470.0f, 0.0f);
		mLights[DAYLIGHT_Plus5].mDirection.set(0.0f, -1.0f, 0.0f);
		mLights[DAYLIGHT_Plus5].mDistancedRange = 450.0f;
		mLights[DAYLIGHT_Plus5].mSpotAngle      = 45.0f;
		mLights[DAYLIGHT_Plus5].mLightFlag      = LIGHT_Parallel;
		mLights[DAYLIGHT_Plus5].update();

		mAmbientColour.set(48, 48, 48, 48); // very weak grey
		mFogColour.set(48, 48, 48, 48);     // very weak grey
		mFogNear = 1000.0f;
		mFogFar  = 30000.0f;
	}

	Light mLights[DAYLIGHT_COUNT];       ///< _0000, array of all possible lights to use for this phase - see `DayLightType` enum.
	int mLightMoveTypes[DAYLIGHT_COUNT]; ///< _13CC, movement/attachment types for each possible light - see `DayLightMoveTypes` enum.
	Colour mAmbientColour;               ///< _13E8, ambient colour for rendering.
	f32 mFogNear;                        ///< _13EC, fog start distance.
	f32 mFogFar;                         ///< _13F0, fog end distance.
	Colour mFogColour;                   ///< _13F4, fog colour.
};

/**
 * @brief Central manager for day/night cycle settings, including lighting, fog and blending.
 *
 * Also holds a debug menu for editing fog, lights, and time settings.
 *
 * @note Size: 0x1418.
 */
struct DayMgr {
	DayMgr(MapMgr* map, Controller* controller);

	void menuBIncrease(Menu& parent);
	void menuBDecrease(Menu& parent);
	void menuIncreaseLights(Menu& parent);
	void menuDecreaseLights(Menu& parent);
	void menuIncreaseTime(Menu& parent);
	void menuDecreaseTime(Menu& parent);
	void refresh(Graphics& gfx, f32 time, int numLights);
	void setFog(Graphics& gfx, Colour* fogColour);
	void menuDumpSettings(Menu& parent);
	void init(CmdStream* cmds);

	// unused/inlined:

	void updateComponent(Menu& parent, immut char* name, int* valuePtr);
	void updateLightCount(Menu& parent);
	void updateTime(Menu& parent);

	int mActiveLightCount;           ///< _0000, number of active lights, included in order - see `DayLightType` enum.
	int mMaxLightCount;              ///< _0004, maximum allowed lights, 7 by default - see `DayLightType` enum.
	TimeSetting mCurrentTimeSetting; ///< _0008, blended settings for current time-of-day lighting.
	TimeSetting* mTimeSettings;      ///< _1400, array of settings for each phase - see `TimeSettingType` enum.
	Menu* mDebugMenu;                ///< _1404, root of debug menu, for editing lighting/fog/time settings.
	Vector3f mCurrentSunPosition;    ///< _1408, current sun position.
	MapMgr* mMapMgr;                 ///< _1414, manager for current map/area.
};

#endif
