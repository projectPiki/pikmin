#ifndef _PARAPARAMETERSI_H
#define _PARAPARAMETERSI_H

/**
 * .obj __vt__15ParaParametersI, global
 * .4byte __RTTI__15ParaParametersI
 * .4byte 0
 * .4byte read__15ParaParametersIFR6Stream
 * .4byte write__15ParaParametersIFR6Stream
 * .4byte print__15ParaParametersIFv
 */

/**
 * @brief TODO
 */
struct ParaParametersI {
	virtual void read(Stream&);  // _08
	virtual void write(Stream&); // _0C
	virtual void print();        // _10
};

#endif
