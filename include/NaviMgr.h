#ifndef _NAVIMGR_H
#define _NAVIMGR_H

#include "types.h"
#include "ObjectMgr.h"
#include "CreatureProp.h"
#include "Piki.h"
#include "Navi.h"

/**
 * @brief TODO
 *
 * @note Size: 0x43C.
 */
struct NaviProp : public CreatureProp {

	/**
	 * @brief Fabricated. Offsets relative to NaviProp for convenience.
	 */
	struct NaviParms : public Parameters {
		inline NaviParms()
		    : _5C(this, 120.0f, 0.0f, 500.0f, "p00", nullptr)
		    , _6C(this, 200.0f, 0.0f, 1000.0f, "p60", nullptr)
		    , _7C(this, 15.0f, 0.0f, 500.0f, "p62", nullptr)
		    , _8C(this, 100.0f, 0.0f, 500.0f, "p01", nullptr)
		    , _9C(this, 5.0f, 0.0f, 500.0f, "p53", nullptr)
		    , _AC(this, 0.2f, 0.0f, 500.0f, "p02", nullptr)
		    , _BC(this, 0.15f, 0.0f, 500.0f, "p03", nullptr)
		    , _CC(this, 170.0f, 0.0f, 500.0f, "p04", nullptr)
		    , _DC(this, 210.0f, 0.0f, 500.0f, "p56", nullptr)
		    , mDisplayScale(this, 1.0f, 0.0f, 10.0f, "p38", nullptr)
		    , _FC(this, 0.001f, 0.0f, 1.0f, "p05", nullptr)
		    , _10C(this, 0.1f, 0.0f, 1.0f, "p20", nullptr)
		    , _11C(this, 0.8f, 0.0f, 1.0f, "p06", nullptr)
		    , _12C(this, 1.0f, 0.0f, 1.0f, "p07", nullptr)
		    , _13C(this, 120.0f, 90.0f, 180.0f, "p08", nullptr)
		    , _14C(this, 2.5f, 0.0f, 10.0f, "p09", nullptr)
		    , _15C(this, 600.0f, 0.0f, 1000.0f, "p10", nullptr)
		    , _16C(this, 150.0f, 0.0f, 500.0f, "p11", nullptr)
		    , _17C(this, 100.0f, 0.0f, 1000.0f, "p24", nullptr)
		    , _18C(this, 80.0f, 0.0f, 1000.0f, "p25", nullptr)
		    , _19C(this, 200.0f, 0.0f, 1000.0f, "p54", nullptr)
		    , _1AC(this, 1.0f, 0.0f, 100.0f, "p26", nullptr)
		    , _1BC(this, 80.0f, 0.0f, 200.0f, "p37", nullptr)
		    , _1CC(this, 1, 0, 10, "p42", nullptr)
		    , _1DC(this, 30.0f, 0.0f, 200.0f, "p39", nullptr)
		    , _1EC(this, 60.0f, 0.0f, 200.0f, "p40", nullptr)
		    , _1FC(this, 15.0f, 0.0f, 100.0f, "p21", nullptr)
		    , _20C(this, 16.0f, 0.0f, 100.0f, "p41", nullptr)
		    , _21C(this, 4.0f, 0.0f, 2000.0f, "p22", nullptr)
		    , _22C(this, 0.04f, 0.0f, 1.0f, "p23", nullptr)
		    , _23C(this, 5.0f, 0.0f, 500.0f, "p14", nullptr)
		    , _24C(this, 35.0f, 0.0f, 500.0f, "p15", nullptr)
		    , _25C(this, 70.0f, 0.0f, 500.0f, "p16", nullptr)
		    , _26C(this, 160.0f, 0.0f, 500.0f, "p17", nullptr)
		    , _27C(this, 30.0f, 0.0f, 300.0f, "p18", nullptr)
		    , _28C(this, 60.0f, 0.0f, 300.0f, "p19", nullptr)
		    , _29C(this, 30.0f, 0.0f, 300.0f, "p27", nullptr)
		    , _2AC(this, 60.0f, 0.0f, 300.0f, "p28", nullptr)
		    , _2BC(this, 30.0f, 0.0f, 300.0f, "p29", nullptr)
		    , _2CC(this, 60.0f, 0.0f, 300.0f, "p30", nullptr)
		    , _2DC(this, 3.0f, 0.0f, 10.0f, "p31", nullptr)
		    , _2EC(this, 1.0f, 0.0f, 10.0f, "p32", nullptr)
		    , _2FC(this, 0.5f, 0.0f, 10.0f, "p33", nullptr)
		    , _30C(this, 0.3f, 0.0f, 1.0f, "p34", nullptr)
		    , _31C(this, 10.0f, 0.0f, 180.0f, "p35", nullptr)
		    , _32C(this, 0.1f, 0.0f, 1.0f, "p36", nullptr)
		    , _33C(this, 2.0f, 0.0f, 60.0f, "p48", nullptr)
		    , _34C(this, 8.0f, 0.0f, 60.0f, "p49", nullptr)
		    , _35C(this, 0.1f, 0.0f, 1.0f, "p43", nullptr)
		    , _36C(this, 0.75f, 0.0f, 1.0f, "p44", nullptr)
		    , _37C(this, 0.85f, 0.0f, 1.0f, "p48", nullptr)
		    , _38C(this, 50.0f, 0.0f, 1000.0f, "p45", nullptr)
		    , _39C(this, 300.0f, 0.0f, 2000.0f, "p46", nullptr)
		    , _3AC(this, 200.0f, 0.0f, 1000.0f, "p47", nullptr)
		    , mHealth(this, 100.0f, 0.0f, 1000.0f, "p50", nullptr)
		    , _3CC(this, 1.0f, 0.0f, 1000.0f, "p51", nullptr)
		    , _3DC(this, 10.0f, 0.0f, 100.0f, "p52", nullptr)
		    , _3EC(this, 1, 0, 10, "p55", nullptr)
		    , mMinKinokoFlickActions(this, 4, 0, 16, "p57", nullptr)
		    , _40C(this, 3, 0, 16, "p58", nullptr)
		    , _41C(this, 3, 0, 16, "p59", nullptr)
		    , _42C(this, 100, 0, 1000, "p61", nullptr)
		{
		}

