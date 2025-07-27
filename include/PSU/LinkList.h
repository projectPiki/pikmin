#ifndef _PSU_LINKLIST_H
#define _PSU_LINKLIST_H

#include "types.h"

struct PSUPtrList;
struct PSUPtrLink;

/**
 * @brief TODO
 */
struct PSUPtrLink {
	friend struct PSUPtrList;

protected:
	PSUPtrLink(void*);
	~PSUPtrLink();

	void* mObject;     // _00
	PSUPtrList* mList; // _04
	PSUPtrLink* mPrev; // _08
	PSUPtrLink* mNext; // _0C
};

/**
 * @brief TODO
 */
struct PSUPtrList {
	friend struct PSUPtrLink;

protected:
	PSUPtrList() { initiate(); }
	PSUPtrList(bool); // unused/inlined
	~PSUPtrList();

	void initiate();

	PSUPtrLink* getFirstLink() const { return mHead; }
	PSUPtrLink* getNthLink(u32) const;

	bool append(PSUPtrLink*);
	bool remove(PSUPtrLink*);
	bool prepend(PSUPtrLink*);
	bool insert(PSUPtrLink*, PSUPtrLink*);

private:
	void setFirst(PSUPtrLink*);

	PSUPtrLink* mHead; // _00
	PSUPtrLink* mTail; // _04
	u32 mLinkCount;    // _08
};

/**
 * @brief TODO
 */
template <typename T>
struct PSULink : public PSUPtrLink {
public:
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
public:
	PSUList() { } // DLL, to do/check

	~PSUList() { } // unused/inlined

	// only DLL inlines:
	bool append(PSULink<T>* link) { return PSUPtrList::append((PSUPtrLink*)link); }
	bool remove(PSULink<T>* link) { return PSUPtrList::remove((PSUPtrLink*)link); }

	// _00-_0C = PSUPtrList
};

#endif
