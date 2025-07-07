#ifndef _TEKIANIMATIONMANAGER_H
#define _TEKIANIMATIONMANAGER_H

#include "Node.h"
#include "types.h"

struct TekiMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct TekiAnimationManager : public Node {
	TekiAnimationManager(TekiMgr*);

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_20 = Node
	TekiMgr* mTekiMgr; // _20
};

#endif
