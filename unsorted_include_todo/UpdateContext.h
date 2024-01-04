#ifndef _UPDATECONTEXT_H
#define _UPDATECONTEXT_H

/*
 * @brief TODO
 */
struct UpdateContext {
	UpdateContext();
	void updatable();
	void init(UpdateMgr*);
	void exit();
};

#endif
