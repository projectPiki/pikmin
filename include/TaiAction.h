#ifndef _TAIACTION_H
#define _TAIACTION_H

#include "types.h"
#include "teki.h"

/**
 * .obj __vt__9TaiAction, weak
 * .4byte __RTTI__9TaiAction
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__9TaiActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

/**
 * @brief TODO
 */
struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual int act(Teki&);             // _10
	virtual int actByEvent(TekiEvent&); // _14
	virtual bool hasNextState();         // _18
};

#endif
