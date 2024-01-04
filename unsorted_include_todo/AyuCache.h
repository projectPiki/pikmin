#ifndef _AYUCACHE_H
#define _AYUCACHE_H

/*
 * @brief TODO
 */
struct AyuCache {
	AyuCache(unsigned long);
	void init(unsigned long, unsigned long);
	void mallocL(unsigned long);
	void cacheFree(void*);
	void isEmpty();
	void largestBlockFree();
};

#endif
