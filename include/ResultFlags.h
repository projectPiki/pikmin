#ifndef _RESULTFLAGS_H
#define _RESULTFLAGS_H

#include "GlobalGameOptions.h"
#include "types.h"
#include "zen/ogResult.h"

struct RandomAccessStream;
struct Creature;

/**
 * @brief TODO
 */
struct ResultFlags {
public:
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
	int getDocument(int& pageCount);
	void dump();

protected:
	u8 getFlag(int);
	void setFlag(int, u8);

	static FlagInfo flagTable[];

	u16 mLength;             // _00, maximum amount of flags
	u16 mActiveCount;        // _02
	u16 mTableSize;          // _04
	u8* mStates;             // _08
	s16 mDaysSeen[MAX_DAYS]; // _0C, what log id was seen for each day
	u32* mScreenToTableList; // _48
};

#endif
