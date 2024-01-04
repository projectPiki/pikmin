#ifndef _QUITTINGMODESTATE_H
#define _QUITTINGMODESTATE_H

/**
 * .obj __vt__17QuittingModeState, weak
 * .4byte __RTTI__17QuittingModeState
 * .4byte 0
 * .4byte update__17QuittingModeStateFRUl
 * .4byte postRender__9ModeStateFR8Graphics
 * .4byte postUpdate__17QuittingModeStateFv
 */

struct ModeState {
	virtual void update(unsigned long&); // _08
	virtual void postRender(Graphics&);  // _0C
};

/**
 * @brief TODO
 */
struct QuittingModeState : public ModeState {
	virtual void update(unsigned long&); // _08
	virtual void postUpdate();           // _10
};

#endif
