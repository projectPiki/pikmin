#ifndef _POMAI_H
#define _POMAI_H

/**
 * .obj __vt__5PomAi, global
 * .4byte __RTTI__5PomAi
 * .4byte 0
 * .4byte animationKeyUpdated__5PomAiFR16PaniAnimKeyEvent
*/

/**
 * @brief TODO
 */
struct PomAi {
	virtual void animationKeyUpdated(PaniAnimKeyEvent &);  // _08

};

#endif
