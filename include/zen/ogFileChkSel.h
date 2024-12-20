#ifndef _ZEN_OGFILECHKSEL_H
#define _ZEN_OGFILECHKSEL_H

#include "types.h"

struct Controller;
struct CardQuickInfo;
struct Graphics;
struct P2DScreen;

namespace zen {

struct ogScrMemChkMgr;
struct ogScrFileSelectMgr;

/**
 * @brief TODO
 */
enum ogScrFileChkSelState {
	FILECHKSEL_NULL = -1,
	FILECHKSEL_Unk0 = 0,

	FILECHKSEL_Unk1 = 1,
	FILECHKSEL_Unk2 = 2,
	FILECHKSEL_Unk3 = 3,
	FILECHKSEL_Unk4 = 4,
	FILECHKSEL_Unk5 = 5,

	FILECHKSEL_Exit = FILECHKSEL_Unk1, // anything above this is an error/exit
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct ogScrFileChkSelMgr {
	ogScrFileChkSelMgr();

	void start(bool);
	void startSave();
	int update(Controller*, CardQuickInfo&);
	void draw(Graphics&);

	// unused/inlined:
	void init();
	void startSub();

	int mState;                         // _00
	bool _04;                           // _04
	P2DScreen* mDataBScreen;            // _08
	bool _0C;                           // _0C
	bool _0D;                           // _0D
	bool mIsScreenVisible;              // _0E
	ogScrMemChkMgr* mMemChkMgr;         // _10
	ogScrFileSelectMgr* mFileSelectMgr; // _14
};

} // namespace zen

#endif
