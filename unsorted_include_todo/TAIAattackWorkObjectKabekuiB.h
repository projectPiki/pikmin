#ifndef _TAIAATTACKWORKOBJECTKABEKUIB_H
#define _TAIAATTACKWORKOBJECTKABEKUIB_H

/**
 * .obj __vt__28TAIAattackWorkObjectKabekuiB, weak
 * .4byte __RTTI__28TAIAattackWorkObjectKabekuiB
 * .4byte 0
 * .4byte start__28TAIAattackWorkObjectKabekuiBFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__28TAIAattackWorkObjectKabekuiBFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getDamage__28TAIAattackWorkObjectKabekuiBFR4Teki
 * .4byte getAttackPointRadius__28TAIAattackWorkObjectKabekuiBFR4Teki
 * .4byte attackEffect__28TAIAattackWorkObjectKabekuiBFR4Teki
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
struct TAIAattackWorkObjectKabekuiB : public TaiAction {
	virtual void start(Teki &);                 // _08
	virtual void act(Teki &);                   // _10
	virtual void getDamage(Teki &);             // _1C
	virtual void getAttackPointRadius(Teki &);  // _20
	virtual void attackEffect(Teki &);          // _24

};

#endif
