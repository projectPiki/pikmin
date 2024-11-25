#ifndef _TEKIPARAMETERS_H
#define _TEKIPARAMETERS_H

#include "types.h"
#include "Node.h"
#include "ID32.h"
#include "ParaParameters.h"

/**
 * @brief TODO
 *
 * @note Size: 0x88.
 */
struct TekiParameters : public Node {
	TekiParameters(int iParamNum, int fParamNum);

	virtual void read(RandomAccessStream&); // _0C

	void getF(int);

	// _00     = VTBL
	// _00-_20 = Node
	int _20;                          // _20
	ID32 mParaIDs[8];                 // _24
	ParaMultiParameters* mParameters; // _84
};

#endif
