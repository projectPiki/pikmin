#ifndef _QUITTINGGAMEMODESTATE_H
#define _QUITTINGGAMEMODESTATE_H

/**
 * .obj __vt__21QuittingGameModeState, weak
 * .4byte __RTTI__21QuittingGameModeState
 * .4byte 0
 * .4byte update__21QuittingGameModeStateFRUl
 * .4byte postRender__9ModeStateFR8Graphics
 * .4byte postUpdate__21QuittingGameModeStateFv
 */

struct ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C
};

/**
 * @brief TODO
 */
struct QuittingGameModeState : public ModeState {
	virtual void update(u32&); // _08
	virtual void postUpdate(); // _10
};

#endif
