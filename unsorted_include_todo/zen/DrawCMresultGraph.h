#ifndef _ZEN_DRAWCMRESULTGRAPH_H
#define _ZEN_DRAWCMRESULTGRAPH_H

/**
 * .obj __vt__Q23zen17DrawCMresultGraph, weak
 * .4byte __RTTI__Q23zen17DrawCMresultGraph
 * .4byte 0
 * .4byte update__Q23zen17DrawCMresultAlphaFv
 */

namespace zen {
struct DrawCMresultAlpha {
	virtual void update(); // _08
};
} // namespace zen

namespace zen {
/**
 * @brief TODO
 */
struct DrawCMresultGraph : public DrawCMresultAlpha {
};
} // namespace zen

#endif
