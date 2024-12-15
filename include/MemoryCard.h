#ifndef _MEMORYCARD_H
#define _MEMORYCARD_H

#include "types.h"
#include "CoreNode.h"

struct CARDStat;
struct PlayState;

/**
 * @brief TODO
 */
struct CardQuickInfo {
	CardQuickInfo() { _08 = 0; }

	u32 mIndex;          // _00, unknown
	u8 _04[0x4];         // _04, unknown
	u32 _08;             // _08, unknown
	int _0C;             // _0C, to do with day count?
	u8 _10[0x24 - 0x10]; // _10, unknown
	u32 mCrc;            // _24, unknown
};

/**
 * @brief TODO
 */
struct MemoryCard : public CoreNode {
	inline MemoryCard()
	    : CoreNode("memoryCard")
	{
		_3C = -1;
		_34 = -1;
		_38 = -1;
		_40 = 0x26000;
		_44 = 0;
	}

	void getOptionsOffset(int);
	void getGameFileOffset(int);
	void calcChecksum(void*, u32);
	bool hasCardFinished();
	void attemptFormatCard(int);
	void waitWhileBusy(int);
	void getCardStatus(int);
	void checkUseFile();
	void getMemoryCardState(bool);
	void loadCurrentFile();
	void getNewestOptionsIndex();
	void loadOptions();
	void saveOptions();
	void loadCurrentGame();
	void saveCurrentGame();
	void writeCurrentGame(RandomAccessStream*, PlayState&);
	void readCurrentGame(RandomAccessStream*);
	void initBannerArea(CARDStat&, char*);
	void initOptionsArea(int);
	void makeDefaultFile();
	void copyFile(CardQuickInfo&, CardQuickInfo&);
	void delFile(CardQuickInfo&);
	void doFormatCard();
	bool isCardInserted();
	bool hasCardChanged();
	void getOkSections();
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
	u8 _14[0x34 - 0x14]; // _14, unknown
	int _34;             // _34
	int _38;             // _38
	int _3C;             // _3C
	u32 _40;             // _40
	u32 _44;             // _44, unknown
};

#endif
