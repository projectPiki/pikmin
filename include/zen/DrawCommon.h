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
 */
struct DrawScreen {

	DrawScreen(char*, P2DGrafContext*, bool, bool);

	virtual void update(); // _08
	virtual void draw();   // _0C

	// unused/inlined:
	~DrawScreen();

	// _00 = VTBL
	P2DScreen mPane; // _04
};

/**
 * @brief TODO
 */
struct BalloonPane : public P2DPaneCallBack {
	BalloonPane(P2DPane*, f32);

	virtual bool invoke(P2DPane*); // _08

	void setGoalPos();
	void setGoalRotate();

	// TODO: members
};

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
void getParentPane(P2DPane*);
void getWorldPos(P2DPane*, int*, int*);
void changeParent(P2DPane*, P2DPane*);

// unused/inlined:
void setMirror(P2DPane*, P2DMirror);
void printTag(P2DPane*);
void printUseTexName(P2DPane*, IDelegate1<char*>*);
void printUseTexName(char*, IDelegate1<char*>*);
}; // namespace P2DPaneLibrary

} // namespace zen

#endif
