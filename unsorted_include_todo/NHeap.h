#ifndef _NHEAP_H
#define _NHEAP_H

/**
 * .obj __vt__5NHeap, global
 * .4byte __RTTI__5NHeap
 * .4byte 0
 * .4byte release__5NHeapFv
 * .4byte addHeap__5NHeapFP5NHeap
*/

/**
 * @brief TODO
 */
struct NHeap {
	virtual void release();         // _08
	virtual void addHeap(NHeap *);  // _0C

};

#endif
