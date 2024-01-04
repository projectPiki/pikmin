#ifndef _ZEN_OGSCRPAUSEMGR_H
#define _ZEN_OGSCRPAUSEMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrPauseMgr {
	ogScrPauseMgr();
	void start(bool);
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
