#ifndef _PEVECAMERAPOSTUREIO_H
#define _PEVECAMERAPOSTUREIO_H

/**
 * .obj __vt__19PeveCameraPostureIO, weak
 * .4byte __RTTI__19PeveCameraPostureIO
 * .4byte 0
 * .4byte input__19PeveCameraPostureIOFR10NPosture3D
 * .4byte output__19PeveCameraPostureIOFR10NPosture3D
*/

/**
 * @brief TODO
 */
struct PeveCameraPostureIO {
	virtual void input(NPosture3D &);  // _08
	virtual void output(NPosture3D &); // _0C

};

#endif
