#ifndef _TAIALANDING_H
#define _TAIALANDING_H

/**
 * .obj __vt__11TAIAlanding, global
 * .4byte __RTTI__11TAIAlanding
 * .4byte 0
 * .4byte start__11TAIAlandingFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__11TAIAlandingFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte landingEffect__11TAIAlandingFR4Teki
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
struct TAIAlanding : public TaiAction {
	virtual void start(Teki &);          // _08
	virtual void act(Teki &);            // _10
	virtual void landingEffect(Teki &);  // _1C

};

#endif
