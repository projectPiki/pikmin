#ifndef _MEMORYCARD_H
#define _MEMORYCARD_H

#include "types.h"
#include "CoreNode.h"

struct CARDStat;
struct PlayState;

extern u8 cardData[];

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct CardQuickInfo {
	CardQuickInfo() { _08 = 0; }

	u32 mIndex;             // _00
	u32 _04;                // _04, unknown
	u32 _08;                // _08, maybe int
	int mCurrentDay;        // _0C
	int mCurrentPartsCount; // _10
	int mRedPikiCount;      // _14
	int mYellowPikiCount;   // _18
	int mBluePikiCount;     // _1C
	u8 _20[0x4];            // _20, unknown
	u32 mCrc;               // _24
};

/**
 * @brief TODO
 */
struct MemoryCard : public CoreNode {
	inline MemoryCard()
	    : CoreNode("memoryCard")
	{
		_3C                = -1;
		mCardChannel       = -1;
		mSaveFileIndex     = -1;
		mRequiredFreeSpace = 0x26000;
		mErrorCode         = 0;
	}

	int getOptionsOffset(int);
	int getGameFileOffset(int);
	u32 calcChecksum(void*, u32);
	bool hasCardFinished();
	bool attemptFormatCard(int);
	int waitWhileBusy(int);
	bool getCardStatus(int);
	void checkUseFile();
	int getMemoryCardState(bool);
	void loadCurrentFile();
	int getNewestOptionsIndex();
	void loadOptions();
	void saveOptions();
	void loadCurrentGame();
	void saveCurrentGame();
	void writeCurrentGame(RandomAccessStream*, PlayState&);
	void readCurrentGame(RandomAccessStream*);
	void initBannerArea(CARDStat&, char*);
	void initOptionsArea(int);
	int makeDefaultFile();
	void copyFile(CardQuickInfo&, CardQuickInfo&);
	void delFile(CardQuickInfo&);
	int doFormatCard();
	bool isCardInserted();
	bool hasCardChanged();
	u32 getOkSections();
	bool isFileBroken();
	void repairFile();
	bool didSaveFail();
	void getQuickInfos(CardQuickInfo*);
	void init();

	// unused/inlined:
	void GetBlockSize(s32);
	void getBannerPtr();
	void getOptionsPtr(int);
	void getGameFilePtr(int);
	void getBannerStream();
	void getOptionsStream(int);
	void getGameFileStream(int);
	void waitPolling();
	void createFile(CARDStat&);
	void writeOneBanner();
	void writeOneOption(int);
	void writeOneGameFile(int);
	void initFileArea(int, int);
	void breakFile();

	// _00     = VTBL
	// _00-_14 = CoreNode
	char mFilePath[32];     // _14
	int mCardChannel;       // _34
	int mSaveFileIndex;     // _38
	int _3C;                // _3C
	u32 mRequiredFreeSpace; // _40
	u32 mErrorCode;         // _44
	u32 _48;                // _48
	u32 _4C;                // _4C
	u32 _50;                // _50
	u32 _54;                // _54
	u32 _58;                // _58
	u32 mValidBlockCount;   // _5C
	u32 _60;                // _60
	u32 _64;                // _64
	bool mDidSaveFail;      // _68
	int _6C;                // _6C
};

#endif
