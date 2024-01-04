#ifndef _COLLTRIINFO_H
#define _COLLTRIINFO_H

/*
 * @brief TODO
 */
struct CollTriInfo {
	void init(RoomInfo*, Vector3f*);
	void behindEdge(Vector3f&);
};

#endif
