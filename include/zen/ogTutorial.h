#ifndef _ZEN_OGTUTORIAL_H
#define _ZEN_OGTUTORIAL_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

struct ogScrMessageMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct ogScrTutorialMgr {

	/**
	 * @brief TODO
	 */
	enum EnumTutorial {
		// TODO: this
	};

	/**
	 * @brief TODO
	 */
	enum TutorialStatus {
		Status_Null = -1,
		Status_0    = 0,
		Status_1    = 1,
		Status_2    = 2,
		Status_3    = 3,
		Status_4    = 4,
	};

	ogScrTutorialMgr();

	TutorialStatus update(Controller*);
	void draw(Graphics&);
	void start(zen::ogScrTutorialMgr::EnumTutorial);

	// unused/inlined:
	void nextPage();
	void backPage();
	void setCursorXY(P2DTextBox*);

	// DLL inlines:
	ogScrMessageMgr* getScrMsgMgr() { return mMessageMgr; }

	ogScrMessageMgr* mMessageMgr;                  // _00
	zen::ogScrTutorialMgr::TutorialStatus mStatus; // _04
};

extern char** bloFiles_Tutorial[];

} // namespace zen

#endif
