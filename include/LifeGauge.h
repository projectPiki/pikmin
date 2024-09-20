#ifndef _LIFEGAUGE_H
#define _LIFEGAUGE_H

#include "types.h"
#include "CoreNode.h"
#include "Vector.h"

struct Colour;
struct Graphics;
struct LFlareGroup;

/**
 * @brief TODO
 *
 * @note Size: 0x48.
 */
struct GaugeInfo : public CoreNode {
	GaugeInfo()
	    : CoreNode("")
	{
		_14 = 0;
	}

	void update();
	void showDigits(Vector3f, Colour&, int, f32, f32);
	void refresh(Graphics&);

	// unused/inlined:
	void init();

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 _14;             // _14, unknown
	u8 _18[0x10];        // _18, unknown
	Vector3f _28;        // _28
	u8 _34[0x48 - 0x34]; // _34, unknown
};

/**
 * @brief TODO
 */
struct LifeGaugeMgr {
	void init(int);
	void update();
	void refresh(Graphics&);
	void getGaugeInfo();
	void addLG(GaugeInfo*);
	void removeLG(GaugeInfo*);

	GaugeInfo _00;        // _00, probably? definitely CoreNode of some description
	GaugeInfo _48;        // _48, probably? definitely CoreNode of some description
	LFlareGroup* mLFlare; // _90
};

/**
 * @brief TODO
 */
struct LifeGauge {
	LifeGauge();

	void updValue(f32, f32);
	void adjustValue();
	void refresh(Graphics&);
	void countOn(Vector3f&, int, int);
	void countOff();

	// TODO: members
};

extern LifeGaugeMgr* lgMgr;

#endif