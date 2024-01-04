#ifndef _TEKIEVENT_H
#define _TEKIEVENT_H

/*
 * @brief TODO
 */
struct TekiEvent {
	TekiEvent(int, Teki*);
	TekiEvent(int, Teki*, Creature*);
	void init(int, Teki*, Creature*);
};

#endif
