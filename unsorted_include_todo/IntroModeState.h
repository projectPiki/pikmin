#ifndef _INTROMODESTATE_H
#define _INTROMODESTATE_H

/**
 * .obj __vt__14IntroModeState, weak
 * .4byte __RTTI__14IntroModeState
 * .4byte 0
 * .4byte update__14IntroModeStateFRUl
 * .4byte postRender__14IntroModeStateFR8Graphics
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
struct IntroModeState : public ModeState {
	virtual void update(u32&);          // _08
	virtual void postRender(Graphics&); // _0C
};

#endif
