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

	/**
	 * @brief TODO
	 */
	enum DiaryStatus {
		// TODO: this
	};

	ogScrDiaryMgr();

	DiaryStatus update(Controller*);
	void draw(Graphics&);
	void start(s16, s16);
	void typePage();
	bool nextPage();
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

	/**
	 * @brief TODO
	 */
	enum DiaryStatus {
		// TODO: this
	};

	ogDrawDiary();

	void open(f32, f32, s16);
	DiaryStatus update(Controller*);

	// unused/inlined:
	void start();
	void setOffset();
	void draw(Graphics&);

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x2F0.
 */
struct ogDrawSelectDiary {

	/**
	 * @brief TODO
	 */
	enum SelectDiaryStatus {
		SELECT_NULL = -1,
	};

	ogDrawSelectDiary();

	void start();
	void setCursorAlpha();
	bool MoveCursor();
	SelectDiaryStatus update(Controller*);
	void draw(Graphics&);

	u8 _00[0x2F0]; // _00, unknown
};

} // namespace zen

#endif
