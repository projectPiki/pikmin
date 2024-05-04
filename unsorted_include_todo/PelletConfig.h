#ifndef _PELLETCONFIG_H
#define _PELLETCONFIG_H

#include "types.h"
#include "ANode.h"
#include "Stream.h"

/**
 * .obj __vt__12PelletConfig, global
 * .4byte __RTTI__12PelletConfig
 * .4byte 0
 * .4byte __RTTI__12PelletConfig
 * .4byte 0xFFFFFFFC
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@4@read__12PelletConfigFR18RandomAccessStream"
 * .4byte read__12PelletConfigFR18RandomAccessStream
 */

/**
 * @brief TODO
 */
struct PelletConfig : public ANode {
	virtual void read(RandomAccessStream&); // _18 (weak)

	PelletConfig();
};

#endif
