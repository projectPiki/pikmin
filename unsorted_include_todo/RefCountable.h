#ifndef _REFCOUNTABLE_H
#define _REFCOUNTABLE_H

/*
 * @brief TODO
 */
struct RefCountable {
	void addCntCallback();
	void subCntCallback();
	RefCountable();
	void clearCnt();
	void addCnt();
	void subCnt();
};

#endif
