#ifndef _INTROGAMEMODESTATE_H
#define _INTROGAMEMODESTATE_H

/**
 * .obj __vt__18IntroGameModeState, global
 * .4byte __RTTI__18IntroGameModeState
 * .4byte 0
 * .4byte update__18IntroGameModeStateFRUl
 * .4byte postRender__18IntroGameModeStateFR8Graphics
 * .4byte postUpdate__9ModeStateFv
 */

struct ModeState {
	virtual void update(unsigned long&); // _08
	virtual void postRender(Graphics&);  // _0C
	virtual void postUpdate();           // _10
};

/**
 * @brief TODO
 */
struct IntroGameModeState : public ModeState {
	virtual void update(unsigned long&); // _08
	virtual void postRender(Graphics&);  // _0C
};

#endif
