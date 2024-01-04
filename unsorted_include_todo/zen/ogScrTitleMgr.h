#ifndef _ZEN_OGSCRTITLEMGR_H
#define _ZEN_OGSCRTITLEMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrTitleMgr {
	ogScrTitleMgr();
	void start(bool);
	void update(Controller*);
	void draw(Graphics&);
	void StereoOnOff(bool);
	void DispBarBGM(bool);
	void DispBarSE(bool);
};
} // namespace zen

#endif
