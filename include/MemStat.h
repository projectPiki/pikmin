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
	MemStat();

	void reset();
	void start(char* name);
	void end(char* name);
	void print();
	MemInfo* getInfo(char*);
	void printInfoRec(MemInfo*, int);
	MemInfo* getInfoRec(char*, MemInfo*);

	// unused/inlined:
	int getMemorySize(char*);
	int getRestMemory();

	MemInfo mInfoListRoot;       // _00
	MemInfo* mCurrentInfo;       // _18
	MemInfo* mPrevInfoStack[32]; // _1C
	int mStatCount;              // _9C
};

extern MemStat* memStat;

#endif
