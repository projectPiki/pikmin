#ifndef _ZEN_PARTICLEMDL_H
#define _ZEN_PARTICLEMDL_H

/**
 * .obj __vt__Q23zen11particleMdl, weak
 * .4byte __RTTI__Q23zen11particleMdl
 * .4byte 0
 * .4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
 * .4byte remove__Q23zen11particleMdlFv
 */

namespace zen {
struct zenList {
	virtual void insertAfter(zenList*); // _08
};
} // namespace zen

namespace zen {
/**
 * @brief TODO
 */
struct particleMdl : public zenList {
	virtual void remove(); // _0C
};
} // namespace zen

#endif
