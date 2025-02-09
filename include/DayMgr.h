#ifndef _DAYMGR_H
#define _DAYMGR_H

#include "types.h"
#include "Light.h"

struct CmdStream;
struct Colour;
struct Controller;
struct Graphics;
struct MapMgr;
struct Menu;

/**
 * @brief TODO
 *
 * @note Size: 0x13F8.
 */
struct TimeSetting {
	TimeSetting()
	{
		mDayPhaseLights[0].mDiffuseColour.set(255, 255, 255, 255);
		mDayPhaseLights[0].mPosition.set(0.0f, 470.0f, 0.0f);
		mDayPhaseLights[0].mDirection.set(0.0f, -1.0f, 0.0f);
		mDayPhaseLights[0].mDistancedRange = 450.0f;
		mDayPhaseLights[0].mSpotAngle      = 45.0f;
		mDayPhaseLights[0].mLightType      = 1;
		mDayPhaseLights[0].update();

		mDayPhaseLights[1].mDiffuseColour.set(255, 255, 255, 255);
		mDayPhaseLights[1].mPosition.set(-270.0f, -470.0f, 640.0f);
		mDayPhaseLights[1].mDirection.set(0.0f, 1.0f, 0.0f);
		mDayPhaseLights[1].mDistancedRange = 3300.0f;
		mDayPhaseLights[1].mSpotAngle      = 45.0f;
		mDayPhaseLights[1].mLightType      = 1;
		mDayPhaseLights[1].update();

		mDayPhaseLights[2].mDiffuseColour.set(255, 255, 255, 255);
		mDayPhaseLights[2].mPosition.set(0.0f, 470.0f, 0.0f);
		mDayPhaseLights[2].mDirection.set(0.0f, -1.0f, 0.0f);
		mDayPhaseLights[2].mDistancedRange = 450.0f;
		mDayPhaseLights[2].mSpotAngle      = 45.0f;
		mDayPhaseLights[2].mLightType      = 1;
		mDayPhaseLights[2].update();

		mDayPhaseLights[3].mDiffuseColour.set(255, 255, 255, 255);
		mDayPhaseLights[3].mPosition.set(-270.0f, -470.0f, 640.0f);
		mDayPhaseLights[3].mDirection.set(0.0f, -1.0f, 0.0f);
		mDayPhaseLights[3].mDistancedRange = 3300.0f;
		mDayPhaseLights[3].mSpotAngle      = 45.0f;
		mDayPhaseLights[3].mLightType      = 1;
		mDayPhaseLights[3].update();

		mDayPhaseLights[4].mDiffuseColour.set(255, 255, 255, 255);
		mDayPhaseLights[4].mPosition.set(0.0f, 470.0f, 0.0f);
		mDayPhaseLights[4].mDirection.set(0.0f, -1.0f, 0.0f);
		mDayPhaseLights[4].mDistancedRange = 450.0f;
		mDayPhaseLights[4].mSpotAngle      = 45.0f;
		mDayPhaseLights[4].mLightType      = 1;
		mDayPhaseLights[4].update();

		mDayPhaseLights[5].mDiffuseColour.set(255, 255, 255, 255);
		mDayPhaseLights[5].mPosition.set(-270.0f, -470.0f, 640.0f);
		mDayPhaseLights[5].mDirection.set(0.0f, -1.0f, 0.0f);
		mDayPhaseLights[5].mDistancedRange = 3300.0f;
		mDayPhaseLights[5].mSpotAngle      = 45.0f;
		mDayPhaseLights[5].mLightType      = 1;
		mDayPhaseLights[5].update();

		mDayPhaseLights[6].mDiffuseColour.set(255, 255, 255, 255);
		mDayPhaseLights[6].mPosition.set(0.0f, 470.0f, 0.0f);
		mDayPhaseLights[6].mDirection.set(0.0f, -1.0f, 0.0f);
		mDayPhaseLights[6].mDistancedRange = 450.0f;
		mDayPhaseLights[6].mSpotAngle      = 45.0f;
		mDayPhaseLights[6].mLightType      = 1;
		mDayPhaseLights[6].update();

		_13E8.set(48, 48, 48, 48);
		_13F4.set(48, 48, 48, 48);
		_13EC = 1000.0f;
		_13F0 = 30000.0f;
	}

	Light mDayPhaseLights[7]; // _00
	int _13CC[7];             // _13CC
	Colour _13E8;             // _13E8, probably
	f32 _13EC;                // _13EC
	f32 _13F0;                // _13F0
	Colour _13F4;             // _13F4, probably
};

/**
 * @brief TODO
 *
 * @note Size: 0x1418.
 */
struct DayMgr {
	DayMgr(MapMgr*, Controller*);

	void menuBIncrease(Menu&);
	void menuBDecrease(Menu&);
	void menuIncreaseLights(Menu&);
	void menuDecreaseLights(Menu&);
	void menuIncreaseTime(Menu&);
	void menuDecreaseTime(Menu&);
	void refresh(Graphics&, f32, int);
	void setFog(Graphics&, Colour*);
	void menuDumpSettings(Menu&);
	void init(CmdStream*);

	// unused/inlined:
	void updateComponent(Menu&, char*, int*);
	void updateLightCount(Menu&);
	void updateTime(Menu&);

	int mLightCount;                 // _00
	int mMaxLights;                  // _04
	TimeSetting mCurrentTimeSetting; // _08
	TimeSetting* mTimeSettings;      // _1400
	Menu* mMenu;                     // _1404
	Vector3f mSunPosition;           // _1408
	MapMgr* mMapMgr;                 // _1414
};

#endif
