#ifndef _PARAMULTIPARAMETERS_H
#define _PARAMULTIPARAMETERS_H

/**
 * .obj __vt__19ParaMultiParameters, global
 * .4byte __RTTI__19ParaMultiParameters
 * .4byte 0
 * .4byte read__19ParaMultiParametersFR6Stream
 * .4byte write__19ParaMultiParametersFR6Stream
 * .4byte print__19ParaMultiParametersFv
 */

/**
 * @brief TODO
 */
struct ParaMultiParameters {
	virtual void read(Stream&);  // _08
	virtual void write(Stream&); // _0C
	virtual void print();        // _10
};

#endif
