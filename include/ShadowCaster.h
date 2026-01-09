#ifndef _SHADOWCASTER_H
#define _SHADOWCASTER_H

#include "Camera.h"
#include "types.h"

/**
 * @brief Manages shadow projections for large dynamic objects or trees of objects that require shadow shapes that match their model.
 *
 * Other smaller shadows are handled object-to-object by their managers and the `Creature::drawShadow` function, based on their
 * `Creature::needShadow` override. These all just color the relevant triangles, rather than draw a projection of their object.
 *
 * In reality, this is only used for Spider (Beady Long Legs) and (non-USA) King (Emperor Bulbax).
 *
 * @note Size: 0x398.
 */
struct ShadowCaster : public CoreNode {
	ShadowCaster();

	void initShadow();

	// _00     = VTBL
	// _00-_14 = CoreNode
	LightCamera mLightCamera; ///< _014, camera used to render the shadow map/projection from the light's perspective.
	Vector3f mSourcePosition; ///< _37C, position of the shadow-casting light source (above the object).
	Vector3f mTargetPosition; ///< _388, position being shadowed (object or ground).
	Node* mShadowDrawer;      ///< _394, manager for rendering an object's shadow - always cast based on parent structure.
};

#endif
