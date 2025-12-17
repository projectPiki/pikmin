#ifndef _ZEN_DRAWCOMMON_H
#define _ZEN_DRAWCOMMON_H

#include "P2D/Screen.h"
#include "types.h"

struct Graphics;

template <typename T>
struct IDelegate1;

namespace zen {

/**
 * @brief TODO
 */
struct P2DPaneLibrary {
	static void makeResident(P2DPane*);
	static void setFamilyAlpha(P2DPane*, u8);
	static void setAlpha(P2DPane*, u8);
	static void setFamilyMirror(P2DPane*, P2DMirror);
	static P2DPane* getParentPane(P2DPane*);
	static void getWorldPos(P2DPane*, int*, int*);
	static void changeParent(P2DPane*, P2DPane*);

	// unused/inlined:
	static void setMirror(P2DPane*, P2DMirror);
	static void printTag(P2DPane*);
	static void printUseTexName(P2DPane*, IDelegate1<immut char*>*);
	static void printUseTexName(immut char*, IDelegate1<immut char*>*);

	// DLL inlines:
	static int makeTag(immut char* str) { return (str[0] << 24) | (str[1] << 16) | (str[2] << 8) | str[3]; }
};

/**
 * @brief TODO
 *
 * @note Size: 0x100.
 */
struct DrawScreen {
public:
	DrawScreen(immut char* bloFileName, P2DGrafContext* grafContext, bool useAlphaMgr, bool useTexAnimMgr);

	virtual void update(); // _08
	virtual void draw();   // _0C

	// unused/inlined:
	~DrawScreen() { }

	// DLL inlines to do:
	P2DScreen* getScreenPtr() { return &mScreen; }
	void makeResident() { P2DPaneLibrary::makeResident(&mScreen); }

protected:
	// _00 = VTBL
	P2DScreen mScreen;            // _04
	P2DGrafContext* mGrafContext; // _FC
};

/**
 * @brief TODO
 */
struct BalloonPane : public P2DPaneCallBack {
public:
	BalloonPane(P2DPane*, f32);

	virtual bool invoke(P2DPane*); // _08

protected:
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
