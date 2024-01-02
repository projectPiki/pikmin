#ifndef _TEKI_H
#define _TEKI_H
#include "types.h"
struct Creature {
	s32 mInt;
};

struct Teki {
	s32 mInt;
};

struct TekiEvent {
	s32 mInt;               // _00
	Teki* mTekiptr;         // _04
	Creature* mCreatureptr; // _08

	TekiEvent(int, Teki*);
	TekiEvent(int, Teki*, Creature*);
	void init(int, Teki*, Creature*);
};
#endif
