#ifndef _ACTWATCH_ANIMLISTENER_H
#define _ACTWATCH_ANIMLISTENER_H

/**
 * .obj __vt__Q28ActWatch12AnimListener, global
 * .4byte __RTTI__Q28ActWatch12AnimListener
 * .4byte 0
 * .4byte animationKeyUpdated__Q28ActWatch12AnimListenerFR16PaniAnimKeyEvent
*/

namespace ActWatch {
/**
 * @brief TODO
 */
struct AnimListener {
	virtual void animationKeyUpdated(PaniAnimKeyEvent &);  // _08

};
} // namespace ActWatch

#endif
