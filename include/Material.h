#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Stream.h"
#include "ANode.h"

/**
 * .obj __vt__8Material, global
 * .4byte __RTTI__8Material
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8MaterialFR18RandomAccessStream
 * .4byte attach__8MaterialFv
 */

/**
 * @brief TODO
 */
struct Material : public ANode {
	virtual void read(RandomAccessStream&); // _0C
	virtual void attach();                  // _10
};

struct PVWKeyInfoS10;

struct PVWTevStage {
	void read(RandomAccessStream&);
};

struct PVWTevInfo { };

struct MatobjInfo {
	void attach();
	void detach();
};

#endif
