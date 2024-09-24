#ifndef _ZEN_OGDIARY_H
#define _ZEN_OGDIARY_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrDiaryMgr {
	ogScrDiaryMgr();

	void update(Controller*);
	void draw(Graphics&);
	void start(s16, s16);
	void typePage();
	void nextPage();
	void backPage();
	void exit();

	// unused/inlined:
	void setDiarySpecialNumber(s16);
	void setCursorXY(P2DTextBox*);
	void updateDiary(Controller*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogDrawDiary {
	ogDrawDiary();

	void open(f32, f32, s16);
	void update(Controller*);

	// unused/inlined:
	void start();
	void setOffset();
	void draw(Graphics&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogDrawSelectDiary {
	ogDrawSelectDiary();

	void start();
	void setCursorAlpha();
	void MoveCursor();
	void update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
