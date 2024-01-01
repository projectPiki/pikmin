#ifndef _TOPACTION_MOTIONLISTENER_H
#define _TOPACTION_MOTIONLISTENER_H

/**
 * .obj __vt__Q29TopAction14MotionListener, global
 * .4byte __RTTI__Q29TopAction14MotionListener
 * .4byte 0
 * .4byte animationKeyUpdated__Q29TopAction14MotionListenerFR16PaniAnimKeyEvent
*/

namespace TopAction {
/**
 * @brief TODO
 */
struct MotionListener {
	virtual void animationKeyUpdated(PaniAnimKeyEvent &);  // _08

};
} // namespace TopAction

#endif
