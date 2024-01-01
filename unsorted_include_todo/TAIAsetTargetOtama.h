#ifndef _TAIASETTARGETOTAMA_H
#define _TAIASETTARGETOTAMA_H

/**
 * .obj __vt__18TAIAsetTargetOtama, weak
 * .4byte __RTTI__18TAIAsetTargetOtama
 * .4byte 0
 * .4byte start__30TAIAsetTargetPointCircleRandomFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__18TAIAsetTargetOtamaFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
*/

struct TAIAsetTargetPointCircleRandom {
	virtual void start(Teki &);  // _08
};

struct TaiAction {
	virtual void _08() = 0;                // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAsetTargetOtama : public TAIAsetTargetPointCircleRandom, public TaiAction {
	virtual void act(Teki &);  // _10

};

#endif
