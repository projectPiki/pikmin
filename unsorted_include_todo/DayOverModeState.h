#ifndef _DAYOVERMODESTATE_H
#define _DAYOVERMODESTATE_H

/**
 * .obj __vt__16DayOverModeState, global
 * .4byte __RTTI__16DayOverModeState
 * .4byte 0
 * .4byte update__16DayOverModeStateFRUl
 * .4byte postRender__16DayOverModeStateFR8Graphics
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
struct DayOverModeState : public ModeState {
	virtual void update(unsigned long&); // _08
	virtual void postRender(Graphics&);  // _0C
};

#endif
