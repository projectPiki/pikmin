#ifndef _ZEN_DRAWGAMEOVER_H
#define _ZEN_DRAWGAMEOVER_H

/*
 * @brief TODO
 */
namespace zen {
struct DrawGameOver {
	DrawGameOver();
	void start(zen::DrawGameOver::modeFlag, float);
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
