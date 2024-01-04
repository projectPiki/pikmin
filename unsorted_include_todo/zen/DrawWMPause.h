#ifndef _ZEN_DRAWWMPAUSE_H
#define _ZEN_DRAWWMPAUSE_H

/*
 * @brief TODO
 */
namespace zen {
struct DrawWMPause {
	DrawWMPause();
	void start();
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
