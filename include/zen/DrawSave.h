#ifndef _ZEN_DRAWSAVE_H
#define _ZEN_DRAWSAVE_H

#include "types.h"

struct Graphics;
struct Controller;

namespace zen {

/**
 * @brief TODO
 */
struct DrawSaveMes {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	DrawSaveMes();

	void sleep();
	void mesAppear();
	void saveFinish();
	void saveError();
	void update(Controller*);
	void draw(Graphics&);
	void setMode(modeFlag);

	// unused/inlined:
	void hide();

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawSaveFailure {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	DrawSaveFailure();

	void update(Controller*);
	void draw(Graphics&);
	void open(f32);
	void setMode(modeFlag);
	void calcFrame(f32);
	void init();

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawOptionSave {
	DrawOptionSave();

	void update(Controller*);
	void draw(Graphics&);
	void modeCardCheck(Controller*);
	void init();
	void start();
	void setMode(u32, Controller*);
};

} // namespace zen

#endif
