#ifndef _ZEN_OGMAKEDEFAULT_H
#define _ZEN_OGMAKEDEFAULT_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DPane;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

struct setTenmetuAlpha;
struct TypingTextMgr;

/**
 * @brief TODO
 */
struct ogScrMakeDefaultMgr {

	/**
	 * @brief TODO
	 */
	enum MakeDefaultStatus {
		Status_NULL = -1,
		Status_0    = 0,
		Status_1    = 1,
		Status_2    = 2,
		Status_3    = 3,
		Status_4    = 4,
		Status_5    = 5,
	};

	ogScrMakeDefaultMgr();

	void start();
	MakeDefaultStatus update(Controller*);
	void draw(Graphics&);
	bool checkTypingAll();

	// unused/inlined:

	MakeDefaultStatus mStatus; // _00
	MakeDefaultStatus _04;     // _04
	P2DScreen* mScreen;        // _08
	P2DScreen* mScreen2;       // _0C
	P2DPicture* _10;           // _10
	int _14;                   // _14
	P2DPicture* _18;           // _18
	P2DPicture* _1C;           // _1C
	setTenmetuAlpha* _20;      // _20
	setTenmetuAlpha* _24;      // _24
	TypingTextMgr* _28;        // _28
	P2DTextBox* _2C;           // _2C
	TypingTextMgr* _30;        // _30
	P2DTextBox* _34;           // _34
	TypingTextMgr* _38;        // _38
	P2DTextBox* _3C;           // _3C
	TypingTextMgr* _40;        // _40
	P2DPane* _44;              // _44
	P2DPane* _48;              // _48
	P2DPane* _4C;              // _4C
	f32 _50;                   // _50
};

} // namespace zen

#endif
