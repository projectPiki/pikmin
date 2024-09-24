#ifndef _ZEN_OGMESSAGE_H
#define _ZEN_OGMESSAGE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
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

	// TODO: members
};

} // namespace zen

#endif
