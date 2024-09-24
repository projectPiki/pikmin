#ifndef _ZEN_OGGRAPH_H
#define _ZEN_OGGRAPH_H

#include "types.h"
#include "P2D/Pane.h"

struct Colour;

namespace zen {

/**
 * @brief TODO
 */
struct TextColorCallBack : public P2DPaneCallBack {
	TextColorCallBack(P2DPane*);

	virtual bool invoke(P2DPane*); // _08

	void setTargetColor(Colour&, Colour&, f32);

	// TODO: members
};

} // namespace zen

#endif