		// _58-_5C = Parameters
		Parm<f32> _5C;                    // _5C, p00, action radius?
		Parm<f32> _6C;                    // _6C, p60, continuous withdrawal distance?
		Parm<f32> _7C;                    // _7C, p62, extraction distance (outside onyon)?
		Parm<f32> _8C;                    // _8C, p01, max whistle radius?
		Parm<f32> _9C;                    // _9C, p53, min whistle radius?
		Parm<f32> _AC;                    // _AC, p02, whistle transition timer?
		Parm<f32> _BC;                    // _BC, p03, whistle holding timer?
		Parm<f32> _CC;                    // _CC, p04, speed?
		Parm<f32> _DC;                    // _DC, p56, running speed (good condition)?
		Parm<f32> mDisplayScale;          // _EC, p38, Olimar size
		Parm<f32> _FC;                    // _FC, p05, stick 0?
		Parm<f32> _10C;                   // _10C, p20, stick 01?
		Parm<f32> _11C;                   // _11C, p06, stick 1?
		Parm<f32> _12C;                   // _12C, p07, stick 2?
		Parm<f32> _13C;                   // _13C, p08, slip angle?
		Parm<f32> _14C;                   // _14C, p09, limit time for throwing?
		Parm<f32> _15C;                   // _15C, p10, throwing dist (max)?
		Parm<f32> _16C;                   // _16C, p11, throwing dist (min)?
		Parm<f32> _17C;                   // _17C, p24, throwing height (max)?
		Parm<f32> _18C;                   // _18C, p25, throwing height (min)?
		Parm<f32> _19C;                   // _19C, p54, throwing height (yellow)?
		Parm<f32> _1AC;                   // _1AC, p26, landing time?
		Parm<f32> _1BC;                   // _1BC, p37, eff range to grasp piki?
		Parm<int> _1CC;                   // _1CC, p42, num loops pulled out?
		Parm<f32> _1DC;                   // _1DC, p39, range where piki waits?
		Parm<f32> _1EC;                   // _1EC, p40, range where piki change formation?
		Parm<f32> _1FC;                   // _1FC, p21, per size?
		Parm<f32> _20C;                   // _20C, p41, ground per size?
		Parm<f32> _21C;                   // _21C, p22, recip of weight?
		Parm<f32> _22C;                   // _22C, p23, aiming rotation speed?
		Parm<f32> _23C;                   // _23C, p14, asibumi start speed?
		Parm<f32> _24C;                   // _24C, p15, walk start speed?
		Parm<f32> _25C;                   // _25C, p16, run start speed?
		Parm<f32> _26C;                   // _26C, p17, escape start speed?
		Parm<f32> _27C;                   // _27C, p18, walk frames (min)?
		Parm<f32> _28C;                   // _28C, p19, walk frames (max)?
		Parm<f32> _29C;                   // _29C, p27, run frames (min)?
		Parm<f32> _2AC;                   // _2AC, p28, run frames (max)?
		Parm<f32> _2BC;                   // _2BC, p29, escape frames (min)?
		Parm<f32> _2CC;                   // _2CC, p30, escape frames (max)?
		Parm<f32> _2DC;                   // _2DC, p31, collapse total time?
		Parm<f32> _2EC;                   // _2EC, p32, completely flat time?
		Parm<f32> _2FC;                   // _2FC, p33, push start time?
		Parm<f32> _30C;                   // _30C, p34, push start stick amount?
		Parm<f32> _31C;                   // _31C, p35, shake prevention angle?
		Parm<f32> _32C;                   // _32C, p36, anti-shake size?
		Parm<f32> _33C;                   // _33C, p48, cursor moving stick?
		Parm<f32> _34C;                   // _34C, p49, time for piki to get numb?
		Parm<f32> _35C;                   // _35C, p43, neutral stick?
		Parm<f32> _36C;                   // _36C, p44, cursor moving stick?
		Parm<f32> _37C;                   // _37C, p48, clamp stick?
		Parm<f32> _38C;                   // _38C, p45, cursor movement min radius?
		Parm<f32> _39C;                   // _39C, p46, cursor movement max radius?
		Parm<f32> _3AC;                   // _3AC, p47, cursor movement speed?
		Parm<f32> mHealth;                // _3BC, p50, Olimar's health
		Parm<f32> _3CC;                   // _3CC, p51, punch damage?
		Parm<f32> _3DC;                   // _3DC, p52, punch radius?
		Parm<int> _3EC;                   // _3EC, p55, cursor count?
		Parm<int> mMinKinokoFlickActions; // _3FC, p57, need to put in (this + 1) "actions" to flick a puffmin
		Parm<int> _40C;                   // _40C, p58, bury key count?
		Parm<int> _41C;                   // _41C, p59, bury exit count?
		Parm<int> _42C;                   // _42C, p61, focus camera zoom out (frames)
	};

	NaviProp();

	virtual void read(RandomAccessStream&); // _08 (weak)

	// _54     = VTBL
	// _00-_58 = CreatureProp
	NaviParms mNaviProps; // _58
};

/**
 * @brief TODO
 */
struct NaviMgr : public MonoObjectMgr {
	NaviMgr();

	virtual ~NaviMgr() { }                  // _48
	virtual void update();                  // _4C
	virtual Navi* createObject();           // _80
	virtual void read(RandomAccessStream&); // _84

	Navi* getNavi();
	Navi* getNavi(int);
	void refresh2d(Graphics&);
	void renderCircle(Graphics&);
	void drawShadow(Graphics&);

	// unused/inlined:
	void init();

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	u8 _3C[0x4];                          // _3C, unknown
	Shape* mNaviShape;                    // _40
	u8 _44[0x4];                          // _44, unknown
	PikiShapeObject* mNaviShapeObject[2]; // _48
	PaniMotionTable* mMotionTable;        // _50
	int mNaviID;                          // _54
	NaviProp* mNaviParms;                 // _58
};

extern NaviMgr* naviMgr;

#endif
