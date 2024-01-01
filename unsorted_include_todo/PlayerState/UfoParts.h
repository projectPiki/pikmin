#ifndef _PLAYERSTATE_UFOPARTS_H
#define _PLAYERSTATE_UFOPARTS_H

/**
 * .obj __vt__Q211PlayerState8UfoParts, global
 * .4byte __RTTI__Q211PlayerState8UfoParts
 * .4byte 0
 * .4byte animationKeyUpdated__Q211PlayerState8UfoPartsFR16PaniAnimKeyEvent
*/

namespace PlayerState {
/**
 * @brief TODO
 */
struct UfoParts {
	virtual void animationKeyUpdated(PaniAnimKeyEvent &);  // _08

};
} // namespace PlayerState

#endif
