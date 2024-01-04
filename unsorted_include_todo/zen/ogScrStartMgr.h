#ifndef _ZEN_OGSCRSTARTMGR_H
#define _ZEN_OGSCRSTARTMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrStartMgr {
	ogScrStartMgr();
	void start();
	void stop();
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
