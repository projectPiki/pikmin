#ifndef _ZEN_DRAWOPTIONSAVE_H
#define _ZEN_DRAWOPTIONSAVE_H

/*
 * @brief TODO
 */
namespace zen {
struct DrawOptionSave {
	DrawOptionSave();
	void update(Controller*);
	void draw(Graphics&);
	void modeCardCheck(Controller*);
	void init();
	void start();
	void setMode(unsigned long, Controller*);
};
} // namespace zen

#endif
