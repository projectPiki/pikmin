#include "Shape.h"

/**
 * @todo: Documentation
 */
void Shape::optimize()
{
	if (!mTexCoordList[0]) {
		mTexCoordList[0]      = new Vector2f[1];
		mTexCoordList[0][0].x = 0.0f;
		mTexCoordList[0][0].y = 0.0f;
	}

	// Yep, that's it.
}
