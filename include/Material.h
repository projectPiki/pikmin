#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Stream.h"
#include "CoreNode.h"
#include "GfxObject.h"

/**
 * @brief TODO
 */
struct Material : public CoreNode {
	Material();

	virtual void read(RandomAccessStream&); // _0C
	virtual void attach();                  // _10

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct MatobjInfo : public GfxobjInfo {
	virtual void attach(); // _08
	virtual void detach(); // _0C

	// _1C     = VTBL
	// _00-_20 = GfxobjInfo
	// TODO: members
};

/**
 * @brief TODO
 */
struct MaterialHandler {
	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C

	// TODO: members
};

#endif
