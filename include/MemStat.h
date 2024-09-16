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
	// TODO: members
};

/**
 * @brief TODO
 */
struct MemStat {
	MemStat();

	void reset();
	void start(char*);
	void end(char*);
	void print();
	void getInfo(char*);
	void printInfoRec(MemInfo*, int);
	void getInfoRec(char*, MemInfo*);

	// unused/inlined:
	void getMemorySize(char*);
	void getRestMemory();

	// TODO: members
	MemInfo mMemInfo; // _00
};

extern MemStat* memStat;

#endif
