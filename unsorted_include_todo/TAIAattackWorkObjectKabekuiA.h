#ifndef _TAIAATTACKWORKOBJECTKABEKUIA_H
#define _TAIAATTACKWORKOBJECTKABEKUIA_H

/**
 * .obj __vt__28TAIAattackWorkObjectKabekuiA, weak
 * .4byte __RTTI__28TAIAattackWorkObjectKabekuiA
 * .4byte 0
 * .4byte start__28TAIAattackWorkObjectKabekuiAFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__28TAIAattackWorkObjectKabekuiAFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getDamage__28TAIAattackWorkObjectKabekuiAFR4Teki
 * .4byte getAttackPointRadius__28TAIAattackWorkObjectKabekuiAFR4Teki
 * .4byte attackEffect__28TAIAattackWorkObjectKabekuiAFR4Teki
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
struct TAIAattackWorkObjectKabekuiA : public TaiAction {
	virtual void start(Teki &);                 // _08
	virtual void act(Teki &);                   // _10
	virtual void getDamage(Teki &);             // _1C
	virtual void getAttackPointRadius(Teki &);  // _20
	virtual void attackEffect(Teki &);          // _24

};

#endif
