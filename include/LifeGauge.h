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
	u32 _14;      // _14
	u32 _18;      // _18
	u32 _1C;      // _1C
	u32 _20;      // _20
	int _24;      // _24
	Vector3f _28; // _28
	f32 _34;      // _34
	f32 _38;      // _38
	f32 _3C;      // _3C
	f32 _40;      // _40
	f32 _44;      // _44
};

/**
 * @brief TODO
 */
struct LifeGaugeMgr {
	void init(int);
	void update();
	void refresh(Graphics&);
	GaugeInfo* getGaugeInfo();
	void addLG(GaugeInfo*);
	void removeLG(GaugeInfo*);

	GaugeInfo _00;        // _00
	GaugeInfo _48;        // _48
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

	Vector3f mPosition; // _00
	Vector3f mOffset;   // _0C
	u32 mIsNotFull;     // _18, unknown
	int _1C;            // _1C
	u8 _20;             // _20
	f32 _24;            // _24
	f32 _28;            // _28
	f32 mHealthRatio;   // _2C, aka "value"
	f32 _30;            // _30
	f32 mScale;         // _34
	u32 _38;            // _38, unknown
};

extern LifeGaugeMgr* lgMgr;

#endif
