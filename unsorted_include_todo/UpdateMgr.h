#ifndef _UPDATEMGR_H
#define _UPDATEMGR_H

/*
 * @brief TODO
 */
struct UpdateMgr {
	UpdateMgr();
	void update();
	void updatable(UpdateContext*);
	void create(int);
	void addClient(UpdateContext*);
	void removeClient(UpdateContext*);
};

#endif
