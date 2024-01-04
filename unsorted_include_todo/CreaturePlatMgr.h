#ifndef _CREATUREPLATMGR_H
#define _CREATUREPLATMGR_H

/*
 * @brief TODO
 */
struct CreaturePlatMgr {
	void init(Creature*, MapMgr*, Shape*);
	void release();
	void update(Graphics&);
};

#endif
