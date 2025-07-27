#ifndef _ZEN_ZENLIST_H
#define _ZEN_ZENLIST_H

#include "types.h"

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct zenList {
public:
	zenList() { mPrev = mNext = this; }

	virtual void insertAfter(zenList* newList) // _08
	{
		newList->mNext = mNext;
		newList->mPrev = this;
		mNext->mPrev   = newList;
		mNext          = newList;
	}
	virtual void remove() // _0C
	{
		mNext->mPrev = mPrev;
		mPrev->mNext = mNext;
	}

	// _00 = VTBL
	zenList* mPrev; // _04
	zenList* mNext; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct zenListManager {
public:
	zenListManager()
	{
		mOrigin = &mList;
		init();
	}

	~zenListManager() { }

	// these are all the inlines/member functions according to the DLL.

	void init() { mOrigin->mPrev = mOrigin->mNext = mOrigin; }

	zenList* get()
	{
		zenList* out = nullptr;
		if (mOrigin != mOrigin->mNext) {
			out = mOrigin->mNext;
			out->remove();
		}
		return out;
	}

	void put(zenList* list)
	{
		list->remove();
		mOrigin->insertAfter(list);
	}

	zenList* getOrigin() { return mOrigin; }
	zenList* getTopList() { return mOrigin->mNext; }
	zenList* getBottomList() { return mOrigin->mPrev; }

	void merge(zenListManager* other)
	{
		zenList* list = other->getTopList();
		if (list != other->getOrigin()) {
			zenList* end          = other->getBottomList();
			list->mPrev           = mOrigin->mPrev->mNext;
			mOrigin->mPrev->mNext = list;
			mOrigin->mPrev        = end;
			end->mNext            = mOrigin;
			other->init();
		}
	}

	int getListNum()
	{
		int count = 0;
		for (zenList* list = getTopList(); list != getOrigin(); list = list->mNext) {
			count++;
		}
		return count;
	}

private:
	zenList* mOrigin; // _00
	zenList mList;    // _04
};

} // namespace zen

#endif
