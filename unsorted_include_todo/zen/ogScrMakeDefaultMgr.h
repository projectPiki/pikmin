#ifndef _ZEN_OGSCRMAKEDEFAULTMGR_H
#define _ZEN_OGSCRMAKEDEFAULTMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrMakeDefaultMgr {
	ogScrMakeDefaultMgr();
	void start();
	void update(Controller*);
	void draw(Graphics&);
	void checkTypingAll();
};
} // namespace zen

#endif
