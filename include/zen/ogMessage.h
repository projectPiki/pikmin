#ifndef _ZEN_OGMESSAGE_H
#define _ZEN_OGMESSAGE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0xA5F0.
 */
struct ogScrMessageMgr {
	ogScrMessageMgr(char*);

	void SearchTopPage(int);
	void resetPage();
	void start(int);
	void setPage(int);
	void nextPage();
	void backPage();
	void makePageInfo(char***);
	void cnvSingleMulti(char*);
	void cnvButtonIcon(char*);
	void setPageInfoSub();
	void MakeAndSetPageInfo(char***);
	void dispAll();
	void fadeOut();
	void update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void setMessagePage(int);
	void ReadAllScreen();
	void setScreenAlpha(u8);

	u8 _00[0x4E0];           // _00, unknown
	u8 _4E0;                 // _4E0
	u8 _4E1[0xA5F0 - 0x4E1]; // _4E1, unknown
};

} // namespace zen

#endif
