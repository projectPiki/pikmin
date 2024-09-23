#ifndef _PSU_LINKLIST_H
#define _PSU_LINKLIST_H

#include "types.h"

/**
 * @brief TODO
 */
struct PSUPtrLink {
	PSUPtrLink(void*);

	~PSUPtrLink();

	// TODO: members
};

/**
 * @brief TODO
 */
struct PSUPtrList {
	PSUPtrList(bool); // unused/inlined

	~PSUPtrList();

	void initiate();
	void append(PSUPtrLink*);
	void remove(PSUPtrLink*);

	void getFirstLink() const;

	// unused/inlined:
	void setFirst(PSUPtrLink*);
	void prepend(PSUPtrLink*);
	void insert(PSUPtrLink*, PSUPtrLink*);
	void getNthLink(u32) const;

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Does this inherit from PSUPtrLink? Check later.
 */
template <typename T>
struct PSULink {
	~PSULink(); // unused/inlined

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Does this inherit from PSUPtrList? Check later.
 */
template <typename T>
struct PSUList {
	~PSUList(); // unused/inlined

	// TODO: members
};

#endif
