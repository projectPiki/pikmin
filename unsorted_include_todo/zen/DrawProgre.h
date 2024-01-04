#ifndef _ZEN_DRAWPROGRE_H
#define _ZEN_DRAWPROGRE_H

/*
 * @brief TODO
 */
namespace zen {
struct DrawProgre {
	DrawProgre();
	void start();
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
