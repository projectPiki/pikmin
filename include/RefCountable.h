#ifndef _REFCOUNTABLE_H
#define _REFCOUNTABLE_H

#include "types.h"

struct RefCountable {
	// vtable _00
	RefCountable();
	void clearCnt();
	void addCnt();
	void subCnt();
	virtual void addCntCallback();
	virtual void subCntCallback();

	s32 m_count; // _04
};

#endif
