#ifndef _NCLAMPLINEARFUNCTION_H
#define _NCLAMPLINEARFUNCTION_H

/**
 * .obj __vt__20NClampLinearFunction, global
 * .4byte __RTTI__20NClampLinearFunction
 * .4byte 0
 * .4byte getValue__20NClampLinearFunctionFf
 * .4byte println__20NClampLinearFunctionFv
 */

/**
 * @brief TODO
 */
struct NClampLinearFunction {
	virtual void getValue(float); // _08
	virtual void println();       // _0C

	NClampLinearFunction(float*);
	void construct(float*);
	void makeClampLinearFunction(float, float, float, float);
};

#endif
