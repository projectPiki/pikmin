#ifndef _DAYMGR_H
#define _DAYMGR_H

#include "types.h"

struct CmdStream;
struct Colour;
struct Controller;
struct Graphics;
struct MapMgr;
struct Menu;

/**
 * @brief TODO
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

	// TODO: members
};

/**
 * @brief TODO
 */
struct TimeSetting {
	TimeSetting();

	// TODO: members
};

#endif
