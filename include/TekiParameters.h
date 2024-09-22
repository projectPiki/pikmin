#ifndef _TEKIPARAMETERS_H
#define _TEKIPARAMETERS_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 */
struct TekiParameters : public Node {
	TekiParameters(int, int);

	virtual void read(RandomAccessStream&); // _0C

	void getF(int);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
