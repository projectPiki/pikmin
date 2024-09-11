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
	CardQuickInfo();

	// TODO: members
};

/**
 * @brief TODO
 */
struct MemoryCard : public CoreNode {

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
	// TODO: members
};

#endif
