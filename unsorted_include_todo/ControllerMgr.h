#ifndef _CONTROLLERMGR_H
#define _CONTROLLERMGR_H

/**
 * .obj __vt__13ControllerMgr, global
 * .4byte __RTTI__13ControllerMgr
 * .4byte 0
 * .4byte keyDown__13ControllerMgrFi
 */

/**
 * @brief TODO
 */
struct ControllerMgr {
	virtual void keyDown(int); // _08

	void update();
	void init();
	void updateController(Controller*);
};

#endif
