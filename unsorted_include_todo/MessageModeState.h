#ifndef _MESSAGEMODESTATE_H
#define _MESSAGEMODESTATE_H

/**
 * .obj __vt__16MessageModeState, global
 * .4byte __RTTI__16MessageModeState
 * .4byte 0
 * .4byte update__16MessageModeStateFRUl
 * .4byte postRender__16MessageModeStateFR8Graphics
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
struct MessageModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C
};

#endif
