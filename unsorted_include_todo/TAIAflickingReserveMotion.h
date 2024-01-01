#ifndef _TAIAFLICKINGRESERVEMOTION_H
#define _TAIAFLICKINGRESERVEMOTION_H

/**
 * .obj __vt__25TAIAflickingReserveMotion, global
 * .4byte __RTTI__25TAIAflickingReserveMotion
 * .4byte 0
 * .4byte start__25TAIAflickingReserveMotionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__25TAIAflickingReserveMotionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte flick__25TAIAflickingReserveMotionFR4Teki
 * .4byte getFlickDirection__25TAIAflickingReserveMotionFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAflickingReserveMotion : public TaiAction {
	virtual void start(Teki &);              // _08
	virtual void act(Teki &);                // _10
	virtual void flick(Teki &);              // _1C
	virtual void getFlickDirection(Teki &);  // _20

};

#endif
