#ifndef _ZEN_ZENLIST_H
#define _ZEN_ZENLIST_H

#include "types.h"

namespace zen {

/**
 * @brief TODO
 */
struct zenList {
	inline zenList() { mPrev = mNext = this; }

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
	zenListManager()
	{
		_00           = &_04;
		zenList* list = _00;
		_00->mNext    = list;
		_00->mPrev    = list;
	}

	zenList* get()
	{
		zenList* out = nullptr;
		if (_00 != _00->mNext) {
			out = _00->mNext;
			out->remove();
		}
		return out;
	}

	// unused/inlined:
	~zenListManager();

	zenList* _00; // _00
	zenList _04;  // _04
};

} // namespace zen

#endif
