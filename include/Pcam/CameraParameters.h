#ifndef _PCAM_CAMERAPARAMETERS_H
#define _PCAM_CAMERAPARAMETERS_H

#include "types.h"
#include "Node.h"
#include "ParaParameters.h"

/**
 * @brief TODO
 */
struct PcamCameraParameters : public Node {
	PcamCameraParameters();

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
