#ifndef _ZEN_OGSCRMAPMGR_H
#define _ZEN_OGSCRMAPMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrMapMgr {
	void start(short);
	ogScrMapMgr();
	void update(Controller*);
	void draw(Graphics&);
};
} // namespace zen

#endif
