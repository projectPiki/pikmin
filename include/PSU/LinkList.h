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

	void* getObjectPtr() const { return mObject; }
	PSUPtrLink* getNext() const { return mNext; }

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

	~PSULink(); // unused/inlined

	inline T* getObject() const { return (T*)getObjectPtr(); }

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Does this inherit from PSUPtrList? Check later.
 */
template <typename T>
struct PSUList : public PSUPtrList {
	~PSUList(); // unused/inlined

	inline PSULink<T>* getFirst() const { return (PSULink<T>*)getFirstLink(); }

	bool append(PSULink<T>* link) { return PSUPtrList::append((PSUPtrLink*)link); }

	// TODO: members
};

#endif
