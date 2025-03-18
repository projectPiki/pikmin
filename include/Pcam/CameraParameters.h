#ifndef _PCAM_CAMERAPARAMETERS_H
#define _PCAM_CAMERAPARAMETERS_H

#include "types.h"
#include "Node.h"
#include "ParaParameters.h"

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct PcamCameraParameters : public Node {
	PcamCameraParameters();

	virtual void read(RandomAccessStream&); // _0C

	// DLL inlines:
	f32 getF(int idx) { return _24->getF(idx); }

	// _00     = VTBL
	// _00-_20 = Node
	u8 _20[0x4];              // _20, unknown
	ParaMultiParameters* _24; // _24
};

#endif
