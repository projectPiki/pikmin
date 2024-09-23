#ifndef _ZEN_OGTITLE_H
#define _ZEN_OGTITLE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrTitleMgr {
	ogScrTitleMgr();

	void start(bool);
	void update(Controller*);
	void draw(Graphics&);
	void StereoOnOff(bool);
	void DispBarBGM(bool);
	void DispBarSE(bool);

	// unused/inlined:
	void getGamePrefs();
	void setGamePrefs();

	// TODO: members
};

} // namespace zen

#endif
