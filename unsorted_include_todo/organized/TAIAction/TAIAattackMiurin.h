#ifndef _TAIAATTACKMIURIN_H
#define _TAIAATTACKMIURIN_H

/**
 * .obj __vt__16TAIAattackMiurin, weak
 * .4byte __RTTI__16TAIAattackMiurin
 * .4byte 0
 * .4byte start__16TAIAattackMiurinFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__16TAIAattackMiurinFR4Teki
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
struct TAIAattackMiurin : public TaiAction {
	virtual void start(Teki &);  // _08
	virtual void act(Teki &);    // _10

};

#endif
