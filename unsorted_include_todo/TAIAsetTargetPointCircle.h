#ifndef _TAIASETTARGETPOINTCIRCLE_H
#define _TAIASETTARGETPOINTCIRCLE_H

/**
 * .obj __vt__24TAIAsetTargetPointCircle, global
 * .4byte __RTTI__24TAIAsetTargetPointCircle
 * .4byte 0
 * .4byte start__24TAIAsetTargetPointCircleFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__24TAIAsetTargetPointCircleFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TAIAsetTargetPointCircle : public TaiAction {
	virtual void start(Teki&); // _08
	virtual void act(Teki&);   // _10
};

#endif
