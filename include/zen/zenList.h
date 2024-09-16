#ifndef _ZEN_ZENLIST_H
#define _ZEN_ZENLIST_H

#include "types.h"

namespace zen {

/**
 * @brief TODO
 */
struct zenList {
	virtual void insertAfter(zenList*); // _08
	virtual void remove();              // _0C

	// _00 = VTBL
	zenList* mPrev; // _04
	zenList* mNext; // _08
};

/**
 * @brief TODO
 */
struct zenListManager {
	zenListManager();

	void get();

	// unused/inlined:
	~zenListManager();

	// TODO: members
};

} // namespace zen

#endif
