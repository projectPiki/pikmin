#ifndef _TAISTATE_H
#define _TAISTATE_H

/**
 * .obj __vt__8TaiState, global
 * .4byte __RTTI__8TaiState
 * .4byte 0
 * .4byte start__8TaiStateFR4Teki
 * .4byte finish__8TaiStateFR4Teki
 * .4byte act__8TaiStateFR4Teki
 * .4byte eventPerformed__8TaiStateFR9TekiEvent
*/

/**
 * @brief TODO
 */
struct TaiState {
	virtual void start(Teki &);                // _08
	virtual void finish(Teki &);               // _0C
	virtual void act(Teki &);                  // _10
	virtual void eventPerformed(TekiEvent &);  // _14

};

#endif
