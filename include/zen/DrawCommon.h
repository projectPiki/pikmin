#ifndef _ZEN_DRAWCOMMON_H
#define _ZEN_DRAWCOMMON_H

#include "types.h"
#include "P2D/Pane.h"

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

	// TODO: members
};

/**
 * @brief TODO
 */
struct P2DPaneLibrary {

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

	// TODO: members
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

} // namespace zen

#endif
