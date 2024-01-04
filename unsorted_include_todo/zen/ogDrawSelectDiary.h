#ifndef _ZEN_OGDRAWSELECTDIARY_H
#define _ZEN_OGDRAWSELECTDIARY_H

/*
 * @brief TODO
 */
namespace zen {
struct ogDrawSelectDiary {
	ogDrawSelectDiary();
	void start();
	void setCursorAlpha();
	void MoveCursor();
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
