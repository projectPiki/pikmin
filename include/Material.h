#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Stream.h"
#include "CoreNode.h"
#include "GfxObject.h"

/**
 * @brief TODO
 */
struct Material : public CoreNode {
	virtual void read(RandomAccessStream&); // _0C
	virtual void attach();                  // _10
};

/**
 * @brief TODO
 */
struct MatobjInfo : public GfxobjInfo {
	virtual void attach(); // _08
	virtual void detach(); // _0C
};

/**
 * @brief TODO
 */
struct MaterialHandler {
	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C
};

#endif
