#ifndef _TAICOLLECLETGOOFPELLETACTION_H
#define _TAICOLLECLETGOOFPELLETACTION_H

/**
 * .obj __vt__28TaiCollecLetGoOfPelletAction, global
 * .4byte __RTTI__28TaiCollecLetGoOfPelletAction
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__28TaiCollecLetGoOfPelletActionFR4Teki
 * .4byte actByEvent__28TaiCollecLetGoOfPelletActionFR9TekiEvent
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
struct TaiCollecLetGoOfPelletAction : public TaiAction {
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14

};

#endif
