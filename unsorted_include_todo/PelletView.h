#ifndef _PELLETVIEW_H
#define _PELLETVIEW_H

/**
 * .obj __vt__10PelletView, weak
 * .4byte __RTTI__10PelletView
 * .4byte 0
 * .4byte viewInit__10PelletViewFv
 * .4byte 0
 * .4byte 0
 * .4byte viewStartTrembleMotion__10PelletViewFf
 * .4byte viewStartExplodeMotion__10PelletViewFf
 * .4byte viewSetMotionSpeed__10PelletViewFf
 * .4byte viewFinishMotion__10PelletViewFv
 * .4byte viewDoAnimation__10PelletViewFv
 * .4byte 0
 * .4byte 0
 * .4byte viewGetScale__10PelletViewFv
*/

/**
 * @brief TODO
 */
struct PelletView {
	virtual void viewInit();                     // _08 (weak)
	virtual void _0C() = 0;                      // _0C
	virtual void _10() = 0;                      // _10
	virtual void viewStartTrembleMotion(float);  // _14 (weak)
	virtual void viewStartExplodeMotion(float);  // _18 (weak)
	virtual void viewSetMotionSpeed(float);      // _1C (weak)
	virtual void viewFinishMotion();             // _20 (weak)
	virtual void viewDoAnimation();              // _24 (weak)
	virtual void _28() = 0;                      // _28
	virtual void _2C() = 0;                      // _2C
	virtual void viewGetScale();                 // _30 (weak)

};

#endif
