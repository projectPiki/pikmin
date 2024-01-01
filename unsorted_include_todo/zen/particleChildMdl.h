#ifndef _ZEN_PARTICLECHILDMDL_H
#define _ZEN_PARTICLECHILDMDL_H

/**
 * .obj __vt__Q23zen16particleChildMdl, weak
 * .4byte __RTTI__Q23zen16particleChildMdl
 * .4byte 0
 * .4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
 * .4byte remove__Q23zen16particleChildMdlFv
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
struct particleChildMdl : public zenList {
	virtual void remove();  // _0C

};
} // namespace zen

#endif
