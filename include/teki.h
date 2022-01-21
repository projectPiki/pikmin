#ifndef _TEKI_H
#define _TEKI_H
#include "types.h"
class Creature {
	s32 m_int;
};

class Teki {
	s32 m_int;
};

class TekiEvent {
	s32 m_int;               // _00
	Teki* m_tekiptr;         // _04
	Creature* m_creatureptr; // _08

	TekiEvent(int, Teki*);
	TekiEvent(int, Teki*, Creature*);
	void init(int, Teki*, Creature*);
};
#endif
