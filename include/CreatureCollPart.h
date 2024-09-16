#ifndef _CREATURECOLLPART_H
#define _CREATURECOLLPART_H

#include "types.h"
#include "DynColl.h"

struct CollPart;

/**
 * @brief TODO
 */
struct CreatureCollPart : public DynCollShape {
	CreatureCollPart() // TODO: fix this, it's implicit but required/this is just a guess
	    : DynCollShape(nullptr)
	{
	}

	virtual void update();                                    // _10 (weak)
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void refresh(Graphics&);                          // _44 (weak)

	// _00     = VTBL
	// _00-_?? = DynCollShape
	// TODO: members
};

/*
 * @brief TODO
 */
struct CreaturePlatMgr {
	void init(Creature*, MapMgr*, Shape*);
	void release();
	void update(Graphics&);

	// TODO: members
	Shape* _00;        // _00
	CollPart* _04[16]; // _04
	u32 _44;           // _44, count of something?
};

#endif
