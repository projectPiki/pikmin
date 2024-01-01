#ifndef _TAIKINOKODISCHARGINGSPORESACTION_H
#define _TAIKINOKODISCHARGINGSPORESACTION_H

/**
 * .obj __vt__32TaiKinokoDischargingSporesAction, global
 * .4byte __RTTI__32TaiKinokoDischargingSporesAction
 * .4byte 0
 * .4byte start__32TaiKinokoDischargingSporesActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__32TaiKinokoDischargingSporesActionFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
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
struct TaiKinokoDischargingSporesAction : public TaiAction {
	virtual void start(Teki &);  // _08
	virtual void act(Teki &);    // _10

};

#endif
