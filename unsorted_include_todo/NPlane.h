#ifndef _NPLANE_H
#define _NPLANE_H

/**
 * .obj __vt__6NPlane, global
 * .4byte __RTTI__6NPlane
 * .4byte 0
 * .4byte transform__6NPlaneFR12NTransform3D
 * .4byte println__6NPlaneFv
 */

/**
 * @brief TODO
 */
struct NPlane {
	virtual void transform(NTransform3D&); // _08
	virtual void println();                // _0C

	NPlane(NVector3f&, NVector3f&);
	void construct(NVector3f&, NVector3f&);
	void outputVerticalPosition(NVector3f&, NVector3f&);
};

#endif
