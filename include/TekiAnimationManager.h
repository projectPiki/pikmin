#ifndef _TEKIANIMATIONMANAGER_H
#define _TEKIANIMATIONMANAGER_H

#include "types.h"
#include "Node.h"

struct TekiMgr;

/**
 * @brief TODO
 */
struct TekiAnimationManager : public Node {
	TekiAnimationManager(TekiMgr*);

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_20 = Section?
	// TODO: members
};

#endif
