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
	TimeSetting();

	Light mDayPhaseLights[7];  // _00
	u8 _13CC[0x13E8 - 0x13CC]; // _13CC, unknown
	Colour _13E8;              // _13E8, probably
	f32 _13EC;                 // _13EC
	f32 _13F0;                 // _13F0
	Colour _13F4;              // _13F4, probably
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

	int _00;                         // _00
	int _04;                         // _04
	TimeSetting mCurrentTimeSetting; // _08
	TimeSetting* mTimeSettings;      // _1400
	Menu* _1404;                     // _1404
	Vector3f _1408;                  // _1408
	MapMgr* mMapMgr;                 // _1414
};

#endif
