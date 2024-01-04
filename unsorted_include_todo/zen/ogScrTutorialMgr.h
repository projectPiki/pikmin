#ifndef _ZEN_OGSCRTUTORIALMGR_H
#define _ZEN_OGSCRTUTORIALMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrTutorialMgr {
	ogScrTutorialMgr();
	void update(Controller*);
	void draw(Graphics&);
	void start(zen::ogScrTutorialMgr::EnumTutorial);
};
} // namespace zen

#endif
