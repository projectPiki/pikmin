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
		ErrorOrCompleted      = 1, ///< 1, we backed out
		SelectionA            = 2, ///< 2, selected file slot A.
		SelectionB            = 3, ///< 3, selected file slot B.
		SelectionC            = 4, ///< 4, selected file slot C.
		ForceExit             = 5, ///< 5, exit from skipping, successful exit, or requesting return to previous screen.

		FILECHKSEL_Exit       = ErrorOrCompleted, // anything above this is an error/exit
		FILECHKSEL_SlotOffset = SelectionA,       // offset for converting result to save file slot
	};

	ogScrFileChkSelMgr();

	void start(bool skipFileSelect);
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
