#ifndef _RESULTFLAGS_H
#define _RESULTFLAGS_H

#include "GlobalGameOptions.h"
#include "types.h"

struct RandomAccessStream;
struct Creature;

/**
 * @brief TODO
 */
enum EResultsFlags {
	RESFLAG_NULL                    = -1,
	RESFLAG_EndFirstDay             = 1,
	RESFLAG_FirstVisitForest        = 3,
	RESFLAG_UnlockCave              = 5,
	RESFLAG_FirstVisitCave          = 6,
	RESFLAG_UnlockYakushima         = 7,
	RESFLAG_FirstVisitYakushima     = 8,
	RESFLAG_FinalDay                = 10,
	RESFLAG_Collect25Parts          = 11,
	RESFLAG_Collect29Parts          = 12,
	RESFLAG_OlimarDown              = 13,
	RESFLAG_PikminExtinction        = 14,
	RESFLAG_CollectAllParts         = 15, // unused
	RESFLAG_YellowWithBomb          = 17,
	RESFLAG_MeetBluePikmin          = 18,
	RESFLAG_PikminRouting           = 19,
	RESFLAG_OlimarDaydream          = 20,
	RESFLAG_Collect15Parts          = 21,
	RESFLAG_PikminLeftBehind        = 23,
	RESFLAG_PikminBombDeath         = 24,
	RESFLAG_Collect10Parts          = 26,
	RESFLAG_UnusedControls1         = 27,
	RESFLAG_UnusedControls2         = 29,
	RESFLAG_UnusedControls3         = 31,
	RESFLAG_BrokenBridge            = 32,
	RESFLAG_PikminSeeds             = 33,
	RESFLAG_PikminSeedStageUp       = 35,
	RESFLAG_Onyons                  = 36,
	RESFLAG_MeetYellowPikminNoBomb  = 37,
	RESFLAG_BluePikminWaterImmunity = 38, // unused
	RESFLAG_PikminOnFire            = 39,
	RESFLAG_Dororo                  = 40, // Smoky Progg
	RESFLAG_Swallow                 = 41, // Bulborb
	RESFLAG_Kinoko                  = 42, // Puffstool
	RESFLAG_Kogane                  = 43, // Flint Beetle
	RESFLAG_Mizinko                 = 44, // Honeywisp
	RESFLAG_Pom                     = 45, // Candypop Bud
	RESFLAG_Spider                  = 46, // Beady Long Legs
	RESFLAG_Beatle                  = 47, // Armored Cannon Beetle
	RESFLAG_Snake                   = 48, // Burrowing Snagret
	RESFLAG_King                    = 49, // Emperor Bulblax
	RESFLAG_Slime                   = 50, // Goolix
	RESFLAG_Miurin                  = 51, // Mamuta
	RESFLAG_Kabekui                 = 52, // Sheargrub
	RESFLAG_Tank                    = 53, // Fiery Blowhog
	RESFLAG_Shell                   = 54, // Pearly Clamclamp
	RESFLAG_Collec                  = 55, // Breadbug
	RESFLAG_Mar                     = 56, // Puffy Blowhog
	RESFLAG_Otimoti                 = 57, // Wollywog
	RESFLAG_Misc1                   = 58,
	RESFLAG_Misc2                   = 59,
	RESFLAG_Misc3                   = 60,
	RESFLAG_Misc4                   = 61,
	RESFLAG_Misc5                   = 62,
	RESFLAG_Misc6                   = 63,
	RESFLAG_Misc7                   = 64,
	RESFLAG_Misc8                   = 65,
	RESFLAG_Misc9                   = 66,
	RESFLAG_Misc10                  = 67,
	RESFLAG_Misc11                  = 68,
	RESFLAG_Misc12                  = 69,
	RESFLAG_Misc13                  = 70,
	RESFLAG_Misc14                  = 71,
	RESFLAG_Misc15                  = 72,
	RESFLAG_Misc16                  = 73,
	RESFLAG_Misc17                  = 74,
	RESFLAG_Misc18                  = 75,
	RESFLAG_Misc19                  = 76,
	RESFLAG_Misc20                  = 77,
	RESFLAG_Misc21                  = 78,
	RESFLAG_Misc22                  = 79,
	RESFLAG_Misc23                  = 80,
	RESFLAG_Misc24                  = 81,
	RESFLAG_Misc25                  = 82,
	RESFLAG_Misc26                  = 83,
	RESFLAG_Misc27                  = 84,
};

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
	int getDocument(int&);
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
