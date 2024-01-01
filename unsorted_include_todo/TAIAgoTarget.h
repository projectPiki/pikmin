#ifndef _TAIAGOTARGET_H
#define _TAIAGOTARGET_H

/**
 * .obj __vt__12TAIAgoTarget, global
 * .4byte __RTTI__12TAIAgoTarget
 * .4byte 0
 * .4byte start__12TAIAgoTargetFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__12TAIAgoTargetFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getVelocity__12TAIAgoTargetFR4Teki
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
struct TAIAgoTarget : public TaiAction {
	virtual void start(Teki &);        // _08
	virtual void act(Teki &);          // _10
	virtual void getVelocity(Teki &);  // _1C

};

#endif
