#ifndef _ZEN_OGSAVEMGR_H
#define _ZEN_OGSAVEMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogSaveMgr {
	ogSaveMgr();
	void start();
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
