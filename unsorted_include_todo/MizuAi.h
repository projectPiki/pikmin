#ifndef _MIZUAI_H
#define _MIZUAI_H

/**
 * .obj __vt__6MizuAi, global
 * .4byte __RTTI__6MizuAi
 * .4byte 0
 * .4byte animationKeyUpdated__6MizuAiFR16PaniAnimKeyEvent
 */

/**
 * @brief TODO
 */
struct MizuAi {
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	MizuAi(Mizu*);
};

#endif
