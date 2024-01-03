#ifndef _TAIABITEFORKABEKUI_H
#define _TAIABITEFORKABEKUI_H

/**
 * .obj __vt__18TAIAbiteForKabekui, global
 * .4byte __RTTI__18TAIAbiteForKabekui
 * .4byte 0
 * .4byte start__18TAIAbiteForKabekuiFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__18TAIAbiteForKabekuiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPikiAttackSize__18TAIAbiteForKabekuiFR4Teki
 * .4byte getNaviAttackSize__18TAIAbiteForKabekuiFR4Teki
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
struct TAIAbiteForKabekui : public TaiAction {
	virtual void start(Teki &);              // _08
	virtual void act(Teki &);                // _10
	virtual void getPikiAttackSize(Teki &);  // _1C
	virtual void getNaviAttackSize(Teki &);  // _20

};

#endif
