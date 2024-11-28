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
	NaviProp();

	virtual void read(RandomAccessStream&); // _08 (weak)

	// _54     = VTBL
	// _00-_58 = CreatureProp
	u8 _58[0x43C - 0x58]; // _58, unknown
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
	u8 _3C[0x4];                       // _3C, unknown
	Shape* mNaviShape;                 // _40
	u8 _44[0x4];                       // _44, unknown
	PikiShapeObject* mNaviShapeObject; // _48
	u8 _4C[0x4];                       // _4C, unknown
	PaniMotionTable* mMotionTable;     // _50
	int mNaviID;                       // _54
	NaviProp* mNaviParms;              // _58
};

extern NaviMgr* naviMgr;

#endif
