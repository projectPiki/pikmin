#ifndef _MEMSTAT_H
#define _MEMSTAT_H

#include "CoreNode.h"
#include "types.h"

/**
 * @brief TODO
 */
struct MemInfoNode : public CoreNode {
	MemInfoNode()
	    : CoreNode("meminfo")
	{
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct MemInfo : public MemInfoNode {
	// _00     = VTBL
	// _00-_14 = MemInfoNode?
	int mMemorySize; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0xA0.
 */
struct MemStat {
public:
	MemStat();

	void reset();
	void start(immut char* name);
	void end(immut char* name);
	void print();

	// unused/inlined:
	int getMemorySize(immut char*);
	int getRestMemory();

protected:
	MemInfo* getInfo(immut char*);
	void printInfoRec(MemInfo*, int);
	MemInfo* getInfoRec(immut char*, MemInfo*);

	MemInfo mInfoListRoot;       // _00
	MemInfo* mCurrentInfo;       // _18
	MemInfo* mPrevInfoStack[32]; // _1C
	u32 mStatCount;              // _9C
};

extern MemStat* memStat;

#endif
