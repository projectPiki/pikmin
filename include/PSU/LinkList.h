#ifndef _PSU_LINKLIST_H
#define _PSU_LINKLIST_H

#include "types.h"

struct PSUPtrList;
struct PSUPtrLink;

/**
 * @brief TODO
 */
struct PSUPtrLink {
	PSUPtrLink(void*);

	~PSUPtrLink();

	// no DLL inlines.

	void* mObject;     // _00
	PSUPtrList* mList; // _04
	PSUPtrLink* mPrev; // _08
	PSUPtrLink* mNext; // _0C
};

/**
 * @brief TODO
 */
struct PSUPtrList {
	PSUPtrList() { initiate(); }
	PSUPtrList(bool); // unused/inlined

	~PSUPtrList();

	void initiate();
	bool append(PSUPtrLink*);
	bool remove(PSUPtrLink*);

	PSUPtrLink* getFirstLink() const { return mHead; }

	// unused/inlined:
	void setFirst(PSUPtrLink*);
	bool prepend(PSUPtrLink*);
	bool insert(PSUPtrLink*, PSUPtrLink*);
	void getNthLink(u32) const;

	// no more DLL inlines.

	PSUPtrLink* mHead; // _00
	PSUPtrLink* mTail; // _04
	u32 mLinkCount;    // _08
};

/**
 * @brief TODO
 */
template <typename T>
struct PSULink : public PSUPtrLink {
	inline PSULink(T* object)
	    : PSUPtrLink((void*)object)
	{
	}

	~PSULink() { } // unused/inlined

	// no DLL inlines.

	// _00-_10 = PSUPtrLink
};

/**
 * @brief TODO
 */
template <typename T>
struct PSUList : public PSUPtrList {
	PSUList() { } // DLL, to do/check

	~PSUList() { } // unused/inlined

	// only DLL inlines:
	bool append(PSULink<T>* link) { return PSUPtrList::append((PSUPtrLink*)link); }
	bool remove(PSULink<T>* link) { return PSUPtrList::remove((PSUPtrLink*)link); }

	// _00-_0C = PSUPtrList
};

#endif
