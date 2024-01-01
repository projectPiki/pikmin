#ifndef _TAICOLLECPUTTINGPELLETACTION_H
#define _TAICOLLECPUTTINGPELLETACTION_H

/**
 * .obj __vt__28TaiCollecPuttingPelletAction, global
 * .4byte __RTTI__28TaiCollecPuttingPelletAction
 * .4byte 0
 * .4byte start__28TaiCollecPuttingPelletActionFR4Teki
 * .4byte finish__28TaiCollecPuttingPelletActionFR4Teki
 * .4byte act__28TaiCollecPuttingPelletActionFR4Teki
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
struct TaiCollecPuttingPelletAction : public TaiAction {
	virtual void start(Teki &);  // _08
	virtual void finish(Teki &); // _0C
	virtual void act(Teki &);    // _10

};

#endif
