#ifndef _MEMSTAT_H
#define _MEMSTAT_H

#include "types.h"
#include "CoreNode.h"

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
	void start(char*);
	void end(char*);
	void print();
	MemInfo* getInfo(char*);
	void printInfoRec(MemInfo*, int);
	MemInfo* getInfoRec(char*, MemInfo*);

	// unused/inlined:
	void getMemorySize(char*);
	void getRestMemory();

	inline void addInfo(MemInfo* newInfo)
	{
		// Add the new info to the stack
		mPrevInfoStack[mStatCount] = mCurrentInfo;
		mStatCount++;
		mCurrentInfo = newInfo;
	}

	MemInfo mInfoListRoot;       // _00
	MemInfo* mCurrentInfo;       // _18
	MemInfo* mPrevInfoStack[32]; // _1C
	int mStatCount;              // _9C
};

extern MemStat* memStat;

#endif
