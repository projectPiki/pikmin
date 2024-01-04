#ifndef _ZEN_OGSCRDIARYMGR_H
#define _ZEN_OGSCRDIARYMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrDiaryMgr {
	ogScrDiaryMgr();
	void update(Controller*);
	void draw(Graphics&);
	void start(short, short);
	void typePage();
	void nextPage();
	void backPage();
	void exit();
};
} // namespace zen

#endif
