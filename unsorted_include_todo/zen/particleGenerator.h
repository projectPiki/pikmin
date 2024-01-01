#ifndef _ZEN_PARTICLEGENERATOR_H
#define _ZEN_PARTICLEGENERATOR_H

/**
 * .obj __vt__Q23zen17particleGenerator, weak
 * .4byte __RTTI__Q23zen17particleGenerator
 * .4byte 0
 * .4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
 * .4byte remove__Q23zen17particleGeneratorFv
*/

namespace zen {
struct zenList {
	virtual void insertAfter(zenList *);  // _08
};
} // namespace zen

namespace zen {
/**
 * @brief TODO
 */
struct particleGenerator : public zenList {
	virtual void remove();  // _0C

};
} // namespace zen

#endif
