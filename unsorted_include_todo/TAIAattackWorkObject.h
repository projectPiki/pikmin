#ifndef _TAIAATTACKWORKOBJECT_H
#define _TAIAATTACKWORKOBJECT_H

/**
 * .obj __vt__20TAIAattackWorkObject, global
 * .4byte __RTTI__20TAIAattackWorkObject
 * .4byte 0
 * .4byte start__20TAIAattackWorkObjectFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__20TAIAattackWorkObjectFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getDamage__20TAIAattackWorkObjectFR4Teki
 * .4byte getAttackPointRadius__20TAIAattackWorkObjectFR4Teki
 * .4byte attackEffect__20TAIAattackWorkObjectFR4Teki
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
struct TAIAattackWorkObject : public TaiAction {
	virtual void start(Teki &);                 // _08
	virtual void act(Teki &);                   // _10
	virtual void getDamage(Teki &);             // _1C
	virtual void getAttackPointRadius(Teki &);  // _20
	virtual void attackEffect(Teki &);          // _24

};

#endif
