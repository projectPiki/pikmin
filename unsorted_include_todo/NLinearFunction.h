#ifndef _NLINEARFUNCTION_H
#define _NLINEARFUNCTION_H

/**
 * .obj __vt__15NLinearFunction, global
 * .4byte __RTTI__15NLinearFunction
 * .4byte 0
 * .4byte getValue__19NPolynomialFunctionFf
 * .4byte println__19NPolynomialFunctionFv
*/

struct NPolynomialFunction {
	virtual void getValue(float);  // _08
	virtual void println();        // _0C
};

/**
 * @brief TODO
 */
struct NLinearFunction : public NPolynomialFunction {

};

#endif
