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
	PikiProp() { mCreatureProps.mFriction.setValue(0.1f); }

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
 *
 * @note Size: 0x74.
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

	static u8 meNukiMode;
	static u8 meBirthMode;

	// unused/inlined:
	void getFormationPikis();
	void lostAllPikis();
	void refresh2d(Graphics&);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	Shape* mLeafModel;             // _3C
	Shape* mBudModel;              // _40
	Shape* mFlowerModel;           // _44
	Shape* mPikiShape;             // _48
	MapMgr* mMapMgr;               // _4C
	u32 _50;                       // _50
	u32 _54;                       // _54
	u32 _58;                       // _58
	u32 _5C;                       // _5C
	u32 _60;                       // _60
	PaniMotionTable* mMotionTable; // _64
	PikiProp* mPikiParms;          // _68
	Navi* mNavi;                   // _6C
	s16 _70;                       // _70
	s16 _72;                       // _72
};

extern PikiMgr* pikiMgr;

inline PikiProp* Piki::getPikiProp() { return static_cast<PikiProp*>(mProps); }

#endif
