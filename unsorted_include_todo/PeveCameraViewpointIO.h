#ifndef _PEVECAMERAVIEWPOINTIO_H
#define _PEVECAMERAVIEWPOINTIO_H

/**
 * .obj __vt__21PeveCameraViewpointIO, weak
 * .4byte __RTTI__21PeveCameraViewpointIO
 * .4byte 0
 * .4byte input__21PeveCameraViewpointIOFR9NVector3f
 * .4byte output__21PeveCameraViewpointIOFR9NVector3f
 */

/**
 * @brief TODO
 */
struct PeveCameraViewpointIO {
	virtual void input(NVector3f&);  // _08
	virtual void output(NVector3f&); // _0C
};

#endif
