#ifndef _ZEN_NUMBER_H
#define _ZEN_NUMBER_H

#include "types.h"
#include "P2D/Pane.h"

struct Texture;

namespace zen {

/**
 * @brief TODO
 */
struct NumberTex {
	NumberTex();

	static Texture* texTable[10];       // unknown type
	static Texture* shadowTexTable[10]; // unknown type

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
	NumberPicCallBack(P2DPane*, T*, int, bool); // DLL, to do

	virtual bool invoke(P2DPane*); // _08

	void setTexture(P2DPane*);

	// _00     = VTBL?
	// _00-_04 = P2DPaneCallBack
	// _04-_?? = FigureTex
	// TODO: members
};

} // namespace zen

#endif
