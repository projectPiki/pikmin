#ifndef _NLOWERMATRIX_H
#define _NLOWERMATRIX_H

/**
 * .obj __vt__12NLowerMatrix, weak
 * .4byte __RTTI__12NLowerMatrix
 * .4byte 0
 * .4byte setDimension__14NSpecialMatrixFi
 */

struct NSpecialMatrix {
	virtual void setDimension(int); // _08
};

/**
 * @brief TODO
 */
struct NLowerMatrix : public NSpecialMatrix {
};

#endif
