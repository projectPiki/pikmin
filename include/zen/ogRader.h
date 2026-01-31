#ifndef _ZEN_OGRADER_H
#define _ZEN_OGRADER_H

#include "GlobalGameOptions.h"
#include "Vector.h"
#include "types.h"

struct P2DPane;
struct P2DPicture;
struct Controller;
struct Graphics;
struct P2DScreen;

namespace zen {

struct PikaAlphaMgr;

struct ogRaderMgr {
public:
	// Completely fabricated struct
	struct PikiRaderEntry {
		P2DPicture* mPic; // _00
		s16 mColor;       // _04
	};

	/**
	 * @brief TODO
	 */
	enum RaderStatus {
		STATE_NULL = -1,
		STATE_0    = 0,
		STATE_1    = 1,
		STATE_2    = 2,
		STATE_3    = 3,
		STATE_4    = 4,
		STATE_5    = 5,
		STATE_6    = 6,
		STATE_7    = 7,
		// TODO: this
	};

	P2DScreen* getScrPtr() { return mMainScreen; }

	ogRaderMgr();

	void startMenu(P2DPane*);
	void end();
	void MapOn();
	RaderStatus update(Controller*);
	void draw(Graphics&);
	void start();
	void MapOff();

private:
	Vector3f ogCalcDispXZ(Vector3f);
	void setRaderScale(f32);
	void chaseRaderScale(f32);
	void setRaderAngle(f32);
	void setRaderScroll(int, int);
	void getOrimaPos();
	void getContainerPos();
	void getRocketPos();
	void getPartsPos();
	void getAllPikiPos();
	void startSub();
	void updateGame(Controller*);
	void AreaScroll(f32*, f32*, f32, f32);
	void updateMenu(Controller*);
	void RotatePos(f32*, f32*);
	void DrawCircle(u8, u8, u8, u8, f32);

	bool _00;            // _00
	bool _01;            // _01
	bool _02;            // _02
	int _04;             // _04
	RaderStatus mStatus; // _08
	f32 _0C;             // _0C
	f32 _10;             // _10
	int _14;             // _14
	int _18;             // _18
	int _1C;             // _1C
	int _20;             // _20
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	Vector3f _24demo[4]; // _24
#endif
	f32 _24;                                // _24
	f32 _28;                                // _28
	f32 _2C;                                // _2C
	f32 _30;                                // _30
	f32 _34;                                // _34
	f32 _38;                                // _38
	P2DScreen* mMainScreen;                 // _3C
	P2DPicture* _40[3];                     // _40
	P2DPicture* _4C;                        // _4C
	PikaAlphaMgr* _50;                      // _50
	int _54;                                // _54
	P2DPane* _58;                           // _58
	P2DPicture* _5C;                        // _5C
	P2DPicture* _60;                        // _60
	P2DPicture* _64;                        // _64
	P2DPicture* _68;                        // _68
	P2DPicture* _6C;                        // _6C
	P2DPicture* _70;                        // _70
	P2DPicture* _74;                        // _74
	P2DPicture* _78;                        // _78
	P2DPicture* _7C;                        // _7C
	P2DPicture* _80;                        // _80
	P2DPicture* _84[MAX_UFO_PARTS];         // _84
	s16 _FC;                                // _FC
	PikiRaderEntry _100[MAX_PIKI_ON_FIELD]; // _100
	P2DPicture* _420;                       // _420
	P2DPane* _424;                          // _424
	f32 _428;                               // _428
	f32 _42C;                               // _42C
	Vector3f _430;                          // _430
	Vector3f _43C;                          // _43C
	int _448;                               // _448
	int _44C;                               // _44C
	f32 _450;                               // _450
	f32 _454;                               // _454
	s16 _458;                               // _458
	s16 _45A;                               // _45A
};

} // namespace zen

#endif
