#ifndef _ZEN_DRAWUFOPARTS_H
#define _ZEN_DRAWUFOPARTS_H

/*
 * @brief TODO
 */
namespace zen {
struct DrawUfoParts {
	DrawUfoParts();
	void update(Controller*);
	void draw(Graphics&);
	void sleep();
	void start();
	void operation();
	void dataSet();
};
} // namespace zen

#endif
