#ifndef _MEMSTAT_H
#define _MEMSTAT_H

/*
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
};

#endif
