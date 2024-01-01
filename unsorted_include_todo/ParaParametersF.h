#ifndef _PARAPARAMETERSF_H
#define _PARAPARAMETERSF_H

/**
 * .obj __vt__15ParaParametersF, global
 * .4byte __RTTI__15ParaParametersF
 * .4byte 0
 * .4byte read__15ParaParametersFFR6Stream
 * .4byte write__15ParaParametersFFR6Stream
 * .4byte print__15ParaParametersFFv
*/

/**
 * @brief TODO
 */
struct ParaParametersF {
	virtual void read(Stream &);  // _08
	virtual void write(Stream &); // _0C
	virtual void print();         // _10

};

#endif
