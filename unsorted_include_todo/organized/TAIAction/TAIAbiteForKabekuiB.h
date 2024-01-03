#ifndef _TAIABITEFORKABEKUIB_H
#define _TAIABITEFORKABEKUIB_H

/**
 * .obj __vt__19TAIAbiteForKabekuiB, weak
 * .4byte __RTTI__19TAIAbiteForKabekuiB
 * .4byte 0
 * .4byte start__18TAIAbiteForKabekuiFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__18TAIAbiteForKabekuiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPikiAttackSize__19TAIAbiteForKabekuiBFR4Teki
 * .4byte getNaviAttackSize__19TAIAbiteForKabekuiBFR4Teki
*/

struct TAIAbiteForKabekui {
	virtual void start(Teki &);  // _08
	virtual void _0C() = 0;      // _0C
	virtual void act(Teki &);    // _10
};

struct TaiAction {
	virtual void _08() = 0;                // _08
	virtual void finish(Teki &);           // _0C
	virtual void _10() = 0;                // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAbiteForKabekuiB : public TAIAbiteForKabekui, public TaiAction {
	virtual void getPikiAttackSize(Teki &);  // _1C
	virtual void getNaviAttackSize(Teki &);  // _20

};

#endif
