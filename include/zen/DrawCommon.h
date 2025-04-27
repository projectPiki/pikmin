#ifndef _ZEN_DRAWCOMMON_H
#define _ZEN_DRAWCOMMON_H

#include "types.h"
#include "P2D/Screen.h"

struct Graphics;

template <typename T>
struct IDelegate1;

namespace zen {

/**
 * @brief TODO
 *
 * @note Might be a struct? I think it's a namespace.
 */
namespace P2DPaneLibrary {
void makeResident(P2DPane*);
void setFamilyAlpha(P2DPane*, u8);
void setAlpha(P2DPane*, u8);
void setFamilyMirror(P2DPane*, P2DMirror);
P2DPane* getParentPane(P2DPane*);
void getWorldPos(P2DPane*, int*, int*);
void changeParent(P2DPane*, P2DPane*);

// unused/inlined:
void setMirror(P2DPane*, P2DMirror);
void printTag(P2DPane*);
void printUseTexName(P2DPane*, IDelegate1<char*>*);
void printUseTexName(char*, IDelegate1<char*>*);

// DLL inlines:
inline int makeTag(char* str)
{
	return ((u8)str[0] << 24) | ((u8)str[1] << 16) | ((u8)str[2] << 8) | (u8)str[3];
}

}; // namespace P2DPaneLibrary

/**
 * @brief TODO
 *
 * @note Size: 0x100.
 */
struct DrawScreen {

	DrawScreen(char* bloFileName, P2DGrafContext* grafContext, bool useAlphaMgr, bool useTexAnimMgr);

	virtual void update(); // _08
	virtual void draw();   // _0C

	// unused/inlined:
	~DrawScreen() { }

	// DLL inlines to do:
	P2DScreen* getScreenPtr() { return &mScreen; }
	void makeResident() { P2DPaneLibrary::makeResident(&mScreen); }

	// _00 = VTBL
	P2DScreen mScreen;            // _04
	P2DGrafContext* mGrafContext; // _FC
};

/**
 * @brief TODO
 */
struct BalloonPane : public P2DPaneCallBack {
	BalloonPane(P2DPane*, f32);

	virtual bool invoke(P2DPane*); // _08

	void setGoalPos();
	void setGoalRotate();

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	f32 mGoalRadius;    // _04
	Vector3f mHomePos;  // _08
	Vector3f mCurrPos;  // _14
	Vector3f mGoalPos;  // _20
	Vector3f mVelocity; // _2C
	f32 mCurrRotate;    // _38
	f32 mGoalRotate;    // _3C
};

} // namespace zen

#endif
