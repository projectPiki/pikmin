#ifndef _PIKIMGR_H
#define _PIKIMGR_H

#include "types.h"
#include "ObjectMgr.h"
#include "CreatureProp.h"
#include "ViewPiki.h"

struct Navi;

/**
 * @brief TODO
 */
struct PikiProp : public CreatureProp {
	PikiProp() { mCreatureProps.mFriction.mValue = 0.1f; }

	/**
	 * @brief TODO
	 *
	 * @note Offsets are relative to PikiProp for convenience.
	 */
	struct Parms : public Parameters {
		Parms();

		// _58-_5C = Parameters
		// TODO: members
	};

	virtual void read(RandomAccessStream&); // _08

	// _54     = VTBL
	// _00-_58 = CreatureProp
	Parms mPikiParms; // _58
};

/**
 * @brief TODO
 */
struct PikiMgr : public MonoObjectMgr {
	PikiMgr(Navi*);

	virtual ~PikiMgr();                     // _48
	virtual void update();                  // _4C
	virtual void refresh(Graphics&);        // _58
	virtual Creature* birth();              // _78
	virtual ViewPiki* createObject();       // _80
	virtual void read(RandomAccessStream&); // _84

	void init();
	void dumpAll();

	// unused/inlined:
	void getFormationPikis();
	void lostAllPikis();
	void refresh2d(Graphics&);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = MonoObjectMgr?
	u8 _28[0x68 - sizeof(MonoObjectMgr)]; // _28, update/remove once size of MonoObjectMgr is known
	PikiProp* mParms;                     // _68
	Navi* mNavi;                          // _6C
	                                      // TODO: members
};

#endif
