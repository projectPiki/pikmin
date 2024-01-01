#ifndef _NUPPERMATRIX_H
#define _NUPPERMATRIX_H

/**
 * .obj __vt__12NUpperMatrix, weak
 * .4byte __RTTI__12NUpperMatrix
 * .4byte 0
 * .4byte setDimension__14NSpecialMatrixFi
*/

struct NSpecialMatrix {
	virtual void setDimension(int);  // _08
};

/**
 * @brief TODO
 */
struct NUpperMatrix : public NSpecialMatrix {

};

#endif
