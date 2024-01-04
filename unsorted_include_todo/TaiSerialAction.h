#ifndef _TAISERIALACTION_H
#define _TAISERIALACTION_H

/**
 * .obj __vt__15TaiSerialAction, global
 * .4byte __RTTI__15TaiSerialAction
 * .4byte 0
 * .4byte start__15TaiSerialActionFR4Teki
 * .4byte finish__15TaiSerialActionFR4Teki
 * .4byte act__15TaiSerialActionFR4Teki
 * .4byte actByEvent__15TaiSerialActionFR9TekiEvent
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
struct TaiSerialAction : public TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14

	TaiSerialAction(int, int);
};

#endif
