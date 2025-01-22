#ifndef _ZEN_OGTITLE_H
#define _ZEN_OGTITLE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0xA8.
 */
struct ogScrTitleMgr {

	/**
	 * @brief TODO
	 */
	enum TitleStatus {
		// TODO: this
	};

	ogScrTitleMgr();

	void start(bool);
	TitleStatus update(Controller*);
	void draw(Graphics&);
	void StereoOnOff(bool);
	void DispBarBGM(bool);
	void DispBarSE(bool);

	// unused/inlined:
	void getGamePrefs();
	void setGamePrefs();

	u8 _00[0xA8]; // _00, unknown
};

} // namespace zen

#endif
