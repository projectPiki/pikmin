#ifndef _PSUPTRLIST_H
#define _PSUPTRLIST_H

/*
 * @brief TODO
 */
struct PSUPtrList {
	~PSUPtrList();
	void initiate();
	void append(PSUPtrLink*);
	void remove(PSUPtrLink*);
};

#endif
