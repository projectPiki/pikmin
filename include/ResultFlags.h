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
	RESFLAG_BluePikminWaterImmunity = 38,
	RESFLAG_Unk39                   = 39,
	// ...
	RESFLAG_Unk42 = 42,
	RESFLAG_Unk43 = 43,
	// ...
	RESFLAG_PomFlowerFound = 45,
	RESFLAG_Unk46          = 46,
	// ...
	RESFLAG_Unk48 = 48,
	RESFLAG_Unk49 = 49,
	RESFLAG_Unk50 = 50,
};

/**
 * @brief TODO
 */
struct ResultFlags {

	/**
	 * @brief TODO
	 */
	struct FlagInfo {

		enum StoreType {
			Store_Forget = 0,
			Store_Reset  = 1,
			Store_Keep   = 2,
		};

		// unused/inlined:
		int type();

		int mScreenId;   // _00
		bool mIsAutoSet; // _04
		int mPriority;   // _08
		u32 mStore;      // _0C
	};

	ResultFlags();

	void initGame();
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	void setOn(int);
	void setSeen(int);
	int getDayDocument(int, int&);
	int getDocument(int&);
	void dump();
	u8 getFlag(int);
	void setFlag(int, u8);

	static FlagInfo flagTable[];

	u16 mLength;             // _00, maximum amount of flags
	u16 mActiveCount;        // _02
	u16 mTableSize;          // _04
	u8* mStates;             // _08
	s16 mDaysSeen[30];       // _0C, what log id was seen for each day
	u32* mScreenToTableList; // _48
};

#endif
