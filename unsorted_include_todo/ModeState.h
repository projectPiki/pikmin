#ifndef _MODESTATE_H
#define _MODESTATE_H

/**
 * .obj __vt__9ModeState, weak
 * .4byte __RTTI__9ModeState
 * .4byte 0
 * .4byte update__9ModeStateFRUl
 * .4byte postRender__9ModeStateFR8Graphics
 * .4byte postUpdate__9ModeStateFv
*/

/**
 * @brief TODO
 */
struct ModeState {
	virtual void update(unsigned long &);  // _08
	virtual void postRender(Graphics &);   // _0C
	virtual void postUpdate();             // _10

};

#endif
