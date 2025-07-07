#ifndef _ZEN_NUMBER_H
#define _ZEN_NUMBER_H

#include "P2D/Pane.h"
#include "P2D/Picture.h"
#include "Texture.h"
#include "nlib/Math.h"
#include "types.h"

struct Texture;

namespace zen {

/**
 * @brief TODO
 */
struct NumberTex {
	NumberTex();

	static Texture* texTable[10];       // unknown type
	static Texture* shadowTexTable[10]; // unknown type

	static void makeResident()
	{
		for (int i = 0; i < 10; i++) {
			if (texTable[i]) {
				texTable[i]->makeResident();
			}
			if (shadowTexTable[i]) {
				shadowTexTable[i]->makeResident();
			}
		}
	}

	// empty
};

/**
 * @brief TODO
 */
template <typename T>
struct FigureTex : public NumberTex {
	FigureTex(T* numberPtr, int digit)
	{
		mNumberPtr = numberPtr;
		mDigit     = digit;
	}

	int getNumber() { return getNumber(*mNumberPtr); }
	int getNumber(T& numPtr)
	{
		int num = (numPtr / mDigit) % 10;
		if (num < 0) {
			return 0;
		}
		return num;
	}

	// DLL inlines:
	Texture* getTexPtr() { return texTable[getNumber()]; }
	Texture* getShadowTexPtr() { return shadowTexTable[getNumber()]; }

	// _00-_00 = NumberTex (empty)
	T* mNumberPtr; // _00, pointer to count/amount to display
	int mDigit;    // _04, 10 for tens, 1 for ones, etc
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C (for int, check for short)
 */
template <typename T>
struct NumberPicCallBack : public P2DPaneCallBack, public FigureTex<T> {
	NumberPicCallBack(P2DPane* pane, T* amountPtr, int digit, bool p4)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , FigureTex<T>(amountPtr, digit)
	{
		mUseShadowTex    = p4;
		mCurrentValue    = *mNumberPtr;
		mValueDifference = 0;
		mAnimTimer       = 0.0f;
		setTexture(pane);
		pane->setOffset(pane->getWidth() >> 1, pane->getHeight() >> 1);
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		if (getNumber() != getNumber(mCurrentValue)) {
			setTexture(pane);
			mValueDifference = *mNumberPtr - mCurrentValue;
			mAnimTimer       = 0.0f;
		}

		if (mValueDifference) {
			mAnimTimer += gsys->getFrameTime();
			if (mAnimTimer > 0.5f) {
				mAnimTimer       = 0.5f;
				mValueDifference = 0;
			}

			f32 t     = mAnimTimer / 0.5f;
			f32 tComp = (1.0f - t) * 0.3f;
			if (mValueDifference > 0) {
				f32 scale = (NMathF::cos(2.0f * TAU * t) + 1.0f) * tComp + 1.0f;
				pane->setScale(scale, scale, 1.0f);
			} else {
				f32 scale = 1.0f - (NMathF::cos(2.0f * TAU * t) + 1.0f) * tComp;
				pane->setScale(scale, scale, 1.0f);
			}
		}

		mCurrentValue = *mNumberPtr;
		STACK_PAD_VAR(2);
		return true;
	}

	void setTexture(P2DPane* pane)
	{
		if (mUseShadowTex) {
			P2DPicture* pic = (P2DPicture*)pane;
			pic->setTexture(getShadowTexPtr(), 0);
		} else {
			P2DPicture* pic = (P2DPicture*)pane;
			pic->setTexture(getTexPtr(), 0);
		}
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04-_0C = FigureTex
	f32 mAnimTimer;     // _0C
	T mCurrentValue;    // _10
	T mValueDifference; // _14
	bool mUseShadowTex; // _18
};

} // namespace zen

#endif
