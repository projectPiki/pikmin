#ifndef _ZEN_PCRDATA_H
#define _ZEN_PCRDATA_H

/**
 * .obj __vt__Q23zen7PCRData, weak
 * .4byte __RTTI__Q23zen7PCRData
 * .4byte 0
 * .4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
 * .4byte remove__Q23zen7zenListFv
 */

namespace zen {
struct zenList {
	virtual void insertAfter(zenList*); // _08
	virtual void remove();              // _0C
};
} // namespace zen

namespace zen {
/**
 * @brief TODO
 */
struct PCRData : public zenList {
};
} // namespace zen

#endif
