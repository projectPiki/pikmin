#ifndef _GENERATORCACHE_CACHE_H
#define _GENERATORCACHE_CACHE_H

/**
 * .obj __vt__Q214GeneratorCache5Cache, weak
 * .4byte __RTTI__Q214GeneratorCache5Cache
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

namespace GeneratorCache {
/**
 * @brief TODO
 */
struct Cache : public ANode, public CoreNode {
};
} // namespace GeneratorCache

#endif
