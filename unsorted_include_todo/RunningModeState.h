#ifndef _RUNNINGMODESTATE_H
#define _RUNNINGMODESTATE_H

/**
 * .obj __vt__16RunningModeState, global
 * .4byte __RTTI__16RunningModeState
 * .4byte 0
 * .4byte update__16RunningModeStateFRUl
 * .4byte postRender__16RunningModeStateFR8Graphics
 * .4byte postUpdate__9ModeStateFv
 */

struct ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C
	virtual void postUpdate();          // _10
};

/**
 * @brief TODO
 */
struct RunningModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C
};

#endif
