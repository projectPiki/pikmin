#ifndef _ZEN_ZENLIST_H
#define _ZEN_ZENLIST_H

/**
 * .obj __vt__Q23zen7zenList, weak
 * .4byte __RTTI__Q23zen7zenList
 * .4byte 0
 * .4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
 * .4byte remove__Q23zen7zenListFv
 */

namespace zen {
/**
 * @brief TODO
 */
struct zenList {
	virtual void insertAfter(zenList*); // _08
	virtual void remove();              // _0C
};
} // namespace zen

#endif
