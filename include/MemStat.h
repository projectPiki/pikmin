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
		_1C[_9C] = _18;
		_9C++;
		_18 = newInfo;
	}

	// TODO: members
	MemInfo _00;      // _00
	MemInfo* _18;     // _18
	MemInfo* _1C[32]; // _1C
	int _9C;          // _9C
};

extern MemStat* memStat;

#endif
