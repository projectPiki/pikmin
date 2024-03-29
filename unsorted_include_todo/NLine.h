#ifndef _NLINE_H
#define _NLINE_H

/**
 * .obj __vt__5NLine, global
 * .4byte __RTTI__5NLine
 * .4byte 0
 * .4byte transform__5NLineFR12NTransform3D
 * .4byte println__5NLineFv
 */

/**
 * @brief TODO
 */
struct NLine {
	virtual void transform(NTransform3D&); // _08
	virtual void println();                // _0C

	NLine(NVector3f&, NVector3f&);
	void construct(NVector3f&, NVector3f&);
	void calcDistance(NVector3f&, float*);
	void calcVerticalProjection(NVector3f&);
	void outputPosition(float, NVector3f&);
};

#endif
