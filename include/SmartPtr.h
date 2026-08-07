#ifndef _SMARTPTR_H
#define _SMARTPTR_H

#include "types.h"

/**
 * @brief TODO
 *
 * @note Mostly stripped, but necessary. This is the complete set of inlines from the DLL.
 */
template <typename T>
struct SmartPtr {
	SmartPtr() { mPtr = nullptr; }

	void set(T* creature)
	{
		if (mPtr) {
			clear();
		}
		mPtr = creature;
		if (mPtr) {
			mPtr->addCnt();
		}
	}

	void clear()
	{
		if (mPtr) {
			mPtr->subCnt();
			mPtr = nullptr;
		}
	}

	T* getPtr() { return mPtr; }

	bool isNull() { return mPtr == nullptr; }

	void reset() { mPtr = nullptr; }

	T* mPtr; // _00
};

#endif
