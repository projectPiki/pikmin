#ifndef _ZEN_NUMBER_H
#define _ZEN_NUMBER_H

#include "types.h"
#include "P2D/Pane.h"

namespace zen {

/**
 * @brief TODO
 */
struct NumberTex {
	NumberTex();

	static u32 texTable;       // unknown type
	static u32 shadowTexTable; // unknown type

	// TODO: members
};

/**
 * @brief TODO
 */
template <typename T>
struct FigureTex : public NumberTex {

	void getNumber();
	void getNumber(T&);

	// _00-_?? = NumberTex
	// TODO: members
};

/**
 * @brief TODO
 */
template <typename T>
struct NumberPicCallBack : public P2DPaneCallBack, public FigureTex<T> {

	virtual bool invoke(P2DPane*); // _08

	void setTexture(P2DPane*);

	// _00     = VTBL?
	// _00-_04 = P2DPaneCallBack
	// _04-_?? = FigureTex
	// TODO: members
};

} // namespace zen

#endif
