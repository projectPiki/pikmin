#ifndef _RESULTFLAGS_H
#define _RESULTFLAGS_H

#include "types.h"

struct RandomAccessStream;
struct Creature;

/**
 * @brief TODO
 */
enum EResultsFlags {
	RESFLAG_Unk0 = 0,
	RESFLAG_Unk1 = 1,
	// ...
	RESFLAG_Unk24 = 24,
	// ...
	RESFLAG_Unk39 = 39,
	// ...
	RESFLAG_Unk42 = 42,
};

/**
 * @brief TODO
 */
struct ResultFlags {

	/**
	 * @brief TODO
	 */
	struct FlagInfo {

		// unused/inlined:
		void type();

		// TODO: members
	};

	ResultFlags();

	void initGame();
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	void setOn(int);
	void setSeen(int);
	void getDayDocument(int, int&);
	void getDocument(int&);
	void dump();
	void getFlag(int);
	void setFlag(int, u8);

	u16 _00;     // _00
	u16 _02;     // _02
	u16 _04;     // _04
	u8* _08;     // _08
	s16 _0C[30]; // _0C
	u32* _48;    // _48
};

#endif
