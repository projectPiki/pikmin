#ifndef _NAVIMGR_H
#define _NAVIMGR_H

#include "types.h"
#include "ObjectMgr.h"
#include "CreatureProp.h"
#include "Navi.h"

/**
 * @brief TODO
 */
struct NaviProp : public CreatureProp {
	NaviProp();

	virtual void read(RandomAccessStream&); // _08 (weak)

	// _F8     = VTBL
	// _00-_FC = CreatureProp
	// TODO: work out members
};

/**
 * @brief TODO
 */
struct NaviMgr : public MonoObjectMgr {
	NaviMgr();

	virtual ~NaviMgr();                     // _48
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
	// _00-_?? = MonoObjectMgr
	// TODO: members
};

#endif
