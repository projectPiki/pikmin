#ifndef _ZEN_OGSAVE_H
#define _ZEN_OGSAVE_H

#include "types.h"
#include "MemoryCard.h"

struct Controller;
struct Graphics;
struct P2DPane;
struct P2DTextBox;
struct P2DPicture;
struct P2DScreen;

namespace zen {

struct ogScrFileChkSelMgr;
struct DrawSaveFailure;
struct ogScrMemChkMgr;
struct ogNitakuMgr;
struct ogFadeMgr;

/**
 * @brief TODO
 */
struct ogSaveMgr {

	/**
	 * @brief TODO
	 */
	enum SaveStatus {
		Status_NULL = -1,
		Status_0    = 0,
		Status_1    = 1,
		Status_2    = 2,
		Status_3    = 3,
		Status_4    = 4,
		Status_5    = 5,
		Status_6    = 6,
		Status_7    = 7,
		Status_8    = 8,
		Status_9    = 9,
		Status_10   = 10,
		Status_11   = 11,
	};

	ogSaveMgr();

	void start();
	SaveStatus update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void startDirectSave(s16);

	SaveStatus mStatus;           // _00
	SaveStatus _04;               // _04
	P2DScreen* mScreen;           // _08
	P2DScreen* _0C;               // _0C
	f32 _10;                      // _10
	u16 _14;                      // _14
	ogNitakuMgr* _18;             // _18
	ogNitakuMgr* _1C;             // _1C
	ogScrMemChkMgr* mMemCheckMgr; // _20
	P2DScreen* _24;               // _24
	P2DPicture* _28;              // _28
	DrawSaveFailure* mSaveFail;   // _2C
	u8 _30;                       // _30
	u16 _32;                      // _32
	P2DTextBox* _34;              // _34
	P2DTextBox* _38;              // _38
	P2DPane* _3C;                 // _3C
	P2DPane* _40;                 // _40
	P2DTextBox* _44;              // _44
	P2DTextBox* _48;              // _48
	P2DTextBox* _4C;              // _4C
	P2DTextBox* _50;              // _50
	P2DTextBox* _54;              // _54
	P2DPane* _58;                 // _58
	P2DPane* _5C;                 // _5C
	ogFadeMgr* _60;               // _60
	ogFadeMgr* _64;               // _64
	ogFadeMgr* _68;               // _68
	ogFadeMgr* _6C;               // _6C
	P2DPicture* _70;              // _70
	P2DPicture* _74;              // _74
	P2DPane* _78;                 // _78
	P2DPane* _7C;                 // _7C
	P2DPane* _80;                 // _80
	ogScrFileChkSelMgr* _84;      // _84
	CardQuickInfo _88;            // _88
};

} // namespace zen

#endif
