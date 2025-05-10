#ifndef _ZEN_OGRADER_H
#define _ZEN_OGRADER_H

#include "types.h"

struct P2DPane;
struct P2DPicture;
struct Controller;
struct Graphics;
struct P2DScreen;
struct Vector3f;

namespace zen {

/**
 * @brief TODO
 */
struct ogRaderMgr {

	/**
	 * @brief TODO
	 */
	enum RaderStatus {
		// TODO: this
	};

	ogRaderMgr();

	void setRaderAngle(f32);
	void setRaderScroll(int, int);
	void getPartsPos();
	void getAllPikiPos();
	void startSub();
	void startMenu(P2DPane*);
	void MapOn();
	void updateGame(Controller*);
	void AreaScroll(f32*, f32*, f32, f32);
	void updateMenu(Controller*);
	RaderStatus update(Controller*);
	void end();
	void draw(Graphics&);

	// unused/inlined:
	Vector3f ogCalcDispXZ(Vector3f);
	void setRaderScale(f32);
	void chaseRaderScale(f32);
	void getOrimaPos();
	void getContainerPos();
	void getRocketPos();
	void start();
	void MapOff();
	void RotatePos(f32*, f32*);
	void DrawCircle(u8, u8, u8, u8, f32);

	// DLL inlines to do:
	P2DScreen* getScrPtr() { return _3C; }

	// TODO: members
	u8 _00[0x3C];         // _00
	P2DScreen* _3C;       // _3C
	u8 _40[0x45C - 0x40]; // _40, unknown
};

// unused/inlined global functions:

} // namespace zen

#endif
