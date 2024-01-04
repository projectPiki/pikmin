#ifndef _TAIAATTACKWORKOBJECTKABEKUIC_H
#define _TAIAATTACKWORKOBJECTKABEKUIC_H

/**
 * .obj __vt__28TAIAattackWorkObjectKabekuiC, weak
 * .4byte __RTTI__28TAIAattackWorkObjectKabekuiC
 * .4byte 0
 * .4byte start__28TAIAattackWorkObjectKabekuiCFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__28TAIAattackWorkObjectKabekuiCFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getDamage__28TAIAattackWorkObjectKabekuiCFR4Teki
 * .4byte getAttackPointRadius__28TAIAattackWorkObjectKabekuiCFR4Teki
 * .4byte attackEffect__28TAIAattackWorkObjectKabekuiCFR4Teki
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
struct TAIAattackWorkObjectKabekuiC : public TaiAction {
	virtual void start(Teki&);                // _08
	virtual void act(Teki&);                  // _10
	virtual void getDamage(Teki&);            // _1C
	virtual void getAttackPointRadius(Teki&); // _20
	virtual void attackEffect(Teki&);         // _24
};

#endif
