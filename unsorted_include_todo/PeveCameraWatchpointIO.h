#ifndef _PEVECAMERAWATCHPOINTIO_H
#define _PEVECAMERAWATCHPOINTIO_H

/**
 * .obj __vt__22PeveCameraWatchpointIO, weak
 * .4byte __RTTI__22PeveCameraWatchpointIO
 * .4byte 0
 * .4byte input__22PeveCameraWatchpointIOFR9NVector3f
 * .4byte output__22PeveCameraWatchpointIOFR9NVector3f
 */

/**
 * @brief TODO
 */
struct PeveCameraWatchpointIO {
	virtual void input(NVector3f&);  // _08
	virtual void output(NVector3f&); // _0C
};

#endif
