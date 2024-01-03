#ifndef _TAIOTIMOTIDROPPINGACTION_H
#define _TAIOTIMOTIDROPPINGACTION_H

/**
 * .obj __vt__24TaiOtimotiDroppingAction, global
 * .4byte __RTTI__24TaiOtimotiDroppingAction
 * .4byte 0
 * .4byte start__24TaiOtimotiDroppingActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__24TaiOtimotiDroppingActionFR4Teki
 * .4byte actByEvent__24TaiOtimotiDroppingActionFR9TekiEvent
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
struct TaiOtimotiDroppingAction : public TaiAction {
	virtual void start(Teki &);            // _08
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14

};

#endif
