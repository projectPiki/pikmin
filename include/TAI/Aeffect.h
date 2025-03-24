#ifndef _TAI_AEFFECT_H
#define _TAI_AEFFECT_H

#include "types.h"
#include "TAI/Action.h"
#include "EffectMgr.h"

struct Vector3f;
struct CollPart;

/**
 * @brief TODO
 */
struct TAIAeffCloudOfDust : public TaiAction {
	TAIAeffCloudOfDust(int nextState, EffectMgr::effTypeTable p2, f32 p3, int p4, int p5, int p6, int p7, int p8)
	    : TaiAction(nextState)
	{
		init(p2, true, -1, RUMBLE_NONE, p3, p4, p5, p6, p7, p8);
	}

	// DLL inlines to do:
	TAIAeffCloudOfDust(int p1, EffectMgr::effTypeTable p2, int p3, f32 p4, int p5, int p6, int p7, int p8, int p9);
	TAIAeffCloudOfDust(int p1, EffectMgr::effTypeTable p2, int p3, int p4, f32 p5, int p6, int p7, int p8, int p9, int p10);

	virtual void start(Teki&);                 // _08
	virtual bool act(Teki&);                   // _10
	virtual void setType(Vector3f&, int, int); // _1C

	void init(EffectMgr::effTypeTable, bool, int, int, f32, int, int, int, int, int);
	void createCloudOfDust(Teki&, int);
	CollPart* getCollPart(Teki&, int);

	static const int RUMBLE_NONE;

	// _04     = VTBL
	// _00-_08 = TaiAction
	int* _08;                            // _08, array of something
	int _0C;                             // _0C
	f32 _10;                             // _10
	EffectMgr::effTypeTable mEffectType; // _14
	int _18;                             // _18
	int _1C;                             // _1C
	bool _20;                            // _20
};

#endif
