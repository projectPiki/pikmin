#ifndef _SUCKABLE_H
#define _SUCKABLE_H

#include "types.h"
#include "ItemMgr.h"

/**
 * @brief TODO
 *
 * @note Size: 0x3C8.
 */
struct Suckable : public ItemCreature {
	inline Suckable(u16 id, CreatureProp* prop)
	    : ItemCreature(id, prop, nullptr)
	{
	}

	virtual Vector3f getGoalPos()  = 0;  // _15C
	virtual f32 getGoalPosRadius() = 0;  // _160
	virtual Vector3f getSuckPos()  = 0;  // _164
	virtual void suckMe(Pellet*)   = 0;  // _168
	virtual void finishSuck(Pellet*) { } // _16C (weak)
	virtual int getRouteIndex() = 0;     // _170

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
};

#endif
