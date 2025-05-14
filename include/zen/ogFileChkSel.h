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
 *
 * @note Size: 0x18.
 */
struct ogScrFileChkSelMgr {

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		Null                  = -1,
		MemoryCheckInProgress = 0,
		ErrorOrCompleted      = 1,
		FILECHKSEL_SelectionA = 2,
		FILECHKSEL_SelectionB = 3,
		FILECHKSEL_SelectionC = 4,
		FILECHKSEL_Unk5       = 5,

		FILECHKSEL_Exit = ErrorOrCompleted, // anything above this is an error/exit
	};

	ogScrFileChkSelMgr();

	void start(bool);
	void startSave();
	returnStatusFlag update(Controller*, CardQuickInfo&);
	void draw(Graphics&);

	// unused/inlined:
	void init();
	void startSub();

	returnStatusFlag mState;            // _00
	bool mIsSaveOperation;              // _04
	P2DScreen* mDataBScreen;            // _08
	bool _UNUSED0C;                     // _0C
	bool mSkipFileSelect;               // _0D
	bool mIsScreenVisible;              // _0E
	ogScrMemChkMgr* mMemChkMgr;         // _10
	ogScrFileSelectMgr* mFileSelectMgr; // _14
};

} // namespace zen

#endif
